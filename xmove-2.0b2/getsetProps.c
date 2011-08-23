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
#define NEED_REPLIES
#include <stdio.h>

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

#include "xmove.h"

void GetWindowPropsState P((Window curwin, u_int *XGetPRep_cnt, xGetPropertyReply **XGetPRep));

Global void
XMOVEGetSetProps (Window oldwin,
		  Window newwin,
		  WindowMoveInfo *move_info,
		  Bool ForceWindowPosition,
		  int x,
		  int y,
		  int width,
		  int height)
{
     u_int              nGetPRep;
     xGetPropertyReply *XGetPRep, *curGetPRep;
     xChangePropertyReq XChaPReq;
     
     unsigned char my_normal_hints[72];
     unsigned char *PropValue;
     Bool FoundNormalHints = False;
     
     if (move_info) {
	  nGetPRep = move_info->nGetPRep;
	  XGetPRep = move_info->XGetPRep;
     } else {
	  GetWindowPropsState(oldwin, &nGetPRep, &XGetPRep);
     }

     /* set-up XChaPReq constants */
     XChaPReq.reqType = X_ChangeProperty;
     XChaPReq.mode = 0;
     ISetLong((unsigned char *)&XChaPReq.window, newwin);
     
     curGetPRep = XGetPRep;

     while (nGetPRep--) {
	  AtomPtr atom_ptr;
	  Atom atom, new_atom, map_atom, new_type, map_type;
	  Window map_win, conv_win;
	  void (*map_func)() = (void (*)())NULL;
	  
	  atom = new_atom = (Atom)curGetPRep->pad1;
	  map_atom = MapAtom(atom, Server2Server);
	  atom_ptr = FindServerAtom(atom);

	  /* if atom_ptr is NULL, that means this property has neither been
	     created by this client nor has it been examined by this client.
	     Don't recreate a property created by others and never used by
	     this client! */
	  
	  if (atom_ptr == NULL) {
	       if (!move_info)
		    free(*((char **)&curGetPRep->pad2));
	       curGetPRep++;
	       continue;
	  }

	  PropValue = *((u_char **)&curGetPRep->pad2);
	  
	  new_type = ILong((unsigned char *)&curGetPRep->propertyType);
	  map_type = MapAtom(new_type, Server2Server);

	  /* if this is the NORMAL_HINTS property, and we need to force the
	     window's position, change the flags in the property to say that
	     the window's position was chosen by the user and not by the
	     client. The window manager SHOULD place the window as specified
	     if this is set. */
	  
	  if (atom == XA_WM_NORMAL_HINTS && ForceWindowPosition) {
/*	       ISetLong(&PropValue[0], (ILong(&PropValue[0]) | USPosition) & ~(PPosition));*/
	       ISetLong(&PropValue[0], ILong(&PropValue[0]) | PPosition | USPosition);
	       ISetLong(&PropValue[4], x);
	       ISetLong(&PropValue[8], y);
	       ISetLong(&PropValue[12], width);
	       ISetLong(&PropValue[16], height);
	       FoundNormalHints = True;
	  }

	  map_win = newwin;
	  
	  if (atom_ptr->property_map_func)
	       map_func = atom_ptr->property_map_func->MapProperty;
	  else {
	       atom_ptr = FindServerAtom(new_type);
	       if (atom_ptr && atom_ptr->type_map_func)
		    map_func = atom_ptr->type_map_func->MapProperty;
	  }
	  
	  if (map_func) {
	       conv_win = oldwin;
	       
	       (map_func)(MapMoveClientProps, &new_atom, &new_type, NULL,
			  atom_ptr, False, &conv_win, PropValue,
			  curGetPRep->format / 8  * ILong((unsigned char *)&curGetPRep->nItems));

	       if (new_atom != atom) /* if new_atom was changed */
		    map_atom = new_atom; /* use it instead of MapAtom() */

	       if (new_type != curGetPRep->propertyType)
		    map_type = new_type;

	       if (conv_win != oldwin)
		    map_win = conv_win;
	       
	  }
	  
	  XMOVEChangeProperty(new_fd, new_seqno, map_win, map_atom, map_type,
			      curGetPRep->format, PropModeReplace, PropValue,
			      ILong((unsigned char *)&curGetPRep->nItems));
	  
	  if (!move_info)
	       free(PropValue);
	  curGetPRep++;
     }
     
     if (ForceWindowPosition && !FoundNormalHints) {
	  ISetLong(&my_normal_hints[0], USPosition);
	  ISetLong(&my_normal_hints[4], x);
	  ISetLong(&my_normal_hints[8], y);
	  ISetLong(&my_normal_hints[12], width);
	  ISetLong(&my_normal_hints[16], height);
	  
	  XMOVEChangeProperty(new_fd, new_seqno, newwin,
			      XA_WM_NORMAL_HINTS, XA_WM_SIZE_HINTS, 32,
			      PropModeReplace, &my_normal_hints[0], 18);
     }
     
     if (!move_info)
	  free((char *) XGetPRep);
}

