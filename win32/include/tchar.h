/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#समावेश <_mingw.h>

#अगर_अघोषित _INC_TCHAR
#घोषणा _INC_TCHAR

#अगर_घोषित _STRSAFE_H_INCLUDED_
#त्रुटि Need to include strsafe.h after tchar.h
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#घोषणा _ftcscat _tcscat
#घोषणा _ftcschr _tcschr
#घोषणा _ftcscpy _tcscpy
#घोषणा _ftcscspn _tcscspn
#घोषणा _ftcslen _tcslen
#घोषणा _ftcsncat _tcsncat
#घोषणा _ftcsncpy _tcsncpy
#घोषणा _ftcspbrk _tcspbrk
#घोषणा _ftcsrchr _tcsrchr
#घोषणा _ftcsspn _tcsspn
#घोषणा _ftcsstr _tcsstr
#घोषणा _ftcstok _tcstok

#घोषणा _ftcsdup _tcsdup
#घोषणा _ftcsnset _tcsnset
#घोषणा _ftcsrev _tcsrev
#घोषणा _ftcsset _tcsset

#घोषणा _ftcscmp _tcscmp
#घोषणा _ftcsicmp _tcsicmp
#घोषणा _ftcsnccmp _tcsnccmp
#घोषणा _ftcsncmp _tcsncmp
#घोषणा _ftcsncicmp _tcsncicmp
#घोषणा _ftcsnicmp _tcsnicmp

#घोषणा _ftcscoll _tcscoll
#घोषणा _ftcsicoll _tcsicoll
#घोषणा _ftcsnccoll _tcsnccoll
#घोषणा _ftcsncoll _tcsncoll
#घोषणा _ftcsncicoll _tcsncicoll
#घोषणा _ftcsnicoll _tcsnicoll

#घोषणा _ftcsclen _tcsclen
#घोषणा _ftcsnccat _tcsnccat
#घोषणा _ftcsnccpy _tcsnccpy
#घोषणा _ftcsncset _tcsncset

#घोषणा _ftcsdec _tcsdec
#घोषणा _ftcsinc _tcsinc
#घोषणा _ftcsnbcnt _tcsnbcnt
#घोषणा _ftcsnccnt _tcsnccnt
#घोषणा _ftcsnextc _tcsnextc
#घोषणा _ftcsninc _tcsninc
#घोषणा _ftcsspnp _tcsspnp

#घोषणा _ftcslwr _tcslwr
#घोषणा _ftcsupr _tcsupr

#घोषणा _ftclen _tclen
#घोषणा _ftccpy _tccpy
#घोषणा _ftccmp _tccmp

#अगर_अघोषित _CONST_RETURN
#अगर_घोषित __cplusplus
#घोषणा _CONST_RETURN स्थिर
#घोषणा _CRT_CONST_CORRECT_OVERLOADS
#अन्यथा
#घोषणा _CONST_RETURN
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _WConst_return _CONST_RETURN

#अगर_घोषित _UNICODE

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#समावेश <wchar.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _WCTYPE_T_DEFINED
#घोषणा _WCTYPE_T_DEFINED
  प्रकार अचिन्हित लघु wint_t;
  प्रकार अचिन्हित लघु wctype_t;
#पूर्ण_अगर

#अगर_अघोषित __TCHAR_DEFINED
#घोषणा __TCHAR_DEFINED
  प्रकार ब_अक्षर_प्रकार _TCHAR;
  प्रकार ब_अक्षर_प्रकार _TSCHAR;
  प्रकार ब_अक्षर_प्रकार _TUCHAR;
  प्रकार ब_अक्षर_प्रकार _TXCHAR;
  प्रकार wint_t _TINT;
#पूर्ण_अगर

#अगर_अघोषित _TCHAR_DEFINED
#घोषणा _TCHAR_DEFINED
#अगर_अघोषित	NO_OLDNAMES
  प्रकार ब_अक्षर_प्रकार TCHAR;
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _TEOF WEOF

#घोषणा __T(x) L##x

#घोषणा _tmain wmain
#घोषणा _tWinMain wWinMain
#घोषणा _tenviron _wenviron
#घोषणा __targv __wargv

#घोषणा _tprintf wprintf
#घोषणा _tprintf_l _wprintf_l
#घोषणा _tprintf_p _wprintf_p
#घोषणा _tprintf_p_l _wprintf_p_l
#घोषणा _tcprintf _cwprintf
#घोषणा _tcprintf_l _cwprintf_l
#घोषणा _tcprintf_p _cwprintf_p
#घोषणा _tcprintf_p_l _cwprintf_p_l
#घोषणा _vtcprintf _vcwprintf
#घोषणा _vtcprintf_l _vcwprintf_l
#घोषणा _vtcprintf_p _vcwprintf_p
#घोषणा _vtcprintf_p_l _vcwprintf_p_l
#घोषणा _ftprintf fwprintf
#घोषणा _ftprintf_l _fwprintf_l
#घोषणा _ftprintf_p _fwprintf_p
#घोषणा _ftprintf_p_l _fwprintf_p_l
#घोषणा _stprintf swprintf
#घोषणा _stprintf_l __swprintf_l
#घोषणा _stprintf_p _swprintf_p
#घोषणा _stprintf_p_l _swprintf_p_l
#घोषणा _sctprintf _scwprintf
#घोषणा _sctprintf_l _scwprintf_l
#घोषणा _sctprintf_p _scwprintf_p
#घोषणा _sctprintf_p_l _scwprintf_p_l
#घोषणा _sntprintf _snwprintf
#घोषणा _sntprintf_l _snwprintf_l
#घोषणा _vtprintf vwprintf
#घोषणा _vtprintf_l _vwprintf_l
#घोषणा _vtprintf_p _vwprintf_p
#घोषणा _vtprintf_p_l _vwprintf_p_l
#घोषणा _vftprintf vfwprintf
#घोषणा _vftprintf_l _vfwprintf_l
#घोषणा _vftprintf_p _vfwprintf_p
#घोषणा _vftprintf_p_l _vfwprintf_p_l
#घोषणा _vstprintf vswprintf
#घोषणा _vstprintf_l _vswprintf_l
#घोषणा _vstprintf_p _vswprintf_p
#घोषणा _vstprintf_p_l _vswprintf_p_l
#घोषणा _vsctprintf _vscwprintf
#घोषणा _vsctprintf_l _vscwprintf_l
#घोषणा _vsctprintf_p _vscwprintf_p
#घोषणा _vsctprintf_p_l _vscwprintf_p_l
#घोषणा _vsntprintf _vsnwprintf
#घोषणा _vsntprintf_l _vsnwprintf_l

