/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#అన్తర్భావ <_mingw.h>

#నిర్వచితం_కాకపోతే _INC_TCHAR
#నిర్వచించు _INC_TCHAR

#నిర్వచితమైతే _STRSAFE_H_INCLUDED_
#దోషం Need గమ్యం include strsafe.h after tchar.h
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచించు _ftcscat _tcscat
#నిర్వచించు _ftcschr _tcschr
#నిర్వచించు _ftcscpy _tcscpy
#నిర్వచించు _ftcscspn _tcscspn
#నిర్వచించు _ftcslen _tcslen
#నిర్వచించు _ftcsncat _tcsncat
#నిర్వచించు _ftcsncpy _tcsncpy
#నిర్వచించు _ftcspbrk _tcspbrk
#నిర్వచించు _ftcsrchr _tcsrchr
#నిర్వచించు _ftcsspn _tcsspn
#నిర్వచించు _ftcsstr _tcsstr
#నిర్వచించు _ftcstok _tcstok

#నిర్వచించు _ftcsdup _tcsdup
#నిర్వచించు _ftcsnset _tcsnset
#నిర్వచించు _ftcsrev _tcsrev
#నిర్వచించు _ftcsset _tcsset

#నిర్వచించు _ftcscmp _tcscmp
#నిర్వచించు _ftcsicmp _tcsicmp
#నిర్వచించు _ftcsnccmp _tcsnccmp
#నిర్వచించు _ftcsncmp _tcsncmp
#నిర్వచించు _ftcsncicmp _tcsncicmp
#నిర్వచించు _ftcsnicmp _tcsnicmp

#నిర్వచించు _ftcscoll _tcscoll
#నిర్వచించు _ftcsicoll _tcsicoll
#నిర్వచించు _ftcsnccoll _tcsnccoll
#నిర్వచించు _ftcsncoll _tcsncoll
#నిర్వచించు _ftcsncicoll _tcsncicoll
#నిర్వచించు _ftcsnicoll _tcsnicoll

#నిర్వచించు _ftcsclen _tcsclen
#నిర్వచించు _ftcsnccat _tcsnccat
#నిర్వచించు _ftcsnccpy _tcsnccpy
#నిర్వచించు _ftcsncset _tcsncset

#నిర్వచించు _ftcsdec _tcsdec
#నిర్వచించు _ftcsinc _tcsinc
#నిర్వచించు _ftcsnbcnt _tcsnbcnt
#నిర్వచించు _ftcsnccnt _tcsnccnt
#నిర్వచించు _ftcsnextc _tcsnextc
#నిర్వచించు _ftcsninc _tcsninc
#నిర్వచించు _ftcsspnp _tcsspnp

#నిర్వచించు _ftcslwr _tcslwr
#నిర్వచించు _ftcsupr _tcsupr

#నిర్వచించు _ftclen _tclen
#నిర్వచించు _ftccpy _tccpy
#నిర్వచించు _ftccmp _tccmp

#నిర్వచితం_కాకపోతే _CONST_RETURN
#నిర్వచితమైతే __cplusplus
#నిర్వచించు _CONST_RETURN స్థిరరాశి
#నిర్వచించు _CRT_CONST_CORRECT_OVERLOADS
#లేకపోతే
#నిర్వచించు _CONST_RETURN
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _WConst_return _CONST_RETURN

#నిర్వచితమైతే _UNICODE

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అన్తర్భావ <wchar.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCTYPE_T_DEFINED
#నిర్వచించు _WCTYPE_T_DEFINED
  రకనిర్వచనం గుర్తులేని పొట్టి wint_t;
  రకనిర్వచనం గుర్తులేని పొట్టి wctype_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __TCHAR_DEFINED
#నిర్వచించు __TCHAR_DEFINED
  రకనిర్వచనం wchar_t _TCHAR;
  రకనిర్వచనం wchar_t _TSCHAR;
  రకనిర్వచనం wchar_t _TUCHAR;
  రకనిర్వచనం wchar_t _TXCHAR;
  రకనిర్వచనం wint_t _TINT;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TCHAR_DEFINED
#నిర్వచించు _TCHAR_DEFINED
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  రకనిర్వచనం wchar_t TCHAR;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _TEOF WEOF

#నిర్వచించు __T(x) L##x

#నిర్వచించు _tmain wmain
#నిర్వచించు _tWinMain wWinMain
#నిర్వచించు _tenviron _wenviron
#నిర్వచించు __targv __wargv

#నిర్వచించు _tprintf wprintf
#నిర్వచించు _tprintf_l _wprintf_l
#నిర్వచించు _tprintf_p _wprintf_p
#నిర్వచించు _tprintf_p_l _wprintf_p_l
#నిర్వచించు _tcprintf _cwprintf
#నిర్వచించు _tcprintf_l _cwprintf_l
#నిర్వచించు _tcprintf_p _cwprintf_p
#నిర్వచించు _tcprintf_p_l _cwprintf_p_l
#నిర్వచించు _vtcprintf _vcwprintf
#నిర్వచించు _vtcprintf_l _vcwprintf_l
#నిర్వచించు _vtcprintf_p _vcwprintf_p
#నిర్వచించు _vtcprintf_p_l _vcwprintf_p_l
#నిర్వచించు _ftprintf fwprintf
#నిర్వచించు _ftprintf_l _fwprintf_l
#నిర్వచించు _ftprintf_p _fwprintf_p
#నిర్వచించు _ftprintf_p_l _fwprintf_p_l
#నిర్వచించు _stprintf swprintf
#నిర్వచించు _stprintf_l __swprintf_l
#నిర్వచించు _stprintf_p _swprintf_p
#నిర్వచించు _stprintf_p_l _swprintf_p_l
#నిర్వచించు _sctprintf _scwprintf
#నిర్వచించు _sctprintf_l _scwprintf_l
#నిర్వచించు _sctprintf_p _scwprintf_p
#నిర్వచించు _sctprintf_p_l _scwprintf_p_l
#నిర్వచించు _sntprintf _snwprintf
#నిర్వచించు _sntprintf_l _snwprintf_l
#నిర్వచించు _vtprintf vwprintf
#నిర్వచించు _vtprintf_l _vwprintf_l
#నిర్వచించు _vtprintf_p _vwprintf_p
#నిర్వచించు _vtprintf_p_l _vwprintf_p_l
#నిర్వచించు _vftprintf vfwprintf
#నిర్వచించు _vftprintf_l _vfwprintf_l
#నిర్వచించు _vftprintf_p _vfwprintf_p
#నిర్వచించు _vftprintf_p_l _vfwprintf_p_l
#నిర్వచించు _vstprintf vswprintf
#నిర్వచించు _vstprintf_l _vswprintf_l
#నిర్వచించు _vstprintf_p _vswprintf_p
#నిర్వచించు _vstprintf_p_l _vswprintf_p_l
#నిర్వచించు _vsctprintf _vscwprintf
#నిర్వచించు _vsctprintf_l _vscwprintf_l
#నిర్వచించు _vsctprintf_p _vscwprintf_p
#నిర్వచించు _vsctprintf_p_l _vscwprintf_p_l
#నిర్వచించు _vsntprintf _vsnwprintf
#నిర్వచించు _vsntprintf_l _vsnwprintf_l

