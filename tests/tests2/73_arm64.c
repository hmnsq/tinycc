// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#ଅନ୍ତର୍ଭାଵ <stdarg.h>
#ଅନ୍ତର୍ଭାଵ <stdint.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସଂରଚନା s1 { ଅକ୍ଷର x[1]; } s1 = { "0" };
ସଂରଚନା s2 { ଅକ୍ଷର x[2]; } s2 = { "12" };
ସଂରଚନା s3 { ଅକ୍ଷର x[3]; } s3 = { "345" };
ସଂରଚନା s4 { ଅକ୍ଷର x[4]; } s4 = { "6789" };
ସଂରଚନା s5 { ଅକ୍ଷର x[5]; } s5 = { "abcde" };
ସଂରଚନା s6 { ଅକ୍ଷର x[6]; } s6 = { "fghijk" };
ସଂରଚନା s7 { ଅକ୍ଷର x[7]; } s7 = { "lmnopqr" };
ସଂରଚନା s8 { ଅକ୍ଷର x[8]; } s8 = { "stuvwxyz" };
ସଂରଚନା s9 { ଅକ୍ଷର x[9]; } s9 = { "ABCDEFGHI" };
ସଂରଚନା s10 { ଅକ୍ଷର x[10]; } s10 = { "JKLMNOPQRS" };
ସଂରଚନା s11 { ଅକ୍ଷର x[11]; } s11 = { "TUVWXYZ0123" };
ସଂରଚନା s12 { ଅକ୍ଷର x[12]; } s12 = { "456789abcdef" };
ସଂରଚନା s13 { ଅକ୍ଷର x[13]; } s13 = { "ghijklmnopqrs" };
ସଂରଚନା s14 { ଅକ୍ଷର x[14]; } s14 = { "tuvwxyzABCDEFG" };
ସଂରଚନା s15 { ଅକ୍ଷର x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
ସଂରଚନା s16 { ଅକ୍ଷର x[16]; } s16 = { "WXYZ0123456789ab" };
ସଂରଚନା s17 { ଅକ୍ଷର x[17]; } s17 = { "cdefghijklmnopqrs" };

ସଂରଚନା hfa11 { ଦଶମିକ a; } hfa11 = { 11.1 };
ସଂରଚନା hfa12 { ଦଶମିକ a, b; } hfa12 = { 12.1, 12.2 };
ସଂରଚନା hfa13 { ଦଶମିକ a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
ସଂରଚନା hfa14 { ଦଶମିକ a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

ସଂରଚନା hfa21 { ଦ୍ୱିଗୁଣ a; } hfa21 = { 21.1 };
ସଂରଚନା hfa22 { ଦ୍ୱିଗୁଣ a, b; } hfa22 = { 22.1, 22.2 };
ସଂରଚନା hfa23 { ଦ୍ୱିଗୁଣ a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
ସଂରଚନା hfa24 { ଦ୍ୱିଗୁଣ a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

ସଂରଚନା hfa31 { long ଦ୍ୱିଗୁଣ a; } hfa31 = { 31.1 };
ସଂରଚନା hfa32 { long ଦ୍ୱିଗୁଣ a, b; } hfa32 = { 32.1, 32.2 };
ସଂରଚନା hfa33 { long ଦ୍ୱିଗୁଣ a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
ସଂରଚନା hfa34 { long ଦ୍ୱିଗୁଣ a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

ସଂରଚନା empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
ସଂରଚନା hfae12 { ସଂରଚନା empty e; ସଂରଚନା hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
ସଂରଚନା hfae22 { ସଂରଚନା empty e; ସଂରଚନା hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

ଶୂନ୍ୟ fa_s1(ସଂରଚନା s1 a) { printf("%.1s\n", a.x); }
ଶୂନ୍ୟ fa_s2(ସଂରଚନା s2 a) { printf("%.2s\n", a.x); }
ଶୂନ୍ୟ fa_s3(ସଂରଚନା s3 a) { printf("%.3s\n", a.x); }
ଶୂନ୍ୟ fa_s4(ସଂରଚନା s4 a) { printf("%.4s\n", a.x); }
ଶୂନ୍ୟ fa_s5(ସଂରଚନା s5 a) { printf("%.5s\n", a.x); }
ଶୂନ୍ୟ fa_s6(ସଂରଚନା s6 a) { printf("%.6s\n", a.x); }
ଶୂନ୍ୟ fa_s7(ସଂରଚନା s7 a) { printf("%.7s\n", a.x); }
ଶୂନ୍ୟ fa_s8(ସଂରଚନା s8 a) { printf("%.8s\n", a.x); }
ଶୂନ୍ୟ fa_s9(ସଂରଚନା s9 a) { printf("%.9s\n", a.x); }
ଶୂନ୍ୟ fa_s10(ସଂରଚନା s10 a) { printf("%.10s\n", a.x); }
ଶୂନ୍ୟ fa_s11(ସଂରଚନା s11 a) { printf("%.11s\n", a.x); }
ଶୂନ୍ୟ fa_s12(ସଂରଚନା s12 a) { printf("%.12s\n", a.x); }
ଶୂନ୍ୟ fa_s13(ସଂରଚନା s13 a) { printf("%.13s\n", a.x); }
ଶୂନ୍ୟ fa_s14(ସଂରଚନା s14 a) { printf("%.14s\n", a.x); }
ଶୂନ୍ୟ fa_s15(ସଂରଚନା s15 a) { printf("%.15s\n", a.x); }
ଶୂନ୍ୟ fa_s16(ସଂରଚନା s16 a) { printf("%.16s\n", a.x); }
ଶୂନ୍ୟ fa_s17(ସଂରଚନା s17 a) { printf("%.17s\n", a.x); }

ଶୂନ୍ୟ fa_hfa11(ସଂରଚନା hfa11 a)
{ printf("%.1f\n", a.a); }
ଶୂନ୍ୟ fa_hfa12(ସଂରଚନା hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
ଶୂନ୍ୟ fa_hfa13(ସଂରଚନା hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ଶୂନ୍ୟ fa_hfa14(ସଂରଚନା hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ଶୂନ୍ୟ fa_hfa21(ସଂରଚନା hfa21 a)
{ printf("%.1f\n", a.a); }
ଶୂନ୍ୟ fa_hfa22(ସଂରଚନା hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
ଶୂନ୍ୟ fa_hfa23(ସଂରଚନା hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ଶୂନ୍ୟ fa_hfa24(ସଂରଚନା hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ଶୂନ୍ୟ fa_hfa31(ସଂରଚନା hfa31 a)
{ printf("%.1Lf\n", a.a); }
ଶୂନ୍ୟ fa_hfa32(ସଂରଚନା hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
ଶୂନ୍ୟ fa_hfa33(ସଂରଚନା hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
ଶୂନ୍ୟ fa_hfa34(ସଂରଚନା hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
ଶୂନ୍ୟ fa_hfae12(ସଂରଚନା hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
ଶୂନ୍ୟ fa_hfae22(ସଂରଚନା hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

ଶୂନ୍ୟ fa1(ସଂରଚନା s8 a, ସଂରଚନା s9 b, ସଂରଚନା s10 c, ସଂରଚନା s11 d,
         ସଂରଚନା s12 e, ସଂରଚନା s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ଶୂନ୍ୟ fa2(ସଂରଚନା s9 a, ସଂରଚନା s10 b, ସଂରଚନା s11 c, ସଂରଚନା s12 d,
         ସଂରଚନା s13 e, ସଂରଚନା s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ଶୂନ୍ୟ fa3(ସଂରଚନା hfa14 a, ସଂରଚନା hfa23 b, ସଂରଚନା hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

ଶୂନ୍ୟ fa4(ସଂରଚନା s1 a, ସଂରଚନା hfa14 b, ସଂରଚନା s2 c, ସଂରଚନା hfa24 d,
         ସଂରଚନା s3 e, ସଂରଚନା hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

ଶୂନ୍ୟ arg(ଶୂନ୍ୟ)
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

ସଂରଚନା s1 fr_s1(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s1; }
ସଂରଚନା s2 fr_s2(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s2; }
ସଂରଚନା s3 fr_s3(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s3; }
ସଂରଚନା s4 fr_s4(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s4; }
ସଂରଚନା s5 fr_s5(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s5; }
ସଂରଚନା s6 fr_s6(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s6; }
ସଂରଚନା s7 fr_s7(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s7; }
ସଂରଚନା s8 fr_s8(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s8; }
ସଂରଚନା s9 fr_s9(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s9; }
ସଂରଚନା s10 fr_s10(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s10; }
ସଂରଚନା s11 fr_s11(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s11; }
ସଂରଚନା s12 fr_s12(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s12; }
ସଂରଚନା s13 fr_s13(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s13; }
ସଂରଚନା s14 fr_s14(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s14; }
ସଂରଚନା s15 fr_s15(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s15; }
ସଂରଚନା s16 fr_s16(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s16; }
ସଂରଚନା s17 fr_s17(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ s17; }

ସଂରଚନା hfa11 fr_hfa11(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa11; }
ସଂରଚନା hfa12 fr_hfa12(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa12; }
ସଂରଚନା hfa13 fr_hfa13(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa13; }
ସଂରଚନା hfa14 fr_hfa14(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa14; }

ସଂରଚନା hfa21 fr_hfa21(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa21; }
ସଂରଚନା hfa22 fr_hfa22(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa22; }
ସଂରଚନା hfa23 fr_hfa23(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa23; }
ସଂରଚନା hfa24 fr_hfa24(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa24; }

ସଂରଚନା hfa31 fr_hfa31(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa31; }
ସଂରଚନା hfa32 fr_hfa32(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa32; }
ସଂରଚନା hfa33 fr_hfa33(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa33; }
ସଂରଚନା hfa34 fr_hfa34(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfa34; }
ସଂରଚନା hfae12 fr_hfae12(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfae12; }
ସଂରଚନା hfae22 fr_hfae22(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ hfae22; }

ଶୂନ୍ୟ ret(ଶୂନ୍ୟ)
{
    ସଂରଚନା s1 t1 = fr_s1();
    ସଂରଚନା s2 t2 = fr_s2();
    ସଂରଚନା s3 t3 = fr_s3();
    ସଂରଚନା s4 t4 = fr_s4();
    ସଂରଚନା s5 t5 = fr_s5();
    ସଂରଚନା s6 t6 = fr_s6();
    ସଂରଚନା s7 t7 = fr_s7();
    ସଂରଚନା s8 t8 = fr_s8();
    ସଂରଚନା s9 t9 = fr_s9();
    ସଂରଚନା s10 t10 = fr_s10();
    ସଂରଚନା s11 t11 = fr_s11();
    ସଂରଚନା s12 t12 = fr_s12();
    ସଂରଚନା s13 t13 = fr_s13();
    ସଂରଚନା s14 t14 = fr_s14();
    ସଂରଚନା s15 t15 = fr_s15();
    ସଂରଚନା s16 t16 = fr_s16();
    ସଂରଚନା s17 t17 = fr_s17();
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

ଶୂନ୍ୟ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        ସଂରଚନା X { ପୂର୍ଣ୍ଣସଂଖ୍ୟା _x; };
        ସଂରଚନା X *x = va_arg(ap, ସଂରଚନା X *);
        ଫେରନ୍ତୁ x;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା match(ଅଚଳ ଅକ୍ଷର **s, ଅଚଳ ଅକ୍ଷର *f)
{
    ଅଚଳ ଅକ୍ଷର *p = *s;
    ପାଇଁ (p = *s; *f && *f == *p; f++, p++)
        ;
    ଯଦି (!*f) {
        *s = p - 1;
        ଫେରନ୍ତୁ 1;
    }
    ଫେରନ୍ତୁ 0;
}

ଶୂନ୍ୟ myprintf(ଅଚଳ ଅକ୍ଷର *format, ...)
{
    ଅଚଳ ଅକ୍ଷର *s;
    va_list ap;
    va_start(ap, format);
    ପାଇଁ (s = format; *s; s++) {
        ଯଦି (match(&s, "%7s")) {
            ସଂରଚନା s7 t7 = va_arg(ap, ସଂରଚନା s7);
            printf("%.7s", t7.x);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%9s")) {
            ସଂରଚନା s9 t9 = va_arg(ap, ସଂରଚନା s9);
            printf("%.9s", t9.x);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa11")) {
            ସଂରଚନା hfa11 x = va_arg(ap, ସଂରଚନା hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa12")) {
            ସଂରଚନା hfa12 x = va_arg(ap, ସଂରଚନା hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa13")) {
            ସଂରଚନା hfa13 x = va_arg(ap, ସଂରଚନା hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa14")) {
            ସଂରଚନା hfa14 x = va_arg(ap, ସଂରଚନା hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa21")) {
            ସଂରଚନା hfa21 x = va_arg(ap, ସଂରଚନା hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa22")) {
            ସଂରଚନା hfa22 x = va_arg(ap, ସଂରଚନା hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa23")) {
            ସଂରଚନା hfa23 x = va_arg(ap, ସଂରଚନା hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa24")) {
            ସଂରଚନା hfa24 x = va_arg(ap, ସଂରଚନା hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa31")) {
            ସଂରଚନା hfa31 x = va_arg(ap, ସଂରଚନା hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa32")) {
            ସଂରଚନା hfa32 x = va_arg(ap, ସଂରଚନା hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa33")) {
            ସଂରଚନା hfa33 x = va_arg(ap, ସଂରଚନା hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        ଅନ୍ୟଥା ଯଦି (match(&s, "%hfa34")) {
            ସଂରଚନା hfa34 x = va_arg(ap, ସଂରଚନା hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        ଅନ୍ୟଥା
            putchar(*s);
    }
    putchar('\n');
}

ଶୂନ୍ୟ stdarg(ଶୂନ୍ୟ)
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

ଶୂନ୍ୟ pll(unsigned long long x)
{
    printf("%llx\n", x);
}

ଶୂନ୍ୟ movi(ଶୂନ୍ୟ)
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

ସ୍ଥିର uint32_t addip0(uint32_t x) { ଫେରନ୍ତୁ x + 0; }
ସ୍ଥିର uint64_t sublp0(uint64_t x) { ଫେରନ୍ତୁ x - 0; }
ସ୍ଥିର uint32_t addip123(uint32_t x) { ଫେରନ୍ତୁ x + 123; }
ସ୍ଥିର uint64_t addlm123(uint64_t x) { ଫେରନ୍ତୁ x + -123; }
ସ୍ଥିର uint64_t sublp4095(uint64_t x) { ଫେରନ୍ତୁ x - 4095; }
ସ୍ଥିର uint32_t subim503808(uint32_t x) { ଫେରନ୍ତୁ x - -503808; }
ସ୍ଥିର uint64_t addp12345(uint64_t x) { ଫେରନ୍ତୁ x + 12345; }
ସ୍ଥିର uint32_t subp12345(uint32_t x) { ଫେରନ୍ତୁ x - 12345; }

ସ୍ଥିର uint32_t mvni(uint32_t x) { ଫେରନ୍ତୁ 0xffffffff - x; }
ସ୍ଥିର uint64_t negl(uint64_t x) { ଫେରନ୍ତୁ 0 - x; }
ସ୍ଥିର uint32_t rsbi123(uint32_t x) { ଫେରନ୍ତୁ 123 - x; }
ସ୍ଥିର uint64_t rsbl123(uint64_t x) { ଫେରନ୍ତୁ 123 - x; }

ସ୍ଥିର uint32_t andi0(uint32_t x) { ଫେରନ୍ତୁ x & 0; }
ସ୍ଥିର uint64_t andlm1(uint64_t x) { ଫେରନ୍ତୁ x & -1; }
ସ୍ଥିର uint64_t orrl0(uint64_t x) { ଫେରନ୍ତୁ x | 0; }
ସ୍ଥିର uint32_t orrim1(uint32_t x) { ଫେରନ୍ତୁ x | -1; }
ସ୍ଥିର uint32_t eori0(uint32_t x) { ଫେରନ୍ତୁ x ^ 0; }
ସ୍ଥିର uint64_t eorlm1(uint64_t x) { ଫେରନ୍ତୁ x ^ -1; }
ସ୍ଥିର uint32_t and0xf0(uint32_t x) { ଫେରନ୍ତୁ x & 0xf0; }
ସ୍ଥିର uint64_t orr0xf0(uint64_t x) { ଫେରନ୍ତୁ x | 0xf0; }
ସ୍ଥିର uint64_t eor0xf0(uint64_t x) { ଫେରନ୍ତୁ x ^ 0xf0; }

ସ୍ଥିର uint32_t lsli0(uint32_t x) { ଫେରନ୍ତୁ x << 0; }
ସ୍ଥିର uint32_t lsri0(uint32_t x) { ଫେରନ୍ତୁ x >> 0; }
ସ୍ଥିର int64_t asrl0(int64_t x) { ଫେରନ୍ତୁ x >> 0; }
ସ୍ଥିର uint32_t lsli1(uint32_t x) { ଫେରନ୍ତୁ x << 1; }
ସ୍ଥିର uint32_t lsli31(uint32_t x) { ଫେରନ୍ତୁ x << 31; }
ସ୍ଥିର uint64_t lsll1(uint64_t x) { ଫେରନ୍ତୁ x << 1; }
ସ୍ଥିର uint64_t lsll63(uint64_t x) { ଫେରନ୍ତୁ x << 63; }
ସ୍ଥିର uint32_t lsri1(uint32_t x) { ଫେରନ୍ତୁ x >> 1; }
ସ୍ଥିର uint32_t lsri31(uint32_t x) { ଫେରନ୍ତୁ x >> 31; }
ସ୍ଥିର uint64_t lsrl1(uint64_t x) { ଫେରନ୍ତୁ x >> 1; }
ସ୍ଥିର uint64_t lsrl63(uint64_t x) { ଫେରନ୍ତୁ x >> 63; }
ସ୍ଥିର int32_t asri1(int32_t x) { ଫେରନ୍ତୁ x >> 1; }
ସ୍ଥିର int32_t asri31(int32_t x) { ଫେରନ୍ତୁ x >> 31; }
ସ୍ଥିର int64_t asrl1(int64_t x) { ଫେରନ୍ତୁ x >> 1; }
ସ୍ଥିର int64_t asrl63(int64_t x) { ଫେରନ୍ତୁ x >> 63; }

ଶୂନ୍ୟ opi(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 1000;
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

ଶୂନ୍ୟ pcs(ଶୂନ୍ୟ)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    pcs();
    ଫେରନ୍ତୁ 0;
}
