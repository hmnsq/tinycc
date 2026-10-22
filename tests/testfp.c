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

#شامل <stdint.h>
#شامل <stdio.h>
#شامل <stdlib.h>
#شامل <string.h>

#تعریف_کرو check(x) ((x) ? (خالی)0 : check_fail(#x, __FILE__, __LINE__))

خالی check_fail(ثابت حرف *assertion, ثابت حرف *file, غیرعلامتی صحیح سطر)
{
    لکھو("%s:%d: Check (%s) failed.", file, سطر, assertion);
    باہر_نکلو(1);
}

قسمتعریف ساخت {
    غیرعلامتی طویل طویل x0, x1;
} u128_t;

اعشاری copy_fi(uint32_t x)
{
    اعشاری f;
    حافظہ_نقل(&f, &x, 4);
    واپس f;
}

دوہرا copy_di(uint64_t x)
{
    دوہرا f;
    حافظہ_نقل(&f, &x, 8);
    واپس f;
}

طویل دوہرا copy_ldi(u128_t x)
{
    طویل دوہرا f;
    حافظہ_نقل(&f, &x, 16);
    واپس f;
}

uint32_t copy_if(اعشاری f)
{
    uint32_t x;
    حافظہ_نقل(&x, &f, 4);
    واپس x;
}

uint64_t copy_id(دوہرا f)
{
    uint64_t x;
    حافظہ_نقل(&x, &f, 8);
    واپس x;
}

u128_t copy_ild(طویل دوہرا f)
{
    u128_t x;
    حافظہ_نقل(&x, &f, 16);
    واپس x;
}

طویل دوہرا make(صحیح sgn, صحیح قوت_نما, uint64_t بلند, uint64_t کم)
{
    u128_t x = { کم,
                 (0x0000ffffffffffff & بلند) |
                 (0x7fff000000000000 & (uint64_t)قوت_نما << 48) |
                 (0x8000000000000000 & (uint64_t)sgn << 63) };
    واپس copy_ldi(x);
}

خالی cmp(طویل دوہرا a, طویل دوہرا b)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    صحیح eq = (a == b);
    صحیح ne = (a != b);
    صحیح lt = (a < b);
    صحیح le = (a <= b);
    صحیح gt = (a > b);
    صحیح ge = (a >= b);

    check(eq == 0 || eq == 1);
    check(lt == 0 || lt == 1);
    check(gt == 0 || gt == 1);
    check(ne == !eq && le == (lt | eq) && ge == (gt | eq));
    check(eq + lt + gt < 2);

    لکھو("cmp %016llx%016llx %016llx%016llx %d %d %d\n",
           ax.x1, ax.x0, bx.x1, bx.x0, lt, eq, gt);
}

خالی cmps(خالی)
{
    صحیح i, j;

    برائے (i = 0; i < 2; i++)
        برائے (j = 0; j < 2; j++)
            cmp(make(i, 0, 0, 0), make(j, 0, 0, 0));

    برائے (i = 0; i < 2; i++) {
        برائے (j = 0; j < 64; j++) {
            طویل دوہرا f1 = make(i, 32767, (uint64_t)1 << j, 0);
            طویل دوہرا f2 = make(i, 32767, 0, (uint64_t)1 << j);
            cmp(f1, 0);
            cmp(f2, 0);
            cmp(0, f1);
            cmp(0, f2);
        }
    }

    برائے (i = 0; i < 6; i++)
        برائے (j = 0; j < 6; j++)
            cmp(make(i & 1, i >> 1, 0, 0),
                make(j & 1, j >> 1, 0, 0));

    برائے (i = 0; i < 2; i++) {
        برائے (j = 0; j < 2; j++) {
            صحیح a, b;
            برائے (a = 0; a < 2; a++) {
                برائے (b = 0; b < 2; b++) {
                    cmp(make(i, j, a, b), make(i, j, 0, 0));
                    cmp(make(i, j, 0, 0), make(i, j, a, b));
                }
            }
        }
    }
}

خالی xop(ثابت حرف *name, طویل دوہرا a, طویل دوہرا b, طویل دوہرا c)
{
    u128_t ax = copy_ild(a);
    u128_t bx = copy_ild(b);
    u128_t cx = copy_ild(c);
    لکھو("%s %016llx%016llx %016llx%016llx %016llx%016llx\n",
           name, ax.x1, ax.x0, bx.x1, bx.x0, cx.x1, cx.x0);
}

خالی fadd(طویل دوہرا a, طویل دوہرا b)
{
    xop("add", a, b, a + b);
}

خالی fsub(طویل دوہرا a, طویل دوہرا b)
{
    xop("sub", a, b, a - b);
}

خالی fmul(طویل دوہرا a, طویل دوہرا b)
{
    xop("mul", a, b, a * b);
}

خالی fdiv(طویل دوہرا a, طویل دوہرا b)
{
    xop("div", a, b, a / b);
}

