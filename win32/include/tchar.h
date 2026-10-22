/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अन्तर्भाव <_mingw.h>

#यदि_अपरिभाषितम् _INC_TCHAR
#परिभाषय _INC_TCHAR

#यदि_परिभाषितम् _STRSAFE_H_INCLUDED_
#दोषः Need गन्तव्यम् include strsafe.h after tchar.h
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#परिभाषय _ftcscat _tcscat
#परिभाषय _ftcschr _tcschr
#परिभाषय _ftcscpy _tcscpy
#परिभाषय _ftcscspn _tcscspn
#परिभाषय _ftcslen _tcslen
#परिभाषय _ftcsncat _tcsncat
#परिभाषय _ftcsncpy _tcsncpy
#परिभाषय _ftcspbrk _tcspbrk
#परिभाषय _ftcsrchr _tcsrchr
#परिभाषय _ftcsspn _tcsspn
#परिभाषय _ftcsstr _tcsstr
#परिभाषय _ftcstok _tcstok

#परिभाषय _ftcsdup _tcsdup
#परिभाषय _ftcsnset _tcsnset
#परिभाषय _ftcsrev _tcsrev
#परिभाषय _ftcsset _tcsset

#परिभाषय _ftcscmp _tcscmp
#परिभाषय _ftcsicmp _tcsicmp
#परिभाषय _ftcsnccmp _tcsnccmp
#परिभाषय _ftcsncmp _tcsncmp
#परिभाषय _ftcsncicmp _tcsncicmp
#परिभाषय _ftcsnicmp _tcsnicmp

#परिभाषय _ftcscoll _tcscoll
#परिभाषय _ftcsicoll _tcsicoll
#परिभाषय _ftcsnccoll _tcsnccoll
#परिभाषय _ftcsncoll _tcsncoll
#परिभाषय _ftcsncicoll _tcsncicoll
#परिभाषय _ftcsnicoll _tcsnicoll

#परिभाषय _ftcsclen _tcsclen
#परिभाषय _ftcsnccat _tcsnccat
#परिभाषय _ftcsnccpy _tcsnccpy
#परिभाषय _ftcsncset _tcsncset

#परिभाषय _ftcsdec _tcsdec
#परिभाषय _ftcsinc _tcsinc
#परिभाषय _ftcsnbcnt _tcsnbcnt
#परिभाषय _ftcsnccnt _tcsnccnt
#परिभाषय _ftcsnextc _tcsnextc
#परिभाषय _ftcsninc _tcsninc
#परिभाषय _ftcsspnp _tcsspnp

#परिभाषय _ftcslwr _tcslwr
#परिभाषय _ftcsupr _tcsupr

#परिभाषय _ftclen _tclen
#परिभाषय _ftccpy _tccpy
#परिभाषय _ftccmp _tccmp

#यदि_अपरिभाषितम् _CONST_RETURN
#यदि_परिभाषितम् __cplusplus
#परिभाषय _CONST_RETURN ध्रुव
#परिभाषय _CRT_CONST_CORRECT_OVERLOADS
#अन्यथा
#परिभाषय _CONST_RETURN
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _WConst_return _CONST_RETURN

#यदि_परिभाषितम् _UNICODE

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#अन्तर्भाव <wchar.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCTYPE_T_DEFINED
#परिभाषय _WCTYPE_T_DEFINED
  प्रकारनिर्देश अचिह्नित ह्रस्व wint_t;
  प्रकारनिर्देश अचिह्नित ह्रस्व wctype_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् __TCHAR_DEFINED
#परिभाषय __TCHAR_DEFINED
  प्रकारनिर्देश wchar_t _TCHAR;
  प्रकारनिर्देश wchar_t _TSCHAR;
  प्रकारनिर्देश wchar_t _TUCHAR;
  प्रकारनिर्देश wchar_t _TXCHAR;
  प्रकारनिर्देश wint_t _TINT;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TCHAR_DEFINED
#परिभाषय _TCHAR_DEFINED
#यदि_अपरिभाषितम्	NO_OLDNAMES
  प्रकारनिर्देश wchar_t TCHAR;
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _TEOF WEOF

#परिभाषय __T(x) L##x

#परिभाषय _tmain wmain
#परिभाषय _tWinMain wWinMain
#परिभाषय _tenviron _wenviron
#परिभाषय __targv __wargv

#परिभाषय _tprintf wprintf
#परिभाषय _tprintf_l _wprintf_l
#परिभाषय _tprintf_p _wprintf_p
#परिभाषय _tprintf_p_l _wprintf_p_l
#परिभाषय _tcprintf _cwprintf
#परिभाषय _tcprintf_l _cwprintf_l
#परिभाषय _tcprintf_p _cwprintf_p
#परिभाषय _tcprintf_p_l _cwprintf_p_l
#परिभाषय _vtcprintf _vcwprintf
#परिभाषय _vtcprintf_l _vcwprintf_l
#परिभाषय _vtcprintf_p _vcwprintf_p
#परिभाषय _vtcprintf_p_l _vcwprintf_p_l
#परिभाषय _ftprintf fwprintf
#परिभाषय _ftprintf_l _fwprintf_l
#परिभाषय _ftprintf_p _fwprintf_p
#परिभाषय _ftprintf_p_l _fwprintf_p_l
#परिभाषय _stprintf swprintf
#परिभाषय _stprintf_l __swprintf_l
#परिभाषय _stprintf_p _swprintf_p
#परिभाषय _stprintf_p_l _swprintf_p_l
#परिभाषय _sctprintf _scwprintf
#परिभाषय _sctprintf_l _scwprintf_l
#परिभाषय _sctprintf_p _scwprintf_p
#परिभाषय _sctprintf_p_l _scwprintf_p_l
#परिभाषय _sntprintf _snwprintf
#परिभाषय _sntprintf_l _snwprintf_l
#परिभाषय _vtprintf vwprintf
#परिभाषय _vtprintf_l _vwprintf_l
#परिभाषय _vtprintf_p _vwprintf_p
#परिभाषय _vtprintf_p_l _vwprintf_p_l
#परिभाषय _vftprintf vfwprintf
#परिभाषय _vftprintf_l _vfwprintf_l
#परिभाषय _vftprintf_p _vfwprintf_p
#परिभाषय _vftprintf_p_l _vfwprintf_p_l
#परिभाषय _vstprintf vswprintf
#परिभाषय _vstprintf_l _vswprintf_l
#परिभाषय _vstprintf_p _vswprintf_p
#परिभाषय _vstprintf_p_l _vswprintf_p_l
#परिभाषय _vsctprintf _vscwprintf
#परिभाषय _vsctprintf_l _vscwprintf_l
#परिभाषय _vsctprintf_p _vscwprintf_p
#परिभाषय _vsctprintf_p_l _vscwprintf_p_l
#परिभाषय _vsntprintf _vsnwprintf
#परिभाषय _vsntprintf_l _vsnwprintf_l

