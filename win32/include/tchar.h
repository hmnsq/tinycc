/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#اگر_تعریف_نشده _INC_TCHAR
#تعریف_کن _INC_TCHAR

#اگر_تعریف_شده _STRSAFE_H_INCLUDED_
#خطا Need مقصد include strsafe.h after tchar.h
#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#تعریف_کن _ftcscat _tcscat
#تعریف_کن _ftcschr _tcschr
#تعریف_کن _ftcscpy _tcscpy
#تعریف_کن _ftcscspn _tcscspn
#تعریف_کن _ftcslen _tcslen
#تعریف_کن _ftcsncat _tcsncat
#تعریف_کن _ftcsncpy _tcsncpy
#تعریف_کن _ftcspbrk _tcspbrk
#تعریف_کن _ftcsrchr _tcsrchr
#تعریف_کن _ftcsspn _tcsspn
#تعریف_کن _ftcsstr _tcsstr
#تعریف_کن _ftcstok _tcstok

#تعریف_کن _ftcsdup _tcsdup
#تعریف_کن _ftcsnset _tcsnset
#تعریف_کن _ftcsrev _tcsrev
#تعریف_کن _ftcsset _tcsset

#تعریف_کن _ftcscmp _tcscmp
#تعریف_کن _ftcsicmp _tcsicmp
#تعریف_کن _ftcsnccmp _tcsnccmp
#تعریف_کن _ftcsncmp _tcsncmp
#تعریف_کن _ftcsncicmp _tcsncicmp
#تعریف_کن _ftcsnicmp _tcsnicmp

#تعریف_کن _ftcscoll _tcscoll
#تعریف_کن _ftcsicoll _tcsicoll
#تعریف_کن _ftcsnccoll _tcsnccoll
#تعریف_کن _ftcsncoll _tcsncoll
#تعریف_کن _ftcsncicoll _tcsncicoll
#تعریف_کن _ftcsnicoll _tcsnicoll

#تعریف_کن _ftcsclen _tcsclen
#تعریف_کن _ftcsnccat _tcsnccat
#تعریف_کن _ftcsnccpy _tcsnccpy
#تعریف_کن _ftcsncset _tcsncset

#تعریف_کن _ftcsdec _tcsdec
#تعریف_کن _ftcsinc _tcsinc
#تعریف_کن _ftcsnbcnt _tcsnbcnt
#تعریف_کن _ftcsnccnt _tcsnccnt
#تعریف_کن _ftcsnextc _tcsnextc
#تعریف_کن _ftcsninc _tcsninc
#تعریف_کن _ftcsspnp _tcsspnp

#تعریف_کن _ftcslwr _tcslwr
#تعریف_کن _ftcsupr _tcsupr

#تعریف_کن _ftclen _tclen
#تعریف_کن _ftccpy _tccpy
#تعریف_کن _ftccmp _tccmp

#اگر_تعریف_نشده _CONST_RETURN
#اگر_تعریف_شده __cplusplus
#تعریف_کن _CONST_RETURN ثابت
#تعریف_کن _CRT_CONST_CORRECT_OVERLOADS
#وإلا
#تعریف_کن _CONST_RETURN
#پایان_اگر
#پایان_اگر

#تعریف_کن _WConst_return _CONST_RETURN

#اگر_تعریف_شده _UNICODE

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#ضمن <wchar.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _WCTYPE_T_DEFINED
#تعریف_کن _WCTYPE_T_DEFINED
  تعريفنوع بیعلامت کوتاه wint_t;
  تعريفنوع بیعلامت کوتاه wctype_t;
#پایان_اگر

#اگر_تعریف_نشده __TCHAR_DEFINED
#تعریف_کن __TCHAR_DEFINED
  تعريفنوع wchar_t _TCHAR;
  تعريفنوع wchar_t _TSCHAR;
  تعريفنوع wchar_t _TUCHAR;
  تعريفنوع wchar_t _TXCHAR;
  تعريفنوع wint_t _TINT;
#پایان_اگر

#اگر_تعریف_نشده _TCHAR_DEFINED
#تعریف_کن _TCHAR_DEFINED
#اگر_تعریف_نشده	NO_OLDNAMES
  تعريفنوع wchar_t TCHAR;
#پایان_اگر
#پایان_اگر

#تعریف_کن _TEOF WEOF

#تعریف_کن __T(x) L##x

#تعریف_کن _tmain wmain
#تعریف_کن _tWinMain wWinMain
#تعریف_کن _tenviron _wenviron
#تعریف_کن __targv __wargv

#تعریف_کن _tprintf wprintf
#تعریف_کن _tprintf_l _wprintf_l
#تعریف_کن _tprintf_p _wprintf_p
#تعریف_کن _tprintf_p_l _wprintf_p_l
#تعریف_کن _tcprintf _cwprintf
#تعریف_کن _tcprintf_l _cwprintf_l
#تعریف_کن _tcprintf_p _cwprintf_p
#تعریف_کن _tcprintf_p_l _cwprintf_p_l
#تعریف_کن _vtcprintf _vcwprintf
#تعریف_کن _vtcprintf_l _vcwprintf_l
#تعریف_کن _vtcprintf_p _vcwprintf_p
#تعریف_کن _vtcprintf_p_l _vcwprintf_p_l
#تعریف_کن _ftprintf fwprintf
#تعریف_کن _ftprintf_l _fwprintf_l
#تعریف_کن _ftprintf_p _fwprintf_p
#تعریف_کن _ftprintf_p_l _fwprintf_p_l
#تعریف_کن _stprintf swprintf
#تعریف_کن _stprintf_l __swprintf_l
#تعریف_کن _stprintf_p _swprintf_p
#تعریف_کن _stprintf_p_l _swprintf_p_l
#تعریف_کن _sctprintf _scwprintf
#تعریف_کن _sctprintf_l _scwprintf_l
#تعریف_کن _sctprintf_p _scwprintf_p
#تعریف_کن _sctprintf_p_l _scwprintf_p_l
#تعریف_کن _sntprintf _snwprintf
#تعریف_کن _sntprintf_l _snwprintf_l
#تعریف_کن _vtprintf vwprintf
#تعریف_کن _vtprintf_l _vwprintf_l
#تعریف_کن _vtprintf_p _vwprintf_p
#تعریف_کن _vtprintf_p_l _vwprintf_p_l
#تعریف_کن _vftprintf vfwprintf
#تعریف_کن _vftprintf_l _vfwprintf_l
#تعریف_کن _vftprintf_p _vfwprintf_p
#تعریف_کن _vftprintf_p_l _vfwprintf_p_l
#تعریف_کن _vstprintf vswprintf
#تعریف_کن _vstprintf_l _vswprintf_l
#تعریف_کن _vstprintf_p _vswprintf_p
#تعریف_کن _vstprintf_p_l _vswprintf_p_l
#تعریف_کن _vsctprintf _vscwprintf
#تعریف_کن _vsctprintf_l _vscwprintf_l
#تعریف_کن _vsctprintf_p _vscwprintf_p
#تعریف_کن _vsctprintf_p_l _vscwprintf_p_l
#تعریف_کن _vsntprintf _vsnwprintf
#تعریف_کن _vsntprintf_l _vsnwprintf_l

