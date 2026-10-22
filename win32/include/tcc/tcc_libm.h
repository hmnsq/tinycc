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

__CRT_INLINE ཧྲིལ __cdecl __fpclassify (dviguu_na x) {
  sa_ngha {dviguu_na f; uint64_t i;} u = {.f = x};
  ཧྲིལ e = u.i>>52 & 0x7ff;
  གལ་སྲིད (!e) ལོག u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  གལ་སྲིད (e==0x7ff) ལོག u.i<<12 ? FP_NAN : FP_INFINITE;
  ལོག FP_NORMAL;
}

__CRT_INLINE ཧྲིལ __cdecl __fpclassifyf (float x) {
  sa_ngha {float f; uint32_t i;} u = {.f = x};
  ཧྲིལ e = u.i>>23 & 0xff;
  གལ་སྲིད (!e) ལོག u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  གལ་སྲིད (e==0xff) ལོག u.i<<9 ? FP_NAN : FP_INFINITE;
  ལོག FP_NORMAL;
}

__CRT_INLINE ཧྲིལ __cdecl __fpclassifyl (long dviguu_na x) {
  ལོག __fpclassify(x);
}


/* signbit */

__CRT_INLINE ཧྲིལ __cdecl __signbit (dviguu_na x) {
  sa_ngha {dviguu_na f; uint64_t i;} u = {.f = x};
  ལོག u.i>>63;
}

__CRT_INLINE ཧྲིལ __cdecl __signbitf (float x) {
  sa_ngha {float f; uint32_t i; } u = {.f = x};
  ལོག u.i>>31;
}

