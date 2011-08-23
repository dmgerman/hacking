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
 * Project: XMOVE - An X window mover
 *
 * File: xmove.h
 *
 */

/*
 *
 * $Author: pds $
 * $Date: 1993/02/06 23:15:37 $
 * $Locker: ethan $
 * $Revision: 1.9 $
 * $Log: xmove.h,v $
 * Revision 1.9  1993/02/06  23:15:37  pds
 * *** empty log message ***
 *
 * Revision 1.8  1992/12/15  18:31:57  ethan
 * stolen back by pds.
 *
 * Revision 1.7  1992/12/14  03:55:23  pds
 * *** empty log message ***
 *
 * Revision 1.6  1992/11/20  03:50:31  ethan
 * *** empty log message ***
 *
 * Revision 1.5  1992/11/16  22:25:46  pds
 * added some stuff to data structures to support removal of gc and pixmaps
 * after a switch to a new server.
 *
 * Revision 1.4  1992/11/16  22:22:52  ethan
 * *** empty log message ***
 *
 * Revision 1.3  1992/11/08  19:00:24  pds
 * *** empty log message ***
 *
 * Revision 1.2  1992/10/16  16:46:59  pds
 * *** empty log message ***
 *
 * Revision 1.1  1992/10/13  22:16:34  pds
 * Initial revision
 *
 * Revision 2.9  1992/04/11  01:05:37  shamash
 * multiple clients work, all events properly managed
 *
 * Revision 2.8  1992/02/22  07:01:07  shamash
 * little/big endian bug fixed
 *
 * Revision 2.7  1992/02/22  05:52:04  shamash
 * keyboard mapping properly done
 *
 * Revision 2.6  1992/02/11  23:10:43  shamash
 * verbose 0 works!
 *
 * Revision 2.5  1992/01/31  06:50:03  shamash
 * emacs is mobile!!
 *
 *
 */

#ifndef XMOVE_H
#define XMOVE_H

#define NEED_REPLIES
#include <X11/Xproto.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xmond.h"

/*typedef enum {StaticGray, GrayScale, StaticColor, PseudoColor, TrueColor, DirectColor} VisualClass;*/

typedef struct
{
     char *name;

     /*void (*MapProperty) (AtomMapType, Atom *, Atom *, Atom *,
                            AtomPtr, Bool, Window *, char *, int);*/
     void (*MapProperty) ();
} AtomMappingRec, *AtomMappingPtr;

/*
 * To convert an intensity x from a m-bit colormap
 * to an n-bit intensity. x ranges from [ 0 , 1<<m )
 */

#define MapIntensity(x, m, n) \
	((m == n) ? x : (x * ((1 << n) - 1) / ((1 << m) - 1)))

/* Keep this structure a power of 2 bytes in length! Since it
   is used in an array, the optimizer can use shifts instead of
   multiplies to do memory references. */

/*
 * Note: the sum of the usage_counts within each "index" of the
 * colormap must be the same. So all incrs and decrs must affect
 * vis_indices colorcells.
 */

typedef struct
{
    card32 server_pixel, client_pixel, new_server_pixel;
    card32 usage_count;	/* 0 == empty colorcell entry */
    card16 red, green, blue;
    Bool read_write;
    char pad[4];		/* pad size to 32 bytes */
} ColorCellRec, *ColorCellPtr;    

typedef struct
{
	int	cell_index[3];
} ColorIndexRec, *ColorIndexPtr;

struct ColormapRec
{
    Colormap colormap_id;
    VisualPtr visual;
    ColorCellPtr cell_array;
    int cmap_moved;
};

typedef struct {
     Window                   *children;
     u_int                     nchildren;
     xGetWindowAttributesReply XGetARep;
     xGetGeometryReply         XGetGRep;
     u_int                     nGetPRep;
     xGetPropertyReply        *XGetPRep;
} WindowMoveInfo;

