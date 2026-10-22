/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#якщо defined test_static_data_error
void foo() {
    якщо (1) {
	static short w = (ціле)&foo; /* initializer not computable */
    }
}

#elif defined test_static_nodata_error
void foo() {
    якщо (0) {
	static short w = (ціле)&foo; /* initializer not computable */
    }
}

#elif defined test_global_data_error
void foo();
static short w = (ціле)&foo; /* initializer not computable */


#elif defined test_local_data_noerror
void foo() {
    short w = &foo; /* 2 cast warnings */
}

#elif defined test_data_suppression_off || defined test_data_suppression_on

#якщо defined test_data_suppression_on
# define SKIP 1
#інакше
# define SKIP 0
#endif

#include <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

ціле main()
{
    __label__ ts0, te0, ts1, te1;
    ціле tl, dl;

    static const char ds0 = 0;
    static const char de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    якщо (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    static const char ds1 = 0;
ts1:;
    якщо (!SKIP) {
        void *p = (void*)&main;
        char cc[] = "static string";
        double d = 8.0;
        struct
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned char y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            sizeof 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    static const char de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#elif defined test_static_data

#include <stdio.h>
ціле main(ціле argc, char **argv)
{
    goto there;
    якщо (0) {
        static ціле a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    повернути 0;
}

#endif
