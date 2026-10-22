// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#అన్తర్భావ <stdarg.h>
#అన్తర్భావ <stdint.h>
#అన్తర్భావ <stdio.h>

నిర్మాణం s1 { అక్షరం x[1]; } s1 = { "0" };
నిర్మాణం s2 { అక్షరం x[2]; } s2 = { "12" };
నిర్మాణం s3 { అక్షరం x[3]; } s3 = { "345" };
నిర్మాణం s4 { అక్షరం x[4]; } s4 = { "6789" };
నిర్మాణం s5 { అక్షరం x[5]; } s5 = { "abcde" };
నిర్మాణం s6 { అక్షరం x[6]; } s6 = { "fghijk" };
నిర్మాణం s7 { అక్షరం x[7]; } s7 = { "lmnopqr" };
నిర్మాణం s8 { అక్షరం x[8]; } s8 = { "stuvwxyz" };
నిర్మాణం s9 { అక్షరం x[9]; } s9 = { "ABCDEFGHI" };
నిర్మాణం s10 { అక్షరం x[10]; } s10 = { "JKLMNOPQRS" };
నిర్మాణం s11 { అక్షరం x[11]; } s11 = { "TUVWXYZ0123" };
నిర్మాణం s12 { అక్షరం x[12]; } s12 = { "456789abcdef" };
నిర్మాణం s13 { అక్షరం x[13]; } s13 = { "ghijklmnopqrs" };
నిర్మాణం s14 { అక్షరం x[14]; } s14 = { "tuvwxyzABCDEFG" };
నిర్మాణం s15 { అక్షరం x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
నిర్మాణం s16 { అక్షరం x[16]; } s16 = { "WXYZ0123456789ab" };
నిర్మాణం s17 { అక్షరం x[17]; } s17 = { "cdefghijklmnopqrs" };

నిర్మాణం hfa11 { దశాంశం a; } hfa11 = { 11.1 };
నిర్మాణం hfa12 { దశాంశం a, b; } hfa12 = { 12.1, 12.2 };
నిర్మాణం hfa13 { దశాంశం a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
నిర్మాణం hfa14 { దశాంశం a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

నిర్మాణం hfa21 { ద్విగుణ a; } hfa21 = { 21.1 };
నిర్మాణం hfa22 { ద్విగుణ a, b; } hfa22 = { 22.1, 22.2 };
నిర్మాణం hfa23 { ద్విగుణ a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
నిర్మాణం hfa24 { ద్విగుణ a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

నిర్మాణం hfa31 { దీర్ఘ ద్విగుణ a; } hfa31 = { 31.1 };
నిర్మాణం hfa32 { దీర్ఘ ద్విగుణ a, b; } hfa32 = { 32.1, 32.2 };
నిర్మాణం hfa33 { దీర్ఘ ద్విగుణ a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
నిర్మాణం hfa34 { దీర్ఘ ద్విగుణ a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

నిర్మాణం ఖాళీలు { };
/* Keep the top-level offsets at zero without changing the type into a union. */
నిర్మాణం hfae12 { నిర్మాణం ఖాళీలు e; నిర్మాణం hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
నిర్మాణం hfae22 { నిర్మాణం ఖాళీలు e; నిర్మాణం hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

శూన్య fa_s1(నిర్మాణం s1 a) { రాయి("%.1s\n", a.x); }
శూన్య fa_s2(నిర్మాణం s2 a) { రాయి("%.2s\n", a.x); }
శూన్య fa_s3(నిర్మాణం s3 a) { రాయి("%.3s\n", a.x); }
శూన్య fa_s4(నిర్మాణం s4 a) { రాయి("%.4s\n", a.x); }
శూన్య fa_s5(నిర్మాణం s5 a) { రాయి("%.5s\n", a.x); }
శూన్య fa_s6(నిర్మాణం s6 a) { రాయి("%.6s\n", a.x); }
శూన్య fa_s7(నిర్మాణం s7 a) { రాయి("%.7s\n", a.x); }
శూన్య fa_s8(నిర్మాణం s8 a) { రాయి("%.8s\n", a.x); }
శూన్య fa_s9(నిర్మాణం s9 a) { రాయి("%.9s\n", a.x); }
శూన్య fa_s10(నిర్మాణం s10 a) { రాయి("%.10s\n", a.x); }
శూన్య fa_s11(నిర్మాణం s11 a) { రాయి("%.11s\n", a.x); }
శూన్య fa_s12(నిర్మాణం s12 a) { రాయి("%.12s\n", a.x); }
శూన్య fa_s13(నిర్మాణం s13 a) { రాయి("%.13s\n", a.x); }
శూన్య fa_s14(నిర్మాణం s14 a) { రాయి("%.14s\n", a.x); }
శూన్య fa_s15(నిర్మాణం s15 a) { రాయి("%.15s\n", a.x); }
శూన్య fa_s16(నిర్మాణం s16 a) { రాయి("%.16s\n", a.x); }
శూన్య fa_s17(నిర్మాణం s17 a) { రాయి("%.17s\n", a.x); }

శూన్య fa_hfa11(నిర్మాణం hfa11 a)
{ రాయి("%.1f\n", a.a); }
శూన్య fa_hfa12(నిర్మాణం hfa12 a)
{ రాయి("%.1f %.1f\n", a.a, a.a); }
శూన్య fa_hfa13(నిర్మాణం hfa13 a)
{ రాయి("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
శూన్య fa_hfa14(నిర్మాణం hfa14 a)
{ రాయి("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

శూన్య fa_hfa21(నిర్మాణం hfa21 a)
{ రాయి("%.1f\n", a.a); }
శూన్య fa_hfa22(నిర్మాణం hfa22 a)
{ రాయి("%.1f %.1f\n", a.a, a.a); }
శూన్య fa_hfa23(నిర్మాణం hfa23 a)
{ రాయి("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
శూన్య fa_hfa24(నిర్మాణం hfa24 a)
{ రాయి("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

శూన్య fa_hfa31(నిర్మాణం hfa31 a)
{ రాయి("%.1Lf\n", a.a); }
శూన్య fa_hfa32(నిర్మాణం hfa32 a)
{ రాయి("%.1Lf %.1Lf\n", a.a, a.a); }
శూన్య fa_hfa33(నిర్మాణం hfa33 a)
{ రాయి("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
శూన్య fa_hfa34(నిర్మాణం hfa34 a)
{ రాయి("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
శూన్య fa_hfae12(నిర్మాణం hfae12 a)
{ రాయి("%.1f %.1f\n", a.h.a, a.h.b); }
శూన్య fa_hfae22(నిర్మాణం hfae22 a)
{ రాయి("%.1f %.1f\n", a.h.a, a.h.b); }

శూన్య fa1(నిర్మాణం s8 a, నిర్మాణం s9 b, నిర్మాణం s10 c, నిర్మాణం s11 d,
         నిర్మాణం s12 e, నిర్మాణం s13 f)
{
    రాయి("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

శూన్య fa2(నిర్మాణం s9 a, నిర్మాణం s10 b, నిర్మాణం s11 c, నిర్మాణం s12 d,
         నిర్మాణం s13 e, నిర్మాణం s14 f)
{
    రాయి("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

శూన్య fa3(నిర్మాణం hfa14 a, నిర్మాణం hfa23 b, నిర్మాణం hfa32 c)
{
    రాయి("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

శూన్య fa4(నిర్మాణం s1 a, నిర్మాణం hfa14 b, నిర్మాణం s2 c, నిర్మాణం hfa24 d,
         నిర్మాణం s3 e, నిర్మాణం hfa34 f)
{
    రాయి("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

శూన్య arg(శూన్య)
{
    రాయి("Arguments:\n");
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

నిర్మాణం s1 fr_s1(శూన్య) { తిరిగి s1; }
నిర్మాణం s2 fr_s2(శూన్య) { తిరిగి s2; }
నిర్మాణం s3 fr_s3(శూన్య) { తిరిగి s3; }
నిర్మాణం s4 fr_s4(శూన్య) { తిరిగి s4; }
నిర్మాణం s5 fr_s5(శూన్య) { తిరిగి s5; }
నిర్మాణం s6 fr_s6(శూన్య) { తిరిగి s6; }
నిర్మాణం s7 fr_s7(శూన్య) { తిరిగి s7; }
నిర్మాణం s8 fr_s8(శూన్య) { తిరిగి s8; }
నిర్మాణం s9 fr_s9(శూన్య) { తిరిగి s9; }
నిర్మాణం s10 fr_s10(శూన్య) { తిరిగి s10; }
నిర్మాణం s11 fr_s11(శూన్య) { తిరిగి s11; }
నిర్మాణం s12 fr_s12(శూన్య) { తిరిగి s12; }
నిర్మాణం s13 fr_s13(శూన్య) { తిరిగి s13; }
నిర్మాణం s14 fr_s14(శూన్య) { తిరిగి s14; }
నిర్మాణం s15 fr_s15(శూన్య) { తిరిగి s15; }
నిర్మాణం s16 fr_s16(శూన్య) { తిరిగి s16; }
నిర్మాణం s17 fr_s17(శూన్య) { తిరిగి s17; }

నిర్మాణం hfa11 fr_hfa11(శూన్య) { తిరిగి hfa11; }
నిర్మాణం hfa12 fr_hfa12(శూన్య) { తిరిగి hfa12; }
నిర్మాణం hfa13 fr_hfa13(శూన్య) { తిరిగి hfa13; }
నిర్మాణం hfa14 fr_hfa14(శూన్య) { తిరిగి hfa14; }

నిర్మాణం hfa21 fr_hfa21(శూన్య) { తిరిగి hfa21; }
నిర్మాణం hfa22 fr_hfa22(శూన్య) { తిరిగి hfa22; }
నిర్మాణం hfa23 fr_hfa23(శూన్య) { తిరిగి hfa23; }
నిర్మాణం hfa24 fr_hfa24(శూన్య) { తిరిగి hfa24; }

నిర్మాణం hfa31 fr_hfa31(శూన్య) { తిరిగి hfa31; }
నిర్మాణం hfa32 fr_hfa32(శూన్య) { తిరిగి hfa32; }
నిర్మాణం hfa33 fr_hfa33(శూన్య) { తిరిగి hfa33; }
నిర్మాణం hfa34 fr_hfa34(శూన్య) { తిరిగి hfa34; }
నిర్మాణం hfae12 fr_hfae12(శూన్య) { తిరిగి hfae12; }
నిర్మాణం hfae22 fr_hfae22(శూన్య) { తిరిగి hfae22; }

శూన్య ret(శూన్య)
{
    నిర్మాణం s1 t1 = fr_s1();
    నిర్మాణం s2 t2 = fr_s2();
    నిర్మాణం s3 t3 = fr_s3();
    నిర్మాణం s4 t4 = fr_s4();
    నిర్మాణం s5 t5 = fr_s5();
    నిర్మాణం s6 t6 = fr_s6();
    నిర్మాణం s7 t7 = fr_s7();
    నిర్మాణం s8 t8 = fr_s8();
    నిర్మాణం s9 t9 = fr_s9();
    నిర్మాణం s10 t10 = fr_s10();
    నిర్మాణం s11 t11 = fr_s11();
    నిర్మాణం s12 t12 = fr_s12();
    నిర్మాణం s13 t13 = fr_s13();
    నిర్మాణం s14 t14 = fr_s14();
    నిర్మాణం s15 t15 = fr_s15();
    నిర్మాణం s16 t16 = fr_s16();
    నిర్మాణం s17 t17 = fr_s17();
    రాయి("Return values:\n");
    రాయి("%.1s\n", t1.x);
    రాయి("%.2s\n", t2.x);
    రాయి("%.3s\n", t3.x);
    రాయి("%.4s\n", t4.x);
    రాయి("%.5s\n", t5.x);
    రాయి("%.6s\n", t6.x);
    రాయి("%.7s\n", t7.x);
    రాయి("%.8s\n", t8.x);
    రాయి("%.9s\n", t9.x);
    రాయి("%.10s\n", t10.x);
    రాయి("%.11s\n", t11.x);
    రాయి("%.12s\n", t12.x);
    రాయి("%.13s\n", t13.x);
    రాయి("%.14s\n", t14.x);
    రాయి("%.15s\n", t15.x);
    రాయి("%.16s\n", t16.x);
    రాయి("%.17s\n", t17.x);
    రాయి("%.1f\n", fr_hfa11().a);
    రాయి("%.1f %.1f\n", fr_hfa12().a, fr_hfa12().b);
    రాయి("%.1f %.1f\n", fr_hfa13().a, fr_hfa13().c);
    రాయి("%.1f %.1f\n", fr_hfa14().a, fr_hfa14().d);
    రాయి("%.1f\n", fr_hfa21().a);
    రాయి("%.1f %.1f\n", fr_hfa22().a, fr_hfa22().b);
    రాయి("%.1f %.1f\n", fr_hfa23().a, fr_hfa23().c);
    రాయి("%.1f %.1f\n", fr_hfa24().a, fr_hfa24().d);
    రాయి("%.1Lf\n", fr_hfa31().a);
    రాయి("%.1Lf %.1Lf\n", fr_hfa32().a, fr_hfa32().b);
    రాయి("%.1Lf %.1Lf\n", fr_hfa33().a, fr_hfa33().c);
    రాయి("%.1Lf %.1Lf\n", fr_hfa34().a, fr_hfa34().d);
    రాయి("%.1f %.1f\n", fr_hfae12().h.a, fr_hfae12().h.b);
    రాయి("%.1f %.1f\n", fr_hfae22().h.a, fr_hfae22().h.b);
}

శూన్య*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        నిర్మాణం X { పూర్ణాంకం _x; };
        నిర్మాణం X *x = va_arg(ap, నిర్మాణం X *);
        తిరిగి x;
}

పూర్ణాంకం సరిపోలిక(స్థిరరాశి అక్షరం **s, స్థిరరాశి అక్షరం *f)
{
    స్థిరరాశి అక్షరం *p = *s;
    కొరకు (p = *s; *f && *f == *p; f++, p++)
        ;
    ఒకవేళ (!*f) {
        *s = p - 1;
        తిరిగి 1;
    }
    తిరిగి 0;
}

శూన్య myprintf(స్థిరరాశి అక్షరం *format, ...)
{
    స్థిరరాశి అక్షరం *s;
    va_list ap;
    va_start(ap, format);
    కొరకు (s = format; *s; s++) {
        ఒకవేళ (సరిపోలిక(&s, "%7s")) {
            నిర్మాణం s7 t7 = va_arg(ap, నిర్మాణం s7);
            రాయి("%.7s", t7.x);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%9s")) {
            నిర్మాణం s9 t9 = va_arg(ap, నిర్మాణం s9);
            రాయి("%.9s", t9.x);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa11")) {
            నిర్మాణం hfa11 x = va_arg(ap, నిర్మాణం hfa11);
            రాయి("%.1f,%.1f", x.a, x.a);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa12")) {
            నిర్మాణం hfa12 x = va_arg(ap, నిర్మాణం hfa12);
            రాయి("%.1f,%.1f", x.a, x.b);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa13")) {
            నిర్మాణం hfa13 x = va_arg(ap, నిర్మాణం hfa13);
            రాయి("%.1f,%.1f", x.a, x.c);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa14")) {
            నిర్మాణం hfa14 x = va_arg(ap, నిర్మాణం hfa14);
            రాయి("%.1f,%.1f", x.a, x.d);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa21")) {
            నిర్మాణం hfa21 x = va_arg(ap, నిర్మాణం hfa21);
            రాయి("%.1f,%.1f", x.a, x.a);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa22")) {
            నిర్మాణం hfa22 x = va_arg(ap, నిర్మాణం hfa22);
            రాయి("%.1f,%.1f", x.a, x.b);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa23")) {
            నిర్మాణం hfa23 x = va_arg(ap, నిర్మాణం hfa23);
            రాయి("%.1f,%.1f", x.a, x.c);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa24")) {
            నిర్మాణం hfa24 x = va_arg(ap, నిర్మాణం hfa24);
            రాయి("%.1f,%.1f", x.a, x.d);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa31")) {
            నిర్మాణం hfa31 x = va_arg(ap, నిర్మాణం hfa31);
            రాయి("%.1Lf,%.1Lf", x.a, x.a);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa32")) {
            నిర్మాణం hfa32 x = va_arg(ap, నిర్మాణం hfa32);
            రాయి("%.1Lf,%.1Lf", x.a, x.b);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa33")) {
            నిర్మాణం hfa33 x = va_arg(ap, నిర్మాణం hfa33);
            రాయి("%.1Lf,%.1Lf", x.a, x.c);
        }
        లేకపోతే ఒకవేళ (సరిపోలిక(&s, "%hfa34")) {
            నిర్మాణం hfa34 x = va_arg(ap, నిర్మాణం hfa34);
            రాయి("%.1Lf,%.1Lf", x.a, x.d);
        }
        లేకపోతే
            అక్షరం_రాయి(*s);
    }
    అక్షరం_రాయి('\n');
}

శూన్య stdarg(శూన్య)
{
    రాయి("stdarg:\n");
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

శూన్య pll(గుర్తులేని దీర్ఘ దీర్ఘ x)
{
    రాయి("%llx\n", x);
}

శూన్య movi(శూన్య)
{
    రాయి("MOVI:\n");
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

స్థిర uint32_t addip0(uint32_t x) { తిరిగి x + 0; }
స్థిర uint64_t sublp0(uint64_t x) { తిరిగి x - 0; }
స్థిర uint32_t addip123(uint32_t x) { తిరిగి x + 123; }
స్థిర uint64_t addlm123(uint64_t x) { తిరిగి x + -123; }
స్థిర uint64_t sublp4095(uint64_t x) { తిరిగి x - 4095; }
స్థిర uint32_t subim503808(uint32_t x) { తిరిగి x - -503808; }
స్థిర uint64_t addp12345(uint64_t x) { తిరిగి x + 12345; }
స్థిర uint32_t subp12345(uint32_t x) { తిరిగి x - 12345; }

స్థిర uint32_t mvni(uint32_t x) { తిరిగి 0xffffffff - x; }
స్థిర uint64_t negl(uint64_t x) { తిరిగి 0 - x; }
స్థిర uint32_t rsbi123(uint32_t x) { తిరిగి 123 - x; }
స్థిర uint64_t rsbl123(uint64_t x) { తిరిగి 123 - x; }

స్థిర uint32_t andi0(uint32_t x) { తిరిగి x & 0; }
స్థిర uint64_t andlm1(uint64_t x) { తిరిగి x & -1; }
స్థిర uint64_t orrl0(uint64_t x) { తిరిగి x | 0; }
స్థిర uint32_t orrim1(uint32_t x) { తిరిగి x | -1; }
స్థిర uint32_t eori0(uint32_t x) { తిరిగి x ^ 0; }
స్థిర uint64_t eorlm1(uint64_t x) { తిరిగి x ^ -1; }
స్థిర uint32_t and0xf0(uint32_t x) { తిరిగి x & 0xf0; }
స్థిర uint64_t orr0xf0(uint64_t x) { తిరిగి x | 0xf0; }
స్థిర uint64_t eor0xf0(uint64_t x) { తిరిగి x ^ 0xf0; }

స్థిర uint32_t lsli0(uint32_t x) { తిరిగి x << 0; }
స్థిర uint32_t lsri0(uint32_t x) { తిరిగి x >> 0; }
స్థిర int64_t asrl0(int64_t x) { తిరిగి x >> 0; }
స్థిర uint32_t lsli1(uint32_t x) { తిరిగి x << 1; }
స్థిర uint32_t lsli31(uint32_t x) { తిరిగి x << 31; }
స్థిర uint64_t lsll1(uint64_t x) { తిరిగి x << 1; }
స్థిర uint64_t lsll63(uint64_t x) { తిరిగి x << 63; }
స్థిర uint32_t lsri1(uint32_t x) { తిరిగి x >> 1; }
స్థిర uint32_t lsri31(uint32_t x) { తిరిగి x >> 31; }
స్థిర uint64_t lsrl1(uint64_t x) { తిరిగి x >> 1; }
స్థిర uint64_t lsrl63(uint64_t x) { తిరిగి x >> 63; }
స్థిర int32_t asri1(int32_t x) { తిరిగి x >> 1; }
స్థిర int32_t asri31(int32_t x) { తిరిగి x >> 31; }
స్థిర int64_t asrl1(int64_t x) { తిరిగి x >> 1; }
స్థిర int64_t asrl63(int64_t x) { తిరిగి x >> 63; }

శూన్య opi(శూన్య)
{
    పూర్ణాంకం x = 1000;
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

శూన్య pcs(శూన్య)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

పూర్ణాంకం ప్రధాన()
{
    pcs();
    తిరిగి 0;
}
