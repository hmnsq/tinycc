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

#अगर_घोषित __TINYC__
प्रकार चिन्हित अक्षर int8_t;
प्रकार अचिन्हित अक्षर uint8_t;
प्रकार लघु int16_t;
प्रकार अचिन्हित लघु uint16_t;
प्रकार पूर्णांक int32_t;
प्रकार अचिन्हित uint32_t;
प्रकार दीर्घ दीर्घ int64_t;
प्रकार अचिन्हित दीर्घ दीर्घ uint64_t;
#अन्यथा
#समावेश <stdint.h>
#समावेश <string.h>
#पूर्ण_अगर

प्रकार जोड़ {
    काष्ठा { uint64_t x0, x1; };
    दीर्घ द्विगुन f;
} u128_t;

प्रकार जोड़ {
    uint64_t x;
    द्विगुन f;
} u64_t;

प्रकार जोड़ {
    uint32_t x;
    भग्न f;
} u32_t;

अटल दीर्घ द्विगुन f3_zero(पूर्णांक sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 };
    वापस x.f;
}

अटल दीर्घ द्विगुन f3_infinity(पूर्णांक sgn)
{
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    वापस x.f;
}

अटल दीर्घ द्विगुन f3_NaN(व्योम)
{
#अगर 0
    // ARM's default NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#अन्यथा
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#पूर्ण_अगर
    वापस x.f;
}

