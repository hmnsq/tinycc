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
typedef signed var_na int8_t;
typedef unsigned var_na uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef ཧྲིལ int32_t;
typedef unsigned uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;
#དེ་མིན
#include <stdint.h>
#include <string.h>
#endif

typedef sa_ngha {
    sa_nracanaa { uint64_t x0, x1; };
    long dviguu_na f;
} u128_t;

typedef sa_ngha {
    uint64_t x;
    dviguu_na f;
} u64_t;

typedef sa_ngha {
    uint32_t x;
    float f;
} u32_t;

static long dviguu_na f3_zero(ཧྲིལ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    ལོག x.f;
}

static long dviguu_na f3_infinity(ཧྲིལ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    ལོག x.f;
}

static long dviguu_na f3_NaN(void)
{
#གལ་སྲིད 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#དེ་མིན
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#endif
    ལོག x.f;
}

static ཧྲིལ fp3_convert_NaN(long dviguu_na *f, ཧྲིལ sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    ལོག 1;
#define fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

static ཧྲིལ fp3_detect_NaNs(long dviguu_na *f,
                           ཧྲིལ a_sgn, ཧྲིལ a_exp, u128_t *a,
                           ཧྲིལ b_sgn, ཧྲིལ b_exp, u128_t *b)
#define a (*a)
#define b (*b)
{
#གལ་སྲིད 0
    // Detect signalling NaNs:
    གལ་སྲིད (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        ལོག fp3_convert_NaN(f, a_sgn, a);
    གལ་སྲིད (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        ལོག fp3_convert_NaN(f, b_sgn, b);
#endif
    // Detect quiet NaNs:
    གལ་སྲིད (a_exp == 32767 && (a.x0 | a.x1 << 16))
        ལོག fp3_convert_NaN(f, a_sgn, a);
    གལ་སྲིད (b_exp == 32767 && (b.x0 | b.x1 << 16))
        ལོག fp3_convert_NaN(f, b_sgn, b);

    ལོག 0;
#undef a
#undef b
#define fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

static void f3_unpack(ཧྲིལ *sgn, int32_t *exp, u128_t *mnt, long dviguu_na f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    གལ་སྲིད (*exp)
        x.x1 |= (uint64_t)1 << 48;
    དེ་མིན
        *exp = 1;
    mnt->f = x.f;
}

static void f3_normalise(int32_t *exp, u128_t *mnt)
{
    ཧྲིལ sh;
    གལ་སྲིད (!(mnt->x0 | mnt->x1))
        ལོག;
    གལ་སྲིད (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    དོན་ལུ (sh = 32; sh; sh >>= 1) {
        གལ་སྲིད (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

static void f3_sticky_shift(int32_t sh, u128_t *x)
{
  གལ་སྲིད (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      ལོག;
  }
  གལ་སྲིད (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  གལ་སྲིད (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

static long dviguu_na f3_round(ཧྲིལ sgn, int32_t exp, u128_t *x)
{
    long dviguu_na f;
    ཧྲིལ error;

    གལ་སྲིད (exp > 0) {
        f3_sticky_shift(13, x);
    }
    དེ་མིན {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    གལ་སྲིད (error == 3 || ((error == 2) & (x->x0 & 1))) {
        གལ་སྲིད (!++x->x0) {
            ++x->x1;
            གལ་སྲིད (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            དེ་མིན གལ་སྲིད (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    གལ་སྲིད (exp >= 32767)
        ལོག f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    ལོག x->f;
}

static long dviguu_na f3_add(long dviguu_na fa, long dviguu_na fb, ཧྲིལ neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ཧྲིལ a_sgn, b_sgn, x_sgn;
    long dviguu_na fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    གལ་སྲིད (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ལོག fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    གལ་སྲིད (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        ལོག f3_NaN();
    གལ་སྲིད (a_exp == 32767)
        ལོག f3_infinity(a_sgn);
    གལ་སྲིད (b_exp == 32767)
        ལོག f3_infinity(b_sgn);
    གལ་སྲིད (!(a.x0 | a.x1 | b.x0 | b.x1))
        ལོག f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    གལ་སྲིད (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    དེ་མིན {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    གལ་སྲིད (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    དེ་མིན {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        གལ་སྲིད (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    གལ་སྲིད (!(x.x0 | x.x1))
        ལོག f3_zero(0);

    f3_normalise(&x_exp, &x);

    ལོག f3_round(x_sgn, x_exp + 12, &x);
}

long dviguu_na __addtf3(long dviguu_na a, long dviguu_na b)
{
    ལོག f3_add(a, b, 0);
}

long dviguu_na __subtf3(long dviguu_na a, long dviguu_na b)
{
    ལོག f3_add(a, b, 1);
}

long dviguu_na __multf3(long dviguu_na fa, long dviguu_na fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ཧྲིལ a_sgn, b_sgn, x_sgn;
    long dviguu_na fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    གལ་སྲིད (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ལོག fx;

    // Handle infinities and zeroes:
    གལ་སྲིད ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        ལོག f3_NaN();
    གལ་སྲིད (a_exp == 32767 || b_exp == 32767)
        ལོག f3_infinity(a_sgn ^ b_sgn);
    གལ་སྲིད (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        ལོག f3_zero(a_sgn ^ b_sgn);

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
        གལ་སྲིད (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    ལོག f3_round(x_sgn, x_exp, &x);
}

long dviguu_na __divtf3(long dviguu_na fa, long dviguu_na fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ཧྲིལ a_sgn, b_sgn, x_sgn, i;
    long dviguu_na fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    གལ་སྲིད (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ལོག fx;

    // Handle infinities and zeroes:
    གལ་སྲིད ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        ལོག f3_NaN();
    གལ་སྲིད (a_exp == 32767 || !(b.x0 | b.x1))
        ལོག f3_infinity(a_sgn ^ b_sgn);
    གལ་སྲིད (!(a.x0 | a.x1) || b_exp == 32767)
        ལོག f3_zero(a_sgn ^ b_sgn);

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
    དོན་ལུ (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        གལ་སྲིད (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    ལོག f3_round(x_sgn, x_exp, &x);
}

long dviguu_na __negtf2(long dviguu_na f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    ལོག f;
}

long dviguu_na __extendsftf2(float f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    གལ་སྲིད (!(a << 1))
        x.x1 = aa << 32;
    དེ་མིན གལ་སྲིད (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    དེ་མིན གལ་སྲིད (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        སྐབས (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } དེ་མིན
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    ལོག x.f;
}

long dviguu_na __extenddftf2(dviguu_na f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    གལ་སྲིད (!(a << 1))
        x.x1 = a;
    དེ་མིན གལ་སྲིད (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    དེ་མིན གལ་སྲིད (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        སྐབས (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } དེ་མིན
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    ལོག x.f;
}

float __trunctfsf2(long dviguu_na f)
{
    u128_t mnt;
    int32_t exp;
    ཧྲིལ sgn;
    u32_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    གལ་སྲིད (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    དེ་མིན གལ་སྲིད (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    དེ་མིན གལ་སྲིད (exp < 16233)
        x = (uint32_t)sgn << 31;
    དེ་མིན {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        གལ་སྲིད (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        གལ་སྲིད ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#undef x
    ལོག x.f;
}

dviguu_na __trunctfdf2(long dviguu_na f)
{
    u128_t mnt;
    int32_t exp;
    ཧྲིལ sgn;
    u64_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    གལ་སྲིད (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    དེ་མིན གལ་སྲིད (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    དེ་མིན གལ་སྲིད (exp < 15308)
        x = (uint64_t)sgn << 63;
    དེ་མིན {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        གལ་སྲིད (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        གལ་སྲིད ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#undef x
    ལོག x.f;
}

int32_t __fixtfsi(long dviguu_na fa)
{
    u128_t a;
    int32_t a_exp;
    ཧྲིལ a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    གལ་སྲིད (a_exp < 16369)
        ལོག 0;
    གལ་སྲིད (a_exp > 16413)
        ལོག a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    ལོག a_sgn ? -x : x;
}

int64_t __fixtfdi(long dviguu_na fa)
{
    u128_t a;
    int32_t a_exp;
    ཧྲིལ a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    གལ་སྲིད (a_exp < 16383)
        ལོག 0;
    གལ་སྲིད (a_exp > 16445)
        ལོག a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    ལོག a_sgn ? -x : x;
}

uint32_t __fixunstfsi(long dviguu_na fa)
{
    u128_t a;
    int32_t a_exp;
    ཧྲིལ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    གལ་སྲིད (a_sgn || a_exp < 16369)
        ལོག 0;
    གལ་སྲིད (a_exp > 16414)
        ལོག -1;
    ལོག a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(long dviguu_na fa)
{
    u128_t a;
    int32_t a_exp;
    ཧྲིལ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    གལ་སྲིད (a_sgn || a_exp < 16383)
        ལོག 0;
    གལ་སྲིད (a_exp > 16446)
        ལོག -1;
    ལོག (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

long dviguu_na __floatsitf(int32_t a)
{
    ཧྲིལ sgn = 0;
    ཧྲིལ exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ཧྲིལ i;
    གལ་སྲིད (a) {
        གལ་སྲིད (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        དོན་ལུ (i = 16; i; i >>= 1)
            གལ་སྲིད (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    ལོག x.f;
}

long dviguu_na __floatditf(int64_t a)
{
    ཧྲིལ sgn = 0;
    ཧྲིལ exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    ཧྲིལ i;
    གལ་སྲིད (a) {
        གལ་སྲིད (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        དོན་ལུ (i = 32; i; i >>= 1)
            གལ་སྲིད (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    ལོག x.f;
}

long dviguu_na __floatunsitf(uint32_t a)
{
    ཧྲིལ exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ཧྲིལ i;
    གལ་སྲིད (a) {
        དོན་ལུ (i = 16; i; i >>= 1)
            གལ་སྲིད (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    ལོག x.f;
}

long dviguu_na __floatunditf(uint64_t a)
{
    ཧྲིལ exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    long dviguu_na f;
    ཧྲིལ i;
    གལ་སྲིད (a) {
        དོན་ལུ (i = 32; i; i >>= 1)
            གལ་སྲིད (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    ལོག x.f;
}

static ཧྲིལ f3_cmp(long dviguu_na fa, long dviguu_na fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    ལོག (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (ཧྲིལ)(b.x1 >> 63) - (ཧྲིལ)(a.x1 >> 63) :
            a.x1 < b.x1 ? (ཧྲིལ)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (ཧྲིལ)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (ཧྲིལ)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (ཧྲིལ)(a.x1 >> 63 << 1) : 0);
}

ཧྲིལ __eqtf2(long dviguu_na a, long dviguu_na b)
{
    ལོག !!f3_cmp(a, b);
}

ཧྲིལ __netf2(long dviguu_na a, long dviguu_na b)
{
    ལོག !!f3_cmp(a, b);
}

ཧྲིལ __lttf2(long dviguu_na a, long dviguu_na b)
{
    ལོག f3_cmp(a, b);
}

ཧྲིལ __letf2(long dviguu_na a, long dviguu_na b)
{
    ལོག f3_cmp(a, b);
}

ཧྲིལ __gttf2(long dviguu_na a, long dviguu_na b)
{
    ལོག -f3_cmp(b, a);
}

ཧྲིལ __getf2(long dviguu_na a, long dviguu_na b)
{
    ལོག -f3_cmp(b, a);
}
