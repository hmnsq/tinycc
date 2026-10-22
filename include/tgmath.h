/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#اگر_تعریف_نشده _TGMATH_H
#تعریف_کن _TGMATH_H

#ضمن <math.h>

#اگر_تعریف_نشده __cplusplus
#تعریف_کن __tgmath_real(x, F) \
  _Generic ((x), عائم: F##f, دراز مزدوج: F##l, افتراضي: F)(x)
#تعریف_کن __tgmath_real_2_1(x, y, F) \
  _Generic ((x), عائم: F##f, دراز مزدوج: F##l, افتراضي: F)(x, y)
#تعریف_کن __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), عائم: F##f, دراز مزدوج: F##l, افتراضي: F)(x, y)
#تعریف_کن __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), عائم: F##f, دراز مزدوج: F##l, افتراضي: F)(x, y, z)
#تعریف_کن __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), عائم: F##f, دراز مزدوج: F##l, افتراضي: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#تعریف_کن acos(z)          __tgmath_real(z, acos)
#تعریف_کن asin(z)          __tgmath_real(z, asin)
#تعریف_کن atan(z)          __tgmath_real(z, atan)
#تعریف_کن acosh(z)         __tgmath_real(z, acosh)
#تعریف_کن asinh(z)         __tgmath_real(z, asinh)
#تعریف_کن atanh(z)         __tgmath_real(z, atanh)
#تعریف_کن کسینوس(z)           __tgmath_real(z, کسینوس)
#تعریف_کن سینوس(z)           __tgmath_real(z, سینوس)
#تعریف_کن tan(z)           __tgmath_real(z, tan)
#تعریف_کن cosh(z)          __tgmath_real(z, cosh)
#تعریف_کن sinh(z)          __tgmath_real(z, sinh)
#تعریف_کن tanh(z)          __tgmath_real(z, tanh)
#تعریف_کن نمایی_تابع(z)           __tgmath_real(z, نمایی_تابع)
#تعریف_کن لگاریتم(z)           __tgmath_real(z, لگاریتم)
#تعریف_کن توان(z1,z2)       __tgmath_real_2(z1, z2, توان)
#تعریف_کن جذر(z)          __tgmath_real(z, جذر)
#تعریف_کن fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#تعریف_کن atan2(x,y)       __tgmath_real_2(x, y, atan2)
#تعریف_کن cbrt(x)          __tgmath_real(x, cbrt)
#تعریف_کن ceil(x)          __tgmath_real(x, ceil)
#تعریف_کن copysign(x,y)    __tgmath_real_2(x, y, copysign)
#تعریف_کن erf(x)           __tgmath_real(x, erf)
#تعریف_کن erfc(x)          __tgmath_real(x, erfc)
#تعریف_کن exp2(x)          __tgmath_real(x, exp2)
#تعریف_کن expm1(x)         __tgmath_real(x, expm1)
#تعریف_کن fdim(x,y)        __tgmath_real_2(x, y, fdim)
#تعریف_کن floor(x)         __tgmath_real(x, floor)
#تعریف_کن fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#تعریف_کن fmax(x,y)        __tgmath_real_2(x, y, fmax)
#تعریف_کن fmin(x,y)        __tgmath_real_2(x, y, fmin)
#تعریف_کن fmod(x,y)        __tgmath_real_2(x, y, fmod)
#تعریف_کن frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#تعریف_کن hypot(x,y)       __tgmath_real_2(x, y, hypot)
#تعریف_کن ilogb(x)         __tgmath_real(x, ilogb)
#تعریف_کن ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#تعریف_کن lgamma(x)        __tgmath_real(x, lgamma)
#تعریف_کن llrint(x)        __tgmath_real(x, llrint)
#تعریف_کن llround(x)       __tgmath_real(x, llround)
#تعریف_کن log10(x)         __tgmath_real(x, log10)
#تعریف_کن log1p(x)         __tgmath_real(x, log1p)
#تعریف_کن log2(x)          __tgmath_real(x, log2)
#تعریف_کن logb(x)          __tgmath_real(x, logb)
#تعریف_کن lrint(x)         __tgmath_real(x, lrint)
#تعریف_کن lround(x)        __tgmath_real(x, lround)
#تعریف_کن nearbyint(x)     __tgmath_real(x, nearbyint)
#تعریف_کن nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#تعریف_کن nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#تعریف_کن remainder(x,y)   __tgmath_real_2(x, y, remainder)
#تعریف_کن remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#تعریف_کن rint(x)          __tgmath_real(x, rint)
#تعریف_کن دور(x)         __tgmath_real(x, دور)
#تعریف_کن scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#تعریف_کن scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#تعریف_کن tgamma(x)        __tgmath_real(x, tgamma)
#تعریف_کن trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#پایان_اگر /* __cplusplus */
#پایان_اگر /* _TGMATH_H */
