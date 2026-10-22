/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#جيڪڏهن_وصف_نه_ٿيل _TGMATH_H
#وصف_ڪريو _TGMATH_H

#ضمن <math.h>

#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#وصف_ڪريو __tgmath_real(x, F) \
  _Generic ((x), عائم: F##f, ڊگهو مزدوج: F##l, افتراضي: F)(x)
#وصف_ڪريو __tgmath_real_2_1(x, y, F) \
  _Generic ((x), عائم: F##f, ڊگهو مزدوج: F##l, افتراضي: F)(x, y)
#وصف_ڪريو __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), عائم: F##f, ڊگهو مزدوج: F##l, افتراضي: F)(x, y)
#وصف_ڪريو __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), عائم: F##f, ڊگهو مزدوج: F##l, افتراضي: F)(x, y, z)
#وصف_ڪريو __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), عائم: F##f, ڊگهو مزدوج: F##l, افتراضي: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#وصف_ڪريو acos(z)          __tgmath_real(z, acos)
#وصف_ڪريو asin(z)          __tgmath_real(z, asin)
#وصف_ڪريو atan(z)          __tgmath_real(z, atan)
#وصف_ڪريو acosh(z)         __tgmath_real(z, acosh)
#وصف_ڪريو asinh(z)         __tgmath_real(z, asinh)
#وصف_ڪريو atanh(z)         __tgmath_real(z, atanh)
#وصف_ڪريو جيب_تمام(z)           __tgmath_real(z, جيب_تمام)
#وصف_ڪريو جيب(z)           __tgmath_real(z, جيب)
#وصف_ڪريو tan(z)           __tgmath_real(z, tan)
#وصف_ڪريو cosh(z)          __tgmath_real(z, cosh)
#وصف_ڪريو sinh(z)          __tgmath_real(z, sinh)
#وصف_ڪريو tanh(z)          __tgmath_real(z, tanh)
#وصف_ڪريو قوت_نما(z)           __tgmath_real(z, قوت_نما)
#وصف_ڪريو لاگرٿم(z)           __tgmath_real(z, لاگرٿم)
#وصف_ڪريو قوت(z1,z2)       __tgmath_real_2(z1, z2, قوت)
#وصف_ڪريو جذر(z)          __tgmath_real(z, جذر)
#وصف_ڪريو fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#وصف_ڪريو atan2(x,y)       __tgmath_real_2(x, y, atan2)
#وصف_ڪريو cbrt(x)          __tgmath_real(x, cbrt)
#وصف_ڪريو ceil(x)          __tgmath_real(x, ceil)
#وصف_ڪريو copysign(x,y)    __tgmath_real_2(x, y, copysign)
#وصف_ڪريو erf(x)           __tgmath_real(x, erf)
#وصف_ڪريو erfc(x)          __tgmath_real(x, erfc)
#وصف_ڪريو exp2(x)          __tgmath_real(x, exp2)
#وصف_ڪريو expm1(x)         __tgmath_real(x, expm1)
#وصف_ڪريو fdim(x,y)        __tgmath_real_2(x, y, fdim)
#وصف_ڪريو floor(x)         __tgmath_real(x, floor)
#وصف_ڪريو fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#وصف_ڪريو fmax(x,y)        __tgmath_real_2(x, y, fmax)
#وصف_ڪريو fmin(x,y)        __tgmath_real_2(x, y, fmin)
#وصف_ڪريو fmod(x,y)        __tgmath_real_2(x, y, fmod)
#وصف_ڪريو frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#وصف_ڪريو hypot(x,y)       __tgmath_real_2(x, y, hypot)
#وصف_ڪريو ilogb(x)         __tgmath_real(x, ilogb)
#وصف_ڪريو ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#وصف_ڪريو lgamma(x)        __tgmath_real(x, lgamma)
#وصف_ڪريو llrint(x)        __tgmath_real(x, llrint)
#وصف_ڪريو llround(x)       __tgmath_real(x, llround)
#وصف_ڪريو log10(x)         __tgmath_real(x, log10)
#وصف_ڪريو log1p(x)         __tgmath_real(x, log1p)
#وصف_ڪريو log2(x)          __tgmath_real(x, log2)
#وصف_ڪريو logb(x)          __tgmath_real(x, logb)
#وصف_ڪريو lrint(x)         __tgmath_real(x, lrint)
#وصف_ڪريو lround(x)        __tgmath_real(x, lround)
#وصف_ڪريو nearbyint(x)     __tgmath_real(x, nearbyint)
#وصف_ڪريو nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#وصف_ڪريو nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#وصف_ڪريو remainder(x,y)   __tgmath_real_2(x, y, remainder)
#وصف_ڪريو remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#وصف_ڪريو rint(x)          __tgmath_real(x, rint)
#وصف_ڪريو ڦيرو(x)         __tgmath_real(x, ڦيرو)
#وصف_ڪريو scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#وصف_ڪريو scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#وصف_ڪريو tgamma(x)        __tgmath_real(x, tgamma)
#وصف_ڪريو trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#جيڪڏهن_پورو /* __cplusplus */
#جيڪڏهن_پورو /* _TGMATH_H */
