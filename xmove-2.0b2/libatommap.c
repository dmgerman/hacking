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
#include "libatommap.h"
#include <X11/Xutil.h>

/* programmer's note: it is not safe to change atom->transient_map_func
   while in MapChangeProp, MapGetPropReply, MapDeleteProp or MapGetProperty */

extern Bool ignore_bytes;

void
initialize()
{
     AddAtomMapping("WM_HINTS", WM_HINTS_map);
     AddAtomMapping("WM_NAME", WM_NAME_map);
     AddAtomMapping("_OL_WIN_ATTR", _OL_WIN_ATTR_map);
     AddAtomMapping("WM_PROTOCOLS", WM_PROTOCOLS_map);
     AddAtomMapping("_SUN_DRAGDROP_INTEREST", _SUN_DRAGDROP_INTEREST_map);
     
     AddAtomTypeMapping("ATOM", ATOM_map);
     AddAtomTypeMapping("DRAWABLE", DRAWABLE_map);
     AddAtomTypeMapping("WINDOW", WINDOW_map);
     AddAtomTypeMapping("WM_PROTOCOLS", WM_PROTOCOLS_map);
     AddAtomTypeMapping("_SUN_DRAGDROP_SITE_RECTS", _SUN_DRAGDROP_SITE_RECTS_map);
     AddAtomTypeMapping("_SUN_DRAGDROP_TRIGGER", _SUN_DRAGDROP_TRIGGER_map);
     AddAtomTypeMapping("MULTIPLE", MULTIPLE_map);
}

static void WM_HINTS_map(req_type, property, type, selection, atom,
			 delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
	XWMHints *hints = (XWMHints *)data;
	long hints_flags;
	int initial_state;
	Direction dir;
     
	if (length != 36)
		return;
      
	hints_flags = ILong((u_char *)&hints->flags);
	initial_state = ILong((u_char *)&hints->initial_state);

	switch (req_type) {
	case MapChangeProp:
		dir = Request;
		break;

	case MapGetPropReply:
		dir = Reply;
		break;

	case MapMoveClientProps:	/* If icon_window is set, fake an expose event to client */
		dir = Server2Server;

		/*
		 * This is an example of sending an event to a client in mid-move.
		 * client->SequenceMapping holds the most recent sequence number
		 * used by the client. We create the event and then enqueue it onto
		 * the outgoing buffer of the client.
		 */
	  
		if (hints_flags & IconWindowHint) {
			unsigned char expose[32];
			WindowPtr window = FindWindowFromCurrentClient(
				MapWindowID(ILong((u_char *)&hints->icon_window), Event));

			if (window == NULL)
				break;
	       
			expose[0] = 12;
			ISetShort(&expose[2], (u_short)client->SequenceMapping);
			ISetLong(&expose[4], window->window_id);
			ISetShort(&expose[8], 0);
			ISetShort(&expose[10], 0);
			ISetShort(&expose[12], window->width);
			ISetShort(&expose[14], window->height);
			ISetShort(&expose[16], 0);
	       
			SaveBytes(&client->fdd->outBuffer, &expose[0], 32);
		}

		/*
		 * Here we're trying to properly move iconized windows. There may be no way
		 * of knowing whether the window is unmapped or iconized. So for top level
		 * windows, we create them with mapped == -1, if they're later mapped we
		 * set them to 1, and if unmapped back to -1. If we get here and mapped is
		 * 0, ie. GetWindowAttributes returned unmapped, then we guess it is iconized,
		 * since if it were really unmapped, mapped would equal -1.
		 */

		if (initial_state == NormalState || initial_state == IconicState) {
			WindowPtr windowptr = FindWindowFromCurrentClient(
				MapWindowID(*window, Reply));

			if (windowptr && (windowptr->parent_id & ~client->resource_mask) == 0) {
				if (windowptr->mapped > 0)
					ISetLong((u_char *)&hints->initial_state, NormalState);
				else if (windowptr->mapped == 0) {
					ISetLong((u_char *)&hints->initial_state, IconicState);
					windowptr->mapped = 1;
				}
			}
		}

		break;

	default:
		return;
	}
	  
	if (hints_flags & IconPixmapHint) {
		Pixmap id = ILong((void *)&hints->icon_pixmap);
		if (req_type == MapChangeProp) {
			PixmapPtr pixmap = FindPixmapFromCurrentClient(id);
			if (pixmap)
				ConvertPixmapToColormap(
					pixmap,	(ColormapPtr)client->colormap_list.top->contents);
		}
		ISetLong((unsigned char *)&hints->icon_pixmap, MapPixmapID(id, dir));
	}     
	if (hints_flags & IconWindowHint)
		ISetLong((unsigned char *)&hints->icon_window,
			 MapWindowID(ILong((u_char *)&hints->icon_window), dir));
     
	if (hints_flags & IconMaskHint) {
		Pixmap id = ILong((void *)&hints->icon_mask);
		if (req_type == MapChangeProp) {
			PixmapPtr pixmap = FindPixmapFromCurrentClient(id);
			if (pixmap)
				ConvertPixmapToColormap(
					pixmap,	(ColormapPtr)client->colormap_list.top->contents);
		}
		ISetLong((unsigned char *)&hints->icon_mask, MapPixmapID(id, dir));
	}     
	if (hints_flags & WindowGroupHint)
		ISetLong((unsigned char *)&hints->window_group,
			 MapWindowID(ILong((u_char *)&hints->window_group), dir));
}

