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

#అన్తర్భావ <stdint.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <string.h>

#నిర్వచించు check(x) ((x) ? (శూన్య)0 : check_fail(#x, __FILE__, __LINE__))

శూన్య check_fail(స్థిరరాశి అక్షరం *assertion, స్థిరరాశి అక్షరం *file, గుర్తులేని పూర్ణాంకం పంక్తి)
{
    రాయి("%s:%d: Check (%s) failed.", file, పంక్తి, assertion);
    నిష్క్రమించు(1);
}

రకనిర్వచనం నిర్మాణం {
    గుర్తులేని దీర్ఘ దీర్ఘ x0, x1;
} u128_t;

దశాంశం copy_fi(uint32_t x)
{
    దశాంశం f;
    జ్ఞాపకం_నకలు(&f, &x, 4);
    తిరిగి f;
}

ద్విగుణ copy_di(uint64_t x)
{
    ద్విగుణ f;
    జ్ఞాపకం_నకలు(&f, &x, 8);
    తిరిగి f;
}

దీర్ఘ ద్విగుణ copy_ldi(u128_t x)
{
    దీర్ఘ ద్విగుణ f;
    జ్ఞాపకం_నకలు(&f, &x, 16);
    తిరిగి f;
}

uint32_t copy_if(దశాంశం f)
{
    uint32_t x;
    జ్ఞాపకం_నకలు(&x, &f, 4);
    తిరిగి x;
}

uint64_t copy_id(ద్విగుణ f)
{
    uint64_t x;
    జ్ఞాపకం_నకలు(&x, &f, 8);
    తిరిగి x;
}

u128_t copy_ild(దీర్ఘ ద్విగుణ f)
{
    u128_t x;
    జ్ఞాపకం_నకలు(&x, &f, 16);
    తిరిగి x;
}

