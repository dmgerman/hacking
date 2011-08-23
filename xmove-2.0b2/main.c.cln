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
/*
 * Project: XMON - An X protocol monitor
 *
 * File: main.c
 *
 * Description: Contains main() for xmond
 *
 */

#include <sys/types.h>         /* needed by sys/socket.h and netinet/in.h */
#include <sys/uio.h>           /* for struct iovec, used by socket.h */
#include <sys/socket.h>        /* for AF_INET, SOCK_STREAM, ... */
#include <sys/ioctl.h>         /* for FIONCLEX, FIONBIO, ... */
#if defined(SYSV) || defined(SVR4)
#include <sys/fcntl.h>
#ifndef FD_CLOEXEC
#define FD_CLOEXEC 1
#endif
#endif
#include <sys/time.h>
#include <netinet/in.h>        /* struct sockaddr_in */
#include <netinet/tcp.h>       /* TCP_NODELAY */
#include <netdb.h>             /* struct servent * and struct hostent * */
#include <errno.h>             /* for EINTR, EADDRINUSE, ... */
#include <signal.h>
#define NEED_REPLIES
#include <X11/Xproto.h>
#include <malloc.h>

#if defined(DL_W_PRAGMA) || defined(DL_WOUT_PRAGMA)
#include <dlfcn.h>
#include <dirent.h>
#endif

#include "xmove.h"

#define BACKLOG				5
#define XBasePort			6000

/* function prototypes: */
/* main.c: */
static void ScanArgs P((int argc , char **argv ));
static void InitializeMappingLibs P((void ));
static int  SetUpConnectionSocket P((int iport ));
static void SetSignalHandling P((void ));
static void MainLoop P((void ));
       Bool SendXmoveBuffer P((int fd , Buffer *buffer ));
static short GetScopePort P((void ));
static void Usage P((void ));
static void NewConnection P((Pointer private_data ));
static void RemoveSavedBytes P((Buffer *buffer , int n ));
static int ConnectToClient P((int ConnectionSocket , unsigned long *ip_addr ));
/*static char *OfficialName P((char *name ));*/
static void ResizeBuffer P((Buffer *buffer, long len));
static char *SetDefaultServer P((char *server_name));
#ifdef SVR4
static void SignalURG P((int signum ));
static void SignalPIPE P((int signum ));
static void SignalINT P((int signum ));
static void SignalQUIT P((int signum ));
static void SignalTERM P((int signum ));
static void SignalTSTP P((int signum ));
static void SignalCONT P((int signum ));
#else
static void SignalURG P((void));
static void SignalPIPE P((void ));
static void SignalINT P((void ));
static void SignalQUIT P((void ));
static void SignalTERM P((void ));
static void SignalTSTP P((void ));
static void SignalCONT P((void ));
#endif

extern char *getenv();
extern int ServerPacket P((Pointer private_data , unsigned char *buf, long n ));

/* end function prototypes */

Global Server  *server;		/* current server */
Global Client  *client;		/* current client */
Global MetaClient *meta_client;
Global int     NewConnFD;
Global Bool    ignore_bytes;
Global Bool    do_poll = False;
Global Bool    PrintDebug = False;              /* print debugging info? */
Global Bool    EthanPrintDebug = False;
Global int     RequestVerbose = 0;		/* verbose level for requests */
Global int     EventVerbose = 0;		/* verbose level for events */
Global int     ReplyVerbose = 0;		/* verbose level for replies */
Global int     ErrorVerbose = 0;		/* verbose level for error */
Global char    *LocalHostName;
Global int     debuglevel = 0;
Global int     ethandebuglevel = 0;
Global LinkList	client_list;		/* list of Client */
Global LinkList meta_client_list;
Global LinkList AtomMappings;
Global LinkList AtomTypeMappings;
Global FDDescriptor *FDD;
Global long		ReadDescriptors[mskcnt];
Global long		WriteDescriptors[mskcnt];
Global short	HighestFD;
Global Bool	littleEndian, XmoveLittleEndian;
Global unsigned long HostIPAddr;
Global char AuthKey[256], AuthType[256];
Global char OldAuthKey[256];	/* see check_auth.c:InitMagicCookie() */
Global int AuthKeyLen, OldAuthKeyLen;
Global unsigned char ValidSetUpMessage[12];
Global Bool processing_server;

static long ClientNumber = 0;
static long MetaClientNumber = 0;
static int  ServerPort = 0;
Global int  ServerScreen = 0;
static int  ListenForClientsPort = 1;
static char ServerHostName[255];
static char DefaultHost[256];

Global void
main(argc, argv)
int     argc;
char  **argv;
{
    int i = 1;

    /* figure out whether we are on a little-endian or big-endian machine */
    XmoveLittleEndian = ((*(char *)&i) == 1);
    
    ScanArgs(argc, argv);
    InitializeFD();
    InitializeX11();
    InitXMove();
    InitMagicCookie(DefaultHost, LocalHostName, ListenForClientsPort, False);
    
    NewConnFD = SetUpConnectionSocket(GetScopePort());
    SetSignalHandling();
    initList(&client_list);
    initList(&meta_client_list);
    initList(&AtomMappings);
    initList(&AtomTypeMappings);

    InitializeMappingLibs();

    fprintf(stdout, "XMove 2.0 ready.\n");
    MainLoop();
}