#تعریف_کن _tscanf wscanf
#تعریف_کن _tscanf_l _wscanf_l
#تعریف_کن _tcscanf _cwscanf
#تعریف_کن _tcscanf_l _cwscanf_l
#تعریف_کن _ftscanf fwscanf
#تعریف_کن _ftscanf_l _fwscanf_l
#تعریف_کن _stscanf swscanf
#تعریف_کن _stscanf_l _swscanf_l
#تعریف_کن _sntscanf _snwscanf
#تعریف_کن _sntscanf_l _snwscanf_l

#تعریف_کن _fgettc fgetwc
#تعریف_کن _fgettc_nolock _fgetwc_nolock
#تعریف_کن _fgettchar _fgetwchar
#تعریف_کن _fgetts fgetws
#تعریف_کن _fputtc fputwc
#تعریف_کن _fputtc_nolock _fputwc_nolock
#تعریف_کن _fputtchar _fputwchar
#تعریف_کن _fputts fputws
#تعریف_کن _cputts _cputws
#تعریف_کن _cgetts _cgetws
#تعریف_کن _gettc getwc
#تعریف_کن _gettc_nolock _getwc_nolock
#تعریف_کن _gettch _getwch
#تعریف_کن _gettch_nolock _getwch_nolock
#تعریف_کن _gettche _getwche
#تعریف_کن _gettche_nolock _getwche_nolock
#تعریف_کن _gettchar getwchar
#تعریف_کن _gettchar_nolock _getwchar_nolock
#تعریف_کن _getts _getws
#تعریف_کن _puttc putwc
#تعریف_کن _puttc_nolock _putwc_nolock
#تعریف_کن _puttchar putwchar
#تعریف_کن _puttchar_nolock _putwchar_nolock
#تعریف_کن _puttch _putwch
#تعریف_کن _puttch_nolock _putwch_nolock
#تعریف_کن _putts _putws
#تعریف_کن _ungettc ungetwc
#تعریف_کن _ungettc_nolock _ungetwc_nolock
#تعریف_کن _ungettch _ungetwch
#تعریف_کن _ungettch_nolock _ungetwch_nolock

#تعریف_کن _tcstod wcstod
#تعریف_کن _tcstol wcstol
#تعریف_کن _tcstoul wcstoul
#تعریف_کن _tcstoi64 _wcstoi64
#تعریف_کن _tcstoui64 _wcstoui64
#تعریف_کن _tstof _wtof
#تعریف_کن _tstol _wtol
#تعریف_کن _tstoi _wtoi
#تعریف_کن _tstoi64 _wtoi64
#تعریف_کن _tcstod_l _wcstod_l
#تعریف_کن _tcstol_l _wcstol_l
#تعریف_کن _tcstoul_l _wcstoul_l
#تعریف_کن _tcstoi64_l _wcstoi64_l
#تعریف_کن _tcstoui64_l _wcstoui64_l
#تعریف_کن _tstof_l _wtof_l
#تعریف_کن _tstol_l _wtol_l
#تعریف_کن _tstoi_l _wtoi_l
#تعریف_کن _tstoi64_l _wtoi64_l

#تعریف_کن _itot _itow
#تعریف_کن _ltot _ltow
#تعریف_کن _ultot _ultow
#تعریف_کن _ttoi _wtoi
#تعریف_کن _ttol _wtol

#تعریف_کن _ttoi64 _wtoi64
#تعریف_کن _i64tot _i64tow
#تعریف_کن _ui64tot _ui64tow

#تعریف_کن _tcscat wcscat
#تعریف_کن _tcschr wcschr
#تعریف_کن _tcscpy wcscpy
#تعریف_کن _tcscspn wcscspn
#تعریف_کن _tcslen wcslen
#تعریف_کن _tcsnlen wcsnlen
#تعریف_کن _tcsncat wcsncat
#تعریف_کن _tcsncat_l _wcsncat_l
#تعریف_کن _tcsncpy wcsncpy
#تعریف_کن _tcsncpy_l _wcsncpy_l
#تعریف_کن _tcspbrk wcspbrk
#تعریف_کن _tcsrchr wcsrchr
#تعریف_کن _tcsspn wcsspn
#تعریف_کن _tcsstr wcsstr
#تعریف_کن _tcstok wcstok
#تعریف_کن _tcstok_l _wcstok_l
#تعریف_کن _tcserror _wcserror
#تعریف_کن __tcserror __wcserror

#تعریف_کن _tcsdup _wcsdup
#تعریف_کن _tcsnset _wcsnset
#تعریف_کن _tcsnset_l _wcsnset_l
#تعریف_کن _tcsrev _wcsrev
#تعریف_کن _tcsset _wcsset
#تعریف_کن _tcsset_l _wcsset_l

#تعریف_کن _tcscmp wcscmp
#تعریف_کن _tcsicmp _wcsicmp
#تعریف_کن _tcsicmp_l _wcsicmp_l
#تعریف_کن _tcsnccmp wcsncmp
#تعریف_کن _tcsncmp wcsncmp
#تعریف_کن _tcsncicmp _wcsnicmp
#تعریف_کن _tcsncicmp_l _wcsnicmp_l
#تعریف_کن _tcsnicmp _wcsnicmp
#تعریف_کن _tcsnicmp_l _wcsnicmp_l

#تعریف_کن _tcscoll wcscoll
#تعریف_کن _tcscoll_l _wcscoll_l
#تعریف_کن _tcsicoll _wcsicoll
#تعریف_کن _tcsicoll_l _wcsicoll_l
#تعریف_کن _tcsnccoll _wcsncoll
#تعریف_کن _tcsnccoll_l _wcsncoll_l
#تعریف_کن _tcsncoll _wcsncoll
#تعریف_کن _tcsncoll_l _wcsncoll_l
#تعریف_کن _tcsncicoll _wcsnicoll
#تعریف_کن _tcsncicoll_l _wcsnicoll_l
#تعریف_کن _tcsnicoll _wcsnicoll
#تعریف_کن _tcsnicoll_l _wcsnicoll_l

