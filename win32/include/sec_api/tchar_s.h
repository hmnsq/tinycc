/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_TCHAR_S
#నిర్వచించు _INC_TCHAR_S

#అన్తర్భావ <tchar.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితమైతే _UNICODE

#నిర్వచించు _tprintf_s wprintf_s
#నిర్వచించు _tprintf_s_l _wprintf_s_l
#నిర్వచించు _tcprintf_s _cwprintf_s
#నిర్వచించు _tcprintf_s_l _cwprintf_s_l
#నిర్వచించు _vtcprintf_s _vcwprintf_s
#నిర్వచించు _vtcprintf_s_l _vcwprintf_s_l
#నిర్వచించు _ftprintf_s fwprintf_s
#నిర్వచించు _ftprintf_s_l _fwprintf_s_l
#నిర్వచించు _stprintf_s swprintf_s
#నిర్వచించు _stprintf_s_l _swprintf_s_l
#నిర్వచించు _sntprintf_s _snwprintf_s
#నిర్వచించు _sntprintf_s_l _snwprintf_s_l
#నిర్వచించు _vtprintf_s vwprintf_s
#నిర్వచించు _vtprintf_s_l _vwprintf_s_l
#నిర్వచించు _vftprintf_s vfwprintf_s
#నిర్వచించు _vftprintf_s_l _vfwprintf_s_l
#నిర్వచించు _vstprintf_s vswprintf_s
#నిర్వచించు _vstprintf_s_l _vswprintf_s_l
#నిర్వచించు _vsntprintf_s _vsnwprintf_s
#నిర్వచించు _vsntprintf_s_l _vsnwprintf_s_l

#నిర్వచించు _tscanf_s wscanf_s
#నిర్వచించు _tscanf_s_l _wscanf_s_l
#నిర్వచించు _tcscanf_s _cwscanf_s
#నిర్వచించు _tcscanf_s_l _cwscanf_s_l
#నిర్వచించు _ftscanf_s fwscanf_s
#నిర్వచించు _ftscanf_s_l _fwscanf_s_l
#నిర్వచించు _stscanf_s swscanf_s
#నిర్వచించు _stscanf_s_l _swscanf_s_l
#నిర్వచించు _sntscanf_s _snwscanf_s
#నిర్వచించు _sntscanf_s_l _snwscanf_s_l

#నిర్వచించు _cgetts_s _cgetws_s
#నిర్వచించు _getts_s _getws_s

#నిర్వచించు _itot_s _itow_s
#నిర్వచించు _ltot_s _ltow_s
#నిర్వచించు _ultot_s _ultow_s
#నిర్వచించు _i64tot_s _i64tow_s
#నిర్వచించు _ui64tot_s _ui64tow_s

#నిర్వచించు _tcscat_s wcscat_s
#నిర్వచించు _tcscpy_s wcscpy_s
#నిర్వచించు _tcsncat_s wcsncat_s
#నిర్వచించు _tcsncat_s_l _wcsncat_s_l
#నిర్వచించు _tcsncpy_s wcsncpy_s
#నిర్వచించు _tcsncpy_s_l _wcsncpy_s_l
#నిర్వచించు _tcstok_s wcstok_s
#నిర్వచించు _tcstok_s_l _wcstok_s_l
#నిర్వచించు _tcserror_s _wcserror_s
#నిర్వచించు __tcserror_s __wcserror_s

#నిర్వచించు _tcsnset_s _wcsnset_s
#నిర్వచించు _tcsnset_s_l _wcsnset_s_l
#నిర్వచించు _tcsset_s _wcsset_s
#నిర్వచించు _tcsset_s_l _wcsset_s_l

#నిర్వచించు _tasctime_s _wasctime_s
#నిర్వచించు _tctime_s _wctime_s
#నిర్వచించు _tctime32_s _wctime32_s
#నిర్వచించు _tctime64_s _wctime64_s
#నిర్వచించు _tstrdate_s _wstrdate_s
#నిర్వచించు _tstrtime_s _wstrtime_s

#నిర్వచించు _tgetenv_s _wgetenv_s
#నిర్వచించు _tdupenv_s _wdupenv_s
#నిర్వచించు _tmakepath_s _wmakepath_s
#నిర్వచించు _tputenv_s _wputenv_s
#నిర్వచించు _tsearchenv_s _wsearchenv_s
#నిర్వచించు _tsplitpath_s _wsplitpath_s

#నిర్వచించు _tfopen_s _wfopen_s
#నిర్వచించు _tfreopen_s _wfreopen_s
#నిర్వచించు _ttmpnam_s _wtmpnam_s
#నిర్వచించు _taccess_s _waccess_s
#నిర్వచించు _tmktemp_s _wmktemp_s

#నిర్వచించు _tcsnccat_s wcsncat_s
#నిర్వచించు _tcsnccat_s_l _wcsncat_s_l
#నిర్వచించు _tcsnccpy_s wcsncpy_s
#నిర్వచించు _tcsnccpy_s_l _wcsncpy_s_l

