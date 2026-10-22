/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#ଅନ୍ତର୍ଭାଵ <conio.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(ଅକ୍ଷର *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cprintf_s(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cscanf_s(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cscanf_s_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcprintf_s(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cprintf_s_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcprintf_s_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,size_t *_SizeRead);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_s(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwscanf_s(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwscanf_s_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_s(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_s_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_s_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
