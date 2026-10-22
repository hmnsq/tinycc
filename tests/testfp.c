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

#ضمن <stdint.h>
#ضمن <stdio.h>
#ضمن <stdlib.h>
#ضمن <string.h>

#تعریف_کن check(x) ((x) ? (فراغ)0 : check_fail(#x, __FILE__, __LINE__))

فراغ check_fail(ثابت حرف *assertion, ثابت حرف *file, بیعلامت صحيح سطر)
{
    چاپ_کن("%s:%d: Check (%s) failed.", file, سطر, assertion);
    خروج(1);
}

تعريفنوع بنية {
    بیعلامت دراز دراز x0, x1;
} u128_t;

عائم copy_fi(uint32_t x)
{
    عائم f;
    کپی_حافظه(&f, &x, 4);
    أرجع f;
}

مزدوج copy_di(uint64_t x)
{
    مزدوج f;
    کپی_حافظه(&f, &x, 8);
    أرجع f;
}

دراز مزدوج copy_ldi(u128_t x)
{
    دراز مزدوج f;
    کپی_حافظه(&f, &x, 16);
    أرجع f;
}

uint32_t copy_if(عائم f)
{
    uint32_t x;
    کپی_حافظه(&x, &f, 4);
    أرجع x;
}

uint64_t copy_id(مزدوج f)
{
    uint64_t x;
    کپی_حافظه(&x, &f, 8);
    أرجع x;
}

u128_t copy_ild(دراز مزدوج f)
{
    u128_t x;
    کپی_حافظه(&x, &f, 16);
    أرجع x;
}

