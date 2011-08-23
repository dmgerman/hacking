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
 * File: decode11.c
 * 
 * Description: Decoding and switching routines for the X11 protocol
 * 
 * There are 4 types of things in X11: requests, replies, errors, and
 * events.
 * 
 * Each of them has a format defined by a small integer that defines the
 * type of the thing.
 * 
 * Requests have an opcode in the first byte.
 *
 * Events have a code in the first byte.
 * 
 * Errors have a code in the second byte (the first byte is 0)
 * 
 * Replies have a sequence number in bytes 2 and 3.  The sequence number
 * should be used to identify the request that was sent, and from that
 * request we can determine the type of the reply.
 * 
 */

#include "xmove.h"

/* function prototypes: */
/* decode11.c: */
static short CheckReplyTable P((Server *server,
				unsigned short SequenceNumber,
				Bool checkZero,
				QueueEntry *modified));
/* end function prototypes */

extern Bool					ignore_bytes;

extern int					RequestVerbose;
extern int					EventVerbose;
extern int					ReplyVerbose;
extern int					ErrorVerbose;
extern int					CurrentVerbose;

extern long WriteDescriptors[mskcnt];

static int					Lastfd;
static unsigned short				LastSequenceNumber;
static short				LastReplyType;

#define NoRequest (void *(*)())NULL
void *(*DecodeRequestList[])() = {
     NoRequest,			/* 0 */
     CreateWindow,		/* 1 */
     ChangeWindowAttributes,	/* 2 */
     GetWindowAttributes,	/* 3 */
     DestroyWindow,		/* 4 */
     DestroySubwindows,		/* 5 */
     ChangeSaveSet,		/* 6 */
     ReparentWindow,		/* 7 */
     MapWindow,			/* 8 */
     MapSubwindows,		/* 9 */
     UnmapWindow,		/* 10 */
     UnmapSubwindows,		/* 11 */
     ConfigureWindow,		/* 12 */
     CirculateWindow,		/* 13 */
     GetGeometry,		/* 14 */
     QueryTree,			/* 15 */
     InternAtom,		/* 16 */
     GetAtomName,		/* 17 */
     ChangeProperty,		/* 18 */
     DeleteProperty,		/* 19 */
     GetProperty,		/* 20 */
     ListProperties,		/* 21 */
     SetSelectionOwner,		/* 22 */
     GetSelectionOwner,		/* 23 */
     ConvertSelection,		/* 24 */
     SendEvent,			/* 25 */
     GrabPointer,		/* 26 */
     UngrabPointer,		/* 27 */
     GrabButton,		/* 28 */
     UngrabButton,		/* 29 */
     ChangeActivePointerGrab,	/* 30 */
     GrabKeyboard,		/* 31 */
     UngrabKeyboard,		/* 32 */
     GrabKey,			/* 33 */
     UngrabKey,			/* 34 */
     AllowEvents,		/* 35 */
     GrabServer,		/* 36 */
     UngrabServer,		/* 37 */
     QueryPointer,		/* 38 */
     GetMotionEvents,		/* 39 */
     TranslateCoordinates,	/* 40 */
     WarpPointer,		/* 41 */
     SetInputFocus,		/* 42 */
     GetInputFocus,		/* 43 */
     QueryKeymap,		/* 44 */
     OpenFont,			/* 45 */
     CloseFont,			/* 46 */
     QueryFont,			/* 47 */
     QueryTextExtents,		/* 48 */
     ListFonts,			/* 49 */
     ListFontsWithInfo,		/* 50 */
     SetFontPath,		/* 51 */
     GetFontPath,		/* 52 */
     CreatePixmap,		/* 53 */
     FreePixmap,		/* 54 */
     CreateGC,			/* 55 */
     ChangeGC,			/* 56 */
     CopyGC,			/* 57 */
     SetDashes,			/* 58 */
     SetClipRectangles,		/* 59 */
     FreeGC,			/* 60 */
     ClearArea,			/* 61 */
     CopyArea,			/* 62 */
     CopyPlane,			/* 63 */
     PolyPoint,			/* 64 */
     PolyLine,			/* 65 */
     PolySegment,		/* 66 */
     PolyRectangle,		/* 67 */
     PolyArc,			/* 68 */
     FillPoly,			/* 69 */
     PolyFillRectangle,		/* 70 */
     PolyFillArc,		/* 71 */
     PutImage,			/* 72 */
     GetImage,			/* 73 */
     PolyText8,			/* 74 */
     PolyText16,		/* 75 */
     ImageText8,		/* 76 */
     ImageText16,		/* 77 */
     CreateColormap,		/* 78 */
     FreeColormap,		/* 79 */
     CopyColormapAndFree,	/* 80 */
     InstallColormap,		/* 81 */
     UninstallColormap,		/* 82 */
     ListInstalledColormaps,	/* 83 */
     AllocColor,		/* 84 */
     AllocNamedColor,		/* 85 */
     AllocColorCells,		/* 86 */
     AllocColorPlanes,		/* 87 */
     FreeColors,		/* 88 */
     StoreColors,		/* 89 */
     StoreNamedColor,		/* 90 */
     QueryColors,		/* 91 */
     LookupColor,		/* 92 */
     CreateCursor,		/* 93 */
     CreateGlyphCursor,		/* 94 */
     FreeCursor,		/* 95 */
     RecolorCursor,		/* 96 */
     QueryBestSize,		/* 97 */
     QueryExtension,		/* 98 */
     ListExtensions,		/* 99 */
     ChangeKeyboardMapping,	/* 100 */
     GetKeyboardMapping,	/* 101 */
     ChangeKeyboardControl,	/* 102 */
     GetKeyboardControl,	/* 103 */
     Bell,			/* 104 */
     ChangePointerControl,	/* 105 */
     GetPointerControl,		/* 106 */
     SetScreenSaver,		/* 107 */
     GetScreenSaver,		/* 108 */
     ChangeHosts,		/* 109 */
     ListHosts,			/* 110 */
     SetAccessControl,		/* 111 */
     SetCloseDownMode,		/* 112 */
     KillClient,		/* 113 */
     RotateProperties,		/* 114 */
     ForceScreenSaver,		/* 115 */
     SetPointerMapping,		/* 116 */
     GetPointerMapping,		/* 117 */
     SetModifierMapping,	/* 118 */
     GetModifierMapping,	/* 119 */
     NoRequest,
     NoRequest,
     NoRequest,
     NoRequest,
     NoRequest,
     NoRequest,
     NoRequest,
     NoOperation		/* 127 */
};

