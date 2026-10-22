/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _MATH_H_
#وصف_ڪريو _MATH_H_

#إذا __GNUC__ >= 3
#هدايت GCC system_سرو
#جيڪڏهن_پورو

#ضمن <_mingw.h>

بنية exception;

#هدايت pack(ڌڪو,_CRT_PACKING)

#وصف_ڪريو _DOMAIN 1
#وصف_ڪريو _SING 2
#وصف_ڪريو حد_کان_مٿي 3
#وصف_ڪريو _UNDERFLOW 4
#وصف_ڪريو _TLOSS 5
#وصف_ڪريو _PLOSS 6

#جيڪڏهن_وصف_نه_ٿيل __STRICT_ANSI__
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#وصف_ڪريو DOMAIN _DOMAIN
#وصف_ڪريو SING _SING
#وصف_ڪريو حد_کان_مٿي_2 حد_کان_مٿي
#وصف_ڪريو UNDERFLOW _UNDERFLOW
#وصف_ڪريو TLOSS _TLOSS
#وصف_ڪريو PLOSS _PLOSS
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __STRICT_ANSI__
#وصف_ڪريو M_E 2.71828182845904523536
#وصف_ڪريو M_LOG2E 1.44269504088896340736
#وصف_ڪريو M_LOG10E 0.434294481903251827651
#وصف_ڪريو M_LN2 0.693147180559945309417
#وصف_ڪريو M_LN10 2.30258509299404568402
#وصف_ڪريو M_PI 3.14159265358979323846
#وصف_ڪريو M_PI_2 1.57079632679489661923
#وصف_ڪريو M_PI_4 0.785398163397448309616
#وصف_ڪريو M_1_PI 0.318309886183790671538
#وصف_ڪريو M_2_PI 0.636619772367581343076
#وصف_ڪريو M_2_SQRTPI 1.12837916709551257390
#وصف_ڪريو M_SQRT2 1.41421356237309504880
#وصف_ڪريو M_SQRT1_2 0.707106781186547524401
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __STRICT_ANSI__
/* See also float.h  */
#جيڪڏهن_وصف_نه_ٿيل __MINGW_FPCLASS_DEFINED
#وصف_ڪريو __MINGW_FPCLASS_DEFINED 1
#وصف_ڪريو	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#وصف_ڪريو	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#وصف_ڪريو	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#وصف_ڪريو	_FPCLASS_NN	0x0008	/* Negative Normal */
#وصف_ڪريو	_FPCLASS_ND	0x0010	/* Negative Denormal */
#وصف_ڪريو	_FPCLASS_NZ	0x0020	/* Negative Zero */
#وصف_ڪريو	_FPCLASS_PZ	0x0040	/* Positive Zero */
#وصف_ڪريو	_FPCLASS_PD	0x0080	/* Positive Denormal */
#وصف_ڪريو	_FPCLASS_PN	0x0100	/* Positive Normal */
#وصف_ڪريو	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _EXCEPTION_DEFINED
#وصف_ڪريو _EXCEPTION_DEFINED
  بنية _exception {
    صحيح type;
    حرف *name;
    مزدوج arg1;
    مزدوج arg2;
    مزدوج retval;
  };
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _COMPLEX_DEFINED
#وصف_ڪريو _COMPLEX_DEFINED
  بنية _complex {
    مزدوج x,y;
  };
#جيڪڏهن_پورو

#وصف_ڪريو EDOM 33
#وصف_ڪريو ERANGE 34

#جيڪڏهن_وصف_نه_ٿيل _HUGE
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي مزدوج *_HUGE;
#وإلا
  خارجي مزدوج *_imp___HUGE;
#وصف_ڪريو _HUGE	(*_imp___HUGE)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو HUGE_VAL _HUGE

#جيڪڏهن_وصف_نه_ٿيل _CRT_ABS_DEFINED
#وصف_ڪريو _CRT_ABS_DEFINED
  صحيح __cdecl مطلق_قدر(صحيح _X);
  ڊگهو __cdecl labs(ڊگهو _X);
#جيڪڏهن_پورو
  مزدوج __cdecl acos(مزدوج _X);
  مزدوج __cdecl asin(مزدوج _X);
  مزدوج __cdecl atan(مزدوج _X);
  مزدوج __cdecl atan2(مزدوج _Y,مزدوج _X);
#جيڪڏهن_وصف_نه_ٿيل _SIGN_DEFINED
#وصف_ڪريو _SIGN_DEFINED
  _CRTIMP مزدوج __cdecl _copysign (مزدوج عدد,مزدوج _Sign);
  _CRTIMP مزدوج __cdecl _chgsign (مزدوج _X);
