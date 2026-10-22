/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده زمان_H
#تعریف_کن زمان_H

#ضمن <_mingw.h>

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _CRTIMP
#تعریف_کن _CRTIMP __declspec(dllimport)
#پایان_اگر

#اگر_تعریف_نشده _WCHAR_T_DEFINED
#تعریف_کن _WCHAR_T_DEFINED
  تعريفنوع بیعلامت کوتاه wchar_t;
#پایان_اگر

#اگر_تعریف_نشده _TIME32_T_DEFINED
#تعریف_کن _TIME32_T_DEFINED
  تعريفنوع دراز __time32_t;
#پایان_اگر

#اگر_تعریف_نشده _TIME64_T_DEFINED
#تعریف_کن _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بیتها >= 64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _time64_t __attribute__ ((نما (DI)));
#وإلا
  تعريفنوع __int64 __time64_t;
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده زمان_T_DEFINED
#تعریف_کن زمان_T_DEFINED
#اگر_تعریف_شده USE_32_بیت_زمان_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _CLOCK_T_DEFINED
#تعریف_کن _CLOCK_T_DEFINED
  تعريفنوع دراز clock_t;
#پایان_اگر

#اگر_تعریف_نشده _SIZE_T_DEFINED
#تعریف_کن _SIZE_T_DEFINED
#لغو_تعریف اندازه_t
#اگر_تعریف_شده _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بیعلامت صحيح اندازه_t __attribute__ ((نما (DI)));
#وإلا
  تعريفنوع بیعلامت __int64 اندازه_t;
#پایان_اگر
#وإلا
  تعريفنوع بیعلامت صحيح اندازه_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _SSIZE_T_DEFINED
#تعریف_کن _SSIZE_T_DEFINED
#لغو_تعریف ssize_t
#اگر_تعریف_شده _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((نما (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#پایان_اگر
#وإلا
  تعريفنوع صحيح ssize_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده USE_32_بیت_زمان_T
#تعریف_کن _localtime32 localtime
#تعریف_کن _difftime32     difftime
#تعریف_کن _ctime32        ctime
#تعریف_کن _gmtime32       gmtime
#تعریف_کن _mktime32       mktime
#تعریف_کن _time32 زمان
#پایان_اگر

#اگر_تعریف_نشده _TM_DEFINED
#تعریف_کن _TM_DEFINED
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
#پایان_اگر