#تعریف_کن _texecl _wexecl
#تعریف_کن _texecle _wexecle
#تعریف_کن _texeclp _wexeclp
#تعریف_کن _texeclpe _wexeclpe
#تعریف_کن _texecv _wexecv
#تعریف_کن _texecve _wexecve
#تعریف_کن _texecvp _wexecvp
#تعریف_کن _texecvpe _wexecvpe

#تعریف_کن _tspawnl _wspawnl
#تعریف_کن _tspawnle _wspawnle
#تعریف_کن _tspawnlp _wspawnlp
#تعریف_کن _tspawnlpe _wspawnlpe
#تعریف_کن _tspawnv _wspawnv
#تعریف_کن _tspawnve _wspawnve
#تعریف_کن _tspawnvp _wspawnvp
#تعریف_کن _tspawnvp _wspawnvp
#تعریف_کن _tspawnvpe _wspawnvpe

#تعریف_کن _tsystem _wsystem

#تعریف_کن _tasctime _wasctime
#تعریف_کن _tctime _wctime
#تعریف_کن _tctime32 _wctime32
#تعریف_کن _tctime64 _wctime64
#تعریف_کن _tstrdate _wstrdate
#تعریف_کن _tstrtime _wstrtime
#تعریف_کن _tutime _wutime
#تعریف_کن _tutime32 _wutime32
#تعریف_کن _tutime64 _wutime64
#تعریف_کن _tcsftime wcsftime
#تعریف_کن _tcsftime_l _wcsftime_l

#تعریف_کن _tchdir _wchdir
#تعریف_کن _tgetcwd _wgetcwd
#تعریف_کن _tgetdcwd _wgetdcwd
#تعریف_کن _tgetdcwd_nolock _wgetdcwd_nolock
#تعریف_کن _tmkdir _wmkdir
#تعریف_کن _trmdir _wrmdir

#تعریف_کن _tfullpath _wfullpath
#تعریف_کن _tgetenv _wgetenv
#تعریف_کن _tmakepath _wmakepath
#تعریف_کن _tpgmptr _wpgmptr
#تعریف_کن _get_tpgmptr _get_wpgmptr
#تعریف_کن _tputenv _wputenv
#تعریف_کن _tsearchenv _wsearchenv
#تعریف_کن _tsplitpath _wsplitpath

#تعریف_کن _tfdopen _wfdopen
#تعریف_کن _tfsopen _wfsopen
#تعریف_کن _tfopen _wfopen
#تعریف_کن _tfreopen _wfreopen
#تعریف_کن _tperror _wperror
#تعریف_کن _tpopen _wpopen
#تعریف_کن _ttempnam _wtempnam
#تعریف_کن _ttmpnam _wtmpnam

#تعریف_کن _taccess _waccess
#تعریف_کن _tchmod _wchmod
#تعریف_کن _tcreat _wcreat
#تعریف_کن _tfindfirst _wfindfirst
#تعریف_کن _tfindfirst32 _wfindfirst32
#تعریف_کن _tfindfirst64 _wfindfirst64
#تعریف_کن _tfindfirsti64 _wfindfirsti64
#تعریف_کن _tfindfirst32i64 _wfindfirst32i64
#تعریف_کن _tfindfirst64i32 _wfindfirst64i32
#تعریف_کن _tfindnext _wfindnext
#تعریف_کن _tfindnext32 _wfindnext32
#تعریف_کن _tfindnext64 _wfindnext64
#تعریف_کن _tfindnexti64 _wfindnexti64
#تعریف_کن _tfindnext32i64 _wfindnext32i64
#تعریف_کن _tfindnext64i32 _wfindnext64i32
#تعریف_کن _tmktemp _wmktemp
#تعریف_کن _topen _wopen
#تعریف_کن _tremove _wremove
#تعریف_کن _trename _wrename
#تعریف_کن _tsopen _wsopen
#تعریف_کن _tunlink _wunlink

#تعریف_کن _tfinddata_t _wfinddata_t
#تعریف_کن _tfinddata32_t _wfinddata32_t
#تعریف_کن _tfinddata64_t _wfinddata64_t
#تعریف_کن _tfinddatai64_t _wfinddatai64_t
#تعریف_کن _tfinddata32i64_t _wfinddata32i64_t
#تعریف_کن _tfinddata64i32_t _wfinddata64i32_t

#تعریف_کن _tstat _wstat
#تعریف_کن _tstat32 _wstat32
#تعریف_کن _tstat32i64 _wstat32i64
#تعریف_کن _tstat64 _wstat64
#تعریف_کن _tstat64i32 _wstat64i32
#تعریف_کن _tstati64 _wstati64

#تعریف_کن _tsetlocale _wsetlocale

#تعریف_کن _tcsclen wcslen
#تعریف_کن _tcscnlen wcsnlen
#تعریف_کن _tcsclen_l(_String,_Locale) wcslen(_String)
#تعریف_کن _tcscnlen_l(_String,Max_شمار_2,_Locale) wcsnlen_l((_String),(Max_شمار_2))
#تعریف_کن _tcsnccat wcsncat
#تعریف_کن _tcsnccat_l _wcsncat_l
#تعریف_کن _tcsnccpy wcsncpy
#تعریف_کن _tcsnccpy_l _wcsncpy_l
#تعریف_کن _tcsncset _wcsnset

#تعریف_کن _tcsdec _wcsdec
#تعریف_کن _tcsinc _wcsinc
#تعریف_کن _tcsnbcnt _wcsncnt
#تعریف_کن _tcsnccnt _wcsncnt
#تعریف_کن _tcsnextc _wcsnextc
#تعریف_کن _tcsninc _wcsninc
#تعریف_کن _tcsspnp _wcsspnp

#تعریف_کن _tcslwr _wcslwr
#تعریف_کن _tcslwr_l _wcslwr_l
#تعریف_کن _tcsupr _wcsupr
#تعریف_کن _tcsupr_l _wcsupr_l
#تعریف_کن _tcsxfrm wcsxfrm
#تعریف_کن _tcsxfrm_l _wcsxfrm_l