#నిర్వచించు _tscanf wscanf
#నిర్వచించు _tscanf_l _wscanf_l
#నిర్వచించు _tcscanf _cwscanf
#నిర్వచించు _tcscanf_l _cwscanf_l
#నిర్వచించు _ftscanf fwscanf
#నిర్వచించు _ftscanf_l _fwscanf_l
#నిర్వచించు _stscanf swscanf
#నిర్వచించు _stscanf_l _swscanf_l
#నిర్వచించు _sntscanf _snwscanf
#నిర్వచించు _sntscanf_l _snwscanf_l

#నిర్వచించు _fgettc fgetwc
#నిర్వచించు _fgettc_nolock _fgetwc_nolock
#నిర్వచించు _fgettchar _fgetwchar
#నిర్వచించు _fgetts fgetws
#నిర్వచించు _fputtc fputwc
#నిర్వచించు _fputtc_nolock _fputwc_nolock
#నిర్వచించు _fputtchar _fputwchar
#నిర్వచించు _fputts fputws
#నిర్వచించు _cputts _cputws
#నిర్వచించు _cgetts _cgetws
#నిర్వచించు _gettc getwc
#నిర్వచించు _gettc_nolock _getwc_nolock
#నిర్వచించు _gettch _getwch
#నిర్వచించు _gettch_nolock _getwch_nolock
#నిర్వచించు _gettche _getwche
#నిర్వచించు _gettche_nolock _getwche_nolock
#నిర్వచించు _gettchar getwchar
#నిర్వచించు _gettchar_nolock _getwchar_nolock
#నిర్వచించు _getts _getws
#నిర్వచించు _puttc putwc
#నిర్వచించు _puttc_nolock _putwc_nolock
#నిర్వచించు _puttchar putwchar
#నిర్వచించు _puttchar_nolock _putwchar_nolock
#నిర్వచించు _puttch _putwch
#నిర్వచించు _puttch_nolock _putwch_nolock
#నిర్వచించు _putts _putws
#నిర్వచించు _ungettc ungetwc
#నిర్వచించు _ungettc_nolock _ungetwc_nolock
#నిర్వచించు _ungettch _ungetwch
#నిర్వచించు _ungettch_nolock _ungetwch_nolock

#నిర్వచించు _tcstod wcstod
#నిర్వచించు _tcstol wcstol
#నిర్వచించు _tcstoul wcstoul
#నిర్వచించు _tcstoi64 _wcstoi64
#నిర్వచించు _tcstoui64 _wcstoui64
#నిర్వచించు _tstof _wtof
#నిర్వచించు _tstol _wtol
#నిర్వచించు _tstoi _wtoi
#నిర్వచించు _tstoi64 _wtoi64
#నిర్వచించు _tcstod_l _wcstod_l
#నిర్వచించు _tcstol_l _wcstol_l
#నిర్వచించు _tcstoul_l _wcstoul_l
#నిర్వచించు _tcstoi64_l _wcstoi64_l
#నిర్వచించు _tcstoui64_l _wcstoui64_l
#నిర్వచించు _tstof_l _wtof_l
#నిర్వచించు _tstol_l _wtol_l
#నిర్వచించు _tstoi_l _wtoi_l
#నిర్వచించు _tstoi64_l _wtoi64_l

#నిర్వచించు _itot _itow
#నిర్వచించు _ltot _ltow
#నిర్వచించు _ultot _ultow
#నిర్వచించు _ttoi _wtoi
#నిర్వచించు _ttol _wtol

#నిర్వచించు _ttoi64 _wtoi64
#నిర్వచించు _i64tot _i64tow
#నిర్వచించు _ui64tot _ui64tow

#నిర్వచించు _tcscat wcscat
#నిర్వచించు _tcschr wcschr
#నిర్వచించు _tcscpy wcscpy
#నిర్వచించు _tcscspn wcscspn
#నిర్వచించు _tcslen wcslen
#నిర్వచించు _tcsnlen wcsnlen
#నిర్వచించు _tcsncat wcsncat
#నిర్వచించు _tcsncat_l _wcsncat_l
#నిర్వచించు _tcsncpy wcsncpy
#నిర్వచించు _tcsncpy_l _wcsncpy_l
#నిర్వచించు _tcspbrk wcspbrk
#నిర్వచించు _tcsrchr wcsrchr
#నిర్వచించు _tcsspn wcsspn
#నిర్వచించు _tcsstr wcsstr
#నిర్వచించు _tcstok wcstok
#నిర్వచించు _tcstok_l _wcstok_l
#నిర్వచించు _tcserror _wcserror
#నిర్వచించు __tcserror __wcserror

#నిర్వచించు _tcsdup _wcsdup
#నిర్వచించు _tcsnset _wcsnset
#నిర్వచించు _tcsnset_l _wcsnset_l
#నిర్వచించు _tcsrev _wcsrev
#నిర్వచించు _tcsset _wcsset
#నిర్వచించు _tcsset_l _wcsset_l

#నిర్వచించు _tcscmp wcscmp
#నిర్వచించు _tcsicmp _wcsicmp
#నిర్వచించు _tcsicmp_l _wcsicmp_l
#నిర్వచించు _tcsnccmp wcsncmp
#నిర్వచించు _tcsncmp wcsncmp
#నిర్వచించు _tcsncicmp _wcsnicmp
#నిర్వచించు _tcsncicmp_l _wcsnicmp_l
#నిర్వచించు _tcsnicmp _wcsnicmp
#నిర్వచించు _tcsnicmp_l _wcsnicmp_l

#నిర్వచించు _tcscoll wcscoll
#నిర్వచించు _tcscoll_l _wcscoll_l
#నిర్వచించు _tcsicoll _wcsicoll
#నిర్వచించు _tcsicoll_l _wcsicoll_l
#నిర్వచించు _tcsnccoll _wcsncoll
#నిర్వచించు _tcsnccoll_l _wcsncoll_l
#నిర్వచించు _tcsncoll _wcsncoll
#నిర్వచించు _tcsncoll_l _wcsncoll_l
#నిర్వచించు _tcsncicoll _wcsnicoll
#నిర్వచించు _tcsncicoll_l _wcsnicoll_l
#నిర్వచించు _tcsnicoll _wcsnicoll
#నిర్వచించు _tcsnicoll_l _wcsnicoll_l

#నిర్వచించు _texecl _wexecl
#నిర్వచించు _texecle _wexecle
#నిర్వచించు _texeclp _wexeclp
#నిర్వచించు _texeclpe _wexeclpe
#నిర్వచించు _texecv _wexecv
#నిర్వచించు _texecve _wexecve
#నిర్వచించు _texecvp _wexecvp
#నిర్వచించు _texecvpe _wexecvpe

