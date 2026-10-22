/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#ਜੇ defined test_static_ਅੰਕੜੇ_error
ਖਾਲੀ foo() {
    ਜੇ (1) {
	ਸਥਿਰ ਛੋਟਾ w = (ਪੂਰਨ)&foo; /* initializer not computable */
    }
}

#ਜਾਂਜੇ defined test_static_nodata_error
ਖਾਲੀ foo() {
    ਜੇ (0) {
	ਸਥਿਰ ਛੋਟਾ w = (ਪੂਰਨ)&foo; /* initializer not computable */
    }
}

#ਜਾਂਜੇ defined test_global_ਅੰਕੜੇ_error
ਖਾਲੀ foo();
ਸਥਿਰ ਛੋਟਾ w = (ਪੂਰਨ)&foo; /* initializer not computable */


#ਜਾਂਜੇ defined test_local_ਅੰਕੜੇ_noerror
ਖਾਲੀ foo() {
    ਛੋਟਾ w = &foo; /* 2 cast warnings */
}

#ਜਾਂਜੇ defined test_ਅੰਕੜੇ_suppression_off || defined test_ਅੰਕੜੇ_suppression_on

#ਜੇ defined test_ਅੰਕੜੇ_suppression_on
# define SKIP 1
#ਨਹੀਂਤਾਂ
# define SKIP 0
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __attribute__

ਪੂਰਨ ਮੁੱਖ()
{
    __label__ ts0, te0, ts1, te1;
    ਪੂਰਨ tl, dl;

    ਸਥਿਰ ਅਚਲ ਅੱਖਰ ds0 = 0;
    ਸਥਿਰ ਅਚਲ ਅੱਖਰ de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    ਜੇ (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ਸਥਿਰ ਅਚਲ ਅੱਖਰ ds1 = 0;
ts1:;
    ਜੇ (!SKIP) {
        ਖਾਲੀ *p = (ਖਾਲੀ*)&ਮੁੱਖ;
        ਅੱਖਰ cc[] = "static string";
        ਦੁੱਗਣਾ d = 8.0;
        ਬਣਤਰ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __arm__
        __attribute__((packed))
#ਜੇ_ਅੰਤ
        {
            ਬਿਨਾਨਿਸ਼ਾਨੀ x : 12;
            ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ y : 7;
            ਬਿਨਾਨਿਸ਼ਾਨੀ z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        ਲਿਖੋ("data:\n");
        ਲਿਖੋ("  %d - %.1f - %.1f - %s - %s\n",
            ਆਕਾਰ 8.0, 8.0, d, __FUNCTION__, cc);
        ਲਿਖੋ("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ਸਥਿਰ ਅਚਲ ਅੱਖਰ de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    ਲਿਖੋ("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#ਜਾਂਜੇ defined test_static_ਅੰਕੜੇ

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਜਾਓ there;
    ਜੇ (0) {
        ਸਥਿਰ ਪੂਰਨ a = 1;
        ਲਿਖੋ("hello\n"); /* the "hello\n" string is still suppressed */
there:
        ਲਿਖੋ("a = %d\n", a);
    }
    ਵਾਪਸ 0;
}

#ਜੇ_ਅੰਤ
