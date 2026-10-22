/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#که_نه_تعریف_شوی _INC_TCHAR
#تعریف_کړه _INC_TCHAR

#که_تعریف_شوی _STRSAFE_H_INCLUDED_
#تېروتنه Need منزل include strsafe.h after tchar.h
#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#تعریف_کړه _ftcscat _tcscat
#تعریف_کړه _ftcschr _tcschr
#تعریف_کړه _ftcscpy _tcscpy
#تعریف_کړه _ftcscspn _tcscspn
#تعریف_کړه _ftcslen _tcslen
#تعریف_کړه _ftcsncat _tcsncat
#تعریف_کړه _ftcsncpy _tcsncpy
#تعریف_کړه _ftcspbrk _tcspbrk
#تعریف_کړه _ftcsrchr _tcsrchr
#تعریف_کړه _ftcsspn _tcsspn
#تعریف_کړه _ftcsstr _tcsstr
#تعریف_کړه _ftcstok _tcstok

#تعریف_کړه _ftcsdup _tcsdup
#تعریف_کړه _ftcsnset _tcsnset
#تعریف_کړه _ftcsrev _tcsrev
#تعریف_کړه _ftcsset _tcsset

#تعریف_کړه _ftcscmp _tcscmp
#تعریف_کړه _ftcsicmp _tcsicmp
#تعریف_کړه _ftcsnccmp _tcsnccmp
#تعریف_کړه _ftcsncmp _tcsncmp
#تعریف_کړه _ftcsncicmp _tcsncicmp
#تعریف_کړه _ftcsnicmp _tcsnicmp

#تعریف_کړه _ftcscoll _tcscoll
#تعریف_کړه _ftcsicoll _tcsicoll
#تعریف_کړه _ftcsnccoll _tcsnccoll
#تعریف_کړه _ftcsncoll _tcsncoll
#تعریف_کړه _ftcsncicoll _tcsncicoll
#تعریف_کړه _ftcsnicoll _tcsnicoll

#تعریف_کړه _ftcsclen _tcsclen
#تعریف_کړه _ftcsnccat _tcsnccat
#تعریف_کړه _ftcsnccpy _tcsnccpy
#تعریف_کړه _ftcsncset _tcsncset

#تعریف_کړه _ftcsdec _tcsdec
#تعریف_کړه _ftcsinc _tcsinc
#تعریف_کړه _ftcsnbcnt _tcsnbcnt
#تعریف_کړه _ftcsnccnt _tcsnccnt
#تعریف_کړه _ftcsnextc _tcsnextc
#تعریف_کړه _ftcsninc _tcsninc
#تعریف_کړه _ftcsspnp _tcsspnp

#تعریف_کړه _ftcslwr _tcslwr
#تعریف_کړه _ftcsupr _tcsupr

#تعریف_کړه _ftclen _tclen
#تعریف_کړه _ftccpy _tccpy
#تعریف_کړه _ftccmp _tccmp

#که_نه_تعریف_شوی _CONST_RETURN
#که_تعریف_شوی __cplusplus
#تعریف_کړه _CONST_RETURN ثابت
#تعریف_کړه _CRT_CONST_CORRECT_OVERLOADS
#وإلا
#تعریف_کړه _CONST_RETURN
#د_که_پای
#د_که_پای

#تعریف_کړه _WConst_return _CONST_RETURN

#که_تعریف_شوی _UNICODE

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#ضمن <wchar.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _WCTYPE_T_DEFINED
#تعریف_کړه _WCTYPE_T_DEFINED
  تعريفنوع بینښه لنډ wint_t;
  تعريفنوع بینښه لنډ wctype_t;
#د_که_پای

#که_نه_تعریف_شوی __TCHAR_DEFINED
#تعریف_کړه __TCHAR_DEFINED
  تعريفنوع wchar_t _TCHAR;
  تعريفنوع wchar_t _TSCHAR;
  تعريفنوع wchar_t _TUCHAR;
  تعريفنوع wchar_t _TXCHAR;
  تعريفنوع wint_t _TINT;
#د_که_پای

#که_نه_تعریف_شوی _TCHAR_DEFINED
#تعریف_کړه _TCHAR_DEFINED
#که_نه_تعریف_شوی	NO_OLDNAMES
  تعريفنوع wchar_t TCHAR;
#د_که_پای
#د_که_پای

#تعریف_کړه _TEOF WEOF

#تعریف_کړه __T(x) L##x

#تعریف_کړه _tmain wmain
#تعریف_کړه _tWinMain wWinMain
#تعریف_کړه _tenviron _wenviron
#تعریف_کړه __targv __wargv

#تعریف_کړه _tprintf wprintf
#تعریف_کړه _tprintf_l _wprintf_l
#تعریف_کړه _tprintf_p _wprintf_p
#تعریف_کړه _tprintf_p_l _wprintf_p_l
#تعریف_کړه _tcprintf _cwprintf
#تعریف_کړه _tcprintf_l _cwprintf_l
#تعریف_کړه _tcprintf_p _cwprintf_p
#تعریف_کړه _tcprintf_p_l _cwprintf_p_l
#تعریف_کړه _vtcprintf _vcwprintf
#تعریف_کړه _vtcprintf_l _vcwprintf_l
#تعریف_کړه _vtcprintf_p _vcwprintf_p
#تعریف_کړه _vtcprintf_p_l _vcwprintf_p_l
#تعریف_کړه _ftprintf fwprintf
#تعریف_کړه _ftprintf_l _fwprintf_l
#تعریف_کړه _ftprintf_p _fwprintf_p
#تعریف_کړه _ftprintf_p_l _fwprintf_p_l
#تعریف_کړه _stprintf swprintf
#تعریف_کړه _stprintf_l __swprintf_l
#تعریف_کړه _stprintf_p _swprintf_p
#تعریف_کړه _stprintf_p_l _swprintf_p_l
#تعریف_کړه _sctprintf _scwprintf
#تعریف_کړه _sctprintf_l _scwprintf_l
#تعریف_کړه _sctprintf_p _scwprintf_p
#تعریف_کړه _sctprintf_p_l _scwprintf_p_l
#تعریف_کړه _sntprintf _snwprintf
#تعریف_کړه _sntprintf_l _snwprintf_l
#تعریف_کړه _vtprintf vwprintf
#تعریف_کړه _vtprintf_l _vwprintf_l
#تعریف_کړه _vtprintf_p _vwprintf_p
#تعریف_کړه _vtprintf_p_l _vwprintf_p_l
#تعریف_کړه _vftprintf vfwprintf
#تعریف_کړه _vftprintf_l _vfwprintf_l
#تعریف_کړه _vftprintf_p _vfwprintf_p
#تعریف_کړه _vftprintf_p_l _vfwprintf_p_l
#تعریف_کړه _vstprintf vswprintf
#تعریف_کړه _vstprintf_l _vswprintf_l
#تعریف_کړه _vstprintf_p _vswprintf_p
#تعریف_کړه _vstprintf_p_l _vswprintf_p_l
#تعریف_کړه _vsctprintf _vscwprintf
#تعریف_کړه _vsctprintf_l _vscwprintf_l
#تعریف_کړه _vsctprintf_p _vscwprintf_p
#تعریف_کړه _vsctprintf_p_l _vscwprintf_p_l
#تعریف_کړه _vsntprintf _vsnwprintf
#تعریف_کړه _vsntprintf_l _vsnwprintf_l