static void WM_NAME_map(req_type, property, type, selection,
			atom, delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     if (req_type == MapChangeProp && !GetCurrentClientName())
	  SetCurrentClientName((char *)data, length);
}

static void _OL_WIN_ATTR_map(req_type, property, type, selection,
			     atom, delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;
     
     switch (req_type) {
     case MapChangeProp:
	  dir = Request;
	  break;

     case MapGetPropReply:
	  dir = Reply;
	  break;

     case MapMoveClientProps:
	  dir = Server2Server;
	  break;

     default:
	  return;
     }
     
     if (length == 12) {
	  ISetLong(&data[0], MapAtom(ILong(&data[0]), dir));
	  ISetLong(&data[4], MapAtom(ILong(&data[4]), dir));
	  ISetLong(&data[8], MapAtom(ILong(&data[8]), dir));
     } else {
	  if (ILong(&data[0]) & 1)
	       ISetLong(&data[4], MapAtom(ILong(&data[4]), dir));
	  
	  if (ILong(&data[0]) & 2)
	       ISetLong(&data[8], MapAtom(ILong(&data[8]), dir));

	  if (ILong(&data[0]) & 4)
	       ISetLong(&data[12], MapAtom(ILong(&data[12]), dir));

	  if (ILong(&data[0]) & 8)
	       ISetLong(&data[16], MapAtom(ILong(&data[16]), dir));
     }
}

static void WM_PROTOCOLS_map(req_type, property, type, selection,
			     atom, delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;
     
     switch (req_type) {
     case MapClientMessage:
	  ISetLong(data, MapAtom(ILong(data), Event));
	  return;
	  
     case MapGetPropReply:
	  dir = Reply;
	  break;

     case MapChangeProp:
	  dir = Request;
	  break;

     case MapMoveClientProps:
	  dir = Server2Server;
	  break;

     default:
	  return;
     }

     while (length) {
	  ISetLong(data, MapAtom(ILong(data), dir));
	  data += 4;
	  length -= 4;
     }

     return;
}

