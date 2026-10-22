#ifndef _TCC_LIBM_H_
#define _TCC_LIBM_H_

#அந்தர்பாவ "../math.h"
#அந்தர்பாவ "../stdint.h"

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

__CRT_INLINE முழு __cdecl __fpclassify (இரட்டை x) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u = {.f = x};
  முழு e = u.i>>52 & 0x7ff;
  எனில் (!e) திரும்பு u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  எனில் (e==0x7ff) திரும்பு u.i<<12 ? FP_NAN : FP_INFINITE;
  திரும்பு FP_NORMAL;
}

__CRT_INLINE முழு __cdecl __fpclassifyf (தசம x) {
  ஒன்றிப்பு {தசம f; uint32_t i;} u = {.f = x};
  முழு e = u.i>>23 & 0xff;
  எனில் (!e) திரும்பு u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  எனில் (e==0xff) திரும்பு u.i<<9 ? FP_NAN : FP_INFINITE;
  திரும்பு FP_NORMAL;
}

__CRT_INLINE முழு __cdecl __fpclassifyl (long இரட்டை x) {
  திரும்பு __fpclassify(x);
}


/* signbit */

__CRT_INLINE முழு __cdecl __signbit (இரட்டை x) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u = {.f = x};
  திரும்பு u.i>>63;
}

__CRT_INLINE முழு __cdecl __signbitf (தசம x) {
  ஒன்றிப்பு {தசம f; uint32_t i; } u = {.f = x};
  திரும்பு u.i>>31;
}

__CRT_INLINE முழு __cdecl __signbitl (long இரட்டை x) {
  திரும்பு __signbit(x);
}


/* fmin*, fmax* */

#define TCCFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE இரட்டை __cdecl fmin (இரட்டை x, இரட்டை y) {
  திரும்பு TCCFP_FMIN_EVAL;
}

__CRT_INLINE தசம __cdecl fminf (தசம x, தசம y) {
  திரும்பு TCCFP_FMIN_EVAL;
}

__CRT_INLINE long இரட்டை __cdecl fminl (long இரட்டை x, long இரட்டை y) {
  திரும்பு TCCFP_FMIN_EVAL;
}

#define TCCFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE இரட்டை __cdecl fmax (இரட்டை x, இரட்டை y) {
  திரும்பு TCCFP_FMAX_EVAL;
}

__CRT_INLINE தசம __cdecl fmaxf (தசம x, தசம y) {
  திரும்பு TCCFP_FMAX_EVAL;
}

__CRT_INLINE long இரட்டை __cdecl fmaxl (long இரட்டை x, long இரட்டை y) {
  திரும்பு TCCFP_FMAX_EVAL;
}


/* *round* */

#define TCCFP_FORCE_EVAL(x) செய் {  \
  நிலையற்ற typeof(x) __x;         \
  __x = (x);                      \
} போது(0)

__CRT_INLINE இரட்டை __cdecl round (இரட்டை x) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u = {.f = x};
  முழு e = u.i >> 52 & 0x7ff;
  இரட்டை y;

  எனில் (e >= 0x3ff+52)
    திரும்பு x;
  எனில் (u.i >> 63)
    x = -x;
  எனில் (e < 0x3ff-1) {
    /* raise inexact if x!=0 */
    TCCFP_FORCE_EVAL(x + 0x1p52);
    திரும்பு 0*u.f;
  }
  y = (இரட்டை)(x + 0x1p52) - 0x1p52 - x;
  y = y + x - (y > 0.5) + (y <= -0.5); /* branchless */
  திரும்பு (u.i >> 63) ? -y : y;
}

__CRT_INLINE long __cdecl lround (இரட்டை x) {
  திரும்பு round(x);
}

__CRT_INLINE long long __cdecl llround (இரட்டை x) {
  திரும்பு round(x);
}

__CRT_INLINE தசம __cdecl roundf (தசம x) {
  திரும்பு round(x);
}

__CRT_INLINE long __cdecl lroundf (தசம x) {
  திரும்பு round(x);
}

__CRT_INLINE long long __cdecl llroundf (தசம x) {
  திரும்பு round(x);
}

__CRT_INLINE long இரட்டை __cdecl roundl (long இரட்டை x) {
  திரும்பு round(x);
}