#تعریف_کړه _tscanf wscanf
#تعریف_کړه _tscanf_l _wscanf_l
#تعریف_کړه _tcscanf _cwscanf
#تعریف_کړه _tcscanf_l _cwscanf_l
#تعریف_کړه _ftscanf fwscanf
#تعریف_کړه _ftscanf_l _fwscanf_l
#تعریف_کړه _stscanf swscanf
#تعریف_کړه _stscanf_l _swscanf_l
#تعریف_کړه _sntscanf _snwscanf
#تعریف_کړه _sntscanf_l _snwscanf_l

#تعریف_کړه _fgettc fgetwc
#تعریف_کړه _fgettc_nolock _fgetwc_nolock
#تعریف_کړه _fgettchar _fgetwchar
#تعریف_کړه _fgetts fgetws
#تعریف_کړه _fputtc fputwc
#تعریف_کړه _fputtc_nolock _fputwc_nolock
#تعریف_کړه _fputtchar _fputwchar
#تعریف_کړه _fputts fputws
#تعریف_کړه _cputts _cputws
#تعریف_کړه _cgetts _cgetws
#تعریف_کړه _gettc getwc
#تعریف_کړه _gettc_nolock _getwc_nolock
#تعریف_کړه _gettch _getwch
#تعریف_کړه _gettch_nolock _getwch_nolock
#تعریف_کړه _gettche _getwche
#تعریف_کړه _gettche_nolock _getwche_nolock
#تعریف_کړه _gettchar getwchar
#تعریف_کړه _gettchar_nolock _getwchar_nolock
#تعریف_کړه _getts _getws
#تعریف_کړه _puttc putwc
#تعریف_کړه _puttc_nolock _putwc_nolock
#تعریف_کړه _puttchar putwchar
#تعریف_کړه _puttchar_nolock _putwchar_nolock
#تعریف_کړه _puttch _putwch
#تعریف_کړه _puttch_nolock _putwch_nolock
#تعریف_کړه _putts _putws
#تعریف_کړه _ungettc ungetwc
#تعریف_کړه _ungettc_nolock _ungetwc_nolock
#تعریف_کړه _ungettch _ungetwch
#تعریف_کړه _ungettch_nolock _ungetwch_nolock

#تعریف_کړه _tcstod wcstod
#تعریف_کړه _tcstol wcstol
#تعریف_کړه _tcstoul wcstoul
#تعریف_کړه _tcstoi64 _wcstoi64
#تعریف_کړه _tcstoui64 _wcstoui64
#تعریف_کړه _tstof _wtof
#تعریف_کړه _tstol _wtol
#تعریف_کړه _tstoi _wtoi
#تعریف_کړه _tstoi64 _wtoi64
#تعریف_کړه _tcstod_l _wcstod_l
#تعریف_کړه _tcstol_l _wcstol_l
#تعریف_کړه _tcstoul_l _wcstoul_l
#تعریف_کړه _tcstoi64_l _wcstoi64_l
#تعریف_کړه _tcstoui64_l _wcstoui64_l
#تعریف_کړه _tstof_l _wtof_l
#تعریف_کړه _tstol_l _wtol_l
#تعریف_کړه _tstoi_l _wtoi_l
#تعریف_کړه _tstoi64_l _wtoi64_l

#تعریف_کړه _itot _itow
#تعریف_کړه _ltot _ltow
#تعریف_کړه _ultot _ultow
#تعریف_کړه _ttoi _wtoi
#تعریف_کړه _ttol _wtol

#تعریف_کړه _ttoi64 _wtoi64
#تعریف_کړه _i64tot _i64tow
#تعریف_کړه _ui64tot _ui64tow

#تعریف_کړه _tcscat wcscat
#تعریف_کړه _tcschr wcschr
#تعریف_کړه _tcscpy wcscpy
#تعریف_کړه _tcscspn wcscspn
#تعریف_کړه _tcslen wcslen
#تعریف_کړه _tcsnlen wcsnlen
#تعریف_کړه _tcsncat wcsncat
#تعریف_کړه _tcsncat_l _wcsncat_l
#تعریف_کړه _tcsncpy wcsncpy
#تعریف_کړه _tcsncpy_l _wcsncpy_l
#تعریف_کړه _tcspbrk wcspbrk
#تعریف_کړه _tcsrchr wcsrchr
#تعریف_کړه _tcsspn wcsspn
#تعریف_کړه _tcsstr wcsstr
#تعریف_کړه _tcstok wcstok
#تعریف_کړه _tcstok_l _wcstok_l
#تعریف_کړه _tcserror _wcserror
#تعریف_کړه __tcserror __wcserror

#تعریف_کړه _tcsdup _wcsdup
#تعریف_کړه _tcsnset _wcsnset
#تعریف_کړه _tcsnset_l _wcsnset_l
#تعریف_کړه _tcsrev _wcsrev
#تعریف_کړه _tcsset _wcsset
#تعریف_کړه _tcsset_l _wcsset_l

#تعریف_کړه _tcscmp wcscmp
#تعریف_کړه _tcsicmp _wcsicmp
#تعریف_کړه _tcsicmp_l _wcsicmp_l
#تعریف_کړه _tcsnccmp wcsncmp
#تعریف_کړه _tcsncmp wcsncmp
#تعریف_کړه _tcsncicmp _wcsnicmp
#تعریف_کړه _tcsncicmp_l _wcsnicmp_l
#تعریف_کړه _tcsnicmp _wcsnicmp
#تعریف_کړه _tcsnicmp_l _wcsnicmp_l

#تعریف_کړه _tcscoll wcscoll
#تعریف_کړه _tcscoll_l _wcscoll_l
#تعریف_کړه _tcsicoll _wcsicoll
#تعریف_کړه _tcsicoll_l _wcsicoll_l
#تعریف_کړه _tcsnccoll _wcsncoll
#تعریف_کړه _tcsnccoll_l _wcsncoll_l
#تعریف_کړه _tcsncoll _wcsncoll
#تعریف_کړه _tcsncoll_l _wcsncoll_l
#تعریف_کړه _tcsncicoll _wcsnicoll
#تعریف_کړه _tcsncicoll_l _wcsnicoll_l
#تعریف_کړه _tcsnicoll _wcsnicoll
#تعریف_کړه _tcsnicoll_l _wcsnicoll_l

