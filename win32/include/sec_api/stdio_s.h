/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#অন্তর্ভাব <stdio.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  পূর্ণসংখ্যা __cdecl fprintf_s(FILE *_File,ধ্রুবক অক্ষর *_Format,...);
  আকার_t __cdecl fread_s(শূন্য *_DstBuf,আকার_t Dst_আকার,আকার_t Element_আকার,আকার_t গুনতি_5,FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fscanf_s_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  পূর্ণসংখ্যা __cdecl printf_s(ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scanf_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scanf_s_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snprintf_s(অক্ষর *_DstBuf,আকার_t Dst_আকার,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snprintf_c(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnprintf_c(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl sprintf_s(অক্ষর *_DstBuf,আকার_t Dst_আকার,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fscanf_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _sscanf_l(ধ্রুবক অক্ষর *_Src,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _sscanf_s_l(ধ্রুবক অক্ষর *_Src,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snscanf_s(ধ্রুবক অক্ষর *_Src,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snscanf_l(ধ্রুবক অক্ষর *_Src,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snscanf_s_l(ধ্রুবক অক্ষর *_Src,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  পূর্ণসংখ্যা __cdecl vfprintf_s(FILE *_File,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl vprintf_s(ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl vsnprintf_s(অক্ষর *_DstBuf,আকার_t Dst_আকার,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnprintf_s(অক্ষর *_DstBuf,আকার_t Dst_আকার,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl vsprintf_s(অক্ষর *_DstBuf,আকার_t আকার_5,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fprintf_p(FILE *_File,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _printf_p(ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _sprintf_p(অক্ষর *_Dst,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfprintf_p(FILE *_File,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vprintf_p(ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsprintf_p(অক্ষর *_Dst,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scprintf_p(ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscprintf_p(ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _printf_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _printf_p_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vprintf_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vprintf_p_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fprintf_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fprintf_p_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfprintf_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfprintf_p_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _sprintf_l(অক্ষর *_DstBuf,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _sprintf_p_l(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsprintf_l(অক্ষর *_DstBuf,ধ্রুবক অক্ষর *_Format,_locale_t,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsprintf_p_l(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scprintf_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scprintf_p_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscprintf_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscprintf_p_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _printf_s_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vprintf_s_l(ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fprintf_s_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfprintf_s_l(FILE *_File,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _sprintf_s_l(অক্ষর *_DstBuf,আকার_t Dst_আকার,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsprintf_s_l(অক্ষর *_DstBuf,আকার_t Dst_আকার,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snprintf_s_l(অক্ষর *_DstBuf,আকার_t Dst_আকার,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnprintf_s_l(অক্ষর *_DstBuf,আকার_t Dst_আকার,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snprintf_l(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snprintf_c_l(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnprintf_l(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnprintf_c_l(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,আকার_t আকার_In_শব্দগুলি);
  পূর্ণসংখ্যা __cdecl fwprintf_s(FILE *_File,ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl wprintf_s(ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl vwprintf_s(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl swprintf_s(wchar_t *_Dst,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl vswprintf_s(wchar_t *_Dst,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwprintf_s(wchar_t *_DstBuf,আকার_t Dst_আকার_In_শব্দগুলি,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnwprintf_s(wchar_t *_DstBuf,আকার_t Dst_আকার_In_শব্দগুলি,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wprintf_s_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vwprintf_s_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwprintf_s_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfwprintf_s_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_s_l(wchar_t *_DstBuf,আকার_t Dst_আকার,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_s_l(wchar_t *_DstBuf,আকার_t Dst_আকার,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwprintf_s_l(wchar_t *_DstBuf,আকার_t Dst_আকার,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,আকার_t Dst_আকার,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwscanf_s_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swscanf_s_l(ধ্রুবক wchar_t *_Src,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwscanf_s(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwscanf_s_l(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wscanf_s_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwprintf_p(FILE *_File,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wprintf_p(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfwprintf_p(FILE *_File,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vwprintf_p(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_p(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_p(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf_p(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf_p(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwprintf_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwprintf_p_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfwprintf_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfwprintf_p_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_c_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_p_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_c_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_p_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwprintf_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnwprintf_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl __swprintf_l(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl __vswprintf_l(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwscanf_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swscanf_l(ধ্রুবক wchar_t *_Src,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwscanf_l(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wscanf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP আকার_t __cdecl _fread_nolock_s(শূন্য *_DstBuf,আকার_t Dst_আকার,আকার_t Element_আকার,আকার_t গুনতি_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
