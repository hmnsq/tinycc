/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#اگر defined test_static_data_error
تهی foo() {
    اگر (1) {
	ایستا short w = (صحیح)&foo; /* initializer not computable */
    }
}

#وگرنهاگر defined test_static_nodata_error
تهی foo() {
    اگر (0) {
	ایستا short w = (صحیح)&foo; /* initializer not computable */
    }
}

#وگرنهاگر defined test_global_data_error
تهی foo();
ایستا short w = (صحیح)&foo; /* initializer not computable */


#وگرنهاگر defined test_local_data_noerror
تهی foo() {
    short w = &foo; /* 2 cast warnings */
}

#وگرنهاگر defined test_data_suppression_off || defined test_data_suppression_on

#اگر defined test_data_suppression_on
# define SKIP 1
#وگرنه
# define SKIP 0
#endif

#شامل <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

صحیح اصلی()
{
    __label__ ts0, te0, ts1, te1;
    صحیح tl, dl;

    ایستا ثابت نویسه ds0 = 0;
    ایستا ثابت نویسه de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    اگر (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ایستا ثابت نویسه ds1 = 0;
ts1:;
    اگر (!SKIP) {
        تهی *p = (تهی*)&اصلی;
        نویسه cc[] = "static string";
        دوگانه d = 8.0;
        ساختار
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned نویسه y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            اندازه 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ایستا ثابت نویسه de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#وگرنهاگر defined test_static_data

#شامل <stdio.h>
صحیح اصلی(صحیح argc, نویسه **argv)
{
    برو there;
    اگر (0) {
        ایستا صحیح a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    بازگشت 0;
}

#endif
