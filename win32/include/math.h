/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MATH_H_
#define _MATH_H_

#ಯದಿ __GNUC__ >= 3
#pragma GCC system_header
#endif

#ಅನ್ತರ್ಭಾವ <_mingw.h>

ಸಂರಚನಾ exception;

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

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
ಬಾಹ್ಯ "C" {
#endif

#ifndef _EXCEPTION_DEFINED
#define _EXCEPTION_DEFINED
  ಸಂರಚನಾ _exception {
    ಪೂರ್ಣಾಙ್ಕ type;
    ವರ್ಣ *name;
    ದ್ವಿಗುಣ arg1;
    ದ್ವಿಗುಣ arg2;
    ದ್ವಿಗುಣ retval;
  };
#endif

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
  ಸಂರಚನಾ _complex {
    ದ್ವಿಗುಣ x,y;
  };
#endif

#define EDOM 33
#define ERANGE 34

#ifndef _HUGE
#ifdef _MSVCRT_
  ಬಾಹ್ಯ ದ್ವಿಗುಣ *_HUGE;
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ ದ್ವಿಗುಣ *_imp___HUGE;
#define _HUGE	(*_imp___HUGE)
#endif
#endif

#define HUGE_VAL _HUGE

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  ಪೂರ್ಣಾಙ್ಕ __cdecl abs(ಪೂರ್ಣಾಙ್ಕ _X);
  long __cdecl labs(long _X);
#endif
  ದ್ವಿಗುಣ __cdecl acos(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl asin(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl atan(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl atan2(ದ್ವಿಗುಣ _Y,ದ್ವಿಗುಣ _X);
#ifndef _SIGN_DEFINED
#define _SIGN_DEFINED
  _CRTIMP ದ್ವಿಗುಣ __cdecl _copysign (ದ್ವಿಗುಣ ಸಂಖ್ಯೆ,ದ್ವಿಗುಣ _Sign);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _chgsign (ದ್ವಿಗುಣ _X);
#endif
  ದ್ವಿಗುಣ __cdecl cos(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl cosh(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl exp(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl expm1(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl fabs(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl fmod(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  ದ್ವಿಗುಣ __cdecl log(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl log10(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl pow(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  ದ್ವಿಗುಣ __cdecl sin(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl sinh(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl tan(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl tanh(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl sqrt(ದ್ವಿಗುಣ _X);
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  ದ್ವಿಗುಣ __cdecl atof(ಧ್ರುವ ವರ್ಣ *_String);
  ದ್ವಿಗುಣ __cdecl _atof_l(ಧ್ರುವ ವರ್ಣ *_String,_locale_t _Locale);
#endif

  _CRTIMP ದ್ವಿಗುಣ __cdecl _cabs(ಸಂರಚನಾ _complex _ComplexA);
  ದ್ವಿಗುಣ __cdecl ceil(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl floor(ದ್ವಿಗುಣ _X);
  ದ್ವಿಗುಣ __cdecl frexp(ದ್ವಿಗುಣ _X,ಪೂರ್ಣಾಙ್ಕ *_Y);
  ದ್ವಿಗುಣ __cdecl _hypot(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _j0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _j1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _jn(ಪೂರ್ಣಾಙ್ಕ _X,ದ್ವಿಗುಣ _Y);
  ದ್ವಿಗುಣ __cdecl ldexp(ದ್ವಿಗುಣ _X,ಪೂರ್ಣಾಙ್ಕ _Y);
#ifndef _CRT_MATHERR_DEFINED
#define _CRT_MATHERR_DEFINED
  ಪೂರ್ಣಾಙ್ಕ __cdecl _matherr(ಸಂರಚನಾ _exception *_Except);
#endif
  ದ್ವಿಗುಣ __cdecl modf(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ *_Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _y0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _y1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _yn(ಪೂರ್ಣಾಙ್ಕ _X,ದ್ವಿಗುಣ _Y);

#ಯದಿ(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _set_SSE2_enable(ಪೂರ್ಣಾಙ್ಕ _Flag);
  /* from libmingwex */
  ಭಿನ್ನ __cdecl _hypotf(ಭಿನ್ನ _X,ಭಿನ್ನ _Y);
#endif

  ಭಿನ್ನ frexpf(ಭಿನ್ನ _X,ಪೂರ್ಣಾಙ್ಕ *_Y);
  ಭಿನ್ನ __cdecl ldexpf(ಭಿನ್ನ _X,ಪೂರ್ಣಾಙ್ಕ _Y);
  long ದ್ವಿಗುಣ __cdecl ldexpl(long ದ್ವಿಗುಣ _X,ಪೂರ್ಣಾಙ್ಕ _Y);
  ಭಿನ್ನ __cdecl acosf(ಭಿನ್ನ _X);
  ಭಿನ್ನ __cdecl asinf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl atanf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl atan2f(ಭಿನ್ನ _X,ಭಿನ್ನ _Y);
   ಭಿನ್ನ __cdecl cosf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl sinf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl tanf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl coshf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl sinhf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl tanhf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl expf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl expm1f(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl logf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl log10f(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl modff(ಭಿನ್ನ _X,ಭಿನ್ನ *_Y);
   ಭಿನ್ನ __cdecl powf(ಭಿನ್ನ _X,ಭಿನ್ನ _Y);
   ಭಿನ್ನ __cdecl sqrtf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl ceilf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl floorf(ಭಿನ್ನ _X);
  ಭಿನ್ನ __cdecl fmodf(ಭಿನ್ನ _X,ಭಿನ್ನ _Y);
   ಭಿನ್ನ __cdecl _hypotf(ಭಿನ್ನ _X,ಭಿನ್ನ _Y);
  ಭಿನ್ನ __cdecl fabsf(ಭಿನ್ನ _X);
#ಯದಿ !defined(__ia64__)
   /* from libmingwex */
   ಭಿನ್ನ __cdecl _copysignf (ಭಿನ್ನ ಸಂಖ್ಯೆ,ಭಿನ್ನ _Sign);
   ಭಿನ್ನ __cdecl _chgsignf (ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl _logbf(ಭಿನ್ನ _X);
   ಭಿನ್ನ __cdecl _nextafterf(ಭಿನ್ನ _X,ಭಿನ್ನ _Y);
   ಪೂರ್ಣಾಙ್ಕ __cdecl _finitef(ಭಿನ್ನ _X);
   ಪೂರ್ಣಾಙ್ಕ __cdecl _isnanf(ಭಿನ್ನ _X);
   ಪೂರ್ಣಾಙ್ಕ __cdecl _fpclassf(ಭಿನ್ನ _X);
#endif

#ifndef	NO_OLDNAMES
#define matherr _matherr

#define HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  ದ್ವಿಗುಣ __cdecl hypot(ದ್ವಿಗುಣ _X,ದ್ವಿಗುಣ _Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl j0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl j1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl jn(ಪೂರ್ಣಾಙ್ಕ _X,ದ್ವಿಗುಣ _Y);
  _CRTIMP ದ್ವಿಗುಣ __cdecl y0(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl y1(ದ್ವಿಗುಣ _X);
  _CRTIMP ದ್ವಿಗುಣ __cdecl yn(ಪೂರ್ಣಾಙ್ಕ _X,ದ್ವಿಗುಣ _Y);
#endif

#ifndef __NO_ISOCEXT
#ಯದಿ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
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

  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl __fpclassifyf (ಭಿನ್ನ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl __fpclassify (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl __fpclassifyl (long ದ್ವಿಗುಣ);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#define fpclassify(x) \
  _Generic(x, ಭಿನ್ನ: __fpclassifyf, ದ್ವಿಗುಣ: __fpclassify, long ದ್ವಿಗುಣ: __fpclassifyl)(x)

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

  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl __signbitf (ಭಿನ್ನ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl __signbit (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl __signbitl (long ದ್ವಿಗುಣ);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#define signbit(x) \
  _Generic(x, ಭಿನ್ನ: __signbitf, ದ್ವಿಗುಣ: __signbit, long ದ್ವಿಗುಣ: __signbitl)(x)

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl exp2(ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl exp2f(ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl exp2l(long ದ್ವಿಗುಣ);

#define FP_ILOGB0 ((ಪೂರ್ಣಾಙ್ಕ)0x80000000)
#define FP_ILOGBNAN ((ಪೂರ್ಣಾಙ್ಕ)0x80000000)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl ilogb (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl ilogbf (ಭಿನ್ನ);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl ilogbl (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl log1p(ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl log1pf(ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl log1pl(long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl log2 (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl log2f (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl log2l (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl logb (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl logbf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl logbl (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl modfl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ*);

  /* 7.12.6.13 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl scalbn (ದ್ವಿಗುಣ, ಪೂರ್ಣಾಙ್ಕ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl scalbnf (ಭಿನ್ನ, ಪೂರ್ಣಾಙ್ಕ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl scalbnl (long ದ್ವಿಗುಣ, ಪೂರ್ಣಾಙ್ಕ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl scalbln (ದ್ವಿಗುಣ, long);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl scalblnf (ಭಿನ್ನ, long);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl scalblnl (long ದ್ವಿಗುಣ, long);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl cbrt (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl cbrtf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl cbrtl (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl hypot (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl hypotf (ಭಿನ್ನ, ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl hypotl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl powl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl expl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl expm1l(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl coshl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl fabsl (long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl acosl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl asinl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl atanl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl atan2l(long ದ್ವಿಗುಣ,long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl sinhl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl tanhl(long ದ್ವಿಗುಣ);

  /* 7.12.8.1 The erf functions  */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl erf (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl erff (ಭಿನ್ನ);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl erfc (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl erfcf (ಭಿನ್ನ);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl lgamma (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl lgammaf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl lgammal (long ದ್ವಿಗುಣ);

  /* 7.12.8.4 The tgamma functions */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl tgamma (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl tgammaf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl tgammal (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl ceill (long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl floorl (long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl frexpl(long ದ್ವಿಗುಣ,ಪೂರ್ಣಾಙ್ಕ *);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl log10l(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl logl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl cosl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl sinl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl tanl(long ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ sqrtl(long ದ್ವಿಗುಣ);

  /* 7.12.9.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl nearbyint ( ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl nearbyintf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl nearbyintl (long ದ್ವಿಗುಣ);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl rint (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl rintf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl rintl (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ long __cdecl lrint (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long __cdecl lrintf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long __cdecl lrintl (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ long long __cdecl llrint (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long long __cdecl llrintf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long long __cdecl llrintl (long ದ್ವಿಗುಣ);

  #define FE_TONEAREST	0x0000
  #define FE_DOWNWARD	0x0400
  #define FE_UPWARD	0x0800
  #define FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl round (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl roundf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl roundl (long ದ್ವಿಗುಣ);

  /* 7.12.9.7  */
  ಬಾಹ್ಯ long __cdecl lround (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long __cdecl lroundf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long __cdecl lroundl (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ long long __cdecl llround (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ long long __cdecl llroundf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long long __cdecl llroundl (long ದ್ವಿಗುಣ);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl trunc (ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl truncf (ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl truncl (long ದ್ವಿಗುಣ);

  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl fmodl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);

  /* 7.12.10.2 */ 
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl remainder (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl remainderf (ಭಿನ್ನ, ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl remainderl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);

  /* 7.12.10.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl remquo(ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ಪೂರ್ಣಾಙ್ಕ *);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl remquof(ಭಿನ್ನ, ಭಿನ್ನ, ಪೂರ್ಣಾಙ್ಕ *);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl remquol(long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ, ಪೂರ್ಣಾಙ್ಕ *);

  /* 7.12.11.1 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl copysign (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ); /* in libmoldname.a */
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl copysignf (ಭಿನ್ನ, ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl copysignl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);

  /* 7.12.11.2 Return a NaN */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl nan(ಧ್ರುವ ವರ್ಣ *tagp);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl nanf(ಧ್ರುವ ವರ್ಣ *tagp);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl nanl(ಧ್ರುವ ವರ್ಣ *tagp);

#ifndef __STRICT_ANSI__
#define _nan() nan("")
#define _nanf() nanf("")
#define _nanl() nanl("")
#endif

  /* 7.12.11.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl nextafter (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ); /* in libmoldname.a */
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl nextafterf (ಭಿನ್ನ, ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl nextafterl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fdim (ದ್ವಿಗುಣ x, ದ್ವಿಗುಣ y);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl fdimf (ಭಿನ್ನ x, ಭಿನ್ನ y);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl fdiml (long ದ್ವಿಗುಣ x, long ದ್ವಿಗುಣ y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fmax  (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl fmaxf (ಭಿನ್ನ, ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl fmaxl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);

  /* 7.12.12.3 */
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fmin (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl fminf (ಭಿನ್ನ, ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl fminl (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  ಬಾಹ್ಯ ದ್ವಿಗುಣ __cdecl fma (ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ);
  ಬಾಹ್ಯ ಭಿನ್ನ __cdecl fmaf (ಭಿನ್ನ, ಭಿನ್ನ, ಭಿನ್ನ);
  ಬಾಹ್ಯ long ದ್ವಿಗುಣ __cdecl fmal (long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ, long ದ್ವಿಗುಣ);


#endif /* __STDC_VERSION__ >= 199901L */
#endif /* __NO_ISOCEXT */

#ifdef __cplusplus
}
#endif
#pragma pack(ತೆಗೆ)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#ಅನ್ತರ್ಭಾವ "tcc/tcc_libm.h"

#endif /* End _MATH_H_ */

