/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#إذا defined test_static_معلومات_error
فراغ foo() {
    إذا (1) {
	ساكن ننڍو w = (صحيح)&foo; /* initializer not computable */
    }
}

#وإلاإذا defined test_static_nodata_error
فراغ foo() {
    إذا (0) {
	ساكن ننڍو w = (صحيح)&foo; /* initializer not computable */
    }
}

#وإلاإذا defined test_global_معلومات_error
فراغ foo();
ساكن ننڍو w = (صحيح)&foo; /* initializer not computable */


#وإلاإذا defined test_local_معلومات_noerror
فراغ foo() {
    ننڍو w = &foo; /* 2 cast warnings */
}

#وإلاإذا defined test_معلومات_suppression_off || defined test_معلومات_suppression_on

#إذا defined test_معلومات_suppression_on
# define SKIP 1
#وإلا
# define SKIP 0
#جيڪڏهن_پورو

#ضمن <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#وصف_رد __attribute__

صحيح مکيه()
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
        فراغ *p = (فراغ*)&مکيه;
        حرف cc[] = "static string";
        مزدوج d = 8.0;
        بنية
#جيڪڏهن_وصف_نه_ٿيل __arm__
        __attribute__((packed))
#جيڪڏهن_پورو
        {
            بنانشان x : 12;
            بنانشان حرف y : 7;
            بنانشان z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        لکو("data:\n");
        لکو("  %d - %.1f - %.1f - %s - %s\n",
            حجم 8.0, 8.0, d, __FUNCTION__, cc);
        لکو("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ساكن ثابت حرف de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    لکو("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#وإلاإذا defined test_static_معلومات

#ضمن <stdio.h>
صحيح مکيه(صحيح argc, حرف **argv)
{
    اذهب there;
    إذا (0) {
        ساكن صحيح a = 1;
        لکو("hello\n"); /* the "hello\n" string is still suppressed */
there:
        لکو("a = %d\n", a);
    }
    أرجع 0;
}

#جيڪڏهن_پورو
