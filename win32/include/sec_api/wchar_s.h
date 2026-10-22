/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_WCHAR_S
#تعریف_کن _INC_WCHAR_S

#ضمن <wchar.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _WIO_S_DEFINED
#تعریف_کن _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_نما);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,اندازه_t اندازه_درون_واژگان);
#پایان_اگر

#اگر_تعریف_نشده _WCONIO_S_DEFINED
#تعریف_کن _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *میانگیر_2,اندازه_t اندازه_درون_واژگان,اندازه_t *اندازه_Read);
  _CRTIMP صحيح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#پایان_اگر

#اگر_تعریف_نشده _WSTDIO_S_DEFINED
#تعریف_کن _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,اندازه_t اندازه_درون_واژگان);
  صحيح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
  صحيح __cdecl vfwprintf_s(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl vwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl swprintf_s(wchar_t *_Dst,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,...);
  صحيح __cdecl vswprintf_s(wchar_t *_Dst,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s(wchar_t *_DstBuf,اندازه_t Dst_اندازه_درون_واژگان,اندازه_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s(wchar_t *_DstBuf,اندازه_t Dst_اندازه_درون_واژگان,اندازه_t Max_شمار,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _wprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,اندازه_t Dst_اندازه,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwscanf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swscanf_s_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf_s(ثابت wchar_t *_Src,اندازه_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_s_l(ثابت wchar_t *_Src,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *نما_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *نما_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان);
#پایان_اگر

#اگر_تعریف_نشده _WSTDLIB_S_DEFINED
#تعریف_کن _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (دراز _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بیعلامت دراز _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(اندازه_t *Return_اندازه,wchar_t *_DstBuf,اندازه_t Dst_اندازه_درون_واژگان,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **میانگیر_2,اندازه_t *میانگیر_اندازه_درون_واژگان,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بیعلامت __int64 _Val,wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,صحيح _Radix);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _POSIX_
#اگر_تعریف_نشده _WSTDLIBP_S_DEFINED
#تعریف_کن _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *مسیر_نتیجه,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *مقدار_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجه_مسیر,اندازه_t اندازه_درون_واژگان);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *پر_مسیر,wchar_t *_Drive,اندازه_t Drive_اندازه_درون_واژگان,wchar_t *_Dir,اندازه_t Dir_اندازه_درون_واژگان,wchar_t *_Filename,اندازه_t Filename_اندازه_درون_واژگان,wchar_t *_Ext,اندازه_t Ext_اندازه_درون_واژگان);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WSTRING_S_DEFINED
#تعریف_کن _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,صحيح Err_رقم);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *میانگیر_2,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *Err_پیام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,اندازه_t Dst_اندازه_درون_واژگان,wchar_t _Val,اندازه_t Max_شمار);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,اندازه_t اندازه_درون_واژگان,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,اندازه_t اندازه_درون_واژگان);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,اندازه_t اندازه_درون_واژگان,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,اندازه_t اندازه_4,_locale_t _Locale);
#پایان_اگر

#اگر_تعریف_نشده _WTIME_S_DEFINED
#تعریف_کن _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت __time32_t *زمان_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت __time64_t *زمان_2);
#پایان_اگر

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کن _INC_WTIME_S_INL
#اگر_تعریف_شده USE_32_بیت_زمان_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *میانگیر_2,اندازه_t اندازه_درون_واژگان,ثابت time_t *زمان_2) { أرجع _wctime32_s(میانگیر_2,اندازه_درون_واژگان,زمان_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *میانگیر_2,اندازه_t اندازه_درون_واژگان,ثابت time_t *زمان_2) { أرجع _wctime64_s(میانگیر_2,اندازه_درون_واژگان,زمان_2); }
#پایان_اگر
#پایان_اگر
#پایان_اگر

  _CRTIMP errno_t __cdecl mbsrtowcs_s(اندازه_t *_Retval,wchar_t *_Dst,اندازه_t اندازه_درون_واژگان,ثابت حرف **_PSrc,اندازه_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(اندازه_t *_Retval,حرف *_Dst,اندازه_t اندازه_درون_بایتها,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(اندازه_t *_Retval,حرف *_Dst,اندازه_t اندازه_درون_بایتها,ثابت wchar_t **_Src,اندازه_t اندازه_4,mbstate_t *_State);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
#پایان_اگر
