#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#अन्तर्भाव "../math.h"
#अन्तर्भाव "../stdint.h"

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

__CRT_INLINE पूर्णांक __cdecl __fpclassify (द्विगुण x) {
  संघ {द्विगुण f; uint64_t i;} u = {.f = x};
  पूर्णांक e = u.i>>52 & 0x7ff;
  जर (!e) परत u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  जर (e==0x7ff) परत u.i<<12 ? FP_NAN : FP_INFINITE;
  परत FP_NORMAL;
}

__CRT_INLINE पूर्णांक __cdecl __fpclassifyf (दशांश x) {
  संघ {दशांश f; uint32_t i;} u = {.f = x};
  पूर्णांक e = u.i>>23 & 0xff;
  जर (!e) परत u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  जर (e==0xff) परत u.i<<9 ? FP_NAN : FP_INFINITE;
  परत FP_NORMAL;
}

__CRT_INLINE पूर्णांक __cdecl __fpclassifyl (दीर्घ द्विगुण x) {
  परत __fpclassify(x);
}


/* signbit */

__CRT_INLINE पूर्णांक __cdecl __signbit (द्विगुण x) {
  संघ {द्विगुण f; uint64_t i;} u = {.f = x};
  परत u.i>>63;
}

__CRT_INLINE पूर्णांक __cdecl __signbitf (दशांश x) {
  संघ {दशांश f; uint32_t i; } u = {.f = x};
  परत u.i>>31;
}