#घोषणा _tscanf wscanf
#घोषणा _tscanf_l _wscanf_l
#घोषणा _tcscanf _cwscanf
#घोषणा _tcscanf_l _cwscanf_l
#घोषणा _ftscanf fwscanf
#घोषणा _ftscanf_l _fwscanf_l
#घोषणा _stscanf swscanf
#घोषणा _stscanf_l _swscanf_l
#घोषणा _sntscanf _snwscanf
#घोषणा _sntscanf_l _snwscanf_l

#घोषणा _fgettc fgetwc
#घोषणा _fgettc_nolock _fgetwc_nolock
#घोषणा _fgettchar _fgetwchar
#घोषणा _fgetts fgetws
#घोषणा _fputtc fputwc
#घोषणा _fputtc_nolock _fputwc_nolock
#घोषणा _fputtchar _fputwchar
#घोषणा _fputts fputws
#घोषणा _cputts _cputws
#घोषणा _cgetts _cgetws
#घोषणा _gettc getwc
#घोषणा _gettc_nolock _getwc_nolock
#घोषणा _gettch _getwch
#घोषणा _gettch_nolock _getwch_nolock
#घोषणा _gettche _getwche
#घोषणा _gettche_nolock _getwche_nolock
#घोषणा _gettchar getwchar
#घोषणा _gettchar_nolock _getwchar_nolock
#घोषणा _getts _getws
#घोषणा _puttc putwc
#घोषणा _puttc_nolock _putwc_nolock
#घोषणा _puttchar putwchar
#घोषणा _puttchar_nolock _putwchar_nolock
#घोषणा _puttch _putwch
#घोषणा _puttch_nolock _putwch_nolock
#घोषणा _putts _putws
#घोषणा _ungettc ungetwc
#घोषणा _ungettc_nolock _ungetwc_nolock
#घोषणा _ungettch _ungetwch
#घोषणा _ungettch_nolock _ungetwch_nolock

#घोषणा _tcstod wcstod
#घोषणा _tcstol wcstol
#घोषणा _tcstoul wcstoul
#घोषणा _tcstoi64 _wcstoi64
#घोषणा _tcstoui64 _wcstoui64
#घोषणा _tstof _wtof
#घोषणा _tstol _wtol
#घोषणा _tstoi _wtoi
#घोषणा _tstoi64 _wtoi64
#घोषणा _tcstod_l _wcstod_l
#घोषणा _tcstol_l _wcstol_l
#घोषणा _tcstoul_l _wcstoul_l
#घोषणा _tcstoi64_l _wcstoi64_l
#घोषणा _tcstoui64_l _wcstoui64_l
#घोषणा _tstof_l _wtof_l
#घोषणा _tstol_l _wtol_l
#घोषणा _tstoi_l _wtoi_l
#घोषणा _tstoi64_l _wtoi64_l

#घोषणा _itot _itow
#घोषणा _ltot _ltow
#घोषणा _ultot _ultow
#घोषणा _ttoi _wtoi
#घोषणा _ttol _wtol

#घोषणा _ttoi64 _wtoi64
#घोषणा _i64tot _i64tow
#घोषणा _ui64tot _ui64tow

#घोषणा _tcscat wcscat
#घोषणा _tcschr wcschr
#घोषणा _tcscpy wcscpy
#घोषणा _tcscspn wcscspn
#घोषणा _tcslen wcslen
#घोषणा _tcsnlen wcsnlen
#घोषणा _tcsncat wcsncat
#घोषणा _tcsncat_l _wcsncat_l
#घोषणा _tcsncpy wcsncpy
#घोषणा _tcsncpy_l _wcsncpy_l
#घोषणा _tcspbrk wcspbrk
#घोषणा _tcsrchr wcsrchr
#घोषणा _tcsspn wcsspn
#घोषणा _tcsstr wcsstr
#घोषणा _tcstok wcstok
#घोषणा _tcstok_l _wcstok_l
#घोषणा _tcserror _wcserror
#घोषणा __tcserror __wcserror

#घोषणा _tcsdup _wcsdup
#घोषणा _tcsnset _wcsnset
#घोषणा _tcsnset_l _wcsnset_l
#घोषणा _tcsrev _wcsrev
#घोषणा _tcsset _wcsset
#घोषणा _tcsset_l _wcsset_l

#घोषणा _tcscmp wcscmp
#घोषणा _tcsicmp _wcsicmp
#घोषणा _tcsicmp_l _wcsicmp_l
#घोषणा _tcsnccmp wcsncmp
#घोषणा _tcsncmp wcsncmp
#घोषणा _tcsncicmp _wcsnicmp
#घोषणा _tcsncicmp_l _wcsnicmp_l
#घोषणा _tcsnicmp _wcsnicmp
#घोषणा _tcsnicmp_l _wcsnicmp_l

#घोषणा _tcscoll wcscoll
#घोषणा _tcscoll_l _wcscoll_l
#घोषणा _tcsicoll _wcsicoll
#घोषणा _tcsicoll_l _wcsicoll_l
#घोषणा _tcsnccoll _wcsncoll
#घोषणा _tcsnccoll_l _wcsncoll_l
#घोषणा _tcsncoll _wcsncoll
#घोषणा _tcsncoll_l _wcsncoll_l
#घोषणा _tcsncicoll _wcsnicoll
#घोषणा _tcsncicoll_l _wcsnicoll_l
#घोषणा _tcsnicoll _wcsnicoll
#घोषणा _tcsnicoll_l _wcsnicoll_l

#घोषणा _texecl _wexecl
#घोषणा _texecle _wexecle
#घोषणा _texeclp _wexeclp
#घोषणा _texeclpe _wexeclpe
#घोषणा _texecv _wexecv
#घोषणा _texecve _wexecve
#घोषणा _texecvp _wexecvp
#घोषणा _texecvpe _wexecvpe

