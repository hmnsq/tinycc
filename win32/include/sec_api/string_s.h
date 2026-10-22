/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_STRING_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_STRING_S

#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl _strset_s(ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ,ਪੂਰਨ ਮੁੱਲ_2);
  _CRTIMP errno_t __cdecl _strerror_s(ਅੱਖਰ *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਅੱਖਰ *Err_ਸੁਨੇਹਾ);
  _CRTIMP errno_t __cdecl _strlwr_s(ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_4,ਪੂਰਨ _Val,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _strupr_s(ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_4,_locale_t _Locale);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTRING_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ਅਚਲ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਪੂਰਨ Err_ਅੰਕ);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *Err_ਸੁਨੇਹਾ);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t _Val,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,ਮਾਪ_t ਮਾਪ_4,_locale_t _Locale);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