#నిర్వచించు _tspawnl _wspawnl
#నిర్వచించు _tspawnle _wspawnle
#నిర్వచించు _tspawnlp _wspawnlp
#నిర్వచించు _tspawnlpe _wspawnlpe
#నిర్వచించు _tspawnv _wspawnv
#నిర్వచించు _tspawnve _wspawnve
#నిర్వచించు _tspawnvp _wspawnvp
#నిర్వచించు _tspawnvp _wspawnvp
#నిర్వచించు _tspawnvpe _wspawnvpe

#నిర్వచించు _tsystem _wsystem

#నిర్వచించు _tasctime _wasctime
#నిర్వచించు _tctime _wctime
#నిర్వచించు _tctime32 _wctime32
#నిర్వచించు _tctime64 _wctime64
#నిర్వచించు _tstrdate _wstrdate
#నిర్వచించు _tstrtime _wstrtime
#నిర్వచించు _tutime _wutime
#నిర్వచించు _tutime32 _wutime32
#నిర్వచించు _tutime64 _wutime64
#నిర్వచించు _tcsftime wcsftime
#నిర్వచించు _tcsftime_l _wcsftime_l

#నిర్వచించు _tchdir _wchdir
#నిర్వచించు _tgetcwd _wgetcwd
#నిర్వచించు _tgetdcwd _wgetdcwd
#నిర్వచించు _tgetdcwd_nolock _wgetdcwd_nolock
#నిర్వచించు _tmkdir _wmkdir
#నిర్వచించు _trmdir _wrmdir

#నిర్వచించు _tfullpath _wfullpath
#నిర్వచించు _tgetenv _wgetenv
#నిర్వచించు _tmakepath _wmakepath
#నిర్వచించు _tpgmptr _wpgmptr
#నిర్వచించు _get_tpgmptr _get_wpgmptr
#నిర్వచించు _tputenv _wputenv
#నిర్వచించు _tsearchenv _wsearchenv
#నిర్వచించు _tsplitpath _wsplitpath

#నిర్వచించు _tfdopen _wfdopen
#నిర్వచించు _tfsopen _wfsopen
#నిర్వచించు _tfopen _wfopen
#నిర్వచించు _tfreopen _wfreopen
#నిర్వచించు _tperror _wperror
#నిర్వచించు _tpopen _wpopen
#నిర్వచించు _ttempnam _wtempnam
#నిర్వచించు _ttmpnam _wtmpnam

#నిర్వచించు _taccess _waccess
#నిర్వచించు _tchmod _wchmod
#నిర్వచించు _tcreat _wcreat
#నిర్వచించు _tfindfirst _wfindfirst
#నిర్వచించు _tfindfirst32 _wfindfirst32
#నిర్వచించు _tfindfirst64 _wfindfirst64
#నిర్వచించు _tfindfirsti64 _wfindfirsti64
#నిర్వచించు _tfindfirst32i64 _wfindfirst32i64
#నిర్వచించు _tfindfirst64i32 _wfindfirst64i32
#నిర్వచించు _tfindnext _wfindnext
#నిర్వచించు _tfindnext32 _wfindnext32
#నిర్వచించు _tfindnext64 _wfindnext64
#నిర్వచించు _tfindnexti64 _wfindnexti64
#నిర్వచించు _tfindnext32i64 _wfindnext32i64
#నిర్వచించు _tfindnext64i32 _wfindnext64i32
#నిర్వచించు _tmktemp _wmktemp
#నిర్వచించు _topen _wopen
#నిర్వచించు _tremove _wremove
#నిర్వచించు _trename _wrename
#నిర్వచించు _tsopen _wsopen
#నిర్వచించు _tunlink _wunlink

#నిర్వచించు _tfinddata_t _wfinddata_t
#నిర్వచించు _tfinddata32_t _wfinddata32_t
#నిర్వచించు _tfinddata64_t _wfinddata64_t
#నిర్వచించు _tfinddatai64_t _wfinddatai64_t
#నిర్వచించు _tfinddata32i64_t _wfinddata32i64_t
#నిర్వచించు _tfinddata64i32_t _wfinddata64i32_t

#నిర్వచించు _tstat _wstat
#నిర్వచించు _tstat32 _wstat32
#నిర్వచించు _tstat32i64 _wstat32i64
#నిర్వచించు _tstat64 _wstat64
#నిర్వచించు _tstat64i32 _wstat64i32
#నిర్వచించు _tstati64 _wstati64

#నిర్వచించు _tsetlocale _wsetlocale

#నిర్వచించు _tcsclen wcslen
#నిర్వచించు _tcscnlen wcsnlen
#నిర్వచించు _tcsclen_l(_String,_Locale) wcslen(_String)
#నిర్వచించు _tcscnlen_l(_String,Max_లెక్క_2,_Locale) wcsnlen_l((_String),(Max_లెక్క_2))
#నిర్వచించు _tcsnccat wcsncat
#నిర్వచించు _tcsnccat_l _wcsncat_l
#నిర్వచించు _tcsnccpy wcsncpy
#నిర్వచించు _tcsnccpy_l _wcsncpy_l
#నిర్వచించు _tcsncset _wcsnset

#నిర్వచించు _tcsdec _wcsdec
#నిర్వచించు _tcsinc _wcsinc
#నిర్వచించు _tcsnbcnt _wcsncnt
#నిర్వచించు _tcsnccnt _wcsncnt
#నిర్వచించు _tcsnextc _wcsnextc
#నిర్వచించు _tcsninc _wcsninc
#నిర్వచించు _tcsspnp _wcsspnp

#నిర్వచించు _tcslwr _wcslwr
#నిర్వచించు _tcslwr_l _wcslwr_l
#నిర్వచించు _tcsupr _wcsupr
#నిర్వచించు _tcsupr_l _wcsupr_l
#నిర్వచించు _tcsxfrm wcsxfrm
#నిర్వచించు _tcsxfrm_l _wcsxfrm_l

#నిర్వచించు _tclen(_pc) (1)
#నిర్వచించు _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#నిర్వచించు _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#నిర్వచించు _istalnum iswalnum
#నిర్వచించు _istalnum_l _iswalnum_l
#నిర్వచించు _istalpha iswalpha
#నిర్వచించు _istalpha_l _iswalpha_l
#నిర్వచించు _istascii iswascii
#నిర్వచించు _istcntrl iswcntrl
#నిర్వచించు _istcntrl_l _iswcntrl_l
#నిర్వచించు _istdigit iswdigit
#నిర్వచించు _istdigit_l _iswdigit_l
#నిర్వచించు _istgraph iswgraph
#నిర్వచించు _istgraph_l _iswgraph_l
#నిర్వచించు _istlower iswlower
#నిర్వచించు _istlower_l _iswlower_l
#నిర్వచించు _istprint iswprint
#నిర్వచించు _istprint_l _iswprint_l
#నిర్వచించు _istpunct iswpunct
#నిర్వచించు _istpunct_l _iswpunct_l
#నిర్వచించు _istspace iswspace
#నిర్వచించు _istspace_l _iswspace_l
#నిర్వచించు _istupper iswupper
#నిర్వచించు _istupper_l _iswupper_l
#నిర్వచించు _istxdigit iswxdigit
#నిర్వచించు _istxdigit_l _iswxdigit_l

