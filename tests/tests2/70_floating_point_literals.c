#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
    /* decimal floating constant */
    દશાંશ fa0 = .123f;
    દશાંશ fa1 = .123E12F;
    દશાંશ fa2 = .123e-12f;
    દશાંશ fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    દશાંશ fb0 = 123.123f;
    દશાંશ fb1 = 123.123E12F;
    દશાંશ fb2 = 123.123e-12f;
    દશાંશ fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    દશાંશ fc0 = 123.f;
    દશાંશ fc1 = 123.E12F;
    દશાંશ fc2 = 123.e-12f;
    દશાંશ fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    દશાંશ fd0 = 123E12F;
    દશાંશ fd1 = 123e-12f;
    દશાંશ fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    દ્વિગુણ da0 = 0X.1ACP12;
    દ્વિગુણ da1 = 0x.1acp-12;
    દ્વિગુણ da2 = 0x.1acp+12;
    દ્વિગુણ da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    દ્વિગુણ da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    દ્વિગુણ db0 = 0X1AC.BDP12;
    દ્વિગુણ db1 = 0x1ac.bdp-12;
    દ્વિગુણ db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    દ્વિગુણ dc0 = 0X1AC.P12;
    દ્વિગુણ dc1 = 0x1ac.p-12;
    દ્વિગુણ dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    દ્વિગુણ dd0 = 0X1ACP12;
    દ્વિગુણ dd1 = 0x1acp-12;
    દ્વિગુણ dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long દ્વિગુણ la0 = 0B.110101100P12L;
    long દ્વિગુણ la1 = 0b.110101100p-12l;
    long દ્વિગુણ la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long દ્વિગુણ lb0 = 0B110101100.10111101P12L;
    long દ્વિગુણ lb1 = 0b110101100.10111101p-12l;
    long દ્વિગુણ lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long દ્વિગુણ lc0 = 0B110101100.P12L;
    long દ્વિગુણ lc1 = 0b110101100.p-12l;
    long દ્વિગુણ lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long દ્વિગુણ ld0 = 0B110101100P12L;
    long દ્વિગુણ ld1 = 0b110101100p-12l;
    long દ્વિગુણ ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    પાછા 0;
}
