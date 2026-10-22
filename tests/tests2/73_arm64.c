// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਬਣਤਰ s1 { ਅੱਖਰ x[1]; } s1 = { "0" };
ਬਣਤਰ s2 { ਅੱਖਰ x[2]; } s2 = { "12" };
ਬਣਤਰ s3 { ਅੱਖਰ x[3]; } s3 = { "345" };
ਬਣਤਰ s4 { ਅੱਖਰ x[4]; } s4 = { "6789" };
ਬਣਤਰ s5 { ਅੱਖਰ x[5]; } s5 = { "abcde" };
ਬਣਤਰ s6 { ਅੱਖਰ x[6]; } s6 = { "fghijk" };
ਬਣਤਰ s7 { ਅੱਖਰ x[7]; } s7 = { "lmnopqr" };
ਬਣਤਰ s8 { ਅੱਖਰ x[8]; } s8 = { "stuvwxyz" };
ਬਣਤਰ s9 { ਅੱਖਰ x[9]; } s9 = { "ABCDEFGHI" };
ਬਣਤਰ s10 { ਅੱਖਰ x[10]; } s10 = { "JKLMNOPQRS" };
ਬਣਤਰ s11 { ਅੱਖਰ x[11]; } s11 = { "TUVWXYZ0123" };
ਬਣਤਰ s12 { ਅੱਖਰ x[12]; } s12 = { "456789abcdef" };
ਬਣਤਰ s13 { ਅੱਖਰ x[13]; } s13 = { "ghijklmnopqrs" };
ਬਣਤਰ s14 { ਅੱਖਰ x[14]; } s14 = { "tuvwxyzABCDEFG" };
ਬਣਤਰ s15 { ਅੱਖਰ x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
ਬਣਤਰ s16 { ਅੱਖਰ x[16]; } s16 = { "WXYZ0123456789ab" };
ਬਣਤਰ s17 { ਅੱਖਰ x[17]; } s17 = { "cdefghijklmnopqrs" };

ਬਣਤਰ hfa11 { ਦਸ਼ਮਲਵ a; } hfa11 = { 11.1 };
ਬਣਤਰ hfa12 { ਦਸ਼ਮਲਵ a, b; } hfa12 = { 12.1, 12.2 };
ਬਣਤਰ hfa13 { ਦਸ਼ਮਲਵ a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
ਬਣਤਰ hfa14 { ਦਸ਼ਮਲਵ a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

ਬਣਤਰ hfa21 { ਦੁੱਗਣਾ a; } hfa21 = { 21.1 };
ਬਣਤਰ hfa22 { ਦੁੱਗਣਾ a, b; } hfa22 = { 22.1, 22.2 };
ਬਣਤਰ hfa23 { ਦੁੱਗਣਾ a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
ਬਣਤਰ hfa24 { ਦੁੱਗਣਾ a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

ਬਣਤਰ hfa31 { ਲੰਮਾ ਦੁੱਗਣਾ a; } hfa31 = { 31.1 };
ਬਣਤਰ hfa32 { ਲੰਮਾ ਦੁੱਗਣਾ a, b; } hfa32 = { 32.1, 32.2 };
ਬਣਤਰ hfa33 { ਲੰਮਾ ਦੁੱਗਣਾ a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
ਬਣਤਰ hfa34 { ਲੰਮਾ ਦੁੱਗਣਾ a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

ਬਣਤਰ ਖਾਲੀ_ਥਾਵਾਂ { };
/* Keep the top-level offsets at zero without changing the type into a union. */
ਬਣਤਰ hfae12 { ਬਣਤਰ ਖਾਲੀ_ਥਾਵਾਂ e; ਬਣਤਰ hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
ਬਣਤਰ hfae22 { ਬਣਤਰ ਖਾਲੀ_ਥਾਵਾਂ e; ਬਣਤਰ hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

ਖਾਲੀ fa_s1(ਬਣਤਰ s1 a) { ਲਿਖੋ("%.1s\n", a.x); }
ਖਾਲੀ fa_s2(ਬਣਤਰ s2 a) { ਲਿਖੋ("%.2s\n", a.x); }
ਖਾਲੀ fa_s3(ਬਣਤਰ s3 a) { ਲਿਖੋ("%.3s\n", a.x); }
ਖਾਲੀ fa_s4(ਬਣਤਰ s4 a) { ਲਿਖੋ("%.4s\n", a.x); }
ਖਾਲੀ fa_s5(ਬਣਤਰ s5 a) { ਲਿਖੋ("%.5s\n", a.x); }
ਖਾਲੀ fa_s6(ਬਣਤਰ s6 a) { ਲਿਖੋ("%.6s\n", a.x); }
ਖਾਲੀ fa_s7(ਬਣਤਰ s7 a) { ਲਿਖੋ("%.7s\n", a.x); }
ਖਾਲੀ fa_s8(ਬਣਤਰ s8 a) { ਲਿਖੋ("%.8s\n", a.x); }
ਖਾਲੀ fa_s9(ਬਣਤਰ s9 a) { ਲਿਖੋ("%.9s\n", a.x); }
ਖਾਲੀ fa_s10(ਬਣਤਰ s10 a) { ਲਿਖੋ("%.10s\n", a.x); }
ਖਾਲੀ fa_s11(ਬਣਤਰ s11 a) { ਲਿਖੋ("%.11s\n", a.x); }
ਖਾਲੀ fa_s12(ਬਣਤਰ s12 a) { ਲਿਖੋ("%.12s\n", a.x); }
ਖਾਲੀ fa_s13(ਬਣਤਰ s13 a) { ਲਿਖੋ("%.13s\n", a.x); }
ਖਾਲੀ fa_s14(ਬਣਤਰ s14 a) { ਲਿਖੋ("%.14s\n", a.x); }
ਖਾਲੀ fa_s15(ਬਣਤਰ s15 a) { ਲਿਖੋ("%.15s\n", a.x); }
ਖਾਲੀ fa_s16(ਬਣਤਰ s16 a) { ਲਿਖੋ("%.16s\n", a.x); }
ਖਾਲੀ fa_s17(ਬਣਤਰ s17 a) { ਲਿਖੋ("%.17s\n", a.x); }

ਖਾਲੀ fa_hfa11(ਬਣਤਰ hfa11 a)
{ ਲਿਖੋ("%.1f\n", a.a); }
ਖਾਲੀ fa_hfa12(ਬਣਤਰ hfa12 a)
{ ਲਿਖੋ("%.1f %.1f\n", a.a, a.a); }
ਖਾਲੀ fa_hfa13(ਬਣਤਰ hfa13 a)
{ ਲਿਖੋ("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ਖਾਲੀ fa_hfa14(ਬਣਤਰ hfa14 a)
{ ਲਿਖੋ("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ਖਾਲੀ fa_hfa21(ਬਣਤਰ hfa21 a)
{ ਲਿਖੋ("%.1f\n", a.a); }
ਖਾਲੀ fa_hfa22(ਬਣਤਰ hfa22 a)
{ ਲਿਖੋ("%.1f %.1f\n", a.a, a.a); }
ਖਾਲੀ fa_hfa23(ਬਣਤਰ hfa23 a)
{ ਲਿਖੋ("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ਖਾਲੀ fa_hfa24(ਬਣਤਰ hfa24 a)
{ ਲਿਖੋ("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ਖਾਲੀ fa_hfa31(ਬਣਤਰ hfa31 a)
{ ਲਿਖੋ("%.1Lf\n", a.a); }
ਖਾਲੀ fa_hfa32(ਬਣਤਰ hfa32 a)
{ ਲਿਖੋ("%.1Lf %.1Lf\n", a.a, a.a); }
ਖਾਲੀ fa_hfa33(ਬਣਤਰ hfa33 a)
{ ਲਿਖੋ("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
ਖਾਲੀ fa_hfa34(ਬਣਤਰ hfa34 a)
{ ਲਿਖੋ("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
ਖਾਲੀ fa_hfae12(ਬਣਤਰ hfae12 a)
{ ਲਿਖੋ("%.1f %.1f\n", a.h.a, a.h.b); }
ਖਾਲੀ fa_hfae22(ਬਣਤਰ hfae22 a)
{ ਲਿਖੋ("%.1f %.1f\n", a.h.a, a.h.b); }

ਖਾਲੀ fa1(ਬਣਤਰ s8 a, ਬਣਤਰ s9 b, ਬਣਤਰ s10 c, ਬਣਤਰ s11 d,
         ਬਣਤਰ s12 e, ਬਣਤਰ s13 f)
{
    ਲਿਖੋ("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ਖਾਲੀ fa2(ਬਣਤਰ s9 a, ਬਣਤਰ s10 b, ਬਣਤਰ s11 c, ਬਣਤਰ s12 d,
         ਬਣਤਰ s13 e, ਬਣਤਰ s14 f)
{
    ਲਿਖੋ("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ਖਾਲੀ fa3(ਬਣਤਰ hfa14 a, ਬਣਤਰ hfa23 b, ਬਣਤਰ hfa32 c)
{
    ਲਿਖੋ("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

ਖਾਲੀ fa4(ਬਣਤਰ s1 a, ਬਣਤਰ hfa14 b, ਬਣਤਰ s2 c, ਬਣਤਰ hfa24 d,
         ਬਣਤਰ s3 e, ਬਣਤਰ hfa34 f)
{
    ਲਿਖੋ("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

ਖਾਲੀ arg(ਖਾਲੀ)
{
    ਲਿਖੋ("Arguments:\n");
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

ਬਣਤਰ s1 fr_s1(ਖਾਲੀ) { ਵਾਪਸ s1; }
ਬਣਤਰ s2 fr_s2(ਖਾਲੀ) { ਵਾਪਸ s2; }
ਬਣਤਰ s3 fr_s3(ਖਾਲੀ) { ਵਾਪਸ s3; }
ਬਣਤਰ s4 fr_s4(ਖਾਲੀ) { ਵਾਪਸ s4; }
ਬਣਤਰ s5 fr_s5(ਖਾਲੀ) { ਵਾਪਸ s5; }
ਬਣਤਰ s6 fr_s6(ਖਾਲੀ) { ਵਾਪਸ s6; }
ਬਣਤਰ s7 fr_s7(ਖਾਲੀ) { ਵਾਪਸ s7; }
ਬਣਤਰ s8 fr_s8(ਖਾਲੀ) { ਵਾਪਸ s8; }
ਬਣਤਰ s9 fr_s9(ਖਾਲੀ) { ਵਾਪਸ s9; }
ਬਣਤਰ s10 fr_s10(ਖਾਲੀ) { ਵਾਪਸ s10; }
ਬਣਤਰ s11 fr_s11(ਖਾਲੀ) { ਵਾਪਸ s11; }
ਬਣਤਰ s12 fr_s12(ਖਾਲੀ) { ਵਾਪਸ s12; }
ਬਣਤਰ s13 fr_s13(ਖਾਲੀ) { ਵਾਪਸ s13; }
ਬਣਤਰ s14 fr_s14(ਖਾਲੀ) { ਵਾਪਸ s14; }
ਬਣਤਰ s15 fr_s15(ਖਾਲੀ) { ਵਾਪਸ s15; }
ਬਣਤਰ s16 fr_s16(ਖਾਲੀ) { ਵਾਪਸ s16; }
ਬਣਤਰ s17 fr_s17(ਖਾਲੀ) { ਵਾਪਸ s17; }

ਬਣਤਰ hfa11 fr_hfa11(ਖਾਲੀ) { ਵਾਪਸ hfa11; }
ਬਣਤਰ hfa12 fr_hfa12(ਖਾਲੀ) { ਵਾਪਸ hfa12; }
ਬਣਤਰ hfa13 fr_hfa13(ਖਾਲੀ) { ਵਾਪਸ hfa13; }
ਬਣਤਰ hfa14 fr_hfa14(ਖਾਲੀ) { ਵਾਪਸ hfa14; }

ਬਣਤਰ hfa21 fr_hfa21(ਖਾਲੀ) { ਵਾਪਸ hfa21; }
ਬਣਤਰ hfa22 fr_hfa22(ਖਾਲੀ) { ਵਾਪਸ hfa22; }
ਬਣਤਰ hfa23 fr_hfa23(ਖਾਲੀ) { ਵਾਪਸ hfa23; }
ਬਣਤਰ hfa24 fr_hfa24(ਖਾਲੀ) { ਵਾਪਸ hfa24; }

ਬਣਤਰ hfa31 fr_hfa31(ਖਾਲੀ) { ਵਾਪਸ hfa31; }
ਬਣਤਰ hfa32 fr_hfa32(ਖਾਲੀ) { ਵਾਪਸ hfa32; }
ਬਣਤਰ hfa33 fr_hfa33(ਖਾਲੀ) { ਵਾਪਸ hfa33; }
ਬਣਤਰ hfa34 fr_hfa34(ਖਾਲੀ) { ਵਾਪਸ hfa34; }
ਬਣਤਰ hfae12 fr_hfae12(ਖਾਲੀ) { ਵਾਪਸ hfae12; }
ਬਣਤਰ hfae22 fr_hfae22(ਖਾਲੀ) { ਵਾਪਸ hfae22; }

ਖਾਲੀ ret(ਖਾਲੀ)
{
    ਬਣਤਰ s1 t1 = fr_s1();
    ਬਣਤਰ s2 t2 = fr_s2();
    ਬਣਤਰ s3 t3 = fr_s3();
    ਬਣਤਰ s4 t4 = fr_s4();
    ਬਣਤਰ s5 t5 = fr_s5();
    ਬਣਤਰ s6 t6 = fr_s6();
    ਬਣਤਰ s7 t7 = fr_s7();
    ਬਣਤਰ s8 t8 = fr_s8();
    ਬਣਤਰ s9 t9 = fr_s9();
    ਬਣਤਰ s10 t10 = fr_s10();
    ਬਣਤਰ s11 t11 = fr_s11();
    ਬਣਤਰ s12 t12 = fr_s12();
    ਬਣਤਰ s13 t13 = fr_s13();
    ਬਣਤਰ s14 t14 = fr_s14();
    ਬਣਤਰ s15 t15 = fr_s15();
    ਬਣਤਰ s16 t16 = fr_s16();
    ਬਣਤਰ s17 t17 = fr_s17();
    ਲਿਖੋ("Return values:\n");
    ਲਿਖੋ("%.1s\n", t1.x);
    ਲਿਖੋ("%.2s\n", t2.x);
    ਲਿਖੋ("%.3s\n", t3.x);
    ਲਿਖੋ("%.4s\n", t4.x);
    ਲਿਖੋ("%.5s\n", t5.x);
    ਲਿਖੋ("%.6s\n", t6.x);
    ਲਿਖੋ("%.7s\n", t7.x);
    ਲਿਖੋ("%.8s\n", t8.x);
    ਲਿਖੋ("%.9s\n", t9.x);
    ਲਿਖੋ("%.10s\n", t10.x);
    ਲਿਖੋ("%.11s\n", t11.x);
    ਲਿਖੋ("%.12s\n", t12.x);
    ਲਿਖੋ("%.13s\n", t13.x);
    ਲਿਖੋ("%.14s\n", t14.x);
    ਲਿਖੋ("%.15s\n", t15.x);
    ਲਿਖੋ("%.16s\n", t16.x);
    ਲਿਖੋ("%.17s\n", t17.x);
    ਲਿਖੋ("%.1f\n", fr_hfa11().a);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfa12().a, fr_hfa12().b);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfa13().a, fr_hfa13().c);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfa14().a, fr_hfa14().d);
    ਲਿਖੋ("%.1f\n", fr_hfa21().a);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfa22().a, fr_hfa22().b);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfa23().a, fr_hfa23().c);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfa24().a, fr_hfa24().d);
    ਲਿਖੋ("%.1Lf\n", fr_hfa31().a);
    ਲਿਖੋ("%.1Lf %.1Lf\n", fr_hfa32().a, fr_hfa32().b);
    ਲਿਖੋ("%.1Lf %.1Lf\n", fr_hfa33().a, fr_hfa33().c);
    ਲਿਖੋ("%.1Lf %.1Lf\n", fr_hfa34().a, fr_hfa34().d);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfae12().h.a, fr_hfae12().h.b);
    ਲਿਖੋ("%.1f %.1f\n", fr_hfae22().h.a, fr_hfae22().h.b);
}

ਖਾਲੀ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        ਬਣਤਰ X { ਪੂਰਨ _x; };
        ਬਣਤਰ X *x = va_arg(ap, ਬਣਤਰ X *);
        ਵਾਪਸ x;
}

ਪੂਰਨ ਮੇਲ(ਅਚਲ ਅੱਖਰ **s, ਅਚਲ ਅੱਖਰ *f)
{
    ਅਚਲ ਅੱਖਰ *p = *s;
    ਲਈ (p = *s; *f && *f == *p; f++, p++)
        ;
    ਜੇ (!*f) {
        *s = p - 1;
        ਵਾਪਸ 1;
    }
    ਵਾਪਸ 0;
}

ਖਾਲੀ myprintf(ਅਚਲ ਅੱਖਰ *format, ...)
{
    ਅਚਲ ਅੱਖਰ *s;
    va_list ap;
    va_start(ap, format);
    ਲਈ (s = format; *s; s++) {
        ਜੇ (ਮੇਲ(&s, "%7s")) {
            ਬਣਤਰ s7 t7 = va_arg(ap, ਬਣਤਰ s7);
            ਲਿਖੋ("%.7s", t7.x);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%9s")) {
            ਬਣਤਰ s9 t9 = va_arg(ap, ਬਣਤਰ s9);
            ਲਿਖੋ("%.9s", t9.x);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa11")) {
            ਬਣਤਰ hfa11 x = va_arg(ap, ਬਣਤਰ hfa11);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.a);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa12")) {
            ਬਣਤਰ hfa12 x = va_arg(ap, ਬਣਤਰ hfa12);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.b);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa13")) {
            ਬਣਤਰ hfa13 x = va_arg(ap, ਬਣਤਰ hfa13);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.c);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa14")) {
            ਬਣਤਰ hfa14 x = va_arg(ap, ਬਣਤਰ hfa14);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.d);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa21")) {
            ਬਣਤਰ hfa21 x = va_arg(ap, ਬਣਤਰ hfa21);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.a);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa22")) {
            ਬਣਤਰ hfa22 x = va_arg(ap, ਬਣਤਰ hfa22);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.b);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa23")) {
            ਬਣਤਰ hfa23 x = va_arg(ap, ਬਣਤਰ hfa23);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.c);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa24")) {
            ਬਣਤਰ hfa24 x = va_arg(ap, ਬਣਤਰ hfa24);
            ਲਿਖੋ("%.1f,%.1f", x.a, x.d);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa31")) {
            ਬਣਤਰ hfa31 x = va_arg(ap, ਬਣਤਰ hfa31);
            ਲਿਖੋ("%.1Lf,%.1Lf", x.a, x.a);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa32")) {
            ਬਣਤਰ hfa32 x = va_arg(ap, ਬਣਤਰ hfa32);
            ਲਿਖੋ("%.1Lf,%.1Lf", x.a, x.b);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa33")) {
            ਬਣਤਰ hfa33 x = va_arg(ap, ਬਣਤਰ hfa33);
            ਲਿਖੋ("%.1Lf,%.1Lf", x.a, x.c);
        }
        ਨਹੀਂਤਾਂ ਜੇ (ਮੇਲ(&s, "%hfa34")) {
            ਬਣਤਰ hfa34 x = va_arg(ap, ਬਣਤਰ hfa34);
            ਲਿਖੋ("%.1Lf,%.1Lf", x.a, x.d);
        }
        ਨਹੀਂਤਾਂ
            ਅੱਖਰ_ਲਿਖੋ(*s);
    }
    ਅੱਖਰ_ਲਿਖੋ('\n');
}

ਖਾਲੀ stdarg(ਖਾਲੀ)
{
    ਲਿਖੋ("stdarg:\n");
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

ਖਾਲੀ pll(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x)
{
    ਲਿਖੋ("%llx\n", x);
}

ਖਾਲੀ movi(ਖਾਲੀ)
{
    ਲਿਖੋ("MOVI:\n");
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

ਸਥਿਰ uint32_t addip0(uint32_t x) { ਵਾਪਸ x + 0; }
ਸਥਿਰ uint64_t sublp0(uint64_t x) { ਵਾਪਸ x - 0; }
ਸਥਿਰ uint32_t addip123(uint32_t x) { ਵਾਪਸ x + 123; }
ਸਥਿਰ uint64_t addlm123(uint64_t x) { ਵਾਪਸ x + -123; }
ਸਥਿਰ uint64_t sublp4095(uint64_t x) { ਵਾਪਸ x - 4095; }
ਸਥਿਰ uint32_t subim503808(uint32_t x) { ਵਾਪਸ x - -503808; }
ਸਥਿਰ uint64_t addp12345(uint64_t x) { ਵਾਪਸ x + 12345; }
ਸਥਿਰ uint32_t subp12345(uint32_t x) { ਵਾਪਸ x - 12345; }

ਸਥਿਰ uint32_t mvni(uint32_t x) { ਵਾਪਸ 0xffffffff - x; }
ਸਥਿਰ uint64_t negl(uint64_t x) { ਵਾਪਸ 0 - x; }
ਸਥਿਰ uint32_t rsbi123(uint32_t x) { ਵਾਪਸ 123 - x; }
ਸਥਿਰ uint64_t rsbl123(uint64_t x) { ਵਾਪਸ 123 - x; }

ਸਥਿਰ uint32_t andi0(uint32_t x) { ਵਾਪਸ x & 0; }
ਸਥਿਰ uint64_t andlm1(uint64_t x) { ਵਾਪਸ x & -1; }
ਸਥਿਰ uint64_t orrl0(uint64_t x) { ਵਾਪਸ x | 0; }
ਸਥਿਰ uint32_t orrim1(uint32_t x) { ਵਾਪਸ x | -1; }
ਸਥਿਰ uint32_t eori0(uint32_t x) { ਵਾਪਸ x ^ 0; }
ਸਥਿਰ uint64_t eorlm1(uint64_t x) { ਵਾਪਸ x ^ -1; }
ਸਥਿਰ uint32_t and0xf0(uint32_t x) { ਵਾਪਸ x & 0xf0; }
ਸਥਿਰ uint64_t orr0xf0(uint64_t x) { ਵਾਪਸ x | 0xf0; }
ਸਥਿਰ uint64_t eor0xf0(uint64_t x) { ਵਾਪਸ x ^ 0xf0; }

ਸਥਿਰ uint32_t lsli0(uint32_t x) { ਵਾਪਸ x << 0; }
ਸਥਿਰ uint32_t lsri0(uint32_t x) { ਵਾਪਸ x >> 0; }
ਸਥਿਰ int64_t asrl0(int64_t x) { ਵਾਪਸ x >> 0; }
ਸਥਿਰ uint32_t lsli1(uint32_t x) { ਵਾਪਸ x << 1; }
ਸਥਿਰ uint32_t lsli31(uint32_t x) { ਵਾਪਸ x << 31; }
ਸਥਿਰ uint64_t lsll1(uint64_t x) { ਵਾਪਸ x << 1; }
ਸਥਿਰ uint64_t lsll63(uint64_t x) { ਵਾਪਸ x << 63; }
ਸਥਿਰ uint32_t lsri1(uint32_t x) { ਵਾਪਸ x >> 1; }
ਸਥਿਰ uint32_t lsri31(uint32_t x) { ਵਾਪਸ x >> 31; }
ਸਥਿਰ uint64_t lsrl1(uint64_t x) { ਵਾਪਸ x >> 1; }
ਸਥਿਰ uint64_t lsrl63(uint64_t x) { ਵਾਪਸ x >> 63; }
ਸਥਿਰ int32_t asri1(int32_t x) { ਵਾਪਸ x >> 1; }
ਸਥਿਰ int32_t asri31(int32_t x) { ਵਾਪਸ x >> 31; }
ਸਥਿਰ int64_t asrl1(int64_t x) { ਵਾਪਸ x >> 1; }
ਸਥਿਰ int64_t asrl63(int64_t x) { ਵਾਪਸ x >> 63; }

ਖਾਲੀ opi(ਖਾਲੀ)
{
    ਪੂਰਨ x = 1000;
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

ਖਾਲੀ pcs(ਖਾਲੀ)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

ਪੂਰਨ ਮੁੱਖ()
{
    pcs();
    ਵਾਪਸ 0;
}