void
GetWindowPropsState(Window curwin, u_int *XGetPRep_cnt,
		    xGetPropertyReply **XGetPRep)
{
     xResourceReq XListReq;
     int PropCnt;
     Atom *PropList;
     xGetPropertyReply *curgprep;
     xListPropertiesReply XListRep;
     xGetPropertyReq XGetPReq;
     
     /* First, a note. We use the XGetPRep.pad1 to hold the
      * atom whose info is in XGetPRep, because the reply doesn't
      * actually hold the atom. In XGetPRep.pad2 we place a
      * pointer to the property's data. Both pad1 and pad2 are
      * stored in xmove's native byte ordering. This isn't "proper"
      * programming practice. So sue me!
      */

     XListReq.reqType = X_ListProperties;
     ISetShort((u_char *)&XListReq.length, 2);
     ISetLong((u_char *)&XListReq.id, curwin);

     /* send the XListProperties request to the server */
     
     SendBuffer(cur_fd,
		(unsigned char *) &XListReq,
		sizeof(xResourceReq));
     
     /* read back the reply header */
     
     ReceiveReply(cur_fd, (unsigned char *) &XListRep,
		  sizeof(xListPropertiesReply), ++(*cur_seqno));
     
     /* allocate space for the properties list and retrieve list */
     
     *XGetPRep_cnt = PropCnt = IShort((u_char *)&XListRep.nProperties);
     PropList = (Atom *) malloc(PropCnt * sizeof(Atom));
     curgprep = *XGetPRep = (xGetPropertyReply *)
	  malloc(PropCnt * sizeof(**XGetPRep));
     
     ReceiveBuffer(cur_fd, (u_char *)PropList,
		   IShort((u_char *)&XListRep.nProperties) * sizeof(Atom));
     
     /* set-up XGetPReq constants*/
     XGetPReq.reqType = X_GetProperty;
     ISetShort((unsigned char *)&XGetPReq.length, 6);
     XGetPReq.delete = False;
     ISetLong((unsigned char *)&XGetPReq.window, curwin);
     ISetLong((unsigned char *)&XGetPReq.type, 0);
     ISetLong((unsigned char *)&XGetPReq.longOffset, 0);
     ISetLong((unsigned char *)&XGetPReq.longLength, 1000000000); /* n, where n is VERY large */
     
     while (PropCnt--) {
	  unsigned char *CurValue;
	  Atom atom;
	  
	  atom = PropList[PropCnt];
	  ISetLong((unsigned char *)&XGetPReq.property, atom);
	  
	  SendBuffer(cur_fd,
		     (unsigned char *) &XGetPReq,
		     sizeof(xGetPropertyReq));
	  
	  ReceiveReply(cur_fd, (unsigned char *) curgprep, 32, ++(*cur_seqno));
	  
	  CurValue = (u_char *) malloc(ILong((u_char *)&curgprep->length) << 2);
	  curgprep->pad1 = (u_long) atom;
	  *((u_char **)&curgprep->pad2) = CurValue;
	  
	  ReceiveBuffer(cur_fd, CurValue, ILong((u_char *)&curgprep->length) << 2);
	  curgprep++;
     }

     free(PropList);
}
