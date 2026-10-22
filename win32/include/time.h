/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_H
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_H

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ದೋಷ Only Win32 ಗುರಿ is supported!
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRTIMP
#ವ್ಯಾಖ್ಯಾನಿಸು _CRTIMP __declspec(dllimport)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCHAR_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCHAR_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ wchar_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME32_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME32_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ __time32_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME64_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME64_T_DEFINED
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ _time64_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 __time64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time32_t time_t;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time64_t time_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CLOCK_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CLOCK_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ clock_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ಗಾತ್ರ_t
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 ಗಾತ್ರ_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SSIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SSIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ssize_t
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ ssize_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 ssize_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ ssize_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಖಾಲಿ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ 0
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ ((ಶೂನ್ಯ *)0)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿಸು _localtime32 localtime
#ವ್ಯಾಖ್ಯಾನಿಸು _difftime32     difftime
#ವ್ಯಾಖ್ಯಾನಿಸು _ctime32        ctime
#ವ್ಯಾಖ್ಯಾನಿಸು _gmtime32       gmtime
#ವ್ಯಾಖ್ಯಾನಿಸು _mktime32       mktime
#ವ್ಯಾಖ್ಯಾನಿಸು _time32 ಸಮಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TM_DEFINED
  ರಚನೆ tm {
    ಪೂರ್ಣಾಂಕ tm_sec;
    ಪೂರ್ಣಾಂಕ tm_min;
    ಪೂರ್ಣಾಂಕ tm_hour;
    ಪೂರ್ಣಾಂಕ tm_mday;
    ಪೂರ್ಣಾಂಕ tm_mon;
    ಪೂರ್ಣಾಂಕ tm_year;
    ಪೂರ್ಣಾಂಕ tm_wday;
    ಪೂರ್ಣಾಂಕ tm_yday;
    ಪೂರ್ಣಾಂಕ tm_isdst;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು CLOCKS_PER_SEC 1000

  __MINGW_IMPORT ಪೂರ್ಣಾಂಕ _daylight;
  __MINGW_IMPORT ದೀರ್ಘ _dstbias;
  __MINGW_IMPORT ದೀರ್ಘ _timezone;
  __MINGW_IMPORT ಅಕ್ಷರ * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(ಪೂರ್ಣಾಂಕ *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(ದೀರ್ಘ *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(ದೀರ್ಘ *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(ಗಾತ್ರ_t *Return_ಮೌಲ್ಯ,ಅಕ್ಷರ *ಬಫರ್_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ_2);
  ಅಕ್ಷರ *__cdecl asctime(ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm);
  _CRTIMP ಅಕ್ಷರ *__cdecl _ctime32(ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  clock_t __cdecl clock(ಶೂನ್ಯ);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP ರಚನೆ tm *__cdecl _gmtime32(ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  _CRTIMP ರಚನೆ tm *__cdecl _localtime32(ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  ಗಾತ್ರ_t __cdecl strftime(ಅಕ್ಷರ *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm);
  _CRTIMP ಗಾತ್ರ_t __cdecl _strftime_l(ಅಕ್ಷರ *_Buf,ಗಾತ್ರ_t Max_ಗಾತ್ರ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm,_locale_t _Locale);
  _CRTIMP ಅಕ್ಷರ *__cdecl _strdate(ಅಕ್ಷರ *ಬಫರ್_2);
  _CRTIMP ಅಕ್ಷರ *__cdecl _strtime(ಅಕ್ಷರ *ಬಫರ್_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *ಸಮಯ_2);
  _CRTIMP __time32_t __cdecl _mktime32(ರಚನೆ tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(ರಚನೆ tm *_Tm);
#ಆದರೆ defined (_POSIX_) || defined(__GNUC__)
  ಶೂನ್ಯ __cdecl tzset(ಶೂನ್ಯ);
#ಇಲ್ಲದಿದ್ದರೆ
  _CRTIMP ಶೂನ್ಯ __cdecl _tzset(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ದ್ವಿಗುಣ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP ಅಕ್ಷರ *__cdecl _ctime64(ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
  _CRTIMP ರಚನೆ tm *__cdecl _gmtime64(ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
  _CRTIMP ರಚನೆ tm *__cdecl _localtime64(ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
  _CRTIMP __time64_t __cdecl _mktime64(ರಚನೆ tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(ರಚನೆ tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *ಸಮಯ_2);
#ಆದರೆ_ಅಂತ್ಯ
  ಚಿಹ್ನೆರಹಿತ __cdecl _getsystime(ರಚನೆ tm *_Tm);
  ಚಿಹ್ನೆರಹಿತ __cdecl _setsystime(ರಚನೆ tm *_Tm,ಚಿಹ್ನೆರಹಿತ _MilliSec);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 ಗಾತ್ರ_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SSIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SSIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ ssize_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 ssize_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ssize_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  ಗಾತ್ರ_t __cdecl wcsftime(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm);
  _CRTIMP ಗಾತ್ರ_t __cdecl _wcsftime_l(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *ಬಫರ್_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *ಬಫರ್_2);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_WTIME_INL
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE wchar_t *__cdecl _wctime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _wctime32(ಸಮಯ_2); }
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE wchar_t *__cdecl _wctime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _wctime64(ಸಮಯ_2); }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _WTIME_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
ದ್ವಿಗುಣ __cdecl difftime(time_t _Time1,time_t _Time2);
ಅಕ್ಷರ *__cdecl ctime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2);
ರಚನೆ tm *__cdecl gmtime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2);
ರಚನೆ tm *__cdecl localtime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2);
ರಚನೆ tm *__cdecl localtime_r(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2,ರಚನೆ tm *);

time_t __cdecl mktime(ರಚನೆ tm *_Tm);
time_t __cdecl _mkgmtime(ರಚನೆ tm *_Tm);
time_t __cdecl ಸಮಯ(time_t *ಸಮಯ_2);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ 0
__CRT_INLINE ದ್ವಿಗುಣ __cdecl difftime(time_t _Time1,time_t _Time2) { ಹಿಂತಿರುಗಿ _difftime32(_Time1,_Time2); }
__CRT_INLINE ಅಕ್ಷರ *__cdecl ctime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _ctime32(ಸಮಯ_2); }
__CRT_INLINE ರಚನೆ tm *__cdecl gmtime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _gmtime32(ಸಮಯ_2); }
__CRT_INLINE ರಚನೆ tm *__cdecl localtime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _localtime32(ಸಮಯ_2); }
__CRT_INLINE time_t __cdecl mktime(ರಚನೆ tm *_Tm) { ಹಿಂತಿರುಗಿ _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ರಚನೆ tm *_Tm) { ಹಿಂತಿರುಗಿ _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl ಸಮಯ(time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _time32(ಸಮಯ_2); }
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE ದ್ವಿಗುಣ __cdecl difftime(time_t _Time1,time_t _Time2) { ಹಿಂತಿರುಗಿ _difftime64(_Time1,_Time2); }
__CRT_INLINE ಅಕ್ಷರ *__cdecl ctime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _ctime64(ಸಮಯ_2); }
__CRT_INLINE ರಚನೆ tm *__cdecl gmtime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _gmtime64(ಸಮಯ_2); }
__CRT_INLINE ರಚನೆ tm *__cdecl localtime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _localtime64(ಸಮಯ_2); }
__CRT_INLINE time_t __cdecl mktime(ರಚನೆ tm *_Tm) { ಹಿಂತಿರುಗಿ _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ರಚನೆ tm *_Tm) { ಹಿಂತಿರುಗಿ _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl ಸಮಯ(time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _time64(ಸಮಯ_2); }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
#ವ್ಯಾಖ್ಯಾನಿಸು CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT ಪೂರ್ಣಾಂಕ daylight;
  __MINGW_IMPORT ದೀರ್ಘ dstbias;
  __MINGW_IMPORT ದೀರ್ಘ timezone;
  __MINGW_IMPORT ಅಕ್ಷರ *tzname[2];
  ಶೂನ್ಯ __cdecl tzset(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMEVAL_DEFINED /* also in winsock[2].h */
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMEVAL_DEFINED
ರಚನೆ timeval {
  ದೀರ್ಘ tv_sec;
  ದೀರ್ಘ tv_usec;
};
#ವ್ಯಾಖ್ಯಾನಿಸು timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#ವ್ಯಾಖ್ಯಾನಿಸು timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#ವ್ಯಾಖ್ಯಾನಿಸು timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#ಆದರೆ_ಅಂತ್ಯ /* _TIMEVAL_DEFINED */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRICT_ANSI__
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMEZONE_DEFINED /* also in sys/time.h */
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMEZONE_DEFINED
ರಚನೆ timezone {
  ಪೂರ್ಣಾಂಕ tz_minuteswest;
  ಪೂರ್ಣಾಂಕ tz_dsttime;
};

  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl mingw_gettimeofday (ರಚನೆ timeval *p, ರಚನೆ timezone *z);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ /* __STRICT_ANSI__ */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/time_s.h>

/* Adding timespec definition.  */
#ಅನ್ತರ್ಭಾವ <sys/timeb.h>

#ಆದರೆ_ಅಂತ್ಯ /* End _TIME_H_ */

