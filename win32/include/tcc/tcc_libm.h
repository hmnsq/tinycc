#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#ଅନ୍ତର୍ଭାଵ "../math.h"
#ଅନ୍ତର୍ଭାଵ "../stdint.h"

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

__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __fpclassify (ଦ୍ୱିଗୁଣ x) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u = {.f = x};
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = u.i>>52 & 0x7ff;
  ଯଦି (!e) ଫେରନ୍ତୁ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ଯଦି (e==0x7ff) ଫେରନ୍ତୁ u.i<<12 ? FP_NAN : FP_INFINITE;
  ଫେରନ୍ତୁ FP_NORMAL;
}

__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __fpclassifyf (ଦଶମିକ x) {
  ସଂଘ {ଦଶମିକ f; uint32_t i;} u = {.f = x};
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = u.i>>23 & 0xff;
  ଯଦି (!e) ଫେରନ୍ତୁ u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ଯଦି (e==0xff) ଫେରନ୍ତୁ u.i<<9 ? FP_NAN : FP_INFINITE;
  ଫେରନ୍ତୁ FP_NORMAL;
}

__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __fpclassifyl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ __fpclassify(x);
}


/* signbit */

__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __signbit (ଦ୍ୱିଗୁଣ x) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u = {.f = x};
  ଫେରନ୍ତୁ u.i>>63;
}

__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __signbitf (ଦଶମିକ x) {
  ସଂଘ {ଦଶମିକ f; uint32_t i; } u = {.f = x};
  ଫେରନ୍ତୁ u.i>>31;
}

__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __signbitl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl fmin (ଦ୍ୱିଗୁଣ x, ଦ୍ୱିଗୁଣ y) {
  ଫେରନ୍ତୁ TCCFP_FMIN_EVAL;
}

__CRT_INLINE ଦଶମିକ __cdecl fminf (ଦଶମିକ x, ଦଶମିକ y) {
  ଫେରନ୍ତୁ TCCFP_FMIN_EVAL;
}

__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl fminl (long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ y) {
  ଫେରନ୍ତୁ TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl fmax (ଦ୍ୱିଗୁଣ x, ଦ୍ୱିଗୁଣ y) {
  ଫେରନ୍ତୁ TCCFP_FMAX_EVAL;
}

__CRT_INLINE ଦଶମିକ __cdecl fmaxf (ଦଶମିକ x, ଦଶମିକ y) {
  ଫେରନ୍ତୁ TCCFP_FMAX_EVAL;
}

__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl fmaxl (long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ y) {
  ଫେରନ୍ତୁ TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) କର {  \
  ଅସ୍ଥିର typeof(x) __x;         \
  __x = (x);                      \
} ଯେତେବେଳେ(0)

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl round (ଦ୍ୱିଗୁଣ x) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u = {.f = x};
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = u.i >> 52 & 0x7ff;
  ଦ୍ୱିଗୁଣ y;

  ଯଦି (e >= 0x3ff+52)
    ଫେରନ୍ତୁ x;
  ଯଦି (u.i >> 63)
    x = -x;
  ଯଦି (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    ଫେରନ୍ତୁ 0*u.f;
  }
  y = (ଦ୍ୱିଗୁଣ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  ଫେରନ୍ତୁ (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ round(x);
}

__CRT_INLINE long long __cdecl llround (ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ round(x);
}

__CRT_INLINE ଦଶମିକ __cdecl roundf (ଦଶମିକ x) {
  ଫେରନ୍ତୁ round(x);
}

__CRT_INLINE long __cdecl lroundf (ଦଶମିକ x) {
  ଫେରନ୍ତୁ round(x);
}

__CRT_INLINE long long __cdecl llroundf (ଦଶମିକ x) {
  ଫେରନ୍ତୁ round(x);
}

__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl roundl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ round(x);
}

__CRT_INLINE long __cdecl lroundl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ round(x);
}

