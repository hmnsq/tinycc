/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే సమయం_H_S
#నిర్వచించు సమయం_H_S

#అన్తర్భావ <time.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl _ctime32_s(అక్షరం *_Buf,కొలత_t కొలత_లోపల_బైట్లు,స్థిరరాశి __time32_t *సమయం_2);
  _CRTIMP errno_t __cdecl _gmtime32_s(నిర్మాణం tm *_Tm,స్థిరరాశి __time32_t *సమయం_2);
  _CRTIMP errno_t __cdecl _localtime32_s(నిర్మాణం tm *_Tm,స్థిరరాశి __time32_t *సమయం_2);
  _CRTIMP errno_t __cdecl _strdate_s(అక్షరం *_Buf,కొలత_t కొలత_లోపల_బైట్లు);
  _CRTIMP errno_t __cdecl _strtime_s(అక్షరం *_Buf ,కొలత_t కొలత_లోపల_బైట్లు);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(అక్షరం *_Buf,కొలత_t కొలత_లోపల_బైట్లు,స్థిరరాశి __time64_t *సమయం_2);
  _CRTIMP errno_t __cdecl _gmtime64_s(నిర్మాణం tm *_Tm,స్థిరరాశి __time64_t *సమయం_2);
  _CRTIMP errno_t __cdecl _localtime64_s(నిర్మాణం tm *_Tm,స్థిరరాశి __time64_t *సమయం_2);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WTIME_S_DEFINED
#నిర్వచించు _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి __time32_t *సమయం_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి __time64_t *సమయం_2);
#అయితే_ముగింపు

#ఒకవేళ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#నిర్వచించు _INC_WTIME_S_INL
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime32_s(బఫరు_2,కొలత_లోపల_పదాలు,సమయం_2); }
#లేకపోతే
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime64_s(బఫరు_2,కొలత_లోపల_పదాలు,సమయం_2); }
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే RC_INVOKED
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE errno_t __cdecl localtime_s(నిర్మాణం tm *_Tm,స్థిరరాశి time_t *సమయం_2) { తిరిగి _localtime32_s(_Tm,సమయం_2); }
#లేకపోతే
__CRT_INLINE errno_t __cdecl localtime_s(నిర్మాణం tm *_Tm,స్థిరరాశి time_t *సమయం_2) { తిరిగి _localtime64_s(_Tm,సమయం_2); }
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు
