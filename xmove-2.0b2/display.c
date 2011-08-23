/*                            xmove
 *                            -----
 *             A Pseudoserver For Client Mobility
 *
 *   Copyright (c) 1994         Ethan Solomita
 *
 */

#include "xmove.h"

void
DumpVisual(VisualPtr vis)
{
	int i;

	fprintf(stderr, "VIS %8x(%c%8x)%8x%8x\n", vis->vis_id,
		vis->vis_equivalent ? '=' : ' ',
		vis->vis_mapped ? vis->vis_mapped->vis_id : 0,
		vis->vis_class, vis->vis_depth);
	i = -1;
	while (++i < vis->vis_indices)
		fprintf(stderr, "    %8x%8x%8x\n", vis->vis_index[i],
			vis->vis_shift[i], vis->vis_mask[i]);
	fprintf(stderr, "    %8x\n\n", vis->vis_index[i]);
}


Global int
SaveVisuals(ImageFormatPtr format, unsigned char *buf)
{
	xWindowRoot	*buf_screen = (void *)buf;
	xDepth		*buf_depth;
	xVisualType	*buf_visual;

	VisualPtr	cur_visual;
	ColormapPtr	colormap;
	int		ndepths, nvisuals = 0;
	VisualID	root_visual = ILong(&buf_screen->rootVisualID);
	Colormap	default_cmap = ILong(&buf_screen->defaultColormap);

	/* First, count total number of visuals */
	
	ndepths = IByte(&buf_screen->nDepths);
	buf_depth = (void *)(buf_screen + 1);

	while (ndepths--) {
		nvisuals   += IShort(&buf_depth->nVisuals);
		
		buf_visual  = (void *)(buf_depth + 1);
		buf_visual += IShort(&buf_depth->nVisuals);
		buf_depth   = (void *)buf_visual;
	}

	format->sc_root_window  = ILong(&buf_screen->windowId);
	format->sc_default_cmap = default_cmap;
	format->sc_visuals_count = nvisuals;
	format->sc_visuals = Tcalloc(nvisuals, VisualRec);

	if (format->sc_visuals == NULL)
		panic("xmove: Out of memory in SaveScreen()\n");

	/* Now, process each visual */

	buf_depth = (void *)(buf_screen + 1);
	cur_visual = format->sc_visuals;

	for (ndepths = IByte(&buf_screen->nDepths); ndepths; ndepths--) {
		buf_visual = (void *)(buf_depth + 1);

		for (nvisuals = IShort(&buf_depth->nVisuals); nvisuals; nvisuals--) {
			cur_visual->vis_class      = IByte(&buf_visual->class);
			cur_visual->vis_id         = ILong(&buf_visual->visualID);
			cur_visual->vis_depth      = IByte(&buf_depth->depth);
			cur_visual->vis_red        = ILong(&buf_visual->redMask);
			cur_visual->vis_green      = ILong(&buf_visual->greenMask);
			cur_visual->vis_blue       = ILong(&buf_visual->blueMask);
			cur_visual->vis_mapped     = cur_visual;
			cur_visual->vis_equivalent = IsVisualLinear(cur_visual);

			debug(2, (stderr, "SaveVisuals: saving visual %x\n",
				  cur_visual->vis_id));

			if (IsVisualSplit(cur_visual)) {
				cur_visual->vis_indices  = 3;
			
				cur_visual->vis_mask[0]  = cur_visual->vis_red;
				cur_visual->vis_shift[0] = 0;
				while (cur_visual->vis_mask[0] &&
				       (cur_visual->vis_mask[0] & 1) == 0)
				{
					cur_visual->vis_mask[0] >>= 1;
					cur_visual->vis_shift[0]++;
				}
				cur_visual->vis_index[0] = 0;
			
				cur_visual->vis_mask[1]  = cur_visual->vis_green;
				cur_visual->vis_shift[1] = 0;
				while (cur_visual->vis_mask[1] &&
				       (cur_visual->vis_mask[1] & 1) == 0)
				{
					cur_visual->vis_mask[1] >>= 1;
					cur_visual->vis_shift[1]++;
				}
				cur_visual->vis_index[1] = cur_visual->vis_index[0];
				cur_visual->vis_index[1] += cur_visual->vis_mask[0] + 1;
			
				cur_visual->vis_mask[2] = cur_visual->vis_blue;
				cur_visual->vis_shift[2] = 0;
				while (cur_visual->vis_mask[2] &&
				       (cur_visual->vis_mask[2] & 1) == 0)
				{
					cur_visual->vis_mask[2] >>= 1;
					cur_visual->vis_shift[2]++;
				}
				cur_visual->vis_index[2] = cur_visual->vis_index[1];
				cur_visual->vis_index[2] += cur_visual->vis_mask[1] + 1;
			
				cur_visual->vis_index[3] = cur_visual->vis_index[2];
				cur_visual->vis_index[3] += cur_visual->vis_mask[2] + 1;
			} else {
				cur_visual->vis_indices  = 1;
				cur_visual->vis_index[0] = 0;
				cur_visual->vis_index[1] = 1 << cur_visual->vis_depth;
				cur_visual->vis_mask[0]  = cur_visual->vis_index[1] - 1;
				cur_visual->vis_shift[0] = 0;
			}
			if (debuglevel > 1)
				DumpVisual(cur_visual);
			
			if (cur_visual->vis_id == root_visual)
				format->sc_default_vis = cur_visual;
			
			cur_visual++;
			buf_visual++;
		}

		buf_depth = (void *)buf_visual;
	}

	if (cur_visual != format->sc_visuals + format->sc_visuals_count)
		panic("xmove assert: SaveScreen() got wrong visuals count\n");

	if (format->sc_default_vis == NULL)
		panic("xmove assert: SaveVisuals() couldn't find the default visual\n");

	/* add the default colormap to the client's list of colormaps, and allocate
	   color cell entries for the while and black defaults. We assume that
	   white is pure white and black is pure black, as will the client. If the
	   client finds out that this isn't true, so will we */
    
	if (ListIsEmpty(&client->colormap_list)) {
		ColorIndexRec index;
		
		colormap = (ColormapPtr)Tcalloc(1, ColormapRec);
		colormap->colormap_id  = default_cmap;
		colormap->visual       = format->sc_default_vis;
		colormap->visual->vis_inuse = 1;
		CreateNewCellArray(colormap);
		
#define DoRGB (DoRed | DoGreen | DoBlue)

		if (AllocColorCell(ILong(&buf_screen->whitePixel), colormap, False, &index)) {
			SetColorCell(&index, colormap, True, 0xFFFF, 0xFFFF, 0xFFFF, DoRGB);
			ISetLong(&buf_screen->whitePixel,
				 MapColorIndex(&index, colormap, Reply));
		}		
		if (AllocColorCell(ILong(&buf_screen->blackPixel), colormap, False, &index)) {
			SetColorCell(&index, colormap, True, 0, 0, 0, DoRGB);
			ISetLong(&buf_screen->blackPixel,
				 MapColorIndex(&index, colormap, Reply));
		}
#undef DoRGB
		AddColormapToCurrentClient(colormap);
	}

	return ((unsigned char *)buf_depth) - buf;
}
		