struct WindowRec
{
    Window window_id;
    Window parent_id;
    Window sibling_id;
    int8 sibling_stack_mode;
    card8 depth;
    short mapped;
    short tag;
    int16 x,y;
    card16 width, height, border_width, class;
    VisualPtr visual;
    XSetWindowAttributes attributes;
    unsigned long attributes_mask;
    ColormapPtr cmap;
    WindowMoveInfo *move_info;
};

typedef struct
{
    GContext gc_id;
    Drawable drawable_id;
    XGCValues values;
    unsigned long values_mask;

    card8 depth;
    ColormapPtr cmap;
    
    void *setclip_rects;
    int   setclip_n;
    int   setclip_ordering;
} GCRec, *GCPtr;

typedef struct
{
    Font font_id;
    char *name;
} FontRec, *FontPtr;

typedef struct
{
    Cursor cursor_id;
    Font source_font, mask_font;
    unsigned int source_char, mask_char;
    XColor foreground_color, background_color;
} GlyphCursorRec, *GlyphCursorPtr;

typedef struct
{
    Cursor cursor_id;
    XImage *source_image, *mask_image;
    XColor foreground_color, background_color;
    int16 x,y;
} CursorRec, *CursorPtr;

typedef struct
{
    Atom client_atom;
    Atom server_atom;
    Atom new_server_atom;
    AtomMappingPtr property_map_func;
    AtomMappingPtr type_map_func;
    AtomMappingPtr transient_map_func;
    char *atom_name;
} AtomRec, *AtomPtr;

typedef struct
{
    Atom selection;
    Window owner;		/* only set while client is suspended */
} SelectionRec, *SelectionPtr;

typedef struct
{
    Pixmap pixmap_id;
    Drawable drawable;
    unsigned int width, height;
    PixmapFormatPtr depth;

    /* temp storage of the newly created pixmap id for putimage loop */
    Pixmap new_pixmap;

    /* Pointer to the colormap associated with this pixmap */
    ColormapPtr cmap;
    
    /* Image may be kept here after a client is placed in suspended
     * animation, until it is placed somewhere else.
     */

    XImage *image;
    
} PixmapRec, *PixmapPtr;

typedef struct
{
  int type; /* the opcode from the grab */
  Window grab_window;
  Window confine_to;
  Cursor cursor;
  Time time;
  card16 event_mask;
  card16 modifiers;
  Bool owner_events;
  card8 pointer_mode;
  card8 keyboard_mode;
  card8 button;
  card8 key;
} GrabRec, *GrabPtr; 

/*
 * We need to keep the sequence number for a request to match it with an
 * expected reply.  The sequence number is associated only with the
 * particular connection that we have. We would expect these replies to be
 * handled as a FIFO queue.
*/

typedef struct
{
	unsigned short    SequenceNumber;
	short   Request;
	void *context;

	/* these fields are necessary to deal with the */
	/* GetKeyboardMapping request.  See appropriate comments there */

	Bool modified;
	unsigned char client_first_keycode, client_count;
	unsigned char server_first_keycode, server_count;
}
	QueueEntry;

typedef enum {Request, Event, Reply, Error, Server2Server, Client2NewServer} Direction;
typedef enum {MapChangeProp, MapDeleteProp, MapGetProp, MapGetPropReply,
	      MapClientMessage, MapConvertSelection, MapMoveClientProps,
	      MapSendClientMessage, MapSelectionRequest} AtomMapType;

/* global variables described in this file */

extern unsigned char *MappingNotifyEventBuf;
extern long MappingNotifyEventBufLength;

/* function prototypes specific to xmove */

/* xmove.c */

Global void InitXMove P((void));

Global void SetCurrentClientName P((char *name, int length));

Global char *xmovemalloc P((int n));
Global char *xmovecalloc P((int n, int size));

