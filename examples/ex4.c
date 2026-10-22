#!/usr/local/bin/tcc -لگاتار -L/usr/X11R6/lib -lX11
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

صحيح مکھ(صحيح argc, حرف **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    إذا (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        باہر_نکلو(1);
    }
    لکھو("X11 display opened.\n");
    screen = XScreen_دا_Display(display, 0);
    لکھو("width = %d\nheight = %d\ndepth = %d\n",
           screen->چوڑائی,
           screen->اچائی,
           screen->جڑ_ڈونگھائی);
    XCloseDisplay(display);
    أرجع 0;
}
