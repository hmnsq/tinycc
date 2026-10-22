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

#که_تعریف_شوی __TINYC__
تعريفنوع نښهدار حرف int8_t;
تعريفنوع بینښه حرف uint8_t;
تعريفنوع لنډ int16_t;
تعريفنوع بینښه لنډ uint16_t;
تعريفنوع صحيح int32_t;
تعريفنوع بینښه uint32_t;
تعريفنوع اوږد اوږد int64_t;
تعريفنوع بینښه اوږد اوږد uint64_t;
#وإلا
#ضمن <stdint.h>
#ضمن <string.h>
#د_که_پای

تعريفنوع اتحاد {
    بنية { uint64_t x0, x1; };
    اوږد مزدوج f;
} u128_t;

تعريفنوع اتحاد {
    uint64_t x;
    مزدوج f;
} u64_t;

تعريفنوع اتحاد {
    uint32_t x;
    عائم f;
} u32_t;

ساكن اوږد مزدوج f3_zero(صحيح sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    أرجع x.f;
}

ساكن اوږد مزدوج f3_infinity(صحيح sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    أرجع x.f;
}

ساكن اوږد مزدوج f3_NaN(فراغ)
{
#إذا 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#وإلا
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#د_که_پای
    أرجع x.f;
}

ساكن صحيح fp3_convert_NaN(اوږد مزدوج *f, صحيح sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    أرجع 1;
#تعریف_کړه fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

ساكن صحيح fp3_detect_NaNs(اوږد مزدوج *f,
                           صحيح a_sgn, صحيح a_exp, u128_t *a,
                           صحيح b_sgn, صحيح b_exp, u128_t *b)
#تعریف_کړه a (*a)
#تعریف_کړه b (*b)
{
#إذا 0
    // Detect signalling NaNs:
    إذا (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        أرجع fp3_convert_NaN(f, a_sgn, a);
    إذا (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        أرجع fp3_convert_NaN(f, b_sgn, b);
#د_که_پای
    // Detect quiet NaNs:
    إذا (a_exp == 32767 && (a.x0 | a.x1 << 16))
        أرجع fp3_convert_NaN(f, a_sgn, a);
    إذا (b_exp == 32767 && (b.x0 | b.x1 << 16))
        أرجع fp3_convert_NaN(f, b_sgn, b);

    أرجع 0;
#تعریف_لغوه a
#تعریف_لغوه b
#تعریف_کړه fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

ساكن فراغ f3_unpack(صحيح *sgn, int32_t *توانیز_تابع, u128_t *mnt, اوږد مزدوج f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *توانیز_تابع = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    إذا (*توانیز_تابع)
        x.x1 |= (uint64_t)1 << 48;
    وإلا
        *توانیز_تابع = 1;
    mnt->f = x.f;
}

ساكن فراغ f3_normalise(int32_t *توانیز_تابع, u128_t *mnt)
{
    صحيح sh;
    إذا (!(mnt->x0 | mnt->x1))
        أرجع;
    إذا (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *توانیز_تابع -= 64;
    }
    لكل (sh = 32; sh; sh >>= 1) {
        إذا (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *توانیز_تابع -= sh;
        }
    }
}

ساكن فراغ f3_sticky_ښويدنه(int32_t sh, u128_t *x)
{
  إذا (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      أرجع;
  }
  إذا (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  إذا (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

ساكن اوږد مزدوج f3_پړاو(صحيح sgn, int32_t توانیز_تابع, u128_t *x)
{
    اوږد مزدوج f;
    صحيح error;

    إذا (توانیز_تابع > 0) {
        f3_sticky_ښويدنه(13, x);
    }
    وإلا {
        f3_sticky_ښويدنه(14 - توانیز_تابع, x);
        توانیز_تابع = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    إذا (error == 3 || ((error == 2) & (x->x0 & 1))) {
        إذا (!++x->x0) {
            ++x->x1;
            إذا (x->x1 == (uint64_t)1 << 48)
                توانیز_تابع = 1;
            وإلا إذا (x->x1 == (uint64_t)1 << 49) {
                ++توانیز_تابع;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    إذا (توانیز_تابع >= 32767)
        أرجع f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)توانیز_تابع << 48 | (uint64_t)sgn << 63;
    أرجع x->f;
}

ساكن اوږد مزدوج f3_جمع_کړه(اوږد مزدوج fa, اوږد مزدوج fb, صحيح neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحيح a_sgn, b_sgn, x_sgn;
    اوږد مزدوج fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    إذا (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        أرجع fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    إذا (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        أرجع f3_NaN();
    إذا (a_exp == 32767)
        أرجع f3_infinity(a_sgn);
    إذا (b_exp == 32767)
        أرجع f3_infinity(b_sgn);
    إذا (!(a.x0 | a.x1 | b.x0 | b.x1))
        أرجع f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    إذا (a_exp <= b_exp) {
        f3_sticky_ښويدنه(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    وإلا {
        f3_sticky_ښويدنه(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    إذا (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    وإلا {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        إذا (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    إذا (!(x.x0 | x.x1))
        أرجع f3_zero(0);

    f3_normalise(&x_exp, &x);

    أرجع f3_پړاو(x_sgn, x_exp + 12, &x);
}

اوږد مزدوج __addtf3(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع f3_جمع_کړه(a, b, 0);
}

اوږد مزدوج __subtf3(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع f3_جمع_کړه(a, b, 1);
}

اوږد مزدوج __multf3(اوږد مزدوج fa, اوږد مزدوج fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحيح a_sgn, b_sgn, x_sgn;
    اوږد مزدوج fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    إذا (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        أرجع fx;

    // Handle infinities and zeroes:
    إذا ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        أرجع f3_NaN();
    إذا (a_exp == 32767 || b_exp == 32767)
        أرجع f3_infinity(a_sgn ^ b_sgn);
    إذا (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        أرجع f3_zero(a_sgn ^ b_sgn);

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
        إذا (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    أرجع f3_پړاو(x_sgn, x_exp, &x);
}

اوږد مزدوج __divtf3(اوږد مزدوج fa, اوږد مزدوج fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    صحيح a_sgn, b_sgn, x_sgn, i;
    اوږد مزدوج fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    إذا (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        أرجع fx;

    // Handle infinities and zeroes:
    إذا ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        أرجع f3_NaN();
    إذا (a_exp == 32767 || !(b.x0 | b.x1))
        أرجع f3_infinity(a_sgn ^ b_sgn);
    إذا (!(a.x0 | a.x1) || b_exp == 32767)
        أرجع f3_zero(a_sgn ^ b_sgn);

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
    لكل (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        إذا (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    أرجع f3_پړاو(x_sgn, x_exp, &x);
}

اوږد مزدوج __negtf2(اوږد مزدوج f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    أرجع f;
}

اوږد مزدوج __extendsftf2(عائم f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    إذا (!(a << 1))
        x.x1 = aa << 32;
    وإلا إذا (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    وإلا إذا (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        طالما (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } وإلا
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    أرجع x.f;
}

اوږد مزدوج __extenddftf2(مزدوج f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    إذا (!(a << 1))
        x.x1 = a;
    وإلا إذا (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    وإلا إذا (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        طالما (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } وإلا
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    أرجع x.f;
}

عائم __trunctfsf2(اوږد مزدوج f)
{
    u128_t mnt;
    int32_t توانیز_تابع;
    صحيح sgn;
    u32_t x;
#تعریف_کړه x x.x

    f3_unpack(&sgn, &توانیز_تابع, &mnt, f);
    إذا (توانیز_تابع == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    وإلا إذا (توانیز_تابع > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    وإلا إذا (توانیز_تابع < 16233)
        x = (uint32_t)sgn << 31;
    وإلا {
        توانیز_تابع -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        إذا (توانیز_تابع < 0) {
            x = x >> -توانیز_تابع | !!(x << (32 + توانیز_تابع));
            توانیز_تابع = 0;
        }
        إذا ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (توانیز_تابع << 23)) | (uint32_t)sgn << 31;
    }
#تعریف_لغوه x
    أرجع x.f;
}

مزدوج __trunctfdf2(اوږد مزدوج f)
{
    u128_t mnt;
    int32_t توانیز_تابع;
    صحيح sgn;
    u64_t x;
#تعریف_کړه x x.x

    f3_unpack(&sgn, &توانیز_تابع, &mnt, f);
    إذا (توانیز_تابع == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    وإلا إذا (توانیز_تابع > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    وإلا إذا (توانیز_تابع < 15308)
        x = (uint64_t)sgn << 63;
    وإلا {
        توانیز_تابع -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        إذا (توانیز_تابع < 0) {
            x = x >> -توانیز_تابع | !!(x << (64 + توانیز_تابع));
            توانیز_تابع = 0;
        }
        إذا ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)توانیز_تابع << 52)) | (uint64_t)sgn << 63;
    }
#تعریف_لغوه x
    أرجع x.f;
}

int32_t __fixtfsi(اوږد مزدوج fa)
{
    u128_t a;
    int32_t a_exp;
    صحيح a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    إذا (a_exp < 16369)
        أرجع 0;
    إذا (a_exp > 16413)
        أرجع a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    أرجع a_sgn ? -x : x;
}

int64_t __fixtfdi(اوږد مزدوج fa)
{
    u128_t a;
    int32_t a_exp;
    صحيح a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    إذا (a_exp < 16383)
        أرجع 0;
    إذا (a_exp > 16445)
        أرجع a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    أرجع a_sgn ? -x : x;
}

uint32_t __fixunstfsi(اوږد مزدوج fa)
{
    u128_t a;
    int32_t a_exp;
    صحيح a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    إذا (a_sgn || a_exp < 16369)
        أرجع 0;
    إذا (a_exp > 16414)
        أرجع -1;
    أرجع a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(اوږد مزدوج fa)
{
    u128_t a;
    int32_t a_exp;
    صحيح a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    إذا (a_sgn || a_exp < 16383)
        أرجع 0;
    إذا (a_exp > 16446)
        أرجع -1;
    أرجع (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

اوږد مزدوج __floatsitf(int32_t a)
{
    صحيح sgn = 0;
    صحيح توانیز_تابع = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    صحيح i;
    إذا (a) {
        إذا (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        لكل (i = 16; i; i >>= 1)
            إذا (!(mnt >> (32 - i))) {
                mnt <<= i;
                توانیز_تابع -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)توانیز_تابع << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    أرجع x.f;
}

اوږد مزدوج __floatditf(int64_t a)
{
    صحيح sgn = 0;
    صحيح توانیز_تابع = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    صحيح i;
    إذا (a) {
        إذا (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        لكل (i = 32; i; i >>= 1)
            إذا (!(mnt >> (64 - i))) {
                mnt <<= i;
                توانیز_تابع -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)توانیز_تابع << 48 | mnt << 1 >> 16;
    }
    أرجع x.f;
}

اوږد مزدوج __floatunsitf(uint32_t a)
{
    صحيح توانیز_تابع = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    صحيح i;
    إذا (a) {
        لكل (i = 16; i; i >>= 1)
            إذا (!(mnt >> (32 - i))) {
                mnt <<= i;
                توانیز_تابع -= i;
            }
        x.x1 = (uint64_t)توانیز_تابع << 48 | (uint64_t)(mnt << 1) << 16;
    }
    أرجع x.f;
}

اوږد مزدوج __floatunditf(uint64_t a)
{
    صحيح توانیز_تابع = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    اوږد مزدوج f;
    صحيح i;
    إذا (a) {
        لكل (i = 32; i; i >>= 1)
            إذا (!(mnt >> (64 - i))) {
                mnt <<= i;
                توانیز_تابع -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)توانیز_تابع << 48 | mnt << 1 >> 16;
    }
    أرجع x.f;
}

ساكن صحيح f3_cmp(اوږد مزدوج fa, اوږد مزدوج fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    أرجع (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (صحيح)(b.x1 >> 63) - (صحيح)(a.x1 >> 63) :
            a.x1 < b.x1 ? (صحيح)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (صحيح)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (صحيح)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (صحيح)(a.x1 >> 63 << 1) : 0);
}

صحيح __eqtf2(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع !!f3_cmp(a, b);
}

صحيح __netf2(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع !!f3_cmp(a, b);
}

صحيح __lttf2(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع f3_cmp(a, b);
}

صحيح __letf2(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع f3_cmp(a, b);
}

صحيح __gttf2(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع -f3_cmp(b, a);
}

صحيح __getf2(اوږد مزدوج a, اوږد مزدوج b)
{
    أرجع -f3_cmp(b, a);
}
