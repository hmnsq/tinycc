/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#شامل <_mingw.h>

#اگر_غیر_تعریف_شدہ _INC_TCHAR
#تعریف_کرو _INC_TCHAR

#اگر_تعریف_شدہ _STRSAFE_H_INCLUDED_
#غلطی Need مقصد include strsafe.h after tchar.h
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#تعریف_کرو _ftcscat _tcscat
#تعریف_کرو _ftcschr _tcschr
#تعریف_کرو _ftcscpy _tcscpy
#تعریف_کرو _ftcscspn _tcscspn
#تعریف_کرو _ftcslen _tcslen
#تعریف_کرو _ftcsncat _tcsncat
#تعریف_کرو _ftcsncpy _tcsncpy
#تعریف_کرو _ftcspbrk _tcspbrk
#تعریف_کرو _ftcsrchr _tcsrchr
#تعریف_کرو _ftcsspn _tcsspn
#تعریف_کرو _ftcsstr _tcsstr
#تعریف_کرو _ftcstok _tcstok

#تعریف_کرو _ftcsdup _tcsdup
#تعریف_کرو _ftcsnset _tcsnset
#تعریف_کرو _ftcsrev _tcsrev
#تعریف_کرو _ftcsset _tcsset

#تعریف_کرو _ftcscmp _tcscmp
#تعریف_کرو _ftcsicmp _tcsicmp
#تعریف_کرو _ftcsnccmp _tcsnccmp
#تعریف_کرو _ftcsncmp _tcsncmp
#تعریف_کرو _ftcsncicmp _tcsncicmp
#تعریف_کرو _ftcsnicmp _tcsnicmp

#تعریف_کرو _ftcscoll _tcscoll
#تعریف_کرو _ftcsicoll _tcsicoll
#تعریف_کرو _ftcsnccoll _tcsnccoll
#تعریف_کرو _ftcsncoll _tcsncoll
#تعریف_کرو _ftcsncicoll _tcsncicoll
#تعریف_کرو _ftcsnicoll _tcsnicoll

#تعریف_کرو _ftcsclen _tcsclen
#تعریف_کرو _ftcsnccat _tcsnccat
#تعریف_کرو _ftcsnccpy _tcsnccpy
#تعریف_کرو _ftcsncset _tcsncset

#تعریف_کرو _ftcsdec _tcsdec
#تعریف_کرو _ftcsinc _tcsinc
#تعریف_کرو _ftcsnbcnt _tcsnbcnt
#تعریف_کرو _ftcsnccnt _tcsnccnt
#تعریف_کرو _ftcsnextc _tcsnextc
#تعریف_کرو _ftcsninc _tcsninc
#تعریف_کرو _ftcsspnp _tcsspnp

#تعریف_کرو _ftcslwr _tcslwr
#تعریف_کرو _ftcsupr _tcsupr

#تعریف_کرو _ftclen _tclen
#تعریف_کرو _ftccpy _tccpy
#تعریف_کرو _ftccmp _tccmp

#اگر_غیر_تعریف_شدہ _CONST_RETURN
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو _CONST_RETURN ثابت
#تعریف_کرو _CRT_CONST_CORRECT_OVERLOADS
#ورنہ
#تعریف_کرو _CONST_RETURN
#اگر_ختم
#اگر_ختم

#تعریف_کرو _WConst_return _CONST_RETURN

#اگر_تعریف_شدہ _UNICODE

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#شامل <wchar.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCTYPE_T_DEFINED
#تعریف_کرو _WCTYPE_T_DEFINED
  قسمتعریف غیرعلامتی مختصر wint_t;
  قسمتعریف غیرعلامتی مختصر wctype_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ __TCHAR_DEFINED
#تعریف_کرو __TCHAR_DEFINED
  قسمتعریف wchar_t _TCHAR;
  قسمتعریف wchar_t _TSCHAR;
  قسمتعریف wchar_t _TUCHAR;
  قسمتعریف wchar_t _TXCHAR;
  قسمتعریف wint_t _TINT;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TCHAR_DEFINED
#تعریف_کرو _TCHAR_DEFINED
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  قسمتعریف wchar_t TCHAR;
#اگر_ختم
#اگر_ختم

#تعریف_کرو _TEOF WEOF

#تعریف_کرو __T(x) L##x

#تعریف_کرو _tmain wmain
#تعریف_کرو _tWinMain wWinMain
#تعریف_کرو _tenviron _wenviron
#تعریف_کرو __targv __wargv

#تعریف_کرو _tprintf wprintf
#تعریف_کرو _tprintf_l _wprintf_l
#تعریف_کرو _tprintf_p _wprintf_p
#تعریف_کرو _tprintf_p_l _wprintf_p_l
#تعریف_کرو _tcprintf _cwprintf
#تعریف_کرو _tcprintf_l _cwprintf_l
#تعریف_کرو _tcprintf_p _cwprintf_p
#تعریف_کرو _tcprintf_p_l _cwprintf_p_l
#تعریف_کرو _vtcprintf _vcwprintf
#تعریف_کرو _vtcprintf_l _vcwprintf_l
#تعریف_کرو _vtcprintf_p _vcwprintf_p
#تعریف_کرو _vtcprintf_p_l _vcwprintf_p_l
#تعریف_کرو _ftprintf fwprintf
#تعریف_کرو _ftprintf_l _fwprintf_l
#تعریف_کرو _ftprintf_p _fwprintf_p
#تعریف_کرو _ftprintf_p_l _fwprintf_p_l
#تعریف_کرو _stprintf swprintf
#تعریف_کرو _stprintf_l __swprintf_l
#تعریف_کرو _stprintf_p _swprintf_p
#تعریف_کرو _stprintf_p_l _swprintf_p_l
#تعریف_کرو _sctprintf _scwprintf
#تعریف_کرو _sctprintf_l _scwprintf_l
#تعریف_کرو _sctprintf_p _scwprintf_p
#تعریف_کرو _sctprintf_p_l _scwprintf_p_l
#تعریف_کرو _sntprintf _snwprintf
#تعریف_کرو _sntprintf_l _snwprintf_l
#تعریف_کرو _vtprintf vwprintf
#تعریف_کرو _vtprintf_l _vwprintf_l
#تعریف_کرو _vtprintf_p _vwprintf_p
#تعریف_کرو _vtprintf_p_l _vwprintf_p_l
#تعریف_کرو _vftprintf vfwprintf
#تعریف_کرو _vftprintf_l _vfwprintf_l
#تعریف_کرو _vftprintf_p _vfwprintf_p
#تعریف_کرو _vftprintf_p_l _vfwprintf_p_l
#تعریف_کرو _vstprintf vswprintf
#تعریف_کرو _vstprintf_l _vswprintf_l
#تعریف_کرو _vstprintf_p _vswprintf_p
#تعریف_کرو _vstprintf_p_l _vswprintf_p_l
#تعریف_کرو _vsctprintf _vscwprintf
#تعریف_کرو _vsctprintf_l _vscwprintf_l
#تعریف_کرو _vsctprintf_p _vscwprintf_p
#تعریف_کرو _vsctprintf_p_l _vscwprintf_p_l
#تعریف_کرو _vsntprintf _vsnwprintf
#تعریف_کرو _vsntprintf_l _vsnwprintf_l

