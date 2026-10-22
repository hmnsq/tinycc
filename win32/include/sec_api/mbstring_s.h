/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_MBSTRING_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_MBSTRING_S

#ਅਨ੍ਤਰ੍ਭਾਵ <mbstring.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _MBSTRING_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Ch,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Ch,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Val,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Val,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Val,_locale_t _Locale);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *__cdecl _mbstok_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Str,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Delim,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ **_Context);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *__cdecl _mbstok_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Str,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Delim,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਪੂਰਨ *_PCopied,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਪੂਰਨ *_PCopied,ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *_Src,_locale_t _Locale);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
