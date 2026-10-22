#నిర్వచితం_కాకపోతే _TCC_LIBM_H_
#నిర్వచించు _TCC_LIBM_H_

#అన్తర్భావ "../math.h"
#అన్తర్భావ "../stdint.h"

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

__CRT_INLINE పూర్ణాంకం __cdecl __fpclassify (ద్విగుణ x) {
  సంఘం {ద్విగుణ f; uint64_t i;} u = {.f = x};
  పూర్ణాంకం e = u.i>>52 & 0x7ff;
  ఒకవేళ (!e) తిరిగి u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ఒకవేళ (e==0x7ff) తిరిగి u.i<<12 ? FP_NAN : FP_INFINITE;
  తిరిగి FP_NORMAL;
}

__CRT_INLINE పూర్ణాంకం __cdecl __fpclassifyf (దశాంశం x) {
  సంఘం {దశాంశం f; uint32_t i;} u = {.f = x};
  పూర్ణాంకం e = u.i>>23 & 0xff;
  ఒకవేళ (!e) తిరిగి u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  ఒకవేళ (e==0xff) తిరిగి u.i<<9 ? FP_NAN : FP_INFINITE;
  తిరిగి FP_NORMAL;
}

__CRT_INLINE పూర్ణాంకం __cdecl __fpclassifyl (దీర్ఘ ద్విగుణ x) {
  తిరిగి __fpclassify(x);
}


/* signbit */

__CRT_INLINE పూర్ణాంకం __cdecl __signbit (ద్విగుణ x) {
  సంఘం {ద్విగుణ f; uint64_t i;} u = {.f = x};
  తిరిగి u.i>>63;
}

__CRT_INLINE పూర్ణాంకం __cdecl __signbitf (దశాంశం x) {
  సంఘం {దశాంశం f; uint32_t i; } u = {.f = x};
  తిరిగి u.i>>31;
}

__CRT_INLINE పూర్ణాంకం __cdecl __signbitl (దీర్ఘ ద్విగుణ x) {
  తిరిగి __signbit(x);
}


/* fmin*, fmax* */

#నిర్వచించు TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE ద్విగుణ __cdecl fmin (ద్విగుణ x, ద్విగుణ y) {
  తిరిగి TCCFP_FMIN_EVAL;
}

__CRT_INLINE దశాంశం __cdecl fminf (దశాంశం x, దశాంశం y) {
  తిరిగి TCCFP_FMIN_EVAL;
}

__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl fminl (దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ y) {
  తిరిగి TCCFP_FMIN_EVAL;
}

#నిర్వచించు TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE ద్విగుణ __cdecl fmax (ద్విగుణ x, ద్విగుణ y) {
  తిరిగి TCCFP_FMAX_EVAL;
}

__CRT_INLINE దశాంశం __cdecl fmaxf (దశాంశం x, దశాంశం y) {
  తిరిగి TCCFP_FMAX_EVAL;
}

__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl fmaxl (దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ y) {
  తిరిగి TCCFP_FMAX_EVAL;
}


/* *round* */

#నిర్వచించు TCCFP_FORCE_EVAL(x) చేయి {  \
  అస్థిర typeof(x) __x;         \
  __x = (x);                      \
} అయితే(0)

__CRT_INLINE ద్విగుణ __cdecl విడత (ద్విగుణ x) {
  సంఘం {ద్విగుణ f; uint64_t i;} u = {.f = x};
  పూర్ణాంకం e = u.i >> 52 & 0x7ff;
  ద్విగుణ y;

  ఒకవేళ (e >= 0x3ff+52)
    తిరిగి x;
  ఒకవేళ (u.i >> 63)
    x = -x;
  ఒకవేళ (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    తిరిగి 0*u.f;
  }
  y = (ద్విగుణ)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  తిరిగి (u.i >> 63) ? -y : y;
}

__CRT_INLINE దీర్ఘ __cdecl lround (ద్విగుణ x) {
  తిరిగి విడత(x);
}

