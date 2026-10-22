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

#నిర్వచితమైతే __TINYC__
రకనిర్వచనం గుర్తుగల అక్షరం int8_t;
రకనిర్వచనం గుర్తులేని అక్షరం uint8_t;
రకనిర్వచనం పొట్టి int16_t;
రకనిర్వచనం గుర్తులేని పొట్టి uint16_t;
రకనిర్వచనం పూర్ణాంకం int32_t;
రకనిర్వచనం గుర్తులేని uint32_t;
రకనిర్వచనం దీర్ఘ దీర్ఘ int64_t;
రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ uint64_t;
#లేకపోతే
#అన్తర్భావ <stdint.h>
#అన్తర్భావ <string.h>
#అయితే_ముగింపు

రకనిర్వచనం సంఘం {
    నిర్మాణం { uint64_t x0, x1; };
    దీర్ఘ ద్విగుణ f;
} u128_t;

రకనిర్వచనం సంఘం {
    uint64_t x;
    ద్విగుణ f;
} u64_t;

రకనిర్వచనం సంఘం {
    uint32_t x;
    దశాంశం f;
} u32_t;

స్థిర దీర్ఘ ద్విగుణ f3_zero(పూర్ణాంకం sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    తిరిగి x.f;
}

స్థిర దీర్ఘ ద్విగుణ f3_infinity(పూర్ణాంకం sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    తిరిగి x.f;
}

స్థిర దీర్ఘ ద్విగుణ f3_NaN(శూన్య)
{
#ఒకవేళ 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#లేకపోతే
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#అయితే_ముగింపు
    తిరిగి x.f;
}

