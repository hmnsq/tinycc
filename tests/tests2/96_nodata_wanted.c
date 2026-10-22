/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#যদি defined test_static_তথ্য_error
শূন্য foo() {
    যদি (1) {
	স্থির short w = (পূর্ণসংখ্যা)&foo; /* initializer not computable */
    }
}

#নতুবা_যদি defined test_static_nodata_error
শূন্য foo() {
    যদি (0) {
	স্থির short w = (পূর্ণসংখ্যা)&foo; /* initializer not computable */
    }
}

#নতুবা_যদি defined test_global_তথ্য_error
শূন্য foo();
স্থির short w = (পূর্ণসংখ্যা)&foo; /* initializer not computable */


#নতুবা_যদি defined test_local_তথ্য_noerror
শূন্য foo() {
    short w = &foo; /* 2 cast warnings */
}

#নতুবা_যদি defined test_তথ্য_suppression_off || defined test_তথ্য_suppression_on

#যদি defined test_তথ্য_suppression_on
# define SKIP 1
#অন্যথা
# define SKIP 0
#endif

#অন্তর্ভাব <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

পূর্ণসংখ্যা প্রধান()
{
    __label__ ts0, te0, ts1, te1;
    পূর্ণসংখ্যা tl, dl;

    স্থির ধ্রুবক অক্ষর ds0 = 0;
    স্থির ধ্রুবক অক্ষর de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    যদি (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    স্থির ধ্রুবক অক্ষর ds1 = 0;
ts1:;
    যদি (!SKIP) {
        শূন্য *p = (শূন্য*)&প্রধান;
        অক্ষর cc[] = "static string";
        দ্বিগুণ d = 8.0;
        কাঠামো
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned অক্ষর y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            আকার 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    স্থির ধ্রুবক অক্ষর de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#নতুবা_যদি defined test_static_তথ্য

#অন্তর্ভাব <stdio.h>
পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    যাও there;
    যদি (0) {
        স্থির পূর্ণসংখ্যা a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    ফেরত 0;
}

#endif
