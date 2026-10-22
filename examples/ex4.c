#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    ប្រសិនបើ (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->root_depth);
    XCloseDisplay(display);
    ត្រឡប់ 0;
}
