#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    ଯଦି (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->ମୂଳ_depth);
    XCloseDisplay(display);
    ଫେରନ୍ତୁ 0;
}
