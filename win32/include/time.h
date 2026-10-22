/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _TIME_H_
#घोषणा _TIME_H_

#समावेश <_mingw.h>

#अगर_अघोषित _WIN32
#त्रुटि Only Win32 target is supported!
#पूर्ण_अगर

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _CRTIMP
#घोषणा _CRTIMP __declspec(dllimport)
#पूर्ण_अगर

#अगर_अघोषित _WCHAR_T_DEFINED
#घोषणा _WCHAR_T_DEFINED
  प्रकार अचिन्हित लघु ब_अक्षर_प्रकार;
#पूर्ण_अगर

#अगर_अघोषित _TIME32_T_DEFINED
#घोषणा _TIME32_T_DEFINED
  प्रकार दीर्घ __time32_t;
#पूर्ण_अगर

#अगर_अघोषित _TIME64_T_DEFINED
#घोषणा _TIME64_T_DEFINED
#अगर _INTEGRAL_MAX_BITS >= 64
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार पूर्णांक _time64_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकार __int64 __time64_t;
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TIME_T_DEFINED
#घोषणा _TIME_T_DEFINED
#अगर_घोषित _USE_32BIT_TIME_T
  प्रकार __time32_t समय_प्रकार;
#अन्यथा
  प्रकार __time64_t समय_प्रकार;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _CLOCK_T_DEFINED
#घोषणा _CLOCK_T_DEFINED
  प्रकार दीर्घ घड़ी_प्रकार;
#पूर्ण_अगर

#अगर_अघोषित _SIZE_T_DEFINED
#घोषणा _SIZE_T_DEFINED
#अघोषित माप_प्रकार
#अगर_घोषित _WIN64
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार अचिन्हित पूर्णांक माप_प्रकार __attribute__ ((mode (DI)));
#अन्यथा
  प्रकार अचिन्हित __int64 माप_प्रकार;
#पूर्ण_अगर
#अन्यथा
  प्रकार अचिन्हित पूर्णांक माप_प्रकार;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _SSIZE_T_DEFINED
#घोषणा _SSIZE_T_DEFINED
#अघोषित ssize_t
#अगर_घोषित _WIN64
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार पूर्णांक ssize_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकार __int64 ssize_t;
#पूर्ण_अगर
#अन्यथा
  प्रकार पूर्णांक ssize_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित _USE_32BIT_TIME_T
#घोषणा _localtime32 स_स्थानीय
#घोषणा _difftime32     स_अंतर
#घोषणा _ctime32        स_समय
#घोषणा _gmtime32       स_जमट
#घोषणा _mktime32       स_गढ़ो
#घोषणा _time32 समय
#पूर्ण_अगर

#अगर_अघोषित _TM_DEFINED
#घोषणा _TM_DEFINED
  काष्ठा पंचांग {
    पूर्णांक tm_sec;
    पूर्णांक tm_min;
    पूर्णांक tm_hour;
    पूर्णांक tm_mday;
    पूर्णांक tm_mon;
    पूर्णांक tm_year;
    पूर्णांक tm_wday;
    पूर्णांक tm_yday;
    पूर्णांक tm_isdst;
  };
#पूर्ण_अगर

