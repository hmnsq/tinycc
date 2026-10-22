/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#જો defined test_static_data_error
શૂન્ય foo() {
    જો (1) {
	સ્થિર short w = (પૂર્ણાંક)&foo; /* initializer not computable */
    }
}

#અથવાજો defined test_static_nodata_error
શૂન્ય foo() {
    જો (0) {
	સ્થિર short w = (પૂર્ણાંક)&foo; /* initializer not computable */
    }
}

#અથવાજો defined test_global_data_error
શૂન્ય foo();
સ્થિર short w = (પૂર્ણાંક)&foo; /* initializer not computable */


#અથવાજો defined test_local_data_noerror
શૂન્ય foo() {
    short w = &foo; /* 2 cast warnings */
}

#અથવાજો defined test_data_suppression_off || defined test_data_suppression_on

#જો defined test_data_suppression_on
# define SKIP 1
#નહીંતર
# define SKIP 0
#endif

#અન્તર્ભાવ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

પૂર્ણાંક મુખ્ય()
{
    __label__ ts0, te0, ts1, te1;
    પૂર્ણાંક tl, dl;

    સ્થિર અચલ અક્ષર ds0 = 0;
    સ્થિર અચલ અક્ષર de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    જો (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    સ્થિર અચલ અક્ષર ds1 = 0;
ts1:;
    જો (!SKIP) {
        શૂન્ય *p = (શૂન્ય*)&મુખ્ય;
        અક્ષર cc[] = "static string";
        દ્વિગુણ d = 8.0;
        સંરચના
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned અક્ષર y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            કદ 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    સ્થિર અચલ અક્ષર de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#અથવાજો defined test_static_data

#અન્તર્ભાવ <stdio.h>
પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    જાઓ there;
    જો (0) {
        સ્થિર પૂર્ણાંક a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    પાછા 0;
}

#endif
