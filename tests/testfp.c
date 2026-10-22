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

#অন্তর্ভাব <stdint.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <string.h>

#define check(x) ((x) ? (শূন্য)0 : check_fail(#x, __FILE__, __LINE__))

শূন্য check_fail(ধ্রুবক অক্ষর *assertion, ধ্রুবক অক্ষর *file, unsigned পূর্ণসংখ্যা সারি)
{
    printf("%s:%d: Check (%s) failed.", file, সারি, assertion);
    exit(1);
}

প্রকারলেখ কাঠামো {
    unsigned long long x0, x1;
} u128_t;

দশমিক copy_fi(uint32_t x)
{
    দশমিক f;
    memcpy(&f, &x, 4);
    ফেরত f;
}

দ্বিগুণ copy_di(uint64_t x)
{
    দ্বিগুণ f;
    memcpy(&f, &x, 8);
    ফেরত f;
}

long দ্বিগুণ copy_ldi(u128_t x)
{
    long দ্বিগুণ f;
    memcpy(&f, &x, 16);
    ফেরত f;
}

uint32_t copy_if(দশমিক f)
{
    uint32_t x;
    memcpy(&x, &f, 4);
    ফেরত x;
}

uint64_t copy_id(দ্বিগুণ f)
{
    uint64_t x;
    memcpy(&x, &f, 8);
    ফেরত x;
}

u128_t copy_ild(long দ্বিগুণ f)
{
    u128_t x;
    memcpy(&x, &f, 16);
    ফেরত x;
}

