/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _MATH_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MATH_H_

#ਜੇ __GNUC__ >= 3
#ਹਦਾਇਤ GCC system_ਸਿਰਲੇਖ
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

ਬਣਤਰ exception;

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DOMAIN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SING 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਉਛਾਲ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UNDERFLOW 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TLOSS 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PLOSS 6

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRICT_ANSI__
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN _DOMAIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SING _SING
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਉਛਾਲ_2 ਉਛਾਲ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNDERFLOW _UNDERFLOW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TLOSS _TLOSS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PLOSS _PLOSS
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRICT_ANSI__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_E 2.71828182845904523536
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_LOG2E 1.44269504088896340736
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_LOG10E 0.434294481903251827651
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_LN2 0.693147180559945309417
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_LN10 2.30258509299404568402
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_PI 3.14159265358979323846
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_PI_2 1.57079632679489661923
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_PI_4 0.785398163397448309616
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_1_PI 0.318309886183790671538
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_2_PI 0.636619772367581343076
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_2_SQRTPI 1.12837916709551257390
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_SQRT2 1.41421356237309504880
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_SQRT1_2 0.707106781186547524401
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRICT_ANSI__
/* See also float.h  */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __MINGW_FPCLASS_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MINGW_FPCLASS_DEFINED 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_NN	0x0008	/* Negative Normal */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_ND	0x0010	/* Negative Denormal */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_NZ	0x0020	/* Negative Zero */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_PZ	0x0040	/* Positive Zero */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_PD	0x0080	/* Positive Denormal */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_PN	0x0100	/* Positive Normal */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _EXCEPTION_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _EXCEPTION_DEFINED
  ਬਣਤਰ _exception {
    ਪੂਰਨ type;
    ਅੱਖਰ *name;
    ਦੁੱਗਣਾ arg1;
    ਦੁੱਗਣਾ arg2;
    ਦੁੱਗਣਾ retval;
  };
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _COMPLEX_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _COMPLEX_DEFINED
  ਬਣਤਰ _complex {
    ਦੁੱਗਣਾ x,y;
  };
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EDOM 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERANGE 34

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _HUGE
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਦੁੱਗਣਾ *_HUGE;
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਦੁੱਗਣਾ *_imp___HUGE;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HUGE	(*_imp___HUGE)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HUGE_VAL _HUGE

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_ABS_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ABS_DEFINED
  ਪੂਰਨ __cdecl ਨਿਰਪੇਖ(ਪੂਰਨ _X);
  ਲੰਮਾ __cdecl labs(ਲੰਮਾ _X);
