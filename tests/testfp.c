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

#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ check(x) ((x) ? (ਖਾਲੀ)0 : check_fail(#x, __FILE__, __LINE__))

ਖਾਲੀ check_fail(ਅਚਲ ਅੱਖਰ *assertion, ਅਚਲ ਅੱਖਰ *file, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਸਤਰ)
{
    ਲਿਖੋ("%s:%d: Check (%s) failed.", file, ਸਤਰ, assertion);
    ਬਾਹਰ_ਨਿਕਲੋ(1);
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x0, x1;
} u128_t;

ਦਸ਼ਮਲਵ copy_fi(uint32_t x)
{
    ਦਸ਼ਮਲਵ f;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&f, &x, 4);
    ਵਾਪਸ f;
}

ਦੁੱਗਣਾ copy_di(uint64_t x)
{
    ਦੁੱਗਣਾ f;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&f, &x, 8);
    ਵਾਪਸ f;
}

ਲੰਮਾ ਦੁੱਗਣਾ copy_ldi(u128_t x)
{
    ਲੰਮਾ ਦੁੱਗਣਾ f;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&f, &x, 16);
    ਵਾਪਸ f;
}

uint32_t copy_if(ਦਸ਼ਮਲਵ f)
{
    uint32_t x;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&x, &f, 4);
    ਵਾਪਸ x;
}

uint64_t copy_id(ਦੁੱਗਣਾ f)
{
    uint64_t x;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&x, &f, 8);
    ਵਾਪਸ x;
}

u128_t copy_ild(ਲੰਮਾ ਦੁੱਗਣਾ f)
{
    u128_t x;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&x, &f, 16);
    ਵਾਪਸ x;
}

