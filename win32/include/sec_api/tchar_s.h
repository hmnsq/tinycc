/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_TCHAR_S
#تعریف_کرو _INC_TCHAR_S

#شامل <tchar.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_تعریف_شدہ _UNICODE

#تعریف_کرو _tprintf_s wprintf_s
#تعریف_کرو _tprintf_s_l _wprintf_s_l
#تعریف_کرو _tcprintf_s _cwprintf_s
#تعریف_کرو _tcprintf_s_l _cwprintf_s_l
#تعریف_کرو _vtcprintf_s _vcwprintf_s
#تعریف_کرو _vtcprintf_s_l _vcwprintf_s_l
#تعریف_کرو _ftprintf_s fwprintf_s
#تعریف_کرو _ftprintf_s_l _fwprintf_s_l
#تعریف_کرو _stprintf_s swprintf_s
#تعریف_کرو _stprintf_s_l _swprintf_s_l
#تعریف_کرو _sntprintf_s _snwprintf_s
#تعریف_کرو _sntprintf_s_l _snwprintf_s_l
#تعریف_کرو _vtprintf_s vwprintf_s
#تعریف_کرو _vtprintf_s_l _vwprintf_s_l
#تعریف_کرو _vftprintf_s vfwprintf_s
#تعریف_کرو _vftprintf_s_l _vfwprintf_s_l
#تعریف_کرو _vstprintf_s vswprintf_s
#تعریف_کرو _vstprintf_s_l _vswprintf_s_l
#تعریف_کرو _vsntprintf_s _vsnwprintf_s
#تعریف_کرو _vsntprintf_s_l _vsnwprintf_s_l

#تعریف_کرو _tscanf_s wscanf_s
#تعریف_کرو _tscanf_s_l _wscanf_s_l
#تعریف_کرو _tcscanf_s _cwscanf_s
#تعریف_کرو _tcscanf_s_l _cwscanf_s_l
#تعریف_کرو _ftscanf_s fwscanf_s
#تعریف_کرو _ftscanf_s_l _fwscanf_s_l
#تعریف_کرو _stscanf_s swscanf_s
#تعریف_کرو _stscanf_s_l _swscanf_s_l
#تعریف_کرو _sntscanf_s _snwscanf_s
#تعریف_کرو _sntscanf_s_l _snwscanf_s_l

#تعریف_کرو _cgetts_s _cgetws_s
#تعریف_کرو _getts_s _getws_s

#تعریف_کرو _itot_s _itow_s
#تعریف_کرو _ltot_s _ltow_s
#تعریف_کرو _ultot_s _ultow_s
#تعریف_کرو _i64tot_s _i64tow_s
#تعریف_کرو _ui64tot_s _ui64tow_s

#تعریف_کرو _tcscat_s wcscat_s
#تعریف_کرو _tcscpy_s wcscpy_s
#تعریف_کرو _tcsncat_s wcsncat_s
#تعریف_کرو _tcsncat_s_l _wcsncat_s_l
#تعریف_کرو _tcsncpy_s wcsncpy_s
#تعریف_کرو _tcsncpy_s_l _wcsncpy_s_l
#تعریف_کرو _tcstok_s wcstok_s
#تعریف_کرو _tcstok_s_l _wcstok_s_l
#تعریف_کرو _tcserror_s _wcserror_s
#تعریف_کرو __tcserror_s __wcserror_s

#تعریف_کرو _tcsnset_s _wcsnset_s
#تعریف_کرو _tcsnset_s_l _wcsnset_s_l
#تعریف_کرو _tcsset_s _wcsset_s
#تعریف_کرو _tcsset_s_l _wcsset_s_l

#تعریف_کرو _tasctime_s _wasctime_s
#تعریف_کرو _tctime_s _wctime_s
#تعریف_کرو _tctime32_s _wctime32_s
#تعریف_کرو _tctime64_s _wctime64_s
#تعریف_کرو _tstrdate_s _wstrdate_s
#تعریف_کرو _tstrtime_s _wstrtime_s

#تعریف_کرو _tgetenv_s _wgetenv_s
#تعریف_کرو _tdupenv_s _wdupenv_s
#تعریف_کرو _tmakepath_s _wmakepath_s
#تعریف_کرو _tputenv_s _wputenv_s
#تعریف_کرو _tsearchenv_s _wsearchenv_s
#تعریف_کرو _tsplitpath_s _wsplitpath_s

#تعریف_کرو _tfopen_s _wfopen_s
#تعریف_کرو _tfreopen_s _wfreopen_s
#تعریف_کرو _ttmpnam_s _wtmpnam_s
#تعریف_کرو _taccess_s _waccess_s
#تعریف_کرو _tmktemp_s _wmktemp_s

