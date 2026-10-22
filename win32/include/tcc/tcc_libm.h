#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#ಅನ್ತರ್ಭಾವ "../math.h"
#ಅನ್ತರ್ಭಾವ "../stdint.h"

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

__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl __fpclassify (ದ್ವಿಗುಣ x) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಪೂರ್ಣಾಙ್ಕ e = u.i>>52 & 0x7ff;
  ಯದಿ (!e) ಪ್ರತ್ಯಾಗಮ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ಯದಿ (e==0x7ff) ಪ್ರತ್ಯಾಗಮ u.i<<12 ? FP_NAN : FP_INFINITE;
  ಪ್ರತ್ಯಾಗಮ FP_NORMAL;
}

__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl __fpclassifyf (ಭಿನ್ನ x) {
  ಸಙ್ಘ {ಭಿನ್ನ f; uint32_t i;} u = {.f = x};
  ಪೂರ್ಣಾಙ್ಕ e = u.i>>23 & 0xff;
  ಯದಿ (!e) ಪ್ರತ್ಯಾಗಮ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ಯದಿ (e==0xff) ಪ್ರತ್ಯಾಗಮ u.i<<9 ? FP_NAN : FP_INFINITE;
  ಪ್ರತ್ಯಾಗಮ FP_NORMAL;
}

__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl __fpclassifyl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ __fpclassify(x);
}


/* signbit */

__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl __signbit (ದ್ವಿಗುಣ x) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಪ್ರತ್ಯಾಗಮ u.i>>63;
}

__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl __signbitf (ಭಿನ್ನ x) {
  ಸಙ್ಘ {ಭಿನ್ನ f; uint32_t i; } u = {.f = x};
  ಪ್ರತ್ಯಾಗಮ u.i>>31;
}

__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl __signbitl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE ದ್ವಿಗುಣ __cdecl fmin (ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y) {
  ಪ್ರತ್ಯಾಗಮ TCCFP_FMIN_EVAL;
}

__CRT_INLINE ಭಿನ್ನ __cdecl fminf (ಭಿನ್ನ x, ಭಿನ್ನ y) {
  ಪ್ರತ್ಯಾಗಮ TCCFP_FMIN_EVAL;
}

__CRT_INLINE long ದ್ವಿಗುಣ __cdecl fminl (long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ y) {
  ಪ್ರತ್ಯಾಗಮ TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE ದ್ವಿಗುಣ __cdecl fmax (ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y) {
  ಪ್ರತ್ಯಾಗಮ TCCFP_FMAX_EVAL;
}

__CRT_INLINE ಭಿನ್ನ __cdecl fmaxf (ಭಿನ್ನ x, ಭಿನ್ನ y) {
  ಪ್ರತ್ಯಾಗಮ TCCFP_FMAX_EVAL;
}

__CRT_INLINE long ದ್ವಿಗುಣ __cdecl fmaxl (long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ y) {
  ಪ್ರತ್ಯಾಗಮ TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) ಕುರು {  \
  ಚಞ್ಚಲ typeof(x) __x;         \
  __x = (x);                      \
} ಯಾವತ್(0)

__CRT_INLINE ದ್ವಿಗುಣ __cdecl round (ದ್ವಿಗುಣ x) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಪೂರ್ಣಾಙ್ಕ e = u.i >> 52 & 0x7ff;
  ದ್ವಿಗುಣ y;

  ಯದಿ (e >= 0x3ff+52)
    ಪ್ರತ್ಯಾಗಮ x;
  ಯದಿ (u.i >> 63)
    x = -x;
  ಯದಿ (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    ಪ್ರತ್ಯಾಗಮ 0*u.f;
  }
  y = (ದ್ವಿಗುಣ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  ಪ್ರತ್ಯಾಗಮ (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}

__CRT_INLINE long long __cdecl llround (ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}

__CRT_INLINE ಭಿನ್ನ __cdecl roundf (ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}

__CRT_INLINE long __cdecl lroundf (ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}

__CRT_INLINE long long __cdecl llroundf (ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}

__CRT_INLINE long ದ್ವಿಗುಣ __cdecl roundl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}

__CRT_INLINE long __cdecl lroundl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}

