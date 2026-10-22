/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#شامل <conio.h>

#اگر defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
بیرونی "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(نویسه *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP صحیح __cdecl _cprintf_s(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _cscanf_s(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _cscanf_s_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_s(ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_s_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_s_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_واژگان,size_t *_SizeRead);
  _CRTIMP صحیح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
