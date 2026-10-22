/*
 * ISO C Standard:  7.22  Type-generic math <tgmath.h>
 */

#यदि_अपरिभाषितम् _TGMATH_H
#परिभाषय _TGMATH_H

#अन्तर्भाव <math.h>

#यदि_अपरिभाषितम् __cplusplus
#परिभाषय __tgmath_real(x, F) \
  _Generic ((x), भिन्न: F##f, दीर्घ द्विगुण: F##l, स्वभाव: F)(x)
#परिभाषय __tgmath_real_2_1(x, y, F) \
  _Generic ((x), भिन्न: F##f, दीर्घ द्विगुण: F##l, स्वभाव: F)(x, y)
#परिभाषय __tgmath_real_2(x, y, F) \
  _Generic ((x)+(y), भिन्न: F##f, दीर्घ द्विगुण: F##l, स्वभाव: F)(x, y)
#परिभाषय __tgmath_real_3_2(x, y, z, F) \
  _Generic ((x)+(y), भिन्न: F##f, दीर्घ द्विगुण: F##l, स्वभाव: F)(x, y, z)
#परिभाषय __tgmath_real_3(x, y, z, F) \
  _Generic ((x)+(y)+(z), भिन्न: F##f, दीर्घ द्विगुण: F##l, स्वभाव: F)(x, y, z)

/* Functions defined in both <math.h> and <complex.h> (7.22p4) */
#परिभाषय acos(z)          __tgmath_real(z, acos)
#परिभाषय asin(z)          __tgmath_real(z, asin)
#परिभाषय atan(z)          __tgmath_real(z, atan)
#परिभाषय acosh(z)         __tgmath_real(z, acosh)
#परिभाषय asinh(z)         __tgmath_real(z, asinh)
#परिभाषय atanh(z)         __tgmath_real(z, atanh)
#परिभाषय कोटिज्या(z)           __tgmath_real(z, कोटिज्या)
#परिभाषय ज्या(z)           __tgmath_real(z, ज्या)
#परिभाषय tan(z)           __tgmath_real(z, tan)
#परिभाषय cosh(z)          __tgmath_real(z, cosh)
#परिभाषय sinh(z)          __tgmath_real(z, sinh)
#परिभाषय tanh(z)          __tgmath_real(z, tanh)
#परिभाषय घातांकः(z)           __tgmath_real(z, घातांकः)
#परिभाषय लघुगणकः(z)           __tgmath_real(z, लघुगणकः)
#परिभाषय घातः(z1,z2)       __tgmath_real_2(z1, z2, घातः)
#परिभाषय वर्गमूलम्(z)          __tgmath_real(z, वर्गमूलम्)
#परिभाषय fabs(z)          __tgmath_real(z, fabs)

/* Functions defined in <math.h> only (7.22p5) */
#परिभाषय atan2(x,y)       __tgmath_real_2(x, y, atan2)
#परिभाषय cbrt(x)          __tgmath_real(x, cbrt)
#परिभाषय ceil(x)          __tgmath_real(x, ceil)
#परिभाषय copysign(x,y)    __tgmath_real_2(x, y, copysign)
#परिभाषय erf(x)           __tgmath_real(x, erf)
#परिभाषय erfc(x)          __tgmath_real(x, erfc)
#परिभाषय exp2(x)          __tgmath_real(x, exp2)
#परिभाषय expm1(x)         __tgmath_real(x, expm1)
#परिभाषय fdim(x,y)        __tgmath_real_2(x, y, fdim)
#परिभाषय floor(x)         __tgmath_real(x, floor)
#परिभाषय fma(x,y,z)       __tgmath_real_3(x, y, z, fma)
#परिभाषय fmax(x,y)        __tgmath_real_2(x, y, fmax)
#परिभाषय fmin(x,y)        __tgmath_real_2(x, y, fmin)
#परिभाषय fmod(x,y)        __tgmath_real_2(x, y, fmod)
#परिभाषय frexp(x,y)       __tgmath_real_2_1(x, y, frexp)
#परिभाषय hypot(x,y)       __tgmath_real_2(x, y, hypot)
#परिभाषय ilogb(x)         __tgmath_real(x, ilogb)
#परिभाषय ldexp(x,y)       __tgmath_real_2_1(x, y, ldexp)
#परिभाषय lgamma(x)        __tgmath_real(x, lgamma)
#परिभाषय llrint(x)        __tgmath_real(x, llrint)
#परिभाषय llround(x)       __tgmath_real(x, llround)
#परिभाषय log10(x)         __tgmath_real(x, log10)
#परिभाषय log1p(x)         __tgmath_real(x, log1p)
#परिभाषय log2(x)          __tgmath_real(x, log2)
#परिभाषय logb(x)          __tgmath_real(x, logb)
#परिभाषय lrint(x)         __tgmath_real(x, lrint)
#परिभाषय lround(x)        __tgmath_real(x, lround)
#परिभाषय nearbyint(x)     __tgmath_real(x, nearbyint)
#परिभाषय nextafter(x,y)   __tgmath_real_2(x, y, nextafter)
#परिभाषय nexttoward(x,y)  __tgmath_real_2(x, y, nexttoward)
#परिभाषय remainder(x,y)   __tgmath_real_2(x, y, remainder)
#परिभाषय remquo(x,y,z)    __tgmath_real_3_2(x, y, z, remquo)
#परिभाषय rint(x)          __tgmath_real(x, rint)
#परिभाषय आवर्तनम्(x)         __tgmath_real(x, आवर्तनम्)
#परिभाषय scalbln(x,y)     __tgmath_real_2_1(x, y, scalbln)
#परिभाषय scalbn(x,y)      __tgmath_real_2_1(x, y, scalbn)
#परिभाषय tgamma(x)        __tgmath_real(x, tgamma)
#परिभाषय trunc(x)         __tgmath_real(x, trunc)

/* Functions defined in <complex.h> only (7.22p6)
#define carg(z)          __tgmath_cplx_only(z, carg)
#define cimag(z)         __tgmath_cplx_only(z, cimag)
#define conj(z)          __tgmath_cplx_only(z, conj)
#define cproj(z)         __tgmath_cplx_only(z, cproj)
#define creal(z)         __tgmath_cplx_only(z, creal)
*/
#यदि_अन्तः /* __cplusplus */
#यदि_अन्तः /* _TGMATH_H */
