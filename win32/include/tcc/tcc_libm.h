#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#અન્તર્ભાવ "../math.h"
#અન્તર્ભાવ "../stdint.h"

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

__CRT_INLINE પૂર્ણાંક __cdecl __fpclassify (દ્વિગુણ x) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u = {.f = x};
  પૂર્ણાંક e = u.i>>52 & 0x7ff;
  જો (!e) પાછા u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  જો (e==0x7ff) પાછા u.i<<12 ? FP_NAN : FP_INFINITE;
  પાછા FP_NORMAL;
}

__CRT_INLINE પૂર્ણાંક __cdecl __fpclassifyf (દશાંશ x) {
  સંઘ {દશાંશ f; uint32_t i;} u = {.f = x};
  પૂર્ણાંક e = u.i>>23 & 0xff;
  જો (!e) પાછા u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  જો (e==0xff) પાછા u.i<<9 ? FP_NAN : FP_INFINITE;
  પાછા FP_NORMAL;
}

__CRT_INLINE પૂર્ણાંક __cdecl __fpclassifyl (long દ્વિગુણ x) {
  પાછા __fpclassify(x);
}


/* signbit */

__CRT_INLINE પૂર્ણાંક __cdecl __signbit (દ્વિગુણ x) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u = {.f = x};
  પાછા u.i>>63;
}

__CRT_INLINE પૂર્ણાંક __cdecl __signbitf (દશાંશ x) {
  સંઘ {દશાંશ f; uint32_t i; } u = {.f = x};
  પાછા u.i>>31;
}

