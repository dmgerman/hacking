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

/*
 *
 * $Author: pds $
 * $Date: 1993/02/04 21:47:36 $
 * $Locker: ethan $
 * $Revision: 1.10 $
 * $Log: xmove.c,v $
 * Revision 1.10  1993/02/04  21:47:36  pds
 * *** empty log message ***
 *
 * Revision 1.9  1992/12/15  19:17:11  ethan
 * stolen by pds.
 *
 * Revision 1.8  1992/12/14  03:49:52  pds
 * *** empty log message ***
 *
 * Revision 1.7  1992/11/21  00:18:33  pds
 * Took out a couple of bugs... nothing earth shattering
 *
 * Revision 1.6  1992/11/11  04:31:36  ethan
 * *** empty log message ***
 *
 * Revision 1.5  1992/11/09  00:10:56  ethan
 * various attributes related routines removed
 * TagAllDescendants now works -- uses recursive method
 *
 * Revision 1.4  1992/11/08  23:38:09  pds
 * *** empty log message ***
 *
 * Revision 1.3  1992/10/20  22:13:45  pds
 * *** empty log message ***
 *
 * Revision 1.2  1992/10/16  16:47:18  pds
 * *** empty log message ***
 *
 * Revision 1.1  1992/10/13  22:18:11  pds
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
 * Revision 2.4  1992/01/29  01:52:10  shamash
 * fonts, pixmaps recorded
 *
 *
 */

Global unsigned char *MappingNotifyEventBuf;
Global long MappingNotifyEventBufLength;
extern LinkList AtomMappings;
extern LinkList AtomTypeMappings;
extern LinkList meta_client_list;

Global void
InitXMove(void)
{
    /* here we do all the local initialization stuff that we may need */
    /* to do */

    MappingNotifyEventBuf = (unsigned char *) Tcalloc(32, char);
    MappingNotifyEventBufLength = 32;

    /* fill up the MappingNotifyEvent with the appropriate values */

    MappingNotifyEventBuf[0] = 34;	     /* event code */
    MappingNotifyEventBuf[1] = 0;	     /* unused */

    /* bytes 2,3 are the sequence number.  They will be poked in later */

    MappingNotifyEventBuf[4] = 1;	     /* request:  1 = keyboard */

    /* bytes 5,6 are the first keycode, and count, respectively.  They */
    /* will be poked in later */
    
    /* the rest of the bytes (7..31) are unused. */
}
       

/* given a base and the current client, locate the owner of "base", whether
   it is the current client or it is related via the meta client. Do not
   search other clients unless they are related via the meta client. If the
   base is 0, ie this is a default colormap, root window or such, then
   the information about it is stored in the client locally and so return
   the current client. */

Global Client *
FindClientFromBase(unsigned long base)
{
     LinkLeaf *ll;
     Client *cur_client;
     
     if (client->resource_base == base || base == 0)
	  return client;

     ScanList(&meta_client->client_list, ll, cur_client, Client *) {
	  if (cur_client->resource_base == base)
	       return cur_client;
     }

     return NULL;
}


void
SetCurrentClientName(char *name, int length)
{
     /* name isn't guaranteed to be null-terminated. store a null-terminated
	string. */

     if (client->window_name)
	  free(client->window_name);
     
     if (name[length-1] == '\0') {
	  client->window_name = malloc(length);
	  strncpy(client->window_name, name, length);
     } else {
	  client->window_name = malloc(length+1);
	  strncpy(client->window_name, name, length);
	  client->window_name[length] = '\0';
     }
}

void
AddGCToCurrentClient(GCPtr gc)
{
#ifdef DEBUG
    Dprintf(("Adding gc to current client:\n"));
    Dprintf(("  id = %x, drawable = %x\n", 
	    gc->gc_id, gc->drawable_id));
#endif

    hash_add(client->gc_table, gc);
}

void
FreeClientLists(Client *client)
{
    Pointer item;
    CursorPtr cursor;
    FontPtr font;
    AtomPtr atom;
    hash_location loc;
    GCPtr gc;

    if (client->window_name)
	free(client->window_name);

    if (client->startup_message)
	free(client->startup_message);
     
    while (item = deleteFirst(&client->resource_maps))
	Tfree(item);

    hash_free(client->window_table);

    hash_free(client->pixmap_table);

    for (font = hashloc_init(&loc, client->font_table);
	 font; font = hashloc_deletenext(&loc))
    {
	Tfree(font->name);
	Tfree(font);
    }
    hash_free(client->font_table);

    hash_free(client->glyph_cursor_table);

    for (cursor = hashloc_init(&loc, client->cursor_table);
	 cursor; cursor = hashloc_deletenext(&loc))
    {
	if (cursor->source_image) {
	    Tfree(cursor->source_image->data);
	    Tfree(cursor->source_image);
	}

	if (cursor->mask_image) {
	    Tfree(cursor->mask_image->data);
	    Tfree(cursor->mask_image);
	}

	Tfree(cursor);
    }
     
    hash_free(client->cursor_table);

    for (gc = hashloc_init(&loc, client->gc_table);
	 gc; gc = hashloc_deletenext(&loc))
    {
	    if (gc->setclip_rects)
		    free(gc->setclip_rects);
	    free((void *)gc);
    }

    while (item = deleteFirst(&client->colormap_list)) {
	    Tfree((Pointer)(((ColormapPtr)item)->cell_array));
	    Tfree((Pointer)item);
    }

    while (item = deleteFirst(&client->grab_list))
	Tfree(item);

    for (atom = hashloc_init(&loc, client->atom_table);
	 atom; atom = hashloc_deletenext(&loc))
    {
	free(atom->atom_name);
	Tfree(atom);
    }
    hash_free(client->atom_table);

    while (item = deleteFirst(&client->selection_list))
	Tfree(item);
     
    if (client->formats) {
	if (client->formats->sc_formats)
	    free(client->formats->sc_formats);
	 
	if (client->formats->sc_visuals)
	    free(client->formats->sc_visuals);
	  
	free(client->formats);
    }
}

void
FreeServerLists(Server *server)
{
    Pointer item;
     
    if (server->fdd) {
	if (server->fdd->outBuffer.BlockSize > 0)
	    Tfree(server->fdd->outBuffer.data - server->fdd->outBuffer.data_offset);
	if (server->fdd->inBuffer.BlockSize > 0)
	    Tfree(server->fdd->inBuffer.data - server->fdd->inBuffer.data_offset);
    }
     
     
    if (server->server_name) free(server->server_name);
    while (item = deleteFirst(&server->reply_list))
	Tfree(item);

    /* because the client and its original server share pointers to the same 
       format, don't free up the lists if this is the client's original
       server. */

    if (server->formats != client->formats) {
	if (server->formats->sc_formats)
	    free(server->formats->sc_formats);

	if (server->formats->sc_visuals)
	    free(server->formats->sc_visuals);

	free(server->formats);
    }

    free(server);
}     

void
AddColormapToCurrentClient(ColormapPtr colormap)
{
    Dprintf(("Adding colormap to current client:\n"))

    appendToList(&client->colormap_list, (Pointer) colormap);
    if ((colormap->colormap_id & ~(client->resource_mask)) != 0)
	 client->allocated_colormaps++;
}

void
CreateNewCellArray(ColormapPtr cmap)
{
	int ncells;
	VisualPtr vis = cmap->visual;
	
	cmap->cell_array = Tcalloc(vis->vis_index[vis->vis_indices], ColorCellRec);
}

void
AddWindowToCurrentClient(WindowPtr window)
{
#ifdef DEBUG
    Dprintf(("Adding window to current client:\n"));
    Dprintf(("    id = 0x%x, parent = 0x%x, geom: %dx%d+%d+%d\n",
	    window->window_id, window->parent_id, 
	    window->width, window->height, window->x, window->y));
#endif

    hash_add(client->window_table, window);
}

