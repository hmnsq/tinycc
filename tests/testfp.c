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

#ଅନ୍ତର୍ଭାଵ <stdint.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <string.h>

#define check(x) ((x) ? (ଶୂନ୍ୟ)0 : check_fail(#x, __FILE__, __LINE__))

ଶୂନ୍ୟ check_fail(ଅଚଳ ଅକ୍ଷର *assertion, ଅଚଳ ଅକ୍ଷର *file, unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି)
{
    printf("%s:%d: Check (%s) failed.", file, ଧାଡ଼ି, assertion);
    exit(1);
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    unsigned long long x0, x1;
} u128_t;

ଦଶମିକ copy_fi(uint32_t x)
{
    ଦଶମିକ f;
    memcpy(&f, &x, 4);
    ଫେରନ୍ତୁ f;
}

ଦ୍ୱିଗୁଣ copy_di(uint64_t x)
{
    ଦ୍ୱିଗୁଣ f;
    memcpy(&f, &x, 8);
    ଫେରନ୍ତୁ f;
}

long ଦ୍ୱିଗୁଣ copy_ldi(u128_t x)
{
    long ଦ୍ୱିଗୁଣ f;
    memcpy(&f, &x, 16);
    ଫେରନ୍ତୁ f;
}

uint32_t copy_if(ଦଶମିକ f)
{
    uint32_t x;
    memcpy(&x, &f, 4);
    ଫେରନ୍ତୁ x;
}

uint64_t copy_id(ଦ୍ୱିଗୁଣ f)
{
    uint64_t x;
    memcpy(&x, &f, 8);
    ଫେରନ୍ତୁ x;
}

u128_t copy_ild(long ଦ୍ୱିଗୁଣ f)
{
    u128_t x;
    memcpy(&x, &f, 16);
    ଫେରନ୍ତୁ x;
}

