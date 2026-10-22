/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#شامل <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  تعریفنوع unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  تعریفنوع long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#اگر _INTEGRAL_MAX_BITS >= 64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع صحیح _time64_t __attribute__ ((mode (DI)));
#وگرنه
  تعریفنوع __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  تعریفنوع __time32_t time_t;
#وگرنه
  تعریفنوع __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  تعریفنوع long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع unsigned صحیح size_t __attribute__ ((mode (DI)));
#وگرنه
  تعریفنوع unsigned __int64 size_t;
#endif
#وگرنه
  تعریفنوع unsigned صحیح size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع صحیح ssize_t __attribute__ ((mode (DI)));
#وگرنه
  تعریفنوع __int64 ssize_t;
#endif
#وگرنه
  تعریفنوع صحیح ssize_t;
#endif
#endif

#ifndef پوچ
#ifdef __cplusplus
#define پوچ 0
#وگرنه
#define پوچ ((تهی *)0)
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
  ساختار tm {
    صحیح tm_sec;
    صحیح tm_min;
    صحیح tm_hour;
    صحیح tm_mday;
    صحیح tm_mon;
    صحیح tm_year;
    صحیح tm_wday;
    صحیح tm_yday;
    صحیح tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT صحیح _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT نویسه * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(صحیح *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_مقدار,نویسه *_Buffer,size_t _SizeInBytes,صحیح _Index);
  نویسه *__cdecl asctime(ثابت ساختار tm *_Tm);
  _CRTIMP نویسه *__cdecl _ctime32(ثابت __time32_t *_Time);
  clock_t __cdecl clock(تهی);
  _CRTIMP دوگانه __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP ساختار tm *__cdecl _gmtime32(ثابت __time32_t *_Time);
  _CRTIMP ساختار tm *__cdecl _localtime32(ثابت __time32_t *_Time);
  size_t __cdecl strftime(نویسه *_Buf,size_t _SizeInBytes,ثابت نویسه *_Format,ثابت ساختار tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(نویسه *_Buf,size_t _Max_size,ثابت نویسه *_Format,ثابت ساختار tm *_Tm,_locale_t _Locale);
  _CRTIMP نویسه *__cdecl _strdate(نویسه *_Buffer);
  _CRTIMP نویسه *__cdecl _strtime(نویسه *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(ساختار tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(ساختار tm *_Tm);
#اگر defined (_POSIX_) || defined(__GNUC__)
  تهی __cdecl tzset(تهی);
#وگرنه
  _CRTIMP تهی __cdecl _tzset(تهی);
#endif

#اگر _INTEGRAL_MAX_BITS >= 64
  دوگانه __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP نویسه *__cdecl _ctime64(ثابت __time64_t *_Time);
  _CRTIMP ساختار tm *__cdecl _gmtime64(ثابت __time64_t *_Time);
  _CRTIMP ساختار tm *__cdecl _localtime64(ثابت __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(ساختار tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(ساختار tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(ساختار tm *_Tm);
  unsigned __cdecl _setsystime(ساختار tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع unsigned صحیح size_t __attribute__ ((mode (DI)));
#وگرنه
  تعریفنوع unsigned __int64 size_t;
#endif
#وگرنه
  تعریفنوع unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع صحیح ssize_t __attribute__ ((mode (DI)));
#وگرنه
  تعریفنوع __int64 ssize_t;
#endif
#وگرنه
  تعریفنوع long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ثابت ساختار tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_واژگان,ثابت wchar_t *_Format,ثابت ساختار tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_واژگان,ثابت wchar_t *_Format,ثابت ساختار tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *_Time);
#endif

#اگر !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *_Time) { بازگشت _wctime32(_Time); }
#وگرنه
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *_Time) { بازگشت _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
دوگانه __cdecl difftime(time_t _Time1,time_t _Time2);
نویسه *__cdecl ctime(ثابت time_t *_Time);
ساختار tm *__cdecl gmtime(ثابت time_t *_Time);
ساختار tm *__cdecl localtime(ثابت time_t *_Time);
ساختار tm *__cdecl localtime_r(ثابت time_t *_Time,ساختار tm *);

time_t __cdecl mktime(ساختار tm *_Tm);
time_t __cdecl _mkgmtime(ساختار tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#اگر 0
__CRT_INLINE دوگانه __cdecl difftime(time_t _Time1,time_t _Time2) { بازگشت _difftime32(_Time1,_Time2); }
__CRT_INLINE نویسه *__cdecl ctime(ثابت time_t *_Time) { بازگشت _ctime32(_Time); }
__CRT_INLINE ساختار tm *__cdecl gmtime(ثابت time_t *_Time) { بازگشت _gmtime32(_Time); }
__CRT_INLINE ساختار tm *__cdecl localtime(ثابت time_t *_Time) { بازگشت _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(ساختار tm *_Tm) { بازگشت _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ساختار tm *_Tm) { بازگشت _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { بازگشت _time32(_Time); }
#endif
#وگرنه
__CRT_INLINE دوگانه __cdecl difftime(time_t _Time1,time_t _Time2) { بازگشت _difftime64(_Time1,_Time2); }
__CRT_INLINE نویسه *__cdecl ctime(ثابت time_t *_Time) { بازگشت _ctime64(_Time); }
__CRT_INLINE ساختار tm *__cdecl gmtime(ثابت time_t *_Time) { بازگشت _gmtime64(_Time); }
__CRT_INLINE ساختار tm *__cdecl localtime(ثابت time_t *_Time) { بازگشت _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(ساختار tm *_Tm) { بازگشت _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ساختار tm *_Tm) { بازگشت _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { بازگشت _time64(_Time); }
#endif
#endif

#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT صحیح daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT نویسه *tzname[2];
  تهی __cdecl tzset(تهی);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
ساختار timeval {
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
ساختار timezone {
  صحیح tz_minuteswest;
  صحیح tz_dsttime;
};

  بیرونی صحیح __cdecl mingw_gettimeofday (ساختار timeval *p, ساختار timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)

#شامل <sec_api/time_s.h>

/* Adding timespec definition.  */
#شامل <sys/timeb.h>

#endif /* End _TIME_H_ */