Global void AddGCToCurrentClient P((GCPtr gc));
Global void AddWindowToCurrentClient P((WindowPtr window));
Global void RemoveWindowFromCurrentClient P((Window window));
Global void RemoveGCFromCurrentClient P((GContext gc));
Global void RemoveFontFromCurrentClient P((Font font));
Global void RemoveCursorFromCurrentClient P((Cursor font));
Global void RemoveColormapFromCurrentClient P((Colormap xcolormap));

Global Client *FindClientFromBase P((unsigned long base));
Global WindowPtr FindWindowFromCurrentClient P((Window xwin));
Global WindowPtr FindWindowFromCurrentClient2 P((Window xwin));
Global PixmapPtr FindPixmapFromCurrentClient P((Pixmap pixmap));
Global ColormapPtr FindColormapFromCurrentClient P((Colormap cmap_id));
Global void SetColorCell P((ColorIndexPtr index, ColormapPtr cmap, Bool force,
			    card16 red, card16 green, card16 blue, card8 rgbmask));
Global Bool AllocColorCell P((card32 pixel, ColormapPtr cmap, Bool read_write, ColorIndexPtr index_arg));
Global Bool FindColorIndex P((card32 pixel, ColormapPtr cmap, ColorIndexPtr index));
Global ColorCellPtr FindColorCell P((card32 pixel, ColormapPtr cmap, int vis_index));
Global Bool FindServerColorIndex P((card32 pixel, ColormapPtr cmap, ColorIndexPtr index));
Global ColorCellPtr FindServerColorCell P((card32 pixel, ColormapPtr cmap, int vis_index));
Global ColorCellPtr FindNewServerColorCell P((card32 pixel, ColormapPtr cmap, int vis_index));
Global void RemoveColorIndex P((ColorIndexPtr index, ColormapPtr cmap));
Global AtomPtr FindAtom P((Atom atom));
Global AtomPtr FindServerAtom P((Atom atom));
Global AtomMappingPtr FindAtomMapping P((char *name));
Global AtomMappingPtr FindAtomTypeMapping P((char *name));
Global AtomMappingPtr AddAtomMapping P((char *name, void (*MapProperty)()));
Global AtomMappingPtr AddAtomTypeMapping P((char *name, void (*MapProperty)()));
Global AtomPtr CreateNewAtom P((Atom atom, char *name, Direction dir));
Global void ConvertGCToColormap P((GCPtr gc, ColormapPtr cmap));
Global card32 *MakeServerColorCellMap P((ColormapPtr cmap));
Global void ConvertPixmapToColormap P((PixmapPtr pixmap, ColormapPtr cmap));

Global void UntagAllWindows P(());

Global void AddGlyphCursorToCurrentClient P((GlyphCursorPtr cursor));
Global void AddCursorToCurrentClient P((CursorPtr cursor));
Global void AddPixmapToCurrentClient P((PixmapPtr pixmap));
Global void AddFontToCurrentClient P((FontPtr window));
Global void AddColormapToCurrentClient P((ColormapPtr colormap));
Global void CreateNewCellArray P((ColormapPtr cmap));

Global GCPtr FindGCFromCurrentClient P((GContext gc_id));

Global void ParseWindowBitmaskValueList P((WindowPtr window_ptr,
					   unsigned long cmask, 
					   unsigned char *ValueList));

Global void ParseGCBitmaskValueList P((GCPtr window_ptr,
				       unsigned long cmask, 
				       unsigned char *ValueList));

Global void FreeServerLists P((Server *server));
Global void FreeClientLists P((Client *client));

/* display.h */

