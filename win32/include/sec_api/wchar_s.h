/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_WCHAR_S
#وصف_ڪريو _INC_WCHAR_S

#ضمن <wchar.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WIO_S_DEFINED
#وصف_ڪريو _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_گهڻائي);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,سائيز_t سائيز_اندريون_لفظ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCONIO_S_DEFINED
#وصف_ڪريو _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,سائيز_t *سائيز_Read);
  _CRTIMP صحيح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTDIO_S_DEFINED
#وصف_ڪريو _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,سائيز_t سائيز_اندريون_لفظ);
  صحيح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
  صحيح __cdecl vfwprintf_s(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl vwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl swprintf_s(wchar_t *_Dst,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,...);
  صحيح __cdecl vswprintf_s(wchar_t *_Dst,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s(wchar_t *_DstBuf,سائيز_t Dst_سائيز_اندريون_لفظ,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s(wchar_t *_DstBuf,سائيز_t Dst_سائيز_اندريون_لفظ,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _wprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_s_l(wchar_t *_DstBuf,سائيز_t Dst_سائيز,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_s_l(wchar_t *_DstBuf,سائيز_t Dst_سائيز,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s_l(wchar_t *_DstBuf,سائيز_t Dst_سائيز,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,سائيز_t Dst_سائيز,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwscanf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swscanf_s_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf_s(ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_s_l(ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTDLIB_S_DEFINED
#وصف_ڪريو _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (ڊگهو _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بنانشان ڊگهو _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(سائيز_t *Return_سائيز,wchar_t *_DstBuf,سائيز_t Dst_سائيز_اندريون_لفظ,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,سائيز_t *بفر_سائيز_اندريون_لفظ,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بنانشان __int64 _Val,wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,صحيح _Radix);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _POSIX_
#جيڪڏهن_وصف_نه_ٿيل _WSTDLIBP_S_DEFINED
#وصف_ڪريو _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *رستو_نتيجو,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *قدر_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتيجو_رستو,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *ڀريل_رستو,wchar_t *_Drive,سائيز_t Drive_سائيز_اندريون_لفظ,wchar_t *_Dir,سائيز_t Dir_سائيز_اندريون_لفظ,wchar_t *_Filename,سائيز_t Filename_سائيز_اندريون_لفظ,wchar_t *_Ext,سائيز_t Ext_سائيز_اندريون_لفظ);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTRING_S_DEFINED
#وصف_ڪريو _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,صحيح Err_انگ);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *Err_نياپو);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,سائيز_t Dst_سائيز_اندريون_لفظ,wchar_t _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,سائيز_t سائيز_اندريون_لفظ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,سائيز_t سائيز_اندريون_لفظ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,سائيز_t سائيز_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,سائيز_t سائيز_4,_locale_t _Locale);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WTIME_S_DEFINED
#وصف_ڪريو _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت __time64_t *وقت_2);
#جيڪڏهن_پورو

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#وصف_ڪريو _INC_WTIME_S_INL
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,ثابت time_t *وقت_2) { أرجع _wctime32_s(بفر_2,سائيز_اندريون_لفظ,وقت_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائيز_t سائيز_اندريون_لفظ,ثابت time_t *وقت_2) { أرجع _wctime64_s(بفر_2,سائيز_اندريون_لفظ,وقت_2); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl mbsrtowcs_s(سائيز_t *_Retval,wchar_t *_Dst,سائيز_t سائيز_اندريون_لفظ,ثابت حرف **_PSrc,سائيز_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(سائيز_t *_Retval,حرف *_Dst,سائيز_t سائيز_اندريون_بائيٽون,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(سائيز_t *_Retval,حرف *_Dst,سائيز_t سائيز_اندريون_بائيٽون,ثابت wchar_t **_Src,سائيز_t سائيز_4,mbstate_t *_State);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو
