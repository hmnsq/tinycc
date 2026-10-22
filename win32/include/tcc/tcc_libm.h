#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#অন্তর্ভাব "../math.h"
#অন্তর্ভাব "../stdint.h"

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

__CRT_INLINE পূর্ণসংখ্যা __cdecl __fpclassify (দ্বিগুণ x) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u = {.f = x};
  পূর্ণসংখ্যা e = u.i>>52 & 0x7ff;
  যদি (!e) ফেরত u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  যদি (e==0x7ff) ফেরত u.i<<12 ? FP_NAN : FP_INFINITE;
  ফেরত FP_NORMAL;
}

__CRT_INLINE পূর্ণসংখ্যা __cdecl __fpclassifyf (দশমিক x) {
  সংঘ {দশমিক f; uint32_t i;} u = {.f = x};
  পূর্ণসংখ্যা e = u.i>>23 & 0xff;
  যদি (!e) ফেরত u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  যদি (e==0xff) ফেরত u.i<<9 ? FP_NAN : FP_INFINITE;
  ফেরত FP_NORMAL;
}

__CRT_INLINE পূর্ণসংখ্যা __cdecl __fpclassifyl (long দ্বিগুণ x) {
  ফেরত __fpclassify(x);
}


/* signbit */

__CRT_INLINE পূর্ণসংখ্যা __cdecl __signbit (দ্বিগুণ x) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u = {.f = x};
  ফেরত u.i>>63;
}

__CRT_INLINE পূর্ণসংখ্যা __cdecl __signbitf (দশমিক x) {
  সংঘ {দশমিক f; uint32_t i; } u = {.f = x};
  ফেরত u.i>>31;
}

