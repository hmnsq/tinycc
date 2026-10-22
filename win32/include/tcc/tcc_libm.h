#اگر_غیر_تعریف_شدہ _TCC_LIBM_H_
#تعریف_کرو _TCC_LIBM_H_

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

__CRT_INLINE صحیح __cdecl __fpclassify (دوہرا x) {
  اتحاد {دوہرا f; uint64_t i;} u = {.f = x};
  صحیح e = u.i>>52 & 0x7ff;
  اگر (!e) واپس u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  اگر (e==0x7ff) واپس u.i<<12 ? FP_NAN : FP_INFINITE;
  واپس FP_NORMAL;
}

__CRT_INLINE صحیح __cdecl __fpclassifyf (اعشاری x) {
  اتحاد {اعشاری f; uint32_t i;} u = {.f = x};
  صحیح e = u.i>>23 & 0xff;
  اگر (!e) واپس u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  اگر (e==0xff) واپس u.i<<9 ? FP_NAN : FP_INFINITE;
  واپس FP_NORMAL;
}

__CRT_INLINE صحیح __cdecl __fpclassifyl (طویل دوہرا x) {
  واپس __fpclassify(x);
}


/* signbit */

__CRT_INLINE صحیح __cdecl __signbit (دوہرا x) {
  اتحاد {دوہرا f; uint64_t i;} u = {.f = x};
  واپس u.i>>63;
}

__CRT_INLINE صحیح __cdecl __signbitf (اعشاری x) {
  اتحاد {اعشاری f; uint32_t i; } u = {.f = x};
  واپس u.i>>31;
}

__CRT_INLINE صحیح __cdecl __signbitl (طویل دوہرا x) {
  واپس __signbit(x);
}


/* fmin*, fmax* */

#تعریف_کرو TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE دوہرا __cdecl fmin (دوہرا x, دوہرا y) {
  واپس TCCFP_FMIN_EVAL;
}

__CRT_INLINE اعشاری __cdecl fminf (اعشاری x, اعشاری y) {
  واپس TCCFP_FMIN_EVAL;
}

__CRT_INLINE طویل دوہرا __cdecl fminl (طویل دوہرا x, طویل دوہرا y) {
  واپس TCCFP_FMIN_EVAL;
}

#تعریف_کرو TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE دوہرا __cdecl fmax (دوہرا x, دوہرا y) {
  واپس TCCFP_FMAX_EVAL;
}

__CRT_INLINE اعشاری __cdecl fmaxf (اعشاری x, اعشاری y) {
  واپس TCCFP_FMAX_EVAL;
}

__CRT_INLINE طویل دوہرا __cdecl fmaxl (طویل دوہرا x, طویل دوہرا y) {
  واپس TCCFP_FMAX_EVAL;
}


/* *round* */

#تعریف_کرو TCCFP_FORCE_EVAL(x) کرو {  \
  متلون typeof(x) __x;         \
  __x = (x);                      \
} جب(0)

__CRT_INLINE دوہرا __cdecl باری (دوہرا x) {
  اتحاد {دوہرا f; uint64_t i;} u = {.f = x};
  صحیح e = u.i >> 52 & 0x7ff;
  دوہرا y;

  اگر (e >= 0x3ff+52)
    واپس x;
  اگر (u.i >> 63)
    x = -x;
  اگر (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    واپس 0*u.f;
  }
  y = (دوہرا)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  واپس (u.i >> 63) ? -y : y;
}

__CRT_INLINE طویل __cdecl lround (دوہرا x) {
  واپس باری(x);
}

__CRT_INLINE طویل طویل __cdecl llround (دوہرا x) {
  واپس باری(x);
}

__CRT_INLINE اعشاری __cdecl roundf (اعشاری x) {
  واپس باری(x);
}

__CRT_INLINE طویل __cdecl lroundf (اعشاری x) {
  واپس باری(x);
}

__CRT_INLINE طویل طویل __cdecl llroundf (اعشاری x) {
  واپس باری(x);
}

__CRT_INLINE طویل دوہرا __cdecl roundl (طویل دوہرا x) {
  واپس باری(x);
}

__CRT_INLINE طویل __cdecl lroundl (طویل دوہرا x) {
  واپس باری(x);
}

