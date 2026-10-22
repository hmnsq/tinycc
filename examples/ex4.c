#!/usr/local/bin/tcc -تسلسل -L/usr/X11R6/lib -lX11
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

صحیح مین(صحیح argc, حرف **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    اگر (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        باہر_نکلو(1);
    }
    لکھو("X11 display opened.\n");
    screen = XScreen_کا_Display(display, 0);
    لکھو("width = %d\nheight = %d\ndepth = %d\n",
           screen->چوڑائی,
           screen->اونچائی,
           screen->جڑ_گہرائی);
    XCloseDisplay(display);
    واپس 0;
}
