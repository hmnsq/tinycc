/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#அந்தர்பாவ <stdio.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  முழு __cdecl fprintf_s(FILE *_File,மாறிலி எழுத்து *_Format,...);
  size_t __cdecl fread_s(வெறுமை *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t மொத்தம்_5,FILE *_File);
  _CRTIMP முழு __cdecl _fscanf_s_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  முழு __cdecl printf_s(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _scanf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _scanf_s_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _snprintf_s(எழுத்து *_DstBuf,size_t _DstSize,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _snprintf_c(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _vsnprintf_c(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,va_list _ArgList);
  முழு __cdecl sprintf_s(எழுத்து *_DstBuf,size_t _DstSize,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _fscanf_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _sscanf_l(மாறிலி எழுத்து *_Src,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _sscanf_s_l(மாறிலி எழுத்து *_Src,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _snscanf_s(மாறிலி எழுத்து *_Src,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _snscanf_l(மாறிலி எழுத்து *_Src,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _snscanf_s_l(மாறிலி எழுத்து *_Src,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  முழு __cdecl vfprintf_s(FILE *_File,மாறிலி எழுத்து *_Format,va_list _ArgList);
  முழு __cdecl vprintf_s(மாறிலி எழுத்து *_Format,va_list _ArgList);
  முழு __cdecl vsnprintf_s(எழுத்து *_DstBuf,size_t _DstSize,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _vsnprintf_s(எழுத்து *_DstBuf,size_t _DstSize,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,va_list _ArgList);
  முழு __cdecl vsprintf_s(எழுத்து *_DstBuf,size_t _Size,மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _fprintf_p(FILE *_File,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _printf_p(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _sprintf_p(எழுத்து *_Dst,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _vfprintf_p(FILE *_File,மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _vprintf_p(மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _vsprintf_p(எழுத்து *_Dst,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _scprintf_p(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _vscprintf_p(மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _printf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _printf_p_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vprintf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vprintf_p_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _fprintf_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _fprintf_p_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vfprintf_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vfprintf_p_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _sprintf_l(எழுத்து *_DstBuf,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _sprintf_p_l(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vsprintf_l(எழுத்து *_DstBuf,மாறிலி எழுத்து *_Format,_locale_t,va_list _ArgList);
  _CRTIMP முழு __cdecl _vsprintf_p_l(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _scprintf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _scprintf_p_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vscprintf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vscprintf_p_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _printf_s_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vprintf_s_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _fprintf_s_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vfprintf_s_l(FILE *_File,மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _sprintf_s_l(எழுத்து *_DstBuf,size_t _DstSize,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vsprintf_s_l(எழுத்து *_DstBuf,size_t _DstSize,மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _snprintf_s_l(எழுத்து *_DstBuf,size_t _DstSize,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vsnprintf_s_l(எழுத்து *_DstBuf,size_t _DstSize,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _snprintf_l(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _snprintf_c_l(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vsnprintf_l(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vsnprintf_c_l(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_சொற்கள்);
  முழு __cdecl fwprintf_s(FILE *_File,மாறிலி wchar_t *_Format,...);
  முழு __cdecl wprintf_s(மாறிலி wchar_t *_Format,...);
  முழு __cdecl vwprintf_s(மாறிலி wchar_t *_Format,va_list _ArgList);
  முழு __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,...);
  முழு __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_சொற்கள்,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_சொற்கள்,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _wprintf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vwprintf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _fwprintf_s_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vfwprintf_s_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _fwscanf_s_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _swscanf_s_l(மாறிலி wchar_t *_Src,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _snwscanf_s(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _snwscanf_s_l(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _wscanf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_சொற்கள்);
  _CRTIMP முழு __cdecl _fwprintf_p(FILE *_File,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _wprintf_p(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vfwprintf_p(FILE *_File,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _vwprintf_p(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _scwprintf_p(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vscwprintf_p(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _wprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _wprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _fwprintf_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _fwprintf_p_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vfwprintf_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vfwprintf_p_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _scwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _scwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vscwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl __swprintf_l(wchar_t *_Dest,மாறிலி wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP முழு __cdecl __vswprintf_l(wchar_t *_Dest,மாறிலி wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP முழு __cdecl _vscwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _fwscanf_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _swscanf_l(மாறிலி wchar_t *_Src,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _snwscanf_l(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _wscanf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(வெறுமை *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t மொத்தம்_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