__CRT_INLINE long long __cdecl llroundl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl asinh(ದ್ವಿಗುಣ x) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ಯದಿ (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  ಅನ್ಯಥಾ ಯದಿ (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  ಅನ್ಯಥಾ ಯದಿ (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  ಅನ್ಯಥಾ TCCFP_FORCE_EVAL(x + 0x1p120f);
  ಪ್ರತ್ಯಾಗಮ s ? -x : x;
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl acosh(ದ್ವಿಗುಣ x) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  ಯದಿ (e < 0x3ff + 1) ಪ್ರತ್ಯಾಗಮ --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  ಯದಿ (e < 0x3ff + 26) ಪ್ರತ್ಯಾಗಮ log(2*x - 1 / (x + sqrt(x*x - 1)));
  ಪ್ರತ್ಯಾಗಮ log(x) + 0.693147180559945309;
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl atanh(ದ್ವಿಗುಣ x) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ಯದಿ (e < 0x3ff - 1) {
    ಯದಿ (e < 0x3ff - 32) { ಯದಿ (e == 0) TCCFP_FORCE_EVAL((ಭಿನ್ನ)x); }
    ಅನ್ಯಥಾ x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } ಅನ್ಯಥಾ x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  ಪ್ರತ್ಯಾಗಮ s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl scalbn(ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಙ್ಕ n) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u;
  ಯದಿ (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    ಯದಿ (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      ಯದಿ (n > 1023) n = 1023;
    }
  } ಅನ್ಯಥಾ ಯದಿ (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    ಯದಿ (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      ಯದಿ (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  ಪ್ರತ್ಯಾಗಮ x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl frexp(ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಙ್ಕ *e) {
  ಸಙ್ಘ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಪೂರ್ಣಾಙ್ಕ ee = u.i>>52 & 0x7ff;
  ಯದಿ (!ee) {
    ಯದಿ (x) x = frexp(x*0x1p64, e), *e -= 64;
    ಅನ್ಯಥಾ *e = 0;
    ಪ್ರತ್ಯಾಗಮ x;
  } ಅನ್ಯಥಾ ಯದಿ (ee == 0x7ff)
    ಪ್ರತ್ಯಾಗಮ x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  ಪ್ರತ್ಯಾಗಮ u.f;
}

/* MUSL nan */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl nan(ಧ್ರುವ ವರ್ಣ* s) {
  ಪ್ರತ್ಯಾಗಮ NAN;
}
__CRT_INLINE ಭಿನ್ನ __cdecl nanf(ಧ್ರುವ ವರ್ಣ* s) {
  ಪ್ರತ್ಯಾಗಮ NAN;
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl nanl(ಧ್ರುವ ವರ್ಣ* s) {
  ಪ್ರತ್ಯಾಗಮ NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE ಭಿನ್ನ __cdecl scalbnf(ಭಿನ್ನ x, ಪೂರ್ಣಾಙ್ಕ n) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, n);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl scalbnl(long ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಙ್ಕ n) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, n);
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl scalbln(ದ್ವಿಗುಣ x, long n) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, n);
}
__CRT_INLINE ಭಿನ್ನ __cdecl scalblnf(ಭಿನ್ನ x, long n) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, n);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl scalblnl(long ದ್ವಿಗುಣ x, long n) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl ldexp(ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಙ್ಕ expn) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, expn);
}
__CRT_INLINE ಭಿನ್ನ __cdecl ldexpf(ಭಿನ್ನ x, ಪೂರ್ಣಾಙ್ಕ expn) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, expn);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl ldexpl(long ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಙ್ಕ expn) {
  ಪ್ರತ್ಯಾಗಮ scalbn(x, expn);
}

