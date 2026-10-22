/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_STDLIB_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_STDLIB_S

#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl _dupenv_s(ਅੱਖਰ **_PBuffer,ਮਾਪ_t *PBuffer_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ ਅੱਖਰ *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(ਪੂਰਨ ਮੁੱਲ_2,ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਪੂਰਨ _Radix);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਪੂਰਨ _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Val,ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਪੂਰਨ _Radix);
#ਜੇ_ਅੰਤ
  _CRTIMP errno_t __cdecl _ltoa_s(ਲੰਮਾ _Val,ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਪੂਰਨ _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(ਮਾਪ_t *Pt_ਅੰਕ_ਦਾ_Char_Converted,wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ ਅੱਖਰ *_SrcBuf,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(ਮਾਪ_t *Pt_ਅੰਕ_ਦਾ_Char_Converted,wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ ਅੱਖਰ *_SrcBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _Val,ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਪੂਰਨ _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(ਪੂਰਨ *ਮਾਪ_Converted,ਅੱਖਰ *_MbCh,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(ਮਾਪ_t *Pt_ਅੰਕ_ਦਾ_Char_Converted,ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(ਮਾਪ_t *Pt_ਅੰਕ_ਦਾ_Char_Converted,ਅੱਖਰ *_Dst,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ_ਵਿੱਚ_ਬਾਈਟਾਂ,_locale_t _Locale);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDLIB_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (ਪੂਰਨ _Val,wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਪੂਰਨ _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (ਲੰਮਾ _Val,wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਪੂਰਨ _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _Val,wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਪੂਰਨ _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(ਮਾਪ_t *Return_ਮਾਪ,wchar_t *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **ਬਫਰ_2,ਮਾਪ_t *ਬਫਰ_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_VarName);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਪੂਰਨ _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Val,wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਪੂਰਨ _Radix);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _POSIX_
  _CRTIMP errno_t __cdecl _ecvt_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Dights,ਪੂਰਨ *_PtDec,ਪੂਰਨ *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Dec,ਪੂਰਨ *_PtDec,ਪੂਰਨ *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Digits);
  _CRTIMP errno_t __cdecl _makepath_s(ਅੱਖਰ *ਰਸਤਾ_ਨਤੀਜਾ,ਮਾਪ_t ਮਾਪ_4,ਅਚਲ ਅੱਖਰ *_Drive,ਅਚਲ ਅੱਖਰ *_Dir,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(ਅਚਲ ਅੱਖਰ *_Name,ਅਚਲ ਅੱਖਰ *ਮੁੱਲ_2);
  _CRTIMP errno_t __cdecl _searchenv_s(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_EnvVar,ਅੱਖਰ *ਨਤੀਜਾ_ਰਸਤਾ,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP errno_t __cdecl _splitpath_s(ਅਚਲ ਅੱਖਰ *ਭਰਿਆ_ਰਸਤਾ,ਅੱਖਰ *_Drive,ਮਾਪ_t Drive_ਮਾਪ,ਅੱਖਰ *_Dir,ਮਾਪ_t Dir_ਮਾਪ,ਅੱਖਰ *_Filename,ਮਾਪ_t Filename_ਮਾਪ,ਅੱਖਰ *_Ext,ਮਾਪ_t Ext_ਮਾਪ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDLIBP_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *ਰਸਤਾ_ਨਤੀਜਾ,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Drive,ਅਚਲ wchar_t *_Dir,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ਅਚਲ wchar_t *_Name,ਅਚਲ wchar_t *ਮੁੱਲ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_EnvVar,wchar_t *ਨਤੀਜਾ_ਰਸਤਾ,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ਅਚਲ wchar_t *ਭਰਿਆ_ਰਸਤਾ,wchar_t *_Drive,ਮਾਪ_t Drive_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t *_Dir,ਮਾਪ_t Dir_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t *_Filename,ਮਾਪ_t Filename_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t *_Ext,ਮਾਪ_t Ext_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
