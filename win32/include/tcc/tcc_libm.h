#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#include "../math.h"
#include "../stdint.h"

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

__CRT_INLINE целое __cdecl __fpclassify (double x) {
  union {double f; uint64_t i;} u = {.f = x};
  целое e = u.i>>52 & 0x7ff;
  если (!e) вернуть u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  если (e==0x7ff) вернуть u.i<<12 ? FP_NAN : FP_INFINITE;
  вернуть FP_NORMAL;
}

__CRT_INLINE целое __cdecl __fpclassifyf (float x) {
  union {float f; uint32_t i;} u = {.f = x};
  целое e = u.i>>23 & 0xff;
  если (!e) вернуть u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  если (e==0xff) вернуть u.i<<9 ? FP_NAN : FP_INFINITE;
  вернуть FP_NORMAL;
}

__CRT_INLINE целое __cdecl __fpclassifyl (long double x) {
  вернуть __fpclassify(x);
}


/* signbit */

__CRT_INLINE целое __cdecl __signbit (double x) {
  union {double f; uint64_t i;} u = {.f = x};
  вернуть u.i>>63;
}

__CRT_INLINE целое __cdecl __signbitf (float x) {
  union {float f; uint32_t i; } u = {.f = x};
  вернуть u.i>>31;
}

__CRT_INLINE целое __cdecl __signbitl (long double x) {
  вернуть __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE double __cdecl fmin (double x, double y) {
  вернуть TCCFP_FMIN_EVAL;
}

__CRT_INLINE float __cdecl fminf (float x, float y) {
  вернуть TCCFP_FMIN_EVAL;
}

__CRT_INLINE long double __cdecl fminl (long double x, long double y) {
  вернуть TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE double __cdecl fmax (double x, double y) {
  вернуть TCCFP_FMAX_EVAL;
}

__CRT_INLINE float __cdecl fmaxf (float x, float y) {
  вернуть TCCFP_FMAX_EVAL;
}

__CRT_INLINE long double __cdecl fmaxl (long double x, long double y) {
  вернуть TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) do {  \
  volatile typeof(x) __x;         \
  __x = (x);                      \
} пока(0)

__CRT_INLINE double __cdecl round (double x) {
  union {double f; uint64_t i;} u = {.f = x};
  целое e = u.i >> 52 & 0x7ff;
  double y;

  если (e >= 0x3ff+52)
    вернуть x;
  если (u.i >> 63)
    x = -x;
  если (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    вернуть 0*u.f;
  }
  y = (double)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  вернуть (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (double x) {
  вернуть round(x);
}

__CRT_INLINE long long __cdecl llround (double x) {
  вернуть round(x);
}

__CRT_INLINE float __cdecl roundf (float x) {
  вернуть round(x);
}

__CRT_INLINE long __cdecl lroundf (float x) {
  вернуть round(x);
}

__CRT_INLINE long long __cdecl llroundf (float x) {
  вернуть round(x);
}

__CRT_INLINE long double __cdecl roundl (long double x) {
  вернуть round(x);
}

__CRT_INLINE long __cdecl lroundl (long double x) {
  вернуть round(x);
}

__CRT_INLINE long long __cdecl llroundl (long double x) {
  вернуть round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE double __cdecl asinh(double x) {
  union {double f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  если (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  иначе если (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  иначе если (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  иначе TCCFP_FORCE_EVAL(x + 0x1p120f);
  вернуть s ? -x : x;
}

__CRT_INLINE double __cdecl acosh(double x) {
  union {double f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  если (e < 0x3ff + 1) вернуть --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  если (e < 0x3ff + 26) вернуть log(2*x - 1 / (x + sqrt(x*x - 1)));
  вернуть log(x) + 0.693147180559945309;
}

__CRT_INLINE double __cdecl atanh(double x) {
  union {double f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  если (e < 0x3ff - 1) {
    если (e < 0x3ff - 32) { если (e == 0) TCCFP_FORCE_EVAL((float)x); }
    иначе x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } иначе x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  вернуть s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE double __cdecl scalbn(double x, целое n) {
  union {double f; uint64_t i;} u;
  если (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    если (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      если (n > 1023) n = 1023;
    }
  } иначе если (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    если (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      если (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  вернуть x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE double __cdecl frexp(double x, целое *e) {
  union {double f; uint64_t i;} u = {.f = x};
  целое ee = u.i>>52 & 0x7ff;
  если (!ee) {
    если (x) x = frexp(x*0x1p64, e), *e -= 64;
    иначе *e = 0;
    вернуть x;
  } иначе если (ee == 0x7ff)
    вернуть x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  вернуть u.f;
}

/* MUSL nan */

__CRT_INLINE double __cdecl nan(const char* s) {
  вернуть NAN;
}
__CRT_INLINE float __cdecl nanf(const char* s) {
  вернуть NAN;
}
__CRT_INLINE long double __cdecl nanl(const char* s) {
  вернуть NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE float __cdecl scalbnf(float x, целое n) {
  вернуть scalbn(x, n);
}
__CRT_INLINE long double __cdecl scalbnl(long double x, целое n) {
  вернуть scalbn(x, n);
}

__CRT_INLINE double __cdecl scalbln(double x, long n) {
  вернуть scalbn(x, n);
}
__CRT_INLINE float __cdecl scalblnf(float x, long n) {
  вернуть scalbn(x, n);
}
__CRT_INLINE long double __cdecl scalblnl(long double x, long n) {
  вернуть scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE double __cdecl ldexp(double x, целое expn) {
  вернуть scalbn(x, expn);
}
__CRT_INLINE float __cdecl ldexpf(float x, целое expn) {
  вернуть scalbn(x, expn);
}
__CRT_INLINE long double __cdecl ldexpl(long double x, целое expn) {
  вернуть scalbn(x, expn);
}

__CRT_INLINE float __cdecl frexpf(float x, целое *y) {
  вернуть frexp(x, y);
}
__CRT_INLINE long double __cdecl frexpl (long double x, целое* y) {
  вернуть frexp(x, y);
}


__CRT_INLINE double __cdecl rint(double x) {
double retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  вернуть retval;
}

__CRT_INLINE float __cdecl rintf(float x) {
  float retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   вернуть retval;
}
__CRT_INLINE long double __cdecl rintl (long double x) {
  вернуть rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(double x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  вернуть retval;
}

__CRT_INLINE long __cdecl lrintf(float x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  вернуть retval;
}

__CRT_INLINE long __cdecl lrintl (long double x) {
  вернуть lrint(x);
}


__CRT_INLINE long long __cdecl llrint(double x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  вернуть retval;
}

__CRT_INLINE long long __cdecl llrintf(float x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  вернуть retval;
}

__CRT_INLINE long long __cdecl llrintl (long double x) {
  вернуть llrint(x);
}


__CRT_INLINE double __cdecl trunc(double _x) {
  double retval;
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
  вернуть retval;
}

__CRT_INLINE float __cdecl truncf(float x) {
  вернуть (float) ((intptr_t) x);
}
__CRT_INLINE long double __cdecl truncl(long double x) {
  вернуть trunc(x);
}


__CRT_INLINE long double __cdecl nextafterl(long double x, long double to) {
  вернуть nextafter(x, to);
}

__CRT_INLINE double __cdecl nexttoward(double x, long double to) {
  вернуть nextafter(x, to);
}
__CRT_INLINE float __cdecl nexttowardf(float x, long double to) {
  вернуть nextafterf(x, to);
}
__CRT_INLINE long double __cdecl nexttowardl(long double x, long double to) {
  вернуть nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE double __cdecl fabs(double x) {
  вернуть x < 0 ? -x : x;
}
__CRT_INLINE float __cdecl fabsf(float x) {
  вернуть x < 0 ? -x : x;
}
__CRT_INLINE long double __cdecl fabsl(long double x) {
  вернуть x < 0 ? -x : x;
}


#если defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE float acosf(float x) { вернуть acos(x); }
  __CRT_INLINE float asinf(float x) { вернуть asin(x); }
  __CRT_INLINE float atanf(float x) { вернуть atan(x); }
  __CRT_INLINE float atan2f(float x, float y) { вернуть atan2(x, y); }
  __CRT_INLINE float ceilf(float x) { вернуть ceil(x); }
  __CRT_INLINE float cosf(float x) { вернуть cos(x); }
  __CRT_INLINE float coshf(float x) { вернуть cosh(x); }
  __CRT_INLINE float expf(float x) { вернуть exp(x); }
  __CRT_INLINE float floorf(float x) { вернуть floor(x); }
  __CRT_INLINE float fmodf(float x, float y) { вернуть fmod(x, y); }
  __CRT_INLINE float logf(float x) { вернуть log(x); }
  __CRT_INLINE float logbf(float x) { вернуть logb(x); }
  __CRT_INLINE float log10f(float x) { вернуть log10(x); }
  __CRT_INLINE float modff(float x, float *y) { double di, df = modf(x, &di); *y = di; вернуть df; }
  __CRT_INLINE float powf(float x, float y) { вернуть pow(x, y); }
  __CRT_INLINE float sinf(float x) { вернуть sin(x); }
  __CRT_INLINE float sinhf(float x) { вернуть sinh(x); }
  __CRT_INLINE float sqrtf(float x) { вернуть sqrt(x); }
  __CRT_INLINE float tanf(float x) { вернуть tan(x); }
  __CRT_INLINE float tanhf(float x) { вернуть tanh(x); }
#endif
__CRT_INLINE float __cdecl asinhf(float x) { вернуть asinh(x); }
__CRT_INLINE float __cdecl acoshf(float x) { вернуть acosh(x); }
__CRT_INLINE float __cdecl atanhf(float x) { вернуть atanh(x); }

__CRT_INLINE long double __cdecl asinhl(long double x) { вернуть asinh(x); }
__CRT_INLINE long double __cdecl acoshl(long double x) { вернуть acosh(x); }
__CRT_INLINE long double __cdecl atanhl(long double x) { вернуть atanh(x); }
__CRT_INLINE long double __cdecl asinl(long double x) { вернуть asin(x); }
__CRT_INLINE long double __cdecl acosl(long double x) { вернуть acos(x); }
__CRT_INLINE long double __cdecl atanl(long double x) { вернуть atan(x); }
__CRT_INLINE long double __cdecl ceill(long double x) { вернуть ceil(x); }
__CRT_INLINE long double __cdecl coshl(long double x) { вернуть cosh(x); }
__CRT_INLINE long double __cdecl cosl(long double x) { вернуть cos(x); }
__CRT_INLINE long double __cdecl expl(long double x) { вернуть exp(x); }
__CRT_INLINE long double __cdecl floorl(long double x) { вернуть floor(x); }
__CRT_INLINE long double __cdecl fmodl(long double x, long double y) { вернуть fmod(x, y); }
__CRT_INLINE long double __cdecl hypotl(long double x, long double y) { вернуть hypot(x, y); }
__CRT_INLINE long double __cdecl logl(long double x) { вернуть log(x); }
__CRT_INLINE long double __cdecl logbl(long double x) { вернуть logb(x); }
__CRT_INLINE long double __cdecl log10l(long double x) { вернуть log10(x); }
__CRT_INLINE long double __cdecl modfl(long double x, long double* y) { double y1 = *y; x = modf(x, &y1); *y = y1; вернуть x; }
__CRT_INLINE long double __cdecl powl(long double x, long double y) { вернуть pow(x, y); }
__CRT_INLINE long double __cdecl sinhl(long double x) { вернуть sinh(x); }
__CRT_INLINE long double __cdecl sinl(long double x) { вернуть sin(x); }
__CRT_INLINE long double __cdecl sqrtl(long double x) { вернуть sqrt(x); }
__CRT_INLINE long double __cdecl tanhl(long double x) { вернуть tanh(x); }
__CRT_INLINE long double __cdecl tanl(long double x) { вернуть tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE double __cdecl log1p(double x) {
  double u = 1.0 + x;
  вернуть u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE float __cdecl log1pf(float x) {
  float u = 1.0f + x;
  вернуть u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long double __cdecl log1pl(long double x) {
  вернуть log1p(x);
}


__CRT_INLINE double __cdecl expm1(double x) {
  если (x > 0.0024 || x < -0.0024) вернуть exp(x) - 1.0;
  вернуть x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE float __cdecl expm1f(float x) {
  если (x > 0.085f || x < -0.085f) вернуть expf(x) - 1.0f;
  вернуть x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long double __cdecl expm1l(long double x) {
  вернуть expm1(x);
}


__CRT_INLINE double __cdecl cbrt(double x) {
  вернуть x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE float __cdecl cbrtf(float x) {
  вернуть x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long double __cdecl cbrtl(long double x) {
  вернуть cbrt(x);
}


__CRT_INLINE double __cdecl log2(double x) {
  вернуть log(x) * 1.442695040888963407;
}
__CRT_INLINE float __cdecl log2f(float x) {
  вернуть log(x) * 1.442695040888963407;
}
__CRT_INLINE long double __cdecl log2l(long double x) {
  вернуть log(x) * 1.442695040888963407;
}


__CRT_INLINE double __cdecl exp2(double x) {
  вернуть exp(x * 0.693147180559945309);
}
__CRT_INLINE float __cdecl exp2f(float x) {
  вернуть exp(x * 0.693147180559945309);
}
__CRT_INLINE long double __cdecl exp2l(long double x) {
  вернуть exp(x * 0.693147180559945309);
}


__CRT_INLINE целое __cdecl ilogb(double x) {
  вернуть (целое) logb(x);
}
__CRT_INLINE целое __cdecl ilogbf(float x) {
  вернуть (целое) logbf(x);
}
__CRT_INLINE целое __cdecl ilogbl(long double x) {
  вернуть (целое) logb(x);
}


__CRT_INLINE double __cdecl fdim(double x, double y) {
  если (isnan(x) || isnan(y)) вернуть NAN;
  вернуть x > y ? x - y : 0;
}
__CRT_INLINE float __cdecl fdimf(float x, float y) {
  если (isnan(x) || isnan(y)) вернуть NAN;
  вернуть x > y ? x - y : 0;
}
__CRT_INLINE long double __cdecl fdiml(long double x, long double y) {
  если (isnan(x) || isnan(y)) вернуть NAN;
  вернуть x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE double __cdecl tgamma(double x) {
  double m = 1.0, t = 3.14159265358979323;
  если (x == floor(x)) {
    если (x == 0) вернуть INFINITY;
    если (x < 0) вернуть NAN;
    если (x < 26) { для (double k = 2; k < x; ++k) m *= k; вернуть m; }
  }
  если (x < 0.5)
    вернуть t / (sin(t*x)*tgamma(1.0 - x));
  если (x > 12.0)
    вернуть exp(lgamma(x));

  static const double c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  для (целое k = 0; k < 8; ++k) m += c[k] / (x + k);
  вернуть 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE double __cdecl lgamma(double x) {
  если (x < 12.0) {
    если (x <= 0.0 && x == floor(x)) вернуть INFINITY;
    x = tgamma(x);
    вернуть log(x < 0.0 ? -x : x);
  }
  static const double c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  double m = -3617.0/122400.0, t = 1.0 / (x*x);
  для (целое k = 6; k >= 0; --k) m = m*t + c[k];
  вернуть (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE float __cdecl tgammaf(float x) {
  вернуть tgamma(x);
}
__CRT_INLINE float __cdecl lgammaf(float x) {
  вернуть lgamma(x);
}
__CRT_INLINE long double __cdecl tgammal(long double x) {
  вернуть tgamma(x);
}
__CRT_INLINE long double __cdecl lgammal(long double x) {
  вернуть lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
