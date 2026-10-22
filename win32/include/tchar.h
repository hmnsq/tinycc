/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#جيڪڏهن_وصف_نه_ٿيل _INC_TCHAR
#وصف_ڪريو _INC_TCHAR

#جيڪڏهن_وصف_ٿيل _STRSAFE_H_INCLUDED_
#غلطي Need منزل include strsafe.h after tchar.h
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#وصف_ڪريو _ftcscat _tcscat
#وصف_ڪريو _ftcschr _tcschr
#وصف_ڪريو _ftcscpy _tcscpy
#وصف_ڪريو _ftcscspn _tcscspn
#وصف_ڪريو _ftcslen _tcslen
#وصف_ڪريو _ftcsncat _tcsncat
#وصف_ڪريو _ftcsncpy _tcsncpy
#وصف_ڪريو _ftcspbrk _tcspbrk
#وصف_ڪريو _ftcsrchr _tcsrchr
#وصف_ڪريو _ftcsspn _tcsspn
#وصف_ڪريو _ftcsstr _tcsstr
#وصف_ڪريو _ftcstok _tcstok

#وصف_ڪريو _ftcsdup _tcsdup
#وصف_ڪريو _ftcsnset _tcsnset
#وصف_ڪريو _ftcsrev _tcsrev
#وصف_ڪريو _ftcsset _tcsset

#وصف_ڪريو _ftcscmp _tcscmp
#وصف_ڪريو _ftcsicmp _tcsicmp
#وصف_ڪريو _ftcsnccmp _tcsnccmp
#وصف_ڪريو _ftcsncmp _tcsncmp
#وصف_ڪريو _ftcsncicmp _tcsncicmp
#وصف_ڪريو _ftcsnicmp _tcsnicmp

#وصف_ڪريو _ftcscoll _tcscoll
#وصف_ڪريو _ftcsicoll _tcsicoll
#وصف_ڪريو _ftcsnccoll _tcsnccoll
#وصف_ڪريو _ftcsncoll _tcsncoll
#وصف_ڪريو _ftcsncicoll _tcsncicoll
#وصف_ڪريو _ftcsnicoll _tcsnicoll

#وصف_ڪريو _ftcsclen _tcsclen
#وصف_ڪريو _ftcsnccat _tcsnccat
#وصف_ڪريو _ftcsnccpy _tcsnccpy
#وصف_ڪريو _ftcsncset _tcsncset

#وصف_ڪريو _ftcsdec _tcsdec
#وصف_ڪريو _ftcsinc _tcsinc
#وصف_ڪريو _ftcsnbcnt _tcsnbcnt
#وصف_ڪريو _ftcsnccnt _tcsnccnt
#وصف_ڪريو _ftcsnextc _tcsnextc
#وصف_ڪريو _ftcsninc _tcsninc
#وصف_ڪريو _ftcsspnp _tcsspnp

#وصف_ڪريو _ftcslwr _tcslwr
#وصف_ڪريو _ftcsupr _tcsupr

#وصف_ڪريو _ftclen _tclen
#وصف_ڪريو _ftccpy _tccpy
#وصف_ڪريو _ftccmp _tccmp

#جيڪڏهن_وصف_نه_ٿيل _CONST_RETURN
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو _CONST_RETURN ثابت
#وصف_ڪريو _CRT_CONST_CORRECT_OVERLOADS
#وإلا
#وصف_ڪريو _CONST_RETURN
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _WConst_return _CONST_RETURN

#جيڪڏهن_وصف_ٿيل _UNICODE

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#ضمن <wchar.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_T_DEFINED
#وصف_ڪريو _WCTYPE_T_DEFINED
  تعريفنوع بنانشان ننڍو wint_t;
  تعريفنوع بنانشان ننڍو wctype_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __TCHAR_DEFINED
#وصف_ڪريو __TCHAR_DEFINED
  تعريفنوع wchar_t _TCHAR;
  تعريفنوع wchar_t _TSCHAR;
  تعريفنوع wchar_t _TUCHAR;
  تعريفنوع wchar_t _TXCHAR;
  تعريفنوع wint_t _TINT;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TCHAR_DEFINED
#وصف_ڪريو _TCHAR_DEFINED
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  تعريفنوع wchar_t TCHAR;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _TEOF WEOF

#وصف_ڪريو __T(x) L##x

#وصف_ڪريو _tmain wmain
#وصف_ڪريو _tWinMain wWinMain
#وصف_ڪريو _tenviron _wenviron
#وصف_ڪريو __targv __wargv

#وصف_ڪريو _tprintf wprintf
#وصف_ڪريو _tprintf_l _wprintf_l
#وصف_ڪريو _tprintf_p _wprintf_p
#وصف_ڪريو _tprintf_p_l _wprintf_p_l
#وصف_ڪريو _tcprintf _cwprintf
#وصف_ڪريو _tcprintf_l _cwprintf_l
#وصف_ڪريو _tcprintf_p _cwprintf_p
#وصف_ڪريو _tcprintf_p_l _cwprintf_p_l
#وصف_ڪريو _vtcprintf _vcwprintf
#وصف_ڪريو _vtcprintf_l _vcwprintf_l
#وصف_ڪريو _vtcprintf_p _vcwprintf_p
#وصف_ڪريو _vtcprintf_p_l _vcwprintf_p_l
#وصف_ڪريو _ftprintf fwprintf
#وصف_ڪريو _ftprintf_l _fwprintf_l
#وصف_ڪريو _ftprintf_p _fwprintf_p
#وصف_ڪريو _ftprintf_p_l _fwprintf_p_l
#وصف_ڪريو _stprintf swprintf
#وصف_ڪريو _stprintf_l __swprintf_l
#وصف_ڪريو _stprintf_p _swprintf_p
#وصف_ڪريو _stprintf_p_l _swprintf_p_l
#وصف_ڪريو _sctprintf _scwprintf
#وصف_ڪريو _sctprintf_l _scwprintf_l
#وصف_ڪريو _sctprintf_p _scwprintf_p
#وصف_ڪريو _sctprintf_p_l _scwprintf_p_l
#وصف_ڪريو _sntprintf _snwprintf
#وصف_ڪريو _sntprintf_l _snwprintf_l
#وصف_ڪريو _vtprintf vwprintf
#وصف_ڪريو _vtprintf_l _vwprintf_l
#وصف_ڪريو _vtprintf_p _vwprintf_p
#وصف_ڪريو _vtprintf_p_l _vwprintf_p_l
#وصف_ڪريو _vftprintf vfwprintf
#وصف_ڪريو _vftprintf_l _vfwprintf_l
#وصف_ڪريو _vftprintf_p _vfwprintf_p
#وصف_ڪريو _vftprintf_p_l _vfwprintf_p_l
#وصف_ڪريو _vstprintf vswprintf
#وصف_ڪريو _vstprintf_l _vswprintf_l
#وصف_ڪريو _vstprintf_p _vswprintf_p
#وصف_ڪريو _vstprintf_p_l _vswprintf_p_l
#وصف_ڪريو _vsctprintf _vscwprintf
#وصف_ڪريو _vsctprintf_l _vscwprintf_l
#وصف_ڪريو _vsctprintf_p _vscwprintf_p
#وصف_ڪريو _vsctprintf_p_l _vscwprintf_p_l
#وصف_ڪريو _vsntprintf _vsnwprintf
#وصف_ڪريو _vsntprintf_l _vsnwprintf_l