__CRT_INLINE ཧྲིལ __cdecl __signbitl (long dviguu_na x) {
  ལོག __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE dviguu_na __cdecl fmin (dviguu_na x, dviguu_na y) {
  ལོག TCCFP_FMIN_EVAL;
}

__CRT_INLINE float __cdecl fminf (float x, float y) {
  ལོག TCCFP_FMIN_EVAL;
}

__CRT_INLINE long dviguu_na __cdecl fminl (long dviguu_na x, long dviguu_na y) {
  ལོག TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE dviguu_na __cdecl fmax (dviguu_na x, dviguu_na y) {
  ལོག TCCFP_FMAX_EVAL;
}

__CRT_INLINE float __cdecl fmaxf (float x, float y) {
  ལོག TCCFP_FMAX_EVAL;
}

__CRT_INLINE long dviguu_na __cdecl fmaxl (long dviguu_na x, long dviguu_na y) {
  ལོག TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) do {  \
  ca_ncala typeof(x) __x;         \
  __x = (x);                      \
} སྐབས(0)

__CRT_INLINE dviguu_na __cdecl round (dviguu_na x) {
  sa_ngha {dviguu_na f; uint64_t i;} u = {.f = x};
  ཧྲིལ e = u.i >> 52 & 0x7ff;
  dviguu_na y;

  གལ་སྲིད (e >= 0x3ff+52)
    ལོག x;
  གལ་སྲིད (u.i >> 63)
    x = -x;
  གལ་སྲིད (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    ལོག 0*u.f;
  }
  y = (dviguu_na)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  ལོག (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (dviguu_na x) {
  ལོག round(x);
}

__CRT_INLINE long long __cdecl llround (dviguu_na x) {
  ལོག round(x);
}

__CRT_INLINE float __cdecl roundf (float x) {
  ལོག round(x);
}

__CRT_INLINE long __cdecl lroundf (float x) {
  ལོག round(x);
}

__CRT_INLINE long long __cdecl llroundf (float x) {
  ལོག round(x);
}

__CRT_INLINE long dviguu_na __cdecl roundl (long dviguu_na x) {
  ལོག round(x);
}

__CRT_INLINE long __cdecl lroundl (long dviguu_na x) {
  ལོག round(x);
}

__CRT_INLINE long long __cdecl llroundl (long dviguu_na x) {
  ལོག round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE dviguu_na __cdecl asinh(dviguu_na x) {
  sa_ngha {dviguu_na f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  གལ་སྲིད (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  དེ་མིན གལ་སྲིད (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  དེ་མིན གལ་སྲིད (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  དེ་མིན TCCFP_FORCE_EVAL(x + 0x1p120f);
  ལོག s ? -x : x;
}

__CRT_INLINE dviguu_na __cdecl acosh(dviguu_na x) {
  sa_ngha {dviguu_na f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  གལ་སྲིད (e < 0x3ff + 1) ལོག --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  གལ་སྲིད (e < 0x3ff + 26) ལོག log(2*x - 1 / (x + sqrt(x*x - 1)));
  ལོག log(x) + 0.693147180559945309;
}

__CRT_INLINE dviguu_na __cdecl atanh(dviguu_na x) {
  sa_ngha {dviguu_na f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  གལ་སྲིད (e < 0x3ff - 1) {
    གལ་སྲིད (e < 0x3ff - 32) { གལ་སྲིད (e == 0) TCCFP_FORCE_EVAL((float)x); }
    དེ་མིན x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } དེ་མིན x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  ལོག s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE dviguu_na __cdecl scalbn(dviguu_na x, ཧྲིལ n) {
  sa_ngha {dviguu_na f; uint64_t i;} u;
  གལ་སྲིད (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    གལ་སྲིད (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      གལ་སྲིད (n > 1023) n = 1023;
    }
  } དེ་མིན གལ་སྲིད (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    གལ་སྲིད (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      གལ་སྲིད (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  ལོག x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE dviguu_na __cdecl frexp(dviguu_na x, ཧྲིལ *e) {
  sa_ngha {dviguu_na f; uint64_t i;} u = {.f = x};
  ཧྲིལ ee = u.i>>52 & 0x7ff;
  གལ་སྲིད (!ee) {
    གལ་སྲིད (x) x = frexp(x*0x1p64, e), *e -= 64;
    དེ་མིན *e = 0;
    ལོག x;
  } དེ་མིན གལ་སྲིད (ee == 0x7ff)
    ལོག x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  ལོག u.f;
}

/* MUSL nan */

__CRT_INLINE dviguu_na __cdecl nan(const var_na* s) {
  ལོག NAN;
}
__CRT_INLINE float __cdecl nanf(const var_na* s) {
  ལོག NAN;
}
__CRT_INLINE long dviguu_na __cdecl nanl(const var_na* s) {
  ལོག NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE float __cdecl scalbnf(float x, ཧྲིལ n) {
  ལོག scalbn(x, n);
}
__CRT_INLINE long dviguu_na __cdecl scalbnl(long dviguu_na x, ཧྲིལ n) {
  ལོག scalbn(x, n);
}

__CRT_INLINE dviguu_na __cdecl scalbln(dviguu_na x, long n) {
  ལོག scalbn(x, n);
}
__CRT_INLINE float __cdecl scalblnf(float x, long n) {
  ལོག scalbn(x, n);
}
__CRT_INLINE long dviguu_na __cdecl scalblnl(long dviguu_na x, long n) {
  ལོག scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE dviguu_na __cdecl ldexp(dviguu_na x, ཧྲིལ expn) {
  ལོག scalbn(x, expn);
}
__CRT_INLINE float __cdecl ldexpf(float x, ཧྲིལ expn) {
  ལོག scalbn(x, expn);
}
__CRT_INLINE long dviguu_na __cdecl ldexpl(long dviguu_na x, ཧྲིལ expn) {
  ལོག scalbn(x, expn);
}

__CRT_INLINE float __cdecl frexpf(float x, ཧྲིལ *y) {
  ལོག frexp(x, y);
}
__CRT_INLINE long dviguu_na __cdecl frexpl (long dviguu_na x, ཧྲིལ* y) {
  ལོག frexp(x, y);
}


__CRT_INLINE dviguu_na __cdecl rint(dviguu_na x) {
dviguu_na retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  ལོག retval;
}

__CRT_INLINE float __cdecl rintf(float x) {
  float retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   ལོག retval;
}
__CRT_INLINE long dviguu_na __cdecl rintl (long dviguu_na x) {
  ལོག rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(dviguu_na x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ལོག retval;
}

__CRT_INLINE long __cdecl lrintf(float x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ལོག retval;
}

__CRT_INLINE long __cdecl lrintl (long dviguu_na x) {
  ལོག lrint(x);
}


__CRT_INLINE long long __cdecl llrint(dviguu_na x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ལོག retval;
}

__CRT_INLINE long long __cdecl llrintf(float x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ལོག retval;
}

__CRT_INLINE long long __cdecl llrintl (long dviguu_na x) {
  ལོག llrint(x);
}


__CRT_INLINE dviguu_na __cdecl trunc(dviguu_na _x) {
  dviguu_na retval;
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
  ལོག retval;
}

__CRT_INLINE float __cdecl truncf(float x) {
  ལོག (float) ((intptr_t) x);
}
__CRT_INLINE long dviguu_na __cdecl truncl(long dviguu_na x) {
  ལོག trunc(x);
}


__CRT_INLINE long dviguu_na __cdecl nextafterl(long dviguu_na x, long dviguu_na to) {
  ལོག nextafter(x, to);
}

__CRT_INLINE dviguu_na __cdecl nexttoward(dviguu_na x, long dviguu_na to) {
  ལོག nextafter(x, to);
}
__CRT_INLINE float __cdecl nexttowardf(float x, long dviguu_na to) {
  ལོག nextafterf(x, to);
}
__CRT_INLINE long dviguu_na __cdecl nexttowardl(long dviguu_na x, long dviguu_na to) {
  ལོག nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE dviguu_na __cdecl fabs(dviguu_na x) {
  ལོག x < 0 ? -x : x;
}
__CRT_INLINE float __cdecl fabsf(float x) {
  ལོག x < 0 ? -x : x;
}
__CRT_INLINE long dviguu_na __cdecl fabsl(long dviguu_na x) {
  ལོག x < 0 ? -x : x;
}


#གལ་སྲིད defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE float acosf(float x) { ལོག acos(x); }
  __CRT_INLINE float asinf(float x) { ལོག asin(x); }
  __CRT_INLINE float atanf(float x) { ལོག atan(x); }
  __CRT_INLINE float atan2f(float x, float y) { ལོག atan2(x, y); }
  __CRT_INLINE float ceilf(float x) { ལོག ceil(x); }
  __CRT_INLINE float cosf(float x) { ལོག cos(x); }
  __CRT_INLINE float coshf(float x) { ལོག cosh(x); }
  __CRT_INLINE float expf(float x) { ལོག exp(x); }
  __CRT_INLINE float floorf(float x) { ལོག floor(x); }
  __CRT_INLINE float fmodf(float x, float y) { ལོག fmod(x, y); }
  __CRT_INLINE float logf(float x) { ལོག log(x); }
  __CRT_INLINE float logbf(float x) { ལོག logb(x); }
  __CRT_INLINE float log10f(float x) { ལོག log10(x); }
  __CRT_INLINE float modff(float x, float *y) { dviguu_na di, df = modf(x, &di); *y = di; ལོག df; }
  __CRT_INLINE float powf(float x, float y) { ལོག pow(x, y); }
  __CRT_INLINE float sinf(float x) { ལོག sin(x); }
  __CRT_INLINE float sinhf(float x) { ལོག sinh(x); }
  __CRT_INLINE float sqrtf(float x) { ལོག sqrt(x); }
  __CRT_INLINE float tanf(float x) { ལོག tan(x); }
  __CRT_INLINE float tanhf(float x) { ལོག tanh(x); }
#endif
__CRT_INLINE float __cdecl asinhf(float x) { ལོག asinh(x); }
__CRT_INLINE float __cdecl acoshf(float x) { ལོག acosh(x); }
__CRT_INLINE float __cdecl atanhf(float x) { ལོག atanh(x); }

__CRT_INLINE long dviguu_na __cdecl asinhl(long dviguu_na x) { ལོག asinh(x); }
__CRT_INLINE long dviguu_na __cdecl acoshl(long dviguu_na x) { ལོག acosh(x); }
__CRT_INLINE long dviguu_na __cdecl atanhl(long dviguu_na x) { ལོག atanh(x); }
__CRT_INLINE long dviguu_na __cdecl asinl(long dviguu_na x) { ལོག asin(x); }
__CRT_INLINE long dviguu_na __cdecl acosl(long dviguu_na x) { ལོག acos(x); }
__CRT_INLINE long dviguu_na __cdecl atanl(long dviguu_na x) { ལོག atan(x); }
__CRT_INLINE long dviguu_na __cdecl ceill(long dviguu_na x) { ལོག ceil(x); }
__CRT_INLINE long dviguu_na __cdecl coshl(long dviguu_na x) { ལོག cosh(x); }
__CRT_INLINE long dviguu_na __cdecl cosl(long dviguu_na x) { ལོག cos(x); }
__CRT_INLINE long dviguu_na __cdecl expl(long dviguu_na x) { ལོག exp(x); }
__CRT_INLINE long dviguu_na __cdecl floorl(long dviguu_na x) { ལོག floor(x); }
__CRT_INLINE long dviguu_na __cdecl fmodl(long dviguu_na x, long dviguu_na y) { ལོག fmod(x, y); }
__CRT_INLINE long dviguu_na __cdecl hypotl(long dviguu_na x, long dviguu_na y) { ལོག hypot(x, y); }
__CRT_INLINE long dviguu_na __cdecl logl(long dviguu_na x) { ལོག log(x); }
__CRT_INLINE long dviguu_na __cdecl logbl(long dviguu_na x) { ལོག logb(x); }
__CRT_INLINE long dviguu_na __cdecl log10l(long dviguu_na x) { ལོག log10(x); }
__CRT_INLINE long dviguu_na __cdecl modfl(long dviguu_na x, long dviguu_na* y) { dviguu_na y1 = *y; x = modf(x, &y1); *y = y1; ལོག x; }
__CRT_INLINE long dviguu_na __cdecl powl(long dviguu_na x, long dviguu_na y) { ལོག pow(x, y); }
__CRT_INLINE long dviguu_na __cdecl sinhl(long dviguu_na x) { ལོག sinh(x); }
__CRT_INLINE long dviguu_na __cdecl sinl(long dviguu_na x) { ལོག sin(x); }
__CRT_INLINE long dviguu_na __cdecl sqrtl(long dviguu_na x) { ལོག sqrt(x); }
__CRT_INLINE long dviguu_na __cdecl tanhl(long dviguu_na x) { ལོག tanh(x); }
__CRT_INLINE long dviguu_na __cdecl tanl(long dviguu_na x) { ལོག tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE dviguu_na __cdecl log1p(dviguu_na x) {
  dviguu_na u = 1.0 + x;
  ལོག u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE float __cdecl log1pf(float x) {
  float u = 1.0f + x;
  ལོག u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long dviguu_na __cdecl log1pl(long dviguu_na x) {
  ལོག log1p(x);
}


__CRT_INLINE dviguu_na __cdecl expm1(dviguu_na x) {
  གལ་སྲིད (x > 0.0024 || x < -0.0024) ལོག exp(x) - 1.0;
  ལོག x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE float __cdecl expm1f(float x) {
  གལ་སྲིད (x > 0.085f || x < -0.085f) ལོག expf(x) - 1.0f;
  ལོག x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long dviguu_na __cdecl expm1l(long dviguu_na x) {
  ལོག expm1(x);
}


__CRT_INLINE dviguu_na __cdecl cbrt(dviguu_na x) {
  ལོག x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE float __cdecl cbrtf(float x) {
  ལོག x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long dviguu_na __cdecl cbrtl(long dviguu_na x) {
  ལོག cbrt(x);
}


__CRT_INLINE dviguu_na __cdecl log2(dviguu_na x) {
  ལོག log(x) * 1.442695040888963407;
}
__CRT_INLINE float __cdecl log2f(float x) {
  ལོག log(x) * 1.442695040888963407;
}
__CRT_INLINE long dviguu_na __cdecl log2l(long dviguu_na x) {
  ལོག log(x) * 1.442695040888963407;
}


__CRT_INLINE dviguu_na __cdecl exp2(dviguu_na x) {
  ལོག exp(x * 0.693147180559945309);
}
__CRT_INLINE float __cdecl exp2f(float x) {
  ལོག exp(x * 0.693147180559945309);
}
__CRT_INLINE long dviguu_na __cdecl exp2l(long dviguu_na x) {
  ལོག exp(x * 0.693147180559945309);
}


__CRT_INLINE ཧྲིལ __cdecl ilogb(dviguu_na x) {
  ལོག (ཧྲིལ) logb(x);
}
__CRT_INLINE ཧྲིལ __cdecl ilogbf(float x) {
  ལོག (ཧྲིལ) logbf(x);
}
__CRT_INLINE ཧྲིལ __cdecl ilogbl(long dviguu_na x) {
  ལོག (ཧྲིལ) logb(x);
}


__CRT_INLINE dviguu_na __cdecl fdim(dviguu_na x, dviguu_na y) {
  གལ་སྲིད (isnan(x) || isnan(y)) ལོག NAN;
  ལོག x > y ? x - y : 0;
}
__CRT_INLINE float __cdecl fdimf(float x, float y) {
  གལ་སྲིད (isnan(x) || isnan(y)) ལོག NAN;
  ལོག x > y ? x - y : 0;
}
__CRT_INLINE long dviguu_na __cdecl fdiml(long dviguu_na x, long dviguu_na y) {
  གལ་སྲིད (isnan(x) || isnan(y)) ལོག NAN;
  ལོག x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE dviguu_na __cdecl tgamma(dviguu_na x) {
  dviguu_na m = 1.0, t = 3.14159265358979323;
  གལ་སྲིད (x == floor(x)) {
    གལ་སྲིད (x == 0) ལོག INFINITY;
    གལ་སྲིད (x < 0) ལོག NAN;
    གལ་སྲིད (x < 26) { དོན་ལུ (dviguu_na k = 2; k < x; ++k) m *= k; ལོག m; }
  }
  གལ་སྲིད (x < 0.5)
    ལོག t / (sin(t*x)*tgamma(1.0 - x));
  གལ་སྲིད (x > 12.0)
    ལོག exp(lgamma(x));

  static const dviguu_na c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  དོན་ལུ (ཧྲིལ k = 0; k < 8; ++k) m += c[k] / (x + k);
  ལོག 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE dviguu_na __cdecl lgamma(dviguu_na x) {
  གལ་སྲིད (x < 12.0) {
    གལ་སྲིད (x <= 0.0 && x == floor(x)) ལོག INFINITY;
    x = tgamma(x);
    ལོག log(x < 0.0 ? -x : x);
  }
  static const dviguu_na c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  dviguu_na m = -3617.0/122400.0, t = 1.0 / (x*x);
  དོན་ལུ (ཧྲིལ k = 6; k >= 0; --k) m = m*t + c[k];
  ལོག (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE float __cdecl tgammaf(float x) {
  ལོག tgamma(x);
}
__CRT_INLINE float __cdecl lgammaf(float x) {
  ལོག lgamma(x);
}
__CRT_INLINE long dviguu_na __cdecl tgammal(long dviguu_na x) {
  ལོག tgamma(x);
}
__CRT_INLINE long dviguu_na __cdecl lgammal(long dviguu_na x) {
  ལོག lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