#నిర్వచించు _totupper towupper
#నిర్వచించు _totupper_l _towupper_l
#నిర్వచించు _totlower towlower
#నిర్వచించు _totlower_l _towlower_l

#నిర్వచించు _istlegal(_Char) (1)
#నిర్వచించు _istlead(_Char) (0)
#నిర్వచించు _istleadbyte(_Char) (0)
#నిర్వచించు _istleadbyte_l(_Char,_Locale) (0)

#నిర్వచించు _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? ఖాళీ : (_cpc2)-1)
#నిర్వచించు _wcsinc(_pc) ((_pc)+1)
#నిర్వచించు _wcsnextc(_cpc) ((గుర్తులేని పూర్ణాంకం) *(_cpc))
#నిర్వచించు _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP కొలత_t __cdecl __wcsncnt(స్థిరరాశి wchar_t *_Str,కొలత_t Max_లెక్క);
#నిర్వచించు _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#నిర్వచించు _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? ఖాళీ : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : ఖాళీ))
#నిర్వచించు _wcsncpy_l(_Destination,ఆధారం_3,లెక్క_5,_Locale) (wcsncpy(_Destination,ఆధారం_3,లెక్క_5))
#నిర్వచించు _wcsncat_l(_Destination,ఆధారం_3,లెక్క_5,_Locale) (wcsncat(_Destination,ఆధారం_3,లెక్క_5))
#నిర్వచించు _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#నిర్వచించు _wcsnset_l(_Destination,విలువ_2,లెక్క_5,_Locale) (_wcsnset(_Destination,విలువ_2,లెక్క_5))
#నిర్వచించు _wcsset_l(_Destination,విలువ_2,_Locale) (_wcsset(_Destination,విలువ_2))

  /* dirent structures and functions */
#నిర్వచించు _tdirent	_wdirent
#నిర్వచించు _TDIR 		_WDIR
#నిర్వచించు _topendir	_wopendir
#నిర్వచించు _tclosedir	_wclosedir
#నిర్వచించు _treaddir	_wreaddir
#నిర్వచించు _trewinddir	_wrewinddir
#నిర్వచించు _ttelldir	_wtelldir
#నిర్వచించు _tseekdir	_wseekdir

#లేకపోతే

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అన్తర్భావ <string.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచించు _TEOF EOF

#నిర్వచించు __T(x) x

#నిర్వచించు _tmain ప్రధాన
#నిర్వచించు _tWinMain WinMain
#నిర్వచితమైతే _POSIX_
#నిర్వచించు _tenviron environ
#లేకపోతే
#నిర్వచించు _tenviron _environ
#అయితే_ముగింపు
#నిర్వచించు __targv __argv

#నిర్వచించు _tprintf రాయి
#నిర్వచించు _tprintf_l _printf_l
#నిర్వచించు _tprintf_p _printf_p
#నిర్వచించు _tprintf_p_l _printf_p_l
#నిర్వచించు _tcprintf _cprintf
#నిర్వచించు _tcprintf_l _cprintf_l
#నిర్వచించు _tcprintf_p _cprintf_p
#నిర్వచించు _tcprintf_p_l _cprintf_p_l
#నిర్వచించు _vtcprintf _vcprintf
#నిర్వచించు _vtcprintf_l _vcprintf_l
#నిర్వచించు _vtcprintf_p _vcprintf_p
#నిర్వచించు _vtcprintf_p_l _vcprintf_p_l
#నిర్వచించు _ftprintf fprintf
#నిర్వచించు _ftprintf_l _fprintf_l
#నిర్వచించు _ftprintf_p _fprintf_p
#నిర్వచించు _ftprintf_p_l _fprintf_p_l
#నిర్వచించు _stprintf sprintf
#నిర్వచించు _stprintf_l _sprintf_l
#నిర్వచించు _stprintf_p _sprintf_p
#నిర్వచించు _stprintf_p_l _sprintf_p_l
#నిర్వచించు _sctprintf _scprintf
#నిర్వచించు _sctprintf_l _scprintf_l
#నిర్వచించు _sctprintf_p _scprintf_p
#నిర్వచించు _sctprintf_p_l _scprintf_p_l
#నిర్వచించు _sntprintf _snprintf
#నిర్వచించు _sntprintf_l _snprintf_l
#నిర్వచించు _vtprintf vprintf
#నిర్వచించు _vtprintf_l _vprintf_l
#నిర్వచించు _vtprintf_p _vprintf_p
#నిర్వచించు _vtprintf_p_l _vprintf_p_l
#నిర్వచించు _vftprintf vfprintf
#నిర్వచించు _vftprintf_l _vfprintf_l
#నిర్వచించు _vftprintf_p _vfprintf_p
#నిర్వచించు _vftprintf_p_l _vfprintf_p_l
#నిర్వచించు _vstprintf vsprintf
#నిర్వచించు _vstprintf_l _vsprintf_l
#నిర్వచించు _vstprintf_p _vsprintf_p
#నిర్వచించు _vstprintf_p_l _vsprintf_p_l
#నిర్వచించు _vsctprintf _vscprintf
#నిర్వచించు _vsctprintf_l _vscprintf_l
#నిర్వచించు _vsctprintf_p _vscprintf_p
#నిర్వచించు _vsctprintf_p_l _vscprintf_p_l
#నిర్వచించు _vsntprintf _vsnprintf
#నిర్వచించు _vsntprintf_l _vsnprintf_l

#నిర్వచించు _tscanf scanf
#నిర్వచించు _tscanf_l _scanf_l
#నిర్వచించు _tcscanf _cscanf
#నిర్వచించు _tcscanf_l _cscanf_l
#నిర్వచించు _ftscanf fscanf
#నిర్వచించు _ftscanf_l _fscanf_l
#నిర్వచించు _stscanf అక్షరశ్రేణి_చదువు
#నిర్వచించు _stscanf_l _sscanf_l
#నిర్వచించు _sntscanf _snscanf
#నిర్వచించు _sntscanf_l _snscanf_l

