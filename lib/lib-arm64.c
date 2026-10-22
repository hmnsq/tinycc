/*
 *  TCC runtime library for arm64.
 *
 *  Copyright (c) 2015 Edmund Grimley Evans
 *
 * Copying and distribution of this file, with or without modification,
 * are permitted in any medium without royalty provided the copyright
 * notice and this notice are preserved.  This file is offered as-is,
 * without any warranty.
 */

#اگر_تعریف_شدہ __TINYC__
قسمتعریف علامتی حرف int8_t;
قسمتعریف غیرعلامتی حرف uint8_t;
قسمتعریف مختصر int16_t;
قسمتعریف غیرعلامتی مختصر uint16_t;
قسمتعریف صحیح int32_t;
قسمتعریف غیرعلامتی uint32_t;
قسمتعریف طویل طویل int64_t;
قسمتعریف غیرعلامتی طویل طویل uint64_t;
#ورنہ
#شامل <stdint.h>
#شامل <string.h>
#اگر_ختم

قسمتعریف اتحاد {
    ساخت { uint64_t x0, x1; };
    طویل دوہرا f;
} u128_t;

قسمتعریف اتحاد {
    uint64_t x;
    دوہرا f;
} u64_t;

قسمتعریف اتحاد {
    uint32_t x;
    اعشاری f;
} u32_t;

ساکن طویل دوہرا f3_zero(صحیح sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    واپس x.f;
}

ساکن طویل دوہرا f3_infinity(صحیح sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    واپس x.f;
}

ساکن طویل دوہرا f3_NaN(خالی)
{
#اگر 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#ورنہ
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#اگر_ختم
    واپس x.f;
}