void
RemoveGrabsUsingWindow(Window win)
{
     GrabPtr grab;
     
     ForAllInList(&client->grab_list)
     {
	  grab = (GrabPtr) CurrentContentsOfList(&client->grab_list);

	  if (grab->grab_window == win)
	       free((char *) deleteCurrent(&client->grab_list));
	  else
	       if (grab->confine_to == win) {
		    grab->confine_to = (Window)0;
	       }
     }
}
	  

void
RemoveClientFromMetaClient(MetaClient *meta_client, Client *client)
{
     ForAllInList(&meta_client->client_list) {
	  if (CurrentContentsOfList(&meta_client->client_list) ==
	      (Pointer)client)
	  {
	       deleteCurrent(&meta_client->client_list);
	       return;
	  }
     }
}

void
RemoveMetaClient(MetaClient *meta_client)
{
     ForAllInList(&meta_client_list) {
	  if (CurrentContentsOfList(&meta_client_list) ==
	      (Pointer)meta_client)
	  {
	       deleteCurrent(&meta_client_list);
	       return;
	  }
     }
}

void
RemoveCurrentWindow(LinkList *list)
{
     Window xwin = ((WindowPtr)CurrentContentsOfList(list))->window_id;
     RemoveGrabsUsingWindow(xwin);
     free((char *) deleteCurrent(list));
}

void
RemoveWindowFromCurrentClient(Window xwin)
{
    WindowPtr temp_window;
    
    if (temp_window = hash_delete(client->window_table, xwin))
	 free((char *)temp_window);
}

void
ReparentWindowForCurrentClient(Window xwin, Window parent, int16 x, int16 y)
{
    WindowPtr temp_window;
    
    if (temp_window = hash_find(client->window_table, xwin)) {
	 temp_window->parent_id = parent;
	 temp_window->x = x;
	 temp_window->y = y;
    }
}

void
RemoveGCFromCurrentClient(GContext xgc)
{
	GCPtr gc;
	
	Dprintf(("In RemoveGCFromCurrentClient()\n"));
	
	if (gc = hash_delete(client->gc_table, xgc)) {
		if (gc->setclip_rects)
			free(gc->setclip_rects);
		free((char *)gc);
	}
}

void
RemoveColormapFromCurrentClient(Colormap xcolormap)
{
     ColormapPtr temp_colormap;
     
     ForAllInList(&client->colormap_list)
     {
	  temp_colormap = (ColormapPtr)
	       CurrentContentsOfList(&client->colormap_list);
	  
	  if (temp_colormap->colormap_id == xcolormap)
	  {
	       temp_colormap = (ColormapPtr)
		    deleteCurrent(&client->colormap_list);
	       Tfree((Pointer)temp_colormap->cell_array);
	       Tfree((Pointer)temp_colormap);
	       
	       if ((xcolormap & ~(client->resource_mask)) != 0)
		    client->allocated_colormaps--;
	       return;
	  }
     }

     return;
}

void
RemoveFontFromCurrentClient(Font xfont)
{
    FontPtr temp_font;
    
    if (temp_font = hash_delete(client->font_table, xfont)) {
	 free((char *)temp_font->name);
	 free((char *)temp_font);
    }
}


void
RemoveCursorFromCurrentClient(Cursor xcursor)
{
     CursorPtr cursor;
     GlyphCursorPtr glyph;
     
     /* this routine is a bit different from the above several, since */
     /* we don't know exactly what kind of cursor this is.  It is */
     /* either a glyph cursor (created from a font), or a regular */
     /* cursor (created from a pixmap).  Therefore, we have two check */
     /* the two lists for the cursor. */
     
     if (cursor = hash_delete(client->cursor_table, xcursor)) {
	  if (cursor->source_image) {
	       Tfree(cursor->source_image->data);
	       Tfree(cursor->source_image);
	  }

	  if (cursor->mask_image) {
	       Tfree(cursor->mask_image->data);
	       Tfree(cursor->mask_image);
	  }
	  
	  free(cursor);
     } else
	  if (glyph = hash_delete(client->glyph_cursor_table, xcursor))
	       free(glyph);

     return;
}


void
RecolorCursorFromCurrentClient(Cursor xcursor, short fg_r, short fg_g, 
			       short fg_b, short bg_r, short bg_g, short bg_b)

{

     /* This routine will find a cursor and will change its color values. */
     /* We don't know exactly what kind of cursor this is.  It is */
     /* either a glyph cursor (created from a font), or a regular */
     /* cursor (created from a pixmap).  Therefore, we have two check */
     /* the two lists for the cursor. */
     
     CursorPtr temp_cursor;
     GlyphCursorPtr temp_glyph_cursor;
     
     if (temp_cursor = hash_find(client->cursor_table, xcursor)) {
	  temp_cursor->foreground_color.red = fg_r;
	  temp_cursor->foreground_color.green = fg_g;
	  temp_cursor->foreground_color.blue = fg_b;
	  temp_cursor->background_color.red =  bg_r;
	  temp_cursor->background_color.green =  bg_g;
	  temp_cursor->background_color.blue =  bg_b;
	  
	  return;
     }
     
     if (temp_glyph_cursor = hash_find(client->glyph_cursor_table, xcursor)) {
	  temp_glyph_cursor->foreground_color.red = fg_r;
	  temp_glyph_cursor->foreground_color.green = fg_g;
	  temp_glyph_cursor->foreground_color.blue = fg_b;
	  temp_glyph_cursor->background_color.red =  bg_r;
	  temp_glyph_cursor->background_color.green =  bg_g;
	  temp_glyph_cursor->background_color.blue =  bg_b;
     }
}

void
AddGlyphCursorToCurrentClient(GlyphCursorPtr cursor)
{
     hash_add(client->glyph_cursor_table, cursor);
}

void
AddCursorToCurrentClient(CursorPtr cursor)
{
     hash_add(client->cursor_table, cursor);
}

void
AddGrabToCurrentClient(GrabPtr grab)
{
    appendToList(&client->grab_list, (Pointer) grab);
}

void
ChangeGrabPointerFromCurrentClient(cursor, time, event_mask)
Cursor cursor;
Time time;
card16 event_mask;
{
    GrabPtr temp_grab;
    
    ForAllInList(&client->grab_list)
    {
	temp_grab = (GrabPtr)CurrentContentsOfList(&client->grab_list);
	if(temp_grab->type == 26)
	{
	    temp_grab->cursor = cursor;
	    temp_grab->time = time;
	    temp_grab->event_mask = event_mask;
	    return;
	}
    }
    return;
}

void
RemoveGrabButtonFromCurrentClient(button, grab_window, modifiers)
card8 button;
Window grab_window;
card16 modifiers;
{
    GrabPtr temp_grab;
    
    ForAllInList(&client->grab_list)
    {
	temp_grab = (GrabPtr)CurrentContentsOfList(&client->grab_list);
	if((temp_grab->type == 28) &&
	   (temp_grab->button == button) &&
	   (temp_grab->grab_window == grab_window) &&
	   (temp_grab->modifiers == modifiers))
	{
	    temp_grab=(GrabPtr)deleteCurrent(&client->grab_list);
	    free((char *)temp_grab);
	    return;
	}
    }
    return;
}

void
RemoveGrabKeyFromCurrentClient(key, grab_window, modifiers)
card8 key;
Window grab_window;
card16 modifiers;
{
    GrabPtr temp_grab;
    
    ForAllInList(&client->grab_list)
    {
	temp_grab = (GrabPtr)CurrentContentsOfList(&client->grab_list);
	if((temp_grab->type == 33) &&
	   (temp_grab->key == key) &&
	   (temp_grab->grab_window == grab_window) &&
	   (temp_grab->modifiers == modifiers))
	{
	    temp_grab=(GrabPtr)deleteCurrent(&client->grab_list);
	    free((char *)temp_grab);
	    return;
	}
    }
    return;
}