#నిర్వచించు _fgettc fgetc
#నిర్వచించు _fgettc_nolock _fgetc_nolock
#నిర్వచించు _fgettchar _fgetchar
#నిర్వచించు _fgetts fgets
#నిర్వచించు _fputtc fputc
#నిర్వచించు _fputtc_nolock _fputc_nolock
#నిర్వచించు _fputtchar _fputchar
#నిర్వచించు _fputts fputs
#నిర్వచించు _cputts _cputs
#నిర్వచించు _gettc getc
#నిర్వచించు _gettc_nolock _getc_nolock
#నిర్వచించు _gettch _getch
#నిర్వచించు _gettch_nolock _getch_nolock
#నిర్వచించు _gettche _getche
#నిర్వచించు _gettche_nolock _getche_nolock
#నిర్వచించు _gettchar getchar
#నిర్వచించు _gettchar_nolock _getchar_nolock
#నిర్వచించు _getts gets
#నిర్వచించు _cgetts _cgets
#నిర్వచించు _puttc putc
#నిర్వచించు _puttc_nolock _putc_nolock
#నిర్వచించు _puttchar అక్షరం_రాయి
#నిర్వచించు _puttchar_nolock _putchar_nolock
#నిర్వచించు _puttch _putch
#నిర్వచించు _puttch_nolock _putch_nolock
#నిర్వచించు _putts puts
#నిర్వచించు _ungettc ungetc
#నిర్వచించు _ungettc_nolock _ungetc_nolock
#నిర్వచించు _ungettch _ungetch
#నిర్వచించు _ungettch_nolock _ungetch_nolock

#నిర్వచించు _tcstod strtod
#నిర్వచించు _tcstol strtol
#నిర్వచించు _tcstoul strtoul
#నిర్వచించు _tstof atof
#నిర్వచించు _tstol atol
#నిర్వచించు _tstoi atoi
#నిర్వచించు _tstoi64 _atoi64
#నిర్వచించు _tcstod_l _strtod_l
#నిర్వచించు _tcstol_l _strtol_l
#నిర్వచించు _tcstoul_l _strtoul_l
#నిర్వచించు _tstof_l _atof_l
#నిర్వచించు _tstol_l _atol_l
#నిర్వచించు _tstoi_l _atoi_l
#నిర్వచించు _tstoi64_l _atoi64_l

#నిర్వచించు _itot _itoa
#నిర్వచించు _ltot _ltoa
#నిర్వచించు _ultot _ultoa
#నిర్వచించు _ttoi atoi
#నిర్వచించు _ttol atol

#నిర్వచించు _ttoi64 _atoi64
#నిర్వచించు _tcstoi64 _strtoi64
#నిర్వచించు _tcstoi64_l _strtoi64_l
#నిర్వచించు _tcstoui64 _strtoui64
#నిర్వచించు _tcstoui64_l _strtoui64_l
#నిర్వచించు _i64tot _i64toa
#నిర్వచించు _ui64tot _ui64toa

#నిర్వచించు _tcscat strcat
#నిర్వచించు _tcscpy strcpy
#నిర్వచించు _tcsdup _strdup
#నిర్వచించు _tcslen అక్షరశ్రేణి_పొడవు
#ఒకవేళ 0
#నిర్వచించు _tcsnlen strnlen
#అయితే_ముగింపు
#నిర్వచించు _tcsxfrm strxfrm
#నిర్వచించు _tcsxfrm_l _strxfrm_l
#నిర్వచించు _tcserror strerror
#నిర్వచించు __tcserror _strerror

#నిర్వచించు _texecl _execl
#నిర్వచించు _texecle _execle
#నిర్వచించు _texeclp _execlp
#నిర్వచించు _texeclpe _execlpe
#నిర్వచించు _texecv _execv
#నిర్వచించు _texecve _execve
#నిర్వచించు _texecvp _execvp
#నిర్వచించు _texecvpe _execvpe

#నిర్వచించు _tspawnl _spawnl
#నిర్వచించు _tspawnle _spawnle
#నిర్వచించు _tspawnlp _spawnlp
#నిర్వచించు _tspawnlpe _spawnlpe
#నిర్వచించు _tspawnv _spawnv
#నిర్వచించు _tspawnve _spawnve
#నిర్వచించు _tspawnvp _spawnvp
#నిర్వచించు _tspawnvpe _spawnvpe

#నిర్వచించు _tsystem system

#నిర్వచించు _tasctime asctime
#నిర్వచించు _tctime ctime
#నిర్వచించు _tctime32 _ctime32
#నిర్వచించు _tctime64 _ctime64
#నిర్వచించు _tstrdate _strdate
#నిర్వచించు _tstrtime _strtime
#నిర్వచించు _tutime _utime
#నిర్వచించు _tutime32 _utime32
#నిర్వచించు _tutime64 _utime64
#నిర్వచించు _tcsftime strftime
#నిర్వచించు _tcsftime_l _strftime_l

#నిర్వచించు _tchdir _chdir
#నిర్వచించు _tgetcwd _getcwd
#నిర్వచించు _tgetdcwd _getdcwd
#నిర్వచించు _tgetdcwd_nolock _getdcwd_nolock
#నిర్వచించు _tmkdir _mkdir
#నిర్వచించు _trmdir _rmdir

#నిర్వచించు _tfullpath _fullpath
#నిర్వచించు _tgetenv getenv
#నిర్వచించు _tmakepath _makepath
#నిర్వచించు _tpgmptr _pgmptr
#నిర్వచించు _get_tpgmptr _get_pgmptr
#నిర్వచించు _tputenv _putenv
#నిర్వచించు _tsearchenv _searchenv
#నిర్వచించు _tsplitpath _splitpath

#నిర్వచితమైతే _POSIX_
#నిర్వచించు _tfdopen fdopen
#లేకపోతే
#నిర్వచించు _tfdopen _fdopen
#అయితే_ముగింపు
#నిర్వచించు _tfsopen _fsopen
#నిర్వచించు _tfopen fopen
#నిర్వచించు _tfreopen freopen
#నిర్వచించు _tperror perror
#నిర్వచించు _tpopen _popen
#నిర్వచించు _ttempnam _tempnam
#నిర్వచించు _ttmpnam tmpnam

#నిర్వచించు _tchmod _chmod
#నిర్వచించు _tcreat _creat
#నిర్వచించు _tfindfirst _findfirst
#నిర్వచించు _tfindfirst32 _findfirst32
#నిర్వచించు _tfindfirst64 _findfirst64
#నిర్వచించు _tfindfirsti64 _findfirsti64
#నిర్వచించు _tfindfirst32i64 _findfirst32i64
#నిర్వచించు _tfindfirst64i32 _findfirst64i32
#నిర్వచించు _tfindnext _findnext
#నిర్వచించు _tfindnext32 _findnext32
#నిర్వచించు _tfindnext64 _findnext64
#నిర్వచించు _tfindnexti64 _findnexti64
#నిర్వచించు _tfindnext32i64 _findnext32i64
#నిర్వచించు _tfindnext64i32 _findnext64i32
#నిర్వచించు _tmktemp _mktemp

#నిర్వచితమైతే _POSIX_
#నిర్వచించు _topen open
#నిర్వచించు _taccess access
#లేకపోతే
#నిర్వచించు _topen _open
#నిర్వచించు _taccess _access
#అయితే_ముగింపు