#تعریف_کرو _tscanf wscanf
#تعریف_کرو _tscanf_l _wscanf_l
#تعریف_کرو _tcscanf _cwscanf
#تعریف_کرو _tcscanf_l _cwscanf_l
#تعریف_کرو _ftscanf fwscanf
#تعریف_کرو _ftscanf_l _fwscanf_l
#تعریف_کرو _stscanf swscanf
#تعریف_کرو _stscanf_l _swscanf_l
#تعریف_کرو _sntscanf _snwscanf
#تعریف_کرو _sntscanf_l _snwscanf_l

#تعریف_کرو _fgettc fgetwc
#تعریف_کرو _fgettc_nolock _fgetwc_nolock
#تعریف_کرو _fgettchar _fgetwchar
#تعریف_کرو _fgetts fgetws
#تعریف_کرو _fputtc fputwc
#تعریف_کرو _fputtc_nolock _fputwc_nolock
#تعریف_کرو _fputtchar _fputwchar
#تعریف_کرو _fputts fputws
#تعریف_کرو _cputts _cputws
#تعریف_کرو _cgetts _cgetws
#تعریف_کرو _gettc getwc
#تعریف_کرو _gettc_nolock _getwc_nolock
#تعریف_کرو _gettch _getwch
#تعریف_کرو _gettch_nolock _getwch_nolock
#تعریف_کرو _gettche _getwche
#تعریف_کرو _gettche_nolock _getwche_nolock
#تعریف_کرو _gettchar getwchar
#تعریف_کرو _gettchar_nolock _getwchar_nolock
#تعریف_کرو _getts _getws
#تعریف_کرو _puttc putwc
#تعریف_کرو _puttc_nolock _putwc_nolock
#تعریف_کرو _puttchar putwchar
#تعریف_کرو _puttchar_nolock _putwchar_nolock
#تعریف_کرو _puttch _putwch
#تعریف_کرو _puttch_nolock _putwch_nolock
#تعریف_کرو _putts _putws
#تعریف_کرو _ungettc ungetwc
#تعریف_کرو _ungettc_nolock _ungetwc_nolock
#تعریف_کرو _ungettch _ungetwch
#تعریف_کرو _ungettch_nolock _ungetwch_nolock

#تعریف_کرو _tcstod wcstod
#تعریف_کرو _tcstol wcstol
#تعریف_کرو _tcstoul wcstoul
#تعریف_کرو _tcstoi64 _wcstoi64
#تعریف_کرو _tcstoui64 _wcstoui64
#تعریف_کرو _tstof _wtof
#تعریف_کرو _tstol _wtol
#تعریف_کرو _tstoi _wtoi
#تعریف_کرو _tstoi64 _wtoi64
#تعریف_کرو _tcstod_l _wcstod_l
#تعریف_کرو _tcstol_l _wcstol_l
#تعریف_کرو _tcstoul_l _wcstoul_l
#تعریف_کرو _tcstoi64_l _wcstoi64_l
#تعریف_کرو _tcstoui64_l _wcstoui64_l
#تعریف_کرو _tstof_l _wtof_l
#تعریف_کرو _tstol_l _wtol_l
#تعریف_کرو _tstoi_l _wtoi_l
#تعریف_کرو _tstoi64_l _wtoi64_l

#تعریف_کرو _itot _itow
#تعریف_کرو _ltot _ltow
#تعریف_کرو _ultot _ultow
#تعریف_کرو _ttoi _wtoi
#تعریف_کرو _ttol _wtol

#تعریف_کرو _ttoi64 _wtoi64
#تعریف_کرو _i64tot _i64tow
#تعریف_کرو _ui64tot _ui64tow

#تعریف_کرو _tcscat wcscat
#تعریف_کرو _tcschr wcschr
#تعریف_کرو _tcscpy wcscpy
#تعریف_کرو _tcscspn wcscspn
#تعریف_کرو _tcslen wcslen
#تعریف_کرو _tcsnlen wcsnlen
#تعریف_کرو _tcsncat wcsncat
#تعریف_کرو _tcsncat_l _wcsncat_l
#تعریف_کرو _tcsncpy wcsncpy
#تعریف_کرو _tcsncpy_l _wcsncpy_l
#تعریف_کرو _tcspbrk wcspbrk
#تعریف_کرو _tcsrchr wcsrchr
#تعریف_کرو _tcsspn wcsspn
#تعریف_کرو _tcsstr wcsstr
#تعریف_کرو _tcstok wcstok
#تعریف_کرو _tcstok_l _wcstok_l
#تعریف_کرو _tcserror _wcserror
#تعریف_کرو __tcserror __wcserror

#تعریف_کرو _tcsdup _wcsdup
#تعریف_کرو _tcsnset _wcsnset
#تعریف_کرو _tcsnset_l _wcsnset_l
#تعریف_کرو _tcsrev _wcsrev
#تعریف_کرو _tcsset _wcsset
#تعریف_کرو _tcsset_l _wcsset_l

#تعریف_کرو _tcscmp wcscmp
#تعریف_کرو _tcsicmp _wcsicmp
#تعریف_کرو _tcsicmp_l _wcsicmp_l
#تعریف_کرو _tcsnccmp wcsncmp
#تعریف_کرو _tcsncmp wcsncmp
#تعریف_کرو _tcsncicmp _wcsnicmp
#تعریف_کرو _tcsncicmp_l _wcsnicmp_l
#تعریف_کرو _tcsnicmp _wcsnicmp
#تعریف_کرو _tcsnicmp_l _wcsnicmp_l

#تعریف_کرو _tcscoll wcscoll
#تعریف_کرو _tcscoll_l _wcscoll_l
#تعریف_کرو _tcsicoll _wcsicoll
#تعریف_کرو _tcsicoll_l _wcsicoll_l
#تعریف_کرو _tcsnccoll _wcsncoll
#تعریف_کرو _tcsnccoll_l _wcsncoll_l
#تعریف_کرو _tcsncoll _wcsncoll
#تعریف_کرو _tcsncoll_l _wcsncoll_l
#تعریف_کرو _tcsncicoll _wcsnicoll
#تعریف_کرو _tcsncicoll_l _wcsnicoll_l
#تعریف_کرو _tcsnicoll _wcsnicoll
#تعریف_کرو _tcsnicoll_l _wcsnicoll_l