Global void
    DecodeRequest(buf, n)
unsigned char			*buf;
long					n;
{
    int						fd = client->fdd->fd;
    short					Request = IByte (&buf[0]);
    
    client->SequenceNumber += 1;
    if (client->SequenceNumber == 0) {
	 client->LastMoveSeqNo = -1; /* the seqno just reset to 0. reset lastmoveseqno. */
    }
    
    ISetLong((unsigned char *)SBf, (unsigned long)client->SequenceNumber);
    
    if (CurrentVerbose = RequestVerbose)
	 SetIndentLevel(PRINTCLIENT);
    
    if (CurrentVerbose > 3)
	DumpItem("Request", fd, buf, IShort(&buf[2]));

    if (DecodeRequestList[Request] == NoRequest) {
	 fprintf(stdout, 
		 "Extended request opcode: %d, SequenceNumber: %d\n",
		 Request, client->SequenceNumber);
    } else {
	 void *retval;

	 retval = (DecodeRequestList[Request])(buf);
	 if (retval)
	      if (retval == (void *)1)
		   ReplyExpected(Request, NULL);
	      else
		   ReplyExpected(Request, retval);
    }
}

Global void
DecodeReply(unsigned char *buf, long n)
{
     int	fd = server->fdd->fd;
     u_short	SequenceNumber = IShort (&buf[2]);
     short	Request;
     QueueEntry	modified;
     void      *context;   

     modified.modified = False;
     Request = CheckReplyTable(server, SequenceNumber, True, &modified);

     if(modified.modified == True)
     {
	  Dprintf(("reply for modified request received.\n"));
	  Dprintf(("client requested first=%d, count = %d\n", 
		   modified.client_first_keycode, modified.client_count));
	  Dprintf(("server reply contains first=%d, count=%d\n", 
		   modified.server_first_keycode, modified.server_count));
     }
     
     if (CurrentVerbose = ReplyVerbose)
	  SetIndentLevel(PRINTSERVER);
     
     RBf[0] = Request;		/* for the PrintField in the Reply procedure */
     
     if (CurrentVerbose > 3)
	  DumpItem("Reply", fd, buf, n);
     
     context = modified.context;

     if (Request <= 0 || 127 < Request)
	  fprintf(stdout, "####### Extended reply opcode %d\n", Request);
     else 
	  switch (Request)
	  {
	  case 3:
	       GetWindowAttributesReply(buf, context);
	       break;
	  case 14:
	       GetGeometryReply(buf, context);
	       break;
	  case 15:
	       QueryTreeReply(buf, context);
	       break;
	  case 16:
	       InternAtomReply(buf, context);
	       break;
	  case 17:
	       GetAtomNameReply(buf, context);
	       break;
	  case 20:
	       GetPropertyReply(buf, context);
	       break;
	  case 21:
	       ListPropertiesReply(buf, context);
	       break;
	  case 23:
	       GetSelectionOwnerReply(buf, context);
	       break;
	  case 26:
	       GrabPointerReply(buf, context);
	       break;
	  case 31:
	       GrabKeyboardReply(buf, context);
	       break;
	  case 38:
	       QueryPointerReply(buf, context);
	       break;
	  case 39:
	       GetMotionEventsReply(buf, context);
	       break;
	  case 40:
	       TranslateCoordinatesReply(buf, context);
	       break;
	  case 43:
	       GetInputFocusReply(buf, context);
	       break;
	  case 44:
	       QueryKeymapReply(buf, context);
	       break;
	  case 47:
	       QueryFontReply(buf, context);
	       break;
	  case 48:
	       QueryTextExtentsReply(buf, context);
	       break;
	  case 49:
	       ListFontsReply(buf, context);
	       break;
	  case 50:
	       ListFontsWithInfoReply(buf, context);
	       break;
	  case 52:
	       GetFontPathReply(buf, context);
	       break;
	  case 73:
	       GetImageReply(buf, context);
	       break;
	  case 83:
	       ListInstalledColormapsReply(buf, context);
	       break;
	  case 84:
	       AllocColorReply(buf, context);
	       break;
	  case 85:
	       AllocNamedColorReply(buf, context);
	       break;
	  case 86:
	       AllocColorCellsReply(buf, context);
	       break;
	  case 87:
	       AllocColorPlanesReply(buf, context);
	       break;
	  case 91:
	       QueryColorsReply(buf, context);
	       break;
	  case 92:
	       LookupColorReply(buf, context);
	       break;
	  case 97:
	       QueryBestSizeReply(buf, context);
	       break;
	  case 98:
	       QueryExtensionReply(buf, context);
	       break;
	  case 99:
	       ListExtensionsReply(buf, context);
	       break;
	  case 101:
	       /* this may be a reply for a request that was modified. */
	       /* If so, we need to modify this request */
	       
	       if (modified.modified == True)
	       {
		    unsigned char *new_reply;
		    long new_reply_size;
		    unsigned char n = IByte(&buf[1]); /* keysyms/keycode */
		    unsigned long index = modified.server_first_keycode -
			 modified.client_first_keycode;
		    
		    /* here, reconstruct the new buffer to send out to the */
		    /* client, send it to the client, and set ignore_bytes */
		    /* so it is not duplicated */
		    
		    
		    /* compute the in memory size */
		    ISetLong(&buf[4], modified.client_count * n);
		    new_reply_size = 32 + 4 * modified.client_count * n;
		    
		    new_reply = Tcalloc(new_reply_size, unsigned char);
		    
		    /* copy the header */
		    bcopy((char *)buf, (char *)new_reply, 32);
		    
		    /* copy the actual data, offset appropriately into the */
		    /* destination buffer */
		    
		    bcopy((char *) &buf[32],
			  (char *)&new_reply[32+(4*n*index)], 
			  (modified.server_count * n * 4));
		    
		    /* poke in the right size information into the header */
		    ISetLong(&new_reply[4], (n * modified.client_count));
		    
		    /* send it off to this client */
		    SaveBytes(&(client->fdd->outBuffer), 
			      new_reply,
			      new_reply_size);
		    BITSET(WriteDescriptors, client->fdd->fd);
		    
		    /* set ignore_bytes so that this packet is not */
		    /* transmitted by the main loop as well */
		    ignore_bytes = True;
		    free(new_reply);
	       }
	       else
		    GetKeyboardMappingReply(buf, context);
	       break;
	  case 103:
	       GetKeyboardControlReply(buf, context);
	       break;
	  case 106:
	       GetPointerControlReply(buf, context);
	       break;
	  case 108:
	       GetScreenSaverReply(buf, context);
	       break;
	  case 110:
	       ListHostsReply(buf, context);
	       break;
	  case 116:
	       SetPointerMappingReply(buf, context);
	       break;
	  case 117:
	       GetPointerMappingReply(buf, context);
	       break;
	  case 118:
	       SetModifierMappingReply(buf, context);
	       break;
	  case 119:
	       GetModifierMappingReply(buf, context);
	       break;
	  default:
	       fprintf(stdout, "####### Unimplemented reply opcode %d\n", Request);
	       break;
	}
}

