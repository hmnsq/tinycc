/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#නම් defined test_static_data_error
void foo() {
    නම් (1) {
	static short w = (පූර්ණ_සංඛ්‍යා)&foo; /* initializer not computable */
    }
}

#elif defined test_static_nodata_error
void foo() {
    නම් (0) {
	static short w = (පූර්ණ_සංඛ්‍යා)&foo; /* initializer not computable */
    }
}

#elif defined test_global_data_error
void foo();
static short w = (පූර්ණ_සංඛ්‍යා)&foo; /* initializer not computable */


#elif defined test_local_data_noerror
void foo() {
    short w = &foo; /* 2 cast warnings */
}

#elif defined test_data_suppression_off || defined test_data_suppression_on

#නම් defined test_data_suppression_on
# define SKIP 1
#නැතහොත්
# define SKIP 0
#endif

#include <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

පූර්ණ_සංඛ්‍යා main()
{
    __label__ ts0, te0, ts1, te1;
    පූර්ණ_සංඛ්‍යා tl, dl;

    static const var_na ds0 = 0;
    static const var_na de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    නම් (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    static const var_na ds1 = 0;
ts1:;
    නම් (!SKIP) {
        void *p = (void*)&main;
        var_na cc[] = "static string";
        dviguu_na d = 8.0;
        sa_nracanaa
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned var_na y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            parimaa_na 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    static const var_na de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#elif defined test_static_data

#include <stdio.h>
පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා argc, var_na **argv)
{
    goto there;
    නම් (0) {
        static පූර්ණ_සංඛ්‍යා a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    ආපසු 0;
}

#endif