#تعریف_کرو _tcsnccat_s wcsncat_s
#تعریف_کرو _tcsnccat_s_l _wcsncat_s_l
#تعریف_کرو _tcsnccpy_s wcsncpy_s
#تعریف_کرو _tcsnccpy_s_l _wcsncpy_s_l

#تعریف_کرو _tcslwr_s _wcslwr_s
#تعریف_کرو _tcslwr_s_l _wcslwr_s_l
#تعریف_کرو _tcsupr_s _wcsupr_s
#تعریف_کرو _tcsupr_s_l _wcsupr_s_l

#تعریف_کرو _wcstok_s_l(_String,_Delimiters,_Current_position,_Locale) (wcstok_s(_String,_Delimiters,_Current_position))
#تعریف_کرو _wcsnset_s_l(_Destination,Destination_سائز_chars,قدر_2,گنتی_5,_Locale) (_wcsnset_s(_Destination,Destination_سائز_chars,قدر_2,گنتی_5))
#تعریف_کرو _wcsset_s_l(_Destination,Destination_سائز_chars,قدر_2,_Locale) (_wcsset_s(_Destination,Destination_سائز_chars,قدر_2))

#ورنہ

#تعریف_کرو _tprintf_s printf_s
#تعریف_کرو _tprintf_s_l _printf_s_l
#تعریف_کرو _tcprintf_s _cprintf_s
#تعریف_کرو _tcprintf_s_l _cprintf_s_l
#تعریف_کرو _vtcprintf_s _vcprintf_s
#تعریف_کرو _vtcprintf_s_l _vcprintf_s_l
#تعریف_کرو _ftprintf_s fprintf_s
#تعریف_کرو _ftprintf_s_l _fprintf_s_l
#تعریف_کرو _stprintf_s sprintf_s
#تعریف_کرو _stprintf_s_l _sprintf_s_l
#تعریف_کرو _sntprintf_s _snprintf_s
#تعریف_کرو _sntprintf_s_l _snprintf_s_l
#تعریف_کرو _vtprintf_s vprintf_s
#تعریف_کرو _vtprintf_s_l _vprintf_s_l
#تعریف_کرو _vftprintf_s vfprintf_s
#تعریف_کرو _vftprintf_s_l _vfprintf_s_l
#تعریف_کرو _vstprintf_s vsprintf_s
#تعریف_کرو _vstprintf_s_l _vsprintf_s_l
#تعریف_کرو _vsntprintf_s _vsnprintf_s
#تعریف_کرو _vsntprintf_s_l _vsnprintf_s_l
#تعریف_کرو _tscanf_s scanf_s
#تعریف_کرو _tscanf_s_l _scanf_s_l
#تعریف_کرو _tcscanf_s _cscanf_s
#تعریف_کرو _tcscanf_s_l _cscanf_s_l
#تعریف_کرو _ftscanf_s fscanf_s
#تعریف_کرو _ftscanf_s_l _fscanf_s_l
#تعریف_کرو _stscanf_s sscanf_s
#تعریف_کرو _stscanf_s_l _sscanf_s_l
#تعریف_کرو _sntscanf_s _snscanf_s
#تعریف_کرو _sntscanf_s_l _snscanf_s_l

#تعریف_کرو _getts_s gets_s
#تعریف_کرو _cgetts_s _cgets_s
#تعریف_کرو _itot_s _itoa_s
#تعریف_کرو _ltot_s _ltoa_s
#تعریف_کرو _ultot_s _ultoa_s
#تعریف_کرو _i64tot_s _i64toa_s
#تعریف_کرو _ui64tot_s _ui64toa_s

#تعریف_کرو _tcscat_s strcat_s
#تعریف_کرو _tcscpy_s strcpy_s
#تعریف_کرو _tcserror_s strerror_s
#تعریف_کرو __tcserror_s _strerror_s

#تعریف_کرو _tasctime_s asctime_s
#تعریف_کرو _tctime_s ctime_s
#تعریف_کرو _tctime32_s _ctime32_s
#تعریف_کرو _tctime64_s _ctime64_s
#تعریف_کرو _tstrdate_s _strdate_s
#تعریف_کرو _tstrtime_s _strtime_s

#تعریف_کرو _tgetenv_s getenv_s
#تعریف_کرو _tdupenv_s _dupenv_s
#تعریف_کرو _tmakepath_s _makepath_s
#تعریف_کرو _tputenv_s _putenv_s
#تعریف_کرو _tsearchenv_s _searchenv_s
#تعریف_کرو _tsplitpath_s _splitpath_s

#تعریف_کرو _tfopen_s fopen_s
#تعریف_کرو _tfreopen_s freopen_s
#تعریف_کرو _ttmpnam_s tmpnam_s
#تعریف_کرو _tmktemp_s _mktemp_s

#اگر_غیر_تعریف_شدہ _POSIX_
#تعریف_کرو _taccess_s _access_s
#اگر_ختم

