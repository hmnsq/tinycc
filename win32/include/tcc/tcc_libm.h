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

__CRT_INLINE 정수 __cdecl __fpclassify (double x) {
  union {double f; uint64_t i;} u = {.f = x};
  정수 e = u.i>>52 & 0x7ff;
  만약 (!e) 반환 u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  만약 (e==0x7ff) 반환 u.i<<12 ? FP_NAN : FP_INFINITE;
  반환 FP_NORMAL;
}

__CRT_INLINE 정수 __cdecl __fpclassifyf (float x) {
  union {float f; uint32_t i;} u = {.f = x};
  정수 e = u.i>>23 & 0xff;
  만약 (!e) 반환 u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  만약 (e==0xff) 반환 u.i<<9 ? FP_NAN : FP_INFINITE;
  반환 FP_NORMAL;
}

__CRT_INLINE 정수 __cdecl __fpclassifyl (long double x) {
  반환 __fpclassify(x);
}


/* signbit */

__CRT_INLINE 정수 __cdecl __signbit (double x) {
  union {double f; uint64_t i;} u = {.f = x};
  반환 u.i>>63;
}

__CRT_INLINE 정수 __cdecl __signbitf (float x) {
  union {float f; uint32_t i; } u = {.f = x};
  반환 u.i>>31;
}

