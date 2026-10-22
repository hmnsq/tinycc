/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_CONIO_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_CONIO_S

#ਅਨ੍ਤਰ੍ਭਾਵ <conio.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl _cgets_s(ਅੱਖਰ *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t *ਮਾਪ_Read);
  _CRTIMP ਪੂਰਨ __cdecl _cprintf_s(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cscanf_s(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cscanf_s_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcprintf_s(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cprintf_s_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcprintf_s_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCONIO_DEFINED_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਮਾਪ_t *ਮਾਪ_Read);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_s(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf_s(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_s(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
