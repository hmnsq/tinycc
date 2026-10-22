#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#شامل "../math.h"
#شامل "../stdint.h"

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

__CRT_INLINE صحیح __cdecl __fpclassify (دوگانه x) {
  اجتماع {دوگانه f; uint64_t i;} u = {.f = x};
  صحیح e = u.i>>52 & 0x7ff;
  اگر (!e) بازگشت u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  اگر (e==0x7ff) بازگشت u.i<<12 ? FP_NAN : FP_INFINITE;
  بازگشت FP_NORMAL;
}

__CRT_INLINE صحیح __cdecl __fpclassifyf (اعشاری x) {
  اجتماع {اعشاری f; uint32_t i;} u = {.f = x};
  صحیح e = u.i>>23 & 0xff;
  اگر (!e) بازگشت u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  اگر (e==0xff) بازگشت u.i<<9 ? FP_NAN : FP_INFINITE;
  بازگشت FP_NORMAL;
}

__CRT_INLINE صحیح __cdecl __fpclassifyl (long دوگانه x) {
  بازگشت __fpclassify(x);
}


/* signbit */

__CRT_INLINE صحیح __cdecl __signbit (دوگانه x) {
  اجتماع {دوگانه f; uint64_t i;} u = {.f = x};
  بازگشت u.i>>63;
}

__CRT_INLINE صحیح __cdecl __signbitf (اعشاری x) {
  اجتماع {اعشاری f; uint32_t i; } u = {.f = x};
  بازگشت u.i>>31;
}

