/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_WCHAR
#وصف_ڪريو _INC_WCHAR

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WCHAR_MIN  /* also at stdint.h */
#وصف_ڪريو WCHAR_MIN 0
#وصف_ڪريو WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __GNUC_VA_LIST
#وصف_ڪريو __GNUC_VA_LIST
  تعريفنوع __builtin_va_list __gnuc_va_list;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _VA_LIST_DEFINED
#وصف_ڪريو _VA_LIST_DEFINED
  تعريفنوع __gnuc_va_list va_list;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WEOF
#وصف_ڪريو WEOF (wint_t)(0xFFFF)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _FILE_DEFINED
  بنية _iobuf {
    حرف *_ptr;
    صحيح _cnt;
    حرف *بنياد_4;
    صحيح _flag;
    صحيح _file;
    صحيح _charbuf;
    صحيح _bufsiz;
    حرف *_tmpfname;
  };
  تعريفنوع بنية _iobuf FILE;
#وصف_ڪريو _FILE_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _STDIO_DEFINED
#جيڪڏهن_وصف_ٿيل _WIN64
  _CRTIMP FILE *__cdecl __iob_func(فراغ);
#وإلا
#جيڪڏهن_وصف_ٿيل _MSVCRT_
خارجي FILE _iob[];	/* A pointer to an array of FILE */
#وصف_ڪريو __iob_func()	(_iob)
#وإلا
خارجي FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#وصف_ڪريو __iob_func()	(*_imp___iob)
#وصف_ڪريو _iob __iob_func()
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو _iob __iob_func()
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _STDSTREAM_DEFINED
#وصف_ڪريو stdin (&__iob_func()[0])
#وصف_ڪريو stdout (&__iob_func()[1])
#وصف_ڪريو stderr (&__iob_func()[2])
#وصف_ڪريو _STDSTREAM_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _FSIZE_T_DEFINED
  تعريفنوع بنانشان ڊگهو _fsize_t;
#وصف_ڪريو _FSIZE_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WFINDDATA_T_DEFINED
  بنية _wfinddata32_t {
    بنانشان attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    _fsize_t سائيز;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    بنانشان attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    __int64 سائيز;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    بنانشان attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    _fsize_t سائيز;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
    بنانشان attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    __int64 سائيز;
    wchar_t name[260];
  };
/* #endif */

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#وصف_ڪريو _wfinddata_t _wfinddata32_t
#وصف_ڪريو _wfinddatai64_t _wfinddata32i64_t

#وصف_ڪريو _wfindfirst _wfindfirst32
#وصف_ڪريو _wfindnext _wfindnext32
#وصف_ڪريو _wfindfirsti64 _wfindfirst32i64
#وصف_ڪريو _wfindnexti64 _wfindnext32i64
#وإلا
#وصف_ڪريو _wfinddata_t _wfinddata64i32_t
#وصف_ڪريو _wfinddatai64_t _wfinddata64_t

#وصف_ڪريو _wfindfirst _wfindfirst64i32
#وصف_ڪريو _wfindnext _wfindnext64i32
#وصف_ڪريو _wfindfirsti64 _wfindfirst64
#وصف_ڪريو _wfindnexti64 _wfindnext64
#جيڪڏهن_پورو

#وصف_ڪريو _WFINDDATA_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل عدم
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو عدم 0
#وإلا
#وصف_ڪريو عدم ((فراغ *)0)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CONST_RETURN
#وصف_ڪريو _CONST_RETURN
#جيڪڏهن_پورو

#وصف_ڪريو _WConst_return _CONST_RETURN

#جيڪڏهن_وصف_نه_ٿيل _CRT_CTYPEDATA_DEFINED
#وصف_ڪريو _CRT_CTYPEDATA_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS

#جيڪڏهن_وصف_نه_ٿيل __PCTYPE_FUNC
#وصف_ڪريو __PCTYPE_FUNC __pctype_func()
#جيڪڏهن_وصف_ٿيل _MSVCRT_
#وصف_ڪريو __pctype_func() (_pctype)
#وإلا
#وصف_ڪريو __pctype_func() (*_imp___pctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _pctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_pctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___pctype;
#وصف_ڪريو _pctype (*_imp___pctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_WCTYPEDATA_DEFINED
#وصف_ڪريو _CRT_WCTYPEDATA_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS
#جيڪڏهن_وصف_نه_ٿيل _wctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_wctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___wctype;
#وصف_ڪريو _wctype (*_imp___wctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _MSVCRT_
#وصف_ڪريو __pwctype_func() (_pwctype)
#وإلا
#وصف_ڪريو __pwctype_func() (*_imp___pwctype)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _pwctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_pwctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___pwctype;
#وصف_ڪريو _pwctype (*_imp___pwctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو مٿانهون_3 0x1
#وصف_ڪريو هيٺاهون_2 0x2
#وصف_ڪريو _DIGIT 0x4
#وصف_ڪريو _SPACE 0x8

#وصف_ڪريو _PUNCT 0x10
#وصف_ڪريو _CONTROL 0x20
#وصف_ڪريو _BLANK 0x40
#وصف_ڪريو _HEX 0x80

#وصف_ڪريو _LEADBYTE 0x8000
#وصف_ڪريو _ALPHA (0x0100|مٿانهون_3|هيٺاهون_2)

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_DEFINED
#وصف_ڪريو _WCTYPE_DEFINED

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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WDIRECT_DEFINED
#وصف_ڪريو _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح سائيز_اندريون_لفظ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح سائيز_اندريون_لفظ);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح سائيز_اندريون_لفظ);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *رستو_2);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *رستو_2);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *رستو_2);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WIO_DEFINED
#وصف_ڪريو _WIO_DEFINED

  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح Access_گهڻائي);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح گهڻائي_3);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح Permission_گهڻائي);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t ڳوليو_Handle,بنية _wfinddata32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *ڳوليو_معلومات);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *ڳوليو_معلومات);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t ڳوليو_Handle,بنية _wfinddata32i64_t *ڳوليو_معلومات);
  صحيح __cdecl _wfindnext64i32(intptr_t ڳوليو_Handle,بنية _wfinddata64i32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t ڳوليو_Handle,بنية _wfinddata64_t *ڳوليو_معلومات);
#جيڪڏهن_پورو
  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);
#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح Permission_گهڻائي = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_گهڻائي = 0);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WLOCALE_DEFINED
#وصف_ڪريو _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحيح _Category,ثابت wchar_t *_Locale);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WPROCESS_DEFINED
#وصف_ڪريو _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#جيڪڏهن_وصف_نه_ٿيل _CRT_WSYSTEM_DEFINED
#وصف_ڪريو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_INLINE_DEFINED
#وصف_رد _CRT_WCTYPE_NOINLINE
#إذا !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#وصف_ڪريو iswalpha(_c) (iswctype(_c,_ALPHA))
#وصف_ڪريو iswupper(_c) (iswctype(_c,مٿانهون_3))
#وصف_ڪريو iswlower(_c) (iswctype(_c,هيٺاهون_2))
#وصف_ڪريو iswdigit(_c) (iswctype(_c,_DIGIT))
#وصف_ڪريو iswxdigit(_c) (iswctype(_c,_HEX))
#وصف_ڪريو iswspace(_c) (iswctype(_c,_SPACE))
#وصف_ڪريو iswpunct(_c) (iswctype(_c,_PUNCT))
#وصف_ڪريو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#وصف_ڪريو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#وصف_ڪريو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#وصف_ڪريو iswcntrl(_c) (iswctype(_c,_CONTROL))
#وصف_ڪريو iswascii(_c) ((بنانشان)(_c) < 0x80)

#وصف_ڪريو _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#وصف_ڪريو _iswupper_l(_c,_p) (_iswctype_l(_c,مٿانهون_3,_p))
#وصف_ڪريو _iswlower_l(_c,_p) (_iswctype_l(_c,هيٺاهون_2,_p))
#وصف_ڪريو _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#وصف_ڪريو _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#وصف_ڪريو _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#وصف_ڪريو _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#وصف_ڪريو _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#وصف_ڪريو _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#وصف_ڪريو _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#وصف_ڪريو _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS
#وصف_ڪريو isleadbyte(_c) (__PCTYPE_FUNC[(بنانشان حرف)(_c)] & _LEADBYTE)
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#وصف_ڪريو _WCTYPE_INLINE_DEFINED
#جيڪڏهن_پورو