__CRT_INLINE ಭಿನ್ನ __cdecl frexpf(ಭಿನ್ನ x, ಪೂರ್ಣಾಙ್ಕ *y) {
  ಪ್ರತ್ಯಾಗಮ frexp(x, y);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl frexpl (long ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಙ್ಕ* y) {
  ಪ್ರತ್ಯಾಗಮ frexp(x, y);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl rint(ದ್ವಿಗುಣ x) {
ದ್ವಿಗುಣ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  ಪ್ರತ್ಯಾಗಮ retval;
}

__CRT_INLINE ಭಿನ್ನ __cdecl rintf(ಭಿನ್ನ x) {
  ಭಿನ್ನ retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   ಪ್ರತ್ಯಾಗಮ retval;
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl rintl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(ದ್ವಿಗುಣ x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ಪ್ರತ್ಯಾಗಮ retval;
}

__CRT_INLINE long __cdecl lrintf(ಭಿನ್ನ x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ಪ್ರತ್ಯಾಗಮ retval;
}

__CRT_INLINE long __cdecl lrintl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ lrint(x);
}


__CRT_INLINE long long __cdecl llrint(ದ್ವಿಗುಣ x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ಪ್ರತ್ಯಾಗಮ retval;
}

__CRT_INLINE long long __cdecl llrintf(ಭಿನ್ನ x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ಪ್ರತ್ಯಾಗಮ retval;
}

__CRT_INLINE long long __cdecl llrintl (long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ llrint(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl trunc(ದ್ವಿಗುಣ _x) {
  ದ್ವಿಗುಣ retval;
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
  ಪ್ರತ್ಯಾಗಮ retval;
}

__CRT_INLINE ಭಿನ್ನ __cdecl truncf(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ (ಭಿನ್ನ) ((intptr_t) x);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl truncl(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ trunc(x);
}


__CRT_INLINE long ದ್ವಿಗುಣ __cdecl nextafterl(long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ to) {
  ಪ್ರತ್ಯಾಗಮ nextafter(x, to);
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl nexttoward(ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ to) {
  ಪ್ರತ್ಯಾಗಮ nextafter(x, to);
}
__CRT_INLINE ಭಿನ್ನ __cdecl nexttowardf(ಭಿನ್ನ x, long ದ್ವಿಗುಣ to) {
  ಪ್ರತ್ಯಾಗಮ nextafterf(x, to);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl nexttowardl(long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ to) {
  ಪ್ರತ್ಯಾಗಮ nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl fabs(ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ x < 0 ? -x : x;
}
__CRT_INLINE ಭಿನ್ನ __cdecl fabsf(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ x < 0 ? -x : x;
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl fabsl(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ x < 0 ? -x : x;
}


#ಯದಿ defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE ಭಿನ್ನ acosf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ acos(x); }
  __CRT_INLINE ಭಿನ್ನ asinf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ asin(x); }
  __CRT_INLINE ಭಿನ್ನ atanf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ atan(x); }
  __CRT_INLINE ಭಿನ್ನ atan2f(ಭಿನ್ನ x, ಭಿನ್ನ y) { ಪ್ರತ್ಯಾಗಮ atan2(x, y); }
  __CRT_INLINE ಭಿನ್ನ ceilf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ ceil(x); }
  __CRT_INLINE ಭಿನ್ನ cosf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ cos(x); }
  __CRT_INLINE ಭಿನ್ನ coshf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ cosh(x); }
  __CRT_INLINE ಭಿನ್ನ expf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ exp(x); }
  __CRT_INLINE ಭಿನ್ನ floorf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ floor(x); }
  __CRT_INLINE ಭಿನ್ನ fmodf(ಭಿನ್ನ x, ಭಿನ್ನ y) { ಪ್ರತ್ಯಾಗಮ fmod(x, y); }
  __CRT_INLINE ಭಿನ್ನ logf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ log(x); }
  __CRT_INLINE ಭಿನ್ನ logbf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ logb(x); }
  __CRT_INLINE ಭಿನ್ನ log10f(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ log10(x); }
  __CRT_INLINE ಭಿನ್ನ modff(ಭಿನ್ನ x, ಭಿನ್ನ *y) { ದ್ವಿಗುಣ di, df = modf(x, &di); *y = di; ಪ್ರತ್ಯಾಗಮ df; }
  __CRT_INLINE ಭಿನ್ನ powf(ಭಿನ್ನ x, ಭಿನ್ನ y) { ಪ್ರತ್ಯಾಗಮ pow(x, y); }
  __CRT_INLINE ಭಿನ್ನ sinf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ sin(x); }
  __CRT_INLINE ಭಿನ್ನ sinhf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ sinh(x); }
  __CRT_INLINE ಭಿನ್ನ sqrtf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ sqrt(x); }
  __CRT_INLINE ಭಿನ್ನ tanf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ tan(x); }
  __CRT_INLINE ಭಿನ್ನ tanhf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ tanh(x); }