دراز مزدوج make(صحيح sgn, صحيح نمایی_تابع, uint64_t بالا, uint64_t کم)
{
    u128_t x = { کم,
                 (0x0000ffffffffffff & بالا) |
                 (0x7fff000000000000 & (uint64_t)نمایی_تابع << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    أرجع copy_ldi(x);
}

فراغ cmp(دراز مزدوج a, دراز مزدوج b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    صحيح eq = (a == b);
    صحيح ne = (a != b);
    صحيح lt = (a < b);
    صحيح le = (a <= b);
    صحيح gt = (a > b);
    صحيح ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    چاپ_کن("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

فراغ cmps(فراغ)
{
    صحيح i, j;

    لكل (i = 0; i < 2; i++)
        لكل (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    لكل (i = 0; i < 2; i++) {
        لكل (j = 0; j < 64; j++) {
            دراز مزدوج f1 = make(i, 32767, (uint64_t)1 << j, 0);
            دراز مزدوج f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    لكل (i = 0; i < 6; i++)
        لكل (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    لكل (i = 0; i < 2; i++) {
        لكل (j = 0; j < 2; j++) {
            صحيح a, b;
            لكل (a = 0; a < 2; a++) {
                لكل (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

فراغ xop(ثابت حرف *name, دراز مزدوج a, دراز مزدوج b, دراز مزدوج c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    چاپ_کن("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

فراغ fadd(دراز مزدوج a, دراز مزدوج b)
{
    xop("add", a, b, a + b);
}

فراغ fsub(دراز مزدوج a, دراز مزدوج b)
{
    xop("sub", a, b, a - b);
}

فراغ fmul(دراز مزدوج a, دراز مزدوج b)
{
    xop("mul", a, b, a * b);
}

فراغ fdiv(دراز مزدوج a, دراز مزدوج b)
{
    xop("div", a, b, a / b);
}

فراغ nanz(فراغ)
{
    // Check NaNs:
    {
        دراز مزدوج x[7];
        صحيح i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == حجم(x) / حجم(*x));
        لكل (i = 0; i < n; i++) {
            لكل (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        دراز مزدوج x[6];
        صحيح i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == حجم(x) / حجم(*x));
        لكل (i = 0; i < n; i++) {
            لكل (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

فراغ adds(فراغ)
{
    // Check shifting and add/sub:
    {
        صحيح i;
        لكل (i = -130; i <= 130; i++) {
            صحيح s1 = (uint32_t)i % 3 < 1;
            صحيح s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        صحيح ee[] = { 0, 1, 10000 };
        صحيح e, i;
        لكل (e = 0; e < حجم(ee) / حجم(*ee); e++) {
            صحيح نمایی_تابع = ee[e];
            fsub(make(0, نمایی_تابع, a1, a0), make(0, 0, 0, 0));
            لكل (i = 63; i >= 0; i--)
                fsub(make(0, نمایی_تابع, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, نمایی_تابع, a1 >> i << i, 0));
            لكل (i = 63; i >=0; i--)
                fsub(make(0, نمایی_تابع, a1, a0 | (uint64_t)1 << i >> 1),
                     make(0, نمایی_تابع, a1, a0 >> i << i));
        }
    }

    // Carry/overflow from rounding:
    {
        fadd(make(0, 114, -1, -1), make(0, 1, 0, 0));
        fadd(make(0, 32766, -1, -1), make(0, 32653, 0, 0));
        fsub(make(1, 32766, -1, -1), make(0, 32653, 0, 0));
    }
}

فراغ muls(فراغ)
{
    صحيح i, j;

    {
        دراز مزدوج max = make(0, 32766, -1, -1);
        دراز مزدوج min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    لكل (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    لكل (i = 0; i < 2; i++)
        لكل (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

فراغ divs(فراغ)
{
    صحيح i;

    {
        دراز مزدوج max = make(0, 32766, -1, -1);
        دراز مزدوج min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    لكل (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    لكل (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

فراغ cvtlsw(int32_t a)
{
    دراز مزدوج f = a;
    u128_t x = copy_ild(f);
    چاپ_کن("cvtlsw %08lx %016llx%016llx\n", (دراز)(uint32_t)a, x.x1, x.x0);
}

فراغ cvtlsx(int64_t a)
{
    دراز مزدوج f = a;
    u128_t x = copy_ild(f);
    چاپ_کن("cvtlsx %016llx %016llx%016llx\n",
           (دراز دراز)(uint64_t)a, x.x1, x.x0);
}

فراغ cvtluw(uint32_t a)
{
    دراز مزدوج f = a;
    u128_t x = copy_ild(f);
    چاپ_کن("cvtluw %08lx %016llx%016llx\n", (دراز)a, x.x1, x.x0);
}

فراغ cvtlux(uint64_t a)
{
    دراز مزدوج f = a;
    u128_t x = copy_ild(f);
    چاپ_کن("cvtlux %016llx %016llx%016llx\n", (دراز دراز)a, x.x1, x.x0);
}

فراغ cvtil(دراز مزدوج a)
{
    u128_t x = copy_ild(a);
    int32_t b1 = a;
    int64_t b2 = a;
    uint32_t b3 = a;
    uint64_t b4 = a;
    چاپ_کن("cvtswl %016llx%016llx %08lx\n",
           x.x1, x.x0, (دراز)(uint32_t)b1);
    چاپ_کن("cvtsxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (دراز دراز)(uint64_t)b2);
    چاپ_کن("cvtuwl %016llx%016llx %08lx\n",
           x.x1, x.x0, (دراز)b3);
    چاپ_کن("cvtuxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (دراز دراز)b4);
}

فراغ cvtlf(عائم a)
{
    uint32_t ax = copy_if(a);
    دراز مزدوج b = a;
    u128_t bx = copy_ild(b);
    چاپ_کن("cvtlf %08lx %016llx%016llx\n", (دراز)ax, bx.x1, bx.x0);
}

فراغ cvtld(مزدوج a)
{
    uint64_t ax = copy_id(a);
    دراز مزدوج b = a;
    u128_t bx = copy_ild(b);
    چاپ_کن("cvtld %016llx %016llx%016llx\n", (دراز دراز)ax, bx.x1, bx.x0);
}

فراغ cvtfl(دراز مزدوج a)
{
    u128_t ax = copy_ild(a);
    عائم b = a;
    uint32_t bx = copy_if(b);
    چاپ_کن("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (دراز)bx);
}

فراغ cvtdl(دراز مزدوج a)
{
    u128_t ax = copy_ild(a);
    مزدوج b = a;
    uint64_t bx = copy_id(b);
    چاپ_کن("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (دراز دراز)bx);
}

فراغ cvts(فراغ)
{
    صحيح i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        لكل (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        لكل (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        لكل (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        لكل (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        لكل (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        لكل (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    لكل (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        لكل (j = 0; j < 68; j++)
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

    لكل (i = 0; i < 2; i++) {                   \
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

    لكل (i = 0; i < 2; i++) {
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

فراغ tests(فراغ)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

صحيح اصلی()
{
#اگر_تعریف_شده __aarch64__
    tests();
#وإلا
    چاپ_کن("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#پایان_اگر
    أرجع 0;
}