దీర్ఘ ద్విగుణ make(పూర్ణాంకం sgn, పూర్ణాంకం ఘాతాంకం, uint64_t ఎగువ, uint64_t దిగువ)
{
    u128_t x = { దిగువ,
                 (0x0000ffffffffffff & ఎగువ) |
                 (0x7fff000000000000 & (uint64_t)ఘాతాంకం << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    తిరిగి copy_ldi(x);
}

శూన్య cmp(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    పూర్ణాంకం eq = (a == b);
    పూర్ణాంకం ne = (a != b);
    పూర్ణాంకం lt = (a < b);
    పూర్ణాంకం le = (a <= b);
    పూర్ణాంకం gt = (a > b);
    పూర్ణాంకం ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    రాయి("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

శూన్య cmps(శూన్య)
{
    పూర్ణాంకం i, j;

    కొరకు (i = 0; i < 2; i++)
        కొరకు (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    కొరకు (i = 0; i < 2; i++) {
        కొరకు (j = 0; j < 64; j++) {
            దీర్ఘ ద్విగుణ f1 = make(i, 32767, (uint64_t)1 << j, 0);
            దీర్ఘ ద్విగుణ f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    కొరకు (i = 0; i < 6; i++)
        కొరకు (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    కొరకు (i = 0; i < 2; i++) {
        కొరకు (j = 0; j < 2; j++) {
            పూర్ణాంకం a, b;
            కొరకు (a = 0; a < 2; a++) {
                కొరకు (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

శూన్య xop(స్థిరరాశి అక్షరం *name, దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b, దీర్ఘ ద్విగుణ c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    రాయి("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

శూన్య fadd(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    xop("add", a, b, a + b);
}

శూన్య fsub(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    xop("sub", a, b, a - b);
}

శూన్య fmul(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    xop("mul", a, b, a * b);
}

శూన్య fdiv(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    xop("div", a, b, a / b);
}

శూన్య nanz(శూన్య)
{
    // Check NaNs:
    {
        దీర్ఘ ద్విగుణ x[7];
        పూర్ణాంకం i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == పరిమాణం(x) / పరిమాణం(*x));
        కొరకు (i = 0; i < n; i++) {
            కొరకు (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        దీర్ఘ ద్విగుణ x[6];
        పూర్ణాంకం i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == పరిమాణం(x) / పరిమాణం(*x));
        కొరకు (i = 0; i < n; i++) {
            కొరకు (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

శూన్య adds(శూన్య)
{
    // Check shifting and add/sub:
    {
        పూర్ణాంకం i;
        కొరకు (i = -130; i <= 130; i++) {
            పూర్ణాంకం s1 = (uint32_t)i % 3 < 1;
            పూర్ణాంకం s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        పూర్ణాంకం ee[] = { 0, 1, 10000 };
        పూర్ణాంకం e, i;
        కొరకు (e = 0; e < పరిమాణం(ee) / పరిమాణం(*ee); e++) {
            పూర్ణాంకం ఘాతాంకం = ee[e];
            fsub(make(0, ఘాతాంకం, a1, a0), make(0, 0, 0, 0));
            కొరకు (i = 63; i >= 0; i--)
                fsub(make(0, ఘాతాంకం, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, ఘాతాంకం, a1 >> i << i, 0));
            కొరకు (i = 63; i >=0; i--)
                fsub(make(0, ఘాతాంకం, a1, a0 | (uint64_t)1 << i >> 1),
                     make(0, ఘాతాంకం, a1, a0 >> i << i));
        }
    }

    // Carry/overflow from rounding:
    {
        fadd(make(0, 114, -1, -1), make(0, 1, 0, 0));
        fadd(make(0, 32766, -1, -1), make(0, 32653, 0, 0));
        fsub(make(1, 32766, -1, -1), make(0, 32653, 0, 0));
    }
}

శూన్య muls(శూన్య)
{
    పూర్ణాంకం i, j;

    {
        దీర్ఘ ద్విగుణ max = make(0, 32766, -1, -1);
        దీర్ఘ ద్విగుణ min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    కొరకు (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    కొరకు (i = 0; i < 2; i++)
        కొరకు (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

శూన్య divs(శూన్య)
{
    పూర్ణాంకం i;

    {
        దీర్ఘ ద్విగుణ max = make(0, 32766, -1, -1);
        దీర్ఘ ద్విగుణ min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    కొరకు (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    కొరకు (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

శూన్య cvtlsw(int32_t a)
{
    దీర్ఘ ద్విగుణ f = a;
    u128_t x = copy_ild(f);
    రాయి("cvtlsw %08lx %016llx%016llx\n", (దీర్ఘ)(uint32_t)a, x.x1, x.x0);
}

శూన్య cvtlsx(int64_t a)
{
    దీర్ఘ ద్విగుణ f = a;
    u128_t x = copy_ild(f);
    రాయి("cvtlsx %016llx %016llx%016llx\n",
           (దీర్ఘ దీర్ఘ)(uint64_t)a, x.x1, x.x0);
}

శూన్య cvtluw(uint32_t a)
{
    దీర్ఘ ద్విగుణ f = a;
    u128_t x = copy_ild(f);
    రాయి("cvtluw %08lx %016llx%016llx\n", (దీర్ఘ)a, x.x1, x.x0);
}

శూన్య cvtlux(uint64_t a)
{
    దీర్ఘ ద్విగుణ f = a;
    u128_t x = copy_ild(f);
    రాయి("cvtlux %016llx %016llx%016llx\n", (దీర్ఘ దీర్ఘ)a, x.x1, x.x0);
}

శూన్య cvtil(దీర్ఘ ద్విగుణ a)
{
    u128_t x = copy_ild(a);
    int32_t b1 = a;
    int64_t b2 = a;
    uint32_t b3 = a;
    uint64_t b4 = a;
    రాయి("cvtswl %016llx%016llx %08lx\n",
           x.x1, x.x0, (దీర్ఘ)(uint32_t)b1);
    రాయి("cvtsxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (దీర్ఘ దీర్ఘ)(uint64_t)b2);
    రాయి("cvtuwl %016llx%016llx %08lx\n",
           x.x1, x.x0, (దీర్ఘ)b3);
    రాయి("cvtuxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (దీర్ఘ దీర్ఘ)b4);
}

శూన్య cvtlf(దశాంశం a)
{
    uint32_t ax = copy_if(a);
    దీర్ఘ ద్విగుణ b = a;
    u128_t bx = copy_ild(b);
    రాయి("cvtlf %08lx %016llx%016llx\n", (దీర్ఘ)ax, bx.x1, bx.x0);
}

శూన్య cvtld(ద్విగుణ a)
{
    uint64_t ax = copy_id(a);
    దీర్ఘ ద్విగుణ b = a;
    u128_t bx = copy_ild(b);
    రాయి("cvtld %016llx %016llx%016llx\n", (దీర్ఘ దీర్ఘ)ax, bx.x1, bx.x0);
}

శూన్య cvtfl(దీర్ఘ ద్విగుణ a)
{
    u128_t ax = copy_ild(a);
    దశాంశం b = a;
    uint32_t bx = copy_if(b);
    రాయి("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (దీర్ఘ)bx);
}

శూన్య cvtdl(దీర్ఘ ద్విగుణ a)
{
    u128_t ax = copy_ild(a);
    ద్విగుణ b = a;
    uint64_t bx = copy_id(b);
    రాయి("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (దీర్ఘ దీర్ఘ)bx);
}

శూన్య cvts(శూన్య)
{
    పూర్ణాంకం i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        కొరకు (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        కొరకు (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        కొరకు (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        కొరకు (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        కొరకు (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        కొరకు (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    కొరకు (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        కొరకు (j = 0; j < 68; j++)
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

    కొరకు (i = 0; i < 2; i++) {                   \
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

    కొరకు (i = 0; i < 2; i++) {
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

శూన్య tests(శూన్య)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

పూర్ణాంకం ప్రధాన()
{
#నిర్వచితమైతే __aarch64__
    tests();
#లేకపోతే
    రాయి("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#అయితే_ముగింపు
    తిరిగి 0;
}