void
RemoveGrabPointerFromCurrentClient()
{
    GrabPtr temp_grab;
    
    ForAllInList(&client->grab_list)
    {
	temp_grab = (GrabPtr)CurrentContentsOfList(&client->grab_list);
	if(temp_grab->type == 26)
	{
	    temp_grab=(GrabPtr)deleteCurrent(&client->grab_list);
	    free((char *)temp_grab);
	    return;
	}
    }
    return;
}

void
RemoveGrabKeyboardFromCurrentClient()
{
    GrabPtr temp_grab;
    
    ForAllInList(&client->grab_list)
    {
	temp_grab = (GrabPtr)CurrentContentsOfList(&client->grab_list);
	if(temp_grab->type == 31)
	{
	    temp_grab=(GrabPtr)deleteCurrent(&client->grab_list);
	    free((char *)temp_grab);
	    return;
	}
    }
    return;
}

void
AddPixmapToCurrentClient(PixmapPtr pixmap)
{
    Dprintf(("Adding pixmap to current client:\n"));
    Dprintf(("id:  0x%x, size = (%d,%d), depth = %d\n",
	     pixmap->pixmap_id, pixmap->width, pixmap->height, pixmap->depth));

    hash_add(client->pixmap_table, pixmap);
}

void
RemovePixmapFromCurrentClient(Pixmap pixmap)
{
    PixmapPtr temp_pixmap;
    
    if (temp_pixmap = hash_delete(client->pixmap_table, pixmap))
	 free((char *)temp_pixmap);
}

void
AddSelectionToCurrentClient(SelectionPtr selection)
{
#ifdef DEBUG
    Dprintf(("Adding selection to current client:\n"))
    Dprintf(("selection: %d\n", selection->selection))
#endif

    appendToList(&client->selection_list, (Pointer) selection);
}

void


RemoveSelectionFromCurrentClient(Atom selection)
{
    SelectionPtr temp_selection;
    
    ForAllInList(&client->selection_list)
    {
	temp_selection = (SelectionPtr)
	     CurrentContentsOfList(&client->selection_list);
	
	if(temp_selection->selection == selection)
	{
	    temp_selection =
		 (SelectionPtr)deleteCurrent(&client->selection_list);
	    free((char *)temp_selection);
	    return;
	}
    }
    return;
}

void
AddAtomToCurrentClient(AtomPtr atom)
{
#ifdef DEBUG
    Dprintf(("Adding atom to current client:\n"));
    Dprintf(("name: %s\n", atom->atom_name));
#endif

    hash_add(client->atom_table, atom);
}

AtomPtr
CreateNewAtom(Atom atom, char *name, Direction dir)
{
     AtomPtr new_atom;
     Atom client_atom;

     client_atom = atom;
     if (dir == Request) {
	  if (new_atom = FindAtom(client_atom))
	       return new_atom;
     } else {
	  if (new_atom = FindServerAtom(atom))
	       return new_atom;
	  
	  while (new_atom = FindAtom(client_atom))
	       client_atom = new_atom->server_atom;
     }
     
     new_atom = malloc(sizeof(AtomRec));
     new_atom->client_atom        = client_atom;
     new_atom->server_atom        = atom;
     new_atom->property_map_func  = FindAtomMapping(name);
     new_atom->type_map_func      = FindAtomTypeMapping(name);
     new_atom->transient_map_func = NULL;
     new_atom->atom_name          = malloc(strlen(name)+1);
     strcpy(new_atom->atom_name, name);

     hash_add(client->atom_table, new_atom);
     return new_atom;
}

AtomPtr
FindAtom(Atom atom)
{
     return(hash_find(client->atom_table, atom));
}

AtomPtr
FindServerAtom(Atom atom)
{
     hash_location loc;
     AtomPtr temp_atom;

     for (temp_atom = hashloc_init(&loc, client->atom_table);
	  temp_atom; temp_atom = hashloc_getnext(&loc))
     {
	  if (temp_atom->server_atom == atom)
	       return temp_atom;
     }

     return NULL;
}

void
RemoveAtomFromCurrentClient(Atom atom)
{
    AtomPtr temp_atom;
    
    if (temp_atom = hash_delete(client->atom_table, atom)) {
	 free(temp_atom->atom_name);
	 free((char *)temp_atom);
    }
}

void
AddFontToCurrentClient(FontPtr font)
{
#ifdef DEBUG
    Dprintf(("Adding font to current client:\n"));
    Dprintf(("name = %s, id = 0x%x\n", 
	     font->name, font->font_id));
#endif

    hash_add(client->font_table, font);
}

AtomMappingPtr
FindAtomMapping(char *name)
{
     AtomMappingPtr atommap;

     ForAllInList(&AtomMappings)
     {
	  atommap = (AtomMappingPtr) CurrentContentsOfList(&AtomMappings);
	  if (strcmp(name, atommap->name) == 0)
	       return atommap;
     }

     return NULL;
}

AtomMappingPtr
FindAtomTypeMapping(char *name)
{
     AtomMappingPtr atommap;

     ForAllInList(&AtomTypeMappings)
     {
	  atommap = (AtomMappingPtr) CurrentContentsOfList(&AtomTypeMappings);
	  if (strcmp(name, atommap->name) == 0)
	       return atommap;
     }

     return NULL;
}

AtomMappingPtr
AddAtomMapping(char *name, void (*MapProperty)())
{
     AtomMappingPtr atommap;

     if (atommap = FindAtomMapping(name))
	  return NULL;

     atommap = malloc(sizeof(AtomMappingRec));

     if (atommap == NULL)
	  return NULL;

     atommap->name         = name;
     atommap->MapProperty  = MapProperty;
     
     appendToList(&AtomMappings, (Pointer) atommap);

     return atommap;
}

AtomMappingPtr
AddAtomTypeMapping(char *name, void (*MapProperty)())
{
     AtomMappingPtr atommap;

     if (atommap = FindAtomTypeMapping(name))
	  return NULL;

     atommap = malloc(sizeof(AtomMappingRec));

     if (atommap == NULL)
	  return NULL;

     atommap->name         = name;
     atommap->MapProperty  = MapProperty;
     
     appendToList(&AtomTypeMappings, (Pointer) atommap);

     return atommap;
}

ColormapPtr
FindColormapFromCurrentClient(Colormap cmap_id)
{
	ColormapPtr temp_cmap;
	Client *cur_client = FindClientFromBase(cmap_id & ~(client->resource_mask));

	if (cur_client == NULL)
		return NULL;

	if ((cmap_id & (~client->resource_mask)) == 0) {
		return (ColormapPtr)TopOfList(&cur_client->colormap_list);
	}
     
	ForAllInList(&cur_client->colormap_list)
	{
		temp_cmap = (ColormapPtr)
			CurrentContentsOfList(&cur_client->colormap_list);
		
		if(temp_cmap->colormap_id == cmap_id)
			return(temp_cmap);
	}

	return NULL;
}

/* ETHAN: AllocNewColorCell needs some comments! */

void
SetColorCell(ColorIndexPtr index, ColormapPtr cmap, Bool force,
	     card16 red, card16 green, card16 blue, card8 rgbmask)
{
	int cur_index = -1;
	ColorCellPtr cell;

	while (++cur_index < cmap->visual->vis_indices) {
		cell = cmap->cell_array + index->cell_index[cur_index];
		
		if (cell->usage_count == 1 || (force && cell->read_write)) {
			if (rgbmask & DoRed)
				cell->red = red;
			if (rgbmask & DoGreen)
				cell->green = green;
			if (rgbmask & DoBlue)
				cell->blue = blue;
		}
	}
}