#تعریف_کړه _texecl _wexecl
#تعریف_کړه _texecle _wexecle
#تعریف_کړه _texeclp _wexeclp
#تعریف_کړه _texeclpe _wexeclpe
#تعریف_کړه _texecv _wexecv
#تعریف_کړه _texecve _wexecve
#تعریف_کړه _texecvp _wexecvp
#تعریف_کړه _texecvpe _wexecvpe

#تعریف_کړه _tspawnl _wspawnl
#تعریف_کړه _tspawnle _wspawnle
#تعریف_کړه _tspawnlp _wspawnlp
#تعریف_کړه _tspawnlpe _wspawnlpe
#تعریف_کړه _tspawnv _wspawnv
#تعریف_کړه _tspawnve _wspawnve
#تعریف_کړه _tspawnvp _wspawnvp
#تعریف_کړه _tspawnvp _wspawnvp
#تعریف_کړه _tspawnvpe _wspawnvpe

#تعریف_کړه _tsystem _wsystem

#تعریف_کړه _tasctime _wasctime
#تعریف_کړه _tctime _wctime
#تعریف_کړه _tctime32 _wctime32
#تعریف_کړه _tctime64 _wctime64
#تعریف_کړه _tstrdate _wstrdate
#تعریف_کړه _tstrtime _wstrtime
#تعریف_کړه _tutime _wutime
#تعریف_کړه _tutime32 _wutime32
#تعریف_کړه _tutime64 _wutime64
#تعریف_کړه _tcsftime wcsftime
#تعریف_کړه _tcsftime_l _wcsftime_l

#تعریف_کړه _tchdir _wchdir
#تعریف_کړه _tgetcwd _wgetcwd
#تعریف_کړه _tgetdcwd _wgetdcwd
#تعریف_کړه _tgetdcwd_nolock _wgetdcwd_nolock
#تعریف_کړه _tmkdir _wmkdir
#تعریف_کړه _trmdir _wrmdir

#تعریف_کړه _tfullpath _wfullpath
#تعریف_کړه _tgetenv _wgetenv
#تعریف_کړه _tmakepath _wmakepath
#تعریف_کړه _tpgmptr _wpgmptr
#تعریف_کړه _get_tpgmptr _get_wpgmptr
#تعریف_کړه _tputenv _wputenv
#تعریف_کړه _tsearchenv _wsearchenv
#تعریف_کړه _tsplitpath _wsplitpath

#تعریف_کړه _tfdopen _wfdopen
#تعریف_کړه _tfsopen _wfsopen
#تعریف_کړه _tfopen _wfopen
#تعریف_کړه _tfreopen _wfreopen
#تعریف_کړه _tperror _wperror
#تعریف_کړه _tpopen _wpopen
#تعریف_کړه _ttempnam _wtempnam
#تعریف_کړه _ttmpnam _wtmpnam

#تعریف_کړه _taccess _waccess
#تعریف_کړه _tchmod _wchmod
#تعریف_کړه _tcreat _wcreat
#تعریف_کړه _tfindfirst _wfindfirst
#تعریف_کړه _tfindfirst32 _wfindfirst32
#تعریف_کړه _tfindfirst64 _wfindfirst64
#تعریف_کړه _tfindfirsti64 _wfindfirsti64
#تعریف_کړه _tfindfirst32i64 _wfindfirst32i64
#تعریف_کړه _tfindfirst64i32 _wfindfirst64i32
#تعریف_کړه _tfindnext _wfindnext
#تعریف_کړه _tfindnext32 _wfindnext32
#تعریف_کړه _tfindnext64 _wfindnext64
#تعریف_کړه _tfindnexti64 _wfindnexti64
#تعریف_کړه _tfindnext32i64 _wfindnext32i64
#تعریف_کړه _tfindnext64i32 _wfindnext64i32
#تعریف_کړه _tmktemp _wmktemp
#تعریف_کړه _topen _wopen
#تعریف_کړه _tremove _wremove
#تعریف_کړه _trename _wrename
#تعریف_کړه _tsopen _wsopen
#تعریف_کړه _tunlink _wunlink

#تعریف_کړه _tfinddata_t _wfinddata_t
#تعریف_کړه _tfinddata32_t _wfinddata32_t
#تعریف_کړه _tfinddata64_t _wfinddata64_t
#تعریف_کړه _tfinddatai64_t _wfinddatai64_t
#تعریف_کړه _tfinddata32i64_t _wfinddata32i64_t
#تعریف_کړه _tfinddata64i32_t _wfinddata64i32_t

#تعریف_کړه _tstat _wstat
#تعریف_کړه _tstat32 _wstat32
#تعریف_کړه _tstat32i64 _wstat32i64
#تعریف_کړه _tstat64 _wstat64
#تعریف_کړه _tstat64i32 _wstat64i32
#تعریف_کړه _tstati64 _wstati64

#تعریف_کړه _tsetlocale _wsetlocale

#تعریف_کړه _tcsclen wcslen
#تعریف_کړه _tcscnlen wcsnlen
#تعریف_کړه _tcsclen_l(_String,_Locale) wcslen(_String)
#تعریف_کړه _tcscnlen_l(_String,Max_شمېر_2,_Locale) wcsnlen_l((_String),(Max_شمېر_2))
#تعریف_کړه _tcsnccat wcsncat
#تعریف_کړه _tcsnccat_l _wcsncat_l
#تعریف_کړه _tcsnccpy wcsncpy
#تعریف_کړه _tcsnccpy_l _wcsncpy_l
#تعریف_کړه _tcsncset _wcsnset

#تعریف_کړه _tcsdec _wcsdec
#تعریف_کړه _tcsinc _wcsinc
#تعریف_کړه _tcsnbcnt _wcsncnt
#تعریف_کړه _tcsnccnt _wcsncnt
#تعریف_کړه _tcsnextc _wcsnextc
#تعریف_کړه _tcsninc _wcsninc
#تعریف_کړه _tcsspnp _wcsspnp

#تعریف_کړه _tcslwr _wcslwr
#تعریف_کړه _tcslwr_l _wcslwr_l
#تعریف_کړه _tcsupr _wcsupr
#تعریف_کړه _tcsupr_l _wcsupr_l
#تعریف_کړه _tcsxfrm wcsxfrm
#تعریف_کړه _tcsxfrm_l _wcsxfrm_l

