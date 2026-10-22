#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#अन्तर्भाव "../math.h"
#अन्तर्भाव "../stdint.h"

/* TCC uses 8 bytes for double and long double, so effectively the l variants
 * are never used. For now, they just run the normal (double) variant.
 */

/*
 * most of the code in this file is taken from MUSL rs-1.0 (MIT license)
 * - musl-libc: http://git.musl-libc.org/cgit/musl/tree/src/math?h=rs-1.0
 * - License:   http://git.musl-libc.org/cgit/musl/tree/COPYRIGHT?h=rs-1.0
 */

/*******************************************************************************
  Start of code based on MUSL
*******************************************************************************/
/*
musl as a whole is licensed under the following standard MIT license:

----------------------------------------------------------------------
Copyright © 2005-2014 Rich Felker, et al.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
*/

/* fpclassify */

__CRT_INLINE पूर्णाङ्क __cdecl __fpclassify (द्विगुण x) {
  सङ्घ {द्विगुण f; uint64_t i;} u = {.f = x};
  पूर्णाङ्क e = u.i>>52 & 0x7ff;
  जइ (!e) प्रत्यागम u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  जइ (e==0x7ff) प्रत्यागम u.i<<12 ? FP_NAN : FP_INFINITE;
  प्रत्यागम FP_NORMAL;
}

__CRT_INLINE पूर्णाङ्क __cdecl __fpclassifyf (भिन्न x) {
  सङ्घ {भिन्न f; uint32_t i;} u = {.f = x};
  पूर्णाङ्क e = u.i>>23 & 0xff;
  जइ (!e) प्रत्यागम u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  जइ (e==0xff) प्रत्यागम u.i<<9 ? FP_NAN : FP_INFINITE;
  प्रत्यागम FP_NORMAL;
}

__CRT_INLINE पूर्णाङ्क __cdecl __fpclassifyl (long द्विगुण x) {
  प्रत्यागम __fpclassify(x);
}


/* signbit */

__CRT_INLINE पूर्णाङ्क __cdecl __signbit (द्विगुण x) {
  सङ्घ {द्विगुण f; uint64_t i;} u = {.f = x};
  प्रत्यागम u.i>>63;
}

__CRT_INLINE पूर्णाङ्क __cdecl __signbitf (भिन्न x) {
  सङ्घ {भिन्न f; uint32_t i; } u = {.f = x};
  प्रत्यागम u.i>>31;
}

