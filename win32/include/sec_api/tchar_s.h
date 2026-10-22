/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_TCHAR_S
#घोषणा _INC_TCHAR_S

#समावेश <tchar.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_घोषित _UNICODE

#घोषणा _tprintf_s wprintf_s
#घोषणा _tprintf_s_l _wprintf_s_l
#घोषणा _tcprintf_s _cwprintf_s
#घोषणा _tcprintf_s_l _cwprintf_s_l
#घोषणा _vtcprintf_s _vcwprintf_s
#घोषणा _vtcprintf_s_l _vcwprintf_s_l
#घोषणा _ftprintf_s fwprintf_s
#घोषणा _ftprintf_s_l _fwprintf_s_l
#घोषणा _stprintf_s swprintf_s
#घोषणा _stprintf_s_l _swprintf_s_l
#घोषणा _sntprintf_s _snwprintf_s
#घोषणा _sntprintf_s_l _snwprintf_s_l
#घोषणा _vtprintf_s vwprintf_s
#घोषणा _vtprintf_s_l _vwprintf_s_l
#घोषणा _vftprintf_s vfwprintf_s
#घोषणा _vftprintf_s_l _vfwprintf_s_l
#घोषणा _vstprintf_s vswprintf_s
#घोषणा _vstprintf_s_l _vswprintf_s_l
#घोषणा _vsntprintf_s _vsnwprintf_s
#घोषणा _vsntprintf_s_l _vsnwprintf_s_l

#घोषणा _tscanf_s wscanf_s
#घोषणा _tscanf_s_l _wscanf_s_l
#घोषणा _tcscanf_s _cwscanf_s
#घोषणा _tcscanf_s_l _cwscanf_s_l
#घोषणा _ftscanf_s fwscanf_s
#घोषणा _ftscanf_s_l _fwscanf_s_l
#घोषणा _stscanf_s swscanf_s
#घोषणा _stscanf_s_l _swscanf_s_l
#घोषणा _sntscanf_s _snwscanf_s
#घोषणा _sntscanf_s_l _snwscanf_s_l

#घोषणा _cgetts_s _cgetws_s
#घोषणा _getts_s _getws_s

#घोषणा _itot_s _itow_s
#घोषणा _ltot_s _ltow_s
#घोषणा _ultot_s _ultow_s
#घोषणा _i64tot_s _i64tow_s
#घोषणा _ui64tot_s _ui64tow_s

#घोषणा _tcscat_s wcscat_s
#घोषणा _tcscpy_s wcscpy_s
#घोषणा _tcsncat_s wcsncat_s
#घोषणा _tcsncat_s_l _wcsncat_s_l
#घोषणा _tcsncpy_s wcsncpy_s
#घोषणा _tcsncpy_s_l _wcsncpy_s_l
#घोषणा _tcstok_s wcstok_s
#घोषणा _tcstok_s_l _wcstok_s_l
#घोषणा _tcserror_s _wcserror_s
#घोषणा __tcserror_s __wcserror_s

#घोषणा _tcsnset_s _wcsnset_s
#घोषणा _tcsnset_s_l _wcsnset_s_l
#घोषणा _tcsset_s _wcsset_s
#घोषणा _tcsset_s_l _wcsset_s_l

#घोषणा _tasctime_s _wasctime_s
#घोषणा _tctime_s _wctime_s
#घोषणा _tctime32_s _wctime32_s
#घोषणा _tctime64_s _wctime64_s
#घोषणा _tstrdate_s _wstrdate_s
#घोषणा _tstrtime_s _wstrtime_s

#घोषणा _tgetenv_s _wgetenv_s
#घोषणा _tdupenv_s _wdupenv_s
#घोषणा _tmakepath_s _wmakepath_s
#घोषणा _tputenv_s _wputenv_s
#घोषणा _tsearchenv_s _wsearchenv_s
#घोषणा _tsplitpath_s _wsplitpath_s

#घोषणा _tfopen_s _wfopen_s
#घोषणा _tfreopen_s _wfreopen_s
#घोषणा _ttmpnam_s _wtmpnam_s
#घोषणा _taccess_s _waccess_s
#घोषणा _tmktemp_s _wmktemp_s

#घोषणा _tcsnccat_s wcsncat_s
#घोषणा _tcsnccat_s_l _wcsncat_s_l
#घोषणा _tcsnccpy_s wcsncpy_s
#घोषणा _tcsnccpy_s_l _wcsncpy_s_l

