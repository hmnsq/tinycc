/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل وقت_H
#وصف_ڪريو وقت_H

#ضمن <_mingw.h>

#جيڪڏهن_وصف_نه_ٿيل _WIN32
#غلطي Only Win32 هدف is supported!
#جيڪڏهن_پورو

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRTIMP
#وصف_ڪريو _CRTIMP __declspec(dllimport)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCHAR_T_DEFINED
#وصف_ڪريو _WCHAR_T_DEFINED
  تعريفنوع بنانشان ننڍو wchar_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME32_T_DEFINED
#وصف_ڪريو _TIME32_T_DEFINED
  تعريفنوع ڊگهو __time32_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME64_T_DEFINED
#وصف_ڪريو _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٽ >= 64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _time64_t __attribute__ ((گهڻائي (DI)));
#وإلا
  تعريفنوع __int64 __time64_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل وقت_T_DEFINED
#وصف_ڪريو وقت_T_DEFINED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CLOCK_T_DEFINED
#وصف_ڪريو _CLOCK_T_DEFINED
  تعريفنوع ڊگهو clock_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _SIZE_T_DEFINED
#وصف_ڪريو _SIZE_T_DEFINED
#وصف_رد سائيز_t
#جيڪڏهن_وصف_ٿيل _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بنانشان صحيح سائيز_t __attribute__ ((گهڻائي (DI)));
#وإلا
  تعريفنوع بنانشان __int64 سائيز_t;
#جيڪڏهن_پورو
#وإلا
  تعريفنوع بنانشان صحيح سائيز_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _SSIZE_T_DEFINED
#وصف_ڪريو _SSIZE_T_DEFINED
#وصف_رد ssize_t
#جيڪڏهن_وصف_ٿيل _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((گهڻائي (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#جيڪڏهن_پورو
#وإلا
  تعريفنوع صحيح ssize_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل عدم
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو عدم 0
#وإلا
#وصف_ڪريو عدم ((فراغ *)0)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#وصف_ڪريو _localtime32 localtime
#وصف_ڪريو _difftime32     difftime
#وصف_ڪريو _ctime32        ctime
#وصف_ڪريو _gmtime32       gmtime
#وصف_ڪريو _mktime32       mktime
#وصف_ڪريو _time32 وقت
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TM_DEFINED
#وصف_ڪريو _TM_DEFINED
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
#جيڪڏهن_پورو

