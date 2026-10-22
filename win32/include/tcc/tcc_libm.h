#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#ضمن "../math.h"
#ضمن "../stdint.h"

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

__CRT_INLINE صحيح __cdecl __fpclassify (مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  صحيح e = u.i>>52 & 0x7ff;
  אם (!e) החזר u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  אם (e==0x7ff) החזר u.i<<12 ? FP_NAN : FP_INFINITE;
  החזר FP_NORMAL;
}

__CRT_INLINE صحيح __cdecl __fpclassifyf (عائم x) {
  اتحاد {عائم f; uint32_t i;} u = {.f = x};
  صحيح e = u.i>>23 & 0xff;
  אם (!e) החזר u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  אם (e==0xff) החזר u.i<<9 ? FP_NAN : FP_INFINITE;
  החזר FP_NORMAL;
}

__CRT_INLINE صحيح __cdecl __fpclassifyl (long مزدوج x) {
  החזר __fpclassify(x);
}


/* signbit */

__CRT_INLINE صحيح __cdecl __signbit (مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  החזר u.i>>63;
}

__CRT_INLINE صحيح __cdecl __signbitf (عائم x) {
  اتحاد {عائم f; uint32_t i; } u = {.f = x};
  החזר u.i>>31;
}

__CRT_INLINE صحيح __cdecl __signbitl (long مزدوج x) {
  החזר __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE مزدوج __cdecl fmin (مزدوج x, مزدوج y) {
  החזר TCCFP_FMIN_EVAL;
}

__CRT_INLINE عائم __cdecl fminf (عائم x, عائم y) {
  החזר TCCFP_FMIN_EVAL;
}

__CRT_INLINE long مزدوج __cdecl fminl (long مزدوج x, long مزدوج y) {
  החזר TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE مزدوج __cdecl fmax (مزدوج x, مزدوج y) {
  החזר TCCFP_FMAX_EVAL;
}

__CRT_INLINE عائم __cdecl fmaxf (عائم x, عائم y) {
  החזר TCCFP_FMAX_EVAL;
}

__CRT_INLINE long مزدوج __cdecl fmaxl (long مزدوج x, long مزدوج y) {
  החזר TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) עשה {  \
  متطاير typeof(x) __x;         \
  __x = (x);                      \
} כלעוד(0)

__CRT_INLINE مزدوج __cdecl round (مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  صحيح e = u.i >> 52 & 0x7ff;
  مزدوج y;

  אם (e >= 0x3ff+52)
    החזר x;
  אם (u.i >> 63)
    x = -x;
  אם (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    החזר 0*u.f;
  }
  y = (مزدوج)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  החזר (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (مزدوج x) {
  החזר round(x);
}

__CRT_INLINE long long __cdecl llround (مزدوج x) {
  החזר round(x);
}

__CRT_INLINE عائم __cdecl roundf (عائم x) {
  החזר round(x);
}

__CRT_INLINE long __cdecl lroundf (عائم x) {
  החזר round(x);
}

__CRT_INLINE long long __cdecl llroundf (عائم x) {
  החזר round(x);
}

__CRT_INLINE long مزدوج __cdecl roundl (long مزدوج x) {
  החזר round(x);
}

__CRT_INLINE long __cdecl lroundl (long مزدوج x) {
  החזר round(x);
}

__CRT_INLINE long long __cdecl llroundl (long مزدوج x) {
  החזר round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE مزدوج __cdecl asinh(مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  אם (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  אחרת אם (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  אחרת אם (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  אחרת TCCFP_FORCE_EVAL(x + 0x1p120f);
  החזר s ? -x : x;
}

__CRT_INLINE مزدوج __cdecl acosh(مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  אם (e < 0x3ff + 1) החזר --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  אם (e < 0x3ff + 26) החזר log(2*x - 1 / (x + sqrt(x*x - 1)));
  החזר log(x) + 0.693147180559945309;
}

__CRT_INLINE مزدوج __cdecl atanh(مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  אם (e < 0x3ff - 1) {
    אם (e < 0x3ff - 32) { אם (e == 0) TCCFP_FORCE_EVAL((عائم)x); }
    אחרת x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } אחרת x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  החזר s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE مزدوج __cdecl scalbn(مزدوج x, صحيح n) {
  اتحاد {مزدوج f; uint64_t i;} u;
  אם (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    אם (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      אם (n > 1023) n = 1023;
    }
  } אחרת אם (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    אם (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      אם (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  החזר x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE مزدوج __cdecl frexp(مزدوج x, صحيح *e) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  صحيح ee = u.i>>52 & 0x7ff;
  אם (!ee) {
    אם (x) x = frexp(x*0x1p64, e), *e -= 64;
    אחרת *e = 0;
    החזר x;
  } אחרת אם (ee == 0x7ff)
    החזר x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  החזר u.f;
}

/* MUSL nan */

__CRT_INLINE مزدوج __cdecl nan(ثابت حرف* s) {
  החזר NAN;
}
__CRT_INLINE عائم __cdecl nanf(ثابت حرف* s) {
  החזר NAN;
}
__CRT_INLINE long مزدوج __cdecl nanl(ثابت حرف* s) {
  החזר NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE عائم __cdecl scalbnf(عائم x, صحيح n) {
  החזר scalbn(x, n);
}
__CRT_INLINE long مزدوج __cdecl scalbnl(long مزدوج x, صحيح n) {
  החזר scalbn(x, n);
}

__CRT_INLINE مزدوج __cdecl scalbln(مزدوج x, long n) {
  החזר scalbn(x, n);
}
__CRT_INLINE عائم __cdecl scalblnf(عائم x, long n) {
  החזר scalbn(x, n);
}
__CRT_INLINE long مزدوج __cdecl scalblnl(long مزدوج x, long n) {
  החזר scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE مزدوج __cdecl ldexp(مزدوج x, صحيح expn) {
  החזר scalbn(x, expn);
}
__CRT_INLINE عائم __cdecl ldexpf(عائم x, صحيح expn) {
  החזר scalbn(x, expn);
}
__CRT_INLINE long مزدوج __cdecl ldexpl(long مزدوج x, صحيح expn) {
  החזר scalbn(x, expn);
}

__CRT_INLINE عائم __cdecl frexpf(عائم x, صحيح *y) {
  החזר frexp(x, y);
}
__CRT_INLINE long مزدوج __cdecl frexpl (long مزدوج x, صحيح* y) {
  החזר frexp(x, y);
}


__CRT_INLINE مزدوج __cdecl rint(مزدوج x) {
مزدوج retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  החזר retval;
}

__CRT_INLINE عائم __cdecl rintf(عائم x) {
  عائم retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   החזר retval;
}
__CRT_INLINE long مزدوج __cdecl rintl (long مزدوج x) {
  החזר rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(مزدوج x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  החזר retval;
}

__CRT_INLINE long __cdecl lrintf(عائم x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  החזר retval;
}

__CRT_INLINE long __cdecl lrintl (long مزدوج x) {
  החזר lrint(x);
}


__CRT_INLINE long long __cdecl llrint(مزدوج x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  החזר retval;
}

__CRT_INLINE long long __cdecl llrintf(عائم x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  החזר retval;
}

__CRT_INLINE long long __cdecl llrintl (long مزدوج x) {
  החזר llrint(x);
}


__CRT_INLINE مزدوج __cdecl trunc(مزدوج _x) {
  مزدوج retval;
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
  החזר retval;
}

__CRT_INLINE عائم __cdecl truncf(عائم x) {
  החזר (عائم) ((intptr_t) x);
}
__CRT_INLINE long مزدوج __cdecl truncl(long مزدوج x) {
  החזר trunc(x);
}


__CRT_INLINE long مزدوج __cdecl nextafterl(long مزدوج x, long مزدوج to) {
  החזר nextafter(x, to);
}

__CRT_INLINE مزدوج __cdecl nexttoward(مزدوج x, long مزدوج to) {
  החזר nextafter(x, to);
}
__CRT_INLINE عائم __cdecl nexttowardf(عائم x, long مزدوج to) {
  החזר nextafterf(x, to);
}
__CRT_INLINE long مزدوج __cdecl nexttowardl(long مزدوج x, long مزدوج to) {
  החזר nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE مزدوج __cdecl fabs(مزدوج x) {
  החזר x < 0 ? -x : x;
}
__CRT_INLINE عائم __cdecl fabsf(عائم x) {
  החזר x < 0 ? -x : x;
}
__CRT_INLINE long مزدوج __cdecl fabsl(long مزدوج x) {
  החזר x < 0 ? -x : x;
}


#אם defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE عائم acosf(عائم x) { החזר acos(x); }
  __CRT_INLINE عائم asinf(عائم x) { החזר asin(x); }
  __CRT_INLINE عائم atanf(عائم x) { החזר atan(x); }
  __CRT_INLINE عائم atan2f(عائم x, عائم y) { החזר atan2(x, y); }
  __CRT_INLINE عائم ceilf(عائم x) { החזר ceil(x); }
  __CRT_INLINE عائم cosf(عائم x) { החזר cos(x); }
  __CRT_INLINE عائم coshf(عائم x) { החזר cosh(x); }
  __CRT_INLINE عائم expf(عائم x) { החזר exp(x); }
  __CRT_INLINE عائم floorf(عائم x) { החזר floor(x); }
  __CRT_INLINE عائم fmodf(عائم x, عائم y) { החזר fmod(x, y); }
  __CRT_INLINE عائم logf(عائم x) { החזר log(x); }
  __CRT_INLINE عائم logbf(عائم x) { החזר logb(x); }
  __CRT_INLINE عائم log10f(عائم x) { החזר log10(x); }
  __CRT_INLINE عائم modff(عائم x, عائم *y) { مزدوج di, df = modf(x, &di); *y = di; החזר df; }
  __CRT_INLINE عائم powf(عائم x, عائم y) { החזר pow(x, y); }
  __CRT_INLINE عائم sinf(عائم x) { החזר sin(x); }
  __CRT_INLINE عائم sinhf(عائم x) { החזר sinh(x); }
  __CRT_INLINE عائم sqrtf(عائم x) { החזר sqrt(x); }
  __CRT_INLINE عائم tanf(عائم x) { החזר tan(x); }
  __CRT_INLINE عائم tanhf(عائم x) { החזר tanh(x); }
#endif
__CRT_INLINE عائم __cdecl asinhf(عائم x) { החזר asinh(x); }
__CRT_INLINE عائم __cdecl acoshf(عائم x) { החזר acosh(x); }
__CRT_INLINE عائم __cdecl atanhf(عائم x) { החזר atanh(x); }

__CRT_INLINE long مزدوج __cdecl asinhl(long مزدوج x) { החזר asinh(x); }
__CRT_INLINE long مزدوج __cdecl acoshl(long مزدوج x) { החזר acosh(x); }
__CRT_INLINE long مزدوج __cdecl atanhl(long مزدوج x) { החזר atanh(x); }
__CRT_INLINE long مزدوج __cdecl asinl(long مزدوج x) { החזר asin(x); }
__CRT_INLINE long مزدوج __cdecl acosl(long مزدوج x) { החזר acos(x); }
__CRT_INLINE long مزدوج __cdecl atanl(long مزدوج x) { החזר atan(x); }
__CRT_INLINE long مزدوج __cdecl ceill(long مزدوج x) { החזר ceil(x); }
__CRT_INLINE long مزدوج __cdecl coshl(long مزدوج x) { החזר cosh(x); }
__CRT_INLINE long مزدوج __cdecl cosl(long مزدوج x) { החזר cos(x); }
__CRT_INLINE long مزدوج __cdecl expl(long مزدوج x) { החזר exp(x); }
__CRT_INLINE long مزدوج __cdecl floorl(long مزدوج x) { החזר floor(x); }
__CRT_INLINE long مزدوج __cdecl fmodl(long مزدوج x, long مزدوج y) { החזר fmod(x, y); }
__CRT_INLINE long مزدوج __cdecl hypotl(long مزدوج x, long مزدوج y) { החזר hypot(x, y); }
__CRT_INLINE long مزدوج __cdecl logl(long مزدوج x) { החזר log(x); }
__CRT_INLINE long مزدوج __cdecl logbl(long مزدوج x) { החזר logb(x); }
__CRT_INLINE long مزدوج __cdecl log10l(long مزدوج x) { החזר log10(x); }
__CRT_INLINE long مزدوج __cdecl modfl(long مزدوج x, long مزدوج* y) { مزدوج y1 = *y; x = modf(x, &y1); *y = y1; החזר x; }
__CRT_INLINE long مزدوج __cdecl powl(long مزدوج x, long مزدوج y) { החזר pow(x, y); }
__CRT_INLINE long مزدوج __cdecl sinhl(long مزدوج x) { החזר sinh(x); }
__CRT_INLINE long مزدوج __cdecl sinl(long مزدوج x) { החזר sin(x); }
__CRT_INLINE long مزدوج __cdecl sqrtl(long مزدوج x) { החזר sqrt(x); }
__CRT_INLINE long مزدوج __cdecl tanhl(long مزدوج x) { החזר tanh(x); }
__CRT_INLINE long مزدوج __cdecl tanl(long مزدوج x) { החזר tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE مزدوج __cdecl log1p(مزدوج x) {
  مزدوج u = 1.0 + x;
  החזר u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE عائم __cdecl log1pf(عائم x) {
  عائم u = 1.0f + x;
  החזר u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long مزدوج __cdecl log1pl(long مزدوج x) {
  החזר log1p(x);
}


__CRT_INLINE مزدوج __cdecl expm1(مزدوج x) {
  אם (x > 0.0024 || x < -0.0024) החזר exp(x) - 1.0;
  החזר x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE عائم __cdecl expm1f(عائم x) {
  אם (x > 0.085f || x < -0.085f) החזר expf(x) - 1.0f;
  החזר x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long مزدوج __cdecl expm1l(long مزدوج x) {
  החזר expm1(x);
}


__CRT_INLINE مزدوج __cdecl cbrt(مزدوج x) {
  החזר x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE عائم __cdecl cbrtf(عائم x) {
  החזר x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long مزدوج __cdecl cbrtl(long مزدوج x) {
  החזר cbrt(x);
}


__CRT_INLINE مزدوج __cdecl log2(مزدوج x) {
  החזר log(x) * 1.442695040888963407;
}
__CRT_INLINE عائم __cdecl log2f(عائم x) {
  החזר log(x) * 1.442695040888963407;
}
__CRT_INLINE long مزدوج __cdecl log2l(long مزدوج x) {
  החזר log(x) * 1.442695040888963407;
}


__CRT_INLINE مزدوج __cdecl exp2(مزدوج x) {
  החזר exp(x * 0.693147180559945309);
}
__CRT_INLINE عائم __cdecl exp2f(عائم x) {
  החזר exp(x * 0.693147180559945309);
}
__CRT_INLINE long مزدوج __cdecl exp2l(long مزدوج x) {
  החזר exp(x * 0.693147180559945309);
}


__CRT_INLINE صحيح __cdecl ilogb(مزدوج x) {
  החזר (صحيح) logb(x);
}
__CRT_INLINE صحيح __cdecl ilogbf(عائم x) {
  החזר (صحيح) logbf(x);
}
__CRT_INLINE صحيح __cdecl ilogbl(long مزدوج x) {
  החזר (صحيح) logb(x);
}


__CRT_INLINE مزدوج __cdecl fdim(مزدوج x, مزدوج y) {
  אם (isnan(x) || isnan(y)) החזר NAN;
  החזר x > y ? x - y : 0;
}
__CRT_INLINE عائم __cdecl fdimf(عائم x, عائم y) {
  אם (isnan(x) || isnan(y)) החזר NAN;
  החזר x > y ? x - y : 0;
}
__CRT_INLINE long مزدوج __cdecl fdiml(long مزدوج x, long مزدوج y) {
  אם (isnan(x) || isnan(y)) החזר NAN;
  החזר x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE مزدوج __cdecl tgamma(مزدوج x) {
  مزدوج m = 1.0, t = 3.14159265358979323;
  אם (x == floor(x)) {
    אם (x == 0) החזר INFINITY;
    אם (x < 0) החזר NAN;
    אם (x < 26) { עבור (مزدوج k = 2; k < x; ++k) m *= k; החזר m; }
  }
  אם (x < 0.5)
    החזר t / (sin(t*x)*tgamma(1.0 - x));
  אם (x > 12.0)
    החזר exp(lgamma(x));

  ساكن ثابت مزدوج c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  עבור (صحيح k = 0; k < 8; ++k) m += c[k] / (x + k);
  החזר 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE مزدوج __cdecl lgamma(مزدوج x) {
  אם (x < 12.0) {
    אם (x <= 0.0 && x == floor(x)) החזר INFINITY;
    x = tgamma(x);
    החזר log(x < 0.0 ? -x : x);
  }
  ساكن ثابت مزدوج c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  مزدوج m = -3617.0/122400.0, t = 1.0 / (x*x);
  עבור (صحيح k = 6; k >= 0; --k) m = m*t + c[k];
  החזר (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE عائم __cdecl tgammaf(عائم x) {
  החזר tgamma(x);
}
__CRT_INLINE عائم __cdecl lgammaf(عائم x) {
  החזר lgamma(x);
}
__CRT_INLINE long مزدوج __cdecl tgammal(long مزدوج x) {
  החזר tgamma(x);
}
__CRT_INLINE long مزدوج __cdecl lgammal(long مزدوج x) {
  החזר lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
