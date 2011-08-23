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
#include <X11/Xproto.h>
#include "xmove.h"
#include <unistd.h>

Bool MoveInProgress;
Server *new_server;
unsigned int cur_mask, cur_base, client_mask, client_base;
int cur_fd, new_fd;
unsigned short *cur_seqno, *new_seqno;

static char *newdisp_key;
static int newdisp_keylen;
static unsigned long server_ip_addr;

static char *Move_stage1(char *new_display, char new_screen);
static char *Move_stage2();
static char *Move_stage3();
static char *Move_stage4();
static char *Move_stage5();
static void UnmapClientWindows();
static void RemapWindows();
static void FixClientSeqnos();

extern LinkList meta_client_list;
extern unsigned long HostIPAddr;
extern long WriteDescriptors[mskcnt], ReadDescriptors[mskcnt];
extern Bool littleEndian;
extern Bool do_poll;

/* THE MOVE ROUTINES */

void SetGlobals()
{
     if (client == NULL)
	  return;

     littleEndian = client->fdd->littleEndian;
     
     client_mask = client->resource_mask;
     client_base = client->resource_base;
     cur_seqno = &client->SequenceNumber;
     new_seqno = &client->new_seqno;

     server = client->server;
     cur_mask = server->resource_mask;
     cur_base = server->resource_base;
     if (server->fdd)
	  cur_fd = server->fdd->fd;
     else
	  cur_fd = -1;

     new_server = client->new_server;
     if (new_server)
	  new_fd   = new_server->fdd->fd;
}
     

static void
CloseNewServers()
{
	LinkLeaf *ll;
	Client *cur_client;

	ScanList(&meta_client->client_list, ll, cur_client, Client *) {
		if (client->new_server) {
			Server *cur_server = client->new_server;
	       
			if (cur_server->fdd) {
				close(cur_server->fdd->fd);
				NotUsingFD(cur_server->fdd->fd);
			}

			if (cur_server->server_name) free(cur_server->server_name);
	       
			if (cur_server->formats && cur_server->formats != client->formats) {
				Pointer item;
		    
				if (cur_server->formats->sc_formats)
					free(cur_server->formats->sc_formats);

				if (cur_server->formats->sc_visuals)
					free(cur_server->formats->sc_visuals);
		    
				free(cur_server->formats);
			}
			Tfree(cur_server);
			client->new_server = NULL;
		}
	}
}

/*
  move_all() will move all clients to new_display_name, with the exception
  of the client pointed to by exclude_client
*/

Global void
MoveAll(char *new_display_name, char new_screen, MetaClient *exclude_client,
	int keylen, char *key, char **rettext)
{

     ForAllInList(&meta_client_list)
     {
	  MetaClient *meta_client =
	       (MetaClient *)CurrentContentsOfList(&meta_client_list);
	  
	  if (meta_client != exclude_client)
	       MoveClient(meta_client, new_display_name, new_screen, keylen, key, rettext);
     }
}


/* meta_client must be set to the client to be moved */

#define RestoreOldGlobals()         \
	meta_client  = old_mclient; \
	client       = old_client;  \
	server       = old_server;  \
	littleEndian = old_endianism;

Global void
MoveClient(MetaClient *mclient, char *new_display, char new_screen, int keylen, char *key, char **rettext)
{
     Bool old_endianism = littleEndian;
     MetaClient *old_mclient = meta_client;
     Client *old_client = client;
     Server *old_server = server;

     if (*new_display == '\0') {
	  SuspendClient(mclient, rettext);
	  return;
     }

     meta_client = mclient;
     
     /* The move is on! Let the world know! */
     MoveInProgress = True;

     newdisp_key = key;
     newdisp_keylen = keylen;

     /* Move_stage1 is assumed to not affect the state of the original client
	connections */

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  littleEndian = client->fdd->littleEndian;
	  if ((*rettext = Move_stage1(new_display, new_screen)) != NULL) {
	       CloseNewServers();
	       RestoreOldGlobals();
	       MoveInProgress = False;
	       return;
	  }
     }

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  SetGlobals();
	  if (cur_fd != -1)
	       UnmapClientWindows();
     }

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  SetGlobals();
	  if ((*rettext = Move_stage2()) != NULL) {
	       CloseNewServers();
	       RemapWindows();
	       FixClientSeqnos();
	       RestoreOldGlobals();
	       MoveInProgress = False;
	       return;
	  }
     }

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  SetGlobals();
	  if ((*rettext = Move_stage3()) != NULL) {
	       CloseNewServers();
	       RemapWindows();
	       FixClientSeqnos();
	       RestoreOldGlobals();
	       MoveInProgress = False;
	       return;
	  }
     }

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  SetGlobals();
	  if ((*rettext = Move_stage4()) != NULL) {
	       CloseNewServers();
	       RemapWindows();
	       FixClientSeqnos();
	       RestoreOldGlobals();
	       MoveInProgress = False;
	       return;
	  }
     }

     /* Move_stage5 shouldn't return error, since it won't be handled correctly.
	stage5 changes too much client state at the end. */

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  SetGlobals();
	  if ((*rettext = Move_stage5()) != NULL) {
	       CloseNewServers();
	       RemapWindows();
	       RestoreOldGlobals();
	       MoveInProgress = False;
	       return;
	  } else
	       client->never_moved = False;
     }

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  
	  /* this may not be the best place to put this, but it can't be called until
	     we know the move has completed. Update the client's output-buffer's pointer
	     to the data source, ie the server. */
	  
	  client->fdd->outBuffer.src_fd = client->server->fdd->fd;
	  
	  if (server_ip_addr == HostIPAddr)
	       client->xmoved_to_elsewhere = False;
	  else
	       client->xmoved_to_elsewhere = True;
     }
     
     /* The move is done! Let the world know! */
     RestoreOldGlobals();
     MoveInProgress = False;
}

