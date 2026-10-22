/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_TCHAR_S
#परिभाषय _INC_TCHAR_S

#अन्तर्भाव <tchar.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_परिभाषितम् _UNICODE

#परिभाषय _tprintf_s wprintf_s
#परिभाषय _tprintf_s_l _wprintf_s_l
#परिभाषय _tcprintf_s _cwprintf_s
#परिभाषय _tcprintf_s_l _cwprintf_s_l
#परिभाषय _vtcprintf_s _vcwprintf_s
#परिभाषय _vtcprintf_s_l _vcwprintf_s_l
#परिभाषय _ftprintf_s fwprintf_s
#परिभाषय _ftprintf_s_l _fwprintf_s_l
#परिभाषय _stprintf_s swprintf_s
#परिभाषय _stprintf_s_l _swprintf_s_l
#परिभाषय _sntprintf_s _snwprintf_s
#परिभाषय _sntprintf_s_l _snwprintf_s_l
#परिभाषय _vtprintf_s vwprintf_s
#परिभाषय _vtprintf_s_l _vwprintf_s_l
#परिभाषय _vftprintf_s vfwprintf_s
#परिभाषय _vftprintf_s_l _vfwprintf_s_l
#परिभाषय _vstprintf_s vswprintf_s
#परिभाषय _vstprintf_s_l _vswprintf_s_l
#परिभाषय _vsntprintf_s _vsnwprintf_s
#परिभाषय _vsntprintf_s_l _vsnwprintf_s_l

#परिभाषय _tscanf_s wscanf_s
#परिभाषय _tscanf_s_l _wscanf_s_l
#परिभाषय _tcscanf_s _cwscanf_s
#परिभाषय _tcscanf_s_l _cwscanf_s_l
#परिभाषय _ftscanf_s fwscanf_s
#परिभाषय _ftscanf_s_l _fwscanf_s_l
#परिभाषय _stscanf_s swscanf_s
#परिभाषय _stscanf_s_l _swscanf_s_l
#परिभाषय _sntscanf_s _snwscanf_s
#परिभाषय _sntscanf_s_l _snwscanf_s_l

#परिभाषय _cgetts_s _cgetws_s
#परिभाषय _getts_s _getws_s

#परिभाषय _itot_s _itow_s
#परिभाषय _ltot_s _ltow_s
#परिभाषय _ultot_s _ultow_s
#परिभाषय _i64tot_s _i64tow_s
#परिभाषय _ui64tot_s _ui64tow_s

#परिभाषय _tcscat_s wcscat_s
#परिभाषय _tcscpy_s wcscpy_s
#परिभाषय _tcsncat_s wcsncat_s
#परिभाषय _tcsncat_s_l _wcsncat_s_l
#परिभाषय _tcsncpy_s wcsncpy_s
#परिभाषय _tcsncpy_s_l _wcsncpy_s_l
#परिभाषय _tcstok_s wcstok_s
#परिभाषय _tcstok_s_l _wcstok_s_l
#परिभाषय _tcserror_s _wcserror_s
#परिभाषय __tcserror_s __wcserror_s

#परिभाषय _tcsnset_s _wcsnset_s
#परिभाषय _tcsnset_s_l _wcsnset_s_l
#परिभाषय _tcsset_s _wcsset_s
#परिभाषय _tcsset_s_l _wcsset_s_l

#परिभाषय _tasctime_s _wasctime_s
#परिभाषय _tctime_s _wctime_s
#परिभाषय _tctime32_s _wctime32_s
#परिभाषय _tctime64_s _wctime64_s
#परिभाषय _tstrdate_s _wstrdate_s
#परिभाषय _tstrtime_s _wstrtime_s

#परिभाषय _tgetenv_s _wgetenv_s
#परिभाषय _tdupenv_s _wdupenv_s
#परिभाषय _tmakepath_s _wmakepath_s
#परिभाषय _tputenv_s _wputenv_s
#परिभाषय _tsearchenv_s _wsearchenv_s
#परिभाषय _tsplitpath_s _wsplitpath_s

#परिभाषय _tfopen_s _wfopen_s
#परिभाषय _tfreopen_s _wfreopen_s
#परिभाषय _ttmpnam_s _wtmpnam_s
#परिभाषय _taccess_s _waccess_s
#परिभाषय _tmktemp_s _wmktemp_s

#परिभाषय _tcsnccat_s wcsncat_s
#परिभाषय _tcsnccat_s_l _wcsncat_s_l
#परिभाषय _tcsnccpy_s wcsncpy_s
#परिभाषय _tcsnccpy_s_l _wcsncpy_s_l

