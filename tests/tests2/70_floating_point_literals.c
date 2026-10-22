#ضمن <stdio.h>

صحيح main()
{
    /* decimal floating constant */
    عائم fa0 = .123f;
    عائم fa1 = .123E12F;
    عائم fa2 = .123e-12f;
    عائم fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    عائم fb0 = 123.123f;
    عائم fb1 = 123.123E12F;
    عائم fb2 = 123.123e-12f;
    عائم fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    عائم fc0 = 123.f;
    عائم fc1 = 123.E12F;
    عائم fc2 = 123.e-12f;
    عائم fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    عائم fd0 = 123E12F;
    عائم fd1 = 123e-12f;
    عائم fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    مزدوج da0 = 0X.1ACP12;
    مزدوج da1 = 0x.1acp-12;
    مزدوج da2 = 0x.1acp+12;
    مزدوج da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    مزدوج da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    مزدوج db0 = 0X1AC.BDP12;
    مزدوج db1 = 0x1ac.bdp-12;
    مزدوج db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    مزدوج dc0 = 0X1AC.P12;
    مزدوج dc1 = 0x1ac.p-12;
    مزدوج dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    مزدوج dd0 = 0X1ACP12;
    مزدوج dd1 = 0x1acp-12;
    مزدوج dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long مزدوج la0 = 0B.110101100P12L;
    long مزدوج la1 = 0b.110101100p-12l;
    long مزدوج la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long مزدوج lb0 = 0B110101100.10111101P12L;
    long مزدوج lb1 = 0b110101100.10111101p-12l;
    long مزدوج lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long مزدوج lc0 = 0B110101100.P12L;
    long مزدوج lc1 = 0b110101100.p-12l;
    long مزدوج lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long مزدوج ld0 = 0B110101100P12L;
    long مزدوج ld1 = 0b110101100p-12l;
    long مزدوج ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    ܦܢܐ 0;
}