static char *
Move_stage1(char *new_display, char new_screen_c)
{
	     int count = 1;	/* ETHAN */

     int new_screen = (signed char)new_screen_c;
     unsigned char conn_reply[32], *display_data, *screen;
     char *full_display_name, *new_display_name, *colon;
     int new_display_name_len, reply_len, num_screens;
     
     if (client->xmoved_from_elsewhere) {
	  unsigned char buf[32];
	  int disp_name_len = strlen(new_display) + 1;

	  ISetByte(&buf[0], 253);
	  ISetLong(&buf[4], 1 + ROUNDUP4(disp_name_len)/4 + ROUNDUP4(newdisp_keylen)/4);
	  ISetShort(&buf[8], disp_name_len);
	  ISetShort(&buf[10], newdisp_keylen);

	  SendBuffer(client->fdd->fd, buf, 32);
	  SendBuffer(client->fdd->fd, (unsigned char *)&new_screen_c, 1);
	  SendBuffer(client->fdd->fd, buf, 3);
	  SendBuffer(client->fdd->fd, (unsigned char *)new_display, disp_name_len);
	  SendBuffer(client->fdd->fd, buf, ROUNDUP4(disp_name_len)-disp_name_len);
	  SendBuffer(client->fdd->fd, (unsigned char *)newdisp_key, newdisp_keylen);
	  SendBuffer(client->fdd->fd, buf, ROUNDUP4(newdisp_keylen)-newdisp_keylen);
	  return strdup("Request received. Client is now being moved\n");
     }

     if (client->grabbed_server)
	  return strdup("Cannot move an application while it has grabbed the server exclusively\n");

     if (newdisp_keylen > 0) {
	  ISetShort(client->startup_message + 6, 18);
	  ISetShort(client->startup_message + 8, newdisp_keylen);
     } else {
	  ISetShort(client->startup_message + 6, 0);
	  ISetShort(client->startup_message + 8, 0);
     }

     new_display_name = malloc(strlen(new_display)+1);
     strcpy(new_display_name, new_display);
     new_display_name_len = strlen(new_display_name);
     full_display_name = malloc(new_display_name_len + 3);
     
     /* if new_display_name has a colon in it, assume that we are being
	told precisely what server to move the client to and that it isn't
	an xmove. If there is no colon, first try to find an xmove running
	on the destination machine, then fall back to using the X11 server
	directly. */
     
     if (colon = strchr(new_display_name, ':')) {
	  strcpy(full_display_name, new_display_name);
	  *(colon++) = '\0';
	  new_fd = ConnectToServer(new_display_name, atoi(colon),
				   &server_ip_addr);
	  if (new_fd < 0) {
	       free(full_display_name);
	       free(new_display_name);
	       return strdup("Unable to connect with new server\n");
	  }

	  SendBuffer(new_fd, client->startup_message, 12);
	  if (newdisp_keylen > 0) {
	       SendBuffer(new_fd, (u_char *)"MIT-MAGIC-COOKIE-1 ", 20);
	       SendBuffer(new_fd, (u_char *)newdisp_key, newdisp_keylen);
	  }
     } else {
	  new_fd = ConnectToServer(new_display_name, 1, &server_ip_addr);
	  if (new_fd < 0) {
	       new_fd = ConnectToServer(new_display_name, 0, &server_ip_addr);
	       if (new_fd < 0) {
		    free(full_display_name);
		    free(new_display_name);
		    return strdup("Unable to connect with new server\n");
	       }

	       sprintf(full_display_name, "%s:0", new_display_name);
	       SendBuffer(new_fd, client->startup_message, 12);
	       if (newdisp_keylen > 0) {
		    SendBuffer(new_fd, (u_char *)"MIT-MAGIC-COOKIE-1 ", 20);
		    SendBuffer(new_fd, (u_char *)newdisp_key, newdisp_keylen);
	       }
	  } else {
	       sprintf(full_display_name, "%s:1", new_display_name);
	       ISetByte(client->startup_message + 1,
			client->window_name ?
			strlen(client->window_name)+1 : 0);
	       ISetShort(client->startup_message + 10,
			 IShort(client->startup_message + 2));
	       ISetShort(client->startup_message + 2, 253);
	       
	       SendBuffer(new_fd, client->startup_message, 12);
	       
	       ISetShort(client->startup_message + 2,
			 IShort(client->startup_message + 10));
	       
	       if (newdisp_keylen > 0) {
		    SendBuffer(new_fd, (u_char *)"MIT-MAGIC-COOKIE-1 ", 20);
		    SendBuffer(new_fd, (u_char *)newdisp_key, newdisp_keylen);
	       }
	  
	       if (client->window_name) {
		    SendBuffer(new_fd, (unsigned char *)client->window_name,
			       strlen(client->window_name)+1);
	       }
	  }
     }

     free(new_display_name);
     
     /* receive reply from server */
     
     ReceiveBuffer(new_fd, conn_reply, 8);
     reply_len = IShort(conn_reply+6)*4;
     display_data = malloc(reply_len);
     ReceiveBuffer(new_fd, display_data, reply_len);

     if (*conn_reply == 0) {
	  char *retval = malloc(36 + IByte(conn_reply+1));

	  bcopy("Connection rejected by new server\n", retval, 34);
	  bcopy((char *)display_data, retval+34, IByte(conn_reply+1));
	  retval[34 + IByte(conn_reply+1)] = '\n';
	  retval[35 + IByte(conn_reply+1)] = '\0';

	  free(full_display_name);
	  free(display_data);
	  close(new_fd);
	  return retval;
     }

     /* instantiate this new server */
     
     new_server = Tcalloc(1, Server);
     new_server->fdd = UsingFD(new_fd, DataFromServer, (Pointer) new_server);
     new_server->fdd->fd = new_fd;

     /* According to the X11 proocol specification, communication */
     /* between the client and the server is done according to the */
     /* client's byte ordering, so the server ends up doing all the */
     /* byte swapping.  Therefore, any new server that we connect */
     /* to has to use the same byte ordering as this particular */
     /* client used previously. */
     /* set the little endian flag for this server */
     
     new_server->fdd->littleEndian = client->fdd->littleEndian;
     new_server->client = client;
     client->new_server = new_server;
     new_server->server_name = full_display_name;
     RestartServerConnection(new_server);
     
     num_screens = IByte(display_data + 20);
     screen = display_data + 32 + ROUNDUP4(IShort(display_data + 16)) +
	  (IByte(display_data + 21) * 8);

     /* if new screen is unspecified, or it doesn't exist, use screen 0 */

     if (new_screen == -1 || new_screen >= num_screens) 
	     new_screen = 0;
	  
     while (new_screen--) {
	     int num_depths = IByte(&screen[39]);
	     
	     screen += 40;
	     while (num_depths--) {
		     int num_visuals = IShort(&screen[2]);
		     
		     screen += 8 + num_visuals * 24;
	     }
     }
     
     /* store the resource ID base and mask into the client and server */
     
     new_server->resource_base             = ILong(display_data + 4);
     new_server->resource_mask             = ILong(display_data + 8);
     new_server->min_keycode               = IByte(display_data + 26);
     new_server->max_keycode               = IByte(display_data + 27);
     new_server->formats->max_request_size = IShort(display_data + 18);

     SaveVisuals(new_server->formats, screen);
     SaveFormats(new_server->formats, display_data);
     free(display_data);

     /* set global variable server to client's current server */
     SetGlobals();

     while (server->fdd && server->fdd->outBuffer.num_Saved)
	  SendXmoveBuffer(server->fdd->fd, &server->fdd->outBuffer);

     /* This isn't the prettiest of ways to do it, but it works. If
	there is a reply pending from the server then we cannot move
	the client until it comes. The client will wait forever to get
	that reply. */

     while ((server->fdd && server->fdd->inBuffer.incomplete_data) ||
	 !ListIsEmpty(&server->reply_list))
     {
	  printf("waiting for reply from server to client's pending request\n");
	  sleep(1);
	  processing_server = True;
	  if (!ReadAndProcessData((Pointer)server, server->fdd, client->fdd, True))
	       return strdup("Unexpected error while moving client\n");
     }
#if 0
     if ((server->fdd && server->fdd->inBuffer.incomplete_data) ||
	 !ListIsEmpty(&server->reply_list))
     {
	     fprintf(stderr, "ETHAN!! cancelling move\n");
	  return strdup("Waiting for server. Please try the move again.\n");
     }
#endif

     client->orig_seqno = client->SequenceNumber;
     client->new_seqno = 0; /* start off at 0, will be pre-incremented */

     if (MakeNewServerFormats(client->formats, new_server->formats) == False)
	     return strdup("New server's visual formats are not compatible with your client.\n");

     fprintf(stdout, "XMOVE:  switching client %d to display %s\n", 
	     client->ClientNumber, full_display_name);

     Dprintf(("New display base = 0x%x, mask = 0x%x\n",
	      new_server->resource_base, new_server->resource_mask));
     Dprintf(("Switching from fd#%d to fd#%d\n",cur_fd,
              new_fd));

     return NULL;
}

static char *Move_stage2()
{
     LinkLeaf *ll;
     Client *tmp_client;
     hash_location loc;
     PixmapPtr pixmap;
     FontPtr font;
     AtomPtr atom;
     char *retval;
     unsigned short startseqno, errorseqno;
     int curfont, fontcount;

     /* Remove transient items from the resource mapping list. */

     ForAllInList(&client->resource_maps) {
	  ResourceMappingPtr map;

	  map = (ResourceMappingPtr)CurrentContentsOfList(&client->resource_maps);

	  if (map->transient) {
	       deleteCurrent(&client->resource_maps);
	       free(map);
	  }
     }
     

     /* Look in our fellow clients and gather their new_server resource bases
	and masks. Update our resource_maps with that information */

     ScanList(&meta_client->client_list, ll, tmp_client, Client *) {
	  ResourceMappingPtr map;
	  
	  if (tmp_client == client)
	       continue;	/* no need to update ourselves */

	  if ((map = FindResourceBase(tmp_client->resource_base)))
	       map->new_server_base = tmp_client->new_server->resource_base;
     }


     /* Move all the colormaps to the new server and allocate all of
	their color cells. */
     
     retval = MoveColormaps();
     if (retval)
	  return retval;
     
     for (atom = hashloc_init(&loc, client->atom_table);
	  atom; atom = hashloc_getnext(&loc))
     {
	  Dprintf(("About to Intern Atom %s == (c)%d (s)%d\n",atom->atom_name,atom->client_atom,atom->server_atom));
	  
	  atom->new_server_atom = XMOVEInternAtom(new_fd, new_seqno, atom->atom_name, False);
     }
     
     startseqno = *new_seqno + 1;
     
     for (font = hashloc_init(&loc, client->font_table);
	  font; font = hashloc_getnext(&loc))
     {
	  Font xfont;
	  
	  xfont = MapFontID(font->font_id, Client2NewServer);
	  
	  XMOVELoadFont(new_fd, new_seqno, xfont, font->name);
	  
	  Dprintf(("Font %s loaded with id 0x%x\n", 
		   font->name, xfont));
     }
     
     fontcount = *new_seqno + 1 - startseqno;
     curfont = 0;
     font = hashloc_init(&loc, client->font_table);
     
     while (XMOVEReceiveReplyOrError(new_fd, new_seqno, &errorseqno) == 1) {
	 Font xfont;

	 errorseqno -= startseqno;

	 if (errorseqno > fontcount)
	     continue;
	 
	 if (curfont == 0)
	     fprintf (stderr, "Some fonts used by this client are set to \"fixed\" on the new server\n");
	 
	 while (curfont < errorseqno) {
	     font = hashloc_getnext(&loc);
	     curfont++;
	 }

	 printf("Font \"%s\" unavailable on new server, reloading as \"fixed\"\n", font->name);
	 xfont = MapFontID(font->font_id, Client2NewServer);
	 XMOVELoadFont(new_fd, new_seqno, xfont, "fixed");

	 Dprintf(("Font fixed loaded with id 0x%x\n", xfont));
     }

     for (pixmap = hashloc_init(&loc, client->pixmap_table);
	  pixmap; pixmap = hashloc_getnext(&loc))
     {
	  Pixmap xpixmap;
	  
	  xpixmap = MapPixmapID(pixmap->pixmap_id, Client2NewServer);
	  
	  /* This is a REALLY cheap hack, but according to O'Reilly X 0, it
	     should be all right. The drawable in the CreatePixmap call
	     is only used to determine the screen with which to associate
	     the pixmap. So we use DefaultRootWindow. This allows us to create
	     the pixmaps before the windows and GCs. */
	  
	  XMOVECreatePixmap(new_fd, new_seqno, xpixmap,
			    new_server->formats->sc_root_window,
			    pixmap->width, pixmap->height,
			    pixmap->depth->new_mapped_depth->depth);
	  
	  pixmap->new_pixmap = xpixmap;
	  Dprintf(("New pixmap %x old pixmap %x\n",xpixmap,
		   pixmap->pixmap_id));
     }

     return NULL;
}

