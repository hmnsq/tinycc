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

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ int8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ uint8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਛੋਟਾ int16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ uint16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ uint32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ int64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ uint64_t;
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ {
    ਬਣਤਰ { uint64_t x0, x1; };
    ਲੰਮਾ ਦੁੱਗਣਾ f;
} u128_t;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ {
    uint64_t x;
    ਦੁੱਗਣਾ f;
} u64_t;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ {
    uint32_t x;
    ਦਸ਼ਮਲਵ f;
} u32_t;

ਸਥਿਰ ਲੰਮਾ ਦੁੱਗਣਾ f3_zero(ਪੂਰਨ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    ਵਾਪਸ x.f;
}

ਸਥਿਰ ਲੰਮਾ ਦੁੱਗਣਾ f3_infinity(ਪੂਰਨ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    ਵਾਪਸ x.f;
}

ਸਥਿਰ ਲੰਮਾ ਦੁੱਗਣਾ f3_NaN(ਖਾਲੀ)
{
#ਜੇ 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#ਨਹੀਂਤਾਂ
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#ਜੇ_ਅੰਤ
    ਵਾਪਸ x.f;
}

ਸਥਿਰ ਪੂਰਨ fp3_convert_NaN(ਲੰਮਾ ਦੁੱਗਣਾ *f, ਪੂਰਨ sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    ਵਾਪਸ 1;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

ਸਥਿਰ ਪੂਰਨ fp3_detect_NaNs(ਲੰਮਾ ਦੁੱਗਣਾ *f,
                           ਪੂਰਨ a_sgn, ਪੂਰਨ a_exp, u128_t *a,
                           ਪੂਰਨ b_sgn, ਪੂਰਨ b_exp, u128_t *b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ a (*a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ b (*b)
{
#ਜੇ 0
    // Detect signalling NaNs:
    ਜੇ (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        ਵਾਪਸ fp3_convert_NaN(f, a_sgn, a);
    ਜੇ (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        ਵਾਪਸ fp3_convert_NaN(f, b_sgn, b);
#ਜੇ_ਅੰਤ
    // Detect quiet NaNs:
    ਜੇ (a_exp == 32767 && (a.x0 | a.x1 << 16))
        ਵਾਪਸ fp3_convert_NaN(f, a_sgn, a);
    ਜੇ (b_exp == 32767 && (b.x0 | b.x1 << 16))
        ਵਾਪਸ fp3_convert_NaN(f, b_sgn, b);

    ਵਾਪਸ 0;
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ a
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

ਸਥਿਰ ਖਾਲੀ f3_unpack(ਪੂਰਨ *sgn, int32_t *ਘਾਤਾਂਕ, u128_t *mnt, ਲੰਮਾ ਦੁੱਗਣਾ f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *ਘਾਤਾਂਕ = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    ਜੇ (*ਘਾਤਾਂਕ)
        x.x1 |= (uint64_t)1 << 48;
    ਨਹੀਂਤਾਂ
        *ਘਾਤਾਂਕ = 1;
    mnt->f = x.f;
}

ਸਥਿਰ ਖਾਲੀ f3_normalise(int32_t *ਘਾਤਾਂਕ, u128_t *mnt)
{
    ਪੂਰਨ sh;
    ਜੇ (!(mnt->x0 | mnt->x1))
        ਵਾਪਸ;
    ਜੇ (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *ਘਾਤਾਂਕ -= 64;
    }
    ਲਈ (sh = 32; sh; sh >>= 1) {
        ਜੇ (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *ਘਾਤਾਂਕ -= sh;
        }
    }
}

ਸਥਿਰ ਖਾਲੀ f3_sticky_ਖਿਸਕਾਓ(int32_t sh, u128_t *x)
{
  ਜੇ (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      ਵਾਪਸ;
  }
  ਜੇ (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  ਜੇ (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

ਸਥਿਰ ਲੰਮਾ ਦੁੱਗਣਾ f3_ਗੇੜਾ(ਪੂਰਨ sgn, int32_t ਘਾਤਾਂਕ, u128_t *x)
{
    ਲੰਮਾ ਦੁੱਗਣਾ f;
    ਪੂਰਨ error;

    ਜੇ (ਘਾਤਾਂਕ > 0) {
        f3_sticky_ਖਿਸਕਾਓ(13, x);
    }
    ਨਹੀਂਤਾਂ {
        f3_sticky_ਖਿਸਕਾਓ(14 - ਘਾਤਾਂਕ, x);
        ਘਾਤਾਂਕ = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    ਜੇ (error == 3 || ((error == 2) & (x->x0 & 1))) {
        ਜੇ (!++x->x0) {
            ++x->x1;
            ਜੇ (x->x1 == (uint64_t)1 << 48)
                ਘਾਤਾਂਕ = 1;
            ਨਹੀਂਤਾਂ ਜੇ (x->x1 == (uint64_t)1 << 49) {
                ++ਘਾਤਾਂਕ;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    ਜੇ (ਘਾਤਾਂਕ >= 32767)
        ਵਾਪਸ f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)ਘਾਤਾਂਕ << 48 | (uint64_t)sgn << 63;
    ਵਾਪਸ x->f;
}

ਸਥਿਰ ਲੰਮਾ ਦੁੱਗਣਾ f3_ਜੋੜੋ(ਲੰਮਾ ਦੁੱਗਣਾ fa, ਲੰਮਾ ਦੁੱਗਣਾ fb, ਪੂਰਨ neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ਪੂਰਨ a_sgn, b_sgn, x_sgn;
    ਲੰਮਾ ਦੁੱਗਣਾ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ਜੇ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ਵਾਪਸ fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    ਜੇ (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        ਵਾਪਸ f3_NaN();
    ਜੇ (a_exp == 32767)
        ਵਾਪਸ f3_infinity(a_sgn);
    ਜੇ (b_exp == 32767)
        ਵਾਪਸ f3_infinity(b_sgn);
    ਜੇ (!(a.x0 | a.x1 | b.x0 | b.x1))
        ਵਾਪਸ f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    ਜੇ (a_exp <= b_exp) {
        f3_sticky_ਖਿਸਕਾਓ(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    ਨਹੀਂਤਾਂ {
        f3_sticky_ਖਿਸਕਾਓ(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    ਜੇ (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    ਨਹੀਂਤਾਂ {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        ਜੇ (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    ਜੇ (!(x.x0 | x.x1))
        ਵਾਪਸ f3_zero(0);

    f3_normalise(&x_exp, &x);

    ਵਾਪਸ f3_ਗੇੜਾ(x_sgn, x_exp + 12, &x);
}

ਲੰਮਾ ਦੁੱਗਣਾ __addtf3(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ f3_ਜੋੜੋ(a, b, 0);
}

ਲੰਮਾ ਦੁੱਗਣਾ __subtf3(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ f3_ਜੋੜੋ(a, b, 1);
}

ਲੰਮਾ ਦੁੱਗਣਾ __multf3(ਲੰਮਾ ਦੁੱਗਣਾ fa, ਲੰਮਾ ਦੁੱਗਣਾ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ਪੂਰਨ a_sgn, b_sgn, x_sgn;
    ਲੰਮਾ ਦੁੱਗਣਾ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ਜੇ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ਵਾਪਸ fx;

    // Handle infinities and zeroes:
    ਜੇ ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        ਵਾਪਸ f3_NaN();
    ਜੇ (a_exp == 32767 || b_exp == 32767)
        ਵਾਪਸ f3_infinity(a_sgn ^ b_sgn);
    ਜੇ (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        ਵਾਪਸ f3_zero(a_sgn ^ b_sgn);

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
        ਜੇ (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    ਵਾਪਸ f3_ਗੇੜਾ(x_sgn, x_exp, &x);
}

ਲੰਮਾ ਦੁੱਗਣਾ __divtf3(ਲੰਮਾ ਦੁੱਗਣਾ fa, ਲੰਮਾ ਦੁੱਗਣਾ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    ਪੂਰਨ a_sgn, b_sgn, x_sgn, i;
    ਲੰਮਾ ਦੁੱਗਣਾ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ਜੇ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        ਵਾਪਸ fx;

    // Handle infinities and zeroes:
    ਜੇ ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        ਵਾਪਸ f3_NaN();
    ਜੇ (a_exp == 32767 || !(b.x0 | b.x1))
        ਵਾਪਸ f3_infinity(a_sgn ^ b_sgn);
    ਜੇ (!(a.x0 | a.x1) || b_exp == 32767)
        ਵਾਪਸ f3_zero(a_sgn ^ b_sgn);

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
    ਲਈ (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        ਜੇ (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    ਵਾਪਸ f3_ਗੇੜਾ(x_sgn, x_exp, &x);
}

ਲੰਮਾ ਦੁੱਗਣਾ __negtf2(ਲੰਮਾ ਦੁੱਗਣਾ f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    ਵਾਪਸ f;
}

ਲੰਮਾ ਦੁੱਗਣਾ __extendsftf2(ਦਸ਼ਮਲਵ f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    ਜੇ (!(a << 1))
        x.x1 = aa << 32;
    ਨਹੀਂਤਾਂ ਜੇ (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    ਨਹੀਂਤਾਂ ਜੇ (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        ਜਦੋਂ (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } ਨਹੀਂਤਾਂ
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    ਵਾਪਸ x.f;
}

ਲੰਮਾ ਦੁੱਗਣਾ __extenddftf2(ਦੁੱਗਣਾ f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    ਜੇ (!(a << 1))
        x.x1 = a;
    ਨਹੀਂਤਾਂ ਜੇ (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    ਨਹੀਂਤਾਂ ਜੇ (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        ਜਦੋਂ (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } ਨਹੀਂਤਾਂ
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    ਵਾਪਸ x.f;
}

ਦਸ਼ਮਲਵ __trunctfsf2(ਲੰਮਾ ਦੁੱਗਣਾ f)
{
    u128_t mnt;
    int32_t ਘਾਤਾਂਕ;
    ਪੂਰਨ sgn;
    u32_t x;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ x x.x

    f3_unpack(&sgn, &ਘਾਤਾਂਕ, &mnt, f);
    ਜੇ (ਘਾਤਾਂਕ == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ < 16233)
        x = (uint32_t)sgn << 31;
    ਨਹੀਂਤਾਂ {
        ਘਾਤਾਂਕ -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        ਜੇ (ਘਾਤਾਂਕ < 0) {
            x = x >> -ਘਾਤਾਂਕ | !!(x << (32 + ਘਾਤਾਂਕ));
            ਘਾਤਾਂਕ = 0;
        }
        ਜੇ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (ਘਾਤਾਂਕ << 23)) | (uint32_t)sgn << 31;
    }
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ x
    ਵਾਪਸ x.f;
}

ਦੁੱਗਣਾ __trunctfdf2(ਲੰਮਾ ਦੁੱਗਣਾ f)
{
    u128_t mnt;
    int32_t ਘਾਤਾਂਕ;
    ਪੂਰਨ sgn;
    u64_t x;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ x x.x

    f3_unpack(&sgn, &ਘਾਤਾਂਕ, &mnt, f);
    ਜੇ (ਘਾਤਾਂਕ == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ < 15308)
        x = (uint64_t)sgn << 63;
    ਨਹੀਂਤਾਂ {
        ਘਾਤਾਂਕ -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        ਜੇ (ਘਾਤਾਂਕ < 0) {
            x = x >> -ਘਾਤਾਂਕ | !!(x << (64 + ਘਾਤਾਂਕ));
            ਘਾਤਾਂਕ = 0;
        }
        ਜੇ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)ਘਾਤਾਂਕ << 52)) | (uint64_t)sgn << 63;
    }
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ x
    ਵਾਪਸ x.f;
}

int32_t __fixtfsi(ਲੰਮਾ ਦੁੱਗਣਾ fa)
{
    u128_t a;
    int32_t a_exp;
    ਪੂਰਨ a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ਜੇ (a_exp < 16369)
        ਵਾਪਸ 0;
    ਜੇ (a_exp > 16413)
        ਵਾਪਸ a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    ਵਾਪਸ a_sgn ? -x : x;
}

int64_t __fixtfdi(ਲੰਮਾ ਦੁੱਗਣਾ fa)
{
    u128_t a;
    int32_t a_exp;
    ਪੂਰਨ a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ਜੇ (a_exp < 16383)
        ਵਾਪਸ 0;
    ਜੇ (a_exp > 16445)
        ਵਾਪਸ a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    ਵਾਪਸ a_sgn ? -x : x;
}

uint32_t __fixunstfsi(ਲੰਮਾ ਦੁੱਗਣਾ fa)
{
    u128_t a;
    int32_t a_exp;
    ਪੂਰਨ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ਜੇ (a_sgn || a_exp < 16369)
        ਵਾਪਸ 0;
    ਜੇ (a_exp > 16414)
        ਵਾਪਸ -1;
    ਵਾਪਸ a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(ਲੰਮਾ ਦੁੱਗਣਾ fa)
{
    u128_t a;
    int32_t a_exp;
    ਪੂਰਨ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ਜੇ (a_sgn || a_exp < 16383)
        ਵਾਪਸ 0;
    ਜੇ (a_exp > 16446)
        ਵਾਪਸ -1;
    ਵਾਪਸ (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

ਲੰਮਾ ਦੁੱਗਣਾ __floatsitf(int32_t a)
{
    ਪੂਰਨ sgn = 0;
    ਪੂਰਨ ਘਾਤਾਂਕ = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ਪੂਰਨ i;
    ਜੇ (a) {
        ਜੇ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        ਲਈ (i = 16; i; i >>= 1)
            ਜੇ (!(mnt >> (32 - i))) {
                mnt <<= i;
                ਘਾਤਾਂਕ -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)ਘਾਤਾਂਕ << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    ਵਾਪਸ x.f;
}

ਲੰਮਾ ਦੁੱਗਣਾ __floatditf(int64_t a)
{
    ਪੂਰਨ sgn = 0;
    ਪੂਰਨ ਘਾਤਾਂਕ = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    ਪੂਰਨ i;
    ਜੇ (a) {
        ਜੇ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        ਲਈ (i = 32; i; i >>= 1)
            ਜੇ (!(mnt >> (64 - i))) {
                mnt <<= i;
                ਘਾਤਾਂਕ -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)ਘਾਤਾਂਕ << 48 | mnt << 1 >> 16;
    }
    ਵਾਪਸ x.f;
}

ਲੰਮਾ ਦੁੱਗਣਾ __floatunsitf(uint32_t a)
{
    ਪੂਰਨ ਘਾਤਾਂਕ = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    ਪੂਰਨ i;
    ਜੇ (a) {
        ਲਈ (i = 16; i; i >>= 1)
            ਜੇ (!(mnt >> (32 - i))) {
                mnt <<= i;
                ਘਾਤਾਂਕ -= i;
            }
        x.x1 = (uint64_t)ਘਾਤਾਂਕ << 48 | (uint64_t)(mnt << 1) << 16;
    }
    ਵਾਪਸ x.f;
}

ਲੰਮਾ ਦੁੱਗਣਾ __floatunditf(uint64_t a)
{
    ਪੂਰਨ ਘਾਤਾਂਕ = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    ਲੰਮਾ ਦੁੱਗਣਾ f;
    ਪੂਰਨ i;
    ਜੇ (a) {
        ਲਈ (i = 32; i; i >>= 1)
            ਜੇ (!(mnt >> (64 - i))) {
                mnt <<= i;
                ਘਾਤਾਂਕ -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)ਘਾਤਾਂਕ << 48 | mnt << 1 >> 16;
    }
    ਵਾਪਸ x.f;
}

ਸਥਿਰ ਪੂਰਨ f3_cmp(ਲੰਮਾ ਦੁੱਗਣਾ fa, ਲੰਮਾ ਦੁੱਗਣਾ fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    ਵਾਪਸ (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (ਪੂਰਨ)(b.x1 >> 63) - (ਪੂਰਨ)(a.x1 >> 63) :
            a.x1 < b.x1 ? (ਪੂਰਨ)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (ਪੂਰਨ)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (ਪੂਰਨ)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (ਪੂਰਨ)(a.x1 >> 63 << 1) : 0);
}

ਪੂਰਨ __eqtf2(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ !!f3_cmp(a, b);
}

ਪੂਰਨ __netf2(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ !!f3_cmp(a, b);
}

ਪੂਰਨ __lttf2(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ f3_cmp(a, b);
}

ਪੂਰਨ __letf2(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ f3_cmp(a, b);
}

ਪੂਰਨ __gttf2(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ -f3_cmp(b, a);
}

ਪੂਰਨ __getf2(ਲੰਮਾ ਦੁੱਗਣਾ a, ਲੰਮਾ ਦੁੱਗਣਾ b)
{
    ਵਾਪਸ -f3_cmp(b, a);
}
