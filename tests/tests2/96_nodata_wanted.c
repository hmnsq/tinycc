/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#اگر defined test_static_ڈیٹا_error
خالی foo() {
    اگر (1) {
	ساکن مختصر w = (صحیح)&foo; /* initializer not computable */
    }
}

#وگرنہ_اگر defined test_static_nodata_error
خالی foo() {
    اگر (0) {
	ساکن مختصر w = (صحیح)&foo; /* initializer not computable */
    }
}

#وگرنہ_اگر defined test_global_ڈیٹا_error
خالی foo();
ساکن مختصر w = (صحیح)&foo; /* initializer not computable */


#وگرنہ_اگر defined test_local_ڈیٹا_noerror
خالی foo() {
    مختصر w = &foo; /* 2 cast warnings */
}

#وگرنہ_اگر defined test_ڈیٹا_suppression_off || defined test_ڈیٹا_suppression_on

#اگر defined test_ڈیٹا_suppression_on
# define SKIP 1
#ورنہ
# define SKIP 0
#اگر_ختم

#شامل <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#تعریف_منسوخ __attribute__

صحیح مین()
{
    __label__ ts0, te0, ts1, te1;
    صحیح tl, dl;

    ساکن ثابت حرف ds0 = 0;
    ساکن ثابت حرف de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    اگر (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ساکن ثابت حرف ds1 = 0;
ts1:;
    اگر (!SKIP) {
        خالی *p = (خالی*)&مین;
        حرف cc[] = "static string";
        دوہرا d = 8.0;
        ساخت
#اگر_غیر_تعریف_شدہ __arm__
        __attribute__((packed))
#اگر_ختم
        {
            غیرعلامتی x : 12;
            غیرعلامتی حرف y : 7;
            غیرعلامتی z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        لکھو("data:\n");
        لکھو("  %d - %.1f - %.1f - %s - %s\n",
            حجم 8.0, 8.0, d, __FUNCTION__, cc);
        لکھو("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ساکن ثابت حرف de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    لکھو("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#وگرنہ_اگر defined test_static_ڈیٹا

#شامل <stdio.h>
صحیح مین(صحیح argc, حرف **argv)
{
    جاؤ there;
    اگر (0) {
        ساکن صحیح a = 1;
        لکھو("hello\n"); /* the "hello\n" string is still suppressed */
there:
        لکھو("a = %d\n", a);
    }
    واپس 0;
}

#اگر_ختم