#تعریف_کن _tclen(_pc) (1)
#تعریف_کن _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#تعریف_کن _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#تعریف_کن _istalnum iswalnum
#تعریف_کن _istalnum_l _iswalnum_l
#تعریف_کن _istalpha iswalpha
#تعریف_کن _istalpha_l _iswalpha_l
#تعریف_کن _istascii iswascii
#تعریف_کن _istcntrl iswcntrl
#تعریف_کن _istcntrl_l _iswcntrl_l
#تعریف_کن _istdigit iswdigit
#تعریف_کن _istdigit_l _iswdigit_l
#تعریف_کن _istgraph iswgraph
#تعریف_کن _istgraph_l _iswgraph_l
#تعریف_کن _istlower iswlower
#تعریف_کن _istlower_l _iswlower_l
#تعریف_کن _istprint iswprint
#تعریف_کن _istprint_l _iswprint_l
#تعریف_کن _istpunct iswpunct
#تعریف_کن _istpunct_l _iswpunct_l
#تعریف_کن _istspace iswspace
#تعریف_کن _istspace_l _iswspace_l
#تعریف_کن _istupper iswupper
#تعریف_کن _istupper_l _iswupper_l
#تعریف_کن _istxdigit iswxdigit
#تعریف_کن _istxdigit_l _iswxdigit_l

#تعریف_کن _totupper towupper
#تعریف_کن _totupper_l _towupper_l
#تعریف_کن _totlower towlower
#تعریف_کن _totlower_l _towlower_l

#تعریف_کن _istlegal(_Char) (1)
#تعریف_کن _istlead(_Char) (0)
#تعریف_کن _istleadbyte(_Char) (0)
#تعریف_کن _istleadbyte_l(_Char,_Locale) (0)

#تعریف_کن _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? عدم : (_cpc2)-1)
#تعریف_کن _wcsinc(_pc) ((_pc)+1)
#تعریف_کن _wcsnextc(_cpc) ((بیعلامت صحيح) *(_cpc))
#تعریف_کن _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP اندازه_t __cdecl __wcsncnt(ثابت wchar_t *_Str,اندازه_t Max_شمار);
#تعریف_کن _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#تعریف_کن _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? عدم : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : عدم))
#تعریف_کن _wcsncpy_l(_Destination,منبع_3,شمار_5,_Locale) (wcsncpy(_Destination,منبع_3,شمار_5))
#تعریف_کن _wcsncat_l(_Destination,منبع_3,شمار_5,_Locale) (wcsncat(_Destination,منبع_3,شمار_5))
#تعریف_کن _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#تعریف_کن _wcsnset_l(_Destination,مقدار_2,شمار_5,_Locale) (_wcsnset(_Destination,مقدار_2,شمار_5))
#تعریف_کن _wcsset_l(_Destination,مقدار_2,_Locale) (_wcsset(_Destination,مقدار_2))

  /* dirent structures and functions */
#تعریف_کن _tdirent	_wdirent
#تعریف_کن _TDIR 		_WDIR
#تعریف_کن _topendir	_wopendir
#تعریف_کن _tclosedir	_wclosedir
#تعریف_کن _treaddir	_wreaddir
#تعریف_کن _trewinddir	_wrewinddir
#تعریف_کن _ttelldir	_wtelldir
#تعریف_کن _tseekdir	_wseekdir

#وإلا

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#ضمن <string.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#تعریف_کن _TEOF EOF

#تعریف_کن __T(x) x

#تعریف_کن _tmain اصلی
#تعریف_کن _tWinMain WinMain
#اگر_تعریف_شده _POSIX_
#تعریف_کن _tenviron environ
#وإلا
#تعریف_کن _tenviron _environ
#پایان_اگر
#تعریف_کن __targv __argv

#تعریف_کن _tprintf چاپ_کن
#تعریف_کن _tprintf_l _printf_l
#تعریف_کن _tprintf_p _printf_p
#تعریف_کن _tprintf_p_l _printf_p_l
#تعریف_کن _tcprintf _cprintf
#تعریف_کن _tcprintf_l _cprintf_l
#تعریف_کن _tcprintf_p _cprintf_p
#تعریف_کن _tcprintf_p_l _cprintf_p_l
#تعریف_کن _vtcprintf _vcprintf
#تعریف_کن _vtcprintf_l _vcprintf_l
#تعریف_کن _vtcprintf_p _vcprintf_p
#تعریف_کن _vtcprintf_p_l _vcprintf_p_l
#تعریف_کن _ftprintf fprintf
#تعریف_کن _ftprintf_l _fprintf_l
#تعریف_کن _ftprintf_p _fprintf_p
#تعریف_کن _ftprintf_p_l _fprintf_p_l
#تعریف_کن _stprintf sprintf
#تعریف_کن _stprintf_l _sprintf_l
#تعریف_کن _stprintf_p _sprintf_p
#تعریف_کن _stprintf_p_l _sprintf_p_l
#تعریف_کن _sctprintf _scprintf
#تعریف_کن _sctprintf_l _scprintf_l
#تعریف_کن _sctprintf_p _scprintf_p
#تعریف_کن _sctprintf_p_l _scprintf_p_l
#تعریف_کن _sntprintf _snprintf
#تعریف_کن _sntprintf_l _snprintf_l
#تعریف_کن _vtprintf vprintf
#تعریف_کن _vtprintf_l _vprintf_l
#تعریف_کن _vtprintf_p _vprintf_p
#تعریف_کن _vtprintf_p_l _vprintf_p_l
#تعریف_کن _vftprintf vfprintf
#تعریف_کن _vftprintf_l _vfprintf_l
#تعریف_کن _vftprintf_p _vfprintf_p
#تعریف_کن _vftprintf_p_l _vfprintf_p_l
#تعریف_کن _vstprintf vsprintf
#تعریف_کن _vstprintf_l _vsprintf_l
#تعریف_کن _vstprintf_p _vsprintf_p
#تعریف_کن _vstprintf_p_l _vsprintf_p_l
#تعریف_کن _vsctprintf _vscprintf
#تعریف_کن _vsctprintf_l _vscprintf_l
#تعریف_کن _vsctprintf_p _vscprintf_p
#تعریف_کن _vsctprintf_p_l _vscprintf_p_l
#تعریف_کن _vsntprintf _vsnprintf
#تعریف_کن _vsntprintf_l _vsnprintf_l

