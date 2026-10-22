#अगर_अघोषित _TCC_LIBM_H_
#घोषणा _TCC_LIBM_H_

#समावेश "../math.h"
#समावेश "../stdint.h"

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

__CRT_INLINE पूर्णांक __cdecl __fpclassify (द्विगुन x) {
  जोड़ {द्विगुन f; uint64_t i;} u = {.f = x};
  पूर्णांक e = u.i>>52 & 0x7ff;
  अगर (!e) वापस u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  अगर (e==0x7ff) वापस u.i<<12 ? FP_NAN : FP_INFINITE;
  वापस FP_NORMAL;
}

__CRT_INLINE पूर्णांक __cdecl __fpclassifyf (भग्न x) {
  जोड़ {भग्न f; uint32_t i;} u = {.f = x};
  पूर्णांक e = u.i>>23 & 0xff;
  अगर (!e) वापस u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  अगर (e==0xff) वापस u.i<<9 ? FP_NAN : FP_INFINITE;
  वापस FP_NORMAL;
}

__CRT_INLINE पूर्णांक __cdecl __fpclassifyl (दीर्घ द्विगुन x) {
  वापस __fpclassify(x);
}


/* signbit */

__CRT_INLINE पूर्णांक __cdecl __signbit (द्विगुन x) {
  जोड़ {द्विगुन f; uint64_t i;} u = {.f = x};
  वापस u.i>>63;
}

__CRT_INLINE पूर्णांक __cdecl __signbitf (भग्न x) {
  जोड़ {भग्न f; uint32_t i; } u = {.f = x};
  वापस u.i>>31;
}

__CRT_INLINE पूर्णांक __cdecl __signbitl (दीर्घ द्विगुन x) {
  वापस __signbit(x);
}


/* fmin*, fmax* */

#घोषणा TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE द्विगुन __cdecl fmin (द्विगुन x, द्विगुन y) {
  वापस TCCFP_FMIN_EVAL;
}

__CRT_INLINE भग्न __cdecl fminf (भग्न x, भग्न y) {
  वापस TCCFP_FMIN_EVAL;
}

__CRT_INLINE दीर्घ द्विगुन __cdecl fminl (दीर्घ द्विगुन x, दीर्घ द्विगुन y) {
  वापस TCCFP_FMIN_EVAL;
}

#घोषणा TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE द्विगुन __cdecl fmax (द्विगुन x, द्विगुन y) {
  वापस TCCFP_FMAX_EVAL;
}

__CRT_INLINE भग्न __cdecl fmaxf (भग्न x, भग्न y) {
  वापस TCCFP_FMAX_EVAL;
}

__CRT_INLINE दीर्घ द्विगुन __cdecl fmaxl (दीर्घ द्विगुन x, दीर्घ द्विगुन y) {
  वापस TCCFP_FMAX_EVAL;
}


/* *round* */

#घोषणा TCCFP_FORCE_EVAL(x) करो {  \
  अस्थिर typeof(x) __x;         \
  __x = (x);                      \
} जबतक(0)

__CRT_INLINE द्विगुन __cdecl round (द्विगुन x) {
  जोड़ {द्विगुन f; uint64_t i;} u = {.f = x};
  पूर्णांक e = u.i >> 52 & 0x7ff;
  द्विगुन y;

  अगर (e >= 0x3ff+52)
    वापस x;
  अगर (u.i >> 63)
    x = -x;
  अगर (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    वापस 0*u.f;
  }
  y = (द्विगुन)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  वापस (u.i >> 63) ? -y : y;
}