Bool
AllocColorCell(card32 pixel, ColormapPtr cmap, Bool read_write,
		  ColorIndexPtr index_arg)
{
	ColorCellPtr new_cell, temp_cell;
	card32 client_pixel;
	ColorIndexRec indexrec;
	ColorIndexPtr index = index_arg ? index_arg : &indexrec;
	int vis_index = -1, min_index, max_index;
	card32 cur_pixel;
	int split;
	VisualPtr svis, cvis;

	if (cmap == NULL)
		return False;

	cvis = cmap->visual;
	svis = cvis->vis_mapped;
	
	while (++vis_index < cvis->vis_indices) {
		min_index = cvis->vis_index[vis_index];
		max_index = cvis->vis_index[vis_index + 1];
		cur_pixel = (pixel >> svis->vis_shift[vis_index]) & svis->vis_mask[vis_index];

		if (new_cell = FindServerColorCell(cur_pixel, cmap, vis_index))
		{
			client_pixel = new_cell - cmap->cell_array;
		} else {
			client_pixel = min_index;
			while (client_pixel < max_index) {
				if (cmap->cell_array[client_pixel].usage_count == 0)
					break;
				client_pixel++;
			}
			
			if (client_pixel == max_index) {
				cmap->cell_array[min_index].usage_count++;
				index->cell_index[vis_index] = min_index; /* we're screwed */
				debug(2, (stderr, "screwed | "));
				Eprintf(("Out of colors in AllocColorCell\n"));
				continue;
			}
			new_cell = &cmap->cell_array[client_pixel];
		}
		if (new_cell->usage_count++ == 0) {
			new_cell->client_pixel = client_pixel - min_index;
			new_cell->server_pixel = cur_pixel;
			new_cell->read_write = read_write;
			debug(2, (stderr, "%3x %3x | ", cur_pixel, new_cell->client_pixel));
		} else {
			debug(2, (stderr, "%3x %3x %3x | ", cur_pixel,
				  new_cell->server_pixel, new_cell->client_pixel));
		}
		index->cell_index[vis_index] = client_pixel;
	}
	debug(2, (stderr, ")\n"));
	return True;
}

Bool
FindColorIndex(card32 pixel, ColormapPtr cmap, ColorIndexPtr index)
{
	VisualPtr vis;
	int cur_index = -1;
	card32 cur_pixel;
	ColorCellPtr cell;

	if (!cmap || !index)
		panic("xmove assert: FindColorIndex missing cmap or index\n");
	vis = cmap->visual;

	while (++cur_index < vis->vis_indices) {
		cur_pixel = (pixel >> vis->vis_shift[cur_index]) & vis->vis_mask[cur_index];
		cell = FindColorCell(cur_pixel, cmap, cur_index);
		if (cell == NULL)
			return False;
		index->cell_index[cur_index] = cell - cmap->cell_array;
	}
	return True;
}

ColorCellPtr
FindColorCell(card32 pixel, ColormapPtr cmap, int vis_index)
{
	ColorCellPtr cell;

	if (cmap == NULL)
		return NULL;

	cell = cmap->cell_array + cmap->visual->vis_index[vis_index] + pixel;

	if (IsVisualLinear(cmap->visual))
		return cell;
	
	if (cell->usage_count) {
		if (cell->client_pixel != pixel)
			panic("xmove assert: FindColorCell client_pixel != pixel\n");
		return cell;
	}
	return NULL;
}

/* "pixel" is from the server's perspective */

Bool
FindServerColorIndex(card32 pixel, ColormapPtr cmap, ColorIndexPtr index)
{
	VisualPtr vis;
	int cur_index = -1;
	card32 cur_pixel;
	ColorCellPtr cell;

	if (!cmap || !index)
		panic("xmove assert: FindColorIndex missing cmap or index\n");
	vis = cmap->visual->vis_mapped;

	while (++cur_index < vis->vis_indices) {
		cur_pixel = (pixel >> vis->vis_shift[cur_index]) & vis->vis_mask[cur_index];
		cell = FindServerColorCell(cur_pixel, cmap, cur_index);
		if (cell == NULL)
			return False;
		index->cell_index[cur_index] = cell - cmap->cell_array;
	}
	return True;
}

ColorCellPtr
FindServerColorCell(card32 pixel, ColormapPtr cmap, int vis_index)
{
	ColorCellPtr cur_cell, max_cell;
	VisualPtr vis;

	if (cmap == NULL)
		return NULL;

	vis = cmap->visual;
	cur_cell = cmap->cell_array + vis->vis_index[vis_index];

	if (IsVisualLinear(vis))
		return cur_cell +
			MapIntensity(pixel, vis->vis_mapped->vis_depth, vis->vis_depth);

	max_cell = cmap->cell_array + vis->vis_index[vis_index + 1];
     
	while (cur_cell < max_cell) {
		if (cur_cell->usage_count && cur_cell->server_pixel == pixel)
			return cur_cell;

		cur_cell++;
	}

	return NULL;
}

ColorCellPtr
FindNewServerColorCell(card32 pixel, ColormapPtr cmap, int vis_index)
{
	ColorCellPtr cur_cell, max_cell;
	VisualPtr vis;

	if (cmap == NULL)
		return NULL;

	vis = cmap->visual;
	cur_cell = cmap->cell_array + vis->vis_index[vis_index];

	if (IsVisualLinear(vis))
		return cur_cell +
			MapIntensity(pixel, vis->vis_new_mapped->vis_depth, vis->vis_depth);

	max_cell = cmap->cell_array + vis->vis_index[vis_index + 1];
     
	while (cur_cell < max_cell) {
		if (cur_cell->usage_count && cur_cell->new_server_pixel == pixel)
			return cur_cell;

		cur_cell++;
	}

	return NULL;
}

/*
 * It is relied on that the sum of all usage counts for each "index"
 * into the colormap be equal. Thus, it is necessary that usage_count be
 * greater than zero for each index pixel.
 */

void
RemoveColorIndex(ColorIndexPtr index, ColormapPtr cmap)
{
	VisualPtr vis;
	ColorCellPtr cell;
	int i = 0;

	if (cmap == NULL)
		return;

	/*
	 * usage_count stays permanently at >= 1 iff the visual is read only
	 * because client may cache the color and rely on its permanence.
	 */
		
	vis = cmap->visual;
	if (IsVisualLinear(vis))
		return;

	while (i < vis->vis_indices) {
		cell = cmap->cell_array + index->cell_index[i];
		
		if (cell->usage_count)
			cell->usage_count--;
		else
			fprintf(stderr, "RemoveColorIndex %d==%d usage count 0\n",
				i, index->cell_index[i]);
		i++;
	}
}

GCPtr
FindGCFromCurrentClient(GContext gc_id)
{
     Client *cur_client = FindClientFromBase(gc_id & ~(client->resource_mask));

     if (cur_client == NULL)
	  return NULL;

     return(hash_find(cur_client->gc_table, gc_id));
}

/* The following routines are used to parse the XSetWindowAttributes */
/* structure that is created for each window */

static void
SetBackgroundPixmap(WindowPtr window_ptr,
		    Pixmap background_pixmap)
{
    Dprintf(("setting background pixmap to 0x%x\n", 
	   background_pixmap))

    window_ptr->attributes.background_pixmap = background_pixmap;
    window_ptr->attributes_mask |= CWBackPixmap;
}

static void
SetBackgroundPixel(WindowPtr window_ptr,
		   unsigned long background_pixel)
{
    window_ptr->attributes.background_pixel = background_pixel;
    window_ptr->attributes_mask |= CWBackPixel;

    Dprintf(("setting background pixel to 0x%x.\n", 
	   background_pixel))
}

static void
SetBorderPixmap(WindowPtr window_ptr,
		Pixmap border_pixmap)
{
    window_ptr->attributes.border_pixmap = border_pixmap;
    window_ptr->attributes_mask |= CWBorderPixmap;

    Dprintf(("setting border pixmap to 0x%x.\n", border_pixmap))
}

static void
SetBorderPixel(WindowPtr window_ptr,
	       unsigned long border_pixel)
{
    window_ptr->attributes.border_pixel = border_pixel;
    window_ptr->attributes_mask |= CWBorderPixel;

    Dprintf(("setting border pixel to 0x%x.\n", border_pixel))
}

