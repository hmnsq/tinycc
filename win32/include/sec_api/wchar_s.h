/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_WCHAR_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WCHAR_S

#ਅਨ੍ਤਰ੍ਭਾਵ <wchar.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIO_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCONIO_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਮਾਪ_t *ਮਾਪ_Read);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_s(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf_s(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_s(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDIO_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  ਪੂਰਨ __cdecl fwprintf_s(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl wprintf_s(ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl vfwprintf_s(FILE *_File,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl vwprintf_s(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl swprintf_s(wchar_t *_Dst,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl vswprintf_s(wchar_t *_Dst,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snwprintf_s(wchar_t *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnwprintf_s(wchar_t *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _wprintf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vwprintf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fwprintf_s_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfwprintf_s_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_s_l(wchar_t *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_s_l(wchar_t *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snwprintf_s_l(wchar_t *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fwscanf_s_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _swscanf_s_l(ਅਚਲ wchar_t *_Src,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _snwscanf_s(ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _snwscanf_s_l(ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _wscanf_s_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
#ਜੇ_ਅੰਤ

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
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDLIBP_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *ਰਸਤਾ_ਨਤੀਜਾ,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Drive,ਅਚਲ wchar_t *_Dir,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ਅਚਲ wchar_t *_Name,ਅਚਲ wchar_t *ਮੁੱਲ_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_EnvVar,wchar_t *ਨਤੀਜਾ_ਰਸਤਾ,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ਅਚਲ wchar_t *ਭਰਿਆ_ਰਸਤਾ,wchar_t *_Drive,ਮਾਪ_t Drive_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t *_Dir,ਮਾਪ_t Dir_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t *_Filename,ਮਾਪ_t Filename_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,wchar_t *_Ext,ਮਾਪ_t Ext_ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

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

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WTIME_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ __time32_t *ਸਮਾਂ_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ __time64_t *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ

#ਜੇ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WTIME_S_INL
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime32_s(ਬਫਰ_2,ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਸਮਾਂ_2); }
#ਨਹੀਂਤਾਂ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *ਬਫਰ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime64_s(ਬਫਰ_2,ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਸਮਾਂ_2); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl mbsrtowcs_s(ਮਾਪ_t *_Retval,wchar_t *_Dst,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ ਅੱਖਰ **_PSrc,ਮਾਪ_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(ਮਾਪ_t *_Retval,ਅੱਖਰ *_Dst,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(ਮਾਪ_t *_Retval,ਅੱਖਰ *_Dst,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,ਅਚਲ wchar_t **_Src,ਮਾਪ_t ਮਾਪ_4,mbstate_t *_State);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