__CRT_INLINE पूर्णांक __cdecl __signbitl (दीर्घ द्विगुण x) {
  परत __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE द्विगुण __cdecl fmin (द्विगुण x, द्विगुण y) {
  परत TCCFP_FMIN_EVAL;
}

__CRT_INLINE दशांश __cdecl fminf (दशांश x, दशांश y) {
  परत TCCFP_FMIN_EVAL;
}

__CRT_INLINE दीर्घ द्विगुण __cdecl fminl (दीर्घ द्विगुण x, दीर्घ द्विगुण y) {
  परत TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE द्विगुण __cdecl fmax (द्विगुण x, द्विगुण y) {
  परत TCCFP_FMAX_EVAL;
}

__CRT_INLINE दशांश __cdecl fmaxf (दशांश x, दशांश y) {
  परत TCCFP_FMAX_EVAL;
}

__CRT_INLINE दीर्घ द्विगुण __cdecl fmaxl (दीर्घ द्विगुण x, दीर्घ द्विगुण y) {
  परत TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) करा {  \
  अस्थिर typeof(x) __x;         \
  __x = (x);                      \
} पर्यंत(0)

__CRT_INLINE द्विगुण __cdecl round (द्विगुण x) {
  संघ {द्विगुण f; uint64_t i;} u = {.f = x};
  पूर्णांक e = u.i >> 52 & 0x7ff;
  द्विगुण y;

  जर (e >= 0x3ff+52)
    परत x;
  जर (u.i >> 63)
    x = -x;
  जर (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    परत 0*u.f;
  }
  y = (द्विगुण)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  परत (u.i >> 63) ? -y : y;
}

__CRT_INLINE दीर्घ __cdecl lround (द्विगुण x) {
  परत round(x);
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llround (द्विगुण x) {
  परत round(x);
}

__CRT_INLINE दशांश __cdecl roundf (दशांश x) {
  परत round(x);
}

__CRT_INLINE दीर्घ __cdecl lroundf (दशांश x) {
  परत round(x);
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llroundf (दशांश x) {
  परत round(x);
}

__CRT_INLINE दीर्घ द्विगुण __cdecl roundl (दीर्घ द्विगुण x) {
  परत round(x);
}

__CRT_INLINE दीर्घ __cdecl lroundl (दीर्घ द्विगुण x) {
  परत round(x);
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llroundl (दीर्घ द्विगुण x) {
  परत round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE द्विगुण __cdecl asinh(द्विगुण x) {
  संघ {द्विगुण f; uint64_t i;} u = {.f = x};
  अचिन्हित e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  जर (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  अन्यथा जर (e >= 0x3ff + 1) x = log(2*x + 1 / (वर्ग_मूल(x*x + 1) + x)); /* |x|>=2 */
  अन्यथा जर (e >= 0x3ff - 26) x = log1p(x + x*x / (वर्ग_मूल(x*x + 1) + 1));
  अन्यथा TCCFP_FORCE_EVAL(x + 0x1p120f);
  परत s ? -x : x;
}

__CRT_INLINE द्विगुण __cdecl acosh(द्विगुण x) {
  संघ {द्विगुण f; uint64_t i;} u = {.f = x};
  अचिन्हित e = u.i >> 52 & 0x7ff;
  जर (e < 0x3ff + 1) परत --x, log1p(x + वर्ग_मूल(x*x + 2*x)); /* |x|<2 */
  जर (e < 0x3ff + 26) परत log(2*x - 1 / (x + वर्ग_मूल(x*x - 1)));
  परत log(x) + 0.693147180559945309;
}

__CRT_INLINE द्विगुण __cdecl atanh(द्विगुण x) {
  संघ {द्विगुण f; uint64_t i;} u = {.f = x};
  अचिन्हित e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  जर (e < 0x3ff - 1) {
    जर (e < 0x3ff - 32) { जर (e == 0) TCCFP_FORCE_EVAL((दशांश)x); }
    अन्यथा x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } अन्यथा x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  परत s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE द्विगुण __cdecl scalbn(द्विगुण x, पूर्णांक n) {
  संघ {द्विगुण f; uint64_t i;} u;
  जर (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    जर (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      जर (n > 1023) n = 1023;
    }
  } अन्यथा जर (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    जर (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      जर (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  परत x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE द्विगुण __cdecl frexp(द्विगुण x, पूर्णांक *e) {
  संघ {द्विगुण f; uint64_t i;} u = {.f = x};
  पूर्णांक ee = u.i>>52 & 0x7ff;
  जर (!ee) {
    जर (x) x = frexp(x*0x1p64, e), *e -= 64;
    अन्यथा *e = 0;
    परत x;
  } अन्यथा जर (ee == 0x7ff)
    परत x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  परत u.f;
}

/* MUSL nan */

__CRT_INLINE द्विगुण __cdecl nan(स्थिरांक अक्षर* s) {
  परत न_अंक;
}
__CRT_INLINE दशांश __cdecl nanf(स्थिरांक अक्षर* s) {
  परत न_अंक;
}
__CRT_INLINE दीर्घ द्विगुण __cdecl nanl(स्थिरांक अक्षर* s) {
  परत न_अंक;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE दशांश __cdecl scalbnf(दशांश x, पूर्णांक n) {
  परत scalbn(x, n);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl scalbnl(दीर्घ द्विगुण x, पूर्णांक n) {
  परत scalbn(x, n);
}

__CRT_INLINE द्विगुण __cdecl scalbln(द्विगुण x, दीर्घ n) {
  परत scalbn(x, n);
}
__CRT_INLINE दशांश __cdecl scalblnf(दशांश x, दीर्घ n) {
  परत scalbn(x, n);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl scalblnl(दीर्घ द्विगुण x, दीर्घ n) {
  परत scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE द्विगुण __cdecl ldexp(द्विगुण x, पूर्णांक expn) {
  परत scalbn(x, expn);
}
__CRT_INLINE दशांश __cdecl ldexpf(दशांश x, पूर्णांक expn) {
  परत scalbn(x, expn);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl ldexpl(दीर्घ द्विगुण x, पूर्णांक expn) {
  परत scalbn(x, expn);
}

__CRT_INLINE दशांश __cdecl frexpf(दशांश x, पूर्णांक *y) {
  परत frexp(x, y);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl frexpl (दीर्घ द्विगुण x, पूर्णांक* y) {
  परत frexp(x, y);
}


__CRT_INLINE द्विगुण __cdecl rint(द्विगुण x) {
द्विगुण retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  परत retval;
}

__CRT_INLINE दशांश __cdecl rintf(दशांश x) {
  दशांश retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   परत retval;
}
__CRT_INLINE दीर्घ द्विगुण __cdecl rintl (दीर्घ द्विगुण x) {
  परत rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE दीर्घ __cdecl lrint(द्विगुण x) {
  दीर्घ retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  परत retval;
}

__CRT_INLINE दीर्घ __cdecl lrintf(दशांश x) {
  दीर्घ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  परत retval;
}

__CRT_INLINE दीर्घ __cdecl lrintl (दीर्घ द्विगुण x) {
  परत lrint(x);
}


__CRT_INLINE दीर्घ दीर्घ __cdecl llrint(द्विगुण x) {
दीर्घ दीर्घ retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  परत retval;
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llrintf(दशांश x) {
  दीर्घ दीर्घ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  परत retval;
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llrintl (दीर्घ द्विगुण x) {
  परत llrint(x);
}


__CRT_INLINE द्विगुण __cdecl trunc(द्विगुण _x) {
  द्विगुण retval;
  अचिन्हित लघु saved_cw;
  अचिन्हित लघु tmp_cw;
  __asm__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
  tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
    | FE_TOWARDZERO;
  __asm__ ("fldcw %0;" : : "m" (tmp_cw));
  __asm__ ("fldl  %1;"
           "frndint;"
           "fstpl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
  __asm__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
  परत retval;
}

__CRT_INLINE दशांश __cdecl truncf(दशांश x) {
  परत (दशांश) ((intptr_t) x);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl truncl(दीर्घ द्विगुण x) {
  परत trunc(x);
}


__CRT_INLINE दीर्घ द्विगुण __cdecl nextafterl(दीर्घ द्विगुण x, दीर्घ द्विगुण to) {
  परत nextafter(x, to);
}

__CRT_INLINE द्विगुण __cdecl nexttoward(द्विगुण x, दीर्घ द्विगुण to) {
  परत nextafter(x, to);
}
__CRT_INLINE दशांश __cdecl nexttowardf(दशांश x, दीर्घ द्विगुण to) {
  परत nextafterf(x, to);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl nexttowardl(दीर्घ द्विगुण x, दीर्घ द्विगुण to) {
  परत nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE द्विगुण __cdecl भ_असल(द्विगुण x) {
  परत x < 0 ? -x : x;
}
__CRT_INLINE दशांश __cdecl fabsf(दशांश x) {
  परत x < 0 ? -x : x;
}
__CRT_INLINE दीर्घ द्विगुण __cdecl fabsl(दीर्घ द्विगुण x) {
  परत x < 0 ? -x : x;
}


#जर defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE दशांश acosf(दशांश x) { परत acos(x); }
  __CRT_INLINE दशांश asinf(दशांश x) { परत asin(x); }
  __CRT_INLINE दशांश atanf(दशांश x) { परत atan(x); }
  __CRT_INLINE दशांश atan2f(दशांश x, दशांश y) { परत atan2(x, y); }
  __CRT_INLINE दशांश ceilf(दशांश x) { परत उच्चमान(x); }
  __CRT_INLINE दशांश cosf(दशांश x) { परत cos(x); }
  __CRT_INLINE दशांश coshf(दशांश x) { परत cosh(x); }
  __CRT_INLINE दशांश expf(दशांश x) { परत exp(x); }
  __CRT_INLINE दशांश floorf(दशांश x) { परत न्यूनमान(x); }
  __CRT_INLINE दशांश fmodf(दशांश x, दशांश y) { परत भ_शेष(x, y); }
  __CRT_INLINE दशांश logf(दशांश x) { परत log(x); }
  __CRT_INLINE दशांश logbf(दशांश x) { परत logb(x); }
  __CRT_INLINE दशांश log10f(दशांश x) { परत log10(x); }
  __CRT_INLINE दशांश modff(दशांश x, दशांश *y) { द्विगुण di, df = modf(x, &di); *y = di; परत df; }
  __CRT_INLINE दशांश powf(दशांश x, दशांश y) { परत घात(x, y); }
  __CRT_INLINE दशांश sinf(दशांश x) { परत sin(x); }
  __CRT_INLINE दशांश sinhf(दशांश x) { परत sinh(x); }
  __CRT_INLINE दशांश sqrtf(दशांश x) { परत वर्ग_मूल(x); }
  __CRT_INLINE दशांश tanf(दशांश x) { परत tan(x); }
  __CRT_INLINE दशांश tanhf(दशांश x) { परत tanh(x); }
#endif
__CRT_INLINE दशांश __cdecl asinhf(दशांश x) { परत asinh(x); }
__CRT_INLINE दशांश __cdecl acoshf(दशांश x) { परत acosh(x); }
__CRT_INLINE दशांश __cdecl atanhf(दशांश x) { परत atanh(x); }

__CRT_INLINE दीर्घ द्विगुण __cdecl asinhl(दीर्घ द्विगुण x) { परत asinh(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl acoshl(दीर्घ द्विगुण x) { परत acosh(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl atanhl(दीर्घ द्विगुण x) { परत atanh(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl asinl(दीर्घ द्विगुण x) { परत asin(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl acosl(दीर्घ द्विगुण x) { परत acos(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl atanl(दीर्घ द्विगुण x) { परत atan(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl ceill(दीर्घ द्विगुण x) { परत उच्चमान(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl coshl(दीर्घ द्विगुण x) { परत cosh(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl cosl(दीर्घ द्विगुण x) { परत cos(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl expl(दीर्घ द्विगुण x) { परत exp(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl floorl(दीर्घ द्विगुण x) { परत न्यूनमान(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl fmodl(दीर्घ द्विगुण x, दीर्घ द्विगुण y) { परत भ_शेष(x, y); }
__CRT_INLINE दीर्घ द्विगुण __cdecl hypotl(दीर्घ द्विगुण x, दीर्घ द्विगुण y) { परत hypot(x, y); }
__CRT_INLINE दीर्घ द्विगुण __cdecl logl(दीर्घ द्विगुण x) { परत log(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl logbl(दीर्घ द्विगुण x) { परत logb(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl log10l(दीर्घ द्विगुण x) { परत log10(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl modfl(दीर्घ द्विगुण x, दीर्घ द्विगुण* y) { द्विगुण y1 = *y; x = modf(x, &y1); *y = y1; परत x; }
__CRT_INLINE दीर्घ द्विगुण __cdecl powl(दीर्घ द्विगुण x, दीर्घ द्विगुण y) { परत घात(x, y); }
__CRT_INLINE दीर्घ द्विगुण __cdecl sinhl(दीर्घ द्विगुण x) { परत sinh(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl sinl(दीर्घ द्विगुण x) { परत sin(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl sqrtl(दीर्घ द्विगुण x) { परत वर्ग_मूल(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl tanhl(दीर्घ द्विगुण x) { परत tanh(x); }
__CRT_INLINE दीर्घ द्विगुण __cdecl tanl(दीर्घ द्विगुण x) { परत tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE द्विगुण __cdecl log1p(द्विगुण x) {
  द्विगुण u = 1.0 + x;
  परत u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE दशांश __cdecl log1pf(दशांश x) {
  दशांश u = 1.0f + x;
  परत u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE दीर्घ द्विगुण __cdecl log1pl(दीर्घ द्विगुण x) {
  परत log1p(x);
}


__CRT_INLINE द्विगुण __cdecl expm1(द्विगुण x) {
  जर (x > 0.0024 || x < -0.0024) परत exp(x) - 1.0;
  परत x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE दशांश __cdecl expm1f(दशांश x) {
  जर (x > 0.085f || x < -0.085f) परत expf(x) - 1.0f;
  परत x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE दीर्घ द्विगुण __cdecl expm1l(दीर्घ द्विगुण x) {
  परत expm1(x);
}


__CRT_INLINE द्विगुण __cdecl cbrt(द्विगुण x) {
  परत x < 0.0 ? -घात(-x, 1/3.0) : घात(x, 1/3.0);
}
__CRT_INLINE दशांश __cdecl cbrtf(दशांश x) {
  परत x < 0.0f ? -घात(-x, 1/3.0) : घात(x, 1/3.0);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl cbrtl(दीर्घ द्विगुण x) {
  परत cbrt(x);
}


__CRT_INLINE द्विगुण __cdecl log2(द्विगुण x) {
  परत log(x) * 1.442695040888963407;
}
__CRT_INLINE दशांश __cdecl log2f(दशांश x) {
  परत log(x) * 1.442695040888963407;
}
__CRT_INLINE दीर्घ द्विगुण __cdecl log2l(दीर्घ द्विगुण x) {
  परत log(x) * 1.442695040888963407;
}


__CRT_INLINE द्विगुण __cdecl exp2(द्विगुण x) {
  परत exp(x * 0.693147180559945309);
}
__CRT_INLINE दशांश __cdecl exp2f(दशांश x) {
  परत exp(x * 0.693147180559945309);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl exp2l(दीर्घ द्विगुण x) {
  परत exp(x * 0.693147180559945309);
}


__CRT_INLINE पूर्णांक __cdecl ilogb(द्विगुण x) {
  परत (पूर्णांक) logb(x);
}
__CRT_INLINE पूर्णांक __cdecl ilogbf(दशांश x) {
  परत (पूर्णांक) logbf(x);
}
__CRT_INLINE पूर्णांक __cdecl ilogbl(दीर्घ द्विगुण x) {
  परत (पूर्णांक) logb(x);
}


__CRT_INLINE द्विगुण __cdecl fdim(द्विगुण x, द्विगुण y) {
  जर (isnan(x) || isnan(y)) परत न_अंक;
  परत x > y ? x - y : 0;
}
__CRT_INLINE दशांश __cdecl fdimf(दशांश x, दशांश y) {
  जर (isnan(x) || isnan(y)) परत न_अंक;
  परत x > y ? x - y : 0;
}
__CRT_INLINE दीर्घ द्विगुण __cdecl fdiml(दीर्घ द्विगुण x, दीर्घ द्विगुण y) {
  जर (isnan(x) || isnan(y)) परत न_अंक;
  परत x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE द्विगुण __cdecl tgamma(द्विगुण x) {
  द्विगुण m = 1.0, t = 3.14159265358979323;
  जर (x == न्यूनमान(x)) {
    जर (x == 0) परत अनन्त;
    जर (x < 0) परत न_अंक;
    जर (x < 26) { साठी (द्विगुण k = 2; k < x; ++k) m *= k; परत m; }
  }
  जर (x < 0.5)
    परत t / (sin(t*x)*tgamma(1.0 - x));
  जर (x > 12.0)
    परत exp(lgamma(x));

  स्थिर स्थिरांक द्विगुण c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  साठी (पूर्णांक k = 0; k < 8; ++k) m += c[k] / (x + k);
  परत 2.50662827463100050 * घात(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE द्विगुण __cdecl lgamma(द्विगुण x) {
  जर (x < 12.0) {
    जर (x <= 0.0 && x == न्यूनमान(x)) परत अनन्त;
    x = tgamma(x);
    परत log(x < 0.0 ? -x : x);
  }
  स्थिर स्थिरांक द्विगुण c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  द्विगुण m = -3617.0/122400.0, t = 1.0 / (x*x);
  साठी (पूर्णांक k = 6; k >= 0; --k) m = m*t + c[k];
  परत (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE दशांश __cdecl tgammaf(दशांश x) {
  परत tgamma(x);
}
__CRT_INLINE दशांश __cdecl lgammaf(दशांश x) {
  परत lgamma(x);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl tgammal(दीर्घ द्विगुण x) {
  परत tgamma(x);
}
__CRT_INLINE दीर्घ द्विगुण __cdecl lgammal(दीर्घ द्विगुण x) {
  परत lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
