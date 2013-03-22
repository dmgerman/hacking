/*
 * Copyright (c) 1983, 1987, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Copyright 2000-2003 by Marco d'Itri <md@linux.it>
 * (I removed the advertisement clause from the original BSD license.)
 *
 * Removed "vacation:" prefix from syslog messages and added openlog() call.
 *
 * Updated to the latest NetBSD release.
 *
 * Merged -l option from FreeBSD.
 *
 * Merged $SUBJECT substitution and Return-Path handling from OpenBSD.
 *
 * Merged -j option from sourceforge version.
 *
 * Merged patch from Stefan Muenkner <stefan.muenkner@zdv.uni-tuebingen.de>
 * which makes nsearch() ignore case when comparing addresses.
 *
 * Implemented sendmail-style -fmtxz options.
 *
 * Added xmalloc() wrapper.
 */

#if 0
static char copyright[] =
  "@(#) Copyright (c) 1983, 1987, 1993\n\
        The Regents of the University of California.  All rights reserved.\n";

static char sccsid[] = "@(#)vacation.c  8.2 (Berkeley) 1/26/94";
#endif /* not lint */

/*
**  Vacation
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/param.h>
#include <sys/stat.h>
#ifdef HAVE_PATHS_H
# include <paths.h>
#else
# define _PATH_SENDMAIL "/usr/lib/sendmail"
#endif

#ifndef PATH_VACATION
# define PATH_VACATION "/usr/bin/vacation"
#endif

#ifdef libc5
# include <db/db.h>
#else
# if defined __GLIBC__ && __GLIBC__ == 2 && __GLIBC_MINOR__ >= 1
#  include <db_185.h>
# else
#  include <db.h>
# endif
#endif

/* from tzfile.h */
#ifndef DAYSPERWEEK
# define DAYSPERWEEK 7
# define SECSPERDAY (long)(60 * 60 * 24)
#endif

#if (!defined _POSIX_C_SOURCE || _POSIX_C_SOURCE < 2)
int getopt(int , char * const [], const char *);
extern char *optarg;
extern int optind, opterr;
#endif

/*
 *  VACATION -- return a message to the sender when on vacation.
 *
 *      This program is invoked as a message receiver.  It returns a
 *      message specified by the user to whomever sent the mail, taking
 *      care not to return a message too often to prevent "I am on
 *      vacation" loops.
 */

#define VIT     "__VACATION__INTERVAL__TIMER__"
#define MAXLINE 1024                    /* max line from mail header */
#define VDB     ".vacation.db"          /* dbm's database */
#define VMSG    ".vacation.msg"         /* vacation message */
#define FWDBACKUP ".forward~vacation~backup" /* backup of ~/.forward */

typedef struct alias {
  struct alias *next;
  const char *name;
} ALIAS;
ALIAS *names;

void (*msglog)(int, const char *, ...) = &syslog;

DB *db;
char from[MAXLINE];
char subj[MAXLINE];
int jflag = 0;

int dryRunFlag = 0; // do not actually send any emails if true

/* prototypes */
void readheaders(void);
int nsearch(const char *, const char *);
int junkmail(void);
int recent(void);
time_t lookup(const char *, size_t);
void setreply(const char *, size_t, time_t);
void sendmessage(const char *, const char *);
void usage(void);
void listdb(void);
int isdelim(int);
void *xmalloc(size_t);
void discard_exit(void);
void initialize(const char *);
void debuglog (int, const char *, ...);
int askyn (const char *);