#घोषणा _tspawnl _wspawnl
#घोषणा _tspawnle _wspawnle
#घोषणा _tspawnlp _wspawnlp
#घोषणा _tspawnlpe _wspawnlpe
#घोषणा _tspawnv _wspawnv
#घोषणा _tspawnve _wspawnve
#घोषणा _tspawnvp _wspawnvp
#घोषणा _tspawnvp _wspawnvp
#घोषणा _tspawnvpe _wspawnvpe

#घोषणा _tsystem _wsystem

#घोषणा _tasctime _wasctime
#घोषणा _tctime _wctime
#घोषणा _tctime32 _wctime32
#घोषणा _tctime64 _wctime64
#घोषणा _tstrdate _wstrdate
#घोषणा _tstrtime _wstrtime
#घोषणा _tutime _wutime
#घोषणा _tutime32 _wutime32
#घोषणा _tutime64 _wutime64
#घोषणा _tcsftime wcsftime
#घोषणा _tcsftime_l _wcsftime_l

#घोषणा _tchdir _wchdir
#घोषणा _tgetcwd _wgetcwd
#घोषणा _tgetdcwd _wgetdcwd
#घोषणा _tgetdcwd_nolock _wgetdcwd_nolock
#घोषणा _tmkdir _wmkdir
#घोषणा _trmdir _wrmdir

#घोषणा _tfullpath _wfullpath
#घोषणा _tgetenv _wgetenv
#घोषणा _tmakepath _wmakepath
#घोषणा _tpgmptr _wpgmptr
#घोषणा _get_tpgmptr _get_wpgmptr
#घोषणा _tputenv _wputenv
#घोषणा _tsearchenv _wsearchenv
#घोषणा _tsplitpath _wsplitpath

#घोषणा _tfdopen _wfdopen
#घोषणा _tfsopen _wfsopen
#घोषणा _tfopen _wfopen
#घोषणा _tfreopen _wfreopen
#घोषणा _tperror _wperror
#घोषणा _tpopen _wpopen
#घोषणा _ttempnam _wtempnam
#घोषणा _ttmpnam _wtmpnam

#घोषणा _taccess _waccess
#घोषणा _tchmod _wchmod
#घोषणा _tcreat _wcreat
#घोषणा _tfindfirst _wfindfirst
#घोषणा _tfindfirst32 _wfindfirst32
#घोषणा _tfindfirst64 _wfindfirst64
#घोषणा _tfindfirsti64 _wfindfirsti64
#घोषणा _tfindfirst32i64 _wfindfirst32i64
#घोषणा _tfindfirst64i32 _wfindfirst64i32
#घोषणा _tfindnext _wfindnext
#घोषणा _tfindnext32 _wfindnext32
#घोषणा _tfindnext64 _wfindnext64
#घोषणा _tfindnexti64 _wfindnexti64
#घोषणा _tfindnext32i64 _wfindnext32i64
#घोषणा _tfindnext64i32 _wfindnext64i32
#घोषणा _tmktemp _wmktemp
#घोषणा _topen _wopen
#घोषणा _tremove _wremove
#घोषणा _trename _wrename
#घोषणा _tsopen _wsopen
#घोषणा _tunlink _wunlink

#घोषणा _tfinddata_t _wfinddata_t
#घोषणा _tfinddata32_t _wfinddata32_t
#घोषणा _tfinddata64_t _wfinddata64_t
#घोषणा _tfinddatai64_t _wfinddatai64_t
#घोषणा _tfinddata32i64_t _wfinddata32i64_t
#घोषणा _tfinddata64i32_t _wfinddata64i32_t

#घोषणा _tstat _wstat
#घोषणा _tstat32 _wstat32
#घोषणा _tstat32i64 _wstat32i64
#घोषणा _tstat64 _wstat64
#घोषणा _tstat64i32 _wstat64i32
#घोषणा _tstati64 _wstati64

#घोषणा _tsetlocale _wsetlocale

#घोषणा _tcsclen wcslen
#घोषणा _tcscnlen wcsnlen
#घोषणा _tcsclen_l(_String,_Locale) wcslen(_String)
#घोषणा _tcscnlen_l(_String,Max_गिनती_2,_Locale) wcsnlen_l((_String),(Max_गिनती_2))
#घोषणा _tcsnccat wcsncat
#घोषणा _tcsnccat_l _wcsncat_l
#घोषणा _tcsnccpy wcsncpy
#घोषणा _tcsnccpy_l _wcsncpy_l
#घोषणा _tcsncset _wcsnset

#घोषणा _tcsdec _wcsdec
#घोषणा _tcsinc _wcsinc
#घोषणा _tcsnbcnt _wcsncnt
#घोषणा _tcsnccnt _wcsncnt
#घोषणा _tcsnextc _wcsnextc
#घोषणा _tcsninc _wcsninc
#घोषणा _tcsspnp _wcsspnp

#घोषणा _tcslwr _wcslwr
#घोषणा _tcslwr_l _wcslwr_l
#घोषणा _tcsupr _wcsupr
#घोषणा _tcsupr_l _wcsupr_l
#घोषणा _tcsxfrm wcsxfrm
#घोषणा _tcsxfrm_l _wcsxfrm_l

#घोषणा _tclen(_pc) (1)
#घोषणा _tccpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#घोषणा _tccmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#घोषणा _istalnum iswalnum
#घोषणा _istalnum_l _iswalnum_l
#घोषणा _istalpha iswalpha
#घोषणा _istalpha_l _iswalpha_l
#घोषणा _istascii iswascii
#घोषणा _istcntrl iswcntrl
#घोषणा _istcntrl_l _iswcntrl_l
#घोषणा _istdigit iswdigit
#घोषणा _istdigit_l _iswdigit_l
#घोषणा _istgraph iswgraph
#घोषणा _istgraph_l _iswgraph_l
#घोषणा _istlower iswlower
#घोषणा _istlower_l _iswlower_l
#घोषणा _istprint iswprint
#घोषणा _istprint_l _iswprint_l
#घोषणा _istpunct iswpunct
#घोषणा _istpunct_l _iswpunct_l
#घोषणा _istspace iswspace
#घोषणा _istspace_l _iswspace_l
#घोषणा _istupper iswupper
#घोषणा _istupper_l _iswupper_l
#घोषणा _istxdigit iswxdigit
#घोषणा _istxdigit_l _iswxdigit_l

