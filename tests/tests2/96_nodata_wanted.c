/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#𐡄𐡍 defined test_static_data_error
فراغ foo() {
    𐡄𐡍 (1) {
	ساكن short w = (صحيح)&foo; /* initializer not computable */
    }
}

#وإلاإذا defined test_static_nodata_error
فراغ foo() {
    𐡄𐡍 (0) {
	ساكن short w = (صحيح)&foo; /* initializer not computable */
    }
}

#وإلاإذا defined test_global_data_error
فراغ foo();
ساكن short w = (صحيح)&foo; /* initializer not computable */


#وإلاإذا defined test_local_data_noerror
فراغ foo() {
    short w = &foo; /* 2 cast warnings */
}

#وإلاإذا defined test_data_suppression_off || defined test_data_suppression_on

#𐡄𐡍 defined test_data_suppression_on
# define SKIP 1
#وإلا
# define SKIP 0
#endif

#ضمن <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

صحيح main()
{
    __label__ ts0, te0, ts1, te1;
    صحيح tl, dl;

    ساكن ثابت حرف ds0 = 0;
    ساكن ثابت حرف de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    𐡄𐡍 (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ساكن ثابت حرف ds1 = 0;
ts1:;
    𐡄𐡍 (!SKIP) {
        فراغ *p = (فراغ*)&main;
        حرف cc[] = "static string";
        مزدوج d = 8.0;
        بنية
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned حرف y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            حجم 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ساكن ثابت حرف de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#وإلاإذا defined test_static_data

#ضمن <stdio.h>
صحيح main(صحيح argc, حرف **argv)
{
    اذهب there;
    𐡄𐡍 (0) {
        ساكن صحيح a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    أرجع 0;
}

#endif