__CRT_INLINE long __cdecl lroundl (long இரட்டை x) {
  திரும்பு round(x);
}

__CRT_INLINE long long __cdecl llroundl (long இரட்டை x) {
  திரும்பு round(x);
}


/* MUSL asinh, acosh, atanh */

__CRT_INLINE இரட்டை __cdecl asinh(இரட்டை x) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  எனில் (e >= 0x3ff + 26) x = log(x) + 0.693147180559945309;
  இல்லையெனில் எனில் (e >= 0x3ff + 1) x = log(2*x + 1 / (sqrt(x*x + 1) + x)); /* |x|>=2 */
  இல்லையெனில் எனில் (e >= 0x3ff - 26) x = log1p(x + x*x / (sqrt(x*x + 1) + 1));
  இல்லையெனில் TCCFP_FORCE_EVAL(x + 0x1p120f);
  திரும்பு s ? -x : x;
}

__CRT_INLINE இரட்டை __cdecl acosh(இரட்டை x) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff;
  எனில் (e < 0x3ff + 1) திரும்பு --x, log1p(x + sqrt(x*x + 2*x)); /* |x|<2 */
  எனில் (e < 0x3ff + 26) திரும்பு log(2*x - 1 / (x + sqrt(x*x - 1)));
  திரும்பு log(x) + 0.693147180559945309;
}

__CRT_INLINE இரட்டை __cdecl atanh(இரட்டை x) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u = {.f = x};
  unsigned e = u.i >> 52 & 0x7ff, s = u.i >> 63;
  u.i &= -1ull / 2, x = u.f;
  எனில் (e < 0x3ff - 1) {
    எனில் (e < 0x3ff - 32) { எனில் (e == 0) TCCFP_FORCE_EVAL((தசம)x); }
    இல்லையெனில் x = 0.5 * log1p(2*x + 2*x*x / (1 - x)); /* |x| < 0.5 */
  } இல்லையெனில் x = 0.5 * log1p(2*(x / (1 - x))); /* avoid overflow */
  திரும்பு s ? -x : x;
}

/* MUSL scalbn */

__CRT_INLINE இரட்டை __cdecl scalbn(இரட்டை x, முழு n) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u;
  எனில் (n > 1023) {
    x *= 0x1p1023, n -= 1023;
    எனில் (n > 1023) {
      x *= 0x1p1023, n -= 1023;
      எனில் (n > 1023) n = 1023;
    }
  } இல்லையெனில் எனில் (n < -1022) {
    x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
    எனில் (n < -1022) {
      x *= 0x1p-1022 * 0x1p53, n += 1022 - 53;
      எனில் (n < -1022) n = -1022;
    }
  }
  u.i = (0x3ffull + n) << 52;
  திரும்பு x * u.f;
}

/* MUSL: Override msvcrt frexp(): 4.5x speedup! */

__CRT_INLINE இரட்டை __cdecl frexp(இரட்டை x, முழு *e) {
  ஒன்றிப்பு {இரட்டை f; uint64_t i;} u = {.f = x};
  முழு ee = u.i>>52 & 0x7ff;
  எனில் (!ee) {
    எனில் (x) x = frexp(x*0x1p64, e), *e -= 64;
    இல்லையெனில் *e = 0;
    திரும்பு x;
  } இல்லையெனில் எனில் (ee == 0x7ff)
    திரும்பு x;
  *e = ee - 0x3fe;
  u.i &= 0x800fffffffffffffull;
  u.i |= 0x3fe0000000000000ull;
  திரும்பு u.f;
}

/* MUSL nan */

