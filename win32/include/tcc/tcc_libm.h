#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TCC_LIBM_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _TCC_LIBM_H_

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

__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl __fpclassify (ದ್ವಿಗುಣ x) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಪೂರ್ಣಾಂಕ e = u.i>>52 & 0x7ff;
  ಆದರೆ (!e) ಹಿಂತಿರುಗಿ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ಆದರೆ (e==0x7ff) ಹಿಂತಿರುಗಿ u.i<<12 ? FP_NAN : FP_INFINITE;
  ಹಿಂತಿರುಗಿ FP_NORMAL;
}

__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl __fpclassifyf (ದಶಮಾಂಶ x) {
  ಒಕ್ಕೂಟ {ದಶಮಾಂಶ f; uint32_t i;} u = {.f = x};
  ಪೂರ್ಣಾಂಕ e = u.i>>23 & 0xff;
  ಆದರೆ (!e) ಹಿಂತಿರುಗಿ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ಆದರೆ (e==0xff) ಹಿಂತಿರುಗಿ u.i<<9 ? FP_NAN : FP_INFINITE;
  ಹಿಂತಿರುಗಿ FP_NORMAL;
}

__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl __fpclassifyl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ __fpclassify(x);
}


/* signbit */

__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl __signbit (ದ್ವಿಗುಣ x) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಹಿಂತಿರುಗಿ u.i>>63;
}

__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl __signbitf (ದಶಮಾಂಶ x) {
  ಒಕ್ಕೂಟ {ದಶಮಾಂಶ f; uint32_t i; } u = {.f = x};
  ಹಿಂತಿರುಗಿ u.i>>31;
}

__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl __signbitl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ __signbit(x);
}


/* fmin*, fmax* */

#ವ್ಯಾಖ್ಯಾನಿಸು TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE ದ್ವಿಗುಣ __cdecl fmin (ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y) {
  ಹಿಂತಿರುಗಿ TCCFP_FMIN_EVAL;
}

__CRT_INLINE ದಶಮಾಂಶ __cdecl fminf (ದಶಮಾಂಶ x, ದಶಮಾಂಶ y) {
  ಹಿಂತಿರುಗಿ TCCFP_FMIN_EVAL;
}

__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fminl (ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ y) {
  ಹಿಂತಿರುಗಿ TCCFP_FMIN_EVAL;
}

#ವ್ಯಾಖ್ಯಾನಿಸು TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE ದ್ವಿಗುಣ __cdecl fmax (ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y) {
  ಹಿಂತಿರುಗಿ TCCFP_FMAX_EVAL;
}

__CRT_INLINE ದಶಮಾಂಶ __cdecl fmaxf (ದಶಮಾಂಶ x, ದಶಮಾಂಶ y) {
  ಹಿಂತಿರುಗಿ TCCFP_FMAX_EVAL;
}

__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fmaxl (ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ y) {
  ಹಿಂತಿರುಗಿ TCCFP_FMAX_EVAL;
}


/* *round* */

#ವ್ಯಾಖ್ಯಾನಿಸು TCCFP_FORCE_EVAL(x) ಮಾಡು {  \
  ಅಸ್ಥಿರ typeof(x) __x;         \
  __x = (x);                      \
} ಆಗ(0)

__CRT_INLINE ದ್ವಿಗುಣ __cdecl ಸುತ್ತು (ದ್ವಿಗುಣ x) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಪೂರ್ಣಾಂಕ e = u.i >> 52 & 0x7ff;
  ದ್ವಿಗುಣ y;

  ಆದರೆ (e >= 0x3ff+52)
    ಹಿಂತಿರುಗಿ x;
  ಆದರೆ (u.i >> 63)
    x = -x;
  ಆದರೆ (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    ಹಿಂತಿರುಗಿ 0*u.f;
  }
  y = (ದ್ವಿಗುಣ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  ಹಿಂತಿರುಗಿ (u.i >> 63) ? -y : y;
}

__CRT_INLINE ದೀರ್ಘ __cdecl lround (ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}

__CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ __cdecl llround (ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}

__CRT_INLINE ದಶಮಾಂಶ __cdecl roundf (ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}

__CRT_INLINE ದೀರ್ಘ __cdecl lroundf (ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}

__CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ __cdecl llroundf (ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}

__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl roundl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}

__CRT_INLINE ದೀರ್ಘ __cdecl lroundl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}

__CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ __cdecl llroundl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಸುತ್ತು(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl asinh(ದ್ವಿಗುಣ x) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಚಿಹ್ನೆರಹಿತ e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ಆದರೆ (e >= 0x3ff + 26) x = ಲಘುಗಣಕ(x) + 0.693147180559945309;
  ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (e >= 0x3ff + 1) x = ಲಘುಗಣಕ(2*x + 1 / (ವರ್ಗಮೂಲ(x*x + 1) + x)); /* |x|>=2 */
  ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (e >= 0x3ff - 26) x = log1p(x + x*x / (ವರ್ಗಮೂಲ(x*x + 1) + 1));
  ಇಲ್ಲದಿದ್ದರೆ TCCFP_FORCE_EVAL(x + 0x1p120f);
  ಹಿಂತಿರುಗಿ s ? -x : x;
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl acosh(ದ್ವಿಗುಣ x) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಚಿಹ್ನೆರಹಿತ e = u.i >> 52 & 0x7ff;
  ಆದರೆ (e < 0x3ff + 1) ಹಿಂತಿರುಗಿ --x, log1p(x + ವರ್ಗಮೂಲ(x*x + 2*x)); /* |x|<2 */
  ಆದರೆ (e < 0x3ff + 26) ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(2*x - 1 / (x + ವರ್ಗಮೂಲ(x*x - 1)));
  ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(x) + 0.693147180559945309;
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl atanh(ದ್ವಿಗುಣ x) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಚಿಹ್ನೆರಹಿತ e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ಆದರೆ (e < 0x3ff - 1) {
    ಆದರೆ (e < 0x3ff - 32) { ಆದರೆ (e == 0) TCCFP_FORCE_EVAL((ದಶಮಾಂಶ)x); }
    ಇಲ್ಲದಿದ್ದರೆ x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } ಇಲ್ಲದಿದ್ದರೆ x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  ಹಿಂತಿರುಗಿ s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl scalbn(ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಂಕ n) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u;
  ಆದರೆ (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    ಆದರೆ (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      ಆದರೆ (n > 1023) n = 1023;
    }
  } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    ಆದರೆ (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      ಆದರೆ (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  ಹಿಂತಿರುಗಿ x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl frexp(ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಂಕ *e) {
  ಒಕ್ಕೂಟ {ದ್ವಿಗುಣ f; uint64_t i;} u = {.f = x};
  ಪೂರ್ಣಾಂಕ ee = u.i>>52 & 0x7ff;
  ಆದರೆ (!ee) {
    ಆದರೆ (x) x = frexp(x*0x1p64, e), *e -= 64;
    ಇಲ್ಲದಿದ್ದರೆ *e = 0;
    ಹಿಂತಿರುಗಿ x;
  } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ee == 0x7ff)
    ಹಿಂತಿರುಗಿ x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  ಹಿಂತಿರುಗಿ u.f;
}

/* MUSL nan */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl nan(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* s) {
  ಹಿಂತಿರುಗಿ NAN;
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl nanf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* s) {
  ಹಿಂತಿರುಗಿ NAN;
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl nanl(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* s) {
  ಹಿಂತಿರುಗಿ NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE ದಶಮಾಂಶ __cdecl scalbnf(ದಶಮಾಂಶ x, ಪೂರ್ಣಾಂಕ n) {
  ಹಿಂತಿರುಗಿ scalbn(x, n);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl scalbnl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಂಕ n) {
  ಹಿಂತಿರುಗಿ scalbn(x, n);
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl scalbln(ದ್ವಿಗುಣ x, ದೀರ್ಘ n) {
  ಹಿಂತಿರುಗಿ scalbn(x, n);
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl scalblnf(ದಶಮಾಂಶ x, ದೀರ್ಘ n) {
  ಹಿಂತಿರುಗಿ scalbn(x, n);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl scalblnl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ n) {
  ಹಿಂತಿರುಗಿ scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl ldexp(ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಂಕ expn) {
  ಹಿಂತಿರುಗಿ scalbn(x, expn);
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl ldexpf(ದಶಮಾಂಶ x, ಪೂರ್ಣಾಂಕ expn) {
  ಹಿಂತಿರುಗಿ scalbn(x, expn);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl ldexpl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಂಕ expn) {
  ಹಿಂತಿರುಗಿ scalbn(x, expn);
}

__CRT_INLINE ದಶಮಾಂಶ __cdecl frexpf(ದಶಮಾಂಶ x, ಪೂರ್ಣಾಂಕ *y) {
  ಹಿಂತಿರುಗಿ frexp(x, y);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl frexpl (ದೀರ್ಘ ದ್ವಿಗುಣ x, ಪೂರ್ಣಾಂಕ* y) {
  ಹಿಂತಿರುಗಿ frexp(x, y);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl rint(ದ್ವಿಗುಣ x) {
ದ್ವಿಗುಣ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  ಹಿಂತಿರುಗಿ retval;
}

__CRT_INLINE ದಶಮಾಂಶ __cdecl rintf(ದಶಮಾಂಶ x) {
  ದಶಮಾಂಶ retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   ಹಿಂತಿರುಗಿ retval;
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl rintl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE ದೀರ್ಘ __cdecl lrint(ದ್ವಿಗುಣ x) {
  ದೀರ್ಘ retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ಹಿಂತಿರುಗಿ retval;
}

__CRT_INLINE ದೀರ್ಘ __cdecl lrintf(ದಶಮಾಂಶ x) {
  ದೀರ್ಘ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ಹಿಂತಿರುಗಿ retval;
}

__CRT_INLINE ದೀರ್ಘ __cdecl lrintl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ lrint(x);
}


__CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ __cdecl llrint(ದ್ವಿಗುಣ x) {
ದೀರ್ಘ ದೀರ್ಘ retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ಹಿಂತಿರುಗಿ retval;
}

__CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ __cdecl llrintf(ದಶಮಾಂಶ x) {
  ದೀರ್ಘ ದೀರ್ಘ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ಹಿಂತಿರುಗಿ retval;
}

__CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ __cdecl llrintl (ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ llrint(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl trunc(ದ್ವಿಗುಣ _x) {
  ದ್ವಿಗುಣ retval;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ saved_cw;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ tmp_cw;
  __asm__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
  tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
    | FE_TOWARDZERO;
  __asm__ ("fldcw %0;" : : "m" (tmp_cw));
  __asm__ ("fldl  %1;"
           "frndint;"
           "fstpl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
  __asm__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
  ಹಿಂತಿರುಗಿ retval;
}

__CRT_INLINE ದಶಮಾಂಶ __cdecl truncf(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ (ದಶಮಾಂಶ) ((intptr_t) x);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl truncl(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ trunc(x);
}


__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl nextafterl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ ಗಮ್ಯ) {
  ಹಿಂತಿರುಗಿ nextafter(x, ಗಮ್ಯ);
}

__CRT_INLINE ದ್ವಿಗುಣ __cdecl nexttoward(ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ ಗಮ್ಯ) {
  ಹಿಂತಿರುಗಿ nextafter(x, ಗಮ್ಯ);
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl nexttowardf(ದಶಮಾಂಶ x, ದೀರ್ಘ ದ್ವಿಗುಣ ಗಮ್ಯ) {
  ಹಿಂತಿರುಗಿ nextafterf(x, ಗಮ್ಯ);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl nexttowardl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ ಗಮ್ಯ) {
  ಹಿಂತಿರುಗಿ nextafter(x, ಗಮ್ಯ);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl fabs(ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ x < 0 ? -x : x;
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl fabsf(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ x < 0 ? -x : x;
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fabsl(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ x < 0 ? -x : x;
}


#ಆದರೆ defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE ದಶಮಾಂಶ acosf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ acos(x); }
  __CRT_INLINE ದಶಮಾಂಶ asinf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ asin(x); }
  __CRT_INLINE ದಶಮಾಂಶ atanf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ atan(x); }
  __CRT_INLINE ದಶಮಾಂಶ atan2f(ದಶಮಾಂಶ x, ದಶಮಾಂಶ y) { ಹಿಂತಿರುಗಿ atan2(x, y); }
  __CRT_INLINE ದಶಮಾಂಶ ceilf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ ceil(x); }
  __CRT_INLINE ದಶಮಾಂಶ cosf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ ಕೋಜ್ಯಾ(x); }
  __CRT_INLINE ದಶಮಾಂಶ coshf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ cosh(x); }
  __CRT_INLINE ದಶಮಾಂಶ expf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ ಘಾತಾಂಕ(x); }
  __CRT_INLINE ದಶಮಾಂಶ floorf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ floor(x); }
  __CRT_INLINE ದಶಮಾಂಶ fmodf(ದಶಮಾಂಶ x, ದಶಮಾಂಶ y) { ಹಿಂತಿರುಗಿ fmod(x, y); }
  __CRT_INLINE ದಶಮಾಂಶ logf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(x); }
  __CRT_INLINE ದಶಮಾಂಶ logbf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ logb(x); }
  __CRT_INLINE ದಶಮಾಂಶ log10f(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ log10(x); }
  __CRT_INLINE ದಶಮಾಂಶ modff(ದಶಮಾಂಶ x, ದಶಮಾಂಶ *y) { ದ್ವಿಗುಣ di, df = modf(x, &di); *y = di; ಹಿಂತಿರುಗಿ df; }
  __CRT_INLINE ದಶಮಾಂಶ powf(ದಶಮಾಂಶ x, ದಶಮಾಂಶ y) { ಹಿಂತಿರುಗಿ ಘಾತ(x, y); }
  __CRT_INLINE ದಶಮಾಂಶ sinf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ ಜ್ಯಾ(x); }
  __CRT_INLINE ದಶಮಾಂಶ sinhf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ sinh(x); }
  __CRT_INLINE ದಶಮಾಂಶ sqrtf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ ವರ್ಗಮೂಲ(x); }
  __CRT_INLINE ದಶಮಾಂಶ tanf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ tan(x); }
  __CRT_INLINE ದಶಮಾಂಶ tanhf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ tanh(x); }
#ಆದರೆ_ಅಂತ್ಯ
__CRT_INLINE ದಶಮಾಂಶ __cdecl asinhf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ asinh(x); }
__CRT_INLINE ದಶಮಾಂಶ __cdecl acoshf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ acosh(x); }
__CRT_INLINE ದಶಮಾಂಶ __cdecl atanhf(ದಶಮಾಂಶ x) { ಹಿಂತಿರುಗಿ atanh(x); }

__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl asinhl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ asinh(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl acoshl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ acosh(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl atanhl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ atanh(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl asinl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ asin(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl acosl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ acos(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl atanl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ atan(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl ceill(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ ceil(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl coshl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ cosh(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl cosl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ ಕೋಜ್ಯಾ(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl expl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ ಘಾತಾಂಕ(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl floorl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ floor(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fmodl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ y) { ಹಿಂತಿರುಗಿ fmod(x, y); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl hypotl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ y) { ಹಿಂತಿರುಗಿ hypot(x, y); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl logl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl logbl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ logb(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl log10l(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ log10(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl modfl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ* y) { ದ್ವಿಗುಣ y1 = *y; x = modf(x, &y1); *y = y1; ಹಿಂತಿರುಗಿ x; }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl powl(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ y) { ಹಿಂತಿರುಗಿ ಘಾತ(x, y); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl sinhl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ sinh(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl sinl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ ಜ್ಯಾ(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl sqrtl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ ವರ್ಗಮೂಲ(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl tanhl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ tanh(x); }
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl tanl(ದೀರ್ಘ ದ್ವಿಗುಣ x) { ಹಿಂತಿರುಗಿ tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl log1p(ದ್ವಿಗುಣ x) {
  ದ್ವಿಗುಣ u = 1.0 + x;
  ಹಿಂತಿರುಗಿ u == 1.0 ? x : ಲಘುಗಣಕ(u)*(x / (u - 1.0));
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl log1pf(ದಶಮಾಂಶ x) {
  ದಶಮಾಂಶ u = 1.0f + x;
  ಹಿಂತಿರುಗಿ u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl log1pl(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ log1p(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl expm1(ದ್ವಿಗುಣ x) {
  ಆದರೆ (x > 0.0024 || x < -0.0024) ಹಿಂತಿರುಗಿ ಘಾತಾಂಕ(x) - 1.0;
  ಹಿಂತಿರುಗಿ x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl expm1f(ದಶಮಾಂಶ x) {
  ಆದರೆ (x > 0.085f || x < -0.085f) ಹಿಂತಿರುಗಿ expf(x) - 1.0f;
  ಹಿಂತಿರುಗಿ x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl expm1l(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ expm1(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl cbrt(ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ x < 0.0 ? -ಘಾತ(-x, 1/3.0) : ಘಾತ(x, 1/3.0);
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl cbrtf(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ x < 0.0f ? -ಘಾತ(-x, 1/3.0) : ಘಾತ(x, 1/3.0);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl cbrtl(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ cbrt(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl log2(ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(x) * 1.442695040888963407;
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl log2f(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(x) * 1.442695040888963407;
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl log2l(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(x) * 1.442695040888963407;
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl exp2(ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಘಾತಾಂಕ(x * 0.693147180559945309);
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl exp2f(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ ಘಾತಾಂಕ(x * 0.693147180559945309);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl exp2l(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ ಘಾತಾಂಕ(x * 0.693147180559945309);
}


__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl ilogb(ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ (ಪೂರ್ಣಾಂಕ) logb(x);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl ilogbf(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ (ಪೂರ್ಣಾಂಕ) logbf(x);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl ilogbl(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ (ಪೂರ್ಣಾಂಕ) logb(x);
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl fdim(ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y) {
  ಆದರೆ (isnan(x) || isnan(y)) ಹಿಂತಿರುಗಿ NAN;
  ಹಿಂತಿರುಗಿ x > y ? x - y : 0;
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl fdimf(ದಶಮಾಂಶ x, ದಶಮಾಂಶ y) {
  ಆದರೆ (isnan(x) || isnan(y)) ಹಿಂತಿರುಗಿ NAN;
  ಹಿಂತಿರುಗಿ x > y ? x - y : 0;
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl fdiml(ದೀರ್ಘ ದ್ವಿಗುಣ x, ದೀರ್ಘ ದ್ವಿಗುಣ y) {
  ಆದರೆ (isnan(x) || isnan(y)) ಹಿಂತಿರುಗಿ NAN;
  ಹಿಂತಿರುಗಿ x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE ದ್ವಿಗುಣ __cdecl tgamma(ದ್ವಿಗುಣ x) {
  ದ್ವಿಗುಣ m = 1.0, t = 3.14159265358979323;
  ಆದರೆ (x == floor(x)) {
    ಆದರೆ (x == 0) ಹಿಂತಿರುಗಿ INFINITY;
    ಆದರೆ (x < 0) ಹಿಂತಿರುಗಿ NAN;
    ಆದರೆ (x < 26) { ಗಾಗಿ (ದ್ವಿಗುಣ k = 2; k < x; ++k) m *= k; ಹಿಂತಿರುಗಿ m; }
  }
  ಆದರೆ (x < 0.5)
    ಹಿಂತಿರುಗಿ t / (ಜ್ಯಾ(t*x)*tgamma(1.0 - x));
  ಆದರೆ (x > 12.0)
    ಹಿಂತಿರುಗಿ ಘಾತಾಂಕ(lgamma(x));

  ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ದ್ವಿಗುಣ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ k = 0; k < 8; ++k) m += c[k] / (x + k);
  ಹಿಂತಿರುಗಿ 2.50662827463100050 * ಘಾತ(t, x - 0.5)*ಘಾತಾಂಕ(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE ದ್ವಿಗುಣ __cdecl lgamma(ದ್ವಿಗುಣ x) {
  ಆದರೆ (x < 12.0) {
    ಆದರೆ (x <= 0.0 && x == floor(x)) ಹಿಂತಿರುಗಿ INFINITY;
    x = tgamma(x);
    ಹಿಂತಿರುಗಿ ಲಘುಗಣಕ(x < 0.0 ? -x : x);
  }
  ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ದ್ವಿಗುಣ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  ದ್ವಿಗುಣ m = -3617.0/122400.0, t = 1.0 / (x*x);
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ k = 6; k >= 0; --k) m = m*t + c[k];
  ಹಿಂತಿರುಗಿ (x - 0.5)*ಲಘುಗಣಕ(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE ದಶಮಾಂಶ __cdecl tgammaf(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ tgamma(x);
}
__CRT_INLINE ದಶಮಾಂಶ __cdecl lgammaf(ದಶಮಾಂಶ x) {
  ಹಿಂತಿರುಗಿ lgamma(x);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl tgammal(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ tgamma(x);
}
__CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl lgammal(ದೀರ್ಘ ದ್ವಿಗುಣ x) {
  ಹಿಂತಿರುಗಿ lgamma(x);
}

#ಆದರೆ_ಅಂತ್ಯ /* _TCC_LIBM_H_ */
