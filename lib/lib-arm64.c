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

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ int8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ uint8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಗಿಡ್ಡ int16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ uint16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ uint32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ int64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ uint64_t;
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ {
    ರಚನೆ { uint64_t x0, x1; };
    ದೀರ್ಘ ದ್ವಿಗುಣ f;
} u128_t;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ {
    uint64_t x;
    ದ್ವಿಗುಣ f;
} u64_t;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ {
    uint32_t x;
    ದಶಮಾಂಶ f;
} u32_t;

ಸ್ಥಿರ ದೀರ್ಘ ದ್ವಿಗುಣ f3_zero(ಪೂರ್ಣಾಂಕ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    ಹಿಂತಿರುಗಿ x.f;
}

ಸ್ಥಿರ ದೀರ್ಘ ದ್ವಿಗುಣ f3_infinity(ಪೂರ್ಣಾಂಕ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    ಹಿಂತಿರುಗಿ x.f;
}

ಸ್ಥಿರ ದೀರ್ಘ ದ್ವಿಗುಣ f3_NaN(ಶೂನ್ಯ)
{
#ಆದರೆ 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#ಇಲ್ಲದಿದ್ದರೆ
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ x.f;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ fp3_convert_NaN(ದೀರ್ಘ ದ್ವಿಗುಣ *f, ಪೂರ್ಣಾಂಕ sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    ಹಿಂತಿರುಗಿ 1;
#ವ್ಯಾಖ್ಯಾನಿಸು fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ fp3_detect_NaNs(ದೀರ್ಘ ದ್ವಿಗುಣ *f,
                           ಪೂರ್ಣಾಂಕ a_sgn, ಪೂರ್ಣಾಂಕ a_exp, u128_t *a,
                           ಪೂರ್ಣಾಂಕ b_sgn, ಪೂರ್ಣಾಂಕ b_exp, u128_t *b)
#ವ್ಯಾಖ್ಯಾನಿಸು a (*a)
#ವ್ಯಾಖ್ಯಾನಿಸು b (*b)
{
#ಆದರೆ 0
    // Detect signalling NaNs:
    ಆದರೆ (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        ಹಿಂತಿರುಗಿ fp3_convert_NaN(f, a_sgn, a);
    ಆದರೆ (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        ಹಿಂತಿರುಗಿ fp3_convert_NaN(f, b_sgn, b);
#ಆದರೆ_ಅಂತ್ಯ
    // Detect quiet NaNs:
    ಆದರೆ (a_exp == 32767 && (a.x0 | a.x1 << 16))
        ಹಿಂತಿರುಗಿ fp3_convert_NaN(f, a_sgn, a);
    ಆದರೆ (b_exp == 32767 && (b.x0 | b.x1 << 16))
        ಹಿಂತಿರುಗಿ fp3_convert_NaN(f, b_sgn, b);

    ಹಿಂತಿರುಗಿ 0;
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು a
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು b
#ವ್ಯಾಖ್ಯಾನಿಸು fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

ಸ್ಥಿರ ಶೂನ್ಯ f3_unpack(ಪೂರ್ಣಾಂಕ *sgn, int32_t *ಘಾತಾಂಕ, u128_t *mnt, ದೀರ್ಘ ದ್ವಿಗುಣ f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *ಘಾತಾಂಕ = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    ಆದರೆ (*ಘಾತಾಂಕ)
        x.x1 |= (uint64_t)1 << 48;
    ಇಲ್ಲದಿದ್ದರೆ
        *ಘಾತಾಂಕ = 1;
    mnt->f = x.f;
}

ಸ್ಥಿರ ಶೂನ್ಯ f3_normalise(int32_t *ಘಾತಾಂಕ, u128_t *mnt)
{
    ಪೂರ್ಣಾಂಕ sh;
    ಆದರೆ (!(mnt->x0 | mnt->x1))
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *ಘಾತಾಂಕ -= 64;
    }
    ಗಾಗಿ (sh = 32; sh; sh >>= 1) {
        ಆದರೆ (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *ಘಾತಾಂಕ -= sh;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ f3_sticky_ಸರಿಸು(int32_t sh, u128_t *x)
{
  ಆದರೆ (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      ಹಿಂತಿರುಗಿ;
  }
  ಆದರೆ (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  ಆದರೆ (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

ಸ್ಥಿರ ದೀರ್ಘ ದ್ವಿಗುಣ f3_ಸುತ್ತು(ಪೂರ್ಣಾಂಕ sgn, int32_t ಘಾತಾಂಕ, u128_t *x)
{
    ದೀರ್ಘ ದ್ವಿಗುಣ f;
    ಪೂರ್ಣಾಂಕ error;

    ಆದರೆ (ಘಾತಾಂಕ > 0) {
        f3_sticky_ಸರಿಸು(13, x);
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        f3_sticky_ಸರಿಸು(14 - ಘಾತಾಂಕ, x);
        ಘಾತಾಂಕ = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    ಆದರೆ (error == 3 || ((error == 2) & (x->x0 & 1))) {
        ಆದರೆ (!++x->x0) {
            ++x->x1;
            ಆದರೆ (x->x1 == (uint64_t)1 << 48)
                ಘಾತಾಂಕ = 1;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x->x1 == (uint64_t)1 << 49) {
                ++ಘಾತಾಂಕ;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    ಆದರೆ (ಘಾತಾಂಕ >= 32767)
        ಹಿಂತಿರುಗಿ f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)ಘಾತಾಂಕ << 48 | (uint64_t)sgn << 63;
    ಹಿಂತಿರುಗಿ x->f;
}

ಸ್ಥಿರ ದೀರ್ಘ ದ್ವಿಗುಣ f3_ಕೂಡಿಸು(ದೀರ್ಘ ದ್ವಿಗುಣ fa, ದೀರ್ಘ ದ್ವಿಗುಣ fb, ಪೂರ್ಣಾಂಕ neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ಪೂರ್ಣಾಂಕ a_sgn, b_sgn, x_sgn;
    ದೀರ್ಘ ದ್ವಿಗುಣ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ಆದರೆ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ಹಿಂತಿರುಗಿ fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    ಆದರೆ (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        ಹಿಂತಿರುಗಿ f3_NaN();
    ಆದರೆ (a_exp == 32767)
        ಹಿಂತಿರುಗಿ f3_infinity(a_sgn);
    ಆದರೆ (b_exp == 32767)
        ಹಿಂತಿರುಗಿ f3_infinity(b_sgn);
    ಆದರೆ (!(a.x0 | a.x1 | b.x0 | b.x1))
        ಹಿಂತಿರುಗಿ f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    ಆದರೆ (a_exp <= b_exp) {
        f3_sticky_ಸರಿಸು(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        f3_sticky_ಸರಿಸು(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    ಆದರೆ (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        ಆದರೆ (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    ಆದರೆ (!(x.x0 | x.x1))
        ಹಿಂತಿರುಗಿ f3_zero(0);

    f3_normalise(&x_exp, &x);

    ಹಿಂತಿರುಗಿ f3_ಸುತ್ತು(x_sgn, x_exp + 12, &x);
}

ದೀರ್ಘ ದ್ವಿಗುಣ __addtf3(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ f3_ಕೂಡಿಸು(a, b, 0);
}

ದೀರ್ಘ ದ್ವಿಗುಣ __subtf3(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ f3_ಕೂಡಿಸು(a, b, 1);
}

ದೀರ್ಘ ದ್ವಿಗುಣ __multf3(ದೀರ್ಘ ದ್ವಿಗುಣ fa, ದೀರ್ಘ ದ್ವಿಗುಣ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ಪೂರ್ಣಾಂಕ a_sgn, b_sgn, x_sgn;
    ದೀರ್ಘ ದ್ವಿಗುಣ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ಆದರೆ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ಹಿಂತಿರುಗಿ fx;

    // Handle infinities and zeroes:
    ಆದರೆ ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        ಹಿಂತಿರುಗಿ f3_NaN();
    ಆದರೆ (a_exp == 32767 || b_exp == 32767)
        ಹಿಂತಿರುಗಿ f3_infinity(a_sgn ^ b_sgn);
    ಆದರೆ (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        ಹಿಂತಿರುಗಿ f3_zero(a_sgn ^ b_sgn);

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
        ಆದರೆ (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    ಹಿಂತಿರುಗಿ f3_ಸುತ್ತು(x_sgn, x_exp, &x);
}

ದೀರ್ಘ ದ್ವಿಗುಣ __divtf3(ದೀರ್ಘ ದ್ವಿಗುಣ fa, ದೀರ್ಘ ದ್ವಿಗುಣ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ಪೂರ್ಣಾಂಕ a_sgn, b_sgn, x_sgn, i;
    ದೀರ್ಘ ದ್ವಿಗುಣ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ಆದರೆ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ಹಿಂತಿರುಗಿ fx;

    // Handle infinities and zeroes:
    ಆದರೆ ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        ಹಿಂತಿರುಗಿ f3_NaN();
    ಆದರೆ (a_exp == 32767 || !(b.x0 | b.x1))
        ಹಿಂತಿರುಗಿ f3_infinity(a_sgn ^ b_sgn);
    ಆದರೆ (!(a.x0 | a.x1) || b_exp == 32767)
        ಹಿಂತಿರುಗಿ f3_zero(a_sgn ^ b_sgn);

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
    ಗಾಗಿ (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        ಆದರೆ (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    ಹಿಂತಿರುಗಿ f3_ಸುತ್ತು(x_sgn, x_exp, &x);
}

ದೀರ್ಘ ದ್ವಿಗುಣ __negtf2(ದೀರ್ಘ ದ್ವಿಗುಣ f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    ಹಿಂತಿರುಗಿ f;
}

ದೀರ್ಘ ದ್ವಿಗುಣ __extendsftf2(ದಶಮಾಂಶ f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    ಆದರೆ (!(a << 1))
        x.x1 = aa << 32;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        ಆಗ (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } ಇಲ್ಲದಿದ್ದರೆ
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    ಹಿಂತಿರುಗಿ x.f;
}

ದೀರ್ಘ ದ್ವಿಗುಣ __extenddftf2(ದ್ವಿಗುಣ f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    ಆದರೆ (!(a << 1))
        x.x1 = a;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        ಆಗ (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } ಇಲ್ಲದಿದ್ದರೆ
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    ಹಿಂತಿರುಗಿ x.f;
}

ದಶಮಾಂಶ __trunctfsf2(ದೀರ್ಘ ದ್ವಿಗುಣ f)
{
    u128_t mnt;
    int32_t ಘಾತಾಂಕ;
    ಪೂರ್ಣಾಂಕ sgn;
    u32_t x;
#ವ್ಯಾಖ್ಯಾನಿಸು x x.x

    f3_unpack(&sgn, &ಘಾತಾಂಕ, &mnt, f);
    ಆದರೆ (ಘಾತಾಂಕ == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ < 16233)
        x = (uint32_t)sgn << 31;
    ಇಲ್ಲದಿದ್ದರೆ {
        ಘಾತಾಂಕ -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        ಆದರೆ (ಘಾತಾಂಕ < 0) {
            x = x >> -ಘಾತಾಂಕ | !!(x << (32 + ಘಾತಾಂಕ));
            ಘಾತಾಂಕ = 0;
        }
        ಆದರೆ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (ಘಾತಾಂಕ << 23)) | (uint32_t)sgn << 31;
    }
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು x
    ಹಿಂತಿರುಗಿ x.f;
}

ದ್ವಿಗುಣ __trunctfdf2(ದೀರ್ಘ ದ್ವಿಗುಣ f)
{
    u128_t mnt;
    int32_t ಘಾತಾಂಕ;
    ಪೂರ್ಣಾಂಕ sgn;
    u64_t x;
#ವ್ಯಾಖ್ಯಾನಿಸು x x.x

    f3_unpack(&sgn, &ಘಾತಾಂಕ, &mnt, f);
    ಆದರೆ (ಘಾತಾಂಕ == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ < 15308)
        x = (uint64_t)sgn << 63;
    ಇಲ್ಲದಿದ್ದರೆ {
        ಘಾತಾಂಕ -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        ಆದರೆ (ಘಾತಾಂಕ < 0) {
            x = x >> -ಘಾತಾಂಕ | !!(x << (64 + ಘಾತಾಂಕ));
            ಘಾತಾಂಕ = 0;
        }
        ಆದರೆ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)ಘಾತಾಂಕ << 52)) | (uint64_t)sgn << 63;
    }
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು x
    ಹಿಂತಿರುಗಿ x.f;
}

int32_t __fixtfsi(ದೀರ್ಘ ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಂಕ a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಆದರೆ (a_exp < 16369)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (a_exp > 16413)
        ಹಿಂತಿರುಗಿ a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    ಹಿಂತಿರುಗಿ a_sgn ? -x : x;
}

int64_t __fixtfdi(ದೀರ್ಘ ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಂಕ a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಆದರೆ (a_exp < 16383)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (a_exp > 16445)
        ಹಿಂತಿರುಗಿ a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    ಹಿಂತಿರುಗಿ a_sgn ? -x : x;
}

uint32_t __fixunstfsi(ದೀರ್ಘ ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಂಕ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಆದರೆ (a_sgn || a_exp < 16369)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (a_exp > 16414)
        ಹಿಂತಿರುಗಿ -1;
    ಹಿಂತಿರುಗಿ a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(ದೀರ್ಘ ದ್ವಿಗುಣ fa)
{
    u128_t a;
    int32_t a_exp;
    ಪೂರ್ಣಾಂಕ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ಆದರೆ (a_sgn || a_exp < 16383)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (a_exp > 16446)
        ಹಿಂತಿರುಗಿ -1;
    ಹಿಂತಿರುಗಿ (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

ದೀರ್ಘ ದ್ವಿಗುಣ __floatsitf(int32_t a)
{
    ಪೂರ್ಣಾಂಕ sgn = 0;
    ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ಪೂರ್ಣಾಂಕ i;
    ಆದರೆ (a) {
        ಆದರೆ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        ಗಾಗಿ (i = 16; i; i >>= 1)
            ಆದರೆ (!(mnt >> (32 - i))) {
                mnt <<= i;
                ಘಾತಾಂಕ -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)ಘಾತಾಂಕ << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    ಹಿಂತಿರುಗಿ x.f;
}

ದೀರ್ಘ ದ್ವಿಗುಣ __floatditf(int64_t a)
{
    ಪೂರ್ಣಾಂಕ sgn = 0;
    ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    ಪೂರ್ಣಾಂಕ i;
    ಆದರೆ (a) {
        ಆದರೆ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        ಗಾಗಿ (i = 32; i; i >>= 1)
            ಆದರೆ (!(mnt >> (64 - i))) {
                mnt <<= i;
                ಘಾತಾಂಕ -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)ಘಾತಾಂಕ << 48 | mnt << 1 >> 16;
    }
    ಹಿಂತಿರುಗಿ x.f;
}

ದೀರ್ಘ ದ್ವಿಗುಣ __floatunsitf(uint32_t a)
{
    ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ಪೂರ್ಣಾಂಕ i;
    ಆದರೆ (a) {
        ಗಾಗಿ (i = 16; i; i >>= 1)
            ಆದರೆ (!(mnt >> (32 - i))) {
                mnt <<= i;
                ಘಾತಾಂಕ -= i;
            }
        x.x1 = (uint64_t)ಘಾತಾಂಕ << 48 | (uint64_t)(mnt << 1) << 16;
    }
    ಹಿಂತಿರುಗಿ x.f;
}

ದೀರ್ಘ ದ್ವಿಗುಣ __floatunditf(uint64_t a)
{
    ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    ದೀರ್ಘ ದ್ವಿಗುಣ f;
    ಪೂರ್ಣಾಂಕ i;
    ಆದರೆ (a) {
        ಗಾಗಿ (i = 32; i; i >>= 1)
            ಆದರೆ (!(mnt >> (64 - i))) {
                mnt <<= i;
                ಘಾತಾಂಕ -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)ಘಾತಾಂಕ << 48 | mnt << 1 >> 16;
    }
    ಹಿಂತಿರುಗಿ x.f;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ f3_cmp(ದೀರ್ಘ ದ್ವಿಗುಣ fa, ದೀರ್ಘ ದ್ವಿಗುಣ fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    ಹಿಂತಿರುಗಿ (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (ಪೂರ್ಣಾಂಕ)(b.x1 >> 63) - (ಪೂರ್ಣಾಂಕ)(a.x1 >> 63) :
            a.x1 < b.x1 ? (ಪೂರ್ಣಾಂಕ)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (ಪೂರ್ಣಾಂಕ)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (ಪೂರ್ಣಾಂಕ)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (ಪೂರ್ಣಾಂಕ)(a.x1 >> 63 << 1) : 0);
}

ಪೂರ್ಣಾಂಕ __eqtf2(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ !!f3_cmp(a, b);
}

ಪೂರ್ಣಾಂಕ __netf2(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ !!f3_cmp(a, b);
}

ಪೂರ್ಣಾಂಕ __lttf2(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ f3_cmp(a, b);
}

ಪೂರ್ಣಾಂಕ __letf2(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ f3_cmp(a, b);
}

ಪೂರ್ಣಾಂಕ __gttf2(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ -f3_cmp(b, a);
}

ಪೂರ್ಣಾಂಕ __getf2(ದೀರ್ಘ ದ್ವಿಗುಣ a, ದೀರ್ಘ ದ್ವಿಗುಣ b)
{
    ಹಿಂತಿರುಗಿ -f3_cmp(b, a);
}