#تعریف_کرو _texecl _wexecl
#تعریف_کرو _texecle _wexecle
#تعریف_کرو _texeclp _wexeclp
#تعریف_کرو _texeclpe _wexeclpe
#تعریف_کرو _texecv _wexecv
#تعریف_کرو _texecve _wexecve
#تعریف_کرو _texecvp _wexecvp
#تعریف_کرو _texecvpe _wexecvpe

#تعریف_کرو _tspawnl _wspawnl
#تعریف_کرو _tspawnle _wspawnle
#تعریف_کرو _tspawnlp _wspawnlp
#تعریف_کرو _tspawnlpe _wspawnlpe
#تعریف_کرو _tspawnv _wspawnv
#تعریف_کرو _tspawnve _wspawnve
#تعریف_کرو _tspawnvp _wspawnvp
#تعریف_کرو _tspawnvp _wspawnvp
#تعریف_کرو _tspawnvpe _wspawnvpe

#تعریف_کرو _tsystem _wsystem

#تعریف_کرو _tasctime _wasctime
#تعریف_کرو _tctime _wctime
#تعریف_کرو _tctime32 _wctime32
#تعریف_کرو _tctime64 _wctime64
#تعریف_کرو _tstrdate _wstrdate
#تعریف_کرو _tstrtime _wstrtime
#تعریف_کرو _tutime _wutime
#تعریف_کرو _tutime32 _wutime32
#تعریف_کرو _tutime64 _wutime64
#تعریف_کرو _tcsftime wcsftime
#تعریف_کرو _tcsftime_l _wcsftime_l

#تعریف_کرو _tchdir _wchdir
#تعریف_کرو _tgetcwd _wgetcwd
#تعریف_کرو _tgetdcwd _wgetdcwd
#تعریف_کرو _tgetdcwd_nolock _wgetdcwd_nolock
#تعریف_کرو _tmkdir _wmkdir
#تعریف_کرو _trmdir _wrmdir

#تعریف_کرو _tfullpath _wfullpath
#تعریف_کرو _tgetenv _wgetenv
#تعریف_کرو _tmakepath _wmakepath
#تعریف_کرو _tpgmptr _wpgmptr
#تعریف_کرو _get_tpgmptr _get_wpgmptr
#تعریف_کرو _tputenv _wputenv
#تعریف_کرو _tsearchenv _wsearchenv
#تعریف_کرو _tsplitpath _wsplitpath

#تعریف_کرو _tfdopen _wfdopen
#تعریف_کرو _tfsopen _wfsopen
#تعریف_کرو _tfopen _wfopen
#تعریف_کرو _tfreopen _wfreopen
#تعریف_کرو _tperror _wperror
#تعریف_کرو _tpopen _wpopen
#تعریف_کرو _ttempnam _wtempnam
#تعریف_کرو _ttmpnam _wtmpnam

#تعریف_کرو _taccess _waccess
#تعریف_کرو _tchmod _wchmod
#تعریف_کرو _tcreat _wcreat
#تعریف_کرو _tfindfirst _wfindfirst
#تعریف_کرو _tfindfirst32 _wfindfirst32
#تعریف_کرو _tfindfirst64 _wfindfirst64
#تعریف_کرو _tfindfirsti64 _wfindfirsti64
#تعریف_کرو _tfindfirst32i64 _wfindfirst32i64
#تعریف_کرو _tfindfirst64i32 _wfindfirst64i32
#تعریف_کرو _tfindnext _wfindnext
#تعریف_کرو _tfindnext32 _wfindnext32
#تعریف_کرو _tfindnext64 _wfindnext64
#تعریف_کرو _tfindnexti64 _wfindnexti64
#تعریف_کرو _tfindnext32i64 _wfindnext32i64
#تعریف_کرو _tfindnext64i32 _wfindnext64i32
#تعریف_کرو _tmktemp _wmktemp
#تعریف_کرو _topen _wopen
#تعریف_کرو _tremove _wremove
#تعریف_کرو _trename _wrename
#تعریف_کرو _tsopen _wsopen
#تعریف_کرو _tunlink _wunlink

#تعریف_کرو _tfinddata_t _wfinddata_t
#تعریف_کرو _tfinddata32_t _wfinddata32_t
#تعریف_کرو _tfinddata64_t _wfinddata64_t
#تعریف_کرو _tfinddatai64_t _wfinddatai64_t
#تعریف_کرو _tfinddata32i64_t _wfinddata32i64_t
#تعریف_کرو _tfinddata64i32_t _wfinddata64i32_t

#تعریف_کرو _tstat _wstat
#تعریف_کرو _tstat32 _wstat32
#تعریف_کرو _tstat32i64 _wstat32i64
#تعریف_کرو _tstat64 _wstat64
#تعریف_کرو _tstat64i32 _wstat64i32
#تعریف_کرو _tstati64 _wstati64

#تعریف_کرو _tsetlocale _wsetlocale

#تعریف_کرو _tcsclen wcslen
#تعریف_کرو _tcscnlen wcsnlen
#تعریف_کرو _tcsclen_l(_String,_Locale) wcslen(_String)
#تعریف_کرو _tcscnlen_l(_String,Max_گنتی_2,_Locale) wcsnlen_l((_String),(Max_گنتی_2))
#تعریف_کرو _tcsnccat wcsncat
#تعریف_کرو _tcsnccat_l _wcsncat_l
#تعریف_کرو _tcsnccpy wcsncpy
#تعریف_کرو _tcsnccpy_l _wcsncpy_l
#تعریف_کرو _tcsncset _wcsnset

#تعریف_کرو _tcsdec _wcsdec
#تعریف_کرو _tcsinc _wcsinc
#تعریف_کرو _tcsnbcnt _wcsncnt
#تعریف_کرو _tcsnccnt _wcsncnt
#تعریف_کرو _tcsnextc _wcsnextc
#تعریف_کرو _tcsninc _wcsninc
#تعریف_کرو _tcsspnp _wcsspnp

#تعریف_کرو _tcslwr _wcslwr
#تعریف_کرو _tcslwr_l _wcslwr_l
#تعریف_کرو _tcsupr _wcsupr
#تعریف_کرو _tcsupr_l _wcsupr_l
#تعریف_کرو _tcsxfrm wcsxfrm
#تعریف_کرو _tcsxfrm_l _wcsxfrm_l