#घोषणा CLOCKS_PER_SEC 1000

  __MINGW_IMPORT पूर्णांक _daylight;
  __MINGW_IMPORT दीर्घ _dstbias;
  __MINGW_IMPORT दीर्घ _timezone;
  __MINGW_IMPORT अक्षर * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(पूर्णांक *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(दीर्घ *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(दीर्घ *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(माप_प्रकार *Return_मूल्य,अक्षर *बफर_2,माप_प्रकार आकार_In_Bytes,पूर्णांक सूचकांक_2);
  अक्षर *__cdecl समय_ठीक(स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP अक्षर *__cdecl _ctime32(स्थिर __time32_t *_Time);
  घड़ी_प्रकार __cdecl घड़ी(व्योम);
  _CRTIMP द्विगुन __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP काष्ठा पंचांग *__cdecl _gmtime32(स्थिर __time32_t *_Time);
  _CRTIMP काष्ठा पंचांग *__cdecl _localtime32(स्थिर __time32_t *_Time);
  माप_प्रकार __cdecl स_माला(अक्षर *_Buf,माप_प्रकार आकार_In_Bytes,स्थिर अक्षर *_Format,स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP माप_प्रकार __cdecl _strftime_l(अक्षर *_Buf,माप_प्रकार Max_आकार,स्थिर अक्षर *_Format,स्थिर काष्ठा पंचांग *_Tm,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _strdate(अक्षर *बफर_2);
  _CRTIMP अक्षर *__cdecl _strtime(अक्षर *बफर_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(काष्ठा पंचांग *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(काष्ठा पंचांग *_Tm);
#अगर defined (_POSIX_) || defined(__GNUC__)
  व्योम __cdecl tzset(व्योम);
#अन्यथा
  _CRTIMP व्योम __cdecl _tzset(व्योम);
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 64
  द्विगुन __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP अक्षर *__cdecl _ctime64(स्थिर __time64_t *_Time);
  _CRTIMP काष्ठा पंचांग *__cdecl _gmtime64(स्थिर __time64_t *_Time);
  _CRTIMP काष्ठा पंचांग *__cdecl _localtime64(स्थिर __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(काष्ठा पंचांग *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(काष्ठा पंचांग *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#पूर्ण_अगर
  अचिन्हित __cdecl _getsystime(काष्ठा पंचांग *_Tm);
  अचिन्हित __cdecl _setsystime(काष्ठा पंचांग *_Tm,अचिन्हित _MilliSec);

#अगर_अघोषित _SIZE_T_DEFINED
#घोषणा _SIZE_T_DEFINED
#अगर_घोषित _WIN64
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार अचिन्हित पूर्णांक माप_प्रकार __attribute__ ((mode (DI)));
#अन्यथा
  प्रकार अचिन्हित __int64 माप_प्रकार;
#पूर्ण_अगर
#अन्यथा
  प्रकार अचिन्हित दीर्घ माप_प्रकार;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _SSIZE_T_DEFINED
#घोषणा _SSIZE_T_DEFINED
#अगर_घोषित _WIN64
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार पूर्णांक ssize_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकार __int64 ssize_t;
#पूर्ण_अगर
#अन्यथा
  प्रकार दीर्घ ssize_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WTIME_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wasctime(स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime32(स्थिर __time32_t *_Time);
  माप_प्रकार __cdecl wcsftime(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP माप_प्रकार __cdecl _wcsftime_l(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,स्थिर काष्ठा पंचांग *_Tm,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrdate(ब_अक्षर_प्रकार *बफर_2);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrtime(ब_अक्षर_प्रकार *बफर_2);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime64(स्थिर __time64_t *_Time);
#पूर्ण_अगर

#अगर !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#घोषणा _INC_WTIME_INL
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(स्थिर समय_प्रकार *_Time) { वापस _wctime32(_Time); }
#अन्यथा
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(स्थिर समय_प्रकार *_Time) { वापस _wctime64(_Time); }
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _WTIME_DEFINED
#पूर्ण_अगर

#अगर_अघोषित RC_INVOKED
द्विगुन __cdecl स_अंतर(समय_प्रकार _Time1,समय_प्रकार _Time2);
अक्षर *__cdecl स_समय(स्थिर समय_प्रकार *_Time);
काष्ठा पंचांग *__cdecl स_जमट(स्थिर समय_प्रकार *_Time);
काष्ठा पंचांग *__cdecl स_स्थानीय(स्थिर समय_प्रकार *_Time);
काष्ठा पंचांग *__cdecl localtime_r(स्थिर समय_प्रकार *_Time,काष्ठा पंचांग *);

समय_प्रकार __cdecl स_गढ़ो(काष्ठा पंचांग *_Tm);
समय_प्रकार __cdecl _mkgmtime(काष्ठा पंचांग *_Tm);
समय_प्रकार __cdecl समय(समय_प्रकार *_Time);

#अगर_घोषित _USE_32BIT_TIME_T
#अगर 0
__CRT_INLINE द्विगुन __cdecl स_अंतर(समय_प्रकार _Time1,समय_प्रकार _Time2) { वापस _difftime32(_Time1,_Time2); }
__CRT_INLINE अक्षर *__cdecl स_समय(स्थिर समय_प्रकार *_Time) { वापस _ctime32(_Time); }
__CRT_INLINE काष्ठा पंचांग *__cdecl स_जमट(स्थिर समय_प्रकार *_Time) { वापस _gmtime32(_Time); }
__CRT_INLINE काष्ठा पंचांग *__cdecl स_स्थानीय(स्थिर समय_प्रकार *_Time) { वापस _localtime32(_Time); }
__CRT_INLINE समय_प्रकार __cdecl स_गढ़ो(काष्ठा पंचांग *_Tm) { वापस _mktime32(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl _mkgmtime(काष्ठा पंचांग *_Tm) { वापस _mkgmtime32(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl समय(समय_प्रकार *_Time) { वापस _time32(_Time); }
#पूर्ण_अगर
#अन्यथा
__CRT_INLINE द्विगुन __cdecl स_अंतर(समय_प्रकार _Time1,समय_प्रकार _Time2) { वापस _difftime64(_Time1,_Time2); }
__CRT_INLINE अक्षर *__cdecl स_समय(स्थिर समय_प्रकार *_Time) { वापस _ctime64(_Time); }
__CRT_INLINE काष्ठा पंचांग *__cdecl स_जमट(स्थिर समय_प्रकार *_Time) { वापस _gmtime64(_Time); }
__CRT_INLINE काष्ठा पंचांग *__cdecl स_स्थानीय(स्थिर समय_प्रकार *_Time) { वापस _localtime64(_Time); }
__CRT_INLINE समय_प्रकार __cdecl स_गढ़ो(काष्ठा पंचांग *_Tm) { वापस _mktime64(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl _mkgmtime(काष्ठा पंचांग *_Tm) { वापस _mkgmtime64(_Tm); }
__CRT_INLINE समय_प्रकार __cdecl समय(समय_प्रकार *_Time) { वापस _time64(_Time); }
#पूर्ण_अगर
#पूर्ण_अगर

#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
#घोषणा घड़ी_टिक CLOCKS_PER_SEC

  __MINGW_IMPORT पूर्णांक daylight;
  __MINGW_IMPORT दीर्घ dstbias;
  __MINGW_IMPORT दीर्घ timezone;
  __MINGW_IMPORT अक्षर *tzname[2];
  व्योम __cdecl tzset(व्योम);
#पूर्ण_अगर

#अगर_अघोषित _TIMEVAL_DEFINED /* also in winsock[2].h */
#घोषणा _TIMEVAL_DEFINED
काष्ठा timeval {
  दीर्घ tv_sec;
  दीर्घ tv_usec;
};
#घोषणा timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#घोषणा timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#घोषणा timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#पूर्ण_अगर /* _TIMEVAL_DEFINED */

#अगर_अघोषित __STRICT_ANSI__
#अगर_अघोषित _TIMEZONE_DEFINED /* also in sys/time.h */
#घोषणा _TIMEZONE_DEFINED
काष्ठा timezone {
  पूर्णांक tz_minuteswest;
  पूर्णांक tz_dsttime;
};

  बाह्य पूर्णांक __cdecl mingw_gettimeofday (काष्ठा timeval *p, काष्ठा timezone *z);
#पूर्ण_अगर
#पूर्ण_अगर /* __STRICT_ANSI__ */

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)

#समावेश <sec_api/time_s.h>

/* Adding timespec definition.  */
#समावेश <sys/timeb.h>

#पूर्ण_अगर /* End _TIME_H_ */