static char *Move_stage3()
{
     hash_location loc;
     void *pos;
     WindowPtr window;
     PixmapPtr pixmap;
     GlyphCursorPtr cursor_ptr;
     
     for (cursor_ptr = hashloc_init(&loc, client->glyph_cursor_table);
	  cursor_ptr; cursor_ptr = hashloc_getnext(&loc))
     {
	  Cursor xcursor;
	  Font src_font, mask_font;
	  
	  xcursor = MapCursorID(cursor_ptr->cursor_id, Client2NewServer);
	  
	  src_font = MapFontID(cursor_ptr->source_font, Client2NewServer);
	  if (cursor_ptr->mask_font)
	       mask_font = MapFontID(cursor_ptr->mask_font, Client2NewServer);
	  else
	       mask_font = 0;
	  
	  XMOVECreateGlyphCursor(new_fd, new_seqno, xcursor, src_font,
				 mask_font, cursor_ptr->source_char, 
				 cursor_ptr->mask_char,
				 &cursor_ptr->foreground_color,
				 &cursor_ptr->background_color);
	  
	  Dprintf(("cursor id 0x%x loaded.\n", cursor_ptr->cursor_id));
     }

     /* Create all the windows that this client has already created */
     
     for (window = hash_getfirst(&pos, client->window_table);
	  window; window = hash_getnext(&pos, client->window_table))
     {
	  move_window(window);
     }

     /* now copy any pixmap image from the original server to the new server
	if there is still valid data in the original servers pixmap */
     
     Dprintf(("Entering putimage loop\n"));
     for (pixmap = hashloc_init(&loc, client->pixmap_table);
	  pixmap; pixmap = hashloc_getnext(&loc))
     {
	     PixmapFormatPtr depth, oldmapdepth, newmapdepth;
	     XImage *image = NULL, *new_image;
	     GContext gc;
	  
	     if (pixmap->image)
		     image = pixmap->image;
	  
	     if (image == NULL && cur_fd != -1)
		     image = XMOVEGetImage(cur_fd, cur_seqno, server,
					   MapPixmapID(pixmap->pixmap_id, Request),
					   0, 0, pixmap->width, pixmap->height,
					   0xFFFFFFFF, ZPixmap);
	     if (image == NULL)
		     continue;

	     depth       = pixmap->depth;
	     oldmapdepth = depth->mapped_depth;
	     newmapdepth = depth->new_mapped_depth;
	     gc          = newmapdepth->new_gc;
	     new_image   = image;

	     if (image->depth != oldmapdepth->depth) {
		     Eprintf(("move.c: pixmap %x expected depth %d, got %d\n",
			      pixmap->pixmap_id, oldmapdepth->depth, image->depth));
	     }
	     if (!depth->compatible || !depth->new_compatible)
		     goto DefaultMoveImage;

	     else if (depth->depth == 1)
		     ;		/* no conversion needed */

	     else if (image->bits_per_pixel == 8)
		     MapImage8(image->data, pixmap->width, pixmap->height, depth->depth,
			       image->bytes_per_line, pixmap->cmap, Server2Server);

	     else if (image->bits_per_pixel == 16)
		     MapImage16(image->data, pixmap->width, pixmap->height, depth->depth,
				image->bytes_per_line, pixmap->cmap, Server2Server,
				(server->formats->image_byte_order != XmoveLittleEndian),
				(new_server->formats->image_byte_order != XmoveLittleEndian));

	     else if (image->bits_per_pixel == 32)
		     MapImage32(image->data, pixmap->width, pixmap->height, depth->depth,
				image->bytes_per_line, pixmap->cmap, Server2Server,
				(server->formats->image_byte_order != XmoveLittleEndian),
				(new_server->formats->image_byte_order != XmoveLittleEndian));

	     else
	     {
	     DefaultMoveImage:
		     new_image = XMOVEPreCreateImage(new_server->formats, NULL, ZPixmap,
						     NULL, 0xFFFFFFFF, newmapdepth->depth,
						     NULL, pixmap->width, pixmap->height);
	       
		     new_image->data = malloc(new_image->bytes_per_line * pixmap->height);
	       
		     if (depth->depth == 1)
			     CopyImage(image, new_image, pixmap->width, pixmap->height);
		     else
			     MoveImage(image, new_image, pixmap->width, pixmap->height,
				       pixmap->cmap, Server2Server);
	     }
	  
	     XMOVEPutImage(new_fd, new_seqno, new_server->formats,
			   pixmap->new_pixmap, gc, new_image,
			   0,0,0,0, pixmap->width, pixmap->height);
	  
	     if (new_image != image) {
		     free(new_image->data);
		     free((char *) new_image);
	     }
	     
	     Dprintf(("putimage with gc 0x%x\n",gc));
	     
	     /* if image was pre-saved in pixmap, don't free now in
	      * case move gets cancelled mid-way through.
	      */
	     
	     if (!pixmap->image) {
		     free(image->data);
		     free((char *) image);
	     }
     }
     
     return NULL;
}

