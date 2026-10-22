/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#جيڪڏهن_وصف_نه_ٿيل _INC_CONIO_S
#وصف_ڪريو _INC_CONIO_S

#ضمن <conio.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl _cgets_s(حرف *بفر_2,سائيز_t سائيز_4,سائيز_t *سائيز_Read);
  _CRTIMP صحيح __cdecl _cprintf_s(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cscanf_s(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cscanf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_s(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);

#جيڪڏهن_وصف_نه_ٿيل _WCONIO_DEFINED_S
#وصف_ڪريو _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,سائيز_t *سائيز_Read);
  _CRTIMP صحيح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو
