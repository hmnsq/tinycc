/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MATH_H_
#define _MATH_H_

#إذا __GNUC__ >= 3
#pragma GCC system_header
#endif

#ضمن <_mingw.h>

بنية exception;

#pragma pack(ادفع,_CRT_PACKING)

#define _DOMAIN 1
#define _SING 2
#define _OVERFLOW 3
#define _UNDERFLOW 4
#define _TLOSS 5
#define _PLOSS 6

#ifndef __STRICT_ANSI__
#ifndef	NO_OLDNAMES
#define DOMAIN _DOMAIN
#define SING _SING
#define OVERFLOW _OVERFLOW
#define UNDERFLOW _UNDERFLOW
#define TLOSS _TLOSS
#define PLOSS _PLOSS
#endif
#endif

#ifndef __STRICT_ANSI__
#define M_E 2.71828182845904523536
#define M_LOG2E 1.44269504088896340736
#define M_LOG10E 0.434294481903251827651
#define M_LN2 0.693147180559945309417
#define M_LN10 2.30258509299404568402
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.785398163397448309616
#define M_1_PI 0.318309886183790671538
#define M_2_PI 0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.707106781186547524401
#endif

#ifndef __STRICT_ANSI__
/* See also float.h  */
#ifndef __MINGW_FPCLASS_DEFINED
#define __MINGW_FPCLASS_DEFINED 1
#define	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#define	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#define	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#define	_FPCLASS_NN	0x0008	/* Negative Normal */
#define	_FPCLASS_ND	0x0010	/* Negative Denormal */
#define	_FPCLASS_NZ	0x0020	/* Negative Zero */
#define	_FPCLASS_PZ	0x0040	/* Positive Zero */
#define	_FPCLASS_PD	0x0080	/* Positive Denormal */
#define	_FPCLASS_PN	0x0100	/* Positive Normal */
#define	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#endif
#endif

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef _EXCEPTION_DEFINED
#define _EXCEPTION_DEFINED
  بنية _exception {
    صحيح type;
    حرف *name;
    مزدوج arg1;
    مزدوج arg2;
    مزدوج retval;
  };
#endif

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
  بنية _complex {
    مزدوج x,y;
  };
#endif

#define EDOM 33
#define ERANGE 34

#ifndef _HUGE
#ifdef _MSVCRT_
  خارجي مزدوج *_HUGE;
#وإلا
  خارجي مزدوج *_imp___HUGE;
#define _HUGE	(*_imp___HUGE)
#endif
#endif

#define HUGE_VAL _HUGE

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  صحيح __cdecl abs(صحيح _X);
  long __cdecl labs(long _X);
#endif
  مزدوج __cdecl acos(مزدوج _X);
  مزدوج __cdecl asin(مزدوج _X);
  مزدوج __cdecl atan(مزدوج _X);
  مزدوج __cdecl atan2(مزدوج _Y,مزدوج _X);
#ifndef _SIGN_DEFINED
#define _SIGN_DEFINED
  _CRTIMP مزدوج __cdecl _copysign (مزدوج العدد,مزدوج _Sign);
  _CRTIMP مزدوج __cdecl _chgsign (مزدوج _X);
