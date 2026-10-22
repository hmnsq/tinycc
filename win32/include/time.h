/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف ویلا_H
#تعریف_کرو ویلا_H

#ضمن <_mingw.h>

#جے_بنا_تعریف _WIN32
#غلطی Only Win32 نشانہ is supported!
#جے_انت

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#جے_انت

#جے_بنا_تعریف _WCHAR_T_DEFINED
#تعریف_کرو _WCHAR_T_DEFINED
  تعريفنوع بنانشانی چھوٹا wchar_t;
#جے_انت

#جے_بنا_تعریف _TIME32_T_DEFINED
#تعریف_کرو _TIME32_T_DEFINED
  تعريفنوع لما __time32_t;
#جے_انت

#جے_بنا_تعریف _TIME64_T_DEFINED
#تعریف_کرو _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٹ >= 64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _time64_t __attribute__ ((منوال (DI)));
#وإلا
  تعريفنوع __int64 __time64_t;
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف ویلا_T_DEFINED
#تعریف_کرو ویلا_T_DEFINED
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _CLOCK_T_DEFINED
#تعریف_کرو _CLOCK_T_DEFINED
  تعريفنوع لما clock_t;
#جے_انت

#جے_بنا_تعریف _SIZE_T_DEFINED
#تعریف_کرو _SIZE_T_DEFINED
#تعریف_رد ناپ_t
#جے_تعریف_شدہ _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بنانشانی صحيح ناپ_t __attribute__ ((منوال (DI)));
#وإلا
  تعريفنوع بنانشانی __int64 ناپ_t;
#جے_انت
#وإلا
  تعريفنوع بنانشانی صحيح ناپ_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _SSIZE_T_DEFINED
#تعریف_کرو _SSIZE_T_DEFINED
#تعریف_رد ssize_t
#جے_تعریف_شدہ _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((منوال (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#جے_انت
#وإلا
  تعريفنوع صحيح ssize_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف عدم
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو عدم 0
#وإلا
#تعریف_کرو عدم ((فراغ *)0)
#جے_انت
#جے_انت

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#تعریف_کرو _localtime32 localtime
#تعریف_کرو _difftime32     difftime
#تعریف_کرو _ctime32        ctime
#تعریف_کرو _gmtime32       gmtime
#تعریف_کرو _mktime32       mktime
#تعریف_کرو _time32 ویلا
#جے_انت

#جے_بنا_تعریف _TM_DEFINED
#تعریف_کرو _TM_DEFINED
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
#جے_انت

#تعریف_کرو CLOCKS_PER_SEC 1000

  __MINGW_IMPORT صحيح _daylight;
  __MINGW_IMPORT لما _dstbias;
  __MINGW_IMPORT لما _timezone;
  __MINGW_IMPORT حرف * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(صحيح *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(لما *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(لما *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(ناپ_t *Return_قدر,حرف *بفر_2,ناپ_t ناپ_وچ_بائٹاں,صحيح اشاریہ_2);
  حرف *__cdecl asctime(ثابت بنية tm *_Tm);
  _CRTIMP حرف *__cdecl _ctime32(ثابت __time32_t *ویلا_2);
  clock_t __cdecl clock(فراغ);
  _CRTIMP مزدوج __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP بنية tm *__cdecl _gmtime32(ثابت __time32_t *ویلا_2);
  _CRTIMP بنية tm *__cdecl _localtime32(ثابت __time32_t *ویلا_2);
  ناپ_t __cdecl strftime(حرف *_Buf,ناپ_t ناپ_وچ_بائٹاں,ثابت حرف *_Format,ثابت بنية tm *_Tm);
  _CRTIMP ناپ_t __cdecl _strftime_l(حرف *_Buf,ناپ_t Max_ناپ,ثابت حرف *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _strdate(حرف *بفر_2);
  _CRTIMP حرف *__cdecl _strtime(حرف *بفر_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *ویلا_2);
  _CRTIMP __time32_t __cdecl _mktime32(بنية tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(بنية tm *_Tm);
#إذا defined (_POSIX_) || defined(__GNUC__)
  فراغ __cdecl tzset(فراغ);
#وإلا
  _CRTIMP فراغ __cdecl _tzset(فراغ);
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 64
  مزدوج __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP حرف *__cdecl _ctime64(ثابت __time64_t *ویلا_2);
  _CRTIMP بنية tm *__cdecl _gmtime64(ثابت __time64_t *ویلا_2);
  _CRTIMP بنية tm *__cdecl _localtime64(ثابت __time64_t *ویلا_2);
  _CRTIMP __time64_t __cdecl _mktime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(بنية tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *ویلا_2);
#جے_انت
  بنانشانی __cdecl _getsystime(بنية tm *_Tm);
  بنانشانی __cdecl _setsystime(بنية tm *_Tm,بنانشانی _MilliSec);

#جے_بنا_تعریف _SIZE_T_DEFINED
#تعریف_کرو _SIZE_T_DEFINED
#جے_تعریف_شدہ _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بنانشانی صحيح ناپ_t __attribute__ ((منوال (DI)));
#وإلا
  تعريفنوع بنانشانی __int64 ناپ_t;
#جے_انت
#وإلا
  تعريفنوع بنانشانی لما ناپ_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _SSIZE_T_DEFINED
#تعریف_کرو _SSIZE_T_DEFINED
#جے_تعریف_شدہ _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((منوال (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#جے_انت
#وإلا
  تعريفنوع لما ssize_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *ویلا_2);
  ناپ_t __cdecl wcsftime(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP ناپ_t __cdecl _wcsftime_l(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *بفر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *بفر_2);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *ویلا_2);
#جے_انت

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#تعریف_کرو _INC_WTIME_INL
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *ویلا_2) { أرجع _wctime32(ویلا_2); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *ویلا_2) { أرجع _wctime64(ویلا_2); }
#جے_انت
#جے_انت

#تعریف_کرو _WTIME_DEFINED
#جے_انت

#جے_بنا_تعریف RC_INVOKED
مزدوج __cdecl difftime(time_t _Time1,time_t _Time2);
حرف *__cdecl ctime(ثابت time_t *ویلا_2);
بنية tm *__cdecl gmtime(ثابت time_t *ویلا_2);
بنية tm *__cdecl localtime(ثابت time_t *ویلا_2);
بنية tm *__cdecl localtime_r(ثابت time_t *ویلا_2,بنية tm *);

time_t __cdecl mktime(بنية tm *_Tm);
time_t __cdecl _mkgmtime(بنية tm *_Tm);
time_t __cdecl ویلا(time_t *ویلا_2);

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#إذا 0
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime32(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *ویلا_2) { أرجع _ctime32(ویلا_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *ویلا_2) { أرجع _gmtime32(ویلا_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *ویلا_2) { أرجع _localtime32(ویلا_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl ویلا(time_t *ویلا_2) { أرجع _time32(ویلا_2); }
#جے_انت
#وإلا
__CRT_INLINE مزدوج __cdecl difftime(time_t _Time1,time_t _Time2) { أرجع _difftime64(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *ویلا_2) { أرجع _ctime64(ویلا_2); }
__CRT_INLINE بنية tm *__cdecl gmtime(ثابت time_t *ویلا_2) { أرجع _gmtime64(ویلا_2); }
__CRT_INLINE بنية tm *__cdecl localtime(ثابت time_t *ویلا_2) { أرجع _localtime64(ویلا_2); }
__CRT_INLINE time_t __cdecl mktime(بنية tm *_Tm) { أرجع _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(بنية tm *_Tm) { أرجع _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl ویلا(time_t *ویلا_2) { أرجع _time64(ویلا_2); }
#جے_انت
#جے_انت

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#تعریف_کرو CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT صحيح daylight;
  __MINGW_IMPORT لما dstbias;
  __MINGW_IMPORT لما timezone;
  __MINGW_IMPORT حرف *tzname[2];
  فراغ __cdecl tzset(فراغ);
#جے_انت

#جے_بنا_تعریف _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کرو _TIMEVAL_DEFINED
بنية timeval {
  لما tv_sec;
  لما tv_usec;
};
#تعریف_کرو timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کرو timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کرو timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#جے_انت /* _TIMEVAL_DEFINED */

#جے_بنا_تعریف __STRICT_ANSI__
#جے_بنا_تعریف _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کرو _TIMEZONE_DEFINED
بنية timezone {
  صحيح tz_minuteswest;
  صحيح tz_dsttime;
};

  خارجي صحيح __cdecl mingw_gettimeofday (بنية timeval *p, بنية timezone *z);
#جے_انت
#جے_انت /* __STRICT_ANSI__ */

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)

#ضمن <sec_api/time_s.h>

/* Adding timespec definition.  */
#ضمن <sys/timeb.h>

#جے_انت /* End _TIME_H_ */

