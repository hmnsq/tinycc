/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#నిర్వచితం_కాకపోతే _INC_CONIO_S
#నిర్వచించు _INC_CONIO_S

#అన్తర్భావ <conio.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl _cgets_s(అక్షరం *బఫరు_2,కొలత_t కొలత_4,కొలత_t *కొలత_Read);
  _CRTIMP పూర్ణాంకం __cdecl _cprintf_s(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cscanf_s(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cscanf_s_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcprintf_s(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cprintf_s_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcprintf_s_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);

#నిర్వచితం_కాకపోతే _WCONIO_DEFINED_S
#నిర్వచించు _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *బఫరు_2,కొలత_t కొలత_లోపల_పదాలు,కొలత_t *కొలత_Read);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_s(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf_s(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_s(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_s_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు
