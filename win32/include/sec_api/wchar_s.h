/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_WCHAR_S
#تعریف_کرو _INC_WCHAR_S

#ضمن <wchar.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _WIO_S_DEFINED
#تعریف_کرو _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_منوال);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,ناپ_t ناپ_وچ_الفاظ);
#جے_انت

#جے_بنا_تعریف _WCONIO_S_DEFINED
#تعریف_کرو _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *بفر_2,ناپ_t ناپ_وچ_الفاظ,ناپ_t *ناپ_Read);
  _CRTIMP صحيح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#جے_انت

#جے_بنا_تعریف _WSTDIO_S_DEFINED
#تعریف_کرو _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,ناپ_t ناپ_وچ_الفاظ);
  صحيح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
  صحيح __cdecl vfwprintf_s(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl vwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl swprintf_s(wchar_t *_Dst,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,...);
  صحيح __cdecl vswprintf_s(wchar_t *_Dst,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s(wchar_t *_DstBuf,ناپ_t Dst_ناپ_وچ_الفاظ,ناپ_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s(wchar_t *_DstBuf,ناپ_t Dst_ناپ_وچ_الفاظ,ناپ_t Max_گنتی,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _wprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_s_l(wchar_t *_DstBuf,ناپ_t Dst_ناپ,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_s_l(wchar_t *_DstBuf,ناپ_t Dst_ناپ,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_s_l(wchar_t *_DstBuf,ناپ_t Dst_ناپ,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,ناپ_t Dst_ناپ,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwscanf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swscanf_s_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf_s(ثابت wchar_t *_Src,ناپ_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_s_l(ثابت wchar_t *_Src,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ);
#جے_انت

#جے_بنا_تعریف _WSTDLIB_S_DEFINED
#تعریف_کرو _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحيح _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (لما _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (بنانشانی لما _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(ناپ_t *Return_ناپ,wchar_t *_DstBuf,ناپ_t Dst_ناپ_وچ_الفاظ,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,ناپ_t *بفر_ناپ_وچ_الفاظ,ثابت wchar_t *_VarName);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(بنانشانی __int64 _Val,wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,صحيح _Radix);
#جے_انت
#جے_انت

#جے_بنا_تعریف _POSIX_
#جے_بنا_تعریف _WSTDLIBP_S_DEFINED
#تعریف_کرو _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *رستہ_نتیجہ,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *قدر_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_رستہ,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *بھریا_رستہ,wchar_t *_Drive,ناپ_t Drive_ناپ_وچ_الفاظ,wchar_t *_Dir,ناپ_t Dir_ناپ_وچ_الفاظ,wchar_t *_Filename,ناپ_t Filename_ناپ_وچ_الفاظ,wchar_t *_Ext,ناپ_t Ext_ناپ_وچ_الفاظ);
#جے_انت
#جے_انت

#جے_بنا_تعریف _WSTRING_S_DEFINED
#تعریف_کرو _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,صحيح Err_عدد);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *Err_پیغام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,ناپ_t Dst_ناپ_وچ_الفاظ,wchar_t _Val,ناپ_t Max_گنتی);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,ناپ_t ناپ_وچ_الفاظ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,ناپ_t ناپ_وچ_الفاظ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,ناپ_t ناپ_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,ناپ_t ناپ_4,_locale_t _Locale);
#جے_انت

#جے_بنا_تعریف _WTIME_S_DEFINED
#تعریف_کرو _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت بنية tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت __time32_t *ویلا_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت __time64_t *ویلا_2);
#جے_انت

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کرو _INC_WTIME_S_INL
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,ناپ_t ناپ_وچ_الفاظ,ثابت time_t *ویلا_2) { أرجع _wctime32_s(بفر_2,ناپ_وچ_الفاظ,ویلا_2); }
#وإلا
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,ناپ_t ناپ_وچ_الفاظ,ثابت time_t *ویلا_2) { أرجع _wctime64_s(بفر_2,ناپ_وچ_الفاظ,ویلا_2); }
#جے_انت
#جے_انت
#جے_انت

  _CRTIMP errno_t __cdecl mbsrtowcs_s(ناپ_t *_Retval,wchar_t *_Dst,ناپ_t ناپ_وچ_الفاظ,ثابت حرف **_PSrc,ناپ_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(ناپ_t *_Retval,حرف *_Dst,ناپ_t ناپ_وچ_بائٹاں,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(ناپ_t *_Retval,حرف *_Dst,ناپ_t ناپ_وچ_بائٹاں,ثابت wchar_t **_Src,ناپ_t ناپ_4,mbstate_t *_State);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
#جے_انت