__CRT_INLINE दीर्घ __cdecl lround (द्विगुन x) {
  वापस round(x);
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llround (द्विगुन x) {
  वापस round(x);
}

__CRT_INLINE भग्न __cdecl roundf (भग्न x) {
  वापस round(x);
}

__CRT_INLINE दीर्घ __cdecl lroundf (भग्न x) {
  वापस round(x);
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llroundf (भग्न x) {
  वापस round(x);
}

__CRT_INLINE दीर्घ द्विगुन __cdecl roundl (दीर्घ द्विगुन x) {
  वापस round(x);
}

__CRT_INLINE दीर्घ __cdecl lroundl (दीर्घ द्विगुन x) {
  वापस round(x);
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llroundl (दीर्घ द्विगुन x) {
  वापस round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE द्विगुन __cdecl asinh(द्विगुन x) {
  जोड़ {द्विगुन f; uint64_t i;} u = {.f = x};
  अचिन्हित e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  अगर (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  अन्यथा अगर (e >= 0x3ff + 1) x = log(2*x + 1 / (वर्ग_मूल(x*x + 1) + x)); /* |x|>=2 */
  अन्यथा अगर (e >= 0x3ff - 26) x = log1p(x + x*x / (वर्ग_मूल(x*x + 1) + 1));
  अन्यथा TCCFP_FORCE_EVAL(x + 0x1p120f);
  वापस s ? -x : x;
}

__CRT_INLINE द्विगुन __cdecl acosh(द्विगुन x) {
  जोड़ {द्विगुन f; uint64_t i;} u = {.f = x};
  अचिन्हित e = u.i >> 52 & 0x7ff;
  अगर (e < 0x3ff + 1) वापस --x, log1p(x + वर्ग_मूल(x*x + 2*x)); /* |x|<2 */
  अगर (e < 0x3ff + 26) वापस log(2*x - 1 / (x + वर्ग_मूल(x*x - 1)));
  वापस log(x) + 0.693147180559945309;
}

__CRT_INLINE द्विगुन __cdecl atanh(द्विगुन x) {
  जोड़ {द्विगुन f; uint64_t i;} u = {.f = x};
  अचिन्हित e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  अगर (e < 0x3ff - 1) {
    अगर (e < 0x3ff - 32) { अगर (e == 0) TCCFP_FORCE_EVAL((भग्न)x); }
    अन्यथा x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } अन्यथा x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  वापस s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE द्विगुन __cdecl scalbn(द्विगुन x, पूर्णांक n) {
  जोड़ {द्विगुन f; uint64_t i;} u;
  अगर (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    अगर (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      अगर (n > 1023) n = 1023;
    }
  } अन्यथा अगर (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    अगर (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      अगर (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  वापस x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE द्विगुन __cdecl frexp(द्विगुन x, पूर्णांक *e) {
  जोड़ {द्विगुन f; uint64_t i;} u = {.f = x};
  पूर्णांक ee = u.i>>52 & 0x7ff;
  अगर (!ee) {
    अगर (x) x = frexp(x*0x1p64, e), *e -= 64;
    अन्यथा *e = 0;
    वापस x;
  } अन्यथा अगर (ee == 0x7ff)
    वापस x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  वापस u.f;
}

/* MUSL nan */

__CRT_INLINE द्विगुन __cdecl nan(स्थिर अक्षर* s) {
  वापस न_अंक;
}
__CRT_INLINE भग्न __cdecl nanf(स्थिर अक्षर* s) {
  वापस न_अंक;
}
__CRT_INLINE दीर्घ द्विगुन __cdecl nanl(स्थिर अक्षर* s) {
  वापस न_अंक;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE भग्न __cdecl scalbnf(भग्न x, पूर्णांक n) {
  वापस scalbn(x, n);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl scalbnl(दीर्घ द्विगुन x, पूर्णांक n) {
  वापस scalbn(x, n);
}

__CRT_INLINE द्विगुन __cdecl scalbln(द्विगुन x, दीर्घ n) {
  वापस scalbn(x, n);
}
__CRT_INLINE भग्न __cdecl scalblnf(भग्न x, दीर्घ n) {
  वापस scalbn(x, n);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl scalblnl(दीर्घ द्विगुन x, दीर्घ n) {
  वापस scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE द्विगुन __cdecl ldexp(द्विगुन x, पूर्णांक expn) {
  वापस scalbn(x, expn);
}
__CRT_INLINE भग्न __cdecl ldexpf(भग्न x, पूर्णांक expn) {
  वापस scalbn(x, expn);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl ldexpl(दीर्घ द्विगुन x, पूर्णांक expn) {
  वापस scalbn(x, expn);
}

__CRT_INLINE भग्न __cdecl frexpf(भग्न x, पूर्णांक *y) {
  वापस frexp(x, y);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl frexpl (दीर्घ द्विगुन x, पूर्णांक* y) {
  वापस frexp(x, y);
}


__CRT_INLINE द्विगुन __cdecl rint(द्विगुन x) {
द्विगुन retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  वापस retval;
}

__CRT_INLINE भग्न __cdecl rintf(भग्न x) {
  भग्न retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   वापस retval;
}
__CRT_INLINE दीर्घ द्विगुन __cdecl rintl (दीर्घ द्विगुन x) {
  वापस rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE दीर्घ __cdecl lrint(द्विगुन x) {
  दीर्घ retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  वापस retval;
}

__CRT_INLINE दीर्घ __cdecl lrintf(भग्न x) {
  दीर्घ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  वापस retval;
}

__CRT_INLINE दीर्घ __cdecl lrintl (दीर्घ द्विगुन x) {
  वापस lrint(x);
}


__CRT_INLINE दीर्घ दीर्घ __cdecl llrint(द्विगुन x) {
दीर्घ दीर्घ retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  वापस retval;
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llrintf(भग्न x) {
  दीर्घ दीर्घ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  वापस retval;
}

__CRT_INLINE दीर्घ दीर्घ __cdecl llrintl (दीर्घ द्विगुन x) {
  वापस llrint(x);
}


__CRT_INLINE द्विगुन __cdecl trunc(द्विगुन _x) {
  द्विगुन retval;
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
  वापस retval;
}

__CRT_INLINE भग्न __cdecl truncf(भग्न x) {
  वापस (भग्न) ((intptr_t) x);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl truncl(दीर्घ द्विगुन x) {
  वापस trunc(x);
}


__CRT_INLINE दीर्घ द्विगुन __cdecl nextafterl(दीर्घ द्विगुन x, दीर्घ द्विगुन to) {
  वापस nextafter(x, to);
}

__CRT_INLINE द्विगुन __cdecl nexttoward(द्विगुन x, दीर्घ द्विगुन to) {
  वापस nextafter(x, to);
}
__CRT_INLINE भग्न __cdecl nexttowardf(भग्न x, दीर्घ द्विगुन to) {
  वापस nextafterf(x, to);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl nexttowardl(दीर्घ द्विगुन x, दीर्घ द्विगुन to) {
  वापस nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE द्विगुन __cdecl भ_असल(द्विगुन x) {
  वापस x < 0 ? -x : x;
}
__CRT_INLINE भग्न __cdecl fabsf(भग्न x) {
  वापस x < 0 ? -x : x;
}
__CRT_INLINE दीर्घ द्विगुन __cdecl fabsl(दीर्घ द्विगुन x) {
  वापस x < 0 ? -x : x;
}


#अगर defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE भग्न acosf(भग्न x) { वापस acos(x); }
  __CRT_INLINE भग्न asinf(भग्न x) { वापस asin(x); }
  __CRT_INLINE भग्न atanf(भग्न x) { वापस atan(x); }
  __CRT_INLINE भग्न atan2f(भग्न x, भग्न y) { वापस atan2(x, y); }
  __CRT_INLINE भग्न ceilf(भग्न x) { वापस उच्चमान(x); }
  __CRT_INLINE भग्न cosf(भग्न x) { वापस cos(x); }
  __CRT_INLINE भग्न coshf(भग्न x) { वापस cosh(x); }
  __CRT_INLINE भग्न expf(भग्न x) { वापस exp(x); }
  __CRT_INLINE भग्न floorf(भग्न x) { वापस न्यूनमान(x); }
  __CRT_INLINE भग्न fmodf(भग्न x, भग्न y) { वापस भ_शेष(x, y); }
  __CRT_INLINE भग्न logf(भग्न x) { वापस log(x); }
  __CRT_INLINE भग्न logbf(भग्न x) { वापस logb(x); }
  __CRT_INLINE भग्न log10f(भग्न x) { वापस log10(x); }
  __CRT_INLINE भग्न modff(भग्न x, भग्न *y) { द्विगुन di, df = modf(x, &di); *y = di; वापस df; }
  __CRT_INLINE भग्न powf(भग्न x, भग्न y) { वापस घात(x, y); }
  __CRT_INLINE भग्न sinf(भग्न x) { वापस sin(x); }
  __CRT_INLINE भग्न sinhf(भग्न x) { वापस sinh(x); }
  __CRT_INLINE भग्न sqrtf(भग्न x) { वापस वर्ग_मूल(x); }
  __CRT_INLINE भग्न tanf(भग्न x) { वापस tan(x); }
  __CRT_INLINE भग्न tanhf(भग्न x) { वापस tanh(x); }
#पूर्ण_अगर
__CRT_INLINE भग्न __cdecl asinhf(भग्न x) { वापस asinh(x); }
__CRT_INLINE भग्न __cdecl acoshf(भग्न x) { वापस acosh(x); }
__CRT_INLINE भग्न __cdecl atanhf(भग्न x) { वापस atanh(x); }

__CRT_INLINE दीर्घ द्विगुन __cdecl asinhl(दीर्घ द्विगुन x) { वापस asinh(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl acoshl(दीर्घ द्विगुन x) { वापस acosh(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl atanhl(दीर्घ द्विगुन x) { वापस atanh(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl asinl(दीर्घ द्विगुन x) { वापस asin(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl acosl(दीर्घ द्विगुन x) { वापस acos(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl atanl(दीर्घ द्विगुन x) { वापस atan(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl ceill(दीर्घ द्विगुन x) { वापस उच्चमान(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl coshl(दीर्घ द्विगुन x) { वापस cosh(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl cosl(दीर्घ द्विगुन x) { वापस cos(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl expl(दीर्घ द्विगुन x) { वापस exp(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl floorl(दीर्घ द्विगुन x) { वापस न्यूनमान(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl fmodl(दीर्घ द्विगुन x, दीर्घ द्विगुन y) { वापस भ_शेष(x, y); }
__CRT_INLINE दीर्घ द्विगुन __cdecl hypotl(दीर्घ द्विगुन x, दीर्घ द्विगुन y) { वापस hypot(x, y); }
__CRT_INLINE दीर्घ द्विगुन __cdecl logl(दीर्घ द्विगुन x) { वापस log(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl logbl(दीर्घ द्विगुन x) { वापस logb(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl log10l(दीर्घ द्विगुन x) { वापस log10(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl modfl(दीर्घ द्विगुन x, दीर्घ द्विगुन* y) { द्विगुन y1 = *y; x = modf(x, &y1); *y = y1; वापस x; }
__CRT_INLINE दीर्घ द्विगुन __cdecl powl(दीर्घ द्विगुन x, दीर्घ द्विगुन y) { वापस घात(x, y); }
__CRT_INLINE दीर्घ द्विगुन __cdecl sinhl(दीर्घ द्विगुन x) { वापस sinh(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl sinl(दीर्घ द्विगुन x) { वापस sin(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl sqrtl(दीर्घ द्विगुन x) { वापस वर्ग_मूल(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl tanhl(दीर्घ द्विगुन x) { वापस tanh(x); }
__CRT_INLINE दीर्घ द्विगुन __cdecl tanl(दीर्घ द्विगुन x) { वापस tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE द्विगुन __cdecl log1p(द्विगुन x) {
  द्विगुन u = 1.0 + x;
  वापस u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE भग्न __cdecl log1pf(भग्न x) {
  भग्न u = 1.0f + x;
  वापस u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE दीर्घ द्विगुन __cdecl log1pl(दीर्घ द्विगुन x) {
  वापस log1p(x);
}


__CRT_INLINE द्विगुन __cdecl expm1(द्विगुन x) {
  अगर (x > 0.0024 || x < -0.0024) वापस exp(x) - 1.0;
  वापस x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE भग्न __cdecl expm1f(भग्न x) {
  अगर (x > 0.085f || x < -0.085f) वापस expf(x) - 1.0f;
  वापस x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE दीर्घ द्विगुन __cdecl expm1l(दीर्घ द्विगुन x) {
  वापस expm1(x);
}


__CRT_INLINE द्विगुन __cdecl cbrt(द्विगुन x) {
  वापस x < 0.0 ? -घात(-x, 1/3.0) : घात(x, 1/3.0);
}
__CRT_INLINE भग्न __cdecl cbrtf(भग्न x) {
  वापस x < 0.0f ? -घात(-x, 1/3.0) : घात(x, 1/3.0);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl cbrtl(दीर्घ द्विगुन x) {
  वापस cbrt(x);
}


__CRT_INLINE द्विगुन __cdecl log2(द्विगुन x) {
  वापस log(x) * 1.442695040888963407;
}
__CRT_INLINE भग्न __cdecl log2f(भग्न x) {
  वापस log(x) * 1.442695040888963407;
}
__CRT_INLINE दीर्घ द्विगुन __cdecl log2l(दीर्घ द्विगुन x) {
  वापस log(x) * 1.442695040888963407;
}


__CRT_INLINE द्विगुन __cdecl exp2(द्विगुन x) {
  वापस exp(x * 0.693147180559945309);
}
__CRT_INLINE भग्न __cdecl exp2f(भग्न x) {
  वापस exp(x * 0.693147180559945309);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl exp2l(दीर्घ द्विगुन x) {
  वापस exp(x * 0.693147180559945309);
}


__CRT_INLINE पूर्णांक __cdecl ilogb(द्विगुन x) {
  वापस (पूर्णांक) logb(x);
}
__CRT_INLINE पूर्णांक __cdecl ilogbf(भग्न x) {
  वापस (पूर्णांक) logbf(x);
}
__CRT_INLINE पूर्णांक __cdecl ilogbl(दीर्घ द्विगुन x) {
  वापस (पूर्णांक) logb(x);
}


__CRT_INLINE द्विगुन __cdecl fdim(द्विगुन x, द्विगुन y) {
  अगर (isnan(x) || isnan(y)) वापस न_अंक;
  वापस x > y ? x - y : 0;
}
__CRT_INLINE भग्न __cdecl fdimf(भग्न x, भग्न y) {
  अगर (isnan(x) || isnan(y)) वापस न_अंक;
  वापस x > y ? x - y : 0;
}
__CRT_INLINE दीर्घ द्विगुन __cdecl fdiml(दीर्घ द्विगुन x, दीर्घ द्विगुन y) {
  अगर (isnan(x) || isnan(y)) वापस न_अंक;
  वापस x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE द्विगुन __cdecl tgamma(द्विगुन x) {
  द्विगुन m = 1.0, t = 3.14159265358979323;
  अगर (x == न्यूनमान(x)) {
    अगर (x == 0) वापस अनन्त;
    अगर (x < 0) वापस न_अंक;
    अगर (x < 26) { क्रम (द्विगुन k = 2; k < x; ++k) m *= k; वापस m; }
  }
  अगर (x < 0.5)
    वापस t / (sin(t*x)*tgamma(1.0 - x));
  अगर (x > 12.0)
    वापस exp(lgamma(x));

  अटल स्थिर द्विगुन c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  क्रम (पूर्णांक k = 0; k < 8; ++k) m += c[k] / (x + k);
  वापस 2.50662827463100050 * घात(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE द्विगुन __cdecl lgamma(द्विगुन x) {
  अगर (x < 12.0) {
    अगर (x <= 0.0 && x == न्यूनमान(x)) वापस अनन्त;
    x = tgamma(x);
    वापस log(x < 0.0 ? -x : x);
  }
  अटल स्थिर द्विगुन c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  द्विगुन m = -3617.0/122400.0, t = 1.0 / (x*x);
  क्रम (पूर्णांक k = 6; k >= 0; --k) m = m*t + c[k];
  वापस (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE भग्न __cdecl tgammaf(भग्न x) {
  वापस tgamma(x);
}
__CRT_INLINE भग्न __cdecl lgammaf(भग्न x) {
  वापस lgamma(x);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl tgammal(दीर्घ द्विगुन x) {
  वापस tgamma(x);
}
__CRT_INLINE दीर्घ द्विगुन __cdecl lgammal(दीर्घ द्विगुन x) {
  वापस lgamma(x);
}

#पूर्ण_अगर /* _TCC_LIBM_H_ */