static char *Move_stage4()
{
     hash_location loc;
     CursorPtr cursor_ptr;
     Pixmap src_pixmap, mask_pixmap;
     GContext gc;
     GCPtr gc_ptr;
     WindowPtr winptr;

     /* set the stacking order for the windows created in stage 3 */

     for (winptr = hashloc_init(&loc, client->window_table);
	  winptr; winptr = hashloc_getnext(&loc))
     {
	  Window *curwin, *children;
	  u_int nchildren;

	  if (winptr->move_info) {
	       children = winptr->move_info->children;
	       nchildren = winptr->move_info->nchildren;
	  } else if (cur_fd == -1)
	       panic("At QueryTree, cur_fd == -1");
	  else {
	       XMOVEQueryTree(cur_fd, cur_seqno,
			      MapWindowID(winptr->window_id, Request),
			      &children, &nchildren);
	  }
	  
	  if (nchildren >= 2) {
	       curwin = children + 1; /* no need to do lowest child */
	       while (--nchildren) {
		    XMOVERaiseWindow(new_fd, new_seqno,
				     MapWindowID(*curwin, Server2Server));
		    curwin++;
	       }
	  }

	  /* if children were pre-saved in move_info, don't free now in
	   * case move gets cancelled mid-way through.
	   */

	  if (!winptr->move_info && children)
	       free(children);
     }

     /* create all of the gc's */

     for (gc_ptr = hashloc_init(&loc, client->gc_table);
	  gc_ptr; gc_ptr = hashloc_getnext(&loc))
     {
	  GContext xgc;
	  Drawable drawable;
	  XGCValues values;
	  ColormapPtr cmap;
	  
	  xgc = MapGCID(gc_ptr->gc_id, Client2NewServer);
	  
	  cmap = gc_ptr->cmap;
	  
	  /* map all the new resource ID's to the current server */

	  drawable = MapDrawable(gc_ptr->drawable_id, Client2NewServer);
	  
	  memcpy(&values, &gc_ptr->values, sizeof(XGCValues));

	  if (gc_ptr->values_mask & GCForeground)
	       values.foreground = MapColorCell(values.foreground, cmap, Client2NewServer);

	  if (gc_ptr->values_mask & GCBackground)
	       values.background = MapColorCell(values.background, cmap, Client2NewServer);

	  if (gc_ptr->values_mask & GCFont)
	  {
	       values.font = MapFontID(values.font, Client2NewServer);
	       Dprintf(("remapped font for new gc to be 0x%x\n",gc_ptr->values.font));
	       }
	  
	  if (gc_ptr->values_mask & GCTile) {
		  if (FindPixmapFromCurrentClient(values.tile) == NULL)
			  gc_ptr->values_mask ^= GCTile;
		  else
			  values.tile = MapPixmapID(values.tile, Client2NewServer);
	  }
	  if (gc_ptr->values_mask & GCStipple) {
		  if (FindPixmapFromCurrentClient(values.stipple) == NULL)
			  gc_ptr->values_mask ^= GCStipple;
		  else
			  values.stipple = MapPixmapID(values.stipple, Client2NewServer);
	  }
	  /* The clip mask can have a value of 0 which should remain 0 */
	  
	  if ((gc_ptr->values_mask & GCClipMask) && values.clip_mask) {
		  if (FindPixmapFromCurrentClient(values.clip_mask) == NULL)
			  gc_ptr->values_mask ^= GCClipMask;
		  else
			  values.clip_mask = MapPixmapID(values.clip_mask, Client2NewServer);
	  }
	  XMOVECreateGC(new_fd, new_seqno, xgc,
			GetNewServerMovePixmap(new_server->formats, gc_ptr->depth),
			gc_ptr->values_mask, &values);

	  if (gc_ptr->setclip_rects) {
		  if ((gc_ptr->values_mask & (GCClipXOrigin | GCClipYOrigin)) !=
		      (GCClipXOrigin | GCClipYOrigin))
		  {
			  Eprintf(("Moving gc %x with ClipRects, but no origins?\n", xgc));
		  }
		  XMOVESetClipRectangles(new_fd, new_seqno, xgc,
			gc_ptr->values.clip_x_origin, gc_ptr->values.clip_y_origin,
			gc_ptr->setclip_rects, gc_ptr->setclip_n, gc_ptr->setclip_ordering);
	  }
	  
	  Dprintf(("Created new GC with gc_id 0x%x  old gc_id 0x%x\n",
		   xgc, gc_ptr->gc_id));
     }

     
     src_pixmap = (new_server->resource_base | (new_server->resource_mask >> 1)) - 1;
     mask_pixmap = (new_server->resource_base | (new_server->resource_mask >> 1)) - 2;
     gc = GetNewServerMoveGC(new_server->formats, 1);
     
     for (cursor_ptr = hashloc_init(&loc, client->cursor_table);
	  cursor_ptr; cursor_ptr = hashloc_getnext(&loc))
     {
	  Cursor xcursor;
	  
	  if (!cursor_ptr->source_image)
	       continue;

	  XMOVECreatePixmap(new_fd, new_seqno, src_pixmap, new_server->formats->sc_root_window,
			    cursor_ptr->source_image->width,
			    cursor_ptr->source_image->height, 1);
	  XMOVEPutImage(new_fd, new_seqno, new_server->formats,
			src_pixmap, gc, cursor_ptr->source_image,
			0,0,0,0, cursor_ptr->source_image->width,
			cursor_ptr->source_image->height);

	  if (cursor_ptr->mask_image) {
	       XMOVECreatePixmap(new_fd, new_seqno, mask_pixmap, new_server->formats->sc_root_window,
				 cursor_ptr->mask_image->width,
				 cursor_ptr->mask_image->height, 1);
	       XMOVEPutImage(new_fd, new_seqno, new_server->formats,
			     mask_pixmap, gc, cursor_ptr->mask_image,
			     0,0,0,0, cursor_ptr->source_image->width,
			     cursor_ptr->source_image->height);
	  }
	  
	  xcursor = MapCursorID(cursor_ptr->cursor_id, Client2NewServer);
	  
	  XMOVECreatePixmapCursor(new_fd, new_seqno, xcursor, src_pixmap,
				  cursor_ptr->mask_image ? mask_pixmap : 0,
				  &cursor_ptr->foreground_color,
				  &cursor_ptr->background_color,
				  cursor_ptr->x, cursor_ptr->y);

	  XMOVEFreePixmap(new_fd, new_seqno, src_pixmap);
	  if (cursor_ptr->mask_image)
	       XMOVEFreePixmap(new_fd, new_seqno, mask_pixmap);
	  
	  Dprintf(("cursor id 0x%x loaded.\n", xcursor));
     } 
     
     return NULL;
}

