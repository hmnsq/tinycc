#شامل <stdio.h>

صحیح اصلی()
{
    /* decimal floating constant */
    اعشاری fa0 = .123f;
    اعشاری fa1 = .123E12F;
    اعشاری fa2 = .123e-12f;
    اعشاری fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    اعشاری fb0 = 123.123f;
    اعشاری fb1 = 123.123E12F;
    اعشاری fb2 = 123.123e-12f;
    اعشاری fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    اعشاری fc0 = 123.f;
    اعشاری fc1 = 123.E12F;
    اعشاری fc2 = 123.e-12f;
    اعشاری fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    اعشاری fd0 = 123E12F;
    اعشاری fd1 = 123e-12f;
    اعشاری fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    دوگانه da0 = 0X.1ACP12;
    دوگانه da1 = 0x.1acp-12;
    دوگانه da2 = 0x.1acp+12;
    دوگانه da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    دوگانه da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    دوگانه db0 = 0X1AC.BDP12;
    دوگانه db1 = 0x1ac.bdp-12;
    دوگانه db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    دوگانه dc0 = 0X1AC.P12;
    دوگانه dc1 = 0x1ac.p-12;
    دوگانه dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    دوگانه dd0 = 0X1ACP12;
    دوگانه dd1 = 0x1acp-12;
    دوگانه dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long دوگانه la0 = 0B.110101100P12L;
    long دوگانه la1 = 0b.110101100p-12l;
    long دوگانه la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long دوگانه lb0 = 0B110101100.10111101P12L;
    long دوگانه lb1 = 0b110101100.10111101p-12l;
    long دوگانه lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long دوگانه lc0 = 0B110101100.P12L;
    long دوگانه lc1 = 0b110101100.p-12l;
    long دوگانه lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long دوگانه ld0 = 0B110101100P12L;
    long دوگانه ld1 = 0b110101100p-12l;
    long دوگانه ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    بازگشت 0;
}
