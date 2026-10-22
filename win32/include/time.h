/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ وقت_H
#تعریف_کرو وقت_H

#شامل <_mingw.h>

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCHAR_T_DEFINED
#تعریف_کرو _WCHAR_T_DEFINED
  قسمتعریف غیرعلامتی مختصر wchar_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME32_T_DEFINED
#تعریف_کرو _TIME32_T_DEFINED
  قسمتعریف طویل __time32_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME64_T_DEFINED
#تعریف_کرو _TIME64_T_DEFINED
#اگر INTEGRAL_MAX_بٹ >= 64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف صحیح _time64_t __attribute__ ((منوال (DI)));
#ورنہ
  قسمتعریف __int64 __time64_t;
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ وقت_T_DEFINED
#تعریف_کرو وقت_T_DEFINED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
  قسمتعریف __time32_t time_t;
#ورنہ
  قسمتعریف __time64_t time_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CLOCK_T_DEFINED
#تعریف_کرو _CLOCK_T_DEFINED
  قسمتعریف طویل clock_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _SIZE_T_DEFINED
#تعریف_کرو _SIZE_T_DEFINED
#تعریف_منسوخ سائز_t
#اگر_تعریف_شدہ _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف غیرعلامتی صحیح سائز_t __attribute__ ((منوال (DI)));
#ورنہ
  قسمتعریف غیرعلامتی __int64 سائز_t;
#اگر_ختم
#ورنہ
  قسمتعریف غیرعلامتی صحیح سائز_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _SSIZE_T_DEFINED
#تعریف_کرو _SSIZE_T_DEFINED
#تعریف_منسوخ ssize_t
#اگر_تعریف_شدہ _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف صحیح ssize_t __attribute__ ((منوال (DI)));
#ورنہ
  قسمتعریف __int64 ssize_t;
#اگر_ختم
#ورنہ
  قسمتعریف صحیح ssize_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#تعریف_کرو _localtime32 localtime
#تعریف_کرو _difftime32     difftime
#تعریف_کرو _ctime32        ctime
#تعریف_کرو _gmtime32       gmtime
#تعریف_کرو _mktime32       mktime
#تعریف_کرو _time32 وقت
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TM_DEFINED
#تعریف_کرو _TM_DEFINED
  ساخت tm {
    صحیح tm_sec;
    صحیح tm_min;
    صحیح tm_hour;
    صحیح tm_mday;
    صحیح tm_mon;
    صحیح tm_year;
    صحیح tm_wday;
    صحیح tm_yday;
    صحیح tm_isdst;
  };
#اگر_ختم