static void
InitializeMappingLibs()
{
#if !defined(DL_W_PRAGMA) && !defined(DL_WOUT_PRAGMA)
     
     /* if we aren't using dynamically loaded libraries, just call the
	initialization routine directly. */
     
     initialize();
     return;
     
#else
     
     void *dlopenhandle;
     void (*initialize)();

     char *libpath = getenv("XMOVE_ATOMMAP_LIBPATH");
     int libpathlen;
     char fullpath[512];
     char *version, *sub_version;
     DIR *dir;
     struct dirent *curdir;
     int curdirnamlen;

     if (libpath == NULL)
	  libpath = ATOMMAP_LIBPATH; /* defined in Imakefile */

     if ((libpathlen = strlen(libpath)) == 0)
	  return;

     if ((dir = opendir(libpath)) == NULL)
	  return;

     /* fullpath receives a copy of the path now, and has the filename
	being referenced appended after the path before each call to
	dlopen(). */

     memcpy(fullpath, libpath, libpathlen);
     if (fullpath[libpathlen-1] != '/')
	  fullpath[libpathlen++] = '/';
     
     while (curdir = readdir(dir)) {
	  version = strstr(curdir->d_name, ".so.");
	  if (version == NULL)
	       continue;

	  version += 4;		/* skip ".so." */
	  
	  /* only load a library if it is a version 1 library */
	  /* if there is more to the name (aka .so.1.1 instead of just
	     .so.1) then ignore it. */
	  
	  if ((strtol(version, &sub_version, 10) != 1) || (*sub_version != '\0'))
	       continue;
	  
	  curdirnamlen = strlen(curdir->d_name);
	  memcpy(fullpath + libpathlen, curdir->d_name, curdirnamlen);
	  fullpath[libpathlen + curdirnamlen] = '\0';
	  
	  if ((dlopenhandle = dlopen(fullpath, 1)) == NULL)
	       continue;

#ifdef DL_WOUT_PRAGMA
	  if ((initialize = (void(*)())dlsym(dlopenhandle, "initialize")) == (void(*)())NULL) {
	       dlclose(dlopenhandle);
	       continue;
	  }
	  
	  (*initialize)();
#endif

	  printf ("Loaded mapping library %s\n", fullpath);
     }

     closedir(dir);

#endif

}

Global void
CloseConnection(Client *client)
{
	Server *server = client->server;
	MetaClient *meta_client = client->meta_client;
	
	Dprintf(("CloseConnection: client = %d, server = %d\n",
	       client->fdd->fd, server ? (server->fdd ? server->fdd->fd : -1) : -1));
	
	if (client->fdd->outBuffer.BlockSize > 0)
		Tfree(client->fdd->outBuffer.data - client->fdd->outBuffer.data_offset);
	if (client->fdd->inBuffer.BlockSize > 0)
		Tfree(client->fdd->inBuffer.data - client->fdd->inBuffer.data_offset);
	close(client->fdd->fd);
	NotUsingFD(client->fdd->fd);

	RemoveClientFromMetaClient(meta_client, client);
	if (ListIsEmpty(&meta_client->client_list)) {
	     RemoveMetaClient(meta_client);
	     free(meta_client);
	}
	     
	if (server) {
	     if (server->fdd && server->fdd->InputHandler) {
		  close(server->fdd->fd);
		  NotUsingFD(server->fdd->fd);
	     }

	     FreeServerLists(server);
	}
	
	FreeClientLists(client);
	freeMatchingLeaf(&client_list, (Pointer)client);
}

static void
ScanArgs(int argc, char **argv)
{
	int i;
	char *string = NULL;

	ServerHostName[0] = '\0';
	DefaultHost[0] = '\0';
	/* Scan argument list */
	for (i = 1; i < argc; i++)
	{
		if (Streq(argv[i], "-server") || Streq(argv[i], "-display"))
		{
			/*	Generally of the form server_name:display_number.
			 *	These all mean port 0 on server blah:
			 *		"blah",
			 *		"blah:",
			 *		"blah:0"
			 *	This means port 0 on local host: ":0".
			 */
			if (++i < argc)
				string = argv[i];
			else
				Usage();
			debug(1,(stderr, "ServerHostName=%s\n", ServerHostName));
		}
		else if (Streq(argv[i], "-port"))
		{
			if (++i < argc)
				ListenForClientsPort = atoi(argv[i]);
			else
				Usage();
			if (ListenForClientsPort <= 0)
				ListenForClientsPort = 0;
			debug(1,(stderr, "ListenForClientsPort=%d\n",ListenForClientsPort));
		}
		else if (Streq(argv[i], "-debug"))
		{
			/*
			  debug levels:
			  1 - print debugging printfs
			  2 - trace each procedure entry
			  4 - I/O, connections
			  8 - Scope internals
			  16 - Message protocol
			  32 - 64 - malloc
			  128 - 256 - really low level
			  */
			if (++i < argc)
				debuglevel = atoi(argv[i]);
			else
				Usage();
			if (debuglevel == 0)
				debuglevel = 255;
			else
				PrintDebug = True;
   
			debuglevel |= 1;
			debug(1,(stderr, "debuglevel = %d\n", debuglevel));
		}
		else if (Streq(argv[i], "-ethan"))
		{
			ethandebuglevel = 1;
			EthanPrintDebug = True;
			fprintf(stderr, "Ethan is watching...\n");
		}
		else if (Streq(argv[i], "-verbose"))
		{
			if (++i < argc)
				RequestVerbose = EventVerbose =
					ReplyVerbose = ErrorVerbose = atoi(argv[i]);
			else
				Usage();
		}
		else
			Usage();
	}

	LocalHostName = (char *)malloc(255);
	(void) gethostname(LocalHostName, 255);

	if (string == NULL)
		string = getenv("DISPLAY");

	string = SetDefaultServer(string);

	if (string) {
		fprintf (stderr, "%s", string);
		Usage();
	}
}

/*
 * SetUpConnectionSocket:
 *
 * Create a socket for a service to listen for clients
 */