#परिभाषय _tscanf wscanf
#परिभाषय _tscanf_l _wscanf_l
#परिभाषय _tcscanf _cwscanf
#परिभाषय _tcscanf_l _cwscanf_l
#परिभाषय _ftscanf fwscanf
#परिभाषय _ftscanf_l _fwscanf_l
#परिभाषय _stscanf swscanf
#परिभाषय _stscanf_l _swscanf_l
#परिभाषय _sntscanf _snwscanf
#परिभाषय _sntscanf_l _snwscanf_l

#परिभाषय _fgettc fgetwc
#परिभाषय _fgettc_nolock _fgetwc_nolock
#परिभाषय _fgettchar _fgetwchar
#परिभाषय _fgetts fgetws
#परिभाषय _fputtc fputwc
#परिभाषय _fputtc_nolock _fputwc_nolock
#परिभाषय _fputtchar _fputwchar
#परिभाषय _fputts fputws
#परिभाषय _cputts _cputws
#परिभाषय _cgetts _cgetws
#परिभाषय _gettc getwc
#परिभाषय _gettc_nolock _getwc_nolock
#परिभाषय _gettch _getwch
#परिभाषय _gettch_nolock _getwch_nolock
#परिभाषय _gettche _getwche
#परिभाषय _gettche_nolock _getwche_nolock
#परिभाषय _gettchar getwchar
#परिभाषय _gettchar_nolock _getwchar_nolock
#परिभाषय _getts _getws
#परिभाषय _puttc putwc
#परिभाषय _puttc_nolock _putwc_nolock
#परिभाषय _puttchar putwchar
#परिभाषय _puttchar_nolock _putwchar_nolock
#परिभाषय _puttch _putwch
#परिभाषय _puttch_nolock _putwch_nolock
#परिभाषय _putts _putws
#परिभाषय _ungettc ungetwc
#परिभाषय _ungettc_nolock _ungetwc_nolock
#परिभाषय _ungettch _ungetwch
#परिभाषय _ungettch_nolock _ungetwch_nolock

#परिभाषय _tcstod wcstod
#परिभाषय _tcstol wcstol
#परिभाषय _tcstoul wcstoul
#परिभाषय _tcstoi64 _wcstoi64
#परिभाषय _tcstoui64 _wcstoui64
#परिभाषय _tstof _wtof
#परिभाषय _tstol _wtol
#परिभाषय _tstoi _wtoi
#परिभाषय _tstoi64 _wtoi64
#परिभाषय _tcstod_l _wcstod_l
#परिभाषय _tcstol_l _wcstol_l
#परिभाषय _tcstoul_l _wcstoul_l
#परिभाषय _tcstoi64_l _wcstoi64_l
#परिभाषय _tcstoui64_l _wcstoui64_l
#परिभाषय _tstof_l _wtof_l
#परिभाषय _tstol_l _wtol_l
#परिभाषय _tstoi_l _wtoi_l
#परिभाषय _tstoi64_l _wtoi64_l

#परिभाषय _itot _itow
#परिभाषय _ltot _ltow
#परिभाषय _ultot _ultow
#परिभाषय _ttoi _wtoi
#परिभाषय _ttol _wtol

#परिभाषय _ttoi64 _wtoi64
#परिभाषय _i64tot _i64tow
#परिभाषय _ui64tot _ui64tow

#परिभाषय _tcscat wcscat
#परिभाषय _tcschr wcschr
#परिभाषय _tcscpy wcscpy
#परिभाषय _tcscspn wcscspn
#परिभाषय _tcslen wcslen
#परिभाषय _tcsnlen wcsnlen
#परिभाषय _tcsncat wcsncat
#परिभाषय _tcsncat_l _wcsncat_l
#परिभाषय _tcsncpy wcsncpy
#परिभाषय _tcsncpy_l _wcsncpy_l
#परिभाषय _tcspbrk wcspbrk
#परिभाषय _tcsrchr wcsrchr
#परिभाषय _tcsspn wcsspn
#परिभाषय _tcsstr wcsstr
#परिभाषय _tcstok wcstok
#परिभाषय _tcstok_l _wcstok_l
#परिभाषय _tcserror _wcserror
#परिभाषय __tcserror __wcserror

#परिभाषय _tcsdup _wcsdup
#परिभाषय _tcsnset _wcsnset
#परिभाषय _tcsnset_l _wcsnset_l
#परिभाषय _tcsrev _wcsrev
#परिभाषय _tcsset _wcsset
#परिभाषय _tcsset_l _wcsset_l

#परिभाषय _tcscmp wcscmp
#परिभाषय _tcsicmp _wcsicmp
#परिभाषय _tcsicmp_l _wcsicmp_l
#परिभाषय _tcsnccmp wcsncmp
#परिभाषय _tcsncmp wcsncmp
#परिभाषय _tcsncicmp _wcsnicmp
#परिभाषय _tcsncicmp_l _wcsnicmp_l
#परिभाषय _tcsnicmp _wcsnicmp
#परिभाषय _tcsnicmp_l _wcsnicmp_l

#परिभाषय _tcscoll wcscoll
#परिभाषय _tcscoll_l _wcscoll_l
#परिभाषय _tcsicoll _wcsicoll
#परिभाषय _tcsicoll_l _wcsicoll_l
#परिभाषय _tcsnccoll _wcsncoll
#परिभाषय _tcsnccoll_l _wcsncoll_l
#परिभाषय _tcsncoll _wcsncoll
#परिभाषय _tcsncoll_l _wcsncoll_l
#परिभाषय _tcsncicoll _wcsnicoll
#परिभाषय _tcsncicoll_l _wcsnicoll_l
#परिभाषय _tcsnicoll _wcsnicoll
#परिभाषय _tcsnicoll_l _wcsnicoll_l

