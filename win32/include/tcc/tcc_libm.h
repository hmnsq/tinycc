#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TCC_LIBM_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TCC_LIBM_H_

#ਅਨ੍ਤਰ੍ਭਾਵ "../math.h"
#ਅਨ੍ਤਰ੍ਭਾਵ "../stdint.h"

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

__CRT_INLINE ਪੂਰਨ __cdecl __fpclassify (ਦੁੱਗਣਾ x) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u = {.f = x};
  ਪੂਰਨ e = u.i>>52 & 0x7ff;
  ਜੇ (!e) ਵਾਪਸ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ਜੇ (e==0x7ff) ਵਾਪਸ u.i<<12 ? FP_NAN : FP_INFINITE;
  ਵਾਪਸ FP_NORMAL;
}

__CRT_INLINE ਪੂਰਨ __cdecl __fpclassifyf (ਦਸ਼ਮਲਵ x) {
  ਸੰਘ {ਦਸ਼ਮਲਵ f; uint32_t i;} u = {.f = x};
  ਪੂਰਨ e = u.i>>23 & 0xff;
  ਜੇ (!e) ਵਾਪਸ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ਜੇ (e==0xff) ਵਾਪਸ u.i<<9 ? FP_NAN : FP_INFINITE;
  ਵਾਪਸ FP_NORMAL;
}

__CRT_INLINE ਪੂਰਨ __cdecl __fpclassifyl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ __fpclassify(x);
}


/* signbit */

__CRT_INLINE ਪੂਰਨ __cdecl __signbit (ਦੁੱਗਣਾ x) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u = {.f = x};
  ਵਾਪਸ u.i>>63;
}

__CRT_INLINE ਪੂਰਨ __cdecl __signbitf (ਦਸ਼ਮਲਵ x) {
  ਸੰਘ {ਦਸ਼ਮਲਵ f; uint32_t i; } u = {.f = x};
  ਵਾਪਸ u.i>>31;
}

__CRT_INLINE ਪੂਰਨ __cdecl __signbitl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ __signbit(x);
}


/* fmin*, fmax* */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE ਦੁੱਗਣਾ __cdecl fmin (ਦੁੱਗਣਾ x, ਦੁੱਗਣਾ y) {
  ਵਾਪਸ TCCFP_FMIN_EVAL;
}

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl fminf (ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y) {
  ਵਾਪਸ TCCFP_FMIN_EVAL;
}

__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fminl (ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ y) {
  ਵਾਪਸ TCCFP_FMIN_EVAL;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE ਦੁੱਗਣਾ __cdecl fmax (ਦੁੱਗਣਾ x, ਦੁੱਗਣਾ y) {
  ਵਾਪਸ TCCFP_FMAX_EVAL;
}

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl fmaxf (ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y) {
  ਵਾਪਸ TCCFP_FMAX_EVAL;
}

__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fmaxl (ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ y) {
  ਵਾਪਸ TCCFP_FMAX_EVAL;
}


/* *round* */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCFP_FORCE_EVAL(x) ਕਰੋ {  \
  ਅਸਥਿਰ typeof(x) __x;         \
  __x = (x);                      \
} ਜਦੋਂ(0)

__CRT_INLINE ਦੁੱਗਣਾ __cdecl ਗੇੜਾ (ਦੁੱਗਣਾ x) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u = {.f = x};
  ਪੂਰਨ e = u.i >> 52 & 0x7ff;
  ਦੁੱਗਣਾ y;

  ਜੇ (e >= 0x3ff+52)
    ਵਾਪਸ x;
  ਜੇ (u.i >> 63)
    x = -x;
  ਜੇ (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    ਵਾਪਸ 0*u.f;
  }
  y = (ਦੁੱਗਣਾ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  ਵਾਪਸ (u.i >> 63) ? -y : y;
}

__CRT_INLINE ਲੰਮਾ __cdecl lround (ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}

__CRT_INLINE ਲੰਮਾ ਲੰਮਾ __cdecl llround (ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl roundf (ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}

__CRT_INLINE ਲੰਮਾ __cdecl lroundf (ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}

__CRT_INLINE ਲੰਮਾ ਲੰਮਾ __cdecl llroundf (ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}

__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl roundl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}

__CRT_INLINE ਲੰਮਾ __cdecl lroundl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}

