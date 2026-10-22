// This program is designed to test some arm64-specific things, such as the
// calling convention, but should give the same results on any architecture.

#அந்தர்பாவ <stdarg.h>
#அந்தர்பாவ <stdint.h>
#அந்தர்பாவ <stdio.h>

கட்டமைப்பு s1 { எழுத்து x[1]; } s1 = { "0" };
கட்டமைப்பு s2 { எழுத்து x[2]; } s2 = { "12" };
கட்டமைப்பு s3 { எழுத்து x[3]; } s3 = { "345" };
கட்டமைப்பு s4 { எழுத்து x[4]; } s4 = { "6789" };
கட்டமைப்பு s5 { எழுத்து x[5]; } s5 = { "abcde" };
கட்டமைப்பு s6 { எழுத்து x[6]; } s6 = { "fghijk" };
கட்டமைப்பு s7 { எழுத்து x[7]; } s7 = { "lmnopqr" };
கட்டமைப்பு s8 { எழுத்து x[8]; } s8 = { "stuvwxyz" };
கட்டமைப்பு s9 { எழுத்து x[9]; } s9 = { "ABCDEFGHI" };
கட்டமைப்பு s10 { எழுத்து x[10]; } s10 = { "JKLMNOPQRS" };
கட்டமைப்பு s11 { எழுத்து x[11]; } s11 = { "TUVWXYZ0123" };
கட்டமைப்பு s12 { எழுத்து x[12]; } s12 = { "456789abcdef" };
கட்டமைப்பு s13 { எழுத்து x[13]; } s13 = { "ghijklmnopqrs" };
கட்டமைப்பு s14 { எழுத்து x[14]; } s14 = { "tuvwxyzABCDEFG" };
கட்டமைப்பு s15 { எழுத்து x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
கட்டமைப்பு s16 { எழுத்து x[16]; } s16 = { "WXYZ0123456789ab" };
கட்டமைப்பு s17 { எழுத்து x[17]; } s17 = { "cdefghijklmnopqrs" };

கட்டமைப்பு hfa11 { தசம a; } hfa11 = { 11.1 };
கட்டமைப்பு hfa12 { தசம a, b; } hfa12 = { 12.1, 12.2 };
கட்டமைப்பு hfa13 { தசம a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
கட்டமைப்பு hfa14 { தசம a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

கட்டமைப்பு hfa21 { இரட்டை a; } hfa21 = { 21.1 };
கட்டமைப்பு hfa22 { இரட்டை a, b; } hfa22 = { 22.1, 22.2 };
கட்டமைப்பு hfa23 { இரட்டை a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
கட்டமைப்பு hfa24 { இரட்டை a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

கட்டமைப்பு hfa31 { long இரட்டை a; } hfa31 = { 31.1 };
கட்டமைப்பு hfa32 { long இரட்டை a, b; } hfa32 = { 32.1, 32.2 };
கட்டமைப்பு hfa33 { long இரட்டை a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
கட்டமைப்பு hfa34 { long இரட்டை a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

கட்டமைப்பு empty { };
/* Keep the top-level offsets at zero without changing the type into a union. */
கட்டமைப்பு hfae12 { கட்டமைப்பு empty e; கட்டமைப்பு hfa12 h; } hfae12 = { { }, { 112.1, 112.2 } };
கட்டமைப்பு hfae22 { கட்டமைப்பு empty e; கட்டமைப்பு hfa22 h; } hfae22 = { { }, { 122.1, 122.2 } };

வெறுமை fa_s1(கட்டமைப்பு s1 a) { printf("%.1s\n", a.x); }
வெறுமை fa_s2(கட்டமைப்பு s2 a) { printf("%.2s\n", a.x); }
வெறுமை fa_s3(கட்டமைப்பு s3 a) { printf("%.3s\n", a.x); }
வெறுமை fa_s4(கட்டமைப்பு s4 a) { printf("%.4s\n", a.x); }
வெறுமை fa_s5(கட்டமைப்பு s5 a) { printf("%.5s\n", a.x); }
வெறுமை fa_s6(கட்டமைப்பு s6 a) { printf("%.6s\n", a.x); }
வெறுமை fa_s7(கட்டமைப்பு s7 a) { printf("%.7s\n", a.x); }
வெறுமை fa_s8(கட்டமைப்பு s8 a) { printf("%.8s\n", a.x); }
வெறுமை fa_s9(கட்டமைப்பு s9 a) { printf("%.9s\n", a.x); }
வெறுமை fa_s10(கட்டமைப்பு s10 a) { printf("%.10s\n", a.x); }
வெறுமை fa_s11(கட்டமைப்பு s11 a) { printf("%.11s\n", a.x); }
வெறுமை fa_s12(கட்டமைப்பு s12 a) { printf("%.12s\n", a.x); }
வெறுமை fa_s13(கட்டமைப்பு s13 a) { printf("%.13s\n", a.x); }
வெறுமை fa_s14(கட்டமைப்பு s14 a) { printf("%.14s\n", a.x); }
வெறுமை fa_s15(கட்டமைப்பு s15 a) { printf("%.15s\n", a.x); }
வெறுமை fa_s16(கட்டமைப்பு s16 a) { printf("%.16s\n", a.x); }
வெறுமை fa_s17(கட்டமைப்பு s17 a) { printf("%.17s\n", a.x); }

வெறுமை fa_hfa11(கட்டமைப்பு hfa11 a)
{ printf("%.1f\n", a.a); }
வெறுமை fa_hfa12(கட்டமைப்பு hfa12 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
வெறுமை fa_hfa13(கட்டமைப்பு hfa13 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
வெறுமை fa_hfa14(கட்டமைப்பு hfa14 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

வெறுமை fa_hfa21(கட்டமைப்பு hfa21 a)
{ printf("%.1f\n", a.a); }
வெறுமை fa_hfa22(கட்டமைப்பு hfa22 a)
{ printf("%.1f %.1f\n", a.a, a.a); }
வெறுமை fa_hfa23(கட்டமைப்பு hfa23 a)
{ printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
வெறுமை fa_hfa24(கட்டமைப்பு hfa24 a)
{ printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

வெறுமை fa_hfa31(கட்டமைப்பு hfa31 a)
{ printf("%.1Lf\n", a.a); }
வெறுமை fa_hfa32(கட்டமைப்பு hfa32 a)
{ printf("%.1Lf %.1Lf\n", a.a, a.a); }
வெறுமை fa_hfa33(கட்டமைப்பு hfa33 a)
{ printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
வெறுமை fa_hfa34(கட்டமைப்பு hfa34 a)
{ printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }
வெறுமை fa_hfae12(கட்டமைப்பு hfae12 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }
வெறுமை fa_hfae22(கட்டமைப்பு hfae22 a)
{ printf("%.1f %.1f\n", a.h.a, a.h.b); }

வெறுமை fa1(கட்டமைப்பு s8 a, கட்டமைப்பு s9 b, கட்டமைப்பு s10 c, கட்டமைப்பு s11 d,
         கட்டமைப்பு s12 e, கட்டமைப்பு s13 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

வெறுமை fa2(கட்டமைப்பு s9 a, கட்டமைப்பு s10 b, கட்டமைப்பு s11 c, கட்டமைப்பு s12 d,
         கட்டமைப்பு s13 e, கட்டமைப்பு s14 f)
{
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

வெறுமை fa3(கட்டமைப்பு hfa14 a, கட்டமைப்பு hfa23 b, கட்டமைப்பு hfa32 c)
{
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n",
           a.a, a.d, b.a, b.c, c.a, c.b);
}

வெறுமை fa4(கட்டமைப்பு s1 a, கட்டமைப்பு hfa14 b, கட்டமைப்பு s2 c, கட்டமைப்பு hfa24 d,
         கட்டமைப்பு s3 e, கட்டமைப்பு hfa34 f)
{
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n",
           a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

வெறுமை arg(வெறுமை)
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

கட்டமைப்பு s1 fr_s1(வெறுமை) { திரும்பு s1; }
கட்டமைப்பு s2 fr_s2(வெறுமை) { திரும்பு s2; }
கட்டமைப்பு s3 fr_s3(வெறுமை) { திரும்பு s3; }
கட்டமைப்பு s4 fr_s4(வெறுமை) { திரும்பு s4; }
கட்டமைப்பு s5 fr_s5(வெறுமை) { திரும்பு s5; }
கட்டமைப்பு s6 fr_s6(வெறுமை) { திரும்பு s6; }
கட்டமைப்பு s7 fr_s7(வெறுமை) { திரும்பு s7; }
கட்டமைப்பு s8 fr_s8(வெறுமை) { திரும்பு s8; }
கட்டமைப்பு s9 fr_s9(வெறுமை) { திரும்பு s9; }
கட்டமைப்பு s10 fr_s10(வெறுமை) { திரும்பு s10; }
கட்டமைப்பு s11 fr_s11(வெறுமை) { திரும்பு s11; }
கட்டமைப்பு s12 fr_s12(வெறுமை) { திரும்பு s12; }
கட்டமைப்பு s13 fr_s13(வெறுமை) { திரும்பு s13; }
கட்டமைப்பு s14 fr_s14(வெறுமை) { திரும்பு s14; }
கட்டமைப்பு s15 fr_s15(வெறுமை) { திரும்பு s15; }
கட்டமைப்பு s16 fr_s16(வெறுமை) { திரும்பு s16; }
கட்டமைப்பு s17 fr_s17(வெறுமை) { திரும்பு s17; }

கட்டமைப்பு hfa11 fr_hfa11(வெறுமை) { திரும்பு hfa11; }
கட்டமைப்பு hfa12 fr_hfa12(வெறுமை) { திரும்பு hfa12; }
கட்டமைப்பு hfa13 fr_hfa13(வெறுமை) { திரும்பு hfa13; }
கட்டமைப்பு hfa14 fr_hfa14(வெறுமை) { திரும்பு hfa14; }

கட்டமைப்பு hfa21 fr_hfa21(வெறுமை) { திரும்பு hfa21; }
கட்டமைப்பு hfa22 fr_hfa22(வெறுமை) { திரும்பு hfa22; }
கட்டமைப்பு hfa23 fr_hfa23(வெறுமை) { திரும்பு hfa23; }
கட்டமைப்பு hfa24 fr_hfa24(வெறுமை) { திரும்பு hfa24; }

கட்டமைப்பு hfa31 fr_hfa31(வெறுமை) { திரும்பு hfa31; }
கட்டமைப்பு hfa32 fr_hfa32(வெறுமை) { திரும்பு hfa32; }
கட்டமைப்பு hfa33 fr_hfa33(வெறுமை) { திரும்பு hfa33; }
கட்டமைப்பு hfa34 fr_hfa34(வெறுமை) { திரும்பு hfa34; }
கட்டமைப்பு hfae12 fr_hfae12(வெறுமை) { திரும்பு hfae12; }
கட்டமைப்பு hfae22 fr_hfae22(வெறுமை) { திரும்பு hfae22; }

வெறுமை ret(வெறுமை)
{
    கட்டமைப்பு s1 t1 = fr_s1();
    கட்டமைப்பு s2 t2 = fr_s2();
    கட்டமைப்பு s3 t3 = fr_s3();
    கட்டமைப்பு s4 t4 = fr_s4();
    கட்டமைப்பு s5 t5 = fr_s5();
    கட்டமைப்பு s6 t6 = fr_s6();
    கட்டமைப்பு s7 t7 = fr_s7();
    கட்டமைப்பு s8 t8 = fr_s8();
    கட்டமைப்பு s9 t9 = fr_s9();
    கட்டமைப்பு s10 t10 = fr_s10();
    கட்டமைப்பு s11 t11 = fr_s11();
    கட்டமைப்பு s12 t12 = fr_s12();
    கட்டமைப்பு s13 t13 = fr_s13();
    கட்டமைப்பு s14 t14 = fr_s14();
    கட்டமைப்பு s15 t15 = fr_s15();
    கட்டமைப்பு s16 t16 = fr_s16();
    கட்டமைப்பு s17 t17 = fr_s17();
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

வெறுமை*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles.
         */
        கட்டமைப்பு X { முழு _x; };
        கட்டமைப்பு X *x = va_arg(ap, கட்டமைப்பு X *);
        திரும்பு x;
}

முழு match(மாறிலி எழுத்து **s, மாறிலி எழுத்து *f)
{
    மாறிலி எழுத்து *p = *s;
    க்கு (p = *s; *f && *f == *p; f++, p++)
        ;
    எனில் (!*f) {
        *s = p - 1;
        திரும்பு 1;
    }
    திரும்பு 0;
}

வெறுமை myprintf(மாறிலி எழுத்து *format, ...)
{
    மாறிலி எழுத்து *s;
    va_list ap;
    va_start(ap, format);
    க்கு (s = format; *s; s++) {
        எனில் (match(&s, "%7s")) {
            கட்டமைப்பு s7 t7 = va_arg(ap, கட்டமைப்பு s7);
            printf("%.7s", t7.x);
        }
        இல்லையெனில் எனில் (match(&s, "%9s")) {
            கட்டமைப்பு s9 t9 = va_arg(ap, கட்டமைப்பு s9);
            printf("%.9s", t9.x);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa11")) {
            கட்டமைப்பு hfa11 x = va_arg(ap, கட்டமைப்பு hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa12")) {
            கட்டமைப்பு hfa12 x = va_arg(ap, கட்டமைப்பு hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa13")) {
            கட்டமைப்பு hfa13 x = va_arg(ap, கட்டமைப்பு hfa13);
            printf("%.1f,%.1f", x.a, x.c);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa14")) {
            கட்டமைப்பு hfa14 x = va_arg(ap, கட்டமைப்பு hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa21")) {
            கட்டமைப்பு hfa21 x = va_arg(ap, கட்டமைப்பு hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa22")) {
            கட்டமைப்பு hfa22 x = va_arg(ap, கட்டமைப்பு hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa23")) {
            கட்டமைப்பு hfa23 x = va_arg(ap, கட்டமைப்பு hfa23);
            printf("%.1f,%.1f", x.a, x.c);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa24")) {
            கட்டமைப்பு hfa24 x = va_arg(ap, கட்டமைப்பு hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa31")) {
            கட்டமைப்பு hfa31 x = va_arg(ap, கட்டமைப்பு hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa32")) {
            கட்டமைப்பு hfa32 x = va_arg(ap, கட்டமைப்பு hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa33")) {
            கட்டமைப்பு hfa33 x = va_arg(ap, கட்டமைப்பு hfa33);
            printf("%.1Lf,%.1Lf", x.a, x.c);
        }
        இல்லையெனில் எனில் (match(&s, "%hfa34")) {
            கட்டமைப்பு hfa34 x = va_arg(ap, கட்டமைப்பு hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        இல்லையெனில்
            putchar(*s);
    }
    putchar('\n');
}

வெறுமை stdarg(வெறுமை)
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

வெறுமை pll(unsigned long long x)
{
    printf("%llx\n", x);
}

வெறுமை movi(வெறுமை)
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

நிலையான uint32_t addip0(uint32_t x) { திரும்பு x + 0; }
நிலையான uint64_t sublp0(uint64_t x) { திரும்பு x - 0; }
நிலையான uint32_t addip123(uint32_t x) { திரும்பு x + 123; }
நிலையான uint64_t addlm123(uint64_t x) { திரும்பு x + -123; }
நிலையான uint64_t sublp4095(uint64_t x) { திரும்பு x - 4095; }
நிலையான uint32_t subim503808(uint32_t x) { திரும்பு x - -503808; }
நிலையான uint64_t addp12345(uint64_t x) { திரும்பு x + 12345; }
நிலையான uint32_t subp12345(uint32_t x) { திரும்பு x - 12345; }

நிலையான uint32_t mvni(uint32_t x) { திரும்பு 0xffffffff - x; }
நிலையான uint64_t negl(uint64_t x) { திரும்பு 0 - x; }
நிலையான uint32_t rsbi123(uint32_t x) { திரும்பு 123 - x; }
நிலையான uint64_t rsbl123(uint64_t x) { திரும்பு 123 - x; }

நிலையான uint32_t andi0(uint32_t x) { திரும்பு x & 0; }
நிலையான uint64_t andlm1(uint64_t x) { திரும்பு x & -1; }
நிலையான uint64_t orrl0(uint64_t x) { திரும்பு x | 0; }
நிலையான uint32_t orrim1(uint32_t x) { திரும்பு x | -1; }
நிலையான uint32_t eori0(uint32_t x) { திரும்பு x ^ 0; }
நிலையான uint64_t eorlm1(uint64_t x) { திரும்பு x ^ -1; }
நிலையான uint32_t and0xf0(uint32_t x) { திரும்பு x & 0xf0; }
நிலையான uint64_t orr0xf0(uint64_t x) { திரும்பு x | 0xf0; }
நிலையான uint64_t eor0xf0(uint64_t x) { திரும்பு x ^ 0xf0; }

நிலையான uint32_t lsli0(uint32_t x) { திரும்பு x << 0; }
நிலையான uint32_t lsri0(uint32_t x) { திரும்பு x >> 0; }
நிலையான int64_t asrl0(int64_t x) { திரும்பு x >> 0; }
நிலையான uint32_t lsli1(uint32_t x) { திரும்பு x << 1; }
நிலையான uint32_t lsli31(uint32_t x) { திரும்பு x << 31; }
நிலையான uint64_t lsll1(uint64_t x) { திரும்பு x << 1; }
நிலையான uint64_t lsll63(uint64_t x) { திரும்பு x << 63; }
நிலையான uint32_t lsri1(uint32_t x) { திரும்பு x >> 1; }
நிலையான uint32_t lsri31(uint32_t x) { திரும்பு x >> 31; }
நிலையான uint64_t lsrl1(uint64_t x) { திரும்பு x >> 1; }
நிலையான uint64_t lsrl63(uint64_t x) { திரும்பு x >> 63; }
நிலையான int32_t asri1(int32_t x) { திரும்பு x >> 1; }
நிலையான int32_t asri31(int32_t x) { திரும்பு x >> 31; }
நிலையான int64_t asrl1(int64_t x) { திரும்பு x >> 1; }
நிலையான int64_t asrl63(int64_t x) { திரும்பு x >> 63; }

வெறுமை opi(வெறுமை)
{
    முழு x = 1000;
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

வெறுமை pcs(வெறுமை)
{
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

முழு முதன்மை()
{
    pcs();
    திரும்பு 0;
}
