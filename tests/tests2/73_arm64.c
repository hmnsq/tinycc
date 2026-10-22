// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#અન્તર્ભાવ <stdarg.h>
#અન્તર્ભાવ <stdint.h>
#અન્તર્ભાવ <stdio.h>

સંરચના s1 { અક્ષર x[1]; } s1 = { "0" };
સંરચના s2 { અક્ષર x[2]; } s2 = { "12" };
સંરચના s3 { અક્ષર x[3]; } s3 = { "345" };
સંરચના s4 { અક્ષર x[4]; } s4 = { "6789" };
સંરચના s5 { અક્ષર x[5]; } s5 = { "abcde" };
સંરચના s6 { અક્ષર x[6]; } s6 = { "fghijk" };
સંરચના s7 { અક્ષર x[7]; } s7 = { "lmnopqr" };
સંરચના s8 { અક્ષર x[8]; } s8 = { "stuvwxyz" };
સંરચના s9 { અક્ષર x[9]; } s9 = { "ABCDEFGHI" };
સંરચના s10 { અક્ષર x[10]; } s10 = { "JKLMNOPQRS" };
સંરચના s11 { અક્ષર x[11]; } s11 = { "TUVWXYZ0123" };
સંરચના s12 { અક્ષર x[12]; } s12 = { "456789abcdef" };
સંરચના s13 { અક્ષર x[13]; } s13 = { "ghijklmnopqrs" };
સંરચના s14 { અક્ષર x[14]; } s14 = { "tuvwxyzABCDEFG" };
સંરચના s15 { અક્ષર x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
સંરચના s16 { અક્ષર x[16]; } s16 = { "WXYZ0123456789ab" };
સંરચના s17 { અક્ષર x[17]; } s17 = { "cdefghijklmnopqrs" };

સંરચના hfa11 { દશાંશ a; } hfa11 = { 11.1 };
સંરચના hfa12 { દશાંશ a, b; } hfa12 = { 12.1, 12.2 };
સંરચના hfa13 { દશાંશ a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
સંરચના hfa14 { દશાંશ a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

સંરચના hfa21 { દ્વિગુણ a; } hfa21 = { 21.1 };
સંરચના hfa22 { દ્વિગુણ a, b; } hfa22 = { 22.1, 22.2 };
સંરચના hfa23 { દ્વિગુણ a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
સંરચના hfa24 { દ્વિગુણ a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

સંરચના hfa31 { long દ્વિગુણ a; } hfa31 = { 31.1 };
સંરચના hfa32 { long દ્વિગુણ a, b; } hfa32 = { 32.1, 32.2 };
સંરચના hfa33 { long દ્વિગુણ a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
સંરચના hfa34 { long દ્વિગુણ a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

સંરચના empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
સંરચના hfae12 { સંરચના empty e; સંરચના hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
સંરચના hfae22 { સંરચના empty e; સંરચના hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

શૂન્ય fa_s1(સંરચના s1 a) { printf("%.1s\n", a.x); }
શૂન્ય fa_s2(સંરચના s2 a) { printf("%.2s\n", a.x); }
શૂન્ય fa_s3(સંરચના s3 a) { printf("%.3s\n", a.x); }
શૂન્ય fa_s4(સંરચના s4 a) { printf("%.4s\n", a.x); }
શૂન્ય fa_s5(સંરચના s5 a) { printf("%.5s\n", a.x); }
શૂન્ય fa_s6(સંરચના s6 a) { printf("%.6s\n", a.x); }
શૂન્ય fa_s7(સંરચના s7 a) { printf("%.7s\n", a.x); }
શૂન્ય fa_s8(સંરચના s8 a) { printf("%.8s\n", a.x); }
શૂન્ય fa_s9(સંરચના s9 a) { printf("%.9s\n", a.x); }
શૂન્ય fa_s10(સંરચના s10 a) { printf("%.10s\n", a.x); }
શૂન્ય fa_s11(સંરચના s11 a) { printf("%.11s\n", a.x); }
શૂન્ય fa_s12(સંરચના s12 a) { printf("%.12s\n", a.x); }
શૂન્ય fa_s13(સંરચના s13 a) { printf("%.13s\n", a.x); }
શૂન્ય fa_s14(સંરચના s14 a) { printf("%.14s\n", a.x); }
શૂન્ય fa_s15(સંરચના s15 a) { printf("%.15s\n", a.x); }
શૂન્ય fa_s16(સંરચના s16 a) { printf("%.16s\n", a.x); }
શૂન્ય fa_s17(સંરચના s17 a) { printf("%.17s\n", a.x); }

શૂન્ય fa_hfa11(સંરચના hfa11 a)
{ printf("%.1f\n", a.a); }
શૂન્ય fa_hfa12(સંરચના hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
શૂન્ય fa_hfa13(સંરચના hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
શૂન્ય fa_hfa14(સંરચના hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

શૂન્ય fa_hfa21(સંરચના hfa21 a)
{ printf("%.1f\n", a.a); }
શૂન્ય fa_hfa22(સંરચના hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
શૂન્ય fa_hfa23(સંરચના hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
શૂન્ય fa_hfa24(સંરચના hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

શૂન્ય fa_hfa31(સંરચના hfa31 a)
{ printf("%.1Lf\n", a.a); }
શૂન્ય fa_hfa32(સંરચના hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
શૂન્ય fa_hfa33(સંરચના hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
શૂન્ય fa_hfa34(સંરચના hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
શૂન્ય fa_hfae12(સંરચના hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
શૂન્ય fa_hfae22(સંરચના hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

શૂન્ય fa1(સંરચના s8 a, સંરચના s9 b, સંરચના s10 c, સંરચના s11 d,
         સંરચના s12 e, સંરચના s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

શૂન્ય fa2(સંરચના s9 a, સંરચના s10 b, સંરચના s11 c, સંરચના s12 d,
         સંરચના s13 e, સંરચના s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

શૂન્ય fa3(સંરચના hfa14 a, સંરચના hfa23 b, સંરચના hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

શૂન્ય fa4(સંરચના s1 a, સંરચના hfa14 b, સંરચના s2 c, સંરચના hfa24 d,
         સંરચના s3 e, સંરચના hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

શૂન્ય arg(શૂન્ય)
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

સંરચના s1 fr_s1(શૂન્ય) { પાછા s1; }
સંરચના s2 fr_s2(શૂન્ય) { પાછા s2; }
સંરચના s3 fr_s3(શૂન્ય) { પાછા s3; }
સંરચના s4 fr_s4(શૂન્ય) { પાછા s4; }
સંરચના s5 fr_s5(શૂન્ય) { પાછા s5; }
સંરચના s6 fr_s6(શૂન્ય) { પાછા s6; }
સંરચના s7 fr_s7(શૂન્ય) { પાછા s7; }
સંરચના s8 fr_s8(શૂન્ય) { પાછા s8; }
સંરચના s9 fr_s9(શૂન્ય) { પાછા s9; }
સંરચના s10 fr_s10(શૂન્ય) { પાછા s10; }
સંરચના s11 fr_s11(શૂન્ય) { પાછા s11; }
સંરચના s12 fr_s12(શૂન્ય) { પાછા s12; }
સંરચના s13 fr_s13(શૂન્ય) { પાછા s13; }
સંરચના s14 fr_s14(શૂન્ય) { પાછા s14; }
સંરચના s15 fr_s15(શૂન્ય) { પાછા s15; }
સંરચના s16 fr_s16(શૂન્ય) { પાછા s16; }
સંરચના s17 fr_s17(શૂન્ય) { પાછા s17; }

સંરચના hfa11 fr_hfa11(શૂન્ય) { પાછા hfa11; }
સંરચના hfa12 fr_hfa12(શૂન્ય) { પાછા hfa12; }
સંરચના hfa13 fr_hfa13(શૂન્ય) { પાછા hfa13; }
સંરચના hfa14 fr_hfa14(શૂન્ય) { પાછા hfa14; }

સંરચના hfa21 fr_hfa21(શૂન્ય) { પાછા hfa21; }
સંરચના hfa22 fr_hfa22(શૂન્ય) { પાછા hfa22; }
સંરચના hfa23 fr_hfa23(શૂન્ય) { પાછા hfa23; }
સંરચના hfa24 fr_hfa24(શૂન્ય) { પાછા hfa24; }

સંરચના hfa31 fr_hfa31(શૂન્ય) { પાછા hfa31; }
સંરચના hfa32 fr_hfa32(શૂન્ય) { પાછા hfa32; }
સંરચના hfa33 fr_hfa33(શૂન્ય) { પાછા hfa33; }
સંરચના hfa34 fr_hfa34(શૂન્ય) { પાછા hfa34; }
સંરચના hfae12 fr_hfae12(શૂન્ય) { પાછા hfae12; }
સંરચના hfae22 fr_hfae22(શૂન્ય) { પાછા hfae22; }

શૂન્ય ret(શૂન્ય)
{
    સંરચના s1 t1 = fr_s1();
    સંરચના s2 t2 = fr_s2();
    સંરચના s3 t3 = fr_s3();
    સંરચના s4 t4 = fr_s4();
    સંરચના s5 t5 = fr_s5();
    સંરચના s6 t6 = fr_s6();
    સંરચના s7 t7 = fr_s7();
    સંરચના s8 t8 = fr_s8();
    સંરચના s9 t9 = fr_s9();
    સંરચના s10 t10 = fr_s10();
    સંરચના s11 t11 = fr_s11();
    સંરચના s12 t12 = fr_s12();
    સંરચના s13 t13 = fr_s13();
    સંરચના s14 t14 = fr_s14();
    સંરચના s15 t15 = fr_s15();
    સંરચના s16 t16 = fr_s16();
    સંરચના s17 t17 = fr_s17();
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

શૂન્ય*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        સંરચના X { પૂર્ણાંક _x; };
        સંરચના X *x = va_arg(ap, સંરચના X *);
        પાછા x;
}

પૂર્ણાંક match(અચલ અક્ષર **s, અચલ અક્ષર *f)
{
    અચલ અક્ષર *p = *s;
    માટે (p = *s; *f && *f == *p; f++, p++)
        ;
    જો (!*f) {
        *s = p - 1;
        પાછા 1;
    }
    પાછા 0;
}

શૂન્ય myprintf(અચલ અક્ષર *format, ...)
{
    અચલ અક્ષર *s;
    va_list ap;
    va_start(ap, format);
    માટે (s = format; *s; s++) {
        જો (match(&s, "%7s")) {
            સંરચના s7 t7 = va_arg(ap, સંરચના s7);
            printf("%.7s", t7.x);
        }
        નહીંતર જો (match(&s, "%9s")) {
            સંરચના s9 t9 = va_arg(ap, સંરચના s9);
            printf("%.9s", t9.x);
        }
        નહીંતર જો (match(&s, "%hfa11")) {
            સંરચના hfa11 x = va_arg(ap, સંરચના hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        નહીંતર જો (match(&s, "%hfa12")) {
            સંરચના hfa12 x = va_arg(ap, સંરચના hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        નહીંતર જો (match(&s, "%hfa13")) {
            સંરચના hfa13 x = va_arg(ap, સંરચના hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        નહીંતર જો (match(&s, "%hfa14")) {
            સંરચના hfa14 x = va_arg(ap, સંરચના hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        નહીંતર જો (match(&s, "%hfa21")) {
            સંરચના hfa21 x = va_arg(ap, સંરચના hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        નહીંતર જો (match(&s, "%hfa22")) {
            સંરચના hfa22 x = va_arg(ap, સંરચના hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        નહીંતર જો (match(&s, "%hfa23")) {
            સંરચના hfa23 x = va_arg(ap, સંરચના hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        નહીંતર જો (match(&s, "%hfa24")) {
            સંરચના hfa24 x = va_arg(ap, સંરચના hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        નહીંતર જો (match(&s, "%hfa31")) {
            સંરચના hfa31 x = va_arg(ap, સંરચના hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        નહીંતર જો (match(&s, "%hfa32")) {
            સંરચના hfa32 x = va_arg(ap, સંરચના hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        નહીંતર જો (match(&s, "%hfa33")) {
            સંરચના hfa33 x = va_arg(ap, સંરચના hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        નહીંતર જો (match(&s, "%hfa34")) {
            સંરચના hfa34 x = va_arg(ap, સંરચના hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        નહીંતર
            putchar(*s);
    }
    putchar('\n');
}

શૂન્ય stdarg(શૂન્ય)
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

શૂન્ય pll(unsigned long long x)
{
    printf("%llx\n", x);
}

શૂન્ય movi(શૂન્ય)
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

સ્થિર uint32_t addip0(uint32_t x) { પાછા x + 0; }
સ્થિર uint64_t sublp0(uint64_t x) { પાછા x - 0; }
સ્થિર uint32_t addip123(uint32_t x) { પાછા x + 123; }
સ્થિર uint64_t addlm123(uint64_t x) { પાછા x + -123; }
સ્થિર uint64_t sublp4095(uint64_t x) { પાછા x - 4095; }
સ્થિર uint32_t subim503808(uint32_t x) { પાછા x - -503808; }
સ્થિર uint64_t addp12345(uint64_t x) { પાછા x + 12345; }
સ્થિર uint32_t subp12345(uint32_t x) { પાછા x - 12345; }

સ્થિર uint32_t mvni(uint32_t x) { પાછા 0xffffffff - x; }
સ્થિર uint64_t negl(uint64_t x) { પાછા 0 - x; }
સ્થિર uint32_t rsbi123(uint32_t x) { પાછા 123 - x; }
સ્થિર uint64_t rsbl123(uint64_t x) { પાછા 123 - x; }

સ્થિર uint32_t andi0(uint32_t x) { પાછા x & 0; }
સ્થિર uint64_t andlm1(uint64_t x) { પાછા x & -1; }
સ્થિર uint64_t orrl0(uint64_t x) { પાછા x | 0; }
સ્થિર uint32_t orrim1(uint32_t x) { પાછા x | -1; }
સ્થિર uint32_t eori0(uint32_t x) { પાછા x ^ 0; }
સ્થિર uint64_t eorlm1(uint64_t x) { પાછા x ^ -1; }
સ્થિર uint32_t and0xf0(uint32_t x) { પાછા x & 0xf0; }
સ્થિર uint64_t orr0xf0(uint64_t x) { પાછા x | 0xf0; }
સ્થિર uint64_t eor0xf0(uint64_t x) { પાછા x ^ 0xf0; }

સ્થિર uint32_t lsli0(uint32_t x) { પાછા x << 0; }
સ્થિર uint32_t lsri0(uint32_t x) { પાછા x >> 0; }
સ્થિર int64_t asrl0(int64_t x) { પાછા x >> 0; }
સ્થિર uint32_t lsli1(uint32_t x) { પાછા x << 1; }
સ્થિર uint32_t lsli31(uint32_t x) { પાછા x << 31; }
સ્થિર uint64_t lsll1(uint64_t x) { પાછા x << 1; }
સ્થિર uint64_t lsll63(uint64_t x) { પાછા x << 63; }
સ્થિર uint32_t lsri1(uint32_t x) { પાછા x >> 1; }
સ્થિર uint32_t lsri31(uint32_t x) { પાછા x >> 31; }
સ્થિર uint64_t lsrl1(uint64_t x) { પાછા x >> 1; }
સ્થિર uint64_t lsrl63(uint64_t x) { પાછા x >> 63; }
સ્થિર int32_t asri1(int32_t x) { પાછા x >> 1; }
સ્થિર int32_t asri31(int32_t x) { પાછા x >> 31; }
સ્થિર int64_t asrl1(int64_t x) { પાછા x >> 1; }
સ્થિર int64_t asrl63(int64_t x) { પાછા x >> 63; }

શૂન્ય opi(શૂન્ય)
{
    પૂર્ણાંક x = 1000;
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

શૂન્ય pcs(શૂન્ય)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

પૂર્ણાંક મુખ્ય()
{
    pcs();
    પાછા 0;
}
