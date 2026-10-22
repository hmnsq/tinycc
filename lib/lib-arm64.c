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
ಪ್ರಕಾರನಿರ್ದೇಶ signed ವರ್ಣ int8_t;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ವರ್ಣ uint8_t;
ಪ್ರಕಾರನಿರ್ದೇಶ short int16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short uint16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int32_t;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned uint32_t;
ಪ್ರಕಾರನಿರ್ದೇಶ long long int64_t;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long long uint64_t;
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ {
    ಸಂರಚನಾ { uint64_t x0, x1; };
    long ದ್ವಿಗುಣ f;
} u128_t;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ {
    uint64_t x;
    ದ್ವಿಗುಣ f;
} u64_t;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ {
    uint32_t x;
    ಭಿನ್ನ f;
} u32_t;

ಸ್ಥಿರ long ದ್ವಿಗುಣ f3_zero(ಪೂರ್ಣಾಙ್ಕ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    ಪ್ರತ್ಯಾಗಮ x.f;
}

ಸ್ಥಿರ long ದ್ವಿಗುಣ f3_infinity(ಪೂರ್ಣಾಙ್ಕ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    ಪ್ರತ್ಯಾಗಮ x.f;
}

ಸ್ಥಿರ long ದ್ವಿಗುಣ f3_NaN(ಶೂನ್ಯ)
{
#ಯದಿ 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#ಅನ್ಯಥಾ
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#endif
    ಪ್ರತ್ಯಾಗಮ x.f;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ fp3_convert_NaN(long ದ್ವಿಗುಣ *f, ಪೂರ್ಣಾಙ್ಕ sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    ಪ್ರತ್ಯಾಗಮ 1;
#define fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ fp3_detect_NaNs(long ದ್ವಿಗುಣ *f,
                           ಪೂರ್ಣಾಙ್ಕ a_sgn, ಪೂರ್ಣಾಙ್ಕ a_exp, u128_t *a,
                           ಪೂರ್ಣಾಙ್ಕ b_sgn, ಪೂರ್ಣಾಙ್ಕ b_exp, u128_t *b)
#define a (*a)
#define b (*b)
{
#ಯದಿ 0
    // Detect signalling NaNs:
    ಯದಿ (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        ಪ್ರತ್ಯಾಗಮ fp3_convert_NaN(f, a_sgn, a);
    ಯದಿ (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        ಪ್ರತ್ಯಾಗಮ fp3_convert_NaN(f, b_sgn, b);
#endif
    // Detect quiet NaNs:
    ಯದಿ (a_exp == 32767 && (a.x0 | a.x1 << 16))
        ಪ್ರತ್ಯಾಗಮ fp3_convert_NaN(f, a_sgn, a);
    ಯದಿ (b_exp == 32767 && (b.x0 | b.x1 << 16))
        ಪ್ರತ್ಯಾಗಮ fp3_convert_NaN(f, b_sgn, b);

    ಪ್ರತ್ಯಾಗಮ 0;
#undef a
#undef b
#define fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

ಸ್ಥಿರ ಶೂನ್ಯ f3_unpack(ಪೂರ್ಣಾಙ್ಕ *sgn, int32_t *exp, u128_t *mnt, long ದ್ವಿಗುಣ f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    ಯದಿ (*exp)
        x.x1 |= (uint64_t)1 << 48;
    ಅನ್ಯಥಾ
        *exp = 1;
    mnt->f = x.f;
}

ಸ್ಥಿರ ಶೂನ್ಯ f3_normalise(int32_t *exp, u128_t *mnt)
{
    ಪೂರ್ಣಾಙ್ಕ sh;
    ಯದಿ (!(mnt->x0 | mnt->x1))
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    ಪ್ರತಿ (sh = 32; sh; sh >>= 1) {
        ಯದಿ (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ f3_sticky_shift(int32_t sh, u128_t *x)
{
  ಯದಿ (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      ಪ್ರತ್ಯಾಗಮ;
  }
  ಯದಿ (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  ಯದಿ (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

ಸ್ಥಿರ long ದ್ವಿಗುಣ f3_round(ಪೂರ್ಣಾಙ್ಕ sgn, int32_t exp, u128_t *x)
{
    long ದ್ವಿಗುಣ f;
    ಪೂರ್ಣಾಙ್ಕ error;

    ಯದಿ (exp > 0) {
        f3_sticky_shift(13, x);
    }
    ಅನ್ಯಥಾ {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    ಯದಿ (error == 3 || ((error == 2) & (x->x0 & 1))) {
        ಯದಿ (!++x->x0) {
            ++x->x1;
            ಯದಿ (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            ಅನ್ಯಥಾ ಯದಿ (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    ಯದಿ (exp >= 32767)
        ಪ್ರತ್ಯಾಗಮ f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    ಪ್ರತ್ಯಾಗಮ x->f;
}

ಸ್ಥಿರ long ದ್ವಿಗುಣ f3_add(long ದ್ವಿಗುಣ fa, long ದ್ವಿಗುಣ fb, ಪೂರ್ಣಾಙ್ಕ neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ಪೂರ್ಣಾಙ್ಕ a_sgn, b_sgn, x_sgn;
    long ದ್ವಿಗುಣ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ಯದಿ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ಪ್ರತ್ಯಾಗಮ fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    ಯದಿ (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        ಪ್ರತ್ಯಾಗಮ f3_NaN();
    ಯದಿ (a_exp == 32767)
        ಪ್ರತ್ಯಾಗಮ f3_infinity(a_sgn);
    ಯದಿ (b_exp == 32767)
        ಪ್ರತ್ಯಾಗಮ f3_infinity(b_sgn);
    ಯದಿ (!(a.x0 | a.x1 | b.x0 | b.x1))
        ಪ್ರತ್ಯಾಗಮ f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    ಯದಿ (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    ಅನ್ಯಥಾ {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    ಯದಿ (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    ಅನ್ಯಥಾ {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        ಯದಿ (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    ಯದಿ (!(x.x0 | x.x1))
        ಪ್ರತ್ಯಾಗಮ f3_zero(0);

    f3_normalise(&x_exp, &x);

    ಪ್ರತ್ಯಾಗಮ f3_round(x_sgn, x_exp + 12, &x);
}

long ದ್ವಿಗುಣ __addtf3(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ f3_add(a, b, 0);
}

long ದ್ವಿಗುಣ __subtf3(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ f3_add(a, b, 1);
}

long ದ್ವಿಗುಣ __multf3(long ದ್ವಿಗುಣ fa, long ದ್ವಿಗುಣ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ಪೂರ್ಣಾಙ್ಕ a_sgn, b_sgn, x_sgn;
    long ದ್ವಿಗುಣ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ಯದಿ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ಪ್ರತ್ಯಾಗಮ fx;

    // Handle infinities and zeroes:
    ಯದಿ ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        ಪ್ರತ್ಯಾಗಮ f3_NaN();
    ಯದಿ (a_exp == 32767 || b_exp == 32767)
        ಪ್ರತ್ಯಾಗಮ f3_infinity(a_sgn ^ b_sgn);
    ಯದಿ (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        ಪ್ರತ್ಯಾಗಮ f3_zero(a_sgn ^ b_sgn);

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
        ಯದಿ (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    ಪ್ರತ್ಯಾಗಮ f3_round(x_sgn, x_exp, &x);
}

long ದ್ವಿಗುಣ __divtf3(long ದ್ವಿಗುಣ fa, long ದ್ವಿಗುಣ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ಪೂರ್ಣಾಙ್ಕ a_sgn, b_sgn, x_sgn, i;
    long ದ್ವಿಗುಣ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ಯದಿ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ಪ್ರತ್ಯಾಗಮ fx;

    // Handle infinities and zeroes:
    ಯದಿ ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        ಪ್ರತ್ಯಾಗಮ f3_NaN();
    ಯದಿ (a_exp == 32767 || !(b.x0 | b.x1))
        ಪ್ರತ್ಯಾಗಮ f3_infinity(a_sgn ^ b_sgn);
    ಯದಿ (!(a.x0 | a.x1) || b_exp == 32767)
        ಪ್ರತ್ಯಾಗಮ f3_zero(a_sgn ^ b_sgn);

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
    ಪ್ರತಿ (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        ಯದಿ (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    ಪ್ರತ್ಯಾಗಮ f3_round(x_sgn, x_exp, &x);
}

long ದ್ವಿಗುಣ __negtf2(long ದ್ವಿಗುಣ f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    ಪ್ರತ್ಯಾಗಮ f;
}

long ದ್ವಿಗುಣ __extendsftf2(ಭಿನ್ನ f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    ಯದಿ (!(a << 1))
        x.x1 = aa << 32;
    ಅನ್ಯಥಾ ಯದಿ (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    ಅನ್ಯಥಾ ಯದಿ (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        ಯಾವತ್ (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } ಅನ್ಯಥಾ
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    ಪ್ರತ್ಯಾಗಮ x.f;
}

long ದ್ವಿಗುಣ __extenddftf2(ದ್ವಿಗುಣ f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    ಯದಿ (!(a << 1))
        x.x1 = a;
    ಅನ್ಯಥಾ ಯದಿ (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    ಅನ್ಯಥಾ ಯದಿ (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        ಯಾವತ್ (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } ಅನ್ಯಥಾ
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    ಪ್ರತ್ಯಾಗಮ x.f;
}

ಭಿನ್ನ __trunctfsf2(long ದ್ವಿಗುಣ f)
{
    u128_t mnt;
    int32_t exp;
    ಪೂರ್ಣಾಙ್ಕ sgn;
    u32_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    ಯದಿ (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    ಅನ್ಯಥಾ ಯದಿ (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    ಅನ್ಯಥಾ ಯದಿ (exp < 16233)
        x = (uint32_t)sgn << 31;
    ಅನ್ಯಥಾ {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        ಯದಿ (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        ಯದಿ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#undef x
    ಪ್ರತ್ಯಾಗಮ x.f;
}

ದ್ವಿಗುಣ __trunctfdf2(long ದ್ವಿಗುಣ f)
{
    u128_t mnt;
    int32_t exp;
    ಪೂರ್ಣಾಙ್ಕ sgn;
    u64_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    ಯದಿ (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    ಅನ್ಯಥಾ ಯದಿ (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    ಅನ್ಯಥಾ ಯದಿ (exp < 15308)
        x = (uint64_t)sgn << 63;
    ಅನ್ಯಥಾ {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        ಯದಿ (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        ಯದಿ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#undef x
    ಪ್ರತ್ಯಾಗಮ x.f;
}

int32_t __fixtfsi(long ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಙ್ಕ a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಯದಿ (a_exp < 16369)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (a_exp > 16413)
        ಪ್ರತ್ಯಾಗಮ a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    ಪ್ರತ್ಯಾಗಮ a_sgn ? -x : x;
}

int64_t __fixtfdi(long ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಙ್ಕ a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಯದಿ (a_exp < 16383)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (a_exp > 16445)
        ಪ್ರತ್ಯಾಗಮ a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    ಪ್ರತ್ಯಾಗಮ a_sgn ? -x : x;
}

uint32_t __fixunstfsi(long ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಙ್ಕ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಯದಿ (a_sgn || a_exp < 16369)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (a_exp > 16414)
        ಪ್ರತ್ಯಾಗಮ -1;
    ಪ್ರತ್ಯಾಗಮ a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(long ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಙ್ಕ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಯದಿ (a_sgn || a_exp < 16383)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (a_exp > 16446)
        ಪ್ರತ್ಯಾಗಮ -1;
    ಪ್ರತ್ಯಾಗಮ (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

long ದ್ವಿಗುಣ __floatsitf(int32_t a)
{
    ಪೂರ್ಣಾಙ್ಕ sgn = 0;
    ಪೂರ್ಣಾಙ್ಕ exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ಪೂರ್ಣಾಙ್ಕ i;
    ಯದಿ (a) {
        ಯದಿ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        ಪ್ರತಿ (i = 16; i; i >>= 1)
            ಯದಿ (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    ಪ್ರತ್ಯಾಗಮ x.f;
}

long ದ್ವಿಗುಣ __floatditf(int64_t a)
{
    ಪೂರ್ಣಾಙ್ಕ sgn = 0;
    ಪೂರ್ಣಾಙ್ಕ exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    ಪೂರ್ಣಾಙ್ಕ i;
    ಯದಿ (a) {
        ಯದಿ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        ಪ್ರತಿ (i = 32; i; i >>= 1)
            ಯದಿ (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    ಪ್ರತ್ಯಾಗಮ x.f;
}

long ದ್ವಿಗುಣ __floatunsitf(uint32_t a)
{
    ಪೂರ್ಣಾಙ್ಕ exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ಪೂರ್ಣಾಙ್ಕ i;
    ಯದಿ (a) {
        ಪ್ರತಿ (i = 16; i; i >>= 1)
            ಯದಿ (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    ಪ್ರತ್ಯಾಗಮ x.f;
}

long ದ್ವಿಗುಣ __floatunditf(uint64_t a)
{
    ಪೂರ್ಣಾಙ್ಕ exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    long ದ್ವಿಗುಣ f;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಯದಿ (a) {
        ಪ್ರತಿ (i = 32; i; i >>= 1)
            ಯದಿ (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    ಪ್ರತ್ಯಾಗಮ x.f;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ f3_cmp(long ದ್ವಿಗುಣ fa, long ದ್ವಿಗುಣ fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    ಪ್ರತ್ಯಾಗಮ (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (ಪೂರ್ಣಾಙ್ಕ)(b.x1 >> 63) - (ಪೂರ್ಣಾಙ್ಕ)(a.x1 >> 63) :
            a.x1 < b.x1 ? (ಪೂರ್ಣಾಙ್ಕ)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (ಪೂರ್ಣಾಙ್ಕ)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (ಪೂರ್ಣಾಙ್ಕ)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (ಪೂರ್ಣಾಙ್ಕ)(a.x1 >> 63 << 1) : 0);
}

ಪೂರ್ಣಾಙ್ಕ __eqtf2(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ !!f3_cmp(a, b);
}

ಪೂರ್ಣಾಙ್ಕ __netf2(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ !!f3_cmp(a, b);
}

ಪೂರ್ಣಾಙ್ಕ __lttf2(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ f3_cmp(a, b);
}

ಪೂರ್ಣಾಙ್ಕ __letf2(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ f3_cmp(a, b);
}

ಪೂರ್ಣಾಙ್ಕ __gttf2(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ -f3_cmp(b, a);
}

ಪೂರ್ಣಾಙ್ಕ __getf2(long ದ್ವಿಗುಣ a, long ದ್ವಿಗುಣ b)
{
    ಪ್ರತ್ಯಾಗಮ -f3_cmp(b, a);
}
