// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#شامل <stdarg.h>
#شامل <stdint.h>
#شامل <stdio.h>

ساخت s1 { حرف x[1]; } s1 = { "0" };
ساخت s2 { حرف x[2]; } s2 = { "12" };
ساخت s3 { حرف x[3]; } s3 = { "345" };
ساخت s4 { حرف x[4]; } s4 = { "6789" };
ساخت s5 { حرف x[5]; } s5 = { "abcde" };
ساخت s6 { حرف x[6]; } s6 = { "fghijk" };
ساخت s7 { حرف x[7]; } s7 = { "lmnopqr" };
ساخت s8 { حرف x[8]; } s8 = { "stuvwxyz" };
ساخت s9 { حرف x[9]; } s9 = { "ABCDEFGHI" };
ساخت s10 { حرف x[10]; } s10 = { "JKLMNOPQRS" };
ساخت s11 { حرف x[11]; } s11 = { "TUVWXYZ0123" };
ساخت s12 { حرف x[12]; } s12 = { "456789abcdef" };
ساخت s13 { حرف x[13]; } s13 = { "ghijklmnopqrs" };
ساخت s14 { حرف x[14]; } s14 = { "tuvwxyzABCDEFG" };
ساخت s15 { حرف x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
ساخت s16 { حرف x[16]; } s16 = { "WXYZ0123456789ab" };
ساخت s17 { حرف x[17]; } s17 = { "cdefghijklmnopqrs" };

ساخت hfa11 { اعشاری a; } hfa11 = { 11.1 };
ساخت hfa12 { اعشاری a, b; } hfa12 = { 12.1, 12.2 };
ساخت hfa13 { اعشاری a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
ساخت hfa14 { اعشاری a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

ساخت hfa21 { دوہرا a; } hfa21 = { 21.1 };
ساخت hfa22 { دوہرا a, b; } hfa22 = { 22.1, 22.2 };
ساخت hfa23 { دوہرا a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
ساخت hfa24 { دوہرا a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

ساخت hfa31 { طویل دوہرا a; } hfa31 = { 31.1 };
ساخت hfa32 { طویل دوہرا a, b; } hfa32 = { 32.1, 32.2 };
ساخت hfa33 { طویل دوہرا a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
ساخت hfa34 { طویل دوہرا a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

ساخت خالی_خانے { };
/* Keep the top-level offsets at zero without changing the type into a union. */
ساخت hfae12 { ساخت خالی_خانے e; ساخت hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
ساخت hfae22 { ساخت خالی_خانے e; ساخت hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

خالی fa_s1(ساخت s1 a) { لکھو("%.1s\n", a.x); }
خالی fa_s2(ساخت s2 a) { لکھو("%.2s\n", a.x); }
خالی fa_s3(ساخت s3 a) { لکھو("%.3s\n", a.x); }
خالی fa_s4(ساخت s4 a) { لکھو("%.4s\n", a.x); }
خالی fa_s5(ساخت s5 a) { لکھو("%.5s\n", a.x); }
خالی fa_s6(ساخت s6 a) { لکھو("%.6s\n", a.x); }
خالی fa_s7(ساخت s7 a) { لکھو("%.7s\n", a.x); }
خالی fa_s8(ساخت s8 a) { لکھو("%.8s\n", a.x); }
خالی fa_s9(ساخت s9 a) { لکھو("%.9s\n", a.x); }
خالی fa_s10(ساخت s10 a) { لکھو("%.10s\n", a.x); }
خالی fa_s11(ساخت s11 a) { لکھو("%.11s\n", a.x); }
خالی fa_s12(ساخت s12 a) { لکھو("%.12s\n", a.x); }
خالی fa_s13(ساخت s13 a) { لکھو("%.13s\n", a.x); }
خالی fa_s14(ساخت s14 a) { لکھو("%.14s\n", a.x); }
خالی fa_s15(ساخت s15 a) { لکھو("%.15s\n", a.x); }
خالی fa_s16(ساخت s16 a) { لکھو("%.16s\n", a.x); }
خالی fa_s17(ساخت s17 a) { لکھو("%.17s\n", a.x); }

خالی fa_hfa11(ساخت hfa11 a)
{ لکھو("%.1f\n", a.a); }
خالی fa_hfa12(ساخت hfa12 a)
{ لکھو("%.1f %.1f\n", a.a, a.a); }
خالی fa_hfa13(ساخت hfa13 a)
{ لکھو("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
خالی fa_hfa14(ساخت hfa14 a)
{ لکھو("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

خالی fa_hfa21(ساخت hfa21 a)
{ لکھو("%.1f\n", a.a); }
خالی fa_hfa22(ساخت hfa22 a)
{ لکھو("%.1f %.1f\n", a.a, a.a); }
خالی fa_hfa23(ساخت hfa23 a)
{ لکھو("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
خالی fa_hfa24(ساخت hfa24 a)
{ لکھو("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

خالی fa_hfa31(ساخت hfa31 a)
{ لکھو("%.1Lf\n", a.a); }
خالی fa_hfa32(ساخت hfa32 a)
{ لکھو("%.1Lf %.1Lf\n", a.a, a.a); }
خالی fa_hfa33(ساخت hfa33 a)
{ لکھو("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
خالی fa_hfa34(ساخت hfa34 a)
{ لکھو("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
خالی fa_hfae12(ساخت hfae12 a)
{ لکھو("%.1f %.1f\n", a.h.a, a.h.b); }
خالی fa_hfae22(ساخت hfae22 a)
{ لکھو("%.1f %.1f\n", a.h.a, a.h.b); }

خالی fa1(ساخت s8 a, ساخت s9 b, ساخت s10 c, ساخت s11 d,
         ساخت s12 e, ساخت s13 f)
{
    لکھو("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

خالی fa2(ساخت s9 a, ساخت s10 b, ساخت s11 c, ساخت s12 d,
         ساخت s13 e, ساخت s14 f)
{
    لکھو("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

خالی fa3(ساخت hfa14 a, ساخت hfa23 b, ساخت hfa32 c)
{
    لکھو("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

خالی fa4(ساخت s1 a, ساخت hfa14 b, ساخت s2 c, ساخت hfa24 d,
         ساخت s3 e, ساخت hfa34 f)
{
    لکھو("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

خالی arg(خالی)
{
    لکھو("Arguments:\n");
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

ساخت s1 fr_s1(خالی) { واپس s1; }
ساخت s2 fr_s2(خالی) { واپس s2; }
ساخت s3 fr_s3(خالی) { واپس s3; }
ساخت s4 fr_s4(خالی) { واپس s4; }
ساخت s5 fr_s5(خالی) { واپس s5; }
ساخت s6 fr_s6(خالی) { واپس s6; }
ساخت s7 fr_s7(خالی) { واپس s7; }
ساخت s8 fr_s8(خالی) { واپس s8; }
ساخت s9 fr_s9(خالی) { واپس s9; }
ساخت s10 fr_s10(خالی) { واپس s10; }
ساخت s11 fr_s11(خالی) { واپس s11; }
ساخت s12 fr_s12(خالی) { واپس s12; }
ساخت s13 fr_s13(خالی) { واپس s13; }
ساخت s14 fr_s14(خالی) { واپس s14; }
ساخت s15 fr_s15(خالی) { واپس s15; }
ساخت s16 fr_s16(خالی) { واپس s16; }
ساخت s17 fr_s17(خالی) { واپس s17; }

ساخت hfa11 fr_hfa11(خالی) { واپس hfa11; }
ساخت hfa12 fr_hfa12(خالی) { واپس hfa12; }
ساخت hfa13 fr_hfa13(خالی) { واپس hfa13; }
ساخت hfa14 fr_hfa14(خالی) { واپس hfa14; }

ساخت hfa21 fr_hfa21(خالی) { واپس hfa21; }
ساخت hfa22 fr_hfa22(خالی) { واپس hfa22; }
ساخت hfa23 fr_hfa23(خالی) { واپس hfa23; }
ساخت hfa24 fr_hfa24(خالی) { واپس hfa24; }

ساخت hfa31 fr_hfa31(خالی) { واپس hfa31; }
ساخت hfa32 fr_hfa32(خالی) { واپس hfa32; }
ساخت hfa33 fr_hfa33(خالی) { واپس hfa33; }
ساخت hfa34 fr_hfa34(خالی) { واپس hfa34; }
ساخت hfae12 fr_hfae12(خالی) { واپس hfae12; }
ساخت hfae22 fr_hfae22(خالی) { واپس hfae22; }

خالی ret(خالی)
{
    ساخت s1 t1 = fr_s1();
    ساخت s2 t2 = fr_s2();
    ساخت s3 t3 = fr_s3();
    ساخت s4 t4 = fr_s4();
    ساخت s5 t5 = fr_s5();
    ساخت s6 t6 = fr_s6();
    ساخت s7 t7 = fr_s7();
    ساخت s8 t8 = fr_s8();
    ساخت s9 t9 = fr_s9();
    ساخت s10 t10 = fr_s10();
    ساخت s11 t11 = fr_s11();
    ساخت s12 t12 = fr_s12();
    ساخت s13 t13 = fr_s13();
    ساخت s14 t14 = fr_s14();
    ساخت s15 t15 = fr_s15();
    ساخت s16 t16 = fr_s16();
    ساخت s17 t17 = fr_s17();
    لکھو("Return values:\n");
    لکھو("%.1s\n", t1.x);
    لکھو("%.2s\n", t2.x);
    لکھو("%.3s\n", t3.x);
    لکھو("%.4s\n", t4.x);
    لکھو("%.5s\n", t5.x);
    لکھو("%.6s\n", t6.x);
    لکھو("%.7s\n", t7.x);
    لکھو("%.8s\n", t8.x);
    لکھو("%.9s\n", t9.x);
    لکھو("%.10s\n", t10.x);
    لکھو("%.11s\n", t11.x);
    لکھو("%.12s\n", t12.x);
    لکھو("%.13s\n", t13.x);
    لکھو("%.14s\n", t14.x);
    لکھو("%.15s\n", t15.x);
    لکھو("%.16s\n", t16.x);
    لکھو("%.17s\n", t17.x);
    لکھو("%.1f\n", fr_hfa11().a);
    لکھو("%.1f %.1f\n", fr_hfa12().a, fr_hfa12().b);
    لکھو("%.1f %.1f\n", fr_hfa13().a, fr_hfa13().c);
    لکھو("%.1f %.1f\n", fr_hfa14().a, fr_hfa14().d);
    لکھو("%.1f\n", fr_hfa21().a);
    لکھو("%.1f %.1f\n", fr_hfa22().a, fr_hfa22().b);
    لکھو("%.1f %.1f\n", fr_hfa23().a, fr_hfa23().c);
    لکھو("%.1f %.1f\n", fr_hfa24().a, fr_hfa24().d);
    لکھو("%.1Lf\n", fr_hfa31().a);
    لکھو("%.1Lf %.1Lf\n", fr_hfa32().a, fr_hfa32().b);
    لکھو("%.1Lf %.1Lf\n", fr_hfa33().a, fr_hfa33().c);
    لکھو("%.1Lf %.1Lf\n", fr_hfa34().a, fr_hfa34().d);
    لکھو("%.1f %.1f\n", fr_hfae12().h.a, fr_hfae12().h.b);
    لکھو("%.1f %.1f\n", fr_hfae22().h.a, fr_hfae22().h.b);
}

خالی*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        ساخت X { صحیح _x; };
        ساخت X *x = va_arg(ap, ساخت X *);
        واپس x;
}

صحیح مطابقت(ثابت حرف **s, ثابت حرف *f)
{
    ثابت حرف *p = *s;
    برائے (p = *s; *f && *f == *p; f++, p++)
        ;
    اگر (!*f) {
        *s = p - 1;
        واپس 1;
    }
    واپس 0;
}

خالی myprintf(ثابت حرف *format, ...)
{
    ثابت حرف *s;
    va_list ap;
    va_start(ap, format);
    برائے (s = format; *s; s++) {
        اگر (مطابقت(&s, "%7s")) {
            ساخت s7 t7 = va_arg(ap, ساخت s7);
            لکھو("%.7s", t7.x);
        }
        ورنہ اگر (مطابقت(&s, "%9s")) {
            ساخت s9 t9 = va_arg(ap, ساخت s9);
            لکھو("%.9s", t9.x);
        }
        ورنہ اگر (مطابقت(&s, "%hfa11")) {
            ساخت hfa11 x = va_arg(ap, ساخت hfa11);
            لکھو("%.1f,%.1f", x.a, x.a);
        }
        ورنہ اگر (مطابقت(&s, "%hfa12")) {
            ساخت hfa12 x = va_arg(ap, ساخت hfa12);
            لکھو("%.1f,%.1f", x.a, x.b);
        }
        ورنہ اگر (مطابقت(&s, "%hfa13")) {
            ساخت hfa13 x = va_arg(ap, ساخت hfa13);
            لکھو("%.1f,%.1f", x.a, x.c);
        }
        ورنہ اگر (مطابقت(&s, "%hfa14")) {
            ساخت hfa14 x = va_arg(ap, ساخت hfa14);
            لکھو("%.1f,%.1f", x.a, x.d);
        }
        ورنہ اگر (مطابقت(&s, "%hfa21")) {
            ساخت hfa21 x = va_arg(ap, ساخت hfa21);
            لکھو("%.1f,%.1f", x.a, x.a);
        }
        ورنہ اگر (مطابقت(&s, "%hfa22")) {
            ساخت hfa22 x = va_arg(ap, ساخت hfa22);
            لکھو("%.1f,%.1f", x.a, x.b);
        }
        ورنہ اگر (مطابقت(&s, "%hfa23")) {
            ساخت hfa23 x = va_arg(ap, ساخت hfa23);
            لکھو("%.1f,%.1f", x.a, x.c);
        }
        ورنہ اگر (مطابقت(&s, "%hfa24")) {
            ساخت hfa24 x = va_arg(ap, ساخت hfa24);
            لکھو("%.1f,%.1f", x.a, x.d);
        }
        ورنہ اگر (مطابقت(&s, "%hfa31")) {
            ساخت hfa31 x = va_arg(ap, ساخت hfa31);
            لکھو("%.1Lf,%.1Lf", x.a, x.a);
        }
        ورنہ اگر (مطابقت(&s, "%hfa32")) {
            ساخت hfa32 x = va_arg(ap, ساخت hfa32);
            لکھو("%.1Lf,%.1Lf", x.a, x.b);
        }
        ورنہ اگر (مطابقت(&s, "%hfa33")) {
            ساخت hfa33 x = va_arg(ap, ساخت hfa33);
            لکھو("%.1Lf,%.1Lf", x.a, x.c);
        }
        ورنہ اگر (مطابقت(&s, "%hfa34")) {
            ساخت hfa34 x = va_arg(ap, ساخت hfa34);
            لکھو("%.1Lf,%.1Lf", x.a, x.d);
        }
        ورنہ
            حرف_لکھو(*s);
    }
    حرف_لکھو('\n');
}

خالی stdarg(خالی)
{
    لکھو("stdarg:\n");
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

خالی pll(غیرعلامتی طویل طویل x)
{
    لکھو("%llx\n", x);
}

خالی movi(خالی)
{
    لکھو("MOVI:\n");
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

ساکن uint32_t addip0(uint32_t x) { واپس x + 0; }
ساکن uint64_t sublp0(uint64_t x) { واپس x - 0; }
ساکن uint32_t addip123(uint32_t x) { واپس x + 123; }
ساکن uint64_t addlm123(uint64_t x) { واپس x + -123; }
ساکن uint64_t sublp4095(uint64_t x) { واپس x - 4095; }
ساکن uint32_t subim503808(uint32_t x) { واپس x - -503808; }
ساکن uint64_t addp12345(uint64_t x) { واپس x + 12345; }
ساکن uint32_t subp12345(uint32_t x) { واپس x - 12345; }

ساکن uint32_t mvni(uint32_t x) { واپس 0xffffffff - x; }
ساکن uint64_t negl(uint64_t x) { واپس 0 - x; }
ساکن uint32_t rsbi123(uint32_t x) { واپس 123 - x; }
ساکن uint64_t rsbl123(uint64_t x) { واپس 123 - x; }

ساکن uint32_t andi0(uint32_t x) { واپس x & 0; }
ساکن uint64_t andlm1(uint64_t x) { واپس x & -1; }
ساکن uint64_t orrl0(uint64_t x) { واپس x | 0; }
ساکن uint32_t orrim1(uint32_t x) { واپس x | -1; }
ساکن uint32_t eori0(uint32_t x) { واپس x ^ 0; }
ساکن uint64_t eorlm1(uint64_t x) { واپس x ^ -1; }
ساکن uint32_t and0xf0(uint32_t x) { واپس x & 0xf0; }
ساکن uint64_t orr0xf0(uint64_t x) { واپس x | 0xf0; }
ساکن uint64_t eor0xf0(uint64_t x) { واپس x ^ 0xf0; }

ساکن uint32_t lsli0(uint32_t x) { واپس x << 0; }
ساکن uint32_t lsri0(uint32_t x) { واپس x >> 0; }
ساکن int64_t asrl0(int64_t x) { واپس x >> 0; }
ساکن uint32_t lsli1(uint32_t x) { واپس x << 1; }
ساکن uint32_t lsli31(uint32_t x) { واپس x << 31; }
ساکن uint64_t lsll1(uint64_t x) { واپس x << 1; }
ساکن uint64_t lsll63(uint64_t x) { واپس x << 63; }
ساکن uint32_t lsri1(uint32_t x) { واپس x >> 1; }
ساکن uint32_t lsri31(uint32_t x) { واپس x >> 31; }
ساکن uint64_t lsrl1(uint64_t x) { واپس x >> 1; }
ساکن uint64_t lsrl63(uint64_t x) { واپس x >> 63; }
ساکن int32_t asri1(int32_t x) { واپس x >> 1; }
ساکن int32_t asri31(int32_t x) { واپس x >> 31; }
ساکن int64_t asrl1(int64_t x) { واپس x >> 1; }
ساکن int64_t asrl63(int64_t x) { واپس x >> 63; }

خالی opi(خالی)
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

خالی pcs(خالی)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

صحیح مین()
{
    pcs();
    واپس 0;
}
