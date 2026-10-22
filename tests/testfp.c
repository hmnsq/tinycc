/*
 *  Test 128-bit floating-point arithmetic on arm64:
 *  build with two different compilers and compare the output.
 *
 *  Copyright (c) 2015 Edmund Grimley Evans
 *
 * Copying and distribution of this file, with or without modification,
 * are permitted in any medium without royalty provided the copyright
 * notice and this notice are preserved.  This file is offered as-is,
 * without any warranty.
 */

#समावेश <stdint.h>
#समावेश <stdio.h>
#समावेश <stdlib.h>
#समावेश <string.h>

#घोषणा check(x) ((x) ? (व्योम)0 : check_fail(#x, __खाता__, __LINE__))

व्योम check_fail(स्थिर अक्षर *assertion, स्थिर अक्षर *file, अचिन्हित पूर्णांक पंक्ति_2)
{
    म_लिखो("%s:%d: Check (%s) failed.", file, पंक्ति_2, assertion);
    निकास(1);
}

प्रकार काष्ठा {
    अचिन्हित दीर्घ दीर्घ x0, x1;
} u128_t;

भग्न copy_fi(uint32_t x)
{
    भग्न f;
    स_नकल(&f, &x, 4);
    वापस f;
}

द्विगुन copy_di(uint64_t x)
{
    द्विगुन f;
    स_नकल(&f, &x, 8);
    वापस f;
}

दीर्घ द्विगुन copy_ldi(u128_t x)
{
    दीर्घ द्विगुन f;
    स_नकल(&f, &x, 16);
    वापस f;
}

uint32_t copy_if(भग्न f)
{
    uint32_t x;
    स_नकल(&x, &f, 4);
    वापस x;
}

uint64_t copy_id(द्विगुन f)
{
    uint64_t x;
    स_नकल(&x, &f, 8);
    वापस x;
}

u128_t copy_ild(दीर्घ द्विगुन f)
{
    u128_t x;
    स_नकल(&x, &f, 16);
    वापस x;
}

