#!/usr/local/bin/tcc -پرلپسې -L/usr/X11R6/lib -lX11
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

صحيح اصلي(صحيح argc, حرف **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    إذا (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        وتل(1);
    }
    چاپ_کړه("X11 display opened.\n");
    screen = XScreen_د_Display(display, 0);
    چاپ_کړه("width = %d\nheight = %d\ndepth = %d\n",
           screen->پلنوالی,
           screen->لوړوالی,
           screen->ریښه_ژوروالی);
    XCloseDisplay(display);
    أرجع 0;
}
