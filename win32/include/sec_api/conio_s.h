/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_غیر_تعریف_شدہ _INC_CONIO_S
#تعریف_کرو _INC_CONIO_S

#شامل <conio.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  _CRTIMP errno_t __cdecl _cgets_s(حرف *بفر_2,سائز_t سائز_4,سائز_t *سائز_Read);
  _CRTIMP صحیح __cdecl _cprintf_s(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _cscanf_s(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _cscanf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_s(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);

#اگر_غیر_تعریف_شدہ _WCONIO_DEFINED_S
#تعریف_کرو _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,سائز_t *سائز_Read);
  _CRTIMP صحیح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
#اگر_ختم
