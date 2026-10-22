/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_WCHAR
#تعریف_کرو _INC_WCHAR

#ضمن <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف WCHAR_MIN  /* also at stdint.h */
#تعریف_کرو WCHAR_MIN 0
#تعریف_کرو WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#جے_انت

#جے_بنا_تعریف __GNUC_VA_LIST
#تعریف_کرو __GNUC_VA_LIST
  تعريفنوع __builtin_va_list __gnuc_va_list;
#جے_انت

#جے_بنا_تعریف _VA_LIST_DEFINED
#تعریف_کرو _VA_LIST_DEFINED
  تعريفنوع __gnuc_va_list va_list;
#جے_انت

#جے_بنا_تعریف WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#جے_انت

#جے_بنا_تعریف _FILE_DEFINED
  بنية _iobuf {
    حرف *_ptr;
    صحيح _cnt;
    حرف *ادھار_4;
    صحيح _flag;
    صحيح _file;
    صحيح _charbuf;
    صحيح _bufsiz;
    حرف *_tmpfname;
  };
  تعريفنوع بنية _iobuf FILE;
#تعریف_کرو _FILE_DEFINED
#جے_انت

#جے_بنا_تعریف _STDIO_DEFINED
#جے_تعریف_شدہ _WIN64
  _CRTIMP FILE *__cdecl __iob_func(فراغ);
#وإلا
#جے_تعریف_شدہ _MSVCRT_
خارجي FILE _iob[];	/* A pointer to an array of FILE */
#تعریف_کرو __iob_func()	(_iob)
#وإلا
خارجي FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#تعریف_کرو __iob_func()	(*_imp___iob)
#تعریف_کرو _iob __iob_func()
#جے_انت
#جے_انت

#تعریف_کرو _iob __iob_func()
#جے_انت

#جے_بنا_تعریف _STDSTREAM_DEFINED
#تعریف_کرو stdin (&__iob_func()[0])
#تعریف_کرو stdout (&__iob_func()[1])
#تعریف_کرو stderr (&__iob_func()[2])
#تعریف_کرو _STDSTREAM_DEFINED
#جے_انت

#جے_بنا_تعریف _FSIZE_T_DEFINED
  تعريفنوع بنانشانی لما _fsize_t;
#تعریف_کرو _FSIZE_T_DEFINED
#جے_انت

#جے_بنا_تعریف _WFINDDATA_T_DEFINED
  بنية _wfinddata32_t {
    بنانشانی attrib;
    __time32_t ویلا_create;
    __time32_t ویلا_access;
    __time32_t ویلا_write;
    _fsize_t ناپ;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    بنانشانی attrib;
    __time32_t ویلا_create;
    __time32_t ویلا_access;
    __time32_t ویلا_write;
    __int64 ناپ;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    بنانشانی attrib;
    __time64_t ویلا_create;
    __time64_t ویلا_access;
    __time64_t ویلا_write;
    _fsize_t ناپ;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
    بنانشانی attrib;
    __time64_t ویلا_create;
    __time64_t ویلا_access;
    __time64_t ویلا_write;
    __int64 ناپ;
    wchar_t name[260];
  };
/* #endif */

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#تعریف_کرو _wfinddata_t _wfinddata32_t
#تعریف_کرو _wfinddatai64_t _wfinddata32i64_t

#تعریف_کرو _wfindfirst _wfindfirst32
#تعریف_کرو _wfindnext _wfindnext32
#تعریف_کرو _wfindfirsti64 _wfindfirst32i64
#تعریف_کرو _wfindnexti64 _wfindnext32i64
#وإلا
#تعریف_کرو _wfinddata_t _wfinddata64i32_t
#تعریف_کرو _wfinddatai64_t _wfinddata64_t

#تعریف_کرو _wfindfirst _wfindfirst64i32
#تعریف_کرو _wfindnext _wfindnext64i32
#تعریف_کرو _wfindfirsti64 _wfindfirst64
#تعریف_کرو _wfindnexti64 _wfindnext64
#جے_انت

#تعریف_کرو _WFINDDATA_T_DEFINED
#جے_انت

#جے_بنا_تعریف عدم
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو عدم 0
#وإلا
#تعریف_کرو عدم ((فراغ *)0)
#جے_انت
#جے_انت

