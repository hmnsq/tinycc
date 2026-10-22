/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _MATH_H_
#घोषणा _MATH_H_

#अगर __GNUC__ >= 3
#आशय GCC system_header
#पूर्ण_अगर

#समावेश <_mingw.h>

काष्ठा exception;

#आशय pack(धकेलो,_CRT_PACKING)

#घोषणा _DOMAIN 1
#घोषणा _SING 2
#घोषणा _OVERFLOW 3
#घोषणा _UNDERFLOW 4
#घोषणा _TLOSS 5
#घोषणा _PLOSS 6

#अगर_अघोषित __STRICT_ANSI__
#अगर_अघोषित	NO_OLDNAMES
#घोषणा DOMAIN _DOMAIN
#घोषणा SING _SING
#घोषणा OVERFLOW _OVERFLOW
#घोषणा UNDERFLOW _UNDERFLOW
#घोषणा TLOSS _TLOSS
#घोषणा PLOSS _PLOSS
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित __STRICT_ANSI__
#घोषणा M_E 2.71828182845904523536
#घोषणा M_LOG2E 1.44269504088896340736
#घोषणा M_LOG10E 0.434294481903251827651
#घोषणा M_LN2 0.693147180559945309417
#घोषणा M_LN10 2.30258509299404568402
#घोषणा M_PI 3.14159265358979323846
#घोषणा M_PI_2 1.57079632679489661923
#घोषणा M_PI_4 0.785398163397448309616
#घोषणा M_1_PI 0.318309886183790671538
#घोषणा M_2_PI 0.636619772367581343076
#घोषणा M_2_SQRTPI 1.12837916709551257390
#घोषणा M_SQRT2 1.41421356237309504880
#घोषणा M_SQRT1_2 0.707106781186547524401
#पूर्ण_अगर

#अगर_अघोषित __STRICT_ANSI__
/* See also float.h  */
#अगर_अघोषित __MINGW_FPCLASS_DEFINED
#घोषणा __MINGW_FPCLASS_DEFINED 1
#घोषणा	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#घोषणा	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#घोषणा	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#घोषणा	_FPCLASS_NN	0x0008	/* Negative Normal */
#घोषणा	_FPCLASS_ND	0x0010	/* Negative Denormal */
#घोषणा	_FPCLASS_NZ	0x0020	/* Negative Zero */
#घोषणा	_FPCLASS_PZ	0x0040	/* Positive Zero */
#घोषणा	_FPCLASS_PD	0x0080	/* Positive Denormal */
#घोषणा	_FPCLASS_PN	0x0100	/* Positive Normal */
#घोषणा	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _EXCEPTION_DEFINED
#घोषणा _EXCEPTION_DEFINED
  काष्ठा _exception {
    पूर्णांक type;
    अक्षर *name;
    द्विगुन arg1;
    द्विगुन arg2;
    द्विगुन retval;
  };
#पूर्ण_अगर

#अगर_अघोषित _COMPLEX_DEFINED
#घोषणा _COMPLEX_DEFINED
  काष्ठा _complex {
    द्विगुन x,y;
  };
#पूर्ण_अगर

#घोषणा गलत_तर्क 33
#घोषणा दुस्फल 34

#अगर_अघोषित _HUGE
#अगर_घोषित _MSVCRT_
  बाह्य द्विगुन *_HUGE;
#अन्यथा
  बाह्य द्विगुन *_imp___HUGE;
#घोषणा _HUGE	(*_imp___HUGE)
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा विशाल_मान _HUGE

#अगर_अघोषित _CRT_ABS_DEFINED
#घोषणा _CRT_ABS_DEFINED
  पूर्णांक __cdecl असल(पूर्णांक _X);
  दीर्घ __cdecl द_असल(दीर्घ _X);
#पूर्ण_अगर
  द्विगुन __cdecl acos(द्विगुन _X);
  द्विगुन __cdecl asin(द्विगुन _X);
  द्विगुन __cdecl atan(द्विगुन _X);
  द्विगुन __cdecl atan2(द्विगुन _Y,द्विगुन _X);
#अगर_अघोषित _SIGN_DEFINED
#घोषणा _SIGN_DEFINED
  _CRTIMP द्विगुन __cdecl _copysign (द्विगुन संख्या,द्विगुन _Sign);
  _CRTIMP द्विगुन __cdecl _chgsign (द्विगुन _X);