#నిర్వచించు _tremove remove
#నిర్వచించు _trename rename
#నిర్వచించు _tsopen _sopen
#నిర్వచించు _tunlink _unlink

#నిర్వచించు _tfinddata_t _finddata_t
#నిర్వచించు _tfinddata32_t _finddata32_t
#నిర్వచించు _tfinddata64_t __finddata64_t
#నిర్వచించు _tfinddatai64_t _finddatai64_t
#నిర్వచించు _tfinddata32i64_t _finddata32i64_t
#నిర్వచించు _tfinddata64i32_t _finddata64i32_t

#నిర్వచించు _istascii __isascii
#నిర్వచించు _istcntrl iscntrl
#నిర్వచించు _istcntrl_l _iscntrl_l
#నిర్వచించు _istxdigit isxdigit
#నిర్వచించు _istxdigit_l _isxdigit_l

#నిర్వచించు _tstat _stat
#నిర్వచించు _tstat32 _stat32
#నిర్వచించు _tstat32i64 _stat32i64
#నిర్వచించు _tstat64 _stat64
#నిర్వచించు _tstat64i32 _stat64i32
#నిర్వచించు _tstati64 _stati64

#నిర్వచించు _tsetlocale setlocale

#నిర్వచితమైతే _MBCS

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అన్తర్భావ <mbstring.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __TCHAR_DEFINED
  రకనిర్వచనం అక్షరం _TCHAR;
  రకనిర్వచనం గుర్తుగల అక్షరం _TSCHAR;
  రకనిర్వచనం గుర్తులేని అక్షరం _TUCHAR;
  రకనిర్వచనం గుర్తులేని అక్షరం _TXCHAR;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం _TINT;
#నిర్వచించు __TCHAR_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TCHAR_DEFINED
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  రకనిర్వచనం అక్షరం TCHAR;
#అయితే_ముగింపు
#నిర్వచించు _TCHAR_DEFINED
#అయితే_ముగింపు

#నిర్వచితమైతే MB_MAP_ప్రత్యక్ష

#నిర్వచించు _tcschr _mbschr
#నిర్వచించు _tcscspn _mbscspn
#నిర్వచించు _tcsncat _mbsnbcat
#నిర్వచించు _tcsncat_l _mbsnbcat_l
#నిర్వచించు _tcsncpy _mbsnbcpy
#నిర్వచించు _tcsncpy_l _mbsnbcpy_l
#నిర్వచించు _tcspbrk _mbspbrk
#నిర్వచించు _tcsrchr _mbsrchr
#నిర్వచించు _tcsspn _mbsspn
#నిర్వచించు _tcsstr _mbsstr
#నిర్వచించు _tcstok _mbstok
#నిర్వచించు _tcstok_l _mbstok_l

#నిర్వచించు _tcsnset _mbsnbset
#నిర్వచించు _tcsnset_l _mbsnbset_l
#నిర్వచించు _tcsrev _mbsrev
#నిర్వచించు _tcsset _mbsset
#నిర్వచించు _tcsset_l _mbsset_l

#నిర్వచించు _tcscmp _mbscmp
#నిర్వచించు _tcsicmp _mbsicmp
#నిర్వచించు _tcsicmp_l _mbsicmp_l
#నిర్వచించు _tcsnccmp _mbsncmp
#నిర్వచించు _tcsncmp _mbsnbcmp
#నిర్వచించు _tcsncicmp _mbsnicmp
#నిర్వచించు _tcsncicmp_l _mbsnicmp_l
#నిర్వచించు _tcsnicmp _mbsnbicmp
#నిర్వచించు _tcsnicmp_l _mbsnbicmp_l

#నిర్వచించు _tcscoll _mbscoll
#నిర్వచించు _tcscoll_l _mbscoll_l
#నిర్వచించు _tcsicoll _mbsicoll
#నిర్వచించు _tcsicoll_l _mbsicoll_l
#నిర్వచించు _tcsnccoll _mbsncoll
#నిర్వచించు _tcsnccoll_l _mbsncoll_l
#నిర్వచించు _tcsncoll _mbsnbcoll
#నిర్వచించు _tcsncoll_l _mbsnbcoll_l
#నిర్వచించు _tcsncicoll _mbsnicoll
#నిర్వచించు _tcsncicoll_l _mbsnicoll_l
#నిర్వచించు _tcsnicoll _mbsnbicoll
#నిర్వచించు _tcsnicoll_l _mbsnbicoll_l

#నిర్వచించు _tcsclen _mbslen
#నిర్వచించు _tcscnlen _mbsnlen
#నిర్వచించు _tcsclen_l _mbslen_l
#నిర్వచించు _tcscnlen_l _mbsnlen_l
#నిర్వచించు _tcsnccat _mbsncat
#నిర్వచించు _tcsnccat_l _mbsncat_l
#నిర్వచించు _tcsnccpy _mbsncpy
#నిర్వచించు _tcsnccpy_l _mbsncpy_l
#నిర్వచించు _tcsncset _mbsnset
#నిర్వచించు _tcsncset_l _mbsnset_l

#నిర్వచించు _tcsdec _mbsdec
#నిర్వచించు _tcsinc _mbsinc
#నిర్వచించు _tcsnbcnt _mbsnbcnt
#నిర్వచించు _tcsnccnt _mbsnccnt
#నిర్వచించు _tcsnextc _mbsnextc
#నిర్వచించు _tcsninc _mbsninc
#నిర్వచించు _tcsspnp _mbsspnp

#నిర్వచించు _tcslwr _mbslwr
#నిర్వచించు _tcslwr_l _mbslwr_l
#నిర్వచించు _tcsupr _mbsupr
#నిర్వచించు _tcsupr_l _mbsupr_l

