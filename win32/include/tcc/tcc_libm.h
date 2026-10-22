#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#অন্তর্ভাৱ "../math.h"
#অন্তর্ভাৱ "../stdint.h"

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

__CRT_INLINE পূর্ণাঙ্ক __cdecl __fpclassify (দ্ৱিগুণ x) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u = {.f = x};
  পূর্ণাঙ্ক e = u.i>>52 & 0x7ff;
  যদি (!e) ঘূৰাই u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  যদি (e==0x7ff) ঘূৰাই u.i<<12 ? FP_NAN : FP_INFINITE;
  ঘূৰাই FP_NORMAL;
}

__CRT_INLINE পূর্ণাঙ্ক __cdecl __fpclassifyf (ভিন্ন x) {
  সঙ্ঘ {ভিন্ন f; uint32_t i;} u = {.f = x};
  পূর্ণাঙ্ক e = u.i>>23 & 0xff;
  যদি (!e) ঘূৰাই u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  যদি (e==0xff) ঘূৰাই u.i<<9 ? FP_NAN : FP_INFINITE;
  ঘূৰাই FP_NORMAL;
}

__CRT_INLINE পূর্ণাঙ্ক __cdecl __fpclassifyl (long দ্ৱিগুণ x) {
  ঘূৰাই __fpclassify(x);
}


/* signbit */

__CRT_INLINE পূর্ণাঙ্ক __cdecl __signbit (দ্ৱিগুণ x) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u = {.f = x};
  ঘূৰাই u.i>>63;
}

__CRT_INLINE পূর্ণাঙ্ক __cdecl __signbitf (ভিন্ন x) {
  সঙ্ঘ {ভিন্ন f; uint32_t i; } u = {.f = x};
  ঘূৰাই u.i>>31;
}

