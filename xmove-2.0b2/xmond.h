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
 * File: xmond.h
 *
 */

#ifndef XMOND_H
#define XMOND_H

#include <stdio.h>

#include	"common.h"
#include "linkl.h"
#include "hash.h"
#include "x11.h"
#include "select_args.h"

#ifndef _XLIB_H_
#include <X11/Xlib.h>
#endif

/* standard X11 type definitions */

typedef char int8;
typedef unsigned char card8;

typedef short int16;
typedef unsigned short card16;

typedef long int32;
typedef unsigned long card32;


/* Reply Buffer: Pseudo-buffer used to provide the opcode for the
                 request to which this is a reply: Set by DecodeReply
		 and used in the PrintField of the Reply procedure */
extern card16 RBf_16;
#define RBf ((unsigned char *)&RBf_16)


/* Sequence Buffer: Pseudo-buffer used to provide the sequence number for a
                 request: Set by DecodeReply and used in a PrintField of 
		 the Request procedure */
extern card32 SBf_32;
#define SBf ((unsigned char *)&SBf_32)


extern int debuglevel, ethandebuglevel;
extern Bool PrintDebug, EthanPrintDebug;

#define debug(n,f) (void)((debuglevel & n) ? (fprintf f,fflush(stderr)) : 0)
#define Dprintf(f) { if (PrintDebug) printf f; }

#define ethan(n,f) (void)((ethandebuglevel & n) ? (fprintf f,fflush(stderr)) : 0)
#define Eprintf(f) { if (EthanPrintDebug) printf f; }

typedef struct
{
	unsigned char				*data;
	long					num_Saved;
	long					num_Needed;
	long					BlockSize;


	/* incomplete_data is only used with inBuffer, and currently only
	 * with inBuffers for servers. It points to the start of a message
	 * which we haven't finished reading in, or NULL if the last message
	 * we read was read in its entirety. This allows us to determine
	 * immediately whether we should expect a 32-byte message from the
	 * server the next time we do a read().
	 */
	
	unsigned char				*incomplete_data;

	
	/* in order to avoid unnecessary bcopys, we will increment data as we
	   do RemoveSavedBytes and only do the bcopy once the buffer fills up,
	   resetting data back to the original malloc'd value. data_offset tells
	   us how much data has been skipped. */
	
	long                                    data_offset;
	int                                     src_fd;
}
	Buffer;

/*
 * File descriptors are grouped into four classes:
 *   standard input: one FD for reading from standard input
 *   X port: one FD for listening for new client connections
 *   clients: FDs connected to clients
 *   servers: FDs connected to servers
 * When input is read from a file desccriptor, an InputHandler function
 * is called to deal with the data just read. Each FD class has its own
 * input handler.
 *
 * The InputHandler called and the meaning of the private_data field for
 * each FD class is:
 *
 *   FD class			InputHandler		private_data
 *   --------			------------		------------
 *   standard input		ReadStdin		FD of stdin
 *   X port			NewConnection		FD of X port
 *   clients			DataFromClient		pointer to Client struct
 *   servers			DataFromServer		pointer to Server struct
 */

typedef struct
{
	VoidCallback			InputHandler;
	Pointer				private_data;
	int				fd;
	Buffer				inBuffer;
	Buffer				outBuffer;
	IntCallback			ByteProcessing;
	Bool				littleEndian;
	Bool                            pass_through;
}
	FDDescriptor;

/*typedef enum {moveStable = 0, moveRepliesPending, moveSyncing, moveInProgress} MoveState;*/

typedef struct
{
        LinkList        client_list;
	unsigned int    meta_id;
#if 0
	MoveState	move_state;
	u_int		move_state_count; /* valid for mRP and mS states */
	Client	       *notify_me; /* to be notified after move */
#endif
} MetaClient;
	
typedef struct {
     unsigned long     client_base;
     unsigned long     server_base;
     unsigned long new_server_base;
     Bool                transient;
} ResourceMappingRec, *ResourceMappingPtr;
	