#परिभाषय _texecl _wexecl
#परिभाषय _texecle _wexecle
#परिभाषय _texeclp _wexeclp
#परिभाषय _texeclpe _wexeclpe
#परिभाषय _texecv _wexecv
#परिभाषय _texecve _wexecve
#परिभाषय _texecvp _wexecvp
#परिभाषय _texecvpe _wexecvpe

#परिभाषय _tspawnl _wspawnl
#परिभाषय _tspawnle _wspawnle
#परिभाषय _tspawnlp _wspawnlp
#परिभाषय _tspawnlpe _wspawnlpe
#परिभाषय _tspawnv _wspawnv
#परिभाषय _tspawnve _wspawnve
#परिभाषय _tspawnvp _wspawnvp
#परिभाषय _tspawnvp _wspawnvp
#परिभाषय _tspawnvpe _wspawnvpe

#परिभाषय _tsystem _wsystem

#परिभाषय _tasctime _wasctime
#परिभाषय _tctime _wctime
#परिभाषय _tctime32 _wctime32
#परिभाषय _tctime64 _wctime64
#परिभाषय _tstrdate _wstrdate
#परिभाषय _tstrtime _wstrtime
#परिभाषय _tutime _wutime
#परिभाषय _tutime32 _wutime32
#परिभाषय _tutime64 _wutime64
#परिभाषय _tcsftime wcsftime
#परिभाषय _tcsftime_l _wcsftime_l

#परिभाषय _tchdir _wchdir
#परिभाषय _tgetcwd _wgetcwd
#परिभाषय _tgetdcwd _wgetdcwd
#परिभाषय _tgetdcwd_nolock _wgetdcwd_nolock
#परिभाषय _tmkdir _wmkdir
#परिभाषय _trmdir _wrmdir

#परिभाषय _tfullpath _wfullpath
#परिभाषय _tgetenv _wgetenv
#परिभाषय _tmakepath _wmakepath
#परिभाषय _tpgmptr _wpgmptr
#परिभाषय _get_tpgmptr _get_wpgmptr
#परिभाषय _tputenv _wputenv
#परिभाषय _tsearchenv _wsearchenv
#परिभाषय _tsplitpath _wsplitpath

#परिभाषय _tfdopen _wfdopen
#परिभाषय _tfsopen _wfsopen
#परिभाषय _tfopen _wfopen
#परिभाषय _tfreopen _wfreopen
#परिभाषय _tperror _wperror
#परिभाषय _tpopen _wpopen
#परिभाषय _ttempnam _wtempnam
#परिभाषय _ttmpnam _wtmpnam

#परिभाषय _taccess _waccess
#परिभाषय _tchmod _wchmod
#परिभाषय _tcreat _wcreat
#परिभाषय _tfindfirst _wfindfirst
#परिभाषय _tfindfirst32 _wfindfirst32
#परिभाषय _tfindfirst64 _wfindfirst64
#परिभाषय _tfindfirsti64 _wfindfirsti64
#परिभाषय _tfindfirst32i64 _wfindfirst32i64
#परिभाषय _tfindfirst64i32 _wfindfirst64i32
#परिभाषय _tfindnext _wfindnext
#परिभाषय _tfindnext32 _wfindnext32
#परिभाषय _tfindnext64 _wfindnext64
#परिभाषय _tfindnexti64 _wfindnexti64
#परिभाषय _tfindnext32i64 _wfindnext32i64
#परिभाषय _tfindnext64i32 _wfindnext64i32
#परिभाषय _tmktemp _wmktemp
#परिभाषय _topen _wopen
#परिभाषय _tremove _wremove
#परिभाषय _trename _wrename
#परिभाषय _tsopen _wsopen
#परिभाषय _tunlink _wunlink

#परिभाषय _tfinddata_t _wfinddata_t
#परिभाषय _tfinddata32_t _wfinddata32_t
#परिभाषय _tfinddata64_t _wfinddata64_t
#परिभाषय _tfinddatai64_t _wfinddatai64_t
#परिभाषय _tfinddata32i64_t _wfinddata32i64_t
#परिभाषय _tfinddata64i32_t _wfinddata64i32_t

#परिभाषय _tstat _wstat
#परिभाषय _tstat32 _wstat32
#परिभाषय _tstat32i64 _wstat32i64
#परिभाषय _tstat64 _wstat64
#परिभाषय _tstat64i32 _wstat64i32
#परिभाषय _tstati64 _wstati64

#परिभाषय _tsetlocale _wsetlocale

#परिभाषय _tcsclen wcslen
#परिभाषय _tcscnlen wcsnlen
#परिभाषय _tcsclen_l(_String,_Locale) wcslen(_String)
#परिभाषय _tcscnlen_l(_String,Max_गणनम्_2,_Locale) wcsnlen_l((_String),(Max_गणनम्_2))
#परिभाषय _tcsnccat wcsncat
#परिभाषय _tcsnccat_l _wcsncat_l
#परिभाषय _tcsnccpy wcsncpy
#परिभाषय _tcsnccpy_l _wcsncpy_l
#परिभाषय _tcsncset _wcsnset

#परिभाषय _tcsdec _wcsdec
#परिभाषय _tcsinc _wcsinc
#परिभाषय _tcsnbcnt _wcsncnt
#परिभाषय _tcsnccnt _wcsncnt
#परिभाषय _tcsnextc _wcsnextc
#परिभाषय _tcsninc _wcsninc
#परिभाषय _tcsspnp _wcsspnp

#परिभाषय _tcslwr _wcslwr
#परिभाषय _tcslwr_l _wcslwr_l
#परिभाषय _tcsupr _wcsupr
#परिभाषय _tcsupr_l _wcsupr_l
#परिभाषय _tcsxfrm wcsxfrm
#परिभाषय _tcsxfrm_l _wcsxfrm_l

#परिभाषय _tclen(_pc) (1)
#परिभाषय _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#परिभाषय _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#परिभाषय _istalnum iswalnum
#परिभाषय _istalnum_l _iswalnum_l
#परिभाषय _istalpha iswalpha
#परिभाषय _istalpha_l _iswalpha_l
#परिभाषय _istascii iswascii
#परिभाषय _istcntrl iswcntrl
#परिभाषय _istcntrl_l _iswcntrl_l
#परिभाषय _istdigit iswdigit
#परिभाषय _istdigit_l _iswdigit_l
#परिभाषय _istgraph iswgraph
#परिभाषय _istgraph_l _iswgraph_l
#परिभाषय _istlower iswlower
#परिभाषय _istlower_l _iswlower_l
#परिभाषय _istprint iswprint
#परिभाषय _istprint_l _iswprint_l
#परिभाषय _istpunct iswpunct
#परिभाषय _istpunct_l _iswpunct_l
#परिभाषय _istspace iswspace
#परिभाषय _istspace_l _iswspace_l
#परिभाषय _istupper iswupper
#परिभाषय _istupper_l _iswupper_l
#परिभाषय _istxdigit iswxdigit
#परिभाषय _istxdigit_l _iswxdigit_l

