/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEB_H_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEB_H_S

#ਅਨ੍ਤਰ੍ਭਾਵ <sys/timeb.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ftime_s _ftime32_s
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ftime_s _ftime64_s
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl _ftime32_s(ਬਣਤਰ __timeb32 *ਸਮਾਂ_2);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(ਬਣਤਰ __timeb64 *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
