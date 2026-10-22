// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#شامل <stdarg.h>
#شامل <stdint.h>
#شامل <stdio.h>

ساختار s1 { نویسه x[1]; } s1 = { "0" };
ساختار s2 { نویسه x[2]; } s2 = { "12" };
ساختار s3 { نویسه x[3]; } s3 = { "345" };
ساختار s4 { نویسه x[4]; } s4 = { "6789" };
ساختار s5 { نویسه x[5]; } s5 = { "abcde" };
ساختار s6 { نویسه x[6]; } s6 = { "fghijk" };
ساختار s7 { نویسه x[7]; } s7 = { "lmnopqr" };
ساختار s8 { نویسه x[8]; } s8 = { "stuvwxyz" };
ساختار s9 { نویسه x[9]; } s9 = { "ABCDEFGHI" };
ساختار s10 { نویسه x[10]; } s10 = { "JKLMNOPQRS" };
ساختار s11 { نویسه x[11]; } s11 = { "TUVWXYZ0123" };
ساختار s12 { نویسه x[12]; } s12 = { "456789abcdef" };
ساختار s13 { نویسه x[13]; } s13 = { "ghijklmnopqrs" };
ساختار s14 { نویسه x[14]; } s14 = { "tuvwxyzABCDEFG" };
ساختار s15 { نویسه x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
ساختار s16 { نویسه x[16]; } s16 = { "WXYZ0123456789ab" };
ساختار s17 { نویسه x[17]; } s17 = { "cdefghijklmnopqrs" };

ساختار hfa11 { اعشاری a; } hfa11 = { 11.1 };
ساختار hfa12 { اعشاری a, b; } hfa12 = { 12.1, 12.2 };
ساختار hfa13 { اعشاری a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
ساختار hfa14 { اعشاری a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

ساختار hfa21 { دوگانه a; } hfa21 = { 21.1 };
ساختار hfa22 { دوگانه a, b; } hfa22 = { 22.1, 22.2 };
ساختار hfa23 { دوگانه a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
ساختار hfa24 { دوگانه a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

ساختار hfa31 { long دوگانه a; } hfa31 = { 31.1 };
ساختار hfa32 { long دوگانه a, b; } hfa32 = { 32.1, 32.2 };
ساختار hfa33 { long دوگانه a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
ساختار hfa34 { long دوگانه a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

ساختار empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
ساختار hfae12 { ساختار empty e; ساختار hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
ساختار hfae22 { ساختار empty e; ساختار hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

تهی fa_s1(ساختار s1 a) { printf("%.1s\n", a.x); }
تهی fa_s2(ساختار s2 a) { printf("%.2s\n", a.x); }
تهی fa_s3(ساختار s3 a) { printf("%.3s\n", a.x); }
تهی fa_s4(ساختار s4 a) { printf("%.4s\n", a.x); }
تهی fa_s5(ساختار s5 a) { printf("%.5s\n", a.x); }
تهی fa_s6(ساختار s6 a) { printf("%.6s\n", a.x); }
تهی fa_s7(ساختار s7 a) { printf("%.7s\n", a.x); }
تهی fa_s8(ساختار s8 a) { printf("%.8s\n", a.x); }
تهی fa_s9(ساختار s9 a) { printf("%.9s\n", a.x); }
تهی fa_s10(ساختار s10 a) { printf("%.10s\n", a.x); }
تهی fa_s11(ساختار s11 a) { printf("%.11s\n", a.x); }
تهی fa_s12(ساختار s12 a) { printf("%.12s\n", a.x); }
تهی fa_s13(ساختار s13 a) { printf("%.13s\n", a.x); }
تهی fa_s14(ساختار s14 a) { printf("%.14s\n", a.x); }
تهی fa_s15(ساختار s15 a) { printf("%.15s\n", a.x); }
تهی fa_s16(ساختار s16 a) { printf("%.16s\n", a.x); }
تهی fa_s17(ساختار s17 a) { printf("%.17s\n", a.x); }

تهی fa_hfa11(ساختار hfa11 a)
{ printf("%.1f\n", a.a); }
تهی fa_hfa12(ساختار hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
تهی fa_hfa13(ساختار hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
تهی fa_hfa14(ساختار hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

تهی fa_hfa21(ساختار hfa21 a)
{ printf("%.1f\n", a.a); }
تهی fa_hfa22(ساختار hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
تهی fa_hfa23(ساختار hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
تهی fa_hfa24(ساختار hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

تهی fa_hfa31(ساختار hfa31 a)
{ printf("%.1Lf\n", a.a); }
تهی fa_hfa32(ساختار hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
تهی fa_hfa33(ساختار hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
تهی fa_hfa34(ساختار hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
تهی fa_hfae12(ساختار hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
تهی fa_hfae22(ساختار hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

تهی fa1(ساختار s8 a, ساختار s9 b, ساختار s10 c, ساختار s11 d,
         ساختار s12 e, ساختار s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

تهی fa2(ساختار s9 a, ساختار s10 b, ساختار s11 c, ساختار s12 d,
         ساختار s13 e, ساختار s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

تهی fa3(ساختار hfa14 a, ساختار hfa23 b, ساختار hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

تهی fa4(ساختار s1 a, ساختار hfa14 b, ساختار s2 c, ساختار hfa24 d,
         ساختار s3 e, ساختار hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

تهی arg(تهی)
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

ساختار s1 fr_s1(تهی) { بازگشت s1; }
ساختار s2 fr_s2(تهی) { بازگشت s2; }
ساختار s3 fr_s3(تهی) { بازگشت s3; }
ساختار s4 fr_s4(تهی) { بازگشت s4; }
ساختار s5 fr_s5(تهی) { بازگشت s5; }
ساختار s6 fr_s6(تهی) { بازگشت s6; }
ساختار s7 fr_s7(تهی) { بازگشت s7; }
ساختار s8 fr_s8(تهی) { بازگشت s8; }
ساختار s9 fr_s9(تهی) { بازگشت s9; }
ساختار s10 fr_s10(تهی) { بازگشت s10; }
ساختار s11 fr_s11(تهی) { بازگشت s11; }
ساختار s12 fr_s12(تهی) { بازگشت s12; }
ساختار s13 fr_s13(تهی) { بازگشت s13; }
ساختار s14 fr_s14(تهی) { بازگشت s14; }
ساختار s15 fr_s15(تهی) { بازگشت s15; }
ساختار s16 fr_s16(تهی) { بازگشت s16; }
ساختار s17 fr_s17(تهی) { بازگشت s17; }

ساختار hfa11 fr_hfa11(تهی) { بازگشت hfa11; }
ساختار hfa12 fr_hfa12(تهی) { بازگشت hfa12; }
ساختار hfa13 fr_hfa13(تهی) { بازگشت hfa13; }
ساختار hfa14 fr_hfa14(تهی) { بازگشت hfa14; }

ساختار hfa21 fr_hfa21(تهی) { بازگشت hfa21; }
ساختار hfa22 fr_hfa22(تهی) { بازگشت hfa22; }
ساختار hfa23 fr_hfa23(تهی) { بازگشت hfa23; }
ساختار hfa24 fr_hfa24(تهی) { بازگشت hfa24; }

ساختار hfa31 fr_hfa31(تهی) { بازگشت hfa31; }
ساختار hfa32 fr_hfa32(تهی) { بازگشت hfa32; }
ساختار hfa33 fr_hfa33(تهی) { بازگشت hfa33; }
ساختار hfa34 fr_hfa34(تهی) { بازگشت hfa34; }
ساختار hfae12 fr_hfae12(تهی) { بازگشت hfae12; }
ساختار hfae22 fr_hfae22(تهی) { بازگشت hfae22; }

تهی ret(تهی)
{
    ساختار s1 t1 = fr_s1();
    ساختار s2 t2 = fr_s2();
    ساختار s3 t3 = fr_s3();
    ساختار s4 t4 = fr_s4();
    ساختار s5 t5 = fr_s5();
    ساختار s6 t6 = fr_s6();
    ساختار s7 t7 = fr_s7();
    ساختار s8 t8 = fr_s8();
    ساختار s9 t9 = fr_s9();
    ساختار s10 t10 = fr_s10();
    ساختار s11 t11 = fr_s11();
    ساختار s12 t12 = fr_s12();
    ساختار s13 t13 = fr_s13();
    ساختار s14 t14 = fr_s14();
    ساختار s15 t15 = fr_s15();
    ساختار s16 t16 = fr_s16();
    ساختار s17 t17 = fr_s17();
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

تهی*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        ساختار X { صحیح _x; };
        ساختار X *x = va_arg(ap, ساختار X *);
        بازگشت x;
}

صحیح match(ثابت نویسه **s, ثابت نویسه *f)
{
    ثابت نویسه *p = *s;
    برای (p = *s; *f && *f == *p; f++, p++)
        ;
    اگر (!*f) {
        *s = p - 1;
        بازگشت 1;
    }
    بازگشت 0;
}

تهی myprintf(ثابت نویسه *format, ...)
{
    ثابت نویسه *s;
    va_list ap;
    va_start(ap, format);
    برای (s = format; *s; s++) {
        اگر (match(&s, "%7s")) {
            ساختار s7 t7 = va_arg(ap, ساختار s7);
            printf("%.7s", t7.x);
        }
        وگرنه اگر (match(&s, "%9s")) {
            ساختار s9 t9 = va_arg(ap, ساختار s9);
            printf("%.9s", t9.x);
        }
        وگرنه اگر (match(&s, "%hfa11")) {
            ساختار hfa11 x = va_arg(ap, ساختار hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        وگرنه اگر (match(&s, "%hfa12")) {
            ساختار hfa12 x = va_arg(ap, ساختار hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        وگرنه اگر (match(&s, "%hfa13")) {
            ساختار hfa13 x = va_arg(ap, ساختار hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        وگرنه اگر (match(&s, "%hfa14")) {
            ساختار hfa14 x = va_arg(ap, ساختار hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        وگرنه اگر (match(&s, "%hfa21")) {
            ساختار hfa21 x = va_arg(ap, ساختار hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        وگرنه اگر (match(&s, "%hfa22")) {
            ساختار hfa22 x = va_arg(ap, ساختار hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        وگرنه اگر (match(&s, "%hfa23")) {
            ساختار hfa23 x = va_arg(ap, ساختار hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        وگرنه اگر (match(&s, "%hfa24")) {
            ساختار hfa24 x = va_arg(ap, ساختار hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        وگرنه اگر (match(&s, "%hfa31")) {
            ساختار hfa31 x = va_arg(ap, ساختار hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        وگرنه اگر (match(&s, "%hfa32")) {
            ساختار hfa32 x = va_arg(ap, ساختار hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        وگرنه اگر (match(&s, "%hfa33")) {
            ساختار hfa33 x = va_arg(ap, ساختار hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        وگرنه اگر (match(&s, "%hfa34")) {
            ساختار hfa34 x = va_arg(ap, ساختار hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        وگرنه
            putchar(*s);
    }
    putchar('\n');
}

تهی stdarg(تهی)
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

تهی pll(unsigned long long x)
{
    printf("%llx\n", x);
}

تهی movi(تهی)
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

ایستا uint32_t addip0(uint32_t x) { بازگشت x + 0; }
ایستا uint64_t sublp0(uint64_t x) { بازگشت x - 0; }
ایستا uint32_t addip123(uint32_t x) { بازگشت x + 123; }
ایستا uint64_t addlm123(uint64_t x) { بازگشت x + -123; }
ایستا uint64_t sublp4095(uint64_t x) { بازگشت x - 4095; }
ایستا uint32_t subim503808(uint32_t x) { بازگشت x - -503808; }
ایستا uint64_t addp12345(uint64_t x) { بازگشت x + 12345; }
ایستا uint32_t subp12345(uint32_t x) { بازگشت x - 12345; }

ایستا uint32_t mvni(uint32_t x) { بازگشت 0xffffffff - x; }
ایستا uint64_t negl(uint64_t x) { بازگشت 0 - x; }
ایستا uint32_t rsbi123(uint32_t x) { بازگشت 123 - x; }
ایستا uint64_t rsbl123(uint64_t x) { بازگشت 123 - x; }

ایستا uint32_t andi0(uint32_t x) { بازگشت x & 0; }
ایستا uint64_t andlm1(uint64_t x) { بازگشت x & -1; }
ایستا uint64_t orrl0(uint64_t x) { بازگشت x | 0; }
ایستا uint32_t orrim1(uint32_t x) { بازگشت x | -1; }
ایستا uint32_t eori0(uint32_t x) { بازگشت x ^ 0; }
ایستا uint64_t eorlm1(uint64_t x) { بازگشت x ^ -1; }
ایستا uint32_t and0xf0(uint32_t x) { بازگشت x & 0xf0; }
ایستا uint64_t orr0xf0(uint64_t x) { بازگشت x | 0xf0; }
ایستا uint64_t eor0xf0(uint64_t x) { بازگشت x ^ 0xf0; }

ایستا uint32_t lsli0(uint32_t x) { بازگشت x << 0; }
ایستا uint32_t lsri0(uint32_t x) { بازگشت x >> 0; }
ایستا int64_t asrl0(int64_t x) { بازگشت x >> 0; }
ایستا uint32_t lsli1(uint32_t x) { بازگشت x << 1; }
ایستا uint32_t lsli31(uint32_t x) { بازگشت x << 31; }
ایستا uint64_t lsll1(uint64_t x) { بازگشت x << 1; }
ایستا uint64_t lsll63(uint64_t x) { بازگشت x << 63; }
ایستا uint32_t lsri1(uint32_t x) { بازگشت x >> 1; }
ایستا uint32_t lsri31(uint32_t x) { بازگشت x >> 31; }
ایستا uint64_t lsrl1(uint64_t x) { بازگشت x >> 1; }
ایستا uint64_t lsrl63(uint64_t x) { بازگشت x >> 63; }
ایستا int32_t asri1(int32_t x) { بازگشت x >> 1; }
ایستا int32_t asri31(int32_t x) { بازگشت x >> 31; }
ایستا int64_t asrl1(int64_t x) { بازگشت x >> 1; }
ایستا int64_t asrl63(int64_t x) { بازگشت x >> 63; }

تهی opi(تهی)
{
    صحیح x = 1000;
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

تهی pcs(تهی)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

صحیح اصلی()
{
    pcs();
    بازگشت 0;
}