#परिभाषय _totupper towupper
#परिभाषय _totupper_l _towupper_l
#परिभाषय _totlower towlower
#परिभाषय _totlower_l _towlower_l

#परिभाषय _istlegal(_Char) (1)
#परिभाषय _istlead(_Char) (0)
#परिभाषय _istleadbyte(_Char) (0)
#परिभाषय _istleadbyte_l(_Char,_Locale) (0)

#परिभाषय _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? रिक्त : (_cpc2)-1)
#परिभाषय _wcsinc(_pc) ((_pc)+1)
#परिभाषय _wcsnextc(_cpc) ((अचिह्नित पूर्णाङ्क) *(_cpc))
#परिभाषय _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP आकार_t __cdecl __wcsncnt(ध्रुव wchar_t *_Str,आकार_t Max_गणनम्);
#परिभाषय _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#परिभाषय _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? रिक्त : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : रिक्त))
#परिभाषय _wcsncpy_l(_Destination,_Source,गणनम्_5,_Locale) (wcsncpy(_Destination,_Source,गणनम्_5))
#परिभाषय _wcsncat_l(_Destination,_Source,गणनम्_5,_Locale) (wcsncat(_Destination,_Source,गणनम्_5))
#परिभाषय _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#परिभाषय _wcsnset_l(_Destination,मानम्_2,गणनम्_5,_Locale) (_wcsnset(_Destination,मानम्_2,गणनम्_5))
#परिभाषय _wcsset_l(_Destination,मानम्_2,_Locale) (_wcsset(_Destination,मानम्_2))

  /* dirent structures and functions */
#परिभाषय _tdirent	_wdirent
#परिभाषय _TDIR 		_WDIR
#परिभाषय _topendir	_wopendir
#परिभाषय _tclosedir	_wclosedir
#परिभाषय _treaddir	_wreaddir
#परिभाषय _trewinddir	_wrewinddir
#परिभाषय _ttelldir	_wtelldir
#परिभाषय _tseekdir	_wseekdir

#अन्यथा

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#अन्तर्भाव <string.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#परिभाषय _TEOF EOF

#परिभाषय __T(x) x

#परिभाषय _tmain मुख्यम्
#परिभाषय _tWinMain WinMain
#यदि_परिभाषितम् _POSIX_
#परिभाषय _tenviron environ
#अन्यथा
#परिभाषय _tenviron _environ
#यदि_अन्तः
#परिभाषय __targv __argv

#परिभाषय _tprintf प्रारूप_लिख
#परिभाषय _tprintf_l _printf_l
#परिभाषय _tprintf_p _printf_p
#परिभाषय _tprintf_p_l _printf_p_l
#परिभाषय _tcprintf _cprintf
#परिभाषय _tcprintf_l _cprintf_l
#परिभाषय _tcprintf_p _cprintf_p
#परिभाषय _tcprintf_p_l _cprintf_p_l
#परिभाषय _vtcprintf _vcprintf
#परिभाषय _vtcprintf_l _vcprintf_l
#परिभाषय _vtcprintf_p _vcprintf_p
#परिभाषय _vtcprintf_p_l _vcprintf_p_l
#परिभाषय _ftprintf fprintf
#परिभाषय _ftprintf_l _fprintf_l
#परिभाषय _ftprintf_p _fprintf_p
#परिभाषय _ftprintf_p_l _fprintf_p_l
#परिभाषय _stprintf sprintf
#परिभाषय _stprintf_l _sprintf_l
#परिभाषय _stprintf_p _sprintf_p
#परिभाषय _stprintf_p_l _sprintf_p_l
#परिभाषय _sctprintf _scprintf
#परिभाषय _sctprintf_l _scprintf_l
#परिभाषय _sctprintf_p _scprintf_p
#परिभाषय _sctprintf_p_l _scprintf_p_l
#परिभाषय _sntprintf _snprintf
#परिभाषय _sntprintf_l _snprintf_l
#परिभाषय _vtprintf vprintf
#परिभाषय _vtprintf_l _vprintf_l
#परिभाषय _vtprintf_p _vprintf_p
#परिभाषय _vtprintf_p_l _vprintf_p_l
#परिभाषय _vftprintf vfprintf
#परिभाषय _vftprintf_l _vfprintf_l
#परिभाषय _vftprintf_p _vfprintf_p
#परिभाषय _vftprintf_p_l _vfprintf_p_l
#परिभाषय _vstprintf vsprintf
#परिभाषय _vstprintf_l _vsprintf_l
#परिभाषय _vstprintf_p _vsprintf_p
#परिभाषय _vstprintf_p_l _vsprintf_p_l
#परिभाषय _vsctprintf _vscprintf
#परिभाषय _vsctprintf_l _vscprintf_l
#परिभाषय _vsctprintf_p _vscprintf_p
#परिभाषय _vsctprintf_p_l _vscprintf_p_l
#परिभाषय _vsntprintf _vsnprintf
#परिभाषय _vsntprintf_l _vsnprintf_l

#परिभाषय _tscanf प्रारूप_पठ
#परिभाषय _tscanf_l _scanf_l
#परिभाषय _tcscanf _cscanf
#परिभाषय _tcscanf_l _cscanf_l
#परिभाषय _ftscanf fscanf
#परिभाषय _ftscanf_l _fscanf_l
#परिभाषय _stscanf वाक्यात्_पठ
#परिभाषय _stscanf_l _sscanf_l
#परिभाषय _sntscanf _snscanf
#परिभाषय _sntscanf_l _snscanf_l

