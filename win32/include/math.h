/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _MATH_H_
#تعریف_کرو _MATH_H_

#اگر __GNUC__ >= 3
#ہدایت GCC system_سرخی
#اگر_ختم

#شامل <_mingw.h>

ساخت exception;

#ہدایت pack(ڈالو,_CRT_PACKING)

#تعریف_کرو _DOMAIN 1
#تعریف_کرو _SING 2
#تعریف_کرو حد_سے_تجاوز 3
#تعریف_کرو _UNDERFLOW 4
#تعریف_کرو _TLOSS 5
#تعریف_کرو _PLOSS 6

#اگر_غیر_تعریف_شدہ __STRICT_ANSI__
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#تعریف_کرو DOMAIN _DOMAIN
#تعریف_کرو SING _SING
#تعریف_کرو حد_سے_تجاوز_2 حد_سے_تجاوز
#تعریف_کرو UNDERFLOW _UNDERFLOW
#تعریف_کرو TLOSS _TLOSS
#تعریف_کرو PLOSS _PLOSS
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ __STRICT_ANSI__
#تعریف_کرو M_E 2.71828182845904523536
#تعریف_کرو M_LOG2E 1.44269504088896340736
#تعریف_کرو M_LOG10E 0.434294481903251827651
#تعریف_کرو M_LN2 0.693147180559945309417
#تعریف_کرو M_LN10 2.30258509299404568402
#تعریف_کرو M_PI 3.14159265358979323846
#تعریف_کرو M_PI_2 1.57079632679489661923
#تعریف_کرو M_PI_4 0.785398163397448309616
#تعریف_کرو M_1_PI 0.318309886183790671538
#تعریف_کرو M_2_PI 0.636619772367581343076
#تعریف_کرو M_2_SQRTPI 1.12837916709551257390
#تعریف_کرو M_SQRT2 1.41421356237309504880
#تعریف_کرو M_SQRT1_2 0.707106781186547524401
#اگر_ختم

#اگر_غیر_تعریف_شدہ __STRICT_ANSI__
/* See also float.h  */
#اگر_غیر_تعریف_شدہ __MINGW_FPCLASS_DEFINED
#تعریف_کرو __MINGW_FPCLASS_DEFINED 1
#تعریف_کرو	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#تعریف_کرو	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#تعریف_کرو	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#تعریف_کرو	_FPCLASS_NN	0x0008	/* Negative Normal */
#تعریف_کرو	_FPCLASS_ND	0x0010	/* Negative Denormal */
#تعریف_کرو	_FPCLASS_NZ	0x0020	/* Negative Zero */
#تعریف_کرو	_FPCLASS_PZ	0x0040	/* Positive Zero */
#تعریف_کرو	_FPCLASS_PD	0x0080	/* Positive Denormal */
#تعریف_کرو	_FPCLASS_PN	0x0100	/* Positive Normal */
#تعریف_کرو	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _EXCEPTION_DEFINED
#تعریف_کرو _EXCEPTION_DEFINED
  ساخت _exception {
    صحیح type;
    حرف *name;
    دوہرا arg1;
    دوہرا arg2;
    دوہرا retval;
  };
#اگر_ختم

#اگر_غیر_تعریف_شدہ _COMPLEX_DEFINED
#تعریف_کرو _COMPLEX_DEFINED
  ساخت _complex {
    دوہرا x,y;
  };
#اگر_ختم

#تعریف_کرو EDOM 33
#تعریف_کرو ERANGE 34

#اگر_غیر_تعریف_شدہ _HUGE
#اگر_تعریف_شدہ _MSVCRT_
  خارجی دوہرا *_HUGE;
#ورنہ
  خارجی دوہرا *_imp___HUGE;
#تعریف_کرو _HUGE	(*_imp___HUGE)
#اگر_ختم
#اگر_ختم

#تعریف_کرو HUGE_VAL _HUGE

#اگر_غیر_تعریف_شدہ _CRT_ABS_DEFINED
#تعریف_کرو _CRT_ABS_DEFINED
  صحیح __cdecl مطلق_قدر(صحیح _X);
  طویل __cdecl labs(طویل _X);
