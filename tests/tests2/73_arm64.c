// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#অন্তর্ভাৱ <stdarg.h>
#অন্তর্ভাৱ <stdint.h>
#অন্তর্ভাৱ <stdio.h>

সংরচনা s1 { ৱর্ণ x[1]; } s1 = { "0" };
সংরচনা s2 { ৱর্ণ x[2]; } s2 = { "12" };
সংরচনা s3 { ৱর্ণ x[3]; } s3 = { "345" };
সংরচনা s4 { ৱর্ণ x[4]; } s4 = { "6789" };
সংরচনা s5 { ৱর্ণ x[5]; } s5 = { "abcde" };
সংরচনা s6 { ৱর্ণ x[6]; } s6 = { "fghijk" };
সংরচনা s7 { ৱর্ণ x[7]; } s7 = { "lmnopqr" };
সংরচনা s8 { ৱর্ণ x[8]; } s8 = { "stuvwxyz" };
সংরচনা s9 { ৱর্ণ x[9]; } s9 = { "ABCDEFGHI" };
সংরচনা s10 { ৱর্ণ x[10]; } s10 = { "JKLMNOPQRS" };
সংরচনা s11 { ৱর্ণ x[11]; } s11 = { "TUVWXYZ0123" };
সংরচনা s12 { ৱর্ণ x[12]; } s12 = { "456789abcdef" };
সংরচনা s13 { ৱর্ণ x[13]; } s13 = { "ghijklmnopqrs" };
সংরচনা s14 { ৱর্ণ x[14]; } s14 = { "tuvwxyzABCDEFG" };
সংরচনা s15 { ৱর্ণ x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
সংরচনা s16 { ৱর্ণ x[16]; } s16 = { "WXYZ0123456789ab" };
সংরচনা s17 { ৱর্ণ x[17]; } s17 = { "cdefghijklmnopqrs" };

সংরচনা hfa11 { ভিন্ন a; } hfa11 = { 11.1 };
সংরচনা hfa12 { ভিন্ন a, b; } hfa12 = { 12.1, 12.2 };
সংরচনা hfa13 { ভিন্ন a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
সংরচনা hfa14 { ভিন্ন a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

সংরচনা hfa21 { দ্ৱিগুণ a; } hfa21 = { 21.1 };
সংরচনা hfa22 { দ্ৱিগুণ a, b; } hfa22 = { 22.1, 22.2 };
সংরচনা hfa23 { দ্ৱিগুণ a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
সংরচনা hfa24 { দ্ৱিগুণ a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

সংরচনা hfa31 { long দ্ৱিগুণ a; } hfa31 = { 31.1 };
সংরচনা hfa32 { long দ্ৱিগুণ a, b; } hfa32 = { 32.1, 32.2 };
সংরচনা hfa33 { long দ্ৱিগুণ a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
সংরচনা hfa34 { long দ্ৱিগুণ a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

সংরচনা empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
সংরচনা hfae12 { সংরচনা empty e; সংরচনা hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
সংরচনা hfae22 { সংরচনা empty e; সংরচনা hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

শূন্য fa_s1(সংরচনা s1 a) { printf("%.1s\n", a.x); }
শূন্য fa_s2(সংরচনা s2 a) { printf("%.2s\n", a.x); }
শূন্য fa_s3(সংরচনা s3 a) { printf("%.3s\n", a.x); }
শূন্য fa_s4(সংরচনা s4 a) { printf("%.4s\n", a.x); }
শূন্য fa_s5(সংরচনা s5 a) { printf("%.5s\n", a.x); }
শূন্য fa_s6(সংরচনা s6 a) { printf("%.6s\n", a.x); }
শূন্য fa_s7(সংরচনা s7 a) { printf("%.7s\n", a.x); }
শূন্য fa_s8(সংরচনা s8 a) { printf("%.8s\n", a.x); }
শূন্য fa_s9(সংরচনা s9 a) { printf("%.9s\n", a.x); }
শূন্য fa_s10(সংরচনা s10 a) { printf("%.10s\n", a.x); }
শূন্য fa_s11(সংরচনা s11 a) { printf("%.11s\n", a.x); }
শূন্য fa_s12(সংরচনা s12 a) { printf("%.12s\n", a.x); }
শূন্য fa_s13(সংরচনা s13 a) { printf("%.13s\n", a.x); }
শূন্য fa_s14(সংরচনা s14 a) { printf("%.14s\n", a.x); }
শূন্য fa_s15(সংরচনা s15 a) { printf("%.15s\n", a.x); }
শূন্য fa_s16(সংরচনা s16 a) { printf("%.16s\n", a.x); }
শূন্য fa_s17(সংরচনা s17 a) { printf("%.17s\n", a.x); }

শূন্য fa_hfa11(সংরচনা hfa11 a)
{ printf("%.1f\n", a.a); }
শূন্য fa_hfa12(সংরচনা hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
শূন্য fa_hfa13(সংরচনা hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
শূন্য fa_hfa14(সংরচনা hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

শূন্য fa_hfa21(সংরচনা hfa21 a)
{ printf("%.1f\n", a.a); }
শূন্য fa_hfa22(সংরচনা hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
শূন্য fa_hfa23(সংরচনা hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
শূন্য fa_hfa24(সংরচনা hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

শূন্য fa_hfa31(সংরচনা hfa31 a)
{ printf("%.1Lf\n", a.a); }
শূন্য fa_hfa32(সংরচনা hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
শূন্য fa_hfa33(সংরচনা hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
শূন্য fa_hfa34(সংরচনা hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
শূন্য fa_hfae12(সংরচনা hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
শূন্য fa_hfae22(সংরচনা hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

শূন্য fa1(সংরচনা s8 a, সংরচনা s9 b, সংরচনা s10 c, সংরচনা s11 d,
         সংরচনা s12 e, সংরচনা s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

শূন্য fa2(সংরচনা s9 a, সংরচনা s10 b, সংরচনা s11 c, সংরচনা s12 d,
         সংরচনা s13 e, সংরচনা s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

শূন্য fa3(সংরচনা hfa14 a, সংরচনা hfa23 b, সংরচনা hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

শূন্য fa4(সংরচনা s1 a, সংরচনা hfa14 b, সংরচনা s2 c, সংরচনা hfa24 d,
         সংরচনা s3 e, সংরচনা hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

শূন্য arg(শূন্য)
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

সংরচনা s1 fr_s1(শূন্য) { ঘূৰাই s1; }
সংরচনা s2 fr_s2(শূন্য) { ঘূৰাই s2; }
সংরচনা s3 fr_s3(শূন্য) { ঘূৰাই s3; }
সংরচনা s4 fr_s4(শূন্য) { ঘূৰাই s4; }
সংরচনা s5 fr_s5(শূন্য) { ঘূৰাই s5; }
সংরচনা s6 fr_s6(শূন্য) { ঘূৰাই s6; }
সংরচনা s7 fr_s7(শূন্য) { ঘূৰাই s7; }
সংরচনা s8 fr_s8(শূন্য) { ঘূৰাই s8; }
সংরচনা s9 fr_s9(শূন্য) { ঘূৰাই s9; }
সংরচনা s10 fr_s10(শূন্য) { ঘূৰাই s10; }
সংরচনা s11 fr_s11(শূন্য) { ঘূৰাই s11; }
সংরচনা s12 fr_s12(শূন্য) { ঘূৰাই s12; }
সংরচনা s13 fr_s13(শূন্য) { ঘূৰাই s13; }
সংরচনা s14 fr_s14(শূন্য) { ঘূৰাই s14; }
সংরচনা s15 fr_s15(শূন্য) { ঘূৰাই s15; }
সংরচনা s16 fr_s16(শূন্য) { ঘূৰাই s16; }
সংরচনা s17 fr_s17(শূন্য) { ঘূৰাই s17; }

সংরচনা hfa11 fr_hfa11(শূন্য) { ঘূৰাই hfa11; }
সংরচনা hfa12 fr_hfa12(শূন্য) { ঘূৰাই hfa12; }
সংরচনা hfa13 fr_hfa13(শূন্য) { ঘূৰাই hfa13; }
সংরচনা hfa14 fr_hfa14(শূন্য) { ঘূৰাই hfa14; }

সংরচনা hfa21 fr_hfa21(শূন্য) { ঘূৰাই hfa21; }
সংরচনা hfa22 fr_hfa22(শূন্য) { ঘূৰাই hfa22; }
সংরচনা hfa23 fr_hfa23(শূন্য) { ঘূৰাই hfa23; }
সংরচনা hfa24 fr_hfa24(শূন্য) { ঘূৰাই hfa24; }

সংরচনা hfa31 fr_hfa31(শূন্য) { ঘূৰাই hfa31; }
সংরচনা hfa32 fr_hfa32(শূন্য) { ঘূৰাই hfa32; }
সংরচনা hfa33 fr_hfa33(শূন্য) { ঘূৰাই hfa33; }
সংরচনা hfa34 fr_hfa34(শূন্য) { ঘূৰাই hfa34; }
সংরচনা hfae12 fr_hfae12(শূন্য) { ঘূৰাই hfae12; }
সংরচনা hfae22 fr_hfae22(শূন্য) { ঘূৰাই hfae22; }

শূন্য ret(শূন্য)
{
    সংরচনা s1 t1 = fr_s1();
    সংরচনা s2 t2 = fr_s2();
    সংরচনা s3 t3 = fr_s3();
    সংরচনা s4 t4 = fr_s4();
    সংরচনা s5 t5 = fr_s5();
    সংরচনা s6 t6 = fr_s6();
    সংরচনা s7 t7 = fr_s7();
    সংরচনা s8 t8 = fr_s8();
    সংরচনা s9 t9 = fr_s9();
    সংরচনা s10 t10 = fr_s10();
    সংরচনা s11 t11 = fr_s11();
    সংরচনা s12 t12 = fr_s12();
    সংরচনা s13 t13 = fr_s13();
    সংরচনা s14 t14 = fr_s14();
    সংরচনা s15 t15 = fr_s15();
    সংরচনা s16 t16 = fr_s16();
    সংরচনা s17 t17 = fr_s17();
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

শূন্য*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        সংরচনা X { পূর্ণাঙ্ক _x; };
        সংরচনা X *x = va_arg(ap, সংরচনা X *);
        ঘূৰাই x;
}

পূর্ণাঙ্ক match(ধ্রুৱ ৱর্ণ **s, ধ্রুৱ ৱর্ণ *f)
{
    ধ্রুৱ ৱর্ণ *p = *s;
    বাবে (p = *s; *f && *f == *p; f++, p++)
        ;
    যদি (!*f) {
        *s = p - 1;
        ঘূৰাই 1;
    }
    ঘূৰাই 0;
}

শূন্য myprintf(ধ্রুৱ ৱর্ণ *format, ...)
{
    ধ্রুৱ ৱর্ণ *s;
    va_list ap;
    va_start(ap, format);
    বাবে (s = format; *s; s++) {
        যদি (match(&s, "%7s")) {
            সংরচনা s7 t7 = va_arg(ap, সংরচনা s7);
            printf("%.7s", t7.x);
        }
        অন্যথা যদি (match(&s, "%9s")) {
            সংরচনা s9 t9 = va_arg(ap, সংরচনা s9);
            printf("%.9s", t9.x);
        }
        অন্যথা যদি (match(&s, "%hfa11")) {
            সংরচনা hfa11 x = va_arg(ap, সংরচনা hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        অন্যথা যদি (match(&s, "%hfa12")) {
            সংরচনা hfa12 x = va_arg(ap, সংরচনা hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        অন্যথা যদি (match(&s, "%hfa13")) {
            সংরচনা hfa13 x = va_arg(ap, সংরচনা hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        অন্যথা যদি (match(&s, "%hfa14")) {
            সংরচনা hfa14 x = va_arg(ap, সংরচনা hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        অন্যথা যদি (match(&s, "%hfa21")) {
            সংরচনা hfa21 x = va_arg(ap, সংরচনা hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        অন্যথা যদি (match(&s, "%hfa22")) {
            সংরচনা hfa22 x = va_arg(ap, সংরচনা hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        অন্যথা যদি (match(&s, "%hfa23")) {
            সংরচনা hfa23 x = va_arg(ap, সংরচনা hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        অন্যথা যদি (match(&s, "%hfa24")) {
            সংরচনা hfa24 x = va_arg(ap, সংরচনা hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        অন্যথা যদি (match(&s, "%hfa31")) {
            সংরচনা hfa31 x = va_arg(ap, সংরচনা hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        অন্যথা যদি (match(&s, "%hfa32")) {
            সংরচনা hfa32 x = va_arg(ap, সংরচনা hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        অন্যথা যদি (match(&s, "%hfa33")) {
            সংরচনা hfa33 x = va_arg(ap, সংরচনা hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        অন্যথা যদি (match(&s, "%hfa34")) {
            সংরচনা hfa34 x = va_arg(ap, সংরচনা hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        অন্যথা
            putchar(*s);
    }
    putchar('\n');
}

শূন্য stdarg(শূন্য)
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

শূন্য pll(unsigned long long x)
{
    printf("%llx\n", x);
}

শূন্য movi(শূন্য)
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

স্থির uint32_t addip0(uint32_t x) { ঘূৰাই x + 0; }
স্থির uint64_t sublp0(uint64_t x) { ঘূৰাই x - 0; }
স্থির uint32_t addip123(uint32_t x) { ঘূৰাই x + 123; }
স্থির uint64_t addlm123(uint64_t x) { ঘূৰাই x + -123; }
স্থির uint64_t sublp4095(uint64_t x) { ঘূৰাই x - 4095; }
স্থির uint32_t subim503808(uint32_t x) { ঘূৰাই x - -503808; }
স্থির uint64_t addp12345(uint64_t x) { ঘূৰাই x + 12345; }
স্থির uint32_t subp12345(uint32_t x) { ঘূৰাই x - 12345; }

স্থির uint32_t mvni(uint32_t x) { ঘূৰাই 0xffffffff - x; }
স্থির uint64_t negl(uint64_t x) { ঘূৰাই 0 - x; }
স্থির uint32_t rsbi123(uint32_t x) { ঘূৰাই 123 - x; }
স্থির uint64_t rsbl123(uint64_t x) { ঘূৰাই 123 - x; }

স্থির uint32_t andi0(uint32_t x) { ঘূৰাই x & 0; }
স্থির uint64_t andlm1(uint64_t x) { ঘূৰাই x & -1; }
স্থির uint64_t orrl0(uint64_t x) { ঘূৰাই x | 0; }
স্থির uint32_t orrim1(uint32_t x) { ঘূৰাই x | -1; }
স্থির uint32_t eori0(uint32_t x) { ঘূৰাই x ^ 0; }
স্থির uint64_t eorlm1(uint64_t x) { ঘূৰাই x ^ -1; }
স্থির uint32_t and0xf0(uint32_t x) { ঘূৰাই x & 0xf0; }
স্থির uint64_t orr0xf0(uint64_t x) { ঘূৰাই x | 0xf0; }
স্থির uint64_t eor0xf0(uint64_t x) { ঘূৰাই x ^ 0xf0; }

স্থির uint32_t lsli0(uint32_t x) { ঘূৰাই x << 0; }
স্থির uint32_t lsri0(uint32_t x) { ঘূৰাই x >> 0; }
স্থির int64_t asrl0(int64_t x) { ঘূৰাই x >> 0; }
স্থির uint32_t lsli1(uint32_t x) { ঘূৰাই x << 1; }
স্থির uint32_t lsli31(uint32_t x) { ঘূৰাই x << 31; }
স্থির uint64_t lsll1(uint64_t x) { ঘূৰাই x << 1; }
স্থির uint64_t lsll63(uint64_t x) { ঘূৰাই x << 63; }
স্থির uint32_t lsri1(uint32_t x) { ঘূৰাই x >> 1; }
স্থির uint32_t lsri31(uint32_t x) { ঘূৰাই x >> 31; }
স্থির uint64_t lsrl1(uint64_t x) { ঘূৰাই x >> 1; }
স্থির uint64_t lsrl63(uint64_t x) { ঘূৰাই x >> 63; }
স্থির int32_t asri1(int32_t x) { ঘূৰাই x >> 1; }
স্থির int32_t asri31(int32_t x) { ঘূৰাই x >> 31; }
স্থির int64_t asrl1(int64_t x) { ঘূৰাই x >> 1; }
স্থির int64_t asrl63(int64_t x) { ঘূৰাই x >> 63; }

শূন্য opi(শূন্য)
{
    পূর্ণাঙ্ক x = 1000;
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

শূন্য pcs(শূন্য)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

পূর্ণাঙ্ক main()
{
    pcs();
    ঘূৰাই 0;
}
