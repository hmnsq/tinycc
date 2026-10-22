/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#അന്തര്ഭാവ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  തരനിർവചനം unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  തരനിർവചനം long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം പൂർണ്ണസംഖ്യ _time64_t __attribute__ ((mode (DI)));
#അല്ലെങ്കിൽ
  തരനിർവചനം __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  തരനിർവചനം __time32_t time_t;
#അല്ലെങ്കിൽ
  തരനിർവചനം __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  തരനിർവചനം long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ size_t __attribute__ ((mode (DI)));
#അല്ലെങ്കിൽ
  തരനിർവചനം unsigned __int64 size_t;
#endif
#അല്ലെങ്കിൽ
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം പൂർണ്ണസംഖ്യ ssize_t __attribute__ ((mode (DI)));
#അല്ലെങ്കിൽ
  തരനിർവചനം __int64 ssize_t;
#endif
#അല്ലെങ്കിൽ
  തരനിർവചനം പൂർണ്ണസംഖ്യ ssize_t;
#endif
#endif

#ifndef ശൂന്യ
#ifdef __cplusplus
#define ശൂന്യ 0
#അല്ലെങ്കിൽ
#define ശൂന്യ ((ശൂന്യം *)0)
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
  ഘടന tm {
    പൂർണ്ണസംഖ്യ tm_sec;
    പൂർണ്ണസംഖ്യ tm_min;
    പൂർണ്ണസംഖ്യ tm_hour;
    പൂർണ്ണസംഖ്യ tm_mday;
    പൂർണ്ണസംഖ്യ tm_mon;
    പൂർണ്ണസംഖ്യ tm_year;
    പൂർണ്ണസംഖ്യ tm_wday;
    പൂർണ്ണസംഖ്യ tm_yday;
    പൂർണ്ണസംഖ്യ tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT പൂർണ്ണസംഖ്യ _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT അക്ഷരം * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(പൂർണ്ണസംഖ്യ *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_മൂല്യം,അക്ഷരം *_Buffer,size_t _SizeInBytes,പൂർണ്ണസംഖ്യ _Index);
  അക്ഷരം *__cdecl asctime(സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP അക്ഷരം *__cdecl _ctime32(സ്ഥിരം __time32_t *_Time);
  clock_t __cdecl clock(ശൂന്യം);
  _CRTIMP ഇരട്ട __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP ഘടന tm *__cdecl _gmtime32(സ്ഥിരം __time32_t *_Time);
  _CRTIMP ഘടന tm *__cdecl _localtime32(സ്ഥിരം __time32_t *_Time);
  size_t __cdecl strftime(അക്ഷരം *_Buf,size_t _SizeInBytes,സ്ഥിരം അക്ഷരം *_Format,സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(അക്ഷരം *_Buf,size_t _Max_size,സ്ഥിരം അക്ഷരം *_Format,സ്ഥിരം ഘടന tm *_Tm,_locale_t _Locale);
  _CRTIMP അക്ഷരം *__cdecl _strdate(അക്ഷരം *_Buffer);
  _CRTIMP അക്ഷരം *__cdecl _strtime(അക്ഷരം *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(ഘടന tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(ഘടന tm *_Tm);
#എങ്കിൽ defined (_POSIX_) || defined(__GNUC__)
  ശൂന്യം __cdecl tzset(ശൂന്യം);
#അല്ലെങ്കിൽ
  _CRTIMP ശൂന്യം __cdecl _tzset(ശൂന്യം);
#endif

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  ഇരട്ട __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP അക്ഷരം *__cdecl _ctime64(സ്ഥിരം __time64_t *_Time);
  _CRTIMP ഘടന tm *__cdecl _gmtime64(സ്ഥിരം __time64_t *_Time);
  _CRTIMP ഘടന tm *__cdecl _localtime64(സ്ഥിരം __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(ഘടന tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(ഘടന tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(ഘടന tm *_Tm);
  unsigned __cdecl _setsystime(ഘടന tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ size_t __attribute__ ((mode (DI)));
#അല്ലെങ്കിൽ
  തരനിർവചനം unsigned __int64 size_t;
#endif
#അല്ലെങ്കിൽ
  തരനിർവചനം unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം പൂർണ്ണസംഖ്യ ssize_t __attribute__ ((mode (DI)));
#അല്ലെങ്കിൽ
  തരനിർവചനം __int64 ssize_t;
#endif
#അല്ലെങ്കിൽ
  തരനിർവചനം long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(സ്ഥിരം __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,സ്ഥിരം ഘടന tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(സ്ഥിരം __time64_t *_Time);
#endif

#എങ്കിൽ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(സ്ഥിരം time_t *_Time) { തിരികെ _wctime32(_Time); }
#അല്ലെങ്കിൽ
__CRT_INLINE wchar_t *__cdecl _wctime(സ്ഥിരം time_t *_Time) { തിരികെ _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
ഇരട്ട __cdecl difftime(time_t _Time1,time_t _Time2);
അക്ഷരം *__cdecl ctime(സ്ഥിരം time_t *_Time);
ഘടന tm *__cdecl gmtime(സ്ഥിരം time_t *_Time);
ഘടന tm *__cdecl localtime(സ്ഥിരം time_t *_Time);
ഘടന tm *__cdecl localtime_r(സ്ഥിരം time_t *_Time,ഘടന tm *);

time_t __cdecl mktime(ഘടന tm *_Tm);
time_t __cdecl _mkgmtime(ഘടന tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#എങ്കിൽ 0
__CRT_INLINE ഇരട്ട __cdecl difftime(time_t _Time1,time_t _Time2) { തിരികെ _difftime32(_Time1,_Time2); }
__CRT_INLINE അക്ഷരം *__cdecl ctime(സ്ഥിരം time_t *_Time) { തിരികെ _ctime32(_Time); }
__CRT_INLINE ഘടന tm *__cdecl gmtime(സ്ഥിരം time_t *_Time) { തിരികെ _gmtime32(_Time); }
__CRT_INLINE ഘടന tm *__cdecl localtime(സ്ഥിരം time_t *_Time) { തിരികെ _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(ഘടന tm *_Tm) { തിരികെ _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ഘടന tm *_Tm) { തിരികെ _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { തിരികെ _time32(_Time); }
#endif
#അല്ലെങ്കിൽ
__CRT_INLINE ഇരട്ട __cdecl difftime(time_t _Time1,time_t _Time2) { തിരികെ _difftime64(_Time1,_Time2); }
__CRT_INLINE അക്ഷരം *__cdecl ctime(സ്ഥിരം time_t *_Time) { തിരികെ _ctime64(_Time); }
__CRT_INLINE ഘടന tm *__cdecl gmtime(സ്ഥിരം time_t *_Time) { തിരികെ _gmtime64(_Time); }
__CRT_INLINE ഘടന tm *__cdecl localtime(സ്ഥിരം time_t *_Time) { തിരികെ _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(ഘടന tm *_Tm) { തിരികെ _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ഘടന tm *_Tm) { തിരികെ _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { തിരികെ _time64(_Time); }
#endif
#endif

#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT പൂർണ്ണസംഖ്യ daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT അക്ഷരം *tzname[2];
  ശൂന്യം __cdecl tzset(ശൂന്യം);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
ഘടന timeval {
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
ഘടന timezone {
  പൂർണ്ണസംഖ്യ tz_minuteswest;
  പൂർണ്ണസംഖ്യ tz_dsttime;
};

  ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl mingw_gettimeofday (ഘടന timeval *p, ഘടന timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)

#അന്തര്ഭാവ <sec_api/time_s.h>

/* Adding timespec definition.  */
#അന്തര്ഭാവ <sys/timeb.h>

#endif /* End _TIME_H_ */