typedef struct VisualRec   VisualRec, *VisualPtr;
typedef struct PixmapFormatRec PixmapFormatRec, *PixmapFormatPtr;
typedef struct ImageFormat ImageFormatRec, *ImageFormatPtr;
typedef struct WindowRec   WindowRec, *WindowPtr;
typedef struct ColormapRec ColormapRec, *ColormapPtr;
typedef struct Server      Server;


struct VisualRec {
	VisualID	vis_id;
	VisualPtr	vis_mapped;	/* C->S or S->C */
	Bool		vis_equivalent;	/* C->S all pixels identical */
	VisualPtr	vis_new_mapped;	/* C->NEW SERVER */
	Bool		vis_new_equivalent; /* C->NS all pixels identical */
	card8		vis_class;
	card8		vis_depth;
	card8		vis_inuse;	/* set if client has alloc'd w/vis_id */

	/*
	 * vis_red, etc. are straight from the startup reply.
	 * for non-split colormaps vis_indices is 0, shift[0] is
	 * 0, index[0] is 0, index[1] is size of colormap, mask[0]
	 * is index[1]-1. for split colormaps,
	 * array indices: 0 == red, 1 == green, 2 == blue
	 * ((colorcell >> vis_shift> & vis_mask) + vis_index
	 * will give you the index into a cell_array.
	 * vis_indices is the number of array elements in use
	 * for this visual type, which is always 3.
	 */

	card8		vis_indices;
	card8		vis_shift[3];
	card32		vis_index[4];
	card32		vis_mask[3];
	card32		vis_red,     vis_green,   vis_blue;
};

struct PixmapFormatRec {
    card8		depth;
    card8		bits_per_pixel;
    card8		scanline_pad;
    Bool		compatible;		/* is this compatible w/mapped_depth? */
    Bool		new_compatible;		/* as above, for new_mapped_depth */
    PixmapFormatPtr	mapped_depth;		/* only relevant C->S, not S->C */
    PixmapFormatPtr	new_mapped_depth;	/* only relevant C->NS, not NS->C */
    Pixmap		new_pixmap;		/* pixmap on new server with this depth */
    GContext		new_gc;			/* gc on new server with this depth */
};

struct ImageFormat {
    int 		image_byte_order;
    int			image_bitmap_bit_order;
    int			image_bitmap_unit;
    int			image_bitmap_pad;
    Bool		image_bitmap_compatible; /* is 1-bit bitmap format compatible? */

    unsigned short      max_request_size;

    Window		sc_root_window;
    Colormap		sc_default_cmap;
    VisualPtr		sc_default_vis;

    int			sc_visuals_count;
    VisualPtr		sc_visuals;

    int			sc_formats_count;
    PixmapFormatPtr	sc_formats;
};


typedef struct {
    FDDescriptor        *fdd;
    Bool		authorized; /* true if client OK */
    struct Server       *server;
    MetaClient          *meta_client;
    unsigned long	ClientNumber;
    unsigned short      SequenceNumber;

    char    		*window_name;
    unsigned char       *startup_message;
    unsigned int        startup_message_len;
    Bool                grabbed_server;
    int			closedownmode;

    struct Server       *new_server;
    unsigned short      new_seqno;
    unsigned short      orig_seqno;

    /*
     * SequenceMapping is added to the sequence number of all
     * inbound messages from the server before the message is
     * received by the client. This is because xmove occasionally
     * needs to insert requests, and we don't want the seq num
     * to appear to the client to change. As well, it is used
     * after a move to a new server since that will change the
     * seq num coming out of the server.
     */
	
    long                SequenceMapping;
    long                LastMoveSeqNo;

    /*
     * the next two options can never both be true. If xmoved_to_elsewhere
     * is true, then the client is being displayed elsewhere. Otherwise
     * the client is being displayed locally.
     */
	
    Bool                xmoved_from_elsewhere;
    Bool                xmoved_to_elsewhere;
    Bool		suspended;
    Bool		never_moved;

    /*
     * these are the linked lists that hold the information
     * regarding all the resources that this particular client
     * has.  These LinkLists are initialized in the
     * NewConnection() routine..
     */

    hash_table     	*window_table;
    hash_table		*pixmap_table;
    hash_table		*font_table;
    hash_table		*glyph_cursor_table;
    hash_table          *cursor_table;
    hash_table		*gc_table;
    LinkList            colormap_list;
    LinkList            grab_list;
    hash_table          *atom_table;
    LinkList            selection_list;
    LinkList            resource_maps;

    /* these are values that the client starts up with */

    unsigned long       resource_base;
    unsigned long       resource_mask;
    unsigned char	min_keycode, max_keycode;

    unsigned int        allocated_colormaps;
    ImageFormatPtr      formats;
} Client;

