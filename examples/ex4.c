#!/usr/local/bin/tcc -ಸತತ -L/usr/X11R6/lib -lX11
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    ಆದರೆ (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        ನಿರ್ಗಮಿಸು(1);
    }
    ಬರೆ("X11 display opened.\n");
    screen = XScreen_ದ_Display(display, 0);
    ಬರೆ("width = %d\nheight = %d\ndepth = %d\n",
           screen->ಅಗಲ,
           screen->ಎತ್ತರ,
           screen->ಬೇರು_ಆಳ);
    XCloseDisplay(display);
    ಹಿಂತಿರುಗಿ 0;
}