Global int  SaveVisuals P((ImageFormatPtr format, unsigned char *buf));
Global void SaveFormats P((ImageFormatPtr format, unsigned char *buf));
Global VisualPtr FindVisualFromFormats P((ImageFormatPtr format, VisualID vid));
#define IsVisualRW(vis)     (vis && vis->vis_class & 1)
#define IsVisualLinear(vis) (vis && (vis->vis_class == StaticGray || vis->vis_class == TrueColor))
#define IsVisualColor(vis)  (vis && (vis->vis_class == StaticGray || vis->vis_class == GrayScale))
#define IsVisualSplit(vis)  (vis && (vis->vis_class == DirectColor || vis->vis_class == TrueColor))
Global int  XMOVEGetBitsPerPixel P((ImageFormatPtr image_format, int depth));
Global int  XMOVEGetScanlinePad P((ImageFormatPtr image_format, int depth));
Global PixmapFormatPtr GetPixmapFormat P((ImageFormatPtr image_format, int depth));
Global Pixmap   GetNewServerMovePixmap P((ImageFormatPtr image_format, int depth));
Global GContext GetNewServerMoveGC     P((ImageFormatPtr image_format, int depth));
Global void     FinishNewServerFormats P((ImageFormatPtr cformat, ImageFormatPtr sformat));
Global Bool     MakeNewServerFormats   P((ImageFormatPtr cformats, ImageFormatPtr sformats));

/* map.h */
Global ResourceMappingPtr FindResourceBase P((unsigned long base));
Global ResourceMappingPtr FindServerResourceBase P((unsigned long base));
Global unsigned long MapResource P((unsigned long resource, Direction dir, unsigned long primary));
#define MapDrawable(d, dir) ((Drawable)MapWindowID((Window)(d), (dir)))
#define MapPixmapID(p, dir) (MapResource((p), (dir), (p)))
#define MapGCID(g, dir) (MapResource((g), (dir), (g)))
#define MapFontID(f, dir) (MapResource((f), (dir), (f)))
#define MapCursorID(c, dir) (MapResource((c), (dir), (c)))
Global Window   MapWindowID P((Window xwin, Direction dir));
Global Colormap MapColormapID P((Colormap xcmap, Direction dir));
Global VisualID MapVisualID P((VisualID xvisual, Direction dir));
Global Bool     IsVisualEquivalent P((VisualPtr vis, Direction dir));
Global card32   MapColorCell P((card32 pixel, ColormapPtr cmap, Direction dir));
Global Atom     MapAtom P((Atom xatom, Direction dir));
Global AtomPtr  MapNewAtom P((Atom xatom, Direction dir));

/* get_image.h */

Global XImage *XMOVEGetImage P((int fd, unsigned short *seqno, register Server *server, Drawable d, int x, int y, unsigned int width, unsigned int height, unsigned long plane_mask, int format));
Global XImage *XMOVEPreCreateImage P((ImageFormatPtr image_format, VisualPtr visual, int format, GCPtr gc, unsigned int plane_mask, unsigned int depth, char *data, unsigned int width, unsigned int height));
Global XImage *XMOVECreateImage P((register ImageFormatPtr image_format, register VisualPtr visual, unsigned int depth, int format, int offset, char *data, unsigned int width, unsigned int height, int xpad, int image_bytes_per_line));

/* move.h */

Global void MoveAll P((char *new_display_name, char new_screen, MetaClient *exclude_client, int keylen, char *key, char **rettext));
Global void MoveClient P((MetaClient *mclient, char *new_display_name, char new_screen, int keylen, char *key, char **rettext));
Global void SuspendClient P((MetaClient *mclient, char **rettext));

/* colormaps.h */

Global char *MoveColormaps P((void));

/* XMOVELib.h */