static void _SUN_DRAGDROP_INTEREST_map(req_type, property, type, selection,
				       atom, delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;
     int sites, windows;

     if (length == 0)
	  return;
     
     switch (req_type) {
     case MapChangeProp:
	  dir = Request;
	  break;
	  
     case MapGetPropReply:
	  dir = Reply;
	  break;

     case MapMoveClientProps:
	  dir = Server2Server;
	  break;

     default:
	  return;
     }
     
     /* the data in this property contains window IDs in various
	places. The structure is essentially a list of sites,
	each of which contains a window ID and lists of rectangles
	and/or window IDs. All the window IDs need to be mapped */
     
     sites = ILong(data+4);
     data += 8;

     while (sites--) {
	  ISetLong(data, MapWindowID(ILong(data), dir));
	  data += 12;
	  if (ILong(data)) {	/* list of window IDs -- map them */
	       windows = ILong(data+4);
	       data += 8;
	       while (windows--) {
		    ISetLong(data, MapWindowID(ILong(data), dir));
		    data += 4;
	       }
	  } else {		/* list of rectangles -- skip over them */
	       data += 8 + ILong(data+4)*16;
	  }
     }
}

/* Because this function needs to be applied to transient properties, there
   must be some way to link this function into the transient property and to
   remove it once the client is done with it.

   When this function gets called by ConvertSelection we take the property,
   look up its atom, and set that atom to link into this function. When
   the client deletes that property in the future we remove ourselves.

   We have problems if the client tries to use this same property for
   different purposes on different windows, or if the client uses a
   property which is already linked into a mapping routine due to its
   normal purpose which is here being subverted (ie using WM_HINTS to
   store the site rects). C'est la vie. */

static void _SUN_DRAGDROP_SITE_RECTS_map(req_type, property, type, selection,
					 atom, delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;
     
     switch (req_type) {
     case MapConvertSelection:
     case MapSelectionRequest:
	  FindAtom(*property)->transient_map_func = atom->type_map_func;
	  return;

     case MapChangeProp:
	  dir = Request;
	  break;
	  
     case MapGetPropReply:
	  dir = Reply;
	  break;

     case MapMoveClientProps:
	  dir = Server2Server;
	  break;

     default:
	  return;
     }

     while (length) {
	  ISetLong(&data[8], MapWindowID(ILong(&data[8]), dir));
	  data += 32;
	  length -= 32;
     }
}

static void _SUN_DRAGDROP_TRIGGER_map(req_type, property, type, selection,
				      atom, delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;

     if (length == 0)
	  return;
     
     switch (req_type) {
     case MapClientMessage:
	  dir = Event;
	  break;

     case MapSendClientMessage:
	  dir = Request;
	  break;

     default:
	  return;
     }

     ISetLong(&data[0], MapAtom(ILong(&data[0]), dir));
}

static void DRAWABLE_map(req_type, property, type, selection, atom,
			 delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;
     
     switch (req_type) {
     case MapChangeProp:
	  dir = Request;
	  break;

     case MapGetPropReply:
	  dir = Reply;
	  break;

     case MapMoveClientProps:
	  dir = Server2Server;
	  break;

     case MapConvertSelection:
     case MapSelectionRequest:
	  FindAtom(*property)->transient_map_func = atom->type_map_func;
	  return;
	  
     default:
	  return;
     }

     while (length) {
	  Drawable drw;

	  drw = ILong(data);
	  if (drw)
	       ISetLong(data, MapDrawable(ILong(data), dir));
	  data += 4;
	  length -= 4;
     }
}

static void WINDOW_map(req_type, property, type, selection, atom,
		       delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;
     
     switch (req_type) {
     case MapChangeProp:
	  dir = Request;
	  break;

     case MapGetPropReply:
	  dir = Reply;
	  break;

     case MapMoveClientProps:
	  dir = Server2Server;
	  break;

     case MapConvertSelection:
     case MapSelectionRequest:
	  FindAtom(*property)->transient_map_func = atom->type_map_func;
	  return;
	  
     default:
	  return;
     }

     while (length) {
	  Window win;

	  win = ILong(data);
	  if (win)
	       ISetLong(data, MapWindowID(ILong(data), dir));
	  
	  data += 4;
	  length -= 4;
     }
}

static void ATOM_map(req_type, property, type, selection, atom,
			delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Direction dir;
     
     switch (req_type) {
     case MapChangeProp:
	  dir = Request;
	  break;

     case MapGetPropReply:
	  dir = Reply;
	  break;

     case MapMoveClientProps:
	  dir = Server2Server;
	  break;

     case MapConvertSelection:
     case MapSelectionRequest:
	  FindAtom(*property)->transient_map_func = atom->type_map_func;
	  return;
	  
     default:
	  return;
     }

     while (length) {
	  ISetLong(data, MapAtom(ILong(data), dir));
	  data += 4;
	  length -= 4;
     }
}


