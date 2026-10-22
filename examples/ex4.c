#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

صحیح اصلی(صحیح argc, نویسه **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    اگر (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->ریشه_depth);
    XCloseDisplay(display);
    بازگشت 0;
}
