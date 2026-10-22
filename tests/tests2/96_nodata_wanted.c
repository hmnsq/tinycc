/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#अगर defined test_static_तथ्य_error
व्योम foo() {
    अगर (1) {
	अटल लघु w = (पूर्णांक)&foo; /* initializer not computable */
    }
}

#या_अगर defined test_static_nodata_error
व्योम foo() {
    अगर (0) {
	अटल लघु w = (पूर्णांक)&foo; /* initializer not computable */
    }
}

#या_अगर defined test_global_तथ्य_error
व्योम foo();
अटल लघु w = (पूर्णांक)&foo; /* initializer not computable */


#या_अगर defined test_local_तथ्य_noerror
व्योम foo() {
    लघु w = &foo; /* 2 cast warnings */
}

#या_अगर defined test_तथ्य_suppression_off || defined test_तथ्य_suppression_on

#अगर defined test_तथ्य_suppression_on
# define SKIP 1
#अन्यथा
# define SKIP 0
#पूर्ण_अगर

#समावेश <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#अघोषित __attribute__

पूर्णांक मुख्य()
{
    __label__ ts0, te0, ts1, te1;
    पूर्णांक tl, dl;

    अटल स्थिर अक्षर ds0 = 0;
    अटल स्थिर अक्षर de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    अगर (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    अटल स्थिर अक्षर ds1 = 0;
ts1:;
    अगर (!SKIP) {
        व्योम *p = (व्योम*)&मुख्य;
        अक्षर cc[] = "static string";
        द्विगुन d = 8.0;
        काष्ठा
#अगर_अघोषित __arm__
        __attribute__((packed))
#पूर्ण_अगर
        {
            अचिन्हित x : 12;
            अचिन्हित अक्षर y : 7;
            अचिन्हित z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        म_लिखो("data:\n");
        म_लिखो("  %d - %.1f - %.1f - %s - %s\n",
            माप 8.0, 8.0, d, __FUNCTION__, cc);
        म_लिखो("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    अटल स्थिर अक्षर de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    म_लिखो("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#या_अगर defined test_static_तथ्य

#समावेश <stdio.h>
पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    जाओ there;
    अगर (0) {
        अटल पूर्णांक a = 1;
        म_लिखो("hello\n"); /* the "hello\n" string is still suppressed */
there:
        म_लिखो("a = %d\n", a);
    }
    वापस 0;
}

#पूर्ण_अगर
