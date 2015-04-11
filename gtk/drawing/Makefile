default: drawing compression speed timer


rip6:	rip6.c
	gcc -g rip6.c -o rip `pkg-config --cflags --libs gtk+-3.0 clutter-1.0 clutter-gtk-1.0`


rip:	drawingarea.c
	gcc -g drawingarea.c -o rip `pkg-config --cflags --libs gtk+-3.0 gdk-3.0`


drawing:	drawing.c
	gcc -g drawing.c -o drawing `pkg-config --cflags --libs gtk+-3.0 gdk-3.0`


compression:	compression.c
	gcc -g compression.c -o compression `pkg-config --cflags --libs gtk+-3.0 gdk-3.0`

speed:	speed.c
	gcc -g speed.c -o speed `pkg-config --cflags --libs gtk+-3.0 gdk-3.0`

timer:  timer.c
	gcc -g timer.c -o timer `pkg-config --cflags --libs gtk+-3.0 gdk-3.0`
