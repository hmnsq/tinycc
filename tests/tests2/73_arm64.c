// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#അന്തര്ഭാവ <stdarg.h>
#അന്തര്ഭാവ <stdint.h>
#അന്തര്ഭാവ <stdio.h>

ഘടന s1 { അക്ഷരം x[1]; } s1 = { "0" };
ഘടന s2 { അക്ഷരം x[2]; } s2 = { "12" };
ഘടന s3 { അക്ഷരം x[3]; } s3 = { "345" };
ഘടന s4 { അക്ഷരം x[4]; } s4 = { "6789" };
ഘടന s5 { അക്ഷരം x[5]; } s5 = { "abcde" };
ഘടന s6 { അക്ഷരം x[6]; } s6 = { "fghijk" };
ഘടന s7 { അക്ഷരം x[7]; } s7 = { "lmnopqr" };
ഘടന s8 { അക്ഷരം x[8]; } s8 = { "stuvwxyz" };
ഘടന s9 { അക്ഷരം x[9]; } s9 = { "ABCDEFGHI" };
ഘടന s10 { അക്ഷരം x[10]; } s10 = { "JKLMNOPQRS" };
ഘടന s11 { അക്ഷരം x[11]; } s11 = { "TUVWXYZ0123" };
ഘടന s12 { അക്ഷരം x[12]; } s12 = { "456789abcdef" };
ഘടന s13 { അക്ഷരം x[13]; } s13 = { "ghijklmnopqrs" };
ഘടന s14 { അക്ഷരം x[14]; } s14 = { "tuvwxyzABCDEFG" };
ഘടന s15 { അക്ഷരം x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
ഘടന s16 { അക്ഷരം x[16]; } s16 = { "WXYZ0123456789ab" };
ഘടന s17 { അക്ഷരം x[17]; } s17 = { "cdefghijklmnopqrs" };

ഘടന hfa11 { ദശാംശം a; } hfa11 = { 11.1 };
ഘടന hfa12 { ദശാംശം a, b; } hfa12 = { 12.1, 12.2 };
ഘടന hfa13 { ദശാംശം a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
ഘടന hfa14 { ദശാംശം a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

ഘടന hfa21 { ഇരട്ട a; } hfa21 = { 21.1 };
ഘടന hfa22 { ഇരട്ട a, b; } hfa22 = { 22.1, 22.2 };
ഘടന hfa23 { ഇരട്ട a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
ഘടന hfa24 { ഇരട്ട a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

ഘടന hfa31 { long ഇരട്ട a; } hfa31 = { 31.1 };
ഘടന hfa32 { long ഇരട്ട a, b; } hfa32 = { 32.1, 32.2 };
ഘടന hfa33 { long ഇരട്ട a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
ഘടന hfa34 { long ഇരട്ട a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

ഘടന empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
ഘടന hfae12 { ഘടന empty e; ഘടന hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
ഘടന hfae22 { ഘടന empty e; ഘടന hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

ശൂന്യം fa_s1(ഘടന s1 a) { printf("%.1s\n", a.x); }
ശൂന്യം fa_s2(ഘടന s2 a) { printf("%.2s\n", a.x); }
ശൂന്യം fa_s3(ഘടന s3 a) { printf("%.3s\n", a.x); }
ശൂന്യം fa_s4(ഘടന s4 a) { printf("%.4s\n", a.x); }
ശൂന്യം fa_s5(ഘടന s5 a) { printf("%.5s\n", a.x); }
ശൂന്യം fa_s6(ഘടന s6 a) { printf("%.6s\n", a.x); }
ശൂന്യം fa_s7(ഘടന s7 a) { printf("%.7s\n", a.x); }
ശൂന്യം fa_s8(ഘടന s8 a) { printf("%.8s\n", a.x); }
ശൂന്യം fa_s9(ഘടന s9 a) { printf("%.9s\n", a.x); }
ശൂന്യം fa_s10(ഘടന s10 a) { printf("%.10s\n", a.x); }
ശൂന്യം fa_s11(ഘടന s11 a) { printf("%.11s\n", a.x); }
ശൂന്യം fa_s12(ഘടന s12 a) { printf("%.12s\n", a.x); }
ശൂന്യം fa_s13(ഘടന s13 a) { printf("%.13s\n", a.x); }
ശൂന്യം fa_s14(ഘടന s14 a) { printf("%.14s\n", a.x); }
ശൂന്യം fa_s15(ഘടന s15 a) { printf("%.15s\n", a.x); }
ശൂന്യം fa_s16(ഘടന s16 a) { printf("%.16s\n", a.x); }
ശൂന്യം fa_s17(ഘടന s17 a) { printf("%.17s\n", a.x); }

ശൂന്യം fa_hfa11(ഘടന hfa11 a)
{ printf("%.1f\n", a.a); }
ശൂന്യം fa_hfa12(ഘടന hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
ശൂന്യം fa_hfa13(ഘടന hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ശൂന്യം fa_hfa14(ഘടന hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ശൂന്യം fa_hfa21(ഘടന hfa21 a)
{ printf("%.1f\n", a.a); }
ശൂന്യം fa_hfa22(ഘടന hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
ശൂന്യം fa_hfa23(ഘടന hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
ശൂന്യം fa_hfa24(ഘടന hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

ശൂന്യം fa_hfa31(ഘടന hfa31 a)
{ printf("%.1Lf\n", a.a); }
ശൂന്യം fa_hfa32(ഘടന hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
ശൂന്യം fa_hfa33(ഘടന hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
ശൂന്യം fa_hfa34(ഘടന hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
ശൂന്യം fa_hfae12(ഘടന hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
ശൂന്യം fa_hfae22(ഘടന hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

ശൂന്യം fa1(ഘടന s8 a, ഘടന s9 b, ഘടന s10 c, ഘടന s11 d,
         ഘടന s12 e, ഘടന s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ശൂന്യം fa2(ഘടന s9 a, ഘടന s10 b, ഘടന s11 c, ഘടന s12 d,
         ഘടന s13 e, ഘടന s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

ശൂന്യം fa3(ഘടന hfa14 a, ഘടന hfa23 b, ഘടന hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

ശൂന്യം fa4(ഘടന s1 a, ഘടന hfa14 b, ഘടന s2 c, ഘടന hfa24 d,
         ഘടന s3 e, ഘടന hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

ശൂന്യം arg(ശൂന്യം)
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

ഘടന s1 fr_s1(ശൂന്യം) { തിരികെ s1; }
ഘടന s2 fr_s2(ശൂന്യം) { തിരികെ s2; }
ഘടന s3 fr_s3(ശൂന്യം) { തിരികെ s3; }
ഘടന s4 fr_s4(ശൂന്യം) { തിരികെ s4; }
ഘടന s5 fr_s5(ശൂന്യം) { തിരികെ s5; }
ഘടന s6 fr_s6(ശൂന്യം) { തിരികെ s6; }
ഘടന s7 fr_s7(ശൂന്യം) { തിരികെ s7; }
ഘടന s8 fr_s8(ശൂന്യം) { തിരികെ s8; }
ഘടന s9 fr_s9(ശൂന്യം) { തിരികെ s9; }
ഘടന s10 fr_s10(ശൂന്യം) { തിരികെ s10; }
ഘടന s11 fr_s11(ശൂന്യം) { തിരികെ s11; }
ഘടന s12 fr_s12(ശൂന്യം) { തിരികെ s12; }
ഘടന s13 fr_s13(ശൂന്യം) { തിരികെ s13; }
ഘടന s14 fr_s14(ശൂന്യം) { തിരികെ s14; }
ഘടന s15 fr_s15(ശൂന്യം) { തിരികെ s15; }
ഘടന s16 fr_s16(ശൂന്യം) { തിരികെ s16; }
ഘടന s17 fr_s17(ശൂന്യം) { തിരികെ s17; }

ഘടന hfa11 fr_hfa11(ശൂന്യം) { തിരികെ hfa11; }
ഘടന hfa12 fr_hfa12(ശൂന്യം) { തിരികെ hfa12; }
ഘടന hfa13 fr_hfa13(ശൂന്യം) { തിരികെ hfa13; }
ഘടന hfa14 fr_hfa14(ശൂന്യം) { തിരികെ hfa14; }

ഘടന hfa21 fr_hfa21(ശൂന്യം) { തിരികെ hfa21; }
ഘടന hfa22 fr_hfa22(ശൂന്യം) { തിരികെ hfa22; }
ഘടന hfa23 fr_hfa23(ശൂന്യം) { തിരികെ hfa23; }
ഘടന hfa24 fr_hfa24(ശൂന്യം) { തിരികെ hfa24; }

ഘടന hfa31 fr_hfa31(ശൂന്യം) { തിരികെ hfa31; }
ഘടന hfa32 fr_hfa32(ശൂന്യം) { തിരികെ hfa32; }
ഘടന hfa33 fr_hfa33(ശൂന്യം) { തിരികെ hfa33; }
ഘടന hfa34 fr_hfa34(ശൂന്യം) { തിരികെ hfa34; }
ഘടന hfae12 fr_hfae12(ശൂന്യം) { തിരികെ hfae12; }
ഘടന hfae22 fr_hfae22(ശൂന്യം) { തിരികെ hfae22; }

ശൂന്യം ret(ശൂന്യം)
{
    ഘടന s1 t1 = fr_s1();
    ഘടന s2 t2 = fr_s2();
    ഘടന s3 t3 = fr_s3();
    ഘടന s4 t4 = fr_s4();
    ഘടന s5 t5 = fr_s5();
    ഘടന s6 t6 = fr_s6();
    ഘടന s7 t7 = fr_s7();
    ഘടന s8 t8 = fr_s8();
    ഘടന s9 t9 = fr_s9();
    ഘടന s10 t10 = fr_s10();
    ഘടന s11 t11 = fr_s11();
    ഘടന s12 t12 = fr_s12();
    ഘടന s13 t13 = fr_s13();
    ഘടന s14 t14 = fr_s14();
    ഘടന s15 t15 = fr_s15();
    ഘടന s16 t16 = fr_s16();
    ഘടന s17 t17 = fr_s17();
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

ശൂന്യം*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        ഘടന X { പൂർണ്ണസംഖ്യ _x; };
        ഘടന X *x = va_arg(ap, ഘടന X *);
        തിരികെ x;
}

പൂർണ്ണസംഖ്യ match(സ്ഥിരം അക്ഷരം **s, സ്ഥിരം അക്ഷരം *f)
{
    സ്ഥിരം അക്ഷരം *p = *s;
    വേണ്ടി (p = *s; *f && *f == *p; f++, p++)
        ;
    എങ്കിൽ (!*f) {
        *s = p - 1;
        തിരികെ 1;
    }
    തിരികെ 0;
}

ശൂന്യം myprintf(സ്ഥിരം അക്ഷരം *format, ...)
{
    സ്ഥിരം അക്ഷരം *s;
    va_list ap;
    va_start(ap, format);
    വേണ്ടി (s = format; *s; s++) {
        എങ്കിൽ (match(&s, "%7s")) {
            ഘടന s7 t7 = va_arg(ap, ഘടന s7);
            printf("%.7s", t7.x);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%9s")) {
            ഘടന s9 t9 = va_arg(ap, ഘടന s9);
            printf("%.9s", t9.x);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa11")) {
            ഘടന hfa11 x = va_arg(ap, ഘടന hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa12")) {
            ഘടന hfa12 x = va_arg(ap, ഘടന hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa13")) {
            ഘടന hfa13 x = va_arg(ap, ഘടന hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa14")) {
            ഘടന hfa14 x = va_arg(ap, ഘടന hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa21")) {
            ഘടന hfa21 x = va_arg(ap, ഘടന hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa22")) {
            ഘടന hfa22 x = va_arg(ap, ഘടന hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa23")) {
            ഘടന hfa23 x = va_arg(ap, ഘടന hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa24")) {
            ഘടന hfa24 x = va_arg(ap, ഘടന hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa31")) {
            ഘടന hfa31 x = va_arg(ap, ഘടന hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa32")) {
            ഘടന hfa32 x = va_arg(ap, ഘടന hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa33")) {
            ഘടന hfa33 x = va_arg(ap, ഘടന hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        അല്ലെങ്കിൽ എങ്കിൽ (match(&s, "%hfa34")) {
            ഘടന hfa34 x = va_arg(ap, ഘടന hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        അല്ലെങ്കിൽ
            putchar(*s);
    }
    putchar('\n');
}

ശൂന്യം stdarg(ശൂന്യം)
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

ശൂന്യം pll(unsigned long long x)
{
    printf("%llx\n", x);
}

ശൂന്യം movi(ശൂന്യം)
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

സ്ഥിതം uint32_t addip0(uint32_t x) { തിരികെ x + 0; }
സ്ഥിതം uint64_t sublp0(uint64_t x) { തിരികെ x - 0; }
സ്ഥിതം uint32_t addip123(uint32_t x) { തിരികെ x + 123; }
സ്ഥിതം uint64_t addlm123(uint64_t x) { തിരികെ x + -123; }
സ്ഥിതം uint64_t sublp4095(uint64_t x) { തിരികെ x - 4095; }
സ്ഥിതം uint32_t subim503808(uint32_t x) { തിരികെ x - -503808; }
സ്ഥിതം uint64_t addp12345(uint64_t x) { തിരികെ x + 12345; }
സ്ഥിതം uint32_t subp12345(uint32_t x) { തിരികെ x - 12345; }

സ്ഥിതം uint32_t mvni(uint32_t x) { തിരികെ 0xffffffff - x; }
സ്ഥിതം uint64_t negl(uint64_t x) { തിരികെ 0 - x; }
സ്ഥിതം uint32_t rsbi123(uint32_t x) { തിരികെ 123 - x; }
സ്ഥിതം uint64_t rsbl123(uint64_t x) { തിരികെ 123 - x; }

സ്ഥിതം uint32_t andi0(uint32_t x) { തിരികെ x & 0; }
സ്ഥിതം uint64_t andlm1(uint64_t x) { തിരികെ x & -1; }
സ്ഥിതം uint64_t orrl0(uint64_t x) { തിരികെ x | 0; }
സ്ഥിതം uint32_t orrim1(uint32_t x) { തിരികെ x | -1; }
സ്ഥിതം uint32_t eori0(uint32_t x) { തിരികെ x ^ 0; }
സ്ഥിതം uint64_t eorlm1(uint64_t x) { തിരികെ x ^ -1; }
സ്ഥിതം uint32_t and0xf0(uint32_t x) { തിരികെ x & 0xf0; }
സ്ഥിതം uint64_t orr0xf0(uint64_t x) { തിരികെ x | 0xf0; }
സ്ഥിതം uint64_t eor0xf0(uint64_t x) { തിരികെ x ^ 0xf0; }

സ്ഥിതം uint32_t lsli0(uint32_t x) { തിരികെ x << 0; }
സ്ഥിതം uint32_t lsri0(uint32_t x) { തിരികെ x >> 0; }
സ്ഥിതം int64_t asrl0(int64_t x) { തിരികെ x >> 0; }
സ്ഥിതം uint32_t lsli1(uint32_t x) { തിരികെ x << 1; }
സ്ഥിതം uint32_t lsli31(uint32_t x) { തിരികെ x << 31; }
സ്ഥിതം uint64_t lsll1(uint64_t x) { തിരികെ x << 1; }
സ്ഥിതം uint64_t lsll63(uint64_t x) { തിരികെ x << 63; }
സ്ഥിതം uint32_t lsri1(uint32_t x) { തിരികെ x >> 1; }
സ്ഥിതം uint32_t lsri31(uint32_t x) { തിരികെ x >> 31; }
സ്ഥിതം uint64_t lsrl1(uint64_t x) { തിരികെ x >> 1; }
സ്ഥിതം uint64_t lsrl63(uint64_t x) { തിരികെ x >> 63; }
സ്ഥിതം int32_t asri1(int32_t x) { തിരികെ x >> 1; }
സ്ഥിതം int32_t asri31(int32_t x) { തിരികെ x >> 31; }
സ്ഥിതം int64_t asrl1(int64_t x) { തിരികെ x >> 1; }
സ്ഥിതം int64_t asrl63(int64_t x) { തിരികെ x >> 63; }

ശൂന്യം opi(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 1000;
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

ശൂന്യം pcs(ശൂന്യം)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    pcs();
    തിരികെ 0;
}
