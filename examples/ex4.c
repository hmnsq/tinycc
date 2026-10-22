#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    जइ (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->मूलम्_depth);
    XCloseDisplay(display);
    प्रत्यागम 0;
}
