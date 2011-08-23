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

static void MoveColorCells P((int new_fd, unsigned short *seqno,
			      ColormapPtr cmap, Colormap mid));
static void MoveSplitColorCells P((int new_fd, unsigned short *seqno,
				   ColormapPtr cmap, Colormap mid));
static card32 MoveColorCell  P((int new_fd, unsigned short *seqno, ColormapPtr cmap,
				XColor *color, Bool rw, Colormap mid));

Global char *
MoveColormaps(void)
{
	ForAllInList(&client->colormap_list)
	{
		ColormapPtr cmap;
		Colormap mid;
		
		cmap = (ColormapPtr)
			CurrentContentsOfList(&client->colormap_list);
		
		mid = MapColormapID(cmap->colormap_id, Client2NewServer);
		
		if (mid & ~client->resource_mask) {
			XMOVEGetInputFocus(new_fd, new_seqno);
			XMOVECreateColormap(new_fd, new_seqno, mid,
					    new_server->formats->sc_root_window,
					    cmap->visual->vis_new_mapped->vis_id, False);
			if (!XMOVEVerifyRequest(new_fd, new_seqno))
				return strdup("Unable to create custom colormaps on new server\n");
		}
		
		MoveColorCells(new_fd, new_seqno, cmap, mid);
		cmap->cmap_moved = 1;
	}
     
	return NULL;
}


static void
MoveColorCells(int new_fd, unsigned short *seqno, ColormapPtr cmap, Colormap mid)
{
	ColorCellPtr cell;
	int count;
	VisualPtr vis = cmap->visual;
	XColor color;
	Bool ctobw;

	if (vis->vis_indices > 1) {
		MoveSplitColorCells(new_fd, seqno, cmap, mid);
		return;
	}
	
	ctobw = (IsVisualColor(cmap->visual) &&
		 !IsVisualColor(cmap->visual->vis_new_mapped));

	for (cell = cmap->cell_array;
	     cell < cmap->cell_array + vis->vis_index[vis->vis_indices];
	     cell++)
	{
		count = cell->usage_count;
		if (count == 0)
			continue;
		if (count > 1 && cell->read_write)
			debug(2, (stderr, "xmove error: r/w colorcell has usage_count>1?\n"));
	  
		if (ctobw) {
			color.red = color.blue = color.green =
				RGB2BW(cell->red, cell->green, cell->blue);
		} else {
			color.red = cell->red;
			color.blue = cell->blue;
			color.green = cell->green;
		}
		
		cell->new_server_pixel =
			MoveColorCell(new_fd, seqno, cmap, &color, cell->read_write, mid);
		debug(2, (stderr, "(%4x/%4x/%4x) pixel %8x (cmap %8x) rw %x\n",
			  color.red, color.blue, color.green, cell->new_server_pixel,
			  cmap->colormap_id, cell->read_write));
		while (--count)
			MoveColorCell(new_fd, seqno, cmap, &color, cell->read_write, mid);
	}
}


static ColorCellPtr
FindNextColor(ColorCellPtr start, ColorCellPtr end, Bool rw)
{
	while (start < end) {
		if (start->usage_count &&
		    ((start->read_write && rw) || (!start->read_write && !rw)))
			return start;
		
		start++;
	}
	return NULL;
}