Global void
SaveFormats(ImageFormatPtr format, unsigned char *buf)
{
	xPixmapFormat *xformat;
	int nformats, cur_format = 0;

	format->image_byte_order        = IByte(buf + 22);
	format->image_bitmap_bit_order  = IByte(buf + 23);
	format->image_bitmap_unit       = IByte(buf + 24);
	format->image_bitmap_pad        = IByte(buf + 25);
	format->image_bitmap_compatible = True;
	
	nformats = IByte(buf + 21);
	xformat = (void *)(buf + 32 + ROUNDUP4(IShort(buf + 16)));

	format->sc_formats_count = nformats;
	format->sc_formats = Tcalloc(nformats, PixmapFormatRec);

	if (format->sc_formats == NULL)
		panic ("xmove: Out of memory in SaveScreen()\n");

	while (cur_format < nformats) {
		PixmapFormatPtr pixformat;

		pixformat = format->sc_formats + cur_format;
		pixformat->depth          = IByte(&xformat->depth);
		pixformat->bits_per_pixel = IByte(&xformat->bitsPerPixel);
		pixformat->scanline_pad   = IByte(&xformat->scanLinePad);
		pixformat->compatible     = True;
		pixformat->mapped_depth   = pixformat;

		Dprintf(("XMOVE: depth = %d, bits_per_pixel = %d, scanline_pad = %d\n",
			 pixformat->depth, pixformat->bits_per_pixel,
			 pixformat->scanline_pad));

		xformat++;
		cur_format++;
	}
}

Global VisualPtr
FindVisualFromFormats(ImageFormatPtr format, VisualID vid)
{
	VisualPtr visual;
     
	for (visual = format->sc_visuals;
	     visual < format->sc_visuals + format->sc_visuals_count;
	     visual++)
	{
		if (visual->vis_id == vid)
			return visual;
	}
	return NULL;
}