#جيڪڏهن_پورو
  مزدوج __cdecl جيب_تمام(مزدوج _X);
  مزدوج __cdecl cosh(مزدوج _X);
  مزدوج __cdecl قوت_نما(مزدوج _X);
  مزدوج __cdecl expm1(مزدوج _X);
  مزدوج __cdecl fabs(مزدوج _X);
  مزدوج __cdecl fmod(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl لاگرٿم(مزدوج _X);
  مزدوج __cdecl log10(مزدوج _X);
  مزدوج __cdecl قوت(مزدوج _X,مزدوج _Y);
  مزدوج __cdecl جيب(مزدوج _X);
  مزدوج __cdecl sinh(مزدوج _X);
  مزدوج __cdecl tan(مزدوج _X);
  مزدوج __cdecl tanh(مزدوج _X);
  مزدوج __cdecl جذر(مزدوج _X);
#جيڪڏهن_وصف_نه_ٿيل _CRT_ATOF_DEFINED
#وصف_ڪريو _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#جيڪڏهن_پورو

  _CRTIMP مزدوج __cdecl _cabs(بنية _complex _ComplexA);
  مزدوج __cdecl ceil(مزدوج _X);
  مزدوج __cdecl floor(مزدوج _X);
  مزدوج __cdecl frexp(مزدوج _X,صحيح *_Y);
  مزدوج __cdecl _hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl _j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _jn(صحيح _X,مزدوج _Y);
  مزدوج __cdecl ldexp(مزدوج _X,صحيح _Y);
#جيڪڏهن_وصف_نه_ٿيل _CRT_MATHERR_DEFINED
#وصف_ڪريو _CRT_MATHERR_DEFINED
  صحيح __cdecl _matherr(بنية _exception *_Except);
#جيڪڏهن_پورو
  مزدوج __cdecl modf(مزدوج _X,مزدوج *_Y);
  _CRTIMP مزدوج __cdecl _y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl _y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl _yn(صحيح _X,مزدوج _Y);

#إذا(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl سيٽ_SSE2_enable(صحيح _Flag);
  /* from libmingwex */
  عائم __cdecl _hypotf(عائم _X,عائم _Y);
#جيڪڏهن_پورو

  عائم frexpf(عائم _X,صحيح *_Y);
  عائم __cdecl ldexpf(عائم _X,صحيح _Y);
  ڊگهو مزدوج __cdecl ldexpl(ڊگهو مزدوج _X,صحيح _Y);
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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#وصف_ڪريو matherr _matherr

#وصف_ڪريو HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  مزدوج __cdecl hypot(مزدوج _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl j0(مزدوج _X);
  _CRTIMP مزدوج __cdecl j1(مزدوج _X);
  _CRTIMP مزدوج __cdecl jn(صحيح _X,مزدوج _Y);
  _CRTIMP مزدوج __cdecl y0(مزدوج _X);
  _CRTIMP مزدوج __cdecl y1(مزدوج _X);
  _CRTIMP مزدوج __cdecl yn(صحيح _X,مزدوج _Y);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __NO_ISOCEXT
#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#وصف_ڪريو NAN (0.0F/0.0F)
#وصف_ڪريو HUGE_VALF (1.0F/0.0F)
#وصف_ڪريو HUGE_VALL (1.0L/0.0L)
#وصف_ڪريو INFINITY (1.0F/0.0F)


#وصف_ڪريو FP_NAN		0x0100
#وصف_ڪريو FP_NORMAL	0x0400
#وصف_ڪريو FP_INFINITE	(FP_NAN | FP_NORMAL)
#وصف_ڪريو FP_ZERO		0x4000
#وصف_ڪريو FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  خارجي صحيح __cdecl __fpclassifyf (عائم);
  خارجي صحيح __cdecl __fpclassify (مزدوج);
  خارجي صحيح __cdecl __fpclassifyl (ڊگهو مزدوج);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#وصف_ڪريو fpclassify(x) \
  _Generic(x, عائم: __fpclassifyf, مزدوج: __fpclassify, ڊگهو مزدوج: __fpclassifyl)(x)

  /* 7.12.3.2 */
#وصف_ڪريو isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#وصف_ڪريو isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#وصف_ڪريو isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#وصف_ڪريو isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  خارجي صحيح __cdecl __signbitf (عائم);
  خارجي صحيح __cdecl __signbit (مزدوج);
  خارجي صحيح __cdecl __signbitl (ڊگهو مزدوج);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#وصف_ڪريو signbit(x) \
  _Generic(x, عائم: __signbitf, مزدوج: __signbit, ڊگهو مزدوج: __signbitl)(x)

  خارجي مزدوج __cdecl exp2(مزدوج);
  خارجي عائم __cdecl exp2f(عائم);
  خارجي ڊگهو مزدوج __cdecl exp2l(ڊگهو مزدوج);

#وصف_ڪريو FP_ILOGB0 ((صحيح)0x80000000)
#وصف_ڪريو FP_ILOGBNAN ((صحيح)0x80000000)
  خارجي صحيح __cdecl ilogb (مزدوج);
  خارجي صحيح __cdecl ilogbf (عائم);
  خارجي صحيح __cdecl ilogbl (ڊگهو مزدوج);

  خارجي مزدوج __cdecl log1p(مزدوج);
  خارجي عائم __cdecl log1pf(عائم);
  خارجي ڊگهو مزدوج __cdecl log1pl(ڊگهو مزدوج);

  خارجي مزدوج __cdecl log2 (مزدوج);
  خارجي عائم __cdecl log2f (عائم);
  خارجي ڊگهو مزدوج __cdecl log2l (ڊگهو مزدوج);

  خارجي مزدوج __cdecl logb (مزدوج);
  خارجي عائم __cdecl logbf (عائم);
  خارجي ڊگهو مزدوج __cdecl logbl (ڊگهو مزدوج);

  خارجي ڊگهو مزدوج __cdecl modfl (ڊگهو مزدوج, ڊگهو مزدوج*);

  /* 7.12.6.13 */
  خارجي مزدوج __cdecl scalbn (مزدوج, صحيح);
  خارجي عائم __cdecl scalbnf (عائم, صحيح);
  خارجي ڊگهو مزدوج __cdecl scalbnl (ڊگهو مزدوج, صحيح);

  خارجي مزدوج __cdecl scalbln (مزدوج, ڊگهو);
  خارجي عائم __cdecl scalblnf (عائم, ڊگهو);
  خارجي ڊگهو مزدوج __cdecl scalblnl (ڊگهو مزدوج, ڊگهو);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  خارجي مزدوج __cdecl cbrt (مزدوج);
  خارجي عائم __cdecl cbrtf (عائم);
  خارجي ڊگهو مزدوج __cdecl cbrtl (ڊگهو مزدوج);

  خارجي مزدوج __cdecl hypot (مزدوج, مزدوج);
  خارجي عائم __cdecl hypotf (عائم, عائم);
  خارجي ڊگهو مزدوج __cdecl hypotl (ڊگهو مزدوج, ڊگهو مزدوج);

  خارجي ڊگهو مزدوج __cdecl powl (ڊگهو مزدوج, ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl expl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl expm1l(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl coshl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl fabsl (ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl acosl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl asinl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl atanl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl atan2l(ڊگهو مزدوج,ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl sinhl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl tanhl(ڊگهو مزدوج);

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
  خارجي ڊگهو مزدوج __cdecl lgammal (ڊگهو مزدوج);

  /* 7.12.8.4 The tgamma functions */
  خارجي مزدوج __cdecl tgamma (مزدوج);
  خارجي عائم __cdecl tgammaf (عائم);
  خارجي ڊگهو مزدوج __cdecl tgammal (ڊگهو مزدوج);

  خارجي ڊگهو مزدوج __cdecl ceill (ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl floorl (ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl frexpl(ڊگهو مزدوج,صحيح *);
  خارجي ڊگهو مزدوج __cdecl log10l(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl logl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl cosl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl sinl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج __cdecl tanl(ڊگهو مزدوج);
  خارجي ڊگهو مزدوج sqrtl(ڊگهو مزدوج);

  /* 7.12.9.3 */
  خارجي مزدوج __cdecl nearbyint ( مزدوج);
  خارجي عائم __cdecl nearbyintf (عائم);
  خارجي ڊگهو مزدوج __cdecl nearbyintl (ڊگهو مزدوج);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  خارجي مزدوج __cdecl rint (مزدوج);
  خارجي عائم __cdecl rintf (عائم);
  خارجي ڊگهو مزدوج __cdecl rintl (ڊگهو مزدوج);

  خارجي ڊگهو __cdecl lrint (مزدوج);
  خارجي ڊگهو __cdecl lrintf (عائم);
  خارجي ڊگهو __cdecl lrintl (ڊگهو مزدوج);

  خارجي ڊگهو ڊگهو __cdecl llrint (مزدوج);
  خارجي ڊگهو ڊگهو __cdecl llrintf (عائم);
  خارجي ڊگهو ڊگهو __cdecl llrintl (ڊگهو مزدوج);

  #وصف_ڪريو FE_TONEAREST	0x0000
  #وصف_ڪريو FE_DOWNWARD	0x0400
  #وصف_ڪريو FE_UPWARD	0x0800
  #وصف_ڪريو FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl ڦيرو (مزدوج);
  خارجي عائم __cdecl roundf (عائم);
  خارجي ڊگهو مزدوج __cdecl roundl (ڊگهو مزدوج);

  /* 7.12.9.7  */
  خارجي ڊگهو __cdecl lround (مزدوج);
  خارجي ڊگهو __cdecl lroundf (عائم);
  خارجي ڊگهو __cdecl lroundl (ڊگهو مزدوج);

  خارجي ڊگهو ڊگهو __cdecl llround (مزدوج);
  خارجي ڊگهو ڊگهو __cdecl llroundf (عائم);
  خارجي ڊگهو ڊگهو __cdecl llroundl (ڊگهو مزدوج);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  خارجي مزدوج __cdecl trunc (مزدوج);
  خارجي عائم __cdecl truncf (عائم);
  خارجي ڊگهو مزدوج __cdecl truncl (ڊگهو مزدوج);

  خارجي ڊگهو مزدوج __cdecl fmodl (ڊگهو مزدوج, ڊگهو مزدوج);

  /* 7.12.10.2 */ 
  خارجي مزدوج __cdecl remainder (مزدوج, مزدوج);
  خارجي عائم __cdecl remainderf (عائم, عائم);
  خارجي ڊگهو مزدوج __cdecl remainderl (ڊگهو مزدوج, ڊگهو مزدوج);

  /* 7.12.10.3 */
  خارجي مزدوج __cdecl remquo(مزدوج, مزدوج, صحيح *);
  خارجي عائم __cdecl remquof(عائم, عائم, صحيح *);
  خارجي ڊگهو مزدوج __cdecl remquol(ڊگهو مزدوج, ڊگهو مزدوج, صحيح *);

  /* 7.12.11.1 */
  خارجي مزدوج __cdecl copysign (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl copysignf (عائم, عائم);
  خارجي ڊگهو مزدوج __cdecl copysignl (ڊگهو مزدوج, ڊگهو مزدوج);

  /* 7.12.11.2 Return a NaN */
  خارجي مزدوج __cdecl nan(ثابت حرف *tagp);
  خارجي عائم __cdecl nanf(ثابت حرف *tagp);
  خارجي ڊگهو مزدوج __cdecl nanl(ثابت حرف *tagp);

#جيڪڏهن_وصف_نه_ٿيل __STRICT_ANSI__
#وصف_ڪريو _nan() nan("")
#وصف_ڪريو _nanf() nanf("")
#وصف_ڪريو _nanl() nanl("")
#جيڪڏهن_پورو

  /* 7.12.11.3 */
  خارجي مزدوج __cdecl nextafter (مزدوج, مزدوج); /* in libmoldname.a */
  خارجي عائم __cdecl nextafterf (عائم, عائم);
  خارجي ڊگهو مزدوج __cdecl nextafterl (ڊگهو مزدوج, ڊگهو مزدوج);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  خارجي مزدوج __cdecl fdim (مزدوج x, مزدوج y);
  خارجي عائم __cdecl fdimf (عائم x, عائم y);
  خارجي ڊگهو مزدوج __cdecl fdiml (ڊگهو مزدوج x, ڊگهو مزدوج y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  خارجي مزدوج __cdecl fmax  (مزدوج, مزدوج);
  خارجي عائم __cdecl fmaxf (عائم, عائم);
  خارجي ڊگهو مزدوج __cdecl fmaxl (ڊگهو مزدوج, ڊگهو مزدوج);

  /* 7.12.12.3 */
  خارجي مزدوج __cdecl fmin (مزدوج, مزدوج);
  خارجي عائم __cdecl fminf (عائم, عائم);
  خارجي ڊگهو مزدوج __cdecl fminl (ڊگهو مزدوج, ڊگهو مزدوج);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  خارجي مزدوج __cdecl fma (مزدوج, مزدوج, مزدوج);
  خارجي عائم __cdecl fmaf (عائم, عائم, عائم);
  خارجي ڊگهو مزدوج __cdecl fmal (ڊگهو مزدوج, ڊگهو مزدوج, ڊگهو مزدوج);


#جيڪڏهن_پورو /* __STDC_VERSION__ >= 199901L */
#جيڪڏهن_پورو /* __NO_ISOCEXT */

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#هدايت pack(ڪڍو)

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

#جيڪڏهن_پورو /* End _MATH_H_ */