__CRT_INLINE પૂર્ણાંક __cdecl __signbitl (long દ્વિગુણ x) {
  પાછા __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE દ્વિગુણ __cdecl fmin (દ્વિગુણ x, દ્વિગુણ y) {
  પાછા TCCFP_FMIN_EVAL;
}

__CRT_INLINE દશાંશ __cdecl fminf (દશાંશ x, દશાંશ y) {
  પાછા TCCFP_FMIN_EVAL;
}

__CRT_INLINE long દ્વિગુણ __cdecl fminl (long દ્વિગુણ x, long દ્વિગુણ y) {
  પાછા TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE દ્વિગુણ __cdecl fmax (દ્વિગુણ x, દ્વિગુણ y) {
  પાછા TCCFP_FMAX_EVAL;
}

__CRT_INLINE દશાંશ __cdecl fmaxf (દશાંશ x, દશાંશ y) {
  પાછા TCCFP_FMAX_EVAL;
}

__CRT_INLINE long દ્વિગુણ __cdecl fmaxl (long દ્વિગુણ x, long દ્વિગુણ y) {
  પાછા TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) કરો {  \
  અસ્થિર typeof(x) __x;         \
  __x = (x);                      \
} જ્યારે(0)

__CRT_INLINE દ્વિગુણ __cdecl round (દ્વિગુણ x) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u = {.f = x};
  પૂર્ણાંક e = u.i >> 52 & 0x7ff;
  દ્વિગુણ y;

  જો (e >= 0x3ff+52)
    પાછા x;
  જો (u.i >> 63)
    x = -x;
  જો (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    પાછા 0*u.f;
  }
  y = (દ્વિગુણ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  પાછા (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (દ્વિગુણ x) {
  પાછા round(x);
}

__CRT_INLINE long long __cdecl llround (દ્વિગુણ x) {
  પાછા round(x);
}

__CRT_INLINE દશાંશ __cdecl roundf (દશાંશ x) {
  પાછા round(x);
}

__CRT_INLINE long __cdecl lroundf (દશાંશ x) {
  પાછા round(x);
}

__CRT_INLINE long long __cdecl llroundf (દશાંશ x) {
  પાછા round(x);
}

__CRT_INLINE long દ્વિગુણ __cdecl roundl (long દ્વિગુણ x) {
  પાછા round(x);
}

__CRT_INLINE long __cdecl lroundl (long દ્વિગુણ x) {
  પાછા round(x);
}

__CRT_INLINE long long __cdecl llroundl (long દ્વિગુણ x) {
  પાછા round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE દ્વિગુણ __cdecl asinh(દ્વિગુણ x) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  જો (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  નહીંતર જો (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  નહીંતર જો (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  નહીંતર TCCFP_FORCE_EVAL(x + 0x1p120f);
  પાછા s ? -x : x;
}

__CRT_INLINE દ્વિગુણ __cdecl acosh(દ્વિગુણ x) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  જો (e < 0x3ff + 1) પાછા --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  જો (e < 0x3ff + 26) પાછા log(2*x - 1 / (x + sqrt(x*x - 1)));
  પાછા log(x) + 0.693147180559945309;
}

__CRT_INLINE દ્વિગુણ __cdecl atanh(દ્વિગુણ x) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  જો (e < 0x3ff - 1) {
    જો (e < 0x3ff - 32) { જો (e == 0) TCCFP_FORCE_EVAL((દશાંશ)x); }
    નહીંતર x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } નહીંતર x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  પાછા s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE દ્વિગુણ __cdecl scalbn(દ્વિગુણ x, પૂર્ણાંક n) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u;
  જો (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    જો (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      જો (n > 1023) n = 1023;
    }
  } નહીંતર જો (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    જો (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      જો (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  પાછા x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE દ્વિગુણ __cdecl frexp(દ્વિગુણ x, પૂર્ણાંક *e) {
  સંઘ {દ્વિગુણ f; uint64_t i;} u = {.f = x};
  પૂર્ણાંક ee = u.i>>52 & 0x7ff;
  જો (!ee) {
    જો (x) x = frexp(x*0x1p64, e), *e -= 64;
    નહીંતર *e = 0;
    પાછા x;
  } નહીંતર જો (ee == 0x7ff)
    પાછા x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  પાછા u.f;
}

/* MUSL nan */

__CRT_INLINE દ્વિગુણ __cdecl nan(અચલ અક્ષર* s) {
  પાછા NAN;
}
__CRT_INLINE દશાંશ __cdecl nanf(અચલ અક્ષર* s) {
  પાછા NAN;
}
__CRT_INLINE long દ્વિગુણ __cdecl nanl(અચલ અક્ષર* s) {
  પાછા NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE દશાંશ __cdecl scalbnf(દશાંશ x, પૂર્ણાંક n) {
  પાછા scalbn(x, n);
}
__CRT_INLINE long દ્વિગુણ __cdecl scalbnl(long દ્વિગુણ x, પૂર્ણાંક n) {
  પાછા scalbn(x, n);
}

__CRT_INLINE દ્વિગુણ __cdecl scalbln(દ્વિગુણ x, long n) {
  પાછા scalbn(x, n);
}
__CRT_INLINE દશાંશ __cdecl scalblnf(દશાંશ x, long n) {
  પાછા scalbn(x, n);
}
__CRT_INLINE long દ્વિગુણ __cdecl scalblnl(long દ્વિગુણ x, long n) {
  પાછા scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE દ્વિગુણ __cdecl ldexp(દ્વિગુણ x, પૂર્ણાંક expn) {
  પાછા scalbn(x, expn);
}
__CRT_INLINE દશાંશ __cdecl ldexpf(દશાંશ x, પૂર્ણાંક expn) {
  પાછા scalbn(x, expn);
}
__CRT_INLINE long દ્વિગુણ __cdecl ldexpl(long દ્વિગુણ x, પૂર્ણાંક expn) {
  પાછા scalbn(x, expn);
}

__CRT_INLINE દશાંશ __cdecl frexpf(દશાંશ x, પૂર્ણાંક *y) {
  પાછા frexp(x, y);
}
__CRT_INLINE long દ્વિગુણ __cdecl frexpl (long દ્વિગુણ x, પૂર્ણાંક* y) {
  પાછા frexp(x, y);
}


__CRT_INLINE દ્વિગુણ __cdecl rint(દ્વિગુણ x) {
દ્વિગુણ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  પાછા retval;
}

__CRT_INLINE દશાંશ __cdecl rintf(દશાંશ x) {
  દશાંશ retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   પાછા retval;
}
__CRT_INLINE long દ્વિગુણ __cdecl rintl (long દ્વિગુણ x) {
  પાછા rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(દ્વિગુણ x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  પાછા retval;
}

__CRT_INLINE long __cdecl lrintf(દશાંશ x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  પાછા retval;
}

__CRT_INLINE long __cdecl lrintl (long દ્વિગુણ x) {
  પાછા lrint(x);
}


__CRT_INLINE long long __cdecl llrint(દ્વિગુણ x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  પાછા retval;
}

__CRT_INLINE long long __cdecl llrintf(દશાંશ x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  પાછા retval;
}

__CRT_INLINE long long __cdecl llrintl (long દ્વિગુણ x) {
  પાછા llrint(x);
}


__CRT_INLINE દ્વિગુણ __cdecl trunc(દ્વિગુણ _x) {
  દ્વિગુણ retval;
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
  પાછા retval;
}

__CRT_INLINE દશાંશ __cdecl truncf(દશાંશ x) {
  પાછા (દશાંશ) ((intptr_t) x);
}
__CRT_INLINE long દ્વિગુણ __cdecl truncl(long દ્વિગુણ x) {
  પાછા trunc(x);
}


__CRT_INLINE long દ્વિગુણ __cdecl nextafterl(long દ્વિગુણ x, long દ્વિગુણ to) {
  પાછા nextafter(x, to);
}

__CRT_INLINE દ્વિગુણ __cdecl nexttoward(દ્વિગુણ x, long દ્વિગુણ to) {
  પાછા nextafter(x, to);
}
__CRT_INLINE દશાંશ __cdecl nexttowardf(દશાંશ x, long દ્વિગુણ to) {
  પાછા nextafterf(x, to);
}
__CRT_INLINE long દ્વિગુણ __cdecl nexttowardl(long દ્વિગુણ x, long દ્વિગુણ to) {
  પાછા nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE દ્વિગુણ __cdecl fabs(દ્વિગુણ x) {
  પાછા x < 0 ? -x : x;
}
__CRT_INLINE દશાંશ __cdecl fabsf(દશાંશ x) {
  પાછા x < 0 ? -x : x;
}
__CRT_INLINE long દ્વિગુણ __cdecl fabsl(long દ્વિગુણ x) {
  પાછા x < 0 ? -x : x;
}


#જો defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE દશાંશ acosf(દશાંશ x) { પાછા acos(x); }
  __CRT_INLINE દશાંશ asinf(દશાંશ x) { પાછા asin(x); }
  __CRT_INLINE દશાંશ atanf(દશાંશ x) { પાછા atan(x); }
  __CRT_INLINE દશાંશ atan2f(દશાંશ x, દશાંશ y) { પાછા atan2(x, y); }
  __CRT_INLINE દશાંશ ceilf(દશાંશ x) { પાછા ceil(x); }
  __CRT_INLINE દશાંશ cosf(દશાંશ x) { પાછા cos(x); }
  __CRT_INLINE દશાંશ coshf(દશાંશ x) { પાછા cosh(x); }
  __CRT_INLINE દશાંશ expf(દશાંશ x) { પાછા exp(x); }
  __CRT_INLINE દશાંશ floorf(દશાંશ x) { પાછા floor(x); }
  __CRT_INLINE દશાંશ fmodf(દશાંશ x, દશાંશ y) { પાછા fmod(x, y); }
  __CRT_INLINE દશાંશ logf(દશાંશ x) { પાછા log(x); }
  __CRT_INLINE દશાંશ logbf(દશાંશ x) { પાછા logb(x); }
  __CRT_INLINE દશાંશ log10f(દશાંશ x) { પાછા log10(x); }
  __CRT_INLINE દશાંશ modff(દશાંશ x, દશાંશ *y) { દ્વિગુણ di, df = modf(x, &di); *y = di; પાછા df; }
  __CRT_INLINE દશાંશ powf(દશાંશ x, દશાંશ y) { પાછા pow(x, y); }
  __CRT_INLINE દશાંશ sinf(દશાંશ x) { પાછા sin(x); }
  __CRT_INLINE દશાંશ sinhf(દશાંશ x) { પાછા sinh(x); }
  __CRT_INLINE દશાંશ sqrtf(દશાંશ x) { પાછા sqrt(x); }
  __CRT_INLINE દશાંશ tanf(દશાંશ x) { પાછા tan(x); }
  __CRT_INLINE દશાંશ tanhf(દશાંશ x) { પાછા tanh(x); }
#endif
__CRT_INLINE દશાંશ __cdecl asinhf(દશાંશ x) { પાછા asinh(x); }
__CRT_INLINE દશાંશ __cdecl acoshf(દશાંશ x) { પાછા acosh(x); }
__CRT_INLINE દશાંશ __cdecl atanhf(દશાંશ x) { પાછા atanh(x); }

__CRT_INLINE long દ્વિગુણ __cdecl asinhl(long દ્વિગુણ x) { પાછા asinh(x); }
__CRT_INLINE long દ્વિગુણ __cdecl acoshl(long દ્વિગુણ x) { પાછા acosh(x); }
__CRT_INLINE long દ્વિગુણ __cdecl atanhl(long દ્વિગુણ x) { પાછા atanh(x); }
__CRT_INLINE long દ્વિગુણ __cdecl asinl(long દ્વિગુણ x) { પાછા asin(x); }
__CRT_INLINE long દ્વિગુણ __cdecl acosl(long દ્વિગુણ x) { પાછા acos(x); }
__CRT_INLINE long દ્વિગુણ __cdecl atanl(long દ્વિગુણ x) { પાછા atan(x); }
__CRT_INLINE long દ્વિગુણ __cdecl ceill(long દ્વિગુણ x) { પાછા ceil(x); }
__CRT_INLINE long દ્વિગુણ __cdecl coshl(long દ્વિગુણ x) { પાછા cosh(x); }
__CRT_INLINE long દ્વિગુણ __cdecl cosl(long દ્વિગુણ x) { પાછા cos(x); }
__CRT_INLINE long દ્વિગુણ __cdecl expl(long દ્વિગુણ x) { પાછા exp(x); }
__CRT_INLINE long દ્વિગુણ __cdecl floorl(long દ્વિગુણ x) { પાછા floor(x); }
__CRT_INLINE long દ્વિગુણ __cdecl fmodl(long દ્વિગુણ x, long દ્વિગુણ y) { પાછા fmod(x, y); }
__CRT_INLINE long દ્વિગુણ __cdecl hypotl(long દ્વિગુણ x, long દ્વિગુણ y) { પાછા hypot(x, y); }
__CRT_INLINE long દ્વિગુણ __cdecl logl(long દ્વિગુણ x) { પાછા log(x); }
__CRT_INLINE long દ્વિગુણ __cdecl logbl(long દ્વિગુણ x) { પાછા logb(x); }
__CRT_INLINE long દ્વિગુણ __cdecl log10l(long દ્વિગુણ x) { પાછા log10(x); }
__CRT_INLINE long દ્વિગુણ __cdecl modfl(long દ્વિગુણ x, long દ્વિગુણ* y) { દ્વિગુણ y1 = *y; x = modf(x, &y1); *y = y1; પાછા x; }
__CRT_INLINE long દ્વિગુણ __cdecl powl(long દ્વિગુણ x, long દ્વિગુણ y) { પાછા pow(x, y); }
__CRT_INLINE long દ્વિગુણ __cdecl sinhl(long દ્વિગુણ x) { પાછા sinh(x); }
__CRT_INLINE long દ્વિગુણ __cdecl sinl(long દ્વિગુણ x) { પાછા sin(x); }
__CRT_INLINE long દ્વિગુણ __cdecl sqrtl(long દ્વિગુણ x) { પાછા sqrt(x); }
__CRT_INLINE long દ્વિગુણ __cdecl tanhl(long દ્વિગુણ x) { પાછા tanh(x); }
__CRT_INLINE long દ્વિગુણ __cdecl tanl(long દ્વિગુણ x) { પાછા tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE દ્વિગુણ __cdecl log1p(દ્વિગુણ x) {
  દ્વિગુણ u = 1.0 + x;
  પાછા u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE દશાંશ __cdecl log1pf(દશાંશ x) {
  દશાંશ u = 1.0f + x;
  પાછા u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long દ્વિગુણ __cdecl log1pl(long દ્વિગુણ x) {
  પાછા log1p(x);
}


__CRT_INLINE દ્વિગુણ __cdecl expm1(દ્વિગુણ x) {
  જો (x > 0.0024 || x < -0.0024) પાછા exp(x) - 1.0;
  પાછા x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE દશાંશ __cdecl expm1f(દશાંશ x) {
  જો (x > 0.085f || x < -0.085f) પાછા expf(x) - 1.0f;
  પાછા x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long દ્વિગુણ __cdecl expm1l(long દ્વિગુણ x) {
  પાછા expm1(x);
}


__CRT_INLINE દ્વિગુણ __cdecl cbrt(દ્વિગુણ x) {
  પાછા x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE દશાંશ __cdecl cbrtf(દશાંશ x) {
  પાછા x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long દ્વિગુણ __cdecl cbrtl(long દ્વિગુણ x) {
  પાછા cbrt(x);
}


__CRT_INLINE દ્વિગુણ __cdecl log2(દ્વિગુણ x) {
  પાછા log(x) * 1.442695040888963407;
}
__CRT_INLINE દશાંશ __cdecl log2f(દશાંશ x) {
  પાછા log(x) * 1.442695040888963407;
}
__CRT_INLINE long દ્વિગુણ __cdecl log2l(long દ્વિગુણ x) {
  પાછા log(x) * 1.442695040888963407;
}


__CRT_INLINE દ્વિગુણ __cdecl exp2(દ્વિગુણ x) {
  પાછા exp(x * 0.693147180559945309);
}
__CRT_INLINE દશાંશ __cdecl exp2f(દશાંશ x) {
  પાછા exp(x * 0.693147180559945309);
}
__CRT_INLINE long દ્વિગુણ __cdecl exp2l(long દ્વિગુણ x) {
  પાછા exp(x * 0.693147180559945309);
}


__CRT_INLINE પૂર્ણાંક __cdecl ilogb(દ્વિગુણ x) {
  પાછા (પૂર્ણાંક) logb(x);
}
__CRT_INLINE પૂર્ણાંક __cdecl ilogbf(દશાંશ x) {
  પાછા (પૂર્ણાંક) logbf(x);
}
__CRT_INLINE પૂર્ણાંક __cdecl ilogbl(long દ્વિગુણ x) {
  પાછા (પૂર્ણાંક) logb(x);
}


__CRT_INLINE દ્વિગુણ __cdecl fdim(દ્વિગુણ x, દ્વિગુણ y) {
  જો (isnan(x) || isnan(y)) પાછા NAN;
  પાછા x > y ? x - y : 0;
}
__CRT_INLINE દશાંશ __cdecl fdimf(દશાંશ x, દશાંશ y) {
  જો (isnan(x) || isnan(y)) પાછા NAN;
  પાછા x > y ? x - y : 0;
}
__CRT_INLINE long દ્વિગુણ __cdecl fdiml(long દ્વિગુણ x, long દ્વિગુણ y) {
  જો (isnan(x) || isnan(y)) પાછા NAN;
  પાછા x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE દ્વિગુણ __cdecl tgamma(દ્વિગુણ x) {
  દ્વિગુણ m = 1.0, t = 3.14159265358979323;
  જો (x == floor(x)) {
    જો (x == 0) પાછા INFINITY;
    જો (x < 0) પાછા NAN;
    જો (x < 26) { માટે (દ્વિગુણ k = 2; k < x; ++k) m *= k; પાછા m; }
  }
  જો (x < 0.5)
    પાછા t / (sin(t*x)*tgamma(1.0 - x));
  જો (x > 12.0)
    પાછા exp(lgamma(x));

  સ્થિર અચલ દ્વિગુણ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  માટે (પૂર્ણાંક k = 0; k < 8; ++k) m += c[k] / (x + k);
  પાછા 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE દ્વિગુણ __cdecl lgamma(દ્વિગુણ x) {
  જો (x < 12.0) {
    જો (x <= 0.0 && x == floor(x)) પાછા INFINITY;
    x = tgamma(x);
    પાછા log(x < 0.0 ? -x : x);
  }
  સ્થિર અચલ દ્વિગુણ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  દ્વિગુણ m = -3617.0/122400.0, t = 1.0 / (x*x);
  માટે (પૂર્ણાંક k = 6; k >= 0; --k) m = m*t + c[k];
  પાછા (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE દશાંશ __cdecl tgammaf(દશાંશ x) {
  પાછા tgamma(x);
}
__CRT_INLINE દશાંશ __cdecl lgammaf(દશાંશ x) {
  પાછા lgamma(x);
}
__CRT_INLINE long દ્વિગુણ __cdecl tgammal(long દ્વિગુણ x) {
  પાછા tgamma(x);
}
__CRT_INLINE long દ્વિગુણ __cdecl lgammal(long દ્વિગુણ x) {
  પાછા lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
