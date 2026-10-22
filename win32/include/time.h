/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే సమయం_H
#నిర్వచించు సమయం_H

#అన్తర్భావ <_mingw.h>

#నిర్వచితం_కాకపోతే _WIN32
#దోషం Only Win32 లక్ష్యం is supported!
#అయితే_ముగింపు

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRTIMP
#నిర్వచించు _CRTIMP __declspec(dllimport)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCHAR_T_DEFINED
#నిర్వచించు _WCHAR_T_DEFINED
  రకనిర్వచనం గుర్తులేని పొట్టి wchar_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME32_T_DEFINED
#నిర్వచించు _TIME32_T_DEFINED
  రకనిర్వచనం దీర్ఘ __time32_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME64_T_DEFINED
#నిర్వచించు _TIME64_T_DEFINED
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం పూర్ణాంకం _time64_t __attribute__ ((బహుళకం (DI)));
#లేకపోతే
  రకనిర్వచనం __int64 __time64_t;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే సమయం_T_DEFINED
#నిర్వచించు సమయం_T_DEFINED
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
  రకనిర్వచనం __time32_t time_t;
#లేకపోతే
  రకనిర్వచనం __time64_t time_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CLOCK_T_DEFINED
#నిర్వచించు _CLOCK_T_DEFINED
  రకనిర్వచనం దీర్ఘ clock_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _SIZE_T_DEFINED
#నిర్వచించు _SIZE_T_DEFINED
#నిర్వచనం_రద్దు కొలత_t
#నిర్వచితమైతే _WIN64
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం కొలత_t __attribute__ ((బహుళకం (DI)));
#లేకపోతే
  రకనిర్వచనం గుర్తులేని __int64 కొలత_t;
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం కొలత_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _SSIZE_T_DEFINED
#నిర్వచించు _SSIZE_T_DEFINED
#నిర్వచనం_రద్దు ssize_t
#నిర్వచితమైతే _WIN64
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం పూర్ణాంకం ssize_t __attribute__ ((బహుళకం (DI)));
#లేకపోతే
  రకనిర్వచనం __int64 ssize_t;
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం పూర్ణాంకం ssize_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచించు _localtime32 localtime
#నిర్వచించు _difftime32     difftime
#నిర్వచించు _ctime32        ctime
#నిర్వచించు _gmtime32       gmtime
#నిర్వచించు _mktime32       mktime
#నిర్వచించు _time32 సమయం
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TM_DEFINED
#నిర్వచించు _TM_DEFINED
  నిర్మాణం tm {
    పూర్ణాంకం tm_sec;
    పూర్ణాంకం tm_min;
    పూర్ణాంకం tm_hour;
    పూర్ణాంకం tm_mday;
    పూర్ణాంకం tm_mon;
    పూర్ణాంకం tm_year;
    పూర్ణాంకం tm_wday;
    పూర్ణాంకం tm_yday;
    పూర్ణాంకం tm_isdst;
  };
#అయితే_ముగింపు

