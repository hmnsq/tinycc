/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _TIMEB_H_
#నిర్వచించు _TIMEB_H_

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

#నిర్వచితం_కాకపోతే __TINYC__ /* gr */
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచితమైతే _WIN64
#నిర్వచనం_రద్దు USE_32_బిట్టు_సమయం_T
#అయితే_ముగింపు
#లేకపోతే
#ఒకవేళ INTEGRAL_MAX_బిట్లు < 64
#నిర్వచించు USE_32_బిట్టు_సమయం_T
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME32_T_DEFINED
  రకనిర్వచనం దీర్ఘ __time32_t;
#నిర్వచించు _TIME32_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME64_T_DEFINED
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  రకనిర్వచనం __int64 __time64_t;
#అయితే_ముగింపు
#నిర్వచించు _TIME64_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే సమయం_T_DEFINED
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
  రకనిర్వచనం __time32_t time_t;
#లేకపోతే
  రకనిర్వచనం __time64_t time_t;
#అయితే_ముగింపు
#నిర్వచించు సమయం_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIMEB_DEFINED
#నిర్వచించు _TIMEB_DEFINED

  నిర్మాణం __timeb32 {
    __time32_t సమయం;
    గుర్తులేని పొట్టి millitm;
    పొట్టి timezone;
    పొట్టి dstflag;
  };

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  నిర్మాణం timeb {
    time_t సమయం;
    గుర్తులేని పొట్టి millitm;
    పొట్టి timezone;
    పొట్టి dstflag;
  };
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  నిర్మాణం __timeb64 {
    __time64_t సమయం;
    గుర్తులేని పొట్టి millitm;
    పొట్టి timezone;
    పొట్టి dstflag;
  };
#అయితే_ముగింపు

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచించు _timeb __timeb32
//gr #define _ftime _ftime32
#నిర్వచించు _ftime32 _ftime
#లేకపోతే
#నిర్వచించు _timeb __timeb64
#నిర్వచించు _ftime _ftime64
#అయితే_ముగింపు
#అయితే_ముగింపు

  _CRTIMP శూన్య __cdecl _ftime32(నిర్మాణం __timeb32 *సమయం_2);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP శూన్య __cdecl _ftime64(నిర్మాణం __timeb64 *సమయం_2);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIMESPEC_DEFINED
#నిర్వచించు _TIMESPEC_DEFINED
నిర్మాణం timespec {
  time_t  tv_sec;   /* Seconds */
  దీర్ఘ    tv_nsec;  /* Nanoseconds */
};

నిర్మాణం itimerspec {
  నిర్మాణం timespec  it_interval;  /* Timer period */
  నిర్మాణం timespec  it_value;     /* Timer expiration */
};
#అయితే_ముగింపు

#ఒకవేళ !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE శూన్య __cdecl ftime(నిర్మాణం timeb *_Tmb) {
  _ftime32((నిర్మాణం __timeb32 *)_Tmb);
}
#లేకపోతే
__CRT_INLINE శూన్య __cdecl ftime(నిర్మాణం timeb *_Tmb) {
  _ftime64((నిర్మాణం __timeb64 *)_Tmb);
}
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)

#అన్తర్భావ <sec_api/sys/timeb_s.h>
#అయితే_ముగింపు
