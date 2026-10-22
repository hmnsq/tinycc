#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    જો (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->મૂળ_depth);
    XCloseDisplay(display);
    પાછા 0;
}