Global void
DecodeError(buf, n)
	unsigned char			*buf;
	long					n;
{
	int						fd = server->fdd->fd;
	short					Error = IByte (&buf[1]);
	QueueEntry modified;

	Dprintf(("XMOVE Error from fd %d\n",fd))

	if ((CheckReplyTable(server, (short)IShort(&buf[2]),
			     False, &modified) != 0) && modified.context)
	{
	     free(modified.context);
	}

	CurrentVerbose = ErrorVerbose;
	if (CurrentVerbose <= 0)
		return;
	SetIndentLevel(PRINTSERVER);
	if (CurrentVerbose > 3)
		DumpItem("Error", fd, buf, n);
	if (Error < 1 || Error > 17)
		fprintf(stdout, "####### Extended Error opcode %d\n", Error);
	else
		switch (Error)
		{
		case 1:
			RequestError(buf);
			break;
		case 2:
			ValueError(buf);
			break;
		case 3:
			WindowError(buf);
			break;
		case 4:
			PixmapError(buf);
			break;
		case 5:
			AtomError(buf);
			break;
		case 6:
			CursorError(buf);
			break;
		case 7:
			FontError(buf);
			break;
		case 8:
			MatchError(buf);
			break;
		case 9:
			DrawableError(buf);
			break;
		case 10:
			AccessError(buf);
			break;
		case 11:
			AllocError(buf);
			break;
		case 12:
			ColormapError(buf);
			break;
		case 13:
			GContextError(buf);
			break;
		case 14:
			IDChoiceError(buf);
			break;
		case 15:
			NameError(buf);
			break;
		case 16:
			LengthError(buf);
			break;
		case 17:
			ImplementationError(buf);
			break;
		default:
			fprintf(stdout, "####### Unimplemented Error opcode %d\n", Error);
			break;
		}
}