#परिभाषय _fgettc fgetc
#परिभाषय _fgettc_nolock _fgetc_nolock
#परिभाषय _fgettchar _fgetchar
#परिभाषय _fgetts fgets
#परिभाषय _fputtc fputc
#परिभाषय _fputtc_nolock _fputc_nolock
#परिभाषय _fputtchar _fputchar
#परिभाषय _fputts fputs
#परिभाषय _cputts _cputs
#परिभाषय _gettc getc
#परिभाषय _gettc_nolock _getc_nolock
#परिभाषय _gettch _getch
#परिभाषय _gettch_nolock _getch_nolock
#परिभाषय _gettche _getche
#परिभाषय _gettche_nolock _getche_nolock
#परिभाषय _gettchar अक्षरं_पठ
#परिभाषय _gettchar_nolock _getchar_nolock
#परिभाषय _getts gets
#परिभाषय _cgetts _cgets
#परिभाषय _puttc putc
#परिभाषय _puttc_nolock _putc_nolock
#परिभाषय _puttchar अक्षरं_लिख
#परिभाषय _puttchar_nolock _putchar_nolock
#परिभाषय _puttch _putch
#परिभाषय _puttch_nolock _putch_nolock
#परिभाषय _putts पङ्क्तिं_लिख
#परिभाषय _ungettc ungetc
#परिभाषय _ungettc_nolock _ungetc_nolock
#परिभाषय _ungettch _ungetch
#परिभाषय _ungettch_nolock _ungetch_nolock

#परिभाषय _tcstod strtod
#परिभाषय _tcstol strtol
#परिभाषय _tcstoul strtoul
#परिभाषय _tstof atof
#परिभाषय _tstol atol
#परिभाषय _tstoi atoi
#परिभाषय _tstoi64 _atoi64
#परिभाषय _tcstod_l _strtod_l
#परिभाषय _tcstol_l _strtol_l
#परिभाषय _tcstoul_l _strtoul_l
#परिभाषय _tstof_l _atof_l
#परिभाषय _tstol_l _atol_l
#परिभाषय _tstoi_l _atoi_l
#परिभाषय _tstoi64_l _atoi64_l

#परिभाषय _itot _itoa
#परिभाषय _ltot _ltoa
#परिभाषय _ultot _ultoa
#परिभाषय _ttoi atoi
#परिभाषय _ttol atol

#परिभाषय _ttoi64 _atoi64
#परिभाषय _tcstoi64 _strtoi64
#परिभाषय _tcstoi64_l _strtoi64_l
#परिभाषय _tcstoui64 _strtoui64
#परिभाषय _tcstoui64_l _strtoui64_l
#परिभाषय _i64tot _i64toa
#परिभाषय _ui64tot _ui64toa

#परिभाषय _tcscat वाक्यं_योजय
#परिभाषय _tcscpy वाक्यं_प्रतिलिख
#परिभाषय _tcsdup _strdup
#परिभाषय _tcslen वाक्यदैर्घ्यम्
#यदि 0
#परिभाषय _tcsnlen strnlen
#यदि_अन्तः
#परिभाषय _tcsxfrm strxfrm
#परिभाषय _tcsxfrm_l _strxfrm_l
#परिभाषय _tcserror strerror
#परिभाषय __tcserror _strerror

#परिभाषय _texecl _execl
#परिभाषय _texecle _execle
#परिभाषय _texeclp _execlp
#परिभाषय _texeclpe _execlpe
#परिभाषय _texecv _execv
#परिभाषय _texecve _execve
#परिभाषय _texecvp _execvp
#परिभाषय _texecvpe _execvpe

#परिभाषय _tspawnl _spawnl
#परिभाषय _tspawnle _spawnle
#परिभाषय _tspawnlp _spawnlp
#परिभाषय _tspawnlpe _spawnlpe
#परिभाषय _tspawnv _spawnv
#परिभाषय _tspawnve _spawnve
#परिभाषय _tspawnvp _spawnvp
#परिभाषय _tspawnvpe _spawnvpe

#परिभाषय _tsystem system

#परिभाषय _tasctime asctime
#परिभाषय _tctime ctime
#परिभाषय _tctime32 _ctime32
#परिभाषय _tctime64 _ctime64
#परिभाषय _tstrdate _strdate
#परिभाषय _tstrtime _strtime
#परिभाषय _tutime _utime
#परिभाषय _tutime32 _utime32
#परिभाषय _tutime64 _utime64
#परिभाषय _tcsftime strftime
#परिभाषय _tcsftime_l _strftime_l

#परिभाषय _tchdir _chdir
#परिभाषय _tgetcwd _getcwd
#परिभाषय _tgetdcwd _getdcwd
#परिभाषय _tgetdcwd_nolock _getdcwd_nolock
#परिभाषय _tmkdir _mkdir
#परिभाषय _trmdir _rmdir

#परिभाषय _tfullpath _fullpath
#परिभाषय _tgetenv getenv
#परिभाषय _tmakepath _makepath
#परिभाषय _tpgmptr _pgmptr
#परिभाषय _get_tpgmptr _get_pgmptr
#परिभाषय _tputenv _putenv
#परिभाषय _tsearchenv _searchenv
#परिभाषय _tsplitpath _splitpath

#यदि_परिभाषितम् _POSIX_
#परिभाषय _tfdopen fdopen
#अन्यथा
#परिभाषय _tfdopen _fdopen
#यदि_अन्तः
#परिभाषय _tfsopen _fsopen
#परिभाषय _tfopen fopen
#परिभाषय _tfreopen freopen
#परिभाषय _tperror perror
#परिभाषय _tpopen _popen
#परिभाषय _ttempnam _tempnam
#परिभाषय _ttmpnam tmpnam

#परिभाषय _tchmod _chmod
#परिभाषय _tcreat _creat
#परिभाषय _tfindfirst _findfirst
#परिभाषय _tfindfirst32 _findfirst32
#परिभाषय _tfindfirst64 _findfirst64
#परिभाषय _tfindfirsti64 _findfirsti64
#परिभाषय _tfindfirst32i64 _findfirst32i64
#परिभाषय _tfindfirst64i32 _findfirst64i32
#परिभाषय _tfindnext _findnext
#परिभाषय _tfindnext32 _findnext32
#परिभाषय _tfindnext64 _findnext64
#परिभाषय _tfindnexti64 _findnexti64
#परिभाषय _tfindnext32i64 _findnext32i64
#परिभाषय _tfindnext64i32 _findnext64i32
#परिभाषय _tmktemp _mktemp

#यदि_परिभाषितम् _POSIX_
#परिभाषय _topen उद्घाटय
#परिभाषय _taccess access
#अन्यथा
#परिभाषय _topen _open
#परिभाषय _taccess _access
#यदि_अन्तः

