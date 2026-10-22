#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
    /* decimal floating constant */
    ಭಿನ್ನ fa0 = .123f;
    ಭಿನ್ನ fa1 = .123E12F;
    ಭಿನ್ನ fa2 = .123e-12f;
    ಭಿನ್ನ fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    ಭಿನ್ನ fb0 = 123.123f;
    ಭಿನ್ನ fb1 = 123.123E12F;
    ಭಿನ್ನ fb2 = 123.123e-12f;
    ಭಿನ್ನ fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    ಭಿನ್ನ fc0 = 123.f;
    ಭಿನ್ನ fc1 = 123.E12F;
    ಭಿನ್ನ fc2 = 123.e-12f;
    ಭಿನ್ನ fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    ಭಿನ್ನ fd0 = 123E12F;
    ಭಿನ್ನ fd1 = 123e-12f;
    ಭಿನ್ನ fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    ದ್ವಿಗುಣ da0 = 0X.1ACP12;
    ದ್ವಿಗುಣ da1 = 0x.1acp-12;
    ದ್ವಿಗುಣ da2 = 0x.1acp+12;
    ದ್ವಿಗುಣ da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    ದ್ವಿಗುಣ da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    ದ್ವಿಗುಣ db0 = 0X1AC.BDP12;
    ದ್ವಿಗುಣ db1 = 0x1ac.bdp-12;
    ದ್ವಿಗುಣ db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    ದ್ವಿಗುಣ dc0 = 0X1AC.P12;
    ದ್ವಿಗುಣ dc1 = 0x1ac.p-12;
    ದ್ವಿಗುಣ dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    ದ್ವಿಗುಣ dd0 = 0X1ACP12;
    ದ್ವಿಗುಣ dd1 = 0x1acp-12;
    ದ್ವಿಗುಣ dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long ದ್ವಿಗುಣ la0 = 0B.110101100P12L;
    long ದ್ವಿಗುಣ la1 = 0b.110101100p-12l;
    long ದ್ವಿಗುಣ la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long ದ್ವಿಗುಣ lb0 = 0B110101100.10111101P12L;
    long ದ್ವಿಗುಣ lb1 = 0b110101100.10111101p-12l;
    long ದ್ವಿಗುಣ lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long ದ್ವಿಗುಣ lc0 = 0B110101100.P12L;
    long ದ್ವಿಗುಣ lc1 = 0b110101100.p-12l;
    long ದ್ವಿಗುಣ lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long ದ್ವಿಗುಣ ld0 = 0B110101100P12L;
    long ದ್ವಿಗುಣ ld1 = 0b110101100p-12l;
    long ದ್ವಿಗುಣ ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    ಪ್ರತ್ಯಾಗಮ 0;
}