#घोषणा _totupper towupper
#घोषणा _totupper_l _towupper_l
#घोषणा _totlower towlower
#घोषणा _totlower_l _towlower_l

#घोषणा _istlegal(_Char) (1)
#घोषणा _istlead(_Char) (0)
#घोषणा _istleadbyte(_Char) (0)
#घोषणा _istleadbyte_l(_Char,_Locale) (0)

#घोषणा _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? शून्य : (_cpc2)-1)
#घोषणा _wcsinc(_pc) ((_pc)+1)
#घोषणा _wcsnextc(_cpc) ((अचिन्हित पूर्णांक) *(_cpc))
#घोषणा _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP माप_प्रकार __cdecl __wcsncnt(स्थिर ब_अक्षर_प्रकार *_Str,माप_प्रकार Max_गिनती);
#घोषणा _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#घोषणा _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? शून्य : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : शून्य))
#घोषणा _wcsncpy_l(_Destination,_Source,गिनती_5,_Locale) (wcsncpy(_Destination,_Source,गिनती_5))
#घोषणा _wcsncat_l(_Destination,_Source,गिनती_5,_Locale) (wcsncat(_Destination,_Source,गिनती_5))
#घोषणा _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#घोषणा _wcsnset_l(_Destination,मूल्य_2,गिनती_5,_Locale) (_wcsnset(_Destination,मूल्य_2,गिनती_5))
#घोषणा _wcsset_l(_Destination,मूल्य_2,_Locale) (_wcsset(_Destination,मूल्य_2))

  /* dirent structures and functions */
#घोषणा _tdirent	_wdirent
#घोषणा _TDIR 		_WDIR
#घोषणा _topendir	_wopendir
#घोषणा _tclosedir	_wclosedir
#घोषणा _treaddir	_wreaddir
#घोषणा _trewinddir	_wrewinddir
#घोषणा _ttelldir	_wtelldir
#घोषणा _tseekdir	_wseekdir

#अन्यथा

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#समावेश <string.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#घोषणा _TEOF खातापूर्ण

#घोषणा __T(x) x

#घोषणा _tmain मुख्य
#घोषणा _tWinMain WinMain
#अगर_घोषित _POSIX_
#घोषणा _tenviron environ
#अन्यथा
#घोषणा _tenviron _environ
#पूर्ण_अगर
#घोषणा __targv __argv

#घोषणा _tprintf म_लिखो
#घोषणा _tprintf_l _printf_l
#घोषणा _tprintf_p _printf_p
#घोषणा _tprintf_p_l _printf_p_l
#घोषणा _tcprintf _cprintf
#घोषणा _tcprintf_l _cprintf_l
#घोषणा _tcprintf_p _cprintf_p
#घोषणा _tcprintf_p_l _cprintf_p_l
#घोषणा _vtcprintf _vcprintf
#घोषणा _vtcprintf_l _vcprintf_l
#घोषणा _vtcprintf_p _vcprintf_p
#घोषणा _vtcprintf_p_l _vcprintf_p_l
#घोषणा _ftprintf ख_लिखो
#घोषणा _ftprintf_l _fprintf_l
#घोषणा _ftprintf_p _fprintf_p
#घोषणा _ftprintf_p_l _fprintf_p_l
#घोषणा _stprintf प्र_लिखो
#घोषणा _stprintf_l _sprintf_l
#घोषणा _stprintf_p _sprintf_p
#घोषणा _stprintf_p_l _sprintf_p_l
#घोषणा _sctprintf _scprintf
#घोषणा _sctprintf_l _scprintf_l
#घोषणा _sctprintf_p _scprintf_p
#घोषणा _sctprintf_p_l _scprintf_p_l
#घोषणा _sntprintf _snprintf
#घोषणा _sntprintf_l _snprintf_l
#घोषणा _vtprintf भ_लिखो
#घोषणा _vtprintf_l _vprintf_l
#घोषणा _vtprintf_p _vprintf_p
#घोषणा _vtprintf_p_l _vprintf_p_l
#घोषणा _vftprintf भख_लिखो
#घोषणा _vftprintf_l _vfprintf_l
#घोषणा _vftprintf_p _vfprintf_p
#घोषणा _vftprintf_p_l _vfprintf_p_l
#घोषणा _vstprintf भम_लिखो
#घोषणा _vstprintf_l _vsprintf_l
#घोषणा _vstprintf_p _vsprintf_p
#घोषणा _vstprintf_p_l _vsprintf_p_l
#घोषणा _vsctprintf _vscprintf
#घोषणा _vsctprintf_l _vscprintf_l
#घोषणा _vsctprintf_p _vscprintf_p
#घोषणा _vsctprintf_p_l _vscprintf_p_l
#घोषणा _vsntprintf _vsnprintf
#घोषणा _vsntprintf_l _vsnprintf_l

#घोषणा _tscanf म_पूछो
#घोषणा _tscanf_l _scanf_l
#घोषणा _tcscanf _cscanf
#घोषणा _tcscanf_l _cscanf_l
#घोषणा _ftscanf ख_पूछो
#घोषणा _ftscanf_l _fscanf_l
#घोषणा _stscanf माला_पूछो
#घोषणा _stscanf_l _sscanf_l
#घोषणा _sntscanf _snscanf
#घोषणा _sntscanf_l _snscanf_l

