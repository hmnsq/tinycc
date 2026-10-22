/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#ضمن <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ادفع,_CRT_PACKING)

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  تعريفنوع unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  تعريفنوع long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#إذا _INTEGRAL_MAX_BITS >= 64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _time64_t __attribute__ ((mode (DI)));
#وإلا
  تعريفنوع __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  تعريفنوع long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع unsigned صحيح size_t __attribute__ ((mode (DI)));
#وإلا
  تعريفنوع unsigned __int64 size_t;
#endif
#وإلا
  تعريفنوع unsigned صحيح size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((mode (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#endif
#وإلا
  تعريفنوع صحيح ssize_t;
#endif
#endif

#ifndef عدم
#ifdef __cplusplus
#define عدم 0
#وإلا
#define عدم ((فراغ *)0)
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
  بنية tm {
    صحيح tm_sec;
    صحيح tm_min;
    صحيح tm_hour;
    صحيح tm_mday;
    صحيح tm_mon;
    صحيح tm_year;
    صحيح tm_wday;
    صحيح tm_yday;
    صحيح tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT صحيح _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT حرف * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(صحيح *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_قيمة,حرف *_Buffer,size_t _SizeInBytes,صحيح _Index);
  حرف *__cdecl asctime(ثابت بنية tm *_Tm);
  _CRTIMP حرف *__cdecl _ctime32(ثابت __time32_t *_Time);
  clock_t __cdecl clock(فراغ);
  _CRTIMP مزدوج __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP بنية tm *__cdecl _gmtime32(ثابت __time32_t *_Time);
  _CRTIMP بنية tm *__cdecl _localtime32(ثابت __time32_t *_Time);
  size_t __cdecl strftime(حرف *_Buf,size_t _SizeInBytes,ثابت حرف *_Format,ثابت بنية tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(حرف *_Buf,size_t _Max_size,ثابت حرف *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _strdate(حرف *_Buffer);
  _CRTIMP حرف *__cdecl _strtime(حرف *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(بنية tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(بنية tm *_Tm);
#إذا defined (_POSIX_) || defined(__GNUC__)
  فراغ __cdecl tzset(فراغ);
#وإلا
  _CRTIMP فراغ __cdecl _tzset(فراغ);
#endif

#إذا _INTEGRAL_MAX_BITS >= 64
  مزدوج __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP حرف *__cdecl _ctime64(ثابت __time64_t *_Time);
  _CRTIMP بنية tm *__cdecl _gmtime64(ثابت __time64_t *_Time);
  _CRTIMP بنية tm *__cdecl _localtime64(ثابت __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(بنية tm *_Tm);
  unsigned __cdecl _setsystime(بنية tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع unsigned صحيح size_t __attribute__ ((mode (DI)));
#وإلا
  تعريفنوع unsigned __int64 size_t;
#endif
#وإلا
  تعريفنوع unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((mode (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#endif
#وإلا
  تعريفنوع long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_كلمات,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_كلمات,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#إذا _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *_Time);
#endif

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *_Time) { أرجع _wctime32(_Time); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *_Time) { أرجع _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
مزدوج __cdecl difftime(time_t _Time1,time_t _Time2);
حرف *__cdecl ctime(ثابت time_t *_Time);
بنية tm *__cdecl gmtime(ثابت time_t *_Time);
بنية tm *__cdecl localtime(ثابت time_t *_Time);
بنية tm *__cdecl localtime_r(ثابت time_t *_Time,بنية tm *);

time_t __cdecl mktime(بنية tm *_Tm);
time_t __cdecl _mkgmtime(بنية tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#إذا 0
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime32(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *_Time) { أرجع _ctime32(_Time); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *_Time) { أرجع _gmtime32(_Time); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *_Time) { أرجع _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { أرجع _time32(_Time); }
#endif
#وإلا
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime64(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *_Time) { أرجع _ctime64(_Time); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *_Time) { أرجع _gmtime64(_Time); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *_Time) { أرجع _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { أرجع _time64(_Time); }
#endif
#endif

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT صحيح daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT حرف *tzname[2];
  فراغ __cdecl tzset(فراغ);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
بنية timeval {
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
بنية timezone {
  صحيح tz_minuteswest;
  صحيح tz_dsttime;
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(اسحب)

#ضمن <sec_api/time_s.h>

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>

#endif /* End _TIME_H_ */

