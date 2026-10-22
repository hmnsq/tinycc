/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#अन्तर्भाव <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(प्रक्षिप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  प्रकारनिर्देश unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  प्रकारनिर्देश long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#जइ _INTEGRAL_MAX_BITS >= 64
#जइ defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क _time64_t __attribute__ ((mode (DI)));
#अण्णहा
  प्रकारनिर्देश __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  प्रकारनिर्देश __time32_t time_t;
#अण्णहा
  प्रकारनिर्देश __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  प्रकारनिर्देश long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#जइ defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश unsigned पूर्णाङ्क size_t __attribute__ ((mode (DI)));
#अण्णहा
  प्रकारनिर्देश unsigned __int64 size_t;
#endif
#अण्णहा
  प्रकारनिर्देश unsigned पूर्णाङ्क size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#जइ defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((mode (DI)));
#अण्णहा
  प्रकारनिर्देश __int64 ssize_t;
#endif
#अण्णहा
  प्रकारनिर्देश पूर्णाङ्क ssize_t;
#endif
#endif

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अण्णहा
#define रिक्त ((शून्य *)0)
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
  संरचना tm {
    पूर्णाङ्क tm_sec;
    पूर्णाङ्क tm_min;
    पूर्णाङ्क tm_hour;
    पूर्णाङ्क tm_mday;
    पूर्णाङ्क tm_mon;
    पूर्णाङ्क tm_year;
    पूर्णाङ्क tm_wday;
    पूर्णाङ्क tm_yday;
    पूर्णाङ्क tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT पूर्णाङ्क _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT वर्ण * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(पूर्णाङ्क *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_मानम्,वर्ण *_Buffer,size_t _SizeInBytes,पूर्णाङ्क _Index);
  वर्ण *__cdecl asctime(ध्रुव संरचना tm *_Tm);
  _CRTIMP वर्ण *__cdecl _ctime32(ध्रुव __time32_t *_Time);
  clock_t __cdecl clock(शून्य);
  _CRTIMP द्विगुण __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP संरचना tm *__cdecl _gmtime32(ध्रुव __time32_t *_Time);
  _CRTIMP संरचना tm *__cdecl _localtime32(ध्रुव __time32_t *_Time);
  size_t __cdecl strftime(वर्ण *_Buf,size_t _SizeInBytes,ध्रुव वर्ण *_Format,ध्रुव संरचना tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(वर्ण *_Buf,size_t _Max_size,ध्रुव वर्ण *_Format,ध्रुव संरचना tm *_Tm,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _strdate(वर्ण *_Buffer);
  _CRTIMP वर्ण *__cdecl _strtime(वर्ण *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(संरचना tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(संरचना tm *_Tm);
#जइ defined (_POSIX_) || defined(__GNUC__)
  शून्य __cdecl tzset(शून्य);
#अण्णहा
  _CRTIMP शून्य __cdecl _tzset(शून्य);
#endif

#जइ _INTEGRAL_MAX_BITS >= 64
  द्विगुण __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP वर्ण *__cdecl _ctime64(ध्रुव __time64_t *_Time);
  _CRTIMP संरचना tm *__cdecl _gmtime64(ध्रुव __time64_t *_Time);
  _CRTIMP संरचना tm *__cdecl _localtime64(ध्रुव __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(संरचना tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(संरचना tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(संरचना tm *_Tm);
  unsigned __cdecl _setsystime(संरचना tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#जइ defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश unsigned पूर्णाङ्क size_t __attribute__ ((mode (DI)));
#अण्णहा
  प्रकारनिर्देश unsigned __int64 size_t;
#endif
#अण्णहा
  प्रकारनिर्देश unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#जइ defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((mode (DI)));
#अण्णहा
  प्रकारनिर्देश __int64 ssize_t;
#endif
#अण्णहा
  प्रकारनिर्देश long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ध्रुव संरचना tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ध्रुव __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#जइ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ध्रुव __time64_t *_Time);
#endif

#जइ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { प्रत्यागम _wctime32(_Time); }
#अण्णहा
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { प्रत्यागम _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
द्विगुण __cdecl difftime(time_t _Time1,time_t _Time2);
वर्ण *__cdecl ctime(ध्रुव time_t *_Time);
संरचना tm *__cdecl gmtime(ध्रुव time_t *_Time);
संरचना tm *__cdecl localtime(ध्रुव time_t *_Time);
संरचना tm *__cdecl localtime_r(ध्रुव time_t *_Time,संरचना tm *);

time_t __cdecl mktime(संरचना tm *_Tm);
time_t __cdecl _mkgmtime(संरचना tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#जइ 0
__CRT_INLINE द्विगुण __cdecl difftime(time_t _Time1,time_t _Time2) { प्रत्यागम _difftime32(_Time1,_Time2); }
__CRT_INLINE वर्ण *__cdecl ctime(ध्रुव time_t *_Time) { प्रत्यागम _ctime32(_Time); }
__CRT_INLINE संरचना tm *__cdecl gmtime(ध्रुव time_t *_Time) { प्रत्यागम _gmtime32(_Time); }
__CRT_INLINE संरचना tm *__cdecl localtime(ध्रुव time_t *_Time) { प्रत्यागम _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(संरचना tm *_Tm) { प्रत्यागम _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(संरचना tm *_Tm) { प्रत्यागम _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { प्रत्यागम _time32(_Time); }
#endif
#अण्णहा
__CRT_INLINE द्विगुण __cdecl difftime(time_t _Time1,time_t _Time2) { प्रत्यागम _difftime64(_Time1,_Time2); }
__CRT_INLINE वर्ण *__cdecl ctime(ध्रुव time_t *_Time) { प्रत्यागम _ctime64(_Time); }
__CRT_INLINE संरचना tm *__cdecl gmtime(ध्रुव time_t *_Time) { प्रत्यागम _gmtime64(_Time); }
__CRT_INLINE संरचना tm *__cdecl localtime(ध्रुव time_t *_Time) { प्रत्यागम _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(संरचना tm *_Tm) { प्रत्यागम _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(संरचना tm *_Tm) { प्रत्यागम _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { प्रत्यागम _time64(_Time); }
#endif
#endif

#जइ !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT पूर्णाङ्क daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT वर्ण *tzname[2];
  शून्य __cdecl tzset(शून्य);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
संरचना timeval {
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
संरचना timezone {
  पूर्णाङ्क tz_minuteswest;
  पूर्णाङ्क tz_dsttime;
};

  बाह्य पूर्णाङ्क __cdecl mingw_gettimeofday (संरचना timeval *p, संरचना timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(निष्कासय)

#अन्तर्भाव <sec_api/time_s.h>

/* Adding timespec definition.  */
#अन्तर्भाव <sys/timeb.h>

#endif /* End _TIME_H_ */