static char *Move_stage5()
{
     xChangeWindowAttributesReq ChangeAttrReq;
     WindowPtr window;
     PixmapPtr pixmap;
     SelectionPtr selection_ptr;
     AtomPtr atom;
     hash_location loc;
     u_char buf[32];
     VisualPtr curvis;
     PixmapFormatPtr curformat;
     
     ForAllInList(&client->grab_list)
     {
	  GrabPtr grab_ptr;
	  
	  grab_ptr = (GrabPtr)
	       CurrentContentsOfList(&client->grab_list);
	  
	  if (grab_ptr->type == 28) /* GrabButton */ {
	       Dprintf(("Grabbing Button %d on new display",
			grab_ptr->button));
	       
	       XMOVEGrabButton(new_fd, new_seqno, grab_ptr->button,
			       grab_ptr->modifiers,
			       MapWindowID(grab_ptr->grab_window, Client2NewServer),
			       grab_ptr->owner_events, grab_ptr->event_mask,
			       grab_ptr->pointer_mode, grab_ptr->keyboard_mode,
			       grab_ptr->confine_to ?
			       MapWindowID(grab_ptr->confine_to, Client2NewServer) : 0,
			       (grab_ptr->cursor == None) ? None :
			       MapCursorID(grab_ptr->cursor, Client2NewServer));
	  } else { /* GrabKey */
	       
	       Dprintf(("Grabbing Key %d on new display",grab_ptr->key));
	       /* check this -- map key codes? */
		    
	       XMOVEGrabKey(new_fd, new_seqno, grab_ptr->key,
			    grab_ptr->modifiers,
			    MapWindowID(grab_ptr->grab_window, Client2NewServer),
			    grab_ptr->owner_events, grab_ptr->pointer_mode,
			    grab_ptr->keyboard_mode);
	  }
     }
     
     
     /* move all of the client's selections to the new server */
     
     move_selections();
     
     /* ChangeWindowAttributes for cursor */
     
     ChangeAttrReq.reqType = X_ChangeWindowAttributes;
     ISetShort((unsigned char *)&ChangeAttrReq.length, 4);

     for (window = hashloc_init(&loc, client->window_table);
	  window; window = hashloc_getnext(&loc))
     {
	  XID xwin = MapWindowID(window->window_id, Client2NewServer);

	  if (window->attributes_mask & CWCursor) {
	       Cursor new_cursor =
		    MapCursorID(window->attributes.cursor, Client2NewServer);
	       
	       ISetLong((unsigned char *)&ChangeAttrReq.window, xwin);
	       ISetLong((unsigned char *)&ChangeAttrReq.valueMask, CWCursor);
	       SendBuffer(new_fd, (unsigned char *)&ChangeAttrReq, 12);
	       SendBuffer(new_fd, (unsigned char *)&new_cursor, 4);
	       ++(*new_seqno);
	  }

	  if (window->mapped > 0)
	       XMOVEMapWindow(new_fd, new_seqno, xwin);

	  if (window->move_info) {
	       xGetPropertyReply *curGetPRep = window->move_info->XGetPRep;
	       
	       while (curGetPRep < (window->move_info->XGetPRep +
				    window->move_info->nGetPRep))
	       {
		    /* yes, this is pretty bad, but it *is* 64-bit
		     * compliant. It is a last minute hack to prevent
		     * it from failing with 64-bit pointers. pad2 is
		     * followed by pad3, both 32-bits, and pad2 is 64-bit
		     * aligned. Hence, the *(char **)&.
		     */
		    
		    free(*((char **)&curGetPRep->pad2));
		    curGetPRep++;
	       }
		    
	       free((char *)window->move_info->XGetPRep);
	       free((char *)window->move_info->children);
	       free((char *)window->move_info);
	       window->move_info = NULL;
	  }
     }

     
     /* free pixmap->image, if present */

     for (pixmap = hashloc_init(&loc, client->pixmap_table);
	  pixmap; pixmap = hashloc_getnext(&loc))
     {
	  if (pixmap->image) {
	       free(pixmap->image->data);
	       free((char *)pixmap->image);
	       pixmap->image = NULL;
	  }
     }

     ForAllInList(&client->selection_list)
     {
	  selection_ptr = (SelectionPtr)
	       CurrentContentsOfList(&client->selection_list);
	  
	  selection_ptr->owner = 0;
     }
     
     /* move new server atom mappings into current server section */
     

     for (atom = hashloc_init(&loc, client->atom_table);
	  atom; atom = hashloc_getnext(&loc))
     {
	  atom->server_atom = atom->new_server_atom;
     }
	  
     /* move new colorcell mappings into current server section */

     ForAllInList(&client->colormap_list)
     {
	     ColormapPtr cmap;
	     ColorCellPtr cell;
	     VisualPtr vis;
	     
	     cmap = (ColormapPtr)
		     CurrentContentsOfList(&client->colormap_list);
	     vis = cmap->visual;
	     
	     cell = cmap->cell_array + vis->vis_index[vis->vis_indices];
	     while (--cell >= cmap->cell_array) {
		     if (cell->usage_count)
			     cell->server_pixel = cell->new_server_pixel;
	     }
     }

     /* move new resource base mappings into current server section */
     
     ForAllInList(&client->resource_maps)
     {
	  ResourceMappingPtr map;

	  map = (ResourceMappingPtr)CurrentContentsOfList(&client->resource_maps);
	  if (map->new_server_base)
	       map->server_base = map->new_server_base;
     }

     /* move new visual and pixmap format mappings into current server section */
     /* free pixmaps and GCs created for the move */
     
     FinishNewServerFormats(client->formats, new_server->formats);

     if (client->closedownmode)
	     XMOVESetCloseDownMode(new_fd, new_seqno, client->closedownmode);

     /* at this point we clear out any incoming events from the new
      *	server and enqueue them to be processed. We need to do this
      * since the sequence number must be forced into being LastMoveSeqNo
      * Any errors or replies (quite unexpected!) are dropped.
      */

     buf[0] = (u_char)43;	/* GetInputFocus */
     ISetShort(&buf[2], 1);
     SendBuffer(new_fd, &buf[0], 4);
     client->new_seqno++;
     
     /* We have to update SequenceMapping, since the new server will be at a
	different sequence number. If the original server was at seqno 100, and
	the new one is at seqno 50, we will need to add (100-50)==50 to each new
	sequence number we see. */

     client->SequenceMapping += client->orig_seqno - client->new_seqno;
     client->SequenceMapping = (u_short)client->SequenceMapping;
     client->LastMoveSeqNo = client->new_seqno + client->SequenceMapping;

     /* back to retrieving events from the server */

     while (1) {
	  ReceiveBuffer(new_fd, &buf[0], 32);
	  if (buf[0] == 1 && IShort(&buf[2]) == client->new_seqno)
	       break;

	  if (buf[0] > 1) {
	       if (buf[0] != 11)
		    ISetShort(&buf[2], client->LastMoveSeqNo);
	       Eprintf(("ETHAN: Move_stage5 saving 32 bytes, code %d\n", buf[0]));
	       SaveBytes(&new_server->fdd->inBuffer, &buf[0], 32);
	  } else if (buf[0] == 1) {
	       int remaining = ILong(&buf[4]) << 2;

	       while (remaining > 32) {
		    ReceiveBuffer(new_fd, &buf[0], 32);
		    remaining -= 32;
	       }

	       ReceiveBuffer(new_fd, &buf[0], remaining);
	  }
     }

     /* set the client sequence number to the current sequence number */
     
     client->min_keycode = new_server->min_keycode;
     client->max_keycode = new_server->max_keycode;
     
     client->server = new_server;
     client->SequenceNumber = client->new_seqno;
     client->new_server = NULL;

     /* spoof the old client into believing that it just got a */
     /* RefreshMapping event by writing in the appropriate 32 byte */
     /* block into its output buffer */
     
     /* poke in the sequence number into bytes 2,3 */
     ISetShort(&MappingNotifyEventBuf[2], (unsigned short)
	       (client->SequenceNumber + client->SequenceMapping));
     
     /* check  this */
     /* XXX - eventually, these values should be whatever the new */
     /* server range is, but this can't be done until the */
     /* supporting cast of routines in print11.c is set up, so put */
     /* in dummy values right now */
     
     /* poke in the min, count values */
     ISetByte(&MappingNotifyEventBuf[5], (unsigned char) 0x8);
     ISetByte(&MappingNotifyEventBuf[6], (unsigned char) 0xF8);

     /* send it off to the client */
     SaveBytes(&(client->fdd->outBuffer), 
	       (unsigned char *)MappingNotifyEventBuf, 
	       MappingNotifyEventBufLength);
     BITSET(WriteDescriptors, client->fdd->fd);
     
     /* We've saved data on the server's input queue. Make sure it's processed */
     do_poll = True;
     

     /*
      * we need to clean up differently depending on whether or not the
      * client we are moving was in suspended animation. If it was, the
      * server is already freed and closed, but the client needs to be
      * added back onto the list of sources from which to read data. If
      * the client isn't suspended, we need to free and close the old
      * server.
      */

     FreeServerLists(server);
     
     if (client->suspended) {
	  UsingFD(client->fdd->fd, DataFromClient, (Pointer)client);
	  client->suspended = False;
     } else {
	  NotUsingFD(cur_fd);
	  close(cur_fd);
     }

     return NULL;
}