#నిర్వచించు CLOCKS_PER_SEC 1000

  __MINGW_IMPORT పూర్ణాంకం _daylight;
  __MINGW_IMPORT దీర్ఘ _dstbias;
  __MINGW_IMPORT దీర్ఘ _timezone;
  __MINGW_IMPORT అక్షరం * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(పూర్ణాంకం *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(దీర్ఘ *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(దీర్ఘ *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(కొలత_t *Return_విలువ,అక్షరం *బఫరు_2,కొలత_t కొలత_లోపల_బైట్లు,పూర్ణాంకం సూచీ_2);
  అక్షరం *__cdecl asctime(స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP అక్షరం *__cdecl _ctime32(స్థిరరాశి __time32_t *సమయం_2);
  clock_t __cdecl clock(శూన్య);
  _CRTIMP ద్విగుణ __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP నిర్మాణం tm *__cdecl _gmtime32(స్థిరరాశి __time32_t *సమయం_2);
  _CRTIMP నిర్మాణం tm *__cdecl _localtime32(స్థిరరాశి __time32_t *సమయం_2);
  కొలత_t __cdecl strftime(అక్షరం *_Buf,కొలత_t కొలత_లోపల_బైట్లు,స్థిరరాశి అక్షరం *_Format,స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP కొలత_t __cdecl _strftime_l(అక్షరం *_Buf,కొలత_t Max_కొలత,స్థిరరాశి అక్షరం *_Format,స్థిరరాశి నిర్మాణం tm *_Tm,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _strdate(అక్షరం *బఫరు_2);
  _CRTIMP అక్షరం *__cdecl _strtime(అక్షరం *బఫరు_2);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *సమయం_2);
  _CRTIMP __time32_t __cdecl _mktime32(నిర్మాణం tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(నిర్మాణం tm *_Tm);
#ఒకవేళ defined (_POSIX_) || defined(__GNUC__)
  శూన్య __cdecl tzset(శూన్య);
#లేకపోతే
  _CRTIMP శూన్య __cdecl _tzset(శూన్య);
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  ద్విగుణ __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP అక్షరం *__cdecl _ctime64(స్థిరరాశి __time64_t *సమయం_2);
  _CRTIMP నిర్మాణం tm *__cdecl _gmtime64(స్థిరరాశి __time64_t *సమయం_2);
  _CRTIMP నిర్మాణం tm *__cdecl _localtime64(స్థిరరాశి __time64_t *సమయం_2);
  _CRTIMP __time64_t __cdecl _mktime64(నిర్మాణం tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(నిర్మాణం tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *సమయం_2);
#అయితే_ముగింపు
  గుర్తులేని __cdecl _getsystime(నిర్మాణం tm *_Tm);
  గుర్తులేని __cdecl _setsystime(నిర్మాణం tm *_Tm,గుర్తులేని _MilliSec);

#నిర్వచితం_కాకపోతే _SIZE_T_DEFINED
#నిర్వచించు _SIZE_T_DEFINED
#నిర్వచితమైతే _WIN64
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం కొలత_t __attribute__ ((బహుళకం (DI)));
#లేకపోతే
  రకనిర్వచనం గుర్తులేని __int64 కొలత_t;
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం గుర్తులేని దీర్ఘ కొలత_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _SSIZE_T_DEFINED
#నిర్వచించు _SSIZE_T_DEFINED
#నిర్వచితమైతే _WIN64
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం పూర్ణాంకం ssize_t __attribute__ ((బహుళకం (DI)));
#లేకపోతే
  రకనిర్వచనం __int64 ssize_t;
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం దీర్ఘ ssize_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(స్థిరరాశి __time32_t *సమయం_2);
  కొలత_t __cdecl wcsftime(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP కొలత_t __cdecl _wcsftime_l(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,స్థిరరాశి నిర్మాణం tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *బఫరు_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *బఫరు_2);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(స్థిరరాశి __time64_t *సమయం_2);
#అయితే_ముగింపు

#ఒకవేళ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#నిర్వచించు _INC_WTIME_INL
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE wchar_t *__cdecl _wctime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime32(సమయం_2); }
#లేకపోతే
__CRT_INLINE wchar_t *__cdecl _wctime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime64(సమయం_2); }
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _WTIME_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే RC_INVOKED
ద్విగుణ __cdecl difftime(time_t _Time1,time_t _Time2);
అక్షరం *__cdecl ctime(స్థిరరాశి time_t *సమయం_2);
నిర్మాణం tm *__cdecl gmtime(స్థిరరాశి time_t *సమయం_2);
నిర్మాణం tm *__cdecl localtime(స్థిరరాశి time_t *సమయం_2);
నిర్మాణం tm *__cdecl localtime_r(స్థిరరాశి time_t *సమయం_2,నిర్మాణం tm *);

time_t __cdecl mktime(నిర్మాణం tm *_Tm);
time_t __cdecl _mkgmtime(నిర్మాణం tm *_Tm);
time_t __cdecl సమయం(time_t *సమయం_2);

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#ఒకవేళ 0
__CRT_INLINE ద్విగుణ __cdecl difftime(time_t _Time1,time_t _Time2) { తిరిగి _difftime32(_Time1,_Time2); }
__CRT_INLINE అక్షరం *__cdecl ctime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _ctime32(సమయం_2); }
__CRT_INLINE నిర్మాణం tm *__cdecl gmtime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _gmtime32(సమయం_2); }
__CRT_INLINE నిర్మాణం tm *__cdecl localtime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _localtime32(సమయం_2); }
__CRT_INLINE time_t __cdecl mktime(నిర్మాణం tm *_Tm) { తిరిగి _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(నిర్మాణం tm *_Tm) { తిరిగి _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl సమయం(time_t *సమయం_2) { తిరిగి _time32(సమయం_2); }
#అయితే_ముగింపు
#లేకపోతే
__CRT_INLINE ద్విగుణ __cdecl difftime(time_t _Time1,time_t _Time2) { తిరిగి _difftime64(_Time1,_Time2); }
__CRT_INLINE అక్షరం *__cdecl ctime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _ctime64(సమయం_2); }
__CRT_INLINE నిర్మాణం tm *__cdecl gmtime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _gmtime64(సమయం_2); }
__CRT_INLINE నిర్మాణం tm *__cdecl localtime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _localtime64(సమయం_2); }
__CRT_INLINE time_t __cdecl mktime(నిర్మాణం tm *_Tm) { తిరిగి _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(నిర్మాణం tm *_Tm) { తిరిగి _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl సమయం(time_t *సమయం_2) { తిరిగి _time64(సమయం_2); }
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
#నిర్వచించు CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT పూర్ణాంకం daylight;
  __MINGW_IMPORT దీర్ఘ dstbias;
  __MINGW_IMPORT దీర్ఘ timezone;
  __MINGW_IMPORT అక్షరం *tzname[2];
  శూన్య __cdecl tzset(శూన్య);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIMEVAL_DEFINED /* also in winsock[2].h */
#నిర్వచించు _TIMEVAL_DEFINED
నిర్మాణం timeval {
  దీర్ఘ tv_sec;
  దీర్ఘ tv_usec;
};
#నిర్వచించు timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#నిర్వచించు timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#నిర్వచించు timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#అయితే_ముగింపు /* _TIMEVAL_DEFINED */

#నిర్వచితం_కాకపోతే __STRICT_ANSI__
#నిర్వచితం_కాకపోతే _TIMEZONE_DEFINED /* also in sys/time.h */
#నిర్వచించు _TIMEZONE_DEFINED
నిర్మాణం timezone {
  పూర్ణాంకం tz_minuteswest;
  పూర్ణాంకం tz_dsttime;
};

  బాహ్య పూర్ణాంకం __cdecl mingw_gettimeofday (నిర్మాణం timeval *p, నిర్మాణం timezone *z);
#అయితే_ముగింపు
#అయితే_ముగింపు /* __STRICT_ANSI__ */

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)

#అన్తర్భావ <sec_api/time_s.h>

/* Adding timespec definition.  */
#అన్తర్భావ <sys/timeb.h>

#అయితే_ముగింపు /* End _TIME_H_ */