#تعریف_کرو CLOCKS_PER_SEC 1000

  __MINGW_IMPORT صحیح _daylight;
  __MINGW_IMPORT طویل _dstbias;
  __MINGW_IMPORT طویل _timezone;
  __MINGW_IMPORT حرف * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(صحیح *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(طویل *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(طویل *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(سائز_t *Return_قدر,حرف *بفر_2,سائز_t سائز_اندر_بائٹیں,صحیح اشاریہ_2);
  حرف *__cdecl asctime(ثابت ساخت tm *_Tm);
  _CRTIMP حرف *__cdecl _ctime32(ثابت __time32_t *وقت_2);
  clock_t __cdecl clock(خالی);
  _CRTIMP دوہرا __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP ساخت tm *__cdecl _gmtime32(ثابت __time32_t *وقت_2);
  _CRTIMP ساخت tm *__cdecl _localtime32(ثابت __time32_t *وقت_2);
  سائز_t __cdecl strftime(حرف *_Buf,سائز_t سائز_اندر_بائٹیں,ثابت حرف *_Format,ثابت ساخت tm *_Tm);
  _CRTIMP سائز_t __cdecl _strftime_l(حرف *_Buf,سائز_t Max_سائز,ثابت حرف *_Format,ثابت ساخت tm *_Tm,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _strdate(حرف *بفر_2);
  _CRTIMP حرف *__cdecl _strtime(حرف *بفر_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *وقت_2);
  _CRTIMP __time32_t __cdecl _mktime32(ساخت tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(ساخت tm *_Tm);
#اگر defined (_POSIX_) || defined(__GNUC__)
  خالی __cdecl tzset(خالی);
#ورنہ
  _CRTIMP خالی __cdecl _tzset(خالی);
#اگر_ختم

#اگر INTEGRAL_MAX_بٹ >= 64
  دوہرا __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP حرف *__cdecl _ctime64(ثابت __time64_t *وقت_2);
  _CRTIMP ساخت tm *__cdecl _gmtime64(ثابت __time64_t *وقت_2);
  _CRTIMP ساخت tm *__cdecl _localtime64(ثابت __time64_t *وقت_2);
  _CRTIMP __time64_t __cdecl _mktime64(ساخت tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(ساخت tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *وقت_2);
#اگر_ختم
  غیرعلامتی __cdecl _getsystime(ساخت tm *_Tm);
  غیرعلامتی __cdecl _setsystime(ساخت tm *_Tm,غیرعلامتی _MilliSec);

#اگر_غیر_تعریف_شدہ _SIZE_T_DEFINED
#تعریف_کرو _SIZE_T_DEFINED
#اگر_تعریف_شدہ _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف غیرعلامتی صحیح سائز_t __attribute__ ((منوال (DI)));
#ورنہ
  قسمتعریف غیرعلامتی __int64 سائز_t;
#اگر_ختم
#ورنہ
  قسمتعریف غیرعلامتی طویل سائز_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _SSIZE_T_DEFINED
#تعریف_کرو _SSIZE_T_DEFINED
#اگر_تعریف_شدہ _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف صحیح ssize_t __attribute__ ((منوال (DI)));
#ورنہ
  قسمتعریف __int64 ssize_t;
#اگر_ختم
#ورنہ
  قسمتعریف طویل ssize_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ثابت ساخت tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *وقت_2);
  سائز_t __cdecl wcsftime(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,ثابت ساخت tm *_Tm);
  _CRTIMP سائز_t __cdecl _wcsftime_l(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,ثابت ساخت tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *بفر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *بفر_2);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *وقت_2);
#اگر_ختم

#اگر !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#تعریف_کرو _INC_WTIME_INL
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { واپس _wctime32(وقت_2); }
#ورنہ
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { واپس _wctime64(وقت_2); }
#اگر_ختم
#اگر_ختم

#تعریف_کرو _WTIME_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ RC_INVOKED
دوہرا __cdecl difftime(time_t _Time1,time_t _Time2);
حرف *__cdecl ctime(ثابت time_t *وقت_2);
ساخت tm *__cdecl gmtime(ثابت time_t *وقت_2);
ساخت tm *__cdecl localtime(ثابت time_t *وقت_2);
ساخت tm *__cdecl localtime_r(ثابت time_t *وقت_2,ساخت tm *);

time_t __cdecl mktime(ساخت tm *_Tm);
time_t __cdecl _mkgmtime(ساخت tm *_Tm);
time_t __cdecl وقت(time_t *وقت_2);

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#اگر 0
__CRT_INLINE دوہرا __cdecl difftime(time_t _Time1,time_t _Time2) { واپس _difftime32(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *وقت_2) { واپس _ctime32(وقت_2); }
__CRT_INLINE ساخت tm *__cdecl gmtime(ثابت time_t *وقت_2) { واپس _gmtime32(وقت_2); }
__CRT_INLINE ساخت tm *__cdecl localtime(ثابت time_t *وقت_2) { واپس _localtime32(وقت_2); }
__CRT_INLINE time_t __cdecl mktime(ساخت tm *_Tm) { واپس _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ساخت tm *_Tm) { واپس _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl وقت(time_t *وقت_2) { واپس _time32(وقت_2); }
#اگر_ختم
#ورنہ
__CRT_INLINE دوہرا __cdecl difftime(time_t _Time1,time_t _Time2) { واپس _difftime64(_Time1,_Time2); }
__CRT_INLINE حرف *__cdecl ctime(ثابت time_t *وقت_2) { واپس _ctime64(وقت_2); }
__CRT_INLINE ساخت tm *__cdecl gmtime(ثابت time_t *وقت_2) { واپس _gmtime64(وقت_2); }
__CRT_INLINE ساخت tm *__cdecl localtime(ثابت time_t *وقت_2) { واپس _localtime64(وقت_2); }
__CRT_INLINE time_t __cdecl mktime(ساخت tm *_Tm) { واپس _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(ساخت tm *_Tm) { واپس _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl وقت(time_t *وقت_2) { واپس _time64(وقت_2); }
#اگر_ختم
#اگر_ختم

#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
#تعریف_کرو CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT صحیح daylight;
  __MINGW_IMPORT طویل dstbias;
  __MINGW_IMPORT طویل timezone;
  __MINGW_IMPORT حرف *tzname[2];
  خالی __cdecl tzset(خالی);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کرو _TIMEVAL_DEFINED
ساخت timeval {
  طویل tv_sec;
  طویل tv_usec;
};
#تعریف_کرو timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کرو timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کرو timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#اگر_ختم /* _TIMEVAL_DEFINED */

#اگر_غیر_تعریف_شدہ __STRICT_ANSI__
#اگر_غیر_تعریف_شدہ _TIMEZONE_DEFINED /* also in sys/time.h */
#تعریف_کرو _TIMEZONE_DEFINED
ساخت timezone {
  صحیح tz_minuteswest;
  صحیح tz_dsttime;
};

  خارجی صحیح __cdecl mingw_gettimeofday (ساخت timeval *p, ساخت timezone *z);
#اگر_ختم
#اگر_ختم /* __STRICT_ANSI__ */

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)

#شامل <sec_api/time_s.h>

/* Adding timespec definition.  */
#شامل <sys/timeb.h>

#اگر_ختم /* End _TIME_H_ */

