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

#pragma pack(थप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  प्रकारनिर्देश अचिन्हित लघु ब_अक्षर_प्रकार;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  प्रकारनिर्देश दीर्घ __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#यदि _INTEGRAL_MAX_BITS >= 64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क _time64_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 __time64_t;
#endif
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  प्रकारनिर्देश __time32_t समय_प्रकार;
#अन्यथा
  प्रकारनिर्देश __time64_t समय_प्रकार;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  प्रकारनिर्देश दीर्घ घड़ी_प्रकार;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef माप_प्रकार
#ifdef _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क माप_प्रकार __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारनिर्देश अचिन्हित __int64 माप_प्रकार;
#endif
#अन्यथा
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क माप_प्रकार;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 ssize_t;
#endif
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क ssize_t;
#endif
#endif

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अन्यथा
#define रिक्त ((शून्य *)0)
#endif
#endif

#ifdef _USE_32BIT_TIME_T
#define _localtime32 स_स्थानीय
#define _difftime32     स_अंतर
#define _ctime32        स_समय
#define _gmtime32       स_जमट
#define _mktime32       स_गढ़ो
#define _time32 समय
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  संरचना पंचांग {
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
  __MINGW_IMPORT दीर्घ _dstbias;
  __MINGW_IMPORT दीर्घ _timezone;
  __MINGW_IMPORT वर्ण * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(पूर्णाङ्क *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(दीर्घ *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(दीर्घ *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(माप_प्रकार *Return_मान,वर्ण *_Buffer,माप_प्रकार _SizeInBytes,पूर्णाङ्क _Index);
  वर्ण *__cdecl समय_ठीक(अचर संरचना पंचांग *_Tm);
  _CRTIMP वर्ण *__cdecl _ctime32(अचर __time32_t *_Time);
  घड़ी_प्रकार __cdecl घड़ी(शून्य);
  _CRTIMP द्विगुण __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP संरचना पंचांग *__cdecl _gmtime32(अचर __time32_t *_Time);
  _CRTIMP संरचना पंचांग *__cdecl _localtime32(अचर __time32_t *_Time);
  माप_प्रकार __cdecl स_माला(वर्ण *_Buf,माप_प्रकार _SizeInBytes,अचर वर्ण *_Format,अचर संरचना पंचांग *_Tm);
  _CRTIMP माप_प्रकार __cdecl _strftime_l(वर्ण *_Buf,माप_प्रकार _Max_size,अचर वर्ण *_Format,अचर संरचना पंचांग *_Tm,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _strdate(वर्ण *_Buffer);
  _CRTIMP वर्ण *__cdecl _strtime(वर्ण *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(संरचना पंचांग *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(संरचना पंचांग *_Tm);
#यदि defined (_POSIX_) || defined(__GNUC__)
  शून्य __cdecl tzset(शून्य);
#अन्यथा
  _CRTIMP शून्य __cdecl _tzset(शून्य);
#endif

#यदि _INTEGRAL_MAX_BITS >= 64
  द्विगुण __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP वर्ण *__cdecl _ctime64(अचर __time64_t *_Time);
  _CRTIMP संरचना पंचांग *__cdecl _gmtime64(अचर __time64_t *_Time);
  _CRTIMP संरचना पंचांग *__cdecl _localtime64(अचर __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(संरचना पंचांग *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(संरचना पंचांग *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  अचिन्हित __cdecl _getsystime(संरचना पंचांग *_Tm);
  अचिन्हित __cdecl _setsystime(संरचना पंचांग *_Tm,अचिन्हित _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क माप_प्रकार __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारनिर्देश अचिन्हित __int64 माप_प्रकार;
#endif
#अन्यथा
  प्रकारनिर्देश अचिन्हित दीर्घ माप_प्रकार;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 ssize_t;
#endif
#अन्यथा
  प्रकारनिर्देश दीर्घ ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wasctime(अचर संरचना पंचांग *_Tm);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime32(अचर __time32_t *_Time);
  माप_प्रकार __cdecl wcsftime(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,अचर संरचना पंचांग *_Tm);
  _CRTIMP माप_प्रकार __cdecl _wcsftime_l(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,अचर संरचना पंचांग *_Tm,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrdate(ब_अक्षर_प्रकार *_Buffer);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrtime(ब_अक्षर_प्रकार *_Buffer);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime64(अचर __time64_t *_Time);
#endif

#यदि !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(अचर समय_प्रकार *_Time) { फर्काऊ _wctime32(_Time); }
#अन्यथा
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(अचर समय_प्रकार *_Time) { फर्काऊ _wctime64(_Time); }
#endif
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
द्विगुण __cdecl स_अंतर(समय_प्रकार _Time1,समय_प्रकार _Time2);
वर्ण *__cdecl स_समय(अचर समय_प्रकार *_Time);
संरचना पंचांग *__cdecl स_जमट(अचर समय_प्रकार *_Time);
संरचना पंचांग *__cdecl स_स्थानीय(अचर समय_प्रकार *_Time);
संरचना पंचांग *__cdecl localtime_r(अचर समय_प्रकार *_Time,संरचना पंचांग *);

समय_प्रकार __cdecl स_गढ़ो(संरचना पंचांग *_Tm);
समय_प्रकार __cdecl _mkgmtime(संरचना पंचांग *_Tm);
समय_प्रकार __cdecl समय(समय_प्रकार *_Time);

#ifdef _USE_32BIT_TIME_T
#यदि 0
__CRT_INLINE द्विगुण __cdecl स_अंतर(समय_प्रकार _Time1,समय_प्रकार _Time2) { फर्काऊ _difftime32(_Time1,_Time2); }
__CRT_INLINE वर्ण *__cdecl स_समय(अचर समय_प्रकार *_Time) { फर्काऊ _ctime32(_Time); }
__CRT_INLINE संरचना पंचांग *__cdecl स_जमट(अचर समय_प्रकार *_Time) { फर्काऊ _gmtime32(_Time); }
__CRT_INLINE संरचना पंचांग *__cdecl स_स्थानीय(अचर समय_प्रकार *_Time) { फर्काऊ _localtime32(_Time); }
__CRT_INLINE समय_प्रकार __cdecl स_गढ़ो(संरचना पंचांग *_Tm) { फर्काऊ _mktime32(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl _mkgmtime(संरचना पंचांग *_Tm) { फर्काऊ _mkgmtime32(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl समय(समय_प्रकार *_Time) { फर्काऊ _time32(_Time); }
#endif
#अन्यथा
__CRT_INLINE द्विगुण __cdecl स_अंतर(समय_प्रकार _Time1,समय_प्रकार _Time2) { फर्काऊ _difftime64(_Time1,_Time2); }
__CRT_INLINE वर्ण *__cdecl स_समय(अचर समय_प्रकार *_Time) { फर्काऊ _ctime64(_Time); }
__CRT_INLINE संरचना पंचांग *__cdecl स_जमट(अचर समय_प्रकार *_Time) { फर्काऊ _gmtime64(_Time); }
__CRT_INLINE संरचना पंचांग *__cdecl स_स्थानीय(अचर समय_प्रकार *_Time) { फर्काऊ _localtime64(_Time); }
__CRT_INLINE समय_प्रकार __cdecl स_गढ़ो(संरचना पंचांग *_Tm) { फर्काऊ _mktime64(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl _mkgmtime(संरचना पंचांग *_Tm) { फर्काऊ _mkgmtime64(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl समय(समय_प्रकार *_Time) { फर्काऊ _time64(_Time); }
#endif
#endif

#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
#define घड़ी_टिक CLOCKS_PER_SEC

  __MINGW_IMPORT पूर्णाङ्क daylight;
  __MINGW_IMPORT दीर्घ dstbias;
  __MINGW_IMPORT दीर्घ timezone;
  __MINGW_IMPORT वर्ण *tzname[2];
  शून्य __cdecl tzset(शून्य);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
संरचना timeval {
  दीर्घ tv_sec;
  दीर्घ tv_usec;
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

#pragma pack(झिक)

#अन्तर्भाव <sec_api/time_s.h>

/* Adding timespec definition.  */
#अन्तर्भाव <sys/timeb.h>

#endif /* End _TIME_H_ */

