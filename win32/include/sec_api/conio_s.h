/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#ಅನ್ತರ್ಭಾವ <conio.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(ವರ್ಣ *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cprintf_s(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cscanf_s(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cscanf_s_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcprintf_s(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cprintf_s_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcprintf_s_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_ಪದಗಳು,size_t *_SizeRead);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_s(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwscanf_s(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwscanf_s_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_s(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_s_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_s_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
