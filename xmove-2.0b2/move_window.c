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
#include <stdio.h>

#define NEED_REPLIES
#include <X11/Xproto.h>
#include <X11/Xatom.h>
#include <malloc.h>

#include "xmove.h"

Global Window
move_window(WindowPtr window_ptr)
{
     Window xwin, parent_window;
     short GeomX, GeomY;
     int new_depth;

     Bool ForceWindowPosition = False;
     unsigned long new_winattr_mask;
     Window cur_window = MapWindowID(window_ptr->window_id, Request);
     XSetWindowAttributes new_attribs;

     xResourceReq XGetReq;
     xGetWindowAttributesReply XGetARep;
     xGetGeometryReply XGetGRep;

     xGetWindowAttributesReply *XGetARep_p;
     xGetGeometryReply         *XGetGRep_p;
     
     parent_window = MapWindowID(window_ptr->parent_id, Client2NewServer);
     
     if (window_ptr->move_info)
     {
	  XGetARep_p = &window_ptr->move_info->XGetARep;
	  XGetGRep_p = &window_ptr->move_info->XGetGRep;
     } else {
	  XGetARep_p = &XGetARep;
	  XGetGRep_p = &XGetGRep;
	  
	  XGetReq.reqType = X_GetWindowAttributes;
	  ISetShort((unsigned char *)&XGetReq.length, 2);
	  ISetLong((unsigned char *)&XGetReq.id, cur_window);
	   
	  SendBuffer(cur_fd, (u_char *) &XGetReq, sizeof(XGetReq));

	  ReceiveReply(cur_fd, (u_char *) XGetARep_p,
		       sizeof(XGetARep), ++(*cur_seqno));


	  XGetReq.reqType = X_GetGeometry;
	  
	  SendBuffer(cur_fd, (u_char *) &XGetReq, sizeof(XGetReq));

	  ReceiveReply(cur_fd, (u_char *) XGetGRep_p,
		       sizeof(XGetGRep), ++(*cur_seqno));

     }

     GeomX = IShort((unsigned char *)&XGetGRep_p->x);
     GeomY = IShort((unsigned char *)&XGetGRep_p->y);
     
     /*
      * Code used to be here which used TranslateCoordinates to determine
      * where a window really is on the screen. GetGeometry tells us where
      * the window is relative to its parent, which is a window manager shell
      * typically. However, since we currently unmap all windows at the 
      * beginning of movement, it appears, with olwm at least, that the window
      * is reparented back to root. Hence that code is no longer unnecessary.
      */
     
     if (window_ptr->parent_id == client->formats->sc_root_window)
	  ForceWindowPosition = True; /* when setting properties */
     
     /* map all of the mappable attributes */
     
     memcpy(&new_attribs, &window_ptr->attributes, sizeof(XSetWindowAttributes));

     if (window_ptr->attributes_mask & CWBackPixel) {
	  new_attribs.background_pixel =
	       MapColorCell(new_attribs.background_pixel, window_ptr->cmap, Client2NewServer);
     }

     if (window_ptr->attributes_mask & CWBorderPixel) {
	  new_attribs.border_pixel =
	       MapColorCell(new_attribs.border_pixel, window_ptr->cmap, Client2NewServer);
     }

     if (window_ptr->attributes_mask & CWBackingPixel) {
	  new_attribs.backing_pixel =
	       MapColorCell(new_attribs.backing_pixel, window_ptr->cmap, Client2NewServer);
     }

     /* If the background pixmap isn't None or ParentRelative then map */
     if ((window_ptr->attributes_mask & CWBackPixmap) &&
	 (new_attribs.background_pixmap > 1)) {
	  new_attribs.background_pixmap =  
	       MapPixmapID(new_attribs.background_pixmap, Client2NewServer);
     }
     
     /* If the border pixmap isn't CopyFromParent the map */
     if ((window_ptr->attributes_mask & CWBorderPixmap) &&
	 new_attribs.border_pixmap) {
	  new_attribs.border_pixmap =  
	       MapPixmapID(new_attribs.border_pixmap, Client2NewServer);
     }
     
     /* Check this.  Change all colormaps to root colormap */
     if ((window_ptr->attributes_mask & CWColormap) &&
	 (new_attribs.colormap != CopyFromParent)) {
	  new_attribs.colormap =
	       MapColormapID(new_attribs.colormap, Client2NewServer);
     }

     new_attribs.bit_gravity           = XGetARep_p->bitGravity;
     new_attribs.win_gravity           = XGetARep_p->winGravity;
     new_attribs.backing_store         = XGetARep_p->backingStore;
     new_attribs.backing_planes        = ILong((u_char *)&XGetARep_p->backingBitPlanes);
     new_attribs.backing_pixel         = ILong((u_char *)&XGetARep_p->backingPixel);
     new_attribs.save_under            = XGetARep_p->saveUnder;
     new_attribs.event_mask            = ILong((u_char *)&XGetARep_p->yourEventMask);
     new_attribs.do_not_propagate_mask = IShort((u_char *)&XGetARep_p->doNotPropagateMask);
     new_attribs.override_redirect     = XGetARep_p->override;

     new_winattr_mask = (IShort((u_char *)&XGetARep_p->class) == InputOnly)
	  ?
	  window_ptr->attributes_mask | (CWWinGravity | CWOverrideRedirect |
					 CWEventMask  | CWDontPropagate)
	  :
	  window_ptr->attributes_mask | (CWBitGravity    | CWWinGravity       |
					 CWBackingStore  | CWBackingPlanes    |
					 CWBackingPixel  | CWOverrideRedirect |
					 CWSaveUnder     | CWEventMask        |
					 CWDontPropagate);

     /* don't do the cursor now -- it might not be created yet. It'll be
	rechecked and applied later */
     
     new_winattr_mask &= ~CWCursor;
     
     xwin = XMOVECreateWindow(new_fd,
			      new_seqno,
			      MapWindowID(window_ptr->window_id, Client2NewServer),
			      parent_window,
			      GeomX,
			      GeomY,
			      IShort((u_char *)&XGetGRep_p->width),
			      IShort((u_char *)&XGetGRep_p->height),
			      IShort((u_char *)&XGetGRep_p->borderWidth),
			      IShort((u_char *)&XGetARep_p->class) == InputOnly ? 0 :
			        window_ptr->visual->vis_new_mapped->vis_depth,
			      IShort((u_char *)&XGetARep_p->class),
			      MapVisualID(window_ptr->visual->vis_id, Client2NewServer),
			      new_winattr_mask,
			      &new_attribs);
     
     Dprintf(("Creating window with id 0x%x\n parented by 0x%x\n",xwin,
	    parent_window));

     XMOVEGetSetProps (cur_window,
		       xwin,
		       window_ptr->move_info,
		       ForceWindowPosition,
		       IShort((u_char *)&XGetGRep_p->x),
		       IShort((u_char *)&XGetGRep_p->y),
		       IShort((u_char *)&XGetGRep_p->width),
		       IShort((u_char *)&XGetGRep_p->height));
     
     /* top-most windows already had window_ptr->mapped set in move.c */

     if ((window_ptr->parent_id & ~client->resource_mask) != 0) {
	  if (XGetARep_p->mapState)
	       window_ptr->mapped = 1;
	  else if (window_ptr->mapped > 0)
	       window_ptr->mapped = 0;
     }
     
     return xwin;

}