__CRT_INLINE long long __cdecl llroundl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl asinh(ଦ୍ୱିଗୁଣ x) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ଯଦି (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  ଅନ୍ୟଥା ଯଦି (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  ଅନ୍ୟଥା ଯଦି (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  ଅନ୍ୟଥା TCCFP_FORCE_EVAL(x + 0x1p120f);
  ଫେରନ୍ତୁ s ? -x : x;
}

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl acosh(ଦ୍ୱିଗୁଣ x) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  ଯଦି (e < 0x3ff + 1) ଫେରନ୍ତୁ --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  ଯଦି (e < 0x3ff + 26) ଫେରନ୍ତୁ log(2*x - 1 / (x + sqrt(x*x - 1)));
  ଫେରନ୍ତୁ log(x) + 0.693147180559945309;
}

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl atanh(ଦ୍ୱିଗୁଣ x) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ଯଦି (e < 0x3ff - 1) {
    ଯଦି (e < 0x3ff - 32) { ଯଦି (e == 0) TCCFP_FORCE_EVAL((ଦଶମିକ)x); }
    ଅନ୍ୟଥା x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } ଅନ୍ୟଥା x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  ଫେରନ୍ତୁ s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl scalbn(ଦ୍ୱିଗୁଣ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u;
  ଯଦି (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    ଯଦି (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      ଯଦି (n > 1023) n = 1023;
    }
  } ଅନ୍ୟଥା ଯଦି (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    ଯଦି (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      ଯଦି (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  ଫେରନ୍ତୁ x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl frexp(ଦ୍ୱିଗୁଣ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *e) {
  ସଂଘ {ଦ୍ୱିଗୁଣ f; uint64_t i;} u = {.f = x};
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ee = u.i>>52 & 0x7ff;
  ଯଦି (!ee) {
    ଯଦି (x) x = frexp(x*0x1p64, e), *e -= 64;
    ଅନ୍ୟଥା *e = 0;
    ଫେରନ୍ତୁ x;
  } ଅନ୍ୟଥା ଯଦି (ee == 0x7ff)
    ଫେରନ୍ତୁ x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  ଫେରନ୍ତୁ u.f;
}

/* MUSL nan */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl nan(ଅଚଳ ଅକ୍ଷର* s) {
  ଫେରନ୍ତୁ NAN;
}
__CRT_INLINE ଦଶମିକ __cdecl nanf(ଅଚଳ ଅକ୍ଷର* s) {
  ଫେରନ୍ତୁ NAN;
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl nanl(ଅଚଳ ଅକ୍ଷର* s) {
  ଫେରନ୍ତୁ NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE ଦଶମିକ __cdecl scalbnf(ଦଶମିକ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n) {
  ଫେରନ୍ତୁ scalbn(x, n);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl scalbnl(long ଦ୍ୱିଗୁଣ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n) {
  ଫେରନ୍ତୁ scalbn(x, n);
}

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl scalbln(ଦ୍ୱିଗୁଣ x, long n) {
  ଫେରନ୍ତୁ scalbn(x, n);
}
__CRT_INLINE ଦଶମିକ __cdecl scalblnf(ଦଶମିକ x, long n) {
  ଫେରନ୍ତୁ scalbn(x, n);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl scalblnl(long ଦ୍ୱିଗୁଣ x, long n) {
  ଫେରନ୍ତୁ scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl ldexp(ଦ୍ୱିଗୁଣ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା expn) {
  ଫେରନ୍ତୁ scalbn(x, expn);
}
__CRT_INLINE ଦଶମିକ __cdecl ldexpf(ଦଶମିକ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା expn) {
  ଫେରନ୍ତୁ scalbn(x, expn);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl ldexpl(long ଦ୍ୱିଗୁଣ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା expn) {
  ଫେରନ୍ତୁ scalbn(x, expn);
}

__CRT_INLINE ଦଶମିକ __cdecl frexpf(ଦଶମିକ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *y) {
  ଫେରନ୍ତୁ frexp(x, y);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl frexpl (long ଦ୍ୱିଗୁଣ x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା* y) {
  ଫେରନ୍ତୁ frexp(x, y);
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl rint(ଦ୍ୱିଗୁଣ x) {
ଦ୍ୱିଗୁଣ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  ଫେରନ୍ତୁ retval;
}

__CRT_INLINE ଦଶମିକ __cdecl rintf(ଦଶମିକ x) {
  ଦଶମିକ retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   ଫେରନ୍ତୁ retval;
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl rintl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(ଦ୍ୱିଗୁଣ x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ଫେରନ୍ତୁ retval;
}

__CRT_INLINE long __cdecl lrintf(ଦଶମିକ x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  ଫେରନ୍ତୁ retval;
}

__CRT_INLINE long __cdecl lrintl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ lrint(x);
}


__CRT_INLINE long long __cdecl llrint(ଦ୍ୱିଗୁଣ x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ଫେରନ୍ତୁ retval;
}

__CRT_INLINE long long __cdecl llrintf(ଦଶମିକ x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  ଫେରନ୍ତୁ retval;
}

__CRT_INLINE long long __cdecl llrintl (long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ llrint(x);
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl trunc(ଦ୍ୱିଗୁଣ _x) {
  ଦ୍ୱିଗୁଣ retval;
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
  ଫେରନ୍ତୁ retval;
}

__CRT_INLINE ଦଶମିକ __cdecl truncf(ଦଶମିକ x) {
  ଫେରନ୍ତୁ (ଦଶମିକ) ((intptr_t) x);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl truncl(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ trunc(x);
}


__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl nextafterl(long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ to) {
  ଫେରନ୍ତୁ nextafter(x, to);
}

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl nexttoward(ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ to) {
  ଫେରନ୍ତୁ nextafter(x, to);
}
__CRT_INLINE ଦଶମିକ __cdecl nexttowardf(ଦଶମିକ x, long ଦ୍ୱିଗୁଣ to) {
  ଫେରନ୍ତୁ nextafterf(x, to);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl nexttowardl(long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ to) {
  ଫେରନ୍ତୁ nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl fabs(ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ x < 0 ? -x : x;
}
__CRT_INLINE ଦଶମିକ __cdecl fabsf(ଦଶମିକ x) {
  ଫେରନ୍ତୁ x < 0 ? -x : x;
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl fabsl(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ x < 0 ? -x : x;
}


#ଯଦି defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE ଦଶମିକ acosf(ଦଶମିକ x) { ଫେରନ୍ତୁ acos(x); }
  __CRT_INLINE ଦଶମିକ asinf(ଦଶମିକ x) { ଫେରନ୍ତୁ asin(x); }
  __CRT_INLINE ଦଶମିକ atanf(ଦଶମିକ x) { ଫେରନ୍ତୁ atan(x); }
  __CRT_INLINE ଦଶମିକ atan2f(ଦଶମିକ x, ଦଶମିକ y) { ଫେରନ୍ତୁ atan2(x, y); }
  __CRT_INLINE ଦଶମିକ ceilf(ଦଶମିକ x) { ଫେରନ୍ତୁ ceil(x); }
  __CRT_INLINE ଦଶମିକ cosf(ଦଶମିକ x) { ଫେରନ୍ତୁ cos(x); }
  __CRT_INLINE ଦଶମିକ coshf(ଦଶମିକ x) { ଫେରନ୍ତୁ cosh(x); }
  __CRT_INLINE ଦଶମିକ expf(ଦଶମିକ x) { ଫେରନ୍ତୁ exp(x); }
  __CRT_INLINE ଦଶମିକ floorf(ଦଶମିକ x) { ଫେରନ୍ତୁ floor(x); }
  __CRT_INLINE ଦଶମିକ fmodf(ଦଶମିକ x, ଦଶମିକ y) { ଫେରନ୍ତୁ fmod(x, y); }
  __CRT_INLINE ଦଶମିକ logf(ଦଶମିକ x) { ଫେରନ୍ତୁ log(x); }
  __CRT_INLINE ଦଶମିକ logbf(ଦଶମିକ x) { ଫେରନ୍ତୁ logb(x); }
  __CRT_INLINE ଦଶମିକ log10f(ଦଶମିକ x) { ଫେରନ୍ତୁ log10(x); }
  __CRT_INLINE ଦଶମିକ modff(ଦଶମିକ x, ଦଶମିକ *y) { ଦ୍ୱିଗୁଣ di, df = modf(x, &di); *y = di; ଫେରନ୍ତୁ df; }
  __CRT_INLINE ଦଶମିକ powf(ଦଶମିକ x, ଦଶମିକ y) { ଫେରନ୍ତୁ pow(x, y); }
  __CRT_INLINE ଦଶମିକ sinf(ଦଶମିକ x) { ଫେରନ୍ତୁ sin(x); }
  __CRT_INLINE ଦଶମିକ sinhf(ଦଶମିକ x) { ଫେରନ୍ତୁ sinh(x); }
  __CRT_INLINE ଦଶମିକ sqrtf(ଦଶମିକ x) { ଫେରନ୍ତୁ sqrt(x); }
  __CRT_INLINE ଦଶମିକ tanf(ଦଶମିକ x) { ଫେରନ୍ତୁ tan(x); }
  __CRT_INLINE ଦଶମିକ tanhf(ଦଶମିକ x) { ଫେରନ୍ତୁ tanh(x); }
#endif
__CRT_INLINE ଦଶମିକ __cdecl asinhf(ଦଶମିକ x) { ଫେରନ୍ତୁ asinh(x); }
__CRT_INLINE ଦଶମିକ __cdecl acoshf(ଦଶମିକ x) { ଫେରନ୍ତୁ acosh(x); }
__CRT_INLINE ଦଶମିକ __cdecl atanhf(ଦଶମିକ x) { ଫେରନ୍ତୁ atanh(x); }

__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl asinhl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ asinh(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl acoshl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ acosh(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl atanhl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ atanh(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl asinl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ asin(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl acosl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ acos(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl atanl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ atan(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl ceill(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ ceil(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl coshl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ cosh(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl cosl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ cos(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl expl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ exp(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl floorl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ floor(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl fmodl(long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ y) { ଫେରନ୍ତୁ fmod(x, y); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl hypotl(long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ y) { ଫେରନ୍ତୁ hypot(x, y); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl logl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ log(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl logbl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ logb(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl log10l(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ log10(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl modfl(long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ* y) { ଦ୍ୱିଗୁଣ y1 = *y; x = modf(x, &y1); *y = y1; ଫେରନ୍ତୁ x; }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl powl(long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ y) { ଫେରନ୍ତୁ pow(x, y); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl sinhl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ sinh(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl sinl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ sin(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl sqrtl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ sqrt(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl tanhl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ tanh(x); }
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl tanl(long ଦ୍ୱିଗୁଣ x) { ଫେରନ୍ତୁ tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl log1p(ଦ୍ୱିଗୁଣ x) {
  ଦ୍ୱିଗୁଣ u = 1.0 + x;
  ଫେରନ୍ତୁ u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE ଦଶମିକ __cdecl log1pf(ଦଶମିକ x) {
  ଦଶମିକ u = 1.0f + x;
  ଫେରନ୍ତୁ u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl log1pl(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ log1p(x);
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl expm1(ଦ୍ୱିଗୁଣ x) {
  ଯଦି (x > 0.0024 || x < -0.0024) ଫେରନ୍ତୁ exp(x) - 1.0;
  ଫେରନ୍ତୁ x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE ଦଶମିକ __cdecl expm1f(ଦଶମିକ x) {
  ଯଦି (x > 0.085f || x < -0.085f) ଫେରନ୍ତୁ expf(x) - 1.0f;
  ଫେରନ୍ତୁ x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl expm1l(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ expm1(x);
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl cbrt(ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE ଦଶମିକ __cdecl cbrtf(ଦଶମିକ x) {
  ଫେରନ୍ତୁ x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl cbrtl(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ cbrt(x);
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl log2(ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ log(x) * 1.442695040888963407;
}
__CRT_INLINE ଦଶମିକ __cdecl log2f(ଦଶମିକ x) {
  ଫେରନ୍ତୁ log(x) * 1.442695040888963407;
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl log2l(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ log(x) * 1.442695040888963407;
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl exp2(ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ exp(x * 0.693147180559945309);
}
__CRT_INLINE ଦଶମିକ __cdecl exp2f(ଦଶମିକ x) {
  ଫେରନ୍ତୁ exp(x * 0.693147180559945309);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl exp2l(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ exp(x * 0.693147180559945309);
}


__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ilogb(ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) logb(x);
}
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ilogbf(ଦଶମିକ x) {
  ଫେରନ୍ତୁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) logbf(x);
}
__CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ilogbl(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) logb(x);
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl fdim(ଦ୍ୱିଗୁଣ x, ଦ୍ୱିଗୁଣ y) {
  ଯଦି (isnan(x) || isnan(y)) ଫେରନ୍ତୁ NAN;
  ଫେରନ୍ତୁ x > y ? x - y : 0;
}
__CRT_INLINE ଦଶମିକ __cdecl fdimf(ଦଶମିକ x, ଦଶମିକ y) {
  ଯଦି (isnan(x) || isnan(y)) ଫେରନ୍ତୁ NAN;
  ଫେରନ୍ତୁ x > y ? x - y : 0;
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl fdiml(long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ y) {
  ଯଦି (isnan(x) || isnan(y)) ଫେରନ୍ତୁ NAN;
  ଫେରନ୍ତୁ x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl tgamma(ଦ୍ୱିଗୁଣ x) {
  ଦ୍ୱିଗୁଣ m = 1.0, t = 3.14159265358979323;
  ଯଦି (x == floor(x)) {
    ଯଦି (x == 0) ଫେରନ୍ତୁ INFINITY;
    ଯଦି (x < 0) ଫେରନ୍ତୁ NAN;
    ଯଦି (x < 26) { ପାଇଁ (ଦ୍ୱିଗୁଣ k = 2; k < x; ++k) m *= k; ଫେରନ୍ତୁ m; }
  }
  ଯଦି (x < 0.5)
    ଫେରନ୍ତୁ t / (sin(t*x)*tgamma(1.0 - x));
  ଯଦି (x > 12.0)
    ଫେରନ୍ତୁ exp(lgamma(x));

  ସ୍ଥିର ଅଚଳ ଦ୍ୱିଗୁଣ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  ପାଇଁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା k = 0; k < 8; ++k) m += c[k] / (x + k);
  ଫେରନ୍ତୁ 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl lgamma(ଦ୍ୱିଗୁଣ x) {
  ଯଦି (x < 12.0) {
    ଯଦି (x <= 0.0 && x == floor(x)) ଫେରନ୍ତୁ INFINITY;
    x = tgamma(x);
    ଫେରନ୍ତୁ log(x < 0.0 ? -x : x);
  }
  ସ୍ଥିର ଅଚଳ ଦ୍ୱିଗୁଣ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  ଦ୍ୱିଗୁଣ m = -3617.0/122400.0, t = 1.0 / (x*x);
  ପାଇଁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା k = 6; k >= 0; --k) m = m*t + c[k];
  ଫେରନ୍ତୁ (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE ଦଶମିକ __cdecl tgammaf(ଦଶମିକ x) {
  ଫେରନ୍ତୁ tgamma(x);
}
__CRT_INLINE ଦଶମିକ __cdecl lgammaf(ଦଶମିକ x) {
  ଫେରନ୍ତୁ lgamma(x);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl tgammal(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ tgamma(x);
}
__CRT_INLINE long ଦ୍ୱିଗୁଣ __cdecl lgammal(long ଦ୍ୱିଗୁଣ x) {
  ଫେରନ୍ତୁ lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
