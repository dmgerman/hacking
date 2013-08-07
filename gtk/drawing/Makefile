default: rip


rip6:	rip6.c
	gcc -g rip6.c -o rip `pkg-config --cflags --libs gtk+-3.0 clutter-1.0 clutter-gtk-1.0`


rip:	drawingarea.c
	gcc -g drawingarea.c -o rip `pkg-config --cflags --libs gtk+-3.0 gdk-3.0`
