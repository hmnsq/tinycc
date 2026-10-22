/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#அந்தர்பாவ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  வகைவரை unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  வகைவரை long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#எனில் _INTEGRAL_MAX_BITS >= 64
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை முழு _time64_t __attribute__ ((mode (DI)));
#இல்லையெனில்
  வகைவரை __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  வகைவரை __time32_t time_t;
#இல்லையெனில்
  வகைவரை __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  வகைவரை long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை unsigned முழு size_t __attribute__ ((mode (DI)));
#இல்லையெனில்
  வகைவரை unsigned __int64 size_t;
#endif
#இல்லையெனில்
  வகைவரை unsigned முழு size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை முழு ssize_t __attribute__ ((mode (DI)));
#இல்லையெனில்
  வகைவரை __int64 ssize_t;
#endif
#இல்லையெனில்
  வகைவரை முழு ssize_t;
#endif
#endif

#ifndef வெற்று
#ifdef __cplusplus
#define வெற்று 0
#இல்லையெனில்
#define வெற்று ((வெறுமை *)0)
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
  கட்டமைப்பு tm {
    முழு tm_sec;
    முழு tm_min;
    முழு tm_hour;
    முழு tm_mday;
    முழு tm_mon;
    முழு tm_year;
    முழு tm_wday;
    முழு tm_yday;
    முழு tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT முழு _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT எழுத்து * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(முழு *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_மதிப்பு,எழுத்து *_Buffer,size_t _SizeInBytes,முழு _Index);
  எழுத்து *__cdecl asctime(மாறிலி கட்டமைப்பு tm *_Tm);
  _CRTIMP எழுத்து *__cdecl _ctime32(மாறிலி __time32_t *_Time);
  clock_t __cdecl clock(வெறுமை);
  _CRTIMP இரட்டை __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP கட்டமைப்பு tm *__cdecl _gmtime32(மாறிலி __time32_t *_Time);
  _CRTIMP கட்டமைப்பு tm *__cdecl _localtime32(மாறிலி __time32_t *_Time);
  size_t __cdecl strftime(எழுத்து *_Buf,size_t _SizeInBytes,மாறிலி எழுத்து *_Format,மாறிலி கட்டமைப்பு tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(எழுத்து *_Buf,size_t _Max_size,மாறிலி எழுத்து *_Format,மாறிலி கட்டமைப்பு tm *_Tm,_locale_t _Locale);
  _CRTIMP எழுத்து *__cdecl _strdate(எழுத்து *_Buffer);
  _CRTIMP எழுத்து *__cdecl _strtime(எழுத்து *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(கட்டமைப்பு tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(கட்டமைப்பு tm *_Tm);
#எனில் defined (_POSIX_) || defined(__GNUC__)
  வெறுமை __cdecl tzset(வெறுமை);
#இல்லையெனில்
  _CRTIMP வெறுமை __cdecl _tzset(வெறுமை);
#endif

#எனில் _INTEGRAL_MAX_BITS >= 64
  இரட்டை __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP எழுத்து *__cdecl _ctime64(மாறிலி __time64_t *_Time);
  _CRTIMP கட்டமைப்பு tm *__cdecl _gmtime64(மாறிலி __time64_t *_Time);
  _CRTIMP கட்டமைப்பு tm *__cdecl _localtime64(மாறிலி __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(கட்டமைப்பு tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(கட்டமைப்பு tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(கட்டமைப்பு tm *_Tm);
  unsigned __cdecl _setsystime(கட்டமைப்பு tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை unsigned முழு size_t __attribute__ ((mode (DI)));
#இல்லையெனில்
  வகைவரை unsigned __int64 size_t;
#endif
#இல்லையெனில்
  வகைவரை unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை முழு ssize_t __attribute__ ((mode (DI)));
#இல்லையெனில்
  வகைவரை __int64 ssize_t;
#endif
#இல்லையெனில்
  வகைவரை long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(மாறிலி கட்டமைப்பு tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(மாறிலி __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,மாறிலி கட்டமைப்பு tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,மாறிலி கட்டமைப்பு tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(மாறிலி __time64_t *_Time);
#endif

#எனில் !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(மாறிலி time_t *_Time) { திரும்பு _wctime32(_Time); }
#இல்லையெனில்
__CRT_INLINE wchar_t *__cdecl _wctime(மாறிலி time_t *_Time) { திரும்பு _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
இரட்டை __cdecl difftime(time_t _Time1,time_t _Time2);
எழுத்து *__cdecl ctime(மாறிலி time_t *_Time);
கட்டமைப்பு tm *__cdecl gmtime(மாறிலி time_t *_Time);
கட்டமைப்பு tm *__cdecl localtime(மாறிலி time_t *_Time);
கட்டமைப்பு tm *__cdecl localtime_r(மாறிலி time_t *_Time,கட்டமைப்பு tm *);

time_t __cdecl mktime(கட்டமைப்பு tm *_Tm);
time_t __cdecl _mkgmtime(கட்டமைப்பு tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#எனில் 0
__CRT_INLINE இரட்டை __cdecl difftime(time_t _Time1,time_t _Time2) { திரும்பு _difftime32(_Time1,_Time2); }
__CRT_INLINE எழுத்து *__cdecl ctime(மாறிலி time_t *_Time) { திரும்பு _ctime32(_Time); }
__CRT_INLINE கட்டமைப்பு tm *__cdecl gmtime(மாறிலி time_t *_Time) { திரும்பு _gmtime32(_Time); }
__CRT_INLINE கட்டமைப்பு tm *__cdecl localtime(மாறிலி time_t *_Time) { திரும்பு _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(கட்டமைப்பு tm *_Tm) { திரும்பு _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(கட்டமைப்பு tm *_Tm) { திரும்பு _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { திரும்பு _time32(_Time); }
#endif
#இல்லையெனில்
__CRT_INLINE இரட்டை __cdecl difftime(time_t _Time1,time_t _Time2) { திரும்பு _difftime64(_Time1,_Time2); }
__CRT_INLINE எழுத்து *__cdecl ctime(மாறிலி time_t *_Time) { திரும்பு _ctime64(_Time); }
__CRT_INLINE கட்டமைப்பு tm *__cdecl gmtime(மாறிலி time_t *_Time) { திரும்பு _gmtime64(_Time); }
__CRT_INLINE கட்டமைப்பு tm *__cdecl localtime(மாறிலி time_t *_Time) { திரும்பு _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(கட்டமைப்பு tm *_Tm) { திரும்பு _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(கட்டமைப்பு tm *_Tm) { திரும்பு _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { திரும்பு _time64(_Time); }
#endif
#endif

#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT முழு daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT எழுத்து *tzname[2];
  வெறுமை __cdecl tzset(வெறுமை);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
கட்டமைப்பு timeval {
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
கட்டமைப்பு timezone {
  முழு tz_minuteswest;
  முழு tz_dsttime;
};

  வெளி முழு __cdecl mingw_gettimeofday (கட்டமைப்பு timeval *p, கட்டமைப்பு timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)

#அந்தர்பாவ <sec_api/time_s.h>

/* Adding timespec definition.  */
#அந்தர்பாவ <sys/timeb.h>

#endif /* End _TIME_H_ */

