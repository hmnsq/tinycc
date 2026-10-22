/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#যদি defined test_static_data_error
শূন্য foo() {
    যদি (1) {
	স্থির short w = (পূর্ণাঙ্ক)&foo; /* initializer not computable */
    }
}

#নোচেদ্যদি defined test_static_nodata_error
শূন্য foo() {
    যদি (0) {
	স্থির short w = (পূর্ণাঙ্ক)&foo; /* initializer not computable */
    }
}

#নোচেদ্যদি defined test_global_data_error
শূন্য foo();
স্থির short w = (পূর্ণাঙ্ক)&foo; /* initializer not computable */


#নোচেদ্যদি defined test_local_data_noerror
শূন্য foo() {
    short w = &foo; /* 2 cast warnings */
}

#নোচেদ্যদি defined test_data_suppression_off || defined test_data_suppression_on

#যদি defined test_data_suppression_on
# define SKIP 1
#অন্যথা
# define SKIP 0
#endif

#অন্তর্ভাৱ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

পূর্ণাঙ্ক main()
{
    __label__ ts0, te0, ts1, te1;
    পূর্ণাঙ্ক tl, dl;

    স্থির ধ্রুৱ ৱর্ণ ds0 = 0;
    স্থির ধ্রুৱ ৱর্ণ de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    যদি (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    স্থির ধ্রুৱ ৱর্ণ ds1 = 0;
ts1:;
    যদি (!SKIP) {
        শূন্য *p = (শূন্য*)&main;
        ৱর্ণ cc[] = "static string";
        দ্ৱিগুণ d = 8.0;
        সংরচনা
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned ৱর্ণ y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            পরিমাণ 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    স্থির ধ্রুৱ ৱর্ণ de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#নোচেদ্যদি defined test_static_data

#অন্তর্ভাৱ <stdio.h>
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    গচ্ছ there;
    যদি (0) {
        স্থির পূর্ণাঙ্ক a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    ঘূৰাই 0;
}

#endif
