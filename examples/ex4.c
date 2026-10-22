#!/usr/local/bin/tcc -ਲੜੀਵਾਰ -L/usr/X11R6/lib -lX11
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    ਜੇ (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        ਬਾਹਰ_ਨਿਕਲੋ(1);
    }
    ਲਿਖੋ("X11 display opened.\n");
    screen = XScreen_ਦਾ_Display(display, 0);
    ਲਿਖੋ("width = %d\nheight = %d\ndepth = %d\n",
           screen->ਚੌੜਾਈ,
           screen->ਉਚਾਈ,
           screen->ਜੜ੍ਹ_ਡੂੰਘਾਈ);
    XCloseDisplay(display);
    ਵਾਪਸ 0;
}