__CRT_INLINE صحیح __cdecl __signbitl (long دوگانه x) {
  بازگشت __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE دوگانه __cdecl fmin (دوگانه x, دوگانه y) {
  بازگشت TCCFP_FMIN_EVAL;
}

__CRT_INLINE اعشاری __cdecl fminf (اعشاری x, اعشاری y) {
  بازگشت TCCFP_FMIN_EVAL;
}

__CRT_INLINE long دوگانه __cdecl fminl (long دوگانه x, long دوگانه y) {
  بازگشت TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE دوگانه __cdecl fmax (دوگانه x, دوگانه y) {
  بازگشت TCCFP_FMAX_EVAL;
}

__CRT_INLINE اعشاری __cdecl fmaxf (اعشاری x, اعشاری y) {
  بازگشت TCCFP_FMAX_EVAL;
}

__CRT_INLINE long دوگانه __cdecl fmaxl (long دوگانه x, long دوگانه y) {
  بازگشت TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) انجامبده {  \
  فرار typeof(x) __x;         \
  __x = (x);                      \
} وقتی(0)

__CRT_INLINE دوگانه __cdecl round (دوگانه x) {
  اجتماع {دوگانه f; uint64_t i;} u = {.f = x};
  صحیح e = u.i >> 52 & 0x7ff;
  دوگانه y;

  اگر (e >= 0x3ff+52)
    بازگشت x;
  اگر (u.i >> 63)
    x = -x;
  اگر (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    بازگشت 0*u.f;
  }
  y = (دوگانه)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  بازگشت (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (دوگانه x) {
  بازگشت round(x);
}

__CRT_INLINE long long __cdecl llround (دوگانه x) {
  بازگشت round(x);
}

__CRT_INLINE اعشاری __cdecl roundf (اعشاری x) {
  بازگشت round(x);
}

__CRT_INLINE long __cdecl lroundf (اعشاری x) {
  بازگشت round(x);
}

__CRT_INLINE long long __cdecl llroundf (اعشاری x) {
  بازگشت round(x);
}

__CRT_INLINE long دوگانه __cdecl roundl (long دوگانه x) {
  بازگشت round(x);
}

__CRT_INLINE long __cdecl lroundl (long دوگانه x) {
  بازگشت round(x);
}

__CRT_INLINE long long __cdecl llroundl (long دوگانه x) {
  بازگشت round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE دوگانه __cdecl asinh(دوگانه x) {
  اجتماع {دوگانه f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  اگر (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  وگرنه اگر (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  وگرنه اگر (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  وگرنه TCCFP_FORCE_EVAL(x + 0x1p120f);
  بازگشت s ? -x : x;
}

__CRT_INLINE دوگانه __cdecl acosh(دوگانه x) {
  اجتماع {دوگانه f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  اگر (e < 0x3ff + 1) بازگشت --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  اگر (e < 0x3ff + 26) بازگشت log(2*x - 1 / (x + sqrt(x*x - 1)));
  بازگشت log(x) + 0.693147180559945309;
}

__CRT_INLINE دوگانه __cdecl atanh(دوگانه x) {
  اجتماع {دوگانه f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  اگر (e < 0x3ff - 1) {
    اگر (e < 0x3ff - 32) { اگر (e == 0) TCCFP_FORCE_EVAL((اعشاری)x); }
    وگرنه x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } وگرنه x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  بازگشت s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE دوگانه __cdecl scalbn(دوگانه x, صحیح n) {
  اجتماع {دوگانه f; uint64_t i;} u;
  اگر (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    اگر (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      اگر (n > 1023) n = 1023;
    }
  } وگرنه اگر (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    اگر (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      اگر (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  بازگشت x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE دوگانه __cdecl frexp(دوگانه x, صحیح *e) {
  اجتماع {دوگانه f; uint64_t i;} u = {.f = x};
  صحیح ee = u.i>>52 & 0x7ff;
  اگر (!ee) {
    اگر (x) x = frexp(x*0x1p64, e), *e -= 64;
    وگرنه *e = 0;
    بازگشت x;
  } وگرنه اگر (ee == 0x7ff)
    بازگشت x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  بازگشت u.f;
}

/* MUSL nan */

__CRT_INLINE دوگانه __cdecl nan(ثابت نویسه* s) {
  بازگشت NAN;
}
__CRT_INLINE اعشاری __cdecl nanf(ثابت نویسه* s) {
  بازگشت NAN;
}
__CRT_INLINE long دوگانه __cdecl nanl(ثابت نویسه* s) {
  بازگشت NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE اعشاری __cdecl scalbnf(اعشاری x, صحیح n) {
  بازگشت scalbn(x, n);
}
__CRT_INLINE long دوگانه __cdecl scalbnl(long دوگانه x, صحیح n) {
  بازگشت scalbn(x, n);
}

__CRT_INLINE دوگانه __cdecl scalbln(دوگانه x, long n) {
  بازگشت scalbn(x, n);
}
__CRT_INLINE اعشاری __cdecl scalblnf(اعشاری x, long n) {
  بازگشت scalbn(x, n);
}
__CRT_INLINE long دوگانه __cdecl scalblnl(long دوگانه x, long n) {
  بازگشت scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE دوگانه __cdecl ldexp(دوگانه x, صحیح expn) {
  بازگشت scalbn(x, expn);
}
__CRT_INLINE اعشاری __cdecl ldexpf(اعشاری x, صحیح expn) {
  بازگشت scalbn(x, expn);
}
__CRT_INLINE long دوگانه __cdecl ldexpl(long دوگانه x, صحیح expn) {
  بازگشت scalbn(x, expn);
}

__CRT_INLINE اعشاری __cdecl frexpf(اعشاری x, صحیح *y) {
  بازگشت frexp(x, y);
}
__CRT_INLINE long دوگانه __cdecl frexpl (long دوگانه x, صحیح* y) {
  بازگشت frexp(x, y);
}


__CRT_INLINE دوگانه __cdecl rint(دوگانه x) {
دوگانه retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  بازگشت retval;
}

__CRT_INLINE اعشاری __cdecl rintf(اعشاری x) {
  اعشاری retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   بازگشت retval;
}
__CRT_INLINE long دوگانه __cdecl rintl (long دوگانه x) {
  بازگشت rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(دوگانه x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  بازگشت retval;
}

__CRT_INLINE long __cdecl lrintf(اعشاری x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  بازگشت retval;
}

__CRT_INLINE long __cdecl lrintl (long دوگانه x) {
  بازگشت lrint(x);
}


__CRT_INLINE long long __cdecl llrint(دوگانه x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  بازگشت retval;
}

__CRT_INLINE long long __cdecl llrintf(اعشاری x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  بازگشت retval;
}

__CRT_INLINE long long __cdecl llrintl (long دوگانه x) {
  بازگشت llrint(x);
}


__CRT_INLINE دوگانه __cdecl trunc(دوگانه _x) {
  دوگانه retval;
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
  بازگشت retval;
}

__CRT_INLINE اعشاری __cdecl truncf(اعشاری x) {
  بازگشت (اعشاری) ((intptr_t) x);
}
__CRT_INLINE long دوگانه __cdecl truncl(long دوگانه x) {
  بازگشت trunc(x);
}


__CRT_INLINE long دوگانه __cdecl nextafterl(long دوگانه x, long دوگانه to) {
  بازگشت nextafter(x, to);
}

__CRT_INLINE دوگانه __cdecl nexttoward(دوگانه x, long دوگانه to) {
  بازگشت nextafter(x, to);
}
__CRT_INLINE اعشاری __cdecl nexttowardf(اعشاری x, long دوگانه to) {
  بازگشت nextafterf(x, to);
}
__CRT_INLINE long دوگانه __cdecl nexttowardl(long دوگانه x, long دوگانه to) {
  بازگشت nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE دوگانه __cdecl fabs(دوگانه x) {
  بازگشت x < 0 ? -x : x;
}
__CRT_INLINE اعشاری __cdecl fabsf(اعشاری x) {
  بازگشت x < 0 ? -x : x;
}
__CRT_INLINE long دوگانه __cdecl fabsl(long دوگانه x) {
  بازگشت x < 0 ? -x : x;
}


#اگر defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE اعشاری acosf(اعشاری x) { بازگشت acos(x); }
  __CRT_INLINE اعشاری asinf(اعشاری x) { بازگشت asin(x); }
  __CRT_INLINE اعشاری atanf(اعشاری x) { بازگشت atan(x); }
  __CRT_INLINE اعشاری atan2f(اعشاری x, اعشاری y) { بازگشت atan2(x, y); }
  __CRT_INLINE اعشاری ceilf(اعشاری x) { بازگشت ceil(x); }
  __CRT_INLINE اعشاری cosf(اعشاری x) { بازگشت cos(x); }
  __CRT_INLINE اعشاری coshf(اعشاری x) { بازگشت cosh(x); }
  __CRT_INLINE اعشاری expf(اعشاری x) { بازگشت exp(x); }
  __CRT_INLINE اعشاری floorf(اعشاری x) { بازگشت floor(x); }
  __CRT_INLINE اعشاری fmodf(اعشاری x, اعشاری y) { بازگشت fmod(x, y); }
  __CRT_INLINE اعشاری logf(اعشاری x) { بازگشت log(x); }
  __CRT_INLINE اعشاری logbf(اعشاری x) { بازگشت logb(x); }
  __CRT_INLINE اعشاری log10f(اعشاری x) { بازگشت log10(x); }
  __CRT_INLINE اعشاری modff(اعشاری x, اعشاری *y) { دوگانه di, df = modf(x, &di); *y = di; بازگشت df; }
  __CRT_INLINE اعشاری powf(اعشاری x, اعشاری y) { بازگشت pow(x, y); }
  __CRT_INLINE اعشاری sinf(اعشاری x) { بازگشت sin(x); }
  __CRT_INLINE اعشاری sinhf(اعشاری x) { بازگشت sinh(x); }
  __CRT_INLINE اعشاری sqrtf(اعشاری x) { بازگشت sqrt(x); }
  __CRT_INLINE اعشاری tanf(اعشاری x) { بازگشت tan(x); }
  __CRT_INLINE اعشاری tanhf(اعشاری x) { بازگشت tanh(x); }
#endif
__CRT_INLINE اعشاری __cdecl asinhf(اعشاری x) { بازگشت asinh(x); }
__CRT_INLINE اعشاری __cdecl acoshf(اعشاری x) { بازگشت acosh(x); }
__CRT_INLINE اعشاری __cdecl atanhf(اعشاری x) { بازگشت atanh(x); }

__CRT_INLINE long دوگانه __cdecl asinhl(long دوگانه x) { بازگشت asinh(x); }
__CRT_INLINE long دوگانه __cdecl acoshl(long دوگانه x) { بازگشت acosh(x); }
__CRT_INLINE long دوگانه __cdecl atanhl(long دوگانه x) { بازگشت atanh(x); }
__CRT_INLINE long دوگانه __cdecl asinl(long دوگانه x) { بازگشت asin(x); }
__CRT_INLINE long دوگانه __cdecl acosl(long دوگانه x) { بازگشت acos(x); }
__CRT_INLINE long دوگانه __cdecl atanl(long دوگانه x) { بازگشت atan(x); }
__CRT_INLINE long دوگانه __cdecl ceill(long دوگانه x) { بازگشت ceil(x); }
__CRT_INLINE long دوگانه __cdecl coshl(long دوگانه x) { بازگشت cosh(x); }
__CRT_INLINE long دوگانه __cdecl cosl(long دوگانه x) { بازگشت cos(x); }
__CRT_INLINE long دوگانه __cdecl expl(long دوگانه x) { بازگشت exp(x); }
__CRT_INLINE long دوگانه __cdecl floorl(long دوگانه x) { بازگشت floor(x); }
__CRT_INLINE long دوگانه __cdecl fmodl(long دوگانه x, long دوگانه y) { بازگشت fmod(x, y); }
__CRT_INLINE long دوگانه __cdecl hypotl(long دوگانه x, long دوگانه y) { بازگشت hypot(x, y); }
__CRT_INLINE long دوگانه __cdecl logl(long دوگانه x) { بازگشت log(x); }
__CRT_INLINE long دوگانه __cdecl logbl(long دوگانه x) { بازگشت logb(x); }
__CRT_INLINE long دوگانه __cdecl log10l(long دوگانه x) { بازگشت log10(x); }
__CRT_INLINE long دوگانه __cdecl modfl(long دوگانه x, long دوگانه* y) { دوگانه y1 = *y; x = modf(x, &y1); *y = y1; بازگشت x; }
__CRT_INLINE long دوگانه __cdecl powl(long دوگانه x, long دوگانه y) { بازگشت pow(x, y); }
__CRT_INLINE long دوگانه __cdecl sinhl(long دوگانه x) { بازگشت sinh(x); }
__CRT_INLINE long دوگانه __cdecl sinl(long دوگانه x) { بازگشت sin(x); }
__CRT_INLINE long دوگانه __cdecl sqrtl(long دوگانه x) { بازگشت sqrt(x); }
__CRT_INLINE long دوگانه __cdecl tanhl(long دوگانه x) { بازگشت tanh(x); }
__CRT_INLINE long دوگانه __cdecl tanl(long دوگانه x) { بازگشت tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE دوگانه __cdecl log1p(دوگانه x) {
  دوگانه u = 1.0 + x;
  بازگشت u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE اعشاری __cdecl log1pf(اعشاری x) {
  اعشاری u = 1.0f + x;
  بازگشت u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long دوگانه __cdecl log1pl(long دوگانه x) {
  بازگشت log1p(x);
}


__CRT_INLINE دوگانه __cdecl expm1(دوگانه x) {
  اگر (x > 0.0024 || x < -0.0024) بازگشت exp(x) - 1.0;
  بازگشت x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE اعشاری __cdecl expm1f(اعشاری x) {
  اگر (x > 0.085f || x < -0.085f) بازگشت expf(x) - 1.0f;
  بازگشت x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long دوگانه __cdecl expm1l(long دوگانه x) {
  بازگشت expm1(x);
}


__CRT_INLINE دوگانه __cdecl cbrt(دوگانه x) {
  بازگشت x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE اعشاری __cdecl cbrtf(اعشاری x) {
  بازگشت x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long دوگانه __cdecl cbrtl(long دوگانه x) {
  بازگشت cbrt(x);
}


__CRT_INLINE دوگانه __cdecl log2(دوگانه x) {
  بازگشت log(x) * 1.442695040888963407;
}
__CRT_INLINE اعشاری __cdecl log2f(اعشاری x) {
  بازگشت log(x) * 1.442695040888963407;
}
__CRT_INLINE long دوگانه __cdecl log2l(long دوگانه x) {
  بازگشت log(x) * 1.442695040888963407;
}


__CRT_INLINE دوگانه __cdecl exp2(دوگانه x) {
  بازگشت exp(x * 0.693147180559945309);
}
__CRT_INLINE اعشاری __cdecl exp2f(اعشاری x) {
  بازگشت exp(x * 0.693147180559945309);
}
__CRT_INLINE long دوگانه __cdecl exp2l(long دوگانه x) {
  بازگشت exp(x * 0.693147180559945309);
}


__CRT_INLINE صحیح __cdecl ilogb(دوگانه x) {
  بازگشت (صحیح) logb(x);
}
__CRT_INLINE صحیح __cdecl ilogbf(اعشاری x) {
  بازگشت (صحیح) logbf(x);
}
__CRT_INLINE صحیح __cdecl ilogbl(long دوگانه x) {
  بازگشت (صحیح) logb(x);
}


__CRT_INLINE دوگانه __cdecl fdim(دوگانه x, دوگانه y) {
  اگر (isnan(x) || isnan(y)) بازگشت NAN;
  بازگشت x > y ? x - y : 0;
}
__CRT_INLINE اعشاری __cdecl fdimf(اعشاری x, اعشاری y) {
  اگر (isnan(x) || isnan(y)) بازگشت NAN;
  بازگشت x > y ? x - y : 0;
}
__CRT_INLINE long دوگانه __cdecl fdiml(long دوگانه x, long دوگانه y) {
  اگر (isnan(x) || isnan(y)) بازگشت NAN;
  بازگشت x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE دوگانه __cdecl tgamma(دوگانه x) {
  دوگانه m = 1.0, t = 3.14159265358979323;
  اگر (x == floor(x)) {
    اگر (x == 0) بازگشت INFINITY;
    اگر (x < 0) بازگشت NAN;
    اگر (x < 26) { برای (دوگانه k = 2; k < x; ++k) m *= k; بازگشت m; }
  }
  اگر (x < 0.5)
    بازگشت t / (sin(t*x)*tgamma(1.0 - x));
  اگر (x > 12.0)
    بازگشت exp(lgamma(x));

  ایستا ثابت دوگانه c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  برای (صحیح k = 0; k < 8; ++k) m += c[k] / (x + k);
  بازگشت 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE دوگانه __cdecl lgamma(دوگانه x) {
  اگر (x < 12.0) {
    اگر (x <= 0.0 && x == floor(x)) بازگشت INFINITY;
    x = tgamma(x);
    بازگشت log(x < 0.0 ? -x : x);
  }
  ایستا ثابت دوگانه c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  دوگانه m = -3617.0/122400.0, t = 1.0 / (x*x);
  برای (صحیح k = 6; k >= 0; --k) m = m*t + c[k];
  بازگشت (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE اعشاری __cdecl tgammaf(اعشاری x) {
  بازگشت tgamma(x);
}
__CRT_INLINE اعشاری __cdecl lgammaf(اعشاری x) {
  بازگشت lgamma(x);
}
__CRT_INLINE long دوگانه __cdecl tgammal(long دوگانه x) {
  بازگشت tgamma(x);
}
__CRT_INLINE long دوگانه __cdecl lgammal(long دوگانه x) {
  بازگشت lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