ساکن صحیح fp3_convert_NaN(طویل دوہرا *f, صحیح sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    واپس 1;
#تعریف_کرو fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

ساکن صحیح fp3_detect_NaNs(طویل دوہرا *f,
                           صحیح a_sgn, صحیح a_exp, u128_t *a,
                           صحیح b_sgn, صحیح b_exp, u128_t *b)
#تعریف_کرو a (*a)
#تعریف_کرو b (*b)
{
#اگر 0
    // Detect signalling NaNs:
    اگر (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        واپس fp3_convert_NaN(f, a_sgn, a);
    اگر (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        واپس fp3_convert_NaN(f, b_sgn, b);
#اگر_ختم
    // Detect quiet NaNs:
    اگر (a_exp == 32767 && (a.x0 | a.x1 << 16))
        واپس fp3_convert_NaN(f, a_sgn, a);
    اگر (b_exp == 32767 && (b.x0 | b.x1 << 16))
        واپس fp3_convert_NaN(f, b_sgn, b);

    واپس 0;
#تعریف_منسوخ a
#تعریف_منسوخ b
#تعریف_کرو fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

ساکن خالی f3_unpack(صحیح *sgn, int32_t *قوت_نما, u128_t *mnt, طویل دوہرا f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *قوت_نما = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    اگر (*قوت_نما)
        x.x1 |= (uint64_t)1 << 48;
    ورنہ
        *قوت_نما = 1;
    mnt->f = x.f;
}

ساکن خالی f3_normalise(int32_t *قوت_نما, u128_t *mnt)
{
    صحیح sh;
    اگر (!(mnt->x0 | mnt->x1))
        واپس;
    اگر (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *قوت_نما -= 64;
    }
    برائے (sh = 32; sh; sh >>= 1) {
        اگر (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *قوت_نما -= sh;
        }
    }
}

ساکن خالی f3_sticky_سرکاؤ(int32_t sh, u128_t *x)
{
  اگر (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      واپس;
  }
  اگر (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  اگر (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

ساکن طویل دوہرا f3_باری(صحیح sgn, int32_t قوت_نما, u128_t *x)
{
    طویل دوہرا f;
    صحیح error;

    اگر (قوت_نما > 0) {
        f3_sticky_سرکاؤ(13, x);
    }
    ورنہ {
        f3_sticky_سرکاؤ(14 - قوت_نما, x);
        قوت_نما = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    اگر (error == 3 || ((error == 2) & (x->x0 & 1))) {
        اگر (!++x->x0) {
            ++x->x1;
            اگر (x->x1 == (uint64_t)1 << 48)
                قوت_نما = 1;
            ورنہ اگر (x->x1 == (uint64_t)1 << 49) {
                ++قوت_نما;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    اگر (قوت_نما >= 32767)
        واپس f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)قوت_نما << 48 | (uint64_t)sgn << 63;
    واپس x->f;
}

ساکن طویل دوہرا f3_جوڑو(طویل دوہرا fa, طویل دوہرا fb, صحیح neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحیح a_sgn, b_sgn, x_sgn;
    طویل دوہرا fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    اگر (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        واپس fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    اگر (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        واپس f3_NaN();
    اگر (a_exp == 32767)
        واپس f3_infinity(a_sgn);
    اگر (b_exp == 32767)
        واپس f3_infinity(b_sgn);
    اگر (!(a.x0 | a.x1 | b.x0 | b.x1))
        واپس f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    اگر (a_exp <= b_exp) {
        f3_sticky_سرکاؤ(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    ورنہ {
        f3_sticky_سرکاؤ(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    اگر (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    ورنہ {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        اگر (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    اگر (!(x.x0 | x.x1))
        واپس f3_zero(0);

    f3_normalise(&x_exp, &x);

    واپس f3_باری(x_sgn, x_exp + 12, &x);
}

طویل دوہرا __addtf3(طویل دوہرا a, طویل دوہرا b)
{
    واپس f3_جوڑو(a, b, 0);
}

طویل دوہرا __subtf3(طویل دوہرا a, طویل دوہرا b)
{
    واپس f3_جوڑو(a, b, 1);
}

طویل دوہرا __multf3(طویل دوہرا fa, طویل دوہرا fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحیح a_sgn, b_sgn, x_sgn;
    طویل دوہرا fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    اگر (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        واپس fx;

    // Handle infinities and zeroes:
    اگر ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        واپس f3_NaN();
    اگر (a_exp == 32767 || b_exp == 32767)
        واپس f3_infinity(a_sgn ^ b_sgn);
    اگر (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        واپس f3_zero(a_sgn ^ b_sgn);

    f3_normalise(&a_exp, &a);
    f3_normalise(&b_exp, &b);

    x_sgn = a_sgn ^ b_sgn;
    x_exp = a_exp + b_exp - 16352;

    {
        // Convert to base (1 << 30), discarding bottom 6 bits, which are zero,
        // so there are (32, 30, 30, 30) bits in (a3, a2, a1, a0):
        uint64_t a0 = a.x0 << 28 >> 34;
        uint64_t b0 = b.x0 << 28 >> 34;
        uint64_t a1 = a.x0 >> 36 | a.x1 << 62 >> 34;
        uint64_t b1 = b.x0 >> 36 | b.x1 << 62 >> 34;
        uint64_t a2 = a.x1 << 32 >> 34;
        uint64_t b2 = b.x1 << 32 >> 34;
        uint64_t a3 = a.x1 >> 32;
        uint64_t b3 = b.x1 >> 32;
        // Use 16 small multiplications and additions that do not overflow:
        uint64_t x0 = a0 * b0;
        uint64_t x1 = (x0 >> 30) + a0 * b1 + a1 * b0;
        uint64_t x2 = (x1 >> 30) + a0 * b2 + a1 * b1 + a2 * b0;
        uint64_t x3 = (x2 >> 30) + a0 * b3 + a1 * b2 + a2 * b1 + a3 * b0;
        uint64_t x4 = (x3 >> 30) + a1 * b3 + a2 * b2 + a3 * b1;
        uint64_t x5 = (x4 >> 30) + a2 * b3 + a3 * b2;
        uint64_t x6 = (x5 >> 30) + a3 * b3;
        // We now have (64, 30, 30, ...) bits in (x6, x5, x4, ...).
        // Take the top 128 bits, setting bottom bit if any lower bits were set:
        uint64_t y0 = (x5 << 34 | x4 << 34 >> 30 | x3 << 34 >> 60 |
                       !!(x3 << 38 | (x2 | x1 | x0) << 34));
        uint64_t y1 = x6;
        // Top bit may be zero. Renormalise:
        اگر (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    واپس f3_باری(x_sgn, x_exp, &x);
}

طویل دوہرا __divtf3(طویل دوہرا fa, طویل دوہرا fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحیح a_sgn, b_sgn, x_sgn, i;
    طویل دوہرا fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    اگر (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        واپس fx;

    // Handle infinities and zeroes:
    اگر ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        واپس f3_NaN();
    اگر (a_exp == 32767 || !(b.x0 | b.x1))
        واپس f3_infinity(a_sgn ^ b_sgn);
    اگر (!(a.x0 | a.x1) || b_exp == 32767)
        واپس f3_zero(a_sgn ^ b_sgn);

    f3_normalise(&a_exp, &a);
    f3_normalise(&b_exp, &b);

    x_sgn = a_sgn ^ b_sgn;
    x_exp = a_exp - b_exp + 16395;

    a.x0 = a.x0 >> 1 | a.x1 << 63;
    a.x1 = a.x1 >> 1;
    b.x0 = b.x0 >> 1 | b.x1 << 63;
    b.x1 = b.x1 >> 1;
    x.x0 = 0;
    x.x1 = 0;
    برائے (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        اگر (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    واپس f3_باری(x_sgn, x_exp, &x);
}

طویل دوہرا __negtf2(طویل دوہرا f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    واپس f;
}

طویل دوہرا __extendsftf2(اعشاری f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    اگر (!(a << 1))
        x.x1 = aa << 32;
    ورنہ اگر (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    ورنہ اگر (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        جب (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } ورنہ
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    واپس x.f;
}

طویل دوہرا __extenddftf2(دوہرا f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    اگر (!(a << 1))
        x.x1 = a;
    ورنہ اگر (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    ورنہ اگر (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        جب (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } ورنہ
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    واپس x.f;
}

اعشاری __trunctfsf2(طویل دوہرا f)
{
    u128_t mnt;
    int32_t قوت_نما;
    صحیح sgn;
    u32_t x;
#تعریف_کرو x x.x

    f3_unpack(&sgn, &قوت_نما, &mnt, f);
    اگر (قوت_نما == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    ورنہ اگر (قوت_نما > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    ورنہ اگر (قوت_نما < 16233)
        x = (uint32_t)sgn << 31;
    ورنہ {
        قوت_نما -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        اگر (قوت_نما < 0) {
            x = x >> -قوت_نما | !!(x << (32 + قوت_نما));
            قوت_نما = 0;
        }
        اگر ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (قوت_نما << 23)) | (uint32_t)sgn << 31;
    }
#تعریف_منسوخ x
    واپس x.f;
}

دوہرا __trunctfdf2(طویل دوہرا f)
{
    u128_t mnt;
    int32_t قوت_نما;
    صحیح sgn;
    u64_t x;
#تعریف_کرو x x.x

    f3_unpack(&sgn, &قوت_نما, &mnt, f);
    اگر (قوت_نما == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    ورنہ اگر (قوت_نما > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    ورنہ اگر (قوت_نما < 15308)
        x = (uint64_t)sgn << 63;
    ورنہ {
        قوت_نما -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        اگر (قوت_نما < 0) {
            x = x >> -قوت_نما | !!(x << (64 + قوت_نما));
            قوت_نما = 0;
        }
        اگر ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)قوت_نما << 52)) | (uint64_t)sgn << 63;
    }
#تعریف_منسوخ x
    واپس x.f;
}

int32_t __fixtfsi(طویل دوہرا fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_exp < 16369)
        واپس 0;
    اگر (a_exp > 16413)
        واپس a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    واپس a_sgn ? -x : x;
}

int64_t __fixtfdi(طویل دوہرا fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_exp < 16383)
        واپس 0;
    اگر (a_exp > 16445)
        واپس a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    واپس a_sgn ? -x : x;
}

uint32_t __fixunstfsi(طویل دوہرا fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_sgn || a_exp < 16369)
        واپس 0;
    اگر (a_exp > 16414)
        واپس -1;
    واپس a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(طویل دوہرا fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_sgn || a_exp < 16383)
        واپس 0;
    اگر (a_exp > 16446)
        واپس -1;
    واپس (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

طویل دوہرا __floatsitf(int32_t a)
{
    صحیح sgn = 0;
    صحیح قوت_نما = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    صحیح i;
    اگر (a) {
        اگر (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        برائے (i = 16; i; i >>= 1)
            اگر (!(mnt >> (32 - i))) {
                mnt <<= i;
                قوت_نما -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)قوت_نما << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    واپس x.f;
}

طویل دوہرا __floatditf(int64_t a)
{
    صحیح sgn = 0;
    صحیح قوت_نما = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    صحیح i;
    اگر (a) {
        اگر (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        برائے (i = 32; i; i >>= 1)
            اگر (!(mnt >> (64 - i))) {
                mnt <<= i;
                قوت_نما -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)قوت_نما << 48 | mnt << 1 >> 16;
    }
    واپس x.f;
}

طویل دوہرا __floatunsitf(uint32_t a)
{
    صحیح قوت_نما = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    صحیح i;
    اگر (a) {
        برائے (i = 16; i; i >>= 1)
            اگر (!(mnt >> (32 - i))) {
                mnt <<= i;
                قوت_نما -= i;
            }
        x.x1 = (uint64_t)قوت_نما << 48 | (uint64_t)(mnt << 1) << 16;
    }
    واپس x.f;
}

طویل دوہرا __floatunditf(uint64_t a)
{
    صحیح قوت_نما = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    طویل دوہرا f;
    صحیح i;
    اگر (a) {
        برائے (i = 32; i; i >>= 1)
            اگر (!(mnt >> (64 - i))) {
                mnt <<= i;
                قوت_نما -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)قوت_نما << 48 | mnt << 1 >> 16;
    }
    واپس x.f;
}

ساکن صحیح f3_cmp(طویل دوہرا fa, طویل دوہرا fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    واپس (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (صحیح)(b.x1 >> 63) - (صحیح)(a.x1 >> 63) :
            a.x1 < b.x1 ? (صحیح)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (صحیح)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (صحیح)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (صحیح)(a.x1 >> 63 << 1) : 0);
}

صحیح __eqtf2(طویل دوہرا a, طویل دوہرا b)
{
    واپس !!f3_cmp(a, b);
}

صحیح __netf2(طویل دوہرا a, طویل دوہرا b)
{
    واپس !!f3_cmp(a, b);
}

صحیح __lttf2(طویل دوہرا a, طویل دوہرا b)
{
    واپس f3_cmp(a, b);
}

صحیح __letf2(طویل دوہرا a, طویل دوہرا b)
{
    واپس f3_cmp(a, b);
}

صحیح __gttf2(طویل دوہرا a, طویل دوہرا b)
{
    واپس -f3_cmp(b, a);
}

صحیح __getf2(طویل دوہرا a, طویل دوہرا b)
{
    واپس -f3_cmp(b, a);
}