#تعریف_کرو _tclen(_pc) (1)
#تعریف_کرو _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#تعریف_کرو _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#تعریف_کرو _istalnum iswalnum
#تعریف_کرو _istalnum_l _iswalnum_l
#تعریف_کرو _istalpha iswalpha
#تعریف_کرو _istalpha_l _iswalpha_l
#تعریف_کرو _istascii iswascii
#تعریف_کرو _istcntrl iswcntrl
#تعریف_کرو _istcntrl_l _iswcntrl_l
#تعریف_کرو _istdigit iswdigit
#تعریف_کرو _istdigit_l _iswdigit_l
#تعریف_کرو _istgraph iswgraph
#تعریف_کرو _istgraph_l _iswgraph_l
#تعریف_کرو _istlower iswlower
#تعریف_کرو _istlower_l _iswlower_l
#تعریف_کرو _istprint iswprint
#تعریف_کرو _istprint_l _iswprint_l
#تعریف_کرو _istpunct iswpunct
#تعریف_کرو _istpunct_l _iswpunct_l
#تعریف_کرو _istspace iswspace
#تعریف_کرو _istspace_l _iswspace_l
#تعریف_کرو _istupper iswupper
#تعریف_کرو _istupper_l _iswupper_l
#تعریف_کرو _istxdigit iswxdigit
#تعریف_کرو _istxdigit_l _iswxdigit_l

#تعریف_کرو _totupper towupper
#تعریف_کرو _totupper_l _towupper_l
#تعریف_کرو _totlower towlower
#تعریف_کرو _totlower_l _towlower_l

#تعریف_کرو _istlegal(_Char) (1)
#تعریف_کرو _istlead(_Char) (0)
#تعریف_کرو _istleadbyte(_Char) (0)
#تعریف_کرو _istleadbyte_l(_Char,_Locale) (0)

#تعریف_کرو _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? تہی : (_cpc2)-1)
#تعریف_کرو _wcsinc(_pc) ((_pc)+1)
#تعریف_کرو _wcsnextc(_cpc) ((غیرعلامتی صحیح) *(_cpc))
#تعریف_کرو _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP سائز_t __cdecl __wcsncnt(ثابت wchar_t *_Str,سائز_t Max_گنتی);
#تعریف_کرو _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#تعریف_کرو _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? تہی : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : تہی))
#تعریف_کرو _wcsncpy_l(_Destination,ماخذ_3,گنتی_5,_Locale) (wcsncpy(_Destination,ماخذ_3,گنتی_5))
#تعریف_کرو _wcsncat_l(_Destination,ماخذ_3,گنتی_5,_Locale) (wcsncat(_Destination,ماخذ_3,گنتی_5))
#تعریف_کرو _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#تعریف_کرو _wcsnset_l(_Destination,قدر_2,گنتی_5,_Locale) (_wcsnset(_Destination,قدر_2,گنتی_5))
#تعریف_کرو _wcsset_l(_Destination,قدر_2,_Locale) (_wcsset(_Destination,قدر_2))

  /* dirent structures and functions */
#تعریف_کرو _tdirent	_wdirent
#تعریف_کرو _TDIR 		_WDIR
#تعریف_کرو _topendir	_wopendir
#تعریف_کرو _tclosedir	_wclosedir
#تعریف_کرو _treaddir	_wreaddir
#تعریف_کرو _trewinddir	_wrewinddir
#تعریف_کرو _ttelldir	_wtelldir
#تعریف_کرو _tseekdir	_wseekdir

#ورنہ

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#شامل <string.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#تعریف_کرو _TEOF EOF

#تعریف_کرو __T(x) x

#تعریف_کرو _tmain مین
#تعریف_کرو _tWinMain WinMain
#اگر_تعریف_شدہ _POSIX_
#تعریف_کرو _tenviron environ
#ورنہ
#تعریف_کرو _tenviron _environ
#اگر_ختم
#تعریف_کرو __targv __argv

#تعریف_کرو _tprintf لکھو
#تعریف_کرو _tprintf_l _printf_l
#تعریف_کرو _tprintf_p _printf_p
#تعریف_کرو _tprintf_p_l _printf_p_l
#تعریف_کرو _tcprintf _cprintf
#تعریف_کرو _tcprintf_l _cprintf_l
#تعریف_کرو _tcprintf_p _cprintf_p
#تعریف_کرو _tcprintf_p_l _cprintf_p_l
#تعریف_کرو _vtcprintf _vcprintf
#تعریف_کرو _vtcprintf_l _vcprintf_l
#تعریف_کرو _vtcprintf_p _vcprintf_p
#تعریف_کرو _vtcprintf_p_l _vcprintf_p_l
#تعریف_کرو _ftprintf fprintf
#تعریف_کرو _ftprintf_l _fprintf_l
#تعریف_کرو _ftprintf_p _fprintf_p
#تعریف_کرو _ftprintf_p_l _fprintf_p_l
#تعریف_کرو _stprintf sprintf
#تعریف_کرو _stprintf_l _sprintf_l
#تعریف_کرو _stprintf_p _sprintf_p
#تعریف_کرو _stprintf_p_l _sprintf_p_l
#تعریف_کرو _sctprintf _scprintf
#تعریف_کرو _sctprintf_l _scprintf_l
#تعریف_کرو _sctprintf_p _scprintf_p
#تعریف_کرو _sctprintf_p_l _scprintf_p_l
#تعریف_کرو _sntprintf _snprintf
#تعریف_کرو _sntprintf_l _snprintf_l
#تعریف_کرو _vtprintf vprintf
#تعریف_کرو _vtprintf_l _vprintf_l
#تعریف_کرو _vtprintf_p _vprintf_p
#تعریف_کرو _vtprintf_p_l _vprintf_p_l
#تعریف_کرو _vftprintf vfprintf
#تعریف_کرو _vftprintf_l _vfprintf_l
#تعریف_کرو _vftprintf_p _vfprintf_p
#تعریف_کرو _vftprintf_p_l _vfprintf_p_l
#تعریف_کرو _vstprintf vsprintf
#تعریف_کرو _vstprintf_l _vsprintf_l
#تعریف_کرو _vstprintf_p _vsprintf_p
#تعریف_کرو _vstprintf_p_l _vsprintf_p_l
#تعریف_کرو _vsctprintf _vscprintf
#تعریف_کرو _vsctprintf_l _vscprintf_l
#تعریف_کرو _vsctprintf_p _vscprintf_p
#تعریف_کرو _vsctprintf_p_l _vscprintf_p_l
#تعریف_کرو _vsntprintf _vsnprintf
#تعریف_کرو _vsntprintf_l _vsnprintf_l

#تعریف_کرو _tscanf scanf
#تعریف_کرو _tscanf_l _scanf_l
#تعریف_کرو _tcscanf _cscanf
#تعریف_کرو _tcscanf_l _cscanf_l
#تعریف_کرو _ftscanf fscanf
#تعریف_کرو _ftscanf_l _fscanf_l
#تعریف_کرو _stscanf لڑی_سے_پڑھو
#تعریف_کرو _stscanf_l _sscanf_l
#تعریف_کرو _sntscanf _snscanf
#تعریف_کرو _sntscanf_l _snscanf_l