#اگر_ختم
  دوہرا __cdecl acos(دوہرا _X);
  دوہرا __cdecl asin(دوہرا _X);
  دوہرا __cdecl atan(دوہرا _X);
  دوہرا __cdecl atan2(دوہرا _Y,دوہرا _X);
#اگر_غیر_تعریف_شدہ _SIGN_DEFINED
#تعریف_کرو _SIGN_DEFINED
  _CRTIMP دوہرا __cdecl _copysign (دوہرا نمبر,دوہرا _Sign);
  _CRTIMP دوہرا __cdecl _chgsign (دوہرا _X);
#اگر_ختم
  دوہرا __cdecl جیب_تمام(دوہرا _X);
  دوہرا __cdecl cosh(دوہرا _X);
  دوہرا __cdecl قوت_نما(دوہرا _X);
  دوہرا __cdecl expm1(دوہرا _X);
  دوہرا __cdecl fabs(دوہرا _X);
  دوہرا __cdecl fmod(دوہرا _X,دوہرا _Y);
  دوہرا __cdecl لوگارتھم(دوہرا _X);
  دوہرا __cdecl log10(دوہرا _X);
  دوہرا __cdecl قوت(دوہرا _X,دوہرا _Y);
  دوہرا __cdecl جیب(دوہرا _X);
  دوہرا __cdecl sinh(دوہرا _X);
  دوہرا __cdecl tan(دوہرا _X);
  دوہرا __cdecl tanh(دوہرا _X);
  دوہرا __cdecl جذر(دوہرا _X);
#اگر_غیر_تعریف_شدہ _CRT_ATOF_DEFINED
#تعریف_کرو _CRT_ATOF_DEFINED
  دوہرا __cdecl atof(ثابت حرف *_String);
  دوہرا __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#اگر_ختم

  _CRTIMP دوہرا __cdecl _cabs(ساخت _complex _ComplexA);
  دوہرا __cdecl ceil(دوہرا _X);
  دوہرا __cdecl floor(دوہرا _X);
  دوہرا __cdecl frexp(دوہرا _X,صحیح *_Y);
  دوہرا __cdecl _hypot(دوہرا _X,دوہرا _Y);
  _CRTIMP دوہرا __cdecl _j0(دوہرا _X);
  _CRTIMP دوہرا __cdecl _j1(دوہرا _X);
  _CRTIMP دوہرا __cdecl _jn(صحیح _X,دوہرا _Y);
  دوہرا __cdecl ldexp(دوہرا _X,صحیح _Y);
#اگر_غیر_تعریف_شدہ _CRT_MATHERR_DEFINED
#تعریف_کرو _CRT_MATHERR_DEFINED
  صحیح __cdecl _matherr(ساخت _exception *_Except);
#اگر_ختم
  دوہرا __cdecl modf(دوہرا _X,دوہرا *_Y);
  _CRTIMP دوہرا __cdecl _y0(دوہرا _X);
  _CRTIMP دوہرا __cdecl _y1(دوہرا _X);
  _CRTIMP دوہرا __cdecl _yn(صحیح _X,دوہرا _Y);

#اگر(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح __cdecl سیٹ_SSE2_enable(صحیح _Flag);
  /* from libmingwex */
  اعشاری __cdecl _hypotf(اعشاری _X,اعشاری _Y);
#اگر_ختم

  اعشاری frexpf(اعشاری _X,صحیح *_Y);
  اعشاری __cdecl ldexpf(اعشاری _X,صحیح _Y);
  طویل دوہرا __cdecl ldexpl(طویل دوہرا _X,صحیح _Y);
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
   اعشاری __cdecl _copysignf (اعشاری نمبر,اعشاری _Sign);
   اعشاری __cdecl _chgsignf (اعشاری _X);
   اعشاری __cdecl _logbf(اعشاری _X);
   اعشاری __cdecl _nextafterf(اعشاری _X,اعشاری _Y);
   صحیح __cdecl _finitef(اعشاری _X);
   صحیح __cdecl _isnanf(اعشاری _X);
   صحیح __cdecl _fpclassf(اعشاری _X);
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#تعریف_کرو matherr _matherr

