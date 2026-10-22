/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO_S
#define _INC_STDIO_S

#അന്തര്ഭാവ <stdio.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _STDIO_S_DEFINED
#define _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl fprintf_s(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,...);
  size_t __cdecl fread_s(ശൂന്യം *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t എണ്ണം_5,FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fscanf_s_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  പൂർണ്ണസംഖ്യ __cdecl printf_s(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scanf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scanf_s_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snprintf_s(അക്ഷരം *_DstBuf,size_t _DstSize,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snprintf_c(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnprintf_c(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl sprintf_s(അക്ഷരം *_DstBuf,size_t _DstSize,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fscanf_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sscanf_l(സ്ഥിരം അക്ഷരം *_Src,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sscanf_s_l(സ്ഥിരം അക്ഷരം *_Src,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snscanf_s(സ്ഥിരം അക്ഷരം *_Src,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snscanf_l(സ്ഥിരം അക്ഷരം *_Src,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snscanf_s_l(സ്ഥിരം അക്ഷരം *_Src,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  പൂർണ്ണസംഖ്യ __cdecl vfprintf_s(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl vprintf_s(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl vsnprintf_s(അക്ഷരം *_DstBuf,size_t _DstSize,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnprintf_s(അക്ഷരം *_DstBuf,size_t _DstSize,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl vsprintf_s(അക്ഷരം *_DstBuf,size_t _Size,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fprintf_p(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _printf_p(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sprintf_p(അക്ഷരം *_Dst,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfprintf_p(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vprintf_p(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsprintf_p(അക്ഷരം *_Dst,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scprintf_p(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscprintf_p(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _printf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _printf_p_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vprintf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vprintf_p_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fprintf_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fprintf_p_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfprintf_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfprintf_p_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sprintf_l(അക്ഷരം *_DstBuf,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sprintf_p_l(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsprintf_l(അക്ഷരം *_DstBuf,സ്ഥിരം അക്ഷരം *_Format,_locale_t,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsprintf_p_l(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scprintf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scprintf_p_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscprintf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscprintf_p_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _printf_s_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vprintf_s_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fprintf_s_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfprintf_s_l(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sprintf_s_l(അക്ഷരം *_DstBuf,size_t _DstSize,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsprintf_s_l(അക്ഷരം *_DstBuf,size_t _DstSize,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snprintf_s_l(അക്ഷരം *_DstBuf,size_t _DstSize,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnprintf_s_l(അക്ഷരം *_DstBuf,size_t _DstSize,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snprintf_l(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snprintf_c_l(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnprintf_l(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnprintf_c_l(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *,_locale_t _Locale,va_list _ArgList);

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_വാക്കുകൾ);
  പൂർണ്ണസംഖ്യ __cdecl fwprintf_s(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl wprintf_s(സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl vwprintf_s(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl swprintf_s(wchar_t *_Dst,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl vswprintf_s(wchar_t *_Dst,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_വാക്കുകൾ,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t Dst_Size_In_വാക്കുകൾ,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wprintf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vwprintf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwprintf_s_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfwprintf_s_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwscanf_s_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swscanf_s_l(സ്ഥിരം wchar_t *_Src,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwscanf_s(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwscanf_s_l(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wscanf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwprintf_p(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wprintf_p(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfwprintf_p(FILE *_File,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vwprintf_p(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf_p(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf_p(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwprintf_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwprintf_p_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfwprintf_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfwprintf_p_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl __swprintf_l(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl __vswprintf_l(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwscanf_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swscanf_l(സ്ഥിരം wchar_t *_Src,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwscanf_l(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wscanf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
#endif
#endif

  _CRTIMP size_t __cdecl _fread_nolock_s(ശൂന്യം *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t എണ്ണം_5,FILE *_File);

#ifdef __cplusplus
}
#endif
#endif
#endif