ਲੰਮਾ ਦੁੱਗਣਾ make(ਪੂਰਨ sgn, ਪੂਰਨ ਘਾਤਾਂਕ, uint64_t ਉੱਚਾ, uint64_t ਨੀਵਾਂ)
{
    u128_t x = { ਨੀਵਾਂ,
                 (0x0000ffffffffffff & ਉੱਚਾ) |
                 (0x7fff000000000000 & (uint64_t)ਘਾਤਾਂਕ << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    ਵਾਪਸ copy_ldi(x);
}

ਖਾਲੀ cmp(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    ਪੂਰਨ eq = (a == b);
    ਪੂਰਨ ne = (a != b);
    ਪੂਰਨ lt = (a < b);
    ਪੂਰਨ le = (a <= b);
    ਪੂਰਨ gt = (a > b);
    ਪੂਰਨ ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    ਲਿਖੋ("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

ਖਾਲੀ cmps(ਖਾਲੀ)
{
    ਪੂਰਨ i, j;

    ਲਈ (i = 0; i < 2; i++)
        ਲਈ (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    ਲਈ (i = 0; i < 2; i++) {
        ਲਈ (j = 0; j < 64; j++) {
            ਲੰਮਾ ਦੁੱਗਣਾ f1 = make(i, 32767, (uint64_t)1 << j, 0);
            ਲੰਮਾ ਦੁੱਗਣਾ f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    ਲਈ (i = 0; i < 6; i++)
        ਲਈ (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    ਲਈ (i = 0; i < 2; i++) {
        ਲਈ (j = 0; j < 2; j++) {
            ਪੂਰਨ a, b;
            ਲਈ (a = 0; a < 2; a++) {
                ਲਈ (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

ਖਾਲੀ xop(ਅਚਲ ਅੱਖਰ *name, ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b, ਲੰਮਾ ਦੁੱਗਣਾ c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    ਲਿਖੋ("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

ਖਾਲੀ fadd(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    xop("add", a, b, a + b);
}

ਖਾਲੀ fsub(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    xop("sub", a, b, a - b);
}

ਖਾਲੀ fmul(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    xop("mul", a, b, a * b);
}

ਖਾਲੀ fdiv(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    xop("div", a, b, a / b);
}

ਖਾਲੀ nanz(ਖਾਲੀ)
{
    // Check NaNs:
    {
        ਲੰਮਾ ਦੁੱਗਣਾ x[7];
        ਪੂਰਨ i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == ਆਕਾਰ(x) / ਆਕਾਰ(*x));
        ਲਈ (i = 0; i < n; i++) {
            ਲਈ (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        ਲੰਮਾ ਦੁੱਗਣਾ x[6];
        ਪੂਰਨ i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == ਆਕਾਰ(x) / ਆਕਾਰ(*x));
        ਲਈ (i = 0; i < n; i++) {
            ਲਈ (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

ਖਾਲੀ adds(ਖਾਲੀ)
{
    // Check shifting and add/sub:
    {
        ਪੂਰਨ i;
        ਲਈ (i = -130; i <= 130; i++) {
            ਪੂਰਨ s1 = (uint32_t)i % 3 < 1;
            ਪੂਰਨ s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        ਪੂਰਨ ee[] = { 0, 1, 10000 };
        ਪੂਰਨ e, i;
        ਲਈ (e = 0; e < ਆਕਾਰ(ee) / ਆਕਾਰ(*ee); e++) {
            ਪੂਰਨ ਘਾਤਾਂਕ = ee[e];
            fsub(make(0, ਘਾਤਾਂਕ, a1, a0), make(0, 0, 0, 0));
            ਲਈ (i = 63; i >= 0; i--)
                fsub(make(0, ਘਾਤਾਂਕ, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, ਘਾਤਾਂਕ, a1 >> i << i, 0));
            ਲਈ (i = 63; i >=0; i--)
                fsub(make(0, ਘਾਤਾਂਕ, a1, a0 | (uint64_t)1 << i >> 1),
                     make(0, ਘਾਤਾਂਕ, a1, a0 >> i << i));
        }
    }

    // Carry/overflow from rounding:
    {
        fadd(make(0, 114, -1, -1), make(0, 1, 0, 0));
        fadd(make(0, 32766, -1, -1), make(0, 32653, 0, 0));
        fsub(make(1, 32766, -1, -1), make(0, 32653, 0, 0));
    }
}

ਖਾਲੀ muls(ਖਾਲੀ)
{
    ਪੂਰਨ i, j;

    {
        ਲੰਮਾ ਦੁੱਗਣਾ max = make(0, 32766, -1, -1);
        ਲੰਮਾ ਦੁੱਗਣਾ min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    ਲਈ (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    ਲਈ (i = 0; i < 2; i++)
        ਲਈ (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

ਖਾਲੀ divs(ਖਾਲੀ)
{
    ਪੂਰਨ i;

    {
        ਲੰਮਾ ਦੁੱਗਣਾ max = make(0, 32766, -1, -1);
        ਲੰਮਾ ਦੁੱਗਣਾ min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    ਲਈ (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    ਲਈ (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

ਖਾਲੀ cvtlsw(int32_t a)
{
    ਲੰਮਾ ਦੁੱਗਣਾ f = a;
    u128_t x = copy_ild(f);
    ਲਿਖੋ("cvtlsw %08lx %016llx%016llx\n", (ਲੰਮਾ)(uint32_t)a, x.x1, x.x0);
}

ਖਾਲੀ cvtlsx(int64_t a)
{
    ਲੰਮਾ ਦੁੱਗਣਾ f = a;
    u128_t x = copy_ild(f);
    ਲਿਖੋ("cvtlsx %016llx %016llx%016llx\n",
           (ਲੰਮਾ ਲੰਮਾ)(uint64_t)a, x.x1, x.x0);
}

ਖਾਲੀ cvtluw(uint32_t a)
{
    ਲੰਮਾ ਦੁੱਗਣਾ f = a;
    u128_t x = copy_ild(f);
    ਲਿਖੋ("cvtluw %08lx %016llx%016llx\n", (ਲੰਮਾ)a, x.x1, x.x0);
}

ਖਾਲੀ cvtlux(uint64_t a)
{
    ਲੰਮਾ ਦੁੱਗਣਾ f = a;
    u128_t x = copy_ild(f);
    ਲਿਖੋ("cvtlux %016llx %016llx%016llx\n", (ਲੰਮਾ ਲੰਮਾ)a, x.x1, x.x0);
}

ਖਾਲੀ cvtil(ਲੰਮਾ ਦੁੱਗਣਾ a)
{
    u128_t x = copy_ild(a);
    int32_t b1 = a;
    int64_t b2 = a;
    uint32_t b3 = a;
    uint64_t b4 = a;
    ਲਿਖੋ("cvtswl %016llx%016llx %08lx\n",
           x.x1, x.x0, (ਲੰਮਾ)(uint32_t)b1);
    ਲਿਖੋ("cvtsxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (ਲੰਮਾ ਲੰਮਾ)(uint64_t)b2);
    ਲਿਖੋ("cvtuwl %016llx%016llx %08lx\n",
           x.x1, x.x0, (ਲੰਮਾ)b3);
    ਲਿਖੋ("cvtuxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (ਲੰਮਾ ਲੰਮਾ)b4);
}

ਖਾਲੀ cvtlf(ਦਸ਼ਮਲਵ a)
{
    uint32_t ax = copy_if(a);
    ਲੰਮਾ ਦੁੱਗਣਾ b = a;
    u128_t bx = copy_ild(b);
    ਲਿਖੋ("cvtlf %08lx %016llx%016llx\n", (ਲੰਮਾ)ax, bx.x1, bx.x0);
}

ਖਾਲੀ cvtld(ਦੁੱਗਣਾ a)
{
    uint64_t ax = copy_id(a);
    ਲੰਮਾ ਦੁੱਗਣਾ b = a;
    u128_t bx = copy_ild(b);
    ਲਿਖੋ("cvtld %016llx %016llx%016llx\n", (ਲੰਮਾ ਲੰਮਾ)ax, bx.x1, bx.x0);
}

ਖਾਲੀ cvtfl(ਲੰਮਾ ਦੁੱਗਣਾ a)
{
    u128_t ax = copy_ild(a);
    ਦਸ਼ਮਲਵ b = a;
    uint32_t bx = copy_if(b);
    ਲਿਖੋ("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (ਲੰਮਾ)bx);
}

ਖਾਲੀ cvtdl(ਲੰਮਾ ਦੁੱਗਣਾ a)
{
    u128_t ax = copy_ild(a);
    ਦੁੱਗਣਾ b = a;
    uint64_t bx = copy_id(b);
    ਲਿਖੋ("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (ਲੰਮਾ ਲੰਮਾ)bx);
}

ਖਾਲੀ cvts(ਖਾਲੀ)
{
    ਪੂਰਨ i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        ਲਈ (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        ਲਈ (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        ਲਈ (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        ਲਈ (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        ਲਈ (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        ਲਈ (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    ਲਈ (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        ਲਈ (j = 0; j < 68; j++)
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

    ਲਈ (i = 0; i < 2; i++) {                   \
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

    ਲਈ (i = 0; i < 2; i++) {
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

ਖਾਲੀ tests(ਖਾਲੀ)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

ਪੂਰਨ ਮੁੱਖ()
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __aarch64__
    tests();
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#ਜੇ_ਅੰਤ
    ਵਾਪਸ 0;
}