#وصف_ڪريو _tscanf wscanf
#وصف_ڪريو _tscanf_l _wscanf_l
#وصف_ڪريو _tcscanf _cwscanf
#وصف_ڪريو _tcscanf_l _cwscanf_l
#وصف_ڪريو _ftscanf fwscanf
#وصف_ڪريو _ftscanf_l _fwscanf_l
#وصف_ڪريو _stscanf swscanf
#وصف_ڪريو _stscanf_l _swscanf_l
#وصف_ڪريو _sntscanf _snwscanf
#وصف_ڪريو _sntscanf_l _snwscanf_l

#وصف_ڪريو _fgettc fgetwc
#وصف_ڪريو _fgettc_nolock _fgetwc_nolock
#وصف_ڪريو _fgettchar _fgetwchar
#وصف_ڪريو _fgetts fgetws
#وصف_ڪريو _fputtc fputwc
#وصف_ڪريو _fputtc_nolock _fputwc_nolock
#وصف_ڪريو _fputtchar _fputwchar
#وصف_ڪريو _fputts fputws
#وصف_ڪريو _cputts _cputws
#وصف_ڪريو _cgetts _cgetws
#وصف_ڪريو _gettc getwc
#وصف_ڪريو _gettc_nolock _getwc_nolock
#وصف_ڪريو _gettch _getwch
#وصف_ڪريو _gettch_nolock _getwch_nolock
#وصف_ڪريو _gettche _getwche
#وصف_ڪريو _gettche_nolock _getwche_nolock
#وصف_ڪريو _gettchar getwchar
#وصف_ڪريو _gettchar_nolock _getwchar_nolock
#وصف_ڪريو _getts _getws
#وصف_ڪريو _puttc putwc
#وصف_ڪريو _puttc_nolock _putwc_nolock
#وصف_ڪريو _puttchar putwchar
#وصف_ڪريو _puttchar_nolock _putwchar_nolock
#وصف_ڪريو _puttch _putwch
#وصف_ڪريو _puttch_nolock _putwch_nolock
#وصف_ڪريو _putts _putws
#وصف_ڪريو _ungettc ungetwc
#وصف_ڪريو _ungettc_nolock _ungetwc_nolock
#وصف_ڪريو _ungettch _ungetwch
#وصف_ڪريو _ungettch_nolock _ungetwch_nolock

#وصف_ڪريو _tcstod wcstod
#وصف_ڪريو _tcstol wcstol
#وصف_ڪريو _tcstoul wcstoul
#وصف_ڪريو _tcstoi64 _wcstoi64
#وصف_ڪريو _tcstoui64 _wcstoui64
#وصف_ڪريو _tstof _wtof
#وصف_ڪريو _tstol _wtol
#وصف_ڪريو _tstoi _wtoi
#وصف_ڪريو _tstoi64 _wtoi64
#وصف_ڪريو _tcstod_l _wcstod_l
#وصف_ڪريو _tcstol_l _wcstol_l
#وصف_ڪريو _tcstoul_l _wcstoul_l
#وصف_ڪريو _tcstoi64_l _wcstoi64_l
#وصف_ڪريو _tcstoui64_l _wcstoui64_l
#وصف_ڪريو _tstof_l _wtof_l
#وصف_ڪريو _tstol_l _wtol_l
#وصف_ڪريو _tstoi_l _wtoi_l
#وصف_ڪريو _tstoi64_l _wtoi64_l

#وصف_ڪريو _itot _itow
#وصف_ڪريو _ltot _ltow
#وصف_ڪريو _ultot _ultow
#وصف_ڪريو _ttoi _wtoi
#وصف_ڪريو _ttol _wtol

#وصف_ڪريو _ttoi64 _wtoi64
#وصف_ڪريو _i64tot _i64tow
#وصف_ڪريو _ui64tot _ui64tow

#وصف_ڪريو _tcscat wcscat
#وصف_ڪريو _tcschr wcschr
#وصف_ڪريو _tcscpy wcscpy
#وصف_ڪريو _tcscspn wcscspn
#وصف_ڪريو _tcslen wcslen
#وصف_ڪريو _tcsnlen wcsnlen
#وصف_ڪريو _tcsncat wcsncat
#وصف_ڪريو _tcsncat_l _wcsncat_l
#وصف_ڪريو _tcsncpy wcsncpy
#وصف_ڪريو _tcsncpy_l _wcsncpy_l
#وصف_ڪريو _tcspbrk wcspbrk
#وصف_ڪريو _tcsrchr wcsrchr
#وصف_ڪريو _tcsspn wcsspn
#وصف_ڪريو _tcsstr wcsstr
#وصف_ڪريو _tcstok wcstok
#وصف_ڪريو _tcstok_l _wcstok_l
#وصف_ڪريو _tcserror _wcserror
#وصف_ڪريو __tcserror __wcserror

#وصف_ڪريو _tcsdup _wcsdup
#وصف_ڪريو _tcsnset _wcsnset
#وصف_ڪريو _tcsnset_l _wcsnset_l
#وصف_ڪريو _tcsrev _wcsrev
#وصف_ڪريو _tcsset _wcsset
#وصف_ڪريو _tcsset_l _wcsset_l

#وصف_ڪريو _tcscmp wcscmp
#وصف_ڪريو _tcsicmp _wcsicmp
#وصف_ڪريو _tcsicmp_l _wcsicmp_l
#وصف_ڪريو _tcsnccmp wcsncmp
#وصف_ڪريو _tcsncmp wcsncmp
#وصف_ڪريو _tcsncicmp _wcsnicmp
#وصف_ڪريو _tcsncicmp_l _wcsnicmp_l
#وصف_ڪريو _tcsnicmp _wcsnicmp
#وصف_ڪريو _tcsnicmp_l _wcsnicmp_l

#وصف_ڪريو _tcscoll wcscoll
#وصف_ڪريو _tcscoll_l _wcscoll_l
#وصف_ڪريو _tcsicoll _wcsicoll
#وصف_ڪريو _tcsicoll_l _wcsicoll_l
#وصف_ڪريو _tcsnccoll _wcsncoll
#وصف_ڪريو _tcsnccoll_l _wcsncoll_l
#وصف_ڪريو _tcsncoll _wcsncoll
#وصف_ڪريو _tcsncoll_l _wcsncoll_l
#وصف_ڪريو _tcsncicoll _wcsnicoll
#وصف_ڪريو _tcsncicoll_l _wcsnicoll_l
#وصف_ڪريو _tcsnicoll _wcsnicoll
#وصف_ڪريو _tcsnicoll_l _wcsnicoll_l

