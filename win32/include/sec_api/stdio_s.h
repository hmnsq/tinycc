/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#অন্তর্ভাৱ <stdio.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  পূর্ণাঙ্ক __cdecl fprintf_s(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,...);
  size_t __cdecl fread_s(শূন্য *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t গুনতি_5,FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fscanf_s_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  পূর্ণাঙ্ক __cdecl printf_s(ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scanf_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scanf_s_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snprintf_s(ৱর্ণ *_DstBuf,size_t _DstSize,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snprintf_c(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnprintf_c(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl sprintf_s(ৱর্ণ *_DstBuf,size_t _DstSize,ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fscanf_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _sscanf_l(ধ্রুৱ ৱর্ণ *_Src,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _sscanf_s_l(ধ্রুৱ ৱর্ণ *_Src,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snscanf_s(ধ্রুৱ ৱর্ণ *_Src,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snscanf_l(ধ্রুৱ ৱর্ণ *_Src,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snscanf_s_l(ধ্রুৱ ৱর্ণ *_Src,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  পূর্ণাঙ্ক __cdecl vfprintf_s(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl vprintf_s(ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl vsnprintf_s(ৱর্ণ *_DstBuf,size_t _DstSize,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnprintf_s(ৱর্ণ *_DstBuf,size_t _DstSize,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl vsprintf_s(ৱর্ণ *_DstBuf,size_t _Size,ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fprintf_p(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _printf_p(ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _sprintf_p(ৱর্ণ *_Dst,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfprintf_p(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vprintf_p(ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsprintf_p(ৱর্ণ *_Dst,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scprintf_p(ধ্রুৱ ৱর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscprintf_p(ধ্রুৱ ৱর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _printf_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _printf_p_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vprintf_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vprintf_p_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fprintf_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fprintf_p_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfprintf_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfprintf_p_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _sprintf_l(ৱর্ণ *_DstBuf,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _sprintf_p_l(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsprintf_l(ৱর্ণ *_DstBuf,ধ্রুৱ ৱর্ণ *_Format,_locale_t,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsprintf_p_l(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scprintf_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scprintf_p_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscprintf_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscprintf_p_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _printf_s_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vprintf_s_l(ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fprintf_s_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfprintf_s_l(FILE *_File,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _sprintf_s_l(ৱর্ণ *_DstBuf,size_t _DstSize,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsprintf_s_l(ৱর্ণ *_DstBuf,size_t _DstSize,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snprintf_s_l(ৱর্ণ *_DstBuf,size_t _DstSize,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnprintf_s_l(ৱর্ণ *_DstBuf,size_t _DstSize,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snprintf_l(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snprintf_c_l(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnprintf_l(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnprintf_c_l(ৱর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুৱ ৱর্ণ *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_শব্দগুলি);
  পূর্ণাঙ্ক __cdecl fwprintf_s(FILE *_File,ধ্রুৱ wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl wprintf_s(ধ্রুৱ wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl vwprintf_s(ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_শব্দগুলি,ধ্রুৱ wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_শব্দগুলি,ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_শব্দগুলি,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_শব্দগুলি,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wprintf_s_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vwprintf_s_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwprintf_s_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfwprintf_s_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwscanf_s_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swscanf_s_l(ধ্রুৱ wchar_t *_Src,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwscanf_s(ধ্রুৱ wchar_t *_Src,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwscanf_s_l(ধ্রুৱ wchar_t *_Src,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wscanf_s_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ধ্রুৱ wchar_t *_Filename,ধ্রুৱ wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ধ্রুৱ wchar_t *_Filename,ধ্রুৱ wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_শব্দগুলি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwprintf_p(FILE *_File,ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wprintf_p(ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfwprintf_p(FILE *_File,ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vwprintf_p(ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf_p(ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf_p(ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wprintf_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wprintf_p_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vwprintf_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vwprintf_p_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwprintf_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwprintf_p_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfwprintf_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfwprintf_p_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf_p_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf_p_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl __swprintf_l(wchar_t *_Dest,ধ্রুৱ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl __vswprintf_l(wchar_t *_Dest,ধ্রুৱ wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwscanf_l(FILE *_File,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swscanf_l(ধ্রুৱ wchar_t *_Src,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwscanf_l(ধ্রুৱ wchar_t *_Src,size_t Max_গুনতি,ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wscanf_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(শূন্য *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t গুনতি_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
