#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    എങ്കിൽ (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        exit(1);
    }
    printf("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    printf("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->വേര്_depth);
    XCloseDisplay(display);
    തിരികെ 0;
}