#إذا !defined(_POSIX_) || defined(__GNUC__)
#جيڪڏهن_وصف_نه_ٿيل _INO_T_DEFINED
#وصف_ڪريو _INO_T_DEFINED
  تعريفنوع بنانشان ننڍو _ino_t;
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  تعريفنوع بنانشان ننڍو ino_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _DEV_T_DEFINED
#وصف_ڪريو _DEV_T_DEFINED
  تعريفنوع بنانشان صحيح _dev_t;
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  تعريفنوع بنانشان صحيح dev_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _OFF_T_DEFINED
#وصف_ڪريو _OFF_T_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _OFF_T_
#وصف_ڪريو _OFF_T_
  تعريفنوع ڊگهو _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو off_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _OFF64_T_DEFINED
#وصف_ڪريو _OFF64_T_DEFINED
  تعريفنوع ڊگهو ڊگهو _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو ڊگهو off64_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _STAT_DEFINED
#وصف_ڪريو _STAT_DEFINED

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_وصف_ٿيل WIN64
#وصف_ڪريو _fstat _fstat32
#وصف_ڪريو _stat _stat32
#وصف_ڪريو _wstat _wstat32
#وإلا
#وصف_ڪريو _fstat32 _fstat
#وصف_ڪريو _stat32 _stat
#وصف_ڪريو _wstat32 _wstat
#جيڪڏهن_پورو
#وصف_ڪريو _fstati64 _fstat32i64
#وصف_ڪريو _stati64 _stat32i64
#وصف_ڪريو _wstati64 _wstat32i64
#وإلا
#وصف_ڪريو _fstat _fstat64i32
#وصف_ڪريو _fstati64 _fstat64
#وصف_ڪريو _stat _stat64i32
#وصف_ڪريو _stati64 _stat64
#وصف_ڪريو _wstat _wstat64i32
#وصف_ڪريو _wstati64 _wstat64
#جيڪڏهن_پورو

  بنية _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    _off_t st_سائيز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  بنية stat {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    _off_t st_سائيز;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 64

  بنية _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    __int64 st_سائيز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  بنية _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    _off_t st_سائيز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  بنية _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    __int64 st_سائيز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#جيڪڏهن_پورو

#وصف_ڪريو __stat64 _stat64

#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTAT_DEFINED
#وصف_ڪريو _WSTAT_DEFINED

  _CRTIMP صحيح __cdecl _wstat32(ثابت wchar_t *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP صحيح __cdecl _wstat32i64(ثابت wchar_t *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _wstat64i32(ثابت wchar_t *_Name,بنية _stat64i32 *_Stat);
  _CRTIMP صحيح __cdecl _wstat64(ثابت wchar_t *_Name,بنية _stat64 *_Stat);
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCONIO_DEFINED
#وصف_ڪريو _WCONIO_DEFINED

#جيڪڏهن_وصف_نه_ٿيل WEOF
#وصف_ڪريو WEOF (wint_t)(0xFFFF)
#جيڪڏهن_پورو

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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTDIO_DEFINED
#وصف_ڪريو _WSTDIO_DEFINED

#جيڪڏهن_وصف_نه_ٿيل WEOF
#وصف_ڪريو WEOF (wint_t)(0xFFFF)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3);
#وإلا
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3,صحيح _ShFlag);
#جيڪڏهن_پورو

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(فراغ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(فراغ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحيح سائيز_اندريون_لفظ,FILE *_File);
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
  _CRTIMP صحيح __cdecl _swprintf_c(wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_c(wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf(wchar_t *_Dest,سائيز_t ڳڻپ_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf(wchar_t *_Dest,سائيز_t ڳڻپ_5,ثابت wchar_t *_Format,va_list دليلون_2);
#جيڪڏهن_وصف_نه_ٿيل __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snwprintf (wchar_t *s, سائيز_t n, ثابت wchar_t * format, ...);
  __CRT_INLINE صحيح __cdecl vsnwprintf (wchar_t *s, سائيز_t n, ثابت wchar_t *format, va_list arg) { أرجع _vsnwprintf(s,n,format,arg); }
  صحيح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحيح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحيح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf_p(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_p(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,va_list _ArgList);
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
  _CRTIMP صحيح __cdecl _swprintf_c_l(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _swprintf_p_l(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf_l(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list دليلون_2);
  _CRTIMP صحيح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحيح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list دليلون_2);
#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#ضمن <vadefs.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _CRT_NON_CONFORMING_SWPRINTFS
#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#وصف_ڪريو swprintf _swprintf
#وصف_ڪريو vswprintf _vswprintf
#وصف_ڪريو _swprintf_l __swprintf_l
#وصف_ڪريو _vswprintf_l __vswprintf_l
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_اڳياڙي);
  _CRTIMP صحيح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  صحيح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحيح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _snwscanf(ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf_l(ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحيح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحيح _FileHandle ,ثابت wchar_t *گهڻائي_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3,FILE *_OldFile);

#جيڪڏهن_وصف_نه_ٿيل _CRT_WPERROR_DEFINED
#وصف_ڪريو _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_نياپو);
#جيڪڏهن_پورو
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *گهڻائي_3);
#إذا !defined(NO_OLDNAMES) && !defined(wpopen)
#وصف_ڪريو wpopen	_wpopen
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#وصف_رد _CRT_GETPUTWCHAR_NOINLINE

#إذا !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#وصف_ڪريو getwchar() fgetwc(stdin)
#وصف_ڪريو putwchar(_c) fputwc((_c),stdout)
#وإلا
  __CRT_INLINE wint_t __cdecl getwchar() {أرجع (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {أرجع (fputwc(_C,stdout)); }
#جيڪڏهن_پورو

#وصف_ڪريو getwc(_stm) fgetwc(_stm)
#وصف_ڪريو putwc(_c,_stm) fputwc(_c,_stm)
#وصف_ڪريو _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#وصف_ڪريو _getwc_nolock(_c) _fgetwc_nolock(_c)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTDLIB_DEFINED
#وصف_ڪريو _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(ڊگهو قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(بنانشان ڊگهو قدر_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr);
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,_locale_t _Locale);
  عائم __cdecl wcstof( ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  ڊگهو مزدوج __cdecl wcstold (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#جيڪڏهن_پورو /* __NO_ISOCEXT */
  ڊگهو __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP ڊگهو __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  بنانشان ڊگهو __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP بنانشان ڊگهو __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#جيڪڏهن_وصف_نه_ٿيل _CRT_WSYSTEM_DEFINED
#وصف_ڪريو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جيڪڏهن_پورو
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ڊگهو __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP ڊگهو __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(بنانشان __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بنانشان __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP بنانشان __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _POSIX_
#جيڪڏهن_وصف_نه_ٿيل _WSTDLIBP_DEFINED
#وصف_ڪريو _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *ڀريل_رستو,ثابت wchar_t *رستو_2,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *نتيجو_رستو,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#جيڪڏهن_وصف_نه_ٿيل _CRT_WPERROR_DEFINED
#وصف_ڪريو _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_نياپو);
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتيجو_رستو);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *ڀريل_رستو,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTRING_DEFINED
#وصف_ڪريو _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *ذريعو_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحيح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *ذريعو_3);
  سائيز_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  سائيز_t __cdecl wcslen(ثابت wchar_t *_Str);
  سائيز_t __cdecl wcsnlen(ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ثابت wchar_t *ذريعو_3,سائيز_t ڳڻپ_5);
  صحيح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ثابت wchar_t *ذريعو_3,سائيز_t ڳڻپ_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  سائيز_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحيح Err_انگ);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  سائيز_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ);
  _CRTIMP سائيز_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  صحيح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ,_locale_t _Locale);

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#وصف_ڪريو wcswcs wcsstr
  صحيح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحيح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائيز_t Max_ڳڻپ);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,سائيز_t Max_ڳڻپ);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحيح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TM_DEFINED
#وصف_ڪريو _TM_DEFINED
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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WTIME_DEFINED
#وصف_ڪريو _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ثابت بنية tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *وقت_2);
  سائيز_t __cdecl wcsftime(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm);
  _CRTIMP سائيز_t __cdecl _wcsftime_l(wchar_t *_Buf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,ثابت بنية tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *بفر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *بفر_2);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *وقت_2);
#جيڪڏهن_پورو

#إذا !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#وصف_ڪريو _INC_WTIME_INL
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { أرجع _wctime32(وقت_2); }
#وإلا
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { أرجع _wctime64(وقت_2); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  تعريفنوع صحيح mbstate_t;
  تعريفنوع wchar_t _Wint_t;

  wint_t __cdecl btowc(صحيح);
  سائيز_t __cdecl mbrlen(ثابت حرف *_Ch,سائيز_t سائيز_اندريون_بائيٽون,mbstate_t *_State);
  سائيز_t __cdecl mbrtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,سائيز_t سائيز_اندريون_بائيٽون,mbstate_t *_State);
  سائيز_t __cdecl mbsrtowcs(wchar_t *_Dest,ثابت حرف **_PSrc,سائيز_t ڳڻپ_5,mbstate_t *_State);
  سائيز_t __cdecl wcrtomb(حرف *_Dest,wchar_t ذريعو_3,mbstate_t *_State);
  سائيز_t __cdecl wcsrtombs(حرف *_Dest,ثابت wchar_t **_PSource,سائيز_t ڳڻپ_5,mbstate_t *_State);
  صحيح __cdecl wctob(wint_t _WCh);

#جيڪڏهن_وصف_نه_ٿيل __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, سائيز_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *s, wchar_t c, سائيز_t n);
  صحيح wmemcmp(ثابت wchar_t *s1, ثابت wchar_t *s2,سائيز_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ثابت wchar_t *s2,سائيز_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ثابت wchar_t *s2, سائيز_t n);
  ڊگهو ڊگهو __cdecl wcstoll(ثابت wchar_t *nptr,wchar_t **endptr, صحيح بنياد);
  بنانشان ڊگهو ڊگهو __cdecl wcstoull(ثابت wchar_t *nptr,wchar_t **endptr, صحيح بنياد);
#جيڪڏهن_پورو /* __NO_ISOCEXT */

  فراغ *__cdecl memmove(فراغ *_Dst,ثابت فراغ *_Src,سائيز_t Max_ڳڻپ);
  فراغ *__cdecl يادگيري_نقل(فراغ *_Dst,ثابت فراغ *_Src,سائيز_t Max_ڳڻپ);
  __CRT_INLINE صحيح __cdecl fwide(FILE *_F,صحيح _M) { (فراغ)_F; أرجع (_M); }
  __CRT_INLINE صحيح __cdecl mbsinit(ثابت mbstate_t *_P) { أرجع (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *_S,wchar_t _C,سائيز_t _N) { لكل (;0<_N;++_S,--_N) إذا (*_S==_C) أرجع (_CONST_RETURN wchar_t *)(_S); أرجع (0); }
  __CRT_INLINE صحيح __cdecl wmemcmp(ثابت wchar_t *_S1,ثابت wchar_t *_S2,سائيز_t _N) { لكل (; 0 < _N; ++_S1,++_S2,--_N) إذا (*_S1!=*_S2) أرجع (*_S1 < *_S2 ? -1 : +1); أرجع (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ثابت wchar_t *_S2,سائيز_t _N) { أرجع (wchar_t *)يادگيري_نقل(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ثابت wchar_t *_S2,سائيز_t _N) { أرجع (wchar_t *)memmove(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,سائيز_t _N) {
    wchar_t *_Su = _S;
    لكل (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    أرجع (_S);
  }
#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)

#ضمن <sec_api/wchar_s.h>
#جيڪڏهن_پورو
