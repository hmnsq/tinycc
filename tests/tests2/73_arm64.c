// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

sa_nracanaa s1 { var_na x[1]; } s1 = { "0" };
sa_nracanaa s2 { var_na x[2]; } s2 = { "12" };
sa_nracanaa s3 { var_na x[3]; } s3 = { "345" };
sa_nracanaa s4 { var_na x[4]; } s4 = { "6789" };
sa_nracanaa s5 { var_na x[5]; } s5 = { "abcde" };
sa_nracanaa s6 { var_na x[6]; } s6 = { "fghijk" };
sa_nracanaa s7 { var_na x[7]; } s7 = { "lmnopqr" };
sa_nracanaa s8 { var_na x[8]; } s8 = { "stuvwxyz" };
sa_nracanaa s9 { var_na x[9]; } s9 = { "ABCDEFGHI" };
sa_nracanaa s10 { var_na x[10]; } s10 = { "JKLMNOPQRS" };
sa_nracanaa s11 { var_na x[11]; } s11 = { "TUVWXYZ0123" };
sa_nracanaa s12 { var_na x[12]; } s12 = { "456789abcdef" };
sa_nracanaa s13 { var_na x[13]; } s13 = { "ghijklmnopqrs" };
sa_nracanaa s14 { var_na x[14]; } s14 = { "tuvwxyzABCDEFG" };
sa_nracanaa s15 { var_na x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
sa_nracanaa s16 { var_na x[16]; } s16 = { "WXYZ0123456789ab" };
sa_nracanaa s17 { var_na x[17]; } s17 = { "cdefghijklmnopqrs" };

sa_nracanaa hfa11 { float a; } hfa11 = { 11.1 };
sa_nracanaa hfa12 { float a, b; } hfa12 = { 12.1, 12.2 };
sa_nracanaa hfa13 { float a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
sa_nracanaa hfa14 { float a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

sa_nracanaa hfa21 { dviguu_na a; } hfa21 = { 21.1 };
sa_nracanaa hfa22 { dviguu_na a, b; } hfa22 = { 22.1, 22.2 };
sa_nracanaa hfa23 { dviguu_na a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
sa_nracanaa hfa24 { dviguu_na a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

sa_nracanaa hfa31 { long dviguu_na a; } hfa31 = { 31.1 };
sa_nracanaa hfa32 { long dviguu_na a, b; } hfa32 = { 32.1, 32.2 };
sa_nracanaa hfa33 { long dviguu_na a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
sa_nracanaa hfa34 { long dviguu_na a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

sa_nracanaa empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
sa_nracanaa hfae12 { sa_nracanaa empty e; sa_nracanaa hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
sa_nracanaa hfae22 { sa_nracanaa empty e; sa_nracanaa hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

void fa_s1(sa_nracanaa s1 a) { printf("%.1s\n", a.x); }
void fa_s2(sa_nracanaa s2 a) { printf("%.2s\n", a.x); }
void fa_s3(sa_nracanaa s3 a) { printf("%.3s\n", a.x); }
void fa_s4(sa_nracanaa s4 a) { printf("%.4s\n", a.x); }
void fa_s5(sa_nracanaa s5 a) { printf("%.5s\n", a.x); }
void fa_s6(sa_nracanaa s6 a) { printf("%.6s\n", a.x); }
void fa_s7(sa_nracanaa s7 a) { printf("%.7s\n", a.x); }
void fa_s8(sa_nracanaa s8 a) { printf("%.8s\n", a.x); }
void fa_s9(sa_nracanaa s9 a) { printf("%.9s\n", a.x); }
void fa_s10(sa_nracanaa s10 a) { printf("%.10s\n", a.x); }
void fa_s11(sa_nracanaa s11 a) { printf("%.11s\n", a.x); }
void fa_s12(sa_nracanaa s12 a) { printf("%.12s\n", a.x); }
void fa_s13(sa_nracanaa s13 a) { printf("%.13s\n", a.x); }
void fa_s14(sa_nracanaa s14 a) { printf("%.14s\n", a.x); }
void fa_s15(sa_nracanaa s15 a) { printf("%.15s\n", a.x); }
void fa_s16(sa_nracanaa s16 a) { printf("%.16s\n", a.x); }
void fa_s17(sa_nracanaa s17 a) { printf("%.17s\n", a.x); }

void fa_hfa11(sa_nracanaa hfa11 a)
{ printf("%.1f\n", a.a); }
void fa_hfa12(sa_nracanaa hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
void fa_hfa13(sa_nracanaa hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
void fa_hfa14(sa_nracanaa hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

void fa_hfa21(sa_nracanaa hfa21 a)
{ printf("%.1f\n", a.a); }
void fa_hfa22(sa_nracanaa hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
void fa_hfa23(sa_nracanaa hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
void fa_hfa24(sa_nracanaa hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

void fa_hfa31(sa_nracanaa hfa31 a)
{ printf("%.1Lf\n", a.a); }
void fa_hfa32(sa_nracanaa hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
void fa_hfa33(sa_nracanaa hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
void fa_hfa34(sa_nracanaa hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
void fa_hfae12(sa_nracanaa hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
void fa_hfae22(sa_nracanaa hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

void fa1(sa_nracanaa s8 a, sa_nracanaa s9 b, sa_nracanaa s10 c, sa_nracanaa s11 d,
         sa_nracanaa s12 e, sa_nracanaa s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

void fa2(sa_nracanaa s9 a, sa_nracanaa s10 b, sa_nracanaa s11 c, sa_nracanaa s12 d,
         sa_nracanaa s13 e, sa_nracanaa s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

void fa3(sa_nracanaa hfa14 a, sa_nracanaa hfa23 b, sa_nracanaa hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

void fa4(sa_nracanaa s1 a, sa_nracanaa hfa14 b, sa_nracanaa s2 c, sa_nracanaa hfa24 d,
         sa_nracanaa s3 e, sa_nracanaa hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

void arg(void)
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

sa_nracanaa s1 fr_s1(void) { คืน s1; }
sa_nracanaa s2 fr_s2(void) { คืน s2; }
sa_nracanaa s3 fr_s3(void) { คืน s3; }
sa_nracanaa s4 fr_s4(void) { คืน s4; }
sa_nracanaa s5 fr_s5(void) { คืน s5; }
sa_nracanaa s6 fr_s6(void) { คืน s6; }
sa_nracanaa s7 fr_s7(void) { คืน s7; }
sa_nracanaa s8 fr_s8(void) { คืน s8; }
sa_nracanaa s9 fr_s9(void) { คืน s9; }
sa_nracanaa s10 fr_s10(void) { คืน s10; }
sa_nracanaa s11 fr_s11(void) { คืน s11; }
sa_nracanaa s12 fr_s12(void) { คืน s12; }
sa_nracanaa s13 fr_s13(void) { คืน s13; }
sa_nracanaa s14 fr_s14(void) { คืน s14; }
sa_nracanaa s15 fr_s15(void) { คืน s15; }
sa_nracanaa s16 fr_s16(void) { คืน s16; }
sa_nracanaa s17 fr_s17(void) { คืน s17; }

sa_nracanaa hfa11 fr_hfa11(void) { คืน hfa11; }
sa_nracanaa hfa12 fr_hfa12(void) { คืน hfa12; }
sa_nracanaa hfa13 fr_hfa13(void) { คืน hfa13; }
sa_nracanaa hfa14 fr_hfa14(void) { คืน hfa14; }

sa_nracanaa hfa21 fr_hfa21(void) { คืน hfa21; }
sa_nracanaa hfa22 fr_hfa22(void) { คืน hfa22; }
sa_nracanaa hfa23 fr_hfa23(void) { คืน hfa23; }
sa_nracanaa hfa24 fr_hfa24(void) { คืน hfa24; }

sa_nracanaa hfa31 fr_hfa31(void) { คืน hfa31; }
sa_nracanaa hfa32 fr_hfa32(void) { คืน hfa32; }
sa_nracanaa hfa33 fr_hfa33(void) { คืน hfa33; }
sa_nracanaa hfa34 fr_hfa34(void) { คืน hfa34; }
sa_nracanaa hfae12 fr_hfae12(void) { คืน hfae12; }
sa_nracanaa hfae22 fr_hfae22(void) { คืน hfae22; }

void ret(void)
{
    sa_nracanaa s1 t1 = fr_s1();
    sa_nracanaa s2 t2 = fr_s2();
    sa_nracanaa s3 t3 = fr_s3();
    sa_nracanaa s4 t4 = fr_s4();
    sa_nracanaa s5 t5 = fr_s5();
    sa_nracanaa s6 t6 = fr_s6();
    sa_nracanaa s7 t7 = fr_s7();
    sa_nracanaa s8 t8 = fr_s8();
    sa_nracanaa s9 t9 = fr_s9();
    sa_nracanaa s10 t10 = fr_s10();
    sa_nracanaa s11 t11 = fr_s11();
    sa_nracanaa s12 t12 = fr_s12();
    sa_nracanaa s13 t13 = fr_s13();
    sa_nracanaa s14 t14 = fr_s14();
    sa_nracanaa s15 t15 = fr_s15();
    sa_nracanaa s16 t16 = fr_s16();
    sa_nracanaa s17 t17 = fr_s17();
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

void*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        sa_nracanaa X { จำนวนเต็ม _x; };
        sa_nracanaa X *x = va_arg(ap, sa_nracanaa X *);
        คืน x;
}

จำนวนเต็ม match(const var_na **s, const var_na *f)
{
    const var_na *p = *s;
    สำหรับ (p = *s; *f && *f == *p; f++, p++)
        ;
    ถ้า (!*f) {
        *s = p - 1;
        คืน 1;
    }
    คืน 0;
}

void myprintf(const var_na *format, ...)
{
    const var_na *s;
    va_list ap;
    va_start(ap, format);
    สำหรับ (s = format; *s; s++) {
        ถ้า (match(&s, "%7s")) {
            sa_nracanaa s7 t7 = va_arg(ap, sa_nracanaa s7);
            printf("%.7s", t7.x);
        }
        มิฉะนั้น ถ้า (match(&s, "%9s")) {
            sa_nracanaa s9 t9 = va_arg(ap, sa_nracanaa s9);
            printf("%.9s", t9.x);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa11")) {
            sa_nracanaa hfa11 x = va_arg(ap, sa_nracanaa hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa12")) {
            sa_nracanaa hfa12 x = va_arg(ap, sa_nracanaa hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa13")) {
            sa_nracanaa hfa13 x = va_arg(ap, sa_nracanaa hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa14")) {
            sa_nracanaa hfa14 x = va_arg(ap, sa_nracanaa hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa21")) {
            sa_nracanaa hfa21 x = va_arg(ap, sa_nracanaa hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa22")) {
            sa_nracanaa hfa22 x = va_arg(ap, sa_nracanaa hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa23")) {
            sa_nracanaa hfa23 x = va_arg(ap, sa_nracanaa hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa24")) {
            sa_nracanaa hfa24 x = va_arg(ap, sa_nracanaa hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa31")) {
            sa_nracanaa hfa31 x = va_arg(ap, sa_nracanaa hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa32")) {
            sa_nracanaa hfa32 x = va_arg(ap, sa_nracanaa hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa33")) {
            sa_nracanaa hfa33 x = va_arg(ap, sa_nracanaa hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        มิฉะนั้น ถ้า (match(&s, "%hfa34")) {
            sa_nracanaa hfa34 x = va_arg(ap, sa_nracanaa hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        มิฉะนั้น
            putchar(*s);
    }
    putchar('\n');
}

void stdarg(void)
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

void pll(unsigned long long x)
{
    printf("%llx\n", x);
}

void movi(void)
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

static uint32_t addip0(uint32_t x) { คืน x + 0; }
static uint64_t sublp0(uint64_t x) { คืน x - 0; }
static uint32_t addip123(uint32_t x) { คืน x + 123; }
static uint64_t addlm123(uint64_t x) { คืน x + -123; }
static uint64_t sublp4095(uint64_t x) { คืน x - 4095; }
static uint32_t subim503808(uint32_t x) { คืน x - -503808; }
static uint64_t addp12345(uint64_t x) { คืน x + 12345; }
static uint32_t subp12345(uint32_t x) { คืน x - 12345; }

static uint32_t mvni(uint32_t x) { คืน 0xffffffff - x; }
static uint64_t negl(uint64_t x) { คืน 0 - x; }
static uint32_t rsbi123(uint32_t x) { คืน 123 - x; }
static uint64_t rsbl123(uint64_t x) { คืน 123 - x; }

static uint32_t andi0(uint32_t x) { คืน x & 0; }
static uint64_t andlm1(uint64_t x) { คืน x & -1; }
static uint64_t orrl0(uint64_t x) { คืน x | 0; }
static uint32_t orrim1(uint32_t x) { คืน x | -1; }
static uint32_t eori0(uint32_t x) { คืน x ^ 0; }
static uint64_t eorlm1(uint64_t x) { คืน x ^ -1; }
static uint32_t and0xf0(uint32_t x) { คืน x & 0xf0; }
static uint64_t orr0xf0(uint64_t x) { คืน x | 0xf0; }
static uint64_t eor0xf0(uint64_t x) { คืน x ^ 0xf0; }

static uint32_t lsli0(uint32_t x) { คืน x << 0; }
static uint32_t lsri0(uint32_t x) { คืน x >> 0; }
static int64_t asrl0(int64_t x) { คืน x >> 0; }
static uint32_t lsli1(uint32_t x) { คืน x << 1; }
static uint32_t lsli31(uint32_t x) { คืน x << 31; }
static uint64_t lsll1(uint64_t x) { คืน x << 1; }
static uint64_t lsll63(uint64_t x) { คืน x << 63; }
static uint32_t lsri1(uint32_t x) { คืน x >> 1; }
static uint32_t lsri31(uint32_t x) { คืน x >> 31; }
static uint64_t lsrl1(uint64_t x) { คืน x >> 1; }
static uint64_t lsrl63(uint64_t x) { คืน x >> 63; }
static int32_t asri1(int32_t x) { คืน x >> 1; }
static int32_t asri31(int32_t x) { คืน x >> 31; }
static int64_t asrl1(int64_t x) { คืน x >> 1; }
static int64_t asrl63(int64_t x) { คืน x >> 63; }

void opi(void)
{
    จำนวนเต็ม x = 1000;
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

void pcs(void)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

จำนวนเต็ม หลัก()
{
    pcs();
    คืน 0;
}
