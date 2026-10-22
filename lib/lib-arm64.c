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
પ્રકારવ્યાખ્યા signed અક્ષર int8_t;
પ્રકારવ્યાખ્યા unsigned અક્ષર uint8_t;
પ્રકારવ્યાખ્યા short int16_t;
પ્રકારવ્યાખ્યા unsigned short uint16_t;
પ્રકારવ્યાખ્યા પૂર્ણાંક int32_t;
પ્રકારવ્યાખ્યા unsigned uint32_t;
પ્રકારવ્યાખ્યા long long int64_t;
પ્રકારવ્યાખ્યા unsigned long long uint64_t;
#નહીંતર
#અન્તર્ભાવ <stdint.h>
#અન્તર્ભાવ <string.h>
#endif

પ્રકારવ્યાખ્યા સંઘ {
    સંરચના { uint64_t x0, x1; };
    long દ્વિગુણ f;
} u128_t;

પ્રકારવ્યાખ્યા સંઘ {
    uint64_t x;
    દ્વિગુણ f;
} u64_t;

પ્રકારવ્યાખ્યા સંઘ {
    uint32_t x;
    દશાંશ f;
} u32_t;

સ્થિર long દ્વિગુણ f3_zero(પૂર્ણાંક sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    પાછા x.f;
}

સ્થિર long દ્વિગુણ f3_infinity(પૂર્ણાંક sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    પાછા x.f;
}

સ્થિર long દ્વિગુણ f3_NaN(શૂન્ય)
{
#જો 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#નહીંતર
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#endif
    પાછા x.f;
}