__CRT_INLINE ਲੰਮਾ ਲੰਮਾ __cdecl llroundl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਗੇੜਾ(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl asinh(ਦੁੱਗਣਾ x) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u = {.f = x};
  ਬਿਨਾਨਿਸ਼ਾਨੀ e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ਜੇ (e >= 0x3ff + 26) x = ਲਘੂਗਣਕ(x) + 0.693147180559945309;
  ਨਹੀਂਤਾਂ ਜੇ (e >= 0x3ff + 1) x = ਲਘੂਗਣਕ(2*x + 1 / (ਵਰਗਮੂਲ(x*x + 1) + x)); /* |x|>=2 */
  ਨਹੀਂਤਾਂ ਜੇ (e >= 0x3ff - 26) x = log1p(x + x*x / (ਵਰਗਮੂਲ(x*x + 1) + 1));
  ਨਹੀਂਤਾਂ TCCFP_FORCE_EVAL(x + 0x1p120f);
  ਵਾਪਸ s ? -x : x;
}

__CRT_INLINE ਦੁੱਗਣਾ __cdecl acosh(ਦੁੱਗਣਾ x) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u = {.f = x};
  ਬਿਨਾਨਿਸ਼ਾਨੀ e = u.i >> 52 & 0x7ff;
  ਜੇ (e < 0x3ff + 1) ਵਾਪਸ --x, log1p(x + ਵਰਗਮੂਲ(x*x + 2*x)); /* |x|<2 */
  ਜੇ (e < 0x3ff + 26) ਵਾਪਸ ਲਘੂਗਣਕ(2*x - 1 / (x + ਵਰਗਮੂਲ(x*x - 1)));
  ਵਾਪਸ ਲਘੂਗਣਕ(x) + 0.693147180559945309;
}

