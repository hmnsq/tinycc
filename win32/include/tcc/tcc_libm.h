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
  إذا (!e) أرجع u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  إذا (e==0x7ff) أرجع u.i<<12 ? FP_NAN : FP_INFINITE;
  أرجع FP_NORMAL;
}

__CRT_INLINE صحيح __cdecl __fpclassifyf (عائم x) {
  اتحاد {عائم f; uint32_t i;} u = {.f = x};
  صحيح e = u.i>>23 & 0xff;
  إذا (!e) أرجع u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  إذا (e==0xff) أرجع u.i<<9 ? FP_NAN : FP_INFINITE;
  أرجع FP_NORMAL;
}

__CRT_INLINE صحيح __cdecl __fpclassifyl (long مزدوج x) {
  أرجع __fpclassify(x);
}


/* signbit */

__CRT_INLINE صحيح __cdecl __signbit (مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  أرجع u.i>>63;
}

__CRT_INLINE صحيح __cdecl __signbitf (عائم x) {
  اتحاد {عائم f; uint32_t i; } u = {.f = x};
  أرجع u.i>>31;
}

__CRT_INLINE صحيح __cdecl __signbitl (long مزدوج x) {
  أرجع __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE مزدوج __cdecl fmin (مزدوج x, مزدوج y) {
  أرجع TCCFP_FMIN_EVAL;
}

__CRT_INLINE عائم __cdecl fminf (عائم x, عائم y) {
  أرجع TCCFP_FMIN_EVAL;
}

__CRT_INLINE long مزدوج __cdecl fminl (long مزدوج x, long مزدوج y) {
  أرجع TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE مزدوج __cdecl fmax (مزدوج x, مزدوج y) {
  أرجع TCCFP_FMAX_EVAL;
}

__CRT_INLINE عائم __cdecl fmaxf (عائم x, عائم y) {
  أرجع TCCFP_FMAX_EVAL;
}

__CRT_INLINE long مزدوج __cdecl fmaxl (long مزدوج x, long مزدوج y) {
  أرجع TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) افعل {  \
  متطاير typeof(x) __x;         \
  __x = (x);                      \
} طالما(0)

__CRT_INLINE مزدوج __cdecl round (مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  صحيح e = u.i >> 52 & 0x7ff;
  مزدوج y;

  إذا (e >= 0x3ff+52)
    أرجع x;
  إذا (u.i >> 63)
    x = -x;
  إذا (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    أرجع 0*u.f;
  }
  y = (مزدوج)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  أرجع (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (مزدوج x) {
  أرجع round(x);
}

__CRT_INLINE long long __cdecl llround (مزدوج x) {
  أرجع round(x);
}

__CRT_INLINE عائم __cdecl roundf (عائم x) {
  أرجع round(x);
}

__CRT_INLINE long __cdecl lroundf (عائم x) {
  أرجع round(x);
}

__CRT_INLINE long long __cdecl llroundf (عائم x) {
  أرجع round(x);
}

__CRT_INLINE long مزدوج __cdecl roundl (long مزدوج x) {
  أرجع round(x);
}

__CRT_INLINE long __cdecl lroundl (long مزدوج x) {
  أرجع round(x);
}

__CRT_INLINE long long __cdecl llroundl (long مزدوج x) {
  أرجع round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE مزدوج __cdecl asinh(مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  إذا (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  وإلا إذا (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  وإلا إذا (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  وإلا TCCFP_FORCE_EVAL(x + 0x1p120f);
  أرجع s ? -x : x;
}

__CRT_INLINE مزدوج __cdecl acosh(مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  إذا (e < 0x3ff + 1) أرجع --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  إذا (e < 0x3ff + 26) أرجع log(2*x - 1 / (x + sqrt(x*x - 1)));
  أرجع log(x) + 0.693147180559945309;
}

__CRT_INLINE مزدوج __cdecl atanh(مزدوج x) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  إذا (e < 0x3ff - 1) {
    إذا (e < 0x3ff - 32) { إذا (e == 0) TCCFP_FORCE_EVAL((عائم)x); }
    وإلا x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } وإلا x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  أرجع s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE مزدوج __cdecl scalbn(مزدوج x, صحيح n) {
  اتحاد {مزدوج f; uint64_t i;} u;
  إذا (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    إذا (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      إذا (n > 1023) n = 1023;
    }
  } وإلا إذا (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    إذا (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      إذا (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  أرجع x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE مزدوج __cdecl frexp(مزدوج x, صحيح *e) {
  اتحاد {مزدوج f; uint64_t i;} u = {.f = x};
  صحيح ee = u.i>>52 & 0x7ff;
  إذا (!ee) {
    إذا (x) x = frexp(x*0x1p64, e), *e -= 64;
    وإلا *e = 0;
    أرجع x;
  } وإلا إذا (ee == 0x7ff)
    أرجع x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  أرجع u.f;
}

/* MUSL nan */

__CRT_INLINE مزدوج __cdecl nan(ثابت حرف* s) {
  أرجع NAN;
}
__CRT_INLINE عائم __cdecl nanf(ثابت حرف* s) {
  أرجع NAN;
}
__CRT_INLINE long مزدوج __cdecl nanl(ثابت حرف* s) {
  أرجع NAN;
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
  أرجع scalbn(x, n);
}
__CRT_INLINE long مزدوج __cdecl scalbnl(long مزدوج x, صحيح n) {
  أرجع scalbn(x, n);
}

__CRT_INLINE مزدوج __cdecl scalbln(مزدوج x, long n) {
  أرجع scalbn(x, n);
}
__CRT_INLINE عائم __cdecl scalblnf(عائم x, long n) {
  أرجع scalbn(x, n);
}
__CRT_INLINE long مزدوج __cdecl scalblnl(long مزدوج x, long n) {
  أرجع scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE مزدوج __cdecl ldexp(مزدوج x, صحيح expn) {
  أرجع scalbn(x, expn);
}
__CRT_INLINE عائم __cdecl ldexpf(عائم x, صحيح expn) {
  أرجع scalbn(x, expn);
}
__CRT_INLINE long مزدوج __cdecl ldexpl(long مزدوج x, صحيح expn) {
  أرجع scalbn(x, expn);
}

__CRT_INLINE عائم __cdecl frexpf(عائم x, صحيح *y) {
  أرجع frexp(x, y);
}
__CRT_INLINE long مزدوج __cdecl frexpl (long مزدوج x, صحيح* y) {
  أرجع frexp(x, y);
}


__CRT_INLINE مزدوج __cdecl rint(مزدوج x) {
مزدوج retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  أرجع retval;
}

__CRT_INLINE عائم __cdecl rintf(عائم x) {
  عائم retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   أرجع retval;
}
__CRT_INLINE long مزدوج __cdecl rintl (long مزدوج x) {
  أرجع rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(مزدوج x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  أرجع retval;
}

__CRT_INLINE long __cdecl lrintf(عائم x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  أرجع retval;
}

__CRT_INLINE long __cdecl lrintl (long مزدوج x) {
  أرجع lrint(x);
}


__CRT_INLINE long long __cdecl llrint(مزدوج x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  أرجع retval;
}

__CRT_INLINE long long __cdecl llrintf(عائم x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  أرجع retval;
}

__CRT_INLINE long long __cdecl llrintl (long مزدوج x) {
  أرجع llrint(x);
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
  أرجع retval;
}

__CRT_INLINE عائم __cdecl truncf(عائم x) {
  أرجع (عائم) ((intptr_t) x);
}
__CRT_INLINE long مزدوج __cdecl truncl(long مزدوج x) {
  أرجع trunc(x);
}


__CRT_INLINE long مزدوج __cdecl nextafterl(long مزدوج x, long مزدوج to) {
  أرجع nextafter(x, to);
}

__CRT_INLINE مزدوج __cdecl nexttoward(مزدوج x, long مزدوج to) {
  أرجع nextafter(x, to);
}
__CRT_INLINE عائم __cdecl nexttowardf(عائم x, long مزدوج to) {
  أرجع nextafterf(x, to);
}
__CRT_INLINE long مزدوج __cdecl nexttowardl(long مزدوج x, long مزدوج to) {
  أرجع nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE مزدوج __cdecl fabs(مزدوج x) {
  أرجع x < 0 ? -x : x;
}
__CRT_INLINE عائم __cdecl fabsf(عائم x) {
  أرجع x < 0 ? -x : x;
}
__CRT_INLINE long مزدوج __cdecl fabsl(long مزدوج x) {
  أرجع x < 0 ? -x : x;
}


#إذا defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE عائم acosf(عائم x) { أرجع acos(x); }
  __CRT_INLINE عائم asinf(عائم x) { أرجع asin(x); }
  __CRT_INLINE عائم atanf(عائم x) { أرجع atan(x); }
  __CRT_INLINE عائم atan2f(عائم x, عائم y) { أرجع atan2(x, y); }
  __CRT_INLINE عائم ceilf(عائم x) { أرجع ceil(x); }
  __CRT_INLINE عائم cosf(عائم x) { أرجع cos(x); }
  __CRT_INLINE عائم coshf(عائم x) { أرجع cosh(x); }
  __CRT_INLINE عائم expf(عائم x) { أرجع exp(x); }
  __CRT_INLINE عائم floorf(عائم x) { أرجع floor(x); }
  __CRT_INLINE عائم fmodf(عائم x, عائم y) { أرجع fmod(x, y); }
  __CRT_INLINE عائم logf(عائم x) { أرجع log(x); }
  __CRT_INLINE عائم logbf(عائم x) { أرجع logb(x); }
  __CRT_INLINE عائم log10f(عائم x) { أرجع log10(x); }
  __CRT_INLINE عائم modff(عائم x, عائم *y) { مزدوج di, df = modf(x, &di); *y = di; أرجع df; }
  __CRT_INLINE عائم powf(عائم x, عائم y) { أرجع pow(x, y); }
  __CRT_INLINE عائم sinf(عائم x) { أرجع sin(x); }
  __CRT_INLINE عائم sinhf(عائم x) { أرجع sinh(x); }
  __CRT_INLINE عائم sqrtf(عائم x) { أرجع sqrt(x); }
  __CRT_INLINE عائم tanf(عائم x) { أرجع tan(x); }
  __CRT_INLINE عائم tanhf(عائم x) { أرجع tanh(x); }
#endif
__CRT_INLINE عائم __cdecl asinhf(عائم x) { أرجع asinh(x); }
__CRT_INLINE عائم __cdecl acoshf(عائم x) { أرجع acosh(x); }
__CRT_INLINE عائم __cdecl atanhf(عائم x) { أرجع atanh(x); }

__CRT_INLINE long مزدوج __cdecl asinhl(long مزدوج x) { أرجع asinh(x); }
__CRT_INLINE long مزدوج __cdecl acoshl(long مزدوج x) { أرجع acosh(x); }
__CRT_INLINE long مزدوج __cdecl atanhl(long مزدوج x) { أرجع atanh(x); }
__CRT_INLINE long مزدوج __cdecl asinl(long مزدوج x) { أرجع asin(x); }
__CRT_INLINE long مزدوج __cdecl acosl(long مزدوج x) { أرجع acos(x); }
__CRT_INLINE long مزدوج __cdecl atanl(long مزدوج x) { أرجع atan(x); }
__CRT_INLINE long مزدوج __cdecl ceill(long مزدوج x) { أرجع ceil(x); }
__CRT_INLINE long مزدوج __cdecl coshl(long مزدوج x) { أرجع cosh(x); }
__CRT_INLINE long مزدوج __cdecl cosl(long مزدوج x) { أرجع cos(x); }
__CRT_INLINE long مزدوج __cdecl expl(long مزدوج x) { أرجع exp(x); }
__CRT_INLINE long مزدوج __cdecl floorl(long مزدوج x) { أرجع floor(x); }
__CRT_INLINE long مزدوج __cdecl fmodl(long مزدوج x, long مزدوج y) { أرجع fmod(x, y); }
__CRT_INLINE long مزدوج __cdecl hypotl(long مزدوج x, long مزدوج y) { أرجع hypot(x, y); }
__CRT_INLINE long مزدوج __cdecl logl(long مزدوج x) { أرجع log(x); }
__CRT_INLINE long مزدوج __cdecl logbl(long مزدوج x) { أرجع logb(x); }
__CRT_INLINE long مزدوج __cdecl log10l(long مزدوج x) { أرجع log10(x); }
__CRT_INLINE long مزدوج __cdecl modfl(long مزدوج x, long مزدوج* y) { مزدوج y1 = *y; x = modf(x, &y1); *y = y1; أرجع x; }
__CRT_INLINE long مزدوج __cdecl powl(long مزدوج x, long مزدوج y) { أرجع pow(x, y); }
__CRT_INLINE long مزدوج __cdecl sinhl(long مزدوج x) { أرجع sinh(x); }
__CRT_INLINE long مزدوج __cdecl sinl(long مزدوج x) { أرجع sin(x); }
__CRT_INLINE long مزدوج __cdecl sqrtl(long مزدوج x) { أرجع sqrt(x); }
__CRT_INLINE long مزدوج __cdecl tanhl(long مزدوج x) { أرجع tanh(x); }
__CRT_INLINE long مزدوج __cdecl tanl(long مزدوج x) { أرجع tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE مزدوج __cdecl log1p(مزدوج x) {
  مزدوج u = 1.0 + x;
  أرجع u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE عائم __cdecl log1pf(عائم x) {
  عائم u = 1.0f + x;
  أرجع u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long مزدوج __cdecl log1pl(long مزدوج x) {
  أرجع log1p(x);
}


__CRT_INLINE مزدوج __cdecl expm1(مزدوج x) {
  إذا (x > 0.0024 || x < -0.0024) أرجع exp(x) - 1.0;
  أرجع x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE عائم __cdecl expm1f(عائم x) {
  إذا (x > 0.085f || x < -0.085f) أرجع expf(x) - 1.0f;
  أرجع x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long مزدوج __cdecl expm1l(long مزدوج x) {
  أرجع expm1(x);
}


__CRT_INLINE مزدوج __cdecl cbrt(مزدوج x) {
  أرجع x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE عائم __cdecl cbrtf(عائم x) {
  أرجع x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long مزدوج __cdecl cbrtl(long مزدوج x) {
  أرجع cbrt(x);
}


__CRT_INLINE مزدوج __cdecl log2(مزدوج x) {
  أرجع log(x) * 1.442695040888963407;
}
__CRT_INLINE عائم __cdecl log2f(عائم x) {
  أرجع log(x) * 1.442695040888963407;
}
__CRT_INLINE long مزدوج __cdecl log2l(long مزدوج x) {
  أرجع log(x) * 1.442695040888963407;
}


__CRT_INLINE مزدوج __cdecl exp2(مزدوج x) {
  أرجع exp(x * 0.693147180559945309);
}
__CRT_INLINE عائم __cdecl exp2f(عائم x) {
  أرجع exp(x * 0.693147180559945309);
}
__CRT_INLINE long مزدوج __cdecl exp2l(long مزدوج x) {
  أرجع exp(x * 0.693147180559945309);
}


__CRT_INLINE صحيح __cdecl ilogb(مزدوج x) {
  أرجع (صحيح) logb(x);
}
__CRT_INLINE صحيح __cdecl ilogbf(عائم x) {
  أرجع (صحيح) logbf(x);
}
__CRT_INLINE صحيح __cdecl ilogbl(long مزدوج x) {
  أرجع (صحيح) logb(x);
}


__CRT_INLINE مزدوج __cdecl fdim(مزدوج x, مزدوج y) {
  إذا (isnan(x) || isnan(y)) أرجع NAN;
  أرجع x > y ? x - y : 0;
}
__CRT_INLINE عائم __cdecl fdimf(عائم x, عائم y) {
  إذا (isnan(x) || isnan(y)) أرجع NAN;
  أرجع x > y ? x - y : 0;
}
__CRT_INLINE long مزدوج __cdecl fdiml(long مزدوج x, long مزدوج y) {
  إذا (isnan(x) || isnan(y)) أرجع NAN;
  أرجع x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE مزدوج __cdecl tgamma(مزدوج x) {
  مزدوج m = 1.0, t = 3.14159265358979323;
  إذا (x == floor(x)) {
    إذا (x == 0) أرجع INFINITY;
    إذا (x < 0) أرجع NAN;
    إذا (x < 26) { لكل (مزدوج k = 2; k < x; ++k) m *= k; أرجع m; }
  }
  إذا (x < 0.5)
    أرجع t / (sin(t*x)*tgamma(1.0 - x));
  إذا (x > 12.0)
    أرجع exp(lgamma(x));

  ساكن ثابت مزدوج c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  لكل (صحيح k = 0; k < 8; ++k) m += c[k] / (x + k);
  أرجع 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE مزدوج __cdecl lgamma(مزدوج x) {
  إذا (x < 12.0) {
    إذا (x <= 0.0 && x == floor(x)) أرجع INFINITY;
    x = tgamma(x);
    أرجع log(x < 0.0 ? -x : x);
  }
  ساكن ثابت مزدوج c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  مزدوج m = -3617.0/122400.0, t = 1.0 / (x*x);
  لكل (صحيح k = 6; k >= 0; --k) m = m*t + c[k];
  أرجع (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE عائم __cdecl tgammaf(عائم x) {
  أرجع tgamma(x);
}
__CRT_INLINE عائم __cdecl lgammaf(عائم x) {
  أرجع lgamma(x);
}
__CRT_INLINE long مزدوج __cdecl tgammal(long مزدوج x) {
  أرجع tgamma(x);
}
__CRT_INLINE long مزدوج __cdecl lgammal(long مزدوج x) {
  أرجع lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