struct Server {
    FDDescriptor	*fdd;
    Client		*client;
    LinkList		reply_list; /* list of QueueEntry */

    char		*server_name;

    unsigned long       resource_base;
    unsigned long       resource_mask;
    unsigned char	min_keycode, max_keycode;
    unsigned short      max_request_size;

    ImageFormatPtr      formats;
};

/* function prototypes: */

/* decode11.c: */
Global void DecodeRequest P((unsigned char *buf , long n ));
Global void DecodeReply P((unsigned char *buf, long n ));
Global void DecodeError P((unsigned char *buf, long n ));
Global void DecodeEvent P((unsigned char *buf, long n, Bool real_event ));

Global void ReplyExpected P((short Request, void *context));

Global void ModifiedKeyMappingReplyExpected P((short RequestType,
					       unsigned char client_first_keycode,
					       unsigned char client_count,
					       unsigned char server_first_keycode,
					       unsigned char server_count));

/* print11.c: */
Global void PrintSetUpMessage P((unsigned char *buf ));
Global void PrintSetUpReply P((unsigned char *buf ));
Global void RequestError P((unsigned char *buf ));
Global void ValueError P((unsigned char *buf ));
Global void WindowError P((unsigned char *buf ));
Global void PixmapError P((unsigned char *buf ));
Global void AtomError P((unsigned char *buf ));
Global void CursorError P((unsigned char *buf ));
Global void FontError P((unsigned char *buf ));
Global void MatchError P((unsigned char *buf ));
Global void DrawableError P((unsigned char *buf ));
Global void AccessError P((unsigned char *buf ));
Global void AllocError P((unsigned char *buf ));
Global void ColormapError P((unsigned char *buf ));
Global void GContextError P((unsigned char *buf ));
Global void IDChoiceError P((unsigned char *buf ));
Global void NameError P((unsigned char *buf ));
Global void LengthError P((unsigned char *buf ));
Global void ImplementationError P((unsigned char *buf ));
Global void KeyPressEvent P((unsigned char *buf ));
Global void KeyReleaseEvent P((unsigned char *buf ));
Global void ButtonPressEvent P((unsigned char *buf ));
Global void ButtonReleaseEvent P((unsigned char *buf ));
Global void MotionNotifyEvent P((unsigned char *buf ));
Global void EnterNotifyEvent P((unsigned char *buf ));
Global void LeaveNotifyEvent P((unsigned char *buf ));
Global void FocusInEvent P((unsigned char *buf ));
Global void FocusOutEvent P((unsigned char *buf ));
Global void KeymapNotifyEvent P((unsigned char *buf ));
Global void ExposeEvent P((unsigned char *buf ));
Global void GraphicsExposureEvent P((unsigned char *buf ));
Global void NoExposureEvent P((unsigned char *buf ));
Global void VisibilityNotifyEvent P((unsigned char *buf ));
Global void CreateNotifyEvent P((unsigned char *buf ));
Global void DestroyNotifyEvent P((unsigned char *buf ));
Global void UnmapNotifyEvent P((unsigned char *buf ));
Global void MapNotifyEvent P((unsigned char *buf ));
Global void MapRequestEvent P((unsigned char *buf ));
Global void ReparentNotifyEvent P((unsigned char *buf ));
Global void ConfigureNotifyEvent P((unsigned char *buf ));
Global void ConfigureRequestEvent P((unsigned char *buf ));
Global void GravityNotifyEvent P((unsigned char *buf ));
Global void ResizeRequestEvent P((unsigned char *buf ));
Global void CirculateNotifyEvent P((unsigned char *buf ));
Global void CirculateRequestEvent P((unsigned char *buf ));
Global void PropertyNotifyEvent P((unsigned char *buf ));
Global void SelectionClearEvent P((unsigned char *buf ));
Global void SelectionRequestEvent P((unsigned char *buf ));
Global void SelectionNotifyEvent P((unsigned char *buf ));
Global void ColormapNotifyEvent P((unsigned char *buf ));
Global void ClientMessageEvent P((unsigned char *buf ));
Global void MappingNotifyEvent P((unsigned char *buf ));
Global void *CreateWindow P((unsigned char *buf ));
Global void *ChangeWindowAttributes P((unsigned char *buf ));
Global void *GetWindowAttributes P((unsigned char *buf ));
Global void GetWindowAttributesReply P((unsigned char *buf, void *context ));
Global void *DestroyWindow P((unsigned char *buf ));
Global void *DestroySubwindows P((unsigned char *buf ));
Global void *ChangeSaveSet P((unsigned char *buf ));
Global void *ReparentWindow P((unsigned char *buf ));
Global void *MapWindow P((unsigned char *buf ));
Global void *MapSubwindows P((unsigned char *buf ));
Global void *UnmapWindow P((unsigned char *buf ));
Global void *UnmapSubwindows P((unsigned char *buf ));
Global void *ConfigureWindow P((unsigned char *buf ));
Global void *CirculateWindow P((unsigned char *buf ));
Global void *GetGeometry P((unsigned char *buf ));
Global void GetGeometryReply P((unsigned char *buf, void *context ));
Global void *QueryTree P((unsigned char *buf ));
Global void QueryTreeReply P((unsigned char *buf, void *context ));
Global void *InternAtom P((unsigned char *buf ));
Global void InternAtomReply P((unsigned char *buf, void *context ));
Global void *GetAtomName P((unsigned char *buf ));
Global void GetAtomNameReply P((unsigned char *buf, void *context ));
Global void *ChangeProperty P((unsigned char *buf ));
Global void *DeleteProperty P((unsigned char *buf ));
Global void *GetProperty P((unsigned char *buf ));
Global void GetPropertyReply P((unsigned char *buf, void *context ));
Global void *ListProperties P((unsigned char *buf ));
Global void ListPropertiesReply P((unsigned char *buf, void *context ));
Global void *SetSelectionOwner P((unsigned char *buf ));
Global void *GetSelectionOwner P((unsigned char *buf ));
Global void GetSelectionOwnerReply P((unsigned char *buf, void *context ));
Global void *ConvertSelection P((unsigned char *buf ));
Global void *SendEvent P((unsigned char *buf ));
Global void *GrabPointer P((unsigned char *buf ));
Global void GrabPointerReply P((unsigned char *buf, void *context ));
Global void *UngrabPointer P((unsigned char *buf ));
Global void *GrabButton P((unsigned char *buf ));
Global void *UngrabButton P((unsigned char *buf ));
Global void *ChangeActivePointerGrab P((unsigned char *buf ));
Global void *GrabKeyboard P((unsigned char *buf ));
Global void GrabKeyboardReply P((unsigned char *buf, void *context ));
Global void *UngrabKeyboard P((unsigned char *buf ));
Global void *GrabKey P((unsigned char *buf ));
Global void *UngrabKey P((unsigned char *buf ));
Global void *AllowEvents P((unsigned char *buf ));
Global void *GrabServer P((unsigned char *buf ));
Global void *UngrabServer P((unsigned char *buf ));
Global void *QueryPointer P((unsigned char *buf ));
Global void QueryPointerReply P((unsigned char *buf, void *context ));
Global void *GetMotionEvents P((unsigned char *buf ));
Global void GetMotionEventsReply P((unsigned char *buf, void *context ));
Global void *TranslateCoordinates P((unsigned char *buf ));
Global void TranslateCoordinatesReply P((unsigned char *buf, void *context ));
Global void *WarpPointer P((unsigned char *buf ));
Global void *SetInputFocus P((unsigned char *buf ));
Global void *GetInputFocus P((unsigned char *buf ));
Global void GetInputFocusReply P((unsigned char *buf, void *context ));
Global void *QueryKeymap P((unsigned char *buf ));
Global void QueryKeymapReply P((unsigned char *buf, void *context ));
Global void *OpenFont P((unsigned char *buf ));
Global void *CloseFont P((unsigned char *buf ));
Global void *QueryFont P((unsigned char *buf ));
Global void QueryFontReply P((unsigned char *buf, void *context ));
Global void *QueryTextExtents P((unsigned char *buf ));
Global void QueryTextExtentsReply P((unsigned char *buf, void *context ));
Global void *ListFonts P((unsigned char *buf ));
Global void ListFontsReply P((unsigned char *buf, void *context ));
Global void *ListFontsWithInfo P((unsigned char *buf ));
Global void ListFontsWithInfoReply P((unsigned char *buf, void *context ));
Global void ListFontsWithInfoReply1 P((unsigned char *buf, void *context ));
Global void ListFontsWithInfoReply2 P((unsigned char *buf, void *context ));
Global void *SetFontPath P((unsigned char *buf ));
Global void *GetFontPath P((unsigned char *buf ));
Global void GetFontPathReply P((unsigned char *buf, void *context ));
Global void *CreatePixmap P((unsigned char *buf ));
Global void *FreePixmap P((unsigned char *buf ));
Global void *CreateGC P((unsigned char *buf ));
Global void *ChangeGC P((unsigned char *buf ));
Global void *CopyGC P((unsigned char *buf ));
Global void *SetDashes P((unsigned char *buf ));
Global void *SetClipRectangles P((unsigned char *buf ));
Global void *FreeGC P((unsigned char *buf ));
Global void *ClearArea P((unsigned char *buf ));
Global void *CopyArea P((unsigned char *buf ));
Global void *CopyPlane P((unsigned char *buf ));
Global void *PolyPoint P((unsigned char *buf ));
Global void *PolyLine P((unsigned char *buf ));
Global void *PolySegment P((unsigned char *buf ));
Global void *PolyRectangle P((unsigned char *buf ));
Global void *PolyArc P((unsigned char *buf ));
Global void *FillPoly P((unsigned char *buf ));
Global void *PolyFillRectangle P((unsigned char *buf ));
Global void *PolyFillArc P((unsigned char *buf ));
Global void *PutImage P((unsigned char *buf ));
Global void *GetImage P((unsigned char *buf ));
Global void GetImageReply P((unsigned char *buf, void *context ));
Global void *PolyText8 P((unsigned char *buf ));
Global void *PolyText16 P((unsigned char *buf ));
Global void *ImageText8 P((unsigned char *buf ));
Global void *ImageText16 P((unsigned char *buf ));
Global void *CreateColormap P((unsigned char *buf ));
Global void *FreeColormap P((unsigned char *buf ));
Global void *CopyColormapAndFree P((unsigned char *buf ));
Global void *InstallColormap P((unsigned char *buf ));
Global void *UninstallColormap P((unsigned char *buf ));
Global void *ListInstalledColormaps P((unsigned char *buf ));
Global void ListInstalledColormapsReply P((unsigned char *buf, void *context ));
Global void *AllocColor P((unsigned char *buf ));
Global void AllocColorReply P((unsigned char *buf, void *context ));
Global void *AllocNamedColor P((unsigned char *buf ));
Global void AllocNamedColorReply P((unsigned char *buf, void *context ));
Global void *AllocColorCells P((unsigned char *buf ));
Global void AllocColorCellsReply P((unsigned char *buf, void *context ));
Global void *AllocColorPlanes P((unsigned char *buf ));
Global void AllocColorPlanesReply P((unsigned char *buf, void *context ));
Global void *FreeColors P((unsigned char *buf ));
Global void *StoreColors P((unsigned char *buf ));
Global void *StoreNamedColor P((unsigned char *buf ));
Global void *QueryColors P((unsigned char *buf ));
Global void QueryColorsReply P((unsigned char *buf, void *context ));
Global void *LookupColor P((unsigned char *buf ));
Global void LookupColorReply P((unsigned char *buf, void *context ));
Global void *CreateCursor P((unsigned char *buf ));
Global void *CreateGlyphCursor P((unsigned char *buf ));
Global void *FreeCursor P((unsigned char *buf ));
Global void *RecolorCursor P((unsigned char *buf ));
Global void *QueryBestSize P((unsigned char *buf ));
Global void QueryBestSizeReply P((unsigned char *buf, void *context ));
Global void *QueryExtension P((unsigned char *buf ));
Global void QueryExtensionReply P((unsigned char *buf, void *context ));
Global void *ListExtensions P((unsigned char *buf ));
Global void ListExtensionsReply P((unsigned char *buf, void *context ));
Global void *ChangeKeyboardMapping P((unsigned char *buf ));
Global void *GetKeyboardMapping P((unsigned char *buf ));
Global void GetKeyboardMappingReply P((unsigned char *buf, void *context ));
Global void *ChangeKeyboardControl P((unsigned char *buf ));
Global void *GetKeyboardControl P((unsigned char *buf ));
Global void GetKeyboardControlReply P((unsigned char *buf, void *context ));
Global void *Bell P((unsigned char *buf ));
Global void *ChangePointerControl P((unsigned char *buf ));
Global void *GetPointerControl P((unsigned char *buf ));
Global void GetPointerControlReply P((unsigned char *buf, void *context ));
Global void *SetScreenSaver P((unsigned char *buf ));
Global void *GetScreenSaver P((unsigned char *buf ));
Global void GetScreenSaverReply P((unsigned char *buf, void *context ));
Global void *ChangeHosts P((unsigned char *buf ));
Global void *ListHosts P((unsigned char *buf ));
Global void ListHostsReply P((unsigned char *buf, void *context ));
Global void *SetAccessControl P((unsigned char *buf ));
Global void *SetCloseDownMode P((unsigned char *buf ));
Global void *KillClient P((unsigned char *buf ));
Global void *RotateProperties P((unsigned char *buf ));
Global void *ForceScreenSaver P((unsigned char *buf ));
Global void *SetPointerMapping P((unsigned char *buf ));
Global void SetPointerMappingReply P((unsigned char *buf, void *context ));
Global void *GetPointerMapping P((unsigned char *buf ));
Global void GetPointerMappingReply P((unsigned char *buf, void *context ));
Global void *SetModifierMapping P((unsigned char *buf ));
Global void SetModifierMappingReply P((unsigned char *buf, void *context ));
Global void *GetModifierMapping P((unsigned char *buf ));
Global void GetModifierMappingReply P((unsigned char *buf, void *context ));
Global void *NoOperation P((unsigned char *buf ));

