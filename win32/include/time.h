/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی وخت_H
#تعریف_کړه وخت_H

#ضمن <_mingw.h>

#که_نه_تعریف_شوی _WIN32
#تېروتنه Only Win32 موخه is supported!
#د_که_پای

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _CRTIMP
#تعریف_کړه _CRTIMP __declspec(dllimport)
#د_که_پای

#که_نه_تعریف_شوی _WCHAR_T_DEFINED
#تعریف_کړه _WCHAR_T_DEFINED
  تعريفنوع بینښه لنډ wchar_t;
#د_که_پای

#که_نه_تعریف_شوی _TIME32_T_DEFINED
#تعریف_کړه _TIME32_T_DEFINED
  تعريفنوع اوږد __time32_t;
#د_که_پای

#که_نه_تعریف_شوی _TIME64_T_DEFINED
#تعریف_کړه _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بټونه >= 64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _time64_t __attribute__ ((ډېرپېښ (DI)));
#وإلا
  تعريفنوع __int64 __time64_t;
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی وخت_T_DEFINED
#تعریف_کړه وخت_T_DEFINED
#که_تعریف_شوی USE_32_بټ_وخت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _CLOCK_T_DEFINED
#تعریف_کړه _CLOCK_T_DEFINED
  تعريفنوع اوږد clock_t;
#د_که_پای

#که_نه_تعریف_شوی _SIZE_T_DEFINED
#تعریف_کړه _SIZE_T_DEFINED
#تعریف_لغوه اندازه_t
#که_تعریف_شوی _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بینښه صحيح اندازه_t __attribute__ ((ډېرپېښ (DI)));
#وإلا
  تعريفنوع بینښه __int64 اندازه_t;
#د_که_پای
#وإلا
  تعريفنوع بینښه صحيح اندازه_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _SSIZE_T_DEFINED
#تعریف_کړه _SSIZE_T_DEFINED
#تعریف_لغوه ssize_t
#که_تعریف_شوی _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((ډېرپېښ (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#د_که_پای
#وإلا
  تعريفنوع صحيح ssize_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی عدم
#که_تعریف_شوی __cplusplus
#تعریف_کړه عدم 0
#وإلا
#تعریف_کړه عدم ((فراغ *)0)
#د_که_پای
#د_که_پای

#که_تعریف_شوی USE_32_بټ_وخت_T
#تعریف_کړه _localtime32 localtime
#تعریف_کړه _difftime32     difftime
#تعریف_کړه _ctime32        ctime
#تعریف_کړه _gmtime32       gmtime
#تعریف_کړه _mktime32       mktime
#تعریف_کړه _time32 وخت
#د_که_پای

#که_نه_تعریف_شوی _TM_DEFINED
#تعریف_کړه _TM_DEFINED
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
#د_که_پای

