#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    /* decimal floating constant */
    ଦଶମିକ fa0 = .123f;
    ଦଶମିକ fa1 = .123E12F;
    ଦଶମିକ fa2 = .123e-12f;
    ଦଶମିକ fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    ଦଶମିକ fb0 = 123.123f;
    ଦଶମିକ fb1 = 123.123E12F;
    ଦଶମିକ fb2 = 123.123e-12f;
    ଦଶମିକ fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    ଦଶମିକ fc0 = 123.f;
    ଦଶମିକ fc1 = 123.E12F;
    ଦଶମିକ fc2 = 123.e-12f;
    ଦଶମିକ fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    ଦଶମିକ fd0 = 123E12F;
    ଦଶମିକ fd1 = 123e-12f;
    ଦଶମିକ fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    ଦ୍ୱିଗୁଣ da0 = 0X.1ACP12;
    ଦ୍ୱିଗୁଣ da1 = 0x.1acp-12;
    ଦ୍ୱିଗୁଣ da2 = 0x.1acp+12;
    ଦ୍ୱିଗୁଣ da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    ଦ୍ୱିଗୁଣ da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    ଦ୍ୱିଗୁଣ db0 = 0X1AC.BDP12;
    ଦ୍ୱିଗୁଣ db1 = 0x1ac.bdp-12;
    ଦ୍ୱିଗୁଣ db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    ଦ୍ୱିଗୁଣ dc0 = 0X1AC.P12;
    ଦ୍ୱିଗୁଣ dc1 = 0x1ac.p-12;
    ଦ୍ୱିଗୁଣ dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    ଦ୍ୱିଗୁଣ dd0 = 0X1ACP12;
    ଦ୍ୱିଗୁଣ dd1 = 0x1acp-12;
    ଦ୍ୱିଗୁଣ dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long ଦ୍ୱିଗୁଣ la0 = 0B.110101100P12L;
    long ଦ୍ୱିଗୁଣ la1 = 0b.110101100p-12l;
    long ଦ୍ୱିଗୁଣ la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long ଦ୍ୱିଗୁଣ lb0 = 0B110101100.10111101P12L;
    long ଦ୍ୱିଗୁଣ lb1 = 0b110101100.10111101p-12l;
    long ଦ୍ୱିଗୁଣ lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long ଦ୍ୱିଗୁଣ lc0 = 0B110101100.P12L;
    long ଦ୍ୱିଗୁଣ lc1 = 0b110101100.p-12l;
    long ଦ୍ୱିଗୁଣ lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long ଦ୍ୱିଗୁଣ ld0 = 0B110101100P12L;
    long ଦ୍ୱିଗୁଣ ld1 = 0b110101100p-12l;
    long ଦ୍ୱିଗୁଣ ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    ଫେରନ୍ତୁ 0;
}