static void
MoveSplitColorCells(int new_fd, unsigned short *seqno, ColormapPtr cmap, Colormap mid)
{
	ColorCellPtr cell, maxcell, nextrocell[3], nextrwcell[3];
	int index, count, nextrocount[3], nextrwcount[3];
	VisualPtr vis = cmap->visual;
	VisualPtr svis = vis->vis_mapped;
	ColorCellPtr array;
	Bool ctobw;

	array   = cmap->cell_array;
	cell    = array + vis->vis_index[0];
	maxcell = array + vis->vis_index[1];

	while (cell < maxcell && cell->usage_count == 0)
		cell++;
	if (cell >= maxcell)
		return;
	count = cell->usage_count;

	debug(2, (stderr, "main %x/%x\n", cell->client_pixel, count));
	index = 0;
	while (++index < vis->vis_indices) {
		ColorCellPtr minindex, maxindex;

		minindex = array + vis->vis_index[index];
		maxindex = array + vis->vis_index[index+1];
		nextrocell[index] = FindNextColor(minindex, maxindex, False);
		nextrwcell[index] = FindNextColor(minindex, maxindex, True);
		if (nextrocell[index]) {
			nextrocount[index] = nextrocell[index]->usage_count;
			debug(2, (stderr, "RO%x %x/%x\n", index,
				  nextrocell[index]->client_pixel, nextrocount[index]));
		}
		if (nextrwcell[index]) {
			nextrwcount[index] = nextrwcell[index]->usage_count;
			debug(2, (stderr, "RW%x %x/%x\n", index,
				  nextrwcell[index]->client_pixel, nextrwcount[index]));
		}
	}

	ctobw = (IsVisualColor(cmap->visual) &&
		 !IsVisualColor(cmap->visual->vis_new_mapped));
	
	while (1) {
		ColorCellPtr curreq[3];
		Bool firsttime[3];
		Bool rw;
		card32 newpixel;
		XColor color;

		debug(2, (stderr, "MAIN %x/%x\n", cell->client_pixel, count));
		curreq[0] = cell;
		firsttime[0] = (cell->usage_count == count);
		rw = cell->read_write;

		index = 0;
		while (++index < vis->vis_indices) {
			ColorCellPtr maxindex;
			
			maxindex = array + vis->vis_index[index+1];
			
			if (nextrocell[index] == NULL && nextrwcell[index] == NULL)
				panic("xmove out of colors in move\n");

			if ((!rw && nextrocell[index]) || (nextrwcell[index] == NULL)) {
				curreq[index] = nextrocell[index];
				firsttime[index] =
					(nextrocell[index]->usage_count == nextrocount[index]);
				if (--nextrocount[index] == 0) {
				    nextrocell[index] =
					FindNextColor(nextrocell[index] + 1, maxindex, False);
				    if (nextrocell[index])
					nextrocount[index] = nextrocell[index]->usage_count;
				}
				if (nextrocell[index])
					debug(2, (stderr, "RO%x %x/%x\n", index,
						  nextrocell[index]->client_pixel,
						  nextrocount[index]));
				else
					debug(2, (stderr, "RO%x NULL\n", index));
			} else {
				rw = True;
				curreq[index] = nextrwcell[index];
				firsttime[index] =
					(nextrwcell[index]->usage_count == nextrwcount[index]);
				if (--nextrwcount[index] == 0) {
				    nextrwcell[index] =
					FindNextColor(nextrwcell[index] + 1, maxindex, False);
				    if (nextrwcell[index])
					nextrwcount[index] = nextrwcell[index]->usage_count;
				}
				if (nextrwcell[index])
					debug(2, (stderr, "RW%x %x/%x\n", index,
						  nextrwcell[index]->client_pixel,
						  nextrwcount[index]));
				else
					debug(2, (stderr, "RW%x NULL\n", index));
			}
		}
		
		if (ctobw) {
			color.red = color.blue = color.green =
				RGB2BW(curreq[0]->red, curreq[1]->green, curreq[2]->blue);
		} else {
			color.red = curreq[0]->red;
			color.green = curreq[1]->green;
			color.blue = curreq[2]->blue;
		}
		
		newpixel = MoveColorCell(new_fd, seqno, cmap, &color, rw, mid);
		
		debug(2, (stderr, "(%4x/%4x/%4x) pixel %8x (cmap %8x) rw %x\n",
			  color.red, color.green, color.blue, newpixel, cmap->colormap_id, rw));
		index = -1;
		while (++index < vis->vis_indices) {
			if (!firsttime[index])
				continue;
			curreq[index]->new_server_pixel =
				(newpixel >> svis->vis_shift[index]) & svis->vis_mask[index];
		}
		
		if (--count > 0)
			continue;
		while (++cell < maxcell && cell->usage_count == 0)
			;
		if (cell >= maxcell)
			break;
		count = cell->usage_count;
	}
}

static card32
MoveColorCell(int new_fd, unsigned short *seqno, ColormapPtr cmap,
	      XColor *color, Bool rw, Colormap mid)
{
	card32 newpixel;

	if (rw && IsVisualRW(cmap->visual->vis_mapped)) {
		if (XMOVEAllocColorCells(new_fd, seqno, mid, False, NULL, 0, &newpixel, 1))
		{
			color->flags = DoRed | DoGreen | DoBlue;
			color->pixel = newpixel;
			XMOVEStoreColor(new_fd, seqno, mid, color);

			return newpixel;
		}
		/* no read/write cells available for client.  We'll try
		   allocating the color read_only and hope the client doesn't
		   try to change it. */
	}
     
	if (XMOVEAllocColor(new_fd, seqno, mid, color))
		return color->pixel;
     
	/* OK, xmove gives up. If the color is more than half maximum intensity,
	   we set it to white. Otherwise we set it to black. That should work. 
	   If the color is named, we try looking it up. If the name doesn't exist,
	   we just set it to black. */
     
	if (RGB2BW(color->red, color->blue, color->green) > (unsigned)0x18000)
		(void)XMOVEAllocNamedColor(new_fd, seqno, mid, "white", color, color);
	else
		(void)XMOVEAllocNamedColor(new_fd, seqno, mid, "black", color, color);
     
	return color->pixel;
}