/*
 * When a ConvertSelection converts with target of type MULTIPLE,
 * it should act as a series of ConvertSelections. So we must fake
 * the calls to other mapping routines in here, just as if those
 * multiple ConvertSelection calls went out.
 */

static void MULTIPLE_map(req_type, property, type, selection,
			 atom, delete, window, data, length)
AtomMapType req_type;
Atom *property;
Atom *type;
Atom *selection;
AtomPtr atom;
Bool delete;
Window *window;
unsigned char *data;
int length;
{
     Atom actual_type;
     int actual_format;
     unsigned long bytesafter;
     Window map_window = MapWindowID(*window, Request);
     Atom map_property = MapAtom(*property, Request);
     AtomPtr property_ptr;
     
     switch (req_type) {
     case MapSelectionRequest:
	  if (property_ptr = FindAtom(*property))
	       property_ptr->transient_map_func = atom->type_map_func;
	  return;

     case MapGetPropReply:
	  do_MULTIPLE_map(0, *window, length/4, data, True, MapSelectionRequest, Reply);
	  return;

     case MapChangeProp:
	  do_MULTIPLE_map(0, *window, length/4, data, False, MapChangeProp, Request);
	  return;

     case MapConvertSelection:
	  InsertRequestsInit();

	  while (XMOVEGetProperty(server->fdd->fd, &client->SequenceNumber,
				  map_window, map_property, 0, 1000000, False,
				  AnyPropertyType, &actual_type, &actual_format,
				  &length, &bytesafter, &data) != Success);
	  
	  do_MULTIPLE_map(*selection, *window, length, data, True,
			  MapConvertSelection, Request);
	  
	  XMOVEChangeProperty(server->fdd->fd, &client->SequenceNumber, map_window,
			      map_property, actual_type, actual_format,
			      PropModeReplace, data, length);
	  
	  free(data);
	  
	  if (property_ptr = FindAtom(*property))
	       property_ptr->transient_map_func = atom->type_map_func;

	  XMOVEGetInputFocus(server->fdd->fd, &client->SequenceNumber);
	  InsertRequestsDone();
	  return;
     }
}

static void do_MULTIPLE_map(selection, window, length, data, call_mapfunc, maptype, dir)
Atom selection;
Window window;
int length;
unsigned char *data;
Bool call_mapfunc;
AtomMapType maptype;
Direction dir;
{
     Atom target_atom, dest_atom, new_target, new_dest, new_selection;
     AtomPtr target_atom_ptr;
     Window new_window;

     while (length--) {
	  new_target = target_atom = ILong(data);
	  ISetLong(data, MapAtom(target_atom, dir));
	  data += 4;
	  
	  if (length-- == 0)	/* this should NEVER happen. atoms in pairs only */
	       return;

	  new_dest = dest_atom = ILong(data);
	  ISetLong(data, MapAtom(dest_atom, dir));
	  data += 4;

	  if (call_mapfunc && (dest_atom != 0)) {
	       if (dir == Request)
		    target_atom_ptr = FindAtom(target_atom);
	       else
		    target_atom_ptr = FindServerAtom(target_atom);
	       
	       new_selection = selection; /* any changes made by the mapping function to */
	       new_window = window;	     /* either selection or window are ignored. */
	       
	       if (target_atom_ptr && target_atom_ptr->type_map_func) {
		    (target_atom_ptr->type_map_func->MapProperty)
			 (maptype, &new_dest, &new_target, &new_selection,
			  target_atom_ptr, 0, &new_window, NULL, 0);
		    
		    if (new_dest != dest_atom)
			 ISetLong(data-4, new_dest);
		    
		    if (new_target != target_atom)
			 ISetLong(data-8, new_target);
	       }
	  }
     }
}
