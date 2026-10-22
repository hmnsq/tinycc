#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    /* decimal floating constant */
    ദശാംശം fa0 = .123f;
    ദശാംശം fa1 = .123E12F;
    ദശാംശം fa2 = .123e-12f;
    ദശാംശം fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    ദശാംശം fb0 = 123.123f;
    ദശാംശം fb1 = 123.123E12F;
    ദശാംശം fb2 = 123.123e-12f;
    ദശാംശം fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    ദശാംശം fc0 = 123.f;
    ദശാംശം fc1 = 123.E12F;
    ദശാംശം fc2 = 123.e-12f;
    ദശാംശം fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    ദശാംശം fd0 = 123E12F;
    ദശാംശം fd1 = 123e-12f;
    ദശാംശം fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    ഇരട്ട da0 = 0X.1ACP12;
    ഇരട്ട da1 = 0x.1acp-12;
    ഇരട്ട da2 = 0x.1acp+12;
    ഇരട്ട da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    ഇരട്ട da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    ഇരട്ട db0 = 0X1AC.BDP12;
    ഇരട്ട db1 = 0x1ac.bdp-12;
    ഇരട്ട db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    ഇരട്ട dc0 = 0X1AC.P12;
    ഇരട്ട dc1 = 0x1ac.p-12;
    ഇരട്ട dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    ഇരട്ട dd0 = 0X1ACP12;
    ഇരട്ട dd1 = 0x1acp-12;
    ഇരട്ട dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long ഇരട്ട la0 = 0B.110101100P12L;
    long ഇരട്ട la1 = 0b.110101100p-12l;
    long ഇരട്ട la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long ഇരട്ട lb0 = 0B110101100.10111101P12L;
    long ഇരട്ട lb1 = 0b110101100.10111101p-12l;
    long ഇരട്ട lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long ഇരട്ട lc0 = 0B110101100.P12L;
    long ഇരട്ട lc1 = 0b110101100.p-12l;
    long ഇരട്ട lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long ഇരട്ട ld0 = 0B110101100P12L;
    long ഇരട്ട ld1 = 0b110101100p-12l;
    long ഇരട്ട ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    തിരികെ 0;
}
