/*****************************************************************************/
/* test 'nodata_wanted' data output suppression */

#ఒకవేళ defined test_static_దత్తాంశం_error
శూన్య foo() {
    ఒకవేళ (1) {
	స్థిర పొట్టి w = (పూర్ణాంకం)&foo; /* initializer not computable */
    }
}

#లేదావేళ defined test_static_nodata_error
శూన్య foo() {
    ఒకవేళ (0) {
	స్థిర పొట్టి w = (పూర్ణాంకం)&foo; /* initializer not computable */
    }
}

#లేదావేళ defined test_global_దత్తాంశం_error
శూన్య foo();
స్థిర పొట్టి w = (పూర్ణాంకం)&foo; /* initializer not computable */


#లేదావేళ defined test_local_దత్తాంశం_noerror
శూన్య foo() {
    పొట్టి w = &foo; /* 2 cast warnings */
}

#లేదావేళ defined test_దత్తాంశం_suppression_off || defined test_దత్తాంశం_suppression_on

#ఒకవేళ defined test_దత్తాంశం_suppression_on
# define SKIP 1
#లేకపోతే
# define SKIP 0
#అయితే_ముగింపు

#అన్తర్భావ <stdio.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#నిర్వచనం_రద్దు __attribute__

పూర్ణాంకం ప్రధాన()
{
    __label__ ts0, te0, ts1, te1;
    పూర్ణాంకం tl, dl;

    స్థిర స్థిరరాశి అక్షరం ds0 = 0;
    స్థిర స్థిరరాశి అక్షరం de0 = 0;
    /* get reference size of empty jmp */
ts0:;
    ఒకవేళ (!SKIP) {}
te0:;
    dl = -(&de0 - &ds0);
    tl = -(&&te0 - &&ts0);

    /* test data and code suppression */
    స్థిర స్థిరరాశి అక్షరం ds1 = 0;
ts1:;
    ఒకవేళ (!SKIP) {
        శూన్య *p = (శూన్య*)&ప్రధాన;
        అక్షరం cc[] = "static string";
        ద్విగుణ d = 8.0;
        నిర్మాణం
#నిర్వచితం_కాకపోతే __arm__
        __attribute__((packed))
#అయితే_ముగింపు
        {
            గుర్తులేని x : 12;
            గుర్తులేని అక్షరం y : 7;
            గుర్తులేని z : 28, a: 4, b: 5;
        } s = { 0x333,0x44,0x555555,6,7 };

        రాయి("data:\n");
        రాయి("  %d - %.1f - %.1f - %s - %s\n",
            పరిమాణం 8.0, 8.0, d, __FUNCTION__, cc);
        రాయి("  %x %x %x %x %x\n",
            s.x, s.y, s.z, s.a, s.b);
    }
te1:;
    స్థిర స్థిరరాశి అక్షరం de1 = 0;

    dl += &de1 - &ds1;
    tl += &&te1 - &&ts1;
    రాయి("size of data/text:\n  %s/%s\n",
        dl ? "non-zero":"zero", tl ? "non-zero":"zero");
    /*printf("# %d/%d\n", dl, tl);*/
}

#లేదావేళ defined test_static_దత్తాంశం

#అన్తర్భావ <stdio.h>
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    వెళ్ళు there;
    ఒకవేళ (0) {
        స్థిర పూర్ణాంకం a = 1;
        రాయి("hello\n"); /* the "hello\n" string is still suppressed */
there:
        రాయి("a = %d\n", a);
    }
    తిరిగి 0;
}

#అయితే_ముగింపు