दीर्घ द्विगुन make(पूर्णांक sgn, पूर्णांक exp, uint64_t ऊपरी, uint64_t निचला)
{
    u128_t x = { निचला,
                 (0x0000ffffffffffff & ऊपरी) |
                 (0x7fff000000000000 & (uint64_t)exp << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    वापस copy_ldi(x);
}

व्योम cmp(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    पूर्णांक eq = (a == b);
    पूर्णांक ne = (a != b);
    पूर्णांक lt = (a < b);
    पूर्णांक le = (a <= b);
    पूर्णांक gt = (a > b);
    पूर्णांक ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    म_लिखो("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

व्योम cmps(व्योम)
{
    पूर्णांक i, j;

    क्रम (i = 0; i < 2; i++)
        क्रम (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    क्रम (i = 0; i < 2; i++) {
        क्रम (j = 0; j < 64; j++) {
            दीर्घ द्विगुन f1 = make(i, 32767, (uint64_t)1 << j, 0);
            दीर्घ द्विगुन f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    क्रम (i = 0; i < 6; i++)
        क्रम (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    क्रम (i = 0; i < 2; i++) {
        क्रम (j = 0; j < 2; j++) {
            पूर्णांक a, b;
            क्रम (a = 0; a < 2; a++) {
                क्रम (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

व्योम xop(स्थिर अक्षर *name, दीर्घ द्विगुन a, दीर्घ द्विगुन b, दीर्घ द्विगुन c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    म_लिखो("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

व्योम fadd(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    xop("add", a, b, a + b);
}

व्योम fsub(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    xop("sub", a, b, a - b);
}

व्योम fmul(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    xop("mul", a, b, a * b);
}

व्योम fdiv(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    xop("div", a, b, a / b);
}

व्योम nanz(व्योम)
{
    // Check NaNs:
    {
        दीर्घ द्विगुन x[7];
        पूर्णांक i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == माप(x) / माप(*x));
        क्रम (i = 0; i < n; i++) {
            क्रम (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        दीर्घ द्विगुन x[6];
        पूर्णांक i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == माप(x) / माप(*x));
        क्रम (i = 0; i < n; i++) {
            क्रम (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

व्योम adds(व्योम)
{
    // Check shifting and add/sub:
    {
        पूर्णांक i;
        क्रम (i = -130; i <= 130; i++) {
            पूर्णांक s1 = (uint32_t)i % 3 < 1;
            पूर्णांक s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        पूर्णांक ee[] = { 0, 1, 10000 };
        पूर्णांक e, i;
        क्रम (e = 0; e < माप(ee) / माप(*ee); e++) {
            पूर्णांक exp = ee[e];
            fsub(make(0, exp, a1, a0), make(0, 0, 0, 0));
            क्रम (i = 63; i >= 0; i--)
                fsub(make(0, exp, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, exp, a1 >> i << i, 0));
            क्रम (i = 63; i >=0; i--)
                fsub(make(0, exp, a1, a0 | (uint64_t)1 << i >> 1),
                     make(0, exp, a1, a0 >> i << i));
        }
    }

    // Carry/overflow from rounding:
    {
        fadd(make(0, 114, -1, -1), make(0, 1, 0, 0));
        fadd(make(0, 32766, -1, -1), make(0, 32653, 0, 0));
        fsub(make(1, 32766, -1, -1), make(0, 32653, 0, 0));
    }
}

व्योम muls(व्योम)
{
    पूर्णांक i, j;

    {
        दीर्घ द्विगुन max = make(0, 32766, -1, -1);
        दीर्घ द्विगुन min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    क्रम (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    क्रम (i = 0; i < 2; i++)
        क्रम (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

व्योम divs(व्योम)
{
    पूर्णांक i;

    {
        दीर्घ द्विगुन max = make(0, 32766, -1, -1);
        दीर्घ द्विगुन min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    क्रम (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    क्रम (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

व्योम cvtlsw(int32_t a)
{
    दीर्घ द्विगुन f = a;
    u128_t x = copy_ild(f);
    म_लिखो("cvtlsw %08lx %016llx%016llx\n", (दीर्घ)(uint32_t)a, x.x1, x.x0);
}

व्योम cvtlsx(int64_t a)
{
    दीर्घ द्विगुन f = a;
    u128_t x = copy_ild(f);
    म_लिखो("cvtlsx %016llx %016llx%016llx\n",
           (दीर्घ दीर्घ)(uint64_t)a, x.x1, x.x0);
}

व्योम cvtluw(uint32_t a)
{
    दीर्घ द्विगुन f = a;
    u128_t x = copy_ild(f);
    म_लिखो("cvtluw %08lx %016llx%016llx\n", (दीर्घ)a, x.x1, x.x0);
}

व्योम cvtlux(uint64_t a)
{
    दीर्घ द्विगुन f = a;
    u128_t x = copy_ild(f);
    म_लिखो("cvtlux %016llx %016llx%016llx\n", (दीर्घ दीर्घ)a, x.x1, x.x0);
}

व्योम cvtil(दीर्घ द्विगुन a)
{
    u128_t x = copy_ild(a);
    int32_t b1 = a;
    int64_t b2 = a;
    uint32_t b3 = a;
    uint64_t b4 = a;
    म_लिखो("cvtswl %016llx%016llx %08lx\n",
           x.x1, x.x0, (दीर्घ)(uint32_t)b1);
    म_लिखो("cvtsxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (दीर्घ दीर्घ)(uint64_t)b2);
    म_लिखो("cvtuwl %016llx%016llx %08lx\n",
           x.x1, x.x0, (दीर्घ)b3);
    म_लिखो("cvtuxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (दीर्घ दीर्घ)b4);
}

व्योम cvtlf(भग्न a)
{
    uint32_t ax = copy_if(a);
    दीर्घ द्विगुन b = a;
    u128_t bx = copy_ild(b);
    म_लिखो("cvtlf %08lx %016llx%016llx\n", (दीर्घ)ax, bx.x1, bx.x0);
}

व्योम cvtld(द्विगुन a)
{
    uint64_t ax = copy_id(a);
    दीर्घ द्विगुन b = a;
    u128_t bx = copy_ild(b);
    म_लिखो("cvtld %016llx %016llx%016llx\n", (दीर्घ दीर्घ)ax, bx.x1, bx.x0);
}

व्योम cvtfl(दीर्घ द्विगुन a)
{
    u128_t ax = copy_ild(a);
    भग्न b = a;
    uint32_t bx = copy_if(b);
    म_लिखो("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (दीर्घ)bx);
}

व्योम cvtdl(दीर्घ द्विगुन a)
{
    u128_t ax = copy_ild(a);
    द्विगुन b = a;
    uint64_t bx = copy_id(b);
    म_लिखो("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (दीर्घ दीर्घ)bx);
}

व्योम cvts(व्योम)
{
    पूर्णांक i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        क्रम (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        क्रम (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        क्रम (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        क्रम (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        क्रम (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        क्रम (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    क्रम (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        क्रम (j = 0; j < 68; j++)
            cvtil(make(i, 16381 + j, 0xd4822c0a10ec, 0x1fe2f8b2669f5c9d));
    }

    cvtlf(copy_fi(0x00000000));
    cvtlf(copy_fi(0x456789ab));
    cvtlf(copy_fi(0x7f800000));
    cvtlf(copy_fi(0x7f923456));
    cvtlf(copy_fi(0x7fdbcdef));
    cvtlf(copy_fi(0x80000000));
    cvtlf(copy_fi(0xabcdef12));
    cvtlf(copy_fi(0xff800000));
    cvtlf(copy_fi(0xff923456));
    cvtlf(copy_fi(0xffdbcdef));

    cvtld(copy_di(0x0000000000000000));
    cvtld(copy_di(0x456789abcdef0123));
    cvtld(copy_di(0x7ff0000000000000));
    cvtld(copy_di(0x7ff123456789abcd));
    cvtld(copy_di(0x7ffabcdef1234567));
    cvtld(copy_di(0x8000000000000000));
    cvtld(copy_di(0xcdef123456789abc));
    cvtld(copy_di(0xfff0000000000000));
    cvtld(copy_di(0xfff123456789abcd));
    cvtld(copy_di(0xfffabcdef1234567));

    क्रम (i = 0; i < 2; i++) {                   \
        cvtfl(make(i, 0, 0, 0));
        cvtfl(make(i, 16232, -1, -1));
        cvtfl(make(i, 16233, 0, 0));
        cvtfl(make(i, 16233, 0, 1));
        cvtfl(make(i, 16383, 0xab0ffd000000, 0));
        cvtfl(make(i, 16383, 0xab0ffd000001, 0));
        cvtfl(make(i, 16383, 0xab0ffeffffff, 0));
        cvtfl(make(i, 16383, 0xab0fff000000, 0));
        cvtfl(make(i, 16383, 0xab0fff000001, 0));
        cvtfl(make(i, 16510, 0xfffffeffffff, -1));
        cvtfl(make(i, 16510, 0xffffff000000, 0));
        cvtfl(make(i, 16511, 0, 0));
        cvtfl(make(i, 32767, 0, 0));
        cvtfl(make(i, 32767, 0, 1));
        cvtfl(make(i, 32767, 0x4cbe01ac5f40, 0x75cee3c6afbb00b5));
        cvtfl(make(i, 32767, 0x800000000000, 1));
        cvtfl(make(i, 32767, 0xa11caaaf6a52, 0x696033e871eab099));
    }

    क्रम (i = 0; i < 2; i++) {
        cvtdl(make(i, 0, 0, 0));
        cvtdl(make(i, 15307, -1, -1));
        cvtdl(make(i, 15308, 0, 0));
        cvtdl(make(i, 15308, 0, 1));
        cvtdl(make(i, 16383, 0xabc123abc0ff, 0xe800000000000000));
        cvtdl(make(i, 16383, 0xabc123abc0ff, 0xe800000000000001));
        cvtdl(make(i, 16383, 0xabc123abc0ff, 0xf7ffffffffffffff));
        cvtdl(make(i, 16383, 0xabc123abc0ff, 0xf800000000000000));
        cvtdl(make(i, 16383, 0xabc123abc0ff, 0xf800000000000001));
        cvtdl(make(i, 17406, 0xffffffffffff, 0xf7ffffffffffffff));
        cvtdl(make(i, 17406, 0xffffffffffff, 0xf800000000000000));
        cvtdl(make(i, 17407, 0, 0));
        cvtdl(make(i, 32767, 0, 0));
        cvtdl(make(i, 32767, 0, 1));
        cvtdl(make(i, 32767, 0x4cbe01ac5f40, 0x75cee3c6afbb00b5));
        cvtdl(make(i, 32767, 0x800000000000, 1));
        cvtdl(make(i, 32767, 0xa11caaaf6a52, 0x696033e871eab099));
    }
}

व्योम tests(व्योम)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

पूर्णांक मुख्य()
{
#अगर_घोषित __aarch64__
    tests();
#अन्यथा
    म_लिखो("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#पूर्ण_अगर
    वापस 0;
}