Global void InsertRequestsInit P((void));
Global void InsertRequestsDone P((void));
Global Bool SendBuffer P((int fd, unsigned char *buf, int BytesToWrite));
Global Bool ReceiveBuffer P((int fd, unsigned char *buf, int BytesToRead));
Global Bool ReceiveReply P((int fd, unsigned char *buf, int BytesToRead, unsigned short SequenceNumber));
Global Font XMOVELoadFont P((int fd, unsigned short *seqno, Font id, char *name));
Global Atom XMOVEInternAtom P((int fd, unsigned short *seqno, char *name, Bool onlyifexists));
Global Cursor XMOVECreateGlyphCursor P((int fd, unsigned short *seqno, Cursor id, Font source_font, Font mask_font, unsigned int source_char, unsigned int mask_char, XColor *foreground, XColor *background));
Global Pixmap XMOVECreatePixmap P((int fd, unsigned short *seqno, Pixmap id, Drawable d, unsigned int width, unsigned int height, unsigned int depth));
Global void XMOVESetSelectionOwner P((int fd, unsigned short *seqno, Atom selection, Window owner, Time time));
Global Window XMOVEGetSelectionOwner P((int fd, unsigned short *seqno, Atom selection));
Global GContext XMOVECreateGC P((int fd, unsigned short *seqno, GContext id, Drawable d, unsigned long valuemask, XGCValues *values));
Global Cursor XMOVECreatePixmapCursor P((int fd, unsigned short *seqno, Cursor id, Pixmap source, Pixmap mask, XColor *foreground, XColor *background, unsigned int x, unsigned int y));
Global void XMOVEFreeGC P((int fd, unsigned short *seqno, GContext gc));
Global void XMOVEFreePixmap P((int fd, unsigned short *seqno, Pixmap pixmap));
Global void XMOVEMapWindow P((int fd, unsigned short *seqno, Window w));
Global Window XMOVECreateWindow P((int fd, unsigned short *seqno, Window id, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, int depth, unsigned int class, VisualID visualid, unsigned long valuemask, XSetWindowAttributes *attributes));
Global void XMOVEGrabButton P((int fd, unsigned short *seqno, unsigned int modifiers, unsigned int button, Window grab_window, Bool owner_events, unsigned int event_mask, int pointer_mode, int keyboard_mode, Window confine_to, Cursor curs));
Global void XMOVEGrabKey P((int fd, unsigned short *seqno, int key, unsigned int modifiers, Window grab_window, Bool owner_events, int pointer_mode, int keyboard_mode));
Global void XMOVEChangeProperty P((int fd, unsigned short *seqno, Window w, Atom property, Atom type, int format, int mode, unsigned char *data, int nelements));
Global Status XMOVEAllocColor P((int fd, unsigned short *seqno, Colormap cmap, XColor *def));
Global Status XMOVEAllocNamedColor P((int fd, unsigned short *seqno, Colormap cmap, char *colorname, XColor *hard_def, XColor *exact_def));
Global void XMOVEStoreColor P((int fd, unsigned short *seqno, Colormap cmap, XColor *def));
Global void XMOVEStoreNamedColor P((int fd, unsigned short *seqno, Colormap cmap, char *name, unsigned long pixel, int flags));
Global void XMOVEQueryColor P((int fd, unsigned short *seqno, Colormap cmap, XColor *def));
Global Status XMOVEAllocColorCells P((int fd, unsigned short *seqno, Colormap cmap, Bool contig, unsigned long *masks, unsigned int nplanes, unsigned long *pixels, unsigned int ncolors));
Global Colormap XMOVECreateColormap P((int fd, unsigned short *seqno, Pixmap mid, Window w, VisualID visual, int alloc));
Global Status XMOVELookupColor P((int fd, unsigned short *seqno, Colormap cmap, char *spec, XColor *def, XColor *scr));
Global char *XMOVEGetAtomName P((int fd, unsigned short *seqno, Atom atom));
Global void XMOVEUnmapWindow P((int fd, unsigned short *seqno, Window w));
Global void XMOVEGetInputFocus P((int fd, unsigned short *seqno));
Global Bool XMOVEVerifyRequest P((int fd, unsigned short *seqno));
Global int XMOVEReceiveReplyOrError P((int fd, unsigned short *seqno, unsigned short *error));
Global Status XMOVEQueryTree P((int fd, u_short *seqno, Window w, Window **children_return, u_int *nchildren_return));
Global void XMOVERaiseWindow P((int fd, u_short *seqno, Window w));

/* MoveImage.h */

Global void CopyImage P((XImage *image, XImage *new_image, unsigned int width, unsigned int height));
Global void MoveImage P((XImage *image, XImage *new_image, unsigned int width, unsigned int height, ColormapPtr cmap, Direction dir));