خالی nanz(خالی)
{
    // Check NaNs:
    {
        طویل دوہرا x[7];
        صحیح i, j, n = 0;
        x[n++] = make(0, 32000, 0x95132b76effc, 0xd79035214b4f8d53);
        x[n++] = make(1, 32001, 0xbe71d7a51587, 0x30601c6815d6c3ac);
        x[n++] = make(0, 32767, 0, 1);
        x[n++] = make(0, 32767, (uint64_t)1 << 46, 0);
        x[n++] = make(1, 32767, (uint64_t)1 << 47, 0);
        x[n++] = make(1, 32767, 0x7596c7099ad5, 0xe25fed2c58f73fc9);
        x[n++] = make(0, 32767, 0x835d143360f9, 0x5e315efb35630666);
        check(n == حجم(x) / حجم(*x));
        برائے (i = 0; i < n; i++) {
            برائے (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }

    // Check infinities and zeroes:
    {
        طویل دوہرا x[6];
        صحیح i, j, n = 0;
        x[n++] = make(1, 32000, 0x62acda85f700, 0x47b6c9f35edc4044);
        x[n++] = make(0, 32001, 0x94b7abf55af7, 0x9f425fe354428e19);
        x[n++] = make(0, 32767, 0, 0);
        x[n++] = make(1, 32767, 0, 0);
        x[n++] = make(0, 0, 0, 0);
        x[n++] = make(1, 0, 0, 0);
        check(n == حجم(x) / حجم(*x));
        برائے (i = 0; i < n; i++) {
            برائے (j = 0; j < n; j++) {
                fadd(x[i], x[j]);
                fsub(x[i], x[j]);
                fmul(x[i], x[j]);
                fdiv(x[i], x[j]);
            }
        }
    }
}

خالی adds(خالی)
{
    // Check shifting and add/sub:
    {
        صحیح i;
        برائے (i = -130; i <= 130; i++) {
            صحیح s1 = (uint32_t)i % 3 < 1;
            صحیح s2 = (uint32_t)i % 5 < 2;
            fadd(make(s1, 16384    , 0x502c065e4f71a65d, 0xd2f9bdb031f4f031),
                 make(s2, 16384 + i, 0xae267395a9bc1033, 0xb56b5800da1ba448));
        }
    }

    // Check normalisation:
    {
        uint64_t a0 = 0xc6bab0a6afbef5ed;
        uint64_t a1 = 0x4f84136c4a2e9b52;
        صحیح ee[] = { 0, 1, 10000 };
        صحیح e, i;
        برائے (e = 0; e < حجم(ee) / حجم(*ee); e++) {
            صحیح قوت_نما = ee[e];
            fsub(make(0, قوت_نما, a1, a0), make(0, 0, 0, 0));
            برائے (i = 63; i >= 0; i--)
                fsub(make(0, قوت_نما, a1 | (uint64_t)1 << i >> 1, a0),
                     make(0, قوت_نما, a1 >> i << i, 0));
            برائے (i = 63; i >=0; i--)
                fsub(make(0, قوت_نما, a1, a0 | (uint64_t)1 << i >> 1),
                     make(0, قوت_نما, a1, a0 >> i << i));
        }
    }

    // Carry/overflow from rounding:
    {
        fadd(make(0, 114, -1, -1), make(0, 1, 0, 0));
        fadd(make(0, 32766, -1, -1), make(0, 32653, 0, 0));
        fsub(make(1, 32766, -1, -1), make(0, 32653, 0, 0));
    }
}

خالی muls(خالی)
{
    صحیح i, j;

    {
        طویل دوہرا max = make(0, 32766, -1, -1);
        طویل دوہرا min = make(0, 0, 0, 1);
        fmul(max, max);
        fmul(max, min);
        fmul(min, min);
    }

    برائے (i = 117; i > 0; i--)
        fmul(make(0, 16268, 0x643dcea76edc, 0xe0877a598403627a),
             make(i & 1, i, 0, 0));

    fmul(make(0, 16383, -1, -3), make(0, 16383, 0, 1));
    // Round to next exponent:
    fmul(make(0, 16383, -1, -2), make(0, 16383, 0, 1));
    // Round from subnormal to normal:
    fmul(make(0, 1, -1, -1), make(0, 16382, 0, 0));

    برائے (i = 0; i < 2; i++)
        برائے (j = 0; j < 112; j++)
            fmul(make(0, 16383, (uint64_t)1 << i, 0),
                 make(0, 16383,
                      j < 64 ? 0 : (uint64_t)1 << (j - 64),
                      j < 64 ? (uint64_t)1 << j : 0));
}

خالی divs(خالی)
{
    صحیح i;

    {
        طویل دوہرا max = make(0, 32766, -1, -1);
        طویل دوہرا min = make(0, 0, 0, 1);
        fdiv(max, max);
        fdiv(max, min);
        fdiv(min, max);
        fdiv(min, min);
    }

    برائے (i = 0; i < 64; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -1, -(uint64_t)1 << i));
    برائے (i = 0; i < 48; i++)
        fdiv(make(0, 16383, -1, -1), make(0, 16383, -(uint64_t)1 << i, 0));
}

خالی cvtlsw(int32_t a)
{
    طویل دوہرا f = a;
    u128_t x = copy_ild(f);
    لکھو("cvtlsw %08lx %016llx%016llx\n", (طویل)(uint32_t)a, x.x1, x.x0);
}

خالی cvtlsx(int64_t a)
{
    طویل دوہرا f = a;
    u128_t x = copy_ild(f);
    لکھو("cvtlsx %016llx %016llx%016llx\n",
           (طویل طویل)(uint64_t)a, x.x1, x.x0);
}

خالی cvtluw(uint32_t a)
{
    طویل دوہرا f = a;
    u128_t x = copy_ild(f);
    لکھو("cvtluw %08lx %016llx%016llx\n", (طویل)a, x.x1, x.x0);
}

خالی cvtlux(uint64_t a)
{
    طویل دوہرا f = a;
    u128_t x = copy_ild(f);
    لکھو("cvtlux %016llx %016llx%016llx\n", (طویل طویل)a, x.x1, x.x0);
}

خالی cvtil(طویل دوہرا a)
{
    u128_t x = copy_ild(a);
    int32_t b1 = a;
    int64_t b2 = a;
    uint32_t b3 = a;
    uint64_t b4 = a;
    لکھو("cvtswl %016llx%016llx %08lx\n",
           x.x1, x.x0, (طویل)(uint32_t)b1);
    لکھو("cvtsxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (طویل طویل)(uint64_t)b2);
    لکھو("cvtuwl %016llx%016llx %08lx\n",
           x.x1, x.x0, (طویل)b3);
    لکھو("cvtuxl %016llx%016llx %016llx\n",
           x.x1, x.x0, (طویل طویل)b4);
}

خالی cvtlf(اعشاری a)
{
    uint32_t ax = copy_if(a);
    طویل دوہرا b = a;
    u128_t bx = copy_ild(b);
    لکھو("cvtlf %08lx %016llx%016llx\n", (طویل)ax, bx.x1, bx.x0);
}

خالی cvtld(دوہرا a)
{
    uint64_t ax = copy_id(a);
    طویل دوہرا b = a;
    u128_t bx = copy_ild(b);
    لکھو("cvtld %016llx %016llx%016llx\n", (طویل طویل)ax, bx.x1, bx.x0);
}

خالی cvtfl(طویل دوہرا a)
{
    u128_t ax = copy_ild(a);
    اعشاری b = a;
    uint32_t bx = copy_if(b);
    لکھو("cvtfl %016llx%016llx %08lx\n", ax.x1, ax.x0, (طویل)bx);
}

خالی cvtdl(طویل دوہرا a)
{
    u128_t ax = copy_ild(a);
    دوہرا b = a;
    uint64_t bx = copy_id(b);
    لکھو("cvtdl %016llx%016llx %016llx\n", ax.x1, ax.x0, (طویل طویل)bx);
}

خالی cvts(خالی)
{
    صحیح i, j;

    {
        uint32_t x = 0xad040c5b;
        cvtlsw(0);
        برائے (i = 0; i < 31; i++)
            cvtlsw(x >> (31 - i));
        برائے (i = 0; i < 31; i++)
            cvtlsw(-(x >> (31 - i)));
        cvtlsw(0x80000000);
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlsx(0);
        برائے (i = 0; i < 63; i++)
            cvtlsx(x >> (63 - i));
        برائے (i = 0; i < 63; i++)
            cvtlsx(-(x >> (63 - i)));
        cvtlsx(0x8000000000000000);
    }
    {
        uint32_t x = 0xad040c5b;
        cvtluw(0);
        برائے (i = 0; i < 32; i++)
            cvtluw(x >> (31 - i));
    }
    {
        uint64_t x = 0xb630a248cad9afd2;
        cvtlux(0);
        برائے (i = 0; i < 64; i++)
            cvtlux(x >> (63 - i));
    }

    برائے (i = 0; i < 2; i++) {
        cvtil(make(i, 32767, 0, 1));
        cvtil(make(i, 32767, (uint64_t)1 << 47, 0));
        cvtil(make(i, 32767, 123, 456));
        cvtil(make(i, 32767, 0, 0));
        cvtil(make(i, 16382, -1, -1));
        cvtil(make(i, 16383, -1, -1));
        cvtil(make(i, 16384, 0x7fffffffffff, -1));
        cvtil(make(i, 16384, 0x800000000000, 0));
        برائے (j = 0; j < 68; j++)
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

    برائے (i = 0; i < 2; i++) {                   \
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

    برائے (i = 0; i < 2; i++) {
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

خالی tests(خالی)
{
    cmps();
    nanz();
    adds();
    muls();
    divs();
    cvts();
}

صحیح مین()
{
#اگر_تعریف_شدہ __aarch64__
    tests();
#ورنہ
    لکھو("This test program is intended for a little-endian architecture\n"
           "with an IEEE-standard 128-bit long double.\n");
#اگر_ختم
    واپس 0;
}