#تعریف_کن _tscanf scanf
#تعریف_کن _tscanf_l _scanf_l
#تعریف_کن _tcscanf _cscanf
#تعریف_کن _tcscanf_l _cscanf_l
#تعریف_کن _ftscanf fscanf
#تعریف_کن _ftscanf_l _fscanf_l
#تعریف_کن _stscanf از_رشته_بخوان
#تعریف_کن _stscanf_l _sscanf_l
#تعریف_کن _sntscanf _snscanf
#تعریف_کن _sntscanf_l _snscanf_l

#تعریف_کن _fgettc fgetc
#تعریف_کن _fgettc_nolock _fgetc_nolock
#تعریف_کن _fgettchar _fgetchar
#تعریف_کن _fgetts fgets
#تعریف_کن _fputtc fputc
#تعریف_کن _fputtc_nolock _fputc_nolock
#تعریف_کن _fputtchar _fputchar
#تعریف_کن _fputts fputs
#تعریف_کن _cputts _cputs
#تعریف_کن _gettc getc
#تعریف_کن _gettc_nolock _getc_nolock
#تعریف_کن _gettch _getch
#تعریف_کن _gettch_nolock _getch_nolock
#تعریف_کن _gettche _getche
#تعریف_کن _gettche_nolock _getche_nolock
#تعریف_کن _gettchar getchar
#تعریف_کن _gettchar_nolock _getchar_nolock
#تعریف_کن _getts gets
#تعریف_کن _cgetts _cgets
#تعریف_کن _puttc putc
#تعریف_کن _puttc_nolock _putc_nolock
#تعریف_کن _puttchar حرف_چاپ_کن
#تعریف_کن _puttchar_nolock _putchar_nolock
#تعریف_کن _puttch _putch
#تعریف_کن _puttch_nolock _putch_nolock
#تعریف_کن _putts puts
#تعریف_کن _ungettc ungetc
#تعریف_کن _ungettc_nolock _ungetc_nolock
#تعریف_کن _ungettch _ungetch
#تعریف_کن _ungettch_nolock _ungetch_nolock

#تعریف_کن _tcstod strtod
#تعریف_کن _tcstol strtol
#تعریف_کن _tcstoul strtoul
#تعریف_کن _tstof atof
#تعریف_کن _tstol atol
#تعریف_کن _tstoi atoi
#تعریف_کن _tstoi64 _atoi64
#تعریف_کن _tcstod_l _strtod_l
#تعریف_کن _tcstol_l _strtol_l
#تعریف_کن _tcstoul_l _strtoul_l
#تعریف_کن _tstof_l _atof_l
#تعریف_کن _tstol_l _atol_l
#تعریف_کن _tstoi_l _atoi_l
#تعریف_کن _tstoi64_l _atoi64_l

#تعریف_کن _itot _itoa
#تعریف_کن _ltot _ltoa
#تعریف_کن _ultot _ultoa
#تعریف_کن _ttoi atoi
#تعریف_کن _ttol atol

#تعریف_کن _ttoi64 _atoi64
#تعریف_کن _tcstoi64 _strtoi64
#تعریف_کن _tcstoi64_l _strtoi64_l
#تعریف_کن _tcstoui64 _strtoui64
#تعریف_کن _tcstoui64_l _strtoui64_l
#تعریف_کن _i64tot _i64toa
#تعریف_کن _ui64tot _ui64toa

#تعریف_کن _tcscat strcat
#تعریف_کن _tcscpy strcpy
#تعریف_کن _tcsdup _strdup
#تعریف_کن _tcslen طول_رشته
#إذا 0
#تعریف_کن _tcsnlen strnlen
#پایان_اگر
#تعریف_کن _tcsxfrm strxfrm
#تعریف_کن _tcsxfrm_l _strxfrm_l
#تعریف_کن _tcserror strerror
#تعریف_کن __tcserror _strerror

#تعریف_کن _texecl _execl
#تعریف_کن _texecle _execle
#تعریف_کن _texeclp _execlp
#تعریف_کن _texeclpe _execlpe
#تعریف_کن _texecv _execv
#تعریف_کن _texecve _execve
#تعریف_کن _texecvp _execvp
#تعریف_کن _texecvpe _execvpe

#تعریف_کن _tspawnl _spawnl
#تعریف_کن _tspawnle _spawnle
#تعریف_کن _tspawnlp _spawnlp
#تعریف_کن _tspawnlpe _spawnlpe
#تعریف_کن _tspawnv _spawnv
#تعریف_کن _tspawnve _spawnve
#تعریف_کن _tspawnvp _spawnvp
#تعریف_کن _tspawnvpe _spawnvpe

#تعریف_کن _tsystem system

#تعریف_کن _tasctime asctime
#تعریف_کن _tctime ctime
#تعریف_کن _tctime32 _ctime32
#تعریف_کن _tctime64 _ctime64
#تعریف_کن _tstrdate _strdate
#تعریف_کن _tstrtime _strtime
#تعریف_کن _tutime _utime
#تعریف_کن _tutime32 _utime32
#تعریف_کن _tutime64 _utime64
#تعریف_کن _tcsftime strftime
#تعریف_کن _tcsftime_l _strftime_l

#تعریف_کن _tchdir _chdir
#تعریف_کن _tgetcwd _getcwd
#تعریف_کن _tgetdcwd _getdcwd
#تعریف_کن _tgetdcwd_nolock _getdcwd_nolock
#تعریف_کن _tmkdir _mkdir
#تعریف_کن _trmdir _rmdir

#تعریف_کن _tfullpath _fullpath
#تعریف_کن _tgetenv getenv
#تعریف_کن _tmakepath _makepath
#تعریف_کن _tpgmptr _pgmptr
#تعریف_کن _get_tpgmptr _get_pgmptr
#تعریف_کن _tputenv _putenv
#تعریف_کن _tsearchenv _searchenv
#تعریف_کن _tsplitpath _splitpath

#اگر_تعریف_شده _POSIX_
#تعریف_کن _tfdopen fdopen
#وإلا
#تعریف_کن _tfdopen _fdopen
#پایان_اگر
#تعریف_کن _tfsopen _fsopen
#تعریف_کن _tfopen fopen
#تعریف_کن _tfreopen freopen
#تعریف_کن _tperror perror
#تعریف_کن _tpopen _popen
#تعریف_کن _ttempnam _tempnam
#تعریف_کن _ttmpnam tmpnam

