#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    যদি (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->মূল_depth);
    XCloseDisplay(display);
    ঘূৰাই 0;
}
