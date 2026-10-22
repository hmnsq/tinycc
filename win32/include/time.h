/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#অন্তর্ভাব <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  প্রকারনির্দেশ unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  প্রকারনির্দেশ long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#যদি _INTEGRAL_MAX_BITS >= 64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ পূর্ণাঙ্ক _time64_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারনির্দেশ __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  প্রকারনির্দেশ __time32_t time_t;
#অন্যথা
  প্রকারনির্দেশ __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  প্রকারনির্দেশ long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক size_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারনির্দেশ unsigned __int64 size_t;
#endif
#অন্যথা
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ পূর্ণাঙ্ক ssize_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারনির্দেশ __int64 ssize_t;
#endif
#অন্যথা
  প্রকারনির্দেশ পূর্ণাঙ্ক ssize_t;
#endif
#endif

#ifndef রিক্ত
#ifdef __cplusplus
#define রিক্ত 0
#অন্যথা
#define রিক্ত ((শূন্য *)0)
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
  সংরচনা tm {
    পূর্ণাঙ্ক tm_sec;
    পূর্ণাঙ্ক tm_min;
    পূর্ণাঙ্ক tm_hour;
    পূর্ণাঙ্ক tm_mday;
    পূর্ণাঙ্ক tm_mon;
    পূর্ণাঙ্ক tm_year;
    পূর্ণাঙ্ক tm_wday;
    পূর্ণাঙ্ক tm_yday;
    পূর্ণাঙ্ক tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT পূর্ণাঙ্ক _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT বর্ণ * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(পূর্ণাঙ্ক *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_মান,বর্ণ *_Buffer,size_t _SizeInBytes,পূর্ণাঙ্ক _Index);
  বর্ণ *__cdecl asctime(ধ্রুব সংরচনা tm *_Tm);
  _CRTIMP বর্ণ *__cdecl _ctime32(ধ্রুব __time32_t *_Time);
  clock_t __cdecl clock(শূন্য);
  _CRTIMP দ্বিগুণ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP সংরচনা tm *__cdecl _gmtime32(ধ্রুব __time32_t *_Time);
  _CRTIMP সংরচনা tm *__cdecl _localtime32(ধ্রুব __time32_t *_Time);
  size_t __cdecl strftime(বর্ণ *_Buf,size_t _SizeInBytes,ধ্রুব বর্ণ *_Format,ধ্রুব সংরচনা tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(বর্ণ *_Buf,size_t _Max_size,ধ্রুব বর্ণ *_Format,ধ্রুব সংরচনা tm *_Tm,_locale_t _Locale);
  _CRTIMP বর্ণ *__cdecl _strdate(বর্ণ *_Buffer);
  _CRTIMP বর্ণ *__cdecl _strtime(বর্ণ *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(সংরচনা tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(সংরচনা tm *_Tm);
#যদি defined (_POSIX_) || defined(__GNUC__)
  শূন্য __cdecl tzset(শূন্য);
#অন্যথা
  _CRTIMP শূন্য __cdecl _tzset(শূন্য);
#endif

#যদি _INTEGRAL_MAX_BITS >= 64
  দ্বিগুণ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP বর্ণ *__cdecl _ctime64(ধ্রুব __time64_t *_Time);
  _CRTIMP সংরচনা tm *__cdecl _gmtime64(ধ্রুব __time64_t *_Time);
  _CRTIMP সংরচনা tm *__cdecl _localtime64(ধ্রুব __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(সংরচনা tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(সংরচনা tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(সংরচনা tm *_Tm);
  unsigned __cdecl _setsystime(সংরচনা tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক size_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারনির্দেশ unsigned __int64 size_t;
#endif
#অন্যথা
  প্রকারনির্দেশ unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ পূর্ণাঙ্ক ssize_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারনির্দেশ __int64 ssize_t;
#endif
#অন্যথা
  প্রকারনির্দেশ long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ধ্রুব সংরচনা tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ধ্রুব __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,ধ্রুব সংরচনা tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,ধ্রুব সংরচনা tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ধ্রুব __time64_t *_Time);
#endif

#যদি !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুব time_t *_Time) { প্রত্যাগম _wctime32(_Time); }
#অন্যথা
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুব time_t *_Time) { প্রত্যাগম _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
দ্বিগুণ __cdecl difftime(time_t _Time1,time_t _Time2);
বর্ণ *__cdecl ctime(ধ্রুব time_t *_Time);
সংরচনা tm *__cdecl gmtime(ধ্রুব time_t *_Time);
সংরচনা tm *__cdecl localtime(ধ্রুব time_t *_Time);
সংরচনা tm *__cdecl localtime_r(ধ্রুব time_t *_Time,সংরচনা tm *);

time_t __cdecl mktime(সংরচনা tm *_Tm);
time_t __cdecl _mkgmtime(সংরচনা tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#যদি 0
__CRT_INLINE দ্বিগুণ __cdecl difftime(time_t _Time1,time_t _Time2) { প্রত্যাগম _difftime32(_Time1,_Time2); }
__CRT_INLINE বর্ণ *__cdecl ctime(ধ্রুব time_t *_Time) { প্রত্যাগম _ctime32(_Time); }
__CRT_INLINE সংরচনা tm *__cdecl gmtime(ধ্রুব time_t *_Time) { প্রত্যাগম _gmtime32(_Time); }
__CRT_INLINE সংরচনা tm *__cdecl localtime(ধ্রুব time_t *_Time) { প্রত্যাগম _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(সংরচনা tm *_Tm) { প্রত্যাগম _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(সংরচনা tm *_Tm) { প্রত্যাগম _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { প্রত্যাগম _time32(_Time); }
#endif
#অন্যথা
__CRT_INLINE দ্বিগুণ __cdecl difftime(time_t _Time1,time_t _Time2) { প্রত্যাগম _difftime64(_Time1,_Time2); }
__CRT_INLINE বর্ণ *__cdecl ctime(ধ্রুব time_t *_Time) { প্রত্যাগম _ctime64(_Time); }
__CRT_INLINE সংরচনা tm *__cdecl gmtime(ধ্রুব time_t *_Time) { প্রত্যাগম _gmtime64(_Time); }
__CRT_INLINE সংরচনা tm *__cdecl localtime(ধ্রুব time_t *_Time) { প্রত্যাগম _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(সংরচনা tm *_Tm) { প্রত্যাগম _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(সংরচনা tm *_Tm) { প্রত্যাগম _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { প্রত্যাগম _time64(_Time); }
#endif
#endif

#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT পূর্ণাঙ্ক daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT বর্ণ *tzname[2];
  শূন্য __cdecl tzset(শূন্য);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
সংরচনা timeval {
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
সংরচনা timezone {
  পূর্ণাঙ্ক tz_minuteswest;
  পূর্ণাঙ্ক tz_dsttime;
};

  বাহ্য পূর্ণাঙ্ক __cdecl mingw_gettimeofday (সংরচনা timeval *p, সংরচনা timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/time_s.h>

/* Adding timespec definition.  */
#অন্তর্ভাব <sys/timeb.h>

#endif /* End _TIME_H_ */

