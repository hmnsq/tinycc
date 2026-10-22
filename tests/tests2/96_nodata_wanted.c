/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#എങ്കിൽ defined test_static_data_error
ശൂന്യം foo() {
    എങ്കിൽ (1) {
	സ്ഥിതം short w = (പൂർണ്ണസംഖ്യ)&foo; /* initializer not computable */
    }
}

#അല്ലെങ്കിലെങ്കിൽ defined test_static_nodata_error
ശൂന്യം foo() {
    എങ്കിൽ (0) {
	സ്ഥിതം short w = (പൂർണ്ണസംഖ്യ)&foo; /* initializer not computable */
    }
}

#അല്ലെങ്കിലെങ്കിൽ defined test_global_data_error
ശൂന്യം foo();
സ്ഥിതം short w = (പൂർണ്ണസംഖ്യ)&foo; /* initializer not computable */


#അല്ലെങ്കിലെങ്കിൽ defined test_local_data_noerror
ശൂന്യം foo() {
    short w = &foo; /* 2 cast warnings */
}

#അല്ലെങ്കിലെങ്കിൽ defined test_data_suppression_off || defined test_data_suppression_on

#എങ്കിൽ defined test_data_suppression_on
# define SKIP 1
#അല്ലെങ്കിൽ
# define SKIP 0
#endif

#അന്തര്ഭാവ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    __label__ ts0, te0, ts1, te1;
    പൂർണ്ണസംഖ്യ tl, dl;

    സ്ഥിതം സ്ഥിരം അക്ഷരം ds0 = 0;
    സ്ഥിതം സ്ഥിരം അക്ഷരം de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    എങ്കിൽ (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    സ്ഥിതം സ്ഥിരം അക്ഷരം ds1 = 0;
ts1:;
    എങ്കിൽ (!SKIP) {
        ശൂന്യം *p = (ശൂന്യം*)&പ്രധാന;
        അക്ഷരം cc[] = "static string";
        ഇരട്ട d = 8.0;
        ഘടന
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned അക്ഷരം y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            വലുപ്പം 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    സ്ഥിതം സ്ഥിരം അക്ഷരം de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#അല്ലെങ്കിലെങ്കിൽ defined test_static_data

#അന്തര്ഭാവ <stdio.h>
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    പോകുക there;
    എങ്കിൽ (0) {
        സ്ഥിതം പൂർണ്ണസംഖ്യ a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    തിരികെ 0;
}

#endif