#परिभाषय _tremove remove
#परिभाषय _trename rename
#परिभाषय _tsopen _sopen
#परिभाषय _tunlink _unlink

#परिभाषय _tfinddata_t _finddata_t
#परिभाषय _tfinddata32_t _finddata32_t
#परिभाषय _tfinddata64_t __finddata64_t
#परिभाषय _tfinddatai64_t _finddatai64_t
#परिभाषय _tfinddata32i64_t _finddata32i64_t
#परिभाषय _tfinddata64i32_t _finddata64i32_t

#परिभाषय _istascii __isascii
#परिभाषय _istcntrl iscntrl
#परिभाषय _istcntrl_l _iscntrl_l
#परिभाषय _istxdigit isxdigit
#परिभाषय _istxdigit_l _isxdigit_l

#परिभाषय _tstat _stat
#परिभाषय _tstat32 _stat32
#परिभाषय _tstat32i64 _stat32i64
#परिभाषय _tstat64 _stat64
#परिभाषय _tstat64i32 _stat64i32
#परिभाषय _tstati64 _stati64

#परिभाषय _tsetlocale setlocale

#यदि_परिभाषितम् _MBCS

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#अन्तर्भाव <mbstring.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् __TCHAR_DEFINED
  प्रकारनिर्देश वर्ण _TCHAR;
  प्रकारनिर्देश चिह्नित वर्ण _TSCHAR;
  प्रकारनिर्देश अचिह्नित वर्ण _TUCHAR;
  प्रकारनिर्देश अचिह्नित वर्ण _TXCHAR;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क _TINT;
#परिभाषय __TCHAR_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _TCHAR_DEFINED
#यदि_अपरिभाषितम्	NO_OLDNAMES
  प्रकारनिर्देश वर्ण TCHAR;
#यदि_अन्तः
#परिभाषय _TCHAR_DEFINED
#यदि_अन्तः

#यदि_परिभाषितम् MB_MAP_प्रत्यक्षम्

#परिभाषय _tcschr _mbschr
#परिभाषय _tcscspn _mbscspn
#परिभाषय _tcsncat _mbsnbcat
#परिभाषय _tcsncat_l _mbsnbcat_l
#परिभाषय _tcsncpy _mbsnbcpy
#परिभाषय _tcsncpy_l _mbsnbcpy_l
#परिभाषय _tcspbrk _mbspbrk
#परिभाषय _tcsrchr _mbsrchr
#परिभाषय _tcsspn _mbsspn
#परिभाषय _tcsstr _mbsstr
#परिभाषय _tcstok _mbstok
#परिभाषय _tcstok_l _mbstok_l

#परिभाषय _tcsnset _mbsnbset
#परिभाषय _tcsnset_l _mbsnbset_l
#परिभाषय _tcsrev _mbsrev
#परिभाषय _tcsset _mbsset
#परिभाषय _tcsset_l _mbsset_l

#परिभाषय _tcscmp _mbscmp
#परिभाषय _tcsicmp _mbsicmp
#परिभाषय _tcsicmp_l _mbsicmp_l
#परिभाषय _tcsnccmp _mbsncmp
#परिभाषय _tcsncmp _mbsnbcmp
#परिभाषय _tcsncicmp _mbsnicmp
#परिभाषय _tcsncicmp_l _mbsnicmp_l
#परिभाषय _tcsnicmp _mbsnbicmp
#परिभाषय _tcsnicmp_l _mbsnbicmp_l

#परिभाषय _tcscoll _mbscoll
#परिभाषय _tcscoll_l _mbscoll_l
#परिभाषय _tcsicoll _mbsicoll
#परिभाषय _tcsicoll_l _mbsicoll_l
#परिभाषय _tcsnccoll _mbsncoll
#परिभाषय _tcsnccoll_l _mbsncoll_l
#परिभाषय _tcsncoll _mbsnbcoll
#परिभाषय _tcsncoll_l _mbsnbcoll_l
#परिभाषय _tcsncicoll _mbsnicoll
#परिभाषय _tcsncicoll_l _mbsnicoll_l
#परिभाषय _tcsnicoll _mbsnbicoll
#परिभाषय _tcsnicoll_l _mbsnbicoll_l

#परिभाषय _tcsclen _mbslen
#परिभाषय _tcscnlen _mbsnlen
#परिभाषय _tcsclen_l _mbslen_l
#परिभाषय _tcscnlen_l _mbsnlen_l
#परिभाषय _tcsnccat _mbsncat
#परिभाषय _tcsnccat_l _mbsncat_l
#परिभाषय _tcsnccpy _mbsncpy
#परिभाषय _tcsnccpy_l _mbsncpy_l
#परिभाषय _tcsncset _mbsnset
#परिभाषय _tcsncset_l _mbsnset_l

#परिभाषय _tcsdec _mbsdec
#परिभाषय _tcsinc _mbsinc
#परिभाषय _tcsnbcnt _mbsnbcnt
#परिभाषय _tcsnccnt _mbsnccnt
#परिभाषय _tcsnextc _mbsnextc
#परिभाषय _tcsninc _mbsninc
#परिभाषय _tcsspnp _mbsspnp

#परिभाषय _tcslwr _mbslwr
#परिभाषय _tcslwr_l _mbslwr_l
#परिभाषय _tcsupr _mbsupr
#परिभाषय _tcsupr_l _mbsupr_l