Global Bool
IsVisualSplitColrmap(ImageFormatPtr format, VisualID vid)
{
	VisualPtr visualptr = FindVisualFromFormats(format, vid);

	if (visualptr &&
	    (visualptr->vis_class == TrueColor || visualptr->vis_class == DirectColor))
		return True;
	else
		return False;

}

Global int
XMOVEGetBitsPerPixel(ImageFormatPtr image_format, int depth)
{
	register PixmapFormatPtr fmt;
     
	if (fmt = GetPixmapFormat(image_format, depth))
		return(fmt->bits_per_pixel);
	else if (depth <= 4)
		return 4;
	else if (depth <= 8)
		return 8;
	else if (depth <= 16)
		return 16;
	else
		return 32;
}

Global int
XMOVEGetScanlinePad(ImageFormatPtr image_format, int depth)
{
	register PixmapFormatPtr fmt;

	if (fmt = GetPixmapFormat(image_format, depth))
		return fmt->scanline_pad;
	else
		return (image_format->image_bitmap_pad);
}

Global PixmapFormatPtr
GetPixmapFormat(ImageFormatPtr image_format, int depth)
{
	int curfmt = 0;

	while (curfmt < image_format->sc_formats_count) {
		if (image_format->sc_formats[curfmt].depth == depth)
			return (&image_format->sc_formats[curfmt]);

		curfmt++;
	}
	return NULL;
}


/*
 * The following routines are called while MoveInProgress only.
 * They create the mappings between the new server's formats
 * and the client's formats. They also create a GC and Pixmap
 * for each possible pixmap format to be used during the move
 * process as references.
 */

Global Pixmap
GetNewServerMovePixmap(ImageFormatPtr image_format, int depth)
{
	PixmapFormatPtr format;

	if ((format = GetPixmapFormat(image_format, depth)) == NULL)
		return 0;

	return format->new_pixmap;
}

Global GContext
GetNewServerMoveGC(ImageFormatPtr image_format, int depth)
{
	PixmapFormatPtr format;

	if ((format = GetPixmapFormat(image_format, depth)) == NULL)
		return 0;

	return format->new_gc;
}

Global void
FinishNewServerFormats(ImageFormatPtr cformat, ImageFormatPtr sformat)
{
	PixmapFormatPtr curfmt;
	VisualPtr	curvis;

	for (curfmt = sformat->sc_formats;
	     curfmt < sformat->sc_formats + sformat->sc_formats_count;
	     curfmt++)
	{
		curfmt->mapped_depth = curfmt->new_mapped_depth;
		curfmt->compatible   = curfmt->new_compatible;
		if (curfmt->new_pixmap) {
			XMOVEFreePixmap(new_fd, new_seqno, curfmt->new_pixmap);
			curfmt->new_pixmap = 0;
		}
		if (curfmt->new_gc) {
			XMOVEFreeGC(new_fd, new_seqno, curfmt->new_gc);
			curfmt->new_gc = 0;
		}
	}

	for (curvis = cformat->sc_visuals;
	     curvis < cformat->sc_visuals + cformat->sc_visuals_count;
	     curvis++)
	{
		curvis->vis_mapped     = curvis->vis_new_mapped;
		curvis->vis_equivalent = curvis->vis_new_equivalent;
	}
}

static PixmapFormatPtr
FindCompatiblePixFormat(PixmapFormatPtr pixformat, ImageFormatPtr formats,
			ImageFormatPtr srcformats)
{
	PixmapFormatPtr bestformat, curformat;

	/* If this is the default depth, must map to new default depth */

	if (pixformat->depth == srcformats->sc_default_vis->vis_depth) {
		bestformat = GetPixmapFormat(formats, formats->sc_default_vis->vis_depth);
		printf("ETHAN: matching depth %d to depth %d\n",
		       pixformat->depth, bestformat->depth);
		if (bestformat)
			return bestformat;
		Dprintf(("FindCompatiblePixFormat couldn't find new server's default depth??\n"));
	}
	
	bestformat = formats->sc_formats;
	if (bestformat->depth == pixformat->depth)
		return bestformat;
	
	for (curformat = formats->sc_formats + 1;
	     curformat < formats->sc_formats + formats->sc_formats_count;
	     curformat++)
	{
		if (curformat->depth == pixformat->depth)
			return curformat;

		if ((bestformat->depth < pixformat->depth &&
		     curformat->depth > bestformat->depth) ||
		    (bestformat->depth > pixformat->depth &&
		     curformat->depth < bestformat->depth &&
		     curformat->depth >= pixformat->depth))
		{
			bestformat = curformat;
		}
	}
	return bestformat;
}