#تعریف_کړه CLOCKS_PER_SEC 1000

  __MINGW_IMPORT صحيح _daylight;
  __MINGW_IMPORT اوږد _dstbias;
  __MINGW_IMPORT اوږد _timezone;
  __MINGW_IMPORT حرف * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(صحيح *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(اوږد *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(اوږد *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(اندازه_t *Return_ارزښت,حرف *بفر_2,اندازه_t اندازه_دننه_بایټونه,صحيح شاخص_2);
  حرف *__cdecl asctime(ثابت بنية tm *_Tm);
  _CRTIMP حرف *__cdecl _ctime32(ثابت __time32_t *وخت_2);
  clock_t __cdecl clock(فراغ);
  _CRTIMP مزدوج __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP بنية tm *__cdecl _gmtime32(ثابت __time32_t *وخت_2);
  _CRTIMP بنية tm *__cdecl _localtime32(ثابت __time32_t *وخت_2);
  اندازه_t __cdecl strftime(حرف *_Buf,اندازه_t اندازه_دننه_بایټونه,ثابت حرف *_Format,ثابت بنية tm *_Tm);
  _CRTIMP اندازه_t __cdecl _strftime_l(حرف *_Buf,اندازه_t Max_اندازه,ثابت حرف *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _strdate(حرف *بفر_2);
  _CRTIMP حرف *__cdecl _strtime(حرف *بفر_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *وخت_2);
  _CRTIMP __time32_t __cdecl _mktime32(بنية tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(بنية tm *_Tm);
#إذا defined (_POSIX_) || defined(__GNUC__)
  فراغ __cdecl tzset(فراغ);
#وإلا
  _CRTIMP فراغ __cdecl _tzset(فراغ);
#د_که_پای

#إذا INTEGRAL_MAX_بټونه >= 64
  مزدوج __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP حرف *__cdecl _ctime64(ثابت __time64_t *وخت_2);
  _CRTIMP بنية tm *__cdecl _gmtime64(ثابت __time64_t *وخت_2);
  _CRTIMP بنية tm *__cdecl _localtime64(ثابت __time64_t *وخت_2);
  _CRTIMP __time64_t __cdecl _mktime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *وخت_2);
#د_که_پای
  بینښه __cdecl _getsystime(بنية tm *_Tm);
  بینښه __cdecl _setsystime(بنية tm *_Tm,بینښه _MilliSec);

#که_نه_تعریف_شوی _SIZE_T_DEFINED
#تعریف_کړه _SIZE_T_DEFINED
#که_تعریف_شوی _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بینښه صحيح اندازه_t __attribute__ ((ډېرپېښ (DI)));
#وإلا
  تعريفنوع بینښه __int64 اندازه_t;
#د_که_پای
#وإلا
  تعريفنوع بینښه اوږد اندازه_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _SSIZE_T_DEFINED
#تعریف_کړه _SSIZE_T_DEFINED
#که_تعریف_شوی _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((ډېرپېښ (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#د_که_پای
#وإلا
  تعريفنوع اوږد ssize_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *وخت_2);
  اندازه_t __cdecl wcsftime(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP اندازه_t __cdecl _wcsftime_l(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *بفر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *بفر_2);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *وخت_2);
#د_که_پای

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#تعریف_کړه _INC_WTIME_INL
#که_تعریف_شوی USE_32_بټ_وخت_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وخت_2) { أرجع _wctime32(وخت_2); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وخت_2) { أرجع _wctime64(وخت_2); }
#د_که_پای
#د_که_پای

#تعریف_کړه _WTIME_DEFINED
#د_که_پای

#که_نه_تعریف_شوی RC_INVOKED
مزدوج __cdecl difftime(time_t _Time1,time_t _Time2);
حرف *__cdecl ctime(ثابت time_t *وخت_2);
بنية tm *__cdecl gmtime(ثابت time_t *وخت_2);
بنية tm *__cdecl localtime(ثابت time_t *وخت_2);
بنية tm *__cdecl localtime_r(ثابت time_t *وخت_2,بنية tm *);

time_t __cdecl mktime(بنية tm *_Tm);
time_t __cdecl _mkgmtime(بنية tm *_Tm);
time_t __cdecl وخت(time_t *وخت_2);

#که_تعریف_شوی USE_32_بټ_وخت_T
#إذا 0
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime32(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *وخت_2) { أرجع _ctime32(وخت_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *وخت_2) { أرجع _gmtime32(وخت_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *وخت_2) { أرجع _localtime32(وخت_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl وخت(time_t *وخت_2) { أرجع _time32(وخت_2); }
#د_که_پای
#وإلا
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime64(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *وخت_2) { أرجع _ctime64(وخت_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *وخت_2) { أرجع _gmtime64(وخت_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *وخت_2) { أرجع _localtime64(وخت_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl وخت(time_t *وخت_2) { أرجع _time64(وخت_2); }
#د_که_پای
#د_که_پای

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#تعریف_کړه CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT صحيح daylight;
  __MINGW_IMPORT اوږد dstbias;
  __MINGW_IMPORT اوږد timezone;
  __MINGW_IMPORT حرف *tzname[2];
  فراغ __cdecl tzset(فراغ);
#د_که_پای

#که_نه_تعریف_شوی _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کړه _TIMEVAL_DEFINED
بنية timeval {
  اوږد tv_sec;
  اوږد tv_usec;
};
#تعریف_کړه timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کړه timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کړه timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#د_که_پای /* _TIMEVAL_DEFINED */

#که_نه_تعریف_شوی __STRICT_ANSI__
#که_نه_تعریف_شوی _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کړه _TIMEZONE_DEFINED
بنية timezone {
  صحيح tz_minuteswest;
  صحيح tz_dsttime;
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);
#د_که_پای
#د_که_پای /* __STRICT_ANSI__ */

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)

#ضمن <sec_api/time_s.h>

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>

#د_که_پای /* End _TIME_H_ */