#నిర్వచించు _tclen _mbclen
#నిర్వచించు _tccpy _mbccpy
#నిర్వచించు _tccpy_l _mbccpy_l
#లేకపోతే

  _CRTIMP _CONST_RETURN అక్షరం *__cdecl _tcschr(స్థిరరాశి అక్షరం *_Str,గుర్తులేని పూర్ణాంకం _Val);
  _CRTIMP కొలత_t __cdecl _tcscspn(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_Control);
  _CRTIMP అక్షరం *__cdecl _tcsncat(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsncat_l(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsncpy(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsncpy_l(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP _CONST_RETURN అక్షరం *__cdecl _tcspbrk(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_Control);
  _CRTIMP _CONST_RETURN అక్షరం *__cdecl _tcsrchr(స్థిరరాశి అక్షరం *_Str,గుర్తులేని పూర్ణాంకం _Ch);
  _CRTIMP కొలత_t __cdecl _tcsspn(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_Control);
  _CRTIMP _CONST_RETURN అక్షరం *__cdecl _tcsstr(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_Substr);
  _CRTIMP అక్షరం *__cdecl _tcstok(అక్షరం *_Str,స్థిరరాశి అక్షరం *_Delim);
  _CRTIMP అక్షరం *__cdecl _tcstok_l(అక్షరం *_Str,స్థిరరాశి అక్షరం *_Delim,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsnset(అక్షరం *_Str,గుర్తులేని పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsrev(అక్షరం *_Str);
  _CRTIMP అక్షరం *__cdecl _tcsset(అక్షరం *_Str,గుర్తులేని పూర్ణాంకం _Val);
  _CRTIMP అక్షరం *__cdecl _tcsset_l(అక్షరం *_Str,గుర్తులేని పూర్ణాంకం _Val,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcscmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _tcsicmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _tcsicmp_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcsnccmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsncmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsncicmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsncicmp_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcsnicmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsnicmp_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcscoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _tcscoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcsicoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _tcsicoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcsnccoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsnccoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcsncoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsncoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcsncicoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsncicoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _tcsnicoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _tcsnicoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP కొలత_t __cdecl _tcsclen(స్థిరరాశి అక్షరం *_Str);
  _CRTIMP కొలత_t __cdecl _tcscnlen(స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _tcsclen_l(స్థిరరాశి అక్షరం *_Str,_locale_t _Locale);
  _CRTIMP కొలత_t __cdecl _tcscnlen_l(స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsnccat(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsnccat_l(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsnccpy(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsnccpy_l(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsncset(అక్షరం *_Str,గుర్తులేని పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CRTIMP అక్షరం *__cdecl _tcsdec(స్థిరరాశి అక్షరం *ప్రారంభం_4,స్థిరరాశి అక్షరం *_Pos);
  _CRTIMP అక్షరం *__cdecl _tcsinc(స్థిరరాశి అక్షరం *_Ptr);
  _CRTIMP కొలత_t __cdecl _tcsnbcnt(స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _tcsnccnt(స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క);
  _CRTIMP గుర్తులేని పూర్ణాంకం __cdecl _tcsnextc (స్థిరరాశి అక్షరం *_Str);
  _CRTIMP అక్షరం *__cdecl _tcsninc(స్థిరరాశి అక్షరం *_Ptr,కొలత_t లెక్క_5);
  _CRTIMP అక్షరం *__cdecl _tcsspnp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP అక్షరం *__cdecl _tcslwr(అక్షరం *_Str);
  _CRTIMP అక్షరం *__cdecl _tcslwr_l(అక్షరం *_Str,_locale_t _Locale);
  _CRTIMP అక్షరం *__cdecl _tcsupr(అక్షరం *_Str);
  _CRTIMP అక్షరం *__cdecl _tcsupr_l(అక్షరం *_Str,_locale_t _Locale);
  _CRTIMP కొలత_t __cdecl _tclen(స్థిరరాశి అక్షరం *_Str);
  _CRTIMP శూన్య __cdecl _tccpy(అక్షరం *_DstCh,స్థిరరాశి అక్షరం *_SrcCh);

#నిర్వచితమైతే __cplusplus
#నిర్వచితం_కాకపోతే _CPP_TCHAR_INLINES_DEFINED
#నిర్వచించు _CPP_TCHAR_INLINES_DEFINED
  బాహ్య "C++" {
    బాహ్య అంతఃవరుస అక్షరం *__cdecl _tcschr(అక్షరం *_S,గుర్తులేని పూర్ణాంకం _C) { తిరిగి ((అక్షరం *)_tcschr((స్థిరరాశి అక్షరం *)_S,_C)); }
    బాహ్య అంతఃవరుస అక్షరం *__cdecl _tcspbrk(అక్షరం *_S,స్థిరరాశి అక్షరం *_P) { తిరిగి ((అక్షరం *)_tcspbrk((స్థిరరాశి అక్షరం *)_S,_P)); }
    బాహ్య అంతఃవరుస అక్షరం *__cdecl _tcsrchr(అక్షరం *_S,గుర్తులేని పూర్ణాంకం _C) { తిరిగి ((అక్షరం *)_tcsrchr((స్థిరరాశి అక్షరం *)_S,_C)); }
    బాహ్య అంతఃవరుస అక్షరం *__cdecl _tcsstr(అక్షరం *_S,స్థిరరాశి అక్షరం *_P) { తిరిగి ((అక్షరం *)_tcsstr((స్థిరరాశి అక్షరం *)_S,_P)); }
  }
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#నిర్వచించు _istalnum _ismbcalnum
#నిర్వచించు _istalnum_l _ismbcalnum_l
#నిర్వచించు _istalpha _ismbcalpha
#నిర్వచించు _istalpha_l _ismbcalpha_l
#నిర్వచించు _istdigit _ismbcdigit
#నిర్వచించు _istdigit_l _ismbcdigit_l
#నిర్వచించు _istgraph _ismbcgraph
#నిర్వచించు _istgraph_l _ismbcgraph_l
#నిర్వచించు _istlegal _ismbclegal
#నిర్వచించు _istlegal_l _ismbclegal_l
#నిర్వచించు _istlower _ismbclower
#నిర్వచించు _istlower_l _ismbclower_l
#నిర్వచించు _istprint _ismbcprint
#నిర్వచించు _istprint_l _ismbcprint_l
#నిర్వచించు _istpunct _ismbcpunct
#నిర్వచించు _istpunct_l _ismbcpunct_l
#నిర్వచించు _istspace _ismbcspace
#నిర్వచించు _istspace_l _ismbcspace_l
#నిర్వచించు _istupper _ismbcupper
#నిర్వచించు _istupper_l _ismbcupper_l

#నిర్వచించు _totupper _mbctoupper
#నిర్వచించు _totupper_l _mbctoupper_l
#నిర్వచించు _totlower _mbctolower
#నిర్వచించు _totlower_l _mbctolower_l

#నిర్వచించు _istlead _ismbblead
#నిర్వచించు _istleadbyte isleadbyte
#నిర్వచించు _istleadbyte_l _isleadbyte_l
#లేకపోతే

#నిర్వచితం_కాకపోతే __TCHAR_DEFINED
#నిర్వచించు __TCHAR_DEFINED
  రకనిర్వచనం అక్షరం _TCHAR;
  రకనిర్వచనం గుర్తుగల అక్షరం _TSCHAR;
  రకనిర్వచనం గుర్తులేని అక్షరం _TUCHAR;
  రకనిర్వచనం అక్షరం _TXCHAR;
  రకనిర్వచనం పూర్ణాంకం _TINT;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TCHAR_DEFINED
#నిర్వచించు _TCHAR_DEFINED
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  రకనిర్వచనం అక్షరం TCHAR;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _tcschr strchr
#నిర్వచించు _tcscspn strcspn
#నిర్వచించు _tcsncat strncat
#నిర్వచించు _tcsncat_l _strncat_l
#నిర్వచించు _tcsncpy strncpy
#నిర్వచించు _tcsncpy_l _strncpy_l
#నిర్వచించు _tcspbrk strpbrk
#నిర్వచించు _tcsrchr strrchr
#నిర్వచించు _tcsspn strspn
#నిర్వచించు _tcsstr అక్షరశ్రేణి_శోధన
#నిర్వచించు _tcstok strtok
#నిర్వచించు _tcstok_l _strtok_l

#నిర్వచించు _tcsnset _strnset
#నిర్వచించు _tcsnset_l _strnset_l
#నిర్వచించు _tcsrev _strrev
#నిర్వచించు _tcsset _strset

#నిర్వచించు _tcscmp strcmp
#నిర్వచించు _tcsicmp _stricmp
#నిర్వచించు _tcsicmp_l _stricmp_l
#నిర్వచించు _tcsnccmp అక్షరశ్రేణి_పోలిక
#నిర్వచించు _tcsncmp అక్షరశ్రేణి_పోలిక
#నిర్వచించు _tcsncicmp _strnicmp
#నిర్వచించు _tcsncicmp_l _strnicmp_l
#నిర్వచించు _tcsnicmp _strnicmp
#నిర్వచించు _tcsnicmp_l _strnicmp_l

#నిర్వచించు _tcscoll strcoll
#నిర్వచించు _tcscoll_l _strcoll_l
#నిర్వచించు _tcsicoll _stricoll
#నిర్వచించు _tcsicoll_l _stricoll_l
#నిర్వచించు _tcsnccoll _strncoll
#నిర్వచించు _tcsnccoll_l _strncoll_l
#నిర్వచించు _tcsncoll _strncoll
#నిర్వచించు _tcsncoll_l _strncoll_l
#నిర్వచించు _tcsncicoll _strnicoll
#నిర్వచించు _tcsncicoll_l _strnicoll_l
#నిర్వచించు _tcsnicoll _strnicoll
#నిర్వచించు _tcsnicoll_l _strnicoll_l

#నిర్వచించు _tcsclen అక్షరశ్రేణి_పొడవు
#నిర్వచించు _tcscnlen strnlen
#నిర్వచించు _tcsclen_l(_String,_Locale) అక్షరశ్రేణి_పొడవు(_String)
#నిర్వచించు _tcscnlen_l(_String,Max_లెక్క_2,_Locale) strnlen_l((_String),(Max_లెక్క_2))
#నిర్వచించు _tcsnccat strncat
#నిర్వచించు _tcsnccat_l _strncat_l
#నిర్వచించు _tcsnccpy strncpy
#నిర్వచించు _tcsnccpy_l _strncpy_l
#నిర్వచించు _tcsncset _strnset

#నిర్వచించు _tcsdec _strdec
#నిర్వచించు _tcsinc _strinc
#నిర్వచించు _tcsnbcnt _strncnt
#నిర్వచించు _tcsnccnt _strncnt
#నిర్వచించు _tcsnextc _strnextc
#నిర్వచించు _tcsninc _strninc
#నిర్వచించు _tcsspnp _strspnp

#నిర్వచించు _tcslwr _strlwr
#నిర్వచించు _tcslwr_l _strlwr_l
#నిర్వచించు _tcsupr _strupr
#నిర్వచించు _tcsupr_l _strupr_l
#నిర్వచించు _tcsxfrm strxfrm
#నిర్వచించు _tcsxfrm_l _strxfrm_l

#నిర్వచించు _istlead(_Char) (0)
#నిర్వచించు _istleadbyte(_Char) (0)
#నిర్వచించు _istleadbyte_l(_Char,_Locale) (0)

#నిర్వచించు _tclen(_pc) (1)
#నిర్వచించు _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#నిర్వచించు _tccmp(_cpc1,_cpc2) (((గుర్తులేని అక్షరం)*(_cpc1))-((గుర్తులేని అక్షరం)*(_cpc2)))

  /* dirent structures and functions */
#నిర్వచించు _tdirent	dirent
#నిర్వచించు _TDIR 		DIR
#నిర్వచించు _topendir	opendir
#నిర్వచించు _tclosedir	closedir
#నిర్వచించు _treaddir	readdir
#నిర్వచించు _trewinddir	rewinddir
#నిర్వచించు _ttelldir	telldir
#నిర్వచించు _tseekdir	seekdir

#నిర్వచించు _istalnum అక్షరమా_అంకెనా
#నిర్వచించు _istalnum_l _isalnum_l
#నిర్వచించు _istalpha అక్షరమా
#నిర్వచించు _istalpha_l _isalpha_l
#నిర్వచించు _istdigit అంకెనా
#నిర్వచించు _istdigit_l _isdigit_l
#నిర్వచించు _istgraph isgraph
#నిర్వచించు _istgraph_l _isgraph_l
#నిర్వచించు _istlower islower
#నిర్వచించు _istlower_l _islower_l
#నిర్వచించు _istprint isprint
#నిర్వచించు _istprint_l _isprint_l
#నిర్వచించు _istpunct ispunct
#నిర్వచించు _istpunct_l _ispunct_l
#నిర్వచించు _istspace ఖాళీనా
#నిర్వచించు _istspace_l _isspace_l
#నిర్వచించు _istupper isupper
#నిర్వచించు _istupper_l _isupper_l

#నిర్వచించు _totupper పెద్ద_అక్షరం
#నిర్వచించు _totupper_l _toupper_l
#నిర్వచించు _totlower tolower
#నిర్వచించు _totlower_l _tolower_l

#నిర్వచించు _istlegal(_c) (1)

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? ఖాళీ : (_cpc2)-1)
#నిర్వచించు _strinc(_pc) ((_pc)+1)
#నిర్వచించు _strnextc(_cpc) ((గుర్తులేని పూర్ణాంకం) *(స్థిరరాశి గుర్తులేని అక్షరం *)(_cpc))
#నిర్వచించు _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP కొలత_t __cdecl __strncnt(స్థిరరాశి అక్షరం *_Str,కొలత_t _Cnt);
#నిర్వచించు _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#నిర్వచించు _strspnp(_cpc1,_cpc2) (!_cpc1 ? ఖాళీ : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : ఖాళీ))

#నిర్వచించు _strncpy_l(_Destination,ఆధారం_3,లెక్క_5,_Locale) (strncpy(_Destination,ఆధారం_3,లెక్క_5))
#నిర్వచించు _strncat_l(_Destination,ఆధారం_3,లెక్క_5,_Locale) (strncat(_Destination,ఆధారం_3,లెక్క_5))
#నిర్వచించు _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#నిర్వచించు _strnset_l(_Destination,విలువ_2,లెక్క_5,_Locale) (_strnset(_Destination,విలువ_2,లెక్క_5))
#నిర్వచించు _strset_l(_Destination,విలువ_2,_Locale) (_strset(_Destination,విలువ_2))
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _T(x) __T(x)
#నిర్వచించు పాఠ్యం_2(x) __T(x)

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అన్తర్భావ <sec_api/tchar_s.h>
#అయితే_ముగింపు
