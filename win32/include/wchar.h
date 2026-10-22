/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_WCHAR
#تعریف_کن _INC_WCHAR

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده WCHAR_MIN  /* also at stdint.h */
#تعریف_کن WCHAR_MIN 0
#تعریف_کن WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#پایان_اگر

#اگر_تعریف_نشده __GNUC_VA_LIST
#تعریف_کن __GNUC_VA_LIST
  تعريفنوع __builtin_va_list __gnuc_va_list;
#پایان_اگر

#اگر_تعریف_نشده _VA_LIST_DEFINED
#تعریف_کن _VA_LIST_DEFINED
  تعريفنوع __gnuc_va_list va_list;
#پایان_اگر

#اگر_تعریف_نشده WEOF
#تعریف_کن WEOF (wint_t)(0xFFFF)
#پایان_اگر

#اگر_تعریف_نشده _FILE_DEFINED
  بنية _iobuf {
    حرف *_ptr;
    صحيح _cnt;
    حرف *پایه_4;
    صحيح _flag;
    صحيح _file;
    صحيح _charbuf;
    صحيح _bufsiz;
    حرف *_tmpfname;
  };
  تعريفنوع بنية _iobuf FILE;
#تعریف_کن _FILE_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _STDIO_DEFINED
#اگر_تعریف_شده _WIN64
  _CRTIMP FILE *__cdecl __iob_func(فراغ);
#وإلا
#اگر_تعریف_شده _MSVCRT_
خارجي FILE _iob[];	/* A pointer to an array of FILE */
#تعریف_کن __iob_func()	(_iob)
#وإلا
خارجي FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#تعریف_کن __iob_func()	(*_imp___iob)
#تعریف_کن _iob __iob_func()
#پایان_اگر
#پایان_اگر

#تعریف_کن _iob __iob_func()
#پایان_اگر

#اگر_تعریف_نشده _STDSTREAM_DEFINED
#تعریف_کن stdin (&__iob_func()[0])
#تعریف_کن stdout (&__iob_func()[1])
#تعریف_کن stderr (&__iob_func()[2])
#تعریف_کن _STDSTREAM_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _FSIZE_T_DEFINED
  تعريفنوع بیعلامت دراز _fsize_t;
#تعریف_کن _FSIZE_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _WFINDDATA_T_DEFINED
  بنية _wfinddata32_t {
    بیعلامت attrib;
    __time32_t زمان_create;
    __time32_t زمان_access;
    __time32_t زمان_write;
    _fsize_t اندازه;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    بیعلامت attrib;
    __time32_t زمان_create;
    __time32_t زمان_access;
    __time32_t زمان_write;
    __int64 اندازه;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    بیعلامت attrib;
    __time64_t زمان_create;
    __time64_t زمان_access;
    __time64_t زمان_write;
    _fsize_t اندازه;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
    بیعلامت attrib;
    __time64_t زمان_create;
    __time64_t زمان_access;
    __time64_t زمان_write;
    __int64 اندازه;
    wchar_t name[260];
  };
/* #endif */

#اگر_تعریف_شده USE_32_بیت_زمان_T
#تعریف_کن _wfinddata_t _wfinddata32_t
#تعریف_کن _wfinddatai64_t _wfinddata32i64_t

#تعریف_کن _wfindfirst _wfindfirst32
#تعریف_کن _wfindnext _wfindnext32
#تعریف_کن _wfindfirsti64 _wfindfirst32i64
#تعریف_کن _wfindnexti64 _wfindnext32i64
#وإلا
#تعریف_کن _wfinddata_t _wfinddata64i32_t
#تعریف_کن _wfinddatai64_t _wfinddata64_t

#تعریف_کن _wfindfirst _wfindfirst64i32
#تعریف_کن _wfindnext _wfindnext64i32
#تعریف_کن _wfindfirsti64 _wfindfirst64
#تعریف_کن _wfindnexti64 _wfindnext64
#پایان_اگر