#घोषणा _fgettc ख_अक्षर_लो
#घोषणा _fgettc_nolock _fgetc_nolock
#घोषणा _fgettchar _fgetchar
#घोषणा _fgetts ख_माला_लो
#घोषणा _fputtc ख_अक्षर_दो
#घोषणा _fputtc_nolock _fputc_nolock
#घोषणा _fputtchar _fputchar
#घोषणा _fputts ख_माला_दो
#घोषणा _cputts _cputs
#घोषणा _gettc अ_लो
#घोषणा _gettc_nolock _getc_nolock
#घोषणा _gettch _getch
#घोषणा _gettch_nolock _getch_nolock
#घोषणा _gettche _getche
#घोषणा _gettche_nolock _getche_nolock
#घोषणा _gettchar अक्षर_लो
#घोषणा _gettchar_nolock _getchar_nolock
#घोषणा _getts माला_लो
#घोषणा _cgetts _cgets
#घोषणा _puttc अ_दो
#घोषणा _puttc_nolock _putc_nolock
#घोषणा _puttchar अक्षर_दो
#घोषणा _puttchar_nolock _putchar_nolock
#घोषणा _puttch _putch
#घोषणा _puttch_nolock _putch_nolock
#घोषणा _putts माला_दो
#घोषणा _ungettc अक्षर_वापस
#घोषणा _ungettc_nolock _ungetc_nolock
#घोषणा _ungettch _ungetch
#घोषणा _ungettch_nolock _ungetch_nolock

#घोषणा _tcstod म_से_भग्न
#घोषणा _tcstol म_से_दीर्घ
#घोषणा _tcstoul म_से_अदीर्घ
#घोषणा _tstof म_से_भ
#घोषणा _tstol म_से_द
#घोषणा _tstoi म_से_प
#घोषणा _tstoi64 _atoi64
#घोषणा _tcstod_l _strtod_l
#घोषणा _tcstol_l _strtol_l
#घोषणा _tcstoul_l _strtoul_l
#घोषणा _tstof_l _atof_l
#घोषणा _tstol_l _atol_l
#घोषणा _tstoi_l _atoi_l
#घोषणा _tstoi64_l _atoi64_l

#घोषणा _itot _itoa
#घोषणा _ltot _ltoa
#घोषणा _ultot _ultoa
#घोषणा _ttoi म_से_प
#घोषणा _ttol म_से_द

#घोषणा _ttoi64 _atoi64
#घोषणा _tcstoi64 _strtoi64
#घोषणा _tcstoi64_l _strtoi64_l
#घोषणा _tcstoui64 _strtoui64
#घोषणा _tcstoui64_l _strtoui64_l
#घोषणा _i64tot _i64toa
#घोषणा _ui64tot _ui64toa

#घोषणा _tcscat म_जोड़ो
#घोषणा _tcscpy म_नकल
#घोषणा _tcsdup _strdup
#घोषणा _tcslen म_माप
#अगर 0
#घोषणा _tcsnlen strnlen
#पूर्ण_अगर
#घोषणा _tcsxfrm strxfrm
#घोषणा _tcsxfrm_l _strxfrm_l
#घोषणा _tcserror म_त्रुटि
#घोषणा __tcserror _strerror

#घोषणा _texecl _execl
#घोषणा _texecle _execle
#घोषणा _texeclp _execlp
#घोषणा _texeclpe _execlpe
#घोषणा _texecv _execv
#घोषणा _texecve _execve
#घोषणा _texecvp _execvp
#घोषणा _texecvpe _execvpe

#घोषणा _tspawnl _spawnl
#घोषणा _tspawnle _spawnle
#घोषणा _tspawnlp _spawnlp
#घोषणा _tspawnlpe _spawnlpe
#घोषणा _tspawnv _spawnv
#घोषणा _tspawnve _spawnve
#घोषणा _tspawnvp _spawnvp
#घोषणा _tspawnvpe _spawnvpe

#घोषणा _tsystem प्रणाली

#घोषणा _tasctime समय_ठीक
#घोषणा _tctime स_समय
#घोषणा _tctime32 _ctime32
#घोषणा _tctime64 _ctime64
#घोषणा _tstrdate _strdate
#घोषणा _tstrtime _strtime
#घोषणा _tutime _utime
#घोषणा _tutime32 _utime32
#घोषणा _tutime64 _utime64
#घोषणा _tcsftime स_माला
#घोषणा _tcsftime_l _strftime_l

#घोषणा _tchdir _chdir
#घोषणा _tgetcwd _getcwd
#घोषणा _tgetdcwd _getdcwd
#घोषणा _tgetdcwd_nolock _getdcwd_nolock
#घोषणा _tmkdir _mkdir
#घोषणा _trmdir _rmdir

#घोषणा _tfullpath _fullpath
#घोषणा _tgetenv दो_पर्या
#घोषणा _tmakepath _makepath
#घोषणा _tpgmptr _pgmptr
#घोषणा _get_tpgmptr _get_pgmptr
#घोषणा _tputenv _putenv
#घोषणा _tsearchenv _searchenv
#घोषणा _tsplitpath _splitpath

#अगर_घोषित _POSIX_
#घोषणा _tfdopen fdopen
#अन्यथा
#घोषणा _tfdopen _fdopen
#पूर्ण_अगर
#घोषणा _tfsopen _fsopen
#घोषणा _tfopen ख_खोलो
#घोषणा _tfreopen ख_व_खोलो
#घोषणा _tperror लिखो_त्रुटि
#घोषणा _tpopen _popen
#घोषणा _ttempnam _tempnam
#घोषणा _ttmpnam क्षणिक

#घोषणा _tchmod _chmod
#घोषणा _tcreat _creat
#घोषणा _tfindfirst _findfirst
#घोषणा _tfindfirst32 _findfirst32
#घोषणा _tfindfirst64 _findfirst64
#घोषणा _tfindfirsti64 _findfirsti64
#घोषणा _tfindfirst32i64 _findfirst32i64
#घोषणा _tfindfirst64i32 _findfirst64i32
#घोषणा _tfindnext _findnext
#घोषणा _tfindnext32 _findnext32
#घोषणा _tfindnext64 _findnext64
#घोषणा _tfindnexti64 _findnexti64
#घोषणा _tfindnext32i64 _findnext32i64
#घोषणा _tfindnext64i32 _findnext64i32
#घोषणा _tmktemp _mktemp

#अगर_घोषित _POSIX_
#घोषणा _topen खोलो
#घोषणा _taccess access
#अन्यथा
#घोषणा _topen _open
#घोषणा _taccess _access
#पूर्ण_अगर

#घोषणा _tremove हटाओ
#घोषणा _trename नाम
#घोषणा _tsopen _sopen
#घोषणा _tunlink _unlink