static int
SetUpConnectionSocket(iport)
int                     iport;
{
     int                   ON = 1;         /* used in ioctl */
     int                    ConnectionSocket;
     struct sockaddr_in    sin;

     enterprocedure("SetUpConnectionSocket");

     /* create the connection socket and set its parameters of use */
     ConnectionSocket = socket(AF_INET, SOCK_STREAM, 0);
     if (ConnectionSocket < 0)
     {
	  perror("socket");
	  exit(-1);
     }

#ifdef SO_REUSEADDR
     (void)setsockopt(ConnectionSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&ON, sizeof(int));
#endif
#ifdef SO_REUSEPORT
     (void)setsockopt(ConnectionSocket, SOL_SOCKET, SO_REUSEPORT, (char *)&ON, sizeof(int));
#endif
#ifdef SO_USELOOPBACK
     (void)setsockopt(ConnectionSocket, SOL_SOCKET, SO_USELOOPBACK, (char*)NULL,0);
#endif
#ifdef SO_DONTLINGER
     (void)setsockopt(ConnectionSocket, SOL_SOCKET, SO_DONTLINGER, (char*)NULL, 0);
#endif

     /* define the name and port to be used with the connection socket */
     bzero((char *)&sin, sizeof(sin));
     sin.sin_family = AF_INET;

     /* the address of the socket is composed of two parts: the host
	machine and the port number.  We need the host machine address
	for the current host */
     {
     /* define the host part of the address */
		struct hostent *hp;

		hp = gethostbyname(LocalHostName);
		if (hp == NULL)
			panic("No address for our host"); /* and exit */
                bcopy((char *)hp->h_addr, (char*)&HostIPAddr, 4);
		bcopy((char *)hp->h_addr, (char*)&sin.sin_addr, hp->h_length);
	}

	/* new code -- INADDR_ANY should be better than using the name of the
	   host machine.  The host machine may have several different network
	   addresses.  INADDR_ANY should work with all of them at once. */

	sin.sin_addr.s_addr = INADDR_ANY;

	sin.sin_port = htons (iport);

	/* bind the name and port number to the connection socket */
	if (bind(ConnectionSocket, (struct sockaddr *)&sin, sizeof(sin)) < 0)
		{
			perror("bind");
			fprintf(stderr, "Is another xmove server running on the same port?\n"
				"If not, you may have to wait 5-10 minutes for TCP to\n"
				"allow xmove to be restarted. This can often be prevented by\n"
				"not having the xmove server crash while applications are\n"
				"using it.\n");

			exit(-1);
		}

	debug(4,(stderr, "Socket is FD %d for %s,%d\n",
					ConnectionSocket, LocalHostName, iport));

	/* now activate the named connection socket to get messages */
        if (listen(ConnectionSocket, BACKLOG) < 0)
		{
			perror("listen");
			exit(-1);
		};

	/* a few more parameter settings */

#if defined(FD_CLOEXEC) && defined(F_SETFD)
	fcntl(ConnectionSocket, F_SETFD, FD_CLOEXEC);
#else
#ifdef FIOCLEX
	ioctl(ConnectionSocket, FIOCLEX, 0);
#endif
#endif

#if defined(F_SETFL) && defined(O_NONBLOCK)
        fcntl(ConnectionSocket, F_SETFL, O_NONBLOCK |
              fcntl(ConnectionSocket, F_GETFL, NULL));
#else
#ifdef FIONBIO
	ioctl(ConnectionSocket, FIONBIO, (char *)&ON);
#endif
#endif

	debug(4,(stderr, "Listening on FD %d\n", ConnectionSocket));
        (void)UsingFD(ConnectionSocket, NewConnection, (Pointer)ConnectionSocket);
        FDD[ConnectionSocket].inBuffer.num_Needed = 0;
        return(ConnectionSocket);
}

/*
 * Signal Handling support
 */
static void
SetSignalHandling()
{
	enterprocedure("SetSignalHandling");
	signal(SIGURG, SignalURG);
	signal(SIGPIPE, SignalPIPE);
	signal(SIGINT, SignalINT);
	signal(SIGQUIT, SignalQUIT);
	signal(SIGTERM, SignalTERM);
	signal(SIGTSTP, SignalTSTP);
	signal(SIGCONT, SignalCONT);
}

/*
 * MainLoop:
 * 
 * Wait for input from any source and Process.
 */
static void
MainLoop()
{
     u_long	rfds[mskcnt];
     u_long	wfds[mskcnt];
     short	nfds;
     int        mskloop;
     struct timeval tv = {0, 0};

     while (True)
     {
	  
	  for (mskloop = 0; mskloop <= (HighestFD>>5) && mskloop < mskcnt; mskloop++) {
	       rfds[mskloop] = ReadDescriptors[mskloop];
	       wfds[mskloop] = WriteDescriptors[mskloop];
	  }
	  
#ifdef hpux
#define seltype int *
#else
#define seltype fd_set *
#endif

	  nfds = select(HighestFD + 1, (seltype)rfds, (seltype)wfds, NULL,
			(do_poll ? &tv : NULL));
	  do_poll = False;

#undef seltype

	  if (nfds < 0)
	  {
	       if (errno != EINTR)
		    if (errno == EBADF)
			 EOFonFD(HighestFD);
		    else
			 panic("Select returns error");
	  }
	  else
	  {
	       int cur_fd;
	       
	       for (mskloop = 0; mskloop <= (HighestFD>>5) && mskloop < mskcnt; mskloop++) {
		    cur_fd = mskloop << 5;
		    
		    while (wfds[mskloop]) {
			    if ((wfds[mskloop] & 1) && FDD[cur_fd].InputHandler)
				    SendXmoveBuffer(cur_fd, &FDD[cur_fd].outBuffer);
			 
			    cur_fd++;
			    wfds[mskloop] >>= 1;
		    }
	       }
	       
	       /* this is where all the parsing/printing gets */
	       /* done.  One little innocuous call.. */
	       
	       /* note we call the input handler if select told us there was
		  something to read, *or* if there is enough data saved up to
		  process something. This is a kludge but it should be safe
		  enough. Because of ReceiveReply(), it is possible
		  to read data from the server, save it in the inbuffer, and
		  then not process it then-and-there. Since this only happens
		  to the server, and realistically the server has a higher FD
		  than the client since it was opened after the client connection,
		  this should pick up the fact that there is data in the server
		  which was added there as the client was processed. *whew* */

	       for (mskloop = 0; mskloop <= (HighestFD>>5) && mskloop < mskcnt; mskloop++) {
		    cur_fd = mskloop << 5;
		    
		    while (cur_fd < ((mskloop + 1) << 5) && cur_fd <= HighestFD) {
			    if (FDD[cur_fd].InputHandler &&
				((rfds[mskloop] & 1) ||
				 ((FDD[cur_fd].inBuffer.num_Needed &&
				   FDD[cur_fd].inBuffer.num_Saved >=
				   FDD[cur_fd].inBuffer.num_Needed))))
			    {
				    (FDD[cur_fd].InputHandler)(FDD[cur_fd].private_data);
			    }			    
			    cur_fd++;
			    rfds[mskloop] >>= 1;
		    }
	       }
	  }
     }
}