#पूर्ण_अगर
  द्विगुन __cdecl cos(द्विगुन _X);
  द्विगुन __cdecl cosh(द्विगुन _X);
  द्विगुन __cdecl exp(द्विगुन _X);
  द्विगुन __cdecl expm1(द्विगुन _X);
  द्विगुन __cdecl भ_असल(द्विगुन _X);
  द्विगुन __cdecl भ_शेष(द्विगुन _X,द्विगुन _Y);
  द्विगुन __cdecl log(द्विगुन _X);
  द्विगुन __cdecl log10(द्विगुन _X);
  द्विगुन __cdecl घात(द्विगुन _X,द्विगुन _Y);
  द्विगुन __cdecl sin(द्विगुन _X);
  द्विगुन __cdecl sinh(द्विगुन _X);
  द्विगुन __cdecl tan(द्विगुन _X);
  द्विगुन __cdecl tanh(द्विगुन _X);
  द्विगुन __cdecl वर्ग_मूल(द्विगुन _X);
#अगर_अघोषित _CRT_ATOF_DEFINED
#घोषणा _CRT_ATOF_DEFINED
  द्विगुन __cdecl म_से_भ(स्थिर अक्षर *_String);
  द्विगुन __cdecl _atof_l(स्थिर अक्षर *_String,_locale_t _Locale);