#تعریف_کن _tchmod _chmod
#تعریف_کن _tcreat _creat
#تعریف_کن _tfindfirst _findfirst
#تعریف_کن _tfindfirst32 _findfirst32
#تعریف_کن _tfindfirst64 _findfirst64
#تعریف_کن _tfindfirsti64 _findfirsti64
#تعریف_کن _tfindfirst32i64 _findfirst32i64
#تعریف_کن _tfindfirst64i32 _findfirst64i32
#تعریف_کن _tfindnext _findnext
#تعریف_کن _tfindnext32 _findnext32
#تعریف_کن _tfindnext64 _findnext64
#تعریف_کن _tfindnexti64 _findnexti64
#تعریف_کن _tfindnext32i64 _findnext32i64
#تعریف_کن _tfindnext64i32 _findnext64i32
#تعریف_کن _tmktemp _mktemp

#اگر_تعریف_شده _POSIX_
#تعریف_کن _topen open
#تعریف_کن _taccess access
#وإلا
#تعریف_کن _topen _open
#تعریف_کن _taccess _access
#پایان_اگر

#تعریف_کن _tremove remove
#تعریف_کن _trename rename
#تعریف_کن _tsopen _sopen
#تعریف_کن _tunlink _unlink

#تعریف_کن _tfinddata_t _finddata_t
#تعریف_کن _tfinddata32_t _finddata32_t
#تعریف_کن _tfinddata64_t __finddata64_t
#تعریف_کن _tfinddatai64_t _finddatai64_t
#تعریف_کن _tfinddata32i64_t _finddata32i64_t
#تعریف_کن _tfinddata64i32_t _finddata64i32_t

#تعریف_کن _istascii __isascii
#تعریف_کن _istcntrl iscntrl
#تعریف_کن _istcntrl_l _iscntrl_l
#تعریف_کن _istxdigit isxdigit
#تعریف_کن _istxdigit_l _isxdigit_l

#تعریف_کن _tstat _stat
#تعریف_کن _tstat32 _stat32
#تعریف_کن _tstat32i64 _stat32i64
#تعریف_کن _tstat64 _stat64
#تعریف_کن _tstat64i32 _stat64i32
#تعریف_کن _tstati64 _stati64

#تعریف_کن _tsetlocale setlocale

#اگر_تعریف_شده _MBCS

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#ضمن <mbstring.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده __TCHAR_DEFINED
  تعريفنوع حرف _TCHAR;
  تعريفنوع علامتدار حرف _TSCHAR;
  تعريفنوع بیعلامت حرف _TUCHAR;
  تعريفنوع بیعلامت حرف _TXCHAR;
  تعريفنوع بیعلامت صحيح _TINT;
#تعریف_کن __TCHAR_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _TCHAR_DEFINED
#اگر_تعریف_نشده	NO_OLDNAMES
  تعريفنوع حرف TCHAR;
#پایان_اگر
#تعریف_کن _TCHAR_DEFINED
#پایان_اگر

#اگر_تعریف_شده MB_MAP_مستقیم

#تعریف_کن _tcschr _mbschr
#تعریف_کن _tcscspn _mbscspn
#تعریف_کن _tcsncat _mbsnbcat
#تعریف_کن _tcsncat_l _mbsnbcat_l
#تعریف_کن _tcsncpy _mbsnbcpy
#تعریف_کن _tcsncpy_l _mbsnbcpy_l
#تعریف_کن _tcspbrk _mbspbrk
#تعریف_کن _tcsrchr _mbsrchr
#تعریف_کن _tcsspn _mbsspn
#تعریف_کن _tcsstr _mbsstr
#تعریف_کن _tcstok _mbstok
#تعریف_کن _tcstok_l _mbstok_l

#تعریف_کن _tcsnset _mbsnbset
#تعریف_کن _tcsnset_l _mbsnbset_l
#تعریف_کن _tcsrev _mbsrev
#تعریف_کن _tcsset _mbsset
#تعریف_کن _tcsset_l _mbsset_l

#تعریف_کن _tcscmp _mbscmp
#تعریف_کن _tcsicmp _mbsicmp
#تعریف_کن _tcsicmp_l _mbsicmp_l
#تعریف_کن _tcsnccmp _mbsncmp
#تعریف_کن _tcsncmp _mbsnbcmp
#تعریف_کن _tcsncicmp _mbsnicmp
#تعریف_کن _tcsncicmp_l _mbsnicmp_l
#تعریف_کن _tcsnicmp _mbsnbicmp
#تعریف_کن _tcsnicmp_l _mbsnbicmp_l

#تعریف_کن _tcscoll _mbscoll
#تعریف_کن _tcscoll_l _mbscoll_l
#تعریف_کن _tcsicoll _mbsicoll
#تعریف_کن _tcsicoll_l _mbsicoll_l
#تعریف_کن _tcsnccoll _mbsncoll
#تعریف_کن _tcsnccoll_l _mbsncoll_l
#تعریف_کن _tcsncoll _mbsnbcoll
#تعریف_کن _tcsncoll_l _mbsnbcoll_l
#تعریف_کن _tcsncicoll _mbsnicoll
#تعریف_کن _tcsncicoll_l _mbsnicoll_l
#تعریف_کن _tcsnicoll _mbsnbicoll
#تعریف_کن _tcsnicoll_l _mbsnbicoll_l

#تعریف_کن _tcsclen _mbslen
#تعریف_کن _tcscnlen _mbsnlen
#تعریف_کن _tcsclen_l _mbslen_l
#تعریف_کن _tcscnlen_l _mbsnlen_l
#تعریف_کن _tcsnccat _mbsncat
#تعریف_کن _tcsnccat_l _mbsncat_l
#تعریف_کن _tcsnccpy _mbsncpy
#تعریف_کن _tcsnccpy_l _mbsncpy_l
#تعریف_کن _tcsncset _mbsnset
#تعریف_کن _tcsncset_l _mbsnset_l

#تعریف_کن _tcsdec _mbsdec
#تعریف_کن _tcsinc _mbsinc
#تعریف_کن _tcsnbcnt _mbsnbcnt
#تعریف_کن _tcsnccnt _mbsnccnt
#تعریف_کن _tcsnextc _mbsnextc
#تعریف_کن _tcsninc _mbsninc
#تعریف_کن _tcsspnp _mbsspnp

#تعریف_کن _tcslwr _mbslwr
#تعریف_کن _tcslwr_l _mbslwr_l
#تعریف_کن _tcsupr _mbsupr
#تعریف_کن _tcsupr_l _mbsupr_l

