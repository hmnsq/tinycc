#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    ಯದಿ (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->ಬೇರು_depth);
    XCloseDisplay(display);
    ಪ್ರತ್ಯಾಗಮ 0;
}
