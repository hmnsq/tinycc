/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _TIME_H_
#परिभाषय _TIME_H_

#अन्तर्भाव <_mingw.h>

#यदि_अपरिभाषितम् _WIN32
#दोषः Only Win32 target is supported!
#यदि_अन्तः

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRTIMP
#परिभाषय _CRTIMP __declspec(dllimport)
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCHAR_T_DEFINED
#परिभाषय _WCHAR_T_DEFINED
  प्रकारनिर्देश अचिह्नित ह्रस्व wchar_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME32_T_DEFINED
#परिभाषय _TIME32_T_DEFINED
  प्रकारनिर्देश दीर्घ __time32_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME64_T_DEFINED
#परिभाषय _TIME64_T_DEFINED
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क _time64_t __attribute__ ((बहुलकम् (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 __time64_t;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME_T_DEFINED
#परिभाषय _TIME_T_DEFINED
#यदि_परिभाषितम् _USE_32BIT_TIME_T
  प्रकारनिर्देश __time32_t time_t;
#अन्यथा
  प्रकारनिर्देश __time64_t time_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _CLOCK_T_DEFINED
#परिभाषय _CLOCK_T_DEFINED
  प्रकारनिर्देश दीर्घ clock_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _SIZE_T_DEFINED
#परिभाषय _SIZE_T_DEFINED
#अपरिभाषय आकार_t
#यदि_परिभाषितम् _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क आकार_t __attribute__ ((बहुलकम् (DI)));
#अन्यथा
  प्रकारनिर्देश अचिह्नित __int64 आकार_t;
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क आकार_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _SSIZE_T_DEFINED
#परिभाषय _SSIZE_T_DEFINED
#अपरिभाषय ssize_t
#यदि_परिभाषितम् _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((बहुलकम् (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 ssize_t;
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क ssize_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#परिभाषय _localtime32 localtime
#परिभाषय _difftime32     difftime
#परिभाषय _ctime32        ctime
#परिभाषय _gmtime32       gmtime
#परिभाषय _mktime32       mktime
#परिभाषय _time32 time
#यदि_अन्तः

#यदि_अपरिभाषितम् _TM_DEFINED
#परिभाषय _TM_DEFINED
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
#यदि_अन्तः

#परिभाषय CLOCKS_PER_SEC 1000

  __MINGW_IMPORT पूर्णाङ्क _daylight;
  __MINGW_IMPORT दीर्घ _dstbias;
  __MINGW_IMPORT दीर्घ _timezone;
  __MINGW_IMPORT वर्ण * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(पूर्णाङ्क *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(दीर्घ *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(दीर्घ *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(आकार_t *Return_मानम्,वर्ण *बफर_2,आकार_t आकार_अन्तर्_अष्टकानि,पूर्णाङ्क सूचकांक_2);
  वर्ण *__cdecl asctime(ध्रुव संरचना tm *_Tm);
  _CRTIMP वर्ण *__cdecl _ctime32(ध्रुव __time32_t *_Time);
  clock_t __cdecl clock(शून्य);
  _CRTIMP द्विगुण __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP संरचना tm *__cdecl _gmtime32(ध्रुव __time32_t *_Time);
  _CRTIMP संरचना tm *__cdecl _localtime32(ध्रुव __time32_t *_Time);
  आकार_t __cdecl strftime(वर्ण *_Buf,आकार_t आकार_अन्तर्_अष्टकानि,ध्रुव वर्ण *_Format,ध्रुव संरचना tm *_Tm);
  _CRTIMP आकार_t __cdecl _strftime_l(वर्ण *_Buf,आकार_t Max_आकार,ध्रुव वर्ण *_Format,ध्रुव संरचना tm *_Tm,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _strdate(वर्ण *बफर_2);
  _CRTIMP वर्ण *__cdecl _strtime(वर्ण *बफर_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(संरचना tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(संरचना tm *_Tm);
#यदि defined (_POSIX_) || defined(__GNUC__)
  शून्य __cdecl tzset(शून्य);
#अन्यथा
  _CRTIMP शून्य __cdecl _tzset(शून्य);
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  द्विगुण __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP वर्ण *__cdecl _ctime64(ध्रुव __time64_t *_Time);
  _CRTIMP संरचना tm *__cdecl _gmtime64(ध्रुव __time64_t *_Time);
  _CRTIMP संरचना tm *__cdecl _localtime64(ध्रुव __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(संरचना tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(संरचना tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#यदि_अन्तः
  अचिह्नित __cdecl _getsystime(संरचना tm *_Tm);
  अचिह्नित __cdecl _setsystime(संरचना tm *_Tm,अचिह्नित _MilliSec);

#यदि_अपरिभाषितम् _SIZE_T_DEFINED
#परिभाषय _SIZE_T_DEFINED
#यदि_परिभाषितम् _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क आकार_t __attribute__ ((बहुलकम् (DI)));
#अन्यथा
  प्रकारनिर्देश अचिह्नित __int64 आकार_t;
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश अचिह्नित दीर्घ आकार_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _SSIZE_T_DEFINED
#परिभाषय _SSIZE_T_DEFINED
#यदि_परिभाषितम् _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((बहुलकम् (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 ssize_t;
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश दीर्घ ssize_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(ध्रुव संरचना tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ध्रुव __time32_t *_Time);
  आकार_t __cdecl wcsftime(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm);
  _CRTIMP आकार_t __cdecl _wcsftime_l(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *बफर_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *बफर_2);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ध्रुव __time64_t *_Time);
#यदि_अन्तः

#यदि !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#परिभाषय _INC_WTIME_INL
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { प्रत्यागम _wctime32(_Time); }
#अन्यथा
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { प्रत्यागम _wctime64(_Time); }
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _WTIME_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् RC_INVOKED
द्विगुण __cdecl difftime(time_t _Time1,time_t _Time2);
वर्ण *__cdecl ctime(ध्रुव time_t *_Time);
संरचना tm *__cdecl gmtime(ध्रुव time_t *_Time);
संरचना tm *__cdecl localtime(ध्रुव time_t *_Time);
संरचना tm *__cdecl localtime_r(ध्रुव time_t *_Time,संरचना tm *);

time_t __cdecl mktime(संरचना tm *_Tm);
time_t __cdecl _mkgmtime(संरचना tm *_Tm);
time_t __cdecl time(time_t *_Time);

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#यदि 0
__CRT_INLINE द्विगुण __cdecl difftime(time_t _Time1,time_t _Time2) { प्रत्यागम _difftime32(_Time1,_Time2); }
__CRT_INLINE वर्ण *__cdecl ctime(ध्रुव time_t *_Time) { प्रत्यागम _ctime32(_Time); }
__CRT_INLINE संरचना tm *__cdecl gmtime(ध्रुव time_t *_Time) { प्रत्यागम _gmtime32(_Time); }
__CRT_INLINE संरचना tm *__cdecl localtime(ध्रुव time_t *_Time) { प्रत्यागम _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(संरचना tm *_Tm) { प्रत्यागम _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(संरचना tm *_Tm) { प्रत्यागम _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { प्रत्यागम _time32(_Time); }
#यदि_अन्तः
#अन्यथा
__CRT_INLINE द्विगुण __cdecl difftime(time_t _Time1,time_t _Time2) { प्रत्यागम _difftime64(_Time1,_Time2); }
__CRT_INLINE वर्ण *__cdecl ctime(ध्रुव time_t *_Time) { प्रत्यागम _ctime64(_Time); }
__CRT_INLINE संरचना tm *__cdecl gmtime(ध्रुव time_t *_Time) { प्रत्यागम _gmtime64(_Time); }
__CRT_INLINE संरचना tm *__cdecl localtime(ध्रुव time_t *_Time) { प्रत्यागम _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(संरचना tm *_Tm) { प्रत्यागम _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(संरचना tm *_Tm) { प्रत्यागम _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { प्रत्यागम _time64(_Time); }
#यदि_अन्तः
#यदि_अन्तः

#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
#परिभाषय CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT पूर्णाङ्क daylight;
  __MINGW_IMPORT दीर्घ dstbias;
  __MINGW_IMPORT दीर्घ timezone;
  __MINGW_IMPORT वर्ण *tzname[2];
  शून्य __cdecl tzset(शून्य);
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIMEVAL_DEFINED /* also in winsock[2].h */
#परिभाषय _TIMEVAL_DEFINED
संरचना timeval {
  दीर्घ tv_sec;
  दीर्घ tv_usec;
};
#परिभाषय timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#परिभाषय timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#परिभाषय timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#यदि_अन्तः /* _TIMEVAL_DEFINED */

#यदि_अपरिभाषितम् __STRICT_ANSI__
#यदि_अपरिभाषितम् _TIMEZONE_DEFINED /* also in sys/time.h */
#परिभाषय _TIMEZONE_DEFINED
संरचना timezone {
  पूर्णाङ्क tz_minuteswest;
  पूर्णाङ्क tz_dsttime;
};

  बाह्य पूर्णाङ्क __cdecl mingw_gettimeofday (संरचना timeval *p, संरचना timezone *z);
#यदि_अन्तः
#यदि_अन्तः /* __STRICT_ANSI__ */

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)

#अन्तर्भाव <sec_api/time_s.h>

/* Adding timespec definition.  */
#अन्तर्भाव <sys/timeb.h>

#यदि_अन्तः /* End _TIME_H_ */