/*
 * don't allow a match between a split and non-split visual,
 * or from a client's read-only visual to a new server's
 * read-write visual. The former is because we can't map
 * from a non-split to a split colormap. The latter is because,
 * on linear read-only colormaps, client's assume the values in the
 * colormap without doing allocations. We can't move that to
 * a read-write colormap where allocating colors is essential.
 *
 * depths must already have been matched up. only match up visuals
 * whose depths are compatible with the pixmapformat's matchings.
 */
	
static VisualPtr
FindCompatibleVisual(ImageFormatPtr srcfmt, VisualPtr visual, ImageFormatPtr formats)
{
	VisualPtr bestvisual = NULL, curvisual;
	PixmapFormatPtr pixdepth;
	int newdepth;

	pixdepth = GetPixmapFormat(srcfmt, visual->vis_depth);
	if (pixdepth == NULL)
		return NULL;
	newdepth = pixdepth->mapped_depth->depth;

	/* We *always* link the default visuals */

	if (visual == srcfmt->sc_default_vis) {
		bestvisual = formats->sc_default_vis;
		if ((IsVisualSplit(visual) != IsVisualSplit(bestvisual)) ||
		    (IsVisualLinear(visual) && !IsVisualLinear(bestvisual)) ||
		    (visual->vis_depth == 1 && bestvisual->vis_depth != 1) ||
		    (bestvisual->vis_depth != newdepth))
		{
			bestvisual = NULL;
		}
		goto FCV_done;
	}

	debug(3, (stderr, "FindCompatibleVisual: checking for %s visual %x\n",
		  visual->vis_inuse ? "in-use" : "unused", visual->vis_id));
	
	for (curvisual = formats->sc_visuals;
	     curvisual < formats->sc_visuals + formats->sc_visuals_count;
	     curvisual++)
	{
		if (curvisual->vis_depth != newdepth)
			continue;

		debug(3, (stderr, "FindCompatibleVisual: comparing with visual %x\n",
			  curvisual->vis_id));
		
		if (IsVisualSplit(curvisual) != IsVisualSplit(visual)) {
			debug(3, (stderr, " - wrong split/unified visual\n"));
			continue;
		}
		if (IsVisualLinear(visual) && !IsVisualLinear(curvisual)) {
			debug(3, (stderr, " - can't map RO cvis to a RW svis\n"));
			continue;
		}

		if (bestvisual == NULL) {
			bestvisual = curvisual;
			debug(3, (stderr, " + 1st usable visual\n"));
			continue;
		}
		
		if (IsVisualRW(curvisual) != IsVisualRW(bestvisual)) {
			if (IsVisualRW(curvisual) == IsVisualRW(visual)) {
				debug(3, (stderr, " + correct R/W type\n"));
				bestvisual = curvisual;
			} else
				debug(3, (stderr, " - wrong R/W type\n"));
			continue;
		}

		if (IsVisualSplit(curvisual) || IsVisualSplit(visual))
			continue;

		if (IsVisualColor(curvisual) != IsVisualColor(bestvisual)) {
			if (IsVisualColor(curvisual) == IsVisualColor(visual)) {
				debug(3, (stderr, " + correct color vs. BW\n"));
				bestvisual = curvisual;
			} else
				debug(3, (stderr, " - wrong color vs. BW\n"));
			continue;
		}
	}
FCV_done:
	return bestvisual;
}	

/*
 * MakeNewServerFormats must be called after SaveFormats/SaveVisuals above.
 * It attempts to match the visuals and pixmap formats of the new server to
 * those the client knows about. This can be nothing more than a best-guess
 * effort. It also allocates pixmaps and GCs that are to be used in the
 * process of moving the client to the new server.
 */