#تعریف_کرو HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  دوہرا __cdecl hypot(دوہرا _X,دوہرا _Y);
  _CRTIMP دوہرا __cdecl j0(دوہرا _X);
  _CRTIMP دوہرا __cdecl j1(دوہرا _X);
  _CRTIMP دوہرا __cdecl jn(صحیح _X,دوہرا _Y);
  _CRTIMP دوہرا __cdecl y0(دوہرا _X);
  _CRTIMP دوہرا __cdecl y1(دوہرا _X);
  _CRTIMP دوہرا __cdecl yn(صحیح _X,دوہرا _Y);
#اگر_ختم

#اگر_غیر_تعریف_شدہ __NO_ISOCEXT
#اگر (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#تعریف_کرو NAN (0.0F/0.0F)
#تعریف_کرو HUGE_VALF (1.0F/0.0F)
#تعریف_کرو HUGE_VALL (1.0L/0.0L)
#تعریف_کرو INFINITY (1.0F/0.0F)


#تعریف_کرو FP_NAN		0x0100
#تعریف_کرو FP_NORMAL	0x0400
#تعریف_کرو FP_INFINITE	(FP_NAN | FP_NORMAL)
#تعریف_کرو FP_ZERO		0x4000
#تعریف_کرو FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  خارجی صحیح __cdecl __fpclassifyf (اعشاری);
  خارجی صحیح __cdecl __fpclassify (دوہرا);
  خارجی صحیح __cdecl __fpclassifyl (طویل دوہرا);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#تعریف_کرو fpclassify(x) \
  _Generic(x, اعشاری: __fpclassifyf, دوہرا: __fpclassify, طویل دوہرا: __fpclassifyl)(x)

  /* 7.12.3.2 */
#تعریف_کرو isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#تعریف_کرو isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#تعریف_کرو isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#تعریف_کرو isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  خارجی صحیح __cdecl __signbitf (اعشاری);
  خارجی صحیح __cdecl __signbit (دوہرا);
  خارجی صحیح __cdecl __signbitl (طویل دوہرا);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#تعریف_کرو signbit(x) \
  _Generic(x, اعشاری: __signbitf, دوہرا: __signbit, طویل دوہرا: __signbitl)(x)

  خارجی دوہرا __cdecl exp2(دوہرا);
  خارجی اعشاری __cdecl exp2f(اعشاری);
  خارجی طویل دوہرا __cdecl exp2l(طویل دوہرا);