#تعریف_کن _WFINDDATA_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _CONST_RETURN
#تعریف_کن _CONST_RETURN
#پایان_اگر

#تعریف_کن _WConst_return _CONST_RETURN

#اگر_تعریف_نشده _CRT_CTYPEDATA_DEFINED
#تعریف_کن _CRT_CTYPEDATA_DEFINED
#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS

#اگر_تعریف_نشده __PCTYPE_FUNC
#تعریف_کن __PCTYPE_FUNC __pctype_func()
#اگر_تعریف_شده _MSVCRT_
#تعریف_کن __pctype_func() (_pctype)
#وإلا
#تعریف_کن __pctype_func() (*_imp___pctype)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _pctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_pctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___pctype;
#تعریف_کن _pctype (*_imp___pctype)
#پایان_اگر
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _CRT_WCTYPEDATA_DEFINED
#تعریف_کن _CRT_WCTYPEDATA_DEFINED
#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS
#اگر_تعریف_نشده _wctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_wctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___wctype;
#تعریف_کن _wctype (*_imp___wctype)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده _MSVCRT_
#تعریف_کن __pwctype_func() (_pwctype)
#وإلا
#تعریف_کن __pwctype_func() (*_imp___pwctype)
#پایان_اگر

#اگر_تعریف_نشده _pwctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_pwctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___pwctype;
#تعریف_کن _pwctype (*_imp___pwctype)
#پایان_اگر
#پایان_اگر

#پایان_اگر
#پایان_اگر

#تعریف_کن فوقانی_3 0x1
#تعریف_کن پایینی_2 0x2
#تعریف_کن _DIGIT 0x4
#تعریف_کن _SPACE 0x8

#تعریف_کن _PUNCT 0x10
#تعریف_کن _CONTROL 0x20
#تعریف_کن _BLANK 0x40
#تعریف_کن _HEX 0x80

#تعریف_کن _LEADBYTE 0x8000
#تعریف_کن _ALPHA (0x0100|فوقانی_3|پایینی_2)

#اگر_تعریف_نشده _WCTYPE_DEFINED
#تعریف_کن _WCTYPE_DEFINED

  صحيح __cdecl iswalpha(wint_t _C);
  _CRTIMP صحيح __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswupper(wint_t _C);
  _CRTIMP صحيح __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswlower(wint_t _C);
  _CRTIMP صحيح __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswdigit(wint_t _C);
  _CRTIMP صحيح __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswxdigit(wint_t _C);
  _CRTIMP صحيح __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswspace(wint_t _C);
  _CRTIMP صحيح __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswpunct(wint_t _C);
  _CRTIMP صحيح __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswalnum(wint_t _C);
  _CRTIMP صحيح __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswprint(wint_t _C);
  _CRTIMP صحيح __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswgraph(wint_t _C);
  _CRTIMP صحيح __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswcntrl(wint_t _C);
  _CRTIMP صحيح __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswascii(wint_t _C);
  صحيح __cdecl isleadbyte(صحيح _C);
  _CRTIMP صحيح __cdecl _isleadbyte_l(صحيح _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP صحيح __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP صحيح __cdecl __iswcsymf(wint_t _C);
  _CRTIMP صحيح __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl __iswcsym(wint_t _C);
  _CRTIMP صحيح __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl is_wctype(wint_t _C,wctype_t _Type);
#پایان_اگر

#اگر_تعریف_نشده _WDIRECT_DEFINED
#تعریف_کن _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح اندازه_درون_واژگان);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح اندازه_درون_واژگان);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح اندازه_درون_واژگان);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *مسیر_2);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *مسیر_2);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *مسیر_2);
#پایان_اگر

#اگر_تعریف_نشده _WIO_DEFINED
#تعریف_کن _WIO_DEFINED

  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح Access_نما);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح نما_3);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح Permission_نما);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t پیدا_کن_Handle,بنية _wfinddata32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *پیدا_کن_داده);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *پیدا_کن_داده);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t پیدا_کن_Handle,بنية _wfinddata32i64_t *پیدا_کن_داده);
  صحيح __cdecl _wfindnext64i32(intptr_t پیدا_کن_Handle,بنية _wfinddata64i32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t پیدا_کن_Handle,بنية _wfinddata64_t *پیدا_کن_داده);