#تعریف_کړه _tclen(_pc) (1)
#تعریف_کړه _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#تعریف_کړه _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#تعریف_کړه _istalnum iswalnum
#تعریف_کړه _istalnum_l _iswalnum_l
#تعریف_کړه _istalpha iswalpha
#تعریف_کړه _istalpha_l _iswalpha_l
#تعریف_کړه _istascii iswascii
#تعریف_کړه _istcntrl iswcntrl
#تعریف_کړه _istcntrl_l _iswcntrl_l
#تعریف_کړه _istdigit iswdigit
#تعریف_کړه _istdigit_l _iswdigit_l
#تعریف_کړه _istgraph iswgraph
#تعریف_کړه _istgraph_l _iswgraph_l
#تعریف_کړه _istlower iswlower
#تعریف_کړه _istlower_l _iswlower_l
#تعریف_کړه _istprint iswprint
#تعریف_کړه _istprint_l _iswprint_l
#تعریف_کړه _istpunct iswpunct
#تعریف_کړه _istpunct_l _iswpunct_l
#تعریف_کړه _istspace iswspace
#تعریف_کړه _istspace_l _iswspace_l
#تعریف_کړه _istupper iswupper
#تعریف_کړه _istupper_l _iswupper_l
#تعریف_کړه _istxdigit iswxdigit
#تعریف_کړه _istxdigit_l _iswxdigit_l

#تعریف_کړه _totupper towupper
#تعریف_کړه _totupper_l _towupper_l
#تعریف_کړه _totlower towlower
#تعریف_کړه _totlower_l _towlower_l

#تعریف_کړه _istlegal(_Char) (1)
#تعریف_کړه _istlead(_Char) (0)
#تعریف_کړه _istleadbyte(_Char) (0)
#تعریف_کړه _istleadbyte_l(_Char,_Locale) (0)

#تعریف_کړه _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? عدم : (_cpc2)-1)
#تعریف_کړه _wcsinc(_pc) ((_pc)+1)
#تعریف_کړه _wcsnextc(_cpc) ((بینښه صحيح) *(_cpc))
#تعریف_کړه _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP اندازه_t __cdecl __wcsncnt(ثابت wchar_t *_Str,اندازه_t Max_شمېر);
#تعریف_کړه _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#تعریف_کړه _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? عدم : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : عدم))
#تعریف_کړه _wcsncpy_l(_Destination,سرچینه_3,شمېر_5,_Locale) (wcsncpy(_Destination,سرچینه_3,شمېر_5))
#تعریف_کړه _wcsncat_l(_Destination,سرچینه_3,شمېر_5,_Locale) (wcsncat(_Destination,سرچینه_3,شمېر_5))
#تعریف_کړه _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#تعریف_کړه _wcsnset_l(_Destination,ارزښت_2,شمېر_5,_Locale) (_wcsnset(_Destination,ارزښت_2,شمېر_5))
#تعریف_کړه _wcsset_l(_Destination,ارزښت_2,_Locale) (_wcsset(_Destination,ارزښت_2))

  /* dirent structures and functions */
#تعریف_کړه _tdirent	_wdirent
#تعریف_کړه _TDIR 		_WDIR
#تعریف_کړه _topendir	_wopendir
#تعریف_کړه _tclosedir	_wclosedir
#تعریف_کړه _treaddir	_wreaddir
#تعریف_کړه _trewinddir	_wrewinddir
#تعریف_کړه _ttelldir	_wtelldir
#تعریف_کړه _tseekdir	_wseekdir

#وإلا

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#ضمن <string.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#تعریف_کړه _TEOF EOF

#تعریف_کړه __T(x) x

#تعریف_کړه _tmain اصلي
#تعریف_کړه _tWinMain WinMain
#که_تعریف_شوی _POSIX_
#تعریف_کړه _tenviron environ
#وإلا
#تعریف_کړه _tenviron _environ
#د_که_پای
#تعریف_کړه __targv __argv

#تعریف_کړه _tprintf چاپ_کړه
#تعریف_کړه _tprintf_l _printf_l
#تعریف_کړه _tprintf_p _printf_p
#تعریف_کړه _tprintf_p_l _printf_p_l
#تعریف_کړه _tcprintf _cprintf
#تعریف_کړه _tcprintf_l _cprintf_l
#تعریف_کړه _tcprintf_p _cprintf_p
#تعریف_کړه _tcprintf_p_l _cprintf_p_l
#تعریف_کړه _vtcprintf _vcprintf
#تعریف_کړه _vtcprintf_l _vcprintf_l
#تعریف_کړه _vtcprintf_p _vcprintf_p
#تعریف_کړه _vtcprintf_p_l _vcprintf_p_l
#تعریف_کړه _ftprintf fprintf
#تعریف_کړه _ftprintf_l _fprintf_l
#تعریف_کړه _ftprintf_p _fprintf_p
#تعریف_کړه _ftprintf_p_l _fprintf_p_l
#تعریف_کړه _stprintf sprintf
#تعریف_کړه _stprintf_l _sprintf_l
#تعریف_کړه _stprintf_p _sprintf_p
#تعریف_کړه _stprintf_p_l _sprintf_p_l
#تعریف_کړه _sctprintf _scprintf
#تعریف_کړه _sctprintf_l _scprintf_l
#تعریف_کړه _sctprintf_p _scprintf_p
#تعریف_کړه _sctprintf_p_l _scprintf_p_l
#تعریف_کړه _sntprintf _snprintf
#تعریف_کړه _sntprintf_l _snprintf_l
#تعریف_کړه _vtprintf vprintf
#تعریف_کړه _vtprintf_l _vprintf_l
#تعریف_کړه _vtprintf_p _vprintf_p
#تعریف_کړه _vtprintf_p_l _vprintf_p_l
#تعریف_کړه _vftprintf vfprintf
#تعریف_کړه _vftprintf_l _vfprintf_l
#تعریف_کړه _vftprintf_p _vfprintf_p
#تعریف_کړه _vftprintf_p_l _vfprintf_p_l
#تعریف_کړه _vstprintf vsprintf
#تعریف_کړه _vstprintf_l _vsprintf_l
#تعریف_کړه _vstprintf_p _vsprintf_p
#تعریف_کړه _vstprintf_p_l _vsprintf_p_l
#تعریف_کړه _vsctprintf _vscprintf
#تعریف_کړه _vsctprintf_l _vscprintf_l
#تعریف_کړه _vsctprintf_p _vscprintf_p
#تعریف_کړه _vsctprintf_p_l _vscprintf_p_l
#تعریف_کړه _vsntprintf _vsnprintf
#تعریف_کړه _vsntprintf_l _vsnprintf_l

#تعریف_کړه _tscanf scanf
#تعریف_کړه _tscanf_l _scanf_l
#تعریف_کړه _tcscanf _cscanf
#تعریف_کړه _tcscanf_l _cscanf_l
#تعریف_کړه _ftscanf fscanf
#تعریف_کړه _ftscanf_l _fscanf_l
#تعریف_کړه _stscanf له_مزي_ولوله
#تعریف_کړه _stscanf_l _sscanf_l
#تعریف_کړه _sntscanf _snscanf
#تعریف_کړه _sntscanf_l _snscanf_l

