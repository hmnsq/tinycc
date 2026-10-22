// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#ضمن <stdarg.h>
#ضمن <stdint.h>
#ضمن <stdio.h>

بنية s1 { حرف x[1]; } s1 = { "0" };
بنية s2 { حرف x[2]; } s2 = { "12" };
بنية s3 { حرف x[3]; } s3 = { "345" };
بنية s4 { حرف x[4]; } s4 = { "6789" };
بنية s5 { حرف x[5]; } s5 = { "abcde" };
بنية s6 { حرف x[6]; } s6 = { "fghijk" };
بنية s7 { حرف x[7]; } s7 = { "lmnopqr" };
بنية s8 { حرف x[8]; } s8 = { "stuvwxyz" };
بنية s9 { حرف x[9]; } s9 = { "ABCDEFGHI" };
بنية s10 { حرف x[10]; } s10 = { "JKLMNOPQRS" };
بنية s11 { حرف x[11]; } s11 = { "TUVWXYZ0123" };
بنية s12 { حرف x[12]; } s12 = { "456789abcdef" };
بنية s13 { حرف x[13]; } s13 = { "ghijklmnopqrs" };
بنية s14 { حرف x[14]; } s14 = { "tuvwxyzABCDEFG" };
بنية s15 { حرف x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
بنية s16 { حرف x[16]; } s16 = { "WXYZ0123456789ab" };
بنية s17 { حرف x[17]; } s17 = { "cdefghijklmnopqrs" };

بنية hfa11 { عائم a; } hfa11 = { 11.1 };
بنية hfa12 { عائم a, b; } hfa12 = { 12.1, 12.2 };
بنية hfa13 { عائم a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
بنية hfa14 { عائم a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

بنية hfa21 { مزدوج a; } hfa21 = { 21.1 };
بنية hfa22 { مزدوج a, b; } hfa22 = { 22.1, 22.2 };
بنية hfa23 { مزدوج a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
بنية hfa24 { مزدوج a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

بنية hfa31 { long مزدوج a; } hfa31 = { 31.1 };
بنية hfa32 { long مزدوج a, b; } hfa32 = { 32.1, 32.2 };
بنية hfa33 { long مزدوج a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
بنية hfa34 { long مزدوج a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

بنية empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
بنية hfae12 { بنية empty e; بنية hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
بنية hfae22 { بنية empty e; بنية hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

فراغ fa_s1(بنية s1 a) { printf("%.1s\n", a.x); }
فراغ fa_s2(بنية s2 a) { printf("%.2s\n", a.x); }
فراغ fa_s3(بنية s3 a) { printf("%.3s\n", a.x); }
فراغ fa_s4(بنية s4 a) { printf("%.4s\n", a.x); }
فراغ fa_s5(بنية s5 a) { printf("%.5s\n", a.x); }
فراغ fa_s6(بنية s6 a) { printf("%.6s\n", a.x); }
فراغ fa_s7(بنية s7 a) { printf("%.7s\n", a.x); }
فراغ fa_s8(بنية s8 a) { printf("%.8s\n", a.x); }
فراغ fa_s9(بنية s9 a) { printf("%.9s\n", a.x); }
فراغ fa_s10(بنية s10 a) { printf("%.10s\n", a.x); }
فراغ fa_s11(بنية s11 a) { printf("%.11s\n", a.x); }
فراغ fa_s12(بنية s12 a) { printf("%.12s\n", a.x); }
فراغ fa_s13(بنية s13 a) { printf("%.13s\n", a.x); }
فراغ fa_s14(بنية s14 a) { printf("%.14s\n", a.x); }
فراغ fa_s15(بنية s15 a) { printf("%.15s\n", a.x); }
فراغ fa_s16(بنية s16 a) { printf("%.16s\n", a.x); }
فراغ fa_s17(بنية s17 a) { printf("%.17s\n", a.x); }

فراغ fa_hfa11(بنية hfa11 a)
{ printf("%.1f\n", a.a); }
فراغ fa_hfa12(بنية hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
فراغ fa_hfa13(بنية hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
فراغ fa_hfa14(بنية hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

فراغ fa_hfa21(بنية hfa21 a)
{ printf("%.1f\n", a.a); }
فراغ fa_hfa22(بنية hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
فراغ fa_hfa23(بنية hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
فراغ fa_hfa24(بنية hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

فراغ fa_hfa31(بنية hfa31 a)
{ printf("%.1Lf\n", a.a); }
فراغ fa_hfa32(بنية hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
فراغ fa_hfa33(بنية hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
فراغ fa_hfa34(بنية hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
فراغ fa_hfae12(بنية hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
فراغ fa_hfae22(بنية hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

فراغ fa1(بنية s8 a, بنية s9 b, بنية s10 c, بنية s11 d,
         بنية s12 e, بنية s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

فراغ fa2(بنية s9 a, بنية s10 b, بنية s11 c, بنية s12 d,
         بنية s13 e, بنية s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

فراغ fa3(بنية hfa14 a, بنية hfa23 b, بنية hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

فراغ fa4(بنية s1 a, بنية hfa14 b, بنية s2 c, بنية hfa24 d,
         بنية s3 e, بنية hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

فراغ arg(فراغ)
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

بنية s1 fr_s1(فراغ) { أرجع s1; }
بنية s2 fr_s2(فراغ) { أرجع s2; }
بنية s3 fr_s3(فراغ) { أرجع s3; }
بنية s4 fr_s4(فراغ) { أرجع s4; }
بنية s5 fr_s5(فراغ) { أرجع s5; }
بنية s6 fr_s6(فراغ) { أرجع s6; }
بنية s7 fr_s7(فراغ) { أرجع s7; }
بنية s8 fr_s8(فراغ) { أرجع s8; }
بنية s9 fr_s9(فراغ) { أرجع s9; }
بنية s10 fr_s10(فراغ) { أرجع s10; }
بنية s11 fr_s11(فراغ) { أرجع s11; }
بنية s12 fr_s12(فراغ) { أرجع s12; }
بنية s13 fr_s13(فراغ) { أرجع s13; }
بنية s14 fr_s14(فراغ) { أرجع s14; }
بنية s15 fr_s15(فراغ) { أرجع s15; }
بنية s16 fr_s16(فراغ) { أرجع s16; }
بنية s17 fr_s17(فراغ) { أرجع s17; }

بنية hfa11 fr_hfa11(فراغ) { أرجع hfa11; }
بنية hfa12 fr_hfa12(فراغ) { أرجع hfa12; }
بنية hfa13 fr_hfa13(فراغ) { أرجع hfa13; }
بنية hfa14 fr_hfa14(فراغ) { أرجع hfa14; }

بنية hfa21 fr_hfa21(فراغ) { أرجع hfa21; }
بنية hfa22 fr_hfa22(فراغ) { أرجع hfa22; }
بنية hfa23 fr_hfa23(فراغ) { أرجع hfa23; }
بنية hfa24 fr_hfa24(فراغ) { أرجع hfa24; }

بنية hfa31 fr_hfa31(فراغ) { أرجع hfa31; }
بنية hfa32 fr_hfa32(فراغ) { أرجع hfa32; }
بنية hfa33 fr_hfa33(فراغ) { أرجع hfa33; }
بنية hfa34 fr_hfa34(فراغ) { أرجع hfa34; }
بنية hfae12 fr_hfae12(فراغ) { أرجع hfae12; }
بنية hfae22 fr_hfae22(فراغ) { أرجع hfae22; }

فراغ ret(فراغ)
{
    بنية s1 t1 = fr_s1();
    بنية s2 t2 = fr_s2();
    بنية s3 t3 = fr_s3();
    بنية s4 t4 = fr_s4();
    بنية s5 t5 = fr_s5();
    بنية s6 t6 = fr_s6();
    بنية s7 t7 = fr_s7();
    بنية s8 t8 = fr_s8();
    بنية s9 t9 = fr_s9();
    بنية s10 t10 = fr_s10();
    بنية s11 t11 = fr_s11();
    بنية s12 t12 = fr_s12();
    بنية s13 t13 = fr_s13();
    بنية s14 t14 = fr_s14();
    بنية s15 t15 = fr_s15();
    بنية s16 t16 = fr_s16();
    بنية s17 t17 = fr_s17();
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

فراغ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        بنية X { صحيح _x; };
        بنية X *x = va_arg(ap, بنية X *);
        أرجع x;
}

صحيح match(ثابت حرف **s, ثابت حرف *f)
{
    ثابت حرف *p = *s;
    لكل (p = *s; *f && *f == *p; f++, p++)
        ;
    𐡄𐡍 (!*f) {
        *s = p - 1;
        أرجع 1;
    }
    أرجع 0;
}

فراغ myprintf(ثابت حرف *format, ...)
{
    ثابت حرف *s;
    va_list ap;
    va_start(ap, format);
    لكل (s = format; *s; s++) {
        𐡄𐡍 (match(&s, "%7s")) {
            بنية s7 t7 = va_arg(ap, بنية s7);
            printf("%.7s", t7.x);
        }
        وإلا 𐡄𐡍 (match(&s, "%9s")) {
            بنية s9 t9 = va_arg(ap, بنية s9);
            printf("%.9s", t9.x);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa11")) {
            بنية hfa11 x = va_arg(ap, بنية hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa12")) {
            بنية hfa12 x = va_arg(ap, بنية hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa13")) {
            بنية hfa13 x = va_arg(ap, بنية hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa14")) {
            بنية hfa14 x = va_arg(ap, بنية hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa21")) {
            بنية hfa21 x = va_arg(ap, بنية hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa22")) {
            بنية hfa22 x = va_arg(ap, بنية hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa23")) {
            بنية hfa23 x = va_arg(ap, بنية hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa24")) {
            بنية hfa24 x = va_arg(ap, بنية hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa31")) {
            بنية hfa31 x = va_arg(ap, بنية hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa32")) {
            بنية hfa32 x = va_arg(ap, بنية hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa33")) {
            بنية hfa33 x = va_arg(ap, بنية hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        وإلا 𐡄𐡍 (match(&s, "%hfa34")) {
            بنية hfa34 x = va_arg(ap, بنية hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        وإلا
            putchar(*s);
    }
    putchar('\n');
}

فراغ stdarg(فراغ)
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

فراغ pll(unsigned long long x)
{
    printf("%llx\n", x);
}

فراغ movi(فراغ)
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

ساكن uint32_t addip0(uint32_t x) { أرجع x + 0; }
ساكن uint64_t sublp0(uint64_t x) { أرجع x - 0; }
ساكن uint32_t addip123(uint32_t x) { أرجع x + 123; }
ساكن uint64_t addlm123(uint64_t x) { أرجع x + -123; }
ساكن uint64_t sublp4095(uint64_t x) { أرجع x - 4095; }
ساكن uint32_t subim503808(uint32_t x) { أرجع x - -503808; }
ساكن uint64_t addp12345(uint64_t x) { أرجع x + 12345; }
ساكن uint32_t subp12345(uint32_t x) { أرجع x - 12345; }

ساكن uint32_t mvni(uint32_t x) { أرجع 0xffffffff - x; }
ساكن uint64_t negl(uint64_t x) { أرجع 0 - x; }
ساكن uint32_t rsbi123(uint32_t x) { أرجع 123 - x; }
ساكن uint64_t rsbl123(uint64_t x) { أرجع 123 - x; }

ساكن uint32_t andi0(uint32_t x) { أرجع x & 0; }
ساكن uint64_t andlm1(uint64_t x) { أرجع x & -1; }
ساكن uint64_t orrl0(uint64_t x) { أرجع x | 0; }
ساكن uint32_t orrim1(uint32_t x) { أرجع x | -1; }
ساكن uint32_t eori0(uint32_t x) { أرجع x ^ 0; }
ساكن uint64_t eorlm1(uint64_t x) { أرجع x ^ -1; }
ساكن uint32_t and0xf0(uint32_t x) { أرجع x & 0xf0; }
ساكن uint64_t orr0xf0(uint64_t x) { أرجع x | 0xf0; }
ساكن uint64_t eor0xf0(uint64_t x) { أرجع x ^ 0xf0; }

ساكن uint32_t lsli0(uint32_t x) { أرجع x << 0; }
ساكن uint32_t lsri0(uint32_t x) { أرجع x >> 0; }
ساكن int64_t asrl0(int64_t x) { أرجع x >> 0; }
ساكن uint32_t lsli1(uint32_t x) { أرجع x << 1; }
ساكن uint32_t lsli31(uint32_t x) { أرجع x << 31; }
ساكن uint64_t lsll1(uint64_t x) { أرجع x << 1; }
ساكن uint64_t lsll63(uint64_t x) { أرجع x << 63; }
ساكن uint32_t lsri1(uint32_t x) { أرجع x >> 1; }
ساكن uint32_t lsri31(uint32_t x) { أرجع x >> 31; }
ساكن uint64_t lsrl1(uint64_t x) { أرجع x >> 1; }
ساكن uint64_t lsrl63(uint64_t x) { أرجع x >> 63; }
ساكن int32_t asri1(int32_t x) { أرجع x >> 1; }
ساكن int32_t asri31(int32_t x) { أرجع x >> 31; }
ساكن int64_t asrl1(int64_t x) { أرجع x >> 1; }
ساكن int64_t asrl63(int64_t x) { أرجع x >> 63; }

فراغ opi(فراغ)
{
    صحيح x = 1000;
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

فراغ pcs(فراغ)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

صحيح main()
{
    pcs();
    أرجع 0;
}