long দ্বিগুণ make(পূর্ণসংখ্যা sgn, পূর্ণসংখ্যা exp, uint64_t উপরের, uint64_t নিচের)
{
    u128_t x = { নিচের,
                 (0x0000ffffffffffff & উপরের) |
                 (0x7fff000000000000 & (uint64_t)exp << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    ফেরত copy_ldi(x);
}

শূন্য cmp(long দ্বিগুণ a, long দ্বিগুণ b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    পূর্ণসংখ্যা eq = (a == b);
    পূর্ণসংখ্যা ne = (a != b);
    পূর্ণসংখ্যা lt = (a < b);
    পূর্ণসংখ্যা le = (a <= b);
    পূর্ণসংখ্যা gt = (a > b);
    পূর্ণসংখ্যা ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    printf("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

শূন্য cmps(শূন্য)
{
    পূর্ণসংখ্যা i, j;

    জন্য (i = 0; i < 2; i++)
        জন্য (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    জন্য (i = 0; i < 2; i++) {
        জন্য (j = 0; j < 64; j++) {
            long দ্বিগুণ f1 = make(i, 32767, (uint64_t)1 << j, 0);
            long দ্বিগুণ f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    জন্য (i = 0; i < 6; i++)
        জন্য (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    জন্য (i = 0; i < 2; i++) {
        জন্য (j = 0; j < 2; j++) {
            পূর্ণসংখ্যা a, b;
            জন্য (a = 0; a < 2; a++) {
                জন্য (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

শূন্য xop(ধ্রুবক অক্ষর *name, long দ্বিগুণ a, long দ্বিগুণ b, long দ্বিগুণ c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    printf("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

শূন্য fadd(long দ্বিগুণ a, long দ্বিগুণ b)
{
    xop("add", a, b, a + b);
}

শূন্য fsub(long দ্বিগুণ a, long দ্বিগুণ b)
{
    xop("sub", a, b, a - b);
}

শূন্য fmul(long দ্বিগুণ a, long দ্বিগুণ b)
{
    xop("mul", a, b, a * b);
}

শূন্য fdiv(long দ্বিগুণ a, long দ্বিগুণ b)
{
    xop("div", a, b, a / b);
}

শূন্য nanz(শূন্য)
{
    // Check NaNs:
    {
        long দ্বিগুণ x[7];
        পূর্ণসংখ্যা i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == আকার(x) / আকার(*x));
        জন্য (i = 0; i < n; i++) {
            জন্য (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        long দ্বিগুণ x[6];
        পূর্ণসংখ্যা i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == আকার(x) / আকার(*x));
        জন্য (i = 0; i < n; i++) {
            জন্য (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

শূন্য adds(শূন্য)
{
    // Check shifting and add/sub:
    {
        পূর্ণসংখ্যা i;
        জন্য (i = -130; i <= 130; i++) {
            পূর্ণসংখ্যা s1 = (uint32_t)i % 3 < 1;
            পূর্ণসংখ্যা s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        পূর্ণসংখ্যা ee[] = { 0, 1, 10000 };
        পূর্ণসংখ্যা e, i;
        জন্য (e = 0; e < আকার(ee) / আকার(*ee); e++) {
            পূর্ণসংখ্যা exp = ee[e];
            fsub(make(0, exp, a1, a0), make(0, 0, 0, 0));
            জন্য (i = 63; i >= 0; i--)
                fsub(make(0, exp, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, exp, a1 >> i << i, 0));
            জন্য (i = 63; i >=0; i--)
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

শূন্য muls(শূন্য)
{
    পূর্ণসংখ্যা i, j;

    {
        long দ্বিগুণ max = make(0, 32766, -1, -1);
        long দ্বিগুণ min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    জন্য (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    জন্য (i = 0; i < 2; i++)
        জন্য (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

শূন্য divs(শূন্য)
{
    পূর্ণসংখ্যা i;

    {
        long দ্বিগুণ max = make(0, 32766, -1, -1);
        long দ্বিগুণ min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    জন্য (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    জন্য (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

শূন্য cvtlsw(int32_t a)
{
    long দ্বিগুণ f = a;
    u128_t x = copy_ild(f);
    printf("cvtlsw %08lx %016llx%016llx\n", (long)(uint32_t)a, x.x1, x.x0);
}

শূন্য cvtlsx(int64_t a)
{
    long দ্বিগুণ f = a;
    u128_t x = copy_ild(f);
    printf("cvtlsx %016llx %016llx%016llx\n",
           (long long)(uint64_t)a, x.x1, x.x0);
}

শূন্য cvtluw(uint32_t a)
{
    long দ্বিগুণ f = a;
    u128_t x = copy_ild(f);
    printf("cvtluw %08lx %016llx%016llx\n", (long)a, x.x1, x.x0);
}

শূন্য cvtlux(uint64_t a)
{
    long দ্বিগুণ f = a;
    u128_t x = copy_ild(f);
    printf("cvtlux %016llx %016llx%016llx\n", (long long)a, x.x1, x.x0);
}

শূন্য cvtil(long দ্বিগুণ a)
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

শূন্য cvtlf(দশমিক a)
{
    uint32_t ax = copy_if(a);
    long দ্বিগুণ b = a;
    u128_t bx = copy_ild(b);
    printf("cvtlf %08lx %016llx%016llx\n", (long)ax, bx.x1, bx.x0);
}

শূন্য cvtld(দ্বিগুণ a)
{
    uint64_t ax = copy_id(a);
    long দ্বিগুণ b = a;
    u128_t bx = copy_ild(b);
    printf("cvtld %016llx %016llx%016llx\n", (long long)ax, bx.x1, bx.x0);
}

শূন্য cvtfl(long দ্বিগুণ a)
{
    u128_t ax = copy_ild(a);
    দশমিক b = a;
    uint32_t bx = copy_if(b);
    printf("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (long)bx);
}

শূন্য cvtdl(long দ্বিগুণ a)
{
    u128_t ax = copy_ild(a);
    দ্বিগুণ b = a;
    uint64_t bx = copy_id(b);
    printf("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (long long)bx);
}

শূন্য cvts(শূন্য)
{
    পূর্ণসংখ্যা i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        জন্য (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        জন্য (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        জন্য (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        জন্য (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        জন্য (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        জন্য (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    জন্য (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        জন্য (j = 0; j < 68; j++)
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

    জন্য (i = 0; i < 2; i++) {                   \
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

    জন্য (i = 0; i < 2; i++) {
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

শূন্য tests(শূন্য)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

পূর্ণসংখ্যা প্রধান()
{
#ifdef __aarch64__
    tests();
#অন্যথা
    printf("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#endif
    ফেরত 0;
}
