/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fprintf_s(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,...);
  size_t __cdecl fread_s(ಶೂನ್ಯ *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t ಎಣಿಕೆ_5,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fscanf_s_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl printf_s(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scanf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scanf_s_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snprintf_s(ವರ್ಣ *_DstBuf,size_t _DstSize,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snprintf_c(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnprintf_c(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl sprintf_s(ವರ್ಣ *_DstBuf,size_t _DstSize,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fscanf_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sscanf_l(ಧ್ರುವ ವರ್ಣ *_Src,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sscanf_s_l(ಧ್ರುವ ವರ್ಣ *_Src,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snscanf_s(ಧ್ರುವ ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snscanf_l(ಧ್ರುವ ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snscanf_s_l(ಧ್ರುವ ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vfprintf_s(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vprintf_s(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vsnprintf_s(ವರ್ಣ *_DstBuf,size_t _DstSize,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnprintf_s(ವರ್ಣ *_DstBuf,size_t _DstSize,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vsprintf_s(ವರ್ಣ *_DstBuf,size_t _Size,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fprintf_p(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _printf_p(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sprintf_p(ವರ್ಣ *_Dst,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfprintf_p(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vprintf_p(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsprintf_p(ವರ್ಣ *_Dst,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scprintf_p(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscprintf_p(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _printf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _printf_p_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vprintf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vprintf_p_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fprintf_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fprintf_p_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfprintf_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfprintf_p_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sprintf_l(ವರ್ಣ *_DstBuf,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sprintf_p_l(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsprintf_l(ವರ್ಣ *_DstBuf,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsprintf_p_l(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scprintf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scprintf_p_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscprintf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscprintf_p_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _printf_s_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vprintf_s_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fprintf_s_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfprintf_s_l(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sprintf_s_l(ವರ್ಣ *_DstBuf,size_t _DstSize,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsprintf_s_l(ವರ್ಣ *_DstBuf,size_t _DstSize,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snprintf_s_l(ವರ್ಣ *_DstBuf,size_t _DstSize,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnprintf_s_l(ವರ್ಣ *_DstBuf,size_t _DstSize,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snprintf_l(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snprintf_c_l(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnprintf_l(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnprintf_c_l(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_ಪದಗಳು);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fwprintf_s(FILE *_File,ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wprintf_s(ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vwprintf_s(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_ಪದಗಳು,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_ಪದಗಳು,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wprintf_s_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vwprintf_s_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwprintf_s_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfwprintf_s_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwscanf_s_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swscanf_s_l(ಧ್ರುವ wchar_t *_Src,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwscanf_s(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwscanf_s_l(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wscanf_s_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwprintf_p(FILE *_File,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wprintf_p(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfwprintf_p(FILE *_File,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vwprintf_p(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf_p(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf_p(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwprintf_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwprintf_p_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfwprintf_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfwprintf_p_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __swprintf_l(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __vswprintf_l(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwscanf_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swscanf_l(ಧ್ರುವ wchar_t *_Src,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwscanf_l(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wscanf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(ಶೂನ್ಯ *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t ಎಣಿಕೆ_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
