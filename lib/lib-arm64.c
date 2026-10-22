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
প্রকারলেখ signed অক্ষর int8_t;
প্রকারলেখ unsigned অক্ষর uint8_t;
প্রকারলেখ short int16_t;
প্রকারলেখ unsigned short uint16_t;
প্রকারলেখ পূর্ণসংখ্যা int32_t;
প্রকারলেখ unsigned uint32_t;
প্রকারলেখ long long int64_t;
প্রকারলেখ unsigned long long uint64_t;
#অন্যথা
#অন্তর্ভাব <stdint.h>
#অন্তর্ভাব <string.h>
#endif

প্রকারলেখ সংঘ {
    কাঠামো { uint64_t x0, x1; };
    long দ্বিগুণ f;
} u128_t;

প্রকারলেখ সংঘ {
    uint64_t x;
    দ্বিগুণ f;
} u64_t;

প্রকারলেখ সংঘ {
    uint32_t x;
    দশমিক f;
} u32_t;

স্থির long দ্বিগুণ f3_zero(পূর্ণসংখ্যা sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    ফেরত x.f;
}

স্থির long দ্বিগুণ f3_infinity(পূর্ণসংখ্যা sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    ফেরত x.f;
}

স্থির long দ্বিগুণ f3_NaN(শূন্য)
{
#যদি 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#অন্যথা
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#endif
    ফেরত x.f;
}

