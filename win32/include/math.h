/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MATH_H_
#define _MATH_H_

#ଯଦି __GNUC__ >= 3
#pragma GCC system_header
#endif

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

ସଂରଚନା exception;

#pragma pack(ଠେଲ,_CRT_PACKING)

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
ବାହ୍ୟ "C" {
#endif

#ifndef _EXCEPTION_DEFINED
#define _EXCEPTION_DEFINED
  ସଂରଚନା _exception {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା type;
    ଅକ୍ଷର *name;
    ଦ୍ୱିଗୁଣ arg1;
    ଦ୍ୱିଗୁଣ arg2;
    ଦ୍ୱିଗୁଣ retval;
  };
#endif

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
  ସଂରଚନା _complex {
    ଦ୍ୱିଗୁଣ x,y;
  };
#endif

#define EDOM 33
#define ERANGE 34

#ifndef _HUGE
#ifdef _MSVCRT_
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ *_HUGE;
#ଅନ୍ୟଥା
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ *_imp___HUGE;
#define _HUGE	(*_imp___HUGE)
#endif
#endif

#define HUGE_VAL _HUGE

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl abs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _X);
  long __cdecl labs(long _X);
#endif
  ଦ୍ୱିଗୁଣ __cdecl acos(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl asin(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl atan(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl atan2(ଦ୍ୱିଗୁଣ _Y,ଦ୍ୱିଗୁଣ _X);
#ifndef _SIGN_DEFINED
#define _SIGN_DEFINED
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _copysign (ଦ୍ୱିଗୁଣ ସଂଖ୍ୟା,ଦ୍ୱିଗୁଣ _Sign);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _chgsign (ଦ୍ୱିଗୁଣ _X);
#endif
  ଦ୍ୱିଗୁଣ __cdecl cos(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl cosh(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl exp(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl expm1(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl fabs(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl fmod(ଦ୍ୱିଗୁଣ _X,ଦ୍ୱିଗୁଣ _Y);
  ଦ୍ୱିଗୁଣ __cdecl log(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl log10(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl pow(ଦ୍ୱିଗୁଣ _X,ଦ୍ୱିଗୁଣ _Y);
  ଦ୍ୱିଗୁଣ __cdecl sin(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl sinh(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl tan(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl tanh(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl sqrt(ଦ୍ୱିଗୁଣ _X);
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  ଦ୍ୱିଗୁଣ __cdecl atof(ଅଚଳ ଅକ୍ଷର *_String);
  ଦ୍ୱିଗୁଣ __cdecl _atof_l(ଅଚଳ ଅକ୍ଷର *_String,_locale_t _Locale);
#endif

  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _cabs(ସଂରଚନା _complex _ComplexA);
  ଦ୍ୱିଗୁଣ __cdecl ceil(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl floor(ଦ୍ୱିଗୁଣ _X);
  ଦ୍ୱିଗୁଣ __cdecl frexp(ଦ୍ୱିଗୁଣ _X,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_Y);
  ଦ୍ୱିଗୁଣ __cdecl _hypot(ଦ୍ୱିଗୁଣ _X,ଦ୍ୱିଗୁଣ _Y);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _j0(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _j1(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _jn(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _X,ଦ୍ୱିଗୁଣ _Y);
  ଦ୍ୱିଗୁଣ __cdecl ldexp(ଦ୍ୱିଗୁଣ _X,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Y);
#ifndef _CRT_MATHERR_DEFINED
#define _CRT_MATHERR_DEFINED
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _matherr(ସଂରଚନା _exception *_Except);
#endif
  ଦ୍ୱିଗୁଣ __cdecl modf(ଦ୍ୱିଗୁଣ _X,ଦ୍ୱିଗୁଣ *_Y);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _y0(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _y1(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _yn(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _X,ଦ୍ୱିଗୁଣ _Y);

#ଯଦି(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _set_SSE2_enable(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Flag);
  /* from libmingwex */
  ଦଶମିକ __cdecl _hypotf(ଦଶମିକ _X,ଦଶମିକ _Y);
#endif

  ଦଶମିକ frexpf(ଦଶମିକ _X,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_Y);
  ଦଶମିକ __cdecl ldexpf(ଦଶମିକ _X,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Y);
  long ଦ୍ୱିଗୁଣ __cdecl ldexpl(long ଦ୍ୱିଗୁଣ _X,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Y);
  ଦଶମିକ __cdecl acosf(ଦଶମିକ _X);
  ଦଶମିକ __cdecl asinf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl atanf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl atan2f(ଦଶମିକ _X,ଦଶମିକ _Y);
   ଦଶମିକ __cdecl cosf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl sinf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl tanf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl coshf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl sinhf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl tanhf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl expf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl expm1f(ଦଶମିକ _X);
   ଦଶମିକ __cdecl logf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl log10f(ଦଶମିକ _X);
   ଦଶମିକ __cdecl modff(ଦଶମିକ _X,ଦଶମିକ *_Y);
   ଦଶମିକ __cdecl powf(ଦଶମିକ _X,ଦଶମିକ _Y);
   ଦଶମିକ __cdecl sqrtf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl ceilf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl floorf(ଦଶମିକ _X);
  ଦଶମିକ __cdecl fmodf(ଦଶମିକ _X,ଦଶମିକ _Y);
   ଦଶମିକ __cdecl _hypotf(ଦଶମିକ _X,ଦଶମିକ _Y);
  ଦଶମିକ __cdecl fabsf(ଦଶମିକ _X);
#ଯଦି !defined(__ia64__)
   /* from libmingwex */
   ଦଶମିକ __cdecl _copysignf (ଦଶମିକ ସଂଖ୍ୟା,ଦଶମିକ _Sign);
   ଦଶମିକ __cdecl _chgsignf (ଦଶମିକ _X);
   ଦଶମିକ __cdecl _logbf(ଦଶମିକ _X);
   ଦଶମିକ __cdecl _nextafterf(ଦଶମିକ _X,ଦଶମିକ _Y);
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _finitef(ଦଶମିକ _X);
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isnanf(ଦଶମିକ _X);
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fpclassf(ଦଶମିକ _X);
#endif

#ifndef	NO_OLDNAMES
#define matherr _matherr

#define HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  ଦ୍ୱିଗୁଣ __cdecl hypot(ଦ୍ୱିଗୁଣ _X,ଦ୍ୱିଗୁଣ _Y);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl j0(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl j1(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl jn(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _X,ଦ୍ୱିଗୁଣ _Y);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl y0(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl y1(ଦ୍ୱିଗୁଣ _X);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl yn(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _X,ଦ୍ୱିଗୁଣ _Y);
#endif

#ifndef __NO_ISOCEXT
#ଯଦି (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
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

  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __fpclassifyf (ଦଶମିକ);
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __fpclassify (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __fpclassifyl (long ଦ୍ୱିଗୁଣ);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#define fpclassify(x) \
  _Generic(x, ଦଶମିକ: __fpclassifyf, ଦ୍ୱିଗୁଣ: __fpclassify, long ଦ୍ୱିଗୁଣ: __fpclassifyl)(x)

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

  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __signbitf (ଦଶମିକ);
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __signbit (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __signbitl (long ଦ୍ୱିଗୁଣ);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#define signbit(x) \
  _Generic(x, ଦଶମିକ: __signbitf, ଦ୍ୱିଗୁଣ: __signbit, long ଦ୍ୱିଗୁଣ: __signbitl)(x)

  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl exp2(ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl exp2f(ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl exp2l(long ଦ୍ୱିଗୁଣ);

#define FP_ILOGB0 ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)0x80000000)
#define FP_ILOGBNAN ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)0x80000000)
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ilogb (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ilogbf (ଦଶମିକ);
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ilogbl (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl log1p(ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl log1pf(ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl log1pl(long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl log2 (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl log2f (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl log2l (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl logb (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl logbf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl logbl (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl modfl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ*);

  /* 7.12.6.13 */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl scalbn (ଦ୍ୱିଗୁଣ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  ବାହ୍ୟ ଦଶମିକ __cdecl scalbnf (ଦଶମିକ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl scalbnl (long ଦ୍ୱିଗୁଣ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl scalbln (ଦ୍ୱିଗୁଣ, long);
  ବାହ୍ୟ ଦଶମିକ __cdecl scalblnf (ଦଶମିକ, long);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl scalblnl (long ଦ୍ୱିଗୁଣ, long);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl cbrt (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl cbrtf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl cbrtl (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl hypot (ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl hypotf (ଦଶମିକ, ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl hypotl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl powl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl expl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl expm1l(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl coshl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl fabsl (long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl acosl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl asinl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl atanl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl atan2l(long ଦ୍ୱିଗୁଣ,long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl sinhl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl tanhl(long ଦ୍ୱିଗୁଣ);

  /* 7.12.8.1 The erf functions  */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl erf (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl erff (ଦଶମିକ);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl erfc (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl erfcf (ଦଶମିକ);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl lgamma (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl lgammaf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl lgammal (long ଦ୍ୱିଗୁଣ);

  /* 7.12.8.4 The tgamma functions */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl tgamma (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl tgammaf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl tgammal (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl ceill (long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl floorl (long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl frexpl(long ଦ୍ୱିଗୁଣ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl log10l(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl logl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl cosl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl sinl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl tanl(long ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ sqrtl(long ଦ୍ୱିଗୁଣ);

  /* 7.12.9.3 */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl nearbyint ( ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl nearbyintf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl nearbyintl (long ଦ୍ୱିଗୁଣ);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl rint (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl rintf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl rintl (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ long __cdecl lrint (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long __cdecl lrintf (ଦଶମିକ);
  ବାହ୍ୟ long __cdecl lrintl (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ long long __cdecl llrint (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long long __cdecl llrintf (ଦଶମିକ);
  ବାହ୍ୟ long long __cdecl llrintl (long ଦ୍ୱିଗୁଣ);

  #define FE_TONEAREST	0x0000
  #define FE_DOWNWARD	0x0400
  #define FE_UPWARD	0x0800
  #define FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl round (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl roundf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl roundl (long ଦ୍ୱିଗୁଣ);

  /* 7.12.9.7  */
  ବାହ୍ୟ long __cdecl lround (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long __cdecl lroundf (ଦଶମିକ);
  ବାହ୍ୟ long __cdecl lroundl (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ long long __cdecl llround (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ long long __cdecl llroundf (ଦଶମିକ);
  ବାହ୍ୟ long long __cdecl llroundl (long ଦ୍ୱିଗୁଣ);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl trunc (ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl truncf (ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl truncl (long ଦ୍ୱିଗୁଣ);

  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl fmodl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);

  /* 7.12.10.2 */ 
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl remainder (ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl remainderf (ଦଶମିକ, ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl remainderl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);

  /* 7.12.10.3 */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl remquo(ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *);
  ବାହ୍ୟ ଦଶମିକ __cdecl remquof(ଦଶମିକ, ଦଶମିକ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl remquol(long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *);

  /* 7.12.11.1 */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl copysign (ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ); /* in libmoldname.a */
  ବାହ୍ୟ ଦଶମିକ __cdecl copysignf (ଦଶମିକ, ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl copysignl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);

  /* 7.12.11.2 Return a NaN */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl nan(ଅଚଳ ଅକ୍ଷର *tagp);
  ବାହ୍ୟ ଦଶମିକ __cdecl nanf(ଅଚଳ ଅକ୍ଷର *tagp);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl nanl(ଅଚଳ ଅକ୍ଷର *tagp);

#ifndef __STRICT_ANSI__
#define _nan() nan("")
#define _nanf() nanf("")
#define _nanl() nanl("")
#endif

  /* 7.12.11.3 */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl nextafter (ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ); /* in libmoldname.a */
  ବାହ୍ୟ ଦଶମିକ __cdecl nextafterf (ଦଶମିକ, ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl nextafterl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl fdim (ଦ୍ୱିଗୁଣ x, ଦ୍ୱିଗୁଣ y);
  ବାହ୍ୟ ଦଶମିକ __cdecl fdimf (ଦଶମିକ x, ଦଶମିକ y);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl fdiml (long ଦ୍ୱିଗୁଣ x, long ଦ୍ୱିଗୁଣ y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl fmax  (ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl fmaxf (ଦଶମିକ, ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl fmaxl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);

  /* 7.12.12.3 */
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl fmin (ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl fminf (ଦଶମିକ, ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl fminl (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  ବାହ୍ୟ ଦ୍ୱିଗୁଣ __cdecl fma (ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ);
  ବାହ୍ୟ ଦଶମିକ __cdecl fmaf (ଦଶମିକ, ଦଶମିକ, ଦଶମିକ);
  ବାହ୍ୟ long ଦ୍ୱିଗୁଣ __cdecl fmal (long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ, long ଦ୍ୱିଗୁଣ);


#endif /* __STDC_VERSION__ >= 199901L */
#endif /* __NO_ISOCEXT */

#ifdef __cplusplus
}
#endif
#pragma pack(କାଢ଼)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#ଅନ୍ତର୍ଭାଵ "tcc/tcc_libm.h"

#endif /* End _MATH_H_ */

