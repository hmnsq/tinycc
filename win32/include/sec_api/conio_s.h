/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#که_نه_تعریف_شوی _INC_CONIO_S
#تعریف_کړه _INC_CONIO_S

#ضمن <conio.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  _CRTIMP errno_t __cdecl _cgets_s(حرف *بفر_2,اندازه_t اندازه_4,اندازه_t *اندازه_Read);
  _CRTIMP صحيح __cdecl _cprintf_s(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cscanf_s(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cscanf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_s(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);

#که_نه_تعریف_شوی _WCONIO_DEFINED_S
#تعریف_کړه _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,اندازه_t *اندازه_Read);
  _CRTIMP صحيح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
#د_که_پای
