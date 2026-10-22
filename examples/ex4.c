#!/usr/local/bin/tcc -सततम् -L/usr/X11R6/lib -lX11
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <X11/Xlib.h>

/* Yes, TCC can use X11 too ! */

पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    Display *display;
    Screen *screen;

    display = XOpenDisplay("");
    यदि (!display) {
        fprintf(stderr, "Could not open X11 display\n");
        निर्गच्छ(1);
    }
    प्रारूप_लिख("X11 display opened.\n");
    screen = XScreen_सम्बन्धि_Display(display, 0);
    प्रारूप_लिख("width = %d\nheight = %d\ndepth = %d\n",
           screen->विस्तारः,
           screen->height,
           screen->मूलम्_गभीरता);
    XCloseDisplay(display);
    प्रत्यागम 0;
}