Global void
DecodeEvent(unsigned char *buf, long n, Bool real_event)
{
    short Event = IByte (&buf[0]) & 0x7f;

    if (real_event)
    {
	if (CurrentVerbose = EventVerbose)
	     SetIndentLevel(PRINTSERVER);

	if (CurrentVerbose > 3)
	    DumpItem("Event", server->fdd->fd, buf, n);
    }

    if (Event < 2 || Event >= MAX_EVENT)
	fprintf(stdout, "####### Extended Event opcode %d\n", Event);
    else
	switch (Event)
	{
	  case 2:
	    KeyPressEvent(buf);
	    break;
	  case 3:
	    KeyReleaseEvent(buf);
	    break;
	  case 4:
	    ButtonPressEvent(buf);
	    break;
	  case 5:
	    ButtonReleaseEvent(buf);
	    break;
	  case 6:
	    MotionNotifyEvent(buf);
	    break;
	  case 7:
	    EnterNotifyEvent(buf);
	    break;
	  case 8:
	    LeaveNotifyEvent(buf);
	    break;
	  case 9:
	    FocusInEvent(buf);
	    break;
	  case 10:
	    FocusOutEvent(buf);
	    break;
	  case 11:
	    KeymapNotifyEvent(buf);
	    break;
	  case 12:
	    ExposeEvent(buf);
	    break;
	  case 13:
	    GraphicsExposureEvent(buf);
	    break;
	  case 14:
	    NoExposureEvent(buf);
	    break;
	  case 15:
	    VisibilityNotifyEvent(buf);
	    break;
	  case 16:
	    CreateNotifyEvent(buf);
	    break;
	  case 17:
	    DestroyNotifyEvent(buf);
	    break;
	  case 18:
	    UnmapNotifyEvent(buf);
	    break;
	  case 19:
	    MapNotifyEvent(buf);
	    break;
	  case 20:
	    MapRequestEvent(buf);
	    break;
	  case 21:
	    ReparentNotifyEvent(buf);
	    break;
	  case 22:
	    ConfigureNotifyEvent(buf);
	    break;
	  case 23:
	    ConfigureRequestEvent(buf);
	    break;
	  case 24:
	    GravityNotifyEvent(buf);
	    break;
	  case 25:
	    ResizeRequestEvent(buf);
	    break;
	  case 26:
	    CirculateNotifyEvent(buf);
	    break;
	  case 27:
	    CirculateRequestEvent(buf);
	    break;
	  case 28:
	    PropertyNotifyEvent(buf);
	    break;
	  case 29:
	    SelectionClearEvent(buf);
	    break;
	  case 30:
	    SelectionRequestEvent(buf);
	    break;
	  case 31:
	    SelectionNotifyEvent(buf);
	    break;
	  case 32:
	    ColormapNotifyEvent(buf);
	    break;
	  case 33:
	    ClientMessageEvent(buf);
	    break;
	  case 34:
	    MappingNotifyEvent(buf);
	    break;
	  default:
	    fprintf(stdout, "####### Unimplemented Event opcode %d\n", Event);
	    break;
	}
}