#endif
  مزدوج __cdecl cos(مزدوج _X);
  مزدوج __cdecl cosh(مزدوج _X);
  مزدوج __cdecl exp(مزدوج _X);
  مزدوج __cdecl expm1(مزدوج _X);
  مزدوج __cdecl fabs(مزدوج _X);
  مزدوج __cdecl fmod(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl log(مزدوج _X);
  مزدوج __cdecl log10(مزدوج _X);
  مزدوج __cdecl pow(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl sin(مزدوج _X);
  مزدوج __cdecl sinh(مزدوج _X);
  مزدوج __cdecl tan(مزدوج _X);
  مزدوج __cdecl tanh(مزدوج _X);
  مزدوج __cdecl sqrt(مزدوج _X);
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#endif

  _CRTIMP مزدوج __cdecl _cabs(بنية _complex _ComplexA);
  مزدوج __cdecl ceil(مزدوج _X);
  مزدوج __cdecl floor(مزدوج _X);
  مزدوج __cdecl frexp(مزدوج _X,صحيح *_Y);
  مزدوج __cdecl _hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl _j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _jn(صحيح _X,مزدوج _Y);
  مزدوج __cdecl ldexp(مزدوج _X,صحيح _Y);
#ifndef _CRT_MATHERR_DEFINED
#define _CRT_MATHERR_DEFINED
  صحيح __cdecl _matherr(بنية _exception *_Except);
#endif
  مزدوج __cdecl modf(مزدوج _X,مزدوج *_Y);
  _CRTIMP مزدوج __cdecl _y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _yn(صحيح _X,مزدوج _Y);

#إذا(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _set_SSE2_enable(صحيح _Flag);
  /* from libmingwex */
  عائم __cdecl _hypotf(عائم _X,عائم _Y);
#endif

  عائم frexpf(عائم _X,صحيح *_Y);
  عائم __cdecl ldexpf(عائم _X,صحيح _Y);
  long مزدوج __cdecl ldexpl(long مزدوج _X,صحيح _Y);
  عائم __cdecl acosf(عائم _X);
  عائم __cdecl asinf(عائم _X);
   عائم __cdecl atanf(عائم _X);
   عائم __cdecl atan2f(عائم _X,عائم _Y);
   عائم __cdecl cosf(عائم _X);
   عائم __cdecl sinf(عائم _X);
   عائم __cdecl tanf(عائم _X);
   عائم __cdecl coshf(عائم _X);
   عائم __cdecl sinhf(عائم _X);
   عائم __cdecl tanhf(عائم _X);
   عائم __cdecl expf(عائم _X);
   عائم __cdecl expm1f(عائم _X);
   عائم __cdecl logf(عائم _X);
   عائم __cdecl log10f(عائم _X);
   عائم __cdecl modff(عائم _X,عائم *_Y);
   عائم __cdecl powf(عائم _X,عائم _Y);
   عائم __cdecl sqrtf(عائم _X);
   عائم __cdecl ceilf(عائم _X);
   عائم __cdecl floorf(عائم _X);
  عائم __cdecl fmodf(عائم _X,عائم _Y);
   عائم __cdecl _hypotf(عائم _X,عائم _Y);
  عائم __cdecl fabsf(عائم _X);
#إذا !defined(__ia64__)
   /* from libmingwex */
   عائم __cdecl _copysignf (عائم العدد,عائم _Sign);
   عائم __cdecl _chgsignf (عائم _X);
   عائم __cdecl _logbf(عائم _X);
   عائم __cdecl _nextafterf(عائم _X,عائم _Y);
   صحيح __cdecl _finitef(عائم _X);
   صحيح __cdecl _isnanf(عائم _X);
   صحيح __cdecl _fpclassf(عائم _X);
#endif

#ifndef	NO_OLDNAMES
#define matherr _matherr

#define HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  مزدوج __cdecl hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl jn(صحيح _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl yn(صحيح _X,مزدوج _Y);
#endif

#ifndef __NO_ISOCEXT
#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#define NAN (0.0F/0.0F)
#define HUGE_VALF (1.0F/0.0F)
#define HUGE_VALL (1.0L/0.0L)
#define INFINITY (1.0F/0.0F)


#define FP_NAN		0x0100
#define FP_NORMAL	0x0400
#define FP_INFINITE	(FP_NAN | FP_NORMAL)
#define FP_ZERO		0x4000
#define FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  خارجي صحيح __cdecl __fpclassifyf (عائم);
  خارجي صحيح __cdecl __fpclassify (مزدوج);
  خارجي صحيح __cdecl __fpclassifyl (long مزدوج);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#define fpclassify(x) \
  _Generic(x, عائم: __fpclassifyf, مزدوج: __fpclassify, long مزدوج: __fpclassifyl)(x)

  /* 7.12.3.2 */
#define isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#define isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#define isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#define isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  خارجي صحيح __cdecl __signbitf (عائم);
  خارجي صحيح __cdecl __signbit (مزدوج);
  خارجي صحيح __cdecl __signbitl (long مزدوج);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#define signbit(x) \
  _Generic(x, عائم: __signbitf, مزدوج: __signbit, long مزدوج: __signbitl)(x)

  خارجي مزدوج __cdecl exp2(مزدوج);
  خارجي عائم __cdecl exp2f(عائم);
  خارجي long مزدوج __cdecl exp2l(long مزدوج);

#define FP_ILOGB0 ((صحيح)0x80000000)
#define FP_ILOGBNAN ((صحيح)0x80000000)
  خارجي صحيح __cdecl ilogb (مزدوج);
  خارجي صحيح __cdecl ilogbf (عائم);
  خارجي صحيح __cdecl ilogbl (long مزدوج);

  خارجي مزدوج __cdecl log1p(مزدوج);
  خارجي عائم __cdecl log1pf(عائم);
  خارجي long مزدوج __cdecl log1pl(long مزدوج);

  خارجي مزدوج __cdecl log2 (مزدوج);
  خارجي عائم __cdecl log2f (عائم);
  خارجي long مزدوج __cdecl log2l (long مزدوج);

  خارجي مزدوج __cdecl logb (مزدوج);
  خارجي عائم __cdecl logbf (عائم);
  خارجي long مزدوج __cdecl logbl (long مزدوج);

  خارجي long مزدوج __cdecl modfl (long مزدوج, long مزدوج*);

  /* 7.12.6.13 */
  خارجي مزدوج __cdecl scalbn (مزدوج, صحيح);
  خارجي عائم __cdecl scalbnf (عائم, صحيح);
  خارجي long مزدوج __cdecl scalbnl (long مزدوج, صحيح);

  خارجي مزدوج __cdecl scalbln (مزدوج, long);
  خارجي عائم __cdecl scalblnf (عائم, long);
  خارجي long مزدوج __cdecl scalblnl (long مزدوج, long);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  خارجي مزدوج __cdecl cbrt (مزدوج);
  خارجي عائم __cdecl cbrtf (عائم);
  خارجي long مزدوج __cdecl cbrtl (long مزدوج);

  خارجي مزدوج __cdecl hypot (مزدوج, مزدوج);
  خارجي عائم __cdecl hypotf (عائم, عائم);
  خارجي long مزدوج __cdecl hypotl (long مزدوج, long مزدوج);

  خارجي long مزدوج __cdecl powl (long مزدوج, long مزدوج);
  خارجي long مزدوج __cdecl expl(long مزدوج);
  خارجي long مزدوج __cdecl expm1l(long مزدوج);
  خارجي long مزدوج __cdecl coshl(long مزدوج);
  خارجي long مزدوج __cdecl fabsl (long مزدوج);
  خارجي long مزدوج __cdecl acosl(long مزدوج);
  خارجي long مزدوج __cdecl asinl(long مزدوج);
  خارجي long مزدوج __cdecl atanl(long مزدوج);
  خارجي long مزدوج __cdecl atan2l(long مزدوج,long مزدوج);
  خارجي long مزدوج __cdecl sinhl(long مزدوج);
  خارجي long مزدوج __cdecl tanhl(long مزدوج);

  /* 7.12.8.1 The erf functions  */
  خارجي مزدوج __cdecl erf (مزدوج);
  خارجي عائم __cdecl erff (عائم);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  خارجي مزدوج __cdecl erfc (مزدوج);
  خارجي عائم __cdecl erfcf (عائم);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  خارجي مزدوج __cdecl lgamma (مزدوج);
  خارجي عائم __cdecl lgammaf (عائم);
  خارجي long مزدوج __cdecl lgammal (long مزدوج);

  /* 7.12.8.4 The tgamma functions */
  خارجي مزدوج __cdecl tgamma (مزدوج);
  خارجي عائم __cdecl tgammaf (عائم);
  خارجي long مزدوج __cdecl tgammal (long مزدوج);

  خارجي long مزدوج __cdecl ceill (long مزدوج);
  خارجي long مزدوج __cdecl floorl (long مزدوج);
  خارجي long مزدوج __cdecl frexpl(long مزدوج,صحيح *);
  خارجي long مزدوج __cdecl log10l(long مزدوج);
  خارجي long مزدوج __cdecl logl(long مزدوج);
  خارجي long مزدوج __cdecl cosl(long مزدوج);
  خارجي long مزدوج __cdecl sinl(long مزدوج);
  خارجي long مزدوج __cdecl tanl(long مزدوج);
  خارجي long مزدوج sqrtl(long مزدوج);

  /* 7.12.9.3 */
  خارجي مزدوج __cdecl nearbyint ( مزدوج);
  خارجي عائم __cdecl nearbyintf (عائم);
  خارجي long مزدوج __cdecl nearbyintl (long مزدوج);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  خارجي مزدوج __cdecl rint (مزدوج);
  خارجي عائم __cdecl rintf (عائم);
  خارجي long مزدوج __cdecl rintl (long مزدوج);

  خارجي long __cdecl lrint (مزدوج);
  خارجي long __cdecl lrintf (عائم);
  خارجي long __cdecl lrintl (long مزدوج);

  خارجي long long __cdecl llrint (مزدوج);
  خارجي long long __cdecl llrintf (عائم);
  خارجي long long __cdecl llrintl (long مزدوج);

  #define FE_TONEAREST	0x0000
  #define FE_DOWNWARD	0x0400
  #define FE_UPWARD	0x0800
  #define FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl round (مزدوج);
  خارجي عائم __cdecl roundf (عائم);
  خارجي long مزدوج __cdecl roundl (long مزدوج);

  /* 7.12.9.7  */
  خارجي long __cdecl lround (مزدوج);
  خارجي long __cdecl lroundf (عائم);
  خارجي long __cdecl lroundl (long مزدوج);

  خارجي long long __cdecl llround (مزدوج);
  خارجي long long __cdecl llroundf (عائم);
  خارجي long long __cdecl llroundl (long مزدوج);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl trunc (مزدوج);
  خارجي عائم __cdecl truncf (عائم);
  خارجي long مزدوج __cdecl truncl (long مزدوج);

  خارجي long مزدوج __cdecl fmodl (long مزدوج, long مزدوج);

  /* 7.12.10.2 */ 
  خارجي مزدوج __cdecl remainder (مزدوج, مزدوج);
  خارجي عائم __cdecl remainderf (عائم, عائم);
  خارجي long مزدوج __cdecl remainderl (long مزدوج, long مزدوج);

  /* 7.12.10.3 */
  خارجي مزدوج __cdecl remquo(مزدوج, مزدوج, صحيح *);
  خارجي عائم __cdecl remquof(عائم, عائم, صحيح *);
  خارجي long مزدوج __cdecl remquol(long مزدوج, long مزدوج, صحيح *);

  /* 7.12.11.1 */
  خارجي مزدوج __cdecl copysign (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl copysignf (عائم, عائم);
  خارجي long مزدوج __cdecl copysignl (long مزدوج, long مزدوج);

  /* 7.12.11.2 Return a NaN */
  خارجي مزدوج __cdecl nan(ثابت حرف *tagp);
  خارجي عائم __cdecl nanf(ثابت حرف *tagp);
  خارجي long مزدوج __cdecl nanl(ثابت حرف *tagp);

#ifndef __STRICT_ANSI__
#define _nan() nan("")
#define _nanf() nanf("")
#define _nanl() nanl("")
#endif

  /* 7.12.11.3 */
  خارجي مزدوج __cdecl nextafter (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl nextafterf (عائم, عائم);
  خارجي long مزدوج __cdecl nextafterl (long مزدوج, long مزدوج);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  خارجي مزدوج __cdecl fdim (مزدوج x, مزدوج y);
  خارجي عائم __cdecl fdimf (عائم x, عائم y);
  خارجي long مزدوج __cdecl fdiml (long مزدوج x, long مزدوج y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  خارجي مزدوج __cdecl fmax  (مزدوج, مزدوج);
  خارجي عائم __cdecl fmaxf (عائم, عائم);
  خارجي long مزدوج __cdecl fmaxl (long مزدوج, long مزدوج);

  /* 7.12.12.3 */
  خارجي مزدوج __cdecl fmin (مزدوج, مزدوج);
  خارجي عائم __cdecl fminf (عائم, عائم);
  خارجي long مزدوج __cdecl fminl (long مزدوج, long مزدوج);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  خارجي مزدوج __cdecl fma (مزدوج, مزدوج, مزدوج);
  خارجي عائم __cdecl fmaf (عائم, عائم, عائم);
  خارجي long مزدوج __cdecl fmal (long مزدوج, long مزدوج, long مزدوج);


#endif /* __STDC_VERSION__ >= 199901L */
#endif /* __NO_ISOCEXT */

#ifdef __cplusplus
}
#endif
#pragma pack(اسحب)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#ضمن "tcc/tcc_libm.h"

#endif /* End _MATH_H_ */

