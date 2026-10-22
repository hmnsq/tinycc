/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#ଯଦି _INTEGRAL_MAX_BITS >= 64
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା _time64_t __attribute__ ((mode (DI)));
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __time32_t time_t;
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା size_t __attribute__ ((mode (DI)));
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned __int64 size_t;
#endif
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା ssize_t __attribute__ ((mode (DI)));
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 ssize_t;
#endif
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା ssize_t;
#endif
#endif

#ifndef ଖାଲି
#ifdef __cplusplus
#define ଖାଲି 0
#ଅନ୍ୟଥା
#define ଖାଲି ((ଶୂନ୍ୟ *)0)
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
  ସଂରଚନା tm {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_sec;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_min;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_hour;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_mday;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_mon;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_year;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_wday;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_yday;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT ପୂର୍ଣ୍ଣସଂଖ୍ୟା _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT ଅକ୍ଷର * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_ମୂଲ୍ୟ,ଅକ୍ଷର *_Buffer,size_t _SizeInBytes,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Index);
  ଅକ୍ଷର *__cdecl asctime(ଅଚଳ ସଂରଚନା tm *_Tm);
  _CRTIMP ଅକ୍ଷର *__cdecl _ctime32(ଅଚଳ __time32_t *_Time);
  clock_t __cdecl clock(ଶୂନ୍ୟ);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP ସଂରଚନା tm *__cdecl _gmtime32(ଅଚଳ __time32_t *_Time);
  _CRTIMP ସଂରଚନା tm *__cdecl _localtime32(ଅଚଳ __time32_t *_Time);
  size_t __cdecl strftime(ଅକ୍ଷର *_Buf,size_t _SizeInBytes,ଅଚଳ ଅକ୍ଷର *_Format,ଅଚଳ ସଂରଚନା tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(ଅକ୍ଷର *_Buf,size_t _Max_size,ଅଚଳ ଅକ୍ଷର *_Format,ଅଚଳ ସଂରଚନା tm *_Tm,_locale_t _Locale);
  _CRTIMP ଅକ୍ଷର *__cdecl _strdate(ଅକ୍ଷର *_Buffer);
  _CRTIMP ଅକ୍ଷର *__cdecl _strtime(ଅକ୍ଷର *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(ସଂରଚନା tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(ସଂରଚନା tm *_Tm);
#ଯଦି defined (_POSIX_) || defined(__GNUC__)
  ଶୂନ୍ୟ __cdecl tzset(ଶୂନ୍ୟ);
#ଅନ୍ୟଥା
  _CRTIMP ଶୂନ୍ୟ __cdecl _tzset(ଶୂନ୍ୟ);
#endif

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  ଦ୍ୱିଗୁଣ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP ଅକ୍ଷର *__cdecl _ctime64(ଅଚଳ __time64_t *_Time);
  _CRTIMP ସଂରଚନା tm *__cdecl _gmtime64(ଅଚଳ __time64_t *_Time);
  _CRTIMP ସଂରଚନା tm *__cdecl _localtime64(ଅଚଳ __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(ସଂରଚନା tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(ସଂରଚନା tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(ସଂରଚନା tm *_Tm);
  unsigned __cdecl _setsystime(ସଂରଚନା tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା size_t __attribute__ ((mode (DI)));
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned __int64 size_t;
#endif
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା ssize_t __attribute__ ((mode (DI)));
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 ssize_t;
#endif
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ଅଚଳ ସଂରଚନା tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ଅଚଳ __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,ଅଚଳ ସଂରଚନା tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,ଅଚଳ ସଂରଚନା tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ଅଚଳ __time64_t *_Time);
#endif

#ଯଦି !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _wctime32(_Time); }
#ଅନ୍ୟଥା
__CRT_INLINE wchar_t *__cdecl _wctime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
ଦ୍ୱିଗୁଣ __cdecl difftime(time_t _Time1,time_t _Time2);
ଅକ୍ଷର *__cdecl ctime(ଅଚଳ time_t *_Time);
ସଂରଚନା tm *__cdecl gmtime(ଅଚଳ time_t *_Time);
ସଂରଚନା tm *__cdecl localtime(ଅଚଳ time_t *_Time);
ସଂରଚନା tm *__cdecl localtime_r(ଅଚଳ time_t *_Time,ସଂରଚନା tm *);

time_t __cdecl mktime(ସଂରଚନା tm *_Tm);
time_t __cdecl _mkgmtime(ସଂରଚନା tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#ଯଦି 0
__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl difftime(time_t _Time1,time_t _Time2) { ଫେରନ୍ତୁ _difftime32(_Time1,_Time2); }
__CRT_INLINE ଅକ୍ଷର *__cdecl ctime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _ctime32(_Time); }
__CRT_INLINE ସଂରଚନା tm *__cdecl gmtime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _gmtime32(_Time); }
__CRT_INLINE ସଂରଚନା tm *__cdecl localtime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(ସଂରଚନା tm *_Tm) { ଫେରନ୍ତୁ _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ସଂରଚନା tm *_Tm) { ଫେରନ୍ତୁ _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { ଫେରନ୍ତୁ _time32(_Time); }
#endif
#ଅନ୍ୟଥା
__CRT_INLINE ଦ୍ୱିଗୁଣ __cdecl difftime(time_t _Time1,time_t _Time2) { ଫେରନ୍ତୁ _difftime64(_Time1,_Time2); }
__CRT_INLINE ଅକ୍ଷର *__cdecl ctime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _ctime64(_Time); }
__CRT_INLINE ସଂରଚନା tm *__cdecl gmtime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _gmtime64(_Time); }
__CRT_INLINE ସଂରଚନା tm *__cdecl localtime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(ସଂରଚନା tm *_Tm) { ଫେରନ୍ତୁ _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ସଂରଚନା tm *_Tm) { ଫେରନ୍ତୁ _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { ଫେରନ୍ତୁ _time64(_Time); }
#endif
#endif

#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT ପୂର୍ଣ୍ଣସଂଖ୍ୟା daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT ଅକ୍ଷର *tzname[2];
  ଶୂନ୍ୟ __cdecl tzset(ଶୂନ୍ୟ);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
ସଂରଚନା timeval {
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
ସଂରଚନା timezone {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା tz_minuteswest;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା tz_dsttime;
};

  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl mingw_gettimeofday (ସଂରଚନା timeval *p, ସଂରଚନା timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)

#ଅନ୍ତର୍ଭାଵ <sec_api/time_s.h>

/* Adding timespec definition.  */
#ଅନ୍ତର୍ଭାଵ <sys/timeb.h>

#endif /* End _TIME_H_ */