స్థిర పూర్ణాంకం fp3_convert_NaN(దీర్ఘ ద్విగుణ *f, పూర్ణాంకం sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    తిరిగి 1;
#నిర్వచించు fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

స్థిర పూర్ణాంకం fp3_detect_NaNs(దీర్ఘ ద్విగుణ *f,
                           పూర్ణాంకం a_sgn, పూర్ణాంకం a_exp, u128_t *a,
                           పూర్ణాంకం b_sgn, పూర్ణాంకం b_exp, u128_t *b)
#నిర్వచించు a (*a)
#నిర్వచించు b (*b)
{
#ఒకవేళ 0
    // Detect signalling NaNs:
    ఒకవేళ (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        తిరిగి fp3_convert_NaN(f, a_sgn, a);
    ఒకవేళ (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        తిరిగి fp3_convert_NaN(f, b_sgn, b);
#అయితే_ముగింపు
    // Detect quiet NaNs:
    ఒకవేళ (a_exp == 32767 && (a.x0 | a.x1 << 16))
        తిరిగి fp3_convert_NaN(f, a_sgn, a);
    ఒకవేళ (b_exp == 32767 && (b.x0 | b.x1 << 16))
        తిరిగి fp3_convert_NaN(f, b_sgn, b);

    తిరిగి 0;
#నిర్వచనం_రద్దు a
#నిర్వచనం_రద్దు b
#నిర్వచించు fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

స్థిర శూన్య f3_unpack(పూర్ణాంకం *sgn, int32_t *ఘాతాంకం, u128_t *mnt, దీర్ఘ ద్విగుణ f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *ఘాతాంకం = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    ఒకవేళ (*ఘాతాంకం)
        x.x1 |= (uint64_t)1 << 48;
    లేకపోతే
        *ఘాతాంకం = 1;
    mnt->f = x.f;
}

స్థిర శూన్య f3_normalise(int32_t *ఘాతాంకం, u128_t *mnt)
{
    పూర్ణాంకం sh;
    ఒకవేళ (!(mnt->x0 | mnt->x1))
        తిరిగి;
    ఒకవేళ (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *ఘాతాంకం -= 64;
    }
    కొరకు (sh = 32; sh; sh >>= 1) {
        ఒకవేళ (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *ఘాతాంకం -= sh;
        }
    }
}

స్థిర శూన్య f3_sticky_జరుపు(int32_t sh, u128_t *x)
{
  ఒకవేళ (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      తిరిగి;
  }
  ఒకవేళ (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  ఒకవేళ (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

స్థిర దీర్ఘ ద్విగుణ f3_విడత(పూర్ణాంకం sgn, int32_t ఘాతాంకం, u128_t *x)
{
    దీర్ఘ ద్విగుణ f;
    పూర్ణాంకం error;

    ఒకవేళ (ఘాతాంకం > 0) {
        f3_sticky_జరుపు(13, x);
    }
    లేకపోతే {
        f3_sticky_జరుపు(14 - ఘాతాంకం, x);
        ఘాతాంకం = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    ఒకవేళ (error == 3 || ((error == 2) & (x->x0 & 1))) {
        ఒకవేళ (!++x->x0) {
            ++x->x1;
            ఒకవేళ (x->x1 == (uint64_t)1 << 48)
                ఘాతాంకం = 1;
            లేకపోతే ఒకవేళ (x->x1 == (uint64_t)1 << 49) {
                ++ఘాతాంకం;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    ఒకవేళ (ఘాతాంకం >= 32767)
        తిరిగి f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)ఘాతాంకం << 48 | (uint64_t)sgn << 63;
    తిరిగి x->f;
}

స్థిర దీర్ఘ ద్విగుణ f3_కూడు(దీర్ఘ ద్విగుణ fa, దీర్ఘ ద్విగుణ fb, పూర్ణాంకం neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    పూర్ణాంకం a_sgn, b_sgn, x_sgn;
    దీర్ఘ ద్విగుణ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ఒకవేళ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        తిరిగి fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    ఒకవేళ (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        తిరిగి f3_NaN();
    ఒకవేళ (a_exp == 32767)
        తిరిగి f3_infinity(a_sgn);
    ఒకవేళ (b_exp == 32767)
        తిరిగి f3_infinity(b_sgn);
    ఒకవేళ (!(a.x0 | a.x1 | b.x0 | b.x1))
        తిరిగి f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    ఒకవేళ (a_exp <= b_exp) {
        f3_sticky_జరుపు(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    లేకపోతే {
        f3_sticky_జరుపు(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    ఒకవేళ (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    లేకపోతే {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        ఒకవేళ (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    ఒకవేళ (!(x.x0 | x.x1))
        తిరిగి f3_zero(0);

    f3_normalise(&x_exp, &x);

    తిరిగి f3_విడత(x_sgn, x_exp + 12, &x);
}

దీర్ఘ ద్విగుణ __addtf3(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి f3_కూడు(a, b, 0);
}

దీర్ఘ ద్విగుణ __subtf3(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి f3_కూడు(a, b, 1);
}

దీర్ఘ ద్విగుణ __multf3(దీర్ఘ ద్విగుణ fa, దీర్ఘ ద్విగుణ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    పూర్ణాంకం a_sgn, b_sgn, x_sgn;
    దీర్ఘ ద్విగుణ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ఒకవేళ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        తిరిగి fx;

    // Handle infinities and zeroes:
    ఒకవేళ ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        తిరిగి f3_NaN();
    ఒకవేళ (a_exp == 32767 || b_exp == 32767)
        తిరిగి f3_infinity(a_sgn ^ b_sgn);
    ఒకవేళ (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        తిరిగి f3_zero(a_sgn ^ b_sgn);

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
        ఒకవేళ (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    తిరిగి f3_విడత(x_sgn, x_exp, &x);
}

దీర్ఘ ద్విగుణ __divtf3(దీర్ఘ ద్విగుణ fa, దీర్ఘ ద్విగుణ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    పూర్ణాంకం a_sgn, b_sgn, x_sgn, i;
    దీర్ఘ ద్విగుణ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    ఒకవేళ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        తిరిగి fx;

    // Handle infinities and zeroes:
    ఒకవేళ ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        తిరిగి f3_NaN();
    ఒకవేళ (a_exp == 32767 || !(b.x0 | b.x1))
        తిరిగి f3_infinity(a_sgn ^ b_sgn);
    ఒకవేళ (!(a.x0 | a.x1) || b_exp == 32767)
        తిరిగి f3_zero(a_sgn ^ b_sgn);

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
    కొరకు (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        ఒకవేళ (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    తిరిగి f3_విడత(x_sgn, x_exp, &x);
}

దీర్ఘ ద్విగుణ __negtf2(దీర్ఘ ద్విగుణ f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    తిరిగి f;
}

దీర్ఘ ద్విగుణ __extendsftf2(దశాంశం f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    ఒకవేళ (!(a << 1))
        x.x1 = aa << 32;
    లేకపోతే ఒకవేళ (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    లేకపోతే ఒకవేళ (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        అయితే (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } లేకపోతే
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    తిరిగి x.f;
}

దీర్ఘ ద్విగుణ __extenddftf2(ద్విగుణ f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    ఒకవేళ (!(a << 1))
        x.x1 = a;
    లేకపోతే ఒకవేళ (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    లేకపోతే ఒకవేళ (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        అయితే (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } లేకపోతే
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    తిరిగి x.f;
}

దశాంశం __trunctfsf2(దీర్ఘ ద్విగుణ f)
{
    u128_t mnt;
    int32_t ఘాతాంకం;
    పూర్ణాంకం sgn;
    u32_t x;
#నిర్వచించు x x.x

    f3_unpack(&sgn, &ఘాతాంకం, &mnt, f);
    ఒకవేళ (ఘాతాంకం == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    లేకపోతే ఒకవేళ (ఘాతాంకం > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    లేకపోతే ఒకవేళ (ఘాతాంకం < 16233)
        x = (uint32_t)sgn << 31;
    లేకపోతే {
        ఘాతాంకం -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        ఒకవేళ (ఘాతాంకం < 0) {
            x = x >> -ఘాతాంకం | !!(x << (32 + ఘాతాంకం));
            ఘాతాంకం = 0;
        }
        ఒకవేళ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (ఘాతాంకం << 23)) | (uint32_t)sgn << 31;
    }
#నిర్వచనం_రద్దు x
    తిరిగి x.f;
}

ద్విగుణ __trunctfdf2(దీర్ఘ ద్విగుణ f)
{
    u128_t mnt;
    int32_t ఘాతాంకం;
    పూర్ణాంకం sgn;
    u64_t x;
#నిర్వచించు x x.x

    f3_unpack(&sgn, &ఘాతాంకం, &mnt, f);
    ఒకవేళ (ఘాతాంకం == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    లేకపోతే ఒకవేళ (ఘాతాంకం > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    లేకపోతే ఒకవేళ (ఘాతాంకం < 15308)
        x = (uint64_t)sgn << 63;
    లేకపోతే {
        ఘాతాంకం -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        ఒకవేళ (ఘాతాంకం < 0) {
            x = x >> -ఘాతాంకం | !!(x << (64 + ఘాతాంకం));
            ఘాతాంకం = 0;
        }
        ఒకవేళ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)ఘాతాంకం << 52)) | (uint64_t)sgn << 63;
    }
#నిర్వచనం_రద్దు x
    తిరిగి x.f;
}

int32_t __fixtfsi(దీర్ఘ ద్విగుణ fa)
{
    u128_t a;
    int32_t a_exp;
    పూర్ణాంకం a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ఒకవేళ (a_exp < 16369)
        తిరిగి 0;
    ఒకవేళ (a_exp > 16413)
        తిరిగి a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    తిరిగి a_sgn ? -x : x;
}

int64_t __fixtfdi(దీర్ఘ ద్విగుణ fa)
{
    u128_t a;
    int32_t a_exp;
    పూర్ణాంకం a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ఒకవేళ (a_exp < 16383)
        తిరిగి 0;
    ఒకవేళ (a_exp > 16445)
        తిరిగి a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    తిరిగి a_sgn ? -x : x;
}

uint32_t __fixunstfsi(దీర్ఘ ద్విగుణ fa)
{
    u128_t a;
    int32_t a_exp;
    పూర్ణాంకం a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ఒకవేళ (a_sgn || a_exp < 16369)
        తిరిగి 0;
    ఒకవేళ (a_exp > 16414)
        తిరిగి -1;
    తిరిగి a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(దీర్ఘ ద్విగుణ fa)
{
    u128_t a;
    int32_t a_exp;
    పూర్ణాంకం a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    ఒకవేళ (a_sgn || a_exp < 16383)
        తిరిగి 0;
    ఒకవేళ (a_exp > 16446)
        తిరిగి -1;
    తిరిగి (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

దీర్ఘ ద్విగుణ __floatsitf(int32_t a)
{
    పూర్ణాంకం sgn = 0;
    పూర్ణాంకం ఘాతాంకం = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    పూర్ణాంకం i;
    ఒకవేళ (a) {
        ఒకవేళ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        కొరకు (i = 16; i; i >>= 1)
            ఒకవేళ (!(mnt >> (32 - i))) {
                mnt <<= i;
                ఘాతాంకం -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)ఘాతాంకం << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    తిరిగి x.f;
}

దీర్ఘ ద్విగుణ __floatditf(int64_t a)
{
    పూర్ణాంకం sgn = 0;
    పూర్ణాంకం ఘాతాంకం = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    పూర్ణాంకం i;
    ఒకవేళ (a) {
        ఒకవేళ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        కొరకు (i = 32; i; i >>= 1)
            ఒకవేళ (!(mnt >> (64 - i))) {
                mnt <<= i;
                ఘాతాంకం -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)ఘాతాంకం << 48 | mnt << 1 >> 16;
    }
    తిరిగి x.f;
}

దీర్ఘ ద్విగుణ __floatunsitf(uint32_t a)
{
    పూర్ణాంకం ఘాతాంకం = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    పూర్ణాంకం i;
    ఒకవేళ (a) {
        కొరకు (i = 16; i; i >>= 1)
            ఒకవేళ (!(mnt >> (32 - i))) {
                mnt <<= i;
                ఘాతాంకం -= i;
            }
        x.x1 = (uint64_t)ఘాతాంకం << 48 | (uint64_t)(mnt << 1) << 16;
    }
    తిరిగి x.f;
}

దీర్ఘ ద్విగుణ __floatunditf(uint64_t a)
{
    పూర్ణాంకం ఘాతాంకం = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    దీర్ఘ ద్విగుణ f;
    పూర్ణాంకం i;
    ఒకవేళ (a) {
        కొరకు (i = 32; i; i >>= 1)
            ఒకవేళ (!(mnt >> (64 - i))) {
                mnt <<= i;
                ఘాతాంకం -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)ఘాతాంకం << 48 | mnt << 1 >> 16;
    }
    తిరిగి x.f;
}

స్థిర పూర్ణాంకం f3_cmp(దీర్ఘ ద్విగుణ fa, దీర్ఘ ద్విగుణ fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    తిరిగి (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (పూర్ణాంకం)(b.x1 >> 63) - (పూర్ణాంకం)(a.x1 >> 63) :
            a.x1 < b.x1 ? (పూర్ణాంకం)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (పూర్ణాంకం)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (పూర్ణాంకం)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (పూర్ణాంకం)(a.x1 >> 63 << 1) : 0);
}

పూర్ణాంకం __eqtf2(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి !!f3_cmp(a, b);
}

పూర్ణాంకం __netf2(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి !!f3_cmp(a, b);
}

పూర్ణాంకం __lttf2(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి f3_cmp(a, b);
}

పూర్ణాంకం __letf2(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి f3_cmp(a, b);
}

పూర్ణాంకం __gttf2(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి -f3_cmp(b, a);
}

పూర్ణాంకం __getf2(దీర్ఘ ద్విగుణ a, దీర్ఘ ద్విగుణ b)
{
    తిరిగి -f3_cmp(b, a);
}
