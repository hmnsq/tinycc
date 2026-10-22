/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#నిర్వచితం_కాకపోతే _TGMATH_H
#నిర్వచించు _TGMATH_H

#అన్తర్భావ <math.h>

#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచించు __tgmath_real(x, F) \
  _Generic ((x), దశాంశం: F##f, దీర్ఘ ద్విగుణ: F##l, అప్రమేయ: F)(x)
#నిర్వచించు __tgmath_real_2_1(x, y, F) \
  _Generic ((x), దశాంశం: F##f, దీర్ఘ ద్విగుణ: F##l, అప్రమేయ: F)(x, y)
#నిర్వచించు __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), దశాంశం: F##f, దీర్ఘ ద్విగుణ: F##l, అప్రమేయ: F)(x, y)
#నిర్వచించు __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), దశాంశం: F##f, దీర్ఘ ద్విగుణ: F##l, అప్రమేయ: F)(x, y, z)
#నిర్వచించు __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), దశాంశం: F##f, దీర్ఘ ద్విగుణ: F##l, అప్రమేయ: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#నిర్వచించు acos(z)          __tgmath_real(z, acos)
#నిర్వచించు asin(z)          __tgmath_real(z, asin)
#నిర్వచించు atan(z)          __tgmath_real(z, atan)
#నిర్వచించు acosh(z)         __tgmath_real(z, acosh)
#నిర్వచించు asinh(z)         __tgmath_real(z, asinh)
#నిర్వచించు atanh(z)         __tgmath_real(z, atanh)
#నిర్వచించు కోజ్యా(z)           __tgmath_real(z, కోజ్యా)
#నిర్వచించు జ్యా(z)           __tgmath_real(z, జ్యా)
#నిర్వచించు tan(z)           __tgmath_real(z, tan)
#నిర్వచించు cosh(z)          __tgmath_real(z, cosh)
#నిర్వచించు sinh(z)          __tgmath_real(z, sinh)
#నిర్వచించు tanh(z)          __tgmath_real(z, tanh)
#నిర్వచించు ఘాతాంకం(z)           __tgmath_real(z, ఘాతాంకం)
#నిర్వచించు సంవర్గమానం(z)           __tgmath_real(z, సంవర్గమానం)
#నిర్వచించు ఘాతం(z1,z2)       __tgmath_real_2(z1, z2, ఘాతం)
#నిర్వచించు వర్గమూలం(z)          __tgmath_real(z, వర్గమూలం)
#నిర్వచించు fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#నిర్వచించు atan2(x,y)       __tgmath_real_2(x, y, atan2)
#నిర్వచించు cbrt(x)          __tgmath_real(x, cbrt)
#నిర్వచించు ceil(x)          __tgmath_real(x, ceil)
#నిర్వచించు copysign(x,y)    __tgmath_real_2(x, y, copysign)
#నిర్వచించు erf(x)           __tgmath_real(x, erf)
#నిర్వచించు erfc(x)          __tgmath_real(x, erfc)
#నిర్వచించు exp2(x)          __tgmath_real(x, exp2)
#నిర్వచించు expm1(x)         __tgmath_real(x, expm1)
#నిర్వచించు fdim(x,y)        __tgmath_real_2(x, y, fdim)
#నిర్వచించు floor(x)         __tgmath_real(x, floor)
#నిర్వచించు fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#నిర్వచించు fmax(x,y)        __tgmath_real_2(x, y, fmax)
#నిర్వచించు fmin(x,y)        __tgmath_real_2(x, y, fmin)
#నిర్వచించు fmod(x,y)        __tgmath_real_2(x, y, fmod)
#నిర్వచించు frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#నిర్వచించు hypot(x,y)       __tgmath_real_2(x, y, hypot)
#నిర్వచించు ilogb(x)         __tgmath_real(x, ilogb)
#నిర్వచించు ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#నిర్వచించు lgamma(x)        __tgmath_real(x, lgamma)
#నిర్వచించు llrint(x)        __tgmath_real(x, llrint)
#నిర్వచించు llround(x)       __tgmath_real(x, llround)
#నిర్వచించు log10(x)         __tgmath_real(x, log10)
#నిర్వచించు log1p(x)         __tgmath_real(x, log1p)
#నిర్వచించు log2(x)          __tgmath_real(x, log2)
#నిర్వచించు logb(x)          __tgmath_real(x, logb)
#నిర్వచించు lrint(x)         __tgmath_real(x, lrint)
#నిర్వచించు lround(x)        __tgmath_real(x, lround)
#నిర్వచించు nearbyint(x)     __tgmath_real(x, nearbyint)
#నిర్వచించు nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#నిర్వచించు nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#నిర్వచించు remainder(x,y)   __tgmath_real_2(x, y, remainder)
#నిర్వచించు remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#నిర్వచించు rint(x)          __tgmath_real(x, rint)
#నిర్వచించు విడత(x)         __tgmath_real(x, విడత)
#నిర్వచించు scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#నిర్వచించు scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#నిర్వచించు tgamma(x)        __tgmath_real(x, tgamma)
#నిర్వచించు trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#అయితే_ముగింపు /* __cplusplus */
#అయితే_ముగింపు /* _TGMATH_H */
