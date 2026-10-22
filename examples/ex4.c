#!/usr/local/bin/tcc -پیاپی -L/usr/X11R6/lib -lX11
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

صحيح اصلی(صحيح argc, حرف **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    إذا (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        خروج(1);
    }
    چاپ_کن("X11 display opened.\n");
    screen = XScreen_از_Display(display, 0);
    چاپ_کن("width = %d\nheight = %d\ndepth = %d\n",
           screen->عرض,
           screen->ارتفاع,
           screen->ریشه_عمق);
    XCloseDisplay(display);
    أرجع 0;
}
