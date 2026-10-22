/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#जर defined test_static_data_error
शून्य foo() {
    जर (1) {
	स्थिर लघु w = (पूर्णांक)&foo; /* initializer not computable */
    }
}

#किंवाजर defined test_static_nodata_error
शून्य foo() {
    जर (0) {
	स्थिर लघु w = (पूर्णांक)&foo; /* initializer not computable */
    }
}

#किंवाजर defined test_global_data_error
शून्य foo();
स्थिर लघु w = (पूर्णांक)&foo; /* initializer not computable */


#किंवाजर defined test_local_data_noerror
शून्य foo() {
    लघु w = &foo; /* 2 cast warnings */
}

#किंवाजर defined test_data_suppression_off || defined test_data_suppression_on

#जर defined test_data_suppression_on
# define SKIP 1
#अन्यथा
# define SKIP 0
#endif

#अन्तर्भाव <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

पूर्णांक main()
{
    __label__ ts0, te0, ts1, te1;
    पूर्णांक tl, dl;

    स्थिर स्थिरांक अक्षर ds0 = 0;
    स्थिर स्थिरांक अक्षर de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    जर (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    स्थिर स्थिरांक अक्षर ds1 = 0;
ts1:;
    जर (!SKIP) {
        शून्य *p = (शून्य*)&main;
        अक्षर cc[] = "static string";
        द्विगुण d = 8.0;
        संरचना
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            अचिन्हित x : 12;
            अचिन्हित अक्षर y : 7;
            अचिन्हित z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        म_लिखो("data:\n");
        म_लिखो("  %d - %.1f - %.1f - %s - %s\n",
            आकार 8.0, 8.0, d, __FUNCTION__, cc);
        म_लिखो("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    स्थिर स्थिरांक अक्षर de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    म_लिखो("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#किंवाजर defined test_static_data

#अन्तर्भाव <stdio.h>
पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
    जा there;
    जर (0) {
        स्थिर पूर्णांक a = 1;
        म_लिखो("hello\n"); /* the "hello\n" string is still suppressed */
there:
        म_लिखो("a = %d\n", a);
    }
    परत 0;
}

#endif
