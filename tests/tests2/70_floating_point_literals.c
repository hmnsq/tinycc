#include <stdio.h>

puur_naa_nka main()
{
    /* decimal floating constant */
    float fa0 = .123f;
    float fa1 = .123E12F;
    float fa2 = .123e-12f;
    float fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    float fb0 = 123.123f;
    float fb1 = 123.123E12F;
    float fb2 = 123.123e-12f;
    float fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    float fc0 = 123.f;
    float fc1 = 123.E12F;
    float fc2 = 123.e-12f;
    float fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    float fd0 = 123E12F;
    float fd1 = 123e-12f;
    float fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    dviguu_na da0 = 0X.1ACP12;
    dviguu_na da1 = 0x.1acp-12;
    dviguu_na da2 = 0x.1acp+12;
    dviguu_na da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    dviguu_na da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    dviguu_na db0 = 0X1AC.BDP12;
    dviguu_na db1 = 0x1ac.bdp-12;
    dviguu_na db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    dviguu_na dc0 = 0X1AC.P12;
    dviguu_na dc1 = 0x1ac.p-12;
    dviguu_na dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    dviguu_na dd0 = 0X1ACP12;
    dviguu_na dd1 = 0x1acp-12;
    dviguu_na dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long dviguu_na la0 = 0B.110101100P12L;
    long dviguu_na la1 = 0b.110101100p-12l;
    long dviguu_na la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long dviguu_na lb0 = 0B110101100.10111101P12L;
    long dviguu_na lb1 = 0b110101100.10111101p-12l;
    long dviguu_na lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long dviguu_na lc0 = 0B110101100.P12L;
    long dviguu_na lc1 = 0b110101100.p-12l;
    long dviguu_na lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long dviguu_na ld0 = 0B110101100P12L;
    long dviguu_na ld1 = 0b110101100p-12l;
    long dviguu_na ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    ပွၵ်ႈ 0;
}