স্থির পূর্ণসংখ্যা fp3_convert_NaN(long দ্বিগুণ *f, পূর্ণসংখ্যা sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    ফেরত 1;
#define fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

স্থির পূর্ণসংখ্যা fp3_detect_NaNs(long দ্বিগুণ *f,
                           পূর্ণসংখ্যা a_sgn, পূর্ণসংখ্যা a_exp, u128_t *a,
                           পূর্ণসংখ্যা b_sgn, পূর্ণসংখ্যা b_exp, u128_t *b)
#define a (*a)
#define b (*b)
{
#যদি 0
    // Detect signalling NaNs:
    যদি (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        ফেরত fp3_convert_NaN(f, a_sgn, a);
    যদি (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        ফেরত fp3_convert_NaN(f, b_sgn, b);
#endif
    // Detect quiet NaNs:
    যদি (a_exp == 32767 && (a.x0 | a.x1 << 16))
        ফেরত fp3_convert_NaN(f, a_sgn, a);
    যদি (b_exp == 32767 && (b.x0 | b.x1 << 16))
        ফেরত fp3_convert_NaN(f, b_sgn, b);

    ফেরত 0;
#undef a
#undef b
#define fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

স্থির শূন্য f3_unpack(পূর্ণসংখ্যা *sgn, int32_t *exp, u128_t *mnt, long দ্বিগুণ f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    যদি (*exp)
        x.x1 |= (uint64_t)1 << 48;
    অন্যথা
        *exp = 1;
    mnt->f = x.f;
}

স্থির শূন্য f3_normalise(int32_t *exp, u128_t *mnt)
{
    পূর্ণসংখ্যা sh;
    যদি (!(mnt->x0 | mnt->x1))
        ফেরত;
    যদি (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    জন্য (sh = 32; sh; sh >>= 1) {
        যদি (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

স্থির শূন্য f3_sticky_shift(int32_t sh, u128_t *x)
{
  যদি (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      ফেরত;
  }
  যদি (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  যদি (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

স্থির long দ্বিগুণ f3_round(পূর্ণসংখ্যা sgn, int32_t exp, u128_t *x)
{
    long দ্বিগুণ f;
    পূর্ণসংখ্যা error;

    যদি (exp > 0) {
        f3_sticky_shift(13, x);
    }
    অন্যথা {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    যদি (error == 3 || ((error == 2) & (x->x0 & 1))) {
        যদি (!++x->x0) {
            ++x->x1;
            যদি (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            অন্যথা যদি (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    যদি (exp >= 32767)
        ফেরত f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    ফেরত x->f;
}

স্থির long দ্বিগুণ f3_add(long দ্বিগুণ fa, long দ্বিগুণ fb, পূর্ণসংখ্যা neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    পূর্ণসংখ্যা a_sgn, b_sgn, x_sgn;
    long দ্বিগুণ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    যদি (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ফেরত fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    যদি (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        ফেরত f3_NaN();
    যদি (a_exp == 32767)
        ফেরত f3_infinity(a_sgn);
    যদি (b_exp == 32767)
        ফেরত f3_infinity(b_sgn);
    যদি (!(a.x0 | a.x1 | b.x0 | b.x1))
        ফেরত f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    যদি (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    অন্যথা {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    যদি (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    অন্যথা {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        যদি (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    যদি (!(x.x0 | x.x1))
        ফেরত f3_zero(0);

    f3_normalise(&x_exp, &x);

    ফেরত f3_round(x_sgn, x_exp + 12, &x);
}

long দ্বিগুণ __addtf3(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত f3_add(a, b, 0);
}

long দ্বিগুণ __subtf3(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত f3_add(a, b, 1);
}

long দ্বিগুণ __multf3(long দ্বিগুণ fa, long দ্বিগুণ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    পূর্ণসংখ্যা a_sgn, b_sgn, x_sgn;
    long দ্বিগুণ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    যদি (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ফেরত fx;

    // Handle infinities and zeroes:
    যদি ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        ফেরত f3_NaN();
    যদি (a_exp == 32767 || b_exp == 32767)
        ফেরত f3_infinity(a_sgn ^ b_sgn);
    যদি (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        ফেরত f3_zero(a_sgn ^ b_sgn);

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
        যদি (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    ফেরত f3_round(x_sgn, x_exp, &x);
}

long দ্বিগুণ __divtf3(long দ্বিগুণ fa, long দ্বিগুণ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    পূর্ণসংখ্যা a_sgn, b_sgn, x_sgn, i;
    long দ্বিগুণ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    যদি (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ফেরত fx;

    // Handle infinities and zeroes:
    যদি ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        ফেরত f3_NaN();
    যদি (a_exp == 32767 || !(b.x0 | b.x1))
        ফেরত f3_infinity(a_sgn ^ b_sgn);
    যদি (!(a.x0 | a.x1) || b_exp == 32767)
        ফেরত f3_zero(a_sgn ^ b_sgn);

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
    জন্য (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        যদি (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    ফেরত f3_round(x_sgn, x_exp, &x);
}

long দ্বিগুণ __negtf2(long দ্বিগুণ f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    ফেরত f;
}

long দ্বিগুণ __extendsftf2(দশমিক f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    যদি (!(a << 1))
        x.x1 = aa << 32;
    অন্যথা যদি (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    অন্যথা যদি (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        যখন (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } অন্যথা
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    ফেরত x.f;
}

long দ্বিগুণ __extenddftf2(দ্বিগুণ f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    যদি (!(a << 1))
        x.x1 = a;
    অন্যথা যদি (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    অন্যথা যদি (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        যখন (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } অন্যথা
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    ফেরত x.f;
}

দশমিক __trunctfsf2(long দ্বিগুণ f)
{
    u128_t mnt;
    int32_t exp;
    পূর্ণসংখ্যা sgn;
    u32_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    যদি (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    অন্যথা যদি (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    অন্যথা যদি (exp < 16233)
        x = (uint32_t)sgn << 31;
    অন্যথা {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        যদি (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        যদি ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#undef x
    ফেরত x.f;
}

দ্বিগুণ __trunctfdf2(long দ্বিগুণ f)
{
    u128_t mnt;
    int32_t exp;
    পূর্ণসংখ্যা sgn;
    u64_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    যদি (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    অন্যথা যদি (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    অন্যথা যদি (exp < 15308)
        x = (uint64_t)sgn << 63;
    অন্যথা {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        যদি (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        যদি ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#undef x
    ফেরত x.f;
}

int32_t __fixtfsi(long দ্বিগুণ fa)
{
    u128_t a;
    int32_t a_exp;
    পূর্ণসংখ্যা a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    যদি (a_exp < 16369)
        ফেরত 0;
    যদি (a_exp > 16413)
        ফেরত a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    ফেরত a_sgn ? -x : x;
}

int64_t __fixtfdi(long দ্বিগুণ fa)
{
    u128_t a;
    int32_t a_exp;
    পূর্ণসংখ্যা a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    যদি (a_exp < 16383)
        ফেরত 0;
    যদি (a_exp > 16445)
        ফেরত a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    ফেরত a_sgn ? -x : x;
}

uint32_t __fixunstfsi(long দ্বিগুণ fa)
{
    u128_t a;
    int32_t a_exp;
    পূর্ণসংখ্যা a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    যদি (a_sgn || a_exp < 16369)
        ফেরত 0;
    যদি (a_exp > 16414)
        ফেরত -1;
    ফেরত a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(long দ্বিগুণ fa)
{
    u128_t a;
    int32_t a_exp;
    পূর্ণসংখ্যা a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    যদি (a_sgn || a_exp < 16383)
        ফেরত 0;
    যদি (a_exp > 16446)
        ফেরত -1;
    ফেরত (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

long দ্বিগুণ __floatsitf(int32_t a)
{
    পূর্ণসংখ্যা sgn = 0;
    পূর্ণসংখ্যা exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    পূর্ণসংখ্যা i;
    যদি (a) {
        যদি (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        জন্য (i = 16; i; i >>= 1)
            যদি (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    ফেরত x.f;
}

long দ্বিগুণ __floatditf(int64_t a)
{
    পূর্ণসংখ্যা sgn = 0;
    পূর্ণসংখ্যা exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    পূর্ণসংখ্যা i;
    যদি (a) {
        যদি (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        জন্য (i = 32; i; i >>= 1)
            যদি (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    ফেরত x.f;
}

long দ্বিগুণ __floatunsitf(uint32_t a)
{
    পূর্ণসংখ্যা exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    পূর্ণসংখ্যা i;
    যদি (a) {
        জন্য (i = 16; i; i >>= 1)
            যদি (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    ফেরত x.f;
}

long দ্বিগুণ __floatunditf(uint64_t a)
{
    পূর্ণসংখ্যা exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    long দ্বিগুণ f;
    পূর্ণসংখ্যা i;
    যদি (a) {
        জন্য (i = 32; i; i >>= 1)
            যদি (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    ফেরত x.f;
}

স্থির পূর্ণসংখ্যা f3_cmp(long দ্বিগুণ fa, long দ্বিগুণ fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    ফেরত (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (পূর্ণসংখ্যা)(b.x1 >> 63) - (পূর্ণসংখ্যা)(a.x1 >> 63) :
            a.x1 < b.x1 ? (পূর্ণসংখ্যা)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (পূর্ণসংখ্যা)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (পূর্ণসংখ্যা)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (পূর্ণসংখ্যা)(a.x1 >> 63 << 1) : 0);
}

পূর্ণসংখ্যা __eqtf2(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত !!f3_cmp(a, b);
}

পূর্ণসংখ্যা __netf2(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত !!f3_cmp(a, b);
}

পূর্ণসংখ্যা __lttf2(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত f3_cmp(a, b);
}

পূর্ণসংখ্যা __letf2(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত f3_cmp(a, b);
}

পূর্ণসংখ্যা __gttf2(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত -f3_cmp(b, a);
}

পূর্ণসংখ্যা __getf2(long দ্বিগুণ a, long দ্বিগুণ b)
{
    ফেরত -f3_cmp(b, a);
}