#घोषणा _tcslwr_s _wcslwr_s
#घोषणा _tcslwr_s_l _wcslwr_s_l
#घोषणा _tcsupr_s _wcsupr_s
#घोषणा _tcsupr_s_l _wcsupr_s_l

#घोषणा _wcstok_s_l(_String,_Delimiters,_Current_position,_Locale) (wcstok_s(_String,_Delimiters,_Current_position))
#घोषणा _wcsnset_s_l(_Destination,Destination_आकार_chars,मूल्य_2,गिनती_5,_Locale) (_wcsnset_s(_Destination,Destination_आकार_chars,मूल्य_2,गिनती_5))
#घोषणा _wcsset_s_l(_Destination,Destination_आकार_chars,मूल्य_2,_Locale) (_wcsset_s(_Destination,Destination_आकार_chars,मूल्य_2))

#अन्यथा

#घोषणा _tprintf_s printf_s
#घोषणा _tprintf_s_l _printf_s_l
#घोषणा _tcprintf_s _cprintf_s
#घोषणा _tcprintf_s_l _cprintf_s_l
#घोषणा _vtcprintf_s _vcprintf_s
#घोषणा _vtcprintf_s_l _vcprintf_s_l
#घोषणा _ftprintf_s fprintf_s
#घोषणा _ftprintf_s_l _fprintf_s_l
#घोषणा _stprintf_s sprintf_s
#घोषणा _stprintf_s_l _sprintf_s_l
#घोषणा _sntprintf_s _snprintf_s
#घोषणा _sntprintf_s_l _snprintf_s_l
#घोषणा _vtprintf_s vprintf_s
#घोषणा _vtprintf_s_l _vprintf_s_l
#घोषणा _vftprintf_s vfprintf_s
#घोषणा _vftprintf_s_l _vfprintf_s_l
#घोषणा _vstprintf_s vsprintf_s
#घोषणा _vstprintf_s_l _vsprintf_s_l
#घोषणा _vsntprintf_s _vsnprintf_s
#घोषणा _vsntprintf_s_l _vsnprintf_s_l
#घोषणा _tscanf_s scanf_s
#घोषणा _tscanf_s_l _scanf_s_l
#घोषणा _tcscanf_s _cscanf_s
#घोषणा _tcscanf_s_l _cscanf_s_l
#घोषणा _ftscanf_s fscanf_s
#घोषणा _ftscanf_s_l _fscanf_s_l
#घोषणा _stscanf_s sscanf_s
#घोषणा _stscanf_s_l _sscanf_s_l
#घोषणा _sntscanf_s _snscanf_s
#घोषणा _sntscanf_s_l _snscanf_s_l

#घोषणा _getts_s gets_s
#घोषणा _cgetts_s _cgets_s
#घोषणा _itot_s _itoa_s
#घोषणा _ltot_s _ltoa_s
#घोषणा _ultot_s _ultoa_s
#घोषणा _i64tot_s _i64toa_s
#घोषणा _ui64tot_s _ui64toa_s

#घोषणा _tcscat_s strcat_s
#घोषणा _tcscpy_s strcpy_s
#घोषणा _tcserror_s strerror_s
#घोषणा __tcserror_s _strerror_s

#घोषणा _tasctime_s asctime_s
#घोषणा _tctime_s ctime_s
#घोषणा _tctime32_s _ctime32_s
#घोषणा _tctime64_s _ctime64_s
#घोषणा _tstrdate_s _strdate_s
#घोषणा _tstrtime_s _strtime_s

#घोषणा _tgetenv_s getenv_s
#घोषणा _tdupenv_s _dupenv_s
#घोषणा _tmakepath_s _makepath_s
#घोषणा _tputenv_s _putenv_s
#घोषणा _tsearchenv_s _searchenv_s
#घोषणा _tsplitpath_s _splitpath_s

#घोषणा _tfopen_s fopen_s
#घोषणा _tfreopen_s freopen_s
#घोषणा _ttmpnam_s tmpnam_s
#घोषणा _tmktemp_s _mktemp_s

#अगर_अघोषित _POSIX_
#घोषणा _taccess_s _access_s
#पूर्ण_अगर

#घोषणा _tsopen_s _sopen_s

#अगर_घोषित _MBCS

