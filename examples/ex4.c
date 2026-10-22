#!/usr/local/bin/tcc -لاڳيتو -L/usr/X11R6/lib -lX11
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

صحيح مکيه(صحيح argc, حرف **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    إذا (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        ٻاهر_نڪرو(1);
    }
    لکو("X11 display opened.\n");
    screen = XScreen_جو_Display(display, 0);
    لکو("width = %d\nheight = %d\ndepth = %d\n",
           screen->ويڪر,
           screen->اوچائي,
           screen->پاڙ_اونهائي);
    XCloseDisplay(display);
    أرجع 0;
}
