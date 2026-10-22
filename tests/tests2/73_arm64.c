// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#अन्तर्भाव <stdarg.h>
#अन्तर्भाव <stdint.h>
#अन्तर्भाव <stdio.h>

संरचना s1 { वर्ण x[1]; } s1 = { "0" };
संरचना s2 { वर्ण x[2]; } s2 = { "12" };
संरचना s3 { वर्ण x[3]; } s3 = { "345" };
संरचना s4 { वर्ण x[4]; } s4 = { "6789" };
संरचना s5 { वर्ण x[5]; } s5 = { "abcde" };
संरचना s6 { वर्ण x[6]; } s6 = { "fghijk" };
संरचना s7 { वर्ण x[7]; } s7 = { "lmnopqr" };
संरचना s8 { वर्ण x[8]; } s8 = { "stuvwxyz" };
संरचना s9 { वर्ण x[9]; } s9 = { "ABCDEFGHI" };
संरचना s10 { वर्ण x[10]; } s10 = { "JKLMNOPQRS" };
संरचना s11 { वर्ण x[11]; } s11 = { "TUVWXYZ0123" };
संरचना s12 { वर्ण x[12]; } s12 = { "456789abcdef" };
संरचना s13 { वर्ण x[13]; } s13 = { "ghijklmnopqrs" };
संरचना s14 { वर्ण x[14]; } s14 = { "tuvwxyzABCDEFG" };
संरचना s15 { वर्ण x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
संरचना s16 { वर्ण x[16]; } s16 = { "WXYZ0123456789ab" };
संरचना s17 { वर्ण x[17]; } s17 = { "cdefghijklmnopqrs" };

संरचना hfa11 { भिन्न a; } hfa11 = { 11.1 };
संरचना hfa12 { भिन्न a, b; } hfa12 = { 12.1, 12.2 };
संरचना hfa13 { भिन्न a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
संरचना hfa14 { भिन्न a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

संरचना hfa21 { द्विगुण a; } hfa21 = { 21.1 };
संरचना hfa22 { द्विगुण a, b; } hfa22 = { 22.1, 22.2 };
संरचना hfa23 { द्विगुण a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
संरचना hfa24 { द्विगुण a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

संरचना hfa31 { long द्विगुण a; } hfa31 = { 31.1 };
संरचना hfa32 { long द्विगुण a, b; } hfa32 = { 32.1, 32.2 };
संरचना hfa33 { long द्विगुण a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
संरचना hfa34 { long द्विगुण a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

संरचना empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
संरचना hfae12 { संरचना empty e; संरचना hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
संरचना hfae22 { संरचना empty e; संरचना hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

शून्य fa_s1(संरचना s1 a) { printf("%.1s\n", a.x); }
शून्य fa_s2(संरचना s2 a) { printf("%.2s\n", a.x); }
शून्य fa_s3(संरचना s3 a) { printf("%.3s\n", a.x); }
शून्य fa_s4(संरचना s4 a) { printf("%.4s\n", a.x); }
शून्य fa_s5(संरचना s5 a) { printf("%.5s\n", a.x); }
शून्य fa_s6(संरचना s6 a) { printf("%.6s\n", a.x); }
शून्य fa_s7(संरचना s7 a) { printf("%.7s\n", a.x); }
शून्य fa_s8(संरचना s8 a) { printf("%.8s\n", a.x); }
शून्य fa_s9(संरचना s9 a) { printf("%.9s\n", a.x); }
शून्य fa_s10(संरचना s10 a) { printf("%.10s\n", a.x); }
शून्य fa_s11(संरचना s11 a) { printf("%.11s\n", a.x); }
शून्य fa_s12(संरचना s12 a) { printf("%.12s\n", a.x); }
शून्य fa_s13(संरचना s13 a) { printf("%.13s\n", a.x); }
शून्य fa_s14(संरचना s14 a) { printf("%.14s\n", a.x); }
शून्य fa_s15(संरचना s15 a) { printf("%.15s\n", a.x); }
शून्य fa_s16(संरचना s16 a) { printf("%.16s\n", a.x); }
शून्य fa_s17(संरचना s17 a) { printf("%.17s\n", a.x); }

शून्य fa_hfa11(संरचना hfa11 a)
{ printf("%.1f\n", a.a); }
शून्य fa_hfa12(संरचना hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
शून्य fa_hfa13(संरचना hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
शून्य fa_hfa14(संरचना hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

शून्य fa_hfa21(संरचना hfa21 a)
{ printf("%.1f\n", a.a); }
शून्य fa_hfa22(संरचना hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
शून्य fa_hfa23(संरचना hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
शून्य fa_hfa24(संरचना hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

शून्य fa_hfa31(संरचना hfa31 a)
{ printf("%.1Lf\n", a.a); }
शून्य fa_hfa32(संरचना hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
शून्य fa_hfa33(संरचना hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
शून्य fa_hfa34(संरचना hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
शून्य fa_hfae12(संरचना hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
शून्य fa_hfae22(संरचना hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

शून्य fa1(संरचना s8 a, संरचना s9 b, संरचना s10 c, संरचना s11 d,
         संरचना s12 e, संरचना s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

शून्य fa2(संरचना s9 a, संरचना s10 b, संरचना s11 c, संरचना s12 d,
         संरचना s13 e, संरचना s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

शून्य fa3(संरचना hfa14 a, संरचना hfa23 b, संरचना hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

शून्य fa4(संरचना s1 a, संरचना hfa14 b, संरचना s2 c, संरचना hfa24 d,
         संरचना s3 e, संरचना hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

शून्य arg(शून्य)
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

संरचना s1 fr_s1(शून्य) { प्रत्यागम s1; }
संरचना s2 fr_s2(शून्य) { प्रत्यागम s2; }
संरचना s3 fr_s3(शून्य) { प्रत्यागम s3; }
संरचना s4 fr_s4(शून्य) { प्रत्यागम s4; }
संरचना s5 fr_s5(शून्य) { प्रत्यागम s5; }
संरचना s6 fr_s6(शून्य) { प्रत्यागम s6; }
संरचना s7 fr_s7(शून्य) { प्रत्यागम s7; }
संरचना s8 fr_s8(शून्य) { प्रत्यागम s8; }
संरचना s9 fr_s9(शून्य) { प्रत्यागम s9; }
संरचना s10 fr_s10(शून्य) { प्रत्यागम s10; }
संरचना s11 fr_s11(शून्य) { प्रत्यागम s11; }
संरचना s12 fr_s12(शून्य) { प्रत्यागम s12; }
संरचना s13 fr_s13(शून्य) { प्रत्यागम s13; }
संरचना s14 fr_s14(शून्य) { प्रत्यागम s14; }
संरचना s15 fr_s15(शून्य) { प्रत्यागम s15; }
संरचना s16 fr_s16(शून्य) { प्रत्यागम s16; }
संरचना s17 fr_s17(शून्य) { प्रत्यागम s17; }

संरचना hfa11 fr_hfa11(शून्य) { प्रत्यागम hfa11; }
संरचना hfa12 fr_hfa12(शून्य) { प्रत्यागम hfa12; }
संरचना hfa13 fr_hfa13(शून्य) { प्रत्यागम hfa13; }
संरचना hfa14 fr_hfa14(शून्य) { प्रत्यागम hfa14; }

संरचना hfa21 fr_hfa21(शून्य) { प्रत्यागम hfa21; }
संरचना hfa22 fr_hfa22(शून्य) { प्रत्यागम hfa22; }
संरचना hfa23 fr_hfa23(शून्य) { प्रत्यागम hfa23; }
संरचना hfa24 fr_hfa24(शून्य) { प्रत्यागम hfa24; }

संरचना hfa31 fr_hfa31(शून्य) { प्रत्यागम hfa31; }
संरचना hfa32 fr_hfa32(शून्य) { प्रत्यागम hfa32; }
संरचना hfa33 fr_hfa33(शून्य) { प्रत्यागम hfa33; }
संरचना hfa34 fr_hfa34(शून्य) { प्रत्यागम hfa34; }
संरचना hfae12 fr_hfae12(शून्य) { प्रत्यागम hfae12; }
संरचना hfae22 fr_hfae22(शून्य) { प्रत्यागम hfae22; }

शून्य ret(शून्य)
{
    संरचना s1 t1 = fr_s1();
    संरचना s2 t2 = fr_s2();
    संरचना s3 t3 = fr_s3();
    संरचना s4 t4 = fr_s4();
    संरचना s5 t5 = fr_s5();
    संरचना s6 t6 = fr_s6();
    संरचना s7 t7 = fr_s7();
    संरचना s8 t8 = fr_s8();
    संरचना s9 t9 = fr_s9();
    संरचना s10 t10 = fr_s10();
    संरचना s11 t11 = fr_s11();
    संरचना s12 t12 = fr_s12();
    संरचना s13 t13 = fr_s13();
    संरचना s14 t14 = fr_s14();
    संरचना s15 t15 = fr_s15();
    संरचना s16 t16 = fr_s16();
    संरचना s17 t17 = fr_s17();
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

शून्य*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        संरचना X { पूर्णाङ्क _x; };
        संरचना X *x = va_arg(ap, संरचना X *);
        प्रत्यागम x;
}

पूर्णाङ्क match(ध्रुव वर्ण **s, ध्रुव वर्ण *f)
{
    ध्रुव वर्ण *p = *s;
    प्रति (p = *s; *f && *f == *p; f++, p++)
        ;
    यदि (!*f) {
        *s = p - 1;
        प्रत्यागम 1;
    }
    प्रत्यागम 0;
}

शून्य myprintf(ध्रुव वर्ण *format, ...)
{
    ध्रुव वर्ण *s;
    va_list ap;
    va_start(ap, format);
    प्रति (s = format; *s; s++) {
        यदि (match(&s, "%7s")) {
            संरचना s7 t7 = va_arg(ap, संरचना s7);
            printf("%.7s", t7.x);
        }
        अन्यथा यदि (match(&s, "%9s")) {
            संरचना s9 t9 = va_arg(ap, संरचना s9);
            printf("%.9s", t9.x);
        }
        अन्यथा यदि (match(&s, "%hfa11")) {
            संरचना hfa11 x = va_arg(ap, संरचना hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        अन्यथा यदि (match(&s, "%hfa12")) {
            संरचना hfa12 x = va_arg(ap, संरचना hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        अन्यथा यदि (match(&s, "%hfa13")) {
            संरचना hfa13 x = va_arg(ap, संरचना hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        अन्यथा यदि (match(&s, "%hfa14")) {
            संरचना hfa14 x = va_arg(ap, संरचना hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        अन्यथा यदि (match(&s, "%hfa21")) {
            संरचना hfa21 x = va_arg(ap, संरचना hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        अन्यथा यदि (match(&s, "%hfa22")) {
            संरचना hfa22 x = va_arg(ap, संरचना hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        अन्यथा यदि (match(&s, "%hfa23")) {
            संरचना hfa23 x = va_arg(ap, संरचना hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        अन्यथा यदि (match(&s, "%hfa24")) {
            संरचना hfa24 x = va_arg(ap, संरचना hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        अन्यथा यदि (match(&s, "%hfa31")) {
            संरचना hfa31 x = va_arg(ap, संरचना hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        अन्यथा यदि (match(&s, "%hfa32")) {
            संरचना hfa32 x = va_arg(ap, संरचना hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        अन्यथा यदि (match(&s, "%hfa33")) {
            संरचना hfa33 x = va_arg(ap, संरचना hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        अन्यथा यदि (match(&s, "%hfa34")) {
            संरचना hfa34 x = va_arg(ap, संरचना hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        अन्यथा
            putchar(*s);
    }
    putchar('\n');
}

शून्य stdarg(शून्य)
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

शून्य pll(unsigned long long x)
{
    printf("%llx\n", x);
}

शून्य movi(शून्य)
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

स्थिर uint32_t addip0(uint32_t x) { प्रत्यागम x + 0; }
स्थिर uint64_t sublp0(uint64_t x) { प्रत्यागम x - 0; }
स्थिर uint32_t addip123(uint32_t x) { प्रत्यागम x + 123; }
स्थिर uint64_t addlm123(uint64_t x) { प्रत्यागम x + -123; }
स्थिर uint64_t sublp4095(uint64_t x) { प्रत्यागम x - 4095; }
स्थिर uint32_t subim503808(uint32_t x) { प्रत्यागम x - -503808; }
स्थिर uint64_t addp12345(uint64_t x) { प्रत्यागम x + 12345; }
स्थिर uint32_t subp12345(uint32_t x) { प्रत्यागम x - 12345; }

स्थिर uint32_t mvni(uint32_t x) { प्रत्यागम 0xffffffff - x; }
स्थिर uint64_t negl(uint64_t x) { प्रत्यागम 0 - x; }
स्थिर uint32_t rsbi123(uint32_t x) { प्रत्यागम 123 - x; }
स्थिर uint64_t rsbl123(uint64_t x) { प्रत्यागम 123 - x; }

स्थिर uint32_t andi0(uint32_t x) { प्रत्यागम x & 0; }
स्थिर uint64_t andlm1(uint64_t x) { प्रत्यागम x & -1; }
स्थिर uint64_t orrl0(uint64_t x) { प्रत्यागम x | 0; }
स्थिर uint32_t orrim1(uint32_t x) { प्रत्यागम x | -1; }
स्थिर uint32_t eori0(uint32_t x) { प्रत्यागम x ^ 0; }
स्थिर uint64_t eorlm1(uint64_t x) { प्रत्यागम x ^ -1; }
स्थिर uint32_t and0xf0(uint32_t x) { प्रत्यागम x & 0xf0; }
स्थिर uint64_t orr0xf0(uint64_t x) { प्रत्यागम x | 0xf0; }
स्थिर uint64_t eor0xf0(uint64_t x) { प्रत्यागम x ^ 0xf0; }

स्थिर uint32_t lsli0(uint32_t x) { प्रत्यागम x << 0; }
स्थिर uint32_t lsri0(uint32_t x) { प्रत्यागम x >> 0; }
स्थिर int64_t asrl0(int64_t x) { प्रत्यागम x >> 0; }
स्थिर uint32_t lsli1(uint32_t x) { प्रत्यागम x << 1; }
स्थिर uint32_t lsli31(uint32_t x) { प्रत्यागम x << 31; }
स्थिर uint64_t lsll1(uint64_t x) { प्रत्यागम x << 1; }
स्थिर uint64_t lsll63(uint64_t x) { प्रत्यागम x << 63; }
स्थिर uint32_t lsri1(uint32_t x) { प्रत्यागम x >> 1; }
स्थिर uint32_t lsri31(uint32_t x) { प्रत्यागम x >> 31; }
स्थिर uint64_t lsrl1(uint64_t x) { प्रत्यागम x >> 1; }
स्थिर uint64_t lsrl63(uint64_t x) { प्रत्यागम x >> 63; }
स्थिर int32_t asri1(int32_t x) { प्रत्यागम x >> 1; }
स्थिर int32_t asri31(int32_t x) { प्रत्यागम x >> 31; }
स्थिर int64_t asrl1(int64_t x) { प्रत्यागम x >> 1; }
स्थिर int64_t asrl63(int64_t x) { प्रत्यागम x >> 63; }

शून्य opi(शून्य)
{
    पूर्णाङ्क x = 1000;
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

शून्य pcs(शून्य)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

पूर्णाङ्क main()
{
    pcs();
    प्रत्यागम 0;
}
