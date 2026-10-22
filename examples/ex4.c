#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    எனில் (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->வேர்_depth);
    XCloseDisplay(display);
    திரும்பு 0;
}