#وصف_ڪريو _texecl _wexecl
#وصف_ڪريو _texecle _wexecle
#وصف_ڪريو _texeclp _wexeclp
#وصف_ڪريو _texeclpe _wexeclpe
#وصف_ڪريو _texecv _wexecv
#وصف_ڪريو _texecve _wexecve
#وصف_ڪريو _texecvp _wexecvp
#وصف_ڪريو _texecvpe _wexecvpe

#وصف_ڪريو _tspawnl _wspawnl
#وصف_ڪريو _tspawnle _wspawnle
#وصف_ڪريو _tspawnlp _wspawnlp
#وصف_ڪريو _tspawnlpe _wspawnlpe
#وصف_ڪريو _tspawnv _wspawnv
#وصف_ڪريو _tspawnve _wspawnve
#وصف_ڪريو _tspawnvp _wspawnvp
#وصف_ڪريو _tspawnvp _wspawnvp
#وصف_ڪريو _tspawnvpe _wspawnvpe

#وصف_ڪريو _tsystem _wsystem

#وصف_ڪريو _tasctime _wasctime
#وصف_ڪريو _tctime _wctime
#وصف_ڪريو _tctime32 _wctime32
#وصف_ڪريو _tctime64 _wctime64
#وصف_ڪريو _tstrdate _wstrdate
#وصف_ڪريو _tstrtime _wstrtime
#وصف_ڪريو _tutime _wutime
#وصف_ڪريو _tutime32 _wutime32
#وصف_ڪريو _tutime64 _wutime64
#وصف_ڪريو _tcsftime wcsftime
#وصف_ڪريو _tcsftime_l _wcsftime_l

#وصف_ڪريو _tchdir _wchdir
#وصف_ڪريو _tgetcwd _wgetcwd
#وصف_ڪريو _tgetdcwd _wgetdcwd
#وصف_ڪريو _tgetdcwd_nolock _wgetdcwd_nolock
#وصف_ڪريو _tmkdir _wmkdir
#وصف_ڪريو _trmdir _wrmdir

#وصف_ڪريو _tfullpath _wfullpath
#وصف_ڪريو _tgetenv _wgetenv
#وصف_ڪريو _tmakepath _wmakepath
#وصف_ڪريو _tpgmptr _wpgmptr
#وصف_ڪريو _get_tpgmptr _get_wpgmptr
#وصف_ڪريو _tputenv _wputenv
#وصف_ڪريو _tsearchenv _wsearchenv
#وصف_ڪريو _tsplitpath _wsplitpath

#وصف_ڪريو _tfdopen _wfdopen
#وصف_ڪريو _tfsopen _wfsopen
#وصف_ڪريو _tfopen _wfopen
#وصف_ڪريو _tfreopen _wfreopen
#وصف_ڪريو _tperror _wperror
#وصف_ڪريو _tpopen _wpopen
#وصف_ڪريو _ttempnam _wtempnam
#وصف_ڪريو _ttmpnam _wtmpnam

#وصف_ڪريو _taccess _waccess
#وصف_ڪريو _tchmod _wchmod
#وصف_ڪريو _tcreat _wcreat
#وصف_ڪريو _tfindfirst _wfindfirst
#وصف_ڪريو _tfindfirst32 _wfindfirst32
#وصف_ڪريو _tfindfirst64 _wfindfirst64
#وصف_ڪريو _tfindfirsti64 _wfindfirsti64
#وصف_ڪريو _tfindfirst32i64 _wfindfirst32i64
#وصف_ڪريو _tfindfirst64i32 _wfindfirst64i32
#وصف_ڪريو _tfindnext _wfindnext
#وصف_ڪريو _tfindnext32 _wfindnext32
#وصف_ڪريو _tfindnext64 _wfindnext64
#وصف_ڪريو _tfindnexti64 _wfindnexti64
#وصف_ڪريو _tfindnext32i64 _wfindnext32i64
#وصف_ڪريو _tfindnext64i32 _wfindnext64i32
#وصف_ڪريو _tmktemp _wmktemp
#وصف_ڪريو _topen _wopen
#وصف_ڪريو _tremove _wremove
#وصف_ڪريو _trename _wrename
#وصف_ڪريو _tsopen _wsopen
#وصف_ڪريو _tunlink _wunlink

#وصف_ڪريو _tfinddata_t _wfinddata_t
#وصف_ڪريو _tfinddata32_t _wfinddata32_t
#وصف_ڪريو _tfinddata64_t _wfinddata64_t
#وصف_ڪريو _tfinddatai64_t _wfinddatai64_t
#وصف_ڪريو _tfinddata32i64_t _wfinddata32i64_t
#وصف_ڪريو _tfinddata64i32_t _wfinddata64i32_t

#وصف_ڪريو _tstat _wstat
#وصف_ڪريو _tstat32 _wstat32
#وصف_ڪريو _tstat32i64 _wstat32i64
#وصف_ڪريو _tstat64 _wstat64
#وصف_ڪريو _tstat64i32 _wstat64i32
#وصف_ڪريو _tstati64 _wstati64

#وصف_ڪريو _tsetlocale _wsetlocale

#وصف_ڪريو _tcsclen wcslen
#وصف_ڪريو _tcscnlen wcsnlen
#وصف_ڪريو _tcsclen_l(_String,_Locale) wcslen(_String)
#وصف_ڪريو _tcscnlen_l(_String,Max_ڳڻپ_2,_Locale) wcsnlen_l((_String),(Max_ڳڻپ_2))
#وصف_ڪريو _tcsnccat wcsncat
#وصف_ڪريو _tcsnccat_l _wcsncat_l
#وصف_ڪريو _tcsnccpy wcsncpy
#وصف_ڪريو _tcsnccpy_l _wcsncpy_l
#وصف_ڪريو _tcsncset _wcsnset

#وصف_ڪريو _tcsdec _wcsdec
#وصف_ڪريو _tcsinc _wcsinc
#وصف_ڪريو _tcsnbcnt _wcsncnt
#وصف_ڪريو _tcsnccnt _wcsncnt
#وصف_ڪريو _tcsnextc _wcsnextc
#وصف_ڪريو _tcsninc _wcsninc
#وصف_ڪريو _tcsspnp _wcsspnp

#وصف_ڪريو _tcslwr _wcslwr
#وصف_ڪريو _tcslwr_l _wcslwr_l
#وصف_ڪريو _tcsupr _wcsupr
#وصف_ڪريو _tcsupr_l _wcsupr_l
#وصف_ڪريو _tcsxfrm wcsxfrm
#وصف_ڪريو _tcsxfrm_l _wcsxfrm_l

#وصف_ڪريو _tclen(_pc) (1)
#وصف_ڪريو _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#وصف_ڪريو _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#وصف_ڪريو _istalnum iswalnum
#وصف_ڪريو _istalnum_l _iswalnum_l
#وصف_ڪريو _istalpha iswalpha
#وصف_ڪريو _istalpha_l _iswalpha_l
#وصف_ڪريو _istascii iswascii
#وصف_ڪريو _istcntrl iswcntrl
#وصف_ڪريو _istcntrl_l _iswcntrl_l
#وصف_ڪريو _istdigit iswdigit
#وصف_ڪريو _istdigit_l _iswdigit_l
#وصف_ڪريو _istgraph iswgraph
#وصف_ڪريو _istgraph_l _iswgraph_l
#وصف_ڪريو _istlower iswlower
#وصف_ڪريو _istlower_l _iswlower_l
#وصف_ڪريو _istprint iswprint
#وصف_ڪريو _istprint_l _iswprint_l
#وصف_ڪريو _istpunct iswpunct
#وصف_ڪريو _istpunct_l _iswpunct_l
#وصف_ڪريو _istspace iswspace
#وصف_ڪريو _istspace_l _iswspace_l
#وصف_ڪريو _istupper iswupper
#وصف_ڪريو _istupper_l _iswupper_l
#وصف_ڪريو _istxdigit iswxdigit
#وصف_ڪريو _istxdigit_l _iswxdigit_l

#وصف_ڪريو _totupper towupper
#وصف_ڪريو _totupper_l _towupper_l
#وصف_ڪريو _totlower towlower
#وصف_ڪريو _totlower_l _towlower_l

#وصف_ڪريو _istlegal(_Char) (1)
#وصف_ڪريو _istlead(_Char) (0)
#وصف_ڪريو _istleadbyte(_Char) (0)
#وصف_ڪريو _istleadbyte_l(_Char,_Locale) (0)

#وصف_ڪريو _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? عدم : (_cpc2)-1)
#وصف_ڪريو _wcsinc(_pc) ((_pc)+1)
#وصف_ڪريو _wcsnextc(_cpc) ((بنانشان صحيح) *(_cpc))
#وصف_ڪريو _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP سائيز_t __cdecl __wcsncnt(ثابت wchar_t *_Str,سائيز_t Max_ڳڻپ);
#وصف_ڪريو _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#وصف_ڪريو _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? عدم : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : عدم))
#وصف_ڪريو _wcsncpy_l(_Destination,ذريعو_3,ڳڻپ_5,_Locale) (wcsncpy(_Destination,ذريعو_3,ڳڻپ_5))
#وصف_ڪريو _wcsncat_l(_Destination,ذريعو_3,ڳڻپ_5,_Locale) (wcsncat(_Destination,ذريعو_3,ڳڻپ_5))
#وصف_ڪريو _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#وصف_ڪريو _wcsnset_l(_Destination,قدر_2,ڳڻپ_5,_Locale) (_wcsnset(_Destination,قدر_2,ڳڻپ_5))
#وصف_ڪريو _wcsset_l(_Destination,قدر_2,_Locale) (_wcsset(_Destination,قدر_2))

  /* dirent structures and functions */
#وصف_ڪريو _tdirent	_wdirent
#وصف_ڪريو _TDIR 		_WDIR
#وصف_ڪريو _topendir	_wopendir
#وصف_ڪريو _tclosedir	_wclosedir
#وصف_ڪريو _treaddir	_wreaddir
#وصف_ڪريو _trewinddir	_wrewinddir
#وصف_ڪريو _ttelldir	_wtelldir
#وصف_ڪريو _tseekdir	_wseekdir

#وإلا

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#ضمن <string.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#وصف_ڪريو _TEOF EOF

#وصف_ڪريو __T(x) x

#وصف_ڪريو _tmain مکيه
#وصف_ڪريو _tWinMain WinMain
#جيڪڏهن_وصف_ٿيل _POSIX_
#وصف_ڪريو _tenviron environ
#وإلا
#وصف_ڪريو _tenviron _environ
#جيڪڏهن_پورو
#وصف_ڪريو __targv __argv

#وصف_ڪريو _tprintf لکو
#وصف_ڪريو _tprintf_l _printf_l
#وصف_ڪريو _tprintf_p _printf_p
#وصف_ڪريو _tprintf_p_l _printf_p_l
#وصف_ڪريو _tcprintf _cprintf
#وصف_ڪريو _tcprintf_l _cprintf_l
#وصف_ڪريو _tcprintf_p _cprintf_p
#وصف_ڪريو _tcprintf_p_l _cprintf_p_l
#وصف_ڪريو _vtcprintf _vcprintf
#وصف_ڪريو _vtcprintf_l _vcprintf_l
#وصف_ڪريو _vtcprintf_p _vcprintf_p
#وصف_ڪريو _vtcprintf_p_l _vcprintf_p_l
#وصف_ڪريو _ftprintf fprintf
#وصف_ڪريو _ftprintf_l _fprintf_l
#وصف_ڪريو _ftprintf_p _fprintf_p
#وصف_ڪريو _ftprintf_p_l _fprintf_p_l
#وصف_ڪريو _stprintf sprintf
#وصف_ڪريو _stprintf_l _sprintf_l
#وصف_ڪريو _stprintf_p _sprintf_p
#وصف_ڪريو _stprintf_p_l _sprintf_p_l
#وصف_ڪريو _sctprintf _scprintf
#وصف_ڪريو _sctprintf_l _scprintf_l
#وصف_ڪريو _sctprintf_p _scprintf_p
#وصف_ڪريو _sctprintf_p_l _scprintf_p_l
#وصف_ڪريو _sntprintf _snprintf
#وصف_ڪريو _sntprintf_l _snprintf_l
#وصف_ڪريو _vtprintf vprintf
#وصف_ڪريو _vtprintf_l _vprintf_l
#وصف_ڪريو _vtprintf_p _vprintf_p
#وصف_ڪريو _vtprintf_p_l _vprintf_p_l
#وصف_ڪريو _vftprintf vfprintf
#وصف_ڪريو _vftprintf_l _vfprintf_l
#وصف_ڪريو _vftprintf_p _vfprintf_p
#وصف_ڪريو _vftprintf_p_l _vfprintf_p_l
#وصف_ڪريو _vstprintf vsprintf
#وصف_ڪريو _vstprintf_l _vsprintf_l
#وصف_ڪريو _vstprintf_p _vsprintf_p
#وصف_ڪريو _vstprintf_p_l _vsprintf_p_l
#وصف_ڪريو _vsctprintf _vscprintf
#وصف_ڪريو _vsctprintf_l _vscprintf_l
#وصف_ڪريو _vsctprintf_p _vscprintf_p
#وصف_ڪريو _vsctprintf_p_l _vscprintf_p_l
#وصف_ڪريو _vsntprintf _vsnprintf
#وصف_ڪريو _vsntprintf_l _vsnprintf_l

