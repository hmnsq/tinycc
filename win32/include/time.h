/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ _time64_t __attribute__ ((mode (DI)));
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  ಪ್ರಕಾರನಿರ್ದೇಶ __time32_t time_t;
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ size_t __attribute__ ((mode (DI)));
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 size_t;
#endif
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ ssize_t __attribute__ ((mode (DI)));
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 ssize_t;
#endif
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ ssize_t;
#endif
#endif

#ifndef ರಿಕ್ತ
#ifdef __cplusplus
#define ರಿಕ್ತ 0
#ಅನ್ಯಥಾ
#define ರಿಕ್ತ ((ಶೂನ್ಯ *)0)
#endif
#endif

#ifdef _USE_32BIT_TIME_T
#define _localtime32 localtime
#define _difftime32     difftime
#define _ctime32        ctime
#define _gmtime32       gmtime
#define _mktime32       mktime
#define _time32 time
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  ಸಂರಚನಾ tm {
    ಪೂರ್ಣಾಙ್ಕ tm_sec;
    ಪೂರ್ಣಾಙ್ಕ tm_min;
    ಪೂರ್ಣಾಙ್ಕ tm_hour;
    ಪೂರ್ಣಾಙ್ಕ tm_mday;
    ಪೂರ್ಣಾಙ್ಕ tm_mon;
    ಪೂರ್ಣಾಙ್ಕ tm_year;
    ಪೂರ್ಣಾಙ್ಕ tm_wday;
    ಪೂರ್ಣಾಙ್ಕ tm_yday;
    ಪೂರ್ಣಾಙ್ಕ tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT ಪೂರ್ಣಾಙ್ಕ _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT ವರ್ಣ * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(ಪೂರ್ಣಾಙ್ಕ *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_ಮೌಲ್ಯ,ವರ್ಣ *_Buffer,size_t _SizeInBytes,ಪೂರ್ಣಾಙ್ಕ _Index);
  ವರ್ಣ *__cdecl asctime(ಧ್ರುವ ಸಂರಚನಾ tm *_Tm);
  _CRTIMP ವರ್ಣ *__cdecl _ctime32(ಧ್ರುವ __time32_t *_Time);
  clock_t __cdecl clock(ಶೂನ್ಯ);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP ಸಂರಚನಾ tm *__cdecl _gmtime32(ಧ್ರುವ __time32_t *_Time);
  _CRTIMP ಸಂರಚನಾ tm *__cdecl _localtime32(ಧ್ರುವ __time32_t *_Time);
  size_t __cdecl strftime(ವರ್ಣ *_Buf,size_t _SizeInBytes,ಧ್ರುವ ವರ್ಣ *_Format,ಧ್ರುವ ಸಂರಚನಾ tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(ವರ್ಣ *_Buf,size_t _Max_size,ಧ್ರುವ ವರ್ಣ *_Format,ಧ್ರುವ ಸಂರಚನಾ tm *_Tm,_locale_t _Locale);
  _CRTIMP ವರ್ಣ *__cdecl _strdate(ವರ್ಣ *_Buffer);
  _CRTIMP ವರ್ಣ *__cdecl _strtime(ವರ್ಣ *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(ಸಂರಚನಾ tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(ಸಂರಚನಾ tm *_Tm);
#ಯದಿ defined (_POSIX_) || defined(__GNUC__)
  ಶೂನ್ಯ __cdecl tzset(ಶೂನ್ಯ);
#ಅನ್ಯಥಾ
  _CRTIMP ಶೂನ್ಯ __cdecl _tzset(ಶೂನ್ಯ);
#endif

#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  ದ್ವಿಗುಣ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP ವರ್ಣ *__cdecl _ctime64(ಧ್ರುವ __time64_t *_Time);
  _CRTIMP ಸಂರಚನಾ tm *__cdecl _gmtime64(ಧ್ರುವ __time64_t *_Time);
  _CRTIMP ಸಂರಚನಾ tm *__cdecl _localtime64(ಧ್ರುವ __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(ಸಂರಚನಾ tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(ಸಂರಚನಾ tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(ಸಂರಚನಾ tm *_Tm);
  unsigned __cdecl _setsystime(ಸಂರಚನಾ tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ size_t __attribute__ ((mode (DI)));
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 size_t;
#endif
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ ssize_t __attribute__ ((mode (DI)));
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 ssize_t;
#endif
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ಧ್ರುವ ಸಂರಚನಾ tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ಧ್ರುವ __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,ಧ್ರುವ ಸಂರಚನಾ tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,ಧ್ರುವ ಸಂರಚನಾ tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ಧ್ರುವ __time64_t *_Time);
#endif

#ಯದಿ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _wctime32(_Time); }
#ಅನ್ಯಥಾ
__CRT_INLINE wchar_t *__cdecl _wctime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
ದ್ವಿಗುಣ __cdecl difftime(time_t _Time1,time_t _Time2);
ವರ್ಣ *__cdecl ctime(ಧ್ರುವ time_t *_Time);
ಸಂರಚನಾ tm *__cdecl gmtime(ಧ್ರುವ time_t *_Time);
ಸಂರಚನಾ tm *__cdecl localtime(ಧ್ರುವ time_t *_Time);
ಸಂರಚನಾ tm *__cdecl localtime_r(ಧ್ರುವ time_t *_Time,ಸಂರಚನಾ tm *);

time_t __cdecl mktime(ಸಂರಚನಾ tm *_Tm);
time_t __cdecl _mkgmtime(ಸಂರಚನಾ tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#ಯದಿ 0
__CRT_INLINE ದ್ವಿಗುಣ __cdecl difftime(time_t _Time1,time_t _Time2) { ಪ್ರತ್ಯಾಗಮ _difftime32(_Time1,_Time2); }
__CRT_INLINE ವರ್ಣ *__cdecl ctime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _ctime32(_Time); }
__CRT_INLINE ಸಂರಚನಾ tm *__cdecl gmtime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _gmtime32(_Time); }
__CRT_INLINE ಸಂರಚನಾ tm *__cdecl localtime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(ಸಂರಚನಾ tm *_Tm) { ಪ್ರತ್ಯಾಗಮ _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ಸಂರಚನಾ tm *_Tm) { ಪ್ರತ್ಯಾಗಮ _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _time32(_Time); }
#endif
#ಅನ್ಯಥಾ
__CRT_INLINE ದ್ವಿಗುಣ __cdecl difftime(time_t _Time1,time_t _Time2) { ಪ್ರತ್ಯಾಗಮ _difftime64(_Time1,_Time2); }
__CRT_INLINE ವರ್ಣ *__cdecl ctime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _ctime64(_Time); }
__CRT_INLINE ಸಂರಚನಾ tm *__cdecl gmtime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _gmtime64(_Time); }
__CRT_INLINE ಸಂರಚನಾ tm *__cdecl localtime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(ಸಂರಚನಾ tm *_Tm) { ಪ್ರತ್ಯಾಗಮ _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ಸಂರಚನಾ tm *_Tm) { ಪ್ರತ್ಯಾಗಮ _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _time64(_Time); }
#endif
#endif

#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT ಪೂರ್ಣಾಙ್ಕ daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT ವರ್ಣ *tzname[2];
  ಶೂನ್ಯ __cdecl tzset(ಶೂನ್ಯ);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
ಸಂರಚನಾ timeval {
  long tv_sec;
  long tv_usec;
};
#define timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#define timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#endif /* _TIMEVAL_DEFINED */

#ifndef __STRICT_ANSI__
#ifndef _TIMEZONE_DEFINED /* also in sys/time.h */
#define _TIMEZONE_DEFINED
ಸಂರಚನಾ timezone {
  ಪೂರ್ಣಾಙ್ಕ tz_minuteswest;
  ಪೂರ್ಣಾಙ್ಕ tz_dsttime;
};

  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __cdecl mingw_gettimeofday (ಸಂರಚನಾ timeval *p, ಸಂರಚನಾ timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/time_s.h>

/* Adding timespec definition.  */
#ಅನ್ತರ್ಭಾವ <sys/timeb.h>

#endif /* End _TIME_H_ */