#घोषणा _tfinddata_t _finddata_t
#घोषणा _tfinddata32_t _finddata32_t
#घोषणा _tfinddata64_t __finddata64_t
#घोषणा _tfinddatai64_t _finddatai64_t
#घोषणा _tfinddata32i64_t _finddata32i64_t
#घोषणा _tfinddata64i32_t _finddata64i32_t

#घोषणा _istascii __isascii
#घोषणा _istcntrl है_नियंत्रण
#घोषणा _istcntrl_l _iscntrl_l
#घोषणा _istxdigit है_षष्ठादशक
#घोषणा _istxdigit_l _isxdigit_l

#घोषणा _tstat _stat
#घोषणा _tstat32 _stat32
#घोषणा _tstat32i64 _stat32i64
#घोषणा _tstat64 _stat64
#घोषणा _tstat64i32 _stat64i32
#घोषणा _tstati64 _stati64

#घोषणा _tsetlocale रखो_क्षेत्र

#अगर_घोषित _MBCS

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#समावेश <mbstring.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित __TCHAR_DEFINED
  प्रकार अक्षर _TCHAR;
  प्रकार चिन्हित अक्षर _TSCHAR;
  प्रकार अचिन्हित अक्षर _TUCHAR;
  प्रकार अचिन्हित अक्षर _TXCHAR;
  प्रकार अचिन्हित पूर्णांक _TINT;
#घोषणा __TCHAR_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _TCHAR_DEFINED
#अगर_अघोषित	NO_OLDNAMES
  प्रकार अक्षर TCHAR;
#पूर्ण_अगर
#घोषणा _TCHAR_DEFINED
#पूर्ण_अगर

#अगर_घोषित _MB_MAP_DIRECT

#घोषणा _tcschr _mbschr
#घोषणा _tcscspn _mbscspn
#घोषणा _tcsncat _mbsnbcat
#घोषणा _tcsncat_l _mbsnbcat_l
#घोषणा _tcsncpy _mbsnbcpy
#घोषणा _tcsncpy_l _mbsnbcpy_l
#घोषणा _tcspbrk _mbspbrk
#घोषणा _tcsrchr _mbsrchr
#घोषणा _tcsspn _mbsspn
#घोषणा _tcsstr _mbsstr
#घोषणा _tcstok _mbstok
#घोषणा _tcstok_l _mbstok_l

#घोषणा _tcsnset _mbsnbset
#घोषणा _tcsnset_l _mbsnbset_l
#घोषणा _tcsrev _mbsrev
#घोषणा _tcsset _mbsset
#घोषणा _tcsset_l _mbsset_l

#घोषणा _tcscmp _mbscmp
#घोषणा _tcsicmp _mbsicmp
#घोषणा _tcsicmp_l _mbsicmp_l
#घोषणा _tcsnccmp _mbsncmp
#घोषणा _tcsncmp _mbsnbcmp
#घोषणा _tcsncicmp _mbsnicmp
#घोषणा _tcsncicmp_l _mbsnicmp_l
#घोषणा _tcsnicmp _mbsnbicmp
#घोषणा _tcsnicmp_l _mbsnbicmp_l

#घोषणा _tcscoll _mbscoll
#घोषणा _tcscoll_l _mbscoll_l
#घोषणा _tcsicoll _mbsicoll
#घोषणा _tcsicoll_l _mbsicoll_l
#घोषणा _tcsnccoll _mbsncoll
#घोषणा _tcsnccoll_l _mbsncoll_l
#घोषणा _tcsncoll _mbsnbcoll
#घोषणा _tcsncoll_l _mbsnbcoll_l
#घोषणा _tcsncicoll _mbsnicoll
#घोषणा _tcsncicoll_l _mbsnicoll_l
#घोषणा _tcsnicoll _mbsnbicoll
#घोषणा _tcsnicoll_l _mbsnbicoll_l

#घोषणा _tcsclen _mbslen
#घोषणा _tcscnlen _mbsnlen
#घोषणा _tcsclen_l _mbslen_l
#घोषणा _tcscnlen_l _mbsnlen_l
#घोषणा _tcsnccat _mbsncat
#घोषणा _tcsnccat_l _mbsncat_l
#घोषणा _tcsnccpy _mbsncpy
#घोषणा _tcsnccpy_l _mbsncpy_l
#घोषणा _tcsncset _mbsnset
#घोषणा _tcsncset_l _mbsnset_l

#घोषणा _tcsdec _mbsdec
#घोषणा _tcsinc _mbsinc
#घोषणा _tcsnbcnt _mbsnbcnt
#घोषणा _tcsnccnt _mbsnccnt
#घोषणा _tcsnextc _mbsnextc
#घोषणा _tcsninc _mbsninc
#घोषणा _tcsspnp _mbsspnp

#घोषणा _tcslwr _mbslwr
#घोषणा _tcslwr_l _mbslwr_l
#घोषणा _tcsupr _mbsupr
#घोषणा _tcsupr_l _mbsupr_l