#وصف_ڪريو _tscanf scanf
#وصف_ڪريو _tscanf_l _scanf_l
#وصف_ڪريو _tcscanf _cscanf
#وصف_ڪريو _tcscanf_l _cscanf_l
#وصف_ڪريو _ftscanf fscanf
#وصف_ڪريو _ftscanf_l _fscanf_l
#وصف_ڪريو _stscanf لڙي_مان_پڙهو
#وصف_ڪريو _stscanf_l _sscanf_l
#وصف_ڪريو _sntscanf _snscanf
#وصف_ڪريو _sntscanf_l _snscanf_l

#وصف_ڪريو _fgettc fgetc
#وصف_ڪريو _fgettc_nolock _fgetc_nolock
#وصف_ڪريو _fgettchar _fgetchar
#وصف_ڪريو _fgetts fgets
#وصف_ڪريو _fputtc fputc
#وصف_ڪريو _fputtc_nolock _fputc_nolock
#وصف_ڪريو _fputtchar _fputchar
#وصف_ڪريو _fputts fputs
#وصف_ڪريو _cputts _cputs
#وصف_ڪريو _gettc getc
#وصف_ڪريو _gettc_nolock _getc_nolock
#وصف_ڪريو _gettch _getch
#وصف_ڪريو _gettch_nolock _getch_nolock
#وصف_ڪريو _gettche _getche
#وصف_ڪريو _gettche_nolock _getche_nolock
#وصف_ڪريو _gettchar getchar
#وصف_ڪريو _gettchar_nolock _getchar_nolock
#وصف_ڪريو _getts gets
#وصف_ڪريو _cgetts _cgets
#وصف_ڪريو _puttc putc
#وصف_ڪريو _puttc_nolock _putc_nolock
#وصف_ڪريو _puttchar اکر_لکو
#وصف_ڪريو _puttchar_nolock _putchar_nolock
#وصف_ڪريو _puttch _putch
#وصف_ڪريو _puttch_nolock _putch_nolock
#وصف_ڪريو _putts puts
#وصف_ڪريو _ungettc ungetc
#وصف_ڪريو _ungettc_nolock _ungetc_nolock
#وصف_ڪريو _ungettch _ungetch
#وصف_ڪريو _ungettch_nolock _ungetch_nolock

#وصف_ڪريو _tcstod strtod
#وصف_ڪريو _tcstol strtol
#وصف_ڪريو _tcstoul strtoul
#وصف_ڪريو _tstof atof
#وصف_ڪريو _tstol atol
#وصف_ڪريو _tstoi atoi
#وصف_ڪريو _tstoi64 _atoi64
#وصف_ڪريو _tcstod_l _strtod_l
#وصف_ڪريو _tcstol_l _strtol_l
#وصف_ڪريو _tcstoul_l _strtoul_l
#وصف_ڪريو _tstof_l _atof_l
#وصف_ڪريو _tstol_l _atol_l
#وصف_ڪريو _tstoi_l _atoi_l
#وصف_ڪريو _tstoi64_l _atoi64_l

#وصف_ڪريو _itot _itoa
#وصف_ڪريو _ltot _ltoa
#وصف_ڪريو _ultot _ultoa
#وصف_ڪريو _ttoi atoi
#وصف_ڪريو _ttol atol

#وصف_ڪريو _ttoi64 _atoi64
#وصف_ڪريو _tcstoi64 _strtoi64
#وصف_ڪريو _tcstoi64_l _strtoi64_l
#وصف_ڪريو _tcstoui64 _strtoui64
#وصف_ڪريو _tcstoui64_l _strtoui64_l
#وصف_ڪريو _i64tot _i64toa
#وصف_ڪريو _ui64tot _ui64toa

#وصف_ڪريو _tcscat strcat
#وصف_ڪريو _tcscpy strcpy
#وصف_ڪريو _tcsdup _strdup
#وصف_ڪريو _tcslen لڙي_ڊيگهه
#إذا 0
#وصف_ڪريو _tcsnlen strnlen
#جيڪڏهن_پورو
#وصف_ڪريو _tcsxfrm strxfrm
#وصف_ڪريو _tcsxfrm_l _strxfrm_l
#وصف_ڪريو _tcserror strerror
#وصف_ڪريو __tcserror _strerror

#وصف_ڪريو _texecl _execl
#وصف_ڪريو _texecle _execle
#وصف_ڪريو _texeclp _execlp
#وصف_ڪريو _texeclpe _execlpe
#وصف_ڪريو _texecv _execv
#وصف_ڪريو _texecve _execve
#وصف_ڪريو _texecvp _execvp
#وصف_ڪريو _texecvpe _execvpe

#وصف_ڪريو _tspawnl _spawnl
#وصف_ڪريو _tspawnle _spawnle
#وصف_ڪريو _tspawnlp _spawnlp
#وصف_ڪريو _tspawnlpe _spawnlpe
#وصف_ڪريو _tspawnv _spawnv
#وصف_ڪريو _tspawnve _spawnve
#وصف_ڪريو _tspawnvp _spawnvp
#وصف_ڪريو _tspawnvpe _spawnvpe

#وصف_ڪريو _tsystem system

#وصف_ڪريو _tasctime asctime
#وصف_ڪريو _tctime ctime
#وصف_ڪريو _tctime32 _ctime32
#وصف_ڪريو _tctime64 _ctime64
#وصف_ڪريو _tstrdate _strdate
#وصف_ڪريو _tstrtime _strtime
#وصف_ڪريو _tutime _utime
#وصف_ڪريو _tutime32 _utime32
#وصف_ڪريو _tutime64 _utime64
#وصف_ڪريو _tcsftime strftime
#وصف_ڪريو _tcsftime_l _strftime_l

#وصف_ڪريو _tchdir _chdir
#وصف_ڪريو _tgetcwd _getcwd
#وصف_ڪريو _tgetdcwd _getdcwd
#وصف_ڪريو _tgetdcwd_nolock _getdcwd_nolock
#وصف_ڪريو _tmkdir _mkdir
#وصف_ڪريو _trmdir _rmdir

#وصف_ڪريو _tfullpath _fullpath
#وصف_ڪريو _tgetenv getenv
#وصف_ڪريو _tmakepath _makepath
#وصف_ڪريو _tpgmptr _pgmptr
#وصف_ڪريو _get_tpgmptr _get_pgmptr
#وصف_ڪريو _tputenv _putenv
#وصف_ڪريو _tsearchenv _searchenv
#وصف_ڪريو _tsplitpath _splitpath

#جيڪڏهن_وصف_ٿيل _POSIX_
#وصف_ڪريو _tfdopen fdopen
#وإلا
#وصف_ڪريو _tfdopen _fdopen
#جيڪڏهن_پورو
#وصف_ڪريو _tfsopen _fsopen
#وصف_ڪريو _tfopen fopen
#وصف_ڪريو _tfreopen freopen
#وصف_ڪريو _tperror perror
#وصف_ڪريو _tpopen _popen
#وصف_ڪريو _ttempnam _tempnam
#وصف_ڪريو _ttmpnam tmpnam

