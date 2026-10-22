/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_WCHAR_S
#تعریف_کړه _INC_WCHAR_S

#ضمن <wchar.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _WIO_S_DEFINED
#تعریف_کړه _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_ډېرپېښ);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,اندازه_t اندازه_دننه_ټکي);
#د_که_پای

#که_نه_تعریف_شوی _WCONIO_S_DEFINED
#تعریف_کړه _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,اندازه_t *اندازه_Read);
  _CRTIMP صحيح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#د_که_پای

#که_نه_تعریف_شوی _WSTDIO_S_DEFINED
#تعریف_کړه _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,اندازه_t اندازه_دننه_ټکي);
  صحيح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
  صحيح __cdecl vfwprintf_s(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl vwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl swprintf_s(wchar_t *_Dst,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Format,...);
  صحيح __cdecl vswprintf_s(wchar_t *_Dst,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s(wchar_t *_DstBuf,اندازه_t Dst_اندازه_دننه_ټکي,اندازه_t Max_شمېر,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s(wchar_t *_DstBuf,اندازه_t Dst_اندازه_دننه_ټکي,اندازه_t Max_شمېر,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _wprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,اندازه_t Max_شمېر,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,اندازه_t Max_شمېر,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwscanf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swscanf_s_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf_s(ثابت wchar_t *_Src,اندازه_t Max_شمېر,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_s_l(ثابت wchar_t *_Src,اندازه_t Max_شمېر,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *ډېرپېښ_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *ډېرپېښ_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي);
#د_که_پای

#که_نه_تعریف_شوی _WSTDLIB_S_DEFINED
#تعریف_کړه _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (اوږد _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بینښه اوږد _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(اندازه_t *Return_اندازه,wchar_t *_DstBuf,اندازه_t Dst_اندازه_دننه_ټکي,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,اندازه_t *بفر_اندازه_دننه_ټکي,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بینښه __int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,صحيح _Radix);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _POSIX_
#که_نه_تعریف_شوی _WSTDLIBP_S_DEFINED
#تعریف_کړه _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *لار_پایله,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *ارزښت_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *پایله_لار,اندازه_t اندازه_دننه_ټکي);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *ډک_لار,wchar_t *_Drive,اندازه_t Drive_اندازه_دننه_ټکي,wchar_t *_Dir,اندازه_t Dir_اندازه_دننه_ټکي,wchar_t *_Filename,اندازه_t Filename_اندازه_دننه_ټکي,wchar_t *_Ext,اندازه_t Ext_اندازه_دننه_ټکي);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _WSTRING_S_DEFINED
#تعریف_کړه _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,صحيح Err_عدد);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *Err_پیغام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,اندازه_t Dst_اندازه_دننه_ټکي,wchar_t _Val,اندازه_t Max_شمېر);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,اندازه_t اندازه_دننه_ټکي,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,اندازه_t اندازه_دننه_ټکي);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,اندازه_t اندازه_دننه_ټکي,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,اندازه_t اندازه_4,_locale_t _Locale);
#د_که_پای

#که_نه_تعریف_شوی _WTIME_S_DEFINED
#تعریف_کړه _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت __time32_t *وخت_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,اندازه_t اندازه_دننه_ټکي,ثابت __time64_t *وخت_2);
#د_که_پای

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کړه _INC_WTIME_S_INL
#که_تعریف_شوی USE_32_بټ_وخت_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,ثابت time_t *وخت_2) { أرجع _wctime32_s(بفر_2,اندازه_دننه_ټکي,وخت_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,اندازه_t اندازه_دننه_ټکي,ثابت time_t *وخت_2) { أرجع _wctime64_s(بفر_2,اندازه_دننه_ټکي,وخت_2); }
#د_که_پای
#د_که_پای
#د_که_پای

  _CRTIMP errno_t __cdecl mbsrtowcs_s(اندازه_t *_Retval,wchar_t *_Dst,اندازه_t اندازه_دننه_ټکي,ثابت حرف **_PSrc,اندازه_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(اندازه_t *_Retval,حرف *_Dst,اندازه_t اندازه_دننه_بایټونه,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(اندازه_t *_Retval,حرف *_Dst,اندازه_t اندازه_دننه_بایټونه,ثابت wchar_t **_Src,اندازه_t اندازه_4,mbstate_t *_State);

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
#د_که_پای
