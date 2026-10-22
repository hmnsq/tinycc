/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#ଅନ୍ତର୍ଭାଵ <stdio.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fprintf_s(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,...);
  size_t __cdecl fread_s(ଶୂନ୍ୟ *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t ଗଣନା_6,FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fscanf_s_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl printf_s(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scanf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scanf_s_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snprintf_s(ଅକ୍ଷର *_DstBuf,size_t _DstSize,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snprintf_c(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnprintf_c(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl sprintf_s(ଅକ୍ଷର *_DstBuf,size_t _DstSize,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fscanf_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sscanf_l(ଅଚଳ ଅକ୍ଷର *_Src,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sscanf_s_l(ଅଚଳ ଅକ୍ଷର *_Src,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snscanf_s(ଅଚଳ ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snscanf_l(ଅଚଳ ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snscanf_s_l(ଅଚଳ ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vfprintf_s(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vprintf_s(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsnprintf_s(ଅକ୍ଷର *_DstBuf,size_t _DstSize,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnprintf_s(ଅକ୍ଷର *_DstBuf,size_t _DstSize,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsprintf_s(ଅକ୍ଷର *_DstBuf,size_t _Size,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fprintf_p(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _printf_p(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sprintf_p(ଅକ୍ଷର *_Dst,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfprintf_p(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vprintf_p(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsprintf_p(ଅକ୍ଷର *_Dst,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scprintf_p(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscprintf_p(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _printf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _printf_p_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vprintf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vprintf_p_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fprintf_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fprintf_p_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfprintf_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfprintf_p_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sprintf_l(ଅକ୍ଷର *_DstBuf,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sprintf_p_l(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsprintf_l(ଅକ୍ଷର *_DstBuf,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsprintf_p_l(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scprintf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scprintf_p_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscprintf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscprintf_p_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _printf_s_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vprintf_s_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fprintf_s_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfprintf_s_l(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sprintf_s_l(ଅକ୍ଷର *_DstBuf,size_t _DstSize,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsprintf_s_l(ଅକ୍ଷର *_DstBuf,size_t _DstSize,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snprintf_s_l(ଅକ୍ଷର *_DstBuf,size_t _DstSize,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnprintf_s_l(ଅକ୍ଷର *_DstBuf,size_t _DstSize,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snprintf_l(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snprintf_c_l(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnprintf_l(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnprintf_c_l(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fwprintf_s(FILE *_File,ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wprintf_s(ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vwprintf_s(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_ଶବ୍ଦଗୁଡ଼ିକ,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wprintf_s_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vwprintf_s_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwprintf_s_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfwprintf_s_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwscanf_s_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swscanf_s_l(ଅଚଳ wchar_t *_Src,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwscanf_s(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwscanf_s_l(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wscanf_s_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwprintf_p(FILE *_File,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wprintf_p(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfwprintf_p(FILE *_File,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vwprintf_p(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf_p(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf_p(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwprintf_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwprintf_p_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfwprintf_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfwprintf_p_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __swprintf_l(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __vswprintf_l(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwscanf_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swscanf_l(ଅଚଳ wchar_t *_Src,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwscanf_l(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wscanf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(ଶୂନ୍ୟ *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t ଗଣନା_6,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