#पूर्ण_अगर

  _CRTIMP द्विगुन __cdecl _cabs(काष्ठा _complex _ComplexA);
  द्विगुन __cdecl उच्चमान(द्विगुन _X);
  द्विगुन __cdecl न्यूनमान(द्विगुन _X);
  द्विगुन __cdecl frexp(द्विगुन _X,पूर्णांक *_Y);
  द्विगुन __cdecl _hypot(द्विगुन _X,द्विगुन _Y);
  _CRTIMP द्विगुन __cdecl _j0(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl _j1(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl _jn(पूर्णांक _X,द्विगुन _Y);
  द्विगुन __cdecl ldexp(द्विगुन _X,पूर्णांक _Y);
#अगर_अघोषित _CRT_MATHERR_DEFINED
#घोषणा _CRT_MATHERR_DEFINED
  पूर्णांक __cdecl _matherr(काष्ठा _exception *_Except);
#पूर्ण_अगर
  द्विगुन __cdecl modf(द्विगुन _X,द्विगुन *_Y);
  _CRTIMP द्विगुन __cdecl _y0(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl _y1(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl _yn(पूर्णांक _X,द्विगुन _Y);

#अगर(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णांक __cdecl _set_SSE2_enable(पूर्णांक _Flag);
  /* from libmingwex */
  भग्न __cdecl _hypotf(भग्न _X,भग्न _Y);
#पूर्ण_अगर

  भग्न frexpf(भग्न _X,पूर्णांक *_Y);
  भग्न __cdecl ldexpf(भग्न _X,पूर्णांक _Y);
  दीर्घ द्विगुन __cdecl ldexpl(दीर्घ द्विगुन _X,पूर्णांक _Y);
  भग्न __cdecl acosf(भग्न _X);
  भग्न __cdecl asinf(भग्न _X);
   भग्न __cdecl atanf(भग्न _X);
   भग्न __cdecl atan2f(भग्न _X,भग्न _Y);
   भग्न __cdecl cosf(भग्न _X);
   भग्न __cdecl sinf(भग्न _X);
   भग्न __cdecl tanf(भग्न _X);
   भग्न __cdecl coshf(भग्न _X);
   भग्न __cdecl sinhf(भग्न _X);
   भग्न __cdecl tanhf(भग्न _X);
   भग्न __cdecl expf(भग्न _X);
   भग्न __cdecl expm1f(भग्न _X);
   भग्न __cdecl logf(भग्न _X);
   भग्न __cdecl log10f(भग्न _X);
   भग्न __cdecl modff(भग्न _X,भग्न *_Y);
   भग्न __cdecl powf(भग्न _X,भग्न _Y);
   भग्न __cdecl sqrtf(भग्न _X);
   भग्न __cdecl ceilf(भग्न _X);
   भग्न __cdecl floorf(भग्न _X);
  भग्न __cdecl fmodf(भग्न _X,भग्न _Y);
   भग्न __cdecl _hypotf(भग्न _X,भग्न _Y);
  भग्न __cdecl fabsf(भग्न _X);
#अगर !defined(__ia64__)
   /* from libmingwex */
   भग्न __cdecl _copysignf (भग्न संख्या,भग्न _Sign);
   भग्न __cdecl _chgsignf (भग्न _X);
   भग्न __cdecl _logbf(भग्न _X);
   भग्न __cdecl _nextafterf(भग्न _X,भग्न _Y);
   पूर्णांक __cdecl _finitef(भग्न _X);
   पूर्णांक __cdecl _isnanf(भग्न _X);
   पूर्णांक __cdecl _fpclassf(भग्न _X);
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
#घोषणा matherr _matherr

#घोषणा HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  द्विगुन __cdecl hypot(द्विगुन _X,द्विगुन _Y);
  _CRTIMP द्विगुन __cdecl j0(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl j1(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl jn(पूर्णांक _X,द्विगुन _Y);
  _CRTIMP द्विगुन __cdecl y0(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl y1(द्विगुन _X);
  _CRTIMP द्विगुन __cdecl yn(पूर्णांक _X,द्विगुन _Y);
#पूर्ण_अगर

#अगर_अघोषित __NO_ISOCEXT
#अगर (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#घोषणा न_अंक (0.0F/0.0F)
#घोषणा HUGE_VALF (1.0F/0.0F)
#घोषणा HUGE_VALL (1.0L/0.0L)
#घोषणा अनन्त (1.0F/0.0F)


#घोषणा FP_NAN		0x0100
#घोषणा FP_NORMAL	0x0400
#घोषणा FP_INFINITE	(FP_NAN | FP_NORMAL)
#घोषणा FP_ZERO		0x4000
#घोषणा FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  बाह्य पूर्णांक __cdecl __fpclassifyf (भग्न);
  बाह्य पूर्णांक __cdecl __fpclassify (द्विगुन);
  बाह्य पूर्णांक __cdecl __fpclassifyl (दीर्घ द्विगुन);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#घोषणा fpclassify(x) \
  _Generic(x, भग्न: __fpclassifyf, द्विगुन: __fpclassify, दीर्घ द्विगुन: __fpclassifyl)(x)

  /* 7.12.3.2 */
#घोषणा है_सीमित(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#घोषणा isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#घोषणा isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#घोषणा isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  बाह्य पूर्णांक __cdecl __signbitf (भग्न);
  बाह्य पूर्णांक __cdecl __signbit (द्विगुन);
  बाह्य पूर्णांक __cdecl __signbitl (दीर्घ द्विगुन);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#घोषणा signbit(x) \
  _Generic(x, भग्न: __signbitf, द्विगुन: __signbit, दीर्घ द्विगुन: __signbitl)(x)

  बाह्य द्विगुन __cdecl exp2(द्विगुन);
  बाह्य भग्न __cdecl exp2f(भग्न);
  बाह्य दीर्घ द्विगुन __cdecl exp2l(दीर्घ द्विगुन);

#घोषणा FP_ILOGB0 ((पूर्णांक)0x80000000)
#घोषणा FP_ILOGBNAN ((पूर्णांक)0x80000000)
  बाह्य पूर्णांक __cdecl ilogb (द्विगुन);
  बाह्य पूर्णांक __cdecl ilogbf (भग्न);
  बाह्य पूर्णांक __cdecl ilogbl (दीर्घ द्विगुन);

  बाह्य द्विगुन __cdecl log1p(द्विगुन);
  बाह्य भग्न __cdecl log1pf(भग्न);
  बाह्य दीर्घ द्विगुन __cdecl log1pl(दीर्घ द्विगुन);

  बाह्य द्विगुन __cdecl log2 (द्विगुन);
  बाह्य भग्न __cdecl log2f (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl log2l (दीर्घ द्विगुन);

  बाह्य द्विगुन __cdecl logb (द्विगुन);
  बाह्य भग्न __cdecl logbf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl logbl (दीर्घ द्विगुन);

  बाह्य दीर्घ द्विगुन __cdecl modfl (दीर्घ द्विगुन, दीर्घ द्विगुन*);

  /* 7.12.6.13 */
  बाह्य द्विगुन __cdecl scalbn (द्विगुन, पूर्णांक);
  बाह्य भग्न __cdecl scalbnf (भग्न, पूर्णांक);
  बाह्य दीर्घ द्विगुन __cdecl scalbnl (दीर्घ द्विगुन, पूर्णांक);

  बाह्य द्विगुन __cdecl scalbln (द्विगुन, दीर्घ);
  बाह्य भग्न __cdecl scalblnf (भग्न, दीर्घ);
  बाह्य दीर्घ द्विगुन __cdecl scalblnl (दीर्घ द्विगुन, दीर्घ);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  बाह्य द्विगुन __cdecl cbrt (द्विगुन);
  बाह्य भग्न __cdecl cbrtf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl cbrtl (दीर्घ द्विगुन);

  बाह्य द्विगुन __cdecl hypot (द्विगुन, द्विगुन);
  बाह्य भग्न __cdecl hypotf (भग्न, भग्न);
  बाह्य दीर्घ द्विगुन __cdecl hypotl (दीर्घ द्विगुन, दीर्घ द्विगुन);

  बाह्य दीर्घ द्विगुन __cdecl powl (दीर्घ द्विगुन, दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl expl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl expm1l(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl coshl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl fabsl (दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl acosl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl asinl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl atanl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl atan2l(दीर्घ द्विगुन,दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl sinhl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl tanhl(दीर्घ द्विगुन);

  /* 7.12.8.1 The erf functions  */
  बाह्य द्विगुन __cdecl erf (द्विगुन);
  बाह्य भग्न __cdecl erff (भग्न);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  बाह्य द्विगुन __cdecl erfc (द्विगुन);
  बाह्य भग्न __cdecl erfcf (भग्न);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  बाह्य द्विगुन __cdecl lgamma (द्विगुन);
  बाह्य भग्न __cdecl lgammaf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl lgammal (दीर्घ द्विगुन);

  /* 7.12.8.4 The tgamma functions */
  बाह्य द्विगुन __cdecl tgamma (द्विगुन);
  बाह्य भग्न __cdecl tgammaf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl tgammal (दीर्घ द्विगुन);

  बाह्य दीर्घ द्विगुन __cdecl ceill (दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl floorl (दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl frexpl(दीर्घ द्विगुन,पूर्णांक *);
  बाह्य दीर्घ द्विगुन __cdecl log10l(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl logl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl cosl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl sinl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन __cdecl tanl(दीर्घ द्विगुन);
  बाह्य दीर्घ द्विगुन sqrtl(दीर्घ द्विगुन);

  /* 7.12.9.3 */
  बाह्य द्विगुन __cdecl nearbyint ( द्विगुन);
  बाह्य भग्न __cdecl nearbyintf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl nearbyintl (दीर्घ द्विगुन);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  बाह्य द्विगुन __cdecl rint (द्विगुन);
  बाह्य भग्न __cdecl rintf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl rintl (दीर्घ द्विगुन);

  बाह्य दीर्घ __cdecl lrint (द्विगुन);
  बाह्य दीर्घ __cdecl lrintf (भग्न);
  बाह्य दीर्घ __cdecl lrintl (दीर्घ द्विगुन);

  बाह्य दीर्घ दीर्घ __cdecl llrint (द्विगुन);
  बाह्य दीर्घ दीर्घ __cdecl llrintf (भग्न);
  बाह्य दीर्घ दीर्घ __cdecl llrintl (दीर्घ द्विगुन);

  #घोषणा FE_TONEAREST	0x0000
  #घोषणा FE_DOWNWARD	0x0400
  #घोषणा FE_UPWARD	0x0800
  #घोषणा FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  बाह्य द्विगुन __cdecl round (द्विगुन);
  बाह्य भग्न __cdecl roundf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl roundl (दीर्घ द्विगुन);

  /* 7.12.9.7  */
  बाह्य दीर्घ __cdecl lround (द्विगुन);
  बाह्य दीर्घ __cdecl lroundf (भग्न);
  बाह्य दीर्घ __cdecl lroundl (दीर्घ द्विगुन);

  बाह्य दीर्घ दीर्घ __cdecl llround (द्विगुन);
  बाह्य दीर्घ दीर्घ __cdecl llroundf (भग्न);
  बाह्य दीर्घ दीर्घ __cdecl llroundl (दीर्घ द्विगुन);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  बाह्य द्विगुन __cdecl trunc (द्विगुन);
  बाह्य भग्न __cdecl truncf (भग्न);
  बाह्य दीर्घ द्विगुन __cdecl truncl (दीर्घ द्विगुन);

  बाह्य दीर्घ द्विगुन __cdecl fmodl (दीर्घ द्विगुन, दीर्घ द्विगुन);

  /* 7.12.10.2 */ 
  बाह्य द्विगुन __cdecl remainder (द्विगुन, द्विगुन);
  बाह्य भग्न __cdecl remainderf (भग्न, भग्न);
  बाह्य दीर्घ द्विगुन __cdecl remainderl (दीर्घ द्विगुन, दीर्घ द्विगुन);

  /* 7.12.10.3 */
  बाह्य द्विगुन __cdecl remquo(द्विगुन, द्विगुन, पूर्णांक *);
  बाह्य भग्न __cdecl remquof(भग्न, भग्न, पूर्णांक *);
  बाह्य दीर्घ द्विगुन __cdecl remquol(दीर्घ द्विगुन, दीर्घ द्विगुन, पूर्णांक *);

  /* 7.12.11.1 */
  बाह्य द्विगुन __cdecl copysign (द्विगुन, द्विगुन); /* in libmoldname.a */
  बाह्य भग्न __cdecl copysignf (भग्न, भग्न);
  बाह्य दीर्घ द्विगुन __cdecl copysignl (दीर्घ द्विगुन, दीर्घ द्विगुन);

  /* 7.12.11.2 Return a NaN */
  बाह्य द्विगुन __cdecl nan(स्थिर अक्षर *tagp);
  बाह्य भग्न __cdecl nanf(स्थिर अक्षर *tagp);
  बाह्य दीर्घ द्विगुन __cdecl nanl(स्थिर अक्षर *tagp);

#अगर_अघोषित __STRICT_ANSI__
#घोषणा _nan() nan("")
#घोषणा _nanf() nanf("")
#घोषणा _nanl() nanl("")
#पूर्ण_अगर

  /* 7.12.11.3 */
  बाह्य द्विगुन __cdecl nextafter (द्विगुन, द्विगुन); /* in libmoldname.a */
  बाह्य भग्न __cdecl nextafterf (भग्न, भग्न);
  बाह्य दीर्घ द्विगुन __cdecl nextafterl (दीर्घ द्विगुन, दीर्घ द्विगुन);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  बाह्य द्विगुन __cdecl fdim (द्विगुन x, द्विगुन y);
  बाह्य भग्न __cdecl fdimf (भग्न x, भग्न y);
  बाह्य दीर्घ द्विगुन __cdecl fdiml (दीर्घ द्विगुन x, दीर्घ द्विगुन y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  बाह्य द्विगुन __cdecl fmax  (द्विगुन, द्विगुन);
  बाह्य भग्न __cdecl fmaxf (भग्न, भग्न);
  बाह्य दीर्घ द्विगुन __cdecl fmaxl (दीर्घ द्विगुन, दीर्घ द्विगुन);

  /* 7.12.12.3 */
  बाह्य द्विगुन __cdecl fmin (द्विगुन, द्विगुन);
  बाह्य भग्न __cdecl fminf (भग्न, भग्न);
  बाह्य दीर्घ द्विगुन __cdecl fminl (दीर्घ द्विगुन, दीर्घ द्विगुन);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  बाह्य द्विगुन __cdecl fma (द्विगुन, द्विगुन, द्विगुन);
  बाह्य भग्न __cdecl fmaf (भग्न, भग्न, भग्न);
  बाह्य दीर्घ द्विगुन __cdecl fmal (दीर्घ द्विगुन, दीर्घ द्विगुन, दीर्घ द्विगुन);


#पूर्ण_अगर /* __STDC_VERSION__ >= 199901L */
#पूर्ण_अगर /* __NO_ISOCEXT */

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#आशय pack(निकालो)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#समावेश "tcc/tcc_libm.h"

#पूर्ण_अगर /* End _MATH_H_ */

