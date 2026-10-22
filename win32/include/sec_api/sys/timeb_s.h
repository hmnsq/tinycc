/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_تعریف_نشده _TIMEB_H_S
#تعریف_کن _TIMEB_H_S

#ضمن <sys/timeb.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده USE_32_بیت_زمان_T
#تعریف_کن _ftime_s _ftime32_s
#وإلا
#تعریف_کن _ftime_s _ftime64_s
#پایان_اگر

  _CRTIMP errno_t __cdecl _ftime32_s(بنية __timeb32 *زمان_2);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(بنية __timeb64 *زمان_2);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