int main(int argc, char *argv[])
{
  struct passwd *pw;
  ALIAS *cur;
  time_t interval;
  int ch, iflag, lflag, xflag, zflag;
  char *dbfilename = (char *)VDB;
  char *msgfilename = (char *)VMSG;
  
  openlog("vacation", LOG_PERROR, LOG_MAIL);
  opterr = iflag = lflag = xflag = zflag = 0;
  interval = -1;
  while ((ch = getopt(argc, argv, "a:df:Iijlm:r:t:xyz")) != -1)
    switch((char)ch) {
    case 'a':                       /* alias */
      cur = xmalloc(sizeof(ALIAS));
      cur->name = optarg;
      cur->next = names;
      names = cur;
      break;
    case 'd':
      msglog = &debuglog;
      break;
    case 'f':                       /* alternate database */
      dbfilename = xmalloc(strlen(optarg) + 1);
      strcpy(dbfilename, optarg);
      break;
    case 'I':                       /* backward compatible */
    case 'i':                       /* init the database */
      iflag = 1;
      break;
    case 'j':                       /* ignore recipient addr. */
      jflag = 1;
      break;
    case 'l':                       /* list the database */
      lflag = 1;
      break;
    case 'm':                       /* alternate message file */
      msgfilename = xmalloc(strlen(optarg) + 1);
      strcpy(msgfilename, optarg);
      break;
    case 'r':
      if (isdigit(*optarg)) {
	interval = atol(optarg) * SECSPERDAY;
	if (interval < 0)
	  usage();
      }
      else
	interval = LONG_MAX;
      break;
      /*
	case 't':
	break;
      */
    case 'x':
      xflag = 1;
      break;
    case 'y':
      dry
	
    case 'z':
      zflag = 1;
      break;
    case '?':
    default:
      usage();
    }
  argc -= optind;
  argv += optind;
  
  if (argc != 1) {
    if (!iflag && !lflag && !xflag && argc != 0)
      usage();
    if (!(pw = getpwuid(getuid()))) {
      msglog(LOG_ERR, "no such user uid %u.\n", getuid());
      exit(1);
    }
  }
  else if (!(pw = getpwnam(*argv))) {
    msglog(LOG_ERR, "no such user %s.\n", *argv);
    exit(1);
  }
  if (msgfilename[0] != '/' || dbfilename[0] != '/')
    if (chdir(pw->pw_dir)) {
      msglog(LOG_ERR, "no such directory %s.\n", pw->pw_dir);
      exit(1);
    }
  
  db = dbopen(dbfilename, O_CREAT|O_RDWR|(iflag ? O_TRUNC : 0),
	      S_IRUSR|S_IWUSR, DB_HASH, NULL);
  if (!db) {
    msglog(LOG_NOTICE, "%s: %m\n", dbfilename);
    exit(1);
  }
  
  if (lflag)
    listdb();
  
  if (xflag) {
    char buf[MAXLINE], *p;
    
    while (fgets(buf, sizeof buf, stdin)) {
      if ((p = strchr(buf, '\n')) != NULL)
	*p = '\0';
      setreply(buf, strlen(buf), LONG_MAX);
    }
  }
  
  if (interval != -1)
    setreply(VIT, sizeof(VIT), interval);
  
  if (iflag || lflag || xflag) {
    (db->close)(db);
    exit(0);
  }
  
  if (argc == 0) {
    if (!isatty(1))
      usage();
    initialize(pw->pw_name);
  }
  
  cur = xmalloc(sizeof(ALIAS));
  cur->name = pw->pw_name;
  cur->next = names;
  names = cur;
  
  readheaders();
  if (!recent()) {
    setreply(from, strlen(from), time(NULL));
    (db->close)(db);
    sendmessage(zflag ? "<>" : pw->pw_name, msgfilename);
  }
  else
    (db->close)(db);
  exit(0);
  /* NOTREACHED */
}

/*
 * readheaders --
 *      read mail headers
 */
