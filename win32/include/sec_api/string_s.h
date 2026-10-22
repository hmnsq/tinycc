/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_STRING_S
#నిర్వచించు _INC_STRING_S

#అన్తర్భావ <string.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl _strset_s(అక్షరం *_Dst,కొలత_t Dst_కొలత,పూర్ణాంకం విలువ_2);
  _CRTIMP errno_t __cdecl _strerror_s(అక్షరం *_Buf,కొలత_t కొలత_లోపల_బైట్లు,స్థిరరాశి అక్షరం *Err_సందేశం);
  _CRTIMP errno_t __cdecl _strlwr_s(అక్షరం *_Str,కొలత_t కొలత_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(అక్షరం *_Str,కొలత_t కొలత_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(అక్షరం *_Str,కొలత_t కొలత_4,పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _strupr_s(అక్షరం *_Str,కొలత_t కొలత_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(అక్షరం *_Str,కొలత_t కొలత_4,_locale_t _Locale);
#నిర్వచితం_కాకపోతే _WSTRING_S_DEFINED
#నిర్వచించు _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,స్థిరరాశి wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,పూర్ణాంకం Err_అంకె);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *Err_సందేశం);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,కొలత_t Dst_కొలత_లోపల_పదాలు,wchar_t _Val,కొలత_t Max_లెక్క);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,కొలత_t కొలత_లోపల_పదాలు,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,కొలత_t కొలత_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,కొలత_t కొలత_4,_locale_t _Locale);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