#وصف_ڪريو _tchmod _chmod
#وصف_ڪريو _tcreat _creat
#وصف_ڪريو _tfindfirst _findfirst
#وصف_ڪريو _tfindfirst32 _findfirst32
#وصف_ڪريو _tfindfirst64 _findfirst64
#وصف_ڪريو _tfindfirsti64 _findfirsti64
#وصف_ڪريو _tfindfirst32i64 _findfirst32i64
#وصف_ڪريو _tfindfirst64i32 _findfirst64i32
#وصف_ڪريو _tfindnext _findnext
#وصف_ڪريو _tfindnext32 _findnext32
#وصف_ڪريو _tfindnext64 _findnext64
#وصف_ڪريو _tfindnexti64 _findnexti64
#وصف_ڪريو _tfindnext32i64 _findnext32i64
#وصف_ڪريو _tfindnext64i32 _findnext64i32
#وصف_ڪريو _tmktemp _mktemp

#جيڪڏهن_وصف_ٿيل _POSIX_
#وصف_ڪريو _topen open
#وصف_ڪريو _taccess access
#وإلا
#وصف_ڪريو _topen _open
#وصف_ڪريو _taccess _access
#جيڪڏهن_پورو

#وصف_ڪريو _tremove remove
#وصف_ڪريو _trename rename
#وصف_ڪريو _tsopen _sopen
#وصف_ڪريو _tunlink _unlink

#وصف_ڪريو _tfinddata_t _finddata_t
#وصف_ڪريو _tfinddata32_t _finddata32_t
#وصف_ڪريو _tfinddata64_t __finddata64_t
#وصف_ڪريو _tfinddatai64_t _finddatai64_t
#وصف_ڪريو _tfinddata32i64_t _finddata32i64_t
#وصف_ڪريو _tfinddata64i32_t _finddata64i32_t

#وصف_ڪريو _istascii __isascii
#وصف_ڪريو _istcntrl iscntrl
#وصف_ڪريو _istcntrl_l _iscntrl_l
#وصف_ڪريو _istxdigit isxdigit
#وصف_ڪريو _istxdigit_l _isxdigit_l

#وصف_ڪريو _tstat _stat
#وصف_ڪريو _tstat32 _stat32
#وصف_ڪريو _tstat32i64 _stat32i64
#وصف_ڪريو _tstat64 _stat64
#وصف_ڪريو _tstat64i32 _stat64i32
#وصف_ڪريو _tstati64 _stati64

#وصف_ڪريو _tsetlocale setlocale

#جيڪڏهن_وصف_ٿيل _MBCS

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#ضمن <mbstring.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __TCHAR_DEFINED
  تعريفنوع حرف _TCHAR;
  تعريفنوع نشانوارو حرف _TSCHAR;
  تعريفنوع بنانشان حرف _TUCHAR;
  تعريفنوع بنانشان حرف _TXCHAR;
  تعريفنوع بنانشان صحيح _TINT;
#وصف_ڪريو __TCHAR_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TCHAR_DEFINED
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  تعريفنوع حرف TCHAR;
#جيڪڏهن_پورو
#وصف_ڪريو _TCHAR_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل MB_MAP_سڌو

#وصف_ڪريو _tcschr _mbschr
#وصف_ڪريو _tcscspn _mbscspn
#وصف_ڪريو _tcsncat _mbsnbcat
#وصف_ڪريو _tcsncat_l _mbsnbcat_l
#وصف_ڪريو _tcsncpy _mbsnbcpy
#وصف_ڪريو _tcsncpy_l _mbsnbcpy_l
#وصف_ڪريو _tcspbrk _mbspbrk
#وصف_ڪريو _tcsrchr _mbsrchr
#وصف_ڪريو _tcsspn _mbsspn
#وصف_ڪريو _tcsstr _mbsstr
#وصف_ڪريو _tcstok _mbstok
#وصف_ڪريو _tcstok_l _mbstok_l

#وصف_ڪريو _tcsnset _mbsnbset
#وصف_ڪريو _tcsnset_l _mbsnbset_l
#وصف_ڪريو _tcsrev _mbsrev
#وصف_ڪريو _tcsset _mbsset
#وصف_ڪريو _tcsset_l _mbsset_l

#وصف_ڪريو _tcscmp _mbscmp
#وصف_ڪريو _tcsicmp _mbsicmp
#وصف_ڪريو _tcsicmp_l _mbsicmp_l
#وصف_ڪريو _tcsnccmp _mbsncmp
#وصف_ڪريو _tcsncmp _mbsnbcmp
#وصف_ڪريو _tcsncicmp _mbsnicmp
#وصف_ڪريو _tcsncicmp_l _mbsnicmp_l
#وصف_ڪريو _tcsnicmp _mbsnbicmp
#وصف_ڪريو _tcsnicmp_l _mbsnbicmp_l

#وصف_ڪريو _tcscoll _mbscoll
#وصف_ڪريو _tcscoll_l _mbscoll_l
#وصف_ڪريو _tcsicoll _mbsicoll
#وصف_ڪريو _tcsicoll_l _mbsicoll_l
#وصف_ڪريو _tcsnccoll _mbsncoll
#وصف_ڪريو _tcsnccoll_l _mbsncoll_l
#وصف_ڪريو _tcsncoll _mbsnbcoll
#وصف_ڪريو _tcsncoll_l _mbsnbcoll_l
#وصف_ڪريو _tcsncicoll _mbsnicoll
#وصف_ڪريو _tcsncicoll_l _mbsnicoll_l
#وصف_ڪريو _tcsnicoll _mbsnbicoll
#وصف_ڪريو _tcsnicoll_l _mbsnbicoll_l

#وصف_ڪريو _tcsclen _mbslen
#وصف_ڪريو _tcscnlen _mbsnlen
#وصف_ڪريو _tcsclen_l _mbslen_l
#وصف_ڪريو _tcscnlen_l _mbsnlen_l
#وصف_ڪريو _tcsnccat _mbsncat
#وصف_ڪريو _tcsnccat_l _mbsncat_l
#وصف_ڪريو _tcsnccpy _mbsncpy
#وصف_ڪريو _tcsnccpy_l _mbsncpy_l
#وصف_ڪريو _tcsncset _mbsnset
#وصف_ڪريو _tcsncset_l _mbsnset_l

#وصف_ڪريو _tcsdec _mbsdec
#وصف_ڪريو _tcsinc _mbsinc
#وصف_ڪريو _tcsnbcnt _mbsnbcnt
#وصف_ڪريو _tcsnccnt _mbsnccnt
#وصف_ڪريو _tcsnextc _mbsnextc
#وصف_ڪريو _tcsninc _mbsninc
#وصف_ڪريو _tcsspnp _mbsspnp

#وصف_ڪريو _tcslwr _mbslwr
#وصف_ڪريو _tcslwr_l _mbslwr_l
#وصف_ڪريو _tcsupr _mbsupr
#وصف_ڪريو _tcsupr_l _mbsupr_l

