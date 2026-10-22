/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#ಯದಿ defined test_static_data_error
ಶೂನ್ಯ foo() {
    ಯದಿ (1) {
	ಸ್ಥಿರ short w = (ಪೂರ್ಣಾಙ್ಕ)&foo; /* initializer not computable */
    }
}

#ನೋಚೇದ್ಯದಿ defined test_static_nodata_error
ಶೂನ್ಯ foo() {
    ಯದಿ (0) {
	ಸ್ಥಿರ short w = (ಪೂರ್ಣಾಙ್ಕ)&foo; /* initializer not computable */
    }
}

#ನೋಚೇದ್ಯದಿ defined test_global_data_error
ಶೂನ್ಯ foo();
ಸ್ಥಿರ short w = (ಪೂರ್ಣಾಙ್ಕ)&foo; /* initializer not computable */


#ನೋಚೇದ್ಯದಿ defined test_local_data_noerror
ಶೂನ್ಯ foo() {
    short w = &foo; /* 2 cast warnings */
}

#ನೋಚೇದ್ಯದಿ defined test_data_suppression_off || defined test_data_suppression_on

#ಯದಿ defined test_data_suppression_on
# define SKIP 1
#ಅನ್ಯಥಾ
# define SKIP 0
#endif

#ಅನ್ತರ್ಭಾವ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

ಪೂರ್ಣಾಙ್ಕ main()
{
    __label__ ts0, te0, ts1, te1;
    ಪೂರ್ಣಾಙ್ಕ tl, dl;

    ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ ds0 = 0;
    ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    ಯದಿ (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ ds1 = 0;
ts1:;
    ಯದಿ (!SKIP) {
        ಶೂನ್ಯ *p = (ಶೂನ್ಯ*)&main;
        ವರ್ಣ cc[] = "static string";
        ದ್ವಿಗುಣ d = 8.0;
        ಸಂರಚನಾ
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned ವರ್ಣ y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            ಪರಿಮಾಣ 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#ನೋಚೇದ್ಯದಿ defined test_static_data

#ಅನ್ತರ್ಭಾವ <stdio.h>
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಗಚ್ಛ there;
    ಯದಿ (0) {
        ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

#endif