Global void
StoreWindowStates()
{
     hash_location loc;
     WindowPtr winptr;

     for (winptr = hashloc_init(&loc, client->window_table);
	  winptr; winptr = hashloc_getnext(&loc))
     {
	  WindowMoveInfo *move_info;
	  xResourceReq    XGetReq;
	  Window          cur_window = MapWindowID(winptr->window_id, Request);
	  
	  move_info = winptr->move_info = malloc(sizeof(*winptr->move_info));
	  
	  /* use query tree to get the ordering of the children */
	  
	  XMOVEQueryTree(cur_fd, cur_seqno, cur_window,
			 &move_info->children, &move_info->nchildren);

	  XGetReq.reqType = X_GetWindowAttributes;
	  ISetShort((unsigned char *)&XGetReq.length, 2);
	  ISetLong((unsigned char *)&XGetReq.id, cur_window);
	  
	  SendBuffer(cur_fd,
		     (unsigned char *) &XGetReq,
		     sizeof(xResourceReq));
	  
	  ReceiveReply(cur_fd, (unsigned char *) &move_info->XGetARep,
		       sizeof(xGetWindowAttributesReply), ++(*cur_seqno));


	  XGetReq.reqType = X_GetGeometry;
	  
	  SendBuffer(cur_fd,
		     (unsigned char *) &XGetReq,
		     sizeof(xResourceReq));
	  
	  ReceiveReply(cur_fd, (unsigned char *) &move_info->XGetGRep,
		       sizeof(xGetGeometryReply), ++(*cur_seqno));
	  
	  GetWindowPropsState(cur_window,
			      &move_info->nGetPRep, &move_info->XGetPRep);
     }
}
