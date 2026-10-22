/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#إذا defined test_static_داده_error
فراغ foo() {
    إذا (1) {
	ساكن کوتاه w = (صحيح)&foo; /* initializer not computable */
    }
}

#وإلاإذا defined test_static_nodata_error
فراغ foo() {
    إذا (0) {
	ساكن کوتاه w = (صحيح)&foo; /* initializer not computable */
    }
}

#وإلاإذا defined test_global_داده_error
فراغ foo();
ساكن کوتاه w = (صحيح)&foo; /* initializer not computable */


#وإلاإذا defined test_local_داده_noerror
فراغ foo() {
    کوتاه w = &foo; /* 2 cast warnings */
}

#وإلاإذا defined test_داده_suppression_off || defined test_داده_suppression_on

#إذا defined test_داده_suppression_on
# define SKIP 1
#وإلا
# define SKIP 0
#پایان_اگر

#ضمن <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#لغو_تعریف __attribute__

صحيح اصلی()
{
    __label__ ts0, te0, ts1, te1;
    صحيح tl, dl;

    ساكن ثابت حرف ds0 = 0;
    ساكن ثابت حرف de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    إذا (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ساكن ثابت حرف ds1 = 0;
ts1:;
    إذا (!SKIP) {
        فراغ *p = (فراغ*)&اصلی;
        حرف cc[] = "static string";
        مزدوج d = 8.0;
        بنية
#اگر_تعریف_نشده __arm__
        __attribute__((packed))
#پایان_اگر
        {
            بیعلامت x : 12;
            بیعلامت حرف y : 7;
            بیعلامت z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        چاپ_کن("data:\n");
        چاپ_کن("  %d - %.1f - %.1f - %s - %s\n",
            حجم 8.0, 8.0, d, __FUNCTION__, cc);
        چاپ_کن("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ساكن ثابت حرف de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    چاپ_کن("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#وإلاإذا defined test_static_داده

#ضمن <stdio.h>
صحيح اصلی(صحيح argc, حرف **argv)
{
    اذهب there;
    إذا (0) {
        ساكن صحيح a = 1;
        چاپ_کن("hello\n"); /* the "hello\n" string is still suppressed */
there:
        چاپ_کن("a = %d\n", a);
    }
    أرجع 0;
}

#پایان_اگر