#پایان_اگر
  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);
#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح Permission_نما = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_نما = 0);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WLOCALE_DEFINED
#تعریف_کن _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحيح _Category,ثابت wchar_t *_Locale);
#پایان_اگر

#اگر_تعریف_نشده _WPROCESS_DEFINED
#تعریف_کن _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحيح نما_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#اگر_تعریف_نشده _CRT_WSYSTEM_DEFINED
#تعریف_کن _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WCTYPE_INLINE_DEFINED
#لغو_تعریف _CRT_WCTYPE_NOINLINE
#إذا !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#تعریف_کن iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کن iswupper(_c) (iswctype(_c,فوقانی_3))
#تعریف_کن iswlower(_c) (iswctype(_c,پایینی_2))
#تعریف_کن iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کن iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کن iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کن iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کن iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کن iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کن iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کن iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کن iswascii(_c) ((بیعلامت)(_c) < 0x80)

#تعریف_کن _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#تعریف_کن _iswupper_l(_c,_p) (_iswctype_l(_c,فوقانی_3,_p))
#تعریف_کن _iswlower_l(_c,_p) (_iswctype_l(_c,پایینی_2,_p))
#تعریف_کن _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#تعریف_کن _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#تعریف_کن _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#تعریف_کن _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#تعریف_کن _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#تعریف_کن _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کن _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کن _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS
#تعریف_کن isleadbyte(_c) (__PCTYPE_FUNC[(بیعلامت حرف)(_c)] & _LEADBYTE)
#پایان_اگر
#پایان_اگر
#تعریف_کن _WCTYPE_INLINE_DEFINED
#پایان_اگر

#إذا !defined(_POSIX_) || defined(__GNUC__)
#اگر_تعریف_نشده _INO_T_DEFINED
#تعریف_کن _INO_T_DEFINED
  تعريفنوع بیعلامت کوتاه _ino_t;
#اگر_تعریف_نشده	NO_OLDNAMES
  تعريفنوع بیعلامت کوتاه ino_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _DEV_T_DEFINED
#تعریف_کن _DEV_T_DEFINED
  تعريفنوع بیعلامت صحيح _dev_t;
#اگر_تعریف_نشده	NO_OLDNAMES
  تعريفنوع بیعلامت صحيح dev_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _OFF_T_DEFINED
#تعریف_کن _OFF_T_DEFINED
#اگر_تعریف_نشده _OFF_T_
#تعریف_کن _OFF_T_
  تعريفنوع دراز _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز off_t;
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _OFF64_T_DEFINED
#تعریف_کن _OFF64_T_DEFINED
  تعريفنوع دراز دراز _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز دراز off64_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _STAT_DEFINED
#تعریف_کن _STAT_DEFINED