સ્થિર પૂર્ણાંક fp3_convert_NaN(long દ્વિગુણ *f, પૂર્ણાંક sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    પાછા 1;
#define fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

સ્થિર પૂર્ણાંક fp3_detect_NaNs(long દ્વિગુણ *f,
                           પૂર્ણાંક a_sgn, પૂર્ણાંક a_exp, u128_t *a,
                           પૂર્ણાંક b_sgn, પૂર્ણાંક b_exp, u128_t *b)
#define a (*a)
#define b (*b)
{
#જો 0
    // Detect signalling NaNs:
    જો (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        પાછા fp3_convert_NaN(f, a_sgn, a);
    જો (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        પાછા fp3_convert_NaN(f, b_sgn, b);
#endif
    // Detect quiet NaNs:
    જો (a_exp == 32767 && (a.x0 | a.x1 << 16))
        પાછા fp3_convert_NaN(f, a_sgn, a);
    જો (b_exp == 32767 && (b.x0 | b.x1 << 16))
        પાછા fp3_convert_NaN(f, b_sgn, b);

    પાછા 0;
#undef a
#undef b
#define fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

સ્થિર શૂન્ય f3_unpack(પૂર્ણાંક *sgn, int32_t *exp, u128_t *mnt, long દ્વિગુણ f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    જો (*exp)
        x.x1 |= (uint64_t)1 << 48;
    નહીંતર
        *exp = 1;
    mnt->f = x.f;
}

સ્થિર શૂન્ય f3_normalise(int32_t *exp, u128_t *mnt)
{
    પૂર્ણાંક sh;
    જો (!(mnt->x0 | mnt->x1))
        પાછા;
    જો (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    માટે (sh = 32; sh; sh >>= 1) {
        જો (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

સ્થિર શૂન્ય f3_sticky_shift(int32_t sh, u128_t *x)
{
  જો (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      પાછા;
  }
  જો (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  જો (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

સ્થિર long દ્વિગુણ f3_round(પૂર્ણાંક sgn, int32_t exp, u128_t *x)
{
    long દ્વિગુણ f;
    પૂર્ણાંક error;

    જો (exp > 0) {
        f3_sticky_shift(13, x);
    }
    નહીંતર {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    જો (error == 3 || ((error == 2) & (x->x0 & 1))) {
        જો (!++x->x0) {
            ++x->x1;
            જો (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            નહીંતર જો (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    જો (exp >= 32767)
        પાછા f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    પાછા x->f;
}

સ્થિર long દ્વિગુણ f3_add(long દ્વિગુણ fa, long દ્વિગુણ fb, પૂર્ણાંક neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    પૂર્ણાંક a_sgn, b_sgn, x_sgn;
    long દ્વિગુણ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    જો (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        પાછા fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    જો (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        પાછા f3_NaN();
    જો (a_exp == 32767)
        પાછા f3_infinity(a_sgn);
    જો (b_exp == 32767)
        પાછા f3_infinity(b_sgn);
    જો (!(a.x0 | a.x1 | b.x0 | b.x1))
        પાછા f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    જો (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    નહીંતર {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    જો (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    નહીંતર {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        જો (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    જો (!(x.x0 | x.x1))
        પાછા f3_zero(0);

    f3_normalise(&x_exp, &x);

    પાછા f3_round(x_sgn, x_exp + 12, &x);
}

long દ્વિગુણ __addtf3(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા f3_add(a, b, 0);
}

long દ્વિગુણ __subtf3(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા f3_add(a, b, 1);
}

long દ્વિગુણ __multf3(long દ્વિગુણ fa, long દ્વિગુણ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    પૂર્ણાંક a_sgn, b_sgn, x_sgn;
    long દ્વિગુણ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    જો (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        પાછા fx;

    // Handle infinities and zeroes:
    જો ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        પાછા f3_NaN();
    જો (a_exp == 32767 || b_exp == 32767)
        પાછા f3_infinity(a_sgn ^ b_sgn);
    જો (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        પાછા f3_zero(a_sgn ^ b_sgn);

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
        જો (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    પાછા f3_round(x_sgn, x_exp, &x);
}

long દ્વિગુણ __divtf3(long દ્વિગુણ fa, long દ્વિગુણ fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    પૂર્ણાંક a_sgn, b_sgn, x_sgn, i;
    long દ્વિગુણ fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    જો (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        પાછા fx;

    // Handle infinities and zeroes:
    જો ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        પાછા f3_NaN();
    જો (a_exp == 32767 || !(b.x0 | b.x1))
        પાછા f3_infinity(a_sgn ^ b_sgn);
    જો (!(a.x0 | a.x1) || b_exp == 32767)
        પાછા f3_zero(a_sgn ^ b_sgn);

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
    માટે (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        જો (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    પાછા f3_round(x_sgn, x_exp, &x);
}

long દ્વિગુણ __negtf2(long દ્વિગુણ f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    પાછા f;
}

long દ્વિગુણ __extendsftf2(દશાંશ f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    જો (!(a << 1))
        x.x1 = aa << 32;
    નહીંતર જો (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    નહીંતર જો (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        જ્યારે (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } નહીંતર
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    પાછા x.f;
}

long દ્વિગુણ __extenddftf2(દ્વિગુણ f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    જો (!(a << 1))
        x.x1 = a;
    નહીંતર જો (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    નહીંતર જો (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        જ્યારે (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } નહીંતર
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    પાછા x.f;
}

દશાંશ __trunctfsf2(long દ્વિગુણ f)
{
    u128_t mnt;
    int32_t exp;
    પૂર્ણાંક sgn;
    u32_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    જો (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    નહીંતર જો (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    નહીંતર જો (exp < 16233)
        x = (uint32_t)sgn << 31;
    નહીંતર {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        જો (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        જો ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#undef x
    પાછા x.f;
}

દ્વિગુણ __trunctfdf2(long દ્વિગુણ f)
{
    u128_t mnt;
    int32_t exp;
    પૂર્ણાંક sgn;
    u64_t x;
#define x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    જો (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    નહીંતર જો (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    નહીંતર જો (exp < 15308)
        x = (uint64_t)sgn << 63;
    નહીંતર {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        જો (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        જો ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#undef x
    પાછા x.f;
}

int32_t __fixtfsi(long દ્વિગુણ fa)
{
    u128_t a;
    int32_t a_exp;
    પૂર્ણાંક a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    જો (a_exp < 16369)
        પાછા 0;
    જો (a_exp > 16413)
        પાછા a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    પાછા a_sgn ? -x : x;
}

int64_t __fixtfdi(long દ્વિગુણ fa)
{
    u128_t a;
    int32_t a_exp;
    પૂર્ણાંક a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    જો (a_exp < 16383)
        પાછા 0;
    જો (a_exp > 16445)
        પાછા a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    પાછા a_sgn ? -x : x;
}

uint32_t __fixunstfsi(long દ્વિગુણ fa)
{
    u128_t a;
    int32_t a_exp;
    પૂર્ણાંક a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    જો (a_sgn || a_exp < 16369)
        પાછા 0;
    જો (a_exp > 16414)
        પાછા -1;
    પાછા a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(long દ્વિગુણ fa)
{
    u128_t a;
    int32_t a_exp;
    પૂર્ણાંક a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    જો (a_sgn || a_exp < 16383)
        પાછા 0;
    જો (a_exp > 16446)
        પાછા -1;
    પાછા (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

long દ્વિગુણ __floatsitf(int32_t a)
{
    પૂર્ણાંક sgn = 0;
    પૂર્ણાંક exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    પૂર્ણાંક i;
    જો (a) {
        જો (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        માટે (i = 16; i; i >>= 1)
            જો (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    પાછા x.f;
}

long દ્વિગુણ __floatditf(int64_t a)
{
    પૂર્ણાંક sgn = 0;
    પૂર્ણાંક exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    પૂર્ણાંક i;
    જો (a) {
        જો (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        માટે (i = 32; i; i >>= 1)
            જો (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    પાછા x.f;
}

long દ્વિગુણ __floatunsitf(uint32_t a)
{
    પૂર્ણાંક exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    પૂર્ણાંક i;
    જો (a) {
        માટે (i = 16; i; i >>= 1)
            જો (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    પાછા x.f;
}

long દ્વિગુણ __floatunditf(uint64_t a)
{
    પૂર્ણાંક exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    long દ્વિગુણ f;
    પૂર્ણાંક i;
    જો (a) {
        માટે (i = 32; i; i >>= 1)
            જો (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    પાછા x.f;
}

સ્થિર પૂર્ણાંક f3_cmp(long દ્વિગુણ fa, long દ્વિગુણ fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    પાછા (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (પૂર્ણાંક)(b.x1 >> 63) - (પૂર્ણાંક)(a.x1 >> 63) :
            a.x1 < b.x1 ? (પૂર્ણાંક)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (પૂર્ણાંક)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (પૂર્ણાંક)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (પૂર્ણાંક)(a.x1 >> 63 << 1) : 0);
}

પૂર્ણાંક __eqtf2(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા !!f3_cmp(a, b);
}

પૂર્ણાંક __netf2(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા !!f3_cmp(a, b);
}

પૂર્ણાંક __lttf2(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા f3_cmp(a, b);
}

પૂર્ણાંક __letf2(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા f3_cmp(a, b);
}

પૂર્ણાંક __gttf2(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા -f3_cmp(b, a);
}

પૂર્ણાંક __getf2(long દ્વિગુણ a, long દ્વિગુણ b)
{
    પાછા -f3_cmp(b, a);
}