#घोषणा _tclen _mbclen
#घोषणा _tccpy _mbccpy
#घोषणा _tccpy_l _mbccpy_l
#अन्यथा

  _CRTIMP _CONST_RETURN अक्षर *__cdecl _tcschr(स्थिर अक्षर *_Str,अचिन्हित पूर्णांक _Val);
  _CRTIMP माप_प्रकार __cdecl _tcscspn(स्थिर अक्षर *_Str,स्थिर अक्षर *_Control);
  _CRTIMP अक्षर *__cdecl _tcsncat(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsncat_l(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsncpy(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsncpy_l(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP _CONST_RETURN अक्षर *__cdecl _tcspbrk(स्थिर अक्षर *_Str,स्थिर अक्षर *_Control);
  _CRTIMP _CONST_RETURN अक्षर *__cdecl _tcsrchr(स्थिर अक्षर *_Str,अचिन्हित पूर्णांक _Ch);
  _CRTIMP माप_प्रकार __cdecl _tcsspn(स्थिर अक्षर *_Str,स्थिर अक्षर *_Control);
  _CRTIMP _CONST_RETURN अक्षर *__cdecl _tcsstr(स्थिर अक्षर *_Str,स्थिर अक्षर *_Substr);
  _CRTIMP अक्षर *__cdecl _tcstok(अक्षर *_Str,स्थिर अक्षर *_Delim);
  _CRTIMP अक्षर *__cdecl _tcstok_l(अक्षर *_Str,स्थिर अक्षर *_Delim,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsnset(अक्षर *_Str,अचिन्हित पूर्णांक _Val,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsrev(अक्षर *_Str);
  _CRTIMP अक्षर *__cdecl _tcsset(अक्षर *_Str,अचिन्हित पूर्णांक _Val);
  _CRTIMP अक्षर *__cdecl _tcsset_l(अक्षर *_Str,अचिन्हित पूर्णांक _Val,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcscmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _tcsicmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP पूर्णांक __cdecl _tcsicmp_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcsnccmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsncmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsncicmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsncicmp_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcsnicmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsnicmp_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcscoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP पूर्णांक __cdecl _tcscoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcsicoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP पूर्णांक __cdecl _tcsicoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcsnccoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsnccoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcsncoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsncoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcsncicoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsncicoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _tcsnicoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _tcsnicoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _tcsclen(स्थिर अक्षर *_Str);
  _CRTIMP माप_प्रकार __cdecl _tcscnlen(स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _tcsclen_l(स्थिर अक्षर *_Str,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _tcscnlen_l(स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsnccat(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsnccat_l(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsnccpy(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsnccpy_l(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsncset(अक्षर *_Str,अचिन्हित पूर्णांक _Val,माप_प्रकार Max_गिनती);
  _CRTIMP अक्षर *__cdecl _tcsdec(स्थिर अक्षर *_Start,स्थिर अक्षर *_Pos);
  _CRTIMP अक्षर *__cdecl _tcsinc(स्थिर अक्षर *_Ptr);
  _CRTIMP माप_प्रकार __cdecl _tcsnbcnt(स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _tcsnccnt(स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती);
  _CRTIMP अचिन्हित पूर्णांक __cdecl _tcsnextc (स्थिर अक्षर *_Str);
  _CRTIMP अक्षर *__cdecl _tcsninc(स्थिर अक्षर *_Ptr,माप_प्रकार गिनती_5);
  _CRTIMP अक्षर *__cdecl _tcsspnp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP अक्षर *__cdecl _tcslwr(अक्षर *_Str);
  _CRTIMP अक्षर *__cdecl _tcslwr_l(अक्षर *_Str,_locale_t _Locale);
  _CRTIMP अक्षर *__cdecl _tcsupr(अक्षर *_Str);
  _CRTIMP अक्षर *__cdecl _tcsupr_l(अक्षर *_Str,_locale_t _Locale);
  _CRTIMP माप_प्रकार __cdecl _tclen(स्थिर अक्षर *_Str);
  _CRTIMP व्योम __cdecl _tccpy(अक्षर *_DstCh,स्थिर अक्षर *_SrcCh);

#अगर_घोषित __cplusplus
#अगर_अघोषित _CPP_TCHAR_INLINES_DEFINED
#घोषणा _CPP_TCHAR_INLINES_DEFINED
  बाह्य "C++" {
    बाह्य अंतरभूत अक्षर *__cdecl _tcschr(अक्षर *_S,अचिन्हित पूर्णांक _C) { वापस ((अक्षर *)_tcschr((स्थिर अक्षर *)_S,_C)); }
    बाह्य अंतरभूत अक्षर *__cdecl _tcspbrk(अक्षर *_S,स्थिर अक्षर *_P) { वापस ((अक्षर *)_tcspbrk((स्थिर अक्षर *)_S,_P)); }
    बाह्य अंतरभूत अक्षर *__cdecl _tcsrchr(अक्षर *_S,अचिन्हित पूर्णांक _C) { वापस ((अक्षर *)_tcsrchr((स्थिर अक्षर *)_S,_C)); }
    बाह्य अंतरभूत अक्षर *__cdecl _tcsstr(अक्षर *_S,स्थिर अक्षर *_P) { वापस ((अक्षर *)_tcsstr((स्थिर अक्षर *)_S,_P)); }
  }
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _tccmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#घोषणा _istalnum _ismbcalnum
#घोषणा _istalnum_l _ismbcalnum_l
#घोषणा _istalpha _ismbcalpha
#घोषणा _istalpha_l _ismbcalpha_l
#घोषणा _istdigit _ismbcdigit
#घोषणा _istdigit_l _ismbcdigit_l
#घोषणा _istgraph _ismbcgraph
#घोषणा _istgraph_l _ismbcgraph_l
#घोषणा _istlegal _ismbclegal
#घोषणा _istlegal_l _ismbclegal_l
#घोषणा _istlower _ismbclower
#घोषणा _istlower_l _ismbclower_l
#घोषणा _istprint _ismbcprint
#घोषणा _istprint_l _ismbcprint_l
#घोषणा _istpunct _ismbcpunct
#घोषणा _istpunct_l _ismbcpunct_l
#घोषणा _istspace _ismbcspace
#घोषणा _istspace_l _ismbcspace_l
#घोषणा _istupper _ismbcupper
#घोषणा _istupper_l _ismbcupper_l

#घोषणा _totupper _mbctoupper
#घोषणा _totupper_l _mbctoupper_l
#घोषणा _totlower _mbctolower
#घोषणा _totlower_l _mbctolower_l

#घोषणा _istlead _ismbblead
#घोषणा _istleadbyte isleadbyte
#घोषणा _istleadbyte_l _isleadbyte_l
#अन्यथा

#अगर_अघोषित __TCHAR_DEFINED
#घोषणा __TCHAR_DEFINED
  प्रकार अक्षर _TCHAR;
  प्रकार चिन्हित अक्षर _TSCHAR;
  प्रकार अचिन्हित अक्षर _TUCHAR;
  प्रकार अक्षर _TXCHAR;
  प्रकार पूर्णांक _TINT;
#पूर्ण_अगर

#अगर_अघोषित _TCHAR_DEFINED
#घोषणा _TCHAR_DEFINED
#अगर_अघोषित	NO_OLDNAMES
  प्रकार अक्षर TCHAR;
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _tcschr म_अक्षर
#घोषणा _tcscspn म_खोज
#घोषणा _tcsncat म_जोड़न
#घोषणा _tcsncat_l _strncat_l
#घोषणा _tcsncpy म_नकलन
#घोषणा _tcsncpy_l _strncpy_l
#घोषणा _tcspbrk strpbrk
#घोषणा _tcsrchr म_खोजप
#घोषणा _tcsspn म_अखोज
#घोषणा _tcsstr म_माला
#घोषणा _tcstok म_मोहर
#घोषणा _tcstok_l _strtok_l

#घोषणा _tcsnset _strnset
#घोषणा _tcsnset_l _strnset_l
#घोषणा _tcsrev _strrev
#घोषणा _tcsset _strset

#घोषणा _tcscmp म_भेद
#घोषणा _tcsicmp _stricmp
#घोषणा _tcsicmp_l _stricmp_l
#घोषणा _tcsnccmp म_भेदन
#घोषणा _tcsncmp म_भेदन
#घोषणा _tcsncicmp _strnicmp
#घोषणा _tcsncicmp_l _strnicmp_l
#घोषणा _tcsnicmp _strnicmp
#घोषणा _tcsnicmp_l _strnicmp_l

#घोषणा _tcscoll strcoll
#घोषणा _tcscoll_l _strcoll_l
#घोषणा _tcsicoll _stricoll
#घोषणा _tcsicoll_l _stricoll_l
#घोषणा _tcsnccoll _strncoll
#घोषणा _tcsnccoll_l _strncoll_l
#घोषणा _tcsncoll _strncoll
#घोषणा _tcsncoll_l _strncoll_l
#घोषणा _tcsncicoll _strnicoll
#घोषणा _tcsncicoll_l _strnicoll_l
#घोषणा _tcsnicoll _strnicoll
#घोषणा _tcsnicoll_l _strnicoll_l

#घोषणा _tcsclen म_माप
#घोषणा _tcscnlen strnlen
#घोषणा _tcsclen_l(_String,_Locale) म_माप(_String)
#घोषणा _tcscnlen_l(_String,Max_गिनती_2,_Locale) strnlen_l((_String),(Max_गिनती_2))
#घोषणा _tcsnccat म_जोड़न
#घोषणा _tcsnccat_l _strncat_l
#घोषणा _tcsnccpy म_नकलन
#घोषणा _tcsnccpy_l _strncpy_l
#घोषणा _tcsncset _strnset

#घोषणा _tcsdec _strdec
#घोषणा _tcsinc _strinc
#घोषणा _tcsnbcnt _strncnt
#घोषणा _tcsnccnt _strncnt
#घोषणा _tcsnextc _strnextc
#घोषणा _tcsninc _strninc
#घोषणा _tcsspnp _strspnp

#घोषणा _tcslwr _strlwr
#घोषणा _tcslwr_l _strlwr_l
#घोषणा _tcsupr _strupr
#घोषणा _tcsupr_l _strupr_l
#घोषणा _tcsxfrm strxfrm
#घोषणा _tcsxfrm_l _strxfrm_l

#घोषणा _istlead(_Char) (0)
#घोषणा _istleadbyte(_Char) (0)
#घोषणा _istleadbyte_l(_Char,_Locale) (0)

#घोषणा _tclen(_pc) (1)
#घोषणा _tccpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#घोषणा _tccmp(_cpc1,_cpc2) (((अचिन्हित अक्षर)*(_cpc1))-((अचिन्हित अक्षर)*(_cpc2)))

  /* dirent structures and functions */
#घोषणा _tdirent	dirent
#घोषणा _TDIR 		सूची
#घोषणा _topendir	सूची_खोलो
#घोषणा _tclosedir	बंद_सूची
#घोषणा _treaddir	सूची_पढ़ो
#घोषणा _trewinddir	सूची_शुरु
#घोषणा _ttelldir	telldir
#घोषणा _tseekdir	seekdir

#घोषणा _istalnum है_अक्षर_अंक
#घोषणा _istalnum_l _isalnum_l
#घोषणा _istalpha है_अक्षर
#घोषणा _istalpha_l _isalpha_l
#घोषणा _istdigit है_अंक
#घोषणा _istdigit_l _isdigit_l
#घोषणा _istgraph है_चित्र
#घोषणा _istgraph_l _isgraph_l
#घोषणा _istlower है_छोटा
#घोषणा _istlower_l _islower_l
#घोषणा _istprint है_छाप
#घोषणा _istprint_l _isprint_l
#घोषणा _istpunct है_विराम
#घोषणा _istpunct_l _ispunct_l
#घोषणा _istspace है_खाली
#घोषणा _istspace_l _isspace_l
#घोषणा _istupper है_बड़ा
#घोषणा _istupper_l _isupper_l

#घोषणा _totupper बड़े
#घोषणा _totupper_l _toupper_l
#घोषणा _totlower छोटे
#घोषणा _totlower_l _tolower_l

#घोषणा _istlegal(_c) (1)

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? शून्य : (_cpc2)-1)
#घोषणा _strinc(_pc) ((_pc)+1)
#घोषणा _strnextc(_cpc) ((अचिन्हित पूर्णांक) *(स्थिर अचिन्हित अक्षर *)(_cpc))
#घोषणा _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP माप_प्रकार __cdecl __strncnt(स्थिर अक्षर *_Str,माप_प्रकार _Cnt);
#घोषणा _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#घोषणा _strspnp(_cpc1,_cpc2) (!_cpc1 ? शून्य : ((*((_cpc1)+म_अखोज(_cpc1,_cpc2))) ? ((_cpc1)+म_अखोज(_cpc1,_cpc2)) : शून्य))

#घोषणा _strncpy_l(_Destination,_Source,गिनती_5,_Locale) (म_नकलन(_Destination,_Source,गिनती_5))
#घोषणा _strncat_l(_Destination,_Source,गिनती_5,_Locale) (म_जोड़न(_Destination,_Source,गिनती_5))
#घोषणा _strtok_l(_String,_Delimiters,_Locale) (म_मोहर(_String,_Delimiters))
#घोषणा _strnset_l(_Destination,मूल्य_2,गिनती_5,_Locale) (_strnset(_Destination,मूल्य_2,गिनती_5))
#घोषणा _strset_l(_Destination,मूल्य_2,_Locale) (_strset(_Destination,मूल्य_2))
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _T(x) __T(x)
#घोषणा _TEXT(x) __T(x)

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#समावेश <sec_api/tchar_s.h>
#पूर्ण_अगर
