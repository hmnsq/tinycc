#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
    /* decimal floating constant */
    দশমিক fa0 = .123f;
    দশমিক fa1 = .123E12F;
    দশমিক fa2 = .123e-12f;
    দশমিক fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    দশমিক fb0 = 123.123f;
    দশমিক fb1 = 123.123E12F;
    দশমিক fb2 = 123.123e-12f;
    দশমিক fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    দশমিক fc0 = 123.f;
    দশমিক fc1 = 123.E12F;
    দশমিক fc2 = 123.e-12f;
    দশমিক fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    দশমিক fd0 = 123E12F;
    দশমিক fd1 = 123e-12f;
    দশমিক fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    দ্বিগুণ da0 = 0X.1ACP12;
    দ্বিগুণ da1 = 0x.1acp-12;
    দ্বিগুণ da2 = 0x.1acp+12;
    দ্বিগুণ da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    দ্বিগুণ da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    দ্বিগুণ db0 = 0X1AC.BDP12;
    দ্বিগুণ db1 = 0x1ac.bdp-12;
    দ্বিগুণ db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    দ্বিগুণ dc0 = 0X1AC.P12;
    দ্বিগুণ dc1 = 0x1ac.p-12;
    দ্বিগুণ dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    দ্বিগুণ dd0 = 0X1ACP12;
    দ্বিগুণ dd1 = 0x1acp-12;
    দ্বিগুণ dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long দ্বিগুণ la0 = 0B.110101100P12L;
    long দ্বিগুণ la1 = 0b.110101100p-12l;
    long দ্বিগুণ la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long দ্বিগুণ lb0 = 0B110101100.10111101P12L;
    long দ্বিগুণ lb1 = 0b110101100.10111101p-12l;
    long দ্বিগুণ lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long দ্বিগুণ lc0 = 0B110101100.P12L;
    long দ্বিগুণ lc1 = 0b110101100.p-12l;
    long দ্বিগুণ lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long দ্বিগুণ ld0 = 0B110101100P12L;
    long দ্বিগুণ ld1 = 0b110101100p-12l;
    long দ্বিগুণ ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    ফেরত 0;
}