#جے_بنا_تعریف _CONST_RETURN
#تعریف_کرو _CONST_RETURN
#جے_انت

#تعریف_کرو _WConst_return _CONST_RETURN

#جے_بنا_تعریف _CRT_CTYPEDATA_DEFINED
#تعریف_کرو _CRT_CTYPEDATA_DEFINED
#جے_بنا_تعریف _CTYPE_DISABLE_MACROS

#جے_بنا_تعریف __PCTYPE_FUNC
#تعریف_کرو __PCTYPE_FUNC __pctype_func()
#جے_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pctype_func() (_pctype)
#وإلا
#تعریف_کرو __pctype_func() (*_imp___pctype)
#جے_انت
#جے_انت

#جے_بنا_تعریف _pctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_pctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___pctype;
#تعریف_کرو _pctype (*_imp___pctype)
#جے_انت
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _CRT_WCTYPEDATA_DEFINED
#تعریف_کرو _CRT_WCTYPEDATA_DEFINED
#جے_بنا_تعریف _CTYPE_DISABLE_MACROS
#جے_بنا_تعریف _wctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_wctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___wctype;
#تعریف_کرو _wctype (*_imp___wctype)
#جے_انت
#جے_انت

#جے_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pwctype_func() (_pwctype)
#وإلا
#تعریف_کرو __pwctype_func() (*_imp___pwctype)
#جے_انت

#جے_بنا_تعریف _pwctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_pwctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___pwctype;
#تعریف_کرو _pwctype (*_imp___pwctype)
#جے_انت
#جے_انت

#جے_انت
#جے_انت

#تعریف_کرو اتلا_3 0x1
#تعریف_کرو ہیٹھلا_2 0x2
#تعریف_کرو _DIGIT 0x4
#تعریف_کرو _SPACE 0x8

#تعریف_کرو _PUNCT 0x10
#تعریف_کرو _CONTROL 0x20
#تعریف_کرو _BLANK 0x40
#تعریف_کرو _HEX 0x80

#تعریف_کرو _LEADBYTE 0x8000
#تعریف_کرو _ALPHA (0x0100|اتلا_3|ہیٹھلا_2)

#جے_بنا_تعریف _WCTYPE_DEFINED
#تعریف_کرو _WCTYPE_DEFINED

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
#جے_انت

#جے_بنا_تعریف _WDIRECT_DEFINED
#تعریف_کرو _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح ناپ_وچ_الفاظ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح ناپ_وچ_الفاظ);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح ناپ_وچ_الفاظ);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *رستہ_2);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *رستہ_2);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *رستہ_2);
#جے_انت

#جے_بنا_تعریف _WIO_DEFINED
#تعریف_کرو _WIO_DEFINED

  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح Access_منوال);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح منوال_3);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح Permission_منوال);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t لبھو_Handle,بنية _wfinddata32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *لبھو_انکڑے);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *لبھو_انکڑے);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t لبھو_Handle,بنية _wfinddata32i64_t *لبھو_انکڑے);
  صحيح __cdecl _wfindnext64i32(intptr_t لبھو_Handle,بنية _wfinddata64i32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t لبھو_Handle,بنية _wfinddata64_t *لبھو_انکڑے);
#جے_انت
  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);
#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح Permission_منوال = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_منوال = 0);
#جے_انت
#جے_انت

#جے_بنا_تعریف _WLOCALE_DEFINED
#تعریف_کرو _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحيح _Category,ثابت wchar_t *_Locale);
#جے_انت

#جے_بنا_تعریف _WPROCESS_DEFINED
#تعریف_کرو _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#جے_بنا_تعریف _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جے_انت
#جے_انت

#جے_بنا_تعریف _WCTYPE_INLINE_DEFINED
#تعریف_رد _CRT_WCTYPE_NOINLINE
#إذا !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#تعریف_کرو iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کرو iswupper(_c) (iswctype(_c,اتلا_3))
#تعریف_کرو iswlower(_c) (iswctype(_c,ہیٹھلا_2))
#تعریف_کرو iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کرو iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کرو iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کرو iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کرو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کرو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کرو iswascii(_c) ((بنانشانی)(_c) < 0x80)