#تعریف_کرو FP_ILOGB0 ((صحیح)0x80000000)
#تعریف_کرو FP_ILOGBNAN ((صحیح)0x80000000)
  خارجی صحیح __cdecl ilogb (دوہرا);
  خارجی صحیح __cdecl ilogbf (اعشاری);
  خارجی صحیح __cdecl ilogbl (طویل دوہرا);

  خارجی دوہرا __cdecl log1p(دوہرا);
  خارجی اعشاری __cdecl log1pf(اعشاری);
  خارجی طویل دوہرا __cdecl log1pl(طویل دوہرا);

  خارجی دوہرا __cdecl log2 (دوہرا);
  خارجی اعشاری __cdecl log2f (اعشاری);
  خارجی طویل دوہرا __cdecl log2l (طویل دوہرا);

  خارجی دوہرا __cdecl logb (دوہرا);
  خارجی اعشاری __cdecl logbf (اعشاری);
  خارجی طویل دوہرا __cdecl logbl (طویل دوہرا);

  خارجی طویل دوہرا __cdecl modfl (طویل دوہرا, طویل دوہرا*);

  /* 7.12.6.13 */
  خارجی دوہرا __cdecl scalbn (دوہرا, صحیح);
  خارجی اعشاری __cdecl scalbnf (اعشاری, صحیح);
  خارجی طویل دوہرا __cdecl scalbnl (طویل دوہرا, صحیح);

  خارجی دوہرا __cdecl scalbln (دوہرا, طویل);
  خارجی اعشاری __cdecl scalblnf (اعشاری, طویل);
  خارجی طویل دوہرا __cdecl scalblnl (طویل دوہرا, طویل);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  خارجی دوہرا __cdecl cbrt (دوہرا);
  خارجی اعشاری __cdecl cbrtf (اعشاری);
  خارجی طویل دوہرا __cdecl cbrtl (طویل دوہرا);

  خارجی دوہرا __cdecl hypot (دوہرا, دوہرا);
  خارجی اعشاری __cdecl hypotf (اعشاری, اعشاری);
  خارجی طویل دوہرا __cdecl hypotl (طویل دوہرا, طویل دوہرا);

  خارجی طویل دوہرا __cdecl powl (طویل دوہرا, طویل دوہرا);
  خارجی طویل دوہرا __cdecl expl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl expm1l(طویل دوہرا);
  خارجی طویل دوہرا __cdecl coshl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl fabsl (طویل دوہرا);
  خارجی طویل دوہرا __cdecl acosl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl asinl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl atanl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl atan2l(طویل دوہرا,طویل دوہرا);
  خارجی طویل دوہرا __cdecl sinhl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl tanhl(طویل دوہرا);

  /* 7.12.8.1 The erf functions  */
  خارجی دوہرا __cdecl erf (دوہرا);
  خارجی اعشاری __cdecl erff (اعشاری);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  خارجی دوہرا __cdecl erfc (دوہرا);
  خارجی اعشاری __cdecl erfcf (اعشاری);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  خارجی دوہرا __cdecl lgamma (دوہرا);
  خارجی اعشاری __cdecl lgammaf (اعشاری);
  خارجی طویل دوہرا __cdecl lgammal (طویل دوہرا);

  /* 7.12.8.4 The tgamma functions */
  خارجی دوہرا __cdecl tgamma (دوہرا);
  خارجی اعشاری __cdecl tgammaf (اعشاری);
  خارجی طویل دوہرا __cdecl tgammal (طویل دوہرا);

  خارجی طویل دوہرا __cdecl ceill (طویل دوہرا);
  خارجی طویل دوہرا __cdecl floorl (طویل دوہرا);
  خارجی طویل دوہرا __cdecl frexpl(طویل دوہرا,صحیح *);
  خارجی طویل دوہرا __cdecl log10l(طویل دوہرا);
  خارجی طویل دوہرا __cdecl logl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl cosl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl sinl(طویل دوہرا);
  خارجی طویل دوہرا __cdecl tanl(طویل دوہرا);
  خارجی طویل دوہرا sqrtl(طویل دوہرا);

  /* 7.12.9.3 */
  خارجی دوہرا __cdecl nearbyint ( دوہرا);
  خارجی اعشاری __cdecl nearbyintf (اعشاری);
  خارجی طویل دوہرا __cdecl nearbyintl (طویل دوہرا);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  خارجی دوہرا __cdecl rint (دوہرا);
  خارجی اعشاری __cdecl rintf (اعشاری);
  خارجی طویل دوہرا __cdecl rintl (طویل دوہرا);

  خارجی طویل __cdecl lrint (دوہرا);
  خارجی طویل __cdecl lrintf (اعشاری);
  خارجی طویل __cdecl lrintl (طویل دوہرا);

  خارجی طویل طویل __cdecl llrint (دوہرا);
  خارجی طویل طویل __cdecl llrintf (اعشاری);
  خارجی طویل طویل __cdecl llrintl (طویل دوہرا);

  #تعریف_کرو FE_TONEAREST	0x0000
  #تعریف_کرو FE_DOWNWARD	0x0400
  #تعریف_کرو FE_UPWARD	0x0800
  #تعریف_کرو FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  خارجی دوہرا __cdecl باری (دوہرا);
  خارجی اعشاری __cdecl roundf (اعشاری);
  خارجی طویل دوہرا __cdecl roundl (طویل دوہرا);

  /* 7.12.9.7  */
  خارجی طویل __cdecl lround (دوہرا);
  خارجی طویل __cdecl lroundf (اعشاری);
  خارجی طویل __cdecl lroundl (طویل دوہرا);

  خارجی طویل طویل __cdecl llround (دوہرا);
  خارجی طویل طویل __cdecl llroundf (اعشاری);
  خارجی طویل طویل __cdecl llroundl (طویل دوہرا);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  خارجی دوہرا __cdecl trunc (دوہرا);
  خارجی اعشاری __cdecl truncf (اعشاری);
  خارجی طویل دوہرا __cdecl truncl (طویل دوہرا);

  خارجی طویل دوہرا __cdecl fmodl (طویل دوہرا, طویل دوہرا);

  /* 7.12.10.2 */ 
  خارجی دوہرا __cdecl remainder (دوہرا, دوہرا);
  خارجی اعشاری __cdecl remainderf (اعشاری, اعشاری);
  خارجی طویل دوہرا __cdecl remainderl (طویل دوہرا, طویل دوہرا);

  /* 7.12.10.3 */
  خارجی دوہرا __cdecl remquo(دوہرا, دوہرا, صحیح *);
  خارجی اعشاری __cdecl remquof(اعشاری, اعشاری, صحیح *);
  خارجی طویل دوہرا __cdecl remquol(طویل دوہرا, طویل دوہرا, صحیح *);

  /* 7.12.11.1 */
  خارجی دوہرا __cdecl copysign (دوہرا, دوہرا); /* in libmoldname.a */
  خارجی اعشاری __cdecl copysignf (اعشاری, اعشاری);
  خارجی طویل دوہرا __cdecl copysignl (طویل دوہرا, طویل دوہرا);

  /* 7.12.11.2 Return a NaN */
  خارجی دوہرا __cdecl nan(ثابت حرف *tagp);
  خارجی اعشاری __cdecl nanf(ثابت حرف *tagp);
  خارجی طویل دوہرا __cdecl nanl(ثابت حرف *tagp);