#تعریف_کرو _tsopen_s _sopen_s

#اگر_تعریف_شدہ _MBCS

#اگر_تعریف_شدہ MB_MAP_براہ_راست

#تعریف_کرو _tcsncat_s _mbsnbcat_s
#تعریف_کرو _tcsncat_s_l _mbsnbcat_s_l
#تعریف_کرو _tcsncpy_s _mbsnbcpy_s
#تعریف_کرو _tcsncpy_s_l _mbsnbcpy_s_l
#تعریف_کرو _tcstok_s _mbstok_s
#تعریف_کرو _tcstok_s_l _mbstok_s_l

#تعریف_کرو _tcsnset_s _mbsnbset_s
#تعریف_کرو _tcsnset_s_l _mbsnbset_s_l
#تعریف_کرو _tcsset_s _mbsset_s
#تعریف_کرو _tcsset_s_l _mbsset_s_l

#تعریف_کرو _tcsnccat_s _mbsncat_s
#تعریف_کرو _tcsnccat_s_l _mbsncat_s_l
#تعریف_کرو _tcsnccpy_s _mbsncpy_s
#تعریف_کرو _tcsnccpy_s_l _mbsncpy_s_l
#تعریف_کرو _tcsncset_s _mbsnset_s
#تعریف_کرو _tcsncset_s_l _mbsnset_s_l

#تعریف_کرو _tcslwr_s _mbslwr_s
#تعریف_کرو _tcslwr_s_l _mbslwr_s_l
#تعریف_کرو _tcsupr_s _mbsupr_s
#تعریف_کرو _tcsupr_s_l _mbsupr_s_l

#تعریف_کرو _tccpy_s _mbccpy_s
#تعریف_کرو _tccpy_s_l _mbccpy_s_l
#ورنہ

  _CRTIMP حرف *__cdecl _tcsncat_s(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsncat_s_l(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncpy_s(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsncpy_s_l(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcstok_s(حرف *_Str,ثابت حرف *_Delim,حرف **_Context);
  _CRTIMP حرف *__cdecl _tcstok_s_l(حرف *_Str,ثابت حرف *_Delim,حرف **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _tcsset_s(حرف *_Str,سائز_t سائز_اندر_Chars,غیرعلامتی صحیح _Val);
  _CRTIMP errno_t __cdecl _tcsset_s_l(حرف *_Str,سائز_t سائز_اندر_Chars,غیرعلامتی صحیح,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccat_s(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsnccat_s_l(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccpy_s(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsnccpy_s_l(حرف *_Dst,سائز_t Dst_سائز_اندر_Chars,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcslwr_s(حرف *_Str,سائز_t سائز_اندر_Chars);
  _CRTIMP حرف *__cdecl _tcslwr_s_l(حرف *_Str,سائز_t سائز_اندر_Chars,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsupr_s(حرف *_Str,سائز_t سائز_اندر_Chars);
  _CRTIMP حرف *__cdecl _tcsupr_s_l(حرف *_Str,سائز_t سائز_اندر_Chars,_locale_t _Locale);

#اگر_ختم

#ورنہ

#تعریف_کرو _tcsncat_s strncat_s
#تعریف_کرو _tcsncat_s_l _strncat_s_l
#تعریف_کرو _tcsncpy_s strncpy_s
#تعریف_کرو _tcsncpy_s_l _strncpy_s_l
#تعریف_کرو _tcstok_s strtok_s
#تعریف_کرو _tcstok_s_l _strtok_s_l

#تعریف_کرو _tcsnset_s _strnset_s
#تعریف_کرو _tcsnset_s_l _strnset_s_l
#تعریف_کرو _tcsset_s _strset_s
#تعریف_کرو _tcsset_s _strset_s
#تعریف_کرو _tcsset_s_l _strset_s_l

#تعریف_کرو _tcsnccat_s strncat_s
#تعریف_کرو _tcsnccat_s_l _strncat_s_l
#تعریف_کرو _tcsnccpy_s strncpy_s
#تعریف_کرو _tcsnccpy_s_l _strncpy_s_l

#تعریف_کرو _tcslwr_s _strlwr_s
#تعریف_کرو _tcslwr_s_l _strlwr_s_l
#تعریف_کرو _tcsupr_s _strupr_s
#تعریف_کرو _tcsupr_s_l _strupr_s_l

#تعریف_کرو _strnset_s_l(_Destination,Destination_سائز_chars,قدر_2,گنتی_5,_Locale) (_strnset_s(_Destination,Destination_سائز_chars,قدر_2,گنتی_5))
#تعریف_کرو _strset_s_l(_Destination,Destination_سائز_chars,قدر_2,_Locale) (_strset_s(_Destination,Destination_سائز_chars,قدر_2))
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
#اگر_ختم