__CRT_INLINE পূর্ণসংখ্যা __cdecl __signbitl (long দ্বিগুণ x) {
  ফেরত __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE দ্বিগুণ __cdecl fmin (দ্বিগুণ x, দ্বিগুণ y) {
  ফেরত TCCFP_FMIN_EVAL;
}

__CRT_INLINE দশমিক __cdecl fminf (দশমিক x, দশমিক y) {
  ফেরত TCCFP_FMIN_EVAL;
}

__CRT_INLINE long দ্বিগুণ __cdecl fminl (long দ্বিগুণ x, long দ্বিগুণ y) {
  ফেরত TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE দ্বিগুণ __cdecl fmax (দ্বিগুণ x, দ্বিগুণ y) {
  ফেরত TCCFP_FMAX_EVAL;
}

__CRT_INLINE দশমিক __cdecl fmaxf (দশমিক x, দশমিক y) {
  ফেরত TCCFP_FMAX_EVAL;
}

__CRT_INLINE long দ্বিগুণ __cdecl fmaxl (long দ্বিগুণ x, long দ্বিগুণ y) {
  ফেরত TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) করো {  \
  অস্থির typeof(x) __x;         \
  __x = (x);                      \
} যখন(0)

__CRT_INLINE দ্বিগুণ __cdecl round (দ্বিগুণ x) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u = {.f = x};
  পূর্ণসংখ্যা e = u.i >> 52 & 0x7ff;
  দ্বিগুণ y;

  যদি (e >= 0x3ff+52)
    ফেরত x;
  যদি (u.i >> 63)
    x = -x;
  যদি (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    ফেরত 0*u.f;
  }
  y = (দ্বিগুণ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  ফেরত (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (দ্বিগুণ x) {
  ফেরত round(x);
}

__CRT_INLINE long long __cdecl llround (দ্বিগুণ x) {
  ফেরত round(x);
}

__CRT_INLINE দশমিক __cdecl roundf (দশমিক x) {
  ফেরত round(x);
}

__CRT_INLINE long __cdecl lroundf (দশমিক x) {
  ফেরত round(x);
}

__CRT_INLINE long long __cdecl llroundf (দশমিক x) {
  ফেরত round(x);
}

__CRT_INLINE long দ্বিগুণ __cdecl roundl (long দ্বিগুণ x) {
  ফেরত round(x);
}

__CRT_INLINE long __cdecl lroundl (long দ্বিগুণ x) {
  ফেরত round(x);
}

__CRT_INLINE long long __cdecl llroundl (long দ্বিগুণ x) {
  ফেরত round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE দ্বিগুণ __cdecl asinh(দ্বিগুণ x) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  যদি (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  অন্যথা যদি (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  অন্যথা যদি (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  অন্যথা TCCFP_FORCE_EVAL(x + 0x1p120f);
  ফেরত s ? -x : x;
}

__CRT_INLINE দ্বিগুণ __cdecl acosh(দ্বিগুণ x) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  যদি (e < 0x3ff + 1) ফেরত --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  যদি (e < 0x3ff + 26) ফেরত log(2*x - 1 / (x + sqrt(x*x - 1)));
  ফেরত log(x) + 0.693147180559945309;
}

__CRT_INLINE দ্বিগুণ __cdecl atanh(দ্বিগুণ x) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  যদি (e < 0x3ff - 1) {
    যদি (e < 0x3ff - 32) { যদি (e == 0) TCCFP_FORCE_EVAL((দশমিক)x); }
    অন্যথা x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } অন্যথা x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  ফেরত s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE দ্বিগুণ __cdecl scalbn(দ্বিগুণ x, পূর্ণসংখ্যা n) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u;
  যদি (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    যদি (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      যদি (n > 1023) n = 1023;
    }
  } অন্যথা যদি (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    যদি (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      যদি (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  ফেরত x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE দ্বিগুণ __cdecl frexp(দ্বিগুণ x, পূর্ণসংখ্যা *e) {
  সংঘ {দ্বিগুণ f; uint64_t i;} u = {.f = x};
  পূর্ণসংখ্যা ee = u.i>>52 & 0x7ff;
  যদি (!ee) {
    যদি (x) x = frexp(x*0x1p64, e), *e -= 64;
    অন্যথা *e = 0;
    ফেরত x;
  } অন্যথা যদি (ee == 0x7ff)
    ফেরত x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  ফেরত u.f;
}

/* MUSL nan */

__CRT_INLINE দ্বিগুণ __cdecl nan(ধ্রুবক অক্ষর* s) {
  ফেরত NAN;
}
__CRT_INLINE দশমিক __cdecl nanf(ধ্রুবক অক্ষর* s) {
  ফেরত NAN;
}
__CRT_INLINE long দ্বিগুণ __cdecl nanl(ধ্রুবক অক্ষর* s) {
  ফেরত NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE দশমিক __cdecl scalbnf(দশমিক x, পূর্ণসংখ্যা n) {
  ফেরত scalbn(x, n);
}
__CRT_INLINE long দ্বিগুণ __cdecl scalbnl(long দ্বিগুণ x, পূর্ণসংখ্যা n) {
  ফেরত scalbn(x, n);
}

__CRT_INLINE দ্বিগুণ __cdecl scalbln(দ্বিগুণ x, long n) {
  ফেরত scalbn(x, n);
}
__CRT_INLINE দশমিক __cdecl scalblnf(দশমিক x, long n) {
  ফেরত scalbn(x, n);
}
__CRT_INLINE long দ্বিগুণ __cdecl scalblnl(long দ্বিগুণ x, long n) {
  ফেরত scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE দ্বিগুণ __cdecl ldexp(দ্বিগুণ x, পূর্ণসংখ্যা expn) {
  ফেরত scalbn(x, expn);
}
__CRT_INLINE দশমিক __cdecl ldexpf(দশমিক x, পূর্ণসংখ্যা expn) {
  ফেরত scalbn(x, expn);
}
__CRT_INLINE long দ্বিগুণ __cdecl ldexpl(long দ্বিগুণ x, পূর্ণসংখ্যা expn) {
  ফেরত scalbn(x, expn);
}

__CRT_INLINE দশমিক __cdecl frexpf(দশমিক x, পূর্ণসংখ্যা *y) {
  ফেরত frexp(x, y);
}
__CRT_INLINE long দ্বিগুণ __cdecl frexpl (long দ্বিগুণ x, পূর্ণসংখ্যা* y) {
  ফেরত frexp(x, y);
}


__CRT_INLINE দ্বিগুণ __cdecl rint(দ্বিগুণ x) {
দ্বিগুণ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  ফেরত retval;
}

__CRT_INLINE দশমিক __cdecl rintf(দশমিক x) {
  দশমিক retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   ফেরত retval;
}
__CRT_INLINE long দ্বিগুণ __cdecl rintl (long দ্বিগুণ x) {
  ফেরত rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(দ্বিগুণ x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ফেরত retval;
}

__CRT_INLINE long __cdecl lrintf(দশমিক x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ফেরত retval;
}

__CRT_INLINE long __cdecl lrintl (long দ্বিগুণ x) {
  ফেরত lrint(x);
}


__CRT_INLINE long long __cdecl llrint(দ্বিগুণ x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ফেরত retval;
}

__CRT_INLINE long long __cdecl llrintf(দশমিক x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ফেরত retval;
}

__CRT_INLINE long long __cdecl llrintl (long দ্বিগুণ x) {
  ফেরত llrint(x);
}


__CRT_INLINE দ্বিগুণ __cdecl trunc(দ্বিগুণ _x) {
  দ্বিগুণ retval;
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
  ফেরত retval;
}

__CRT_INLINE দশমিক __cdecl truncf(দশমিক x) {
  ফেরত (দশমিক) ((intptr_t) x);
}
__CRT_INLINE long দ্বিগুণ __cdecl truncl(long দ্বিগুণ x) {
  ফেরত trunc(x);
}


__CRT_INLINE long দ্বিগুণ __cdecl nextafterl(long দ্বিগুণ x, long দ্বিগুণ to) {
  ফেরত nextafter(x, to);
}

__CRT_INLINE দ্বিগুণ __cdecl nexttoward(দ্বিগুণ x, long দ্বিগুণ to) {
  ফেরত nextafter(x, to);
}
__CRT_INLINE দশমিক __cdecl nexttowardf(দশমিক x, long দ্বিগুণ to) {
  ফেরত nextafterf(x, to);
}
__CRT_INLINE long দ্বিগুণ __cdecl nexttowardl(long দ্বিগুণ x, long দ্বিগুণ to) {
  ফেরত nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE দ্বিগুণ __cdecl fabs(দ্বিগুণ x) {
  ফেরত x < 0 ? -x : x;
}
__CRT_INLINE দশমিক __cdecl fabsf(দশমিক x) {
  ফেরত x < 0 ? -x : x;
}
__CRT_INLINE long দ্বিগুণ __cdecl fabsl(long দ্বিগুণ x) {
  ফেরত x < 0 ? -x : x;
}


#যদি defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE দশমিক acosf(দশমিক x) { ফেরত acos(x); }
  __CRT_INLINE দশমিক asinf(দশমিক x) { ফেরত asin(x); }
  __CRT_INLINE দশমিক atanf(দশমিক x) { ফেরত atan(x); }
  __CRT_INLINE দশমিক atan2f(দশমিক x, দশমিক y) { ফেরত atan2(x, y); }
  __CRT_INLINE দশমিক ceilf(দশমিক x) { ফেরত ceil(x); }
  __CRT_INLINE দশমিক cosf(দশমিক x) { ফেরত cos(x); }
  __CRT_INLINE দশমিক coshf(দশমিক x) { ফেরত cosh(x); }
  __CRT_INLINE দশমিক expf(দশমিক x) { ফেরত exp(x); }
  __CRT_INLINE দশমিক floorf(দশমিক x) { ফেরত floor(x); }
  __CRT_INLINE দশমিক fmodf(দশমিক x, দশমিক y) { ফেরত fmod(x, y); }
  __CRT_INLINE দশমিক logf(দশমিক x) { ফেরত log(x); }
  __CRT_INLINE দশমিক logbf(দশমিক x) { ফেরত logb(x); }
  __CRT_INLINE দশমিক log10f(দশমিক x) { ফেরত log10(x); }
  __CRT_INLINE দশমিক modff(দশমিক x, দশমিক *y) { দ্বিগুণ di, df = modf(x, &di); *y = di; ফেরত df; }
  __CRT_INLINE দশমিক powf(দশমিক x, দশমিক y) { ফেরত pow(x, y); }
  __CRT_INLINE দশমিক sinf(দশমিক x) { ফেরত sin(x); }
  __CRT_INLINE দশমিক sinhf(দশমিক x) { ফেরত sinh(x); }
  __CRT_INLINE দশমিক sqrtf(দশমিক x) { ফেরত sqrt(x); }
  __CRT_INLINE দশমিক tanf(দশমিক x) { ফেরত tan(x); }
  __CRT_INLINE দশমিক tanhf(দশমিক x) { ফেরত tanh(x); }
#endif
__CRT_INLINE দশমিক __cdecl asinhf(দশমিক x) { ফেরত asinh(x); }
__CRT_INLINE দশমিক __cdecl acoshf(দশমিক x) { ফেরত acosh(x); }
__CRT_INLINE দশমিক __cdecl atanhf(দশমিক x) { ফেরত atanh(x); }

__CRT_INLINE long দ্বিগুণ __cdecl asinhl(long দ্বিগুণ x) { ফেরত asinh(x); }
__CRT_INLINE long দ্বিগুণ __cdecl acoshl(long দ্বিগুণ x) { ফেরত acosh(x); }
__CRT_INLINE long দ্বিগুণ __cdecl atanhl(long দ্বিগুণ x) { ফেরত atanh(x); }
__CRT_INLINE long দ্বিগুণ __cdecl asinl(long দ্বিগুণ x) { ফেরত asin(x); }
__CRT_INLINE long দ্বিগুণ __cdecl acosl(long দ্বিগুণ x) { ফেরত acos(x); }
__CRT_INLINE long দ্বিগুণ __cdecl atanl(long দ্বিগুণ x) { ফেরত atan(x); }
__CRT_INLINE long দ্বিগুণ __cdecl ceill(long দ্বিগুণ x) { ফেরত ceil(x); }
__CRT_INLINE long দ্বিগুণ __cdecl coshl(long দ্বিগুণ x) { ফেরত cosh(x); }
__CRT_INLINE long দ্বিগুণ __cdecl cosl(long দ্বিগুণ x) { ফেরত cos(x); }
__CRT_INLINE long দ্বিগুণ __cdecl expl(long দ্বিগুণ x) { ফেরত exp(x); }
__CRT_INLINE long দ্বিগুণ __cdecl floorl(long দ্বিগুণ x) { ফেরত floor(x); }
__CRT_INLINE long দ্বিগুণ __cdecl fmodl(long দ্বিগুণ x, long দ্বিগুণ y) { ফেরত fmod(x, y); }
__CRT_INLINE long দ্বিগুণ __cdecl hypotl(long দ্বিগুণ x, long দ্বিগুণ y) { ফেরত hypot(x, y); }
__CRT_INLINE long দ্বিগুণ __cdecl logl(long দ্বিগুণ x) { ফেরত log(x); }
__CRT_INLINE long দ্বিগুণ __cdecl logbl(long দ্বিগুণ x) { ফেরত logb(x); }
__CRT_INLINE long দ্বিগুণ __cdecl log10l(long দ্বিগুণ x) { ফেরত log10(x); }
__CRT_INLINE long দ্বিগুণ __cdecl modfl(long দ্বিগুণ x, long দ্বিগুণ* y) { দ্বিগুণ y1 = *y; x = modf(x, &y1); *y = y1; ফেরত x; }
__CRT_INLINE long দ্বিগুণ __cdecl powl(long দ্বিগুণ x, long দ্বিগুণ y) { ফেরত pow(x, y); }
__CRT_INLINE long দ্বিগুণ __cdecl sinhl(long দ্বিগুণ x) { ফেরত sinh(x); }
__CRT_INLINE long দ্বিগুণ __cdecl sinl(long দ্বিগুণ x) { ফেরত sin(x); }
__CRT_INLINE long দ্বিগুণ __cdecl sqrtl(long দ্বিগুণ x) { ফেরত sqrt(x); }
__CRT_INLINE long দ্বিগুণ __cdecl tanhl(long দ্বিগুণ x) { ফেরত tanh(x); }
__CRT_INLINE long দ্বিগুণ __cdecl tanl(long দ্বিগুণ x) { ফেরত tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE দ্বিগুণ __cdecl log1p(দ্বিগুণ x) {
  দ্বিগুণ u = 1.0 + x;
  ফেরত u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE দশমিক __cdecl log1pf(দশমিক x) {
  দশমিক u = 1.0f + x;
  ফেরত u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long দ্বিগুণ __cdecl log1pl(long দ্বিগুণ x) {
  ফেরত log1p(x);
}


__CRT_INLINE দ্বিগুণ __cdecl expm1(দ্বিগুণ x) {
  যদি (x > 0.0024 || x < -0.0024) ফেরত exp(x) - 1.0;
  ফেরত x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE দশমিক __cdecl expm1f(দশমিক x) {
  যদি (x > 0.085f || x < -0.085f) ফেরত expf(x) - 1.0f;
  ফেরত x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long দ্বিগুণ __cdecl expm1l(long দ্বিগুণ x) {
  ফেরত expm1(x);
}


__CRT_INLINE দ্বিগুণ __cdecl cbrt(দ্বিগুণ x) {
  ফেরত x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE দশমিক __cdecl cbrtf(দশমিক x) {
  ফেরত x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long দ্বিগুণ __cdecl cbrtl(long দ্বিগুণ x) {
  ফেরত cbrt(x);
}


__CRT_INLINE দ্বিগুণ __cdecl log2(দ্বিগুণ x) {
  ফেরত log(x) * 1.442695040888963407;
}
__CRT_INLINE দশমিক __cdecl log2f(দশমিক x) {
  ফেরত log(x) * 1.442695040888963407;
}
__CRT_INLINE long দ্বিগুণ __cdecl log2l(long দ্বিগুণ x) {
  ফেরত log(x) * 1.442695040888963407;
}


__CRT_INLINE দ্বিগুণ __cdecl exp2(দ্বিগুণ x) {
  ফেরত exp(x * 0.693147180559945309);
}
__CRT_INLINE দশমিক __cdecl exp2f(দশমিক x) {
  ফেরত exp(x * 0.693147180559945309);
}
__CRT_INLINE long দ্বিগুণ __cdecl exp2l(long দ্বিগুণ x) {
  ফেরত exp(x * 0.693147180559945309);
}


__CRT_INLINE পূর্ণসংখ্যা __cdecl ilogb(দ্বিগুণ x) {
  ফেরত (পূর্ণসংখ্যা) logb(x);
}
__CRT_INLINE পূর্ণসংখ্যা __cdecl ilogbf(দশমিক x) {
  ফেরত (পূর্ণসংখ্যা) logbf(x);
}
__CRT_INLINE পূর্ণসংখ্যা __cdecl ilogbl(long দ্বিগুণ x) {
  ফেরত (পূর্ণসংখ্যা) logb(x);
}


__CRT_INLINE দ্বিগুণ __cdecl fdim(দ্বিগুণ x, দ্বিগুণ y) {
  যদি (isnan(x) || isnan(y)) ফেরত NAN;
  ফেরত x > y ? x - y : 0;
}
__CRT_INLINE দশমিক __cdecl fdimf(দশমিক x, দশমিক y) {
  যদি (isnan(x) || isnan(y)) ফেরত NAN;
  ফেরত x > y ? x - y : 0;
}
__CRT_INLINE long দ্বিগুণ __cdecl fdiml(long দ্বিগুণ x, long দ্বিগুণ y) {
  যদি (isnan(x) || isnan(y)) ফেরত NAN;
  ফেরত x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE দ্বিগুণ __cdecl tgamma(দ্বিগুণ x) {
  দ্বিগুণ m = 1.0, t = 3.14159265358979323;
  যদি (x == floor(x)) {
    যদি (x == 0) ফেরত INFINITY;
    যদি (x < 0) ফেরত NAN;
    যদি (x < 26) { জন্য (দ্বিগুণ k = 2; k < x; ++k) m *= k; ফেরত m; }
  }
  যদি (x < 0.5)
    ফেরত t / (sin(t*x)*tgamma(1.0 - x));
  যদি (x > 12.0)
    ফেরত exp(lgamma(x));

  স্থির ধ্রুবক দ্বিগুণ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  জন্য (পূর্ণসংখ্যা k = 0; k < 8; ++k) m += c[k] / (x + k);
  ফেরত 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE দ্বিগুণ __cdecl lgamma(দ্বিগুণ x) {
  যদি (x < 12.0) {
    যদি (x <= 0.0 && x == floor(x)) ফেরত INFINITY;
    x = tgamma(x);
    ফেরত log(x < 0.0 ? -x : x);
  }
  স্থির ধ্রুবক দ্বিগুণ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  দ্বিগুণ m = -3617.0/122400.0, t = 1.0 / (x*x);
  জন্য (পূর্ণসংখ্যা k = 6; k >= 0; --k) m = m*t + c[k];
  ফেরত (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE দশমিক __cdecl tgammaf(দশমিক x) {
  ফেরত tgamma(x);
}
__CRT_INLINE দশমিক __cdecl lgammaf(দশমিক x) {
  ফেরত lgamma(x);
}
__CRT_INLINE long দ্বিগুণ __cdecl tgammal(long দ্বিগুণ x) {
  ফেরত tgamma(x);
}
__CRT_INLINE long দ্বিগুণ __cdecl lgammal(long দ্বিগুণ x) {
  ফেরত lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