Bool
SendXmoveBuffer(int fd, Buffer *buffer)
{
	int   tot_written = 0;
	int   BytesToWrite = 0;
	int   num_written = 1;
	u_char *curbuf;
	
	if (!buffer->num_Saved)
		return True;
	
	curbuf = buffer->data;
	BytesToWrite = buffer->num_Saved;

	while (num_written > 0 && BytesToWrite > 0) {
		num_written = write(fd, (char *)curbuf, BytesToWrite);
		
		if (num_written > 0) {
			curbuf += num_written;
			BytesToWrite -= num_written;
		}
	}		
	tot_written = buffer->num_Saved - BytesToWrite;
     
	if (buffer->num_Saved > 128*1024 && (buffer->num_Saved - tot_written) <= 128*1024)
		BITSET(ReadDescriptors, buffer->src_fd);
	
	if (tot_written < buffer->num_Saved)
	{
		if (tot_written == 0 &&
		    (errno != EWOULDBLOCK && errno != EINTR && errno != EAGAIN))
		{
			perror("Error on write to Client/Server");
			return False;
		} else {
			debug(4,(stderr, "write is blocked: buffering output\n"));
		}
	}
	RemoveSavedBytes(buffer, tot_written);
	if (buffer->num_Saved) {
		BITSET(WriteDescriptors, fd);
	} else {
		BITCLEAR(WriteDescriptors, fd);
	}
	return True;
}

static short
GetScopePort ()
{
	short     port;

	enterprocedure("GetScopePort");

	port = XBasePort + ListenForClientsPort;
	debug(4,(stderr, "xmove service is on port %d\n", port));
	return(port);
}

static void
Usage()
{
	fprintf(stderr, "Usage: xmove\n");
	fprintf(stderr, "              [-server <server_name:port>]\n");
	fprintf(stderr, "              [-port <listen_port>]\n");
	fprintf(stderr, "              [-verbose <output_level>]\n");
	exit(1);
}

/*
 * NewConnection:
 * 
 * Create New Connection to a client program and to Server.
 */
static void
NewConnection(private_data)
Pointer private_data;
{
    int	   XPort = (int)private_data;
    int	   fd, ServerFD, size, validate;
    u_long ip_addr;

    fd = ConnectToClient(XPort, &ip_addr);
    
    /* connect to server, send ListHosts requests to find
     * if this ip_addr is permitted access to the server.
     * if not, we will later compare its MAGIC-COOKIE,
     * if it sends one.
     */

    validate = ValidateNewConnection(ip_addr);

    meta_client = malloc(sizeof(MetaClient));
    appendToList(&meta_client_list, (Pointer)meta_client);
    initList(&meta_client->client_list);
/*    meta_client->move_state = moveStable;*/

    client = Tcalloc(1, Client);
    appendToList(&client_list, (Pointer)client);
    appendToList(&meta_client->client_list, (Pointer)client);
/*    client->ip_addr = ip_addr;*/
    client->fdd = UsingFD(fd, DataFromClient, (Pointer)client);
    client->fdd->fd = fd;
    client->meta_client = meta_client;
    if (validate == 1)
	 client->authorized = True;

    initList(&client->resource_maps);
    client->server = server = Tcalloc(1, Server);

    client->window_table       = hash_new(127);
    client->pixmap_table       = hash_new(127);
    client->font_table         = hash_new(31);
    client->glyph_cursor_table = hash_new(63);
    client->cursor_table       = hash_new(63);
    client->gc_table           = hash_new(127);
    client->atom_table         = hash_new(127);
    initList(&client->grab_list);
    initList(&client->selection_list);
    initList(&client->colormap_list);

    client->min_keycode = 0x0;
    client->max_keycode = 0x0;
    client->xmoved_from_elsewhere = False;
    client->xmoved_to_elsewhere = False;
    client->never_moved = True;

    /* now initialize the server */

    server->client = client;

    /* name this server, so that when we list the clients, we can know */
    /* what client is what */

    size = strlen(ServerHostName) + 4 + (ServerPort < 10 ? 1 : 2);
    server->server_name = malloc(size * sizeof(char));
    sprintf(server->server_name, "%s:%d", ServerHostName, ServerPort);

    /* open socket to server */
    ServerFD = ConnectToServer(ServerHostName, ServerPort, NULL);
    if (ServerFD < 0) {
/*	 close(fd);
	 fprintf(stderr, "error: unable to connect to server\n");
	 return;*/

	 server->fdd = NULL;
    } else {
	 server->fdd = UsingFD(ServerFD, DataFromServer, (Pointer)server);
	 server->fdd->fd = ServerFD;
    }
    
    StartServerConnection(server);
    StartClientConnection(client); /* must be called after server->fdd init */
    
    client->ClientNumber = ++ClientNumber;
    meta_client->meta_id = ++MetaClientNumber;
}

Global void
DataFromClient(private_data)
Pointer	private_data;
{
     client = (Client *)private_data;
     meta_client = client->meta_client;
     server = client->server;
     
     processing_server = False;
     if (!ReadAndProcessData(private_data, client->fdd, server->fdd, False))
	  CloseConnection(client);
}

Global void
DataFromServer(private_data)
Pointer	private_data;
{
     server = (Server *)private_data;
     client = server->client;
     meta_client = client->meta_client;
     
     processing_server = True;
     if (!ReadAndProcessData(private_data, server->fdd, client->fdd, True))
	  CloseConnection(client);
}