static void
SetBackingPixel(WindowPtr window_ptr,
		unsigned long backing_pixel)
{
     window_ptr->attributes.backing_pixel = backing_pixel;
     window_ptr->attributes_mask |= CWBackingPixel;

    Dprintf(("setting backing pixel to 0x%x.\n", backing_pixel))
}

static void
SetColormap(WindowPtr window_ptr,
	    Colormap colormap)
{
    window_ptr->attributes.colormap = colormap;
    window_ptr->attributes_mask |= CWColormap;
	    
    Dprintf(("setting colormap to 0x%x.\n", colormap))
}

static void
SetCursor(WindowPtr window_ptr,
	  Cursor cursor)
{
    window_ptr->attributes.cursor = cursor;
    window_ptr->attributes_mask |= CWCursor;
    
    Dprintf(("setting cursor to 0x%x.\n", cursor))
}

/* ParseWindowBitmaskValueList only stores SOME of the attributes
   that can be set for a window. In particular, it stores those attributes
   which cannot be obtained from GetGeometry and GetWindowAttributes. That
   currently includes Background Pixmap and Pixel, Border Pixmap and Pixel,
   and cursor. */

void
ParseWindowBitmaskValueList(WindowPtr window_ptr,
			    unsigned long cmask, 
			    unsigned char *ValueList)
{
     ColormapPtr cmap = window_ptr->cmap;

     if (cmask & CWColormap)
     {
	  /* we're screwed. this is about to change the colormap on us, but we have to
	     map the colors before we get to the new colormap. So skip ahead, find the
	     new colormap, and use it. */

	  unsigned char *CmapValue = ValueList;
	  unsigned int attrmask;
	  Colormap colormap;

	  attrmask = (cmask & (CWColormap-1));
	  while (attrmask) {
	       if (attrmask & 1)
		    CmapValue += 4;
	       attrmask >>= 1;
	  }

	  colormap = IParseLong(CmapValue);

	  if ((colormap == 0) ||
	      ((cmap = FindColormapFromCurrentClient(colormap)) == NULL))
	       cmap = (ColormapPtr)client->colormap_list.top->contents;
     }

     /* there are bits in the controlling bitmask, figure out which */
     /* the ctype is a set type, so this code is similar to PrintSET */
     
     if (cmask & CWBackPixmap)
     {
	  /* background pixmap */
	  Pixmap pixmap = (Pixmap) IParseLong(ValueList);

	  SetBackgroundPixmap(window_ptr, pixmap);
	  pixmap = MapPixmapID(pixmap, Request);
	  ISetLong(ValueList, pixmap);
	  
	  ValueList += 4;
     }
     
     if (cmask & CWBackPixel)
     {
	  /* background pixel value */
	  unsigned long pixel_value = IParseLong(ValueList);

	  SetBackgroundPixel(window_ptr, pixel_value);
	  pixel_value = MapColorCell(pixel_value, cmap, Request);
	  ISetLong(ValueList, pixel_value);
	  
	  ValueList += 4;
     }
     
     if (cmask & CWBorderPixmap)
     {
	  /* pixmap for the border */
	  Pixmap pixmap = IParseLong(ValueList);

	  SetBorderPixmap(window_ptr, pixmap);
	  pixmap = MapPixmapID(pixmap, Request);
	  ISetLong(ValueList, pixmap);
	  
	  ValueList += 4;
     }
     
     if (cmask & CWBorderPixel)
     {
	  /* border color */
	  unsigned long border_pixel = IParseLong(ValueList);

	  SetBorderPixel(window_ptr, border_pixel);
	  border_pixel = MapColorCell(border_pixel, cmap, Request);
	  ISetLong(ValueList, border_pixel);
	  
	  ValueList += 4;
     }
     
     
     if (cmask & CWBitGravity)
	  ValueList += 4;
     
     if (cmask & CWWinGravity)
	  ValueList += 4;
     
     if (cmask & CWBackingStore)
	  ValueList += 4;
     
     if (cmask & CWBackingPlanes)
	  ValueList += 4;
     
     if (cmask & CWBackingPixel) {
	  unsigned long pixel = IParseLong(ValueList);

	  SetBackingPixel(window_ptr, pixel);
	  pixel = MapColorCell(pixel, cmap, Request);
	  ISetLong(ValueList, pixel);
	  
	  ValueList += 4;
     }
     
     if (cmask & CWOverrideRedirect)
	  ValueList += 4;
     
     if (cmask & CWSaveUnder)
	  ValueList += 4;
     
     if (cmask & CWEventMask)
	  ValueList += 4;
     
     if (cmask & CWDontPropagate)
	  ValueList += 4;
     
     if (cmask & CWColormap)
       {
	 Colormap colormap  = IParseLong(ValueList);

	 SetColormap(window_ptr, colormap);
	 window_ptr->cmap = cmap; /* use value calculated earlier */
	 
	 colormap = MapColormapID(colormap, Request);
	 ISetLong(ValueList, colormap);

	 ValueList += 4;
       }
	
     if (cmask & CWCursor)
     {
	  Cursor cursor = IParseLong(ValueList);

	  SetCursor(window_ptr, cursor);
	  cursor = MapCursorID(cursor, Request);
	  ISetLong(ValueList, cursor);
	  
	  ValueList += 4;
     }
}

WindowPtr
FindWindowFromCurrentClient(Window xwin)
{
    Client *cur_client = FindClientFromBase(xwin & ~(client->resource_mask));

    if (cur_client == NULL)
	 return NULL;
    
    return(hash_find(cur_client->window_table, xwin));
}

PixmapPtr
FindPixmapFromCurrentClient(Pixmap pixmap)
{
     Client *cur_client = FindClientFromBase(pixmap & ~(client->resource_mask));

     if (cur_client == NULL)
	 return NULL;

     return(hash_find(cur_client->pixmap_table, pixmap));
}


void
UntagAllWindows()
{
     WindowPtr window;
     hash_location loc;

     window = hashloc_init(&loc, client->window_table);
     while (window) {
	  window->tag = 0;
	  window = hashloc_getnext(&loc);
     }
}

void
DestroyTaggedWindows()
{
     WindowPtr window;
     hash_location loc;

     window = hashloc_init(&loc, client->window_table);
     while (window) {
	  if (window->tag) {
	       RemoveGrabsUsingWindow(window->window_id);
	       free((char *)window);
	       window = hashloc_deletenext(&loc);
	  } else
	       window = hashloc_getnext(&loc);
     }
}

/* The X protocol relies on being able to do an operation to a family of
   windows, i.e. deleting a window and all of its descendants.  This is 
   conducive to a tree data structure, but X also relies on a stacking order
   for displaying windows, so it is imperative that we keep windows in the
   order that they were created in.

   To do both of these with the smallest effort, a singly linked list of
   windows is kept, each containing the id of thier parent.  There is also a
   field for marking windows on which we would like an operation (such as
   delete) to be performed.  This is necessary because if we were to try and
   do a delete without first tagging windows, we would delete critical
   information before it had been used to find more descendants.

   TagAllDescendants is recursive. It takes a parent ID and must mark all
   of its children. So it scans through all windows. If a window has the
   parameter as its parent, it is tagged and TagAllDescendants is called
   recursively for this newly tagged window's children.
*/

void DoTagAllDescendants(Window parent_id);
void TagAllDescendants(Window parent_id)
{
  /* start by untagging all of the windows */
  UntagAllWindows();
  DoTagAllDescendants(parent_id);
}

void DoTagAllDescendants(Window parent_id)
{
     WindowPtr window;
     hash_location loc;

     window = hashloc_init(&loc, client->window_table);
     while (window) {
	  if (window->parent_id == parent_id && !window->tag) {
	       window->tag = 1;
	       DoTagAllDescendants(window->window_id);
	  }
	  window = hashloc_getnext(&loc);
     }
}


