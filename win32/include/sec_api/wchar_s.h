/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR_S
#define _INC_WCHAR_S

#அந்தர்பாவ <wchar.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(மாறிலி wchar_t *_Filename,முழு _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_சொற்கள்);
#endif

#ifndef _WCONIO_S_DEFINED
#define _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_சொற்கள்,size_t *_SizeRead);
  _CRTIMP முழு __cdecl _cwprintf_s(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf_s(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_s(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cwprintf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_s_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_சொற்கள்);
  முழு __cdecl fwprintf_s(FILE *_File,மாறிலி wchar_t *_Format,...);
  முழு __cdecl wprintf_s(மாறிலி wchar_t *_Format,...);
  முழு __cdecl vfwprintf_s(FILE *_File,மாறிலி wchar_t *_Format,va_list _ArgList);
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
#endif

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (முழு _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_சொற்கள்,மாறிலி wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_சொற்கள்,மாறிலி wchar_t *_VarName);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_சொற்கள்,முழு _Radix);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Drive,மாறிலி wchar_t *_Dir,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(மாறிலி wchar_t *_Name,மாறிலி wchar_t *மதிப்பு_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_சொற்கள்);
  _CRTIMP errno_t __cdecl _wsplitpath_s(மாறிலி wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_சொற்கள்,wchar_t *_Dir,size_t Dir_Size_In_சொற்கள்,wchar_t *_Filename,size_t Filename_Size_In_சொற்கள்,wchar_t *_Ext,size_t Ext_Size_In_சொற்கள்);
#endif
#endif

#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,மாறிலி wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_சொற்கள்,முழு Err_இலக்கம்);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_சொற்கள்,மாறிலி wchar_t *Err_செய்தி);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_சொற்கள்,wchar_t _Val,size_t Max_மொத்தம்);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_சொற்கள்,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_சொற்கள்);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_சொற்கள்,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_சொற்கள்,மாறிலி கட்டமைப்பு tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_சொற்கள்,மாறிலி __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_சொற்கள்);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_சொற்கள்);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_சொற்கள்,மாறிலி __time64_t *_Time);
#endif

#எனில் !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_சொற்கள்,மாறிலி time_t *_Time) { திரும்பு _wctime32_s(_Buffer,Size_In_சொற்கள்,_Time); }
#இல்லையெனில்
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_சொற்கள்,மாறிலி time_t *_Time) { திரும்பு _wctime64_s(_Buffer,Size_In_சொற்கள்,_Time); }
#endif
#endif
#endif

  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t Size_In_சொற்கள்,மாறிலி எழுத்து **_PSrc,size_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval,எழுத்து *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval,எழுத்து *_Dst,size_t _SizeInBytes,மாறிலி wchar_t **_Src,size_t _Size,mbstate_t *_State);

#ifdef __cplusplus
}
#endif

#endif
#endif
