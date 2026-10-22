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
തരനിർവചനം signed അക്ഷരം int8_t;
തരനിർവചനം unsigned അക്ഷരം uint8_t;
തരനിർവചനം short int16_t;
തരനിർവചനം unsigned short uint16_t;
തരനിർവചനം പൂർണ്ണസംഖ്യ int32_t;
തരനിർവചനം unsigned uint32_t;
തരനിർവചനം long long int64_t;
തരനിർവചനം unsigned long long uint64_t;
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <stdint.h>
#അന്തര്ഭാവ <string.h>
#endif

തരനിർവചനം സംഘം {
    ഘടന { uint64_t x0, x1; };
    long ഇരട്ട f;
} u128_t;

തരനിർവചനം സംഘം {
    uint64_t x;
    ഇരട്ട f;
} u64_t;

തരനിർവചനം സംഘം {
    uint32_t x;
    ദശാംശം f;
} u32_t;

സ്ഥിതം long ഇരട്ട f3_zero(പൂർണ്ണസംഖ്യ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    തിരികെ x.f;
}

സ്ഥിതം long ഇരട്ട f3_infinity(പൂർണ്ണസംഖ്യ sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    തിരികെ x.f;
}

സ്ഥിതം long ഇരട്ട f3_NaN(ശൂന്യം)
{
#എങ്കിൽ 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#അല്ലെങ്കിൽ
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#endif
    തിരികെ x.f;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ fp3_convert_NaN(long ഇരട്ട *f, പൂർണ്ണസംഖ്യ sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    തിരികെ 1;
#define fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

സ്ഥിതം പൂർണ്ണസംഖ്യ fp3_detect_NaNs(long ഇരട്ട *f,
                           പൂർണ്ണസംഖ്യ a_sgn, പൂർണ്ണസംഖ്യ a_exp, u128_t *a,
                           പൂർണ്ണസംഖ്യ b_sgn, പൂർണ്ണസംഖ്യ b_exp, u128_t *b)
#define a (*a)
#define b (*b)
{
#എങ്കിൽ 0
    // Detect signalling NaNs:
    എങ്കിൽ (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        തിരികെ fp3_convert_NaN(f, a_sgn, a);
    എങ്കിൽ (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        തിരികെ fp3_convert_NaN(f, b_sgn, b);
#endif
    // Detect quiet NaNs:
    എങ്കിൽ (a_exp == 32767 && (a.x0 | a.x1 << 16))
        തിരികെ fp3_convert_NaN(f, a_sgn, a);
    എങ്കിൽ (b_exp == 32767 && (b.x0 | b.x1 << 16))
        തിരികെ fp3_convert_NaN(f, b_sgn, b);

    തിരികെ 0;
#undef a
#undef b
#define fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

സ്ഥിതം ശൂന്യം f3_unpack(പൂർണ്ണസംഖ്യ *sgn, int32_t *exp, u128_t *mnt, long ഇരട്ട f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    എങ്കിൽ (*exp)
        x.x1 |= (uint64_t)1 << 48;
    അല്ലെങ്കിൽ
        *exp = 1;
    mnt->f = x.f;
}

സ്ഥിതം ശൂന്യം f3_normalise(int32_t *exp, u128_t *mnt)
{
    പൂർണ്ണസംഖ്യ sh;
    എങ്കിൽ (!(mnt->x0 | mnt->x1))
        തിരികെ;
    എങ്കിൽ (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    വേണ്ടി (sh = 32; sh; sh >>= 1) {
        എങ്കിൽ (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

സ്ഥിതം ശൂന്യം f3_sticky_shift(int32_t sh, u128_t *x)
{
  എങ്കിൽ (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      തിരികെ;
  }
  എങ്കിൽ (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  എങ്കിൽ (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

സ്ഥിതം long ഇരട്ട f3_round(പൂർണ്ണസംഖ്യ sgn, int32_t exp, u128_t *x)
{
    long ഇരട്ട f;
    പൂർണ്ണസംഖ്യ error;

    എങ്കിൽ (exp > 0) {
        f3_sticky_shift(13, x);
    }
    അല്ലെങ്കിൽ {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    എങ്കിൽ (error == 3 || ((error == 2) & (x->x0 & 1))) {
        എങ്കിൽ (!++x->x0) {
            ++x->x1;
            എങ്കിൽ (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            അല്ലെങ്കിൽ എങ്കിൽ (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    എങ്കിൽ (exp >= 32767)
        തിരികെ f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    തിരികെ x->f;
}

സ്ഥിതം long ഇരട്ട f3_add(long ഇരട്ട fa, long ഇരട്ട fb, പൂർണ്ണസംഖ്യ neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    പൂർണ്ണസംഖ്യ a_sgn, b_sgn, x_sgn;
    long ഇരട്ട fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    എങ്കിൽ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        തിരികെ fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    എങ്കിൽ (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        തിരികെ f3_NaN();
    എങ്കിൽ (a_exp == 32767)
        തിരികെ f3_infinity(a_sgn);
    എങ്കിൽ (b_exp == 32767)
        തിരികെ f3_infinity(b_sgn);
    എങ്കിൽ (!(a.x0 | a.x1 | b.x0 | b.x1))
        തിരികെ f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    എങ്കിൽ (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    അല്ലെങ്കിൽ {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    എങ്കിൽ (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    അല്ലെങ്കിൽ {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        എങ്കിൽ (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    എങ്കിൽ (!(x.x0 | x.x1))
        തിരികെ f3_zero(0);

    f3_normalise(&x_exp, &x);

    തിരികെ f3_round(x_sgn, x_exp + 12, &x);
}

long ഇരട്ട __addtf3(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ f3_add(a, b, 0);
}

long ഇരട്ട __subtf3(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ f3_add(a, b, 1);
}

long ഇരട്ട __multf3(long ഇരട്ട fa, long ഇരട്ട fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    പൂർണ്ണസംഖ്യ a_sgn, b_sgn, x_sgn;
    long ഇരട്ട fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    എങ്കിൽ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        തിരികെ fx;

    // Handle infinities and zeroes:
    എങ്കിൽ ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        തിരികെ f3_NaN();
    എങ്കിൽ (a_exp == 32767 || b_exp == 32767)
        തിരികെ f3_infinity(a_sgn ^ b_sgn);
    എങ്കിൽ (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        തിരികെ f3_zero(a_sgn ^ b_sgn);

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
        എങ്കിൽ (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    തിരികെ f3_round(x_sgn, x_exp, &x);
}

long ഇരട്ട __divtf3(long ഇരട്ട fa, long ഇരട്ട fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    പൂർണ്ണസംഖ്യ a_sgn, b_sgn, x_sgn, i;
    long ഇരട്ട fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    എങ്കിൽ (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        തിരികെ fx;

    // Handle infinities and zeroes:
    എങ്കിൽ ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        തിരികെ f3_NaN();
    എങ്കിൽ (a_exp == 32767 || !(b.x0 | b.x1))
        തിരികെ f3_infinity(a_sgn ^ b_sgn);
    എങ്കിൽ (!(a.x0 | a.x1) || b_exp == 32767)
        തിരികെ f3_zero(a_sgn ^ b_sgn);

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
    വേണ്ടി (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        എങ്കിൽ (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    തിരികെ f3_round(x_sgn, x_exp, &x);
}

long ഇരട്ട __negtf2(long ഇരട്ട f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    തിരികെ f;
}

long ഇരട്ട __extendsftf2(ദശാംശം f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    എങ്കിൽ (!(a << 1))
        x.x1 = aa << 32;
    അല്ലെങ്കിൽ എങ്കിൽ (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    അല്ലെങ്കിൽ എങ്കിൽ (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        ആകുമ്പോൾ (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } അല്ലെങ്കിൽ
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    തിരികെ x.f;
}

long ഇരട്ട __extenddftf2(ഇരട്ട f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    എങ്കിൽ (!(a << 1))
        x.x1 = a;
    അല്ലെങ്കിൽ എങ്കിൽ (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    അല്ലെങ്കിൽ എങ്കിൽ (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        ആകുമ്പോൾ (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } അല്ലെങ്കിൽ
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    തിരികെ x.f;
}

ദശാംശം __trunctfsf2(long ഇരട്ട f)
{
    u128_t mnt;
    int32_t exp;
    പൂർണ്ണസംഖ്യ sgn;
    u32_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    എങ്കിൽ (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    അല്ലെങ്കിൽ എങ്കിൽ (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    അല്ലെങ്കിൽ എങ്കിൽ (exp < 16233)
        x = (uint32_t)sgn << 31;
    അല്ലെങ്കിൽ {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        എങ്കിൽ (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        എങ്കിൽ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#undef x
    തിരികെ x.f;
}

ഇരട്ട __trunctfdf2(long ഇരട്ട f)
{
    u128_t mnt;
    int32_t exp;
    പൂർണ്ണസംഖ്യ sgn;
    u64_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    എങ്കിൽ (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    അല്ലെങ്കിൽ എങ്കിൽ (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    അല്ലെങ്കിൽ എങ്കിൽ (exp < 15308)
        x = (uint64_t)sgn << 63;
    അല്ലെങ്കിൽ {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        എങ്കിൽ (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        എങ്കിൽ ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#undef x
    തിരികെ x.f;
}

int32_t __fixtfsi(long ഇരട്ട fa)
{
    u128_t a;
    int32_t a_exp;
    പൂർണ്ണസംഖ്യ a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    എങ്കിൽ (a_exp < 16369)
        തിരികെ 0;
    എങ്കിൽ (a_exp > 16413)
        തിരികെ a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    തിരികെ a_sgn ? -x : x;
}

int64_t __fixtfdi(long ഇരട്ട fa)
{
    u128_t a;
    int32_t a_exp;
    പൂർണ്ണസംഖ്യ a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    എങ്കിൽ (a_exp < 16383)
        തിരികെ 0;
    എങ്കിൽ (a_exp > 16445)
        തിരികെ a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    തിരികെ a_sgn ? -x : x;
}

uint32_t __fixunstfsi(long ഇരട്ട fa)
{
    u128_t a;
    int32_t a_exp;
    പൂർണ്ണസംഖ്യ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    എങ്കിൽ (a_sgn || a_exp < 16369)
        തിരികെ 0;
    എങ്കിൽ (a_exp > 16414)
        തിരികെ -1;
    തിരികെ a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(long ഇരട്ട fa)
{
    u128_t a;
    int32_t a_exp;
    പൂർണ്ണസംഖ്യ a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    എങ്കിൽ (a_sgn || a_exp < 16383)
        തിരികെ 0;
    എങ്കിൽ (a_exp > 16446)
        തിരികെ -1;
    തിരികെ (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

long ഇരട്ട __floatsitf(int32_t a)
{
    പൂർണ്ണസംഖ്യ sgn = 0;
    പൂർണ്ണസംഖ്യ exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    പൂർണ്ണസംഖ്യ i;
    എങ്കിൽ (a) {
        എങ്കിൽ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        വേണ്ടി (i = 16; i; i >>= 1)
            എങ്കിൽ (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    തിരികെ x.f;
}

long ഇരട്ട __floatditf(int64_t a)
{
    പൂർണ്ണസംഖ്യ sgn = 0;
    പൂർണ്ണസംഖ്യ exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    പൂർണ്ണസംഖ്യ i;
    എങ്കിൽ (a) {
        എങ്കിൽ (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        വേണ്ടി (i = 32; i; i >>= 1)
            എങ്കിൽ (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    തിരികെ x.f;
}

long ഇരട്ട __floatunsitf(uint32_t a)
{
    പൂർണ്ണസംഖ്യ exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    പൂർണ്ണസംഖ്യ i;
    എങ്കിൽ (a) {
        വേണ്ടി (i = 16; i; i >>= 1)
            എങ്കിൽ (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    തിരികെ x.f;
}

long ഇരട്ട __floatunditf(uint64_t a)
{
    പൂർണ്ണസംഖ്യ exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    long ഇരട്ട f;
    പൂർണ്ണസംഖ്യ i;
    എങ്കിൽ (a) {
        വേണ്ടി (i = 32; i; i >>= 1)
            എങ്കിൽ (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    തിരികെ x.f;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ f3_cmp(long ഇരട്ട fa, long ഇരട്ട fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    തിരികെ (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (പൂർണ്ണസംഖ്യ)(b.x1 >> 63) - (പൂർണ്ണസംഖ്യ)(a.x1 >> 63) :
            a.x1 < b.x1 ? (പൂർണ്ണസംഖ്യ)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (പൂർണ്ണസംഖ്യ)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (പൂർണ്ണസംഖ്യ)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (പൂർണ്ണസംഖ്യ)(a.x1 >> 63 << 1) : 0);
}

പൂർണ്ണസംഖ്യ __eqtf2(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ !!f3_cmp(a, b);
}

പൂർണ്ണസംഖ്യ __netf2(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ !!f3_cmp(a, b);
}

പൂർണ്ണസംഖ്യ __lttf2(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ f3_cmp(a, b);
}

പൂർണ്ണസംഖ്യ __letf2(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ f3_cmp(a, b);
}

പൂർണ്ണസംഖ്യ __gttf2(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ -f3_cmp(b, a);
}

പൂർണ്ണസംഖ്യ __getf2(long ഇരട്ട a, long ഇരട്ട b)
{
    തിരികെ -f3_cmp(b, a);
}
