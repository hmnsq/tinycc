/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#અન્તર્ભાવ <stdio.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  પૂર્ણાંક __cdecl fprintf_s(FILE *_File,અચલ અક્ષર *_Format,...);
  size_t __cdecl fread_s(શૂન્ય *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t ગણતરી_5,FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fscanf_s_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  પૂર્ણાંક __cdecl printf_s(અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _scanf_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _scanf_s_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _snprintf_s(અક્ષર *_DstBuf,size_t _DstSize,size_t Max_ગણતરી,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _snprintf_c(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnprintf_c(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl sprintf_s(અક્ષર *_DstBuf,size_t _DstSize,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _fscanf_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _sscanf_l(અચલ અક્ષર *_Src,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _sscanf_s_l(અચલ અક્ષર *_Src,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _snscanf_s(અચલ અક્ષર *_Src,size_t Max_ગણતરી,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _snscanf_l(અચલ અક્ષર *_Src,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _snscanf_s_l(અચલ અક્ષર *_Src,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  પૂર્ણાંક __cdecl vfprintf_s(FILE *_File,અચલ અક્ષર *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl vprintf_s(અચલ અક્ષર *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl vsnprintf_s(અક્ષર *_DstBuf,size_t _DstSize,size_t Max_ગણતરી,અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vsnprintf_s(અક્ષર *_DstBuf,size_t _DstSize,size_t Max_ગણતરી,અચલ અક્ષર *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl vsprintf_s(અક્ષર *_DstBuf,size_t _Size,અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fprintf_p(FILE *_File,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _printf_p(અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _sprintf_p(અક્ષર *_Dst,size_t Max_ગણતરી,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfprintf_p(FILE *_File,અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vprintf_p(અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vsprintf_p(અક્ષર *_Dst,size_t Max_ગણતરી,અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _scprintf_p(અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vscprintf_p(અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _printf_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _printf_p_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vprintf_l(અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vprintf_p_l(અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fprintf_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _fprintf_p_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfprintf_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vfprintf_p_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _sprintf_l(અક્ષર *_DstBuf,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _sprintf_p_l(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsprintf_l(અક્ષર *_DstBuf,અચલ અક્ષર *_Format,_locale_t,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vsprintf_p_l(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _scprintf_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _scprintf_p_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vscprintf_l(અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vscprintf_p_l(અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _printf_s_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vprintf_s_l(અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fprintf_s_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfprintf_s_l(FILE *_File,અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _sprintf_s_l(અક્ષર *_DstBuf,size_t _DstSize,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsprintf_s_l(અક્ષર *_DstBuf,size_t _DstSize,અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snprintf_s_l(અક્ષર *_DstBuf,size_t _DstSize,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnprintf_s_l(અક્ષર *_DstBuf,size_t _DstSize,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snprintf_l(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _snprintf_c_l(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnprintf_l(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vsnprintf_c_l(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_શબ્દો);
  પૂર્ણાંક __cdecl fwprintf_s(FILE *_File,અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl wprintf_s(અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl vwprintf_s(અચલ wchar_t *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_શબ્દો,size_t Max_ગણતરી,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_શબ્દો,size_t Max_ગણતરી,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _wprintf_s_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vwprintf_s_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fwprintf_s_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfwprintf_s_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fwscanf_s_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _swscanf_s_l(અચલ wchar_t *_Src,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _snwscanf_s(અચલ wchar_t *_Src,size_t Max_ગણતરી,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _snwscanf_s_l(અચલ wchar_t *_Src,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _wscanf_s_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,અચલ wchar_t *_Filename,અચલ wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,અચલ wchar_t *_Filename,અચલ wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_શબ્દો);
  _CRTIMP પૂર્ણાંક __cdecl _fwprintf_p(FILE *_File,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _wprintf_p(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfwprintf_p(FILE *_File,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vwprintf_p(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf_p(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf_p(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _wprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _wprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fwprintf_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _fwprintf_p_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfwprintf_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vfwprintf_p_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl __swprintf_l(wchar_t *_Dest,અચલ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP પૂર્ણાંક __cdecl __vswprintf_l(wchar_t *_Dest,અચલ wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fwscanf_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _swscanf_l(અચલ wchar_t *_Src,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _snwscanf_l(અચલ wchar_t *_Src,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _wscanf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(શૂન્ય *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t ગણતરી_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