/*
 * ReadAndProcessData:
 * 
 * Read as much as we can and then loop as long as we have enough
 * bytes to do anything.
 * 
 * In each cycle check if we have enough bytes (saved or in the newly read
 * buffer) to do something.  If so, we want the bytes to be grouped
 * together into one contiguous block of bytes.  We have three cases:
 * 
 * (1) num_Saved == 0; so all needed bytes are in the read buffer.
 * 
 * (2) num_Saved >= num_Needed; in this case all needed
 * bytes are in the save buffer and we will not need to copy any extra
 * bytes from the read buffer into the save buffer.
 * 
 * (3) 0 < num_Saved < num_Needed; so some bytes are in
 * the save buffer and others are in the read buffer.  In this case we
 * need to copy some of the bytes from the read buffer to the save buffer
 * to get as many bytes as we need, then use these bytes.  First determine
 * the number of bytes we need to transfer; then transfer them and remove
 * them from the read buffer.  (There may be additional requests in the
 * read buffer - we'll deal with them next cycle.)
 * 
 * At this stage, we have a pointer to a contiguous block of
 * num_Needed bytes that we should process.  The type of
 * processing depends upon the state we are in, given in the
 * ByteProcessing field of the FDDescriptor structure pointed to by
 * read_fdd.  The processing routine returns the number of bytes that it
 * actually used.
 * 
 * The number of bytes that were actually used is normally (but not
 * always) the number of bytes needed.  Discard the bytes that were
 * actually used, not the bytes that were needed.  The number of used
 * bytes must be less than or equal to the number of needed bytes.  If
 * there were no saved bytes, then the bytes that were used must have been
 * in the read buffer so just modify the buffer pointer.  Otherwise call
 * RemoveSavedBytes.
 * 
 * After leaving the loop, if there are still some bytes left in the read
 * buffer append the newly read bytes to the save buffer.
 *
 * Return False if we reached end-of-file on read.
 */

Global Bool
     ReadAndProcessData(Pointer private_data, 
			FDDescriptor *read_fdd,
			FDDescriptor *write_fdd,
			Bool is_server)
{
	Buffer	   *inbuffer    = &read_fdd->inBuffer;
	unsigned char *process_buf = inbuffer->data;
	Buffer	   *outbuffer   = write_fdd ? &write_fdd->outBuffer : NULL;
	int            write_fd    = write_fdd ? write_fdd->fd : -1;
	int	    num_read;
	int	    NumberofUsedBytes, BytesRemaining;

	/* a single call to read() will return no more bytes than the TCP window size, which is
	   currently 4K for SunOS 4.1.x, and 33580 bytes for SunOS 5.x, by default. We should
	   prepare to read in num_Saved + window_size, but we read in + 64*1024. */
	
	ResizeBuffer(inbuffer, inbuffer->num_Saved + 64*1024);
     
	num_read = read(read_fdd->fd, (char *)inbuffer->data + inbuffer->num_Saved, 64*1024);

	if (num_read == 0 && inbuffer->num_Saved < inbuffer->num_Needed) {
		if (ErrorVerbose > 1)
			fprintf(stdout, "EOF\n");
		return False;
	}
     
	if (num_read < 0) {
		if (inbuffer->num_Saved < inbuffer->num_Needed) {
			if (errno != EWOULDBLOCK && errno != EINTR && errno != EAGAIN)
				return False;
			else
				return True;	/* we were told there was data and there wasn't. */
		}
		num_read = 0;
	}
     
	inbuffer->num_Saved += num_read;
     
	/* set the endian setting for this particular connection, before */
	/* we process any of the information.  If this is not set, then we */
	/* will not be able to understand what values are flying over the */
	/* connection */
     
	littleEndian = read_fdd->littleEndian;
     
	/* if we are just passing data through, save bytes onto output buffer
	   and ignore contents. */
     
	if (read_fdd->pass_through) {
		if (!outbuffer)
			return False;
	  
		SaveBytes(outbuffer, inbuffer->data, inbuffer->num_Saved);
		SendXmoveBuffer(write_fd, outbuffer);
		RemoveSavedBytes(inbuffer, inbuffer->num_Saved);
		return True;
	}
     
	/* 9/13/94 Pre-process the incoming data. Modify the sequence number
	 * if the data comes from the server.
	 */

	if (is_server && server->fdd->ByteProcessing == ServerPacket) {
		u_int curlen;
	  
		process_buf = inbuffer->data;
		BytesRemaining = inbuffer->num_Saved;
	  
		/* if we read in less than the first 8 bytes of a message
		 * the last time, we haven't processed it yet, so process
		 * it now.
		 */
	  
		if (BytesRemaining - num_read < 8)
			num_read = BytesRemaining;
	  
		while (BytesRemaining >= 8)
		{
			/* don't mess with what you don't understand */
			if (((u_char)(process_buf[0] & 0x7F)) > (u_char)MAX_EVENT) {
				fprintf(stderr, "xmove: couldn't adjust sequence number"
					" -- xmove may be unstable\n");
				break;
			}

			/* modify seqno only if this server packet is newly read()
			 * and if it is not KeymapNotify Event, which has no seqno
			 */
	       
			if (BytesRemaining <= num_read && ((process_buf[0] & 0x7F) != 11)) {
				ISetShort(&process_buf[2],
					  (u_short)(IShort(&process_buf[2]) + client->SequenceMapping));
			}

			if (process_buf[0] == 1)
				curlen = 32 + (ILong(&process_buf[4]) << 2);
			else
				curlen = 32;
	       
			process_buf += curlen;
			BytesRemaining -= curlen;
		}

		/* if (0 < BytesRemaining < 8) then process_buf points to the start of
		 * an incomplete msg from the server. if (BytesRemaining < 0) then we
		 * just processed a msg that we haven't entirely read yet, so
		 * process_buf - curlen points to the start. Else, if (BytesRemaining == 0),
		 * the last msg we read was complete.
		 */
	  
		if (BytesRemaining > 0) {
			inbuffer->incomplete_data = process_buf;
			Eprintf(("ETHAN: ReadAndProcessData 1 set incomplete_data, BytesRemaining %d\n", BytesRemaining));
		} else if (BytesRemaining < 0) {
			inbuffer->incomplete_data = process_buf - curlen;
			Eprintf(("ETHAN: ReadAndProcessData 2 set incomplete_data, BytesRemaining %d\n", BytesRemaining));
		} else {
			if (inbuffer->incomplete_data)
				Eprintf(("ETHAN: ReadAndProcessData clearing incomplete_data\n"));
			inbuffer->incomplete_data = NULL;
		}
	}

     
	while (inbuffer->num_Saved >= inbuffer->num_Needed)
	{
		process_buf = inbuffer->data;
		BytesRemaining = inbuffer->num_Saved;

		/* at this point, we have all the bytes that we were told we */
		/* need, so let's go ahead and process this buffer */
	  
		ignore_bytes = False;
	  
		NumberofUsedBytes = (*read_fdd->ByteProcessing)
			(private_data, process_buf, BytesRemaining);
	  
		/* if something went wrong. return False and let caller close the
		   connection. */
	  
		if (NumberofUsedBytes < 0)
			return False;
	  
		/* if the sleeze bags that told us previously that we only */
		/* needed that many bytes really lied to us, then they */
		/* would send us a NumberOfUsedBytes = 0, and set the # of */
		/* bytes needed to the real value.  We'll get them the next */
		/* time around. */
	  
		if (NumberofUsedBytes > 0)
		{
			if (!ignore_bytes)
			{
				/* if we are told not to ignore these bytes, let's */
				/* enqueue them on the output buffer */

				if (!outbuffer)
					return False;
		    
				SaveBytes(outbuffer, process_buf, NumberofUsedBytes);
			}
			/*
			 * We *must* call SendXmoveBuffer. That's what sets the
			 * bit in WriteDescriptors
			 */
			if (outbuffer && outbuffer->num_Saved)
				if (SendXmoveBuffer(write_fd, outbuffer) == False)
					return False;
	       
			RemoveSavedBytes(inbuffer, NumberofUsedBytes);
		}
	}
     
	/* if we have bytes waiting to be sent to the destination, try sending it
	   now rather than waiting for select() in MainLoop() to tell us the
	   recipient is ready. Since SendXmoveBuffer is nonblocking, we won't
	   wait unnecessarily. */
     
	if (outbuffer) {
		if (outbuffer->num_Saved) {
			if (SendXmoveBuffer(write_fd, outbuffer) == False)
				return False;
		} else
			BITCLEAR(WriteDescriptors, write_fd);
     
		/* if the output buffer is getting very filled up (ie more
		   than 128K) stop processing more input until it begins to
		   empty out */
	  
		if (outbuffer->num_Saved > 128*1024) {
			BITCLEAR(ReadDescriptors, read_fdd->fd);
		}
	}
     
	/* We did some work.  Tell the folks that everything's fine, that */
	/* we'll be home soon. */
     
	return True;
}

