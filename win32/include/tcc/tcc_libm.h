#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#അന്തര്ഭാവ "../math.h"
#അന്തര്ഭാവ "../stdint.h"

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

__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl __fpclassify (ഇരട്ട x) {
  സംഘം {ഇരട്ട f; uint64_t i;} u = {.f = x};
  പൂർണ്ണസംഖ്യ e = u.i>>52 & 0x7ff;
  എങ്കിൽ (!e) തിരികെ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  എങ്കിൽ (e==0x7ff) തിരികെ u.i<<12 ? FP_NAN : FP_INFINITE;
  തിരികെ FP_NORMAL;
}

__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl __fpclassifyf (ദശാംശം x) {
  സംഘം {ദശാംശം f; uint32_t i;} u = {.f = x};
  പൂർണ്ണസംഖ്യ e = u.i>>23 & 0xff;
  എങ്കിൽ (!e) തിരികെ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  എങ്കിൽ (e==0xff) തിരികെ u.i<<9 ? FP_NAN : FP_INFINITE;
  തിരികെ FP_NORMAL;
}

__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl __fpclassifyl (long ഇരട്ട x) {
  തിരികെ __fpclassify(x);
}


/* signbit */

__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl __signbit (ഇരട്ട x) {
  സംഘം {ഇരട്ട f; uint64_t i;} u = {.f = x};
  തിരികെ u.i>>63;
}

__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl __signbitf (ദശാംശം x) {
  സംഘം {ദശാംശം f; uint32_t i; } u = {.f = x};
  തിരികെ u.i>>31;
}

