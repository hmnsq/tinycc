/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_STDIO_S
#تعریف_کرو _INC_STDIO_S

#شامل <stdio.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _STDIO_S_DEFINED
#تعریف_کرو _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  صحیح __cdecl fprintf_s(FILE *_File,ثابت حرف *_Format,...);
  سائز_t __cdecl fread_s(خالی *_DstBuf,سائز_t Dst_سائز,سائز_t Element_سائز,سائز_t گنتی_5,FILE *_File);
  _CRTIMP صحیح __cdecl _fscanf_s_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  صحیح __cdecl printf_s(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _scanf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scanf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snprintf_s(حرف *_DstBuf,سائز_t Dst_سائز,سائز_t Max_گنتی,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _snprintf_c(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _vsnprintf_c(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,va_list _ArgList);
  صحیح __cdecl sprintf_s(حرف *_DstBuf,سائز_t Dst_سائز,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _fscanf_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _sscanf_l(ثابت حرف *_Src,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _sscanf_s_l(ثابت حرف *_Src,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snscanf_s(ثابت حرف *_Src,سائز_t Max_گنتی,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _snscanf_l(ثابت حرف *_Src,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snscanf_s_l(ثابت حرف *_Src,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,...);
  صحیح __cdecl vfprintf_s(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  صحیح __cdecl vprintf_s(ثابت حرف *_Format,va_list _ArgList);
  صحیح __cdecl vsnprintf_s(حرف *_DstBuf,سائز_t Dst_سائز,سائز_t Max_گنتی,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsnprintf_s(حرف *_DstBuf,سائز_t Dst_سائز,سائز_t Max_گنتی,ثابت حرف *_Format,va_list _ArgList);
  صحیح __cdecl vsprintf_s(حرف *_DstBuf,سائز_t سائز_4,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fprintf_p(FILE *_File,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _printf_p(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _sprintf_p(حرف *_Dst,سائز_t Max_گنتی,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _vfprintf_p(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vprintf_p(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsprintf_p(حرف *_Dst,سائز_t Max_گنتی,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scprintf_p(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _vscprintf_p(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _printf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _printf_p_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vprintf_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fprintf_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _fprintf_p_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfprintf_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vfprintf_p_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _sprintf_l(حرف *_DstBuf,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _sprintf_p_l(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsprintf_l(حرف *_DstBuf,ثابت حرف *_Format,_locale_t,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsprintf_p_l(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scprintf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vscprintf_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vscprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _printf_s_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vprintf_s_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fprintf_s_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfprintf_s_l(FILE *_File,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _sprintf_s_l(حرف *_DstBuf,سائز_t Dst_سائز,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsprintf_s_l(حرف *_DstBuf,سائز_t Dst_سائز,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snprintf_s_l(حرف *_DstBuf,سائز_t Dst_سائز,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnprintf_s_l(حرف *_DstBuf,سائز_t Dst_سائز,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snprintf_l(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snprintf_c_l(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnprintf_l(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vsnprintf_c_l(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *,_locale_t _Locale,va_list _ArgList);

#اگر_غیر_تعریف_شدہ _WSTDIO_S_DEFINED
#تعریف_کرو _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,سائز_t سائز_اندر_الفاظ);
  صحیح __cdecl fwprintf_s(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl wprintf_s(ثابت wchar_t *_Format,...);
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
  _CRTIMP صحیح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_p(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_p(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,va_list _ArgList);
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
  _CRTIMP صحیح __cdecl _swprintf_c_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swprintf_p_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحیح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list دلائل_2);
  _CRTIMP صحیح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snwscanf_l(ثابت wchar_t *_Src,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
#اگر_ختم
#اگر_ختم

  _CRTIMP سائز_t __cdecl _fread_nolock_s(خالی *_DstBuf,سائز_t Dst_سائز,سائز_t Element_سائز,سائز_t گنتی_5,FILE *_File);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
#اگر_ختم
