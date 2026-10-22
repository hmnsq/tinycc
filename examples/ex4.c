#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#समावेश <stdlib.h>
#समावेश <stdio.h>
#समावेश <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    अगर (!display) {
        ख_लिखो(मानक_त्रुटि, "Could not open X11 display\n");
        निकास(1);
    }
    म_लिखो("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    म_लिखो("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->मूल_depth);
    XCloseDisplay(display);
    वापस 0;
}