/*
 * We will need to save bytes until we get a complete request to
 * interpret.  The following procedures provide this ability.
 */

Global void
SaveBytes(Buffer *buffer, unsigned char *buf, long n)
{
    if (buffer->num_Saved + n > buffer->BlockSize - buffer->data_offset)
	 ResizeBuffer(buffer, buffer->num_Saved + n);
    
    bcopy(buf, (buffer->data + buffer->num_Saved), n);
    buffer->num_Saved += n;
}

static void
ResizeBuffer(Buffer *buffer, long len)
{
     unsigned char *newbuf;
     
     if (len <= buffer->BlockSize - buffer->data_offset)
	  return;

     /* after the buffer hits 256K, don't make it any bigger unless we absolutely have to */

     if (len <= buffer->BlockSize && len > 256*1024) {
	  bcopy(buffer->data, buffer->data - buffer->data_offset, buffer->num_Saved);
	  buffer->data -= buffer->data_offset;
	  buffer->data_offset = 0;
	  return;
     }

     /* double size each time -- don't get called as often! */
     
     len = MAX(len, MIN(len + buffer->BlockSize, 256*1024));
     
     newbuf = (unsigned char *)malloc(len);
     if (buffer->num_Saved)
	  bcopy(buffer->data, newbuf, buffer->num_Saved);

     if (buffer->BlockSize)
	  Tfree(buffer->data - buffer->data_offset);

     buffer->data = newbuf;
     buffer->data_offset = 0;
     buffer->BlockSize = len;
}

static void
RemoveSavedBytes(buffer, n)
Buffer *buffer;
int     n;
{
	int num_Saved = buffer->num_Saved;
	
	/* check if all bytes are being removed -- easiest case */
	
	if (n >= num_Saved) {
		if (buffer->data_offset) {
			buffer->data -= buffer->data_offset;
			buffer->data_offset = 0;
		}
		buffer->num_Saved = 0;
		return;
	}
	
	buffer->data_offset += n;
	buffer->data += n;
	buffer->num_Saved -= n;
	return;
}

static int
ConnectToClient(int ConnectionSocket, unsigned long *ip_addr)
{
	int    ON = 1;         /* used in ioctl */
	int    ClientFD;
	struct sockaddr_in  from;
	int    len = sizeof (from);

	ClientFD = accept(ConnectionSocket, (struct sockaddr *)&from, &len);
	debug(4,(stderr, "Connect To Client: FD %d\n", ClientFD));
	if (ClientFD < 0 && errno == EWOULDBLOCK)
		{
			debug(4,(stderr, "Almost blocked accepting FD %d\n", ClientFD));
			panic("Can't connect to Client");
		}
	if (ClientFD < 0)
		{
			debug(4,(stderr, "ConnectToClient: error %d\n", errno));
			panic("Can't connect to Client");
		}

	(void) setsockopt(ClientFD, IPPROTO_TCP, TCP_NODELAY, (char *)&ON, sizeof (int));

	*ip_addr = from.sin_addr.s_addr;
	
#if defined(FD_CLOEXEC) && defined(F_SETFD)
	fcntl(ClientFD, F_SETFD, FD_CLOEXEC);
#else
#ifdef FIOCLEX
	ioctl(ClientFD, FIOCLEX, 0);
#endif
#endif

#if defined(F_SETFL) && defined(O_NONBLOCK)
        fcntl(ClientFD, F_SETFL, O_NONBLOCK |
              fcntl(ClientFD, F_GETFL, NULL));
#else
#ifdef FIONBIO
	ioctl(ClientFD, FIONBIO, (char *)&ON);
#endif
#endif

	return(ClientFD);
}

