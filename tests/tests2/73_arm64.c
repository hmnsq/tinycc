// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#समावेश <stdarg.h>
#समावेश <stdint.h>
#समावेश <stdio.h>

काष्ठा s1 { अक्षर x[1]; } s1 = { "0" };
काष्ठा s2 { अक्षर x[2]; } s2 = { "12" };
काष्ठा s3 { अक्षर x[3]; } s3 = { "345" };
काष्ठा s4 { अक्षर x[4]; } s4 = { "6789" };
काष्ठा s5 { अक्षर x[5]; } s5 = { "abcde" };
काष्ठा s6 { अक्षर x[6]; } s6 = { "fghijk" };
काष्ठा s7 { अक्षर x[7]; } s7 = { "lmnopqr" };
काष्ठा s8 { अक्षर x[8]; } s8 = { "stuvwxyz" };
काष्ठा s9 { अक्षर x[9]; } s9 = { "ABCDEFGHI" };
काष्ठा s10 { अक्षर x[10]; } s10 = { "JKLMNOPQRS" };
काष्ठा s11 { अक्षर x[11]; } s11 = { "TUVWXYZ0123" };
काष्ठा s12 { अक्षर x[12]; } s12 = { "456789abcdef" };
काष्ठा s13 { अक्षर x[13]; } s13 = { "ghijklmnopqrs" };
काष्ठा s14 { अक्षर x[14]; } s14 = { "tuvwxyzABCDEFG" };
काष्ठा s15 { अक्षर x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
काष्ठा s16 { अक्षर x[16]; } s16 = { "WXYZ0123456789ab" };
काष्ठा s17 { अक्षर x[17]; } s17 = { "cdefghijklmnopqrs" };

काष्ठा hfa11 { भग्न a; } hfa11 = { 11.1 };
काष्ठा hfa12 { भग्न a, b; } hfa12 = { 12.1, 12.2 };
काष्ठा hfa13 { भग्न a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
काष्ठा hfa14 { भग्न a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

काष्ठा hfa21 { द्विगुन a; } hfa21 = { 21.1 };
काष्ठा hfa22 { द्विगुन a, b; } hfa22 = { 22.1, 22.2 };
काष्ठा hfa23 { द्विगुन a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
काष्ठा hfa24 { द्विगुन a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

काष्ठा hfa31 { दीर्घ द्विगुन a; } hfa31 = { 31.1 };
काष्ठा hfa32 { दीर्घ द्विगुन a, b; } hfa32 = { 32.1, 32.2 };
काष्ठा hfa33 { दीर्घ द्विगुन a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
काष्ठा hfa34 { दीर्घ द्विगुन a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

काष्ठा empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
काष्ठा hfae12 { काष्ठा empty e; काष्ठा hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
काष्ठा hfae22 { काष्ठा empty e; काष्ठा hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

व्योम fa_s1(काष्ठा s1 a) { म_लिखो("%.1s\n", a.x); }
व्योम fa_s2(काष्ठा s2 a) { म_लिखो("%.2s\n", a.x); }
व्योम fa_s3(काष्ठा s3 a) { म_लिखो("%.3s\n", a.x); }
व्योम fa_s4(काष्ठा s4 a) { म_लिखो("%.4s\n", a.x); }
व्योम fa_s5(काष्ठा s5 a) { म_लिखो("%.5s\n", a.x); }
व्योम fa_s6(काष्ठा s6 a) { म_लिखो("%.6s\n", a.x); }
व्योम fa_s7(काष्ठा s7 a) { म_लिखो("%.7s\n", a.x); }
व्योम fa_s8(काष्ठा s8 a) { म_लिखो("%.8s\n", a.x); }
व्योम fa_s9(काष्ठा s9 a) { म_लिखो("%.9s\n", a.x); }
व्योम fa_s10(काष्ठा s10 a) { म_लिखो("%.10s\n", a.x); }
व्योम fa_s11(काष्ठा s11 a) { म_लिखो("%.11s\n", a.x); }
व्योम fa_s12(काष्ठा s12 a) { म_लिखो("%.12s\n", a.x); }
व्योम fa_s13(काष्ठा s13 a) { म_लिखो("%.13s\n", a.x); }
व्योम fa_s14(काष्ठा s14 a) { म_लिखो("%.14s\n", a.x); }
व्योम fa_s15(काष्ठा s15 a) { म_लिखो("%.15s\n", a.x); }
व्योम fa_s16(काष्ठा s16 a) { म_लिखो("%.16s\n", a.x); }
व्योम fa_s17(काष्ठा s17 a) { म_लिखो("%.17s\n", a.x); }

व्योम fa_hfa11(काष्ठा hfa11 a)
{ म_लिखो("%.1f\n", a.a); }
व्योम fa_hfa12(काष्ठा hfa12 a)
{ म_लिखो("%.1f %.1f\n", a.a, a.a); }
व्योम fa_hfa13(काष्ठा hfa13 a)
{ म_लिखो("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
व्योम fa_hfa14(काष्ठा hfa14 a)
{ म_लिखो("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

व्योम fa_hfa21(काष्ठा hfa21 a)
{ म_लिखो("%.1f\n", a.a); }
व्योम fa_hfa22(काष्ठा hfa22 a)
{ म_लिखो("%.1f %.1f\n", a.a, a.a); }
व्योम fa_hfa23(काष्ठा hfa23 a)
{ म_लिखो("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
व्योम fa_hfa24(काष्ठा hfa24 a)
{ म_लिखो("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

व्योम fa_hfa31(काष्ठा hfa31 a)
{ म_लिखो("%.1Lf\n", a.a); }
व्योम fa_hfa32(काष्ठा hfa32 a)
{ म_लिखो("%.1Lf %.1Lf\n", a.a, a.a); }
व्योम fa_hfa33(काष्ठा hfa33 a)
{ म_लिखो("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
व्योम fa_hfa34(काष्ठा hfa34 a)
{ म_लिखो("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
व्योम fa_hfae12(काष्ठा hfae12 a)
{ म_लिखो("%.1f %.1f\n", a.h.a, a.h.b); }
व्योम fa_hfae22(काष्ठा hfae22 a)
{ म_लिखो("%.1f %.1f\n", a.h.a, a.h.b); }

व्योम fa1(काष्ठा s8 a, काष्ठा s9 b, काष्ठा s10 c, काष्ठा s11 d,
         काष्ठा s12 e, काष्ठा s13 f)
{
    म_लिखो("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

व्योम fa2(काष्ठा s9 a, काष्ठा s10 b, काष्ठा s11 c, काष्ठा s12 d,
         काष्ठा s13 e, काष्ठा s14 f)
{
    म_लिखो("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

व्योम fa3(काष्ठा hfa14 a, काष्ठा hfa23 b, काष्ठा hfa32 c)
{
    म_लिखो("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

व्योम fa4(काष्ठा s1 a, काष्ठा hfa14 b, काष्ठा s2 c, काष्ठा hfa24 d,
         काष्ठा s3 e, काष्ठा hfa34 f)
{
    म_लिखो("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

व्योम arg(व्योम)
{
    म_लिखो("Arguments:\n");
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

काष्ठा s1 fr_s1(व्योम) { वापस s1; }
काष्ठा s2 fr_s2(व्योम) { वापस s2; }
काष्ठा s3 fr_s3(व्योम) { वापस s3; }
काष्ठा s4 fr_s4(व्योम) { वापस s4; }
काष्ठा s5 fr_s5(व्योम) { वापस s5; }
काष्ठा s6 fr_s6(व्योम) { वापस s6; }
काष्ठा s7 fr_s7(व्योम) { वापस s7; }
काष्ठा s8 fr_s8(व्योम) { वापस s8; }
काष्ठा s9 fr_s9(व्योम) { वापस s9; }
काष्ठा s10 fr_s10(व्योम) { वापस s10; }
काष्ठा s11 fr_s11(व्योम) { वापस s11; }
काष्ठा s12 fr_s12(व्योम) { वापस s12; }
काष्ठा s13 fr_s13(व्योम) { वापस s13; }
काष्ठा s14 fr_s14(व्योम) { वापस s14; }
काष्ठा s15 fr_s15(व्योम) { वापस s15; }
काष्ठा s16 fr_s16(व्योम) { वापस s16; }
काष्ठा s17 fr_s17(व्योम) { वापस s17; }

काष्ठा hfa11 fr_hfa11(व्योम) { वापस hfa11; }
काष्ठा hfa12 fr_hfa12(व्योम) { वापस hfa12; }
काष्ठा hfa13 fr_hfa13(व्योम) { वापस hfa13; }
काष्ठा hfa14 fr_hfa14(व्योम) { वापस hfa14; }

काष्ठा hfa21 fr_hfa21(व्योम) { वापस hfa21; }
काष्ठा hfa22 fr_hfa22(व्योम) { वापस hfa22; }
काष्ठा hfa23 fr_hfa23(व्योम) { वापस hfa23; }
काष्ठा hfa24 fr_hfa24(व्योम) { वापस hfa24; }

काष्ठा hfa31 fr_hfa31(व्योम) { वापस hfa31; }
काष्ठा hfa32 fr_hfa32(व्योम) { वापस hfa32; }
काष्ठा hfa33 fr_hfa33(व्योम) { वापस hfa33; }
काष्ठा hfa34 fr_hfa34(व्योम) { वापस hfa34; }
काष्ठा hfae12 fr_hfae12(व्योम) { वापस hfae12; }
काष्ठा hfae22 fr_hfae22(व्योम) { वापस hfae22; }

व्योम ret(व्योम)
{
    काष्ठा s1 t1 = fr_s1();
    काष्ठा s2 t2 = fr_s2();
    काष्ठा s3 t3 = fr_s3();
    काष्ठा s4 t4 = fr_s4();
    काष्ठा s5 t5 = fr_s5();
    काष्ठा s6 t6 = fr_s6();
    काष्ठा s7 t7 = fr_s7();
    काष्ठा s8 t8 = fr_s8();
    काष्ठा s9 t9 = fr_s9();
    काष्ठा s10 t10 = fr_s10();
    काष्ठा s11 t11 = fr_s11();
    काष्ठा s12 t12 = fr_s12();
    काष्ठा s13 t13 = fr_s13();
    काष्ठा s14 t14 = fr_s14();
    काष्ठा s15 t15 = fr_s15();
    काष्ठा s16 t16 = fr_s16();
    काष्ठा s17 t17 = fr_s17();
    म_लिखो("Return values:\n");
    म_लिखो("%.1s\n", t1.x);
    म_लिखो("%.2s\n", t2.x);
    म_लिखो("%.3s\n", t3.x);
    म_लिखो("%.4s\n", t4.x);
    म_लिखो("%.5s\n", t5.x);
    म_लिखो("%.6s\n", t6.x);
    म_लिखो("%.7s\n", t7.x);
    म_लिखो("%.8s\n", t8.x);
    म_लिखो("%.9s\n", t9.x);
    म_लिखो("%.10s\n", t10.x);
    म_लिखो("%.11s\n", t11.x);
    म_लिखो("%.12s\n", t12.x);
    म_लिखो("%.13s\n", t13.x);
    म_लिखो("%.14s\n", t14.x);
    म_लिखो("%.15s\n", t15.x);
    म_लिखो("%.16s\n", t16.x);
    म_लिखो("%.17s\n", t17.x);
    म_लिखो("%.1f\n", fr_hfa11().a);
    म_लिखो("%.1f %.1f\n", fr_hfa12().a, fr_hfa12().b);
    म_लिखो("%.1f %.1f\n", fr_hfa13().a, fr_hfa13().c);
    म_लिखो("%.1f %.1f\n", fr_hfa14().a, fr_hfa14().d);
    म_लिखो("%.1f\n", fr_hfa21().a);
    म_लिखो("%.1f %.1f\n", fr_hfa22().a, fr_hfa22().b);
    म_लिखो("%.1f %.1f\n", fr_hfa23().a, fr_hfa23().c);
    म_लिखो("%.1f %.1f\n", fr_hfa24().a, fr_hfa24().d);
    म_लिखो("%.1Lf\n", fr_hfa31().a);
    म_लिखो("%.1Lf %.1Lf\n", fr_hfa32().a, fr_hfa32().b);
    म_लिखो("%.1Lf %.1Lf\n", fr_hfa33().a, fr_hfa33().c);
    म_लिखो("%.1Lf %.1Lf\n", fr_hfa34().a, fr_hfa34().d);
    म_लिखो("%.1f %.1f\n", fr_hfae12().h.a, fr_hfae12().h.b);
    म_लिखो("%.1f %.1f\n", fr_hfae22().h.a, fr_hfae22().h.b);
}

व्योम*
va_arg_with_struct_ptr(बहु_सूची ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        काष्ठा X { पूर्णांक _x; };
        काष्ठा X *x = बहु_तर्क(ap, काष्ठा X *);
        वापस x;
}

पूर्णांक match(स्थिर अक्षर **s, स्थिर अक्षर *f)
{
    स्थिर अक्षर *p = *s;
    क्रम (p = *s; *f && *f == *p; f++, p++)
        ;
    अगर (!*f) {
        *s = p - 1;
        वापस 1;
    }
    वापस 0;
}

व्योम myprintf(स्थिर अक्षर *format, ...)
{
    स्थिर अक्षर *s;
    बहु_सूची ap;
    बहु_शुरू(ap, format);
    क्रम (s = format; *s; s++) {
        अगर (match(&s, "%7s")) {
            काष्ठा s7 t7 = बहु_तर्क(ap, काष्ठा s7);
            म_लिखो("%.7s", t7.x);
        }
        अन्यथा अगर (match(&s, "%9s")) {
            काष्ठा s9 t9 = बहु_तर्क(ap, काष्ठा s9);
            म_लिखो("%.9s", t9.x);
        }
        अन्यथा अगर (match(&s, "%hfa11")) {
            काष्ठा hfa11 x = बहु_तर्क(ap, काष्ठा hfa11);
            म_लिखो("%.1f,%.1f", x.a, x.a);
        }
        अन्यथा अगर (match(&s, "%hfa12")) {
            काष्ठा hfa12 x = बहु_तर्क(ap, काष्ठा hfa12);
            म_लिखो("%.1f,%.1f", x.a, x.b);
        }
        अन्यथा अगर (match(&s, "%hfa13")) {
            काष्ठा hfa13 x = बहु_तर्क(ap, काष्ठा hfa13);
            म_लिखो("%.1f,%.1f", x.a, x.c);
        }
        अन्यथा अगर (match(&s, "%hfa14")) {
            काष्ठा hfa14 x = बहु_तर्क(ap, काष्ठा hfa14);
            म_लिखो("%.1f,%.1f", x.a, x.d);
        }
        अन्यथा अगर (match(&s, "%hfa21")) {
            काष्ठा hfa21 x = बहु_तर्क(ap, काष्ठा hfa21);
            म_लिखो("%.1f,%.1f", x.a, x.a);
        }
        अन्यथा अगर (match(&s, "%hfa22")) {
            काष्ठा hfa22 x = बहु_तर्क(ap, काष्ठा hfa22);
            म_लिखो("%.1f,%.1f", x.a, x.b);
        }
        अन्यथा अगर (match(&s, "%hfa23")) {
            काष्ठा hfa23 x = बहु_तर्क(ap, काष्ठा hfa23);
            म_लिखो("%.1f,%.1f", x.a, x.c);
        }
        अन्यथा अगर (match(&s, "%hfa24")) {
            काष्ठा hfa24 x = बहु_तर्क(ap, काष्ठा hfa24);
            म_लिखो("%.1f,%.1f", x.a, x.d);
        }
        अन्यथा अगर (match(&s, "%hfa31")) {
            काष्ठा hfa31 x = बहु_तर्क(ap, काष्ठा hfa31);
            म_लिखो("%.1Lf,%.1Lf", x.a, x.a);
        }
        अन्यथा अगर (match(&s, "%hfa32")) {
            काष्ठा hfa32 x = बहु_तर्क(ap, काष्ठा hfa32);
            म_लिखो("%.1Lf,%.1Lf", x.a, x.b);
        }
        अन्यथा अगर (match(&s, "%hfa33")) {
            काष्ठा hfa33 x = बहु_तर्क(ap, काष्ठा hfa33);
            म_लिखो("%.1Lf,%.1Lf", x.a, x.c);
        }
        अन्यथा अगर (match(&s, "%hfa34")) {
            काष्ठा hfa34 x = बहु_तर्क(ap, काष्ठा hfa34);
            म_लिखो("%.1Lf,%.1Lf", x.a, x.d);
        }
        अन्यथा
            अक्षर_दो(*s);
    }
    अक्षर_दो('\n');
}

व्योम stdarg(व्योम)
{
    म_लिखो("stdarg:\n");
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

व्योम pll(अचिन्हित दीर्घ दीर्घ x)
{
    म_लिखो("%llx\n", x);
}

व्योम movi(व्योम)
{
    म_लिखो("MOVI:\n");
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

अटल uint32_t addip0(uint32_t x) { वापस x + 0; }
अटल uint64_t sublp0(uint64_t x) { वापस x - 0; }
अटल uint32_t addip123(uint32_t x) { वापस x + 123; }
अटल uint64_t addlm123(uint64_t x) { वापस x + -123; }
अटल uint64_t sublp4095(uint64_t x) { वापस x - 4095; }
अटल uint32_t subim503808(uint32_t x) { वापस x - -503808; }
अटल uint64_t addp12345(uint64_t x) { वापस x + 12345; }
अटल uint32_t subp12345(uint32_t x) { वापस x - 12345; }

अटल uint32_t mvni(uint32_t x) { वापस 0xffffffff - x; }
अटल uint64_t negl(uint64_t x) { वापस 0 - x; }
अटल uint32_t rsbi123(uint32_t x) { वापस 123 - x; }
अटल uint64_t rsbl123(uint64_t x) { वापस 123 - x; }

अटल uint32_t andi0(uint32_t x) { वापस x & 0; }
अटल uint64_t andlm1(uint64_t x) { वापस x & -1; }
अटल uint64_t orrl0(uint64_t x) { वापस x | 0; }
अटल uint32_t orrim1(uint32_t x) { वापस x | -1; }
अटल uint32_t eori0(uint32_t x) { वापस x ^ 0; }
अटल uint64_t eorlm1(uint64_t x) { वापस x ^ -1; }
अटल uint32_t and0xf0(uint32_t x) { वापस x & 0xf0; }
अटल uint64_t orr0xf0(uint64_t x) { वापस x | 0xf0; }
अटल uint64_t eor0xf0(uint64_t x) { वापस x ^ 0xf0; }

अटल uint32_t lsli0(uint32_t x) { वापस x << 0; }
अटल uint32_t lsri0(uint32_t x) { वापस x >> 0; }
अटल int64_t asrl0(int64_t x) { वापस x >> 0; }
अटल uint32_t lsli1(uint32_t x) { वापस x << 1; }
अटल uint32_t lsli31(uint32_t x) { वापस x << 31; }
अटल uint64_t lsll1(uint64_t x) { वापस x << 1; }
अटल uint64_t lsll63(uint64_t x) { वापस x << 63; }
अटल uint32_t lsri1(uint32_t x) { वापस x >> 1; }
अटल uint32_t lsri31(uint32_t x) { वापस x >> 31; }
अटल uint64_t lsrl1(uint64_t x) { वापस x >> 1; }
अटल uint64_t lsrl63(uint64_t x) { वापस x >> 63; }
अटल int32_t asri1(int32_t x) { वापस x >> 1; }
अटल int32_t asri31(int32_t x) { वापस x >> 31; }
अटल int64_t asrl1(int64_t x) { वापस x >> 1; }
अटल int64_t asrl63(int64_t x) { वापस x >> 63; }

व्योम opi(व्योम)
{
    पूर्णांक x = 1000;
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

व्योम pcs(व्योम)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

पूर्णांक मुख्य()
{
    pcs();
    वापस 0;
}
