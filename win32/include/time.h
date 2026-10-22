/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#અન્તર્ભાવ <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  પ્રકારવ્યાખ્યા unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  પ્રકારવ્યાખ્યા long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#જો _INTEGRAL_MAX_BITS >= 64
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા પૂર્ણાંક _time64_t __attribute__ ((mode (DI)));
#નહીંતર
  પ્રકારવ્યાખ્યા __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  પ્રકારવ્યાખ્યા __time32_t time_t;
#નહીંતર
  પ્રકારવ્યાખ્યા __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  પ્રકારવ્યાખ્યા long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક size_t __attribute__ ((mode (DI)));
#નહીંતર
  પ્રકારવ્યાખ્યા unsigned __int64 size_t;
#endif
#નહીંતર
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા પૂર્ણાંક ssize_t __attribute__ ((mode (DI)));
#નહીંતર
  પ્રકારવ્યાખ્યા __int64 ssize_t;
#endif
#નહીંતર
  પ્રકારવ્યાખ્યા પૂર્ણાંક ssize_t;
#endif
#endif

#ifndef ખાલી
#ifdef __cplusplus
#define ખાલી 0
#નહીંતર
#define ખાલી ((શૂન્ય *)0)
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
  સંરચના tm {
    પૂર્ણાંક tm_sec;
    પૂર્ણાંક tm_min;
    પૂર્ણાંક tm_hour;
    પૂર્ણાંક tm_mday;
    પૂર્ણાંક tm_mon;
    પૂર્ણાંક tm_year;
    પૂર્ણાંક tm_wday;
    પૂર્ણાંક tm_yday;
    પૂર્ણાંક tm_isdst;
  };
#endif

#define CLOCKS_PER_SEC 1000

  __MINGW_IMPORT પૂર્ણાંક _daylight;
  __MINGW_IMPORT long _dstbias;
  __MINGW_IMPORT long _timezone;
  __MINGW_IMPORT અક્ષર * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(પૂર્ણાંક *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *Return_કિંમત,અક્ષર *_Buffer,size_t _SizeInBytes,પૂર્ણાંક _Index);
  અક્ષર *__cdecl asctime(અચલ સંરચના tm *_Tm);
  _CRTIMP અક્ષર *__cdecl _ctime32(અચલ __time32_t *_Time);
  clock_t __cdecl clock(શૂન્ય);
  _CRTIMP દ્વિગુણ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP સંરચના tm *__cdecl _gmtime32(અચલ __time32_t *_Time);
  _CRTIMP સંરચના tm *__cdecl _localtime32(અચલ __time32_t *_Time);
  size_t __cdecl strftime(અક્ષર *_Buf,size_t _SizeInBytes,અચલ અક્ષર *_Format,અચલ સંરચના tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(અક્ષર *_Buf,size_t _Max_size,અચલ અક્ષર *_Format,અચલ સંરચના tm *_Tm,_locale_t _Locale);
  _CRTIMP અક્ષર *__cdecl _strdate(અક્ષર *_Buffer);
  _CRTIMP અક્ષર *__cdecl _strtime(અક્ષર *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(સંરચના tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(સંરચના tm *_Tm);
#જો defined (_POSIX_) || defined(__GNUC__)
  શૂન્ય __cdecl tzset(શૂન્ય);
#નહીંતર
  _CRTIMP શૂન્ય __cdecl _tzset(શૂન્ય);
#endif

#જો _INTEGRAL_MAX_BITS >= 64
  દ્વિગુણ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP અક્ષર *__cdecl _ctime64(અચલ __time64_t *_Time);
  _CRTIMP સંરચના tm *__cdecl _gmtime64(અચલ __time64_t *_Time);
  _CRTIMP સંરચના tm *__cdecl _localtime64(અચલ __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(સંરચના tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(સંરચના tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(સંરચના tm *_Tm);
  unsigned __cdecl _setsystime(સંરચના tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક size_t __attribute__ ((mode (DI)));
#નહીંતર
  પ્રકારવ્યાખ્યા unsigned __int64 size_t;
#endif
#નહીંતર
  પ્રકારવ્યાખ્યા unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા પૂર્ણાંક ssize_t __attribute__ ((mode (DI)));
#નહીંતર
  પ્રકારવ્યાખ્યા __int64 ssize_t;
#endif
#નહીંતર
  પ્રકારવ્યાખ્યા long ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(અચલ સંરચના tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(અચલ __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,અચલ સંરચના tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,અચલ સંરચના tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(અચલ __time64_t *_Time);
#endif

#જો !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(અચલ time_t *_Time) { પાછા _wctime32(_Time); }
#નહીંતર
__CRT_INLINE wchar_t *__cdecl _wctime(અચલ time_t *_Time) { પાછા _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
દ્વિગુણ __cdecl difftime(time_t _Time1,time_t _Time2);
અક્ષર *__cdecl ctime(અચલ time_t *_Time);
સંરચના tm *__cdecl gmtime(અચલ time_t *_Time);
સંરચના tm *__cdecl localtime(અચલ time_t *_Time);
સંરચના tm *__cdecl localtime_r(અચલ time_t *_Time,સંરચના tm *);

time_t __cdecl mktime(સંરચના tm *_Tm);
time_t __cdecl _mkgmtime(સંરચના tm *_Tm);
time_t __cdecl time(time_t *_Time);

#ifdef _USE_32BIT_TIME_T
#જો 0
__CRT_INLINE દ્વિગુણ __cdecl difftime(time_t _Time1,time_t _Time2) { પાછા _difftime32(_Time1,_Time2); }
__CRT_INLINE અક્ષર *__cdecl ctime(અચલ time_t *_Time) { પાછા _ctime32(_Time); }
__CRT_INLINE સંરચના tm *__cdecl gmtime(અચલ time_t *_Time) { પાછા _gmtime32(_Time); }
__CRT_INLINE સંરચના tm *__cdecl localtime(અચલ time_t *_Time) { પાછા _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(સંરચના tm *_Tm) { પાછા _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(સંરચના tm *_Tm) { પાછા _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { પાછા _time32(_Time); }
#endif
#નહીંતર
__CRT_INLINE દ્વિગુણ __cdecl difftime(time_t _Time1,time_t _Time2) { પાછા _difftime64(_Time1,_Time2); }
__CRT_INLINE અક્ષર *__cdecl ctime(અચલ time_t *_Time) { પાછા _ctime64(_Time); }
__CRT_INLINE સંરચના tm *__cdecl gmtime(અચલ time_t *_Time) { પાછા _gmtime64(_Time); }
__CRT_INLINE સંરચના tm *__cdecl localtime(અચલ time_t *_Time) { પાછા _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(સંરચના tm *_Tm) { પાછા _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(સંરચના tm *_Tm) { પાછા _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { પાછા _time64(_Time); }
#endif
#endif

#જો !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT પૂર્ણાંક daylight;
  __MINGW_IMPORT long dstbias;
  __MINGW_IMPORT long timezone;
  __MINGW_IMPORT અક્ષર *tzname[2];
  શૂન્ય __cdecl tzset(શૂન્ય);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
સંરચના timeval {
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
સંરચના timezone {
  પૂર્ણાંક tz_minuteswest;
  પૂર્ણાંક tz_dsttime;
};

  બાહ્ય પૂર્ણાંક __cdecl mingw_gettimeofday (સંરચના timeval *p, સંરચના timezone *z);
#endif
#endif /* __STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)

#અન્તર્ભાવ <sec_api/time_s.h>

/* Adding timespec definition.  */
#અન્તર્ભાવ <sys/timeb.h>

#endif /* End _TIME_H_ */