Global int
ConnectToServer(char *hostName, short portNum, unsigned long *ip_addr)
{
    int ON = 1;
    int ServerFD;
    struct sockaddr_in  sin;
    struct hostent *hp;
    
    enterprocedure("ConnectToServer");

    hp = gethostbyname(hostName);
    if (hp == NULL)
    {
	perror("gethostbyname failed");
	return -1;
    }

    if (ip_addr)
	 *ip_addr = *(unsigned long *)(hp->h_addr);
    
    if (*(unsigned long *)(hp->h_addr) == HostIPAddr &&
	portNum == ListenForClientsPort)
    {
	 return -1;
    }
    
    /* establish a socket to the name server for this host */
    bzero((char *)&sin, sizeof(sin));
    ServerFD = socket(AF_INET, SOCK_STREAM, 0);
    if (ServerFD < 0)
    {
	perror("socket() to Server failed");
	return -1;
    }

    (void) setsockopt(ServerFD, SOL_SOCKET, SO_REUSEADDR,  (char *) NULL, 0);
#ifdef SO_USELOOPBACK
    (void) setsockopt(ServerFD, SOL_SOCKET, SO_USELOOPBACK,(char *) NULL, 0);
#endif
    (void) setsockopt(ServerFD, IPPROTO_TCP, TCP_NODELAY, (char *)&ON, sizeof (int));
#ifdef SO_DONTLINGER
    (void) setsockopt(ServerFD, SOL_SOCKET, SO_DONTLINGER, (char *) NULL, 0);
#endif

    debug(4,(stderr, "try to connect on %s\n", hostName));

    sin.sin_family = AF_INET;
    bcopy((char *)hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
    sin.sin_port = htons (portNum + XBasePort);

    /* ******************************************************** */
    /* try to connect to Server */
    
    if (connect(ServerFD, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
	debug(4,(stderr, "connect returns errno of %d\n", errno));
	close (ServerFD);
	return -1;
    }

#if defined(FD_CLOEXEC) && defined(F_SETFD)
	fcntl(ServerFD, F_SETFD, FD_CLOEXEC);
#else
#ifdef FIOCLEX
	ioctl(ServerFD, FIOCLEX, 0);
#endif
#endif

#if defined(F_SETFL) && defined(O_NONBLOCK)
        fcntl(ServerFD, F_SETFL, O_NONBLOCK |
              fcntl(ServerFD, F_GETFL, NULL));
#else
#ifdef FIONBIO
	ioctl(ServerFD, FIONBIO, (char *)&ON);
#endif
#endif

    debug(4,(stderr, "Connect To Server: FD %d\n", ServerFD));
    return(ServerFD);
}

#if 0
static char*
OfficialName(name)
char *name;
{
    struct hostent *HostEntry;

    HostEntry = gethostbyname(name);
    if (HostEntry == NULL)
    {
	perror("gethostbyname");
	exit(-1);
    }
    debug(4,(stderr, "Official name of %s is %s\n", name, HostEntry->h_name));
    return(HostEntry->h_name);
}
#endif

static void
#ifdef SVR4
SignalURG(int signum)
#else
SignalURG()
#endif
{
	debug(1,(stderr, "==> SIGURG received\n"));
}

static void
#ifdef SVR4
SignalPIPE(int signum)
#else
SignalPIPE()
#endif
{
	debug(1,(stderr, "==> SIGPIPE received\n"));
}

static void
#ifdef SVR4
SignalINT(int signum)
#else
SignalINT()
#endif
{
	debug(1,(stderr, "==> SIGINT received\n"));
	exit(1);
}

static void
#ifdef SVR4
SignalQUIT(int signum)
#else
SignalQUIT()
#endif
{
	debug(1,(stderr, "==> SIGQUIT received\n"));
	exit(1);
}

static void
#ifdef SVR4
SignalTERM(int signum)
#else
SignalTERM()
#endif
{
	debug(1,(stderr, "==> SIGTERM received\n"));
	exit(1);
}

static void
#ifdef SVR4
SignalTSTP(int signum)
#else
SignalTSTP()
#endif
{
	debug(1,(stderr, "==> SIGTSTP received\n"));
}

static void
#ifdef SVR4
SignalCONT(int signum)
#else
SignalCONT()
#endif
{
	debug(1,(stderr, "==> SIGCONT received\n"));
}

Global void
enterprocedure(s)
		char   *s;
{
	debug(2,(stderr, "-> %s\n", s));
}

Global void
panic(s)
		char   *s;
{
	fprintf(stderr, "%s\n", s);
	exit(1);
}

/* This is a customized version of XListHosts. It uses the global
 * variables ServerHostName and ServerPort to make its socket connection 
 * to the server, and checks to see if ip_addr is allowed to connect.
 * If so, it return 1, if not, it returns 0, if the server is dead, it
 * returns -1. 
 */

Global int
ValidateNewConnection(u_long ip_addr)
{
     int fd;
     int cnt, length;
     xListHostsReq req;
     static xListHostsReply rep;
     static char *reply = NULL;
     char buf[256], *curaddr;
     int NBIO = 0;
     static Bool recurse = False;
     
     fd = ConnectToServer(ServerHostName, ServerPort, NULL);
     if (fd < 0) {
	  fprintf(stderr, "Unable to create connection to server at %s.\n\
Is the server dead?\n\
Is the server name correct?\n",
		  DefaultHost);
	  if (reply)
	       goto VNC_CheckReply;
	  return -1;
     }

     if (XmoveLittleEndian)
	  buf[0] = 0x6C;
     else
	  buf[0] = 0x42;

     *(u_short *)&buf[2] = 11;
     *(u_short *)&buf[4] = 0;
     
     if (AuthKeyLen) {
	  *(u_short *)&buf[6] = 18;
	  *(u_short *)&buf[8] = AuthKeyLen;

	  SendBuffer(fd, (u_char *)&buf[0], 12);
	  SendBuffer(fd, (u_char *)AuthType, 20);
	  SendBuffer(fd, (u_char *)AuthKey, ROUNDUP4(AuthKeyLen));
     } else {
	  *(u_short *)&buf[6] = 0;
	  *(u_short *)&buf[8] = 0;

	  SendBuffer(fd, (u_char *)&buf[0], 12);
     }

#if defined(F_SETFL) && defined(O_NONBLOCK)
     fcntl(fd, F_SETFL, ~O_NONBLOCK & fcntl(fd, F_GETFL, NULL));
#else
#ifdef FIONBIO
     ioctl(fd, FIONBIO, (char *)&NBIO);
#endif
#endif
     
     if ((read(fd, &buf[0], 8) != 8) || (buf[0] == 0)) {
	  int retval;
	  
	  close(fd);
	  
	  /* the server has rejected xmove, which should never happen. Perhaps
	   * the server was restarted and there's a new magic cookie? Re-check
	   * our cookie and recurse to try one more time, unless we are already
	   * in such a recursion.
	   */

	  if (recurse) {
	       fprintf(stderr, "xmove is not authorized to connect to server %s.\n", DefaultHost);
	       return -1;
	  }
	  
	  InitMagicCookie(DefaultHost, LocalHostName, ListenForClientsPort, True);
	  recurse = True;
	  retval = ValidateNewConnection(ip_addr);
	  recurse = False;

	  return (retval);
     }

     /* eat all the bytes telling me about the display. */

     length = (*(u_short *)(&buf[6])) << 2;
     while (length) {
	  length -= cnt = read(fd, buf, length > 256 ? 256 : length);
	  if (cnt < 0)
	       goto VNC_serverIOError;
     }
     
     /* issue ListHosts request */

     req.reqType = X_ListHosts;
     req.length = 1;

     length = 4;
     while (length) {
	  length -= cnt = write(fd, (char *)&req, sz_xListHostsReq);
	  if (cnt == -1)
	       goto VNC_serverIOError;
     }

     if (reply) {
	  free(reply);
	  reply = NULL;
     }
     
     cnt = read(fd, (char *)&rep, sz_xListHostsReply);
     if (cnt == -1)
	  goto VNC_serverIOError;

     reply = malloc(rep.length << 2);
     if (rep.length && (read(fd, reply, rep.length<<2) == -1)) {
	  free(reply);
	  reply = NULL;
	  goto VNC_serverIOError;
     }

VNC_CheckReply:
     if (!rep.enabled) {
	  if (fd != -1)
	       close(fd);
	  return 1;
     }

     curaddr = reply;
     while (curaddr < (reply + (rep.length<<2))) {
	  if (((xHostEntry *)curaddr)->family == 0 &&
	      ((xHostEntry *)curaddr)->length == 4 &&
	      *(u_long *)(((xHostEntry *)curaddr)+1) == ip_addr)
	  {
	       if (fd != -1)
		    close(fd);
	       return 1;
	  }

	  curaddr += SIZEOF(xHostEntry) + ROUNDUP4(((xHostEntry *)curaddr)->length);
     }

     if (fd != -1)
	  close(fd);
     return 0;
     
VNC_serverIOError:
     close(fd);
     fprintf(stderr, "I/O error during session with server %s.\n", DefaultHost);
     return -1;
}


/*
 * Change the default server. This needs to update several global variables,
 * and check the magic cookie records in xauth.
 */

void ChangeDefaultServer(char *server_name, char **retval)
{
     char *string;
     
     string = SetDefaultServer(server_name);
     if (string) {
	     *retval = strdup(string);
	     return;
     }
     
     InitMagicCookie(DefaultHost, LocalHostName, ListenForClientsPort, True);
     *retval = NULL;
}

/*
 * SetDefaultServer() uses server_name as the new value for DefaultHost.
 * It sets ServerHostName, ServerPort and ServerScreen. Returns 0 on success.
 * Returns pointer to string as error message if error. Caller must not
 * modify or free the string.
 */

static char *
SetDefaultServer(char *server_name)
{
	int new_port, new_screen;
	char new_defaulthost[256];
	char new_serverhostname[256];
	char *index;
	
	if (server_name == NULL || server_name[0] == '\0')
		strcpy(new_defaulthost, ":0.0");
	else
		strcpy(new_defaulthost, server_name);

	index = strchr(new_defaulthost, ':');
	if (index == new_defaulthost)
		strcpy(new_serverhostname, LocalHostName);
	else if (index == NULL)
		strcpy(new_serverhostname, new_defaulthost);
	else {
		strncpy(new_serverhostname, new_defaulthost,
			index - new_defaulthost);
		new_serverhostname[index - new_defaulthost] = '\0';
	}
	
	if (index == NULL) {
		new_port = 0;
		new_screen = 0;
	} else {
		new_port = atoi(index + 1);
		if (new_port < 0)
			new_port = 0;
		index = strchr(index + 1, '.');
		if (index == NULL)
			new_screen = 0;
		else {
			new_screen = atoi(index + 1);
			if (new_screen < 0)
				new_screen = 0;
		}
	}

	if ((ListenForClientsPort == new_port) &&
	    Streq(new_serverhostname, LocalHostName))
	{
		return "Can't have xmove on the same display as the server\n";
	}

	ServerPort = new_port;
	ServerScreen = new_screen;
	strcpy(DefaultHost, new_defaulthost);
	strcpy(ServerHostName, new_serverhostname);
	return NULL;
}