#تعریف_کرو _fgettc fgetc
#تعریف_کرو _fgettc_nolock _fgetc_nolock
#تعریف_کرو _fgettchar _fgetchar
#تعریف_کرو _fgetts fgets
#تعریف_کرو _fputtc fputc
#تعریف_کرو _fputtc_nolock _fputc_nolock
#تعریف_کرو _fputtchar _fputchar
#تعریف_کرو _fputts fputs
#تعریف_کرو _cputts _cputs
#تعریف_کرو _gettc getc
#تعریف_کرو _gettc_nolock _getc_nolock
#تعریف_کرو _gettch _getch
#تعریف_کرو _gettch_nolock _getch_nolock
#تعریف_کرو _gettche _getche
#تعریف_کرو _gettche_nolock _getche_nolock
#تعریف_کرو _gettchar getchar
#تعریف_کرو _gettchar_nolock _getchar_nolock
#تعریف_کرو _getts gets
#تعریف_کرو _cgetts _cgets
#تعریف_کرو _puttc putc
#تعریف_کرو _puttc_nolock _putc_nolock
#تعریف_کرو _puttchar حرف_لکھو
#تعریف_کرو _puttchar_nolock _putchar_nolock
#تعریف_کرو _puttch _putch
#تعریف_کرو _puttch_nolock _putch_nolock
#تعریف_کرو _putts puts
#تعریف_کرو _ungettc ungetc
#تعریف_کرو _ungettc_nolock _ungetc_nolock
#تعریف_کرو _ungettch _ungetch
#تعریف_کرو _ungettch_nolock _ungetch_nolock

#تعریف_کرو _tcstod strtod
#تعریف_کرو _tcstol strtol
#تعریف_کرو _tcstoul strtoul
#تعریف_کرو _tstof atof
#تعریف_کرو _tstol atol
#تعریف_کرو _tstoi atoi
#تعریف_کرو _tstoi64 _atoi64
#تعریف_کرو _tcstod_l _strtod_l
#تعریف_کرو _tcstol_l _strtol_l
#تعریف_کرو _tcstoul_l _strtoul_l
#تعریف_کرو _tstof_l _atof_l
#تعریف_کرو _tstol_l _atol_l
#تعریف_کرو _tstoi_l _atoi_l
#تعریف_کرو _tstoi64_l _atoi64_l

#تعریف_کرو _itot _itoa
#تعریف_کرو _ltot _ltoa
#تعریف_کرو _ultot _ultoa
#تعریف_کرو _ttoi atoi
#تعریف_کرو _ttol atol

#تعریف_کرو _ttoi64 _atoi64
#تعریف_کرو _tcstoi64 _strtoi64
#تعریف_کرو _tcstoi64_l _strtoi64_l
#تعریف_کرو _tcstoui64 _strtoui64
#تعریف_کرو _tcstoui64_l _strtoui64_l
#تعریف_کرو _i64tot _i64toa
#تعریف_کرو _ui64tot _ui64toa

#تعریف_کرو _tcscat strcat
#تعریف_کرو _tcscpy strcpy
#تعریف_کرو _tcsdup _strdup
#تعریف_کرو _tcslen لڑی_لمبائی
#اگر 0
#تعریف_کرو _tcsnlen strnlen
#اگر_ختم
#تعریف_کرو _tcsxfrm strxfrm
#تعریف_کرو _tcsxfrm_l _strxfrm_l
#تعریف_کرو _tcserror strerror
#تعریف_کرو __tcserror _strerror

#تعریف_کرو _texecl _execl
#تعریف_کرو _texecle _execle
#تعریف_کرو _texeclp _execlp
#تعریف_کرو _texeclpe _execlpe
#تعریف_کرو _texecv _execv
#تعریف_کرو _texecve _execve
#تعریف_کرو _texecvp _execvp
#تعریف_کرو _texecvpe _execvpe

#تعریف_کرو _tspawnl _spawnl
#تعریف_کرو _tspawnle _spawnle
#تعریف_کرو _tspawnlp _spawnlp
#تعریف_کرو _tspawnlpe _spawnlpe
#تعریف_کرو _tspawnv _spawnv
#تعریف_کرو _tspawnve _spawnve
#تعریف_کرو _tspawnvp _spawnvp
#تعریف_کرو _tspawnvpe _spawnvpe

#تعریف_کرو _tsystem system

#تعریف_کرو _tasctime asctime
#تعریف_کرو _tctime ctime
#تعریف_کرو _tctime32 _ctime32
#تعریف_کرو _tctime64 _ctime64
#تعریف_کرو _tstrdate _strdate
#تعریف_کرو _tstrtime _strtime
#تعریف_کرو _tutime _utime
#تعریف_کرو _tutime32 _utime32
#تعریف_کرو _tutime64 _utime64
#تعریف_کرو _tcsftime strftime
#تعریف_کرو _tcsftime_l _strftime_l

#تعریف_کرو _tchdir _chdir
#تعریف_کرو _tgetcwd _getcwd
#تعریف_کرو _tgetdcwd _getdcwd
#تعریف_کرو _tgetdcwd_nolock _getdcwd_nolock
#تعریف_کرو _tmkdir _mkdir
#تعریف_کرو _trmdir _rmdir

#تعریف_کرو _tfullpath _fullpath
#تعریف_کرو _tgetenv getenv
#تعریف_کرو _tmakepath _makepath
#تعریف_کرو _tpgmptr _pgmptr
#تعریف_کرو _get_tpgmptr _get_pgmptr
#تعریف_کرو _tputenv _putenv
#تعریف_کرو _tsearchenv _searchenv
#تعریف_کرو _tsplitpath _splitpath

#اگر_تعریف_شدہ _POSIX_
#تعریف_کرو _tfdopen fdopen
#ورنہ
#تعریف_کرو _tfdopen _fdopen
#اگر_ختم
#تعریف_کرو _tfsopen _fsopen
#تعریف_کرو _tfopen fopen
#تعریف_کرو _tfreopen freopen
#تعریف_کرو _tperror perror
#تعریف_کرو _tpopen _popen
#تعریف_کرو _ttempnam _tempnam
#تعریف_کرو _ttmpnam tmpnam