__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl __signbitl (long ഇരട്ട x) {
  തിരികെ __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE ഇരട്ട __cdecl fmin (ഇരട്ട x, ഇരട്ട y) {
  തിരികെ TCCFP_FMIN_EVAL;
}

__CRT_INLINE ദശാംശം __cdecl fminf (ദശാംശം x, ദശാംശം y) {
  തിരികെ TCCFP_FMIN_EVAL;
}

__CRT_INLINE long ഇരട്ട __cdecl fminl (long ഇരട്ട x, long ഇരട്ട y) {
  തിരികെ TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE ഇരട്ട __cdecl fmax (ഇരട്ട x, ഇരട്ട y) {
  തിരികെ TCCFP_FMAX_EVAL;
}

__CRT_INLINE ദശാംശം __cdecl fmaxf (ദശാംശം x, ദശാംശം y) {
  തിരികെ TCCFP_FMAX_EVAL;
}

__CRT_INLINE long ഇരട്ട __cdecl fmaxl (long ഇരട്ട x, long ഇരട്ട y) {
  തിരികെ TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) ചെയ്യുക {  \
  അസ്ഥിര typeof(x) __x;         \
  __x = (x);                      \
} ആകുമ്പോൾ(0)

__CRT_INLINE ഇരട്ട __cdecl round (ഇരട്ട x) {
  സംഘം {ഇരട്ട f; uint64_t i;} u = {.f = x};
  പൂർണ്ണസംഖ്യ e = u.i >> 52 & 0x7ff;
  ഇരട്ട y;

  എങ്കിൽ (e >= 0x3ff+52)
    തിരികെ x;
  എങ്കിൽ (u.i >> 63)
    x = -x;
  എങ്കിൽ (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    തിരികെ 0*u.f;
  }
  y = (ഇരട്ട)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  തിരികെ (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (ഇരട്ട x) {
  തിരികെ round(x);
}

__CRT_INLINE long long __cdecl llround (ഇരട്ട x) {
  തിരികെ round(x);
}

__CRT_INLINE ദശാംശം __cdecl roundf (ദശാംശം x) {
  തിരികെ round(x);
}

__CRT_INLINE long __cdecl lroundf (ദശാംശം x) {
  തിരികെ round(x);
}

__CRT_INLINE long long __cdecl llroundf (ദശാംശം x) {
  തിരികെ round(x);
}

__CRT_INLINE long ഇരട്ട __cdecl roundl (long ഇരട്ട x) {
  തിരികെ round(x);
}

__CRT_INLINE long __cdecl lroundl (long ഇരട്ട x) {
  തിരികെ round(x);
}

__CRT_INLINE long long __cdecl llroundl (long ഇരട്ട x) {
  തിരികെ round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE ഇരട്ട __cdecl asinh(ഇരട്ട x) {
  സംഘം {ഇരട്ട f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  എങ്കിൽ (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  അല്ലെങ്കിൽ എങ്കിൽ (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  അല്ലെങ്കിൽ എങ്കിൽ (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  അല്ലെങ്കിൽ TCCFP_FORCE_EVAL(x + 0x1p120f);
  തിരികെ s ? -x : x;
}

__CRT_INLINE ഇരട്ട __cdecl acosh(ഇരട്ട x) {
  സംഘം {ഇരട്ട f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  എങ്കിൽ (e < 0x3ff + 1) തിരികെ --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  എങ്കിൽ (e < 0x3ff + 26) തിരികെ log(2*x - 1 / (x + sqrt(x*x - 1)));
  തിരികെ log(x) + 0.693147180559945309;
}

__CRT_INLINE ഇരട്ട __cdecl atanh(ഇരട്ട x) {
  സംഘം {ഇരട്ട f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  എങ്കിൽ (e < 0x3ff - 1) {
    എങ്കിൽ (e < 0x3ff - 32) { എങ്കിൽ (e == 0) TCCFP_FORCE_EVAL((ദശാംശം)x); }
    അല്ലെങ്കിൽ x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } അല്ലെങ്കിൽ x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  തിരികെ s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE ഇരട്ട __cdecl scalbn(ഇരട്ട x, പൂർണ്ണസംഖ്യ n) {
  സംഘം {ഇരട്ട f; uint64_t i;} u;
  എങ്കിൽ (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    എങ്കിൽ (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      എങ്കിൽ (n > 1023) n = 1023;
    }
  } അല്ലെങ്കിൽ എങ്കിൽ (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    എങ്കിൽ (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      എങ്കിൽ (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  തിരികെ x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE ഇരട്ട __cdecl frexp(ഇരട്ട x, പൂർണ്ണസംഖ്യ *e) {
  സംഘം {ഇരട്ട f; uint64_t i;} u = {.f = x};
  പൂർണ്ണസംഖ്യ ee = u.i>>52 & 0x7ff;
  എങ്കിൽ (!ee) {
    എങ്കിൽ (x) x = frexp(x*0x1p64, e), *e -= 64;
    അല്ലെങ്കിൽ *e = 0;
    തിരികെ x;
  } അല്ലെങ്കിൽ എങ്കിൽ (ee == 0x7ff)
    തിരികെ x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  തിരികെ u.f;
}

/* MUSL nan */

__CRT_INLINE ഇരട്ട __cdecl nan(സ്ഥിരം അക്ഷരം* s) {
  തിരികെ NAN;
}
__CRT_INLINE ദശാംശം __cdecl nanf(സ്ഥിരം അക്ഷരം* s) {
  തിരികെ NAN;
}
__CRT_INLINE long ഇരട്ട __cdecl nanl(സ്ഥിരം അക്ഷരം* s) {
  തിരികെ NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE ദശാംശം __cdecl scalbnf(ദശാംശം x, പൂർണ്ണസംഖ്യ n) {
  തിരികെ scalbn(x, n);
}
__CRT_INLINE long ഇരട്ട __cdecl scalbnl(long ഇരട്ട x, പൂർണ്ണസംഖ്യ n) {
  തിരികെ scalbn(x, n);
}

__CRT_INLINE ഇരട്ട __cdecl scalbln(ഇരട്ട x, long n) {
  തിരികെ scalbn(x, n);
}
__CRT_INLINE ദശാംശം __cdecl scalblnf(ദശാംശം x, long n) {
  തിരികെ scalbn(x, n);
}
__CRT_INLINE long ഇരട്ട __cdecl scalblnl(long ഇരട്ട x, long n) {
  തിരികെ scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE ഇരട്ട __cdecl ldexp(ഇരട്ട x, പൂർണ്ണസംഖ്യ expn) {
  തിരികെ scalbn(x, expn);
}
__CRT_INLINE ദശാംശം __cdecl ldexpf(ദശാംശം x, പൂർണ്ണസംഖ്യ expn) {
  തിരികെ scalbn(x, expn);
}
__CRT_INLINE long ഇരട്ട __cdecl ldexpl(long ഇരട്ട x, പൂർണ്ണസംഖ്യ expn) {
  തിരികെ scalbn(x, expn);
}

__CRT_INLINE ദശാംശം __cdecl frexpf(ദശാംശം x, പൂർണ്ണസംഖ്യ *y) {
  തിരികെ frexp(x, y);
}
__CRT_INLINE long ഇരട്ട __cdecl frexpl (long ഇരട്ട x, പൂർണ്ണസംഖ്യ* y) {
  തിരികെ frexp(x, y);
}


__CRT_INLINE ഇരട്ട __cdecl rint(ഇരട്ട x) {
ഇരട്ട retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  തിരികെ retval;
}

__CRT_INLINE ദശാംശം __cdecl rintf(ദശാംശം x) {
  ദശാംശം retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   തിരികെ retval;
}
__CRT_INLINE long ഇരട്ട __cdecl rintl (long ഇരട്ട x) {
  തിരികെ rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(ഇരട്ട x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  തിരികെ retval;
}

__CRT_INLINE long __cdecl lrintf(ദശാംശം x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  തിരികെ retval;
}

__CRT_INLINE long __cdecl lrintl (long ഇരട്ട x) {
  തിരികെ lrint(x);
}


__CRT_INLINE long long __cdecl llrint(ഇരട്ട x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  തിരികെ retval;
}

__CRT_INLINE long long __cdecl llrintf(ദശാംശം x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  തിരികെ retval;
}

__CRT_INLINE long long __cdecl llrintl (long ഇരട്ട x) {
  തിരികെ llrint(x);
}


__CRT_INLINE ഇരട്ട __cdecl trunc(ഇരട്ട _x) {
  ഇരട്ട retval;
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
  തിരികെ retval;
}

__CRT_INLINE ദശാംശം __cdecl truncf(ദശാംശം x) {
  തിരികെ (ദശാംശം) ((intptr_t) x);
}
__CRT_INLINE long ഇരട്ട __cdecl truncl(long ഇരട്ട x) {
  തിരികെ trunc(x);
}


__CRT_INLINE long ഇരട്ട __cdecl nextafterl(long ഇരട്ട x, long ഇരട്ട to) {
  തിരികെ nextafter(x, to);
}

__CRT_INLINE ഇരട്ട __cdecl nexttoward(ഇരട്ട x, long ഇരട്ട to) {
  തിരികെ nextafter(x, to);
}
__CRT_INLINE ദശാംശം __cdecl nexttowardf(ദശാംശം x, long ഇരട്ട to) {
  തിരികെ nextafterf(x, to);
}
__CRT_INLINE long ഇരട്ട __cdecl nexttowardl(long ഇരട്ട x, long ഇരട്ട to) {
  തിരികെ nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE ഇരട്ട __cdecl fabs(ഇരട്ട x) {
  തിരികെ x < 0 ? -x : x;
}
__CRT_INLINE ദശാംശം __cdecl fabsf(ദശാംശം x) {
  തിരികെ x < 0 ? -x : x;
}
__CRT_INLINE long ഇരട്ട __cdecl fabsl(long ഇരട്ട x) {
  തിരികെ x < 0 ? -x : x;
}


#എങ്കിൽ defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE ദശാംശം acosf(ദശാംശം x) { തിരികെ acos(x); }
  __CRT_INLINE ദശാംശം asinf(ദശാംശം x) { തിരികെ asin(x); }
  __CRT_INLINE ദശാംശം atanf(ദശാംശം x) { തിരികെ atan(x); }
  __CRT_INLINE ദശാംശം atan2f(ദശാംശം x, ദശാംശം y) { തിരികെ atan2(x, y); }
  __CRT_INLINE ദശാംശം ceilf(ദശാംശം x) { തിരികെ ceil(x); }
  __CRT_INLINE ദശാംശം cosf(ദശാംശം x) { തിരികെ cos(x); }
  __CRT_INLINE ദശാംശം coshf(ദശാംശം x) { തിരികെ cosh(x); }
  __CRT_INLINE ദശാംശം expf(ദശാംശം x) { തിരികെ exp(x); }
  __CRT_INLINE ദശാംശം floorf(ദശാംശം x) { തിരികെ floor(x); }
  __CRT_INLINE ദശാംശം fmodf(ദശാംശം x, ദശാംശം y) { തിരികെ fmod(x, y); }
  __CRT_INLINE ദശാംശം logf(ദശാംശം x) { തിരികെ log(x); }
  __CRT_INLINE ദശാംശം logbf(ദശാംശം x) { തിരികെ logb(x); }
  __CRT_INLINE ദശാംശം log10f(ദശാംശം x) { തിരികെ log10(x); }
  __CRT_INLINE ദശാംശം modff(ദശാംശം x, ദശാംശം *y) { ഇരട്ട di, df = modf(x, &di); *y = di; തിരികെ df; }
  __CRT_INLINE ദശാംശം powf(ദശാംശം x, ദശാംശം y) { തിരികെ pow(x, y); }
  __CRT_INLINE ദശാംശം sinf(ദശാംശം x) { തിരികെ sin(x); }
  __CRT_INLINE ദശാംശം sinhf(ദശാംശം x) { തിരികെ sinh(x); }
  __CRT_INLINE ദശാംശം sqrtf(ദശാംശം x) { തിരികെ sqrt(x); }
  __CRT_INLINE ദശാംശം tanf(ദശാംശം x) { തിരികെ tan(x); }
  __CRT_INLINE ദശാംശം tanhf(ദശാംശം x) { തിരികെ tanh(x); }
#endif
__CRT_INLINE ദശാംശം __cdecl asinhf(ദശാംശം x) { തിരികെ asinh(x); }
__CRT_INLINE ദശാംശം __cdecl acoshf(ദശാംശം x) { തിരികെ acosh(x); }
__CRT_INLINE ദശാംശം __cdecl atanhf(ദശാംശം x) { തിരികെ atanh(x); }

__CRT_INLINE long ഇരട്ട __cdecl asinhl(long ഇരട്ട x) { തിരികെ asinh(x); }
__CRT_INLINE long ഇരട്ട __cdecl acoshl(long ഇരട്ട x) { തിരികെ acosh(x); }
__CRT_INLINE long ഇരട്ട __cdecl atanhl(long ഇരട്ട x) { തിരികെ atanh(x); }
__CRT_INLINE long ഇരട്ട __cdecl asinl(long ഇരട്ട x) { തിരികെ asin(x); }
__CRT_INLINE long ഇരട്ട __cdecl acosl(long ഇരട്ട x) { തിരികെ acos(x); }
__CRT_INLINE long ഇരട്ട __cdecl atanl(long ഇരട്ട x) { തിരികെ atan(x); }
__CRT_INLINE long ഇരട്ട __cdecl ceill(long ഇരട്ട x) { തിരികെ ceil(x); }
__CRT_INLINE long ഇരട്ട __cdecl coshl(long ഇരട്ട x) { തിരികെ cosh(x); }
__CRT_INLINE long ഇരട്ട __cdecl cosl(long ഇരട്ട x) { തിരികെ cos(x); }
__CRT_INLINE long ഇരട്ട __cdecl expl(long ഇരട്ട x) { തിരികെ exp(x); }
__CRT_INLINE long ഇരട്ട __cdecl floorl(long ഇരട്ട x) { തിരികെ floor(x); }
__CRT_INLINE long ഇരട്ട __cdecl fmodl(long ഇരട്ട x, long ഇരട്ട y) { തിരികെ fmod(x, y); }
__CRT_INLINE long ഇരട്ട __cdecl hypotl(long ഇരട്ട x, long ഇരട്ട y) { തിരികെ hypot(x, y); }
__CRT_INLINE long ഇരട്ട __cdecl logl(long ഇരട്ട x) { തിരികെ log(x); }
__CRT_INLINE long ഇരട്ട __cdecl logbl(long ഇരട്ട x) { തിരികെ logb(x); }
__CRT_INLINE long ഇരട്ട __cdecl log10l(long ഇരട്ട x) { തിരികെ log10(x); }
__CRT_INLINE long ഇരട്ട __cdecl modfl(long ഇരട്ട x, long ഇരട്ട* y) { ഇരട്ട y1 = *y; x = modf(x, &y1); *y = y1; തിരികെ x; }
__CRT_INLINE long ഇരട്ട __cdecl powl(long ഇരട്ട x, long ഇരട്ട y) { തിരികെ pow(x, y); }
__CRT_INLINE long ഇരട്ട __cdecl sinhl(long ഇരട്ട x) { തിരികെ sinh(x); }
__CRT_INLINE long ഇരട്ട __cdecl sinl(long ഇരട്ട x) { തിരികെ sin(x); }
__CRT_INLINE long ഇരട്ട __cdecl sqrtl(long ഇരട്ട x) { തിരികെ sqrt(x); }
__CRT_INLINE long ഇരട്ട __cdecl tanhl(long ഇരട്ട x) { തിരികെ tanh(x); }
__CRT_INLINE long ഇരട്ട __cdecl tanl(long ഇരട്ട x) { തിരികെ tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE ഇരട്ട __cdecl log1p(ഇരട്ട x) {
  ഇരട്ട u = 1.0 + x;
  തിരികെ u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE ദശാംശം __cdecl log1pf(ദശാംശം x) {
  ദശാംശം u = 1.0f + x;
  തിരികെ u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long ഇരട്ട __cdecl log1pl(long ഇരട്ട x) {
  തിരികെ log1p(x);
}


__CRT_INLINE ഇരട്ട __cdecl expm1(ഇരട്ട x) {
  എങ്കിൽ (x > 0.0024 || x < -0.0024) തിരികെ exp(x) - 1.0;
  തിരികെ x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE ദശാംശം __cdecl expm1f(ദശാംശം x) {
  എങ്കിൽ (x > 0.085f || x < -0.085f) തിരികെ expf(x) - 1.0f;
  തിരികെ x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long ഇരട്ട __cdecl expm1l(long ഇരട്ട x) {
  തിരികെ expm1(x);
}


__CRT_INLINE ഇരട്ട __cdecl cbrt(ഇരട്ട x) {
  തിരികെ x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE ദശാംശം __cdecl cbrtf(ദശാംശം x) {
  തിരികെ x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long ഇരട്ട __cdecl cbrtl(long ഇരട്ട x) {
  തിരികെ cbrt(x);
}


__CRT_INLINE ഇരട്ട __cdecl log2(ഇരട്ട x) {
  തിരികെ log(x) * 1.442695040888963407;
}
__CRT_INLINE ദശാംശം __cdecl log2f(ദശാംശം x) {
  തിരികെ log(x) * 1.442695040888963407;
}
__CRT_INLINE long ഇരട്ട __cdecl log2l(long ഇരട്ട x) {
  തിരികെ log(x) * 1.442695040888963407;
}


__CRT_INLINE ഇരട്ട __cdecl exp2(ഇരട്ട x) {
  തിരികെ exp(x * 0.693147180559945309);
}
__CRT_INLINE ദശാംശം __cdecl exp2f(ദശാംശം x) {
  തിരികെ exp(x * 0.693147180559945309);
}
__CRT_INLINE long ഇരട്ട __cdecl exp2l(long ഇരട്ട x) {
  തിരികെ exp(x * 0.693147180559945309);
}


__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl ilogb(ഇരട്ട x) {
  തിരികെ (പൂർണ്ണസംഖ്യ) logb(x);
}
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl ilogbf(ദശാംശം x) {
  തിരികെ (പൂർണ്ണസംഖ്യ) logbf(x);
}
__CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl ilogbl(long ഇരട്ട x) {
  തിരികെ (പൂർണ്ണസംഖ്യ) logb(x);
}


__CRT_INLINE ഇരട്ട __cdecl fdim(ഇരട്ട x, ഇരട്ട y) {
  എങ്കിൽ (isnan(x) || isnan(y)) തിരികെ NAN;
  തിരികെ x > y ? x - y : 0;
}
__CRT_INLINE ദശാംശം __cdecl fdimf(ദശാംശം x, ദശാംശം y) {
  എങ്കിൽ (isnan(x) || isnan(y)) തിരികെ NAN;
  തിരികെ x > y ? x - y : 0;
}
__CRT_INLINE long ഇരട്ട __cdecl fdiml(long ഇരട്ട x, long ഇരട്ട y) {
  എങ്കിൽ (isnan(x) || isnan(y)) തിരികെ NAN;
  തിരികെ x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE ഇരട്ട __cdecl tgamma(ഇരട്ട x) {
  ഇരട്ട m = 1.0, t = 3.14159265358979323;
  എങ്കിൽ (x == floor(x)) {
    എങ്കിൽ (x == 0) തിരികെ INFINITY;
    എങ്കിൽ (x < 0) തിരികെ NAN;
    എങ്കിൽ (x < 26) { വേണ്ടി (ഇരട്ട k = 2; k < x; ++k) m *= k; തിരികെ m; }
  }
  എങ്കിൽ (x < 0.5)
    തിരികെ t / (sin(t*x)*tgamma(1.0 - x));
  എങ്കിൽ (x > 12.0)
    തിരികെ exp(lgamma(x));

  സ്ഥിതം സ്ഥിരം ഇരട്ട c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  വേണ്ടി (പൂർണ്ണസംഖ്യ k = 0; k < 8; ++k) m += c[k] / (x + k);
  തിരികെ 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE ഇരട്ട __cdecl lgamma(ഇരട്ട x) {
  എങ്കിൽ (x < 12.0) {
    എങ്കിൽ (x <= 0.0 && x == floor(x)) തിരികെ INFINITY;
    x = tgamma(x);
    തിരികെ log(x < 0.0 ? -x : x);
  }
  സ്ഥിതം സ്ഥിരം ഇരട്ട c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  ഇരട്ട m = -3617.0/122400.0, t = 1.0 / (x*x);
  വേണ്ടി (പൂർണ്ണസംഖ്യ k = 6; k >= 0; --k) m = m*t + c[k];
  തിരികെ (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE ദശാംശം __cdecl tgammaf(ദശാംശം x) {
  തിരികെ tgamma(x);
}
__CRT_INLINE ദശാംശം __cdecl lgammaf(ദശാംശം x) {
  തിരികെ lgamma(x);
}
__CRT_INLINE long ഇരട്ട __cdecl tgammal(long ഇരട്ട x) {
  തിരികെ tgamma(x);
}
__CRT_INLINE long ഇരട്ട __cdecl lgammal(long ഇരട്ട x) {
  തിരികെ lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
