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
বাহ্যিক "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  প্রকারলেখ unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  প্রকারলেখ long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#যদি _INTEGRAL_MAX_BITS >= 64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারলেখ পূর্ণসংখ্যা _time64_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারলেখ __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  প্রকারলেখ __time32_t time_t;
#অন্যথা
  প্রকারলেখ __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  প্রকারলেখ long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef আকার_t
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারলেখ unsigned পূর্ণসংখ্যা আকার_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারলেখ unsigned __int64 আকার_t;
#endif
#অন্যথা
  প্রকারলেখ unsigned পূর্ণসংখ্যা আকার_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারলেখ পূর্ণসংখ্যা ssize_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারলেখ __int64 ssize_t;
#endif
#অন্যথা
  প্রকারলেখ পূর্ণসংখ্যা ssize_t;
#endif
#endif

#ifndef ফাঁকা
#ifdef __cplusplus
#define ফাঁকা 0
#অন্যথা
#define ফাঁকা ((শূন্য *)0)
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
  কাঠামো tm {
    পূর্ণসংখ্যা tm_sec;
    পূর্ণসংখ্যা tm_min;
    পূর্ণসংখ্যা tm_hour;
    পূর্ণসংখ্যা tm_mday;
    পূর্ণসংখ্যা tm_mon;
    পূর্ণসংখ্যা tm_year;
    পূর্ণসংখ্যা tm_wday;
    পূর্ণসংখ্যা tm_yday;
    পূর্ণসংখ্যা tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT পূর্ণসংখ্যা _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT অক্ষর * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(পূর্ণসংখ্যা *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(আকার_t *Return_মান,অক্ষর *বাফার_2,আকার_t আকার_In_Bytes,পূর্ণসংখ্যা সূচক_2);
  অক্ষর *__cdecl asctime(ধ্রুবক কাঠামো tm *_Tm);
  _CRTIMP অক্ষর *__cdecl _ctime32(ধ্রুবক __time32_t *_Time);
  clock_t __cdecl clock(শূন্য);
  _CRTIMP দ্বিগুণ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP কাঠামো tm *__cdecl _gmtime32(ধ্রুবক __time32_t *_Time);
  _CRTIMP কাঠামো tm *__cdecl _localtime32(ধ্রুবক __time32_t *_Time);
  আকার_t __cdecl strftime(অক্ষর *_Buf,আকার_t আকার_In_Bytes,ধ্রুবক অক্ষর *_Format,ধ্রুবক কাঠামো tm *_Tm);
  _CRTIMP আকার_t __cdecl _strftime_l(অক্ষর *_Buf,আকার_t Max_আকার,ধ্রুবক অক্ষর *_Format,ধ্রুবক কাঠামো tm *_Tm,_locale_t _Locale);
  _CRTIMP অক্ষর *__cdecl _strdate(অক্ষর *বাফার_2);
  _CRTIMP অক্ষর *__cdecl _strtime(অক্ষর *বাফার_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(কাঠামো tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(কাঠামো tm *_Tm);
#যদি defined (_POSIX_) || defined(__GNUC__)
  শূন্য __cdecl tzset(শূন্য);
#অন্যথা
  _CRTIMP শূন্য __cdecl _tzset(শূন্য);
#endif

#যদি _INTEGRAL_MAX_BITS >= 64
  দ্বিগুণ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP অক্ষর *__cdecl _ctime64(ধ্রুবক __time64_t *_Time);
  _CRTIMP কাঠামো tm *__cdecl _gmtime64(ধ্রুবক __time64_t *_Time);
  _CRTIMP কাঠামো tm *__cdecl _localtime64(ধ্রুবক __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(কাঠামো tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(কাঠামো tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(কাঠামো tm *_Tm);
  unsigned __cdecl _setsystime(কাঠামো tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারলেখ unsigned পূর্ণসংখ্যা আকার_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারলেখ unsigned __int64 আকার_t;
#endif
#অন্যথা
  প্রকারলেখ unsigned long আকার_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারলেখ পূর্ণসংখ্যা ssize_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারলেখ __int64 ssize_t;
#endif
#অন্যথা
  প্রকারলেখ long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ধ্রুবক কাঠামো tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ধ্রুবক __time32_t *_Time);
  আকার_t __cdecl wcsftime(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,ধ্রুবক কাঠামো tm *_Tm);
  _CRTIMP আকার_t __cdecl _wcsftime_l(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,ধ্রুবক কাঠামো tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *বাফার_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *বাফার_2);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ধ্রুবক __time64_t *_Time);
#endif

#যদি !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুবক time_t *_Time) { ফেরত _wctime32(_Time); }
#অন্যথা
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুবক time_t *_Time) { ফেরত _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
দ্বিগুণ __cdecl difftime(time_t _Time1,time_t _Time2);
অক্ষর *__cdecl ctime(ধ্রুবক time_t *_Time);
কাঠামো tm *__cdecl gmtime(ধ্রুবক time_t *_Time);
কাঠামো tm *__cdecl localtime(ধ্রুবক time_t *_Time);
কাঠামো tm *__cdecl localtime_r(ধ্রুবক time_t *_Time,কাঠামো tm *);

time_t __cdecl mktime(কাঠামো tm *_Tm);
time_t __cdecl _mkgmtime(কাঠামো tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#যদি 0
__CRT_INLINE দ্বিগুণ __cdecl difftime(time_t _Time1,time_t _Time2) { ফেরত _difftime32(_Time1,_Time2); }
__CRT_INLINE অক্ষর *__cdecl ctime(ধ্রুবক time_t *_Time) { ফেরত _ctime32(_Time); }
__CRT_INLINE কাঠামো tm *__cdecl gmtime(ধ্রুবক time_t *_Time) { ফেরত _gmtime32(_Time); }
__CRT_INLINE কাঠামো tm *__cdecl localtime(ধ্রুবক time_t *_Time) { ফেরত _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(কাঠামো tm *_Tm) { ফেরত _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(কাঠামো tm *_Tm) { ফেরত _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { ফেরত _time32(_Time); }
#endif
#অন্যথা
__CRT_INLINE দ্বিগুণ __cdecl difftime(time_t _Time1,time_t _Time2) { ফেরত _difftime64(_Time1,_Time2); }
__CRT_INLINE অক্ষর *__cdecl ctime(ধ্রুবক time_t *_Time) { ফেরত _ctime64(_Time); }
__CRT_INLINE কাঠামো tm *__cdecl gmtime(ধ্রুবক time_t *_Time) { ফেরত _gmtime64(_Time); }
__CRT_INLINE কাঠামো tm *__cdecl localtime(ধ্রুবক time_t *_Time) { ফেরত _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(কাঠামো tm *_Tm) { ফেরত _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(কাঠামো tm *_Tm) { ফেরত _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { ফেরত _time64(_Time); }
#endif
#endif

#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT পূর্ণসংখ্যা daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT অক্ষর *tzname[2];
  শূন্য __cdecl tzset(শূন্য);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
কাঠামো timeval {
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
কাঠামো timezone {
  পূর্ণসংখ্যা tz_minuteswest;
  পূর্ণসংখ্যা tz_dsttime;
};

  বাহ্যিক পূর্ণসংখ্যা __cdecl mingw_gettimeofday (কাঠামো timeval *p, কাঠামো timezone *z);
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