void readheaders(void)
{
  ALIAS *cur;
  char *p, *q;
  int tome, cont;
  char buf[MAXLINE];
  
  cont = tome = 0;
  while (fgets(buf, sizeof(buf), stdin) && *buf != '\n')
    switch(*buf) {
    case 'F':               /* "From " */
      cont = 0;
      if (!strncmp(buf, "From ", 5)) {
	for (p = buf + 5; *p && *p != ' '; ++p);
	*p = '\0';
	strcpy(from, buf + 5);
	if ((p = strchr(from, '\n')))
	  *p = '\0';
	if (junkmail())
	  discard_exit();
      }
      break;
    case 'R':               /* "Return-Path:" */
      /* EvB: this may use Name <addr@host> */
      cont = 0;
      if (strncasecmp(buf, "Return-Path:", 12) ||
	  (buf[12] != ' ' && buf[12] != '\t'))
	break;
      for (p = buf + 12; *p && isspace(*p); ++p);
      if ((q = strchr(p, '<'))) 
	p = q + 1;
      strncpy(from, p, sizeof(from));
      if ((p = strchr(from, '>')) || (p = strchr(from, '\n')))
	*p = '\0';
      if (junkmail())
	discard_exit();
      break;
    case 'P':               /* "Precedence:" */
      cont = 0;
      if (strncasecmp(buf, "Precedence", 10) ||
	  (buf[10] != ':' && buf[10] != ' ' &&
	   buf[10] != '\t'))
	break;
      if (!(p = strchr(buf, ':')))
	break;
      while (*++p && isspace(*p));
      if (!*p)
	break;
      if (!strncasecmp(p, "junk", 4) ||
	  !strncasecmp(p, "bulk", 4) ||
	  !strncasecmp(p, "list", 4))
	discard_exit();
      break;
    case 'S':               /* "Subject" */
      cont = 0;
      if (strncasecmp(buf, "Subject:", 8) ||
	  (buf[8] != ' ' && buf[8] != '\t'))
	break;
      for (p = buf + 8; *p && isspace(*p); ++p);
      strncpy(subj, p, sizeof(subj));
      if ((p = strchr(subj, '\n')))
	*p = '\0';
      break;
    case 'C':               /* "Cc:" */
      if (strncasecmp(buf, "Cc:", 3))
	break;
      cont = 1;
      goto findme;
    case 'T':               /* "To:" */
      if (strncasecmp(buf, "To:", 3))
	break;
      cont = 1;
      goto findme;
    default:
      if (!isspace(*buf) || !cont || tome) {
	cont = 0;
	break;
      }
    findme:                 for (cur = names; !tome && cur; cur = cur->next)
	tome += nsearch(cur->name, buf);
    }
  if (!tome && !jflag)
    discard_exit();
  if (!*from) {
    msglog(LOG_ERR, "no initial \"From\" line.\n");
    exit(1);
  }
}

/*
 * nsearch --
 *      do a nice, slow, search of a string for a substring.
 */
int nsearch(const char *name, const char *str)
{
  size_t len;
  const char c = tolower(*name);
  
  for (len = strlen(name); *str; ++str)
    if (tolower(*str) == c && !strncasecmp(name, str, len)
	&& isdelim((unsigned char)str[len]))
      return(1);
  return(0);
}

/*
 * junkmail --
 *      read the header and return if automagic/junk/bulk/list mail
 */
int junkmail(void)
{
  static struct ignore {
    const char      *name;
    int     len;
  } ignore[] = {
    { "-request", 8 },
    { "postmaster", 10 },
    { "uucp", 4 },
    { "mailer-daemon", 13 },
    { "mailer", 6 },
    { "-relay", 6 },
    { NULL, 0 }
  };
  struct ignore *cur;
  int len;
  char *p;
  
  /*
   * This is mildly amusing, and I'm not positive it's right; trying
   * to find the "real" name of the sender, assuming that addresses
   * will be some variant of:
   *
   * From site!site!SENDER%site.domain%site.domain@site.domain
   */
  if (!(p = strchr(from, '%')))
    if (!(p = strchr(from, '@'))) {
      if ((p = strrchr(from, '!')))
	++p;
      else
	p = from;
      for (; *p; ++p);
    }
  len = p - from;
  for (cur = ignore; cur->name; ++cur)
    if (len >= cur->len &&
	!strncasecmp(cur->name, p - cur->len, cur->len))
      return(1);
  return(0);
}

/*
 * recent --
 *      find out if user has gotten a vacation message recently.
 *      use memmove for machines with alignment restrictions
 */
int recent(void)
{
  time_t then, next, now = time(NULL);
  char *domain;
  
  /* get interval time */
  if ((next = lookup(VIT, sizeof(VIT))) == -1)
    next = SECSPERDAY * DAYSPERWEEK;
  
  /* get record for this address */
  if ((then = lookup(from, strlen(from))) != -1)
    if (next == LONG_MAX || then == LONG_MAX || then + next > now)
      return 1;
  if ((domain = strchr(from, '@')) == NULL)
    return 0;
  if ((then = lookup(domain, strlen(domain))) != -1)
    if (next == LONG_MAX || then == LONG_MAX || then + next > now)
      return 1;
  return 0;
}