#وصف_ڪريو CLOCKS_PER_SEC 1000

  __MINGW_IMPORT صحيح _daylight;
  __MINGW_IMPORT ڊگهو _dstbias;
  __MINGW_IMPORT ڊگهو _timezone;
  __MINGW_IMPORT حرف * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(صحيح *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(ڊگهو *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(ڊگهو *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(سائيز_t *Return_قدر,حرف *بفر_2,سائيز_t سائيز_اندريون_بائيٽون,صحيح اشاريو_2);
  حرف *__cdecl asctime(ثابت بنية tm *_Tm);
  _CRTIMP حرف *__cdecl _ctime32(ثابت __time32_t *وقت_2);
  clock_t __cdecl clock(فراغ);
  _CRTIMP مزدوج __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP بنية tm *__cdecl _gmtime32(ثابت __time32_t *وقت_2);
  _CRTIMP بنية tm *__cdecl _localtime32(ثابت __time32_t *وقت_2);
  سائيز_t __cdecl strftime(حرف *_Buf,سائيز_t سائيز_اندريون_بائيٽون,ثابت حرف *_Format,ثابت بنية tm *_Tm);
  _CRTIMP سائيز_t __cdecl _strftime_l(حرف *_Buf,سائيز_t Max_سائيز,ثابت حرف *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _strdate(حرف *بفر_2);
  _CRTIMP حرف *__cdecl _strtime(حرف *بفر_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *وقت_2);
  _CRTIMP __time32_t __cdecl _mktime32(بنية tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(بنية tm *_Tm);
#إذا defined (_POSIX_) || defined(__GNUC__)
  فراغ __cdecl tzset(فراغ);
#وإلا
  _CRTIMP فراغ __cdecl _tzset(فراغ);
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 64
  مزدوج __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP حرف *__cdecl _ctime64(ثابت __time64_t *وقت_2);
  _CRTIMP بنية tm *__cdecl _gmtime64(ثابت __time64_t *وقت_2);
  _CRTIMP بنية tm *__cdecl _localtime64(ثابت __time64_t *وقت_2);
  _CRTIMP __time64_t __cdecl _mktime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *وقت_2);
#جيڪڏهن_پورو
  بنانشان __cdecl _getsystime(بنية tm *_Tm);
  بنانشان __cdecl _setsystime(بنية tm *_Tm,بنانشان _MilliSec);

#جيڪڏهن_وصف_نه_ٿيل _SIZE_T_DEFINED
#وصف_ڪريو _SIZE_T_DEFINED
#جيڪڏهن_وصف_ٿيل _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بنانشان صحيح سائيز_t __attribute__ ((گهڻائي (DI)));
#وإلا
  تعريفنوع بنانشان __int64 سائيز_t;
#جيڪڏهن_پورو
#وإلا
  تعريفنوع بنانشان ڊگهو سائيز_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _SSIZE_T_DEFINED
#وصف_ڪريو _SSIZE_T_DEFINED
#جيڪڏهن_وصف_ٿيل _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((گهڻائي (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#جيڪڏهن_پورو
#وإلا
  تعريفنوع ڊگهو ssize_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *وقت_2);
  سائيز_t __cdecl wcsftime(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP سائيز_t __cdecl _wcsftime_l(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *بفر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *بفر_2);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *وقت_2);
#جيڪڏهن_پورو

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#وصف_ڪريو _INC_WTIME_INL
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { أرجع _wctime32(وقت_2); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { أرجع _wctime64(وقت_2); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _WTIME_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
مزدوج __cdecl difftime(time_t _Time1,time_t _Time2);
حرف *__cdecl ctime(ثابت time_t *وقت_2);
بنية tm *__cdecl gmtime(ثابت time_t *وقت_2);
بنية tm *__cdecl localtime(ثابت time_t *وقت_2);
بنية tm *__cdecl localtime_r(ثابت time_t *وقت_2,بنية tm *);

time_t __cdecl mktime(بنية tm *_Tm);
time_t __cdecl _mkgmtime(بنية tm *_Tm);
time_t __cdecl وقت(time_t *وقت_2);

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#إذا 0
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime32(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *وقت_2) { أرجع _ctime32(وقت_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *وقت_2) { أرجع _gmtime32(وقت_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *وقت_2) { أرجع _localtime32(وقت_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl وقت(time_t *وقت_2) { أرجع _time32(وقت_2); }
#جيڪڏهن_پورو
#وإلا
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime64(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *وقت_2) { أرجع _ctime64(وقت_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *وقت_2) { أرجع _gmtime64(وقت_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *وقت_2) { أرجع _localtime64(وقت_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl وقت(time_t *وقت_2) { أرجع _time64(وقت_2); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#وصف_ڪريو CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT صحيح daylight;
  __MINGW_IMPORT ڊگهو dstbias;
  __MINGW_IMPORT ڊگهو timezone;
  __MINGW_IMPORT حرف *tzname[2];
  فراغ __cdecl tzset(فراغ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIMEVAL_DEFINED /* also in winsock[2].h */
#وصف_ڪريو _TIMEVAL_DEFINED
بنية timeval {
  ڊگهو tv_sec;
  ڊگهو tv_usec;
};
#وصف_ڪريو timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#وصف_ڪريو timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#وصف_ڪريو timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#جيڪڏهن_پورو /* _TIMEVAL_DEFINED */

#جيڪڏهن_وصف_نه_ٿيل __STRICT_ANSI__
#جيڪڏهن_وصف_نه_ٿيل _TIMEZONE_DEFINED /* also in sys/time.h */
#وصف_ڪريو _TIMEZONE_DEFINED
بنية timezone {
  صحيح tz_minuteswest;
  صحيح tz_dsttime;
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);
#جيڪڏهن_پورو
#جيڪڏهن_پورو /* __STRICT_ANSI__ */

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)

#ضمن <sec_api/time_s.h>

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>

#جيڪڏهن_پورو /* End _TIME_H_ */

