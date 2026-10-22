/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#ಆದರೆ defined test_static_ದತ್ತಾಂಶ_error
ಶೂನ್ಯ foo() {
    ಆದರೆ (1) {
	ಸ್ಥಿರ ಗಿಡ್ಡ w = (ಪೂರ್ಣಾಂಕ)&foo; /* initializer not computable */
    }
}

#ಅಥವಾಆದರೆ defined test_static_nodata_error
ಶೂನ್ಯ foo() {
    ಆದರೆ (0) {
	ಸ್ಥಿರ ಗಿಡ್ಡ w = (ಪೂರ್ಣಾಂಕ)&foo; /* initializer not computable */
    }
}

#ಅಥವಾಆದರೆ defined test_global_ದತ್ತಾಂಶ_error
ಶೂನ್ಯ foo();
ಸ್ಥಿರ ಗಿಡ್ಡ w = (ಪೂರ್ಣಾಂಕ)&foo; /* initializer not computable */


#ಅಥವಾಆದರೆ defined test_local_ದತ್ತಾಂಶ_noerror
ಶೂನ್ಯ foo() {
    ಗಿಡ್ಡ w = &foo; /* 2 cast warnings */
}

#ಅಥವಾಆದರೆ defined test_ದತ್ತಾಂಶ_suppression_off || defined test_ದತ್ತಾಂಶ_suppression_on

#ಆದರೆ defined test_ದತ್ತಾಂಶ_suppression_on
# define SKIP 1
#ಇಲ್ಲದಿದ್ದರೆ
# define SKIP 0
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __attribute__

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    __label__ ts0, te0, ts1, te1;
    ಪೂರ್ಣಾಂಕ tl, dl;

    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ ds0 = 0;
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    ಆದರೆ (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ ds1 = 0;
ts1:;
    ಆದರೆ (!SKIP) {
        ಶೂನ್ಯ *p = (ಶೂನ್ಯ*)&ಮುಖ್ಯ;
        ಅಕ್ಷರ cc[] = "static string";
        ದ್ವಿಗುಣ d = 8.0;
        ರಚನೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __arm__
        __attribute__((packed))
#ಆದರೆ_ಅಂತ್ಯ
        {
            ಚಿಹ್ನೆರಹಿತ x : 12;
            ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ y : 7;
            ಚಿಹ್ನೆರಹಿತ z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        ಬರೆ("data:\n");
        ಬರೆ("  %d - %.1f - %.1f - %s - %s\n",
            ಗಾತ್ರ 8.0, 8.0, d, __FUNCTION__, cc);
        ಬರೆ("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    ಬರೆ("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#ಅಥವಾಆದರೆ defined test_static_ದತ್ತಾಂಶ

#ಅನ್ತರ್ಭಾವ <stdio.h>
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಹೋಗು there;
    ಆದರೆ (0) {
        ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ a = 1;
        ಬರೆ("hello\n"); /* the "hello\n" string is still suppressed */
there:
        ಬರೆ("a = %d\n", a);
    }
    ಹಿಂತಿರುಗಿ 0;
}

#ಆದರೆ_ಅಂತ್ಯ