/* routines need to manipulate the window structure */

static void
SetFunction(GCPtr gc_ptr, int function)
{
    Dprintf(("setting function to 0x%x\n", function))

    gc_ptr->values.function = function;
    gc_ptr->values_mask |= GCFunction;
}

static void
SetPlaneMask(GCPtr gc_ptr, unsigned long plane_mask)
{
    Dprintf(("setting plane mask to 0x%x\n", plane_mask))

    gc_ptr->values.plane_mask = plane_mask;
    gc_ptr->values_mask |= GCPlaneMask;
}

static void
SetForeground(GCPtr gc_ptr, unsigned long foreground)
{
    Dprintf(("setting foreground to 0x%x\n", foreground))

    gc_ptr->values.foreground = foreground;
    gc_ptr->values_mask |= GCForeground;
}

static void
SetBackground(GCPtr gc_ptr, unsigned long background)
{
    Dprintf(("setting background to 0x%x\n", background))

    gc_ptr->values.background = background;
    gc_ptr->values_mask |= GCBackground;
}

static void
SetLineWidth(GCPtr gc_ptr, int line_width)
{
    Dprintf(("setting line_width to 0x%x\n", line_width))

    gc_ptr->values.line_width = line_width;
    gc_ptr->values_mask |= GCLineWidth;
}

static void
SetLineStyle(GCPtr gc_ptr, int line_style)
{
    Dprintf(("setting line_style to 0x%x\n", line_style))

    gc_ptr->values.line_style = line_style;
    gc_ptr->values_mask |= GCLineStyle;
}

static void
SetCapStyle(GCPtr gc_ptr, int cap_style)
{
    Dprintf(("setting cap style to 0x%x\n", cap_style))

    gc_ptr->values.cap_style = cap_style;
    gc_ptr->values_mask |= GCCapStyle;
}

static void
SetJoinStyle(GCPtr gc_ptr, int join_style)
{
    Dprintf(("setting join style to 0x%x\n", join_style))

    gc_ptr->values.join_style = join_style;
    gc_ptr->values_mask |= GCJoinStyle;
}

static void
SetFillStyle(GCPtr gc_ptr, int fill_style)
{
    Dprintf(("setting fill style to 0x%x\n", fill_style))

    gc_ptr->values.fill_style = fill_style;
    gc_ptr->values_mask |= GCFillStyle;
}

static void
SetFillRule(GCPtr gc_ptr, int fill_rule)
{
    Dprintf(("setting fill rule to 0x%x\n", fill_rule))

    gc_ptr->values.fill_rule = fill_rule;
    gc_ptr->values_mask |= GCFillRule;
}

static void
SetTile(GCPtr gc_ptr, Pixmap tile)
{
    Dprintf(("setting tile to 0x%x\n", tile))

    gc_ptr->values.tile = tile;
    gc_ptr->values_mask |= GCTile;
}

static void
SetStipple(GCPtr gc_ptr, Pixmap stipple)
{
    Dprintf(("setting stipple to 0x%x\n", stipple))
    gc_ptr->values.stipple = stipple;
    gc_ptr->values_mask |= GCStipple;
}

static void
SetTileStipXOrigin(GCPtr gc_ptr, int ts_x_origin)
{
    Dprintf(("setting tile/stipple X origin to 0x%x\n", ts_x_origin))

    gc_ptr->values.ts_x_origin = ts_x_origin;
    gc_ptr->values_mask |= GCTileStipXOrigin;
}

static void
SetTileStipYOrigin(GCPtr gc_ptr, int ts_y_origin)
{
    Dprintf(("setting Tile/Stipple Y origin to 0x%x\n", ts_y_origin))

    gc_ptr->values.ts_y_origin = ts_y_origin;
    gc_ptr->values_mask |= GCTileStipYOrigin;
}

static void
SetFont(GCPtr gc_ptr, int font)
{
    Dprintf(("setting font to 0x%x\n", font))
    gc_ptr->values.font = font;
    gc_ptr->values_mask |= GCFont;
}

static void
SetSubwindowMode(GCPtr gc_ptr, int subwindow_mode)
{
    Dprintf(("setting subwindow mode to 0x%x\n", subwindow_mode))
    gc_ptr->values.subwindow_mode = subwindow_mode;
    gc_ptr->values_mask |= GCSubwindowMode;
}

static void
SetGraphicsExposures(GCPtr gc_ptr, int graphics_exposures)
{ 
    Dprintf(("setting graphical exposures to 0x%x\n",
	   graphics_exposures))

    gc_ptr->values.graphics_exposures = graphics_exposures;
    gc_ptr->values_mask |= GCGraphicsExposures;
}

Global void
SetClipXOrigin(GCPtr gc_ptr, int clip_x_origin)
{
    Dprintf(("setting clip_x_origin to 0x%x\n", clip_x_origin))

    gc_ptr->values.clip_x_origin = clip_x_origin;
    gc_ptr->values_mask |= GCClipXOrigin;
}

Global void
SetClipYOrigin(GCPtr gc_ptr, int clip_y_origin)
{
    Dprintf(("setting clip y origin to 0x%x\n", clip_y_origin))
    gc_ptr->values.clip_y_origin = clip_y_origin;
    gc_ptr->values_mask |= GCClipYOrigin;
}

static void
SetClipMask(GCPtr gc_ptr, Pixmap clip_mask)
{
    Dprintf(("setting clip mask to 0x%x\n", clip_mask))
    gc_ptr->values.clip_mask = clip_mask;
    gc_ptr->values_mask |= GCClipMask;
    if (gc_ptr->setclip_rects) {
	    free(gc_ptr->setclip_rects);
	    gc_ptr->setclip_rects = NULL;
    }
}


static void
SetDashOffset(GCPtr gc_ptr, int dash_offset)
{
    Dprintf(("setting dash offset to 0x%x\n", dash_offset))
    gc_ptr->values.dash_offset = dash_offset;
    gc_ptr->values_mask |= GCDashOffset;
}

static void
SetDashList(GCPtr gc_ptr, char dashes)
{
    Dprintf(("setting dashes to 0x%x\n", dashes))
    gc_ptr->values.dashes = dashes;
    gc_ptr->values_mask |= GCDashList;
}

static void
SetArcMode(GCPtr gc_ptr, int arc_mode)
{
    Dprintf(("setting arc mode to 0x%x\n", arc_mode))
    gc_ptr->values.arc_mode = arc_mode;
    gc_ptr->values_mask |= GCArcMode;
}

