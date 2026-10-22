/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#यदि_अपरिभाषितम् _TIMEB_H_S
#परिभाषय _TIMEB_H_S

#अन्तर्भाव <sys/timeb.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#परिभाषय _ftime_s _ftime32_s
#अन्यथा
#परिभाषय _ftime_s _ftime64_s
#यदि_अन्तः

  _CRTIMP errno_t __cdecl _ftime32_s(संरचना __timeb32 *_Time);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(संरचना __timeb64 *_Time);
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