/*
  FixClientSeqnos scans through all clients and fixes the SequenceMapping. This
  is called when the move is cancelled mid-way through. Since some requests have
  probably been sent to the original server in the interim, we need to update
  sequencemapping.
  */

static void
FixClientSeqnos()
{
     Client *init_client = client;
     LinkLeaf *ll;

     ScanList(&meta_client->client_list, ll, client, Client *) {
	  client->SequenceMapping += client->orig_seqno - client->SequenceNumber;
	  client->SequenceMapping = (u_short)client->SequenceMapping;
     }

     client = init_client;
}
     

/* note that this routine scans through all clients, not just the current one. */

static void
RemapWindows()
{
     void *pos;
     Client *init_client = client;
     LinkLeaf *ll;
     
     /* map all of the mapped windows in the correct stacking order */
     /* this is called when a move has failed and we need to restore the
	windows onto the original screen. window->mapped has already been
	set with the correct info from the beginning of the move. */
     
     ScanList(&meta_client->client_list, ll, client, Client *) {
	  WindowPtr window;
	  
	  SetGlobals();
	  
	  for (window = hash_getfirst(&pos, client->window_table);
	       window; window = hash_getnext(&pos, client->window_table))
	  {
	       if (window->mapped > 0)
		    XMOVEMapWindow(cur_fd, cur_seqno, MapWindowID(window->window_id, Request));
	  }
     }

     client = init_client;
     SetGlobals();
}


