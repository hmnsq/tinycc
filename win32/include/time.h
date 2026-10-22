/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_H

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਗਲਤੀ Only Win32 ਨਿਸ਼ਾਨਾ is supported!
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRTIMP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRTIMP __declspec(dllimport)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCHAR_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCHAR_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ wchar_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME32_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME32_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ __time32_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME64_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME64_T_DEFINED
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ _time64_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 __time64_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time32_t time_t;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time64_t time_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CLOCK_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CLOCK_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ clock_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ਮਾਪ_t
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਮਾਪ_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮਾਪ_t;
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਮਾਪ_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SSIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SSIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ssize_t
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ ssize_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 ssize_t;
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ ssize_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਨਿਰਾ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ 0
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ ((ਖਾਲੀ *)0)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _localtime32 localtime
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _difftime32     difftime
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ctime32        ctime
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _gmtime32       gmtime
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _mktime32       mktime
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _time32 ਸਮਾਂ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TM_DEFINED
  ਬਣਤਰ tm {
    ਪੂਰਨ tm_sec;
    ਪੂਰਨ tm_min;
    ਪੂਰਨ tm_hour;
    ਪੂਰਨ tm_mday;
    ਪੂਰਨ tm_mon;
    ਪੂਰਨ tm_year;
    ਪੂਰਨ tm_wday;
    ਪੂਰਨ tm_yday;
    ਪੂਰਨ tm_isdst;
  };
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLOCKS_PER_SEC 1000

  __MINGW_IMPORT ਪੂਰਨ _daylight;
  __MINGW_IMPORT ਲੰਮਾ _dstbias;
  __MINGW_IMPORT ਲੰਮਾ _timezone;
  __MINGW_IMPORT ਅੱਖਰ * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(ਪੂਰਨ *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(ਲੰਮਾ *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(ਲੰਮਾ *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(ਮਾਪ_t *Return_ਮੁੱਲ,ਅੱਖਰ *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਪੂਰਨ ਸੂਚਕਾਂਕ_2);
  ਅੱਖਰ *__cdecl asctime(ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP ਅੱਖਰ *__cdecl _ctime32(ਅਚਲ __time32_t *ਸਮਾਂ_2);
  clock_t __cdecl clock(ਖਾਲੀ);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP ਬਣਤਰ tm *__cdecl _gmtime32(ਅਚਲ __time32_t *ਸਮਾਂ_2);
  _CRTIMP ਬਣਤਰ tm *__cdecl _localtime32(ਅਚਲ __time32_t *ਸਮਾਂ_2);
  ਮਾਪ_t __cdecl strftime(ਅੱਖਰ *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਅੱਖਰ *_Format,ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP ਮਾਪ_t __cdecl _strftime_l(ਅੱਖਰ *_Buf,ਮਾਪ_t Max_ਮਾਪ,ਅਚਲ ਅੱਖਰ *_Format,ਅਚਲ ਬਣਤਰ tm *_Tm,_locale_t _Locale);
  _CRTIMP ਅੱਖਰ *__cdecl _strdate(ਅੱਖਰ *ਬਫਰ_2);
  _CRTIMP ਅੱਖਰ *__cdecl _strtime(ਅੱਖਰ *ਬਫਰ_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *ਸਮਾਂ_2);
  _CRTIMP __time32_t __cdecl _mktime32(ਬਣਤਰ tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(ਬਣਤਰ tm *_Tm);
#ਜੇ defined (_POSIX_) || defined(__GNUC__)
  ਖਾਲੀ __cdecl tzset(ਖਾਲੀ);
#ਨਹੀਂਤਾਂ
  _CRTIMP ਖਾਲੀ __cdecl _tzset(ਖਾਲੀ);
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਦੁੱਗਣਾ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP ਅੱਖਰ *__cdecl _ctime64(ਅਚਲ __time64_t *ਸਮਾਂ_2);
  _CRTIMP ਬਣਤਰ tm *__cdecl _gmtime64(ਅਚਲ __time64_t *ਸਮਾਂ_2);
  _CRTIMP ਬਣਤਰ tm *__cdecl _localtime64(ਅਚਲ __time64_t *ਸਮਾਂ_2);
  _CRTIMP __time64_t __cdecl _mktime64(ਬਣਤਰ tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(ਬਣਤਰ tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ
  ਬਿਨਾਨਿਸ਼ਾਨੀ __cdecl _getsystime(ਬਣਤਰ tm *_Tm);
  ਬਿਨਾਨਿਸ਼ਾਨੀ __cdecl _setsystime(ਬਣਤਰ tm *_Tm,ਬਿਨਾਨਿਸ਼ਾਨੀ _MilliSec);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SIZE_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਮਾਪ_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮਾਪ_t;
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SSIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SSIZE_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ ssize_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 ssize_t;
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ssize_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ਅਚਲ __time32_t *ਸਮਾਂ_2);
  ਮਾਪ_t __cdecl wcsftime(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP ਮਾਪ_t __cdecl _wcsftime_l(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,ਅਚਲ ਬਣਤਰ tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *ਬਫਰ_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *ਬਫਰ_2);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ਅਚਲ __time64_t *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ

#ਜੇ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WTIME_INL
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE wchar_t *__cdecl _wctime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime32(ਸਮਾਂ_2); }
#ਨਹੀਂਤਾਂ
__CRT_INLINE wchar_t *__cdecl _wctime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime64(ਸਮਾਂ_2); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WTIME_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
ਦੁੱਗਣਾ __cdecl difftime(time_t _Time1,time_t _Time2);
ਅੱਖਰ *__cdecl ctime(ਅਚਲ time_t *ਸਮਾਂ_2);
ਬਣਤਰ tm *__cdecl gmtime(ਅਚਲ time_t *ਸਮਾਂ_2);
ਬਣਤਰ tm *__cdecl localtime(ਅਚਲ time_t *ਸਮਾਂ_2);
ਬਣਤਰ tm *__cdecl localtime_r(ਅਚਲ time_t *ਸਮਾਂ_2,ਬਣਤਰ tm *);

time_t __cdecl mktime(ਬਣਤਰ tm *_Tm);
time_t __cdecl _mkgmtime(ਬਣਤਰ tm *_Tm);
time_t __cdecl ਸਮਾਂ(time_t *ਸਮਾਂ_2);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ 0
__CRT_INLINE ਦੁੱਗਣਾ __cdecl difftime(time_t _Time1,time_t _Time2) { ਵਾਪਸ _difftime32(_Time1,_Time2); }
__CRT_INLINE ਅੱਖਰ *__cdecl ctime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _ctime32(ਸਮਾਂ_2); }
__CRT_INLINE ਬਣਤਰ tm *__cdecl gmtime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _gmtime32(ਸਮਾਂ_2); }
__CRT_INLINE ਬਣਤਰ tm *__cdecl localtime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _localtime32(ਸਮਾਂ_2); }
__CRT_INLINE time_t __cdecl mktime(ਬਣਤਰ tm *_Tm) { ਵਾਪਸ _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ਬਣਤਰ tm *_Tm) { ਵਾਪਸ _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl ਸਮਾਂ(time_t *ਸਮਾਂ_2) { ਵਾਪਸ _time32(ਸਮਾਂ_2); }
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
__CRT_INLINE ਦੁੱਗਣਾ __cdecl difftime(time_t _Time1,time_t _Time2) { ਵਾਪਸ _difftime64(_Time1,_Time2); }
__CRT_INLINE ਅੱਖਰ *__cdecl ctime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _ctime64(ਸਮਾਂ_2); }
__CRT_INLINE ਬਣਤਰ tm *__cdecl gmtime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _gmtime64(ਸਮਾਂ_2); }
__CRT_INLINE ਬਣਤਰ tm *__cdecl localtime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _localtime64(ਸਮਾਂ_2); }
__CRT_INLINE time_t __cdecl mktime(ਬਣਤਰ tm *_Tm) { ਵਾਪਸ _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ਬਣਤਰ tm *_Tm) { ਵਾਪਸ _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl ਸਮਾਂ(time_t *ਸਮਾਂ_2) { ਵਾਪਸ _time64(ਸਮਾਂ_2); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT ਪੂਰਨ daylight;
  __MINGW_IMPORT ਲੰਮਾ dstbias;
  __MINGW_IMPORT ਲੰਮਾ timezone;
  __MINGW_IMPORT ਅੱਖਰ *tzname[2];
  ਖਾਲੀ __cdecl tzset(ਖਾਲੀ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEVAL_DEFINED /* also in winsock[2].h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEVAL_DEFINED
ਬਣਤਰ timeval {
  ਲੰਮਾ tv_sec;
  ਲੰਮਾ tv_usec;
};
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#ਜੇ_ਅੰਤ /* _TIMEVAL_DEFINED */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRICT_ANSI__
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEZONE_DEFINED /* also in sys/time.h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEZONE_DEFINED
ਬਣਤਰ timezone {
  ਪੂਰਨ tz_minuteswest;
  ਪੂਰਨ tz_dsttime;
};

  ਬਾਹਰੀ ਪੂਰਨ __cdecl mingw_gettimeofday (ਬਣਤਰ timeval *p, ਬਣਤਰ timezone *z);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ /* __STRICT_ANSI__ */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਅਨ੍ਤਰ੍ਭਾਵ <sec_api/time_s.h>

/* Adding timespec definition.  */
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/timeb.h>

#ਜੇ_ਅੰਤ /* End _TIME_H_ */

