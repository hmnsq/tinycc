/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _MATH_H_
#परिभाषय _MATH_H_

#यदि __GNUC__ >= 3
#निर्देशः GCC system_शीर्षकम्
#यदि_अन्तः

#अन्तर्भाव <_mingw.h>

संरचना exception;

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#परिभाषय _DOMAIN 1
#परिभाषय _SING 2
#परिभाषय अतिप्रवाहः 3
#परिभाषय _UNDERFLOW 4
#परिभाषय _TLOSS 5
#परिभाषय _PLOSS 6

#यदि_अपरिभाषितम् __STRICT_ANSI__
#यदि_अपरिभाषितम्	NO_OLDNAMES
#परिभाषय DOMAIN _DOMAIN
#परिभाषय SING _SING
#परिभाषय अतिप्रवाहः_2 अतिप्रवाहः
#परिभाषय UNDERFLOW _UNDERFLOW
#परिभाषय TLOSS _TLOSS
#परिभाषय PLOSS _PLOSS
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् __STRICT_ANSI__
#परिभाषय M_E 2.71828182845904523536
#परिभाषय M_LOG2E 1.44269504088896340736
#परिभाषय M_LOG10E 0.434294481903251827651
#परिभाषय M_LN2 0.693147180559945309417
#परिभाषय M_LN10 2.30258509299404568402
#परिभाषय M_PI 3.14159265358979323846
#परिभाषय M_PI_2 1.57079632679489661923
#परिभाषय M_PI_4 0.785398163397448309616
#परिभाषय M_1_PI 0.318309886183790671538
#परिभाषय M_2_PI 0.636619772367581343076
#परिभाषय M_2_SQRTPI 1.12837916709551257390
#परिभाषय M_SQRT2 1.41421356237309504880
#परिभाषय M_SQRT1_2 0.707106781186547524401
#यदि_अन्तः

#यदि_अपरिभाषितम् __STRICT_ANSI__
/* See also float.h  */
#यदि_अपरिभाषितम् __MINGW_FPCLASS_DEFINED
#परिभाषय __MINGW_FPCLASS_DEFINED 1
#परिभाषय	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#परिभाषय	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#परिभाषय	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#परिभाषय	_FPCLASS_NN	0x0008	/* Negative Normal */
#परिभाषय	_FPCLASS_ND	0x0010	/* Negative Denormal */
#परिभाषय	_FPCLASS_NZ	0x0020	/* Negative Zero */
#परिभाषय	_FPCLASS_PZ	0x0040	/* Positive Zero */
#परिभाषय	_FPCLASS_PD	0x0080	/* Positive Denormal */
#परिभाषय	_FPCLASS_PN	0x0100	/* Positive Normal */
#परिभाषय	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _EXCEPTION_DEFINED
#परिभाषय _EXCEPTION_DEFINED
  संरचना _exception {
    पूर्णाङ्क type;
    वर्ण *name;
    द्विगुण arg1;
    द्विगुण arg2;
    द्विगुण retval;
  };
#यदि_अन्तः

#यदि_अपरिभाषितम् _COMPLEX_DEFINED
#परिभाषय _COMPLEX_DEFINED
  संरचना _complex {
    द्विगुण x,y;
  };
#यदि_अन्तः

#परिभाषय EDOM 33
#परिभाषय ERANGE 34

#यदि_अपरिभाषितम् _HUGE
#यदि_परिभाषितम् _MSVCRT_
  बाह्य द्विगुण *_HUGE;
#अन्यथा
  बाह्य द्विगुण *_imp___HUGE;
#परिभाषय _HUGE	(*_imp___HUGE)
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय HUGE_VAL _HUGE

#यदि_अपरिभाषितम् _CRT_ABS_DEFINED
#परिभाषय _CRT_ABS_DEFINED
  पूर्णाङ्क __cdecl निरपेक्षम्(पूर्णाङ्क _X);
  दीर्घ __cdecl labs(दीर्घ _X);
#यदि_अन्तः
  द्विगुण __cdecl acos(द्विगुण _X);
  द्विगुण __cdecl asin(द्विगुण _X);
  द्विगुण __cdecl atan(द्विगुण _X);
  द्विगुण __cdecl atan2(द्विगुण _Y,द्विगुण _X);