/* take windows off the screen so as not to "annoy" the user */
static void
UnmapClientWindows()
{
     hash_location loc;
     WindowPtr window;

     for (window = hashloc_init(&loc, client->window_table);
	  window; window = hashloc_getnext(&loc))
     {
	  if ((window->parent_id & ~client->resource_mask) == 0) {
	       xResourceReq req;
	       xGetWindowAttributesReply rep;
	       Window new_win = MapWindowID(window->window_id, Request);

	       req.reqType = X_GetWindowAttributes;
	       ISetShort((unsigned char *)&req.length, 2);
	       ISetLong((unsigned char *)&req.id, new_win);

	       SendBuffer(cur_fd,
			  (unsigned char *) &req,
			  sizeof(xResourceReq));

	       ReceiveReply(cur_fd, (unsigned char *) &rep,
			    sizeof(xGetWindowAttributesReply), ++(*cur_seqno));

	       if (rep.mapState) {
		    window->mapped = 1;
		    XMOVEUnmapWindow(cur_fd, cur_seqno, new_win);
	       } else if (window->mapped > 0)
		    window->mapped = 0;
	  }
     }
}	       

Global void
SuspendClient(MetaClient *mclient, char **rettext)
{
     Bool old_endianism = littleEndian;
     MetaClient *old_mclient = meta_client;
     Client *old_client = client;
     Server *old_server = server;

     meta_client = mclient;

     MoveInProgress = True;
     
     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  if (client->server->fdd == NULL)
	      continue;

	  SetGlobals();

	  if (client->xmoved_from_elsewhere) {
	       unsigned char buf[32];
	       char new_screen = (char)-1;

	       ISetByte(&buf[0], 253);
	       ISetLong(&buf[4], 2);
	       ISetShort(&buf[8], 4);
	       ISetShort(&buf[10], 0);

	       SendBuffer(client->fdd->fd, buf, 32);
	       SendBuffer(client->fdd->fd, (unsigned char *)&new_screen, 1);
	       SendBuffer(client->fdd->fd, buf, 3);
	       SendBuffer(client->fdd->fd, (unsigned char *)"\0   ", 4);
	       *rettext = strdup("Request received. Client is now being placed in suspended animation\n");
	       
	       MoveInProgress = False;
	       RestoreOldGlobals();
	       return;
	  }

	  while (server->fdd->outBuffer.num_Saved)
	       SendXmoveBuffer(server->fdd->fd, &server->fdd->outBuffer);
	  
	  if ((server->fdd && server->fdd->inBuffer.incomplete_data) ||
	      !ListIsEmpty(&server->reply_list))
	  {
		  printf("waiting for reply from server to client's pending request\n");
		  sleep(1);
		  processing_server = True;
		  if (!ReadAndProcessData((Pointer)server, server->fdd, client->fdd, True)) {
			  *rettext = strdup("Unexpected error while moving client\n");
			  MoveInProgress = False;
			  RestoreOldGlobals();
			  return;
		  }
	  }
	  client->orig_seqno = client->SequenceNumber;
     }	  

     ForAllInList(&meta_client->client_list) {
	  PixmapPtr pixmap;
	  SelectionPtr selection_ptr;
	  hash_location loc;

	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  if (client->server->fdd == NULL)
	      continue;

	  SetGlobals();
	  
	  client->suspended = True;
	  client->xmoved_to_elsewhere = False;
	  NotUsingFD(client->fdd->fd);
	  
	  UnmapClientWindows();
	  StoreWindowStates();

	  for (pixmap = hashloc_init(&loc, client->pixmap_table);
	       pixmap; pixmap = hashloc_getnext(&loc))
	  {
	       pixmap->image = XMOVEGetImage(cur_fd, cur_seqno, server,
				     MapPixmapID(pixmap->pixmap_id, Request),
				     0, 0, pixmap->width, pixmap->height,
				     0xFFFFFFFF, ZPixmap);
	  }

	  ForAllInList(&client->selection_list)
	  {
	       selection_ptr = (SelectionPtr)
		    CurrentContentsOfList(&client->selection_list);

	       selection_ptr->owner =
		    XMOVEGetSelectionOwner(cur_fd, cur_seqno,
					   MapAtom(selection_ptr->selection, Request));
	  }
     }

     ForAllInList(&meta_client->client_list) {
	  client = (Client *)CurrentContentsOfList(&meta_client->client_list);
	  server = client->server;
	  if (server->fdd == NULL)
	    continue;

	  close(server->fdd->fd);
	  if (server->fdd->outBuffer.BlockSize > 0)
	       Tfree(server->fdd->outBuffer.data - server->fdd->outBuffer.data_offset);
	  if (server->fdd->inBuffer.BlockSize > 0)
	       Tfree(server->fdd->inBuffer.data - server->fdd->inBuffer.data_offset);
	  NotUsingFD(server->fdd->fd);
	  server->fdd = NULL;

	  /*
	   * Reset the SequenceNumber to the last request sent by the client.
	   * This way, when the client is unsuspended, Move_stage1() will know
	   * the correct seqno for the client, and thus set the new SequenceMapping
	   * correctly.
	   */
	  
	  client->SequenceNumber = client->orig_seqno;
     }
	  
     *rettext = NULL;
     MoveInProgress = False;
     RestoreOldGlobals();
}

