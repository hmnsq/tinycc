/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MATH_H_
#define _MATH_H_

#اگر __GNUC__ >= 3
#pragma GCC system_header
#endif

#شامل <_mingw.h>

ساختار exception;

#pragma pack(افزودن,_CRT_PACKING)

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
بیرونی "C" {
#endif

#ifndef _EXCEPTION_DEFINED
#define _EXCEPTION_DEFINED
  ساختار _exception {
    صحیح type;
    نویسه *name;
    دوگانه arg1;
    دوگانه arg2;
    دوگانه retval;
  };
#endif

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
  ساختار _complex {
    دوگانه x,y;
  };
#endif

#define EDOM 33
#define ERANGE 34

#ifndef _HUGE
#ifdef _MSVCRT_
  بیرونی دوگانه *_HUGE;
#وگرنه
  بیرونی دوگانه *_imp___HUGE;
#define _HUGE	(*_imp___HUGE)
#endif
#endif

#define HUGE_VAL _HUGE

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  صحیح __cdecl abs(صحیح _X);
  long __cdecl labs(long _X);
#endif
  دوگانه __cdecl acos(دوگانه _X);
  دوگانه __cdecl asin(دوگانه _X);
  دوگانه __cdecl atan(دوگانه _X);
  دوگانه __cdecl atan2(دوگانه _Y,دوگانه _X);
#ifndef _SIGN_DEFINED
#define _SIGN_DEFINED
  _CRTIMP دوگانه __cdecl _copysign (دوگانه عدد,دوگانه _Sign);
  _CRTIMP دوگانه __cdecl _chgsign (دوگانه _X);
#endif
  دوگانه __cdecl cos(دوگانه _X);
  دوگانه __cdecl cosh(دوگانه _X);
  دوگانه __cdecl exp(دوگانه _X);
  دوگانه __cdecl expm1(دوگانه _X);
  دوگانه __cdecl fabs(دوگانه _X);
  دوگانه __cdecl fmod(دوگانه _X,دوگانه _Y);
  دوگانه __cdecl log(دوگانه _X);
  دوگانه __cdecl log10(دوگانه _X);
  دوگانه __cdecl pow(دوگانه _X,دوگانه _Y);
  دوگانه __cdecl sin(دوگانه _X);
  دوگانه __cdecl sinh(دوگانه _X);
  دوگانه __cdecl tan(دوگانه _X);
  دوگانه __cdecl tanh(دوگانه _X);
  دوگانه __cdecl sqrt(دوگانه _X);
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  دوگانه __cdecl atof(ثابت نویسه *_String);
  دوگانه __cdecl _atof_l(ثابت نویسه *_String,_locale_t _Locale);
#endif

  _CRTIMP دوگانه __cdecl _cabs(ساختار _complex _ComplexA);
  دوگانه __cdecl ceil(دوگانه _X);
  دوگانه __cdecl floor(دوگانه _X);
  دوگانه __cdecl frexp(دوگانه _X,صحیح *_Y);
  دوگانه __cdecl _hypot(دوگانه _X,دوگانه _Y);
  _CRTIMP دوگانه __cdecl _j0(دوگانه _X);
  _CRTIMP دوگانه __cdecl _j1(دوگانه _X);
  _CRTIMP دوگانه __cdecl _jn(صحیح _X,دوگانه _Y);
  دوگانه __cdecl ldexp(دوگانه _X,صحیح _Y);
#ifndef _CRT_MATHERR_DEFINED
#define _CRT_MATHERR_DEFINED
  صحیح __cdecl _matherr(ساختار _exception *_Except);
#endif
  دوگانه __cdecl modf(دوگانه _X,دوگانه *_Y);
  _CRTIMP دوگانه __cdecl _y0(دوگانه _X);
  _CRTIMP دوگانه __cdecl _y1(دوگانه _X);
  _CRTIMP دوگانه __cdecl _yn(صحیح _X,دوگانه _Y);

#اگر(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح __cdecl _set_SSE2_enable(صحیح _Flag);
  /* from libmingwex */
  اعشاری __cdecl _hypotf(اعشاری _X,اعشاری _Y);
#endif

  اعشاری frexpf(اعشاری _X,صحیح *_Y);
  اعشاری __cdecl ldexpf(اعشاری _X,صحیح _Y);
  long دوگانه __cdecl ldexpl(long دوگانه _X,صحیح _Y);
  اعشاری __cdecl acosf(اعشاری _X);
  اعشاری __cdecl asinf(اعشاری _X);
   اعشاری __cdecl atanf(اعشاری _X);
   اعشاری __cdecl atan2f(اعشاری _X,اعشاری _Y);
   اعشاری __cdecl cosf(اعشاری _X);
   اعشاری __cdecl sinf(اعشاری _X);
   اعشاری __cdecl tanf(اعشاری _X);
   اعشاری __cdecl coshf(اعشاری _X);
   اعشاری __cdecl sinhf(اعشاری _X);
   اعشاری __cdecl tanhf(اعشاری _X);
   اعشاری __cdecl expf(اعشاری _X);
   اعشاری __cdecl expm1f(اعشاری _X);
   اعشاری __cdecl logf(اعشاری _X);
   اعشاری __cdecl log10f(اعشاری _X);
   اعشاری __cdecl modff(اعشاری _X,اعشاری *_Y);
   اعشاری __cdecl powf(اعشاری _X,اعشاری _Y);
   اعشاری __cdecl sqrtf(اعشاری _X);
   اعشاری __cdecl ceilf(اعشاری _X);
   اعشاری __cdecl floorf(اعشاری _X);
  اعشاری __cdecl fmodf(اعشاری _X,اعشاری _Y);
   اعشاری __cdecl _hypotf(اعشاری _X,اعشاری _Y);
  اعشاری __cdecl fabsf(اعشاری _X);
#اگر !defined(__ia64__)
   /* from libmingwex */
   اعشاری __cdecl _copysignf (اعشاری عدد,اعشاری _Sign);
   اعشاری __cdecl _chgsignf (اعشاری _X);
   اعشاری __cdecl _logbf(اعشاری _X);
   اعشاری __cdecl _nextafterf(اعشاری _X,اعشاری _Y);
   صحیح __cdecl _finitef(اعشاری _X);
   صحیح __cdecl _isnanf(اعشاری _X);
   صحیح __cdecl _fpclassf(اعشاری _X);
#endif

#ifndef	NO_OLDNAMES
#define matherr _matherr

#define HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  دوگانه __cdecl hypot(دوگانه _X,دوگانه _Y);
  _CRTIMP دوگانه __cdecl j0(دوگانه _X);
  _CRTIMP دوگانه __cdecl j1(دوگانه _X);
  _CRTIMP دوگانه __cdecl jn(صحیح _X,دوگانه _Y);
  _CRTIMP دوگانه __cdecl y0(دوگانه _X);
  _CRTIMP دوگانه __cdecl y1(دوگانه _X);
  _CRTIMP دوگانه __cdecl yn(صحیح _X,دوگانه _Y);
#endif

#ifndef __NO_ISOCEXT
#اگر (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
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

  بیرونی صحیح __cdecl __fpclassifyf (اعشاری);
  بیرونی صحیح __cdecl __fpclassify (دوگانه);
  بیرونی صحیح __cdecl __fpclassifyl (long دوگانه);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#define fpclassify(x) \
  _Generic(x, اعشاری: __fpclassifyf, دوگانه: __fpclassify, long دوگانه: __fpclassifyl)(x)

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

  بیرونی صحیح __cdecl __signbitf (اعشاری);
  بیرونی صحیح __cdecl __signbit (دوگانه);
  بیرونی صحیح __cdecl __signbitl (long دوگانه);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#define signbit(x) \
  _Generic(x, اعشاری: __signbitf, دوگانه: __signbit, long دوگانه: __signbitl)(x)

  بیرونی دوگانه __cdecl exp2(دوگانه);
  بیرونی اعشاری __cdecl exp2f(اعشاری);
  بیرونی long دوگانه __cdecl exp2l(long دوگانه);

#define FP_ILOGB0 ((صحیح)0x80000000)
#define FP_ILOGBNAN ((صحیح)0x80000000)
  بیرونی صحیح __cdecl ilogb (دوگانه);
  بیرونی صحیح __cdecl ilogbf (اعشاری);
  بیرونی صحیح __cdecl ilogbl (long دوگانه);

  بیرونی دوگانه __cdecl log1p(دوگانه);
  بیرونی اعشاری __cdecl log1pf(اعشاری);
  بیرونی long دوگانه __cdecl log1pl(long دوگانه);

  بیرونی دوگانه __cdecl log2 (دوگانه);
  بیرونی اعشاری __cdecl log2f (اعشاری);
  بیرونی long دوگانه __cdecl log2l (long دوگانه);

  بیرونی دوگانه __cdecl logb (دوگانه);
  بیرونی اعشاری __cdecl logbf (اعشاری);
  بیرونی long دوگانه __cdecl logbl (long دوگانه);

  بیرونی long دوگانه __cdecl modfl (long دوگانه, long دوگانه*);

  /* 7.12.6.13 */
  بیرونی دوگانه __cdecl scalbn (دوگانه, صحیح);
  بیرونی اعشاری __cdecl scalbnf (اعشاری, صحیح);
  بیرونی long دوگانه __cdecl scalbnl (long دوگانه, صحیح);

  بیرونی دوگانه __cdecl scalbln (دوگانه, long);
  بیرونی اعشاری __cdecl scalblnf (اعشاری, long);
  بیرونی long دوگانه __cdecl scalblnl (long دوگانه, long);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  بیرونی دوگانه __cdecl cbrt (دوگانه);
  بیرونی اعشاری __cdecl cbrtf (اعشاری);
  بیرونی long دوگانه __cdecl cbrtl (long دوگانه);

  بیرونی دوگانه __cdecl hypot (دوگانه, دوگانه);
  بیرونی اعشاری __cdecl hypotf (اعشاری, اعشاری);
  بیرونی long دوگانه __cdecl hypotl (long دوگانه, long دوگانه);

  بیرونی long دوگانه __cdecl powl (long دوگانه, long دوگانه);
  بیرونی long دوگانه __cdecl expl(long دوگانه);
  بیرونی long دوگانه __cdecl expm1l(long دوگانه);
  بیرونی long دوگانه __cdecl coshl(long دوگانه);
  بیرونی long دوگانه __cdecl fabsl (long دوگانه);
  بیرونی long دوگانه __cdecl acosl(long دوگانه);
  بیرونی long دوگانه __cdecl asinl(long دوگانه);
  بیرونی long دوگانه __cdecl atanl(long دوگانه);
  بیرونی long دوگانه __cdecl atan2l(long دوگانه,long دوگانه);
  بیرونی long دوگانه __cdecl sinhl(long دوگانه);
  بیرونی long دوگانه __cdecl tanhl(long دوگانه);

  /* 7.12.8.1 The erf functions  */
  بیرونی دوگانه __cdecl erf (دوگانه);
  بیرونی اعشاری __cdecl erff (اعشاری);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  بیرونی دوگانه __cdecl erfc (دوگانه);
  بیرونی اعشاری __cdecl erfcf (اعشاری);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  بیرونی دوگانه __cdecl lgamma (دوگانه);
  بیرونی اعشاری __cdecl lgammaf (اعشاری);
  بیرونی long دوگانه __cdecl lgammal (long دوگانه);

  /* 7.12.8.4 The tgamma functions */
  بیرونی دوگانه __cdecl tgamma (دوگانه);
  بیرونی اعشاری __cdecl tgammaf (اعشاری);
  بیرونی long دوگانه __cdecl tgammal (long دوگانه);

  بیرونی long دوگانه __cdecl ceill (long دوگانه);
  بیرونی long دوگانه __cdecl floorl (long دوگانه);
  بیرونی long دوگانه __cdecl frexpl(long دوگانه,صحیح *);
  بیرونی long دوگانه __cdecl log10l(long دوگانه);
  بیرونی long دوگانه __cdecl logl(long دوگانه);
  بیرونی long دوگانه __cdecl cosl(long دوگانه);
  بیرونی long دوگانه __cdecl sinl(long دوگانه);
  بیرونی long دوگانه __cdecl tanl(long دوگانه);
  بیرونی long دوگانه sqrtl(long دوگانه);

  /* 7.12.9.3 */
  بیرونی دوگانه __cdecl nearbyint ( دوگانه);
  بیرونی اعشاری __cdecl nearbyintf (اعشاری);
  بیرونی long دوگانه __cdecl nearbyintl (long دوگانه);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  بیرونی دوگانه __cdecl rint (دوگانه);
  بیرونی اعشاری __cdecl rintf (اعشاری);
  بیرونی long دوگانه __cdecl rintl (long دوگانه);

  بیرونی long __cdecl lrint (دوگانه);
  بیرونی long __cdecl lrintf (اعشاری);
  بیرونی long __cdecl lrintl (long دوگانه);

  بیرونی long long __cdecl llrint (دوگانه);
  بیرونی long long __cdecl llrintf (اعشاری);
  بیرونی long long __cdecl llrintl (long دوگانه);

  #define FE_TONEAREST	0x0000
  #define FE_DOWNWARD	0x0400
  #define FE_UPWARD	0x0800
  #define FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  بیرونی دوگانه __cdecl round (دوگانه);
  بیرونی اعشاری __cdecl roundf (اعشاری);
  بیرونی long دوگانه __cdecl roundl (long دوگانه);

  /* 7.12.9.7  */
  بیرونی long __cdecl lround (دوگانه);
  بیرونی long __cdecl lroundf (اعشاری);
  بیرونی long __cdecl lroundl (long دوگانه);

  بیرونی long long __cdecl llround (دوگانه);
  بیرونی long long __cdecl llroundf (اعشاری);
  بیرونی long long __cdecl llroundl (long دوگانه);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  بیرونی دوگانه __cdecl trunc (دوگانه);
  بیرونی اعشاری __cdecl truncf (اعشاری);
  بیرونی long دوگانه __cdecl truncl (long دوگانه);

  بیرونی long دوگانه __cdecl fmodl (long دوگانه, long دوگانه);

  /* 7.12.10.2 */ 
  بیرونی دوگانه __cdecl remainder (دوگانه, دوگانه);
  بیرونی اعشاری __cdecl remainderf (اعشاری, اعشاری);
  بیرونی long دوگانه __cdecl remainderl (long دوگانه, long دوگانه);

  /* 7.12.10.3 */
  بیرونی دوگانه __cdecl remquo(دوگانه, دوگانه, صحیح *);
  بیرونی اعشاری __cdecl remquof(اعشاری, اعشاری, صحیح *);
  بیرونی long دوگانه __cdecl remquol(long دوگانه, long دوگانه, صحیح *);

  /* 7.12.11.1 */
  بیرونی دوگانه __cdecl copysign (دوگانه, دوگانه); /* in libmoldname.a */
  بیرونی اعشاری __cdecl copysignf (اعشاری, اعشاری);
  بیرونی long دوگانه __cdecl copysignl (long دوگانه, long دوگانه);

  /* 7.12.11.2 Return a NaN */
  بیرونی دوگانه __cdecl nan(ثابت نویسه *tagp);
  بیرونی اعشاری __cdecl nanf(ثابت نویسه *tagp);
  بیرونی long دوگانه __cdecl nanl(ثابت نویسه *tagp);

#ifndef __STRICT_ANSI__
#define _nan() nan("")
#define _nanf() nanf("")
#define _nanl() nanl("")
#endif

  /* 7.12.11.3 */
  بیرونی دوگانه __cdecl nextafter (دوگانه, دوگانه); /* in libmoldname.a */
  بیرونی اعشاری __cdecl nextafterf (اعشاری, اعشاری);
  بیرونی long دوگانه __cdecl nextafterl (long دوگانه, long دوگانه);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  بیرونی دوگانه __cdecl fdim (دوگانه x, دوگانه y);
  بیرونی اعشاری __cdecl fdimf (اعشاری x, اعشاری y);
  بیرونی long دوگانه __cdecl fdiml (long دوگانه x, long دوگانه y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  بیرونی دوگانه __cdecl fmax  (دوگانه, دوگانه);
  بیرونی اعشاری __cdecl fmaxf (اعشاری, اعشاری);
  بیرونی long دوگانه __cdecl fmaxl (long دوگانه, long دوگانه);

  /* 7.12.12.3 */
  بیرونی دوگانه __cdecl fmin (دوگانه, دوگانه);
  بیرونی اعشاری __cdecl fminf (اعشاری, اعشاری);
  بیرونی long دوگانه __cdecl fminl (long دوگانه, long دوگانه);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  بیرونی دوگانه __cdecl fma (دوگانه, دوگانه, دوگانه);
  بیرونی اعشاری __cdecl fmaf (اعشاری, اعشاری, اعشاری);
  بیرونی long دوگانه __cdecl fmal (long دوگانه, long دوگانه, long دوگانه);


#endif /* __STDC_VERSION__ >= 199901L */
#endif /* __NO_ISOCEXT */

#ifdef __cplusplus
}
#endif
#pragma pack(برداشت)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#شامل "tcc/tcc_libm.h"

#endif /* End _MATH_H_ */

