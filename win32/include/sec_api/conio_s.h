/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CONIO_S
#define _INC_CONIO_S

#অন্তর্ভাব <conio.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

  _CRTIMP errno_t __cdecl _cgets_s(বর্ণ *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cprintf_s(ধ্রুব বর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cscanf_s(ধ্রুব বর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cscanf_s_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcprintf_s(ধ্রুব বর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cprintf_s_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcprintf_s_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,va_list _ArgList);

#ifndef _WCONIO_DEFINED_S
#define _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,size_t *_SizeRead);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_s(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf_s(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf_s_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_s(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_s_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_s_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