__CRT_INLINE পূর্ণাঙ্ক __cdecl __signbitl (long দ্ৱিগুণ x) {
  ঘূৰাই __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE দ্ৱিগুণ __cdecl fmin (দ্ৱিগুণ x, দ্ৱিগুণ y) {
  ঘূৰাই TCCFP_FMIN_EVAL;
}

__CRT_INLINE ভিন্ন __cdecl fminf (ভিন্ন x, ভিন্ন y) {
  ঘূৰাই TCCFP_FMIN_EVAL;
}

__CRT_INLINE long দ্ৱিগুণ __cdecl fminl (long দ্ৱিগুণ x, long দ্ৱিগুণ y) {
  ঘূৰাই TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE দ্ৱিগুণ __cdecl fmax (দ্ৱিগুণ x, দ্ৱিগুণ y) {
  ঘূৰাই TCCFP_FMAX_EVAL;
}

__CRT_INLINE ভিন্ন __cdecl fmaxf (ভিন্ন x, ভিন্ন y) {
  ঘূৰাই TCCFP_FMAX_EVAL;
}

__CRT_INLINE long দ্ৱিগুণ __cdecl fmaxl (long দ্ৱিগুণ x, long দ্ৱিগুণ y) {
  ঘূৰাই TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) কৰা {  \
  চঞ্চল typeof(x) __x;         \
  __x = (x);                      \
} যেতিয়ালৈ(0)

__CRT_INLINE দ্ৱিগুণ __cdecl round (দ্ৱিগুণ x) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u = {.f = x};
  পূর্ণাঙ্ক e = u.i >> 52 & 0x7ff;
  দ্ৱিগুণ y;

  যদি (e >= 0x3ff+52)
    ঘূৰাই x;
  যদি (u.i >> 63)
    x = -x;
  যদি (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    ঘূৰাই 0*u.f;
  }
  y = (দ্ৱিগুণ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  ঘূৰাই (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (দ্ৱিগুণ x) {
  ঘূৰাই round(x);
}

__CRT_INLINE long long __cdecl llround (দ্ৱিগুণ x) {
  ঘূৰাই round(x);
}

__CRT_INLINE ভিন্ন __cdecl roundf (ভিন্ন x) {
  ঘূৰাই round(x);
}

__CRT_INLINE long __cdecl lroundf (ভিন্ন x) {
  ঘূৰাই round(x);
}

__CRT_INLINE long long __cdecl llroundf (ভিন্ন x) {
  ঘূৰাই round(x);
}

__CRT_INLINE long দ্ৱিগুণ __cdecl roundl (long দ্ৱিগুণ x) {
  ঘূৰাই round(x);
}

__CRT_INLINE long __cdecl lroundl (long দ্ৱিগুণ x) {
  ঘূৰাই round(x);
}

__CRT_INLINE long long __cdecl llroundl (long দ্ৱিগুণ x) {
  ঘূৰাই round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE দ্ৱিগুণ __cdecl asinh(দ্ৱিগুণ x) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  যদি (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  অন্যথা যদি (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  অন্যথা যদি (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  অন্যথা TCCFP_FORCE_EVAL(x + 0x1p120f);
  ঘূৰাই s ? -x : x;
}

__CRT_INLINE দ্ৱিগুণ __cdecl acosh(দ্ৱিগুণ x) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  যদি (e < 0x3ff + 1) ঘূৰাই --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  যদি (e < 0x3ff + 26) ঘূৰাই log(2*x - 1 / (x + sqrt(x*x - 1)));
  ঘূৰাই log(x) + 0.693147180559945309;
}

__CRT_INLINE দ্ৱিগুণ __cdecl atanh(দ্ৱিগুণ x) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  যদি (e < 0x3ff - 1) {
    যদি (e < 0x3ff - 32) { যদি (e == 0) TCCFP_FORCE_EVAL((ভিন্ন)x); }
    অন্যথা x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } অন্যথা x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  ঘূৰাই s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE দ্ৱিগুণ __cdecl scalbn(দ্ৱিগুণ x, পূর্ণাঙ্ক n) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u;
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
  ঘূৰাই x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE দ্ৱিগুণ __cdecl frexp(দ্ৱিগুণ x, পূর্ণাঙ্ক *e) {
  সঙ্ঘ {দ্ৱিগুণ f; uint64_t i;} u = {.f = x};
  পূর্ণাঙ্ক ee = u.i>>52 & 0x7ff;
  যদি (!ee) {
    যদি (x) x = frexp(x*0x1p64, e), *e -= 64;
    অন্যথা *e = 0;
    ঘূৰাই x;
  } অন্যথা যদি (ee == 0x7ff)
    ঘূৰাই x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  ঘূৰাই u.f;
}

/* MUSL nan */

__CRT_INLINE দ্ৱিগুণ __cdecl nan(ধ্রুৱ ৱর্ণ* s) {
  ঘূৰাই NAN;
}
__CRT_INLINE ভিন্ন __cdecl nanf(ধ্রুৱ ৱর্ণ* s) {
  ঘূৰাই NAN;
}
__CRT_INLINE long দ্ৱিগুণ __cdecl nanl(ধ্রুৱ ৱর্ণ* s) {
  ঘূৰাই NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE ভিন্ন __cdecl scalbnf(ভিন্ন x, পূর্ণাঙ্ক n) {
  ঘূৰাই scalbn(x, n);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl scalbnl(long দ্ৱিগুণ x, পূর্ণাঙ্ক n) {
  ঘূৰাই scalbn(x, n);
}

__CRT_INLINE দ্ৱিগুণ __cdecl scalbln(দ্ৱিগুণ x, long n) {
  ঘূৰাই scalbn(x, n);
}
__CRT_INLINE ভিন্ন __cdecl scalblnf(ভিন্ন x, long n) {
  ঘূৰাই scalbn(x, n);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl scalblnl(long দ্ৱিগুণ x, long n) {
  ঘূৰাই scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE দ্ৱিগুণ __cdecl ldexp(দ্ৱিগুণ x, পূর্ণাঙ্ক expn) {
  ঘূৰাই scalbn(x, expn);
}
__CRT_INLINE ভিন্ন __cdecl ldexpf(ভিন্ন x, পূর্ণাঙ্ক expn) {
  ঘূৰাই scalbn(x, expn);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl ldexpl(long দ্ৱিগুণ x, পূর্ণাঙ্ক expn) {
  ঘূৰাই scalbn(x, expn);
}

__CRT_INLINE ভিন্ন __cdecl frexpf(ভিন্ন x, পূর্ণাঙ্ক *y) {
  ঘূৰাই frexp(x, y);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl frexpl (long দ্ৱিগুণ x, পূর্ণাঙ্ক* y) {
  ঘূৰাই frexp(x, y);
}


__CRT_INLINE দ্ৱিগুণ __cdecl rint(দ্ৱিগুণ x) {
দ্ৱিগুণ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  ঘূৰাই retval;
}

__CRT_INLINE ভিন্ন __cdecl rintf(ভিন্ন x) {
  ভিন্ন retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   ঘূৰাই retval;
}
__CRT_INLINE long দ্ৱিগুণ __cdecl rintl (long দ্ৱিগুণ x) {
  ঘূৰাই rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(দ্ৱিগুণ x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ঘূৰাই retval;
}

__CRT_INLINE long __cdecl lrintf(ভিন্ন x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ঘূৰাই retval;
}

__CRT_INLINE long __cdecl lrintl (long দ্ৱিগুণ x) {
  ঘূৰাই lrint(x);
}


__CRT_INLINE long long __cdecl llrint(দ্ৱিগুণ x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ঘূৰাই retval;
}

__CRT_INLINE long long __cdecl llrintf(ভিন্ন x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ঘূৰাই retval;
}

__CRT_INLINE long long __cdecl llrintl (long দ্ৱিগুণ x) {
  ঘূৰাই llrint(x);
}


__CRT_INLINE দ্ৱিগুণ __cdecl trunc(দ্ৱিগুণ _x) {
  দ্ৱিগুণ retval;
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
  ঘূৰাই retval;
}

__CRT_INLINE ভিন্ন __cdecl truncf(ভিন্ন x) {
  ঘূৰাই (ভিন্ন) ((intptr_t) x);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl truncl(long দ্ৱিগুণ x) {
  ঘূৰাই trunc(x);
}


__CRT_INLINE long দ্ৱিগুণ __cdecl nextafterl(long দ্ৱিগুণ x, long দ্ৱিগুণ to) {
  ঘূৰাই nextafter(x, to);
}

__CRT_INLINE দ্ৱিগুণ __cdecl nexttoward(দ্ৱিগুণ x, long দ্ৱিগুণ to) {
  ঘূৰাই nextafter(x, to);
}
__CRT_INLINE ভিন্ন __cdecl nexttowardf(ভিন্ন x, long দ্ৱিগুণ to) {
  ঘূৰাই nextafterf(x, to);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl nexttowardl(long দ্ৱিগুণ x, long দ্ৱিগুণ to) {
  ঘূৰাই nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE দ্ৱিগুণ __cdecl fabs(দ্ৱিগুণ x) {
  ঘূৰাই x < 0 ? -x : x;
}
__CRT_INLINE ভিন্ন __cdecl fabsf(ভিন্ন x) {
  ঘূৰাই x < 0 ? -x : x;
}
__CRT_INLINE long দ্ৱিগুণ __cdecl fabsl(long দ্ৱিগুণ x) {
  ঘূৰাই x < 0 ? -x : x;
}


#যদি defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE ভিন্ন acosf(ভিন্ন x) { ঘূৰাই acos(x); }
  __CRT_INLINE ভিন্ন asinf(ভিন্ন x) { ঘূৰাই asin(x); }
  __CRT_INLINE ভিন্ন atanf(ভিন্ন x) { ঘূৰাই atan(x); }
  __CRT_INLINE ভিন্ন atan2f(ভিন্ন x, ভিন্ন y) { ঘূৰাই atan2(x, y); }
  __CRT_INLINE ভিন্ন ceilf(ভিন্ন x) { ঘূৰাই ceil(x); }
  __CRT_INLINE ভিন্ন cosf(ভিন্ন x) { ঘূৰাই cos(x); }
  __CRT_INLINE ভিন্ন coshf(ভিন্ন x) { ঘূৰাই cosh(x); }
  __CRT_INLINE ভিন্ন expf(ভিন্ন x) { ঘূৰাই exp(x); }
  __CRT_INLINE ভিন্ন floorf(ভিন্ন x) { ঘূৰাই floor(x); }
  __CRT_INLINE ভিন্ন fmodf(ভিন্ন x, ভিন্ন y) { ঘূৰাই fmod(x, y); }
  __CRT_INLINE ভিন্ন logf(ভিন্ন x) { ঘূৰাই log(x); }
  __CRT_INLINE ভিন্ন logbf(ভিন্ন x) { ঘূৰাই logb(x); }
  __CRT_INLINE ভিন্ন log10f(ভিন্ন x) { ঘূৰাই log10(x); }
  __CRT_INLINE ভিন্ন modff(ভিন্ন x, ভিন্ন *y) { দ্ৱিগুণ di, df = modf(x, &di); *y = di; ঘূৰাই df; }
  __CRT_INLINE ভিন্ন powf(ভিন্ন x, ভিন্ন y) { ঘূৰাই pow(x, y); }
  __CRT_INLINE ভিন্ন sinf(ভিন্ন x) { ঘূৰাই sin(x); }
  __CRT_INLINE ভিন্ন sinhf(ভিন্ন x) { ঘূৰাই sinh(x); }
  __CRT_INLINE ভিন্ন sqrtf(ভিন্ন x) { ঘূৰাই sqrt(x); }
  __CRT_INLINE ভিন্ন tanf(ভিন্ন x) { ঘূৰাই tan(x); }
  __CRT_INLINE ভিন্ন tanhf(ভিন্ন x) { ঘূৰাই tanh(x); }
#endif
__CRT_INLINE ভিন্ন __cdecl asinhf(ভিন্ন x) { ঘূৰাই asinh(x); }
__CRT_INLINE ভিন্ন __cdecl acoshf(ভিন্ন x) { ঘূৰাই acosh(x); }
__CRT_INLINE ভিন্ন __cdecl atanhf(ভিন্ন x) { ঘূৰাই atanh(x); }

__CRT_INLINE long দ্ৱিগুণ __cdecl asinhl(long দ্ৱিগুণ x) { ঘূৰাই asinh(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl acoshl(long দ্ৱিগুণ x) { ঘূৰাই acosh(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl atanhl(long দ্ৱিগুণ x) { ঘূৰাই atanh(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl asinl(long দ্ৱিগুণ x) { ঘূৰাই asin(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl acosl(long দ্ৱিগুণ x) { ঘূৰাই acos(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl atanl(long দ্ৱিগুণ x) { ঘূৰাই atan(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl ceill(long দ্ৱিগুণ x) { ঘূৰাই ceil(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl coshl(long দ্ৱিগুণ x) { ঘূৰাই cosh(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl cosl(long দ্ৱিগুণ x) { ঘূৰাই cos(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl expl(long দ্ৱিগুণ x) { ঘূৰাই exp(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl floorl(long দ্ৱিগুণ x) { ঘূৰাই floor(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl fmodl(long দ্ৱিগুণ x, long দ্ৱিগুণ y) { ঘূৰাই fmod(x, y); }
__CRT_INLINE long দ্ৱিগুণ __cdecl hypotl(long দ্ৱিগুণ x, long দ্ৱিগুণ y) { ঘূৰাই hypot(x, y); }
__CRT_INLINE long দ্ৱিগুণ __cdecl logl(long দ্ৱিগুণ x) { ঘূৰাই log(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl logbl(long দ্ৱিগুণ x) { ঘূৰাই logb(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl log10l(long দ্ৱিগুণ x) { ঘূৰাই log10(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl modfl(long দ্ৱিগুণ x, long দ্ৱিগুণ* y) { দ্ৱিগুণ y1 = *y; x = modf(x, &y1); *y = y1; ঘূৰাই x; }
__CRT_INLINE long দ্ৱিগুণ __cdecl powl(long দ্ৱিগুণ x, long দ্ৱিগুণ y) { ঘূৰাই pow(x, y); }
__CRT_INLINE long দ্ৱিগুণ __cdecl sinhl(long দ্ৱিগুণ x) { ঘূৰাই sinh(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl sinl(long দ্ৱিগুণ x) { ঘূৰাই sin(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl sqrtl(long দ্ৱিগুণ x) { ঘূৰাই sqrt(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl tanhl(long দ্ৱিগুণ x) { ঘূৰাই tanh(x); }
__CRT_INLINE long দ্ৱিগুণ __cdecl tanl(long দ্ৱিগুণ x) { ঘূৰাই tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE দ্ৱিগুণ __cdecl log1p(দ্ৱিগুণ x) {
  দ্ৱিগুণ u = 1.0 + x;
  ঘূৰাই u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE ভিন্ন __cdecl log1pf(ভিন্ন x) {
  ভিন্ন u = 1.0f + x;
  ঘূৰাই u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long দ্ৱিগুণ __cdecl log1pl(long দ্ৱিগুণ x) {
  ঘূৰাই log1p(x);
}


__CRT_INLINE দ্ৱিগুণ __cdecl expm1(দ্ৱিগুণ x) {
  যদি (x > 0.0024 || x < -0.0024) ঘূৰাই exp(x) - 1.0;
  ঘূৰাই x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE ভিন্ন __cdecl expm1f(ভিন্ন x) {
  যদি (x > 0.085f || x < -0.085f) ঘূৰাই expf(x) - 1.0f;
  ঘূৰাই x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long দ্ৱিগুণ __cdecl expm1l(long দ্ৱিগুণ x) {
  ঘূৰাই expm1(x);
}


__CRT_INLINE দ্ৱিগুণ __cdecl cbrt(দ্ৱিগুণ x) {
  ঘূৰাই x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE ভিন্ন __cdecl cbrtf(ভিন্ন x) {
  ঘূৰাই x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl cbrtl(long দ্ৱিগুণ x) {
  ঘূৰাই cbrt(x);
}


__CRT_INLINE দ্ৱিগুণ __cdecl log2(দ্ৱিগুণ x) {
  ঘূৰাই log(x) * 1.442695040888963407;
}
__CRT_INLINE ভিন্ন __cdecl log2f(ভিন্ন x) {
  ঘূৰাই log(x) * 1.442695040888963407;
}
__CRT_INLINE long দ্ৱিগুণ __cdecl log2l(long দ্ৱিগুণ x) {
  ঘূৰাই log(x) * 1.442695040888963407;
}


__CRT_INLINE দ্ৱিগুণ __cdecl exp2(দ্ৱিগুণ x) {
  ঘূৰাই exp(x * 0.693147180559945309);
}
__CRT_INLINE ভিন্ন __cdecl exp2f(ভিন্ন x) {
  ঘূৰাই exp(x * 0.693147180559945309);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl exp2l(long দ্ৱিগুণ x) {
  ঘূৰাই exp(x * 0.693147180559945309);
}


__CRT_INLINE পূর্ণাঙ্ক __cdecl ilogb(দ্ৱিগুণ x) {
  ঘূৰাই (পূর্ণাঙ্ক) logb(x);
}
__CRT_INLINE পূর্ণাঙ্ক __cdecl ilogbf(ভিন্ন x) {
  ঘূৰাই (পূর্ণাঙ্ক) logbf(x);
}
__CRT_INLINE পূর্ণাঙ্ক __cdecl ilogbl(long দ্ৱিগুণ x) {
  ঘূৰাই (পূর্ণাঙ্ক) logb(x);
}


__CRT_INLINE দ্ৱিগুণ __cdecl fdim(দ্ৱিগুণ x, দ্ৱিগুণ y) {
  যদি (isnan(x) || isnan(y)) ঘূৰাই NAN;
  ঘূৰাই x > y ? x - y : 0;
}
__CRT_INLINE ভিন্ন __cdecl fdimf(ভিন্ন x, ভিন্ন y) {
  যদি (isnan(x) || isnan(y)) ঘূৰাই NAN;
  ঘূৰাই x > y ? x - y : 0;
}
__CRT_INLINE long দ্ৱিগুণ __cdecl fdiml(long দ্ৱিগুণ x, long দ্ৱিগুণ y) {
  যদি (isnan(x) || isnan(y)) ঘূৰাই NAN;
  ঘূৰাই x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE দ্ৱিগুণ __cdecl tgamma(দ্ৱিগুণ x) {
  দ্ৱিগুণ m = 1.0, t = 3.14159265358979323;
  যদি (x == floor(x)) {
    যদি (x == 0) ঘূৰাই INFINITY;
    যদি (x < 0) ঘূৰাই NAN;
    যদি (x < 26) { বাবে (দ্ৱিগুণ k = 2; k < x; ++k) m *= k; ঘূৰাই m; }
  }
  যদি (x < 0.5)
    ঘূৰাই t / (sin(t*x)*tgamma(1.0 - x));
  যদি (x > 12.0)
    ঘূৰাই exp(lgamma(x));

  স্থির ধ্রুৱ দ্ৱিগুণ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  বাবে (পূর্ণাঙ্ক k = 0; k < 8; ++k) m += c[k] / (x + k);
  ঘূৰাই 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE দ্ৱিগুণ __cdecl lgamma(দ্ৱিগুণ x) {
  যদি (x < 12.0) {
    যদি (x <= 0.0 && x == floor(x)) ঘূৰাই INFINITY;
    x = tgamma(x);
    ঘূৰাই log(x < 0.0 ? -x : x);
  }
  স্থির ধ্রুৱ দ্ৱিগুণ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  দ্ৱিগুণ m = -3617.0/122400.0, t = 1.0 / (x*x);
  বাবে (পূর্ণাঙ্ক k = 6; k >= 0; --k) m = m*t + c[k];
  ঘূৰাই (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE ভিন্ন __cdecl tgammaf(ভিন্ন x) {
  ঘূৰাই tgamma(x);
}
__CRT_INLINE ভিন্ন __cdecl lgammaf(ভিন্ন x) {
  ঘূৰাই lgamma(x);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl tgammal(long দ্ৱিগুণ x) {
  ঘূৰাই tgamma(x);
}
__CRT_INLINE long দ্ৱিগুণ __cdecl lgammal(long দ্ৱিগুণ x) {
  ঘূৰাই lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
