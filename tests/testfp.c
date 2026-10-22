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

#अन्तर्भाव <stdint.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <string.h>

#define check(x) ((x) ? (शून्य)0 : check_fail(#x, __FILE__, __LINE__))

शून्य check_fail(ध्रुव वर्ण *assertion, ध्रुव वर्ण *file, unsigned पूर्णाङ्क ओळ)
{
    printf("%s:%d: Check (%s) failed.", file, ओळ, assertion);
    exit(1);
}

प्रकारनिर्देश संरचना {
    unsigned long long x0, x1;
} u128_t;

भिन्न copy_fi(uint32_t x)
{
    भिन्न f;
    memcpy(&f, &x, 4);
    प्रत्यागम f;
}

द्विगुण copy_di(uint64_t x)
{
    द्विगुण f;
    memcpy(&f, &x, 8);
    प्रत्यागम f;
}

long द्विगुण copy_ldi(u128_t x)
{
    long द्विगुण f;
    memcpy(&f, &x, 16);
    प्रत्यागम f;
}

uint32_t copy_if(भिन्न f)
{
    uint32_t x;
    memcpy(&x, &f, 4);
    प्रत्यागम x;
}

uint64_t copy_id(द्विगुण f)
{
    uint64_t x;
    memcpy(&x, &f, 8);
    प्रत्यागम x;
}

u128_t copy_ild(long द्विगुण f)
{
    u128_t x;
    memcpy(&x, &f, 16);
    प्रत्यागम x;
}

