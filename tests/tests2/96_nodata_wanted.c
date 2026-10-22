/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#यदि defined test_static_data_error
शून्य foo() {
    यदि (1) {
	स्थिर लघु w = (पूर्णाङ्क)&foo; /* initializer not computable */
    }
}

#नोचेद्यदि defined test_static_nodata_error
शून्य foo() {
    यदि (0) {
	स्थिर लघु w = (पूर्णाङ्क)&foo; /* initializer not computable */
    }
}

#नोचेद्यदि defined test_global_data_error
शून्य foo();
स्थिर लघु w = (पूर्णाङ्क)&foo; /* initializer not computable */


#नोचेद्यदि defined test_local_data_noerror
शून्य foo() {
    लघु w = &foo; /* 2 cast warnings */
}

#नोचेद्यदि defined test_data_suppression_off || defined test_data_suppression_on

#यदि defined test_data_suppression_on
# define SKIP 1
#अन्यथा
# define SKIP 0
#endif

#अन्तर्भाव <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

पूर्णाङ्क main()
{
    __label__ ts0, te0, ts1, te1;
    पूर्णाङ्क tl, dl;

    स्थिर ध्रुव वर्ण ds0 = 0;
    स्थिर ध्रुव वर्ण de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    यदि (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    स्थिर ध्रुव वर्ण ds1 = 0;
ts1:;
    यदि (!SKIP) {
        शून्य *p = (शून्य*)&main;
        वर्ण cc[] = "static string";
        द्विगुण d = 8.0;
        संरचना
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            अचिन्हित x : 12;
            अचिन्हित वर्ण y : 7;
            अचिन्हित z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        म_लिखो("data:\n");
        म_लिखो("  %d - %.1f - %.1f - %s - %s\n",
            परिमाण 8.0, 8.0, d, __FUNCTION__, cc);
        म_लिखो("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    स्थिर ध्रुव वर्ण de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    म_लिखो("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#नोचेद्यदि defined test_static_data

#अन्तर्भाव <stdio.h>
पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    गच्छ there;
    यदि (0) {
        स्थिर पूर्णाङ्क a = 1;
        म_लिखो("hello\n"); /* the "hello\n" string is still suppressed */
there:
        म_लिखो("a = %d\n", a);
    }
    प्रत्यागम 0;
}

#endif