/*
 * ReplyExpected:
 * 
 * A reply is expected to the type of request given for the fd associated
 * with this one
 */
void
ReplyExpected(short RequestType, void *context)
{
    u_short 	SequenceNumber = (u_short)(client->SequenceNumber + client->SequenceMapping);
    QueueEntry	*p;

    /* create a new queue entry */
    p = Tmalloc(QueueEntry);
    p->SequenceNumber = SequenceNumber;
    p->Request = RequestType;
    p->context = context;
    p->modified = False;

    appendToList(&server->reply_list, (Pointer)p);
}

/*
 * CheckReplyTable:
 * 
 * search for the type of request that is associated with a reply to the
 * given sequence number for this fd
 */

static short
CheckReplyTable (Server *server, 
		 unsigned short SequenceNumber, 
		 Bool checkZero,
		 QueueEntry *modified)
{
    int			fd = server->fdd->fd;
    QueueEntry		*p;

    ForAllInList(&server->reply_list)
    {
	p = (QueueEntry *)CurrentContentsOfList(&server->reply_list);
	if (SequenceNumber == p->SequenceNumber)
	{
	    /* save the Request type */
	    Lastfd = fd;
	    LastSequenceNumber = p->SequenceNumber;
	    LastReplyType = p->Request;

	    if (modified)
		 modified->context = p->context;
	    
	    /* if modified is true, then fill in the structure passed */
	    /* to us with the appropriate values */
	    if ((p->modified == True) && (modified != (QueueEntry *) NULL))
	    {
		modified -> modified = True;
		modified -> client_first_keycode = p->client_first_keycode;
		modified -> client_count = p->client_count;
		modified -> server_first_keycode = p->server_first_keycode;
		modified -> server_count = p->server_count;
	    }

	    /* pull the queue entry out of the queue for this fd */
	    freeCurrent(&server->reply_list);
	    return(LastReplyType);
	}
    }

    /* not expecting a reply for that sequence number */
    if (checkZero)
    {
	printf("Unexpected reply, SequenceNumber: %d(%d).\n",
	       SequenceNumber, client->SequenceMapping);

	if (ListIsEmpty(&server->reply_list))
	    printf("No expected replies\n");
	else
	{
	    printf("Expected replies are:\n");
	    ForAllInList(&server->reply_list)
	    {
		p = (QueueEntry *)CurrentContentsOfList(&server->reply_list);
		printf("Reply on fd %d for sequence %d is type %d\n",
		     fd, p->SequenceNumber, p->Request);
	    }
	    printf("End of expected replies\n");
	}
    }
    return(0);
}


Global void
ModifiedKeyMappingReplyExpected(short RequestType,
				unsigned char client_first_keycode,
				unsigned char client_count,
				unsigned char server_first_keycode,
				unsigned char server_count)
{
    u_short	SequenceNumber = (u_short)(client->SequenceNumber + client->SequenceMapping);
    QueueEntry	*p;

    /* create a new queue entry */
    p = Tmalloc(QueueEntry);
    p->SequenceNumber = SequenceNumber;
    p->Request = RequestType;
    p->modified = True;
    p->client_first_keycode = client_first_keycode;
    p->client_count = client_count;
    p->server_first_keycode = server_first_keycode;
    p->server_count = server_count;

    appendToList(&server->reply_list, (Pointer)p);
}
