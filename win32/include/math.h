/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _MATH_H_
#تعریف_کن _MATH_H_

#إذا __GNUC__ >= 3
#رهنمود GCC system_سرآیند
#پایان_اگر

#ضمن <_mingw.h>

بنية exception;

#رهنمود pack(افزودن,_CRT_PACKING)

#تعریف_کن _DOMAIN 1
#تعریف_کن _SING 2
#تعریف_کن سرریز 3
#تعریف_کن _UNDERFLOW 4
#تعریف_کن _TLOSS 5
#تعریف_کن _PLOSS 6

#اگر_تعریف_نشده __STRICT_ANSI__
#اگر_تعریف_نشده	NO_OLDNAMES
#تعریف_کن DOMAIN _DOMAIN
#تعریف_کن SING _SING
#تعریف_کن سرریز_2 سرریز
#تعریف_کن UNDERFLOW _UNDERFLOW
#تعریف_کن TLOSS _TLOSS
#تعریف_کن PLOSS _PLOSS
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده __STRICT_ANSI__
#تعریف_کن M_E 2.71828182845904523536
#تعریف_کن M_LOG2E 1.44269504088896340736
#تعریف_کن M_LOG10E 0.434294481903251827651
#تعریف_کن M_LN2 0.693147180559945309417
#تعریف_کن M_LN10 2.30258509299404568402
#تعریف_کن M_PI 3.14159265358979323846
#تعریف_کن M_PI_2 1.57079632679489661923
#تعریف_کن M_PI_4 0.785398163397448309616
#تعریف_کن M_1_PI 0.318309886183790671538
#تعریف_کن M_2_PI 0.636619772367581343076
#تعریف_کن M_2_SQRTPI 1.12837916709551257390
#تعریف_کن M_SQRT2 1.41421356237309504880
#تعریف_کن M_SQRT1_2 0.707106781186547524401
#پایان_اگر

#اگر_تعریف_نشده __STRICT_ANSI__
/* See also float.h  */
#اگر_تعریف_نشده __MINGW_FPCLASS_DEFINED
#تعریف_کن __MINGW_FPCLASS_DEFINED 1
#تعریف_کن	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#تعریف_کن	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#تعریف_کن	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#تعریف_کن	_FPCLASS_NN	0x0008	/* Negative Normal */
#تعریف_کن	_FPCLASS_ND	0x0010	/* Negative Denormal */
#تعریف_کن	_FPCLASS_NZ	0x0020	/* Negative Zero */
#تعریف_کن	_FPCLASS_PZ	0x0040	/* Positive Zero */
#تعریف_کن	_FPCLASS_PD	0x0080	/* Positive Denormal */
#تعریف_کن	_FPCLASS_PN	0x0100	/* Positive Normal */
#تعریف_کن	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _EXCEPTION_DEFINED
#تعریف_کن _EXCEPTION_DEFINED
  بنية _exception {
    صحيح type;
    حرف *name;
    مزدوج arg1;
    مزدوج arg2;
    مزدوج retval;
  };
#پایان_اگر

#اگر_تعریف_نشده _COMPLEX_DEFINED
#تعریف_کن _COMPLEX_DEFINED
  بنية _complex {
    مزدوج x,y;
  };
#پایان_اگر

#تعریف_کن EDOM 33
#تعریف_کن ERANGE 34

#اگر_تعریف_نشده _HUGE
#اگر_تعریف_شده _MSVCRT_
  خارجي مزدوج *_HUGE;
#وإلا
  خارجي مزدوج *_imp___HUGE;
#تعریف_کن _HUGE	(*_imp___HUGE)
#پایان_اگر
#پایان_اگر

#تعریف_کن HUGE_VAL _HUGE

#اگر_تعریف_نشده _CRT_ABS_DEFINED
#تعریف_کن _CRT_ABS_DEFINED
  صحيح __cdecl قدر_مطلق(صحيح _X);
  دراز __cdecl labs(دراز _X);
#پایان_اگر
  مزدوج __cdecl acos(مزدوج _X);
  مزدوج __cdecl asin(مزدوج _X);
  مزدوج __cdecl atan(مزدوج _X);
  مزدوج __cdecl atan2(مزدوج _Y,مزدوج _X);
#اگر_تعریف_نشده _SIGN_DEFINED
#تعریف_کن _SIGN_DEFINED
  _CRTIMP مزدوج __cdecl _copysign (مزدوج عدد,مزدوج _Sign);
  _CRTIMP مزدوج __cdecl _chgsign (مزدوج _X);