void
ParseGCBitmaskValueList(GCPtr gc_ptr,
			unsigned long cmask, 
			unsigned char *ValueList)
{
     ColormapPtr cmap = gc_ptr->cmap;

    Dprintf(("parsing info for GC 0x%x\n", gc_ptr->gc_id))

    if (cmask & GCFunction)
      {
	/* drawing function */
	int function = (int) IParseByte(ValueList);
	SetFunction(gc_ptr, function);
	
	ValueList += 4;
      }
    
    if (cmask & GCPlaneMask)
      {
	/* plane mask */
	unsigned long plane_mask = (unsigned long) IParseLong(ValueList);
	SetPlaneMask(gc_ptr, plane_mask);
	
	ValueList += 4;
      }
    
    if (cmask & GCForeground)
      {
	unsigned long foreground = (unsigned long) IParseLong(ValueList);

	SetForeground(gc_ptr, foreground);
	foreground = MapColorCell(foreground, cmap, Request);
	ISetLong(ValueList, foreground);
	
	ValueList += 4;
      }
    
    if (cmask & GCBackground)
      {
	unsigned long background = (unsigned long) IParseLong(ValueList);

	SetBackground(gc_ptr, background);
	background = MapColorCell(background, cmap, Request);
	ISetLong(ValueList, background);
	
	ValueList += 4;
      }
    
    if (cmask & GCLineWidth)
      {
	int line_width = (int) IParseShort(ValueList);
	SetLineWidth(gc_ptr, line_width);
	
	ValueList += 4;
      }
    
    if (cmask & GCLineStyle)
      {
	int line_style = (int) IParseByte(ValueList);
	SetLineStyle(gc_ptr, line_style);
	
	ValueList += 4;
      }
    
    if (cmask & GCCapStyle)
      {
	int cap_style = (int) IParseByte(ValueList);
	SetCapStyle(gc_ptr, cap_style);
	
	ValueList += 4;
      }
    
    if (cmask & GCJoinStyle)
      {
	int join_style = (int) IParseByte(ValueList);
	SetJoinStyle(gc_ptr, join_style);
	
	ValueList += 4;
      }
    
    if (cmask & GCFillStyle)
      {
	int fill_style = (int) IParseByte(ValueList);
	SetFillStyle(gc_ptr, fill_style);
	
	ValueList += 4;
      }
    
    if (cmask & GCFillRule)
      {
	int fill_rule = (int) IParseByte(ValueList);
	SetFillRule(gc_ptr, fill_rule);
	
	ValueList += 4;
      }
    
    if (cmask & GCTile)
      {
	Pixmap tile = (Pixmap) IParseLong(ValueList);

	SetTile(gc_ptr, tile);
	tile = MapPixmapID(tile, Request);
	ISetLong(ValueList, tile);
	
	ValueList += 4;
      }
    
    if (cmask & GCStipple)
      {
	Pixmap stipple = (Pixmap) IParseLong(ValueList);

	SetStipple(gc_ptr, stipple);
	stipple = MapPixmapID(stipple, Request);
	ISetLong(ValueList, stipple);
	
	ValueList += 4;
      }
    
    if (cmask & GCTileStipXOrigin)
      {
	int ts_x_origin = (int) IParseShort(ValueList);
	SetTileStipXOrigin(gc_ptr, ts_x_origin);
	
	ValueList += 4;
      }
    
    if (cmask & GCTileStipYOrigin)
      {
	int ts_y_origin = (int) IParseShort(ValueList);
	SetTileStipYOrigin(gc_ptr, ts_y_origin);
	
	ValueList += 4;
      }
    
    if (cmask & GCFont)
      {
	int font = (int) IParseLong(ValueList);

	SetFont(gc_ptr, font);
	font = MapFontID(font, Request);
	ISetLong(ValueList, font);
	
	ValueList += 4;
      }
    
    if (cmask & GCSubwindowMode)
      {
	int subwindow_mode = (int) IParseByte(ValueList);
	SetSubwindowMode(gc_ptr, subwindow_mode);
	
	ValueList += 4;
      }
    
    if (cmask & GCGraphicsExposures)
      {
	/* graphic exposures really should be a Bool, but there is */
	/* going to be a type conflict with Bool, since xmond */
	/* defines a Bool as a short, but XLib defines it as an */
	/* int */
	
	int graphics_exposures = (int) IParseByte(ValueList);
	SetGraphicsExposures(gc_ptr, graphics_exposures);
	
	ValueList += 4;
      }
    
    if (cmask & GCClipXOrigin)
      {
	int clip_x_origin = (int) IParseShort(ValueList);
	SetClipXOrigin(gc_ptr, clip_x_origin);
	
	ValueList += 4;
      }
    
    if (cmask & GCClipYOrigin)
      {
	int clip_y_origin = (int) IParseShort(ValueList);
	SetClipYOrigin(gc_ptr, clip_y_origin);
	
	ValueList += 4;
      }
    
    if (cmask & GCClipMask)
      {
	Pixmap clip_mask = (Pixmap) IParseLong(ValueList);

	SetClipMask(gc_ptr, clip_mask);
	if (clip_mask) {
	     clip_mask = MapPixmapID(clip_mask, Request);
	     ISetLong(ValueList, clip_mask);
	}
	
	ValueList += 4;
      }
    
    if (cmask & GCDashOffset)
      {
	int dash_offset = (int) IParseShort(ValueList);
	SetDashOffset(gc_ptr, dash_offset);
	
	ValueList += 4;
      }
    
    if (cmask & GCDashList)
      {
	char dashes = (char) IParseByte(ValueList);
	SetDashList(gc_ptr, dashes);
	
	ValueList += 4;
      }
    
    if (cmask & GCArcMode)
      {
	int arc_mode = (int) IParseByte(ValueList);
	SetArcMode(gc_ptr, arc_mode);
	
	ValueList += 4;
      }
}

void
ParseGCBitmaskcopy(GCPtr gc_ptr_src, GCPtr gc_ptr_dst, unsigned long cmask)
{
  Dprintf(("parsing info for GC copy from #0x%x to #0x%x\n", 
	   gc_ptr_dst->gc_id, gc_ptr_src->gc_id))
  
  /* this code is borrowed from ParseWindowBitmaskValueList() */
  
  if (cmask & GCFunction)
    SetFunction(gc_ptr_dst, gc_ptr_src->values.function);
  
  if (cmask & GCPlaneMask)
    SetPlaneMask(gc_ptr_dst, gc_ptr_src->values.plane_mask);
  
  if (cmask & GCForeground)
    SetForeground(gc_ptr_dst, gc_ptr_src->values.foreground);
  
  if (cmask & GCBackground)
    SetBackground(gc_ptr_dst, gc_ptr_src->values.background);
  
  if (cmask & GCLineWidth)
    SetLineWidth(gc_ptr_dst, gc_ptr_src->values.line_width);
  
  if (cmask & GCLineStyle)
    SetLineStyle(gc_ptr_dst, gc_ptr_src->values.line_style);
  
  if (cmask & GCCapStyle)
    SetCapStyle(gc_ptr_dst, gc_ptr_src->values.cap_style);
  
  if (cmask & GCJoinStyle)
    SetJoinStyle(gc_ptr_dst, gc_ptr_src->values.join_style);
  
  if (cmask & GCFillStyle)
    SetFillStyle(gc_ptr_dst, gc_ptr_src->values.fill_style);
  
  if (cmask & GCFillRule)
    SetFillRule(gc_ptr_dst, gc_ptr_src->values.fill_rule);

  if (cmask & GCTile)
    SetTile(gc_ptr_dst, gc_ptr_src->values.tile);
  
  if (cmask & GCStipple)
    SetStipple(gc_ptr_dst, gc_ptr_src->values.stipple);
  
  if (cmask & GCTileStipXOrigin)
    SetTileStipXOrigin(gc_ptr_dst, gc_ptr_src->values.ts_x_origin);
  
  if (cmask & GCTileStipYOrigin)
    SetTileStipYOrigin(gc_ptr_dst, gc_ptr_src->values.ts_y_origin);
  
  if (cmask & GCFont)
    SetFont(gc_ptr_dst, gc_ptr_src->values.font);
  
  if (cmask & GCSubwindowMode)
    SetSubwindowMode(gc_ptr_dst, gc_ptr_src->values.subwindow_mode);
  
  if (cmask & GCGraphicsExposures)
    SetGraphicsExposures(gc_ptr_dst, gc_ptr_src->values.graphics_exposures);
  
  if (cmask & GCClipXOrigin)
    SetClipXOrigin(gc_ptr_dst, gc_ptr_src->values.clip_x_origin);
  
  if (cmask & GCClipYOrigin)
    SetClipYOrigin(gc_ptr_dst, gc_ptr_src->values.clip_y_origin);
  
  if (cmask & GCClipMask)
    SetClipMask(gc_ptr_dst, gc_ptr_src->values.clip_mask);
  
  if (cmask & GCDashOffset)
    SetDashOffset(gc_ptr_dst, gc_ptr_src->values.dash_offset);
  
  if (cmask & GCDashList)
    SetDashList(gc_ptr_dst, gc_ptr_src->values.dashes);
  
  if (cmask & GCArcMode)
    SetArcMode(gc_ptr_dst, gc_ptr_src->values.arc_mode);

}


