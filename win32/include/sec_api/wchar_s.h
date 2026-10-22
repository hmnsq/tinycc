/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR_S
#define _INC_WCHAR_S

#അന്തര്ഭാവ <wchar.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_വാക്കുകൾ);
#endif

#ifndef _WCONIO_S_DEFINED
#define _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,size_t *_SizeRead);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_s(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf_s(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_s(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_s_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_വാക്കുകൾ);
  പൂർണ്ണസംഖ്യ __cdecl fwprintf_s(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl wprintf_s(സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl vfwprintf_s(FILE *_File,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
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
#endif

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (പൂർണ്ണസംഖ്യ _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_VarName);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ _Radix);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Drive,സ്ഥിരം wchar_t *_Dir,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(സ്ഥിരം wchar_t *_Name,സ്ഥിരം wchar_t *മൂല്യം_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_വാക്കുകൾ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(സ്ഥിരം wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_വാക്കുകൾ,wchar_t *_Dir,size_t Dir_Size_In_വാക്കുകൾ,wchar_t *_Filename,size_t Filename_Size_In_വാക്കുകൾ,wchar_t *_Ext,size_t Ext_Size_In_വാക്കുകൾ);
#endif
#endif

#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,സ്ഥിരം wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,പൂർണ്ണസംഖ്യ Err_അക്കം);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *Err_സന്ദേശം);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_വാക്കുകൾ,wchar_t _Val,size_t Max_എണ്ണം);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_വാക്കുകൾ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_വാക്കുകൾ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_വാക്കുകൾ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം __time64_t *_Time);
#endif

#എങ്കിൽ !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,സ്ഥിരം time_t *_Time) { തിരികെ _wctime32_s(_Buffer,Size_In_വാക്കുകൾ,_Time); }
#അല്ലെങ്കിൽ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_വാക്കുകൾ,സ്ഥിരം time_t *_Time) { തിരികെ _wctime64_s(_Buffer,Size_In_വാക്കുകൾ,_Time); }
#endif
#endif
#endif

  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t Size_In_വാക്കുകൾ,സ്ഥിരം അക്ഷരം **_PSrc,size_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval,അക്ഷരം *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval,അക്ഷരം *_Dst,size_t _SizeInBytes,സ്ഥിരം wchar_t **_Src,size_t _Size,mbstate_t *_State);

#ifdef __cplusplus
}
#endif

#endif
#endif
