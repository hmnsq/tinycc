/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_UTIME
#నిర్వచించు _INC_UTIME

#నిర్వచితం_కాకపోతే _WIN32
#దోషం Only Win32 లక్ష్యం is supported!
#అయితే_ముగింపు

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRTIMP
#నిర్వచించు _CRTIMP __declspec(dllimport)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCHAR_T_DEFINED
  రకనిర్వచనం గుర్తులేని పొట్టి wchar_t;
#నిర్వచించు _WCHAR_T_DEFINED
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
#నిర్వచించు _TIME32_T_DEFINED
  రకనిర్వచనం దీర్ఘ __time32_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME64_T_DEFINED
#నిర్వచించు _TIME64_T_DEFINED
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  రకనిర్వచనం __int64 __time64_t;
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

#నిర్వచితం_కాకపోతే _UTIMBUF_DEFINED
#నిర్వచించు _UTIMBUF_DEFINED

  నిర్మాణం _utimbuf {
    time_t actime;
    time_t modtime;
  };

  నిర్మాణం __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  నిర్మాణం __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  నిర్మాణం utimbuf {
    time_t actime;
    time_t modtime;
  };

  నిర్మాణం utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#అయితే_ముగింపు
#అయితే_ముగింపు

  _CRTIMP పూర్ణాంకం __cdecl _utime32(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం __utimbuf32 *సమయం_2);
  _CRTIMP పూర్ణాంకం __cdecl _futime32(పూర్ణాంకం _FileDes,నిర్మాణం __utimbuf32 *సమయం_2);
  _CRTIMP పూర్ణాంకం __cdecl _wutime32(స్థిరరాశి wchar_t *_Filename,నిర్మాణం __utimbuf32 *సమయం_2);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP పూర్ణాంకం __cdecl _utime64(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం __utimbuf64 *సమయం_2);
  _CRTIMP పూర్ణాంకం __cdecl _futime64(పూర్ణాంకం _FileDes,నిర్మాణం __utimbuf64 *సమయం_2);
  _CRTIMP పూర్ణాంకం __cdecl _wutime64(స్థిరరాశి wchar_t *_Filename,నిర్మాణం __utimbuf64 *సమయం_2);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే RC_INVOKED
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE పూర్ణాంకం __cdecl _utime(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం _utimbuf *_Utimbuf) {
  తిరిగి _utime32(_Filename,(నిర్మాణం __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE పూర్ణాంకం __cdecl _futime(పూర్ణాంకం _Desc,నిర్మాణం _utimbuf *_Utimbuf) {
  తిరిగి _futime32(_Desc,(నిర్మాణం __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE పూర్ణాంకం __cdecl _wutime(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _utimbuf *_Utimbuf) {
  తిరిగి _wutime32(_Filename,(నిర్మాణం __utimbuf32 *)_Utimbuf);
}
#లేకపోతే
__CRT_INLINE పూర్ణాంకం __cdecl _utime(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం _utimbuf *_Utimbuf) {
  తిరిగి _utime64(_Filename,(నిర్మాణం __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE పూర్ణాంకం __cdecl _futime(పూర్ణాంకం _Desc,నిర్మాణం _utimbuf *_Utimbuf) {
  తిరిగి _futime64(_Desc,(నిర్మాణం __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE పూర్ణాంకం __cdecl _wutime(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _utimbuf *_Utimbuf) {
  తిరిగి _wutime64(_Filename,(నిర్మాణం __utimbuf64 *)_Utimbuf);
}
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE పూర్ణాంకం __cdecl utime(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం utimbuf *_Utimbuf) {
  తిరిగి _utime32(_Filename,(నిర్మాణం __utimbuf32 *)_Utimbuf);
}
#లేకపోతే
__CRT_INLINE పూర్ణాంకం __cdecl utime(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం utimbuf *_Utimbuf) {
  తిరిగి _utime64(_Filename,(నిర్మాణం __utimbuf64 *)_Utimbuf);
}
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)
#అయితే_ముగింపు