#تعریف_کرو _tchmod _chmod
#تعریف_کرو _tcreat _creat
#تعریف_کرو _tfindfirst _findfirst
#تعریف_کرو _tfindfirst32 _findfirst32
#تعریف_کرو _tfindfirst64 _findfirst64
#تعریف_کرو _tfindfirsti64 _findfirsti64
#تعریف_کرو _tfindfirst32i64 _findfirst32i64
#تعریف_کرو _tfindfirst64i32 _findfirst64i32
#تعریف_کرو _tfindnext _findnext
#تعریف_کرو _tfindnext32 _findnext32
#تعریف_کرو _tfindnext64 _findnext64
#تعریف_کرو _tfindnexti64 _findnexti64
#تعریف_کرو _tfindnext32i64 _findnext32i64
#تعریف_کرو _tfindnext64i32 _findnext64i32
#تعریف_کرو _tmktemp _mktemp

#اگر_تعریف_شدہ _POSIX_
#تعریف_کرو _topen open
#تعریف_کرو _taccess access
#ورنہ
#تعریف_کرو _topen _open
#تعریف_کرو _taccess _access
#اگر_ختم

#تعریف_کرو _tremove remove
#تعریف_کرو _trename rename
#تعریف_کرو _tsopen _sopen
#تعریف_کرو _tunlink _unlink

#تعریف_کرو _tfinddata_t _finddata_t
#تعریف_کرو _tfinddata32_t _finddata32_t
#تعریف_کرو _tfinddata64_t __finddata64_t
#تعریف_کرو _tfinddatai64_t _finddatai64_t
#تعریف_کرو _tfinddata32i64_t _finddata32i64_t
#تعریف_کرو _tfinddata64i32_t _finddata64i32_t

#تعریف_کرو _istascii __isascii
#تعریف_کرو _istcntrl iscntrl
#تعریف_کرو _istcntrl_l _iscntrl_l
#تعریف_کرو _istxdigit isxdigit
#تعریف_کرو _istxdigit_l _isxdigit_l

#تعریف_کرو _tstat _stat
#تعریف_کرو _tstat32 _stat32
#تعریف_کرو _tstat32i64 _stat32i64
#تعریف_کرو _tstat64 _stat64
#تعریف_کرو _tstat64i32 _stat64i32
#تعریف_کرو _tstati64 _stati64

#تعریف_کرو _tsetlocale setlocale

#اگر_تعریف_شدہ _MBCS

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#شامل <mbstring.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ __TCHAR_DEFINED
  قسمتعریف حرف _TCHAR;
  قسمتعریف علامتی حرف _TSCHAR;
  قسمتعریف غیرعلامتی حرف _TUCHAR;
  قسمتعریف غیرعلامتی حرف _TXCHAR;
  قسمتعریف غیرعلامتی صحیح _TINT;
#تعریف_کرو __TCHAR_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TCHAR_DEFINED
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  قسمتعریف حرف TCHAR;
#اگر_ختم
#تعریف_کرو _TCHAR_DEFINED
#اگر_ختم

#اگر_تعریف_شدہ MB_MAP_براہ_راست

#تعریف_کرو _tcschr _mbschr
#تعریف_کرو _tcscspn _mbscspn
#تعریف_کرو _tcsncat _mbsnbcat
#تعریف_کرو _tcsncat_l _mbsnbcat_l
#تعریف_کرو _tcsncpy _mbsnbcpy
#تعریف_کرو _tcsncpy_l _mbsnbcpy_l
#تعریف_کرو _tcspbrk _mbspbrk
#تعریف_کرو _tcsrchr _mbsrchr
#تعریف_کرو _tcsspn _mbsspn
#تعریف_کرو _tcsstr _mbsstr
#تعریف_کرو _tcstok _mbstok
#تعریف_کرو _tcstok_l _mbstok_l

#تعریف_کرو _tcsnset _mbsnbset
#تعریف_کرو _tcsnset_l _mbsnbset_l
#تعریف_کرو _tcsrev _mbsrev
#تعریف_کرو _tcsset _mbsset
#تعریف_کرو _tcsset_l _mbsset_l

#تعریف_کرو _tcscmp _mbscmp
#تعریف_کرو _tcsicmp _mbsicmp
#تعریف_کرو _tcsicmp_l _mbsicmp_l
#تعریف_کرو _tcsnccmp _mbsncmp
#تعریف_کرو _tcsncmp _mbsnbcmp
#تعریف_کرو _tcsncicmp _mbsnicmp
#تعریف_کرو _tcsncicmp_l _mbsnicmp_l
#تعریف_کرو _tcsnicmp _mbsnbicmp
#تعریف_کرو _tcsnicmp_l _mbsnbicmp_l

#تعریف_کرو _tcscoll _mbscoll
#تعریف_کرو _tcscoll_l _mbscoll_l
#تعریف_کرو _tcsicoll _mbsicoll
#تعریف_کرو _tcsicoll_l _mbsicoll_l
#تعریف_کرو _tcsnccoll _mbsncoll
#تعریف_کرو _tcsnccoll_l _mbsncoll_l
#تعریف_کرو _tcsncoll _mbsnbcoll
#تعریف_کرو _tcsncoll_l _mbsnbcoll_l
#تعریف_کرو _tcsncicoll _mbsnicoll
#تعریف_کرو _tcsncicoll_l _mbsnicoll_l
#تعریف_کرو _tcsnicoll _mbsnbicoll
#تعریف_کرو _tcsnicoll_l _mbsnbicoll_l

#تعریف_کرو _tcsclen _mbslen
#تعریف_کرو _tcscnlen _mbsnlen
#تعریف_کرو _tcsclen_l _mbslen_l
#تعریف_کرو _tcscnlen_l _mbsnlen_l
#تعریف_کرو _tcsnccat _mbsncat
#تعریف_کرو _tcsnccat_l _mbsncat_l
#تعریف_کرو _tcsnccpy _mbsncpy
#تعریف_کرو _tcsnccpy_l _mbsncpy_l
#تعریف_کرو _tcsncset _mbsnset
#تعریف_کرو _tcsncset_l _mbsnset_l

#تعریف_کرو _tcsdec _mbsdec
#تعریف_کرو _tcsinc _mbsinc
#تعریف_کرو _tcsnbcnt _mbsnbcnt
#تعریف_کرو _tcsnccnt _mbsnccnt
#تعریف_کرو _tcsnextc _mbsnextc
#تعریف_کرو _tcsninc _mbsninc
#تعریف_کرو _tcsspnp _mbsspnp

#تعریف_کرو _tcslwr _mbslwr
#تعریف_کرو _tcslwr_l _mbslwr_l
#تعریف_کرو _tcsupr _mbsupr
#تعریف_کرو _tcsupr_l _mbsupr_l