#अगर_घोषित _MB_MAP_DIRECT

#घोषणा _tcsncat_s _mbsnbcat_s
#घोषणा _tcsncat_s_l _mbsnbcat_s_l
#घोषणा _tcsncpy_s _mbsnbcpy_s
#घोषणा _tcsncpy_s_l _mbsnbcpy_s_l
#घोषणा _tcstok_s _mbstok_s
#घोषणा _tcstok_s_l _mbstok_s_l

#घोषणा _tcsnset_s _mbsnbset_s
#घोषणा _tcsnset_s_l _mbsnbset_s_l
#घोषणा _tcsset_s _mbsset_s
#घोषणा _tcsset_s_l _mbsset_s_l

#घोषणा _tcsnccat_s _mbsncat_s
#घोषणा _tcsnccat_s_l _mbsncat_s_l
#घोषणा _tcsnccpy_s _mbsncpy_s
#घोषणा _tcsnccpy_s_l _mbsncpy_s_l
#घोषणा _tcsncset_s _mbsnset_s
#घोषणा _tcsncset_s_l _mbsnset_s_l

#घोषणा _tcslwr_s _mbslwr_s
#घोषणा _tcslwr_s_l _mbslwr_s_l
#घोषणा _tcsupr_s _mbsupr_s
#घोषणा _tcsupr_s_l _mbsupr_s_l

#घोषणा _tccpy_s _mbccpy_s
#घोषणा _tccpy_s_l _mbccpy_s_l
#अन्यथा

  _CRTIMP अक्षर *__cdecl _tcsncat_s(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsncat_s_l(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsncpy_s(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsncpy_s_l(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcstok_s(अक्षर *_Str,स्थिर अक्षर *_Delim,अक्षर **_Context);
  _CRTIMP अक्षर *__cdecl _tcstok_s_l(अक्षर *_Str,स्थिर अक्षर *_Delim,अक्षर **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _tcsset_s(अक्षर *_Str,माप_प्रकार आकार_In_Chars,अचिन्हित पूर्णांक _Val);
  _CRTIMP errno_t __cdecl _tcsset_s_l(अक्षर *_Str,माप_प्रकार आकार_In_Chars,अचिन्हित पूर्णांक,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsnccat_s(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsnccat_s_l(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsnccpy_s(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsnccpy_s_l(अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Chars,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcslwr_s(अक्षर *_Str,माप_प्रकार आकार_In_Chars);
  _CRTIMP अक्षर *__cdecl _tcslwr_s_l(अक्षर *_Str,माप_प्रकार आकार_In_Chars,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsupr_s(अक्षर *_Str,माप_प्रकार आकार_In_Chars);
  _CRTIMP अक्षर *__cdecl _tcsupr_s_l(अक्षर *_Str,माप_प्रकार आकार_In_Chars,_locale_t _Locale);

#पूर्ण_अगर

#अन्यथा

#घोषणा _tcsncat_s strncat_s
#घोषणा _tcsncat_s_l _strncat_s_l
#घोषणा _tcsncpy_s strncpy_s
#घोषणा _tcsncpy_s_l _strncpy_s_l
#घोषणा _tcstok_s strtok_s
#घोषणा _tcstok_s_l _strtok_s_l

#घोषणा _tcsnset_s _strnset_s
#घोषणा _tcsnset_s_l _strnset_s_l
#घोषणा _tcsset_s _strset_s
#घोषणा _tcsset_s _strset_s
#घोषणा _tcsset_s_l _strset_s_l

#घोषणा _tcsnccat_s strncat_s
#घोषणा _tcsnccat_s_l _strncat_s_l
#घोषणा _tcsnccpy_s strncpy_s
#घोषणा _tcsnccpy_s_l _strncpy_s_l

#घोषणा _tcslwr_s _strlwr_s
#घोषणा _tcslwr_s_l _strlwr_s_l
#घोषणा _tcsupr_s _strupr_s
#घोषणा _tcsupr_s_l _strupr_s_l

#घोषणा _strnset_s_l(_Destination,Destination_आकार_chars,मूल्य_2,गिनती_5,_Locale) (_strnset_s(_Destination,Destination_आकार_chars,मूल्य_2,गिनती_5))
#घोषणा _strset_s_l(_Destination,Destination_आकार_chars,मूल्य_2,_Locale) (_strset_s(_Destination,Destination_आकार_chars,मूल्य_2))
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
