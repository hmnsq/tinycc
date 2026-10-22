#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
    /* decimal floating constant */
    தசம fa0 = .123f;
    தசம fa1 = .123E12F;
    தசம fa2 = .123e-12f;
    தசம fa3 = .123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fa0, fa1, fa2, fa3);

    தசம fb0 = 123.123f;
    தசம fb1 = 123.123E12F;
    தசம fb2 = 123.123e-12f;
    தசம fb3 = 123.123e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fb0, fb1, fb2, fb3);

    தசம fc0 = 123.f;
    தசம fc1 = 123.E12F;
    தசம fc2 = 123.e-12f;
    தசம fc3 = 123.e+12f;
    printf("%f\n%f\n%f\n%f\n\n", fc0, fc1, fc2, fc3);

    தசம fd0 = 123E12F;
    தசம fd1 = 123e-12f;
    தசம fd2 = 123e+12f;
    printf("%f\n%f\n%f\n\n", fd0, fd1, fd2);
    printf("\n");

    /* hexadecimal floating constant */
    இரட்டை da0 = 0X.1ACP12;
    இரட்டை da1 = 0x.1acp-12;
    இரட்டை da2 = 0x.1acp+12;
    இரட்டை da3 = 0x1.00000000000000000000000000000000000000000000p+12;
    இரட்டை da4 = 0x1000000000000000000000000000000000000000000000p-140;
    printf("%f\n%f\n%f\n%f\n%f\n\n", da0, da1, da2, da3, da4);

    இரட்டை db0 = 0X1AC.BDP12;
    இரட்டை db1 = 0x1ac.bdp-12;
    இரட்டை db2 = 0x1ac.dbp+12;
    printf("%f\n%f\n%f\n\n", db0, db1, db2);

    இரட்டை dc0 = 0X1AC.P12;
    இரட்டை dc1 = 0x1ac.p-12;
    இரட்டை dc2 = 0x1ac.p+12;
    printf("%f\n%f\n%f\n\n", dc0, dc1, dc2);

    இரட்டை dd0 = 0X1ACP12;
    இரட்டை dd1 = 0x1acp-12;
    இரட்டை dd2 = 0x1acp+12;
    printf("%f\n%f\n%f\n\n", dd0, dd1, dd2);
    printf("\n");

#ifdef __TINYC__
    /* TCC extension
       binary floating constant */
    long இரட்டை la0 = 0B.110101100P12L;
    long இரட்டை la1 = 0b.110101100p-12l;
    long இரட்டை la2 = 0b.110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", la0, la1, la2);

    long இரட்டை lb0 = 0B110101100.10111101P12L;
    long இரட்டை lb1 = 0b110101100.10111101p-12l;
    long இரட்டை lb2 = 0b110101100.10111101p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lb0, lb1, lb2);

    long இரட்டை lc0 = 0B110101100.P12L;
    long இரட்டை lc1 = 0b110101100.p-12l;
    long இரட்டை lc2 = 0b110101100.p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", lc0, lc1, lc2);

    long இரட்டை ld0 = 0B110101100P12L;
    long இரட்டை ld1 = 0b110101100p-12l;
    long இரட்டை ld2 = 0b110101100p+12l;
    printf("%Lf\n%Lf\n%Lf\n\n", ld0, ld1, ld2);
#endif

    திரும்பு 0;
}