long ଦ୍ୱିଗୁଣ make(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sgn, ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp, uint64_t ଉପର, uint64_t ତଳ)
{
    u128_t x = { ତଳ,
                 (0x0000ffffffffffff & ଉପର) |
                 (0x7fff000000000000 & (uint64_t)exp << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    ଫେରନ୍ତୁ copy_ldi(x);
}

ଶୂନ୍ୟ cmp(long ଦ୍ୱିଗୁଣ a, long ଦ୍ୱିଗୁଣ b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା eq = (a == b);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ne = (a != b);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା lt = (a < b);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା le = (a <= b);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା gt = (a > b);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    printf("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

ଶୂନ୍ୟ cmps(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;

    ପାଇଁ (i = 0; i < 2; i++)
        ପାଇଁ (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    ପାଇଁ (i = 0; i < 2; i++) {
        ପାଇଁ (j = 0; j < 64; j++) {
            long ଦ୍ୱିଗୁଣ f1 = make(i, 32767, (uint64_t)1 << j, 0);
            long ଦ୍ୱିଗୁଣ f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    ପାଇଁ (i = 0; i < 6; i++)
        ପାଇଁ (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    ପାଇଁ (i = 0; i < 2; i++) {
        ପାଇଁ (j = 0; j < 2; j++) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b;
            ପାଇଁ (a = 0; a < 2; a++) {
                ପାଇଁ (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

ଶୂନ୍ୟ xop(ଅଚଳ ଅକ୍ଷର *name, long ଦ୍ୱିଗୁଣ a, long ଦ୍ୱିଗୁଣ b, long ଦ୍ୱିଗୁଣ c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    printf("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

ଶୂନ୍ୟ fadd(long ଦ୍ୱିଗୁଣ a, long ଦ୍ୱିଗୁଣ b)
{
    xop("add", a, b, a + b);
}

ଶୂନ୍ୟ fsub(long ଦ୍ୱିଗୁଣ a, long ଦ୍ୱିଗୁଣ b)
{
    xop("sub", a, b, a - b);
}

ଶୂନ୍ୟ fmul(long ଦ୍ୱିଗୁଣ a, long ଦ୍ୱିଗୁଣ b)
{
    xop("mul", a, b, a * b);
}

ଶୂନ୍ୟ fdiv(long ଦ୍ୱିଗୁଣ a, long ଦ୍ୱିଗୁଣ b)
{
    xop("div", a, b, a / b);
}

ଶୂନ୍ୟ nanz(ଶୂନ୍ୟ)
{
    // Check NaNs:
    {
        long ଦ୍ୱିଗୁଣ x[7];
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == ଆକାର(x) / ଆକାର(*x));
        ପାଇଁ (i = 0; i < n; i++) {
            ପାଇଁ (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        long ଦ୍ୱିଗୁଣ x[6];
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == ଆକାର(x) / ଆକାର(*x));
        ପାଇଁ (i = 0; i < n; i++) {
            ପାଇଁ (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

ଶୂନ୍ୟ adds(ଶୂନ୍ୟ)
{
    // Check shifting and add/sub:
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
        ପାଇଁ (i = -130; i <= 130; i++) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା s1 = (uint32_t)i % 3 < 1;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ee[] = { 0, 1, 10000 };
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା e, i;
        ପାଇଁ (e = 0; e < ଆକାର(ee) / ଆକାର(*ee); e++) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp = ee[e];
            fsub(make(0, exp, a1, a0), make(0, 0, 0, 0));
            ପାଇଁ (i = 63; i >= 0; i--)
                fsub(make(0, exp, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, exp, a1 >> i << i, 0));
            ପାଇଁ (i = 63; i >=0; i--)
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

ଶୂନ୍ୟ muls(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;

    {
        long ଦ୍ୱିଗୁଣ max = make(0, 32766, -1, -1);
        long ଦ୍ୱିଗୁଣ min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    ପାଇଁ (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    ପାଇଁ (i = 0; i < 2; i++)
        ପାଇଁ (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

ଶୂନ୍ୟ divs(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    {
        long ଦ୍ୱିଗୁଣ max = make(0, 32766, -1, -1);
        long ଦ୍ୱିଗୁଣ min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    ପାଇଁ (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    ପାଇଁ (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

ଶୂନ୍ୟ cvtlsw(int32_t a)
{
    long ଦ୍ୱିଗୁଣ f = a;
    u128_t x = copy_ild(f);
    printf("cvtlsw %08lx %016llx%016llx\n", (long)(uint32_t)a, x.x1, x.x0);
}

ଶୂନ୍ୟ cvtlsx(int64_t a)
{
    long ଦ୍ୱିଗୁଣ f = a;
    u128_t x = copy_ild(f);
    printf("cvtlsx %016llx %016llx%016llx\n",
           (long long)(uint64_t)a, x.x1, x.x0);
}

ଶୂନ୍ୟ cvtluw(uint32_t a)
{
    long ଦ୍ୱିଗୁଣ f = a;
    u128_t x = copy_ild(f);
    printf("cvtluw %08lx %016llx%016llx\n", (long)a, x.x1, x.x0);
}

ଶୂନ୍ୟ cvtlux(uint64_t a)
{
    long ଦ୍ୱିଗୁଣ f = a;
    u128_t x = copy_ild(f);
    printf("cvtlux %016llx %016llx%016llx\n", (long long)a, x.x1, x.x0);
}

ଶୂନ୍ୟ cvtil(long ଦ୍ୱିଗୁଣ a)
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

ଶୂନ୍ୟ cvtlf(ଦଶମିକ a)
{
    uint32_t ax = copy_if(a);
    long ଦ୍ୱିଗୁଣ b = a;
    u128_t bx = copy_ild(b);
    printf("cvtlf %08lx %016llx%016llx\n", (long)ax, bx.x1, bx.x0);
}

ଶୂନ୍ୟ cvtld(ଦ୍ୱିଗୁଣ a)
{
    uint64_t ax = copy_id(a);
    long ଦ୍ୱିଗୁଣ b = a;
    u128_t bx = copy_ild(b);
    printf("cvtld %016llx %016llx%016llx\n", (long long)ax, bx.x1, bx.x0);
}

ଶୂନ୍ୟ cvtfl(long ଦ୍ୱିଗୁଣ a)
{
    u128_t ax = copy_ild(a);
    ଦଶମିକ b = a;
    uint32_t bx = copy_if(b);
    printf("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (long)bx);
}

ଶୂନ୍ୟ cvtdl(long ଦ୍ୱିଗୁଣ a)
{
    u128_t ax = copy_ild(a);
    ଦ୍ୱିଗୁଣ b = a;
    uint64_t bx = copy_id(b);
    printf("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (long long)bx);
}

ଶୂନ୍ୟ cvts(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        ପାଇଁ (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        ପାଇଁ (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        ପାଇଁ (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        ପାଇଁ (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        ପାଇଁ (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        ପାଇଁ (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    ପାଇଁ (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        ପାଇଁ (j = 0; j < 68; j++)
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

    ପାଇଁ (i = 0; i < 2; i++) {                   \
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

    ପାଇଁ (i = 0; i < 2; i++) {
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

ଶୂନ୍ୟ tests(ଶୂନ୍ୟ)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
#ifdef __aarch64__
    tests();
#ଅନ୍ୟଥା
    printf("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#endif
    ଫେରନ୍ତୁ 0;
}