#تعریف_کړه _fgettc fgetc
#تعریف_کړه _fgettc_nolock _fgetc_nolock
#تعریف_کړه _fgettchar _fgetchar
#تعریف_کړه _fgetts fgets
#تعریف_کړه _fputtc fputc
#تعریف_کړه _fputtc_nolock _fputc_nolock
#تعریف_کړه _fputtchar _fputchar
#تعریف_کړه _fputts fputs
#تعریف_کړه _cputts _cputs
#تعریف_کړه _gettc getc
#تعریف_کړه _gettc_nolock _getc_nolock
#تعریف_کړه _gettch _getch
#تعریف_کړه _gettch_nolock _getch_nolock
#تعریف_کړه _gettche _getche
#تعریف_کړه _gettche_nolock _getche_nolock
#تعریف_کړه _gettchar getchar
#تعریف_کړه _gettchar_nolock _getchar_nolock
#تعریف_کړه _getts gets
#تعریف_کړه _cgetts _cgets
#تعریف_کړه _puttc putc
#تعریف_کړه _puttc_nolock _putc_nolock
#تعریف_کړه _puttchar توری_چاپ_کړه
#تعریف_کړه _puttchar_nolock _putchar_nolock
#تعریف_کړه _puttch _putch
#تعریف_کړه _puttch_nolock _putch_nolock
#تعریف_کړه _putts puts
#تعریف_کړه _ungettc ungetc
#تعریف_کړه _ungettc_nolock _ungetc_nolock
#تعریف_کړه _ungettch _ungetch
#تعریف_کړه _ungettch_nolock _ungetch_nolock

#تعریف_کړه _tcstod strtod
#تعریف_کړه _tcstol strtol
#تعریف_کړه _tcstoul strtoul
#تعریف_کړه _tstof atof
#تعریف_کړه _tstol atol
#تعریف_کړه _tstoi atoi
#تعریف_کړه _tstoi64 _atoi64
#تعریف_کړه _tcstod_l _strtod_l
#تعریف_کړه _tcstol_l _strtol_l
#تعریف_کړه _tcstoul_l _strtoul_l
#تعریف_کړه _tstof_l _atof_l
#تعریف_کړه _tstol_l _atol_l
#تعریف_کړه _tstoi_l _atoi_l
#تعریف_کړه _tstoi64_l _atoi64_l

#تعریف_کړه _itot _itoa
#تعریف_کړه _ltot _ltoa
#تعریف_کړه _ultot _ultoa
#تعریف_کړه _ttoi atoi
#تعریف_کړه _ttol atol

#تعریف_کړه _ttoi64 _atoi64
#تعریف_کړه _tcstoi64 _strtoi64
#تعریف_کړه _tcstoi64_l _strtoi64_l
#تعریف_کړه _tcstoui64 _strtoui64
#تعریف_کړه _tcstoui64_l _strtoui64_l
#تعریف_کړه _i64tot _i64toa
#تعریف_کړه _ui64tot _ui64toa

#تعریف_کړه _tcscat strcat
#تعریف_کړه _tcscpy strcpy
#تعریف_کړه _tcsdup _strdup
#تعریف_کړه _tcslen مزي_اوږدوالی
#إذا 0
#تعریف_کړه _tcsnlen strnlen
#د_که_پای
#تعریف_کړه _tcsxfrm strxfrm
#تعریف_کړه _tcsxfrm_l _strxfrm_l
#تعریف_کړه _tcserror strerror
#تعریف_کړه __tcserror _strerror

#تعریف_کړه _texecl _execl
#تعریف_کړه _texecle _execle
#تعریف_کړه _texeclp _execlp
#تعریف_کړه _texeclpe _execlpe
#تعریف_کړه _texecv _execv
#تعریف_کړه _texecve _execve
#تعریف_کړه _texecvp _execvp
#تعریف_کړه _texecvpe _execvpe

#تعریف_کړه _tspawnl _spawnl
#تعریف_کړه _tspawnle _spawnle
#تعریف_کړه _tspawnlp _spawnlp
#تعریف_کړه _tspawnlpe _spawnlpe
#تعریف_کړه _tspawnv _spawnv
#تعریف_کړه _tspawnve _spawnve
#تعریف_کړه _tspawnvp _spawnvp
#تعریف_کړه _tspawnvpe _spawnvpe

#تعریف_کړه _tsystem system

#تعریف_کړه _tasctime asctime
#تعریف_کړه _tctime ctime
#تعریف_کړه _tctime32 _ctime32
#تعریف_کړه _tctime64 _ctime64
#تعریف_کړه _tstrdate _strdate
#تعریف_کړه _tstrtime _strtime
#تعریف_کړه _tutime _utime
#تعریف_کړه _tutime32 _utime32
#تعریف_کړه _tutime64 _utime64
#تعریف_کړه _tcsftime strftime
#تعریف_کړه _tcsftime_l _strftime_l

#تعریف_کړه _tchdir _chdir
#تعریف_کړه _tgetcwd _getcwd
#تعریف_کړه _tgetdcwd _getdcwd
#تعریف_کړه _tgetdcwd_nolock _getdcwd_nolock
#تعریف_کړه _tmkdir _mkdir
#تعریف_کړه _trmdir _rmdir

#تعریف_کړه _tfullpath _fullpath
#تعریف_کړه _tgetenv getenv
#تعریف_کړه _tmakepath _makepath
#تعریف_کړه _tpgmptr _pgmptr
#تعریف_کړه _get_tpgmptr _get_pgmptr
#تعریف_کړه _tputenv _putenv
#تعریف_کړه _tsearchenv _searchenv
#تعریف_کړه _tsplitpath _splitpath

#که_تعریف_شوی _POSIX_
#تعریف_کړه _tfdopen fdopen
#وإلا
#تعریف_کړه _tfdopen _fdopen
#د_که_پای
#تعریف_کړه _tfsopen _fsopen
#تعریف_کړه _tfopen fopen
#تعریف_کړه _tfreopen freopen
#تعریف_کړه _tperror perror
#تعریف_کړه _tpopen _popen
#تعریف_کړه _ttempnam _tempnam
#تعریف_کړه _ttmpnam tmpnam

