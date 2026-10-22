/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR_S
#define _INC_WCHAR_S

#অন্তর্ভাৱ <wchar.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ধ্রুৱ wchar_t *_Filename,পূর্ণাঙ্ক _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_শব্দগুলি);
#endif

#ifndef _WCONIO_S_DEFINED
#define _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,size_t *_SizeRead);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_s(ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf_s(ধ্রুৱ wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf_s_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_s(ধ্রুৱ wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_s_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_s_l(ধ্রুৱ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#endif

#ifndef _WSTDIO_S_DEFINED
#define _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t Size_In_শব্দগুলি);
  পূর্ণাঙ্ক __cdecl fwprintf_s(FILE *_File,ধ্রুৱ wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl wprintf_s(ধ্রুৱ wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl vfwprintf_s(FILE *_File,ধ্রুৱ wchar_t *_Format,va_list _ArgList);
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
#endif

#ifndef _WSTDLIB_S_DEFINED
#define _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (পূর্ণাঙ্ক _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (long _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t Dst_Size_In_শব্দগুলি,ধ্রুৱ wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *Buffer_Size_In_শব্দগুলি,ধ্রুৱ wchar_t *_VarName);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64 _Val,wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক _Radix);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_S_DEFINED
#define _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t Size_In_শব্দগুলি,ধ্রুৱ wchar_t *_Drive,ধ্রুৱ wchar_t *_Dir,ধ্রুৱ wchar_t *_Filename,ধ্রুৱ wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ধ্রুৱ wchar_t *_Name,ধ্রুৱ wchar_t *মান_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ধ্রুৱ wchar_t *_Filename,ধ্রুৱ wchar_t *_EnvVar,wchar_t *_ResultPath,size_t Size_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ধ্রুৱ wchar_t *_FullPath,wchar_t *_Drive,size_t Drive_Size_In_শব্দগুলি,wchar_t *_Dir,size_t Dir_Size_In_শব্দগুলি,wchar_t *_Filename,size_t Filename_Size_In_শব্দগুলি,wchar_t *_Ext,size_t Ext_Size_In_শব্দগুলি);
#endif
#endif

#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ধ্রুৱ wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,পূর্ণাঙ্ক Err_অঙ্ক);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,ধ্রুৱ wchar_t *Err_বাৰ্তা);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t Dst_Size_In_শব্দগুলি,wchar_t _Val,size_t Max_গুনতি);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t Size_In_শব্দগুলি,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t Size_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t Size_In_শব্দগুলি,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুৱ সংরচনা tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুৱ __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুৱ __time64_t *_Time);
#endif

#যদি !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,ধ্রুৱ time_t *_Time) { ঘূৰাই _wctime32_s(_Buffer,Size_In_শব্দগুলি,_Time); }
#অন্যথা
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t Size_In_শব্দগুলি,ধ্রুৱ time_t *_Time) { ঘূৰাই _wctime64_s(_Buffer,Size_In_শব্দগুলি,_Time); }
#endif
#endif
#endif

  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t Size_In_শব্দগুলি,ধ্রুৱ ৱর্ণ **_PSrc,size_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval,ৱর্ণ *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval,ৱর্ণ *_Dst,size_t _SizeInBytes,ধ্রুৱ wchar_t **_Src,size_t _Size,mbstate_t *_State);

#ifdef __cplusplus
}
#endif

#endif
#endif