/* move_window.h */

Global Window move_window P((WindowPtr window_ptr));
Global Window XMOVEStackWindows P((WindowPtr window_ptr));

/* getsetProps.h */

Global void XMOVEGetSetProps P((Window oldwin, Window newwin, WindowMoveInfo *move_info, Bool ForceWindowPosition, int x, int y, int width, int height));

/* XMOVEPutImage.h */

Global void XMOVEPutImage P((int fd, unsigned short *seqno, register ImageFormatPtr image_format, Drawable d, GContext gc, register XImage *image, int req_xoffset, int req_yoffset, int x, int y, unsigned int req_width, unsigned int req_height));

/* move_selections.h */

Global void move_selections P(());

/* check_auth.h */

Global Bool CheckAuth P((int typelen, unsigned char *type, int keylen, unsigned char *key));
Global void InitMagicCookie P((char *DefaultHost, char *LocalHostName, int ListenForClientsPort, Bool update));

/* XMOVEImUtil.h */

Global void MapImage32 P((void *data, unsigned int width, unsigned int height, unsigned int depth, unsigned int bpl, ColormapPtr cmap, Direction dir, Bool src_endian, Bool dst_endian));
Global void MapImage16 P((void *data, unsigned int width, unsigned int height, unsigned int depth, unsigned int bpl, ColormapPtr cmap, Direction dir, Bool src_endian, Bool dst_endian));
Global void MapImage8 P((void *data, unsigned int width, unsigned int height, unsigned int depth, unsigned int bpl, ColormapPtr cmap, Direction dir));
Global void MapImage8Double P((void *data, unsigned int width, unsigned int height, unsigned int depth, unsigned int bpl, ColormapPtr src_cmap, ColormapPtr dst_cmap));

/* global variables within xmove */

extern Bool PrintDebug;
extern Bool MoveInProgress;
extern Server *new_server, *server;
extern unsigned int cur_mask, cur_base, client_mask, client_base;
extern int cur_fd, new_fd;
extern unsigned short *cur_seqno, *new_seqno;
extern Client *client;
extern MetaClient *meta_client;
extern char AuthType[256], AuthKey[256];
extern char OldAuthKey[256];
extern int AuthKeyLen, OldAuthKeyLen;
extern unsigned char ValidSetUpMessage[12];
extern int ValidSetUpMessageLen;
extern Bool processing_server;
extern int ServerScreen;

/* client/server access routines */

#define SetCurrentClientSequenceID(seqno) (client->SequenceNumber = seqno)
#define SetCurrentServerMaxReqLength(len) (server->max_request_size = server->formats->max_request_size = len)
#define SetCurrentClientMinKeycode(keycode) (client->min_keycode = keycode)
#define SetCurrentClientMaxKeycode(keycode) (client->max_keycode = keycode)
#define SetCurrentServerMinKeycode(keycode) (server->min_keycode = keycode)
#define SetCurrentServerImageByteOrder(order) (server->formats->image_byte_order = order)
#define SetCurrentServerImageBitmapUnit(unit) (server->formats->image_bitmap_unit = unit)
#define SetCurrentServerImageBitmapBitOrder(order) (server->formats->image_bitmap_bit_order = order)
#define SetCurrentServerImageBitmapPad(pad) (server->formats->image_bitmap_pad = pad)
#define SetCurrentServerMaxKeycode(keycode) (server->max_keycode = keycode)
#define GetCurrentClientMinKeycode() (client->min_keycode)
#define GetCurrentClientMaxKeycode() (client->max_keycode)
#define GetCurrentServerMinKeycode() (server->min_keycode)
#define GetCurrentServerMaxKeycode() (server->max_keycode)
#define GetCurrentClientName() (client->window_name)
#define GetCurrentClientDefaultDepth() (client->formats->sc_default_vis->vis_depth)

#endif /* XMOVE_H */