/* we are guaranteed not to be called unless gc *needs* to be converted */

Global void
ConvertGCToColormap(GCPtr gc, ColormapPtr cmap)
{
	xChangeGCReq req;
	unsigned char buf[8];
	card32 color;

	if (gc->cmap == cmap || gc->depth == 1)
		return;

	if (cmap && gc->depth != cmap->visual->vis_depth)
		return;

	req.reqType = X_ChangeGC;
	req.length = 3;		/* will be endian-converted later */
	ISetLong((unsigned char *)&req.gc, MapGCID(gc->gc_id, Request));
	req.mask = 0;		/* will be endian-converted later */

	if (gc->values_mask & GCForeground)
		if ((color = MapColorCell(gc->values.foreground, cmap, Request)) !=
		    MapColorCell(gc->values.foreground, gc->cmap, Request))
		{
			ISetLong(&buf[0], color);
			req.length++;
			req.mask |= GCForeground;
		}

	if (gc->values_mask & GCBackground)
		if ((color = MapColorCell(gc->values.background, cmap, Request)) !=
		    MapColorCell(gc->values.background, gc->cmap, Request))
		{
			if (req.length == 3)
				ISetLong(&buf[0], color);
			else
				ISetLong(&buf[4], color);
			req.length++;
			req.mask |= GCBackground;
		}

	gc->cmap = cmap;

	if (req.length == 3)
		return;
     
	ISetShort((char *)&req.length, req.length);
	ISetLong((char *)&req.mask, req.mask);

	InsertRequestsInit();
     
	client->SequenceNumber++;
	SendBuffer(server->fdd->fd, (unsigned char *)&req, 12);
	SendBuffer(server->fdd->fd, &buf[0], (req.length-3)*4);
	XMOVEGetInputFocus(server->fdd->fd, &client->SequenceNumber);
     
	InsertRequestsDone();
}

/* NOTE: cmap == NULL will coredump */
/* NOTE: ETHAN: these aren't safe */

Global card32 *
MakeServerColorCellMap(ColormapPtr cmap)
{
	int     depth  = cmap->visual->vis_depth;
	card32 *map    = malloc((1 << depth) * sizeof(card32));
	card32 *endmap = map + (1 << depth);
	card32 *curmap = map;
	int cnt = 0;


	while (curmap < endmap)
		*(curmap++) = MapColorCell(cnt++, cmap, Reply);

	return map;
}
	  
/* as above, but equivalent of Map(Server2Server), not Map(Reply) */

Global card32 *
MakeServer2SColorCellMap(ColormapPtr cmap, int server_depth)
{
     card32 *map = malloc((1 << server_depth) * sizeof(card32));
     card32 *endmap = map + (1 << server_depth);
     card32 *curmap = map;
     int cnt = 0;


     while (curmap < endmap)
	  *(curmap++) = MapColorCell(cnt++, cmap, Reply);

     return map;
}
	  

Global void
ConvertPixmapToColormap(PixmapPtr pixmap, ColormapPtr cmap)
{
	XImage *image;
	int x, y;
	register ColorCellPtr cells;
	card32 *server_cell_map = NULL;
	GContext new_gc;
	Pixmap   new_pixmap;

	if (MoveInProgress)
		panic("xmove assert: cannot ConvertPixmapToColormap while MoveInProgress\n");

	if (pixmap->cmap == cmap || pixmap->depth->depth == 1)
		return;

	if (cmap && pixmap->depth->depth != cmap->visual->vis_depth) {
		Eprintf(("ETHAN: ConvertPixmap %d bits to %d bits?\n",
			 pixmap->depth->depth, cmap->visual->vis_depth));
		return;
	}
	if (cmap && pixmap->depth->mapped_depth->depth != cmap->visual->vis_mapped->vis_depth) {
		Eprintf(("ETHAN: Pixmap mapped depth %d != new cmap mapped depth %d\n",
			 pixmap->depth->mapped_depth->depth,
			 cmap->visual->vis_mapped->vis_depth));
	}
	if ((!pixmap->cmap || IsVisualEquivalent(pixmap->cmap->visual, Reply)) &&
	    (!cmap || IsVisualEquivalent(cmap->visual, Request)))
	{
		/* all done! hakuna matata! */
		pixmap->cmap = cmap;
		return;
	}

	if (cmap == NULL)
		Eprintf(("ETHAN: converting a pixmap to NULL cmap\n"));

	if (cmap && pixmap->cmap && cmap->visual != pixmap->cmap->visual) {
		Eprintf(("ETHAN: ConvertPixmap has mixed visuals %x and %x\n",
			 cmap->visual->vis_id, pixmap->cmap->visual->vis_id));
	}

	InsertRequestsInit();
     
	image = XMOVEGetImage(server->fdd->fd, &client->SequenceNumber, server,
			      MapPixmapID(pixmap->pixmap_id, Request),
			      0, 0, pixmap->width, pixmap->height,
			      0xFFFFFFFF, ZPixmap);

	if (!image) {
		InsertRequestsDone();
		return;
	}
     
	/*
	 * MapImage8Double does a double mapping in one loop through the image, but
	 * for 16 and 32 bits_per_pixel I didn't write such a function. It probably
	 * would be a good idea.
	 */

	if (pixmap->depth->compatible) {
		if (image->bits_per_pixel == 8) {
			MapImage8Double(image->data, pixmap->width, pixmap->height,
					pixmap->depth->depth, image->bytes_per_line,
					pixmap->cmap, cmap);

		} else if (image->bits_per_pixel == 16) {
			MapImage16(image->data, pixmap->width, pixmap->height,
				   pixmap->depth->depth, image->bytes_per_line,
				   pixmap->cmap, Reply,
				   (server->formats->image_byte_order != XmoveLittleEndian),
				   (client->formats->image_byte_order != XmoveLittleEndian));

			MapImage16(image->data, pixmap->width, pixmap->height,
				   pixmap->depth->depth, image->bytes_per_line,
				   cmap, Request,
				   (client->formats->image_byte_order != XmoveLittleEndian),
				   (server->formats->image_byte_order != XmoveLittleEndian));

		} else if (image->bits_per_pixel == 32) {
			MapImage32(image->data, pixmap->width, pixmap->height,
				   pixmap->depth->depth, image->bytes_per_line,
				   pixmap->cmap, Reply,
				   (server->formats->image_byte_order != XmoveLittleEndian),
				   (client->formats->image_byte_order != XmoveLittleEndian));

			MapImage32(image->data, pixmap->width, pixmap->height,
				   pixmap->depth->depth, image->bytes_per_line,
				   cmap, Request,
				   (client->formats->image_byte_order != XmoveLittleEndian),
				   (server->formats->image_byte_order != XmoveLittleEndian));

		} else
			goto CP2C_DEFAULT;
	} else {
	CP2C_DEFAULT:
		ConvertImage(image, pixmap->width, pixmap->height, pixmap->cmap, cmap);
	}

	new_pixmap = MapPixmapID(pixmap->pixmap_id, Request);
	new_gc     = (server->resource_base | (server->resource_mask >> 1)) - 1;
	XMOVECreateGC(server->fdd->fd, &client->SequenceNumber,
		      new_gc, new_pixmap, 0, NULL);
	XMOVEPutImage(server->fdd->fd, &client->SequenceNumber,
		      server->formats, new_pixmap, new_gc, image, 0, 0, 0, 0,
		      pixmap->width, pixmap->height);
	XMOVEFreeGC  (server->fdd->fd, &client->SequenceNumber, new_gc);
	XMOVEGetInputFocus(server->fdd->fd, &client->SequenceNumber);

	InsertRequestsDone();

	pixmap->cmap = cmap;

	if (server_cell_map)
		free(server_cell_map);

	free(image->data);
	free((char *) image);
}