#تعریف_کړه _tchmod _chmod
#تعریف_کړه _tcreat _creat
#تعریف_کړه _tfindfirst _findfirst
#تعریف_کړه _tfindfirst32 _findfirst32
#تعریف_کړه _tfindfirst64 _findfirst64
#تعریف_کړه _tfindfirsti64 _findfirsti64
#تعریف_کړه _tfindfirst32i64 _findfirst32i64
#تعریف_کړه _tfindfirst64i32 _findfirst64i32
#تعریف_کړه _tfindnext _findnext
#تعریف_کړه _tfindnext32 _findnext32
#تعریف_کړه _tfindnext64 _findnext64
#تعریف_کړه _tfindnexti64 _findnexti64
#تعریف_کړه _tfindnext32i64 _findnext32i64
#تعریف_کړه _tfindnext64i32 _findnext64i32
#تعریف_کړه _tmktemp _mktemp

#که_تعریف_شوی _POSIX_
#تعریف_کړه _topen open
#تعریف_کړه _taccess access
#وإلا
#تعریف_کړه _topen _open
#تعریف_کړه _taccess _access
#د_که_پای

#تعریف_کړه _tremove remove
#تعریف_کړه _trename rename
#تعریف_کړه _tsopen _sopen
#تعریف_کړه _tunlink _unlink

#تعریف_کړه _tfinddata_t _finddata_t
#تعریف_کړه _tfinddata32_t _finddata32_t
#تعریف_کړه _tfinddata64_t __finddata64_t
#تعریف_کړه _tfinddatai64_t _finddatai64_t
#تعریف_کړه _tfinddata32i64_t _finddata32i64_t
#تعریف_کړه _tfinddata64i32_t _finddata64i32_t

#تعریف_کړه _istascii __isascii
#تعریف_کړه _istcntrl iscntrl
#تعریف_کړه _istcntrl_l _iscntrl_l
#تعریف_کړه _istxdigit isxdigit
#تعریف_کړه _istxdigit_l _isxdigit_l

#تعریف_کړه _tstat _stat
#تعریف_کړه _tstat32 _stat32
#تعریف_کړه _tstat32i64 _stat32i64
#تعریف_کړه _tstat64 _stat64
#تعریف_کړه _tstat64i32 _stat64i32
#تعریف_کړه _tstati64 _stati64

#تعریف_کړه _tsetlocale setlocale

#که_تعریف_شوی _MBCS

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#ضمن <mbstring.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی __TCHAR_DEFINED
  تعريفنوع حرف _TCHAR;
  تعريفنوع نښهدار حرف _TSCHAR;
  تعريفنوع بینښه حرف _TUCHAR;
  تعريفنوع بینښه حرف _TXCHAR;
  تعريفنوع بینښه صحيح _TINT;
#تعریف_کړه __TCHAR_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _TCHAR_DEFINED
#که_نه_تعریف_شوی	NO_OLDNAMES
  تعريفنوع حرف TCHAR;
#د_که_پای
#تعریف_کړه _TCHAR_DEFINED
#د_که_پای

#که_تعریف_شوی MB_MAP_مستقیم

#تعریف_کړه _tcschr _mbschr
#تعریف_کړه _tcscspn _mbscspn
#تعریف_کړه _tcsncat _mbsnbcat
#تعریف_کړه _tcsncat_l _mbsnbcat_l
#تعریف_کړه _tcsncpy _mbsnbcpy
#تعریف_کړه _tcsncpy_l _mbsnbcpy_l
#تعریف_کړه _tcspbrk _mbspbrk
#تعریف_کړه _tcsrchr _mbsrchr
#تعریف_کړه _tcsspn _mbsspn
#تعریف_کړه _tcsstr _mbsstr
#تعریف_کړه _tcstok _mbstok
#تعریف_کړه _tcstok_l _mbstok_l

#تعریف_کړه _tcsnset _mbsnbset
#تعریف_کړه _tcsnset_l _mbsnbset_l
#تعریف_کړه _tcsrev _mbsrev
#تعریف_کړه _tcsset _mbsset
#تعریف_کړه _tcsset_l _mbsset_l

#تعریف_کړه _tcscmp _mbscmp
#تعریف_کړه _tcsicmp _mbsicmp
#تعریف_کړه _tcsicmp_l _mbsicmp_l
#تعریف_کړه _tcsnccmp _mbsncmp
#تعریف_کړه _tcsncmp _mbsnbcmp
#تعریف_کړه _tcsncicmp _mbsnicmp
#تعریف_کړه _tcsncicmp_l _mbsnicmp_l
#تعریف_کړه _tcsnicmp _mbsnbicmp
#تعریف_کړه _tcsnicmp_l _mbsnbicmp_l

#تعریف_کړه _tcscoll _mbscoll
#تعریف_کړه _tcscoll_l _mbscoll_l
#تعریف_کړه _tcsicoll _mbsicoll
#تعریف_کړه _tcsicoll_l _mbsicoll_l
#تعریف_کړه _tcsnccoll _mbsncoll
#تعریف_کړه _tcsnccoll_l _mbsncoll_l
#تعریف_کړه _tcsncoll _mbsnbcoll
#تعریف_کړه _tcsncoll_l _mbsnbcoll_l
#تعریف_کړه _tcsncicoll _mbsnicoll
#تعریف_کړه _tcsncicoll_l _mbsnicoll_l
#تعریف_کړه _tcsnicoll _mbsnbicoll
#تعریف_کړه _tcsnicoll_l _mbsnbicoll_l

#تعریف_کړه _tcsclen _mbslen
#تعریف_کړه _tcscnlen _mbsnlen
#تعریف_کړه _tcsclen_l _mbslen_l
#تعریف_کړه _tcscnlen_l _mbsnlen_l
#تعریف_کړه _tcsnccat _mbsncat
#تعریف_کړه _tcsnccat_l _mbsncat_l
#تعریف_کړه _tcsnccpy _mbsncpy
#تعریف_کړه _tcsnccpy_l _mbsncpy_l
#تعریف_کړه _tcsncset _mbsnset
#تعریف_کړه _tcsncset_l _mbsnset_l

#تعریف_کړه _tcsdec _mbsdec
#تعریف_کړه _tcsinc _mbsinc
#تعریف_کړه _tcsnbcnt _mbsnbcnt
#تعریف_کړه _tcsnccnt _mbsnccnt
#تعریف_کړه _tcsnextc _mbsnextc
#تعریف_کړه _tcsninc _mbsninc
#تعریف_کړه _tcsspnp _mbsspnp

#تعریف_کړه _tcslwr _mbslwr
#تعریف_کړه _tcslwr_l _mbslwr_l
#تعریف_کړه _tcsupr _mbsupr
#تعریف_کړه _tcsupr_l _mbsupr_l

