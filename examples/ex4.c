#!/usr/local/bin/tcc -run -L/usr/X11R6/lib -lX11
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    जर (!display) {
        ख_लिखो(मानक_त्रुटि, "Could not open X11 display\n");
        निकास(1);
    }
    म_लिखो("X11 display opened.\n");
    screen = XScreenOfDisplay(display, 0);
    म_लिखो("width = %d\nheight = %d\ndepth = %d\n",
           screen->width,
           screen->height,
           screen->मूळ_depth);
    XCloseDisplay(display);
    परत 0;
}