#اگر_غیر_تعریف_شدہ __STRICT_ANSI__
#تعریف_کرو _nan() nan("")
#تعریف_کرو _nanf() nanf("")
#تعریف_کرو _nanl() nanl("")
#اگر_ختم

  /* 7.12.11.3 */
  خارجی دوہرا __cdecl nextafter (دوہرا, دوہرا); /* in libmoldname.a */
  خارجی اعشاری __cdecl nextafterf (اعشاری, اعشاری);
  خارجی طویل دوہرا __cdecl nextafterl (طویل دوہرا, طویل دوہرا);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  خارجی دوہرا __cdecl fdim (دوہرا x, دوہرا y);
  خارجی اعشاری __cdecl fdimf (اعشاری x, اعشاری y);
  خارجی طویل دوہرا __cdecl fdiml (طویل دوہرا x, طویل دوہرا y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  خارجی دوہرا __cdecl fmax  (دوہرا, دوہرا);
  خارجی اعشاری __cdecl fmaxf (اعشاری, اعشاری);
  خارجی طویل دوہرا __cdecl fmaxl (طویل دوہرا, طویل دوہرا);

  /* 7.12.12.3 */
  خارجی دوہرا __cdecl fmin (دوہرا, دوہرا);
  خارجی اعشاری __cdecl fminf (اعشاری, اعشاری);
  خارجی طویل دوہرا __cdecl fminl (طویل دوہرا, طویل دوہرا);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  خارجی دوہرا __cdecl fma (دوہرا, دوہرا, دوہرا);
  خارجی اعشاری __cdecl fmaf (اعشاری, اعشاری, اعشاری);
  خارجی طویل دوہرا __cdecl fmal (طویل دوہرا, طویل دوہرا, طویل دوہرا);


#اگر_ختم /* __STDC_VERSION__ >= 199901L */
#اگر_ختم /* __NO_ISOCEXT */

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#ہدایت pack(نکالو)

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

#اگر_ختم /* End _MATH_H_ */