#ਜੇ_ਅੰਤ
  ਦੁੱਗਣਾ __cdecl acos(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl asin(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl atan(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl atan2(ਦੁੱਗਣਾ _Y,ਦੁੱਗਣਾ _X);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SIGN_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SIGN_DEFINED
  _CRTIMP ਦੁੱਗਣਾ __cdecl _copysign (ਦੁੱਗਣਾ ਸੰਖਿਆ,ਦੁੱਗਣਾ _Sign);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _chgsign (ਦੁੱਗਣਾ _X);
#ਜੇ_ਅੰਤ
  ਦੁੱਗਣਾ __cdecl ਕੋਜੀਵਾ(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl cosh(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl ਘਾਤਾਂਕ(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl expm1(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl fabs(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl fmod(ਦੁੱਗਣਾ _X,ਦੁੱਗਣਾ _Y);
  ਦੁੱਗਣਾ __cdecl ਲਘੂਗਣਕ(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl log10(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl ਘਾਤ(ਦੁੱਗਣਾ _X,ਦੁੱਗਣਾ _Y);
  ਦੁੱਗਣਾ __cdecl ਜੀਵਾ(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl sinh(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl tan(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl tanh(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl ਵਰਗਮੂਲ(ਦੁੱਗਣਾ _X);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_ATOF_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ATOF_DEFINED
  ਦੁੱਗਣਾ __cdecl atof(ਅਚਲ ਅੱਖਰ *_String);
  ਦੁੱਗਣਾ __cdecl _atof_l(ਅਚਲ ਅੱਖਰ *_String,_locale_t _Locale);
#ਜੇ_ਅੰਤ

  _CRTIMP ਦੁੱਗਣਾ __cdecl _cabs(ਬਣਤਰ _complex _ComplexA);
  ਦੁੱਗਣਾ __cdecl ceil(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl floor(ਦੁੱਗਣਾ _X);
  ਦੁੱਗਣਾ __cdecl frexp(ਦੁੱਗਣਾ _X,ਪੂਰਨ *_Y);
  ਦੁੱਗਣਾ __cdecl _hypot(ਦੁੱਗਣਾ _X,ਦੁੱਗਣਾ _Y);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _j0(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _j1(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _jn(ਪੂਰਨ _X,ਦੁੱਗਣਾ _Y);
  ਦੁੱਗਣਾ __cdecl ldexp(ਦੁੱਗਣਾ _X,ਪੂਰਨ _Y);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_MATHERR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_MATHERR_DEFINED
  ਪੂਰਨ __cdecl _matherr(ਬਣਤਰ _exception *_Except);
#ਜੇ_ਅੰਤ
  ਦੁੱਗਣਾ __cdecl modf(ਦੁੱਗਣਾ _X,ਦੁੱਗਣਾ *_Y);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _y0(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _y1(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _yn(ਪੂਰਨ _X,ਦੁੱਗਣਾ _Y);

#ਜੇ(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ਪੂਰਨ __cdecl ਸੈੱਟ_SSE2_enable(ਪੂਰਨ _Flag);
  /* from libmingwex */
  ਦਸ਼ਮਲਵ __cdecl _hypotf(ਦਸ਼ਮਲਵ _X,ਦਸ਼ਮਲਵ _Y);
#ਜੇ_ਅੰਤ

  ਦਸ਼ਮਲਵ frexpf(ਦਸ਼ਮਲਵ _X,ਪੂਰਨ *_Y);
  ਦਸ਼ਮਲਵ __cdecl ldexpf(ਦਸ਼ਮਲਵ _X,ਪੂਰਨ _Y);
  ਲੰਮਾ ਦੁੱਗਣਾ __cdecl ldexpl(ਲੰਮਾ ਦੁੱਗਣਾ _X,ਪੂਰਨ _Y);
  ਦਸ਼ਮਲਵ __cdecl acosf(ਦਸ਼ਮਲਵ _X);
  ਦਸ਼ਮਲਵ __cdecl asinf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl atanf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl atan2f(ਦਸ਼ਮਲਵ _X,ਦਸ਼ਮਲਵ _Y);
   ਦਸ਼ਮਲਵ __cdecl cosf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl sinf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl tanf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl coshf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl sinhf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl tanhf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl expf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl expm1f(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl logf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl log10f(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl modff(ਦਸ਼ਮਲਵ _X,ਦਸ਼ਮਲਵ *_Y);
   ਦਸ਼ਮਲਵ __cdecl powf(ਦਸ਼ਮਲਵ _X,ਦਸ਼ਮਲਵ _Y);
   ਦਸ਼ਮਲਵ __cdecl sqrtf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl ceilf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl floorf(ਦਸ਼ਮਲਵ _X);
  ਦਸ਼ਮਲਵ __cdecl fmodf(ਦਸ਼ਮਲਵ _X,ਦਸ਼ਮਲਵ _Y);
   ਦਸ਼ਮਲਵ __cdecl _hypotf(ਦਸ਼ਮਲਵ _X,ਦਸ਼ਮਲਵ _Y);
  ਦਸ਼ਮਲਵ __cdecl fabsf(ਦਸ਼ਮਲਵ _X);
#ਜੇ !defined(__ia64__)
   /* from libmingwex */
   ਦਸ਼ਮਲਵ __cdecl _copysignf (ਦਸ਼ਮਲਵ ਸੰਖਿਆ,ਦਸ਼ਮਲਵ _Sign);
   ਦਸ਼ਮਲਵ __cdecl _chgsignf (ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl _logbf(ਦਸ਼ਮਲਵ _X);
   ਦਸ਼ਮਲਵ __cdecl _nextafterf(ਦਸ਼ਮਲਵ _X,ਦਸ਼ਮਲਵ _Y);
   ਪੂਰਨ __cdecl _finitef(ਦਸ਼ਮਲਵ _X);
   ਪੂਰਨ __cdecl _isnanf(ਦਸ਼ਮਲਵ _X);
   ਪੂਰਨ __cdecl _fpclassf(ਦਸ਼ਮਲਵ _X);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ matherr _matherr

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HUGE	_HUGE
  /*	double __cdecl cabs(struct _complex _X); */
  ਦੁੱਗਣਾ __cdecl hypot(ਦੁੱਗਣਾ _X,ਦੁੱਗਣਾ _Y);
  _CRTIMP ਦੁੱਗਣਾ __cdecl j0(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl j1(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl jn(ਪੂਰਨ _X,ਦੁੱਗਣਾ _Y);
  _CRTIMP ਦੁੱਗਣਾ __cdecl y0(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl y1(ਦੁੱਗਣਾ _X);
  _CRTIMP ਦੁੱਗਣਾ __cdecl yn(ਪੂਰਨ _X,ਦੁੱਗਣਾ _Y);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __NO_ISOCEXT
#ਜੇ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined __STRICT_ANSI__ || defined __GLIBCPP__

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NAN (0.0F/0.0F)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HUGE_VALF (1.0F/0.0F)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HUGE_VALL (1.0L/0.0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INFINITY (1.0F/0.0F)


#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FP_NAN		0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FP_NORMAL	0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FP_INFINITE	(FP_NAN | FP_NORMAL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FP_ZERO		0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
  */

  ਬਾਹਰੀ ਪੂਰਨ __cdecl __fpclassifyf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਪੂਰਨ __cdecl __fpclassify (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਪੂਰਨ __cdecl __fpclassifyl (ਲੰਮਾ ਦੁੱਗਣਾ);

/* Implemented at tcc/tcc_libm.h
#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (double) ? __fpclassify (x) \
  : __fpclassifyl (x))
*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fpclassify(x) \
  _Generic(x, ਦਸ਼ਮਲਵ: __fpclassifyf, ਦੁੱਗਣਾ: __fpclassify, ਲੰਮਾ ਦੁੱਗਣਾ: __fpclassifyl)(x)

  /* 7.12.3.2 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  ਬਾਹਰੀ ਪੂਰਨ __cdecl __signbitf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਪੂਰਨ __cdecl __signbit (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਪੂਰਨ __cdecl __signbitl (ਲੰਮਾ ਦੁੱਗਣਾ);

/* Implemented at tcc/tcc_libm.h
#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x)	\
  : sizeof (x) == sizeof (double) ? __signbit (x)	\
  : __signbitl (x))
*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ signbit(x) \
  _Generic(x, ਦਸ਼ਮਲਵ: __signbitf, ਦੁੱਗਣਾ: __signbit, ਲੰਮਾ ਦੁੱਗਣਾ: __signbitl)(x)

  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl exp2(ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl exp2f(ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl exp2l(ਲੰਮਾ ਦੁੱਗਣਾ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FP_ILOGB0 ((ਪੂਰਨ)0x80000000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FP_ILOGBNAN ((ਪੂਰਨ)0x80000000)
  ਬਾਹਰੀ ਪੂਰਨ __cdecl ilogb (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਪੂਰਨ __cdecl ilogbf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਪੂਰਨ __cdecl ilogbl (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl log1p(ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl log1pf(ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl log1pl(ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl log2 (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl log2f (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl log2l (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl logb (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl logbf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl logbl (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl modfl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ*);

  /* 7.12.6.13 */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl scalbn (ਦੁੱਗਣਾ, ਪੂਰਨ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl scalbnf (ਦਸ਼ਮਲਵ, ਪੂਰਨ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl scalbnl (ਲੰਮਾ ਦੁੱਗਣਾ, ਪੂਰਨ);

  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl scalbln (ਦੁੱਗਣਾ, ਲੰਮਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl scalblnf (ਦਸ਼ਮਲਵ, ਲੰਮਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl scalblnl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl cbrt (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl cbrtf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl cbrtl (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl hypot (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl hypotf (ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl hypotl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl powl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl expl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl expm1l(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl coshl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fabsl (ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl acosl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl asinl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl atanl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl atan2l(ਲੰਮਾ ਦੁੱਗਣਾ,ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl sinhl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl tanhl(ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.8.1 The erf functions  */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl erf (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl erff (ਦਸ਼ਮਲਵ);
  /* TODO
  extern long double __cdecl erfl (long double);
  */ 

  /* 7.12.8.2 The erfc functions  */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl erfc (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl erfcf (ਦਸ਼ਮਲਵ);
  /* TODO
  extern long double __cdecl erfcl (long double);
  */ 

  /* 7.12.8.3 The lgamma functions */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl lgamma (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl lgammaf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl lgammal (ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.8.4 The tgamma functions */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl tgamma (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl tgammaf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl tgammal (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl ceill (ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl floorl (ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl frexpl(ਲੰਮਾ ਦੁੱਗਣਾ,ਪੂਰਨ *);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl log10l(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl logl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl cosl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl sinl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl tanl(ਲੰਮਾ ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ sqrtl(ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.9.3 */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl nearbyint ( ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl nearbyintf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl nearbyintl (ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl rint (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl rintf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl rintl (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਲੰਮਾ __cdecl lrint (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ __cdecl lrintf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ __cdecl lrintl (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਲੰਮਾ ਲੰਮਾ __cdecl llrint (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਲੰਮਾ __cdecl llrintf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਲੰਮਾ __cdecl llrintl (ਲੰਮਾ ਦੁੱਗਣਾ);

  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_TONEAREST	0x0000
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_DOWNWARD	0x0400
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_UPWARD	0x0800
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_TOWARDZERO	0x0c00

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl ਗੇੜਾ (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl roundf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl roundl (ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.9.7  */
  ਬਾਹਰੀ ਲੰਮਾ __cdecl lround (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ __cdecl lroundf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ __cdecl lroundl (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਲੰਮਾ ਲੰਮਾ __cdecl llround (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਲੰਮਾ ਲੰਮਾ __cdecl llroundf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਲੰਮਾ __cdecl llroundl (ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl trunc (ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl truncf (ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl truncl (ਲੰਮਾ ਦੁੱਗਣਾ);

  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fmodl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.10.2 */ 
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl remainder (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl remainderf (ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl remainderl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.10.3 */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl remquo(ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ਪੂਰਨ *);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl remquof(ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ, ਪੂਰਨ *);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl remquol(ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ, ਪੂਰਨ *);

  /* 7.12.11.1 */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl copysign (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ); /* in libmoldname.a */
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl copysignf (ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl copysignl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.11.2 Return a NaN */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl nan(ਅਚਲ ਅੱਖਰ *tagp);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl nanf(ਅਚਲ ਅੱਖਰ *tagp);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl nanl(ਅਚਲ ਅੱਖਰ *tagp);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRICT_ANSI__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _nan() nan("")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _nanf() nanf("")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _nanl() nanl("")
#ਜੇ_ਅੰਤ

  /* 7.12.11.3 */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl nextafter (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ); /* in libmoldname.a */
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl nextafterf (ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl nextafterl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl fdim (ਦੁੱਗਣਾ x, ਦੁੱਗਣਾ y);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl fdimf (ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fdiml (ਲੰਮਾ ਦੁੱਗਣਾ x, ਲੰਮਾ ਦੁੱਗਣਾ y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl fmax  (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl fmaxf (ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fmaxl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.12.3 */
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl fmin (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl fminf (ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fminl (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);

  /* 7.12.13.1 */
  /* return x * y + z as a ternary op */ 
  ਬਾਹਰੀ ਦੁੱਗਣਾ __cdecl fma (ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ);
  ਬਾਹਰੀ ਦਸ਼ਮਲਵ __cdecl fmaf (ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ);
  ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ __cdecl fmal (ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ, ਲੰਮਾ ਦੁੱਗਣਾ);


#ਜੇ_ਅੰਤ /* __STDC_VERSION__ >= 199901L */
#ਜੇ_ਅੰਤ /* __NO_ISOCEXT */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਹਦਾਇਤ pack(ਕੱਢੋ)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (inline __fpclassify*, __signbit* and variants) */
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc/tcc_libm.h"

#ਜੇ_ਅੰਤ /* End _MATH_H_ */