#परिभाषय _tclen _mbclen
#परिभाषय _tccpy _mbccpy
#परिभाषय _tccpy_l _mbccpy_l
#अन्यथा

  _CRTIMP _CONST_RETURN वर्ण *__cdecl _tcschr(ध्रुव वर्ण *_Str,अचिह्नित पूर्णाङ्क _Val);
  _CRTIMP आकार_t __cdecl _tcscspn(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CRTIMP वर्ण *__cdecl _tcsncat(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsncat_l(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsncpy(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsncpy_l(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP _CONST_RETURN वर्ण *__cdecl _tcspbrk(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CRTIMP _CONST_RETURN वर्ण *__cdecl _tcsrchr(ध्रुव वर्ण *_Str,अचिह्नित पूर्णाङ्क _Ch);
  _CRTIMP आकार_t __cdecl _tcsspn(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CRTIMP _CONST_RETURN वर्ण *__cdecl _tcsstr(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Substr);
  _CRTIMP वर्ण *__cdecl _tcstok(वर्ण *_Str,ध्रुव वर्ण *_Delim);
  _CRTIMP वर्ण *__cdecl _tcstok_l(वर्ण *_Str,ध्रुव वर्ण *_Delim,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsnset(वर्ण *_Str,अचिह्नित पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsrev(वर्ण *_Str);
  _CRTIMP वर्ण *__cdecl _tcsset(वर्ण *_Str,अचिह्नित पूर्णाङ्क _Val);
  _CRTIMP वर्ण *__cdecl _tcsset_l(वर्ण *_Str,अचिह्नित पूर्णाङ्क _Val,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcscmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _tcsicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _tcsicmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcsnccmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsncmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsncicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsncicmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcsnicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsnicmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcscoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _tcscoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcsicoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _tcsicoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcsnccoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsnccoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcsncoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsncoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcsncicoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsncicoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _tcsnicoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _tcsnicoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP आकार_t __cdecl _tcsclen(ध्रुव वर्ण *_Str);
  _CRTIMP आकार_t __cdecl _tcscnlen(ध्रुव वर्ण *_Str,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _tcsclen_l(ध्रुव वर्ण *_Str,_locale_t _Locale);
  _CRTIMP आकार_t __cdecl _tcscnlen_l(ध्रुव वर्ण *_Str,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsnccat(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsnccat_l(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsnccpy(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsnccpy_l(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsncset(वर्ण *_Str,अचिह्नित पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CRTIMP वर्ण *__cdecl _tcsdec(ध्रुव वर्ण *_Start,ध्रुव वर्ण *_Pos);
  _CRTIMP वर्ण *__cdecl _tcsinc(ध्रुव वर्ण *_Ptr);
  _CRTIMP आकार_t __cdecl _tcsnbcnt(ध्रुव वर्ण *_Str,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _tcsnccnt(ध्रुव वर्ण *_Str,आकार_t Max_गणनम्);
  _CRTIMP अचिह्नित पूर्णाङ्क __cdecl _tcsnextc (ध्रुव वर्ण *_Str);
  _CRTIMP वर्ण *__cdecl _tcsninc(ध्रुव वर्ण *_Ptr,आकार_t गणनम्_5);
  _CRTIMP वर्ण *__cdecl _tcsspnp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP वर्ण *__cdecl _tcslwr(वर्ण *_Str);
  _CRTIMP वर्ण *__cdecl _tcslwr_l(वर्ण *_Str,_locale_t _Locale);
  _CRTIMP वर्ण *__cdecl _tcsupr(वर्ण *_Str);
  _CRTIMP वर्ण *__cdecl _tcsupr_l(वर्ण *_Str,_locale_t _Locale);
  _CRTIMP आकार_t __cdecl _tclen(ध्रुव वर्ण *_Str);
  _CRTIMP शून्य __cdecl _tccpy(वर्ण *_DstCh,ध्रुव वर्ण *_SrcCh);

#यदि_परिभाषितम् __cplusplus
#यदि_अपरिभाषितम् _CPP_TCHAR_INLINES_DEFINED
#परिभाषय _CPP_TCHAR_INLINES_DEFINED
  बाह्य "C++" {
    बाह्य अन्तःस्थ वर्ण *__cdecl _tcschr(वर्ण *_S,अचिह्नित पूर्णाङ्क _C) { प्रत्यागम ((वर्ण *)_tcschr((ध्रुव वर्ण *)_S,_C)); }
    बाह्य अन्तःस्थ वर्ण *__cdecl _tcspbrk(वर्ण *_S,ध्रुव वर्ण *_P) { प्रत्यागम ((वर्ण *)_tcspbrk((ध्रुव वर्ण *)_S,_P)); }
    बाह्य अन्तःस्थ वर्ण *__cdecl _tcsrchr(वर्ण *_S,अचिह्नित पूर्णाङ्क _C) { प्रत्यागम ((वर्ण *)_tcsrchr((ध्रुव वर्ण *)_S,_C)); }
    बाह्य अन्तःस्थ वर्ण *__cdecl _tcsstr(वर्ण *_S,ध्रुव वर्ण *_P) { प्रत्यागम ((वर्ण *)_tcsstr((ध्रुव वर्ण *)_S,_P)); }
  }
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#परिभाषय _istalnum _ismbcalnum
#परिभाषय _istalnum_l _ismbcalnum_l
#परिभाषय _istalpha _ismbcalpha
#परिभाषय _istalpha_l _ismbcalpha_l
#परिभाषय _istdigit _ismbcdigit
#परिभाषय _istdigit_l _ismbcdigit_l
#परिभाषय _istgraph _ismbcgraph
#परिभाषय _istgraph_l _ismbcgraph_l
#परिभाषय _istlegal _ismbclegal
#परिभाषय _istlegal_l _ismbclegal_l
#परिभाषय _istlower _ismbclower
#परिभाषय _istlower_l _ismbclower_l
#परिभाषय _istprint _ismbcprint
#परिभाषय _istprint_l _ismbcprint_l
#परिभाषय _istpunct _ismbcpunct
#परिभाषय _istpunct_l _ismbcpunct_l
#परिभाषय _istspace _ismbcspace
#परिभाषय _istspace_l _ismbcspace_l
#परिभाषय _istupper _ismbcupper
#परिभाषय _istupper_l _ismbcupper_l

#परिभाषय _totupper _mbctoupper
#परिभाषय _totupper_l _mbctoupper_l
#परिभाषय _totlower _mbctolower
#परिभाषय _totlower_l _mbctolower_l

#परिभाषय _istlead _ismbblead
#परिभाषय _istleadbyte isleadbyte
#परिभाषय _istleadbyte_l _isleadbyte_l
#अन्यथा

#यदि_अपरिभाषितम् __TCHAR_DEFINED
#परिभाषय __TCHAR_DEFINED
  प्रकारनिर्देश वर्ण _TCHAR;
  प्रकारनिर्देश चिह्नित वर्ण _TSCHAR;
  प्रकारनिर्देश अचिह्नित वर्ण _TUCHAR;
  प्रकारनिर्देश वर्ण _TXCHAR;
  प्रकारनिर्देश पूर्णाङ्क _TINT;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TCHAR_DEFINED
#परिभाषय _TCHAR_DEFINED
#यदि_अपरिभाषितम्	NO_OLDNAMES
  प्रकारनिर्देश वर्ण TCHAR;
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _tcschr strchr
#परिभाषय _tcscspn strcspn
#परिभाषय _tcsncat strncat
#परिभाषय _tcsncat_l _strncat_l
#परिभाषय _tcsncpy strncpy
#परिभाषय _tcsncpy_l _strncpy_l
#परिभाषय _tcspbrk strpbrk
#परिभाषय _tcsrchr strrchr
#परिभाषय _tcsspn strspn
#परिभाषय _tcsstr वाक्ये_अन्विष
#परिभाषय _tcstok strtok
#परिभाषय _tcstok_l _strtok_l

#परिभाषय _tcsnset _strnset
#परिभाषय _tcsnset_l _strnset_l
#परिभाषय _tcsrev _strrev
#परिभाषय _tcsset _strset

#परिभाषय _tcscmp वाक्यं_तुलय
#परिभाषय _tcsicmp _stricmp
#परिभाषय _tcsicmp_l _stricmp_l
#परिभाषय _tcsnccmp वाक्ये_तुलय
#परिभाषय _tcsncmp वाक्ये_तुलय
#परिभाषय _tcsncicmp _strnicmp
#परिभाषय _tcsncicmp_l _strnicmp_l
#परिभाषय _tcsnicmp _strnicmp
#परिभाषय _tcsnicmp_l _strnicmp_l

#परिभाषय _tcscoll strcoll
#परिभाषय _tcscoll_l _strcoll_l
#परिभाषय _tcsicoll _stricoll
#परिभाषय _tcsicoll_l _stricoll_l
#परिभाषय _tcsnccoll _strncoll
#परिभाषय _tcsnccoll_l _strncoll_l
#परिभाषय _tcsncoll _strncoll
#परिभाषय _tcsncoll_l _strncoll_l
#परिभाषय _tcsncicoll _strnicoll
#परिभाषय _tcsncicoll_l _strnicoll_l
#परिभाषय _tcsnicoll _strnicoll
#परिभाषय _tcsnicoll_l _strnicoll_l

#परिभाषय _tcsclen वाक्यदैर्घ्यम्
#परिभाषय _tcscnlen strnlen
#परिभाषय _tcsclen_l(_String,_Locale) वाक्यदैर्घ्यम्(_String)
#परिभाषय _tcscnlen_l(_String,Max_गणनम्_2,_Locale) strnlen_l((_String),(Max_गणनम्_2))
#परिभाषय _tcsnccat strncat
#परिभाषय _tcsnccat_l _strncat_l
#परिभाषय _tcsnccpy strncpy
#परिभाषय _tcsnccpy_l _strncpy_l
#परिभाषय _tcsncset _strnset

#परिभाषय _tcsdec _strdec
#परिभाषय _tcsinc _strinc
#परिभाषय _tcsnbcnt _strncnt
#परिभाषय _tcsnccnt _strncnt
#परिभाषय _tcsnextc _strnextc
#परिभाषय _tcsninc _strninc
#परिभाषय _tcsspnp _strspnp

#परिभाषय _tcslwr _strlwr
#परिभाषय _tcslwr_l _strlwr_l
#परिभाषय _tcsupr _strupr
#परिभाषय _tcsupr_l _strupr_l
#परिभाषय _tcsxfrm strxfrm
#परिभाषय _tcsxfrm_l _strxfrm_l

#परिभाषय _istlead(_Char) (0)
#परिभाषय _istleadbyte(_Char) (0)
#परिभाषय _istleadbyte_l(_Char,_Locale) (0)

#परिभाषय _tclen(_pc) (1)
#परिभाषय _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#परिभाषय _tccmp(_cpc1,_cpc2) (((अचिह्नित वर्ण)*(_cpc1))-((अचिह्नित वर्ण)*(_cpc2)))

  /* dirent structures and functions */
#परिभाषय _tdirent	dirent
#परिभाषय _TDIR 		DIR
#परिभाषय _topendir	opendir
#परिभाषय _tclosedir	closedir
#परिभाषय _treaddir	readdir
#परिभाषय _trewinddir	rewinddir
#परिभाषय _ttelldir	telldir
#परिभाषय _tseekdir	seekdir

#परिभाषय _istalnum अक्षरम्_अङ्कः_वा
#परिभाषय _istalnum_l _isalnum_l
#परिभाषय _istalpha अक्षरम्_वा
#परिभाषय _istalpha_l _isalpha_l
#परिभाषय _istdigit अङ्कः_वा
#परिभाषय _istdigit_l _isdigit_l
#परिभाषय _istgraph isgraph
#परिभाषय _istgraph_l _isgraph_l
#परिभाषय _istlower islower
#परिभाषय _istlower_l _islower_l
#परिभाषय _istprint isprint
#परिभाषय _istprint_l _isprint_l
#परिभाषय _istpunct ispunct
#परिभाषय _istpunct_l _ispunct_l
#परिभाषय _istspace रिक्तम्_वा
#परिभाषय _istspace_l _isspace_l
#परिभाषय _istupper isupper
#परिभाषय _istupper_l _isupper_l

#परिभाषय _totupper महाक्षरम्
#परिभाषय _totupper_l _toupper_l
#परिभाषय _totlower tolower
#परिभाषय _totlower_l _tolower_l

#परिभाषय _istlegal(_c) (1)

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? रिक्त : (_cpc2)-1)
#परिभाषय _strinc(_pc) ((_pc)+1)
#परिभाषय _strnextc(_cpc) ((अचिह्नित पूर्णाङ्क) *(ध्रुव अचिह्नित वर्ण *)(_cpc))
#परिभाषय _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP आकार_t __cdecl __strncnt(ध्रुव वर्ण *_Str,आकार_t _Cnt);
#परिभाषय _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#परिभाषय _strspnp(_cpc1,_cpc2) (!_cpc1 ? रिक्त : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : रिक्त))

#परिभाषय _strncpy_l(_Destination,_Source,गणनम्_5,_Locale) (strncpy(_Destination,_Source,गणनम्_5))
#परिभाषय _strncat_l(_Destination,_Source,गणनम्_5,_Locale) (strncat(_Destination,_Source,गणनम्_5))
#परिभाषय _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#परिभाषय _strnset_l(_Destination,मानम्_2,गणनम्_5,_Locale) (_strnset(_Destination,मानम्_2,गणनम्_5))
#परिभाषय _strset_l(_Destination,मानम्_2,_Locale) (_strset(_Destination,मानम्_2))
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _T(x) __T(x)
#परिभाषय _TEXT(x) __T(x)

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#अन्तर्भाव <sec_api/tchar_s.h>
#यदि_अन्तः