#وصف_ڪريو _tclen _mbclen
#وصف_ڪريو _tccpy _mbccpy
#وصف_ڪريو _tccpy_l _mbccpy_l
#وإلا

  _CRTIMP _CONST_RETURN حرف *__cdecl _tcschr(ثابت حرف *_Str,بنانشان صحيح _Val);
  _CRTIMP سائيز_t __cdecl _tcscspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP حرف *__cdecl _tcsncat(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP حرف *__cdecl _tcsncat_l(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncpy(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP حرف *__cdecl _tcsncpy_l(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcspbrk(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsrchr(ثابت حرف *_Str,بنانشان صحيح _Ch);
  _CRTIMP سائيز_t __cdecl _tcsspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsstr(ثابت حرف *_Str,ثابت حرف *_Substr);
  _CRTIMP حرف *__cdecl _tcstok(حرف *_Str,ثابت حرف *_Delim);
  _CRTIMP حرف *__cdecl _tcstok_l(حرف *_Str,ثابت حرف *_Delim,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnset(حرف *_Str,بنانشان صحيح _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP حرف *__cdecl _tcsrev(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsset(حرف *_Str,بنانشان صحيح _Val);
  _CRTIMP حرف *__cdecl _tcsset_l(حرف *_Str,بنانشان صحيح _Val,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcscmp(ثابت حرف *_Str1,ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _tcsicmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcsicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnccmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsncmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsncicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsncicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsnicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcscoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcscoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsicoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcsicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnccoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsnccoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsncoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsncoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsncicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsncicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _tcsnicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP سائيز_t __cdecl _tcsclen(ثابت حرف *_Str);
  _CRTIMP سائيز_t __cdecl _tcscnlen(ثابت حرف *_Str,سائيز_t Max_ڳڻپ);
  _CRTIMP سائيز_t __cdecl _tcsclen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP سائيز_t __cdecl _tcscnlen_l(ثابت حرف *_Str,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccat(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP حرف *__cdecl _tcsnccat_l(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccpy(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP حرف *__cdecl _tcsnccpy_l(حرف *_Dst,ثابت حرف *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncset(حرف *_Str,بنانشان صحيح _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP حرف *__cdecl _tcsdec(ثابت حرف *شروعات_4,ثابت حرف *_Pos);
  _CRTIMP حرف *__cdecl _tcsinc(ثابت حرف *_Ptr);
  _CRTIMP سائيز_t __cdecl _tcsnbcnt(ثابت حرف *_Str,سائيز_t Max_ڳڻپ);
  _CRTIMP سائيز_t __cdecl _tcsnccnt(ثابت حرف *_Str,سائيز_t Max_ڳڻپ);
  _CRTIMP بنانشان صحيح __cdecl _tcsnextc (ثابت حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsninc(ثابت حرف *_Ptr,سائيز_t ڳڻپ_5);
  _CRTIMP حرف *__cdecl _tcsspnp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP حرف *__cdecl _tcslwr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcslwr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsupr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsupr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP سائيز_t __cdecl _tclen(ثابت حرف *_Str);
  _CRTIMP فراغ __cdecl _tccpy(حرف *_DstCh,ثابت حرف *_SrcCh);

#جيڪڏهن_وصف_ٿيل __cplusplus
#جيڪڏهن_وصف_نه_ٿيل _CPP_TCHAR_INLINES_DEFINED
#وصف_ڪريو _CPP_TCHAR_INLINES_DEFINED
  خارجي "C++" {
    خارجي مضمن حرف *__cdecl _tcschr(حرف *_S,بنانشان صحيح _C) { أرجع ((حرف *)_tcschr((ثابت حرف *)_S,_C)); }
    خارجي مضمن حرف *__cdecl _tcspbrk(حرف *_S,ثابت حرف *_P) { أرجع ((حرف *)_tcspbrk((ثابت حرف *)_S,_P)); }
    خارجي مضمن حرف *__cdecl _tcsrchr(حرف *_S,بنانشان صحيح _C) { أرجع ((حرف *)_tcsrchr((ثابت حرف *)_S,_C)); }
    خارجي مضمن حرف *__cdecl _tcsstr(حرف *_S,ثابت حرف *_P) { أرجع ((حرف *)_tcsstr((ثابت حرف *)_S,_P)); }
  }
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#وصف_ڪريو _istalnum _ismbcalnum
#وصف_ڪريو _istalnum_l _ismbcalnum_l
#وصف_ڪريو _istalpha _ismbcalpha
#وصف_ڪريو _istalpha_l _ismbcalpha_l
#وصف_ڪريو _istdigit _ismbcdigit
#وصف_ڪريو _istdigit_l _ismbcdigit_l
#وصف_ڪريو _istgraph _ismbcgraph
#وصف_ڪريو _istgraph_l _ismbcgraph_l
#وصف_ڪريو _istlegal _ismbclegal
#وصف_ڪريو _istlegal_l _ismbclegal_l
#وصف_ڪريو _istlower _ismbclower
#وصف_ڪريو _istlower_l _ismbclower_l
#وصف_ڪريو _istprint _ismbcprint
#وصف_ڪريو _istprint_l _ismbcprint_l
#وصف_ڪريو _istpunct _ismbcpunct
#وصف_ڪريو _istpunct_l _ismbcpunct_l
#وصف_ڪريو _istspace _ismbcspace
#وصف_ڪريو _istspace_l _ismbcspace_l
#وصف_ڪريو _istupper _ismbcupper
#وصف_ڪريو _istupper_l _ismbcupper_l

#وصف_ڪريو _totupper _mbctoupper
#وصف_ڪريو _totupper_l _mbctoupper_l
#وصف_ڪريو _totlower _mbctolower
#وصف_ڪريو _totlower_l _mbctolower_l

#وصف_ڪريو _istlead _ismbblead
#وصف_ڪريو _istleadbyte isleadbyte
#وصف_ڪريو _istleadbyte_l _isleadbyte_l
#وإلا

#جيڪڏهن_وصف_نه_ٿيل __TCHAR_DEFINED
#وصف_ڪريو __TCHAR_DEFINED
  تعريفنوع حرف _TCHAR;
  تعريفنوع نشانوارو حرف _TSCHAR;
  تعريفنوع بنانشان حرف _TUCHAR;
  تعريفنوع حرف _TXCHAR;
  تعريفنوع صحيح _TINT;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TCHAR_DEFINED
#وصف_ڪريو _TCHAR_DEFINED
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  تعريفنوع حرف TCHAR;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _tcschr strchr
#وصف_ڪريو _tcscspn strcspn
#وصف_ڪريو _tcsncat strncat
#وصف_ڪريو _tcsncat_l _strncat_l
#وصف_ڪريو _tcsncpy strncpy
#وصف_ڪريو _tcsncpy_l _strncpy_l
#وصف_ڪريو _tcspbrk strpbrk
#وصف_ڪريو _tcsrchr strrchr
#وصف_ڪريو _tcsspn strspn
#وصف_ڪريو _tcsstr لڙي_ڳولا
#وصف_ڪريو _tcstok strtok
#وصف_ڪريو _tcstok_l _strtok_l

#وصف_ڪريو _tcsnset _strnset
#وصف_ڪريو _tcsnset_l _strnset_l
#وصف_ڪريو _tcsrev _strrev
#وصف_ڪريو _tcsset _strset

#وصف_ڪريو _tcscmp strcmp
#وصف_ڪريو _tcsicmp _stricmp
#وصف_ڪريو _tcsicmp_l _stricmp_l
#وصف_ڪريو _tcsnccmp لڙي_ڀيٽ
#وصف_ڪريو _tcsncmp لڙي_ڀيٽ
#وصف_ڪريو _tcsncicmp _strnicmp
#وصف_ڪريو _tcsncicmp_l _strnicmp_l
#وصف_ڪريو _tcsnicmp _strnicmp
#وصف_ڪريو _tcsnicmp_l _strnicmp_l

#وصف_ڪريو _tcscoll strcoll
#وصف_ڪريو _tcscoll_l _strcoll_l
#وصف_ڪريو _tcsicoll _stricoll
#وصف_ڪريو _tcsicoll_l _stricoll_l
#وصف_ڪريو _tcsnccoll _strncoll
#وصف_ڪريو _tcsnccoll_l _strncoll_l
#وصف_ڪريو _tcsncoll _strncoll
#وصف_ڪريو _tcsncoll_l _strncoll_l
#وصف_ڪريو _tcsncicoll _strnicoll
#وصف_ڪريو _tcsncicoll_l _strnicoll_l
#وصف_ڪريو _tcsnicoll _strnicoll
#وصف_ڪريو _tcsnicoll_l _strnicoll_l

#وصف_ڪريو _tcsclen لڙي_ڊيگهه
#وصف_ڪريو _tcscnlen strnlen
#وصف_ڪريو _tcsclen_l(_String,_Locale) لڙي_ڊيگهه(_String)
#وصف_ڪريو _tcscnlen_l(_String,Max_ڳڻپ_2,_Locale) strnlen_l((_String),(Max_ڳڻپ_2))
#وصف_ڪريو _tcsnccat strncat
#وصف_ڪريو _tcsnccat_l _strncat_l
#وصف_ڪريو _tcsnccpy strncpy
#وصف_ڪريو _tcsnccpy_l _strncpy_l
#وصف_ڪريو _tcsncset _strnset

#وصف_ڪريو _tcsdec _strdec
#وصف_ڪريو _tcsinc _strinc
#وصف_ڪريو _tcsnbcnt _strncnt
#وصف_ڪريو _tcsnccnt _strncnt
#وصف_ڪريو _tcsnextc _strnextc
#وصف_ڪريو _tcsninc _strninc
#وصف_ڪريو _tcsspnp _strspnp

#وصف_ڪريو _tcslwr _strlwr
#وصف_ڪريو _tcslwr_l _strlwr_l
#وصف_ڪريو _tcsupr _strupr
#وصف_ڪريو _tcsupr_l _strupr_l
#وصف_ڪريو _tcsxfrm strxfrm
#وصف_ڪريو _tcsxfrm_l _strxfrm_l

#وصف_ڪريو _istlead(_Char) (0)
#وصف_ڪريو _istleadbyte(_Char) (0)
#وصف_ڪريو _istleadbyte_l(_Char,_Locale) (0)

#وصف_ڪريو _tclen(_pc) (1)
#وصف_ڪريو _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#وصف_ڪريو _tccmp(_cpc1,_cpc2) (((بنانشان حرف)*(_cpc1))-((بنانشان حرف)*(_cpc2)))

  /* dirent structures and functions */
#وصف_ڪريو _tdirent	dirent
#وصف_ڪريو _TDIR 		DIR
#وصف_ڪريو _topendir	opendir
#وصف_ڪريو _tclosedir	closedir
#وصف_ڪريو _treaddir	readdir
#وصف_ڪريو _trewinddir	rewinddir
#وصف_ڪريو _ttelldir	telldir
#وصف_ڪريو _tseekdir	seekdir

#وصف_ڪريو _istalnum اکر_يا_انگ
#وصف_ڪريو _istalnum_l _isalnum_l
#وصف_ڪريو _istalpha اکر_آهي
#وصف_ڪريو _istalpha_l _isalpha_l
#وصف_ڪريو _istdigit انگ_آهي
#وصف_ڪريو _istdigit_l _isdigit_l
#وصف_ڪريو _istgraph isgraph
#وصف_ڪريو _istgraph_l _isgraph_l
#وصف_ڪريو _istlower islower
#وصف_ڪريو _istlower_l _islower_l
#وصف_ڪريو _istprint isprint
#وصف_ڪريو _istprint_l _isprint_l
#وصف_ڪريو _istpunct ispunct
#وصف_ڪريو _istpunct_l _ispunct_l
#وصف_ڪريو _istspace خال_آهي
#وصف_ڪريو _istspace_l _isspace_l
#وصف_ڪريو _istupper isupper
#وصف_ڪريو _istupper_l _isupper_l

#وصف_ڪريو _totupper وڏو_اکر
#وصف_ڪريو _totupper_l _toupper_l
#وصف_ڪريو _totlower tolower
#وصف_ڪريو _totlower_l _tolower_l

#وصف_ڪريو _istlegal(_c) (1)

#جيڪڏهن_وصف_نه_ٿيل عدم
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو عدم 0
#وإلا
#وصف_ڪريو عدم ((فراغ *)0)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? عدم : (_cpc2)-1)
#وصف_ڪريو _strinc(_pc) ((_pc)+1)
#وصف_ڪريو _strnextc(_cpc) ((بنانشان صحيح) *(ثابت بنانشان حرف *)(_cpc))
#وصف_ڪريو _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP سائيز_t __cdecl __strncnt(ثابت حرف *_Str,سائيز_t _Cnt);
#وصف_ڪريو _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#وصف_ڪريو _strspnp(_cpc1,_cpc2) (!_cpc1 ? عدم : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : عدم))

#وصف_ڪريو _strncpy_l(_Destination,ذريعو_3,ڳڻپ_5,_Locale) (strncpy(_Destination,ذريعو_3,ڳڻپ_5))
#وصف_ڪريو _strncat_l(_Destination,ذريعو_3,ڳڻپ_5,_Locale) (strncat(_Destination,ذريعو_3,ڳڻپ_5))
#وصف_ڪريو _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#وصف_ڪريو _strnset_l(_Destination,قدر_2,ڳڻپ_5,_Locale) (_strnset(_Destination,قدر_2,ڳڻپ_5))
#وصف_ڪريو _strset_l(_Destination,قدر_2,_Locale) (_strset(_Destination,قدر_2))
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _T(x) __T(x)
#وصف_ڪريو متن_2(x) __T(x)

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#ضمن <sec_api/tchar_s.h>
#جيڪڏهن_پورو