#تعریف_کړه _tclen _mbclen
#تعریف_کړه _tccpy _mbccpy
#تعریف_کړه _tccpy_l _mbccpy_l
#وإلا

  _CRTIMP _CONST_RETURN حرف *__cdecl _tcschr(ثابت حرف *_Str,بینښه صحيح _Val);
  _CRTIMP اندازه_t __cdecl _tcscspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP حرف *__cdecl _tcsncat(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP حرف *__cdecl _tcsncat_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncpy(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP حرف *__cdecl _tcsncpy_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcspbrk(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsrchr(ثابت حرف *_Str,بینښه صحيح _Ch);
  _CRTIMP اندازه_t __cdecl _tcsspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsstr(ثابت حرف *_Str,ثابت حرف *_Substr);
  _CRTIMP حرف *__cdecl _tcstok(حرف *_Str,ثابت حرف *_Delim);
  _CRTIMP حرف *__cdecl _tcstok_l(حرف *_Str,ثابت حرف *_Delim,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnset(حرف *_Str,بینښه صحيح _Val,اندازه_t Max_شمېر);
  _CRTIMP حرف *__cdecl _tcsrev(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsset(حرف *_Str,بینښه صحيح _Val);
  _CRTIMP حرف *__cdecl _tcsset_l(حرف *_Str,بینښه صحيح _Val,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcscmp(ثابت حرف *_Str1,ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _tcsicmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcsicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnccmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsncmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsncicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsncicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsnicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcscoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcscoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsicoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _tcsicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnccoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsnccoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsncoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsncoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsncicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsncicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _tcsnicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _tcsnicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _tcsclen(ثابت حرف *_Str);
  _CRTIMP اندازه_t __cdecl _tcscnlen(ثابت حرف *_Str,اندازه_t Max_شمېر);
  _CRTIMP اندازه_t __cdecl _tcsclen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _tcscnlen_l(ثابت حرف *_Str,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccat(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP حرف *__cdecl _tcsnccat_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccpy(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر);
  _CRTIMP حرف *__cdecl _tcsnccpy_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncset(حرف *_Str,بینښه صحيح _Val,اندازه_t Max_شمېر);
  _CRTIMP حرف *__cdecl _tcsdec(ثابت حرف *پیل_4,ثابت حرف *_Pos);
  _CRTIMP حرف *__cdecl _tcsinc(ثابت حرف *_Ptr);
  _CRTIMP اندازه_t __cdecl _tcsnbcnt(ثابت حرف *_Str,اندازه_t Max_شمېر);
  _CRTIMP اندازه_t __cdecl _tcsnccnt(ثابت حرف *_Str,اندازه_t Max_شمېر);
  _CRTIMP بینښه صحيح __cdecl _tcsnextc (ثابت حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsninc(ثابت حرف *_Ptr,اندازه_t شمېر_5);
  _CRTIMP حرف *__cdecl _tcsspnp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP حرف *__cdecl _tcslwr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcslwr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsupr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsupr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _tclen(ثابت حرف *_Str);
  _CRTIMP فراغ __cdecl _tccpy(حرف *_DstCh,ثابت حرف *_SrcCh);

#که_تعریف_شوی __cplusplus
#که_نه_تعریف_شوی _CPP_TCHAR_INLINES_DEFINED
#تعریف_کړه _CPP_TCHAR_INLINES_DEFINED
  خارجي "C++" {
    خارجي مضمن حرف *__cdecl _tcschr(حرف *_S,بینښه صحيح _C) { أرجع ((حرف *)_tcschr((ثابت حرف *)_S,_C)); }
    خارجي مضمن حرف *__cdecl _tcspbrk(حرف *_S,ثابت حرف *_P) { أرجع ((حرف *)_tcspbrk((ثابت حرف *)_S,_P)); }
    خارجي مضمن حرف *__cdecl _tcsrchr(حرف *_S,بینښه صحيح _C) { أرجع ((حرف *)_tcsrchr((ثابت حرف *)_S,_C)); }
    خارجي مضمن حرف *__cdecl _tcsstr(حرف *_S,ثابت حرف *_P) { أرجع ((حرف *)_tcsstr((ثابت حرف *)_S,_P)); }
  }
#د_که_پای
#د_که_پای
#د_که_پای

#تعریف_کړه _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#تعریف_کړه _istalnum _ismbcalnum
#تعریف_کړه _istalnum_l _ismbcalnum_l
#تعریف_کړه _istalpha _ismbcalpha
#تعریف_کړه _istalpha_l _ismbcalpha_l
#تعریف_کړه _istdigit _ismbcdigit
#تعریف_کړه _istdigit_l _ismbcdigit_l
#تعریف_کړه _istgraph _ismbcgraph
#تعریف_کړه _istgraph_l _ismbcgraph_l
#تعریف_کړه _istlegal _ismbclegal
#تعریف_کړه _istlegal_l _ismbclegal_l
#تعریف_کړه _istlower _ismbclower
#تعریف_کړه _istlower_l _ismbclower_l
#تعریف_کړه _istprint _ismbcprint
#تعریف_کړه _istprint_l _ismbcprint_l
#تعریف_کړه _istpunct _ismbcpunct
#تعریف_کړه _istpunct_l _ismbcpunct_l
#تعریف_کړه _istspace _ismbcspace
#تعریف_کړه _istspace_l _ismbcspace_l
#تعریف_کړه _istupper _ismbcupper
#تعریف_کړه _istupper_l _ismbcupper_l

#تعریف_کړه _totupper _mbctoupper
#تعریف_کړه _totupper_l _mbctoupper_l
#تعریف_کړه _totlower _mbctolower
#تعریف_کړه _totlower_l _mbctolower_l

#تعریف_کړه _istlead _ismbblead
#تعریف_کړه _istleadbyte isleadbyte
#تعریف_کړه _istleadbyte_l _isleadbyte_l
#وإلا

#که_نه_تعریف_شوی __TCHAR_DEFINED
#تعریف_کړه __TCHAR_DEFINED
  تعريفنوع حرف _TCHAR;
  تعريفنوع نښهدار حرف _TSCHAR;
  تعريفنوع بینښه حرف _TUCHAR;
  تعريفنوع حرف _TXCHAR;
  تعريفنوع صحيح _TINT;
#د_که_پای

#که_نه_تعریف_شوی _TCHAR_DEFINED
#تعریف_کړه _TCHAR_DEFINED
#که_نه_تعریف_شوی	NO_OLDNAMES
  تعريفنوع حرف TCHAR;
#د_که_پای
#د_که_پای

#تعریف_کړه _tcschr strchr
#تعریف_کړه _tcscspn strcspn
#تعریف_کړه _tcsncat strncat
#تعریف_کړه _tcsncat_l _strncat_l
#تعریف_کړه _tcsncpy strncpy
#تعریف_کړه _tcsncpy_l _strncpy_l
#تعریف_کړه _tcspbrk strpbrk
#تعریف_کړه _tcsrchr strrchr
#تعریف_کړه _tcsspn strspn
#تعریف_کړه _tcsstr مزي_پلټنه
#تعریف_کړه _tcstok strtok
#تعریف_کړه _tcstok_l _strtok_l

#تعریف_کړه _tcsnset _strnset
#تعریف_کړه _tcsnset_l _strnset_l
#تعریف_کړه _tcsrev _strrev
#تعریف_کړه _tcsset _strset

#تعریف_کړه _tcscmp strcmp
#تعریف_کړه _tcsicmp _stricmp
#تعریف_کړه _tcsicmp_l _stricmp_l
#تعریف_کړه _tcsnccmp مزي_پرتله
#تعریف_کړه _tcsncmp مزي_پرتله
#تعریف_کړه _tcsncicmp _strnicmp
#تعریف_کړه _tcsncicmp_l _strnicmp_l
#تعریف_کړه _tcsnicmp _strnicmp
#تعریف_کړه _tcsnicmp_l _strnicmp_l

#تعریف_کړه _tcscoll strcoll
#تعریف_کړه _tcscoll_l _strcoll_l
#تعریف_کړه _tcsicoll _stricoll
#تعریف_کړه _tcsicoll_l _stricoll_l
#تعریف_کړه _tcsnccoll _strncoll
#تعریف_کړه _tcsnccoll_l _strncoll_l
#تعریف_کړه _tcsncoll _strncoll
#تعریف_کړه _tcsncoll_l _strncoll_l
#تعریف_کړه _tcsncicoll _strnicoll
#تعریف_کړه _tcsncicoll_l _strnicoll_l
#تعریف_کړه _tcsnicoll _strnicoll
#تعریف_کړه _tcsnicoll_l _strnicoll_l

#تعریف_کړه _tcsclen مزي_اوږدوالی
#تعریف_کړه _tcscnlen strnlen
#تعریف_کړه _tcsclen_l(_String,_Locale) مزي_اوږدوالی(_String)
#تعریف_کړه _tcscnlen_l(_String,Max_شمېر_2,_Locale) strnlen_l((_String),(Max_شمېر_2))
#تعریف_کړه _tcsnccat strncat
#تعریف_کړه _tcsnccat_l _strncat_l
#تعریف_کړه _tcsnccpy strncpy
#تعریف_کړه _tcsnccpy_l _strncpy_l
#تعریف_کړه _tcsncset _strnset

#تعریف_کړه _tcsdec _strdec
#تعریف_کړه _tcsinc _strinc
#تعریف_کړه _tcsnbcnt _strncnt
#تعریف_کړه _tcsnccnt _strncnt
#تعریف_کړه _tcsnextc _strnextc
#تعریف_کړه _tcsninc _strninc
#تعریف_کړه _tcsspnp _strspnp

#تعریف_کړه _tcslwr _strlwr
#تعریف_کړه _tcslwr_l _strlwr_l
#تعریف_کړه _tcsupr _strupr
#تعریف_کړه _tcsupr_l _strupr_l
#تعریف_کړه _tcsxfrm strxfrm
#تعریف_کړه _tcsxfrm_l _strxfrm_l

#تعریف_کړه _istlead(_Char) (0)
#تعریف_کړه _istleadbyte(_Char) (0)
#تعریف_کړه _istleadbyte_l(_Char,_Locale) (0)

#تعریف_کړه _tclen(_pc) (1)
#تعریف_کړه _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#تعریف_کړه _tccmp(_cpc1,_cpc2) (((بینښه حرف)*(_cpc1))-((بینښه حرف)*(_cpc2)))

  /* dirent structures and functions */
#تعریف_کړه _tdirent	dirent
#تعریف_کړه _TDIR 		DIR
#تعریف_کړه _topendir	opendir
#تعریف_کړه _tclosedir	closedir
#تعریف_کړه _treaddir	readdir
#تعریف_کړه _trewinddir	rewinddir
#تعریف_کړه _ttelldir	telldir
#تعریف_کړه _tseekdir	seekdir

#تعریف_کړه _istalnum که_توری_یا_عدد
#تعریف_کړه _istalnum_l _isalnum_l
#تعریف_کړه _istalpha که_توری
#تعریف_کړه _istalpha_l _isalpha_l
#تعریف_کړه _istdigit که_عدد
#تعریف_کړه _istdigit_l _isdigit_l
#تعریف_کړه _istgraph isgraph
#تعریف_کړه _istgraph_l _isgraph_l
#تعریف_کړه _istlower islower
#تعریف_کړه _istlower_l _islower_l
#تعریف_کړه _istprint isprint
#تعریف_کړه _istprint_l _isprint_l
#تعریف_کړه _istpunct ispunct
#تعریف_کړه _istpunct_l _ispunct_l
#تعریف_کړه _istspace که_تشه
#تعریف_کړه _istspace_l _isspace_l
#تعریف_کړه _istupper isupper
#تعریف_کړه _istupper_l _isupper_l

#تعریف_کړه _totupper لوی_توری
#تعریف_کړه _totupper_l _toupper_l
#تعریف_کړه _totlower tolower
#تعریف_کړه _totlower_l _tolower_l

#تعریف_کړه _istlegal(_c) (1)

#که_نه_تعریف_شوی عدم
#که_تعریف_شوی __cplusplus
#تعریف_کړه عدم 0
#وإلا
#تعریف_کړه عدم ((فراغ *)0)
#د_که_پای
#د_که_پای

#تعریف_کړه _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? عدم : (_cpc2)-1)
#تعریف_کړه _strinc(_pc) ((_pc)+1)
#تعریف_کړه _strnextc(_cpc) ((بینښه صحيح) *(ثابت بینښه حرف *)(_cpc))
#تعریف_کړه _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP اندازه_t __cdecl __strncnt(ثابت حرف *_Str,اندازه_t _Cnt);
#تعریف_کړه _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#تعریف_کړه _strspnp(_cpc1,_cpc2) (!_cpc1 ? عدم : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : عدم))

#تعریف_کړه _strncpy_l(_Destination,سرچینه_3,شمېر_5,_Locale) (strncpy(_Destination,سرچینه_3,شمېر_5))
#تعریف_کړه _strncat_l(_Destination,سرچینه_3,شمېر_5,_Locale) (strncat(_Destination,سرچینه_3,شمېر_5))
#تعریف_کړه _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#تعریف_کړه _strnset_l(_Destination,ارزښت_2,شمېر_5,_Locale) (_strnset(_Destination,ارزښت_2,شمېر_5))
#تعریف_کړه _strset_l(_Destination,ارزښت_2,_Locale) (_strset(_Destination,ارزښت_2))
#د_که_پای
#د_که_پای

#تعریف_کړه _T(x) __T(x)
#تعریف_کړه متن_2(x) __T(x)

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#ضمن <sec_api/tchar_s.h>
#د_که_پای
