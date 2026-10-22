/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#ضمن <stdio.h>

#אם defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  صحيح __cdecl fprintf_s(FILE *_File,ثابت حرف *_Format,...);
  size_t __cdecl fread_s(فراغ *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP صحيح __cdecl _fscanf_s_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  صحيح __cdecl printf_s(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _scanf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _scanf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snprintf_s(حرف *_DstBuf,size_t _DstSize,size_t _MaxCount,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _snprintf_c(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vsnprintf_c(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl sprintf_s(حرف *_DstBuf,size_t _DstSize,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _fscanf_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _sscanf_l(ثابت حرف *_Src,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _sscanf_s_l(ثابت حرف *_Src,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snscanf_s(ثابت حرف *_Src,size_t _MaxCount,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _snscanf_l(ثابت حرف *_Src,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snscanf_s_l(ثابت حرف *_Src,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,...);
  صحيح __cdecl vfprintf_s(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl vprintf_s(ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl vsnprintf_s(حرف *_DstBuf,size_t _DstSize,size_t _MaxCount,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vsnprintf_s(حرف *_DstBuf,size_t _DstSize,size_t _MaxCount,ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl vsprintf_s(حرف *_DstBuf,size_t _Size,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fprintf_p(FILE *_File,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _printf_p(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _sprintf_p(حرف *_Dst,size_t _MaxCount,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vfprintf_p(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vprintf_p(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vsprintf_p(حرف *_Dst,size_t _MaxCount,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scprintf_p(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vscprintf_p(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _printf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _printf_p_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vprintf_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fprintf_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _fprintf_p_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfprintf_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vfprintf_p_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _sprintf_l(حرف *_DstBuf,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _sprintf_p_l(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsprintf_l(حرف *_DstBuf,ثابت حرف *_Format,_locale_t,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vsprintf_p_l(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scprintf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _scprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vscprintf_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vscprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _printf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fprintf_s_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfprintf_s_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _sprintf_s_l(حرف *_DstBuf,size_t _DstSize,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsprintf_s_l(حرف *_DstBuf,size_t _DstSize,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snprintf_s_l(حرف *_DstBuf,size_t _DstSize,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnprintf_s_l(حرف *_DstBuf,size_t _DstSize,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snprintf_l(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snprintf_c_l(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnprintf_l(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vsnprintf_c_l(حرف *_DstBuf,size_t _MaxCount,ثابت حرف *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t _SizeInWords);
  صحيح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
  صحيح __cdecl vwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl swprintf_s(wchar_t *_Dst,size_t _SizeInWords,ثابت wchar_t *_Format,...);
  صحيح __cdecl vswprintf_s(wchar_t *_Dst,size_t _SizeInWords,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _wprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwscanf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swscanf_s_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf_s(ثابت wchar_t *_Src,size_t _MaxCount,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_s_l(ثابت wchar_t *_Src,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t _SizeInWords);
  _CRTIMP صحيح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vscwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _wprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _fwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vfwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحيح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP صحيح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf_l(ثابت wchar_t *_Src,size_t _MaxCount,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(فراغ *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