/* lookup a record in the database */
time_t lookup(const char *s, size_t len)
{
  DBT key, data;
  time_t ret;
  
  key.data = (char *)s;
  key.size = len;
  if (!(db->get)(db, &key, &data, 0)) {
    memmove(&ret, data.data, sizeof(ret));
    return ret;
  }
  return -1;
}

/*
 * setreply --
 *      store that this user knows about the vacation.
 *      VIT must have a trailing \0, addresses must not.
 */
void setreply(const char *addr, size_t size, time_t when)
{
  DBT key, data;
  
  key.data = (char *)addr;
  key.size = size;
  data.data = &when;
  data.size = sizeof(when);
  (db->put)(db, &key, &data, 0);
}

/*
 * sendmessage --
 *      exec sendmail to send the vacation file to sender
 */
void sendmessage(const char *myname, const char *msgfile)
{
  FILE *mfp, *sfp;
  int i;
  int pvect[2];
  char buf[MAXLINE];
  
  mfp = fopen(msgfile, "r");
  if (mfp == NULL) {
    msglog(LOG_ERR, "no %s file.\n", msgfile);
    exit(1);
  }
  if (pipe(pvect) < 0) {
    msglog(LOG_ERR, "pipe: %m");
    exit(1);
  }
  i = fork();
  if (i < 0) {
    msglog(LOG_ERR, "fork: %m");
    exit(1);
  }
  if (i == 0) {
    dup2(pvect[0], 0);
    close(pvect[0]);
    close(pvect[1]);
    fclose(mfp);
    execl(_PATH_SENDMAIL, "sendmail", "-f", myname, "--",
	  from, NULL);
    msglog(LOG_ERR, "can't exec %s: %m", _PATH_SENDMAIL);
    exit(1);
  }
  close(pvect[0]);
  sfp = fdopen(pvect[1], "w");
  fprintf(sfp, "To: %s\n", from);
  while (fgets(buf, sizeof buf, mfp)) {
    char *s = strstr(buf, "$SUBJECT");
    if (s) {
      *s = 0;
      fputs(buf, sfp);
      fputs(subj, sfp);
      fputs(s + 8, sfp);
    } else {
      fputs(buf, sfp);
    }
  }
  fclose(mfp);
  fclose(sfp);
}

void usage(void)
{
  msglog(LOG_NOTICE, "uid %u: usage: vacation [-i] [-r interval] [-a alias] [-f db] [-m msg] [-j] [-l] [-x] [-z] login\n",
	 getuid());
  exit(1);
}

void listdb(void)
{
  DBT key, data;
  int rv;
  time_t t;
  char user[MAXLINE];
  
  while ((rv = (db->seq)(db, &key, &data, R_NEXT)) == 0) {
    memmove(user, key.data, key.size);
    user[key.size] = '\0';
    if (strcmp(user, VIT) == 0)
      continue;
    memmove(&t, data.data, data.size);
    printf("%-50s", user);
    if (t == LONG_MAX)
      puts("(never deleted)");
    else
      printf("%-10s", ctime(&t));
  }
  if (rv == -1)
    perror("IO error in database");
}

/*
 * Is `c' a delimiting character for a recipient name?
 */
int isdelim(int c)
{
  /*
   * NB: don't use setlocale() before, headers are supposed to
   * consist only of ASCII (aka. C locale) characters.
   */
  if (isalnum(c))
    return(0);
  if (c == '_' || c == '-' || c == '.')
    return(0);
  return(1);
}

/*
 * Append a message to the standard error for the convenience of end-users
 * debugging without access to the syslog messages.
 */
void debuglog(int i, const char *fmt, ...)
{
  va_list ap;
  
  i = 0;                  /* Printing syslog priority not implemented */
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);
}

/* read stdin and throw away everything we receive.  This keeps
 * mailers which are delivering to a pipe happy that we've deal with
 * the message sucessfully. */
void discard_exit(void)
{
  char buf[BUFSIZ];
  
  while (fread(buf, BUFSIZ, 1, stdin) > 0 && !feof(stdin));
  
  /* we exit, whether error happened while reading or not */
  exit(0);
}

