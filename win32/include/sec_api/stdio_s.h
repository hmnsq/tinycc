/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#شامل <stdio.h>

#اگر defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  صحیح __cdecl fprintf_s(FILE *_File,ثابت نویسه *_Format,...);
  size_t __cdecl fread_s(تهی *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t شمار_5,FILE *_File);
  _CRTIMP صحیح __cdecl _fscanf_s_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,...);
  صحیح __cdecl printf_s(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _scanf_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scanf_s_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snprintf_s(نویسه *_DstBuf,size_t _DstSize,size_t Max_شمار,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _snprintf_c(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _vsnprintf_c(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,va_list _ArgList);
  صحیح __cdecl sprintf_s(نویسه *_DstBuf,size_t _DstSize,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _fscanf_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _sscanf_l(ثابت نویسه *_Src,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _sscanf_s_l(ثابت نویسه *_Src,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snscanf_s(ثابت نویسه *_Src,size_t Max_شمار,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _snscanf_l(ثابت نویسه *_Src,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snscanf_s_l(ثابت نویسه *_Src,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,...);
  صحیح __cdecl vfprintf_s(FILE *_File,ثابت نویسه *_Format,va_list _ArgList);
  صحیح __cdecl vprintf_s(ثابت نویسه *_Format,va_list _ArgList);
  صحیح __cdecl vsnprintf_s(نویسه *_DstBuf,size_t _DstSize,size_t Max_شمار,ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsnprintf_s(نویسه *_DstBuf,size_t _DstSize,size_t Max_شمار,ثابت نویسه *_Format,va_list _ArgList);
  صحیح __cdecl vsprintf_s(نویسه *_DstBuf,size_t _Size,ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fprintf_p(FILE *_File,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _printf_p(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _sprintf_p(نویسه *_Dst,size_t Max_شمار,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _vfprintf_p(FILE *_File,ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vprintf_p(ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsprintf_p(نویسه *_Dst,size_t Max_شمار,ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scprintf_p(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _vscprintf_p(ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _printf_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _printf_p_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vprintf_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vprintf_p_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fprintf_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _fprintf_p_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfprintf_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vfprintf_p_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _sprintf_l(نویسه *_DstBuf,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _sprintf_p_l(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsprintf_l(نویسه *_DstBuf,ثابت نویسه *_Format,_locale_t,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsprintf_p_l(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scprintf_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scprintf_p_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vscprintf_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vscprintf_p_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _printf_s_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vprintf_s_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fprintf_s_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfprintf_s_l(FILE *_File,ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _sprintf_s_l(نویسه *_DstBuf,size_t _DstSize,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsprintf_s_l(نویسه *_DstBuf,size_t _DstSize,ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snprintf_s_l(نویسه *_DstBuf,size_t _DstSize,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnprintf_s_l(نویسه *_DstBuf,size_t _DstSize,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snprintf_l(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snprintf_c_l(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnprintf_l(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsnprintf_c_l(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_واژگان);
  صحیح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
  صحیح __cdecl vwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_واژگان,ثابت wchar_t *_Format,...);
  صحیح __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_واژگان,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_واژگان,size_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_واژگان,size_t Max_شمار,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _wprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwscanf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swscanf_s_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snwscanf_s(ثابت wchar_t *_Src,size_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _snwscanf_s_l(ثابت wchar_t *_Src,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _wscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_واژگان);
  _CRTIMP صحیح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vscwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _wprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _wprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _fwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vfwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحیح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP صحیح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snwscanf_l(ثابت wchar_t *_Src,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(تهی *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t شمار_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