#నిర్వచించు _tcslwr_s _wcslwr_s
#నిర్వచించు _tcslwr_s_l _wcslwr_s_l
#నిర్వచించు _tcsupr_s _wcsupr_s
#నిర్వచించు _tcsupr_s_l _wcsupr_s_l

#నిర్వచించు _wcstok_s_l(_String,_Delimiters,_Current_position,_Locale) (wcstok_s(_String,_Delimiters,_Current_position))
#నిర్వచించు _wcsnset_s_l(_Destination,Destination_కొలత_chars,విలువ_2,లెక్క_5,_Locale) (_wcsnset_s(_Destination,Destination_కొలత_chars,విలువ_2,లెక్క_5))
#నిర్వచించు _wcsset_s_l(_Destination,Destination_కొలత_chars,విలువ_2,_Locale) (_wcsset_s(_Destination,Destination_కొలత_chars,విలువ_2))

#లేకపోతే

#నిర్వచించు _tprintf_s printf_s
#నిర్వచించు _tprintf_s_l _printf_s_l
#నిర్వచించు _tcprintf_s _cprintf_s
#నిర్వచించు _tcprintf_s_l _cprintf_s_l
#నిర్వచించు _vtcprintf_s _vcprintf_s
#నిర్వచించు _vtcprintf_s_l _vcprintf_s_l
#నిర్వచించు _ftprintf_s fprintf_s
#నిర్వచించు _ftprintf_s_l _fprintf_s_l
#నిర్వచించు _stprintf_s sprintf_s
#నిర్వచించు _stprintf_s_l _sprintf_s_l
#నిర్వచించు _sntprintf_s _snprintf_s
#నిర్వచించు _sntprintf_s_l _snprintf_s_l
#నిర్వచించు _vtprintf_s vprintf_s
#నిర్వచించు _vtprintf_s_l _vprintf_s_l
#నిర్వచించు _vftprintf_s vfprintf_s
#నిర్వచించు _vftprintf_s_l _vfprintf_s_l
#నిర్వచించు _vstprintf_s vsprintf_s
#నిర్వచించు _vstprintf_s_l _vsprintf_s_l
#నిర్వచించు _vsntprintf_s _vsnprintf_s
#నిర్వచించు _vsntprintf_s_l _vsnprintf_s_l
#నిర్వచించు _tscanf_s scanf_s
#నిర్వచించు _tscanf_s_l _scanf_s_l
#నిర్వచించు _tcscanf_s _cscanf_s
#నిర్వచించు _tcscanf_s_l _cscanf_s_l
#నిర్వచించు _ftscanf_s fscanf_s
#నిర్వచించు _ftscanf_s_l _fscanf_s_l
#నిర్వచించు _stscanf_s sscanf_s
#నిర్వచించు _stscanf_s_l _sscanf_s_l
#నిర్వచించు _sntscanf_s _snscanf_s
#నిర్వచించు _sntscanf_s_l _snscanf_s_l

#నిర్వచించు _getts_s gets_s
#నిర్వచించు _cgetts_s _cgets_s
#నిర్వచించు _itot_s _itoa_s
#నిర్వచించు _ltot_s _ltoa_s
#నిర్వచించు _ultot_s _ultoa_s
#నిర్వచించు _i64tot_s _i64toa_s
#నిర్వచించు _ui64tot_s _ui64toa_s

#నిర్వచించు _tcscat_s strcat_s
#నిర్వచించు _tcscpy_s strcpy_s
#నిర్వచించు _tcserror_s strerror_s
#నిర్వచించు __tcserror_s _strerror_s

#నిర్వచించు _tasctime_s asctime_s
#నిర్వచించు _tctime_s ctime_s
#నిర్వచించు _tctime32_s _ctime32_s
#నిర్వచించు _tctime64_s _ctime64_s
#నిర్వచించు _tstrdate_s _strdate_s
#నిర్వచించు _tstrtime_s _strtime_s

#నిర్వచించు _tgetenv_s getenv_s
#నిర్వచించు _tdupenv_s _dupenv_s
#నిర్వచించు _tmakepath_s _makepath_s
#నిర్వచించు _tputenv_s _putenv_s
#నిర్వచించు _tsearchenv_s _searchenv_s
#నిర్వచించు _tsplitpath_s _splitpath_s

#నిర్వచించు _tfopen_s fopen_s
#నిర్వచించు _tfreopen_s freopen_s
#నిర్వచించు _ttmpnam_s tmpnam_s
#నిర్వచించు _tmktemp_s _mktemp_s

#నిర్వచితం_కాకపోతే _POSIX_
#నిర్వచించు _taccess_s _access_s
#అయితే_ముగింపు

#నిర్వచించు _tsopen_s _sopen_s

#నిర్వచితమైతే _MBCS