void *xmalloc(size_t size)
{
  char *p = malloc(size);
  
  if (p != NULL)
    return p;
  msglog(LOG_ERR, "can't allocate memory");
  exit(75);                   /* EX_TEMPFAIL */
}

void initialize(const char *user)
{
  FILE *file;
  char buf[1024];
  int r;
  struct stat sb;
  const char *editor, *pager;
  
  if (stat(FWDBACKUP, &sb) == 0) {
    puts("You have a ~/" FWDBACKUP " file.");
    r = askyn("Do you want to restore it and disable the vacation"
	      " program (y/N)? ");
    if (r) {
      if (rename(FWDBACKUP, ".forward") < 0) {
	perror("rename");
	exit(1);
      }
      puts("The vacation program has been DISABLED.");
    } else
      puts("The vacation program is ENABLED.");
    exit(0);
  }
  
  if (!(editor = getenv("VISUAL")) && !(editor = getenv("EDITOR")))
    editor = "/usr/bin/sensible-editor";
  if (!(pager = getenv("PAGER")))
    pager = "/usr/bin/sensible-pager";
  
  puts("This program will answer your mail automatically when you"
       " go away on vacation.");
  
  if (stat(VMSG, &sb) < 0) {
    if (errno != ENOENT) {
      perror("stat");
      exit(1);
    }
    puts("You need to put in the ~/" VMSG " file the reply message.");
    r = askyn("Would you like to create it (y/N)? ");
    if (!r) {
      puts("OK, no file has been written.");
      exit(0);
    }
    
    file = fopen(VMSG, "w");
    if (!file) {
      perror("fopen(\".forward\")");
      exit(1);
    }
    fprintf(file,
	    "Subject: away from my mail\n"
	    "\n"
	    "I will not be reading my mail for a while.\n"
	    "Your mail concerning \"$SUBJECT\"\n"
	    "will be read when I return.\n"
	    );
    fclose(file);
  } else {
    puts("You have a message in ~/" VMSG ".");
    r = askyn("Would you like to see it (y/N)? ");
    if (r) {
      snprintf(buf, sizeof(buf), "%s " VMSG, pager);
      system(buf);
    }
    
    r = askyn("Would you like to edit it (y/N)? ");
    if (r) {
      snprintf(buf, sizeof(buf), "%s " VMSG, editor);
      system(buf);
    }
  }
  
  r = askyn("To enable the vacation program a '~/.forward' file is created.\n"
	    "Would you like to enable the vacation program (y/N)? ");
  if (!r) {
    puts("OK, the vacation program has not been enabled");
    exit(0);
  }
  
  file = fopen(".forward", "r");
  if (file) {
    puts("You have a '~/.forward' file containing:\n");
    while (fgets(buf, sizeof(buf), file)) {
      printf("    %s", buf);
    }
    fclose(file);
    puts("\nIt needs to be renamed before the vacation program"
	 " can be enabled.");
    r = askyn("Do you want to proceed (y/N)? ");
    if (!r) {
      puts("OK, the vacation program has not been enabled");
      exit(0);
    }
    if (rename(".forward", FWDBACKUP) < 0) {
      perror("rename");
      exit(1);
    }
  } else if (errno != ENOENT) {
    perror("fopen(\".forward\")");
    exit(1);
  }
  
  if ((file = fopen(".forward", "w")) == NULL) {
    perror("fopen(\".forward\")");
    exit(1);
  }
  fprintf(file, "\\%s, \"|" PATH_VACATION " %s\"\n", user, user);
  puts("The vacation program is ENABLED.\n"
       "Please remember to turn it off when you get back from vacation.");
  exit(0);
}

int askyn(const char *question)
{
  char buf[32];
  
  fprintf(stdout, "%s", question);
  while (1) {
    fgets(buf, sizeof(buf), stdin);
    if (!buf || *buf == '\n' || *buf == 'n' || *buf == 'N')
      return 0;
    if (*buf == 'y' || *buf == 'Y')
      return 1;
    fputs("Please reply 'yes' or 'no' ('y' or 'n'): ", stdout);
  }
}
