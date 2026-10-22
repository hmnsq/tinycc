// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸಂರಚನಾ s1 { ವರ್ಣ x[1]; } s1 = { "0" };
ಸಂರಚನಾ s2 { ವರ್ಣ x[2]; } s2 = { "12" };
ಸಂರಚನಾ s3 { ವರ್ಣ x[3]; } s3 = { "345" };
ಸಂರಚನಾ s4 { ವರ್ಣ x[4]; } s4 = { "6789" };
ಸಂರಚನಾ s5 { ವರ್ಣ x[5]; } s5 = { "abcde" };
ಸಂರಚನಾ s6 { ವರ್ಣ x[6]; } s6 = { "fghijk" };
ಸಂರಚನಾ s7 { ವರ್ಣ x[7]; } s7 = { "lmnopqr" };
ಸಂರಚನಾ s8 { ವರ್ಣ x[8]; } s8 = { "stuvwxyz" };
ಸಂರಚನಾ s9 { ವರ್ಣ x[9]; } s9 = { "ABCDEFGHI" };
ಸಂರಚನಾ s10 { ವರ್ಣ x[10]; } s10 = { "JKLMNOPQRS" };
ಸಂರಚನಾ s11 { ವರ್ಣ x[11]; } s11 = { "TUVWXYZ0123" };
ಸಂರಚನಾ s12 { ವರ್ಣ x[12]; } s12 = { "456789abcdef" };
ಸಂರಚನಾ s13 { ವರ್ಣ x[13]; } s13 = { "ghijklmnopqrs" };
ಸಂರಚನಾ s14 { ವರ್ಣ x[14]; } s14 = { "tuvwxyzABCDEFG" };
ಸಂರಚನಾ s15 { ವರ್ಣ x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
ಸಂರಚನಾ s16 { ವರ್ಣ x[16]; } s16 = { "WXYZ0123456789ab" };
ಸಂರಚನಾ s17 { ವರ್ಣ x[17]; } s17 = { "cdefghijklmnopqrs" };

ಸಂರಚನಾ hfa11 { ಭಿನ್ನ a; } hfa11 = { 11.1 };
ಸಂರಚನಾ hfa12 { ಭಿನ್ನ a, b; } hfa12 = { 12.1, 12.2 };
ಸಂರಚನಾ hfa13 { ಭಿನ್ನ a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
ಸಂರಚನಾ hfa14 { ಭಿನ್ನ a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

ಸಂರಚನಾ hfa21 { ದ್ವಿಗುಣ a; } hfa21 = { 21.1 };
ಸಂರಚನಾ hfa22 { ದ್ವಿಗುಣ a, b; } hfa22 = { 22.1, 22.2 };
ಸಂರಚನಾ hfa23 { ದ್ವಿಗುಣ a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
ಸಂರಚನಾ hfa24 { ದ್ವಿಗುಣ a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

ಸಂರಚನಾ hfa31 { long ದ್ವಿಗುಣ a; } hfa31 = { 31.1 };
ಸಂರಚನಾ hfa32 { long ದ್ವಿಗುಣ a, b; } hfa32 = { 32.1, 32.2 };
ಸಂರಚನಾ hfa33 { long ದ್ವಿಗುಣ a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
ಸಂರಚನಾ hfa34 { long ದ್ವಿಗುಣ a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

ಸಂರಚನಾ empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
ಸಂರಚನಾ hfae12 { ಸಂರಚನಾ empty e; ಸಂರಚನಾ hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
ಸಂರಚನಾ hfae22 { ಸಂರಚನಾ empty e; ಸಂರಚನಾ hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

ಶೂನ್ಯ fa_s1(ಸಂರಚನಾ s1 a) { printf("%.1s\n", a.x); }
ಶೂನ್ಯ fa_s2(ಸಂರಚನಾ s2 a) { printf("%.2s\n", a.x); }
ಶೂನ್ಯ fa_s3(ಸಂರಚನಾ s3 a) { printf("%.3s\n", a.x); }
ಶೂನ್ಯ fa_s4(ಸಂರಚನಾ s4 a) { printf("%.4s\n", a.x); }
ಶೂನ್ಯ fa_s5(ಸಂರಚನಾ s5 a) { printf("%.5s\n", a.x); }
ಶೂನ್ಯ fa_s6(ಸಂರಚನಾ s6 a) { printf("%.6s\n", a.x); }
ಶೂನ್ಯ fa_s7(ಸಂರಚನಾ s7 a) { printf("%.7s\n", a.x); }
ಶೂನ್ಯ fa_s8(ಸಂರಚನಾ s8 a) { printf("%.8s\n", a.x); }
ಶೂನ್ಯ fa_s9(ಸಂರಚನಾ s9 a) { printf("%.9s\n", a.x); }
ಶೂನ್ಯ fa_s10(ಸಂರಚನಾ s10 a) { printf("%.10s\n", a.x); }
ಶೂನ್ಯ fa_s11(ಸಂರಚನಾ s11 a) { printf("%.11s\n", a.x); }
ಶೂನ್ಯ fa_s12(ಸಂರಚನಾ s12 a) { printf("%.12s\n", a.x); }
ಶೂನ್ಯ fa_s13(ಸಂರಚನಾ s13 a) { printf("%.13s\n", a.x); }
ಶೂನ್ಯ fa_s14(ಸಂರಚನಾ s14 a) { printf("%.14s\n", a.x); }
ಶೂನ್ಯ fa_s15(ಸಂರಚನಾ s15 a) { printf("%.15s\n", a.x); }
ಶೂನ್ಯ fa_s16(ಸಂರಚನಾ s16 a) { printf("%.16s\n", a.x); }
ಶೂನ್ಯ fa_s17(ಸಂರಚನಾ s17 a) { printf("%.17s\n", a.x); }

ಶೂನ್ಯ fa_hfa11(ಸಂರಚನಾ hfa11 a)
{ printf("%.1f\n", a.a); }
ಶೂನ್ಯ fa_hfa12(ಸಂರಚನಾ hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
ಶೂನ್ಯ fa_hfa13(ಸಂರಚನಾ hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ಶೂನ್ಯ fa_hfa14(ಸಂರಚನಾ hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ಶೂನ್ಯ fa_hfa21(ಸಂರಚನಾ hfa21 a)
{ printf("%.1f\n", a.a); }
ಶೂನ್ಯ fa_hfa22(ಸಂರಚನಾ hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
ಶೂನ್ಯ fa_hfa23(ಸಂರಚನಾ hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ಶೂನ್ಯ fa_hfa24(ಸಂರಚನಾ hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ಶೂನ್ಯ fa_hfa31(ಸಂರಚನಾ hfa31 a)
{ printf("%.1Lf\n", a.a); }
ಶೂನ್ಯ fa_hfa32(ಸಂರಚನಾ hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
ಶೂನ್ಯ fa_hfa33(ಸಂರಚನಾ hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
ಶೂನ್ಯ fa_hfa34(ಸಂರಚನಾ hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
ಶೂನ್ಯ fa_hfae12(ಸಂರಚನಾ hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
ಶೂನ್ಯ fa_hfae22(ಸಂರಚನಾ hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

ಶೂನ್ಯ fa1(ಸಂರಚನಾ s8 a, ಸಂರಚನಾ s9 b, ಸಂರಚನಾ s10 c, ಸಂರಚನಾ s11 d,
         ಸಂರಚನಾ s12 e, ಸಂರಚನಾ s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ಶೂನ್ಯ fa2(ಸಂರಚನಾ s9 a, ಸಂರಚನಾ s10 b, ಸಂರಚನಾ s11 c, ಸಂರಚನಾ s12 d,
         ಸಂರಚನಾ s13 e, ಸಂರಚನಾ s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ಶೂನ್ಯ fa3(ಸಂರಚನಾ hfa14 a, ಸಂರಚನಾ hfa23 b, ಸಂರಚನಾ hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

ಶೂನ್ಯ fa4(ಸಂರಚನಾ s1 a, ಸಂರಚನಾ hfa14 b, ಸಂರಚನಾ s2 c, ಸಂರಚನಾ hfa24 d,
         ಸಂರಚನಾ s3 e, ಸಂರಚನಾ hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

ಶೂನ್ಯ arg(ಶೂನ್ಯ)
{
    printf("Arguments:\n");
    fa_s1(s1);
    fa_s2(s2);
    fa_s3(s3);
    fa_s4(s4);
    fa_s5(s5);
    fa_s6(s6);
    fa_s7(s7);
    fa_s8(s8);
    fa_s9(s9);
    fa_s10(s10);
    fa_s11(s11);
    fa_s12(s12);
    fa_s13(s13);
    fa_s14(s14);
    fa_s15(s15);
    fa_s16(s16);
    fa_s17(s17);
    fa_hfa11(hfa11);
    fa_hfa12(hfa12);
    fa_hfa13(hfa13);
    fa_hfa14(hfa14);
    fa_hfa21(hfa21);
    fa_hfa22(hfa22);
    fa_hfa23(hfa23);
    fa_hfa24(hfa24);
    fa_hfa31(hfa31);
    fa_hfa32(hfa32);
    fa_hfa33(hfa33);
    fa_hfa34(hfa34);
    fa_hfae12(hfae12);
    fa_hfae22(hfae22);
    fa1(s8, s9, s10, s11, s12, s13);
    fa2(s9, s10, s11, s12, s13, s14);
    fa3(hfa14, hfa23, hfa32);
    fa4(s1, hfa14, s2, hfa24, s3, hfa34);
}

ಸಂರಚನಾ s1 fr_s1(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s1; }
ಸಂರಚನಾ s2 fr_s2(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s2; }
ಸಂರಚನಾ s3 fr_s3(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s3; }
ಸಂರಚನಾ s4 fr_s4(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s4; }
ಸಂರಚನಾ s5 fr_s5(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s5; }
ಸಂರಚನಾ s6 fr_s6(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s6; }
ಸಂರಚನಾ s7 fr_s7(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s7; }
ಸಂರಚನಾ s8 fr_s8(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s8; }
ಸಂರಚನಾ s9 fr_s9(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s9; }
ಸಂರಚನಾ s10 fr_s10(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s10; }
ಸಂರಚನಾ s11 fr_s11(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s11; }
ಸಂರಚನಾ s12 fr_s12(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s12; }
ಸಂರಚನಾ s13 fr_s13(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s13; }
ಸಂರಚನಾ s14 fr_s14(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s14; }
ಸಂರಚನಾ s15 fr_s15(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s15; }
ಸಂರಚನಾ s16 fr_s16(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s16; }
ಸಂರಚನಾ s17 fr_s17(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ s17; }

ಸಂರಚನಾ hfa11 fr_hfa11(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa11; }
ಸಂರಚನಾ hfa12 fr_hfa12(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa12; }
ಸಂರಚನಾ hfa13 fr_hfa13(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa13; }
ಸಂರಚನಾ hfa14 fr_hfa14(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa14; }

ಸಂರಚನಾ hfa21 fr_hfa21(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa21; }
ಸಂರಚನಾ hfa22 fr_hfa22(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa22; }
ಸಂರಚನಾ hfa23 fr_hfa23(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa23; }
ಸಂರಚನಾ hfa24 fr_hfa24(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa24; }

ಸಂರಚನಾ hfa31 fr_hfa31(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa31; }
ಸಂರಚನಾ hfa32 fr_hfa32(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa32; }
ಸಂರಚನಾ hfa33 fr_hfa33(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa33; }
ಸಂರಚನಾ hfa34 fr_hfa34(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfa34; }
ಸಂರಚನಾ hfae12 fr_hfae12(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfae12; }
ಸಂರಚನಾ hfae22 fr_hfae22(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ hfae22; }

ಶೂನ್ಯ ret(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ s1 t1 = fr_s1();
    ಸಂರಚನಾ s2 t2 = fr_s2();
    ಸಂರಚನಾ s3 t3 = fr_s3();
    ಸಂರಚನಾ s4 t4 = fr_s4();
    ಸಂರಚನಾ s5 t5 = fr_s5();
    ಸಂರಚನಾ s6 t6 = fr_s6();
    ಸಂರಚನಾ s7 t7 = fr_s7();
    ಸಂರಚನಾ s8 t8 = fr_s8();
    ಸಂರಚನಾ s9 t9 = fr_s9();
    ಸಂರಚನಾ s10 t10 = fr_s10();
    ಸಂರಚನಾ s11 t11 = fr_s11();
    ಸಂರಚನಾ s12 t12 = fr_s12();
    ಸಂರಚನಾ s13 t13 = fr_s13();
    ಸಂರಚನಾ s14 t14 = fr_s14();
    ಸಂರಚನಾ s15 t15 = fr_s15();
    ಸಂರಚನಾ s16 t16 = fr_s16();
    ಸಂರಚನಾ s17 t17 = fr_s17();
    printf("Return values:\n");
    printf("%.1s\n", t1.x);
    printf("%.2s\n", t2.x);
    printf("%.3s\n", t3.x);
    printf("%.4s\n", t4.x);
    printf("%.5s\n", t5.x);
    printf("%.6s\n", t6.x);
    printf("%.7s\n", t7.x);
    printf("%.8s\n", t8.x);
    printf("%.9s\n", t9.x);
    printf("%.10s\n", t10.x);
    printf("%.11s\n", t11.x);
    printf("%.12s\n", t12.x);
    printf("%.13s\n", t13.x);
    printf("%.14s\n", t14.x);
    printf("%.15s\n", t15.x);
    printf("%.16s\n", t16.x);
    printf("%.17s\n", t17.x);
    printf("%.1f\n", fr_hfa11().a);
    printf("%.1f %.1f\n", fr_hfa12().a, fr_hfa12().b);
    printf("%.1f %.1f\n", fr_hfa13().a, fr_hfa13().c);
    printf("%.1f %.1f\n", fr_hfa14().a, fr_hfa14().d);
    printf("%.1f\n", fr_hfa21().a);
    printf("%.1f %.1f\n", fr_hfa22().a, fr_hfa22().b);
    printf("%.1f %.1f\n", fr_hfa23().a, fr_hfa23().c);
    printf("%.1f %.1f\n", fr_hfa24().a, fr_hfa24().d);
    printf("%.1Lf\n", fr_hfa31().a);
    printf("%.1Lf %.1Lf\n", fr_hfa32().a, fr_hfa32().b);
    printf("%.1Lf %.1Lf\n", fr_hfa33().a, fr_hfa33().c);
    printf("%.1Lf %.1Lf\n", fr_hfa34().a, fr_hfa34().d);
    printf("%.1f %.1f\n", fr_hfae12().h.a, fr_hfae12().h.b);
    printf("%.1f %.1f\n", fr_hfae22().h.a, fr_hfae22().h.b);
}

ಶೂನ್ಯ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        ಸಂರಚನಾ X { ಪೂರ್ಣಾಙ್ಕ _x; };
        ಸಂರಚನಾ X *x = va_arg(ap, ಸಂರಚನಾ X *);
        ಪ್ರತ್ಯಾಗಮ x;
}

ಪೂರ್ಣಾಙ್ಕ match(ಧ್ರುವ ವರ್ಣ **s, ಧ್ರುವ ವರ್ಣ *f)
{
    ಧ್ರುವ ವರ್ಣ *p = *s;
    ಪ್ರತಿ (p = *s; *f && *f == *p; f++, p++)
        ;
    ಯದಿ (!*f) {
        *s = p - 1;
        ಪ್ರತ್ಯಾಗಮ 1;
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಶೂನ್ಯ myprintf(ಧ್ರುವ ವರ್ಣ *format, ...)
{
    ಧ್ರುವ ವರ್ಣ *s;
    va_list ap;
    va_start(ap, format);
    ಪ್ರತಿ (s = format; *s; s++) {
        ಯದಿ (match(&s, "%7s")) {
            ಸಂರಚನಾ s7 t7 = va_arg(ap, ಸಂರಚನಾ s7);
            printf("%.7s", t7.x);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%9s")) {
            ಸಂರಚನಾ s9 t9 = va_arg(ap, ಸಂರಚನಾ s9);
            printf("%.9s", t9.x);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa11")) {
            ಸಂರಚನಾ hfa11 x = va_arg(ap, ಸಂರಚನಾ hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa12")) {
            ಸಂರಚನಾ hfa12 x = va_arg(ap, ಸಂರಚನಾ hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa13")) {
            ಸಂರಚನಾ hfa13 x = va_arg(ap, ಸಂರಚನಾ hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa14")) {
            ಸಂರಚನಾ hfa14 x = va_arg(ap, ಸಂರಚನಾ hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa21")) {
            ಸಂರಚನಾ hfa21 x = va_arg(ap, ಸಂರಚನಾ hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa22")) {
            ಸಂರಚನಾ hfa22 x = va_arg(ap, ಸಂರಚನಾ hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa23")) {
            ಸಂರಚನಾ hfa23 x = va_arg(ap, ಸಂರಚನಾ hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa24")) {
            ಸಂರಚನಾ hfa24 x = va_arg(ap, ಸಂರಚನಾ hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa31")) {
            ಸಂರಚನಾ hfa31 x = va_arg(ap, ಸಂರಚನಾ hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa32")) {
            ಸಂರಚನಾ hfa32 x = va_arg(ap, ಸಂರಚನಾ hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa33")) {
            ಸಂರಚನಾ hfa33 x = va_arg(ap, ಸಂರಚನಾ hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        ಅನ್ಯಥಾ ಯದಿ (match(&s, "%hfa34")) {
            ಸಂರಚನಾ hfa34 x = va_arg(ap, ಸಂರಚನಾ hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        ಅನ್ಯಥಾ
            putchar(*s);
    }
    putchar('\n');
}

ಶೂನ್ಯ stdarg(ಶೂನ್ಯ)
{
    printf("stdarg:\n");
    myprintf("%9s %9s %9s %9s %9s %9s", s9, s9, s9, s9, s9, s9);
    myprintf("%7s %9s %9s %9s %9s %9s", s7, s9, s9, s9, s9, s9);

    myprintf("HFA long double:");
    myprintf("%hfa34 %hfa34 %hfa34 %hfa34", hfa34, hfa34, hfa34, hfa34);
    myprintf("%hfa33 %hfa34 %hfa34 %hfa34", hfa33, hfa34, hfa34, hfa34);
    myprintf("%hfa32 %hfa34 %hfa34 %hfa34", hfa32, hfa34, hfa34, hfa34);
    myprintf("%hfa31 %hfa34 %hfa34 %hfa34", hfa31, hfa34, hfa34, hfa34);

    myprintf("%hfa32 %hfa33 %hfa33 %hfa33 %hfa33",
             hfa32, hfa33, hfa33, hfa33, hfa33);
    myprintf("%hfa31 %hfa33 %hfa33 %hfa33 %hfa33",
             hfa31, hfa33, hfa33, hfa33, hfa33);
    myprintf("%hfa33 %hfa33 %hfa33 %hfa33",
             hfa33, hfa33, hfa33, hfa33);

    myprintf("%hfa34 %hfa32 %hfa32 %hfa32 %hfa32",
             hfa34, hfa32, hfa32, hfa32, hfa32);
    myprintf("%hfa33 %hfa32 %hfa32 %hfa32 %hfa32",
             hfa33, hfa32, hfa32, hfa32, hfa32);

    myprintf("%hfa34 %hfa32 %hfa31 %hfa31 %hfa31 %hfa31",
             hfa34, hfa32, hfa31, hfa31, hfa31, hfa31);

    myprintf("HFA double:");
    myprintf("%hfa24 %hfa24 %hfa24 %hfa24", hfa24, hfa24, hfa24, hfa24);
    myprintf("%hfa23 %hfa24 %hfa24 %hfa24", hfa23, hfa24, hfa24, hfa24);
    myprintf("%hfa22 %hfa24 %hfa24 %hfa24", hfa22, hfa24, hfa24, hfa24);
    myprintf("%hfa21 %hfa24 %hfa24 %hfa24", hfa21, hfa24, hfa24, hfa24);

    myprintf("%hfa22 %hfa23 %hfa23 %hfa23 %hfa23",
             hfa22, hfa23, hfa23, hfa23, hfa23);
    myprintf("%hfa21 %hfa23 %hfa23 %hfa23 %hfa23",
             hfa21, hfa23, hfa23, hfa23, hfa23);
    myprintf("%hfa23 %hfa23 %hfa23 %hfa23",
             hfa23, hfa23, hfa23, hfa23);

    myprintf("%hfa24 %hfa22 %hfa22 %hfa22 %hfa22",
             hfa24, hfa22, hfa22, hfa22, hfa22);
    myprintf("%hfa23 %hfa22 %hfa22 %hfa22 %hfa22",
             hfa23, hfa22, hfa22, hfa22, hfa22);

    myprintf("%hfa24 %hfa22 %hfa21 %hfa21 %hfa21 %hfa21",
             hfa24, hfa22, hfa21, hfa21, hfa21, hfa21);

    myprintf("HFA float:");
    myprintf("%hfa14 %hfa14 %hfa14 %hfa14", hfa14, hfa14, hfa14, hfa14);
    myprintf("%hfa13 %hfa14 %hfa14 %hfa14", hfa13, hfa14, hfa14, hfa14);
    myprintf("%hfa12 %hfa14 %hfa14 %hfa14", hfa12, hfa14, hfa14, hfa14);
    myprintf("%hfa11 %hfa14 %hfa14 %hfa14", hfa11, hfa14, hfa14, hfa14);

    myprintf("%hfa12 %hfa13 %hfa13 %hfa13 %hfa13",
             hfa12, hfa13, hfa13, hfa13, hfa13);
    myprintf("%hfa11 %hfa13 %hfa13 %hfa13 %hfa13",
             hfa11, hfa13, hfa13, hfa13, hfa13);
    myprintf("%hfa13 %hfa13 %hfa13 %hfa13",
             hfa13, hfa13, hfa13, hfa13);

    myprintf("%hfa14 %hfa12 %hfa12 %hfa12 %hfa12",
             hfa14, hfa12, hfa12, hfa12, hfa12);
    myprintf("%hfa13 %hfa12 %hfa12 %hfa12 %hfa12",
             hfa13, hfa12, hfa12, hfa12, hfa12);

    myprintf("%hfa14 %hfa12 %hfa11 %hfa11 %hfa11 %hfa11",
             hfa14, hfa12, hfa11, hfa11, hfa11, hfa11);
}

ಶೂನ್ಯ pll(unsigned long long x)
{
    printf("%llx\n", x);
}

ಶೂನ್ಯ movi(ಶೂನ್ಯ)
{
    printf("MOVI:\n");
    pll(0);
    pll(0xabcd);
    pll(0xabcd0000);
    pll(0xabcd00000000);
    pll(0xabcd000000000000);
    pll(0xffffabcd);
    pll(0xabcdffff);
    pll(0xffffffffffffabcd);
    pll(0xffffffffabcdffff);
    pll(0xffffabcdffffffff);
    pll(0xabcdffffffffffff);
    pll(0xaaaaaaaa);
    pll(0x5555555555555555);
    pll(0x77777777);
    pll(0x3333333333333333);
    pll(0xf8f8f8f8);
    pll(0x1e1e1e1e1e1e1e1e);
    pll(0x3f803f80);
    pll(0x01ff01ff01ff01ff);
    pll(0x007fffc0);
    pll(0x03fff80003fff800);
    pll(0x0007fffffffffe00);

    pll(0xabcd1234);
    pll(0xabcd00001234);
    pll(0xabcd000000001234);
    pll(0xabcd12340000);
    pll(0xabcd000012340000);
    pll(0xabcd123400000000);
    pll(0xffffffffabcd1234);
    pll(0xffffabcdffff1234);
    pll(0xabcdffffffff1234);
    pll(0xffffabcd1234ffff);
    pll(0xabcdffff1234ffff);
    pll(0xabcd1234ffffffff);

    pll(0xffffef0123456789);
    pll(0xabcdef012345ffff);

    pll(0xabcdef0123456789);
}

ಸ್ಥಿರ uint32_t addip0(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x + 0; }
ಸ್ಥಿರ uint64_t sublp0(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x - 0; }
ಸ್ಥಿರ uint32_t addip123(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x + 123; }
ಸ್ಥಿರ uint64_t addlm123(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x + -123; }
ಸ್ಥಿರ uint64_t sublp4095(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x - 4095; }
ಸ್ಥಿರ uint32_t subim503808(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x - -503808; }
ಸ್ಥಿರ uint64_t addp12345(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x + 12345; }
ಸ್ಥಿರ uint32_t subp12345(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x - 12345; }

ಸ್ಥಿರ uint32_t mvni(uint32_t x) { ಪ್ರತ್ಯಾಗಮ 0xffffffff - x; }
ಸ್ಥಿರ uint64_t negl(uint64_t x) { ಪ್ರತ್ಯಾಗಮ 0 - x; }
ಸ್ಥಿರ uint32_t rsbi123(uint32_t x) { ಪ್ರತ್ಯಾಗಮ 123 - x; }
ಸ್ಥಿರ uint64_t rsbl123(uint64_t x) { ಪ್ರತ್ಯಾಗಮ 123 - x; }

ಸ್ಥಿರ uint32_t andi0(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x & 0; }
ಸ್ಥಿರ uint64_t andlm1(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x & -1; }
ಸ್ಥಿರ uint64_t orrl0(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x | 0; }
ಸ್ಥಿರ uint32_t orrim1(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x | -1; }
ಸ್ಥಿರ uint32_t eori0(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x ^ 0; }
ಸ್ಥಿರ uint64_t eorlm1(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x ^ -1; }
ಸ್ಥಿರ uint32_t and0xf0(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x & 0xf0; }
ಸ್ಥಿರ uint64_t orr0xf0(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x | 0xf0; }
ಸ್ಥಿರ uint64_t eor0xf0(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x ^ 0xf0; }

ಸ್ಥಿರ uint32_t lsli0(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x << 0; }
ಸ್ಥಿರ uint32_t lsri0(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x >> 0; }
ಸ್ಥಿರ int64_t asrl0(int64_t x) { ಪ್ರತ್ಯಾಗಮ x >> 0; }
ಸ್ಥಿರ uint32_t lsli1(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x << 1; }
ಸ್ಥಿರ uint32_t lsli31(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x << 31; }
ಸ್ಥಿರ uint64_t lsll1(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x << 1; }
ಸ್ಥಿರ uint64_t lsll63(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x << 63; }
ಸ್ಥಿರ uint32_t lsri1(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x >> 1; }
ಸ್ಥಿರ uint32_t lsri31(uint32_t x) { ಪ್ರತ್ಯಾಗಮ x >> 31; }
ಸ್ಥಿರ uint64_t lsrl1(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x >> 1; }
ಸ್ಥಿರ uint64_t lsrl63(uint64_t x) { ಪ್ರತ್ಯಾಗಮ x >> 63; }
ಸ್ಥಿರ int32_t asri1(int32_t x) { ಪ್ರತ್ಯಾಗಮ x >> 1; }
ಸ್ಥಿರ int32_t asri31(int32_t x) { ಪ್ರತ್ಯಾಗಮ x >> 31; }
ಸ್ಥಿರ int64_t asrl1(int64_t x) { ಪ್ರತ್ಯಾಗಮ x >> 1; }
ಸ್ಥಿರ int64_t asrl63(int64_t x) { ಪ್ರತ್ಯಾಗಮ x >> 63; }

ಶೂನ್ಯ opi(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ x = 1000;
    pll(addip0(x));
    pll(sublp0(x));
    pll(addip123(x));
    pll(addlm123(x));
    pll(sublp4095(x));
    pll(subim503808(x));
    pll(addp12345(x));
    pll(subp12345(x));
    pll(mvni(x));
    pll(negl(x));
    pll(rsbi123(x));
    pll(rsbl123(x));
    pll(andi0(x));
    pll(andlm1(x));
    pll(orrl0(x));
    pll(orrim1(x));
    pll(eori0(x));
    pll(eorlm1(x));
    pll(and0xf0(x));
    pll(orr0xf0(x));
    pll(eor0xf0(x));
    pll(lsli0(x));
    pll(lsri0(x));
    pll(asrl0(x));
    pll(lsli1(x));
    pll(lsli31(x));
    pll(lsll1(x));
    pll(lsll63(x));
    pll(lsri1(x));
    pll(lsri31(x));
    pll(lsrl1(x));
    pll(lsrl63(x));
    pll(asri1(x));
    pll(asri31(x));
    pll(asrl1(x));
    pll(asrl63(x));
}

ಶೂನ್ಯ pcs(ಶೂನ್ಯ)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

ಪೂರ್ಣಾಙ್ಕ main()
{
    pcs();
    ಪ್ರತ್ಯಾಗಮ 0;
}
