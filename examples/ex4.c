#!/usr/local/bin/tcc -నిరంతరం -L/usr/X11R6/lib -lX11
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    ఒకవేళ (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        నిష్క్రమించు(1);
    }
    రాయి("X11 display opened.\n");
    screen = XScreen_యొక్క_Display(display, 0);
    రాయి("width = %d\nheight = %d\ndepth = %d\n",
           screen->వెడల్పు,
           screen->ఎత్తు,
           screen->మూలం_లోతు);
    XCloseDisplay(display);
    తిరిగి 0;
}