#परिभाषय _tcslwr_s _wcslwr_s
#परिभाषय _tcslwr_s_l _wcslwr_s_l
#परिभाषय _tcsupr_s _wcsupr_s
#परिभाषय _tcsupr_s_l _wcsupr_s_l

#परिभाषय _wcstok_s_l(_String,_Delimiters,_Current_position,_Locale) (wcstok_s(_String,_Delimiters,_Current_position))
#परिभाषय _wcsnset_s_l(_Destination,Destination_आकार_chars,मानम्_2,गणनम्_5,_Locale) (_wcsnset_s(_Destination,Destination_आकार_chars,मानम्_2,गणनम्_5))
#परिभाषय _wcsset_s_l(_Destination,Destination_आकार_chars,मानम्_2,_Locale) (_wcsset_s(_Destination,Destination_आकार_chars,मानम्_2))

#अन्यथा

#परिभाषय _tprintf_s printf_s
#परिभाषय _tprintf_s_l _printf_s_l
#परिभाषय _tcprintf_s _cprintf_s
#परिभाषय _tcprintf_s_l _cprintf_s_l
#परिभाषय _vtcprintf_s _vcprintf_s
#परिभाषय _vtcprintf_s_l _vcprintf_s_l
#परिभाषय _ftprintf_s fprintf_s
#परिभाषय _ftprintf_s_l _fprintf_s_l
#परिभाषय _stprintf_s sprintf_s
#परिभाषय _stprintf_s_l _sprintf_s_l
#परिभाषय _sntprintf_s _snprintf_s
#परिभाषय _sntprintf_s_l _snprintf_s_l
#परिभाषय _vtprintf_s vprintf_s
#परिभाषय _vtprintf_s_l _vprintf_s_l
#परिभाषय _vftprintf_s vfprintf_s
#परिभाषय _vftprintf_s_l _vfprintf_s_l
#परिभाषय _vstprintf_s vsprintf_s
#परिभाषय _vstprintf_s_l _vsprintf_s_l
#परिभाषय _vsntprintf_s _vsnprintf_s
#परिभाषय _vsntprintf_s_l _vsnprintf_s_l
#परिभाषय _tscanf_s scanf_s
#परिभाषय _tscanf_s_l _scanf_s_l
#परिभाषय _tcscanf_s _cscanf_s
#परिभाषय _tcscanf_s_l _cscanf_s_l
#परिभाषय _ftscanf_s fscanf_s
#परिभाषय _ftscanf_s_l _fscanf_s_l
#परिभाषय _stscanf_s sscanf_s
#परिभाषय _stscanf_s_l _sscanf_s_l
#परिभाषय _sntscanf_s _snscanf_s
#परिभाषय _sntscanf_s_l _snscanf_s_l

#परिभाषय _getts_s gets_s
#परिभाषय _cgetts_s _cgets_s
#परिभाषय _itot_s _itoa_s
#परिभाषय _ltot_s _ltoa_s
#परिभाषय _ultot_s _ultoa_s
#परिभाषय _i64tot_s _i64toa_s
#परिभाषय _ui64tot_s _ui64toa_s

#परिभाषय _tcscat_s strcat_s
#परिभाषय _tcscpy_s strcpy_s
#परिभाषय _tcserror_s strerror_s
#परिभाषय __tcserror_s _strerror_s

#परिभाषय _tasctime_s asctime_s
#परिभाषय _tctime_s ctime_s
#परिभाषय _tctime32_s _ctime32_s
#परिभाषय _tctime64_s _ctime64_s
#परिभाषय _tstrdate_s _strdate_s
#परिभाषय _tstrtime_s _strtime_s

#परिभाषय _tgetenv_s getenv_s
#परिभाषय _tdupenv_s _dupenv_s
#परिभाषय _tmakepath_s _makepath_s
#परिभाषय _tputenv_s _putenv_s
#परिभाषय _tsearchenv_s _searchenv_s
#परिभाषय _tsplitpath_s _splitpath_s

#परिभाषय _tfopen_s fopen_s
#परिभाषय _tfreopen_s freopen_s
#परिभाषय _ttmpnam_s tmpnam_s
#परिभाषय _tmktemp_s _mktemp_s

#यदि_अपरिभाषितम् _POSIX_
#परिभाषय _taccess_s _access_s
#यदि_अन्तः

#परिभाषय _tsopen_s _sopen_s

#यदि_परिभाषितम् _MBCS

#यदि_परिभाषितम् MB_MAP_प्रत्यक्षम्

