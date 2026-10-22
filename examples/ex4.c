#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

صحيح main(صحيح argc, حرف **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    إذا (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->جذر_depth);
    XCloseDisplay(display);
    أرجع 0;
}
