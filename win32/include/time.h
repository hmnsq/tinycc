/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#include <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  typedef unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  typedef long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ако _INTEGRAL_MAX_BITS >= 64
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef цео _time64_t __attribute__ ((mode (DI)));
#инако
  typedef __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#инако
  typedef __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  typedef long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned цео size_t __attribute__ ((mode (DI)));
#инако
  typedef unsigned __int64 size_t;
#endif
#инако
  typedef unsigned цео size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef цео ssize_t __attribute__ ((mode (DI)));
#инако
  typedef __int64 ssize_t;
#endif
#инако
  typedef цео ssize_t;
#endif
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#инако
#define NULL ((void *)0)
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
  struct tm {
    цео tm_sec;
    цео tm_min;
    цео tm_hour;
    цео tm_mday;
    цео tm_mon;
    цео tm_year;
    цео tm_wday;
    цео tm_yday;
    цео tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT цео _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT char * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(цео *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *_ReturnValue,char *_Buffer,size_t _SizeInBytes,цео _Index);
  char *__cdecl asctime(const struct tm *_Tm);
  _CRTIMP char *__cdecl _ctime32(const __time32_t *_Time);
  clock_t __cdecl clock(void);
  _CRTIMP double __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP struct tm *__cdecl _gmtime32(const __time32_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime32(const __time32_t *_Time);
  size_t __cdecl strftime(char *_Buf,size_t _SizeInBytes,const char *_Format,const struct tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(char *_Buf,size_t _Max_size,const char *_Format,const struct tm *_Tm,_locale_t _Locale);
  _CRTIMP char *__cdecl _strdate(char *_Buffer);
  _CRTIMP char *__cdecl _strtime(char *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(struct tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(struct tm *_Tm);
#ако defined (_POSIX_) || defined(__GNUC__)
  void __cdecl tzset(void);
#инако
  _CRTIMP void __cdecl _tzset(void);
#endif

#ако _INTEGRAL_MAX_BITS >= 64
  double __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP char *__cdecl _ctime64(const __time64_t *_Time);
  _CRTIMP struct tm *__cdecl _gmtime64(const __time64_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime64(const __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(struct tm *_Tm);
  unsigned __cdecl _setsystime(struct tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned цео size_t __attribute__ ((mode (DI)));
#инако
  typedef unsigned __int64 size_t;
#endif
#инако
  typedef unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef цео ssize_t __attribute__ ((mode (DI)));
#инако
  typedef __int64 ssize_t;
#endif
#инако
  typedef long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(const struct tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(const __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t _SizeInWords,const wchar_t *_Format,const struct tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t _SizeInWords,const wchar_t *_Format,const struct tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#ако _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(const __time64_t *_Time);
#endif

#ако !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { врати _wctime32(_Time); }
#инако
__CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { врати _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
double __cdecl difftime(time_t _Time1,time_t _Time2);
char *__cdecl ctime(const time_t *_Time);
struct tm *__cdecl gmtime(const time_t *_Time);
struct tm *__cdecl localtime(const time_t *_Time);
struct tm *__cdecl localtime_r(const time_t *_Time,struct tm *);

time_t __cdecl mktime(struct tm *_Tm);
time_t __cdecl _mkgmtime(struct tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#ако 0
__CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2) { врати _difftime32(_Time1,_Time2); }
__CRT_INLINE char *__cdecl ctime(const time_t *_Time) { врати _ctime32(_Time); }
__CRT_INLINE struct tm *__cdecl gmtime(const time_t *_Time) { врати _gmtime32(_Time); }
__CRT_INLINE struct tm *__cdecl localtime(const time_t *_Time) { врати _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) { врати _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) { врати _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { врати _time32(_Time); }
#endif
#инако
__CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2) { врати _difftime64(_Time1,_Time2); }
__CRT_INLINE char *__cdecl ctime(const time_t *_Time) { врати _ctime64(_Time); }
__CRT_INLINE struct tm *__cdecl gmtime(const time_t *_Time) { врати _gmtime64(_Time); }
__CRT_INLINE struct tm *__cdecl localtime(const time_t *_Time) { врати _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) { врати _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) { врати _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { врати _time64(_Time); }
#endif
#endif

#ако !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT цео daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT char *tzname[2];
  void __cdecl tzset(void);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
struct timeval {
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
struct timezone {
  цео tz_minuteswest;
  цео tz_dsttime;
};

  extern цео __cdecl mingw_gettimeofday (struct timeval *p, struct timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/time_s.h>

/* Adding timespec definition.  */
#include <sys/timeb.h>

#endif /* End _TIME_H_ */