#تعریف_کرو _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#تعریف_کرو _iswupper_l(_c,_p) (_iswctype_l(_c,اتلا_3,_p))
#تعریف_کرو _iswlower_l(_c,_p) (_iswctype_l(_c,ہیٹھلا_2,_p))
#تعریف_کرو _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#تعریف_کرو _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#تعریف_کرو _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#تعریف_کرو _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#تعریف_کرو _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#جے_بنا_تعریف _CTYPE_DISABLE_MACROS
#تعریف_کرو isleadbyte(_c) (__PCTYPE_FUNC[(بنانشانی حرف)(_c)] & _LEADBYTE)
#جے_انت
#جے_انت
#تعریف_کرو _WCTYPE_INLINE_DEFINED
#جے_انت

#إذا !defined(_POSIX_) || defined(__GNUC__)
#جے_بنا_تعریف _INO_T_DEFINED
#تعریف_کرو _INO_T_DEFINED
  تعريفنوع بنانشانی چھوٹا _ino_t;
#جے_بنا_تعریف	NO_OLDNAMES
  تعريفنوع بنانشانی چھوٹا ino_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _DEV_T_DEFINED
#تعریف_کرو _DEV_T_DEFINED
  تعريفنوع بنانشانی صحيح _dev_t;
#جے_بنا_تعریف	NO_OLDNAMES
  تعريفنوع بنانشانی صحيح dev_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _OFF_T_DEFINED
#تعریف_کرو _OFF_T_DEFINED
#جے_بنا_تعریف _OFF_T_
#تعریف_کرو _OFF_T_
  تعريفنوع لما _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع لما off_t;
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _OFF64_T_DEFINED
#تعریف_کرو _OFF64_T_DEFINED
  تعريفنوع لما لما _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع لما لما off64_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _STAT_DEFINED