#परिभाषय _tcsncat_s _mbsnbcat_s
#परिभाषय _tcsncat_s_l _mbsnbcat_s_l
#परिभाषय _tcsncpy_s _mbsnbcpy_s
#परिभाषय _tcsncpy_s_l _mbsnbcpy_s_l
#परिभाषय _tcstok_s _mbstok_s
#परिभाषय _tcstok_s_l _mbstok_s_l

#परिभाषय _tcsnset_s _mbsnbset_s
#परिभाषय _tcsnset_s_l _mbsnbset_s_l
#परिभाषय _tcsset_s _mbsset_s
#परिभाषय _tcsset_s_l _mbsset_s_l

#परिभाषय _tcsnccat_s _mbsncat_s
#परिभाषय _tcsnccat_s_l _mbsncat_s_l
#परिभाषय _tcsnccpy_s _mbsncpy_s
#परिभाषय _tcsnccpy_s_l _mbsncpy_s_l
#परिभाषय _tcsncset_s _mbsnset_s
#परिभाषय _tcsncset_s_l _mbsnset_s_l

#परिभाषय _tcslwr_s _mbslwr_s
#परिभाषय _tcslwr_s_l _mbslwr_s_l
#परिभाषय _tcsupr_s _mbsupr_s
#परिभाषय _tcsupr_s_l _mbsupr_s_l

#परिभाषय _tccpy_s _mbccpy_s
#परिभाषय _tccpy_s_l _mbccpy_s_l
#अन्यथा

  _CRTIMP वर्ण *__cdecl _tcsncat_s(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsncat_s_l(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsncpy_s(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsncpy_s_l(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcstok_s(वर्ण *_Str,ध्रुव वर्ण *_Delim,वर्ण **_Context);
  _CRTIMP वर्ण *__cdecl _tcstok_s_l(वर्ण *_Str,ध्रुव वर्ण *_Delim,वर्ण **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _tcsset_s(वर्ण *_Str,आकार_t आकार_अन्तर्_Chars,अचिह्नित पूर्णाङ्क _Val);
  _CRTIMP errno_t __cdecl _tcsset_s_l(वर्ण *_Str,आकार_t आकार_अन्तर्_Chars,अचिह्नित पूर्णाङ्क,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsnccat_s(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsnccat_s_l(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsnccpy_s(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsnccpy_s_l(वर्ण *_Dst,आकार_t Dst_आकार_अन्तर्_Chars,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcslwr_s(वर्ण *_Str,आकार_t आकार_अन्तर्_Chars);
  _CRTIMP वर्ण *__cdecl _tcslwr_s_l(वर्ण *_Str,आकार_t आकार_अन्तर्_Chars,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsupr_s(वर्ण *_Str,आकार_t आकार_अन्तर्_Chars);
  _CRTIMP वर्ण *__cdecl _tcsupr_s_l(वर्ण *_Str,आकार_t आकार_अन्तर्_Chars,_locale_t _Locale);

#यदि_अन्तः

#अन्यथा

#परिभाषय _tcsncat_s strncat_s
#परिभाषय _tcsncat_s_l _strncat_s_l
#परिभाषय _tcsncpy_s strncpy_s
#परिभाषय _tcsncpy_s_l _strncpy_s_l
#परिभाषय _tcstok_s strtok_s
#परिभाषय _tcstok_s_l _strtok_s_l

#परिभाषय _tcsnset_s _strnset_s
#परिभाषय _tcsnset_s_l _strnset_s_l
#परिभाषय _tcsset_s _strset_s
#परिभाषय _tcsset_s _strset_s
#परिभाषय _tcsset_s_l _strset_s_l

#परिभाषय _tcsnccat_s strncat_s
#परिभाषय _tcsnccat_s_l _strncat_s_l
#परिभाषय _tcsnccpy_s strncpy_s
#परिभाषय _tcsnccpy_s_l _strncpy_s_l

#परिभाषय _tcslwr_s _strlwr_s
#परिभाषय _tcslwr_s_l _strlwr_s_l
#परिभाषय _tcsupr_s _strupr_s
#परिभाषय _tcsupr_s_l _strupr_s_l

#परिभाषय _strnset_s_l(_Destination,Destination_आकार_chars,मानम्_2,गणनम्_5,_Locale) (_strnset_s(_Destination,Destination_आकार_chars,मानम्_2,गणनम्_5))
#परिभाषय _strset_s_l(_Destination,Destination_आकार_chars,मानम्_2,_Locale) (_strset_s(_Destination,Destination_आकार_chars,मानम्_2))
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
