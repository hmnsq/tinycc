/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _MATH_H_
#تعریف_کړه _MATH_H_

#إذا __GNUC__ >= 3
#لارښوونه GCC system_سرلیک
#د_که_پای

#ضمن <_mingw.h>

بنية exception;

#لارښوونه pack(ټېل,_CRT_PACKING)

#تعریف_کړه _DOMAIN 1
#تعریف_کړه _SING 2
#تعریف_کړه ډکېدنه 3
#تعریف_کړه _UNDERFLOW 4
#تعریف_کړه _TLOSS 5
#تعریف_کړه _PLOSS 6

#که_نه_تعریف_شوی __STRICT_ANSI__
#که_نه_تعریف_شوی	NO_OLDNAMES
#تعریف_کړه DOMAIN _DOMAIN
#تعریف_کړه SING _SING
#تعریف_کړه ډکېدنه_2 ډکېدنه
#تعریف_کړه UNDERFLOW _UNDERFLOW
#تعریف_کړه TLOSS _TLOSS
#تعریف_کړه PLOSS _PLOSS
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی __STRICT_ANSI__
#تعریف_کړه M_E 2.71828182845904523536
#تعریف_کړه M_LOG2E 1.44269504088896340736
#تعریف_کړه M_LOG10E 0.434294481903251827651
#تعریف_کړه M_LN2 0.693147180559945309417
#تعریف_کړه M_LN10 2.30258509299404568402
#تعریف_کړه M_PI 3.14159265358979323846
#تعریف_کړه M_PI_2 1.57079632679489661923
#تعریف_کړه M_PI_4 0.785398163397448309616
#تعریف_کړه M_1_PI 0.318309886183790671538
#تعریف_کړه M_2_PI 0.636619772367581343076
#تعریف_کړه M_2_SQRTPI 1.12837916709551257390
#تعریف_کړه M_SQRT2 1.41421356237309504880
#تعریف_کړه M_SQRT1_2 0.707106781186547524401
#د_که_پای

#که_نه_تعریف_شوی __STRICT_ANSI__
/* See also float.h  */
#که_نه_تعریف_شوی __MINGW_FPCLASS_DEFINED
#تعریف_کړه __MINGW_FPCLASS_DEFINED 1
#تعریف_کړه	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#تعریف_کړه	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#تعریف_کړه	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#تعریف_کړه	_FPCLASS_NN	0x0008	/* Negative Normal */
#تعریف_کړه	_FPCLASS_ND	0x0010	/* Negative Denormal */
#تعریف_کړه	_FPCLASS_NZ	0x0020	/* Negative Zero */
#تعریف_کړه	_FPCLASS_PZ	0x0040	/* Positive Zero */
#تعریف_کړه	_FPCLASS_PD	0x0080	/* Positive Denormal */
#تعریف_کړه	_FPCLASS_PN	0x0100	/* Positive Normal */
#تعریف_کړه	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _EXCEPTION_DEFINED
#تعریف_کړه _EXCEPTION_DEFINED
  بنية _exception {
    صحيح type;
    حرف *name;
    مزدوج arg1;
    مزدوج arg2;
    مزدوج retval;
  };
#د_که_پای

#که_نه_تعریف_شوی _COMPLEX_DEFINED
#تعریف_کړه _COMPLEX_DEFINED
  بنية _complex {
    مزدوج x,y;
  };
#د_که_پای

#تعریف_کړه EDOM 33
#تعریف_کړه ERANGE 34

#که_نه_تعریف_شوی _HUGE
#که_تعریف_شوی _MSVCRT_
  خارجي مزدوج *_HUGE;
#وإلا
  خارجي مزدوج *_imp___HUGE;
#تعریف_کړه _HUGE	(*_imp___HUGE)
#د_که_پای
#د_که_پای

#تعریف_کړه HUGE_VAL _HUGE

#که_نه_تعریف_شوی _CRT_ABS_DEFINED
#تعریف_کړه _CRT_ABS_DEFINED
  صحيح __cdecl مطلق_قیمت(صحيح _X);
  اوږد __cdecl labs(اوږد _X);
#د_که_پای
  مزدوج __cdecl acos(مزدوج _X);
  مزدوج __cdecl asin(مزدوج _X);
  مزدوج __cdecl atan(مزدوج _X);
  مزدوج __cdecl atan2(مزدوج _Y,مزدوج _X);