अटल पूर्णांक fp3_convert_NaN(दीर्घ द्विगुन *f, पूर्णांक sgn, u128_t *mnt)
{
    u128_t x = { mnt->x0,
                 mnt->x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    *f = x.f;
    वापस 1;
#घोषणा fp3_convert_NaN(a,b,c) fp3_convert_NaN(a,b,&c)
}

अटल पूर्णांक fp3_detect_NaNs(दीर्घ द्विगुन *f,
                           पूर्णांक a_sgn, पूर्णांक a_exp, u128_t *a,
                           पूर्णांक b_sgn, पूर्णांक b_exp, u128_t *b)
#घोषणा a (*a)
#घोषणा b (*b)
{
#अगर 0
    // Detect signalling NaNs:
    अगर (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        वापस fp3_convert_NaN(f, a_sgn, a);
    अगर (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        वापस fp3_convert_NaN(f, b_sgn, b);
#पूर्ण_अगर
    // Detect quiet NaNs:
    अगर (a_exp == 32767 && (a.x0 | a.x1 << 16))
        वापस fp3_convert_NaN(f, a_sgn, a);
    अगर (b_exp == 32767 && (b.x0 | b.x1 << 16))
        वापस fp3_convert_NaN(f, b_sgn, b);

    वापस 0;
#अघोषित a
#अघोषित b
#घोषणा fp3_detect_NaNs(a,b,c,d,e,f,g) fp3_detect_NaNs(a,b,c,&d,e,f,&g)
}

अटल व्योम f3_unpack(पूर्णांक *sgn, int32_t *exp, u128_t *mnt, दीर्घ द्विगुन f)
{
    u128_t x;

    x.f = f;
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    अगर (*exp)
        x.x1 |= (uint64_t)1 << 48;
    अन्यथा
        *exp = 1;
    mnt->f = x.f;
}

अटल व्योम f3_normalise(int32_t *exp, u128_t *mnt)
{
    पूर्णांक sh;
    अगर (!(mnt->x0 | mnt->x1))
        वापस;
    अगर (!mnt->x1) {
        mnt->x1 = mnt->x0;
        mnt->x0 = 0;
        *exp -= 64;
    }
    क्रम (sh = 32; sh; sh >>= 1) {
        अगर (!(mnt->x1 >> (64 - sh))) {
            mnt->x1 = mnt->x1 << sh | mnt->x0 >> (64 - sh);
            mnt->x0 = mnt->x0 << sh;
            *exp -= sh;
        }
    }
}

अटल व्योम f3_sticky_shift(int32_t sh, u128_t *x)
{
  अगर (sh >= 128) {
      x->x0 = !!(x->x0 | x->x1);
      x->x1 = 0;
      वापस;
  }
  अगर (sh >= 64) {
      x->x0 = x->x1 | !!x->x0;
      x->x1 = 0;
      sh -= 64;
  }
  अगर (sh > 0) {
      x->x0 = x->x0 >> sh | x->x1 << (64 - sh) | !!(x->x0 << (64 - sh));
      x->x1 = x->x1 >> sh;
  }
}

अटल दीर्घ द्विगुन f3_round(पूर्णांक sgn, int32_t exp, u128_t *x)
{
    दीर्घ द्विगुन f;
    पूर्णांक error;

    अगर (exp > 0) {
        f3_sticky_shift(13, x);
    }
    अन्यथा {
        f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    error = x->x0 & 3;
    x->x0 = x->x0 >> 2 | x->x1 << 62;
    x->x1 = x->x1 >> 2;

    अगर (error == 3 || ((error == 2) & (x->x0 & 1))) {
        अगर (!++x->x0) {
            ++x->x1;
            अगर (x->x1 == (uint64_t)1 << 48)
                exp = 1;
            अन्यथा अगर (x->x1 == (uint64_t)1 << 49) {
                ++exp;
                x->x0 = x->x0 >> 1 | x->x1 << 63;
                x->x1 = x->x1 >> 1;
            }
        }
    }

    अगर (exp >= 32767)
        वापस f3_infinity(sgn);

    x->x1 = x->x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    वापस x->f;
}

अटल दीर्घ द्विगुन f3_add(दीर्घ द्विगुन fa, दीर्घ द्विगुन fb, पूर्णांक neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    पूर्णांक a_sgn, b_sgn, x_sgn;
    दीर्घ द्विगुन fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    अगर (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        वापस fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    अगर (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        वापस f3_NaN();
    अगर (a_exp == 32767)
        वापस f3_infinity(a_sgn);
    अगर (b_exp == 32767)
        वापस f3_infinity(b_sgn);
    अगर (!(a.x0 | a.x1 | b.x0 | b.x1))
        वापस f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    अगर (a_exp <= b_exp) {
        f3_sticky_shift(b_exp - a_exp, &a);
        a_exp = b_exp;
    }
    अन्यथा {
        f3_sticky_shift(a_exp - b_exp, &b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    अगर (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    अन्यथा {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        अगर (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    अगर (!(x.x0 | x.x1))
        वापस f3_zero(0);

    f3_normalise(&x_exp, &x);

    वापस f3_round(x_sgn, x_exp + 12, &x);
}

दीर्घ द्विगुन __addtf3(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस f3_add(a, b, 0);
}

दीर्घ द्विगुन __subtf3(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस f3_add(a, b, 1);
}

दीर्घ द्विगुन __multf3(दीर्घ द्विगुन fa, दीर्घ द्विगुन fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    पूर्णांक a_sgn, b_sgn, x_sgn;
    दीर्घ द्विगुन fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    अगर (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        वापस fx;

    // Handle infinities and zeroes:
    अगर ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        वापस f3_NaN();
    अगर (a_exp == 32767 || b_exp == 32767)
        वापस f3_infinity(a_sgn ^ b_sgn);
    अगर (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        वापस f3_zero(a_sgn ^ b_sgn);

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
        अगर (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    वापस f3_round(x_sgn, x_exp, &x);
}

दीर्घ द्विगुन __divtf3(दीर्घ द्विगुन fa, दीर्घ द्विगुन fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    पूर्णांक a_sgn, b_sgn, x_sgn, i;
    दीर्घ द्विगुन fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    अगर (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        वापस fx;

    // Handle infinities and zeroes:
    अगर ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        वापस f3_NaN();
    अगर (a_exp == 32767 || !(b.x0 | b.x1))
        वापस f3_infinity(a_sgn ^ b_sgn);
    अगर (!(a.x0 | a.x1) || b_exp == 32767)
        वापस f3_zero(a_sgn ^ b_sgn);

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
    क्रम (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        अगर (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    f3_normalise(&x_exp, &x);

    वापस f3_round(x_sgn, x_exp, &x);
}

दीर्घ द्विगुन __negtf2(दीर्घ द्विगुन f)
{
    ((u128_t*)&f)->x1 ^= 1UL << 63;
    वापस f;
}

दीर्घ द्विगुन __extendsftf2(भग्न f)
{
    u128_t x;
    u32_t u;
    uint32_t a;
    uint64_t aa;

    u.f = f, a = u.x;
    aa = a;

    x.x0 = 0;
    अगर (!(a << 1))
        x.x1 = aa << 32;
    अन्यथा अगर (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    अन्यथा अगर (a << 1 >> 24 == 0) {
        uint64_t adj = 0;
        जबतक (!(a << 1 >> 1 >> (23 - adj)))
          adj++;
        x.x1 = aa >> 31 << 63 | (16256 - adj + 1) << 48 | aa << adj << 41 >> 16;
    } अन्यथा
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    वापस x.f;
}

दीर्घ द्विगुन __extenddftf2(द्विगुन f)
{
    u128_t x;
    u64_t u;
    uint64_t a;

    u.f = f, a = u.x;

    x.x0 = a << 60;
    अगर (!(a << 1))
        x.x1 = a;
    अन्यथा अगर (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    अन्यथा अगर (a << 1 >> 53 == 0) {
        uint64_t adj = 0;
        जबतक (!(a << 1 >> 1 >> (52 - adj)))
          adj++;
        x.x0 <<= adj;
        x.x1 = a >> 63 << 63 | (15360 - adj + 1) << 48 | a << adj << 12 >> 16;
    } अन्यथा
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    वापस x.f;
}

भग्न __trunctfsf2(दीर्घ द्विगुन f)
{
    u128_t mnt;
    int32_t exp;
    पूर्णांक sgn;
    u32_t x;
#घोषणा x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    अगर (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    अन्यथा अगर (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    अन्यथा अगर (exp < 16233)
        x = (uint32_t)sgn << 31;
    अन्यथा {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        अगर (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        अगर ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
#अघोषित x
    वापस x.f;
}

द्विगुन __trunctfdf2(दीर्घ द्विगुन f)
{
    u128_t mnt;
    int32_t exp;
    पूर्णांक sgn;
    u64_t x;
#घोषणा x x.x

    f3_unpack(&sgn, &exp, &mnt, f);
    अगर (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    अन्यथा अगर (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    अन्यथा अगर (exp < 15308)
        x = (uint64_t)sgn << 63;
    अन्यथा {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        अगर (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        अगर ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
#अघोषित x
    वापस x.f;
}

int32_t __fixtfsi(दीर्घ द्विगुन fa)
{
    u128_t a;
    int32_t a_exp;
    पूर्णांक a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    अगर (a_exp < 16369)
        वापस 0;
    अगर (a_exp > 16413)
        वापस a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    वापस a_sgn ? -x : x;
}

int64_t __fixtfdi(दीर्घ द्विगुन fa)
{
    u128_t a;
    int32_t a_exp;
    पूर्णांक a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    अगर (a_exp < 16383)
        वापस 0;
    अगर (a_exp > 16445)
        वापस a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    वापस a_sgn ? -x : x;
}

uint32_t __fixunstfsi(दीर्घ द्विगुन fa)
{
    u128_t a;
    int32_t a_exp;
    पूर्णांक a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    अगर (a_sgn || a_exp < 16369)
        वापस 0;
    अगर (a_exp > 16414)
        वापस -1;
    वापस a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(दीर्घ द्विगुन fa)
{
    u128_t a;
    int32_t a_exp;
    पूर्णांक a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    अगर (a_sgn || a_exp < 16383)
        वापस 0;
    अगर (a_exp > 16446)
        वापस -1;
    वापस (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

दीर्घ द्विगुन __floatsitf(int32_t a)
{
    पूर्णांक sgn = 0;
    पूर्णांक exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    पूर्णांक i;
    अगर (a) {
        अगर (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        क्रम (i = 16; i; i >>= 1)
            अगर (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    वापस x.f;
}

दीर्घ द्विगुन __floatditf(int64_t a)
{
    पूर्णांक sgn = 0;
    पूर्णांक exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    पूर्णांक i;
    अगर (a) {
        अगर (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        क्रम (i = 32; i; i >>= 1)
            अगर (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    वापस x.f;
}

दीर्घ द्विगुन __floatunsitf(uint32_t a)
{
    पूर्णांक exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    पूर्णांक i;
    अगर (a) {
        क्रम (i = 16; i; i >>= 1)
            अगर (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    वापस x.f;
}

दीर्घ द्विगुन __floatunditf(uint64_t a)
{
    पूर्णांक exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    दीर्घ द्विगुन f;
    पूर्णांक i;
    अगर (a) {
        क्रम (i = 32; i; i >>= 1)
            अगर (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    वापस x.f;
}

अटल पूर्णांक f3_cmp(दीर्घ द्विगुन fa, दीर्घ द्विगुन fb)
{
    u128_t a, b;
    a.f = fa;
    b.f = fb;
    वापस (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (पूर्णांक)(b.x1 >> 63) - (पूर्णांक)(a.x1 >> 63) :
            a.x1 < b.x1 ? (पूर्णांक)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (पूर्णांक)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (पूर्णांक)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (पूर्णांक)(a.x1 >> 63 << 1) : 0);
}

पूर्णांक __eqtf2(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस !!f3_cmp(a, b);
}

पूर्णांक __netf2(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस !!f3_cmp(a, b);
}

पूर्णांक __lttf2(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस f3_cmp(a, b);
}

पूर्णांक __letf2(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस f3_cmp(a, b);
}

पूर्णांक __gttf2(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस -f3_cmp(b, a);
}

पूर्णांक __getf2(दीर्घ द्विगुन a, दीर्घ द्विगुन b)
{
    वापस -f3_cmp(b, a);
}
