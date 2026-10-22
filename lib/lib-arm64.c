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

#ifdef __TINYC__
تعریفنوع signed نویسه int8_t;
تعریفنوع unsigned نویسه uint8_t;
تعریفنوع short int16_t;
تعریفنوع unsigned short uint16_t;
تعریفنوع صحیح int32_t;
تعریفنوع unsigned uint32_t;
تعریفنوع long long int64_t;
تعریفنوع unsigned long long uint64_t;
#وگرنه
#شامل <stdint.h>
#شامل <string.h>
#endif

تعریفنوع اجتماع {
    ساختار { uint64_t x0, x1; };
    long دوگانه f;
} u128_t;

تعریفنوع اجتماع {
    uint64_t x;
    دوگانه f;
} u64_t;

تعریفنوع اجتماع {
    uint32_t x;
    اعشاری f;
} u32_t;

ایستا long دوگانه f3_zero(صحیح sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    بازگشت x.f;
}

ایستا long دوگانه f3_infinity(صحیح sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    بازگشت x.f;
}

ایستا long دوگانه f3_NaN(تهی)
{
#اگر 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#وگرنه
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#endif
    بازگشت x.f;
}

ایستا صحیح fp3_convert_NaN(long دوگانه *f, صحیح sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    بازگشت 1;
#define fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

ایستا صحیح fp3_detect_NaNs(long دوگانه *f,
                           صحیح a_sgn, صحیح a_exp, u128_t *a,
                           صحیح b_sgn, صحیح b_exp, u128_t *b)
#define a (*a)
#define b (*b)
{
#اگر 0
    // Detect signalling NaNs:
    اگر (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        بازگشت fp3_convert_NaN(f, a_sgn, a);
    اگر (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        بازگشت fp3_convert_NaN(f, b_sgn, b);
#endif
    // Detect quiet NaNs:
    اگر (a_exp == 32767 && (a.x0 | a.x1 << 16))
        بازگشت fp3_convert_NaN(f, a_sgn, a);
    اگر (b_exp == 32767 && (b.x0 | b.x1 << 16))
        بازگشت fp3_convert_NaN(f, b_sgn, b);

    بازگشت 0;
#undef a
#undef b
#define fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

ایستا تهی f3_unpack(صحیح *sgn, int32_t *exp, u128_t *mnt, long دوگانه f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    اگر (*exp)
        x.x1 |= (uint64_t)1 << 48;
    وگرنه
        *exp = 1;
    mnt->f = x.f;
}

ایستا تهی f3_normalise(int32_t *exp, u128_t *mnt)
{
    صحیح sh;
    اگر (!(mnt->x0 | mnt->x1))
        بازگشت;
    اگر (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    برای (sh = 32; sh; sh >>= 1) {
        اگر (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

ایستا تهی f3_sticky_shift(int32_t sh, u128_t *x)
{
  اگر (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      بازگشت;
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

ایستا long دوگانه f3_round(صحیح sgn, int32_t exp, u128_t *x)
{
    long دوگانه f;
    صحیح error;

    اگر (exp > 0) {
        f3_sticky_shift(13, x);
    }
    وگرنه {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    اگر (error == 3 || ((error == 2) & (x->x0 & 1))) {
        اگر (!++x->x0) {
            ++x->x1;
            اگر (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            وگرنه اگر (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    اگر (exp >= 32767)
        بازگشت f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    بازگشت x->f;
}

ایستا long دوگانه f3_add(long دوگانه fa, long دوگانه fb, صحیح neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحیح a_sgn, b_sgn, x_sgn;
    long دوگانه fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    اگر (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        بازگشت fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    اگر (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        بازگشت f3_NaN();
    اگر (a_exp == 32767)
        بازگشت f3_infinity(a_sgn);
    اگر (b_exp == 32767)
        بازگشت f3_infinity(b_sgn);
    اگر (!(a.x0 | a.x1 | b.x0 | b.x1))
        بازگشت f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    اگر (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    وگرنه {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    اگر (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    وگرنه {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        اگر (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    اگر (!(x.x0 | x.x1))
        بازگشت f3_zero(0);

    f3_normalise(&x_exp, &x);

    بازگشت f3_round(x_sgn, x_exp + 12, &x);
}

long دوگانه __addtf3(long دوگانه a, long دوگانه b)
{
    بازگشت f3_add(a, b, 0);
}

long دوگانه __subtf3(long دوگانه a, long دوگانه b)
{
    بازگشت f3_add(a, b, 1);
}

long دوگانه __multf3(long دوگانه fa, long دوگانه fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحیح a_sgn, b_sgn, x_sgn;
    long دوگانه fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    اگر (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        بازگشت fx;

    // Handle infinities and zeroes:
    اگر ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        بازگشت f3_NaN();
    اگر (a_exp == 32767 || b_exp == 32767)
        بازگشت f3_infinity(a_sgn ^ b_sgn);
    اگر (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        بازگشت f3_zero(a_sgn ^ b_sgn);

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

    بازگشت f3_round(x_sgn, x_exp, &x);
}

long دوگانه __divtf3(long دوگانه fa, long دوگانه fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحیح a_sgn, b_sgn, x_sgn, i;
    long دوگانه fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    اگر (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        بازگشت fx;

    // Handle infinities and zeroes:
    اگر ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        بازگشت f3_NaN();
    اگر (a_exp == 32767 || !(b.x0 | b.x1))
        بازگشت f3_infinity(a_sgn ^ b_sgn);
    اگر (!(a.x0 | a.x1) || b_exp == 32767)
        بازگشت f3_zero(a_sgn ^ b_sgn);

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
    برای (i = 0; i < 116; i++) {
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

    بازگشت f3_round(x_sgn, x_exp, &x);
}

long دوگانه __negtf2(long دوگانه f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    بازگشت f;
}

long دوگانه __extendsftf2(اعشاری f)
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
    وگرنه اگر (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    وگرنه اگر (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        وقتی (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } وگرنه
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    بازگشت x.f;
}

long دوگانه __extenddftf2(دوگانه f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    اگر (!(a << 1))
        x.x1 = a;
    وگرنه اگر (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    وگرنه اگر (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        وقتی (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } وگرنه
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    بازگشت x.f;
}

اعشاری __trunctfsf2(long دوگانه f)
{
    u128_t mnt;
    int32_t exp;
    صحیح sgn;
    u32_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    اگر (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    وگرنه اگر (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    وگرنه اگر (exp < 16233)
        x = (uint32_t)sgn << 31;
    وگرنه {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        اگر (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        اگر ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#undef x
    بازگشت x.f;
}

دوگانه __trunctfdf2(long دوگانه f)
{
    u128_t mnt;
    int32_t exp;
    صحیح sgn;
    u64_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    اگر (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    وگرنه اگر (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    وگرنه اگر (exp < 15308)
        x = (uint64_t)sgn << 63;
    وگرنه {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        اگر (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        اگر ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#undef x
    بازگشت x.f;
}

int32_t __fixtfsi(long دوگانه fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_exp < 16369)
        بازگشت 0;
    اگر (a_exp > 16413)
        بازگشت a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    بازگشت a_sgn ? -x : x;
}

int64_t __fixtfdi(long دوگانه fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_exp < 16383)
        بازگشت 0;
    اگر (a_exp > 16445)
        بازگشت a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    بازگشت a_sgn ? -x : x;
}

uint32_t __fixunstfsi(long دوگانه fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_sgn || a_exp < 16369)
        بازگشت 0;
    اگر (a_exp > 16414)
        بازگشت -1;
    بازگشت a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(long دوگانه fa)
{
    u128_t a;
    int32_t a_exp;
    صحیح a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    اگر (a_sgn || a_exp < 16383)
        بازگشت 0;
    اگر (a_exp > 16446)
        بازگشت -1;
    بازگشت (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

long دوگانه __floatsitf(int32_t a)
{
    صحیح sgn = 0;
    صحیح exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    صحیح i;
    اگر (a) {
        اگر (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        برای (i = 16; i; i >>= 1)
            اگر (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    بازگشت x.f;
}

long دوگانه __floatditf(int64_t a)
{
    صحیح sgn = 0;
    صحیح exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    صحیح i;
    اگر (a) {
        اگر (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        برای (i = 32; i; i >>= 1)
            اگر (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    بازگشت x.f;
}

long دوگانه __floatunsitf(uint32_t a)
{
    صحیح exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    صحیح i;
    اگر (a) {
        برای (i = 16; i; i >>= 1)
            اگر (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    بازگشت x.f;
}

long دوگانه __floatunditf(uint64_t a)
{
    صحیح exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    long دوگانه f;
    صحیح i;
    اگر (a) {
        برای (i = 32; i; i >>= 1)
            اگر (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    بازگشت x.f;
}

ایستا صحیح f3_cmp(long دوگانه fa, long دوگانه fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    بازگشت (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (صحیح)(b.x1 >> 63) - (صحیح)(a.x1 >> 63) :
            a.x1 < b.x1 ? (صحیح)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (صحیح)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (صحیح)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (صحیح)(a.x1 >> 63 << 1) : 0);
}

صحیح __eqtf2(long دوگانه a, long دوگانه b)
{
    بازگشت !!f3_cmp(a, b);
}

صحیح __netf2(long دوگانه a, long دوگانه b)
{
    بازگشت !!f3_cmp(a, b);
}

صحیح __lttf2(long دوگانه a, long دوگانه b)
{
    بازگشت f3_cmp(a, b);
}

صحیح __letf2(long دوگانه a, long دوگانه b)
{
    بازگشت f3_cmp(a, b);
}

صحیح __gttf2(long دوگانه a, long دوگانه b)
{
    بازگشت -f3_cmp(b, a);
}

صحیح __getf2(long دوگانه a, long دوگانه b)
{
    بازگشت -f3_cmp(b, a);
}