#اگر_تعریف_شده USE_32_بیت_زمان_T
#اگر_تعریف_شده WIN64
#تعریف_کن _fstat _fstat32
#تعریف_کن _stat _stat32
#تعریف_کن _wstat _wstat32
#وإلا
#تعریف_کن _fstat32 _fstat
#تعریف_کن _stat32 _stat
#تعریف_کن _wstat32 _wstat
#پایان_اگر
#تعریف_کن _fstati64 _fstat32i64
#تعریف_کن _stati64 _stat32i64
#تعریف_کن _wstati64 _wstat32i64
#وإلا
#تعریف_کن _fstat _fstat64i32
#تعریف_کن _fstati64 _fstat64
#تعریف_کن _stat _stat64i32
#تعریف_کن _stati64 _stat64
#تعریف_کن _wstat _wstat64i32
#تعریف_کن _wstati64 _wstat64
#پایان_اگر

  بنية _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#اگر_تعریف_نشده	NO_OLDNAMES
  بنية stat {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 64

  بنية _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    __int64 st_اندازه;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  بنية _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  بنية _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    __int64 st_اندازه;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#پایان_اگر

#تعریف_کن __stat64 _stat64

#پایان_اگر

#اگر_تعریف_نشده _WSTAT_DEFINED
#تعریف_کن _WSTAT_DEFINED

  _CRTIMP صحيح __cdecl _wstat32(ثابت wchar_t *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP صحيح __cdecl _wstat32i64(ثابت wchar_t *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _wstat64i32(ثابت wchar_t *_Name,بنية _stat64i32 *_Stat);
  _CRTIMP صحيح __cdecl _wstat64(ثابت wchar_t *_Name,بنية _stat64 *_Stat);
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WCONIO_DEFINED
#تعریف_کن _WCONIO_DEFINED

#اگر_تعریف_نشده WEOF
#تعریف_کن WEOF (wint_t)(0xFFFF)
#پایان_اگر

  _CRTIMP wchar_t *_cgetws(wchar_t *میانگیر_2);
  _CRTIMP wint_t __cdecl _getwch(فراغ);
  _CRTIMP wint_t __cdecl _getwche(فراغ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP صحيح __cdecl _cputws(ثابت wchar_t *_String);
  _CRTIMP صحيح __cdecl _cwprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vcwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);

  _CRTIMP صحيح __cdecl _cwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(فراغ);
  wint_t __cdecl _getwche_nolock(فراغ);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#پایان_اگر

#اگر_تعریف_نشده _WSTDIO_DEFINED
#تعریف_کن _WSTDIO_DEFINED

#اگر_تعریف_نشده WEOF
#تعریف_کن WEOF (wint_t)(0xFFFF)
#پایان_اگر

#اگر_تعریف_شده _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3);
#وإلا
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3,صحيح _ShFlag);
#پایان_اگر

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(فراغ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(فراغ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحيح اندازه_درون_واژگان,FILE *_File);
  صحيح __cdecl fputws(ثابت wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP صحيح __cdecl _putws(ثابت wchar_t *_Str);
  صحيح __cdecl fwprintf(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl wprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _scwprintf(ثابت wchar_t *_Format,...);
  صحيح __cdecl vfwprintf(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl vwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl swprintf(wchar_t*, ثابت wchar_t*, ...);
  _CRTIMP صحيح __cdecl vswprintf(wchar_t*, ثابت wchar_t*,va_list);
  _CRTIMP صحيح __cdecl _swprintf_c(wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_c(wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf(wchar_t *_Dest,اندازه_t شمار_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf(wchar_t *_Dest,اندازه_t شمار_5,ثابت wchar_t *_Format,va_list آرگومانها_2);
#اگر_تعریف_نشده __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snwprintf (wchar_t *s, اندازه_t n, ثابت wchar_t * format, ...);
  __CRT_INLINE صحيح __cdecl vsnwprintf (wchar_t *s, اندازه_t n, ثابت wchar_t *format, va_list arg) { أرجع _vsnwprintf(s,n,format,arg); }
  صحيح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحيح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحيح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#پایان_اگر
  _CRTIMP صحيح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_p(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_p(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vscwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _wprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _wprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _fwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _fwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vfwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vfwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_c_l(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swprintf_p_l(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_l(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list آرگومانها_2);
  _CRTIMP صحيح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحيح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list آرگومانها_2);
#اگر_تعریف_نشده RC_INVOKED
#ضمن <vadefs.h>
#پایان_اگر

#اگر_تعریف_شده _CRT_NON_CONFORMING_SWPRINTFS
#اگر_تعریف_نشده __cplusplus
#تعریف_کن swprintf _swprintf
#تعریف_کن vswprintf _vswprintf
#تعریف_کن _swprintf_l __swprintf_l
#تعریف_کن _vswprintf_l __vswprintf_l
#پایان_اگر
#پایان_اگر

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_پیشوند);
  _CRTIMP صحيح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  صحيح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحيح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf(ثابت wchar_t *_Src,اندازه_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_l(ثابت wchar_t *_Src,اندازه_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحيح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحيح _FileHandle ,ثابت wchar_t *نما_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3,FILE *_OldFile);

#اگر_تعریف_نشده _CRT_WPERROR_DEFINED
#تعریف_کن _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیام);
#پایان_اگر
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *نما_3);
#إذا !defined(NO_OLDNAMES) && !defined(wpopen)
#تعریف_کن wpopen	_wpopen
#پایان_اگر
  _CRTIMP صحيح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *میانگیر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#لغو_تعریف _CRT_GETPUTWCHAR_NOINLINE

#إذا !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#تعریف_کن getwchar() fgetwc(stdin)
#تعریف_کن putwchar(_c) fputwc((_c),stdout)
#وإلا
  __CRT_INLINE wint_t __cdecl getwchar() {أرجع (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {أرجع (fputwc(_C,stdout)); }
#پایان_اگر

#تعریف_کن getwc(_stm) fgetwc(_stm)
#تعریف_کن putwc(_c,_stm) fputwc(_c,_stm)
#تعریف_کن _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#تعریف_کن _getwc_nolock(_c) _fgetwc_nolock(_c)
#پایان_اگر

#اگر_تعریف_نشده _WSTDLIB_DEFINED
#تعریف_کن _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح مقدار_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(دراز مقدار_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(بیعلامت دراز مقدار_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **انتها_Ptr);
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,_locale_t _Locale);
  عائم __cdecl wcstof( ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  دراز مزدوج __cdecl wcstold (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#پایان_اگر /* __NO_ISOCEXT */
  دراز __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP دراز __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  بیعلامت دراز __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP بیعلامت دراز __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#اگر_تعریف_نشده _CRT_WSYSTEM_DEFINED
#تعریف_کن _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#پایان_اگر
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP دراز __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP دراز __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(بیعلامت __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بیعلامت __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP بیعلامت __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _POSIX_
#اگر_تعریف_نشده _WSTDLIBP_DEFINED
#تعریف_کن _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *پر_مسیر,ثابت wchar_t *مسیر_2,اندازه_t اندازه_درون_واژگان);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *نتیجه_مسیر,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#اگر_تعریف_نشده _CRT_WPERROR_DEFINED
#تعریف_کن _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیام);
#پایان_اگر
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجه_مسیر);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *پر_مسیر,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WSTRING_DEFINED
#تعریف_کن _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *منبع_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحيح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *منبع_3);
  اندازه_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  اندازه_t __cdecl wcslen(ثابت wchar_t *_Str);
  اندازه_t __cdecl wcsnlen(ثابت wchar_t *_Src,اندازه_t Max_شمار);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ثابت wchar_t *منبع_3,اندازه_t شمار_5);
  صحيح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ثابت wchar_t *منبع_3,اندازه_t شمار_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  اندازه_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحيح Err_رقم);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,اندازه_t Max_شمار);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  اندازه_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  صحيح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار,_locale_t _Locale);

#اگر_تعریف_نشده	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#تعریف_کن wcswcs wcsstr
  صحيح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحيح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,اندازه_t Max_شمار);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحيح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _TM_DEFINED
#تعریف_کن _TM_DEFINED
  بنية tm {
    صحيح tm_sec;
    صحيح tm_min;
    صحيح tm_hour;
    صحيح tm_mday;
    صحيح tm_mon;
    صحيح tm_year;
    صحيح tm_wday;
    صحيح tm_yday;
    صحيح tm_isdst;
  };
#پایان_اگر

#اگر_تعریف_نشده _WTIME_DEFINED
#تعریف_کن _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *زمان_2);
  اندازه_t __cdecl wcsftime(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP اندازه_t __cdecl _wcsftime_l(wchar_t *_Buf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *میانگیر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *میانگیر_2);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *زمان_2);
#پایان_اگر

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#تعریف_کن _INC_WTIME_INL
#اگر_تعریف_شده USE_32_بیت_زمان_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *زمان_2) { أرجع _wctime32(زمان_2); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *زمان_2) { أرجع _wctime64(زمان_2); }
#پایان_اگر
#پایان_اگر
#پایان_اگر

  تعريفنوع صحيح mbstate_t;
  تعريفنوع wchar_t _Wint_t;

  wint_t __cdecl btowc(صحيح);
  اندازه_t __cdecl mbrlen(ثابت حرف *_Ch,اندازه_t اندازه_درون_بایتها,mbstate_t *_State);
  اندازه_t __cdecl mbrtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,اندازه_t اندازه_درون_بایتها,mbstate_t *_State);
  اندازه_t __cdecl mbsrtowcs(wchar_t *_Dest,ثابت حرف **_PSrc,اندازه_t شمار_5,mbstate_t *_State);
  اندازه_t __cdecl wcrtomb(حرف *_Dest,wchar_t منبع_3,mbstate_t *_State);
  اندازه_t __cdecl wcsrtombs(حرف *_Dest,ثابت wchar_t **_PSource,اندازه_t شمار_5,mbstate_t *_State);
  صحيح __cdecl wctob(wint_t _WCh);

#اگر_تعریف_نشده __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, اندازه_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *s, wchar_t c, اندازه_t n);
  صحيح wmemcmp(ثابت wchar_t *s1, ثابت wchar_t *s2,اندازه_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ثابت wchar_t *s2,اندازه_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ثابت wchar_t *s2, اندازه_t n);
  دراز دراز __cdecl wcstoll(ثابت wchar_t *nptr,wchar_t **endptr, صحيح پایه);
  بیعلامت دراز دراز __cdecl wcstoull(ثابت wchar_t *nptr,wchar_t **endptr, صحيح پایه);
#پایان_اگر /* __NO_ISOCEXT */

  فراغ *__cdecl memmove(فراغ *_Dst,ثابت فراغ *_Src,اندازه_t Max_شمار);
  فراغ *__cdecl کپی_حافظه(فراغ *_Dst,ثابت فراغ *_Src,اندازه_t Max_شمار);
  __CRT_INLINE صحيح __cdecl fwide(FILE *_F,صحيح _M) { (فراغ)_F; أرجع (_M); }
  __CRT_INLINE صحيح __cdecl mbsinit(ثابت mbstate_t *_P) { أرجع (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *_S,wchar_t _C,اندازه_t _N) { لكل (;0<_N;++_S,--_N) إذا (*_S==_C) أرجع (_CONST_RETURN wchar_t *)(_S); أرجع (0); }
  __CRT_INLINE صحيح __cdecl wmemcmp(ثابت wchar_t *_S1,ثابت wchar_t *_S2,اندازه_t _N) { لكل (; 0 < _N; ++_S1,++_S2,--_N) إذا (*_S1!=*_S2) أرجع (*_S1 < *_S2 ? -1 : +1); أرجع (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ثابت wchar_t *_S2,اندازه_t _N) { أرجع (wchar_t *)کپی_حافظه(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ثابت wchar_t *_S2,اندازه_t _N) { أرجع (wchar_t *)memmove(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,اندازه_t _N) {
    wchar_t *_Su = _S;
    لكل (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    أرجع (_S);
  }
#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)

#ضمن <sec_api/wchar_s.h>
#پایان_اگر
