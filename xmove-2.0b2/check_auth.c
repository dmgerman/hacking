/*                            xmove
 *                            -----
 *             A Pseudoserver For Client Mobility
 *
 *   Copyright (c) 1994         Ethan Solomita
 *
 *   The X Consortium, and any party obtaining a copy of these files from
 *   the X Consortium, directly or indirectly, is granted, free of charge, a
 *   full and unrestricted irrevocable, world-wide, paid up, royalty-free,
 *   nonexclusive right and license to deal in this software and
 *   documentation files (the "Software"), including without limitation the
 *   rights to use, copy, modify, merge, publish, distribute, sublicense,
 *   and/or sell copies of the Software, and to permit persons who receive
 *   copies from any such party to do so.  This license includes without
 *   limitation a license to do the foregoing actions under any patents of
 *   the party supplying this software to the X Consortium.
 */
#include "xmove.h"
#include "string.h"

static char MagicCookie[] = "MIT-MAGIC-COOKIE-1";
static int MagicCookieLen = 18;

Global Bool
CheckAuth(typelen, type, keylen, key)
int typelen;
unsigned char *type;
int keylen;
unsigned char *key;
{
     /* Reset OldAuthKeyLen to 0, unless this connection is being permitted
      * only because it is using OldAuthKey. If so, keep OldAuthKey for now.
      * This is because some clients make multiple connections to the server
      * at startup, and hence we may have several incoming new connections,
      * all using the old key.
      */

     if (client->authorized)
     {
	  OldAuthKeyLen = 0;
	  return True;
     }
     
     if (typelen != MagicCookieLen || strncmp((char *)type, MagicCookie, MagicCookieLen) != 0)
     {
	  return False;
     }
     
     if (OldAuthKeyLen && keylen == OldAuthKeyLen && strncmp(OldAuthKey, (char *)key, OldAuthKeyLen) == 0)
     {
	  client->authorized = True;
	  return True;
     }
     
     OldAuthKeyLen = 0;
     
     if (AuthKeyLen && keylen == AuthKeyLen && strncmp(AuthKey, (char *)key, AuthKeyLen) == 0)
     {
	  client->authorized = True;
	  return True;
     }
     
     return False;
}

/* In order to support new connections on machines with
 * authorization schemes, xmove first uses xauth to find the code
 * for the default server. If xauth returned a code, xmove then
 * invokes xauth to add that same code for xmove's address. This
 * way both will have the same code and the client's authorization
 * can simply be passed through. Moving clients will require a
 * new authorization code, provided by xmovectrl.
 *
 * If we are updating and we find that the default server's magic
 * cookie has changed, we store the old AuthKey in OldAuthKey. This
 * is because InitMagicCookie() is called in update mode because a
 * client connected to xmove, and xmove found that xmove had a bad
 * cookie. The client will still be attempting to connect with the
 * original cookie, and we should pass it through.
 */

Global void
InitMagicCookie(char *DefaultHost, char *LocalHostName, int ListenForClientsPort, Bool update)
{
     FILE *xauth;
     char shellcmd[1024];
     char authhex[512], authkey[512];
     char *curauthhex = authhex;
     char *curauthkey = update ? authkey : AuthKey;
     int retcnt, authkeylen;

     sprintf(shellcmd, "xauth list %s 2>/dev/null", DefaultHost);
     if (!(xauth = popen(shellcmd, "r")))
	  goto DEFAULT_AUTH;
     retcnt = fscanf(xauth, "%*s %255s %255s", AuthType, authhex);
     (void)pclose(xauth);

     if (retcnt != 2)
	  goto DEFAULT_AUTH;

     if (strcmp(AuthType, "MIT-MAGIC-COOKIE-1") != 0) {
	  fprintf(stderr, "Unable to support %s user authentication\n", AuthType);
	  goto DEFAULT_AUTH;
     }

     while (*curauthhex != '\0') {
	  int newval;
	  
	  sscanf(curauthhex, "%2x", &newval);
	  curauthhex += 2;
	  *(u_char *)curauthkey = (u_char)newval;
	  curauthkey++;
     }

     if (update) {
	  authkeylen = curauthkey - authkey;
	  
	  if (AuthKeyLen == authkeylen && strncmp(AuthKey, authkey, AuthKeyLen) == 0)
	       return;		/* no change in xauth info */
     
	  OldAuthKeyLen = AuthKeyLen;
	  bcopy(AuthKey, OldAuthKey, AuthKeyLen);

	  AuthKeyLen = authkeylen;
	  bcopy(authkey, AuthKey, authkeylen);
     } else {
	  OldAuthKeyLen = 0;
	  AuthKeyLen = curauthkey - AuthKey;
     }

     sprintf(shellcmd, "xauth add %s:%d %s %s", LocalHostName, ListenForClientsPort, AuthType, authhex);
     if (system(shellcmd) != 0) {
	  write(2, "Unable to execute xauth. User authentication not enabled\n", 57);
	  goto DEFAULT_AUTH;
     }
     
     sprintf(shellcmd, "xauth add %s/unix:%d %s %s", LocalHostName, ListenForClientsPort, AuthType, authhex);
     if (system(shellcmd) != 0) {
	  write(2, "Unable to execute xauth. User authentication not enabled\n", 57);
	  goto DEFAULT_AUTH;
     }
     
     write(1, "Implementing MIT-MAGIC-COOKIE-1 user authentication\n", 52);
     
     return;

 DEFAULT_AUTH:
     if (update) {
	  OldAuthKeyLen = AuthKeyLen;
	  bcopy(AuthKey, OldAuthKey, AuthKeyLen);
     } else
	  OldAuthKeyLen = 0;
     
     AuthKeyLen = 0;

     return;
}