#تعریف_کرو _tclen _mbclen
#تعریف_کرو _tccpy _mbccpy
#تعریف_کرو _tccpy_l _mbccpy_l
#ورنہ

  _CRTIMP _CONST_RETURN حرف *__cdecl _tcschr(ثابت حرف *_Str,غیرعلامتی صحیح _Val);
  _CRTIMP سائز_t __cdecl _tcscspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP حرف *__cdecl _tcsncat(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsncat_l(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncpy(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsncpy_l(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcspbrk(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsrchr(ثابت حرف *_Str,غیرعلامتی صحیح _Ch);
  _CRTIMP سائز_t __cdecl _tcsspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP _CONST_RETURN حرف *__cdecl _tcsstr(ثابت حرف *_Str,ثابت حرف *_Substr);
  _CRTIMP حرف *__cdecl _tcstok(حرف *_Str,ثابت حرف *_Delim);
  _CRTIMP حرف *__cdecl _tcstok_l(حرف *_Str,ثابت حرف *_Delim,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnset(حرف *_Str,غیرعلامتی صحیح _Val,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsrev(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsset(حرف *_Str,غیرعلامتی صحیح _Val);
  _CRTIMP حرف *__cdecl _tcsset_l(حرف *_Str,غیرعلامتی صحیح _Val,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcscmp(ثابت حرف *_Str1,ثابت حرف *_Str);
  _CRTIMP صحیح __cdecl _tcsicmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحیح __cdecl _tcsicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcsnccmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsncmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsncicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsncicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcsnicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsnicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcscoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحیح __cdecl _tcscoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcsicoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحیح __cdecl _tcsicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcsnccoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsnccoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcsncoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsncoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcsncicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsncicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _tcsnicoll(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _tcsnicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP سائز_t __cdecl _tcsclen(ثابت حرف *_Str);
  _CRTIMP سائز_t __cdecl _tcscnlen(ثابت حرف *_Str,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _tcsclen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP سائز_t __cdecl _tcscnlen_l(ثابت حرف *_Str,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccat(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsnccat_l(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsnccpy(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsnccpy_l(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsncset(حرف *_Str,غیرعلامتی صحیح _Val,سائز_t Max_گنتی);
  _CRTIMP حرف *__cdecl _tcsdec(ثابت حرف *آغاز_4,ثابت حرف *_Pos);
  _CRTIMP حرف *__cdecl _tcsinc(ثابت حرف *_Ptr);
  _CRTIMP سائز_t __cdecl _tcsnbcnt(ثابت حرف *_Str,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _tcsnccnt(ثابت حرف *_Str,سائز_t Max_گنتی);
  _CRTIMP غیرعلامتی صحیح __cdecl _tcsnextc (ثابت حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsninc(ثابت حرف *_Ptr,سائز_t گنتی_5);
  _CRTIMP حرف *__cdecl _tcsspnp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP حرف *__cdecl _tcslwr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcslwr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP حرف *__cdecl _tcsupr(حرف *_Str);
  _CRTIMP حرف *__cdecl _tcsupr_l(حرف *_Str,_locale_t _Locale);
  _CRTIMP سائز_t __cdecl _tclen(ثابت حرف *_Str);
  _CRTIMP خالی __cdecl _tccpy(حرف *_DstCh,ثابت حرف *_SrcCh);

#اگر_تعریف_شدہ __cplusplus
#اگر_غیر_تعریف_شدہ _CPP_TCHAR_INLINES_DEFINED
#تعریف_کرو _CPP_TCHAR_INLINES_DEFINED
  خارجی "C++" {
    خارجی اندرونی حرف *__cdecl _tcschr(حرف *_S,غیرعلامتی صحیح _C) { واپس ((حرف *)_tcschr((ثابت حرف *)_S,_C)); }
    خارجی اندرونی حرف *__cdecl _tcspbrk(حرف *_S,ثابت حرف *_P) { واپس ((حرف *)_tcspbrk((ثابت حرف *)_S,_P)); }
    خارجی اندرونی حرف *__cdecl _tcsrchr(حرف *_S,غیرعلامتی صحیح _C) { واپس ((حرف *)_tcsrchr((ثابت حرف *)_S,_C)); }
    خارجی اندرونی حرف *__cdecl _tcsstr(حرف *_S,ثابت حرف *_P) { واپس ((حرف *)_tcsstr((ثابت حرف *)_S,_P)); }
  }
#اگر_ختم
#اگر_ختم
#اگر_ختم

#تعریف_کرو _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#تعریف_کرو _istalnum _ismbcalnum
#تعریف_کرو _istalnum_l _ismbcalnum_l
#تعریف_کرو _istalpha _ismbcalpha
#تعریف_کرو _istalpha_l _ismbcalpha_l
#تعریف_کرو _istdigit _ismbcdigit
#تعریف_کرو _istdigit_l _ismbcdigit_l
#تعریف_کرو _istgraph _ismbcgraph
#تعریف_کرو _istgraph_l _ismbcgraph_l
#تعریف_کرو _istlegal _ismbclegal
#تعریف_کرو _istlegal_l _ismbclegal_l
#تعریف_کرو _istlower _ismbclower
#تعریف_کرو _istlower_l _ismbclower_l
#تعریف_کرو _istprint _ismbcprint
#تعریف_کرو _istprint_l _ismbcprint_l
#تعریف_کرو _istpunct _ismbcpunct
#تعریف_کرو _istpunct_l _ismbcpunct_l
#تعریف_کرو _istspace _ismbcspace
#تعریف_کرو _istspace_l _ismbcspace_l
#تعریف_کرو _istupper _ismbcupper
#تعریف_کرو _istupper_l _ismbcupper_l

#تعریف_کرو _totupper _mbctoupper
#تعریف_کرو _totupper_l _mbctoupper_l
#تعریف_کرو _totlower _mbctolower
#تعریف_کرو _totlower_l _mbctolower_l

#تعریف_کرو _istlead _ismbblead
#تعریف_کرو _istleadbyte isleadbyte
#تعریف_کرو _istleadbyte_l _isleadbyte_l
#ورنہ

#اگر_غیر_تعریف_شدہ __TCHAR_DEFINED
#تعریف_کرو __TCHAR_DEFINED
  قسمتعریف حرف _TCHAR;
  قسمتعریف علامتی حرف _TSCHAR;
  قسمتعریف غیرعلامتی حرف _TUCHAR;
  قسمتعریف حرف _TXCHAR;
  قسمتعریف صحیح _TINT;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TCHAR_DEFINED
#تعریف_کرو _TCHAR_DEFINED
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  قسمتعریف حرف TCHAR;
#اگر_ختم
#اگر_ختم

#تعریف_کرو _tcschr strchr
#تعریف_کرو _tcscspn strcspn
#تعریف_کرو _tcsncat strncat
#تعریف_کرو _tcsncat_l _strncat_l
#تعریف_کرو _tcsncpy strncpy
#تعریف_کرو _tcsncpy_l _strncpy_l
#تعریف_کرو _tcspbrk strpbrk
#تعریف_کرو _tcsrchr strrchr
#تعریف_کرو _tcsspn strspn
#تعریف_کرو _tcsstr لڑی_تلاش
#تعریف_کرو _tcstok strtok
#تعریف_کرو _tcstok_l _strtok_l

#تعریف_کرو _tcsnset _strnset
#تعریف_کرو _tcsnset_l _strnset_l
#تعریف_کرو _tcsrev _strrev
#تعریف_کرو _tcsset _strset

#تعریف_کرو _tcscmp strcmp
#تعریف_کرو _tcsicmp _stricmp
#تعریف_کرو _tcsicmp_l _stricmp_l
#تعریف_کرو _tcsnccmp لڑی_موازنہ
#تعریف_کرو _tcsncmp لڑی_موازنہ
#تعریف_کرو _tcsncicmp _strnicmp
#تعریف_کرو _tcsncicmp_l _strnicmp_l
#تعریف_کرو _tcsnicmp _strnicmp
#تعریف_کرو _tcsnicmp_l _strnicmp_l

#تعریف_کرو _tcscoll strcoll
#تعریف_کرو _tcscoll_l _strcoll_l
#تعریف_کرو _tcsicoll _stricoll
#تعریف_کرو _tcsicoll_l _stricoll_l
#تعریف_کرو _tcsnccoll _strncoll
#تعریف_کرو _tcsnccoll_l _strncoll_l
#تعریف_کرو _tcsncoll _strncoll
#تعریف_کرو _tcsncoll_l _strncoll_l
#تعریف_کرو _tcsncicoll _strnicoll
#تعریف_کرو _tcsncicoll_l _strnicoll_l
#تعریف_کرو _tcsnicoll _strnicoll
#تعریف_کرو _tcsnicoll_l _strnicoll_l

#تعریف_کرو _tcsclen لڑی_لمبائی
#تعریف_کرو _tcscnlen strnlen
#تعریف_کرو _tcsclen_l(_String,_Locale) لڑی_لمبائی(_String)
#تعریف_کرو _tcscnlen_l(_String,Max_گنتی_2,_Locale) strnlen_l((_String),(Max_گنتی_2))
#تعریف_کرو _tcsnccat strncat
#تعریف_کرو _tcsnccat_l _strncat_l
#تعریف_کرو _tcsnccpy strncpy
#تعریف_کرو _tcsnccpy_l _strncpy_l
#تعریف_کرو _tcsncset _strnset

#تعریف_کرو _tcsdec _strdec
#تعریف_کرو _tcsinc _strinc
#تعریف_کرو _tcsnbcnt _strncnt
#تعریف_کرو _tcsnccnt _strncnt
#تعریف_کرو _tcsnextc _strnextc
#تعریف_کرو _tcsninc _strninc
#تعریف_کرو _tcsspnp _strspnp

#تعریف_کرو _tcslwr _strlwr
#تعریف_کرو _tcslwr_l _strlwr_l
#تعریف_کرو _tcsupr _strupr
#تعریف_کرو _tcsupr_l _strupr_l
#تعریف_کرو _tcsxfrm strxfrm
#تعریف_کرو _tcsxfrm_l _strxfrm_l

#تعریف_کرو _istlead(_Char) (0)
#تعریف_کرو _istleadbyte(_Char) (0)
#تعریف_کرو _istleadbyte_l(_Char,_Locale) (0)

#تعریف_کرو _tclen(_pc) (1)
#تعریف_کرو _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#تعریف_کرو _tccmp(_cpc1,_cpc2) (((غیرعلامتی حرف)*(_cpc1))-((غیرعلامتی حرف)*(_cpc2)))

  /* dirent structures and functions */
#تعریف_کرو _tdirent	dirent
#تعریف_کرو _TDIR 		DIR
#تعریف_کرو _topendir	opendir
#تعریف_کرو _tclosedir	closedir
#تعریف_کرو _treaddir	readdir
#تعریف_کرو _trewinddir	rewinddir
#تعریف_کرو _ttelldir	telldir
#تعریف_کرو _tseekdir	seekdir

#تعریف_کرو _istalnum حرف_یا_ہندسہ
#تعریف_کرو _istalnum_l _isalnum_l
#تعریف_کرو _istalpha حرف_ہے
#تعریف_کرو _istalpha_l _isalpha_l
#تعریف_کرو _istdigit ہندسہ_ہے
#تعریف_کرو _istdigit_l _isdigit_l
#تعریف_کرو _istgraph isgraph
#تعریف_کرو _istgraph_l _isgraph_l
#تعریف_کرو _istlower islower
#تعریف_کرو _istlower_l _islower_l
#تعریف_کرو _istprint isprint
#تعریف_کرو _istprint_l _isprint_l
#تعریف_کرو _istpunct ispunct
#تعریف_کرو _istpunct_l _ispunct_l
#تعریف_کرو _istspace خلا_ہے
#تعریف_کرو _istspace_l _isspace_l
#تعریف_کرو _istupper isupper
#تعریف_کرو _istupper_l _isupper_l

#تعریف_کرو _totupper بڑا_حرف
#تعریف_کرو _totupper_l _toupper_l
#تعریف_کرو _totlower tolower
#تعریف_کرو _totlower_l _tolower_l

#تعریف_کرو _istlegal(_c) (1)

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#تعریف_کرو _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? تہی : (_cpc2)-1)
#تعریف_کرو _strinc(_pc) ((_pc)+1)
#تعریف_کرو _strnextc(_cpc) ((غیرعلامتی صحیح) *(ثابت غیرعلامتی حرف *)(_cpc))
#تعریف_کرو _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP سائز_t __cdecl __strncnt(ثابت حرف *_Str,سائز_t _Cnt);
#تعریف_کرو _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#تعریف_کرو _strspnp(_cpc1,_cpc2) (!_cpc1 ? تہی : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : تہی))

#تعریف_کرو _strncpy_l(_Destination,ماخذ_3,گنتی_5,_Locale) (strncpy(_Destination,ماخذ_3,گنتی_5))
#تعریف_کرو _strncat_l(_Destination,ماخذ_3,گنتی_5,_Locale) (strncat(_Destination,ماخذ_3,گنتی_5))
#تعریف_کرو _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#تعریف_کرو _strnset_l(_Destination,قدر_2,گنتی_5,_Locale) (_strnset(_Destination,قدر_2,گنتی_5))
#تعریف_کرو _strset_l(_Destination,قدر_2,_Locale) (_strset(_Destination,قدر_2))
#اگر_ختم
#اگر_ختم

#تعریف_کرو _T(x) __T(x)
#تعریف_کرو متن_2(x) __T(x)

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#شامل <sec_api/tchar_s.h>
#اگر_ختم