long द्विगुण make(पूर्णाङ्क sgn, पूर्णाङ्क exp, uint64_t वरचा, uint64_t खालचा)
{
    u128_t x = { खालचा,
                 (0x0000ffffffffffff & वरचा) |
                 (0x7fff000000000000 & (uint64_t)exp << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    प्रत्यागम copy_ldi(x);
}

शून्य cmp(long द्विगुण a, long द्विगुण b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    पूर्णाङ्क eq = (a == b);
    पूर्णाङ्क ne = (a != b);
    पूर्णाङ्क lt = (a < b);
    पूर्णाङ्क le = (a <= b);
    पूर्णाङ्क gt = (a > b);
    पूर्णाङ्क ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    printf("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

शून्य cmps(शून्य)
{
    पूर्णाङ्क i, j;

    प्रति (i = 0; i < 2; i++)
        प्रति (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    प्रति (i = 0; i < 2; i++) {
        प्रति (j = 0; j < 64; j++) {
            long द्विगुण f1 = make(i, 32767, (uint64_t)1 << j, 0);
            long द्विगुण f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    प्रति (i = 0; i < 6; i++)
        प्रति (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    प्रति (i = 0; i < 2; i++) {
        प्रति (j = 0; j < 2; j++) {
            पूर्णाङ्क a, b;
            प्रति (a = 0; a < 2; a++) {
                प्रति (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

शून्य xop(ध्रुव वर्ण *name, long द्विगुण a, long द्विगुण b, long द्विगुण c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    printf("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

शून्य fadd(long द्विगुण a, long द्विगुण b)
{
    xop("add", a, b, a + b);
}

शून्य fsub(long द्विगुण a, long द्विगुण b)
{
    xop("sub", a, b, a - b);
}

शून्य fmul(long द्विगुण a, long द्विगुण b)
{
    xop("mul", a, b, a * b);
}

शून्य fdiv(long द्विगुण a, long द्विगुण b)
{
    xop("div", a, b, a / b);
}

शून्य nanz(शून्य)
{
    // Check NaNs:
    {
        long द्विगुण x[7];
        पूर्णाङ्क i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == परिमाण(x) / परिमाण(*x));
        प्रति (i = 0; i < n; i++) {
            प्रति (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        long द्विगुण x[6];
        पूर्णाङ्क i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == परिमाण(x) / परिमाण(*x));
        प्रति (i = 0; i < n; i++) {
            प्रति (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

शून्य adds(शून्य)
{
    // Check shifting and add/sub:
    {
        पूर्णाङ्क i;
        प्रति (i = -130; i <= 130; i++) {
            पूर्णाङ्क s1 = (uint32_t)i % 3 < 1;
            पूर्णाङ्क s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        पूर्णाङ्क ee[] = { 0, 1, 10000 };
        पूर्णाङ्क e, i;
        प्रति (e = 0; e < परिमाण(ee) / परिमाण(*ee); e++) {
            पूर्णाङ्क exp = ee[e];
            fsub(make(0, exp, a1, a0), make(0, 0, 0, 0));
            प्रति (i = 63; i >= 0; i--)
                fsub(make(0, exp, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, exp, a1 >> i << i, 0));
            प्रति (i = 63; i >=0; i--)
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

शून्य muls(शून्य)
{
    पूर्णाङ्क i, j;

    {
        long द्विगुण max = make(0, 32766, -1, -1);
        long द्विगुण min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    प्रति (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    प्रति (i = 0; i < 2; i++)
        प्रति (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

शून्य divs(शून्य)
{
    पूर्णाङ्क i;

    {
        long द्विगुण max = make(0, 32766, -1, -1);
        long द्विगुण min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    प्रति (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    प्रति (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

शून्य cvtlsw(int32_t a)
{
    long द्विगुण f = a;
    u128_t x = copy_ild(f);
    printf("cvtlsw %08lx %016llx%016llx\n", (long)(uint32_t)a, x.x1, x.x0);
}

शून्य cvtlsx(int64_t a)
{
    long द्विगुण f = a;
    u128_t x = copy_ild(f);
    printf("cvtlsx %016llx %016llx%016llx\n",
           (long long)(uint64_t)a, x.x1, x.x0);
}

शून्य cvtluw(uint32_t a)
{
    long द्विगुण f = a;
    u128_t x = copy_ild(f);
    printf("cvtluw %08lx %016llx%016llx\n", (long)a, x.x1, x.x0);
}

शून्य cvtlux(uint64_t a)
{
    long द्विगुण f = a;
    u128_t x = copy_ild(f);
    printf("cvtlux %016llx %016llx%016llx\n", (long long)a, x.x1, x.x0);
}

शून्य cvtil(long द्विगुण a)
{
    u128_t x = copy_ild(a);
    int32_t b1 = a;
    int64_t b2 = a;
    uint32_t b3 = a;
    uint64_t b4 = a;
    printf("cvtswl %016llx%016llx %08lx\n",
           x.x1, x.x0, (long)(uint32_t)b1);
    printf("cvtsxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (long long)(uint64_t)b2);
    printf("cvtuwl %016llx%016llx %08lx\n",
           x.x1, x.x0, (long)b3);
    printf("cvtuxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (long long)b4);
}

शून्य cvtlf(भिन्न a)
{
    uint32_t ax = copy_if(a);
    long द्विगुण b = a;
    u128_t bx = copy_ild(b);
    printf("cvtlf %08lx %016llx%016llx\n", (long)ax, bx.x1, bx.x0);
}

शून्य cvtld(द्विगुण a)
{
    uint64_t ax = copy_id(a);
    long द्विगुण b = a;
    u128_t bx = copy_ild(b);
    printf("cvtld %016llx %016llx%016llx\n", (long long)ax, bx.x1, bx.x0);
}

शून्य cvtfl(long द्विगुण a)
{
    u128_t ax = copy_ild(a);
    भिन्न b = a;
    uint32_t bx = copy_if(b);
    printf("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (long)bx);
}

शून्य cvtdl(long द्विगुण a)
{
    u128_t ax = copy_ild(a);
    द्विगुण b = a;
    uint64_t bx = copy_id(b);
    printf("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (long long)bx);
}

शून्य cvts(शून्य)
{
    पूर्णाङ्क i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        प्रति (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        प्रति (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        प्रति (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        प्रति (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        प्रति (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        प्रति (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    प्रति (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        प्रति (j = 0; j < 68; j++)
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

    प्रति (i = 0; i < 2; i++) {                   \
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

    प्रति (i = 0; i < 2; i++) {
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

शून्य tests(शून्य)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

पूर्णाङ्क main()
{
#ifdef __aarch64__
    tests();
#अन्यथा
    printf("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#endif
    प्रत्यागम 0;
}
