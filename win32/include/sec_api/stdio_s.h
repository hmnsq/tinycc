/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_STDIO_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_STDIO_S

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDIO_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  ਪੂਰਨ __cdecl fprintf_s(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,...);
  ਮਾਪ_t __cdecl fread_s(ਖਾਲੀ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Element_ਮਾਪ,ਮਾਪ_t ਗਿਣਤੀ_6,FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fscanf_s_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  ਪੂਰਨ __cdecl printf_s(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _scanf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _scanf_s_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _snprintf_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _snprintf_c(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnprintf_c(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl sprintf_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _fscanf_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _sscanf_l(ਅਚਲ ਅੱਖਰ *_Src,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _sscanf_s_l(ਅਚਲ ਅੱਖਰ *_Src,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _snscanf_s(ਅਚਲ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _snscanf_l(ਅਚਲ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _snscanf_s_l(ਅਚਲ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  ਪੂਰਨ __cdecl vfprintf_s(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl vprintf_s(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl vsnprintf_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vsnprintf_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl vsprintf_s(ਅੱਖਰ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fprintf_p(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _printf_p(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _sprintf_p(ਅੱਖਰ *_Dst,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfprintf_p(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vprintf_p(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vsprintf_p(ਅੱਖਰ *_Dst,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _scprintf_p(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vscprintf_p(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _printf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _printf_p_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vprintf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vprintf_p_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fprintf_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _fprintf_p_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfprintf_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vfprintf_p_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _sprintf_l(ਅੱਖਰ *_DstBuf,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _sprintf_p_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsprintf_l(ਅੱਖਰ *_DstBuf,ਅਚਲ ਅੱਖਰ *_Format,_locale_t,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vsprintf_p_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _scprintf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _scprintf_p_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vscprintf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vscprintf_p_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _printf_s_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vprintf_s_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fprintf_s_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfprintf_s_l(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _sprintf_s_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsprintf_s_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snprintf_s_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnprintf_s_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snprintf_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _snprintf_c_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnprintf_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vsnprintf_c_l(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *,_locale_t _Locale,va_list _ArgList);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDIO_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  ਪੂਰਨ __cdecl fwprintf_s(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl wprintf_s(ਅਚਲ wchar_t *_Format,...);
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
  _CRTIMP ਪੂਰਨ __cdecl _fwprintf_p(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _wprintf_p(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfwprintf_p(FILE *_File,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vwprintf_p(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_p(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_p(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf_p(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf_p(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _wprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _wprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fwprintf_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _fwprintf_p_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfwprintf_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vfwprintf_p_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_c_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_p_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snwprintf_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl __swprintf_l(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ਪੂਰਨ __cdecl __vswprintf_l(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,_locale_t _Plocinfo,va_list ਦਲੀਲਾਂ_2);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fwscanf_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _swscanf_l(ਅਚਲ wchar_t *_Src,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _snwscanf_l(ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _wscanf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  _CRTIMP ਮਾਪ_t __cdecl _fread_nolock_s(ਖਾਲੀ *_DstBuf,ਮਾਪ_t Dst_ਮਾਪ,ਮਾਪ_t Element_ਮਾਪ,ਮਾਪ_t ਗਿਣਤੀ_6,FILE *_File);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