#تعریف_کرو _STAT_DEFINED

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#جے_تعریف_شدہ WIN64
#تعریف_کرو _fstat _fstat32
#تعریف_کرو _stat _stat32
#تعریف_کرو _wstat _wstat32
#وإلا
#تعریف_کرو _fstat32 _fstat
#تعریف_کرو _stat32 _stat
#تعریف_کرو _wstat32 _wstat
#جے_انت
#تعریف_کرو _fstati64 _fstat32i64
#تعریف_کرو _stati64 _stat32i64
#تعریف_کرو _wstati64 _wstat32i64
#وإلا
#تعریف_کرو _fstat _fstat64i32
#تعریف_کرو _fstati64 _fstat64
#تعریف_کرو _stat _stat64i32
#تعریف_کرو _stati64 _stat64
#تعریف_کرو _wstat _wstat64i32
#تعریف_کرو _wstati64 _wstat64
#جے_انت

  بنية _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    _off_t st_ناپ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#جے_بنا_تعریف	NO_OLDNAMES
  بنية stat {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    _off_t st_ناپ;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 64

  بنية _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    __int64 st_ناپ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  بنية _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    _off_t st_ناپ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  بنية _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    __int64 st_ناپ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#جے_انت

#تعریف_کرو __stat64 _stat64

#جے_انت

#جے_بنا_تعریف _WSTAT_DEFINED
#تعریف_کرو _WSTAT_DEFINED

  _CRTIMP صحيح __cdecl _wstat32(ثابت wchar_t *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحيح __cdecl _wstat32i64(ثابت wchar_t *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _wstat64i32(ثابت wchar_t *_Name,بنية _stat64i32 *_Stat);
  _CRTIMP صحيح __cdecl _wstat64(ثابت wchar_t *_Name,بنية _stat64 *_Stat);
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _WCONIO_DEFINED
#تعریف_کرو _WCONIO_DEFINED

#جے_بنا_تعریف WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#جے_انت

  _CRTIMP wchar_t *_cgetws(wchar_t *بفر_2);
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
#جے_انت

#جے_بنا_تعریف _WSTDIO_DEFINED
#تعریف_کرو _WSTDIO_DEFINED

#جے_بنا_تعریف WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#جے_انت

#جے_تعریف_شدہ _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
#وإلا
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,صحيح _ShFlag);
#جے_انت

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(فراغ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(فراغ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحيح ناپ_وچ_الفاظ,FILE *_File);
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
  _CRTIMP صحيح __cdecl _swprintf_c(wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_c(wchar_t *_DstBuf,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf(wchar_t *_Dest,ناپ_t گنتی_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf(wchar_t *_Dest,ناپ_t گنتی_5,ثابت wchar_t *_Format,va_list دلیلاں_2);
#جے_بنا_تعریف __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snwprintf (wchar_t *s, ناپ_t n, ثابت wchar_t * format, ...);
  __CRT_INLINE صحيح __cdecl vsnwprintf (wchar_t *s, ناپ_t n, ثابت wchar_t *format, va_list arg) { أرجع _vsnwprintf(s,n,format,arg); }
  صحيح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحيح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحيح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#جے_انت
  _CRTIMP صحيح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_p(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_p(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,va_list _ArgList);
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
  _CRTIMP صحيح __cdecl _swprintf_c_l(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swprintf_p_l(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_l(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list دلیلاں_2);
  _CRTIMP صحيح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحيح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list دلیلاں_2);
#جے_بنا_تعریف RC_INVOKED
#ضمن <vadefs.h>
#جے_انت

#جے_تعریف_شدہ _CRT_NON_CONFORMING_SWPRINTFS
#جے_بنا_تعریف __cplusplus
#تعریف_کرو swprintf _swprintf
#تعریف_کرو vswprintf _vswprintf
#تعریف_کرو _swprintf_l __swprintf_l
#تعریف_کرو _vswprintf_l __vswprintf_l
#جے_انت
#جے_انت

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_اگیتر);
  _CRTIMP صحيح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  صحيح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحيح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf(ثابت wchar_t *_Src,ناپ_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_l(ثابت wchar_t *_Src,ناپ_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحيح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحيح _FileHandle ,ثابت wchar_t *منوال_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,FILE *_OldFile);

#جے_بنا_تعریف _CRT_WPERROR_DEFINED
#تعریف_کرو _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#جے_انت
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *منوال_3);
#إذا !defined(NO_OLDNAMES) && !defined(wpopen)
#تعریف_کرو wpopen	_wpopen
#جے_انت
  _CRTIMP صحيح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#تعریف_رد _CRT_GETPUTWCHAR_NOINLINE

#إذا !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#تعریف_کرو getwchar() fgetwc(stdin)
#تعریف_کرو putwchar(_c) fputwc((_c),stdout)
#وإلا
  __CRT_INLINE wint_t __cdecl getwchar() {أرجع (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {أرجع (fputwc(_C,stdout)); }
#جے_انت

#تعریف_کرو getwc(_stm) fgetwc(_stm)
#تعریف_کرو putwc(_c,_stm) fputwc(_c,_stm)
#تعریف_کرو _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#تعریف_کرو _getwc_nolock(_c) _fgetwc_nolock(_c)
#جے_انت

#جے_بنا_تعریف _WSTDLIB_DEFINED
#تعریف_کرو _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(لما قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(بنانشانی لما قدر_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **سرا_Ptr);
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,_locale_t _Locale);
  عائم __cdecl wcstof( ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  لما مزدوج __cdecl wcstold (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#جے_انت /* __NO_ISOCEXT */
  لما __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP لما __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  بنانشانی لما __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP بنانشانی لما __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#جے_بنا_تعریف _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جے_انت
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP لما __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP لما __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(بنانشانی __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بنانشانی __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP بنانشانی __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
#جے_انت
#جے_انت

#جے_بنا_تعریف _POSIX_
#جے_بنا_تعریف _WSTDLIBP_DEFINED
#تعریف_کرو _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *بھریا_رستہ,ثابت wchar_t *رستہ_2,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *نتیجہ_رستہ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#جے_بنا_تعریف _CRT_WPERROR_DEFINED
#تعریف_کرو _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#جے_انت
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_رستہ);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *بھریا_رستہ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#جے_انت
#جے_انت

#جے_بنا_تعریف _WSTRING_DEFINED
#تعریف_کرو _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *سروت_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحيح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *سروت_3);
  ناپ_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  ناپ_t __cdecl wcslen(ثابت wchar_t *_Str);
  ناپ_t __cdecl wcsnlen(ثابت wchar_t *_Src,ناپ_t Max_گنتی);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ثابت wchar_t *سروت_3,ناپ_t گنتی_5);
  صحيح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ثابت wchar_t *سروت_3,ناپ_t گنتی_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  ناپ_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحيح Err_عدد);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی);
  _CRTIMP صحيح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,ناپ_t Max_گنتی);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  ناپ_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,ناپ_t Max_گنتی);
  _CRTIMP ناپ_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,ناپ_t Max_گنتی,_locale_t _Locale);
  صحيح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی);
  _CRTIMP صحيح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی);
  _CRTIMP صحيح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی,_locale_t _Locale);

#جے_بنا_تعریف	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#تعریف_کرو wcswcs wcsstr
  صحيح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحيح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,ناپ_t Max_گنتی);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,ناپ_t Max_گنتی);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحيح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#جے_انت
