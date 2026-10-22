/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#எனில் defined test_static_data_error
வெறுமை foo() {
    எனில் (1) {
	நிலையான short w = (முழு)&foo; /* initializer not computable */
    }
}

#அல்லதெனில் defined test_static_nodata_error
வெறுமை foo() {
    எனில் (0) {
	நிலையான short w = (முழு)&foo; /* initializer not computable */
    }
}

#அல்லதெனில் defined test_global_data_error
வெறுமை foo();
நிலையான short w = (முழு)&foo; /* initializer not computable */


#அல்லதெனில் defined test_local_data_noerror
வெறுமை foo() {
    short w = &foo; /* 2 cast warnings */
}

#அல்லதெனில் defined test_data_suppression_off || defined test_data_suppression_on

#எனில் defined test_data_suppression_on
# define SKIP 1
#இல்லையெனில்
# define SKIP 0
#endif

#அந்தர்பாவ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

முழு முதன்மை()
{
    __label__ ts0, te0, ts1, te1;
    முழு tl, dl;

    நிலையான மாறிலி எழுத்து ds0 = 0;
    நிலையான மாறிலி எழுத்து de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    எனில் (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    நிலையான மாறிலி எழுத்து ds1 = 0;
ts1:;
    எனில் (!SKIP) {
        வெறுமை *p = (வெறுமை*)&முதன்மை;
        எழுத்து cc[] = "static string";
        இரட்டை d = 8.0;
        கட்டமைப்பு
#ifndef __arm__
        __attribute__((packed))
#endif
        {
            unsigned x : 12;
            unsigned எழுத்து y : 7;
            unsigned z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        printf("data:\n");
        printf("  %d - %.1f - %.1f - %s - %s\n",
            அளவு 8.0, 8.0, d, __FUNCTION__, cc);
        printf("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    நிலையான மாறிலி எழுத்து de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    printf("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#அல்லதெனில் defined test_static_data

#அந்தர்பாவ <stdio.h>
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    செல் there;
    எனில் (0) {
        நிலையான முழு a = 1;
        printf("hello\n"); /* the "hello\n" string is still suppressed */
there:
        printf("a = %d\n", a);
    }
    திரும்பு 0;
}

#endif