__CRT_INLINE पूर्णाङ्क __cdecl __signbitl (long द्विगुण x) {
  प्रत्यागम __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE द्विगुण __cdecl fmin (द्विगुण x, द्विगुण y) {
  प्रत्यागम TCCFP_FMIN_EVAL;
}

__CRT_INLINE भिन्न __cdecl fminf (भिन्न x, भिन्न y) {
  प्रत्यागम TCCFP_FMIN_EVAL;
}

__CRT_INLINE long द्विगुण __cdecl fminl (long द्विगुण x, long द्विगुण y) {
  प्रत्यागम TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE द्विगुण __cdecl fmax (द्विगुण x, द्विगुण y) {
  प्रत्यागम TCCFP_FMAX_EVAL;
}

__CRT_INLINE भिन्न __cdecl fmaxf (भिन्न x, भिन्न y) {
  प्रत्यागम TCCFP_FMAX_EVAL;
}

__CRT_INLINE long द्विगुण __cdecl fmaxl (long द्विगुण x, long द्विगुण y) {
  प्रत्यागम TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) करेहि {  \
  चञ्चल typeof(x) __x;         \
  __x = (x);                      \
} जाव(0)

__CRT_INLINE द्विगुण __cdecl round (द्विगुण x) {
  सङ्घ {द्विगुण f; uint64_t i;} u = {.f = x};
  पूर्णाङ्क e = u.i >> 52 & 0x7ff;
  द्विगुण y;

  जइ (e >= 0x3ff+52)
    प्रत्यागम x;
  जइ (u.i >> 63)
    x = -x;
  जइ (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    प्रत्यागम 0*u.f;
  }
  y = (द्विगुण)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  प्रत्यागम (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (द्विगुण x) {
  प्रत्यागम round(x);
}

__CRT_INLINE long long __cdecl llround (द्विगुण x) {
  प्रत्यागम round(x);
}

__CRT_INLINE भिन्न __cdecl roundf (भिन्न x) {
  प्रत्यागम round(x);
}

__CRT_INLINE long __cdecl lroundf (भिन्न x) {
  प्रत्यागम round(x);
}

__CRT_INLINE long long __cdecl llroundf (भिन्न x) {
  प्रत्यागम round(x);
}

__CRT_INLINE long द्विगुण __cdecl roundl (long द्विगुण x) {
  प्रत्यागम round(x);
}

__CRT_INLINE long __cdecl lroundl (long द्विगुण x) {
  प्रत्यागम round(x);
}

__CRT_INLINE long long __cdecl llroundl (long द्विगुण x) {
  प्रत्यागम round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE द्विगुण __cdecl asinh(द्विगुण x) {
  सङ्घ {द्विगुण f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  जइ (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  अण्णहा जइ (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  अण्णहा जइ (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  अण्णहा TCCFP_FORCE_EVAL(x + 0x1p120f);
  प्रत्यागम s ? -x : x;
}

__CRT_INLINE द्विगुण __cdecl acosh(द्विगुण x) {
  सङ्घ {द्विगुण f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  जइ (e < 0x3ff + 1) प्रत्यागम --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  जइ (e < 0x3ff + 26) प्रत्यागम log(2*x - 1 / (x + sqrt(x*x - 1)));
  प्रत्यागम log(x) + 0.693147180559945309;
}

__CRT_INLINE द्विगुण __cdecl atanh(द्विगुण x) {
  सङ्घ {द्विगुण f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  जइ (e < 0x3ff - 1) {
    जइ (e < 0x3ff - 32) { जइ (e == 0) TCCFP_FORCE_EVAL((भिन्न)x); }
    अण्णहा x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } अण्णहा x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  प्रत्यागम s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE द्विगुण __cdecl scalbn(द्विगुण x, पूर्णाङ्क n) {
  सङ्घ {द्विगुण f; uint64_t i;} u;
  जइ (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    जइ (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      जइ (n > 1023) n = 1023;
    }
  } अण्णहा जइ (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    जइ (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      जइ (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  प्रत्यागम x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE द्विगुण __cdecl frexp(द्विगुण x, पूर्णाङ्क *e) {
  सङ्घ {द्विगुण f; uint64_t i;} u = {.f = x};
  पूर्णाङ्क ee = u.i>>52 & 0x7ff;
  जइ (!ee) {
    जइ (x) x = frexp(x*0x1p64, e), *e -= 64;
    अण्णहा *e = 0;
    प्रत्यागम x;
  } अण्णहा जइ (ee == 0x7ff)
    प्रत्यागम x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  प्रत्यागम u.f;
}

/* MUSL nan */

__CRT_INLINE द्विगुण __cdecl nan(ध्रुव वर्ण* s) {
  प्रत्यागम NAN;
}
__CRT_INLINE भिन्न __cdecl nanf(ध्रुव वर्ण* s) {
  प्रत्यागम NAN;
}
__CRT_INLINE long द्विगुण __cdecl nanl(ध्रुव वर्ण* s) {
  प्रत्यागम NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE भिन्न __cdecl scalbnf(भिन्न x, पूर्णाङ्क n) {
  प्रत्यागम scalbn(x, n);
}
__CRT_INLINE long द्विगुण __cdecl scalbnl(long द्विगुण x, पूर्णाङ्क n) {
  प्रत्यागम scalbn(x, n);
}

__CRT_INLINE द्विगुण __cdecl scalbln(द्विगुण x, long n) {
  प्रत्यागम scalbn(x, n);
}
__CRT_INLINE भिन्न __cdecl scalblnf(भिन्न x, long n) {
  प्रत्यागम scalbn(x, n);
}
__CRT_INLINE long द्विगुण __cdecl scalblnl(long द्विगुण x, long n) {
  प्रत्यागम scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE द्विगुण __cdecl ldexp(द्विगुण x, पूर्णाङ्क expn) {
  प्रत्यागम scalbn(x, expn);
}
__CRT_INLINE भिन्न __cdecl ldexpf(भिन्न x, पूर्णाङ्क expn) {
  प्रत्यागम scalbn(x, expn);
}
__CRT_INLINE long द्विगुण __cdecl ldexpl(long द्विगुण x, पूर्णाङ्क expn) {
  प्रत्यागम scalbn(x, expn);
}

__CRT_INLINE भिन्न __cdecl frexpf(भिन्न x, पूर्णाङ्क *y) {
  प्रत्यागम frexp(x, y);
}
__CRT_INLINE long द्विगुण __cdecl frexpl (long द्विगुण x, पूर्णाङ्क* y) {
  प्रत्यागम frexp(x, y);
}


__CRT_INLINE द्विगुण __cdecl rint(द्विगुण x) {
द्विगुण retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  प्रत्यागम retval;
}

__CRT_INLINE भिन्न __cdecl rintf(भिन्न x) {
  भिन्न retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   प्रत्यागम retval;
}
__CRT_INLINE long द्विगुण __cdecl rintl (long द्विगुण x) {
  प्रत्यागम rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(द्विगुण x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  प्रत्यागम retval;
}

__CRT_INLINE long __cdecl lrintf(भिन्न x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  प्रत्यागम retval;
}

__CRT_INLINE long __cdecl lrintl (long द्विगुण x) {
  प्रत्यागम lrint(x);
}


__CRT_INLINE long long __cdecl llrint(द्विगुण x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  प्रत्यागम retval;
}

__CRT_INLINE long long __cdecl llrintf(भिन्न x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  प्रत्यागम retval;
}

__CRT_INLINE long long __cdecl llrintl (long द्विगुण x) {
  प्रत्यागम llrint(x);
}


__CRT_INLINE द्विगुण __cdecl trunc(द्विगुण _x) {
  द्विगुण retval;
  unsigned short saved_cw;
  unsigned short tmp_cw;
  __asm__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
  tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
    | FE_TOWARDZERO;
  __asm__ ("fldcw %0;" : : "m" (tmp_cw));
  __asm__ ("fldl  %1;"
           "frndint;"
           "fstpl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
  __asm__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
  प्रत्यागम retval;
}

__CRT_INLINE भिन्न __cdecl truncf(भिन्न x) {
  प्रत्यागम (भिन्न) ((intptr_t) x);
}
__CRT_INLINE long द्विगुण __cdecl truncl(long द्विगुण x) {
  प्रत्यागम trunc(x);
}


__CRT_INLINE long द्विगुण __cdecl nextafterl(long द्विगुण x, long द्विगुण to) {
  प्रत्यागम nextafter(x, to);
}

__CRT_INLINE द्विगुण __cdecl nexttoward(द्विगुण x, long द्विगुण to) {
  प्रत्यागम nextafter(x, to);
}
__CRT_INLINE भिन्न __cdecl nexttowardf(भिन्न x, long द्विगुण to) {
  प्रत्यागम nextafterf(x, to);
}
__CRT_INLINE long द्विगुण __cdecl nexttowardl(long द्विगुण x, long द्विगुण to) {
  प्रत्यागम nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE द्विगुण __cdecl fabs(द्विगुण x) {
  प्रत्यागम x < 0 ? -x : x;
}
__CRT_INLINE भिन्न __cdecl fabsf(भिन्न x) {
  प्रत्यागम x < 0 ? -x : x;
}
__CRT_INLINE long द्विगुण __cdecl fabsl(long द्विगुण x) {
  प्रत्यागम x < 0 ? -x : x;
}


#जइ defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE भिन्न acosf(भिन्न x) { प्रत्यागम acos(x); }
  __CRT_INLINE भिन्न asinf(भिन्न x) { प्रत्यागम asin(x); }
  __CRT_INLINE भिन्न atanf(भिन्न x) { प्रत्यागम atan(x); }
  __CRT_INLINE भिन्न atan2f(भिन्न x, भिन्न y) { प्रत्यागम atan2(x, y); }
  __CRT_INLINE भिन्न ceilf(भिन्न x) { प्रत्यागम ceil(x); }
  __CRT_INLINE भिन्न cosf(भिन्न x) { प्रत्यागम cos(x); }
  __CRT_INLINE भिन्न coshf(भिन्न x) { प्रत्यागम cosh(x); }
  __CRT_INLINE भिन्न expf(भिन्न x) { प्रत्यागम exp(x); }
  __CRT_INLINE भिन्न floorf(भिन्न x) { प्रत्यागम floor(x); }
  __CRT_INLINE भिन्न fmodf(भिन्न x, भिन्न y) { प्रत्यागम fmod(x, y); }
  __CRT_INLINE भिन्न logf(भिन्न x) { प्रत्यागम log(x); }
  __CRT_INLINE भिन्न logbf(भिन्न x) { प्रत्यागम logb(x); }
  __CRT_INLINE भिन्न log10f(भिन्न x) { प्रत्यागम log10(x); }
  __CRT_INLINE भिन्न modff(भिन्न x, भिन्न *y) { द्विगुण di, df = modf(x, &di); *y = di; प्रत्यागम df; }
  __CRT_INLINE भिन्न powf(भिन्न x, भिन्न y) { प्रत्यागम pow(x, y); }
  __CRT_INLINE भिन्न sinf(भिन्न x) { प्रत्यागम sin(x); }
  __CRT_INLINE भिन्न sinhf(भिन्न x) { प्रत्यागम sinh(x); }
  __CRT_INLINE भिन्न sqrtf(भिन्न x) { प्रत्यागम sqrt(x); }
  __CRT_INLINE भिन्न tanf(भिन्न x) { प्रत्यागम tan(x); }
  __CRT_INLINE भिन्न tanhf(भिन्न x) { प्रत्यागम tanh(x); }
#endif
__CRT_INLINE भिन्न __cdecl asinhf(भिन्न x) { प्रत्यागम asinh(x); }
__CRT_INLINE भिन्न __cdecl acoshf(भिन्न x) { प्रत्यागम acosh(x); }
__CRT_INLINE भिन्न __cdecl atanhf(भिन्न x) { प्रत्यागम atanh(x); }

__CRT_INLINE long द्विगुण __cdecl asinhl(long द्विगुण x) { प्रत्यागम asinh(x); }
__CRT_INLINE long द्विगुण __cdecl acoshl(long द्विगुण x) { प्रत्यागम acosh(x); }
__CRT_INLINE long द्विगुण __cdecl atanhl(long द्विगुण x) { प्रत्यागम atanh(x); }
__CRT_INLINE long द्विगुण __cdecl asinl(long द्विगुण x) { प्रत्यागम asin(x); }
__CRT_INLINE long द्विगुण __cdecl acosl(long द्विगुण x) { प्रत्यागम acos(x); }
__CRT_INLINE long द्विगुण __cdecl atanl(long द्विगुण x) { प्रत्यागम atan(x); }
__CRT_INLINE long द्विगुण __cdecl ceill(long द्विगुण x) { प्रत्यागम ceil(x); }
__CRT_INLINE long द्विगुण __cdecl coshl(long द्विगुण x) { प्रत्यागम cosh(x); }
__CRT_INLINE long द्विगुण __cdecl cosl(long द्विगुण x) { प्रत्यागम cos(x); }
__CRT_INLINE long द्विगुण __cdecl expl(long द्विगुण x) { प्रत्यागम exp(x); }
__CRT_INLINE long द्विगुण __cdecl floorl(long द्विगुण x) { प्रत्यागम floor(x); }
__CRT_INLINE long द्विगुण __cdecl fmodl(long द्विगुण x, long द्विगुण y) { प्रत्यागम fmod(x, y); }
__CRT_INLINE long द्विगुण __cdecl hypotl(long द्विगुण x, long द्विगुण y) { प्रत्यागम hypot(x, y); }
__CRT_INLINE long द्विगुण __cdecl logl(long द्विगुण x) { प्रत्यागम log(x); }
__CRT_INLINE long द्विगुण __cdecl logbl(long द्विगुण x) { प्रत्यागम logb(x); }
__CRT_INLINE long द्विगुण __cdecl log10l(long द्विगुण x) { प्रत्यागम log10(x); }
__CRT_INLINE long द्विगुण __cdecl modfl(long द्विगुण x, long द्विगुण* y) { द्विगुण y1 = *y; x = modf(x, &y1); *y = y1; प्रत्यागम x; }
__CRT_INLINE long द्विगुण __cdecl powl(long द्विगुण x, long द्विगुण y) { प्रत्यागम pow(x, y); }
__CRT_INLINE long द्विगुण __cdecl sinhl(long द्विगुण x) { प्रत्यागम sinh(x); }
__CRT_INLINE long द्विगुण __cdecl sinl(long द्विगुण x) { प्रत्यागम sin(x); }
__CRT_INLINE long द्विगुण __cdecl sqrtl(long द्विगुण x) { प्रत्यागम sqrt(x); }
__CRT_INLINE long द्विगुण __cdecl tanhl(long द्विगुण x) { प्रत्यागम tanh(x); }
__CRT_INLINE long द्विगुण __cdecl tanl(long द्विगुण x) { प्रत्यागम tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE द्विगुण __cdecl log1p(द्विगुण x) {
  द्विगुण u = 1.0 + x;
  प्रत्यागम u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE भिन्न __cdecl log1pf(भिन्न x) {
  भिन्न u = 1.0f + x;
  प्रत्यागम u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long द्विगुण __cdecl log1pl(long द्विगुण x) {
  प्रत्यागम log1p(x);
}


__CRT_INLINE द्विगुण __cdecl expm1(द्विगुण x) {
  जइ (x > 0.0024 || x < -0.0024) प्रत्यागम exp(x) - 1.0;
  प्रत्यागम x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE भिन्न __cdecl expm1f(भिन्न x) {
  जइ (x > 0.085f || x < -0.085f) प्रत्यागम expf(x) - 1.0f;
  प्रत्यागम x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long द्विगुण __cdecl expm1l(long द्विगुण x) {
  प्रत्यागम expm1(x);
}


__CRT_INLINE द्विगुण __cdecl cbrt(द्विगुण x) {
  प्रत्यागम x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE भिन्न __cdecl cbrtf(भिन्न x) {
  प्रत्यागम x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long द्विगुण __cdecl cbrtl(long द्विगुण x) {
  प्रत्यागम cbrt(x);
}


__CRT_INLINE द्विगुण __cdecl log2(द्विगुण x) {
  प्रत्यागम log(x) * 1.442695040888963407;
}
__CRT_INLINE भिन्न __cdecl log2f(भिन्न x) {
  प्रत्यागम log(x) * 1.442695040888963407;
}
__CRT_INLINE long द्विगुण __cdecl log2l(long द्विगुण x) {
  प्रत्यागम log(x) * 1.442695040888963407;
}


__CRT_INLINE द्विगुण __cdecl exp2(द्विगुण x) {
  प्रत्यागम exp(x * 0.693147180559945309);
}
__CRT_INLINE भिन्न __cdecl exp2f(भिन्न x) {
  प्रत्यागम exp(x * 0.693147180559945309);
}
__CRT_INLINE long द्विगुण __cdecl exp2l(long द्विगुण x) {
  प्रत्यागम exp(x * 0.693147180559945309);
}


__CRT_INLINE पूर्णाङ्क __cdecl ilogb(द्विगुण x) {
  प्रत्यागम (पूर्णाङ्क) logb(x);
}
__CRT_INLINE पूर्णाङ्क __cdecl ilogbf(भिन्न x) {
  प्रत्यागम (पूर्णाङ्क) logbf(x);
}
__CRT_INLINE पूर्णाङ्क __cdecl ilogbl(long द्विगुण x) {
  प्रत्यागम (पूर्णाङ्क) logb(x);
}


__CRT_INLINE द्विगुण __cdecl fdim(द्विगुण x, द्विगुण y) {
  जइ (isnan(x) || isnan(y)) प्रत्यागम NAN;
  प्रत्यागम x > y ? x - y : 0;
}
__CRT_INLINE भिन्न __cdecl fdimf(भिन्न x, भिन्न y) {
  जइ (isnan(x) || isnan(y)) प्रत्यागम NAN;
  प्रत्यागम x > y ? x - y : 0;
}
__CRT_INLINE long द्विगुण __cdecl fdiml(long द्विगुण x, long द्विगुण y) {
  जइ (isnan(x) || isnan(y)) प्रत्यागम NAN;
  प्रत्यागम x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE द्विगुण __cdecl tgamma(द्विगुण x) {
  द्विगुण m = 1.0, t = 3.14159265358979323;
  जइ (x == floor(x)) {
    जइ (x == 0) प्रत्यागम INFINITY;
    जइ (x < 0) प्रत्यागम NAN;
    जइ (x < 26) { प्रति (द्विगुण k = 2; k < x; ++k) m *= k; प्रत्यागम m; }
  }
  जइ (x < 0.5)
    प्रत्यागम t / (sin(t*x)*tgamma(1.0 - x));
  जइ (x > 12.0)
    प्रत्यागम exp(lgamma(x));

  स्थिर ध्रुव द्विगुण c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  प्रति (पूर्णाङ्क k = 0; k < 8; ++k) m += c[k] / (x + k);
  प्रत्यागम 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE द्विगुण __cdecl lgamma(द्विगुण x) {
  जइ (x < 12.0) {
    जइ (x <= 0.0 && x == floor(x)) प्रत्यागम INFINITY;
    x = tgamma(x);
    प्रत्यागम log(x < 0.0 ? -x : x);
  }
  स्थिर ध्रुव द्विगुण c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  द्विगुण m = -3617.0/122400.0, t = 1.0 / (x*x);
  प्रति (पूर्णाङ्क k = 6; k >= 0; --k) m = m*t + c[k];
  प्रत्यागम (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE भिन्न __cdecl tgammaf(भिन्न x) {
  प्रत्यागम tgamma(x);
}
__CRT_INLINE भिन्न __cdecl lgammaf(भिन्न x) {
  प्रत्यागम lgamma(x);
}
__CRT_INLINE long द्विगुण __cdecl tgammal(long द्विगुण x) {
  प्रत्यागम tgamma(x);
}
__CRT_INLINE long द्विगुण __cdecl lgammal(long द्विगुण x) {
  प्रत्यागम lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