#تعریف_کن _tclen _mbclen
#تعریف_کن _tccpy _mbccpy
#تعریف_کن _tccpy_l _mbccpy_l
#وإلا

  _CRTIMP _CONST_RETURN حرف *__cdecl _tcschr(ثابت حرف *_Str,بیعلامت صحيح _Val);
  _CRTIMP اندازه_t __cdecl _tcscspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP حرف *__cdecl _tcsncat(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP حرف *__cdecl _tcsncat_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncpy(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP حرف *__cdecl _tcsncpy_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcspbrk(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsrchr(ثابت حرف *_Str,بیعلامت صحيح _Ch);
  _CRTIMP اندازه_t __cdecl _tcsspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsstr(ثابت حرف *_Str,ثابت حرف *_Substr);
  _CRTIMP حرف *__cdecl _tcstok(حرف *_Str,ثابت حرف *_Delim);
  _CRTIMP حرف *__cdecl _tcstok_l(حرف *_Str,ثابت حرف *_Delim,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnset(حرف *_Str,بیعلامت صحيح _Val,اندازه_t Max_شمار);
  _CRTIMP حرف *__cdecl _tcsrev(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsset(حرف *_Str,بیعلامت صحيح _Val);
  _CRTIMP حرف *__cdecl _tcsset_l(حرف *_Str,بیعلامت صحيح _Val,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcscmp(ثابت حرف *_Str1,ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _tcsicmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcsicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnccmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsncmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsncicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsncicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsnicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcscoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcscoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsicoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcsicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnccoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsnccoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsncoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsncoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsncicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsncicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _tcsnicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _tcsclen(ثابت حرف *_Str);
  _CRTIMP اندازه_t __cdecl _tcscnlen(ثابت حرف *_Str,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _tcsclen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _tcscnlen_l(ثابت حرف *_Str,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccat(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP حرف *__cdecl _tcsnccat_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccpy(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP حرف *__cdecl _tcsnccpy_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncset(حرف *_Str,بیعلامت صحيح _Val,اندازه_t Max_شمار);
  _CRTIMP حرف *__cdecl _tcsdec(ثابت حرف *شروع_4,ثابت حرف *_Pos);
  _CRTIMP حرف *__cdecl _tcsinc(ثابت حرف *_Ptr);
  _CRTIMP اندازه_t __cdecl _tcsnbcnt(ثابت حرف *_Str,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _tcsnccnt(ثابت حرف *_Str,اندازه_t Max_شمار);
  _CRTIMP بیعلامت صحيح __cdecl _tcsnextc (ثابت حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsninc(ثابت حرف *_Ptr,اندازه_t شمار_5);
  _CRTIMP حرف *__cdecl _tcsspnp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP حرف *__cdecl _tcslwr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcslwr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsupr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsupr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _tclen(ثابت حرف *_Str);
  _CRTIMP فراغ __cdecl _tccpy(حرف *_DstCh,ثابت حرف *_SrcCh);

#اگر_تعریف_شده __cplusplus
#اگر_تعریف_نشده _CPP_TCHAR_INLINES_DEFINED
#تعریف_کن _CPP_TCHAR_INLINES_DEFINED
  خارجي "C++" {
    خارجي مضمن حرف *__cdecl _tcschr(حرف *_S,بیعلامت صحيح _C) { أرجع ((حرف *)_tcschr((ثابت حرف *)_S,_C)); }
    خارجي مضمن حرف *__cdecl _tcspbrk(حرف *_S,ثابت حرف *_P) { أرجع ((حرف *)_tcspbrk((ثابت حرف *)_S,_P)); }
    خارجي مضمن حرف *__cdecl _tcsrchr(حرف *_S,بیعلامت صحيح _C) { أرجع ((حرف *)_tcsrchr((ثابت حرف *)_S,_C)); }
    خارجي مضمن حرف *__cdecl _tcsstr(حرف *_S,ثابت حرف *_P) { أرجع ((حرف *)_tcsstr((ثابت حرف *)_S,_P)); }
  }
#پایان_اگر
#پایان_اگر
#پایان_اگر

#تعریف_کن _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#تعریف_کن _istalnum _ismbcalnum
#تعریف_کن _istalnum_l _ismbcalnum_l
#تعریف_کن _istalpha _ismbcalpha
#تعریف_کن _istalpha_l _ismbcalpha_l
#تعریف_کن _istdigit _ismbcdigit
#تعریف_کن _istdigit_l _ismbcdigit_l
#تعریف_کن _istgraph _ismbcgraph
#تعریف_کن _istgraph_l _ismbcgraph_l
#تعریف_کن _istlegal _ismbclegal
#تعریف_کن _istlegal_l _ismbclegal_l
#تعریف_کن _istlower _ismbclower
#تعریف_کن _istlower_l _ismbclower_l
#تعریف_کن _istprint _ismbcprint
#تعریف_کن _istprint_l _ismbcprint_l
#تعریف_کن _istpunct _ismbcpunct
#تعریف_کن _istpunct_l _ismbcpunct_l
#تعریف_کن _istspace _ismbcspace
#تعریف_کن _istspace_l _ismbcspace_l
#تعریف_کن _istupper _ismbcupper
#تعریف_کن _istupper_l _ismbcupper_l

#تعریف_کن _totupper _mbctoupper
#تعریف_کن _totupper_l _mbctoupper_l
#تعریف_کن _totlower _mbctolower
#تعریف_کن _totlower_l _mbctolower_l

#تعریف_کن _istlead _ismbblead
#تعریف_کن _istleadbyte isleadbyte
#تعریف_کن _istleadbyte_l _isleadbyte_l
#وإلا

#اگر_تعریف_نشده __TCHAR_DEFINED
#تعریف_کن __TCHAR_DEFINED
  تعريفنوع حرف _TCHAR;
  تعريفنوع علامتدار حرف _TSCHAR;
  تعريفنوع بیعلامت حرف _TUCHAR;
  تعريفنوع حرف _TXCHAR;
  تعريفنوع صحيح _TINT;
#پایان_اگر

#اگر_تعریف_نشده _TCHAR_DEFINED
#تعریف_کن _TCHAR_DEFINED
#اگر_تعریف_نشده	NO_OLDNAMES
  تعريفنوع حرف TCHAR;
#پایان_اگر
#پایان_اگر

#تعریف_کن _tcschr strchr
#تعریف_کن _tcscspn strcspn
#تعریف_کن _tcsncat strncat
#تعریف_کن _tcsncat_l _strncat_l
#تعریف_کن _tcsncpy strncpy
#تعریف_کن _tcsncpy_l _strncpy_l
#تعریف_کن _tcspbrk strpbrk
#تعریف_کن _tcsrchr strrchr
#تعریف_کن _tcsspn strspn
#تعریف_کن _tcsstr جستجوی_رشته
#تعریف_کن _tcstok strtok
#تعریف_کن _tcstok_l _strtok_l

#تعریف_کن _tcsnset _strnset
#تعریف_کن _tcsnset_l _strnset_l
#تعریف_کن _tcsrev _strrev
#تعریف_کن _tcsset _strset

#تعریف_کن _tcscmp strcmp
#تعریف_کن _tcsicmp _stricmp
#تعریف_کن _tcsicmp_l _stricmp_l
#تعریف_کن _tcsnccmp مقایسه_رشته
#تعریف_کن _tcsncmp مقایسه_رشته
#تعریف_کن _tcsncicmp _strnicmp
#تعریف_کن _tcsncicmp_l _strnicmp_l
#تعریف_کن _tcsnicmp _strnicmp
#تعریف_کن _tcsnicmp_l _strnicmp_l

#تعریف_کن _tcscoll strcoll
#تعریف_کن _tcscoll_l _strcoll_l
#تعریف_کن _tcsicoll _stricoll
#تعریف_کن _tcsicoll_l _stricoll_l
#تعریف_کن _tcsnccoll _strncoll
#تعریف_کن _tcsnccoll_l _strncoll_l
#تعریف_کن _tcsncoll _strncoll
#تعریف_کن _tcsncoll_l _strncoll_l
#تعریف_کن _tcsncicoll _strnicoll
#تعریف_کن _tcsncicoll_l _strnicoll_l
#تعریف_کن _tcsnicoll _strnicoll
#تعریف_کن _tcsnicoll_l _strnicoll_l

#تعریف_کن _tcsclen طول_رشته
#تعریف_کن _tcscnlen strnlen
#تعریف_کن _tcsclen_l(_String,_Locale) طول_رشته(_String)
#تعریف_کن _tcscnlen_l(_String,Max_شمار_2,_Locale) strnlen_l((_String),(Max_شمار_2))
#تعریف_کن _tcsnccat strncat
#تعریف_کن _tcsnccat_l _strncat_l
#تعریف_کن _tcsnccpy strncpy
#تعریف_کن _tcsnccpy_l _strncpy_l
#تعریف_کن _tcsncset _strnset

#تعریف_کن _tcsdec _strdec
#تعریف_کن _tcsinc _strinc
#تعریف_کن _tcsnbcnt _strncnt
#تعریف_کن _tcsnccnt _strncnt
#تعریف_کن _tcsnextc _strnextc
#تعریف_کن _tcsninc _strninc
#تعریف_کن _tcsspnp _strspnp

#تعریف_کن _tcslwr _strlwr
#تعریف_کن _tcslwr_l _strlwr_l
#تعریف_کن _tcsupr _strupr
#تعریف_کن _tcsupr_l _strupr_l
#تعریف_کن _tcsxfrm strxfrm
#تعریف_کن _tcsxfrm_l _strxfrm_l

#تعریف_کن _istlead(_Char) (0)
#تعریف_کن _istleadbyte(_Char) (0)
#تعریف_کن _istleadbyte_l(_Char,_Locale) (0)

#تعریف_کن _tclen(_pc) (1)
#تعریف_کن _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#تعریف_کن _tccmp(_cpc1,_cpc2) (((بیعلامت حرف)*(_cpc1))-((بیعلامت حرف)*(_cpc2)))

  /* dirent structures and functions */
#تعریف_کن _tdirent	dirent
#تعریف_کن _TDIR 		DIR
#تعریف_کن _topendir	opendir
#تعریف_کن _tclosedir	closedir
#تعریف_کن _treaddir	readdir
#تعریف_کن _trewinddir	rewinddir
#تعریف_کن _ttelldir	telldir
#تعریف_کن _tseekdir	seekdir

#تعریف_کن _istalnum آیا_حرف_یا_رقم
#تعریف_کن _istalnum_l _isalnum_l
#تعریف_کن _istalpha آیا_حرف
#تعریف_کن _istalpha_l _isalpha_l
#تعریف_کن _istdigit آیا_رقم
#تعریف_کن _istdigit_l _isdigit_l
#تعریف_کن _istgraph isgraph
#تعریف_کن _istgraph_l _isgraph_l
#تعریف_کن _istlower islower
#تعریف_کن _istlower_l _islower_l
#تعریف_کن _istprint isprint
#تعریف_کن _istprint_l _isprint_l
#تعریف_کن _istpunct ispunct
#تعریف_کن _istpunct_l _ispunct_l
#تعریف_کن _istspace آیا_فاصله
#تعریف_کن _istspace_l _isspace_l
#تعریف_کن _istupper isupper
#تعریف_کن _istupper_l _isupper_l

#تعریف_کن _totupper به_بزرگ
#تعریف_کن _totupper_l _toupper_l
#تعریف_کن _totlower tolower
#تعریف_کن _totlower_l _tolower_l

#تعریف_کن _istlegal(_c) (1)

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#تعریف_کن _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? عدم : (_cpc2)-1)
#تعریف_کن _strinc(_pc) ((_pc)+1)
#تعریف_کن _strnextc(_cpc) ((بیعلامت صحيح) *(ثابت بیعلامت حرف *)(_cpc))
#تعریف_کن _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP اندازه_t __cdecl __strncnt(ثابت حرف *_Str,اندازه_t _Cnt);
#تعریف_کن _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#تعریف_کن _strspnp(_cpc1,_cpc2) (!_cpc1 ? عدم : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : عدم))

#تعریف_کن _strncpy_l(_Destination,منبع_3,شمار_5,_Locale) (strncpy(_Destination,منبع_3,شمار_5))
#تعریف_کن _strncat_l(_Destination,منبع_3,شمار_5,_Locale) (strncat(_Destination,منبع_3,شمار_5))
#تعریف_کن _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#تعریف_کن _strnset_l(_Destination,مقدار_2,شمار_5,_Locale) (_strnset(_Destination,مقدار_2,شمار_5))
#تعریف_کن _strset_l(_Destination,مقدار_2,_Locale) (_strset(_Destination,مقدار_2))
#پایان_اگر
#پایان_اگر

#تعریف_کن _T(x) __T(x)
#تعریف_کن متن_2(x) __T(x)

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#ضمن <sec_api/tchar_s.h>
#پایان_اگر