__CRT_INLINE దీర్ఘ దీర్ఘ __cdecl llround (ద్విగుణ x) {
  తిరిగి విడత(x);
}

__CRT_INLINE దశాంశం __cdecl roundf (దశాంశం x) {
  తిరిగి విడత(x);
}

__CRT_INLINE దీర్ఘ __cdecl lroundf (దశాంశం x) {
  తిరిగి విడత(x);
}

__CRT_INLINE దీర్ఘ దీర్ఘ __cdecl llroundf (దశాంశం x) {
  తిరిగి విడత(x);
}

__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl roundl (దీర్ఘ ద్విగుణ x) {
  తిరిగి విడత(x);
}

__CRT_INLINE దీర్ఘ __cdecl lroundl (దీర్ఘ ద్విగుణ x) {
  తిరిగి విడత(x);
}

__CRT_INLINE దీర్ఘ దీర్ఘ __cdecl llroundl (దీర్ఘ ద్విగుణ x) {
  తిరిగి విడత(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE ద్విగుణ __cdecl asinh(ద్విగుణ x) {
  సంఘం {ద్విగుణ f; uint64_t i;} u = {.f = x};
  గుర్తులేని e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ఒకవేళ (e >= 0x3ff + 26) x = సంవర్గమానం(x) + 0.693147180559945309;
  లేకపోతే ఒకవేళ (e >= 0x3ff + 1) x = సంవర్గమానం(2*x + 1 / (వర్గమూలం(x*x + 1) + x)); /* |x|>=2 */
  లేకపోతే ఒకవేళ (e >= 0x3ff - 26) x = log1p(x + x*x / (వర్గమూలం(x*x + 1) + 1));
  లేకపోతే TCCFP_FORCE_EVAL(x + 0x1p120f);
  తిరిగి s ? -x : x;
}

__CRT_INLINE ద్విగుణ __cdecl acosh(ద్విగుణ x) {
  సంఘం {ద్విగుణ f; uint64_t i;} u = {.f = x};
  గుర్తులేని e = u.i >> 52 & 0x7ff;
  ఒకవేళ (e < 0x3ff + 1) తిరిగి --x, log1p(x + వర్గమూలం(x*x + 2*x)); /* |x|<2 */
  ఒకవేళ (e < 0x3ff + 26) తిరిగి సంవర్గమానం(2*x - 1 / (x + వర్గమూలం(x*x - 1)));
  తిరిగి సంవర్గమానం(x) + 0.693147180559945309;
}

__CRT_INLINE ద్విగుణ __cdecl atanh(ద్విగుణ x) {
  సంఘం {ద్విగుణ f; uint64_t i;} u = {.f = x};
  గుర్తులేని e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  ఒకవేళ (e < 0x3ff - 1) {
    ఒకవేళ (e < 0x3ff - 32) { ఒకవేళ (e == 0) TCCFP_FORCE_EVAL((దశాంశం)x); }
    లేకపోతే x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } లేకపోతే x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  తిరిగి s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE ద్విగుణ __cdecl scalbn(ద్విగుణ x, పూర్ణాంకం n) {
  సంఘం {ద్విగుణ f; uint64_t i;} u;
  ఒకవేళ (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    ఒకవేళ (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      ఒకవేళ (n > 1023) n = 1023;
    }
  } లేకపోతే ఒకవేళ (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    ఒకవేళ (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      ఒకవేళ (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  తిరిగి x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE ద్విగుణ __cdecl frexp(ద్విగుణ x, పూర్ణాంకం *e) {
  సంఘం {ద్విగుణ f; uint64_t i;} u = {.f = x};
  పూర్ణాంకం ee = u.i>>52 & 0x7ff;
  ఒకవేళ (!ee) {
    ఒకవేళ (x) x = frexp(x*0x1p64, e), *e -= 64;
    లేకపోతే *e = 0;
    తిరిగి x;
  } లేకపోతే ఒకవేళ (ee == 0x7ff)
    తిరిగి x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  తిరిగి u.f;
}

/* MUSL nan */

__CRT_INLINE ద్విగుణ __cdecl nan(స్థిరరాశి అక్షరం* s) {
  తిరిగి NAN;
}
__CRT_INLINE దశాంశం __cdecl nanf(స్థిరరాశి అక్షరం* s) {
  తిరిగి NAN;
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl nanl(స్థిరరాశి అక్షరం* s) {
  తిరిగి NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE దశాంశం __cdecl scalbnf(దశాంశం x, పూర్ణాంకం n) {
  తిరిగి scalbn(x, n);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl scalbnl(దీర్ఘ ద్విగుణ x, పూర్ణాంకం n) {
  తిరిగి scalbn(x, n);
}

__CRT_INLINE ద్విగుణ __cdecl scalbln(ద్విగుణ x, దీర్ఘ n) {
  తిరిగి scalbn(x, n);
}
__CRT_INLINE దశాంశం __cdecl scalblnf(దశాంశం x, దీర్ఘ n) {
  తిరిగి scalbn(x, n);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl scalblnl(దీర్ఘ ద్విగుణ x, దీర్ఘ n) {
  తిరిగి scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE ద్విగుణ __cdecl ldexp(ద్విగుణ x, పూర్ణాంకం expn) {
  తిరిగి scalbn(x, expn);
}
__CRT_INLINE దశాంశం __cdecl ldexpf(దశాంశం x, పూర్ణాంకం expn) {
  తిరిగి scalbn(x, expn);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl ldexpl(దీర్ఘ ద్విగుణ x, పూర్ణాంకం expn) {
  తిరిగి scalbn(x, expn);
}

__CRT_INLINE దశాంశం __cdecl frexpf(దశాంశం x, పూర్ణాంకం *y) {
  తిరిగి frexp(x, y);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl frexpl (దీర్ఘ ద్విగుణ x, పూర్ణాంకం* y) {
  తిరిగి frexp(x, y);
}


__CRT_INLINE ద్విగుణ __cdecl rint(ద్విగుణ x) {
ద్విగుణ retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  తిరిగి retval;
}

__CRT_INLINE దశాంశం __cdecl rintf(దశాంశం x) {
  దశాంశం retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   తిరిగి retval;
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl rintl (దీర్ఘ ద్విగుణ x) {
  తిరిగి rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE దీర్ఘ __cdecl lrint(ద్విగుణ x) {
  దీర్ఘ retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  తిరిగి retval;
}

__CRT_INLINE దీర్ఘ __cdecl lrintf(దశాంశం x) {
  దీర్ఘ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  తిరిగి retval;
}

__CRT_INLINE దీర్ఘ __cdecl lrintl (దీర్ఘ ద్విగుణ x) {
  తిరిగి lrint(x);
}


__CRT_INLINE దీర్ఘ దీర్ఘ __cdecl llrint(ద్విగుణ x) {
దీర్ఘ దీర్ఘ retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  తిరిగి retval;
}

__CRT_INLINE దీర్ఘ దీర్ఘ __cdecl llrintf(దశాంశం x) {
  దీర్ఘ దీర్ఘ retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  తిరిగి retval;
}

__CRT_INLINE దీర్ఘ దీర్ఘ __cdecl llrintl (దీర్ఘ ద్విగుణ x) {
  తిరిగి llrint(x);
}


__CRT_INLINE ద్విగుణ __cdecl trunc(ద్విగుణ _x) {
  ద్విగుణ retval;
  గుర్తులేని పొట్టి saved_cw;
  గుర్తులేని పొట్టి tmp_cw;
  __asm__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
  tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
    | FE_TOWARDZERO;
  __asm__ ("fldcw %0;" : : "m" (tmp_cw));
  __asm__ ("fldl  %1;"
           "frndint;"
           "fstpl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
  __asm__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
  తిరిగి retval;
}

__CRT_INLINE దశాంశం __cdecl truncf(దశాంశం x) {
  తిరిగి (దశాంశం) ((intptr_t) x);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl truncl(దీర్ఘ ద్విగుణ x) {
  తిరిగి trunc(x);
}


__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl nextafterl(దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ గమ్యం) {
  తిరిగి nextafter(x, గమ్యం);
}

__CRT_INLINE ద్విగుణ __cdecl nexttoward(ద్విగుణ x, దీర్ఘ ద్విగుణ గమ్యం) {
  తిరిగి nextafter(x, గమ్యం);
}
__CRT_INLINE దశాంశం __cdecl nexttowardf(దశాంశం x, దీర్ఘ ద్విగుణ గమ్యం) {
  తిరిగి nextafterf(x, గమ్యం);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl nexttowardl(దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ గమ్యం) {
  తిరిగి nextafter(x, గమ్యం);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE ద్విగుణ __cdecl fabs(ద్విగుణ x) {
  తిరిగి x < 0 ? -x : x;
}
__CRT_INLINE దశాంశం __cdecl fabsf(దశాంశం x) {
  తిరిగి x < 0 ? -x : x;
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl fabsl(దీర్ఘ ద్విగుణ x) {
  తిరిగి x < 0 ? -x : x;
}


#ఒకవేళ defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE దశాంశం acosf(దశాంశం x) { తిరిగి acos(x); }
  __CRT_INLINE దశాంశం asinf(దశాంశం x) { తిరిగి asin(x); }
  __CRT_INLINE దశాంశం atanf(దశాంశం x) { తిరిగి atan(x); }
  __CRT_INLINE దశాంశం atan2f(దశాంశం x, దశాంశం y) { తిరిగి atan2(x, y); }
  __CRT_INLINE దశాంశం ceilf(దశాంశం x) { తిరిగి ceil(x); }
  __CRT_INLINE దశాంశం cosf(దశాంశం x) { తిరిగి కోజ్యా(x); }
  __CRT_INLINE దశాంశం coshf(దశాంశం x) { తిరిగి cosh(x); }
  __CRT_INLINE దశాంశం expf(దశాంశం x) { తిరిగి ఘాతాంకం(x); }
  __CRT_INLINE దశాంశం floorf(దశాంశం x) { తిరిగి floor(x); }
  __CRT_INLINE దశాంశం fmodf(దశాంశం x, దశాంశం y) { తిరిగి fmod(x, y); }
  __CRT_INLINE దశాంశం logf(దశాంశం x) { తిరిగి సంవర్గమానం(x); }
  __CRT_INLINE దశాంశం logbf(దశాంశం x) { తిరిగి logb(x); }
  __CRT_INLINE దశాంశం log10f(దశాంశం x) { తిరిగి log10(x); }
  __CRT_INLINE దశాంశం modff(దశాంశం x, దశాంశం *y) { ద్విగుణ di, df = modf(x, &di); *y = di; తిరిగి df; }
  __CRT_INLINE దశాంశం powf(దశాంశం x, దశాంశం y) { తిరిగి ఘాతం(x, y); }
  __CRT_INLINE దశాంశం sinf(దశాంశం x) { తిరిగి జ్యా(x); }
  __CRT_INLINE దశాంశం sinhf(దశాంశం x) { తిరిగి sinh(x); }
  __CRT_INLINE దశాంశం sqrtf(దశాంశం x) { తిరిగి వర్గమూలం(x); }
  __CRT_INLINE దశాంశం tanf(దశాంశం x) { తిరిగి tan(x); }
  __CRT_INLINE దశాంశం tanhf(దశాంశం x) { తిరిగి tanh(x); }
#అయితే_ముగింపు
__CRT_INLINE దశాంశం __cdecl asinhf(దశాంశం x) { తిరిగి asinh(x); }
__CRT_INLINE దశాంశం __cdecl acoshf(దశాంశం x) { తిరిగి acosh(x); }
__CRT_INLINE దశాంశం __cdecl atanhf(దశాంశం x) { తిరిగి atanh(x); }

__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl asinhl(దీర్ఘ ద్విగుణ x) { తిరిగి asinh(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl acoshl(దీర్ఘ ద్విగుణ x) { తిరిగి acosh(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl atanhl(దీర్ఘ ద్విగుణ x) { తిరిగి atanh(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl asinl(దీర్ఘ ద్విగుణ x) { తిరిగి asin(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl acosl(దీర్ఘ ద్విగుణ x) { తిరిగి acos(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl atanl(దీర్ఘ ద్విగుణ x) { తిరిగి atan(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl ceill(దీర్ఘ ద్విగుణ x) { తిరిగి ceil(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl coshl(దీర్ఘ ద్విగుణ x) { తిరిగి cosh(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl cosl(దీర్ఘ ద్విగుణ x) { తిరిగి కోజ్యా(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl expl(దీర్ఘ ద్విగుణ x) { తిరిగి ఘాతాంకం(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl floorl(దీర్ఘ ద్విగుణ x) { తిరిగి floor(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl fmodl(దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ y) { తిరిగి fmod(x, y); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl hypotl(దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ y) { తిరిగి hypot(x, y); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl logl(దీర్ఘ ద్విగుణ x) { తిరిగి సంవర్గమానం(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl logbl(దీర్ఘ ద్విగుణ x) { తిరిగి logb(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl log10l(దీర్ఘ ద్విగుణ x) { తిరిగి log10(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl modfl(దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ* y) { ద్విగుణ y1 = *y; x = modf(x, &y1); *y = y1; తిరిగి x; }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl powl(దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ y) { తిరిగి ఘాతం(x, y); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl sinhl(దీర్ఘ ద్విగుణ x) { తిరిగి sinh(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl sinl(దీర్ఘ ద్విగుణ x) { తిరిగి జ్యా(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl sqrtl(దీర్ఘ ద్విగుణ x) { తిరిగి వర్గమూలం(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl tanhl(దీర్ఘ ద్విగుణ x) { తిరిగి tanh(x); }
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl tanl(దీర్ఘ ద్విగుణ x) { తిరిగి tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE ద్విగుణ __cdecl log1p(ద్విగుణ x) {
  ద్విగుణ u = 1.0 + x;
  తిరిగి u == 1.0 ? x : సంవర్గమానం(u)*(x / (u - 1.0));
}
__CRT_INLINE దశాంశం __cdecl log1pf(దశాంశం x) {
  దశాంశం u = 1.0f + x;
  తిరిగి u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl log1pl(దీర్ఘ ద్విగుణ x) {
  తిరిగి log1p(x);
}


__CRT_INLINE ద్విగుణ __cdecl expm1(ద్విగుణ x) {
  ఒకవేళ (x > 0.0024 || x < -0.0024) తిరిగి ఘాతాంకం(x) - 1.0;
  తిరిగి x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE దశాంశం __cdecl expm1f(దశాంశం x) {
  ఒకవేళ (x > 0.085f || x < -0.085f) తిరిగి expf(x) - 1.0f;
  తిరిగి x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl expm1l(దీర్ఘ ద్విగుణ x) {
  తిరిగి expm1(x);
}


__CRT_INLINE ద్విగుణ __cdecl cbrt(ద్విగుణ x) {
  తిరిగి x < 0.0 ? -ఘాతం(-x, 1/3.0) : ఘాతం(x, 1/3.0);
}
__CRT_INLINE దశాంశం __cdecl cbrtf(దశాంశం x) {
  తిరిగి x < 0.0f ? -ఘాతం(-x, 1/3.0) : ఘాతం(x, 1/3.0);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl cbrtl(దీర్ఘ ద్విగుణ x) {
  తిరిగి cbrt(x);
}


__CRT_INLINE ద్విగుణ __cdecl log2(ద్విగుణ x) {
  తిరిగి సంవర్గమానం(x) * 1.442695040888963407;
}
__CRT_INLINE దశాంశం __cdecl log2f(దశాంశం x) {
  తిరిగి సంవర్గమానం(x) * 1.442695040888963407;
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl log2l(దీర్ఘ ద్విగుణ x) {
  తిరిగి సంవర్గమానం(x) * 1.442695040888963407;
}


__CRT_INLINE ద్విగుణ __cdecl exp2(ద్విగుణ x) {
  తిరిగి ఘాతాంకం(x * 0.693147180559945309);
}
__CRT_INLINE దశాంశం __cdecl exp2f(దశాంశం x) {
  తిరిగి ఘాతాంకం(x * 0.693147180559945309);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl exp2l(దీర్ఘ ద్విగుణ x) {
  తిరిగి ఘాతాంకం(x * 0.693147180559945309);
}


__CRT_INLINE పూర్ణాంకం __cdecl ilogb(ద్విగుణ x) {
  తిరిగి (పూర్ణాంకం) logb(x);
}
__CRT_INLINE పూర్ణాంకం __cdecl ilogbf(దశాంశం x) {
  తిరిగి (పూర్ణాంకం) logbf(x);
}
__CRT_INLINE పూర్ణాంకం __cdecl ilogbl(దీర్ఘ ద్విగుణ x) {
  తిరిగి (పూర్ణాంకం) logb(x);
}


__CRT_INLINE ద్విగుణ __cdecl fdim(ద్విగుణ x, ద్విగుణ y) {
  ఒకవేళ (isnan(x) || isnan(y)) తిరిగి NAN;
  తిరిగి x > y ? x - y : 0;
}
__CRT_INLINE దశాంశం __cdecl fdimf(దశాంశం x, దశాంశం y) {
  ఒకవేళ (isnan(x) || isnan(y)) తిరిగి NAN;
  తిరిగి x > y ? x - y : 0;
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl fdiml(దీర్ఘ ద్విగుణ x, దీర్ఘ ద్విగుణ y) {
  ఒకవేళ (isnan(x) || isnan(y)) తిరిగి NAN;
  తిరిగి x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE ద్విగుణ __cdecl tgamma(ద్విగుణ x) {
  ద్విగుణ m = 1.0, t = 3.14159265358979323;
  ఒకవేళ (x == floor(x)) {
    ఒకవేళ (x == 0) తిరిగి INFINITY;
    ఒకవేళ (x < 0) తిరిగి NAN;
    ఒకవేళ (x < 26) { కొరకు (ద్విగుణ k = 2; k < x; ++k) m *= k; తిరిగి m; }
  }
  ఒకవేళ (x < 0.5)
    తిరిగి t / (జ్యా(t*x)*tgamma(1.0 - x));
  ఒకవేళ (x > 12.0)
    తిరిగి ఘాతాంకం(lgamma(x));

  స్థిర స్థిరరాశి ద్విగుణ c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  కొరకు (పూర్ణాంకం k = 0; k < 8; ++k) m += c[k] / (x + k);
  తిరిగి 2.50662827463100050 * ఘాతం(t, x - 0.5)*ఘాతాంకం(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE ద్విగుణ __cdecl lgamma(ద్విగుణ x) {
  ఒకవేళ (x < 12.0) {
    ఒకవేళ (x <= 0.0 && x == floor(x)) తిరిగి INFINITY;
    x = tgamma(x);
    తిరిగి సంవర్గమానం(x < 0.0 ? -x : x);
  }
  స్థిర స్థిరరాశి ద్విగుణ c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  ద్విగుణ m = -3617.0/122400.0, t = 1.0 / (x*x);
  కొరకు (పూర్ణాంకం k = 6; k >= 0; --k) m = m*t + c[k];
  తిరిగి (x - 0.5)*సంవర్గమానం(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE దశాంశం __cdecl tgammaf(దశాంశం x) {
  తిరిగి tgamma(x);
}
__CRT_INLINE దశాంశం __cdecl lgammaf(దశాంశం x) {
  తిరిగి lgamma(x);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl tgammal(దీర్ఘ ద్విగుణ x) {
  తిరిగి tgamma(x);
}
__CRT_INLINE దీర్ఘ ద్విగుణ __cdecl lgammal(దీర్ఘ ద్విగుణ x) {
  తిరిగి lgamma(x);
}

#అయితే_ముగింపు /* _TCC_LIBM_H_ */