#यदि_अपरिभाषितम् _SIGN_DEFINED
#परिभाषय _SIGN_DEFINED
  _CRTIMP द्विगुण __cdecl _copysign (द्विगुण सङ्ख्या,द्विगुण _Sign);
  _CRTIMP द्विगुण __cdecl _chgsign (द्विगुण _X);
#यदि_अन्तः
  द्विगुण __cdecl कोटिज्या(द्विगुण _X);
  द्विगुण __cdecl cosh(द्विगुण _X);
  द्विगुण __cdecl घातांकः(द्विगुण _X);
  द्विगुण __cdecl expm1(द्विगुण _X);
  द्विगुण __cdecl fabs(द्विगुण _X);
  द्विगुण __cdecl fmod(द्विगुण _X,द्विगुण _Y);
  द्विगुण __cdecl लघुगणकः(द्विगुण _X);
  द्विगुण __cdecl log10(द्विगुण _X);
  द्विगुण __cdecl घातः(द्विगुण _X,द्विगुण _Y);
  द्विगुण __cdecl ज्या(द्विगुण _X);
  द्विगुण __cdecl sinh(द्विगुण _X);
  द्विगुण __cdecl tan(द्विगुण _X);
  द्विगुण __cdecl tanh(द्विगुण _X);
  द्विगुण __cdecl वर्गमूलम्(द्विगुण _X);
#यदि_अपरिभाषितम् _CRT_ATOF_DEFINED
#परिभाषय _CRT_ATOF_DEFINED
  द्विगुण __cdecl atof(ध्रुव वर्ण *_String);
  द्विगुण __cdecl _atof_l(ध्रुव वर्ण *_String,_locale_t _Locale);
#यदि_अन्तः

  _CRTIMP द्विगुण __cdecl _cabs(संरचना _complex _ComplexA);
  द्विगुण __cdecl ceil(द्विगुण _X);
  द्विगुण __cdecl floor(द्विगुण _X);
  द्विगुण __cdecl frexp(द्विगुण _X,पूर्णाङ्क *_Y);
  द्विगुण __cdecl _hypot(द्विगुण _X,द्विगुण _Y);
  _CRTIMP द्विगुण __cdecl _j0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _j1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _jn(पूर्णाङ्क _X,द्विगुण _Y);
  द्विगुण __cdecl ldexp(द्विगुण _X,पूर्णाङ्क _Y);
#यदि_अपरिभाषितम् _CRT_MATHERR_DEFINED
#परिभाषय _CRT_MATHERR_DEFINED
  पूर्णाङ्क __cdecl _matherr(संरचना _exception *_Except);
#यदि_अन्तः
  द्विगुण __cdecl modf(द्विगुण _X,द्विगुण *_Y);
  _CRTIMP द्विगुण __cdecl _y0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _y1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl _yn(पूर्णाङ्क _X,द्विगुण _Y);

#यदि(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क __cdecl समुच्चयः_SSE2_enable(पूर्णाङ्क _Flag);
  /* from libmingwex */
  भिन्न __cdecl _hypotf(भिन्न _X,भिन्न _Y);
#यदि_अन्तः

  भिन्न frexpf(भिन्न _X,पूर्णाङ्क *_Y);
  भिन्न __cdecl ldexpf(भिन्न _X,पूर्णाङ्क _Y);
  दीर्घ द्विगुण __cdecl ldexpl(दीर्घ द्विगुण _X,पूर्णाङ्क _Y);
  भिन्न __cdecl acosf(भिन्न _X);
  भिन्न __cdecl asinf(भिन्न _X);
   भिन्न __cdecl atanf(भिन्न _X);
   भिन्न __cdecl atan2f(भिन्न _X,भिन्न _Y);
   भिन्न __cdecl cosf(भिन्न _X);
   भिन्न __cdecl sinf(भिन्न _X);
   भिन्न __cdecl tanf(भिन्न _X);
   भिन्न __cdecl coshf(भिन्न _X);
   भिन्न __cdecl sinhf(भिन्न _X);
   भिन्न __cdecl tanhf(भिन्न _X);
   भिन्न __cdecl expf(भिन्न _X);
   भिन्न __cdecl expm1f(भिन्न _X);
   भिन्न __cdecl logf(भिन्न _X);
   भिन्न __cdecl log10f(भिन्न _X);
   भिन्न __cdecl modff(भिन्न _X,भिन्न *_Y);
   भिन्न __cdecl powf(भिन्न _X,भिन्न _Y);
   भिन्न __cdecl sqrtf(भिन्न _X);
   भिन्न __cdecl ceilf(भिन्न _X);
   भिन्न __cdecl floorf(भिन्न _X);
  भिन्न __cdecl fmodf(भिन्न _X,भिन्न _Y);
   भिन्न __cdecl _hypotf(भिन्न _X,भिन्न _Y);
  भिन्न __cdecl fabsf(भिन्न _X);