#پایان_اگر
  مزدوج __cdecl کسینوس(مزدوج _X);
  مزدوج __cdecl cosh(مزدوج _X);
  مزدوج __cdecl نمایی_تابع(مزدوج _X);
  مزدوج __cdecl expm1(مزدوج _X);
  مزدوج __cdecl fabs(مزدوج _X);
  مزدوج __cdecl fmod(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl لگاریتم(مزدوج _X);
  مزدوج __cdecl log10(مزدوج _X);
  مزدوج __cdecl توان(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl سینوس(مزدوج _X);
  مزدوج __cdecl sinh(مزدوج _X);
  مزدوج __cdecl tan(مزدوج _X);
  مزدوج __cdecl tanh(مزدوج _X);
  مزدوج __cdecl جذر(مزدوج _X);
#اگر_تعریف_نشده _CRT_ATOF_DEFINED
#تعریف_کن _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#پایان_اگر

  _CRTIMP مزدوج __cdecl _cabs(بنية _complex _ComplexA);
  مزدوج __cdecl ceil(مزدوج _X);
  مزدوج __cdecl floor(مزدوج _X);
  مزدوج __cdecl frexp(مزدوج _X,صحيح *_Y);
  مزدوج __cdecl _hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl _j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _jn(صحيح _X,مزدوج _Y);
  مزدوج __cdecl ldexp(مزدوج _X,صحيح _Y);
#اگر_تعریف_نشده _CRT_MATHERR_DEFINED
#تعریف_کن _CRT_MATHERR_DEFINED
  صحيح __cdecl _matherr(بنية _exception *_Except);
#پایان_اگر
  مزدوج __cdecl modf(مزدوج _X,مزدوج *_Y);
  _CRTIMP مزدوج __cdecl _y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _yn(صحيح _X,مزدوج _Y);

#إذا(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl مجموعه_SSE2_enable(صحيح _Flag);
  /* from libmingwex */
  عائم __cdecl _hypotf(عائم _X,عائم _Y);
#پایان_اگر

  عائم frexpf(عائم _X,صحيح *_Y);
  عائم __cdecl ldexpf(عائم _X,صحيح _Y);
  دراز مزدوج __cdecl ldexpl(دراز مزدوج _X,صحيح _Y);
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
   عائم __cdecl _copysignf (عائم عدد,عائم _Sign);
   عائم __cdecl _chgsignf (عائم _X);
   عائم __cdecl _logbf(عائم _X);
   عائم __cdecl _nextafterf(عائم _X,عائم _Y);
   صحيح __cdecl _finitef(عائم _X);
   صحيح __cdecl _isnanf(عائم _X);
   صحيح __cdecl _fpclassf(عائم _X);
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
#تعریف_کن matherr _matherr

#تعریف_کن HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  مزدوج __cdecl hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl jn(صحيح _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl yn(صحيح _X,مزدوج _Y);
#پایان_اگر

#اگر_تعریف_نشده __NO_ISOCEXT
#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#تعریف_کن NAN (0.0F/0.0F)
#تعریف_کن HUGE_VALF (1.0F/0.0F)
#تعریف_کن HUGE_VALL (1.0L/0.0L)
#تعریف_کن INFINITY (1.0F/0.0F)


#تعریف_کن FP_NAN		0x0100
#تعریف_کن FP_NORMAL	0x0400
#تعریف_کن FP_INFINITE	(FP_NAN | FP_NORMAL)
#تعریف_کن FP_ZERO		0x4000
#تعریف_کن FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  خارجي صحيح __cdecl __fpclassifyf (عائم);
  خارجي صحيح __cdecl __fpclassify (مزدوج);
  خارجي صحيح __cdecl __fpclassifyl (دراز مزدوج);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#تعریف_کن fpclassify(x) \
  _Generic(x, عائم: __fpclassifyf, مزدوج: __fpclassify, دراز مزدوج: __fpclassifyl)(x)

  /* 7.12.3.2 */
#تعریف_کن isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#تعریف_کن isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#تعریف_کن isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#تعریف_کن isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  خارجي صحيح __cdecl __signbitf (عائم);
  خارجي صحيح __cdecl __signbit (مزدوج);
  خارجي صحيح __cdecl __signbitl (دراز مزدوج);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#تعریف_کن signbit(x) \
  _Generic(x, عائم: __signbitf, مزدوج: __signbit, دراز مزدوج: __signbitl)(x)

  خارجي مزدوج __cdecl exp2(مزدوج);
  خارجي عائم __cdecl exp2f(عائم);
  خارجي دراز مزدوج __cdecl exp2l(دراز مزدوج);

#تعریف_کن FP_ILOGB0 ((صحيح)0x80000000)
#تعریف_کن FP_ILOGBNAN ((صحيح)0x80000000)
  خارجي صحيح __cdecl ilogb (مزدوج);
  خارجي صحيح __cdecl ilogbf (عائم);
  خارجي صحيح __cdecl ilogbl (دراز مزدوج);

  خارجي مزدوج __cdecl log1p(مزدوج);
  خارجي عائم __cdecl log1pf(عائم);
  خارجي دراز مزدوج __cdecl log1pl(دراز مزدوج);

  خارجي مزدوج __cdecl log2 (مزدوج);
  خارجي عائم __cdecl log2f (عائم);
  خارجي دراز مزدوج __cdecl log2l (دراز مزدوج);

  خارجي مزدوج __cdecl logb (مزدوج);
  خارجي عائم __cdecl logbf (عائم);
  خارجي دراز مزدوج __cdecl logbl (دراز مزدوج);

  خارجي دراز مزدوج __cdecl modfl (دراز مزدوج, دراز مزدوج*);

  /* 7.12.6.13 */
  خارجي مزدوج __cdecl scalbn (مزدوج, صحيح);
  خارجي عائم __cdecl scalbnf (عائم, صحيح);
  خارجي دراز مزدوج __cdecl scalbnl (دراز مزدوج, صحيح);

  خارجي مزدوج __cdecl scalbln (مزدوج, دراز);
  خارجي عائم __cdecl scalblnf (عائم, دراز);
  خارجي دراز مزدوج __cdecl scalblnl (دراز مزدوج, دراز);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  خارجي مزدوج __cdecl cbrt (مزدوج);
  خارجي عائم __cdecl cbrtf (عائم);
  خارجي دراز مزدوج __cdecl cbrtl (دراز مزدوج);

  خارجي مزدوج __cdecl hypot (مزدوج, مزدوج);
  خارجي عائم __cdecl hypotf (عائم, عائم);
  خارجي دراز مزدوج __cdecl hypotl (دراز مزدوج, دراز مزدوج);

  خارجي دراز مزدوج __cdecl powl (دراز مزدوج, دراز مزدوج);
  خارجي دراز مزدوج __cdecl expl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl expm1l(دراز مزدوج);
  خارجي دراز مزدوج __cdecl coshl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl fabsl (دراز مزدوج);
  خارجي دراز مزدوج __cdecl acosl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl asinl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl atanl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl atan2l(دراز مزدوج,دراز مزدوج);
  خارجي دراز مزدوج __cdecl sinhl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl tanhl(دراز مزدوج);

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
  خارجي دراز مزدوج __cdecl lgammal (دراز مزدوج);

  /* 7.12.8.4 The tgamma functions */
  خارجي مزدوج __cdecl tgamma (مزدوج);
  خارجي عائم __cdecl tgammaf (عائم);
  خارجي دراز مزدوج __cdecl tgammal (دراز مزدوج);

  خارجي دراز مزدوج __cdecl ceill (دراز مزدوج);
  خارجي دراز مزدوج __cdecl floorl (دراز مزدوج);
  خارجي دراز مزدوج __cdecl frexpl(دراز مزدوج,صحيح *);
  خارجي دراز مزدوج __cdecl log10l(دراز مزدوج);
  خارجي دراز مزدوج __cdecl logl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl cosl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl sinl(دراز مزدوج);
  خارجي دراز مزدوج __cdecl tanl(دراز مزدوج);
  خارجي دراز مزدوج sqrtl(دراز مزدوج);

  /* 7.12.9.3 */
  خارجي مزدوج __cdecl nearbyint ( مزدوج);
  خارجي عائم __cdecl nearbyintf (عائم);
  خارجي دراز مزدوج __cdecl nearbyintl (دراز مزدوج);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  خارجي مزدوج __cdecl rint (مزدوج);
  خارجي عائم __cdecl rintf (عائم);
  خارجي دراز مزدوج __cdecl rintl (دراز مزدوج);

  خارجي دراز __cdecl lrint (مزدوج);
  خارجي دراز __cdecl lrintf (عائم);
  خارجي دراز __cdecl lrintl (دراز مزدوج);

  خارجي دراز دراز __cdecl llrint (مزدوج);
  خارجي دراز دراز __cdecl llrintf (عائم);
  خارجي دراز دراز __cdecl llrintl (دراز مزدوج);

  #تعریف_کن FE_TONEAREST	0x0000
  #تعریف_کن FE_DOWNWARD	0x0400
  #تعریف_کن FE_UPWARD	0x0800
  #تعریف_کن FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl دور (مزدوج);
  خارجي عائم __cdecl roundf (عائم);
  خارجي دراز مزدوج __cdecl roundl (دراز مزدوج);

  /* 7.12.9.7  */
  خارجي دراز __cdecl lround (مزدوج);
  خارجي دراز __cdecl lroundf (عائم);
  خارجي دراز __cdecl lroundl (دراز مزدوج);

  خارجي دراز دراز __cdecl llround (مزدوج);
  خارجي دراز دراز __cdecl llroundf (عائم);
  خارجي دراز دراز __cdecl llroundl (دراز مزدوج);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl trunc (مزدوج);
  خارجي عائم __cdecl truncf (عائم);
  خارجي دراز مزدوج __cdecl truncl (دراز مزدوج);

  خارجي دراز مزدوج __cdecl fmodl (دراز مزدوج, دراز مزدوج);

  /* 7.12.10.2 */ 
  خارجي مزدوج __cdecl remainder (مزدوج, مزدوج);
  خارجي عائم __cdecl remainderf (عائم, عائم);
  خارجي دراز مزدوج __cdecl remainderl (دراز مزدوج, دراز مزدوج);

  /* 7.12.10.3 */
  خارجي مزدوج __cdecl remquo(مزدوج, مزدوج, صحيح *);
  خارجي عائم __cdecl remquof(عائم, عائم, صحيح *);
  خارجي دراز مزدوج __cdecl remquol(دراز مزدوج, دراز مزدوج, صحيح *);

  /* 7.12.11.1 */
  خارجي مزدوج __cdecl copysign (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl copysignf (عائم, عائم);
  خارجي دراز مزدوج __cdecl copysignl (دراز مزدوج, دراز مزدوج);

  /* 7.12.11.2 Return a NaN */
  خارجي مزدوج __cdecl nan(ثابت حرف *tagp);
  خارجي عائم __cdecl nanf(ثابت حرف *tagp);
  خارجي دراز مزدوج __cdecl nanl(ثابت حرف *tagp);

#اگر_تعریف_نشده __STRICT_ANSI__
#تعریف_کن _nan() nan("")
#تعریف_کن _nanf() nanf("")
#تعریف_کن _nanl() nanl("")
#پایان_اگر

  /* 7.12.11.3 */
  خارجي مزدوج __cdecl nextafter (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl nextafterf (عائم, عائم);
  خارجي دراز مزدوج __cdecl nextafterl (دراز مزدوج, دراز مزدوج);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  خارجي مزدوج __cdecl fdim (مزدوج x, مزدوج y);
  خارجي عائم __cdecl fdimf (عائم x, عائم y);
  خارجي دراز مزدوج __cdecl fdiml (دراز مزدوج x, دراز مزدوج y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  خارجي مزدوج __cdecl fmax  (مزدوج, مزدوج);
  خارجي عائم __cdecl fmaxf (عائم, عائم);
  خارجي دراز مزدوج __cdecl fmaxl (دراز مزدوج, دراز مزدوج);

  /* 7.12.12.3 */
  خارجي مزدوج __cdecl fmin (مزدوج, مزدوج);
  خارجي عائم __cdecl fminf (عائم, عائم);
  خارجي دراز مزدوج __cdecl fminl (دراز مزدوج, دراز مزدوج);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  خارجي مزدوج __cdecl fma (مزدوج, مزدوج, مزدوج);
  خارجي عائم __cdecl fmaf (عائم, عائم, عائم);
  خارجي دراز مزدوج __cdecl fmal (دراز مزدوج, دراز مزدوج, دراز مزدوج);


#پایان_اگر /* __STDC_VERSION__ >= 199901L */
#پایان_اگر /* __NO_ISOCEXT */

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#رهنمود pack(برداشت)

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

#پایان_اگر /* End _MATH_H_ */

