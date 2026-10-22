/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#ଯଦି defined test_static_data_error
ଶୂନ୍ୟ foo() {
    ଯଦି (1) {
	ସ୍ଥିର short w = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)&foo; /* initializer not computable */
    }
}

#ନଚେତଯଦି defined test_static_nodata_error
ଶୂନ୍ୟ foo() {
    ଯଦି (0) {
	ସ୍ଥିର short w = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)&foo; /* initializer not computable */
    }
}

#ନଚେତଯଦି defined test_global_data_error
ଶୂନ୍ୟ foo();
ସ୍ଥିର short w = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)&foo; /* initializer not computable */


#ନଚେତଯଦି defined test_local_data_noerror
ଶୂନ୍ୟ foo() {
    short w = &foo; /* 2 cast warnings */
}

#ନଚେତଯଦି defined test_data_suppression_off || defined test_data_suppression_on

#ଯଦି defined test_data_suppression_on
# define SKIP 1
#ଅନ୍ୟଥା
# define SKIP 0
#endif

#ଅନ୍ତର୍ଭାଵ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    __label__ ts0, te0, ts1, te1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tl, dl;

    ସ୍ଥିର ଅଚଳ ଅକ୍ଷର ds0 = 0;
    ସ୍ଥିର ଅଚଳ ଅକ୍ଷର de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    ଯଦି (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    ସ୍ଥିର ଅଚଳ ଅକ୍ଷର ds1 = 0;
ts1:;
    ଯଦି (!SKIP) {
        ଶୂନ୍ୟ *p = (ଶୂନ୍ୟ*)&ମୁଖ୍ୟ;
        ଅକ୍ଷର cc[] = "static string";
        ଦ୍ୱିଗୁଣ d = 8.0;
        ସଂରଚନା
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned ଅକ୍ଷର y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            ଆକାର 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    ସ୍ଥିର ଅଚଳ ଅକ୍ଷର de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#ନଚେତଯଦି defined test_static_data

#ଅନ୍ତର୍ଭାଵ <stdio.h>
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ଯାଅ there;
    ଯଦି (0) {
        ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    ଫେରନ୍ତୁ 0;
}

#endif