#که_نه_تعریف_شوی _SIGN_DEFINED
#تعریف_کړه _SIGN_DEFINED
  _CRTIMP مزدوج __cdecl _copysign (مزدوج شمېره,مزدوج _Sign);
  _CRTIMP مزدوج __cdecl _chgsign (مزدوج _X);
#د_که_پای
  مزدوج __cdecl کوساین(مزدوج _X);
  مزدوج __cdecl cosh(مزدوج _X);
  مزدوج __cdecl توانیز_تابع(مزدوج _X);
  مزدوج __cdecl expm1(مزدوج _X);
  مزدوج __cdecl fabs(مزدوج _X);
  مزدوج __cdecl fmod(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl لوګاریتم(مزدوج _X);
  مزدوج __cdecl log10(مزدوج _X);
  مزدوج __cdecl توان(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl ساین(مزدوج _X);
  مزدوج __cdecl sinh(مزدوج _X);
  مزدوج __cdecl tan(مزدوج _X);
  مزدوج __cdecl tanh(مزدوج _X);
  مزدوج __cdecl جذر(مزدوج _X);
#که_نه_تعریف_شوی _CRT_ATOF_DEFINED
#تعریف_کړه _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#د_که_پای

  _CRTIMP مزدوج __cdecl _cabs(بنية _complex _ComplexA);
  مزدوج __cdecl ceil(مزدوج _X);
  مزدوج __cdecl floor(مزدوج _X);
  مزدوج __cdecl frexp(مزدوج _X,صحيح *_Y);
  مزدوج __cdecl _hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl _j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _jn(صحيح _X,مزدوج _Y);
  مزدوج __cdecl ldexp(مزدوج _X,صحيح _Y);
#که_نه_تعریف_شوی _CRT_MATHERR_DEFINED
#تعریف_کړه _CRT_MATHERR_DEFINED
  صحيح __cdecl _matherr(بنية _exception *_Except);
#د_که_پای
  مزدوج __cdecl modf(مزدوج _X,مزدوج *_Y);
  _CRTIMP مزدوج __cdecl _y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _yn(صحيح _X,مزدوج _Y);

#إذا(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl سېټ_SSE2_enable(صحيح _Flag);
  /* from libmingwex */
  عائم __cdecl _hypotf(عائم _X,عائم _Y);
#د_که_پای

  عائم frexpf(عائم _X,صحيح *_Y);
  عائم __cdecl ldexpf(عائم _X,صحيح _Y);
  اوږد مزدوج __cdecl ldexpl(اوږد مزدوج _X,صحيح _Y);
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
   عائم __cdecl _copysignf (عائم شمېره,عائم _Sign);
   عائم __cdecl _chgsignf (عائم _X);
   عائم __cdecl _logbf(عائم _X);
   عائم __cdecl _nextafterf(عائم _X,عائم _Y);
   صحيح __cdecl _finitef(عائم _X);
   صحيح __cdecl _isnanf(عائم _X);
   صحيح __cdecl _fpclassf(عائم _X);
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
#تعریف_کړه matherr _matherr

#تعریف_کړه HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  مزدوج __cdecl hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl jn(صحيح _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl yn(صحيح _X,مزدوج _Y);
#د_که_پای

#که_نه_تعریف_شوی __NO_ISOCEXT
#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#تعریف_کړه NAN (0.0F/0.0F)
#تعریف_کړه HUGE_VALF (1.0F/0.0F)
#تعریف_کړه HUGE_VALL (1.0L/0.0L)
#تعریف_کړه INFINITY (1.0F/0.0F)


#تعریف_کړه FP_NAN		0x0100
#تعریف_کړه FP_NORMAL	0x0400
#تعریف_کړه FP_INFINITE	(FP_NAN | FP_NORMAL)
#تعریف_کړه FP_ZERO		0x4000
#تعریف_کړه FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  خارجي صحيح __cdecl __fpclassifyf (عائم);
  خارجي صحيح __cdecl __fpclassify (مزدوج);
  خارجي صحيح __cdecl __fpclassifyl (اوږد مزدوج);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#تعریف_کړه fpclassify(x) \
  _Generic(x, عائم: __fpclassifyf, مزدوج: __fpclassify, اوږد مزدوج: __fpclassifyl)(x)

  /* 7.12.3.2 */
#تعریف_کړه isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#تعریف_کړه isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#تعریف_کړه isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#تعریف_کړه isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  خارجي صحيح __cdecl __signbitf (عائم);
  خارجي صحيح __cdecl __signbit (مزدوج);
  خارجي صحيح __cdecl __signbitl (اوږد مزدوج);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#تعریف_کړه signbit(x) \
  _Generic(x, عائم: __signbitf, مزدوج: __signbit, اوږد مزدوج: __signbitl)(x)

  خارجي مزدوج __cdecl exp2(مزدوج);
  خارجي عائم __cdecl exp2f(عائم);
  خارجي اوږد مزدوج __cdecl exp2l(اوږد مزدوج);

#تعریف_کړه FP_ILOGB0 ((صحيح)0x80000000)
#تعریف_کړه FP_ILOGBNAN ((صحيح)0x80000000)
  خارجي صحيح __cdecl ilogb (مزدوج);
  خارجي صحيح __cdecl ilogbf (عائم);
  خارجي صحيح __cdecl ilogbl (اوږد مزدوج);

  خارجي مزدوج __cdecl log1p(مزدوج);
  خارجي عائم __cdecl log1pf(عائم);
  خارجي اوږد مزدوج __cdecl log1pl(اوږد مزدوج);

  خارجي مزدوج __cdecl log2 (مزدوج);
  خارجي عائم __cdecl log2f (عائم);
  خارجي اوږد مزدوج __cdecl log2l (اوږد مزدوج);

  خارجي مزدوج __cdecl logb (مزدوج);
  خارجي عائم __cdecl logbf (عائم);
  خارجي اوږد مزدوج __cdecl logbl (اوږد مزدوج);

  خارجي اوږد مزدوج __cdecl modfl (اوږد مزدوج, اوږد مزدوج*);

  /* 7.12.6.13 */
  خارجي مزدوج __cdecl scalbn (مزدوج, صحيح);
  خارجي عائم __cdecl scalbnf (عائم, صحيح);
  خارجي اوږد مزدوج __cdecl scalbnl (اوږد مزدوج, صحيح);

  خارجي مزدوج __cdecl scalbln (مزدوج, اوږد);
  خارجي عائم __cdecl scalblnf (عائم, اوږد);
  خارجي اوږد مزدوج __cdecl scalblnl (اوږد مزدوج, اوږد);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  خارجي مزدوج __cdecl cbrt (مزدوج);
  خارجي عائم __cdecl cbrtf (عائم);
  خارجي اوږد مزدوج __cdecl cbrtl (اوږد مزدوج);

  خارجي مزدوج __cdecl hypot (مزدوج, مزدوج);
  خارجي عائم __cdecl hypotf (عائم, عائم);
  خارجي اوږد مزدوج __cdecl hypotl (اوږد مزدوج, اوږد مزدوج);

  خارجي اوږد مزدوج __cdecl powl (اوږد مزدوج, اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl expl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl expm1l(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl coshl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl fabsl (اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl acosl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl asinl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl atanl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl atan2l(اوږد مزدوج,اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl sinhl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl tanhl(اوږد مزدوج);

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
  خارجي اوږد مزدوج __cdecl lgammal (اوږد مزدوج);

  /* 7.12.8.4 The tgamma functions */
  خارجي مزدوج __cdecl tgamma (مزدوج);
  خارجي عائم __cdecl tgammaf (عائم);
  خارجي اوږد مزدوج __cdecl tgammal (اوږد مزدوج);

  خارجي اوږد مزدوج __cdecl ceill (اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl floorl (اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl frexpl(اوږد مزدوج,صحيح *);
  خارجي اوږد مزدوج __cdecl log10l(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl logl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl cosl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl sinl(اوږد مزدوج);
  خارجي اوږد مزدوج __cdecl tanl(اوږد مزدوج);
  خارجي اوږد مزدوج sqrtl(اوږد مزدوج);

  /* 7.12.9.3 */
  خارجي مزدوج __cdecl nearbyint ( مزدوج);
  خارجي عائم __cdecl nearbyintf (عائم);
  خارجي اوږد مزدوج __cdecl nearbyintl (اوږد مزدوج);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  خارجي مزدوج __cdecl rint (مزدوج);
  خارجي عائم __cdecl rintf (عائم);
  خارجي اوږد مزدوج __cdecl rintl (اوږد مزدوج);

  خارجي اوږد __cdecl lrint (مزدوج);
  خارجي اوږد __cdecl lrintf (عائم);
  خارجي اوږد __cdecl lrintl (اوږد مزدوج);

  خارجي اوږد اوږد __cdecl llrint (مزدوج);
  خارجي اوږد اوږد __cdecl llrintf (عائم);
  خارجي اوږد اوږد __cdecl llrintl (اوږد مزدوج);

  #تعریف_کړه FE_TONEAREST	0x0000
  #تعریف_کړه FE_DOWNWARD	0x0400
  #تعریف_کړه FE_UPWARD	0x0800
  #تعریف_کړه FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl پړاو (مزدوج);
  خارجي عائم __cdecl roundf (عائم);
  خارجي اوږد مزدوج __cdecl roundl (اوږد مزدوج);

  /* 7.12.9.7  */
  خارجي اوږد __cdecl lround (مزدوج);
  خارجي اوږد __cdecl lroundf (عائم);
  خارجي اوږد __cdecl lroundl (اوږد مزدوج);

  خارجي اوږد اوږد __cdecl llround (مزدوج);
  خارجي اوږد اوږد __cdecl llroundf (عائم);
  خارجي اوږد اوږد __cdecl llroundl (اوږد مزدوج);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl trunc (مزدوج);
  خارجي عائم __cdecl truncf (عائم);
  خارجي اوږد مزدوج __cdecl truncl (اوږد مزدوج);

  خارجي اوږد مزدوج __cdecl fmodl (اوږد مزدوج, اوږد مزدوج);

  /* 7.12.10.2 */ 
  خارجي مزدوج __cdecl remainder (مزدوج, مزدوج);
  خارجي عائم __cdecl remainderf (عائم, عائم);
  خارجي اوږد مزدوج __cdecl remainderl (اوږد مزدوج, اوږد مزدوج);

  /* 7.12.10.3 */
  خارجي مزدوج __cdecl remquo(مزدوج, مزدوج, صحيح *);
  خارجي عائم __cdecl remquof(عائم, عائم, صحيح *);
  خارجي اوږد مزدوج __cdecl remquol(اوږد مزدوج, اوږد مزدوج, صحيح *);

  /* 7.12.11.1 */
  خارجي مزدوج __cdecl copysign (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl copysignf (عائم, عائم);
  خارجي اوږد مزدوج __cdecl copysignl (اوږد مزدوج, اوږد مزدوج);

  /* 7.12.11.2 Return a NaN */
  خارجي مزدوج __cdecl nan(ثابت حرف *tagp);
  خارجي عائم __cdecl nanf(ثابت حرف *tagp);
  خارجي اوږد مزدوج __cdecl nanl(ثابت حرف *tagp);

#که_نه_تعریف_شوی __STRICT_ANSI__
#تعریف_کړه _nan() nan("")
#تعریف_کړه _nanf() nanf("")
#تعریف_کړه _nanl() nanl("")
#د_که_پای

  /* 7.12.11.3 */
  خارجي مزدوج __cdecl nextafter (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl nextafterf (عائم, عائم);
  خارجي اوږد مزدوج __cdecl nextafterl (اوږد مزدوج, اوږد مزدوج);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  خارجي مزدوج __cdecl fdim (مزدوج x, مزدوج y);
  خارجي عائم __cdecl fdimf (عائم x, عائم y);
  خارجي اوږد مزدوج __cdecl fdiml (اوږد مزدوج x, اوږد مزدوج y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  خارجي مزدوج __cdecl fmax  (مزدوج, مزدوج);
  خارجي عائم __cdecl fmaxf (عائم, عائم);
  خارجي اوږد مزدوج __cdecl fmaxl (اوږد مزدوج, اوږد مزدوج);

  /* 7.12.12.3 */
  خارجي مزدوج __cdecl fmin (مزدوج, مزدوج);
  خارجي عائم __cdecl fminf (عائم, عائم);
  خارجي اوږد مزدوج __cdecl fminl (اوږد مزدوج, اوږد مزدوج);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  خارجي مزدوج __cdecl fma (مزدوج, مزدوج, مزدوج);
  خارجي عائم __cdecl fmaf (عائم, عائم, عائم);
  خارجي اوږد مزدوج __cdecl fmal (اوږد مزدوج, اوږد مزدوج, اوږد مزدوج);


#د_که_پای /* __STDC_VERSION__ >= 199901L */
#د_که_پای /* __NO_ISOCEXT */

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#لارښوونه pack(راوباسه)

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

#د_که_پای /* End _MATH_H_ */