/* server.c: */
Global void ISetLong P((void *, unsigned long value));
Global void ISetShort P((void *, unsigned short value));
Global unsigned long ILong P((void *));
Global unsigned short IShort P((void *));
Global void StartClientConnection P((Client *client ));
Global void StartServerConnection P((Server *server ));
Global void RestartServerConnection P((Server *server ));

/* fd.c: */
Global void InitializeFD P((void ));
Global FDDescriptor *UsingFD P((int fd , VoidCallback Handler , Pointer
private_data ));
Global void NotUsingFD P((int fd ));
Global void EOFonFD P((int fd ));

/* main.c: */
Global Bool ReadAndProcessData P((Pointer private_data , FDDescriptor *read_fdd , FDDescriptor *write_fdd , Bool is_server ));
Global void SaveBytes P((Buffer *buffer, unsigned char *buf, long n));
Global void CloseConnection P((Client *client ));
Global void enterprocedure P((char *s ));
Global void panic P((char *s ));
Global void DataFromClient P((Pointer private_data));
Global void DataFromServer P((Pointer private_data));
Global int  ConnectToServer P((char *hostName, short portNum, unsigned long *ip_addr));
Global void ChangeDefaultServer P((char *server_name, char **retval));

/* prtype.c: */
Global void SetIndentLevel P((short which ));
Global void ModifyIndentLevel P((short amount ));
Global void DumpItem P((char *name , int fd , unsigned char *buf , long n ));
Global int PrintINT8 P((unsigned char *buf ));
Global int PrintINT16 P((unsigned char *buf ));
Global int PrintINT32 P((unsigned char *buf ));
Global int PrintCARD8 P((unsigned char *buf ));
Global int PrintCARD16 P((unsigned char *buf ));
Global int PrintCARD32 P((unsigned char *buf ));
Global int PrintBYTE P((unsigned char *buf ));
Global int PrintCHAR8 P((unsigned char *buf ));
Global int PrintSTRING16 P((unsigned char *buf ));
Global int PrintSTR P((unsigned char *buf ));
Global int PrintWINDOW P((unsigned char *buf ));
Global int PrintWINDOWD P((unsigned char *buf ));
Global int PrintWINDOWNR P((unsigned char *buf ));
Global int PrintPIXMAP P((unsigned char *buf ));
Global int PrintPIXMAPNPR P((unsigned char *buf ));
Global int PrintPIXMAPC P((unsigned char *buf ));
Global int PrintCURSOR P((unsigned char *buf ));
Global int PrintFONT P((unsigned char *buf ));
Global int PrintGCONTEXT P((unsigned char *buf ));
Global int PrintCOLORMAP P((unsigned char *buf ));
Global int PrintCOLORMAPC P((unsigned char *buf ));
Global int PrintDRAWABLE P((unsigned char *buf ));
Global int PrintFONTABLE P((unsigned char *buf ));
Global int PrintATOM P((unsigned char *buf ));
Global int PrintATOMT P((unsigned char *buf ));
Global int PrintVISUALID P((unsigned char *buf ));
Global int PrintVISUALIDC P((unsigned char *buf ));
Global int PrintTIMESTAMP P((unsigned char *buf ));
Global int PrintRESOURCEID P((unsigned char *buf ));
Global int PrintKEYSYM P((unsigned char *buf ));
Global int PrintKEYCODE P((unsigned char *buf ));
Global int PrintKEYCODEA P((unsigned char *buf ));
Global int PrintBUTTON P((unsigned char *buf ));
Global int PrintBUTTONA P((unsigned char *buf ));
Global int PrintEVENTFORM P((unsigned char *buf ));
Global int PrintENUMERATED P((unsigned char *buf, short length, struct ValueListEntry *ValueList ));

Global void PrintSET P((unsigned char *buf, short length, struct ValueListEntry *ValueList ));
Global void PrintField P((unsigned char *buf, short start, short length , short FieldType , char *name ));
Global int PrintList P((unsigned char *buf , long number, short ListType , char *name ));
Global void PrintListSTR P((unsigned char *buf , long number, char *name ));
Global int PrintBytes P((unsigned char buf [], long number, char *name ));
Global int PrintString8 P((unsigned char buf [], short number, char *name ));
Global int PrintString16 P((unsigned char buf [], short number, char *name ));
Global void PrintValues P((unsigned char *control , short clength ,
short ctype , unsigned char *values , char *name ));
Global void PrintTextList8 P((unsigned char *buf , short length , char *name ));
Global void PrintTextList16 P((unsigned char *buf , short length , char *name ));
Global void DumpHexBuffer P((unsigned char *buf , long n ));

/* table11.c: */
Global void InitializeX11 P((void ));

/* end function prototypes */

#endif  /* XMOND_H */
