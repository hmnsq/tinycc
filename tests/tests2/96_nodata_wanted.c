/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#အကယ်၍ defined test_static_data_error
void foo() {
    အကယ်၍ (1) {
	static short w = (ကိန်းပြည့်)&foo; /* initializer not computable */
    }
}

#elif defined test_static_nodata_error
void foo() {
    အကယ်၍ (0) {
	static short w = (ကိန်းပြည့်)&foo; /* initializer not computable */
    }
}

#elif defined test_global_data_error
void foo();
static short w = (ကိန်းပြည့်)&foo; /* initializer not computable */


#elif defined test_local_data_noerror
void foo() {
    short w = &foo; /* 2 cast warnings */
}

#elif defined test_data_suppression_off || defined test_data_suppression_on

#အကယ်၍ defined test_data_suppression_on
# define SKIP 1
#မဟုတ်ပါက
# define SKIP 0
#endif

#include <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

ကိန်းပြည့် main()
{
    __label__ ts0, te0, ts1, te1;
    ကိန်းပြည့် tl, dl;

    static const var_na ds0 = 0;
    static const var_na de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    အကယ်၍ (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    static const var_na ds1 = 0;
ts1:;
    အကယ်၍ (!SKIP) {
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
ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    goto there;
    အကယ်၍ (0) {
        static ကိန်းပြည့် a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    ပြန်ပေး 0;
}

#endif
