/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_WCHAR_S
#تعریف_کرو _INC_WCHAR_S

#شامل <wchar.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WIO_S_DEFINED
#تعریف_کرو _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحیح Access_منوال);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,سائز_t سائز_اندر_الفاظ);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCONIO_S_DEFINED
#تعریف_کرو _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,سائز_t *سائز_Read);
  _CRTIMP صحیح __cdecl _cwprintf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_s(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTDIO_S_DEFINED
#تعریف_کرو _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,سائز_t سائز_اندر_الفاظ);
  صحیح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
  صحیح __cdecl vfwprintf_s(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl vwprintf_s(ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl swprintf_s(wchar_t *_Dst,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,...);
  صحیح __cdecl vswprintf_s(wchar_t *_Dst,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_s(wchar_t *_DstBuf,سائز_t Dst_سائز_اندر_الفاظ,سائز_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_s(wchar_t *_DstBuf,سائز_t Dst_سائز_اندر_الفاظ,سائز_t Max_گنتی,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _wprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vwprintf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfwprintf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_s_l(wchar_t *_DstBuf,سائز_t Dst_سائز,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vswprintf_s_l(wchar_t *_DstBuf,سائز_t Dst_سائز,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_s_l(wchar_t *_DstBuf,سائز_t Dst_سائز,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,سائز_t Dst_سائز,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwscanf_s_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swscanf_s_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snwscanf_s(ثابت wchar_t *_Src,سائز_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _snwscanf_s_l(ثابت wchar_t *_Src,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _wscanf_s_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTDLIB_S_DEFINED
#تعریف_کرو _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (صحیح _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (طویل _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (غیرعلامتی طویل _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(سائز_t *Return_سائز,wchar_t *_DstBuf,سائز_t Dst_سائز_اندر_الفاظ,ثابت wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **بفر_2,سائز_t *بفر_سائز_اندر_الفاظ,ثابت wchar_t *_VarName);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(غیرعلامتی __int64 _Val,wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,صحیح _Radix);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _POSIX_
#اگر_غیر_تعریف_شدہ _WSTDLIBP_S_DEFINED
#تعریف_کرو _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *راستہ_نتیجہ,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(ثابت wchar_t *_Name,ثابت wchar_t *قدر_2);
  _CRTIMP errno_t __cdecl _wsearchenv_s(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_راستہ,سائز_t سائز_اندر_الفاظ);
  _CRTIMP errno_t __cdecl _wsplitpath_s(ثابت wchar_t *بھرا_راستہ,wchar_t *_Drive,سائز_t Drive_سائز_اندر_الفاظ,wchar_t *_Dir,سائز_t Dir_سائز_اندر_الفاظ,wchar_t *_Filename,سائز_t Filename_سائز_اندر_الفاظ,wchar_t *_Ext,سائز_t Ext_سائز_اندر_الفاظ);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTRING_S_DEFINED
#تعریف_کرو _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,ثابت wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,صحیح Err_عدد);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *Err_پیغام);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,سائز_t Dst_سائز_اندر_الفاظ,wchar_t _Val,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,سائز_t سائز_اندر_الفاظ,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,سائز_t سائز_اندر_الفاظ);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,سائز_t سائز_اندر_الفاظ,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,سائز_t سائز_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,سائز_t سائز_4,_locale_t _Locale);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WTIME_S_DEFINED
#تعریف_کرو _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت ساخت tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت __time32_t *وقت_2);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت __time64_t *وقت_2);
#اگر_ختم

#اگر !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#تعریف_کرو _INC_WTIME_S_INL
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,ثابت time_t *وقت_2) { واپس _wctime32_s(بفر_2,سائز_اندر_الفاظ,وقت_2); }
#ورنہ
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *بفر_2,سائز_t سائز_اندر_الفاظ,ثابت time_t *وقت_2) { واپس _wctime64_s(بفر_2,سائز_اندر_الفاظ,وقت_2); }
#اگر_ختم
#اگر_ختم
#اگر_ختم

  _CRTIMP errno_t __cdecl mbsrtowcs_s(سائز_t *_Retval,wchar_t *_Dst,سائز_t سائز_اندر_الفاظ,ثابت حرف **_PSrc,سائز_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(سائز_t *_Retval,حرف *_Dst,سائز_t سائز_اندر_بائٹیں,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(سائز_t *_Retval,حرف *_Dst,سائز_t سائز_اندر_بائٹیں,ثابت wchar_t **_Src,سائز_t سائز_4,mbstate_t *_State);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
#اگر_ختم