#جے_انت

#جے_بنا_تعریف _TM_DEFINED
#تعریف_کرو _TM_DEFINED
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
#جے_انت

#جے_بنا_تعریف _WTIME_DEFINED
#تعریف_کرو _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *ویلا_2);
  ناپ_t __cdecl wcsftime(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP ناپ_t __cdecl _wcsftime_l(wchar_t *_Buf,ناپ_t ناپ_وچ_الفاظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *بفر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *بفر_2);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *ویلا_2);
#جے_انت

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#تعریف_کرو _INC_WTIME_INL
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *ویلا_2) { أرجع _wctime32(ویلا_2); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *ویلا_2) { أرجع _wctime64(ویلا_2); }
#جے_انت
#جے_انت
#جے_انت

  تعريفنوع صحيح mbstate_t;
  تعريفنوع wchar_t _Wint_t;

  wint_t __cdecl btowc(صحيح);
  ناپ_t __cdecl mbrlen(ثابت حرف *_Ch,ناپ_t ناپ_وچ_بائٹاں,mbstate_t *_State);
  ناپ_t __cdecl mbrtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,ناپ_t ناپ_وچ_بائٹاں,mbstate_t *_State);
  ناپ_t __cdecl mbsrtowcs(wchar_t *_Dest,ثابت حرف **_PSrc,ناپ_t گنتی_5,mbstate_t *_State);
  ناپ_t __cdecl wcrtomb(حرف *_Dest,wchar_t سروت_3,mbstate_t *_State);
  ناپ_t __cdecl wcsrtombs(حرف *_Dest,ثابت wchar_t **_PSource,ناپ_t گنتی_5,mbstate_t *_State);
  صحيح __cdecl wctob(wint_t _WCh);

#جے_بنا_تعریف __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, ناپ_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *s, wchar_t c, ناپ_t n);
  صحيح wmemcmp(ثابت wchar_t *s1, ثابت wchar_t *s2,ناپ_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ثابت wchar_t *s2,ناپ_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ثابت wchar_t *s2, ناپ_t n);
  لما لما __cdecl wcstoll(ثابت wchar_t *nptr,wchar_t **endptr, صحيح ادھار);
  بنانشانی لما لما __cdecl wcstoull(ثابت wchar_t *nptr,wchar_t **endptr, صحيح ادھار);
#جے_انت /* __NO_ISOCEXT */

  فراغ *__cdecl memmove(فراغ *_Dst,ثابت فراغ *_Src,ناپ_t Max_گنتی);
  فراغ *__cdecl حافظہ_نقل(فراغ *_Dst,ثابت فراغ *_Src,ناپ_t Max_گنتی);
  __CRT_INLINE صحيح __cdecl fwide(FILE *_F,صحيح _M) { (فراغ)_F; أرجع (_M); }
  __CRT_INLINE صحيح __cdecl mbsinit(ثابت mbstate_t *_P) { أرجع (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *_S,wchar_t _C,ناپ_t _N) { لكل (;0<_N;++_S,--_N) إذا (*_S==_C) أرجع (_CONST_RETURN wchar_t *)(_S); أرجع (0); }
  __CRT_INLINE صحيح __cdecl wmemcmp(ثابت wchar_t *_S1,ثابت wchar_t *_S2,ناپ_t _N) { لكل (; 0 < _N; ++_S1,++_S2,--_N) إذا (*_S1!=*_S2) أرجع (*_S1 < *_S2 ? -1 : +1); أرجع (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ثابت wchar_t *_S2,ناپ_t _N) { أرجع (wchar_t *)حافظہ_نقل(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ثابت wchar_t *_S2,ناپ_t _N) { أرجع (wchar_t *)memmove(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,ناپ_t _N) {
    wchar_t *_Su = _S;
    لكل (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    أرجع (_S);
  }
#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)

#ضمن <sec_api/wchar_s.h>
#جے_انت