__CRT_INLINE 정수 __cdecl __signbitl (long double x) {
  반환 __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE double __cdecl fmin (double x, double y) {
  반환 TCCFP_FMIN_EVAL;
}

__CRT_INLINE float __cdecl fminf (float x, float y) {
  반환 TCCFP_FMIN_EVAL;
}

__CRT_INLINE long double __cdecl fminl (long double x, long double y) {
  반환 TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE double __cdecl fmax (double x, double y) {
  반환 TCCFP_FMAX_EVAL;
}

__CRT_INLINE float __cdecl fmaxf (float x, float y) {
  반환 TCCFP_FMAX_EVAL;
}

__CRT_INLINE long double __cdecl fmaxl (long double x, long double y) {
  반환 TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) do {  \
  volatile typeof(x) __x;         \
  __x = (x);                      \
} 동안(0)

__CRT_INLINE double __cdecl round (double x) {
  union {double f; uint64_t i;} u = {.f = x};
  정수 e = u.i >> 52 & 0x7ff;
  double y;

  만약 (e >= 0x3ff+52)
    반환 x;
  만약 (u.i >> 63)
    x = -x;
  만약 (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    반환 0*u.f;
  }
  y = (double)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  반환 (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (double x) {
  반환 round(x);
}

__CRT_INLINE long long __cdecl llround (double x) {
  반환 round(x);
}

__CRT_INLINE float __cdecl roundf (float x) {
  반환 round(x);
}

__CRT_INLINE long __cdecl lroundf (float x) {
  반환 round(x);
}

__CRT_INLINE long long __cdecl llroundf (float x) {
  반환 round(x);
}

__CRT_INLINE long double __cdecl roundl (long double x) {
  반환 round(x);
}

__CRT_INLINE long __cdecl lroundl (long double x) {
  반환 round(x);
}

__CRT_INLINE long long __cdecl llroundl (long double x) {
  반환 round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE double __cdecl asinh(double x) {
  union {double f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  만약 (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  아니면 만약 (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  아니면 만약 (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  아니면 TCCFP_FORCE_EVAL(x + 0x1p120f);
  반환 s ? -x : x;
}

__CRT_INLINE double __cdecl acosh(double x) {
  union {double f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  만약 (e < 0x3ff + 1) 반환 --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  만약 (e < 0x3ff + 26) 반환 log(2*x - 1 / (x + sqrt(x*x - 1)));
  반환 log(x) + 0.693147180559945309;
}

__CRT_INLINE double __cdecl atanh(double x) {
  union {double f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  만약 (e < 0x3ff - 1) {
    만약 (e < 0x3ff - 32) { 만약 (e == 0) TCCFP_FORCE_EVAL((float)x); }
    아니면 x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } 아니면 x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  반환 s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE double __cdecl scalbn(double x, 정수 n) {
  union {double f; uint64_t i;} u;
  만약 (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    만약 (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      만약 (n > 1023) n = 1023;
    }
  } 아니면 만약 (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    만약 (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      만약 (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  반환 x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE double __cdecl frexp(double x, 정수 *e) {
  union {double f; uint64_t i;} u = {.f = x};
  정수 ee = u.i>>52 & 0x7ff;
  만약 (!ee) {
    만약 (x) x = frexp(x*0x1p64, e), *e -= 64;
    아니면 *e = 0;
    반환 x;
  } 아니면 만약 (ee == 0x7ff)
    반환 x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  반환 u.f;
}

/* MUSL nan */

__CRT_INLINE double __cdecl nan(const char* s) {
  반환 NAN;
}
__CRT_INLINE float __cdecl nanf(const char* s) {
  반환 NAN;
}
__CRT_INLINE long double __cdecl nanl(const char* s) {
  반환 NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE float __cdecl scalbnf(float x, 정수 n) {
  반환 scalbn(x, n);
}
__CRT_INLINE long double __cdecl scalbnl(long double x, 정수 n) {
  반환 scalbn(x, n);
}

__CRT_INLINE double __cdecl scalbln(double x, long n) {
  반환 scalbn(x, n);
}
__CRT_INLINE float __cdecl scalblnf(float x, long n) {
  반환 scalbn(x, n);
}
__CRT_INLINE long double __cdecl scalblnl(long double x, long n) {
  반환 scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE double __cdecl ldexp(double x, 정수 expn) {
  반환 scalbn(x, expn);
}
__CRT_INLINE float __cdecl ldexpf(float x, 정수 expn) {
  반환 scalbn(x, expn);
}
__CRT_INLINE long double __cdecl ldexpl(long double x, 정수 expn) {
  반환 scalbn(x, expn);
}

__CRT_INLINE float __cdecl frexpf(float x, 정수 *y) {
  반환 frexp(x, y);
}
__CRT_INLINE long double __cdecl frexpl (long double x, 정수* y) {
  반환 frexp(x, y);
}


__CRT_INLINE double __cdecl rint(double x) {
double retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  반환 retval;
}

__CRT_INLINE float __cdecl rintf(float x) {
  float retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   반환 retval;
}
__CRT_INLINE long double __cdecl rintl (long double x) {
  반환 rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(double x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  반환 retval;
}

__CRT_INLINE long __cdecl lrintf(float x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  반환 retval;
}

__CRT_INLINE long __cdecl lrintl (long double x) {
  반환 lrint(x);
}


__CRT_INLINE long long __cdecl llrint(double x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  반환 retval;
}

__CRT_INLINE long long __cdecl llrintf(float x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  반환 retval;
}

__CRT_INLINE long long __cdecl llrintl (long double x) {
  반환 llrint(x);
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
  반환 retval;
}

__CRT_INLINE float __cdecl truncf(float x) {
  반환 (float) ((intptr_t) x);
}
__CRT_INLINE long double __cdecl truncl(long double x) {
  반환 trunc(x);
}


__CRT_INLINE long double __cdecl nextafterl(long double x, long double to) {
  반환 nextafter(x, to);
}

__CRT_INLINE double __cdecl nexttoward(double x, long double to) {
  반환 nextafter(x, to);
}
__CRT_INLINE float __cdecl nexttowardf(float x, long double to) {
  반환 nextafterf(x, to);
}
__CRT_INLINE long double __cdecl nexttowardl(long double x, long double to) {
  반환 nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE double __cdecl fabs(double x) {
  반환 x < 0 ? -x : x;
}
__CRT_INLINE float __cdecl fabsf(float x) {
  반환 x < 0 ? -x : x;
}
__CRT_INLINE long double __cdecl fabsl(long double x) {
  반환 x < 0 ? -x : x;
}


#만약 defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE float acosf(float x) { 반환 acos(x); }
  __CRT_INLINE float asinf(float x) { 반환 asin(x); }
  __CRT_INLINE float atanf(float x) { 반환 atan(x); }
  __CRT_INLINE float atan2f(float x, float y) { 반환 atan2(x, y); }
  __CRT_INLINE float ceilf(float x) { 반환 ceil(x); }
  __CRT_INLINE float cosf(float x) { 반환 cos(x); }
  __CRT_INLINE float coshf(float x) { 반환 cosh(x); }
  __CRT_INLINE float expf(float x) { 반환 exp(x); }
  __CRT_INLINE float floorf(float x) { 반환 floor(x); }
  __CRT_INLINE float fmodf(float x, float y) { 반환 fmod(x, y); }
  __CRT_INLINE float logf(float x) { 반환 log(x); }
  __CRT_INLINE float logbf(float x) { 반환 logb(x); }
  __CRT_INLINE float log10f(float x) { 반환 log10(x); }
  __CRT_INLINE float modff(float x, float *y) { double di, df = modf(x, &di); *y = di; 반환 df; }
  __CRT_INLINE float powf(float x, float y) { 반환 pow(x, y); }
  __CRT_INLINE float sinf(float x) { 반환 sin(x); }
  __CRT_INLINE float sinhf(float x) { 반환 sinh(x); }
  __CRT_INLINE float sqrtf(float x) { 반환 sqrt(x); }
  __CRT_INLINE float tanf(float x) { 반환 tan(x); }
  __CRT_INLINE float tanhf(float x) { 반환 tanh(x); }
#endif
__CRT_INLINE float __cdecl asinhf(float x) { 반환 asinh(x); }
__CRT_INLINE float __cdecl acoshf(float x) { 반환 acosh(x); }
__CRT_INLINE float __cdecl atanhf(float x) { 반환 atanh(x); }

__CRT_INLINE long double __cdecl asinhl(long double x) { 반환 asinh(x); }
__CRT_INLINE long double __cdecl acoshl(long double x) { 반환 acosh(x); }
__CRT_INLINE long double __cdecl atanhl(long double x) { 반환 atanh(x); }
__CRT_INLINE long double __cdecl asinl(long double x) { 반환 asin(x); }
__CRT_INLINE long double __cdecl acosl(long double x) { 반환 acos(x); }
__CRT_INLINE long double __cdecl atanl(long double x) { 반환 atan(x); }
__CRT_INLINE long double __cdecl ceill(long double x) { 반환 ceil(x); }
__CRT_INLINE long double __cdecl coshl(long double x) { 반환 cosh(x); }
__CRT_INLINE long double __cdecl cosl(long double x) { 반환 cos(x); }
__CRT_INLINE long double __cdecl expl(long double x) { 반환 exp(x); }
__CRT_INLINE long double __cdecl floorl(long double x) { 반환 floor(x); }
__CRT_INLINE long double __cdecl fmodl(long double x, long double y) { 반환 fmod(x, y); }
__CRT_INLINE long double __cdecl hypotl(long double x, long double y) { 반환 hypot(x, y); }
__CRT_INLINE long double __cdecl logl(long double x) { 반환 log(x); }
__CRT_INLINE long double __cdecl logbl(long double x) { 반환 logb(x); }
__CRT_INLINE long double __cdecl log10l(long double x) { 반환 log10(x); }
__CRT_INLINE long double __cdecl modfl(long double x, long double* y) { double y1 = *y; x = modf(x, &y1); *y = y1; 반환 x; }
__CRT_INLINE long double __cdecl powl(long double x, long double y) { 반환 pow(x, y); }
__CRT_INLINE long double __cdecl sinhl(long double x) { 반환 sinh(x); }
__CRT_INLINE long double __cdecl sinl(long double x) { 반환 sin(x); }
__CRT_INLINE long double __cdecl sqrtl(long double x) { 반환 sqrt(x); }
__CRT_INLINE long double __cdecl tanhl(long double x) { 반환 tanh(x); }
__CRT_INLINE long double __cdecl tanl(long double x) { 반환 tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE double __cdecl log1p(double x) {
  double u = 1.0 + x;
  반환 u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE float __cdecl log1pf(float x) {
  float u = 1.0f + x;
  반환 u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long double __cdecl log1pl(long double x) {
  반환 log1p(x);
}


__CRT_INLINE double __cdecl expm1(double x) {
  만약 (x > 0.0024 || x < -0.0024) 반환 exp(x) - 1.0;
  반환 x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE float __cdecl expm1f(float x) {
  만약 (x > 0.085f || x < -0.085f) 반환 expf(x) - 1.0f;
  반환 x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long double __cdecl expm1l(long double x) {
  반환 expm1(x);
}


__CRT_INLINE double __cdecl cbrt(double x) {
  반환 x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE float __cdecl cbrtf(float x) {
  반환 x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long double __cdecl cbrtl(long double x) {
  반환 cbrt(x);
}


__CRT_INLINE double __cdecl log2(double x) {
  반환 log(x) * 1.442695040888963407;
}
__CRT_INLINE float __cdecl log2f(float x) {
  반환 log(x) * 1.442695040888963407;
}
__CRT_INLINE long double __cdecl log2l(long double x) {
  반환 log(x) * 1.442695040888963407;
}


__CRT_INLINE double __cdecl exp2(double x) {
  반환 exp(x * 0.693147180559945309);
}
__CRT_INLINE float __cdecl exp2f(float x) {
  반환 exp(x * 0.693147180559945309);
}
__CRT_INLINE long double __cdecl exp2l(long double x) {
  반환 exp(x * 0.693147180559945309);
}


__CRT_INLINE 정수 __cdecl ilogb(double x) {
  반환 (정수) logb(x);
}
__CRT_INLINE 정수 __cdecl ilogbf(float x) {
  반환 (정수) logbf(x);
}
__CRT_INLINE 정수 __cdecl ilogbl(long double x) {
  반환 (정수) logb(x);
}


__CRT_INLINE double __cdecl fdim(double x, double y) {
  만약 (isnan(x) || isnan(y)) 반환 NAN;
  반환 x > y ? x - y : 0;
}
__CRT_INLINE float __cdecl fdimf(float x, float y) {
  만약 (isnan(x) || isnan(y)) 반환 NAN;
  반환 x > y ? x - y : 0;
}
__CRT_INLINE long double __cdecl fdiml(long double x, long double y) {
  만약 (isnan(x) || isnan(y)) 반환 NAN;
  반환 x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE double __cdecl tgamma(double x) {
  double m = 1.0, t = 3.14159265358979323;
  만약 (x == floor(x)) {
    만약 (x == 0) 반환 INFINITY;
    만약 (x < 0) 반환 NAN;
    만약 (x < 26) { 위해 (double k = 2; k < x; ++k) m *= k; 반환 m; }
  }
  만약 (x < 0.5)
    반환 t / (sin(t*x)*tgamma(1.0 - x));
  만약 (x > 12.0)
    반환 exp(lgamma(x));

  static const double c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  위해 (정수 k = 0; k < 8; ++k) m += c[k] / (x + k);
  반환 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE double __cdecl lgamma(double x) {
  만약 (x < 12.0) {
    만약 (x <= 0.0 && x == floor(x)) 반환 INFINITY;
    x = tgamma(x);
    반환 log(x < 0.0 ? -x : x);
  }
  static const double c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  double m = -3617.0/122400.0, t = 1.0 / (x*x);
  위해 (정수 k = 6; k >= 0; --k) m = m*t + c[k];
  반환 (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE float __cdecl tgammaf(float x) {
  반환 tgamma(x);
}
__CRT_INLINE float __cdecl lgammaf(float x) {
  반환 lgamma(x);
}
__CRT_INLINE long double __cdecl tgammal(long double x) {
  반환 tgamma(x);
}
__CRT_INLINE long double __cdecl lgammal(long double x) {
  반환 lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