__CRT_INLINE طویل طویل __cdecl llroundl (طویل دوہرا x) {
  واپس باری(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE دوہرا __cdecl asinh(دوہرا x) {
  اتحاد {دوہرا f; uint64_t i;} u = {.f = x};
  غیرعلامتی e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  اگر (e >= 0x3ff + 26) x = لوگارتھم(x) + 0.693147180559945309;
  ورنہ اگر (e >= 0x3ff + 1) x = لوگارتھم(2*x + 1 / (جذر(x*x + 1) + x)); /* |x|>=2 */
  ورنہ اگر (e >= 0x3ff - 26) x = log1p(x + x*x / (جذر(x*x + 1) + 1));
  ورنہ TCCFP_FORCE_EVAL(x + 0x1p120f);
  واپس s ? -x : x;
}

__CRT_INLINE دوہرا __cdecl acosh(دوہرا x) {
  اتحاد {دوہرا f; uint64_t i;} u = {.f = x};
  غیرعلامتی e = u.i >> 52 & 0x7ff;
  اگر (e < 0x3ff + 1) واپس --x, log1p(x + جذر(x*x + 2*x)); /* |x|<2 */
  اگر (e < 0x3ff + 26) واپس لوگارتھم(2*x - 1 / (x + جذر(x*x - 1)));
  واپس لوگارتھم(x) + 0.693147180559945309;
}

__CRT_INLINE دوہرا __cdecl atanh(دوہرا x) {
  اتحاد {دوہرا f; uint64_t i;} u = {.f = x};
  غیرعلامتی e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  اگر (e < 0x3ff - 1) {
    اگر (e < 0x3ff - 32) { اگر (e == 0) TCCFP_FORCE_EVAL((اعشاری)x); }
    ورنہ x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } ورنہ x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  واپس s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE دوہرا __cdecl scalbn(دوہرا x, صحیح n) {
  اتحاد {دوہرا f; uint64_t i;} u;
  اگر (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    اگر (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      اگر (n > 1023) n = 1023;
    }
  } ورنہ اگر (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    اگر (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      اگر (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  واپس x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE دوہرا __cdecl frexp(دوہرا x, صحیح *e) {
  اتحاد {دوہرا f; uint64_t i;} u = {.f = x};
  صحیح ee = u.i>>52 & 0x7ff;
  اگر (!ee) {
    اگر (x) x = frexp(x*0x1p64, e), *e -= 64;
    ورنہ *e = 0;
    واپس x;
  } ورنہ اگر (ee == 0x7ff)
    واپس x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  واپس u.f;
}

/* MUSL nan */

__CRT_INLINE دوہرا __cdecl nan(ثابت حرف* s) {
  واپس NAN;
}
__CRT_INLINE اعشاری __cdecl nanf(ثابت حرف* s) {
  واپس NAN;
}
__CRT_INLINE طویل دوہرا __cdecl nanl(ثابت حرف* s) {
  واپس NAN;
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
  واپس scalbn(x, n);
}
__CRT_INLINE طویل دوہرا __cdecl scalbnl(طویل دوہرا x, صحیح n) {
  واپس scalbn(x, n);
}

__CRT_INLINE دوہرا __cdecl scalbln(دوہرا x, طویل n) {
  واپس scalbn(x, n);
}
__CRT_INLINE اعشاری __cdecl scalblnf(اعشاری x, طویل n) {
  واپس scalbn(x, n);
}
__CRT_INLINE طویل دوہرا __cdecl scalblnl(طویل دوہرا x, طویل n) {
  واپس scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE دوہرا __cdecl ldexp(دوہرا x, صحیح expn) {
  واپس scalbn(x, expn);
}
__CRT_INLINE اعشاری __cdecl ldexpf(اعشاری x, صحیح expn) {
  واپس scalbn(x, expn);
}
__CRT_INLINE طویل دوہرا __cdecl ldexpl(طویل دوہرا x, صحیح expn) {
  واپس scalbn(x, expn);
}

__CRT_INLINE اعشاری __cdecl frexpf(اعشاری x, صحیح *y) {
  واپس frexp(x, y);
}
__CRT_INLINE طویل دوہرا __cdecl frexpl (طویل دوہرا x, صحیح* y) {
  واپس frexp(x, y);
}


__CRT_INLINE دوہرا __cdecl rint(دوہرا x) {
دوہرا retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  واپس retval;
}

__CRT_INLINE اعشاری __cdecl rintf(اعشاری x) {
  اعشاری retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   واپس retval;
}
__CRT_INLINE طویل دوہرا __cdecl rintl (طویل دوہرا x) {
  واپس rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE طویل __cdecl lrint(دوہرا x) {
  طویل retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  واپس retval;
}

__CRT_INLINE طویل __cdecl lrintf(اعشاری x) {
  طویل retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  واپس retval;
}

__CRT_INLINE طویل __cdecl lrintl (طویل دوہرا x) {
  واپس lrint(x);
}


__CRT_INLINE طویل طویل __cdecl llrint(دوہرا x) {
طویل طویل retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  واپس retval;
}

__CRT_INLINE طویل طویل __cdecl llrintf(اعشاری x) {
  طویل طویل retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  واپس retval;
}

__CRT_INLINE طویل طویل __cdecl llrintl (طویل دوہرا x) {
  واپس llrint(x);
}


__CRT_INLINE دوہرا __cdecl trunc(دوہرا _x) {
  دوہرا retval;
  غیرعلامتی مختصر saved_cw;
  غیرعلامتی مختصر tmp_cw;
  __asm__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
  tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
    | FE_TOWARDZERO;
  __asm__ ("fldcw %0;" : : "m" (tmp_cw));
  __asm__ ("fldl  %1;"
           "frndint;"
           "fstpl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
  __asm__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
  واپس retval;
}

__CRT_INLINE اعشاری __cdecl truncf(اعشاری x) {
  واپس (اعشاری) ((intptr_t) x);
}
__CRT_INLINE طویل دوہرا __cdecl truncl(طویل دوہرا x) {
  واپس trunc(x);
}


__CRT_INLINE طویل دوہرا __cdecl nextafterl(طویل دوہرا x, طویل دوہرا مقصد) {
  واپس nextafter(x, مقصد);
}

__CRT_INLINE دوہرا __cdecl nexttoward(دوہرا x, طویل دوہرا مقصد) {
  واپس nextafter(x, مقصد);
}
__CRT_INLINE اعشاری __cdecl nexttowardf(اعشاری x, طویل دوہرا مقصد) {
  واپس nextafterf(x, مقصد);
}
__CRT_INLINE طویل دوہرا __cdecl nexttowardl(طویل دوہرا x, طویل دوہرا مقصد) {
  واپس nextafter(x, مقصد);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE دوہرا __cdecl fabs(دوہرا x) {
  واپس x < 0 ? -x : x;
}
__CRT_INLINE اعشاری __cdecl fabsf(اعشاری x) {
  واپس x < 0 ? -x : x;
}
__CRT_INLINE طویل دوہرا __cdecl fabsl(طویل دوہرا x) {
  واپس x < 0 ? -x : x;
}


#اگر defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE اعشاری acosf(اعشاری x) { واپس acos(x); }
  __CRT_INLINE اعشاری asinf(اعشاری x) { واپس asin(x); }
  __CRT_INLINE اعشاری atanf(اعشاری x) { واپس atan(x); }
  __CRT_INLINE اعشاری atan2f(اعشاری x, اعشاری y) { واپس atan2(x, y); }
  __CRT_INLINE اعشاری ceilf(اعشاری x) { واپس ceil(x); }
  __CRT_INLINE اعشاری cosf(اعشاری x) { واپس جیب_تمام(x); }
  __CRT_INLINE اعشاری coshf(اعشاری x) { واپس cosh(x); }
  __CRT_INLINE اعشاری expf(اعشاری x) { واپس قوت_نما(x); }
  __CRT_INLINE اعشاری floorf(اعشاری x) { واپس floor(x); }
  __CRT_INLINE اعشاری fmodf(اعشاری x, اعشاری y) { واپس fmod(x, y); }
  __CRT_INLINE اعشاری logf(اعشاری x) { واپس لوگارتھم(x); }
  __CRT_INLINE اعشاری logbf(اعشاری x) { واپس logb(x); }
  __CRT_INLINE اعشاری log10f(اعشاری x) { واپس log10(x); }
  __CRT_INLINE اعشاری modff(اعشاری x, اعشاری *y) { دوہرا di, df = modf(x, &di); *y = di; واپس df; }
  __CRT_INLINE اعشاری powf(اعشاری x, اعشاری y) { واپس قوت(x, y); }
  __CRT_INLINE اعشاری sinf(اعشاری x) { واپس جیب(x); }
  __CRT_INLINE اعشاری sinhf(اعشاری x) { واپس sinh(x); }
  __CRT_INLINE اعشاری sqrtf(اعشاری x) { واپس جذر(x); }
  __CRT_INLINE اعشاری tanf(اعشاری x) { واپس tan(x); }
  __CRT_INLINE اعشاری tanhf(اعشاری x) { واپس tanh(x); }
#اگر_ختم
__CRT_INLINE اعشاری __cdecl asinhf(اعشاری x) { واپس asinh(x); }
__CRT_INLINE اعشاری __cdecl acoshf(اعشاری x) { واپس acosh(x); }
__CRT_INLINE اعشاری __cdecl atanhf(اعشاری x) { واپس atanh(x); }

__CRT_INLINE طویل دوہرا __cdecl asinhl(طویل دوہرا x) { واپس asinh(x); }
__CRT_INLINE طویل دوہرا __cdecl acoshl(طویل دوہرا x) { واپس acosh(x); }
__CRT_INLINE طویل دوہرا __cdecl atanhl(طویل دوہرا x) { واپس atanh(x); }
__CRT_INLINE طویل دوہرا __cdecl asinl(طویل دوہرا x) { واپس asin(x); }
__CRT_INLINE طویل دوہرا __cdecl acosl(طویل دوہرا x) { واپس acos(x); }
__CRT_INLINE طویل دوہرا __cdecl atanl(طویل دوہرا x) { واپس atan(x); }
__CRT_INLINE طویل دوہرا __cdecl ceill(طویل دوہرا x) { واپس ceil(x); }
__CRT_INLINE طویل دوہرا __cdecl coshl(طویل دوہرا x) { واپس cosh(x); }
__CRT_INLINE طویل دوہرا __cdecl cosl(طویل دوہرا x) { واپس جیب_تمام(x); }
__CRT_INLINE طویل دوہرا __cdecl expl(طویل دوہرا x) { واپس قوت_نما(x); }
__CRT_INLINE طویل دوہرا __cdecl floorl(طویل دوہرا x) { واپس floor(x); }
__CRT_INLINE طویل دوہرا __cdecl fmodl(طویل دوہرا x, طویل دوہرا y) { واپس fmod(x, y); }
__CRT_INLINE طویل دوہرا __cdecl hypotl(طویل دوہرا x, طویل دوہرا y) { واپس hypot(x, y); }
__CRT_INLINE طویل دوہرا __cdecl logl(طویل دوہرا x) { واپس لوگارتھم(x); }
__CRT_INLINE طویل دوہرا __cdecl logbl(طویل دوہرا x) { واپس logb(x); }
__CRT_INLINE طویل دوہرا __cdecl log10l(طویل دوہرا x) { واپس log10(x); }
__CRT_INLINE طویل دوہرا __cdecl modfl(طویل دوہرا x, طویل دوہرا* y) { دوہرا y1 = *y; x = modf(x, &y1); *y = y1; واپس x; }
__CRT_INLINE طویل دوہرا __cdecl powl(طویل دوہرا x, طویل دوہرا y) { واپس قوت(x, y); }
__CRT_INLINE طویل دوہرا __cdecl sinhl(طویل دوہرا x) { واپس sinh(x); }
__CRT_INLINE طویل دوہرا __cdecl sinl(طویل دوہرا x) { واپس جیب(x); }
__CRT_INLINE طویل دوہرا __cdecl sqrtl(طویل دوہرا x) { واپس جذر(x); }
__CRT_INLINE طویل دوہرا __cdecl tanhl(طویل دوہرا x) { واپس tanh(x); }
__CRT_INLINE طویل دوہرا __cdecl tanl(طویل دوہرا x) { واپس tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE دوہرا __cdecl log1p(دوہرا x) {
  دوہرا u = 1.0 + x;
  واپس u == 1.0 ? x : لوگارتھم(u)*(x / (u - 1.0));
}
__CRT_INLINE اعشاری __cdecl log1pf(اعشاری x) {
  اعشاری u = 1.0f + x;
  واپس u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE طویل دوہرا __cdecl log1pl(طویل دوہرا x) {
  واپس log1p(x);
}


__CRT_INLINE دوہرا __cdecl expm1(دوہرا x) {
  اگر (x > 0.0024 || x < -0.0024) واپس قوت_نما(x) - 1.0;
  واپس x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE اعشاری __cdecl expm1f(اعشاری x) {
  اگر (x > 0.085f || x < -0.085f) واپس expf(x) - 1.0f;
  واپس x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE طویل دوہرا __cdecl expm1l(طویل دوہرا x) {
  واپس expm1(x);
}


__CRT_INLINE دوہرا __cdecl cbrt(دوہرا x) {
  واپس x < 0.0 ? -قوت(-x, 1/3.0) : قوت(x, 1/3.0);
}
__CRT_INLINE اعشاری __cdecl cbrtf(اعشاری x) {
  واپس x < 0.0f ? -قوت(-x, 1/3.0) : قوت(x, 1/3.0);
}
__CRT_INLINE طویل دوہرا __cdecl cbrtl(طویل دوہرا x) {
  واپس cbrt(x);
}


__CRT_INLINE دوہرا __cdecl log2(دوہرا x) {
  واپس لوگارتھم(x) * 1.442695040888963407;
}
__CRT_INLINE اعشاری __cdecl log2f(اعشاری x) {
  واپس لوگارتھم(x) * 1.442695040888963407;
}
__CRT_INLINE طویل دوہرا __cdecl log2l(طویل دوہرا x) {
  واپس لوگارتھم(x) * 1.442695040888963407;
}


__CRT_INLINE دوہرا __cdecl exp2(دوہرا x) {
  واپس قوت_نما(x * 0.693147180559945309);
}
__CRT_INLINE اعشاری __cdecl exp2f(اعشاری x) {
  واپس قوت_نما(x * 0.693147180559945309);
}
__CRT_INLINE طویل دوہرا __cdecl exp2l(طویل دوہرا x) {
  واپس قوت_نما(x * 0.693147180559945309);
}


__CRT_INLINE صحیح __cdecl ilogb(دوہرا x) {
  واپس (صحیح) logb(x);
}
__CRT_INLINE صحیح __cdecl ilogbf(اعشاری x) {
  واپس (صحیح) logbf(x);
}
__CRT_INLINE صحیح __cdecl ilogbl(طویل دوہرا x) {
  واپس (صحیح) logb(x);
}


__CRT_INLINE دوہرا __cdecl fdim(دوہرا x, دوہرا y) {
  اگر (isnan(x) || isnan(y)) واپس NAN;
  واپس x > y ? x - y : 0;
}
__CRT_INLINE اعشاری __cdecl fdimf(اعشاری x, اعشاری y) {
  اگر (isnan(x) || isnan(y)) واپس NAN;
  واپس x > y ? x - y : 0;
}
__CRT_INLINE طویل دوہرا __cdecl fdiml(طویل دوہرا x, طویل دوہرا y) {
  اگر (isnan(x) || isnan(y)) واپس NAN;
  واپس x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE دوہرا __cdecl tgamma(دوہرا x) {
  دوہرا m = 1.0, t = 3.14159265358979323;
  اگر (x == floor(x)) {
    اگر (x == 0) واپس INFINITY;
    اگر (x < 0) واپس NAN;
    اگر (x < 26) { برائے (دوہرا k = 2; k < x; ++k) m *= k; واپس m; }
  }
  اگر (x < 0.5)
    واپس t / (جیب(t*x)*tgamma(1.0 - x));
  اگر (x > 12.0)
    واپس قوت_نما(lgamma(x));

  ساکن ثابت دوہرا c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  برائے (صحیح k = 0; k < 8; ++k) m += c[k] / (x + k);
  واپس 2.50662827463100050 * قوت(t, x - 0.5)*قوت_نما(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE دوہرا __cdecl lgamma(دوہرا x) {
  اگر (x < 12.0) {
    اگر (x <= 0.0 && x == floor(x)) واپس INFINITY;
    x = tgamma(x);
    واپس لوگارتھم(x < 0.0 ? -x : x);
  }
  ساکن ثابت دوہرا c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  دوہرا m = -3617.0/122400.0, t = 1.0 / (x*x);
  برائے (صحیح k = 6; k >= 0; --k) m = m*t + c[k];
  واپس (x - 0.5)*لوگارتھم(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE اعشاری __cdecl tgammaf(اعشاری x) {
  واپس tgamma(x);
}
__CRT_INLINE اعشاری __cdecl lgammaf(اعشاری x) {
  واپس lgamma(x);
}
__CRT_INLINE طویل دوہرا __cdecl tgammal(طویل دوہرا x) {
  واپس tgamma(x);
}
__CRT_INLINE طویل دوہرا __cdecl lgammal(طویل دوہرا x) {
  واپس lgamma(x);
}

#اگر_ختم /* _TCC_LIBM_H_ */