#यदि !defined(__ia64__)
   /* from libmingwex */
   भिन्न __cdecl _copysignf (भिन्न सङ्ख्या,भिन्न _Sign);
   भिन्न __cdecl _chgsignf (भिन्न _X);
   भिन्न __cdecl _logbf(भिन्न _X);
   भिन्न __cdecl _nextafterf(भिन्न _X,भिन्न _Y);
   पूर्णाङ्क __cdecl _finitef(भिन्न _X);
   पूर्णाङ्क __cdecl _isnanf(भिन्न _X);
   पूर्णाङ्क __cdecl _fpclassf(भिन्न _X);
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
#परिभाषय matherr _matherr

#परिभाषय HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  द्विगुण __cdecl hypot(द्विगुण _X,द्विगुण _Y);
  _CRTIMP द्विगुण __cdecl j0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl j1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl jn(पूर्णाङ्क _X,द्विगुण _Y);
  _CRTIMP द्विगुण __cdecl y0(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl y1(द्विगुण _X);
  _CRTIMP द्विगुण __cdecl yn(पूर्णाङ्क _X,द्विगुण _Y);
#यदि_अन्तः

#यदि_अपरिभाषितम् __NO_ISOCEXT
#यदि (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#परिभाषय NAN (0.0F/0.0F)
#परिभाषय HUGE_VALF (1.0F/0.0F)
#परिभाषय HUGE_VALL (1.0L/0.0L)
#परिभाषय INFINITY (1.0F/0.0F)


#परिभाषय FP_NAN		0x0100
#परिभाषय FP_NORMAL	0x0400
#परिभाषय FP_INFINITE	(FP_NAN | FP_NORMAL)
#परिभाषय FP_ZERO		0x4000
#परिभाषय FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  बाह्य पूर्णाङ्क __cdecl __fpclassifyf (भिन्न);
  बाह्य पूर्णाङ्क __cdecl __fpclassify (द्विगुण);
  बाह्य पूर्णाङ्क __cdecl __fpclassifyl (दीर्घ द्विगुण);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#परिभाषय fpclassify(x) \
  _Generic(x, भिन्न: __fpclassifyf, द्विगुण: __fpclassify, दीर्घ द्विगुण: __fpclassifyl)(x)

  /* 7.12.3.2 */
#परिभाषय isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#परिभाषय isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#परिभाषय isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#परिभाषय isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  बाह्य पूर्णाङ्क __cdecl __signbitf (भिन्न);
  बाह्य पूर्णाङ्क __cdecl __signbit (द्विगुण);
  बाह्य पूर्णाङ्क __cdecl __signbitl (दीर्घ द्विगुण);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#परिभाषय signbit(x) \
  _Generic(x, भिन्न: __signbitf, द्विगुण: __signbit, दीर्घ द्विगुण: __signbitl)(x)

  बाह्य द्विगुण __cdecl exp2(द्विगुण);
  बाह्य भिन्न __cdecl exp2f(भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl exp2l(दीर्घ द्विगुण);

#परिभाषय FP_ILOGB0 ((पूर्णाङ्क)0x80000000)
#परिभाषय FP_ILOGBNAN ((पूर्णाङ्क)0x80000000)
  बाह्य पूर्णाङ्क __cdecl ilogb (द्विगुण);
  बाह्य पूर्णाङ्क __cdecl ilogbf (भिन्न);
  बाह्य पूर्णाङ्क __cdecl ilogbl (दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl log1p(द्विगुण);
  बाह्य भिन्न __cdecl log1pf(भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl log1pl(दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl log2 (द्विगुण);
  बाह्य भिन्न __cdecl log2f (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl log2l (दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl logb (द्विगुण);
  बाह्य भिन्न __cdecl logbf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl logbl (दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl modfl (दीर्घ द्विगुण, दीर्घ द्विगुण*);

  /* 7.12.6.13 */
  बाह्य द्विगुण __cdecl scalbn (द्विगुण, पूर्णाङ्क);
  बाह्य भिन्न __cdecl scalbnf (भिन्न, पूर्णाङ्क);
  बाह्य दीर्घ द्विगुण __cdecl scalbnl (दीर्घ द्विगुण, पूर्णाङ्क);

  बाह्य द्विगुण __cdecl scalbln (द्विगुण, दीर्घ);
  बाह्य भिन्न __cdecl scalblnf (भिन्न, दीर्घ);
  बाह्य दीर्घ द्विगुण __cdecl scalblnl (दीर्घ द्विगुण, दीर्घ);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  बाह्य द्विगुण __cdecl cbrt (द्विगुण);
  बाह्य भिन्न __cdecl cbrtf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl cbrtl (दीर्घ द्विगुण);

  बाह्य द्विगुण __cdecl hypot (द्विगुण, द्विगुण);
  बाह्य भिन्न __cdecl hypotf (भिन्न, भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl hypotl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl powl (दीर्घ द्विगुण, दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl expl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl expm1l(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl coshl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl fabsl (दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl acosl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl asinl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl atanl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl atan2l(दीर्घ द्विगुण,दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl sinhl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl tanhl(दीर्घ द्विगुण);

  /* 7.12.8.1 The erf functions  */
  बाह्य द्विगुण __cdecl erf (द्विगुण);
  बाह्य भिन्न __cdecl erff (भिन्न);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  बाह्य द्विगुण __cdecl erfc (द्विगुण);
  बाह्य भिन्न __cdecl erfcf (भिन्न);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  बाह्य द्विगुण __cdecl lgamma (द्विगुण);
  बाह्य भिन्न __cdecl lgammaf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl lgammal (दीर्घ द्विगुण);

  /* 7.12.8.4 The tgamma functions */
  बाह्य द्विगुण __cdecl tgamma (द्विगुण);
  बाह्य भिन्न __cdecl tgammaf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl tgammal (दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl ceill (दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl floorl (दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl frexpl(दीर्घ द्विगुण,पूर्णाङ्क *);
  बाह्य दीर्घ द्विगुण __cdecl log10l(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl logl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl cosl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl sinl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण __cdecl tanl(दीर्घ द्विगुण);
  बाह्य दीर्घ द्विगुण sqrtl(दीर्घ द्विगुण);

  /* 7.12.9.3 */
  बाह्य द्विगुण __cdecl nearbyint ( द्विगुण);
  बाह्य भिन्न __cdecl nearbyintf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl nearbyintl (दीर्घ द्विगुण);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  बाह्य द्विगुण __cdecl rint (द्विगुण);
  बाह्य भिन्न __cdecl rintf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl rintl (दीर्घ द्विगुण);

  बाह्य दीर्घ __cdecl lrint (द्विगुण);
  बाह्य दीर्घ __cdecl lrintf (भिन्न);
  बाह्य दीर्घ __cdecl lrintl (दीर्घ द्विगुण);

  बाह्य दीर्घ दीर्घ __cdecl llrint (द्विगुण);
  बाह्य दीर्घ दीर्घ __cdecl llrintf (भिन्न);
  बाह्य दीर्घ दीर्घ __cdecl llrintl (दीर्घ द्विगुण);

  #परिभाषय FE_TONEAREST	0x0000
  #परिभाषय FE_DOWNWARD	0x0400
  #परिभाषय FE_UPWARD	0x0800
  #परिभाषय FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  बाह्य द्विगुण __cdecl आवर्तनम् (द्विगुण);
  बाह्य भिन्न __cdecl roundf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl roundl (दीर्घ द्विगुण);

  /* 7.12.9.7  */
  बाह्य दीर्घ __cdecl lround (द्विगुण);
  बाह्य दीर्घ __cdecl lroundf (भिन्न);
  बाह्य दीर्घ __cdecl lroundl (दीर्घ द्विगुण);

  बाह्य दीर्घ दीर्घ __cdecl llround (द्विगुण);
  बाह्य दीर्घ दीर्घ __cdecl llroundf (भिन्न);
  बाह्य दीर्घ दीर्घ __cdecl llroundl (दीर्घ द्विगुण);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  बाह्य द्विगुण __cdecl trunc (द्विगुण);
  बाह्य भिन्न __cdecl truncf (भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl truncl (दीर्घ द्विगुण);

  बाह्य दीर्घ द्विगुण __cdecl fmodl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.10.2 */ 
  बाह्य द्विगुण __cdecl remainder (द्विगुण, द्विगुण);
  बाह्य भिन्न __cdecl remainderf (भिन्न, भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl remainderl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.10.3 */
  बाह्य द्विगुण __cdecl remquo(द्विगुण, द्विगुण, पूर्णाङ्क *);
  बाह्य भिन्न __cdecl remquof(भिन्न, भिन्न, पूर्णाङ्क *);
  बाह्य दीर्घ द्विगुण __cdecl remquol(दीर्घ द्विगुण, दीर्घ द्विगुण, पूर्णाङ्क *);

  /* 7.12.11.1 */
  बाह्य द्विगुण __cdecl copysign (द्विगुण, द्विगुण); /* in libmoldname.a */
  बाह्य भिन्न __cdecl copysignf (भिन्न, भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl copysignl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.11.2 Return a NaN */
  बाह्य द्विगुण __cdecl nan(ध्रुव वर्ण *tagp);
  बाह्य भिन्न __cdecl nanf(ध्रुव वर्ण *tagp);
  बाह्य दीर्घ द्विगुण __cdecl nanl(ध्रुव वर्ण *tagp);

#यदि_अपरिभाषितम् __STRICT_ANSI__
#परिभाषय _nan() nan("")
#परिभाषय _nanf() nanf("")
#परिभाषय _nanl() nanl("")
#यदि_अन्तः

  /* 7.12.11.3 */
  बाह्य द्विगुण __cdecl nextafter (द्विगुण, द्विगुण); /* in libmoldname.a */
  बाह्य भिन्न __cdecl nextafterf (भिन्न, भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl nextafterl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  बाह्य द्विगुण __cdecl fdim (द्विगुण x, द्विगुण y);
  बाह्य भिन्न __cdecl fdimf (भिन्न x, भिन्न y);
  बाह्य दीर्घ द्विगुण __cdecl fdiml (दीर्घ द्विगुण x, दीर्घ द्विगुण y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  बाह्य द्विगुण __cdecl fmax  (द्विगुण, द्विगुण);
  बाह्य भिन्न __cdecl fmaxf (भिन्न, भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl fmaxl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.12.3 */
  बाह्य द्विगुण __cdecl fmin (द्विगुण, द्विगुण);
  बाह्य भिन्न __cdecl fminf (भिन्न, भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl fminl (दीर्घ द्विगुण, दीर्घ द्विगुण);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  बाह्य द्विगुण __cdecl fma (द्विगुण, द्विगुण, द्विगुण);
  बाह्य भिन्न __cdecl fmaf (भिन्न, भिन्न, भिन्न);
  बाह्य दीर्घ द्विगुण __cdecl fmal (दीर्घ द्विगुण, दीर्घ द्विगुण, दीर्घ द्विगुण);


#यदि_अन्तः /* __STDC_VERSION__ >= 199901L */
#यदि_अन्तः /* __NO_ISOCEXT */

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#निर्देशः pack(निष्कासय)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#अन्तर्भाव "tcc/tcc_libm.h"

#यदि_अन्तः /* End _MATH_H_ */