#నిర్వచితమైతే MB_MAP_ప్రత్యక్ష

#నిర్వచించు _tcsncat_s _mbsnbcat_s
#నిర్వచించు _tcsncat_s_l _mbsnbcat_s_l
#నిర్వచించు _tcsncpy_s _mbsnbcpy_s
#నిర్వచించు _tcsncpy_s_l _mbsnbcpy_s_l
#నిర్వచించు _tcstok_s _mbstok_s
#నిర్వచించు _tcstok_s_l _mbstok_s_l

#నిర్వచించు _tcsnset_s _mbsnbset_s
#నిర్వచించు _tcsnset_s_l _mbsnbset_s_l
#నిర్వచించు _tcsset_s _mbsset_s
#నిర్వచించు _tcsset_s_l _mbsset_s_l

#నిర్వచించు _tcsnccat_s _mbsncat_s
#నిర్వచించు _tcsnccat_s_l _mbsncat_s_l
#నిర్వచించు _tcsnccpy_s _mbsncpy_s
#నిర్వచించు _tcsnccpy_s_l _mbsncpy_s_l
#నిర్వచించు _tcsncset_s _mbsnset_s
#నిర్వచించు _tcsncset_s_l _mbsnset_s_l

#నిర్వచించు _tcslwr_s _mbslwr_s
#నిర్వచించు _tcslwr_s_l _mbslwr_s_l
#నిర్వచించు _tcsupr_s _mbsupr_s
#నిర్వచించు _tcsupr_s_l _mbsupr_s_l

#నిర్వచించు _tccpy_s _mbccpy_s
#నిర్వచించు _tccpy_s_l _mbccpy_s_l
#లేకపోతే

  _CRTIMP అక్షరం *__cdecl _tcsncat_s(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsncat_s_l(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsncpy_s(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsncpy_s_l(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcstok_s(అక్షరం *_Str,స్థిరరాశి అక్షరం *_Delim,అక్షరం **_Context);
  _CRTIMP అక్షరం *__cdecl _tcstok_s_l(అక్షరం *_Str,స్థిరరాశి అక్షరం *_Delim,అక్షరం **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _tcsset_s(అక్షరం *_Str,కొలత_t కొలత_లోపల_Chars,గుర్తులేని పూర్ణాంకం _Val);
  _CRTIMP errno_t __cdecl _tcsset_s_l(అక్షరం *_Str,కొలత_t కొలత_లోపల_Chars,గుర్తులేని పూర్ణాంకం,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsnccat_s(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsnccat_s_l(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsnccpy_s(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsnccpy_s_l(అక్షరం *_Dst,కొలత_t Dst_కొలత_లోపల_Chars,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcslwr_s(అక్షరం *_Str,కొలత_t కొలత_లోపల_Chars);
  _CRTIMP అక్షరం *__cdecl _tcslwr_s_l(అక్షరం *_Str,కొలత_t కొలత_లోపల_Chars,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsupr_s(అక్షరం *_Str,కొలత_t కొలత_లోపల_Chars);
  _CRTIMP అక్షరం *__cdecl _tcsupr_s_l(అక్షరం *_Str,కొలత_t కొలత_లోపల_Chars,_locale_t _Locale);

#అయితే_ముగింపు

#లేకపోతే

#నిర్వచించు _tcsncat_s strncat_s
#నిర్వచించు _tcsncat_s_l _strncat_s_l
#నిర్వచించు _tcsncpy_s strncpy_s
#నిర్వచించు _tcsncpy_s_l _strncpy_s_l
#నిర్వచించు _tcstok_s strtok_s
#నిర్వచించు _tcstok_s_l _strtok_s_l

#నిర్వచించు _tcsnset_s _strnset_s
#నిర్వచించు _tcsnset_s_l _strnset_s_l
#నిర్వచించు _tcsset_s _strset_s
#నిర్వచించు _tcsset_s _strset_s
#నిర్వచించు _tcsset_s_l _strset_s_l

#నిర్వచించు _tcsnccat_s strncat_s
#నిర్వచించు _tcsnccat_s_l _strncat_s_l
#నిర్వచించు _tcsnccpy_s strncpy_s
#నిర్వచించు _tcsnccpy_s_l _strncpy_s_l

#నిర్వచించు _tcslwr_s _strlwr_s
#నిర్వచించు _tcslwr_s_l _strlwr_s_l
#నిర్వచించు _tcsupr_s _strupr_s
#నిర్వచించు _tcsupr_s_l _strupr_s_l

#నిర్వచించు _strnset_s_l(_Destination,Destination_కొలత_chars,విలువ_2,లెక్క_5,_Locale) (_strnset_s(_Destination,Destination_కొలత_chars,విలువ_2,లెక్క_5))
#నిర్వచించు _strset_s_l(_Destination,Destination_కొలత_chars,విలువ_2,_Locale) (_strset_s(_Destination,Destination_కొలత_chars,విలువ_2))
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