#endif
__CRT_INLINE ಭಿನ್ನ __cdecl asinhf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ asinh(x); }
__CRT_INLINE ಭಿನ್ನ __cdecl acoshf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ acosh(x); }
__CRT_INLINE ಭಿನ್ನ __cdecl atanhf(ಭಿನ್ನ x) { ಪ್ರತ್ಯಾಗಮ atanh(x); }

__CRT_INLINE long ದ್ವಿಗುಣ __cdecl asinhl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ asinh(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl acoshl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ acosh(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl atanhl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ atanh(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl asinl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ asin(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl acosl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ acos(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl atanl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ atan(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl ceill(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ ceil(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl coshl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ cosh(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl cosl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ cos(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl expl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ exp(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl floorl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ floor(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl fmodl(long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ y) { ಪ್ರತ್ಯಾಗಮ fmod(x, y); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl hypotl(long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ y) { ಪ್ರತ್ಯಾಗಮ hypot(x, y); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl logl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ log(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl logbl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ logb(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl log10l(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ log10(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl modfl(long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ* y) { ದ್ವಿಗುಣ y1 = *y; x = modf(x, &y1); *y = y1; ಪ್ರತ್ಯಾಗಮ x; }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl powl(long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ y) { ಪ್ರತ್ಯಾಗಮ pow(x, y); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl sinhl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ sinh(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl sinl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ sin(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl sqrtl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ sqrt(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl tanhl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ tanh(x); }
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl tanl(long ದ್ವಿಗುಣ x) { ಪ್ರತ್ಯಾಗಮ tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl log1p(ದ್ವಿಗುಣ x) {
  ದ್ವಿಗುಣ u = 1.0 + x;
  ಪ್ರತ್ಯಾಗಮ u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE ಭಿನ್ನ __cdecl log1pf(ಭಿನ್ನ x) {
  ಭಿನ್ನ u = 1.0f + x;
  ಪ್ರತ್ಯಾಗಮ u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl log1pl(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ log1p(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl expm1(ದ್ವಿಗುಣ x) {
  ಯದಿ (x > 0.0024 || x < -0.0024) ಪ್ರತ್ಯಾಗಮ exp(x) - 1.0;
  ಪ್ರತ್ಯಾಗಮ x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE ಭಿನ್ನ __cdecl expm1f(ಭಿನ್ನ x) {
  ಯದಿ (x > 0.085f || x < -0.085f) ಪ್ರತ್ಯಾಗಮ expf(x) - 1.0f;
  ಪ್ರತ್ಯಾಗಮ x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl expm1l(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ expm1(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl cbrt(ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE ಭಿನ್ನ __cdecl cbrtf(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl cbrtl(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ cbrt(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl log2(ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ log(x) * 1.442695040888963407;
}
__CRT_INLINE ಭಿನ್ನ __cdecl log2f(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ log(x) * 1.442695040888963407;
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl log2l(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ log(x) * 1.442695040888963407;
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl exp2(ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ exp(x * 0.693147180559945309);
}
__CRT_INLINE ಭಿನ್ನ __cdecl exp2f(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ exp(x * 0.693147180559945309);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl exp2l(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ exp(x * 0.693147180559945309);
}


__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl ilogb(ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ (ಪೂರ್ಣಾಙ್ಕ) logb(x);
}
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl ilogbf(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ (ಪೂರ್ಣಾಙ್ಕ) logbf(x);
}
__CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl ilogbl(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ (ಪೂರ್ಣಾಙ್ಕ) logb(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl fdim(ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y) {
  ಯದಿ (isnan(x) || isnan(y)) ಪ್ರತ್ಯಾಗಮ NAN;
  ಪ್ರತ್ಯಾಗಮ x > y ? x - y : 0;
}
__CRT_INLINE ಭಿನ್ನ __cdecl fdimf(ಭಿನ್ನ x, ಭಿನ್ನ y) {
  ಯದಿ (isnan(x) || isnan(y)) ಪ್ರತ್ಯಾಗಮ NAN;
  ಪ್ರತ್ಯಾಗಮ x > y ? x - y : 0;
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl fdiml(long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ y) {
  ಯದಿ (isnan(x) || isnan(y)) ಪ್ರತ್ಯಾಗಮ NAN;
  ಪ್ರತ್ಯಾಗಮ x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl tgamma(ದ್ವಿಗುಣ x) {
  ದ್ವಿಗುಣ m = 1.0, t = 3.14159265358979323;
  ಯದಿ (x == floor(x)) {
    ಯದಿ (x == 0) ಪ್ರತ್ಯಾಗಮ INFINITY;
    ಯದಿ (x < 0) ಪ್ರತ್ಯಾಗಮ NAN;
    ಯದಿ (x < 26) { ಪ್ರತಿ (ದ್ವಿಗುಣ k = 2; k < x; ++k) m *= k; ಪ್ರತ್ಯಾಗಮ m; }
  }
  ಯದಿ (x < 0.5)
    ಪ್ರತ್ಯಾಗಮ t / (sin(t*x)*tgamma(1.0 - x));
  ಯದಿ (x > 12.0)
    ಪ್ರತ್ಯಾಗಮ exp(lgamma(x));

  ಸ್ಥಿರ ಧ್ರುವ ದ್ವಿಗುಣ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  ಪ್ರತಿ (ಪೂರ್ಣಾಙ್ಕ k = 0; k < 8; ++k) m += c[k] / (x + k);
  ಪ್ರತ್ಯಾಗಮ 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl lgamma(ದ್ವಿಗುಣ x) {
  ಯದಿ (x < 12.0) {
    ಯದಿ (x <= 0.0 && x == floor(x)) ಪ್ರತ್ಯಾಗಮ INFINITY;
    x = tgamma(x);
    ಪ್ರತ್ಯಾಗಮ log(x < 0.0 ? -x : x);
  }
  ಸ್ಥಿರ ಧ್ರುವ ದ್ವಿಗುಣ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  ದ್ವಿಗುಣ m = -3617.0/122400.0, t = 1.0 / (x*x);
  ಪ್ರತಿ (ಪೂರ್ಣಾಙ್ಕ k = 6; k >= 0; --k) m = m*t + c[k];
  ಪ್ರತ್ಯಾಗಮ (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE ಭಿನ್ನ __cdecl tgammaf(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ tgamma(x);
}
__CRT_INLINE ಭಿನ್ನ __cdecl lgammaf(ಭಿನ್ನ x) {
  ಪ್ರತ್ಯಾಗಮ lgamma(x);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl tgammal(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ tgamma(x);
}
__CRT_INLINE long ದ್ವಿಗುಣ __cdecl lgammal(long ದ್ವಿಗುಣ x) {
  ಪ್ರತ್ಯಾಗಮ lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