__CRT_INLINE இரட்டை __cdecl nan(மாறிலி எழுத்து* s) {
  திரும்பு NAN;
}
__CRT_INLINE தசம __cdecl nanf(மாறிலி எழுத்து* s) {
  திரும்பு NAN;
}
__CRT_INLINE long இரட்டை __cdecl nanl(மாறிலி எழுத்து* s) {
  திரும்பு NAN;
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/


/* Following are math functions missing from msvcrt.dll, and not defined
 * in math.h or above. Functions still remaining:
 * remquo(), remainder(), fma(), erf(), erfc(), nearbyint().
 * In <stdlib.h>: lldiv().
 */

__CRT_INLINE தசம __cdecl scalbnf(தசம x, முழு n) {
  திரும்பு scalbn(x, n);
}
__CRT_INLINE long இரட்டை __cdecl scalbnl(long இரட்டை x, முழு n) {
  திரும்பு scalbn(x, n);
}

__CRT_INLINE இரட்டை __cdecl scalbln(இரட்டை x, long n) {
  திரும்பு scalbn(x, n);
}
__CRT_INLINE தசம __cdecl scalblnf(தசம x, long n) {
  திரும்பு scalbn(x, n);
}
__CRT_INLINE long இரட்டை __cdecl scalblnl(long இரட்டை x, long n) {
  திரும்பு scalbn(x, n);
}

/* Override msvcrt ldexp(): 7.3x speedup! */

__CRT_INLINE இரட்டை __cdecl ldexp(இரட்டை x, முழு expn) {
  திரும்பு scalbn(x, expn);
}
__CRT_INLINE தசம __cdecl ldexpf(தசம x, முழு expn) {
  திரும்பு scalbn(x, expn);
}
__CRT_INLINE long இரட்டை __cdecl ldexpl(long இரட்டை x, முழு expn) {
  திரும்பு scalbn(x, expn);
}

__CRT_INLINE தசம __cdecl frexpf(தசம x, முழு *y) {
  திரும்பு frexp(x, y);
}
__CRT_INLINE long இரட்டை __cdecl frexpl (long இரட்டை x, முழு* y) {
  திரும்பு frexp(x, y);
}


__CRT_INLINE இரட்டை __cdecl rint(இரட்டை x) {
இரட்டை retval;
  __asm__ (
    "fldl    %1\n"
    "frndint   \n"
    "fstpl    %0\n" : "=m" (retval) : "m" (x));
  திரும்பு retval;
}

__CRT_INLINE தசம __cdecl rintf(தசம x) {
  தசம retval;
  __asm__ (
    "flds    %1\n"
    "frndint   \n"
    "fstps    %0\n" : "=m" (retval) : "m" (x));
   திரும்பு retval;
}
__CRT_INLINE long இரட்டை __cdecl rintl (long இரட்டை x) {
  திரும்பு rint(x);
}


/* 7.12.9.5 */
__CRT_INLINE long __cdecl lrint(இரட்டை x) {
  long retval;
  __asm__ __volatile__
    ("fldl   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  திரும்பு retval;
}

__CRT_INLINE long __cdecl lrintf(தசம x) {
  long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpl %0"  : "=m" (retval) : "m" (x));
  திரும்பு retval;
}

__CRT_INLINE long __cdecl lrintl (long இரட்டை x) {
  திரும்பு lrint(x);
}


__CRT_INLINE long long __cdecl llrint(இரட்டை x) {
long long retval;
  __asm__ __volatile__
    ("fldl    %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  திரும்பு retval;
}

__CRT_INLINE long long __cdecl llrintf(தசம x) {
  long long retval;
  __asm__ __volatile__
    ("flds   %1\n"
     "fistpll %0"  : "=m" (retval) : "m" (x));
  திரும்பு retval;
}

__CRT_INLINE long long __cdecl llrintl (long இரட்டை x) {
  திரும்பு llrint(x);
}


__CRT_INLINE இரட்டை __cdecl trunc(இரட்டை _x) {
  இரட்டை retval;
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
  திரும்பு retval;
}

__CRT_INLINE தசம __cdecl truncf(தசம x) {
  திரும்பு (தசம) ((intptr_t) x);
}
__CRT_INLINE long இரட்டை __cdecl truncl(long இரட்டை x) {
  திரும்பு trunc(x);
}


__CRT_INLINE long இரட்டை __cdecl nextafterl(long இரட்டை x, long இரட்டை to) {
  திரும்பு nextafter(x, to);
}

__CRT_INLINE இரட்டை __cdecl nexttoward(இரட்டை x, long இரட்டை to) {
  திரும்பு nextafter(x, to);
}
__CRT_INLINE தசம __cdecl nexttowardf(தசம x, long இரட்டை to) {
  திரும்பு nextafterf(x, to);
}
__CRT_INLINE long இரட்டை __cdecl nexttowardl(long இரட்டை x, long இரட்டை to) {
  திரும்பு nextafter(x, to);
}

/* Override msvcrt fabs(): 6.3x speedup! */

__CRT_INLINE இரட்டை __cdecl fabs(இரட்டை x) {
  திரும்பு x < 0 ? -x : x;
}
__CRT_INLINE தசம __cdecl fabsf(தசம x) {
  திரும்பு x < 0 ? -x : x;
}
__CRT_INLINE long இரட்டை __cdecl fabsl(long இரட்டை x) {
  திரும்பு x < 0 ? -x : x;
}


#எனில் defined(_WIN32) && !defined(_WIN64) && !defined(__ia64__)
  __CRT_INLINE தசம acosf(தசம x) { திரும்பு acos(x); }
  __CRT_INLINE தசம asinf(தசம x) { திரும்பு asin(x); }
  __CRT_INLINE தசம atanf(தசம x) { திரும்பு atan(x); }
  __CRT_INLINE தசம atan2f(தசம x, தசம y) { திரும்பு atan2(x, y); }
  __CRT_INLINE தசம ceilf(தசம x) { திரும்பு ceil(x); }
  __CRT_INLINE தசம cosf(தசம x) { திரும்பு cos(x); }
  __CRT_INLINE தசம coshf(தசம x) { திரும்பு cosh(x); }
  __CRT_INLINE தசம expf(தசம x) { திரும்பு exp(x); }
  __CRT_INLINE தசம floorf(தசம x) { திரும்பு floor(x); }
  __CRT_INLINE தசம fmodf(தசம x, தசம y) { திரும்பு fmod(x, y); }
  __CRT_INLINE தசம logf(தசம x) { திரும்பு log(x); }
  __CRT_INLINE தசம logbf(தசம x) { திரும்பு logb(x); }
  __CRT_INLINE தசம log10f(தசம x) { திரும்பு log10(x); }
  __CRT_INLINE தசம modff(தசம x, தசம *y) { இரட்டை di, df = modf(x, &di); *y = di; திரும்பு df; }
  __CRT_INLINE தசம powf(தசம x, தசம y) { திரும்பு pow(x, y); }
  __CRT_INLINE தசம sinf(தசம x) { திரும்பு sin(x); }
  __CRT_INLINE தசம sinhf(தசம x) { திரும்பு sinh(x); }
  __CRT_INLINE தசம sqrtf(தசம x) { திரும்பு sqrt(x); }
  __CRT_INLINE தசம tanf(தசம x) { திரும்பு tan(x); }
  __CRT_INLINE தசம tanhf(தசம x) { திரும்பு tanh(x); }
#endif
__CRT_INLINE தசம __cdecl asinhf(தசம x) { திரும்பு asinh(x); }
__CRT_INLINE தசம __cdecl acoshf(தசம x) { திரும்பு acosh(x); }
__CRT_INLINE தசம __cdecl atanhf(தசம x) { திரும்பு atanh(x); }

__CRT_INLINE long இரட்டை __cdecl asinhl(long இரட்டை x) { திரும்பு asinh(x); }
__CRT_INLINE long இரட்டை __cdecl acoshl(long இரட்டை x) { திரும்பு acosh(x); }
__CRT_INLINE long இரட்டை __cdecl atanhl(long இரட்டை x) { திரும்பு atanh(x); }
__CRT_INLINE long இரட்டை __cdecl asinl(long இரட்டை x) { திரும்பு asin(x); }
__CRT_INLINE long இரட்டை __cdecl acosl(long இரட்டை x) { திரும்பு acos(x); }
__CRT_INLINE long இரட்டை __cdecl atanl(long இரட்டை x) { திரும்பு atan(x); }
__CRT_INLINE long இரட்டை __cdecl ceill(long இரட்டை x) { திரும்பு ceil(x); }
__CRT_INLINE long இரட்டை __cdecl coshl(long இரட்டை x) { திரும்பு cosh(x); }
__CRT_INLINE long இரட்டை __cdecl cosl(long இரட்டை x) { திரும்பு cos(x); }
__CRT_INLINE long இரட்டை __cdecl expl(long இரட்டை x) { திரும்பு exp(x); }
__CRT_INLINE long இரட்டை __cdecl floorl(long இரட்டை x) { திரும்பு floor(x); }
__CRT_INLINE long இரட்டை __cdecl fmodl(long இரட்டை x, long இரட்டை y) { திரும்பு fmod(x, y); }
__CRT_INLINE long இரட்டை __cdecl hypotl(long இரட்டை x, long இரட்டை y) { திரும்பு hypot(x, y); }
__CRT_INLINE long இரட்டை __cdecl logl(long இரட்டை x) { திரும்பு log(x); }
__CRT_INLINE long இரட்டை __cdecl logbl(long இரட்டை x) { திரும்பு logb(x); }
__CRT_INLINE long இரட்டை __cdecl log10l(long இரட்டை x) { திரும்பு log10(x); }
__CRT_INLINE long இரட்டை __cdecl modfl(long இரட்டை x, long இரட்டை* y) { இரட்டை y1 = *y; x = modf(x, &y1); *y = y1; திரும்பு x; }
__CRT_INLINE long இரட்டை __cdecl powl(long இரட்டை x, long இரட்டை y) { திரும்பு pow(x, y); }
__CRT_INLINE long இரட்டை __cdecl sinhl(long இரட்டை x) { திரும்பு sinh(x); }
__CRT_INLINE long இரட்டை __cdecl sinl(long இரட்டை x) { திரும்பு sin(x); }
__CRT_INLINE long இரட்டை __cdecl sqrtl(long இரட்டை x) { திரும்பு sqrt(x); }
__CRT_INLINE long இரட்டை __cdecl tanhl(long இரட்டை x) { திரும்பு tanh(x); }
__CRT_INLINE long இரட்டை __cdecl tanl(long இரட்டை x) { திரும்பு tan(x); }

/* Following are accurate, but much shorter implementations than MUSL lib. */

__CRT_INLINE இரட்டை __cdecl log1p(இரட்டை x) {
  இரட்டை u = 1.0 + x;
  திரும்பு u == 1.0 ? x : log(u)*(x / (u - 1.0));
}
__CRT_INLINE தசம __cdecl log1pf(தசம x) {
  தசம u = 1.0f + x;
  திரும்பு u == 1.0f ? x : logf(u)*(x / (u - 1.0f));
}
__CRT_INLINE long இரட்டை __cdecl log1pl(long இரட்டை x) {
  திரும்பு log1p(x);
}


__CRT_INLINE இரட்டை __cdecl expm1(இரட்டை x) {
  எனில் (x > 0.0024 || x < -0.0024) திரும்பு exp(x) - 1.0;
  திரும்பு x*(1.0 + 0.5*x*(1.0 + (1/3.0)*x*(1.0 + 0.25*x*(1.0 + 0.2*x))));
}
__CRT_INLINE தசம __cdecl expm1f(தசம x) {
  எனில் (x > 0.085f || x < -0.085f) திரும்பு expf(x) - 1.0f;
  திரும்பு x*(1.0f + 0.5f*x*(1.0f + (1/3.0f)*x*(1.0f + 0.25f*x)));
}
__CRT_INLINE long இரட்டை __cdecl expm1l(long இரட்டை x) {
  திரும்பு expm1(x);
}


__CRT_INLINE இரட்டை __cdecl cbrt(இரட்டை x) {
  திரும்பு x < 0.0 ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE தசம __cdecl cbrtf(தசம x) {
  திரும்பு x < 0.0f ? -pow(-x, 1/3.0) : pow(x, 1/3.0);
}
__CRT_INLINE long இரட்டை __cdecl cbrtl(long இரட்டை x) {
  திரும்பு cbrt(x);
}


__CRT_INLINE இரட்டை __cdecl log2(இரட்டை x) {
  திரும்பு log(x) * 1.442695040888963407;
}
__CRT_INLINE தசம __cdecl log2f(தசம x) {
  திரும்பு log(x) * 1.442695040888963407;
}
__CRT_INLINE long இரட்டை __cdecl log2l(long இரட்டை x) {
  திரும்பு log(x) * 1.442695040888963407;
}


__CRT_INLINE இரட்டை __cdecl exp2(இரட்டை x) {
  திரும்பு exp(x * 0.693147180559945309);
}
__CRT_INLINE தசம __cdecl exp2f(தசம x) {
  திரும்பு exp(x * 0.693147180559945309);
}
__CRT_INLINE long இரட்டை __cdecl exp2l(long இரட்டை x) {
  திரும்பு exp(x * 0.693147180559945309);
}


__CRT_INLINE முழு __cdecl ilogb(இரட்டை x) {
  திரும்பு (முழு) logb(x);
}
__CRT_INLINE முழு __cdecl ilogbf(தசம x) {
  திரும்பு (முழு) logbf(x);
}
__CRT_INLINE முழு __cdecl ilogbl(long இரட்டை x) {
  திரும்பு (முழு) logb(x);
}


__CRT_INLINE இரட்டை __cdecl fdim(இரட்டை x, இரட்டை y) {
  எனில் (isnan(x) || isnan(y)) திரும்பு NAN;
  திரும்பு x > y ? x - y : 0;
}
__CRT_INLINE தசம __cdecl fdimf(தசம x, தசம y) {
  எனில் (isnan(x) || isnan(y)) திரும்பு NAN;
  திரும்பு x > y ? x - y : 0;
}
__CRT_INLINE long இரட்டை __cdecl fdiml(long இரட்டை x, long இரட்டை y) {
  எனில் (isnan(x) || isnan(y)) திரும்பு NAN;
  திரும்பு x > y ? x - y : 0;
}


/* tgamma and lgamma: Lanczos approximation
 * https://rosettacode.org/wiki/Gamma_function
 * https://www.johndcook.com/blog/cpp_gamma
 */

__CRT_INLINE இரட்டை __cdecl tgamma(இரட்டை x) {
  இரட்டை m = 1.0, t = 3.14159265358979323;
  எனில் (x == floor(x)) {
    எனில் (x == 0) திரும்பு INFINITY;
    எனில் (x < 0) திரும்பு NAN;
    எனில் (x < 26) { க்கு (இரட்டை k = 2; k < x; ++k) m *= k; திரும்பு m; }
  }
  எனில் (x < 0.5)
    திரும்பு t / (sin(t*x)*tgamma(1.0 - x));
  எனில் (x > 12.0)
    திரும்பு exp(lgamma(x));

  நிலையான மாறிலி இரட்டை c[8] = {676.5203681218851, -1259.1392167224028,
                              771.32342877765313, -176.61502916214059,
                              12.507343278686905, -0.13857109526572012,
                              9.9843695780195716e-6, 1.5056327351493116e-7};
  m = 0.99999999999980993, t = x + 6.5; /* x-1+8-.5 */
  க்கு (முழு k = 0; k < 8; ++k) m += c[k] / (x + k);
  திரும்பு 2.50662827463100050 * pow(t, x - 0.5)*exp(-t)*m; /* C=sqrt(2pi) */
}


__CRT_INLINE இரட்டை __cdecl lgamma(இரட்டை x) {
  எனில் (x < 12.0) {
    எனில் (x <= 0.0 && x == floor(x)) திரும்பு INFINITY;
    x = tgamma(x);
    திரும்பு log(x < 0.0 ? -x : x);
  }
  நிலையான மாறிலி இரட்டை c[7] = {1.0/12.0, -1.0/360.0, 1.0/1260.0, -1.0/1680.0,
                              1.0/1188.0, -691.0/360360.0, 1.0/156.0};
  இரட்டை m = -3617.0/122400.0, t = 1.0 / (x*x);
  க்கு (முழு k = 6; k >= 0; --k) m = m*t + c[k];
  திரும்பு (x - 0.5)*log(x) - x + 0.918938533204672742 + m / x; /* C=log(2pi)/2 */
}

__CRT_INLINE தசம __cdecl tgammaf(தசம x) {
  திரும்பு tgamma(x);
}
__CRT_INLINE தசம __cdecl lgammaf(தசம x) {
  திரும்பு lgamma(x);
}
__CRT_INLINE long இரட்டை __cdecl tgammal(long இரட்டை x) {
  திரும்பு tgamma(x);
}
__CRT_INLINE long இரட்டை __cdecl lgammal(long இரட்டை x) {
  திரும்பு lgamma(x);
}

#endif /* _TCC_LIBM_H_ */
