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
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef ціле int32_t;
typedef unsigned uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;
#інакше
#include <stdint.h>
#include <string.h>
#endif

typedef union {
    struct { uint64_t x0, x1; };
    long double f;
} u128_t;

typedef union {
    uint64_t x;
    double f;
} u64_t;

typedef union {
    uint32_t x;
    float f;
} u32_t;

static long double f3_zero(ціле sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    повернути x.f;
}

static long double f3_infinity(ціле sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    повернути x.f;
}

static long double f3_NaN(void)
{
#якщо 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#інакше
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#endif
    повернути x.f;
}

static ціле fp3_convert_NaN(long double *f, ціле sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    повернути 1;
#define fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

static ціле fp3_detect_NaNs(long double *f,
                           ціле a_sgn, ціле a_exp, u128_t *a,
                           ціле b_sgn, ціле b_exp, u128_t *b)
#define a (*a)
#define b (*b)
{
#якщо 0
    // Detect signalling NaNs:
    якщо (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        повернути fp3_convert_NaN(f, a_sgn, a);
    якщо (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        повернути fp3_convert_NaN(f, b_sgn, b);
#endif
    // Detect quiet NaNs:
    якщо (a_exp == 32767 && (a.x0 | a.x1 << 16))
        повернути fp3_convert_NaN(f, a_sgn, a);
    якщо (b_exp == 32767 && (b.x0 | b.x1 << 16))
        повернути fp3_convert_NaN(f, b_sgn, b);

    повернути 0;
#undef a
#undef b
#define fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

static void f3_unpack(ціле *sgn, int32_t *exp, u128_t *mnt, long double f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    якщо (*exp)
        x.x1 |= (uint64_t)1 << 48;
    інакше
        *exp = 1;
    mnt->f = x.f;
}

static void f3_normalise(int32_t *exp, u128_t *mnt)
{
    ціле sh;
    якщо (!(mnt->x0 | mnt->x1))
        повернути;
    якщо (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    для (sh = 32; sh; sh >>= 1) {
        якщо (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

static void f3_sticky_shift(int32_t sh, u128_t *x)
{
  якщо (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      повернути;
  }
  якщо (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  якщо (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

static long double f3_round(ціле sgn, int32_t exp, u128_t *x)
{
    long double f;
    ціле error;

    якщо (exp > 0) {
        f3_sticky_shift(13, x);
    }
    інакше {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    якщо (error == 3 || ((error == 2) & (x->x0 & 1))) {
        якщо (!++x->x0) {
            ++x->x1;
            якщо (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            інакше якщо (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    якщо (exp >= 32767)
        повернути f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    повернути x->f;
}

static long double f3_add(long double fa, long double fb, ціле neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ціле a_sgn, b_sgn, x_sgn;
    long double fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    якщо (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        повернути fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    якщо (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        повернути f3_NaN();
    якщо (a_exp == 32767)
        повернути f3_infinity(a_sgn);
    якщо (b_exp == 32767)
        повернути f3_infinity(b_sgn);
    якщо (!(a.x0 | a.x1 | b.x0 | b.x1))
        повернути f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    якщо (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    інакше {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    якщо (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    інакше {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        якщо (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    якщо (!(x.x0 | x.x1))
        повернути f3_zero(0);

    f3_normalise(&x_exp, &x);

    повернути f3_round(x_sgn, x_exp + 12, &x);
}

long double __addtf3(long double a, long double b)
{
    повернути f3_add(a, b, 0);
}

long double __subtf3(long double a, long double b)
{
    повернути f3_add(a, b, 1);
}

long double __multf3(long double fa, long double fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ціле a_sgn, b_sgn, x_sgn;
    long double fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    якщо (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        повернути fx;

    // Handle infinities and zeroes:
    якщо ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        повернути f3_NaN();
    якщо (a_exp == 32767 || b_exp == 32767)
        повернути f3_infinity(a_sgn ^ b_sgn);
    якщо (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        повернути f3_zero(a_sgn ^ b_sgn);

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
        якщо (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    повернути f3_round(x_sgn, x_exp, &x);
}

long double __divtf3(long double fa, long double fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ціле a_sgn, b_sgn, x_sgn, i;
    long double fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    якщо (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        повернути fx;

    // Handle infinities and zeroes:
    якщо ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        повернути f3_NaN();
    якщо (a_exp == 32767 || !(b.x0 | b.x1))
        повернути f3_infinity(a_sgn ^ b_sgn);
    якщо (!(a.x0 | a.x1) || b_exp == 32767)
        повернути f3_zero(a_sgn ^ b_sgn);

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
    для (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        якщо (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    повернути f3_round(x_sgn, x_exp, &x);
}

long double __negtf2(long double f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    повернути f;
}

long double __extendsftf2(float f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    якщо (!(a << 1))
        x.x1 = aa << 32;
    інакше якщо (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    інакше якщо (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        поки (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } інакше
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    повернути x.f;
}

long double __extenddftf2(double f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    якщо (!(a << 1))
        x.x1 = a;
    інакше якщо (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    інакше якщо (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        поки (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } інакше
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    повернути x.f;
}

float __trunctfsf2(long double f)
{
    u128_t mnt;
    int32_t exp;
    ціле sgn;
    u32_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    якщо (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    інакше якщо (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    інакше якщо (exp < 16233)
        x = (uint32_t)sgn << 31;
    інакше {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        якщо (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        якщо ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#undef x
    повернути x.f;
}

double __trunctfdf2(long double f)
{
    u128_t mnt;
    int32_t exp;
    ціле sgn;
    u64_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    якщо (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    інакше якщо (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    інакше якщо (exp < 15308)
        x = (uint64_t)sgn << 63;
    інакше {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        якщо (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        якщо ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#undef x
    повернути x.f;
}

int32_t __fixtfsi(long double fa)
{
    u128_t a;
    int32_t a_exp;
    ціле a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    якщо (a_exp < 16369)
        повернути 0;
    якщо (a_exp > 16413)
        повернути a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    повернути a_sgn ? -x : x;
}

int64_t __fixtfdi(long double fa)
{
    u128_t a;
    int32_t a_exp;
    ціле a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    якщо (a_exp < 16383)
        повернути 0;
    якщо (a_exp > 16445)
        повернути a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    повернути a_sgn ? -x : x;
}

uint32_t __fixunstfsi(long double fa)
{
    u128_t a;
    int32_t a_exp;
    ціле a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    якщо (a_sgn || a_exp < 16369)
        повернути 0;
    якщо (a_exp > 16414)
        повернути -1;
    повернути a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(long double fa)
{
    u128_t a;
    int32_t a_exp;
    ціле a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    якщо (a_sgn || a_exp < 16383)
        повернути 0;
    якщо (a_exp > 16446)
        повернути -1;
    повернути (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

long double __floatsitf(int32_t a)
{
    ціле sgn = 0;
    ціле exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ціле i;
    якщо (a) {
        якщо (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        для (i = 16; i; i >>= 1)
            якщо (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    повернути x.f;
}

long double __floatditf(int64_t a)
{
    ціле sgn = 0;
    ціле exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    ціле i;
    якщо (a) {
        якщо (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        для (i = 32; i; i >>= 1)
            якщо (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    повернути x.f;
}

long double __floatunsitf(uint32_t a)
{
    ціле exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ціле i;
    якщо (a) {
        для (i = 16; i; i >>= 1)
            якщо (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    повернути x.f;
}

long double __floatunditf(uint64_t a)
{
    ціле exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    long double f;
    ціле i;
    якщо (a) {
        для (i = 32; i; i >>= 1)
            якщо (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    повернути x.f;
}

static ціле f3_cmp(long double fa, long double fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    повернути (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (ціле)(b.x1 >> 63) - (ціле)(a.x1 >> 63) :
            a.x1 < b.x1 ? (ціле)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (ціле)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (ціле)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (ціле)(a.x1 >> 63 << 1) : 0);
}

ціле __eqtf2(long double a, long double b)
{
    повернути !!f3_cmp(a, b);
}

ціле __netf2(long double a, long double b)
{
    повернути !!f3_cmp(a, b);
}

ціле __lttf2(long double a, long double b)
{
    повернути f3_cmp(a, b);
}

ціле __letf2(long double a, long double b)
{
    повернути f3_cmp(a, b);
}

ціле __gttf2(long double a, long double b)
{
    повернути -f3_cmp(b, a);
}

ціле __getf2(long double a, long double b)
{
    повернути -f3_cmp(b, a);
}