__CRT_INLINE ਦੁੱਗਣਾ __cdecl atanh(ਦੁੱਗਣਾ x) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u = {.f = x};
  ਬਿਨਾਨਿਸ਼ਾਨੀ e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ਜੇ (e < 0x3ff - 1) {
    ਜੇ (e < 0x3ff - 32) { ਜੇ (e == 0) TCCFP_FORCE_EVAL((ਦਸ਼ਮਲਵ)x); }
    ਨਹੀਂਤਾਂ x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } ਨਹੀਂਤਾਂ x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  ਵਾਪਸ s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl scalbn(ਦੁੱਗਣਾ x, ਪੂਰਨ n) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u;
  ਜੇ (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    ਜੇ (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      ਜੇ (n > 1023) n = 1023;
    }
  } ਨਹੀਂਤਾਂ ਜੇ (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    ਜੇ (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      ਜੇ (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  ਵਾਪਸ x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl frexp(ਦੁੱਗਣਾ x, ਪੂਰਨ *e) {
  ਸੰਘ {ਦੁੱਗਣਾ f; uint64_t i;} u = {.f = x};
  ਪੂਰਨ ee = u.i>>52 & 0x7ff;
  ਜੇ (!ee) {
    ਜੇ (x) x = frexp(x*0x1p64, e), *e -= 64;
    ਨਹੀਂਤਾਂ *e = 0;
    ਵਾਪਸ x;
  } ਨਹੀਂਤਾਂ ਜੇ (ee == 0x7ff)
    ਵਾਪਸ x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  ਵਾਪਸ u.f;
}

/* MUSL nan */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl nan(ਅਚਲ ਅੱਖਰ* s) {
  ਵਾਪਸ NAN;
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl nanf(ਅਚਲ ਅੱਖਰ* s) {
  ਵਾਪਸ NAN;
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl nanl(ਅਚਲ ਅੱਖਰ* s) {
  ਵਾਪਸ NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl scalbnf(ਦਸ਼ਮਲਵ x, ਪੂਰਨ n) {
  ਵਾਪਸ scalbn(x, n);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl scalbnl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਪੂਰਨ n) {
  ਵਾਪਸ scalbn(x, n);
}

__CRT_INLINE ਦੁੱਗਣਾ __cdecl scalbln(ਦੁੱਗਣਾ x, ਲੰਮਾ n) {
  ਵਾਪਸ scalbn(x, n);
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl scalblnf(ਦਸ਼ਮਲਵ x, ਲੰਮਾ n) {
  ਵਾਪਸ scalbn(x, n);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl scalblnl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ n) {
  ਵਾਪਸ scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl ldexp(ਦੁੱਗਣਾ x, ਪੂਰਨ expn) {
  ਵਾਪਸ scalbn(x, expn);
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl ldexpf(ਦਸ਼ਮਲਵ x, ਪੂਰਨ expn) {
  ਵਾਪਸ scalbn(x, expn);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl ldexpl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਪੂਰਨ expn) {
  ਵਾਪਸ scalbn(x, expn);
}

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl frexpf(ਦਸ਼ਮਲਵ x, ਪੂਰਨ *y) {
  ਵਾਪਸ frexp(x, y);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl frexpl (ਲੰਮਾ ਦੁੱਗਣਾ x, ਪੂਰਨ* y) {
  ਵਾਪਸ frexp(x, y);
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl rint(ਦੁੱਗਣਾ x) {
ਦੁੱਗਣਾ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  ਵਾਪਸ retval;
}

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl rintf(ਦਸ਼ਮਲਵ x) {
  ਦਸ਼ਮਲਵ retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   ਵਾਪਸ retval;
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl rintl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE ਲੰਮਾ __cdecl lrint(ਦੁੱਗਣਾ x) {
  ਲੰਮਾ retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ਵਾਪਸ retval;
}

__CRT_INLINE ਲੰਮਾ __cdecl lrintf(ਦਸ਼ਮਲਵ x) {
  ਲੰਮਾ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ਵਾਪਸ retval;
}

__CRT_INLINE ਲੰਮਾ __cdecl lrintl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ lrint(x);
}


__CRT_INLINE ਲੰਮਾ ਲੰਮਾ __cdecl llrint(ਦੁੱਗਣਾ x) {
ਲੰਮਾ ਲੰਮਾ retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ਵਾਪਸ retval;
}

__CRT_INLINE ਲੰਮਾ ਲੰਮਾ __cdecl llrintf(ਦਸ਼ਮਲਵ x) {
  ਲੰਮਾ ਲੰਮਾ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ਵਾਪਸ retval;
}

__CRT_INLINE ਲੰਮਾ ਲੰਮਾ __cdecl llrintl (ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ llrint(x);
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl trunc(ਦੁੱਗਣਾ _x) {
  ਦੁੱਗਣਾ retval;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ saved_cw;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ tmp_cw;
  __asm__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
  tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
    | FE_TOWARDZERO;
  __asm__ ("fldcw %0;" : : "m" (tmp_cw));
  __asm__ ("fldl  %1;"
           "frndint;"
           "fstpl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
  __asm__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
  ਵਾਪਸ retval;
}

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl truncf(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ (ਦਸ਼ਮਲਵ) ((intptr_t) x);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl truncl(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ trunc(x);
}


__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl nextafterl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ ਮੰਜ਼ਿਲ) {
  ਵਾਪਸ nextafter(x, ਮੰਜ਼ਿਲ);
}

__CRT_INLINE ਦੁੱਗਣਾ __cdecl nexttoward(ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ ਮੰਜ਼ਿਲ) {
  ਵਾਪਸ nextafter(x, ਮੰਜ਼ਿਲ);
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl nexttowardf(ਦਸ਼ਮਲਵ x, ਲੰਮਾ ਦੁੱਗਣਾ ਮੰਜ਼ਿਲ) {
  ਵਾਪਸ nextafterf(x, ਮੰਜ਼ਿਲ);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl nexttowardl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ ਮੰਜ਼ਿਲ) {
  ਵਾਪਸ nextafter(x, ਮੰਜ਼ਿਲ);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl fabs(ਦੁੱਗਣਾ x) {
  ਵਾਪਸ x < 0 ? -x : x;
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl fabsf(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ x < 0 ? -x : x;
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fabsl(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ x < 0 ? -x : x;
}


#ਜੇ defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE ਦਸ਼ਮਲਵ acosf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ acos(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ asinf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ asin(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ atanf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ atan(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ atan2f(ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y) { ਵਾਪਸ atan2(x, y); }
  __CRT_INLINE ਦਸ਼ਮਲਵ ceilf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ ceil(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ cosf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ ਕੋਜੀਵਾ(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ coshf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ cosh(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ expf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ ਘਾਤਾਂਕ(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ floorf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ floor(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ fmodf(ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y) { ਵਾਪਸ fmod(x, y); }
  __CRT_INLINE ਦਸ਼ਮਲਵ logf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ ਲਘੂਗਣਕ(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ logbf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ logb(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ log10f(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ log10(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ modff(ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ *y) { ਦੁੱਗਣਾ di, df = modf(x, &di); *y = di; ਵਾਪਸ df; }
  __CRT_INLINE ਦਸ਼ਮਲਵ powf(ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y) { ਵਾਪਸ ਘਾਤ(x, y); }
  __CRT_INLINE ਦਸ਼ਮਲਵ sinf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ ਜੀਵਾ(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ sinhf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ sinh(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ sqrtf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ ਵਰਗਮੂਲ(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ tanf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ tan(x); }
  __CRT_INLINE ਦਸ਼ਮਲਵ tanhf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ tanh(x); }
#ਜੇ_ਅੰਤ
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl asinhf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ asinh(x); }
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl acoshf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ acosh(x); }
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl atanhf(ਦਸ਼ਮਲਵ x) { ਵਾਪਸ atanh(x); }

__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl asinhl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ asinh(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl acoshl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ acosh(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl atanhl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ atanh(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl asinl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ asin(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl acosl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ acos(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl atanl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ atan(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl ceill(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ ceil(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl coshl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ cosh(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl cosl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ ਕੋਜੀਵਾ(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl expl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ ਘਾਤਾਂਕ(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl floorl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ floor(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fmodl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ y) { ਵਾਪਸ fmod(x, y); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl hypotl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ y) { ਵਾਪਸ hypot(x, y); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl logl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ ਲਘੂਗਣਕ(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl logbl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ logb(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl log10l(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ log10(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl modfl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ* y) { ਦੁੱਗਣਾ y1 = *y; x = modf(x, &y1); *y = y1; ਵਾਪਸ x; }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl powl(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ y) { ਵਾਪਸ ਘਾਤ(x, y); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl sinhl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ sinh(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl sinl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ ਜੀਵਾ(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl sqrtl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ ਵਰਗਮੂਲ(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl tanhl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ tanh(x); }
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl tanl(ਲੰਮਾ ਦੁੱਗਣਾ x) { ਵਾਪਸ tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl log1p(ਦੁੱਗਣਾ x) {
  ਦੁੱਗਣਾ u = 1.0 + x;
  ਵਾਪਸ u == 1.0 ? x : ਲਘੂਗਣਕ(u)*(x / (u - 1.0));
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl log1pf(ਦਸ਼ਮਲਵ x) {
  ਦਸ਼ਮਲਵ u = 1.0f + x;
  ਵਾਪਸ u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl log1pl(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ log1p(x);
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl expm1(ਦੁੱਗਣਾ x) {
  ਜੇ (x > 0.0024 || x < -0.0024) ਵਾਪਸ ਘਾਤਾਂਕ(x) - 1.0;
  ਵਾਪਸ x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl expm1f(ਦਸ਼ਮਲਵ x) {
  ਜੇ (x > 0.085f || x < -0.085f) ਵਾਪਸ expf(x) - 1.0f;
  ਵਾਪਸ x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl expm1l(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ expm1(x);
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl cbrt(ਦੁੱਗਣਾ x) {
  ਵਾਪਸ x < 0.0 ? -ਘਾਤ(-x, 1/3.0) : ਘਾਤ(x, 1/3.0);
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl cbrtf(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ x < 0.0f ? -ਘਾਤ(-x, 1/3.0) : ਘਾਤ(x, 1/3.0);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl cbrtl(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ cbrt(x);
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl log2(ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਲਘੂਗਣਕ(x) * 1.442695040888963407;
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl log2f(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ ਲਘੂਗਣਕ(x) * 1.442695040888963407;
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl log2l(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਲਘੂਗਣਕ(x) * 1.442695040888963407;
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl exp2(ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਘਾਤਾਂਕ(x * 0.693147180559945309);
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl exp2f(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ ਘਾਤਾਂਕ(x * 0.693147180559945309);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl exp2l(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ ਘਾਤਾਂਕ(x * 0.693147180559945309);
}


__CRT_INLINE ਪੂਰਨ __cdecl ilogb(ਦੁੱਗਣਾ x) {
  ਵਾਪਸ (ਪੂਰਨ) logb(x);
}
__CRT_INLINE ਪੂਰਨ __cdecl ilogbf(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ (ਪੂਰਨ) logbf(x);
}
__CRT_INLINE ਪੂਰਨ __cdecl ilogbl(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ (ਪੂਰਨ) logb(x);
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl fdim(ਦੁੱਗਣਾ x, ਦੁੱਗਣਾ y) {
  ਜੇ (isnan(x) || isnan(y)) ਵਾਪਸ NAN;
  ਵਾਪਸ x > y ? x - y : 0;
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl fdimf(ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y) {
  ਜੇ (isnan(x) || isnan(y)) ਵਾਪਸ NAN;
  ਵਾਪਸ x > y ? x - y : 0;
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fdiml(ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ y) {
  ਜੇ (isnan(x) || isnan(y)) ਵਾਪਸ NAN;
  ਵਾਪਸ x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE ਦੁੱਗਣਾ __cdecl tgamma(ਦੁੱਗਣਾ x) {
  ਦੁੱਗਣਾ m = 1.0, t = 3.14159265358979323;
  ਜੇ (x == floor(x)) {
    ਜੇ (x == 0) ਵਾਪਸ INFINITY;
    ਜੇ (x < 0) ਵਾਪਸ NAN;
    ਜੇ (x < 26) { ਲਈ (ਦੁੱਗਣਾ k = 2; k < x; ++k) m *= k; ਵਾਪਸ m; }
  }
  ਜੇ (x < 0.5)
    ਵਾਪਸ t / (ਜੀਵਾ(t*x)*tgamma(1.0 - x));
  ਜੇ (x > 12.0)
    ਵਾਪਸ ਘਾਤਾਂਕ(lgamma(x));

  ਸਥਿਰ ਅਚਲ ਦੁੱਗਣਾ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  ਲਈ (ਪੂਰਨ k = 0; k < 8; ++k) m += c[k] / (x + k);
  ਵਾਪਸ 2.50662827463100050 * ਘਾਤ(t, x - 0.5)*ਘਾਤਾਂਕ(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE ਦੁੱਗਣਾ __cdecl lgamma(ਦੁੱਗਣਾ x) {
  ਜੇ (x < 12.0) {
    ਜੇ (x <= 0.0 && x == floor(x)) ਵਾਪਸ INFINITY;
    x = tgamma(x);
    ਵਾਪਸ ਲਘੂਗਣਕ(x < 0.0 ? -x : x);
  }
  ਸਥਿਰ ਅਚਲ ਦੁੱਗਣਾ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  ਦੁੱਗਣਾ m = -3617.0/122400.0, t = 1.0 / (x*x);
  ਲਈ (ਪੂਰਨ k = 6; k >= 0; --k) m = m*t + c[k];
  ਵਾਪਸ (x - 0.5)*ਲਘੂਗਣਕ(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl tgammaf(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ tgamma(x);
}
__CRT_INLINE ਦਸ਼ਮਲਵ __cdecl lgammaf(ਦਸ਼ਮਲਵ x) {
  ਵਾਪਸ lgamma(x);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl tgammal(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ tgamma(x);
}
__CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl lgammal(ਲੰਮਾ ਦੁੱਗਣਾ x) {
  ਵਾਪਸ lgamma(x);
}

#ਜੇ_ਅੰਤ /* _TCC_LIBM_H_ */