#تعریف_کن CLOCKS_PER_SEC 1000

  __MINGW_IMPORT صحيح _daylight;
  __MINGW_IMPORT دراز _dstbias;
  __MINGW_IMPORT دراز _timezone;
  __MINGW_IMPORT حرف * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(صحيح *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(دراز *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(دراز *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(اندازه_t *Return_مقدار,حرف *میانگیر_2,اندازه_t اندازه_درون_بایتها,صحيح شاخص_2);
  حرف *__cdecl asctime(ثابت بنية tm *_Tm);
  _CRTIMP حرف *__cdecl _ctime32(ثابت __time32_t *زمان_2);
  clock_t __cdecl clock(فراغ);
  _CRTIMP مزدوج __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP بنية tm *__cdecl _gmtime32(ثابت __time32_t *زمان_2);
  _CRTIMP بنية tm *__cdecl _localtime32(ثابت __time32_t *زمان_2);
  اندازه_t __cdecl strftime(حرف *_Buf,اندازه_t اندازه_درون_بایتها,ثابت حرف *_Format,ثابت بنية tm *_Tm);
  _CRTIMP اندازه_t __cdecl _strftime_l(حرف *_Buf,اندازه_t Max_اندازه,ثابت حرف *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _strdate(حرف *میانگیر_2);
  _CRTIMP حرف *__cdecl _strtime(حرف *میانگیر_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *زمان_2);
  _CRTIMP __time32_t __cdecl _mktime32(بنية tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(بنية tm *_Tm);
#إذا defined (_POSIX_) || defined(__GNUC__)
  فراغ __cdecl tzset(فراغ);
#وإلا
  _CRTIMP فراغ __cdecl _tzset(فراغ);
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 64
  مزدوج __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP حرف *__cdecl _ctime64(ثابت __time64_t *زمان_2);
  _CRTIMP بنية tm *__cdecl _gmtime64(ثابت __time64_t *زمان_2);
  _CRTIMP بنية tm *__cdecl _localtime64(ثابت __time64_t *زمان_2);
  _CRTIMP __time64_t __cdecl _mktime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *زمان_2);
#پایان_اگر
  بیعلامت __cdecl _getsystime(بنية tm *_Tm);
  بیعلامت __cdecl _setsystime(بنية tm *_Tm,بیعلامت _MilliSec);

#اگر_تعریف_نشده _SIZE_T_DEFINED
#تعریف_کن _SIZE_T_DEFINED
#اگر_تعریف_شده _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بیعلامت صحيح اندازه_t __attribute__ ((نما (DI)));
#وإلا
  تعريفنوع بیعلامت __int64 اندازه_t;
#پایان_اگر
#وإلا
  تعريفنوع بیعلامت دراز اندازه_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _SSIZE_T_DEFINED
#تعریف_کن _SSIZE_T_DEFINED
#اگر_تعریف_شده _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((نما (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#پایان_اگر
#وإلا
  تعريفنوع دراز ssize_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *زمان_2);
  اندازه_t __cdecl wcsftime(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP اندازه_t __cdecl _wcsftime_l(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *میانگیر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *میانگیر_2);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *زمان_2);
#پایان_اگر

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#تعریف_کن _INC_WTIME_INL
#اگر_تعریف_شده USE_32_بیت_زمان_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *زمان_2) { أرجع _wctime32(زمان_2); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *زمان_2) { أرجع _wctime64(زمان_2); }
#پایان_اگر
#پایان_اگر

#تعریف_کن _WTIME_DEFINED
#پایان_اگر

#اگر_تعریف_نشده RC_INVOKED
مزدوج __cdecl difftime(time_t _Time1,time_t _Time2);
حرف *__cdecl ctime(ثابت time_t *زمان_2);
بنية tm *__cdecl gmtime(ثابت time_t *زمان_2);
بنية tm *__cdecl localtime(ثابت time_t *زمان_2);
بنية tm *__cdecl localtime_r(ثابت time_t *زمان_2,بنية tm *);

time_t __cdecl mktime(بنية tm *_Tm);
time_t __cdecl _mkgmtime(بنية tm *_Tm);
time_t __cdecl زمان(time_t *زمان_2);

#اگر_تعریف_شده USE_32_بیت_زمان_T
#إذا 0
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime32(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *زمان_2) { أرجع _ctime32(زمان_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *زمان_2) { أرجع _gmtime32(زمان_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *زمان_2) { أرجع _localtime32(زمان_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl زمان(time_t *زمان_2) { أرجع _time32(زمان_2); }
#پایان_اگر
#وإلا
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime64(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *زمان_2) { أرجع _ctime64(زمان_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *زمان_2) { أرجع _gmtime64(زمان_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *زمان_2) { أرجع _localtime64(زمان_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl زمان(time_t *زمان_2) { أرجع _time64(زمان_2); }
#پایان_اگر
#پایان_اگر

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#تعریف_کن CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT صحيح daylight;
  __MINGW_IMPORT دراز dstbias;
  __MINGW_IMPORT دراز timezone;
  __MINGW_IMPORT حرف *tzname[2];
  فراغ __cdecl tzset(فراغ);
#پایان_اگر

#اگر_تعریف_نشده _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کن _TIMEVAL_DEFINED
بنية timeval {
  دراز tv_sec;
  دراز tv_usec;
};
#تعریف_کن timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کن timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کن timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#پایان_اگر /* _TIMEVAL_DEFINED */

#اگر_تعریف_نشده __STRICT_ANSI__
#اگر_تعریف_نشده _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کن _TIMEZONE_DEFINED
بنية timezone {
  صحيح tz_minuteswest;
  صحيح tz_dsttime;
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);
#پایان_اگر
#پایان_اگر /* __STRICT_ANSI__ */

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)

#ضمن <sec_api/time_s.h>

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>

#پایان_اگر /* End _TIME_H_ */