Global Bool
MakeNewServerFormats(ImageFormatPtr cformats, ImageFormatPtr sformats)
{
	PixmapFormatPtr	cpixformat, spixformat, bestformat;
	VisualPtr	cvisual, svisual, bestvisual;
	XID		id;

	if (cformats->image_bitmap_bit_order == sformats->image_bitmap_bit_order &&
	    cformats->image_bitmap_unit      == sformats->image_bitmap_unit &&
	    cformats->image_bitmap_pad       == sformats->image_bitmap_pad &&
	    cformats->image_byte_order       == sformats->image_byte_order &&
	    cformats->image_byte_order       == (!XmoveLittleEndian))
	{
		cformats->image_bitmap_compatible = 1;
	} else
		cformats->image_bitmap_compatible = 0;

	Dprintf(("MakeNewServerFormats: image bitmap compat %d\n",
		 cformats->image_bitmap_compatible));

	/* the first two are reserved for making pixmap cursors in move.c */
	id = (new_server->resource_base | (new_server->resource_mask >> 1)) - 2;

	/*
	 * For each pixmap depth that the client has, find the best match
	 * on the new server. Determine if they are so compatible, that
	 * the contents of a ZPixmap image can be converted in-place
	 * between client and server, ie. both C and S expect a given
	 * pixel (x,y) to be at the same offset within the image.
	 */

	for (cpixformat = cformats->sc_formats;
	     cpixformat < cformats->sc_formats + cformats->sc_formats_count;
	     cpixformat++)
	{
		bestformat = FindCompatiblePixFormat(cpixformat, sformats, cformats);
		cpixformat->new_mapped_depth = bestformat;
		bestformat->mapped_depth = cpixformat;
		
		if (cpixformat->depth          == bestformat->depth &&
		    cpixformat->bits_per_pixel == bestformat->bits_per_pixel &&
		    cpixformat->scanline_pad   == bestformat->scanline_pad &&
		    cformats->image_byte_order == sformats->image_byte_order &&
		    cformats->image_byte_order == (!XmoveLittleEndian))
		{
			cpixformat->new_compatible = 1;
		} else
			cpixformat->new_compatible = 0;

		Dprintf(("MakeNewServerFormats: depths C %d --> S %d, compat %d\n",
			 cpixformat->depth, bestformat->depth, cpixformat->compatible));
	}

	/*
	 * Create a Pixmap and GC for each of the server's pixmap depths
	 * to be used while recreating the client's state on the new server.
	 * If no client depth maps to this depth on the server, we need to
	 * find the closest compatible client depth and map us to it. ie.
	 * we have to point to *something* via mapped_depth.
	 */

	for (spixformat = sformats->sc_formats;
	     spixformat < sformats->sc_formats + sformats->sc_formats_count;
	     spixformat++)
	{
		spixformat->new_pixmap = --id;
		XMOVECreatePixmap(new_fd, new_seqno, id, sformats->sc_root_window,
				  1, 1, spixformat->depth);
		spixformat->new_gc = --id;
		XMOVECreateGC(new_fd, new_seqno, id,
			      spixformat->new_pixmap, 0, NULL);
		
		if (spixformat->mapped_depth == spixformat) {
			spixformat->mapped_depth =
				FindCompatiblePixFormat(spixformat, cformats, sformats);
			Dprintf(("MakeNewServerFormats: depths S %d --> C %d\n",
				 spixformat->depth, spixformat->mapped_depth->depth));
		}
	}

	for (cvisual = cformats->sc_visuals;
	     cvisual < cformats->sc_visuals + cformats->sc_visuals_count;
	     cvisual++)
	{
		bestvisual = FindCompatibleVisual(cformats, cvisual, sformats);
		if (bestvisual == NULL && cvisual->vis_inuse)
		{
			Dprintf(("MakeNewServerFormats: ERROR visual C %x --> NULL\n",
				 cvisual->vis_id));
			return False;
		}

		cvisual->vis_new_mapped     = bestvisual;
		cvisual->vis_new_equivalent = False;
		
		if (IsVisualLinear(cvisual) && bestvisual && IsVisualLinear(bestvisual)) {
			if (IsVisualSplit(cvisual)) {
				if (cvisual->vis_red   == bestvisual->vis_red &&
				    cvisual->vis_green == bestvisual->vis_green &&
				    cvisual->vis_blue  == bestvisual->vis_blue)
					cvisual->vis_new_equivalent = True;
			} else {
				if (cvisual->vis_depth == bestvisual->vis_depth)
					cvisual->vis_new_equivalent = True;
			}
		}
		if (bestvisual)
			bestvisual->vis_mapped = cvisual;

		Dprintf(("MakeNewServerFormats: visual C %x --> S%c%x\n",
			cvisual->vis_id,
			cvisual->vis_new_equivalent ? '=' : ' ',
			bestvisual?bestvisual->vis_id:0));
	}

	for (svisual = sformats->sc_visuals;
	     svisual < sformats->sc_visuals + sformats->sc_visuals_count;
	     svisual++)
	{
		if (svisual->vis_mapped == svisual) {
			bestvisual = FindCompatibleVisual(sformats, svisual, cformats);
			if (bestvisual == NULL) {
				Dprintf(("MakeNewServerFormats: visual S %x --> NULL\n",
					 svisual->vis_id));
				return False;
			}
			svisual->vis_mapped = bestvisual;
			Dprintf(("MakeNewServerFormats: visual S %x --> C %x\n",
				 svisual->vis_id, bestvisual->vis_id));
		}
	}
	return True;
}
