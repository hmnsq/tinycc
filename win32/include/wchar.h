/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_WCHAR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WCHAR

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WCHAR_MIN  /* also at stdint.h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WCHAR_MIN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __GNUC_VA_LIST
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GNUC_VA_LIST
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __builtin_va_list __gnuc_va_list;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _VA_LIST_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _VA_LIST_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __gnuc_va_list va_list;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WEOF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WEOF (wint_t)(0xFFFF)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FILE_DEFINED
  ਬਣਤਰ _iobuf {
    ਅੱਖਰ *_ptr;
    ਪੂਰਨ _cnt;
    ਅੱਖਰ *ਅਧਾਰ_4;
    ਪੂਰਨ _flag;
    ਪੂਰਨ _file;
    ਪੂਰਨ _charbuf;
    ਪੂਰਨ _bufsiz;
    ਅੱਖਰ *_tmpfname;
  };
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _iobuf FILE;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FILE_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDIO_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ਖਾਲੀ);
#ਨਹੀਂਤਾਂ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
ਬਾਹਰੀ FILE _iob[];	/* A pointer to an array of FILE */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __iob_func()	(_iob)
#ਨਹੀਂਤਾਂ
ਬਾਹਰੀ FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __iob_func()	(*_imp___iob)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iob __iob_func()
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iob __iob_func()
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDSTREAM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stdin (&__iob_func()[0])
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stdout (&__iob_func()[1])
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stderr (&__iob_func()[2])
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDSTREAM_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FSIZE_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _fsize_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FSIZE_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WFINDDATA_T_DEFINED
  ਬਣਤਰ _wfinddata32_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time32_t ਸਮਾਂ_create;
    __time32_t ਸਮਾਂ_access;
    __time32_t ਸਮਾਂ_write;
    _fsize_t ਮਾਪ;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ਬਣਤਰ _wfinddata32i64_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time32_t ਸਮਾਂ_create;
    __time32_t ਸਮਾਂ_access;
    __time32_t ਸਮਾਂ_write;
    __int64 ਮਾਪ;
    wchar_t name[260];
  };

  ਬਣਤਰ _wfinddata64i32_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time64_t ਸਮਾਂ_create;
    __time64_t ਸਮਾਂ_access;
    __time64_t ਸਮਾਂ_write;
    _fsize_t ਮਾਪ;
    wchar_t name[260];
  };

  ਬਣਤਰ _wfinddata64_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time64_t ਸਮਾਂ_create;
    __time64_t ਸਮਾਂ_access;
    __time64_t ਸਮਾਂ_write;
    __int64 ਮਾਪ;
    wchar_t name[260];
  };
/* #endif */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddata_t _wfinddata32_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddatai64_t _wfinddata32i64_t

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirst _wfindfirst32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnext _wfindnext32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirsti64 _wfindfirst32i64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnexti64 _wfindnext32i64
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddata_t _wfinddata64i32_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddatai64_t _wfinddata64_t

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirst _wfindfirst64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnext _wfindnext64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirsti64 _wfindfirst64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnexti64 _wfindnext64
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WFINDDATA_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਨਿਰਾ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ 0
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ ((ਖਾਲੀ *)0)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CONST_RETURN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CONST_RETURN
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WConst_return _CONST_RETURN

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_CTYPEDATA_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_CTYPEDATA_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CTYPE_DISABLE_MACROS

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __PCTYPE_FUNC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __PCTYPE_FUNC __pctype_func()
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __pctype_func() (_pctype)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __pctype_func() (*_imp___pctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _pctype
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *_pctype;
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ **_imp___pctype;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _pctype (*_imp___pctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WCTYPEDATA_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WCTYPEDATA_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CTYPE_DISABLE_MACROS
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _wctype
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *_wctype;
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ **_imp___wctype;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wctype (*_imp___wctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __pwctype_func() (_pwctype)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __pwctype_func() (*_imp___pwctype)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _pwctype
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *_pwctype;
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ **_imp___pwctype;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _pwctype (*_imp___pwctype)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਉੱਤਲਾ_3 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਹੇਠਲਾ_2 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DIGIT 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SPACE 0x8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PUNCT 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CONTROL 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _BLANK 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEX 0x80

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LEADBYTE 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ALPHA (0x0100|ਉੱਤਲਾ_3|ਹੇਠਲਾ_2)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCTYPE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCTYPE_DEFINED

  ਪੂਰਨ __cdecl iswalpha(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswupper(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswlower(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswdigit(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswxdigit(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswspace(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswpunct(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswalnum(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswprint(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswgraph(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswcntrl(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswascii(wint_t _C);
  ਪੂਰਨ __cdecl isleadbyte(ਪੂਰਨ _C);
  _CRTIMP ਪੂਰਨ __cdecl _isleadbyte_l(ਪੂਰਨ _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP ਪੂਰਨ __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl __iswcsymf(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl __iswcsym(wint_t _C);
  _CRTIMP ਪੂਰਨ __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  ਪੂਰਨ __cdecl is_wctype(wint_t _C,wctype_t _Type);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WDIRECT_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ਪੂਰਨ _Drive,wchar_t *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  wchar_t *__cdecl _wgetdcwd_nolock(ਪੂਰਨ _Drive,wchar_t *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP ਪੂਰਨ __cdecl _wchdir(ਅਚਲ wchar_t *ਰਸਤਾ_2);
  _CRTIMP ਪੂਰਨ __cdecl _wmkdir(ਅਚਲ wchar_t *ਰਸਤਾ_2);
  _CRTIMP ਪੂਰਨ __cdecl _wrmdir(ਅਚਲ wchar_t *ਰਸਤਾ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WIO_DEFINED

  _CRTIMP ਪੂਰਨ __cdecl _waccess(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  _CRTIMP ਪੂਰਨ __cdecl _wchmod(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ ਬਹੁਲਕ_3);
  _CRTIMP ਪੂਰਨ __cdecl _wcreat(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ Permission_ਬਹੁਲਕ);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wfindnext32(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wunlink(ਅਚਲ wchar_t *_Filename);
  _CRTIMP ਪੂਰਨ __cdecl _wrename(ਅਚਲ wchar_t *_NewFilename,ਅਚਲ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata32i64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  intptr_t __cdecl _wfindfirst64i32(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wfindnext32i64(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata32i64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  ਪੂਰਨ __cdecl _wfindnext64i32(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wfindnext64(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata64_t *ਲੱਭੋ_ਅੰਕੜੇ);
#ਜੇ_ਅੰਤ
  _CRTIMP errno_t __cdecl _wsopen_s(ਪੂਰਨ *_FileHandle,ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,ਪੂਰਨ _PermissionFlag);
#ਜੇ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ਪੂਰਨ __cdecl _wopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,...);
  _CRTIMP ਪੂਰਨ __cdecl _wsopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,...);
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ "C++" _CRTIMP ਪੂਰਨ __cdecl _wopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ Permission_ਬਹੁਲਕ = 0);
  ਬਾਹਰੀ "C++" _CRTIMP ਪੂਰਨ __cdecl _wsopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,ਪੂਰਨ Permission_ਬਹੁਲਕ = 0);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WLOCALE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ਪੂਰਨ _Category,ਅਚਲ wchar_t *_Locale);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WPROCESS_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WSYSTEM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WSYSTEM_DEFINED
  _CRTIMP ਪੂਰਨ __cdecl _wsystem(ਅਚਲ wchar_t *_Command);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCTYPE_INLINE_DEFINED
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _CRT_WCTYPE_NOINLINE
#ਜੇ !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswalpha(_c) (iswctype(_c,_ALPHA))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswupper(_c) (iswctype(_c,ਉੱਤਲਾ_3))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswlower(_c) (iswctype(_c,ਹੇਠਲਾ_2))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswdigit(_c) (iswctype(_c,_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswxdigit(_c) (iswctype(_c,_HEX))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswspace(_c) (iswctype(_c,_SPACE))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswpunct(_c) (iswctype(_c,_PUNCT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswcntrl(_c) (iswctype(_c,_CONTROL))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ iswascii(_c) ((ਬਿਨਾਨਿਸ਼ਾਨੀ)(_c) < 0x80)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswupper_l(_c,_p) (_iswctype_l(_c,ਉੱਤਲਾ_3,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswlower_l(_c,_p) (_iswctype_l(_c,ਹੇਠਲਾ_2,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CTYPE_DISABLE_MACROS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ isleadbyte(_c) (__PCTYPE_FUNC[(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)(_c)] & _LEADBYTE)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCTYPE_INLINE_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ !defined(_POSIX_) || defined(__GNUC__)
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INO_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INO_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ _ino_t;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ino_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _DEV_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DEV_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _dev_t;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ dev_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF_T_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF_T_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF_T_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ _off_t;
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ off_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF64_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF64_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ _off64_t;
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ off64_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STAT_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STAT_DEFINED

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstat _fstat32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stat _stat32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstat _wstat32
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstat32 _fstat
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stat32 _stat
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstat32 _wstat
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstati64 _fstat32i64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stati64 _stat32i64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstati64 _wstat32i64
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstat _fstat64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstati64 _fstat64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stat _stat64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stati64 _stat64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstat _wstat64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstati64 _wstat64
#ਜੇ_ਅੰਤ

  ਬਣਤਰ _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    _off_t st_ਮਾਪ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਬਣਤਰ stat {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    _off_t st_ਮਾਪ;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64

  ਬਣਤਰ _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    __int64 st_ਮਾਪ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  ਬਣਤਰ _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    _off_t st_ਮਾਪ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  ਬਣਤਰ _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    __int64 st_ਮਾਪ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __stat64 _stat64

#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTAT_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTAT_DEFINED

  _CRTIMP ਪੂਰਨ __cdecl _wstat32(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat32 *_Stat);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP ਪੂਰਨ __cdecl _wstat32i64(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat32i64 *_Stat);
  ਪੂਰਨ __cdecl _wstat64i32(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat64i32 *_Stat);
  _CRTIMP ਪੂਰਨ __cdecl _wstat64(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat64 *_Stat);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCONIO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCONIO_DEFINED

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WEOF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WEOF (wint_t)(0xFFFF)
#ਜੇ_ਅੰਤ

  _CRTIMP wchar_t *_cgetws(wchar_t *ਬਫਰ_2);
  _CRTIMP wint_t __cdecl _getwch(ਖਾਲੀ);
  _CRTIMP wint_t __cdecl _getwche(ਖਾਲੀ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ਪੂਰਨ __cdecl _cputws(ਅਚਲ wchar_t *_String);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_p(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_p(ਅਚਲ wchar_t *_Format,va_list _ArgList);

  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(ਖਾਲੀ);
  wint_t __cdecl _getwche_nolock(ਖਾਲੀ);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDIO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDIO_DEFINED

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WEOF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WEOF (wint_t)(0xFFFF)
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
#ਨਹੀਂਤਾਂ
  _CRTIMP FILE *__cdecl _wfsopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3,ਪੂਰਨ _ShFlag);
#ਜੇ_ਅੰਤ

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ਖਾਲੀ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ਖਾਲੀ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,FILE *_File);
  ਪੂਰਨ __cdecl fputws(ਅਚਲ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ਪੂਰਨ __cdecl _putws(ਅਚਲ wchar_t *_Str);
  ਪੂਰਨ __cdecl fwprintf(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl wprintf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf(ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl vfwprintf(FILE *_File,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl vwprintf(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl swprintf(wchar_t*, ਅਚਲ wchar_t*, ...);
  _CRTIMP ਪੂਰਨ __cdecl vswprintf(wchar_t*, ਅਚਲ wchar_t*,va_list);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_c(wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_c(wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snwprintf(wchar_t *_Dest,ਮਾਪ_t ਗਿਣਤੀ_6,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnwprintf(wchar_t *_Dest,ਮਾਪ_t ਗਿਣਤੀ_6,ਅਚਲ wchar_t *_Format,va_list ਦਲੀਲਾਂ_2);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __NO_ISOCEXT  /* externs in libmingwex.a */
  ਪੂਰਨ __cdecl snwprintf (wchar_t *s, ਮਾਪ_t n, ਅਚਲ wchar_t * format, ...);
  __CRT_INLINE ਪੂਰਨ __cdecl vsnwprintf (wchar_t *s, ਮਾਪ_t n, ਅਚਲ wchar_t *format, va_list arg) { ਵਾਪਸ _vsnwprintf(s,n,format,arg); }
  ਪੂਰਨ __cdecl vwscanf (ਅਚਲ wchar_t *, va_list);
  ਪੂਰਨ __cdecl vfwscanf (FILE *,ਅਚਲ wchar_t *,va_list);
  ਪੂਰਨ __cdecl vswscanf (ਅਚਲ wchar_t *,ਅਚਲ wchar_t *,va_list);
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _fwprintf_p(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _wprintf_p(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfwprintf_p(FILE *_File,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vwprintf_p(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_p(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_p(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf_p(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf_p(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _wprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _wprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _fwprintf_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _fwprintf_p_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vfwprintf_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vfwprintf_p_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_c_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_p_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snwprintf_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,va_list ਦਲੀਲਾਂ_2);
  _CRTIMP ਪੂਰਨ __cdecl __swprintf_l(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ਪੂਰਨ __cdecl __vswprintf_l(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,_locale_t _Plocinfo,va_list ਦਲੀਲਾਂ_2);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਅਨ੍ਤਰ੍ਭਾਵ <vadefs.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _CRT_NON_CONFORMING_SWPRINTFS
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ swprintf _swprintf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ vswprintf _vswprintf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _swprintf_l __swprintf_l
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _vswprintf_l __vswprintf_l
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  _CRTIMP wchar_t *__cdecl _wtempnam(ਅਚਲ wchar_t *_Directory,ਅਚਲ wchar_t *File_ਅਗੇਤਰ);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  ਪੂਰਨ __cdecl fwscanf(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _fwscanf_l(FILE *_File,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  ਪੂਰਨ __cdecl swscanf(ਅਚਲ wchar_t *_Src,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _swscanf_l(ਅਚਲ wchar_t *_Src,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _snwscanf(ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _snwscanf_l(ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  ਪੂਰਨ __cdecl wscanf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _wscanf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(ਪੂਰਨ _FileHandle ,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
  _CRTIMP FILE *__cdecl _wfopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
  _CRTIMP FILE *__cdecl _wfreopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3,FILE *_OldFile);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WPERROR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WPERROR_DEFINED
  _CRTIMP ਖਾਲੀ __cdecl _wperror(ਅਚਲ wchar_t *Err_ਸੁਨੇਹਾ);
#ਜੇ_ਅੰਤ
  _CRTIMP FILE *__cdecl _wpopen(ਅਚਲ wchar_t *_Command,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
#ਜੇ !defined(NO_OLDNAMES) && !defined(wpopen)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wpopen	_wpopen
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _wremove(ਅਚਲ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *ਬਫਰ_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _CRT_GETPUTWCHAR_NOINLINE

#ਜੇ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ getwchar() fgetwc(stdin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ putwchar(_c) fputwc((_c),stdout)
#ਨਹੀਂਤਾਂ
  __CRT_INLINE wint_t __cdecl getwchar() {ਵਾਪਸ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {ਵਾਪਸ (fputwc(_C,stdout)); }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ getwc(_stm) fgetwc(_stm)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ putwc(_c,_stm) fputwc(_c,_stm)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _getwc_nolock(_c) _fgetwc_nolock(_c)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDLIB_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ਪੂਰਨ ਮੁੱਲ_2,wchar_t *_Dest,ਪੂਰਨ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(ਲੰਮਾ ਮੁੱਲ_2,wchar_t *_Dest,ਪੂਰਨ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ_2,wchar_t *_Dest,ਪੂਰਨ _Radix);
  ਦੁੱਗਣਾ __cdecl wcstod(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _wcstod_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,_locale_t _Locale);
  ਦਸ਼ਮਲਵ __cdecl wcstof( ਅਚਲ wchar_t *nptr, wchar_t **endptr);
#ਜੇ !defined __NO_ISOCEXT /* in libmingwex.a */
  ਦਸ਼ਮਲਵ __cdecl wcstof (ਅਚਲ wchar_t * __restrict__, wchar_t ** __restrict__);
  ਲੰਮਾ ਦੁੱਗਣਾ __cdecl wcstold (ਅਚਲ wchar_t * __restrict__, wchar_t ** __restrict__);
#ਜੇ_ਅੰਤ /* __NO_ISOCEXT */
  ਲੰਮਾ __cdecl wcstol(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਲੰਮਾ __cdecl _wcstol_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl wcstoul(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _wcstoul_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ਅਚਲ wchar_t *_VarName);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WSYSTEM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WSYSTEM_DEFINED
  _CRTIMP ਪੂਰਨ __cdecl _wsystem(ਅਚਲ wchar_t *_Command);
#ਜੇ_ਅੰਤ
  _CRTIMP ਦੁੱਗਣਾ __cdecl _wtof(ਅਚਲ wchar_t *_Str);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _wtof_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _wtoi(ਅਚਲ wchar_t *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _wtoi_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ਲੰਮਾ __cdecl _wtol(ਅਚਲ wchar_t *_Str);
  _CRTIMP ਲੰਮਾ __cdecl _wtol_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ਪੂਰਨ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Val,wchar_t *_DstBuf,ਪੂਰਨ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ਅਚਲ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _wcstoui64(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _wcstoui64_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDLIBP_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *ਭਰਿਆ_ਰਸਤਾ,ਅਚਲ wchar_t *ਰਸਤਾ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP ਖਾਲੀ __cdecl _wmakepath(wchar_t *ਨਤੀਜਾ_ਰਸਤਾ,ਅਚਲ wchar_t *_Drive,ਅਚਲ wchar_t *_Dir,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_Ext);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WPERROR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WPERROR_DEFINED
  _CRTIMP ਖਾਲੀ __cdecl _wperror(ਅਚਲ wchar_t *Err_ਸੁਨੇਹਾ);
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _wputenv(ਅਚਲ wchar_t *_EnvString);
  _CRTIMP ਖਾਲੀ __cdecl _wsearchenv(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_EnvVar,wchar_t *ਨਤੀਜਾ_ਰਸਤਾ);
  _CRTIMP ਖਾਲੀ __cdecl _wsplitpath(ਅਚਲ wchar_t *ਭਰਿਆ_ਰਸਤਾ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTRING_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ਅਚਲ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ਅਚਲ wchar_t *ਸਰੋਤ_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ਅਚਲ wchar_t *_Str,wchar_t _Ch);
  ਪੂਰਨ __cdecl wcscmp(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ਅਚਲ wchar_t *ਸਰੋਤ_3);
  ਮਾਪ_t __cdecl wcscspn(ਅਚਲ wchar_t *_Str,ਅਚਲ wchar_t *_Control);
  ਮਾਪ_t __cdecl wcslen(ਅਚਲ wchar_t *_Str);
  ਮਾਪ_t __cdecl wcsnlen(ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ਅਚਲ wchar_t *ਸਰੋਤ_3,ਮਾਪ_t ਗਿਣਤੀ_6);
  ਪੂਰਨ __cdecl wcsncmp(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ਅਚਲ wchar_t *ਸਰੋਤ_3,ਮਾਪ_t ਗਿਣਤੀ_6);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ਅਚਲ wchar_t *_Str,ਅਚਲ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ਅਚਲ wchar_t *_Str,wchar_t _Ch);
  ਮਾਪ_t __cdecl wcsspn(ਅਚਲ wchar_t *_Str,ਅਚਲ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ਅਚਲ wchar_t *_Str,ਅਚਲ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ਅਚਲ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(ਪੂਰਨ Err_ਅੰਕ);
  _CRTIMP wchar_t *__cdecl __wcserror(ਅਚਲ wchar_t *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _wcsicmp(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2);
  _CRTIMP ਪੂਰਨ __cdecl _wcsicmp_l(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _wcsnicmp(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਪੂਰਨ __cdecl _wcsnicmp_l(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  ਮਾਪ_t __cdecl wcsxfrm(wchar_t *_Dst,ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਮਾਪ_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  ਪੂਰਨ __cdecl wcscoll(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2);
  _CRTIMP ਪੂਰਨ __cdecl _wcscoll_l(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _wcsicoll(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2);
  _CRTIMP ਪੂਰਨ __cdecl _wcsicoll_l(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _wcsncoll(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਪੂਰਨ __cdecl _wcsncoll_l(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _wcsnicoll(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਪੂਰਨ __cdecl _wcsnicoll_l(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ਅਚਲ wchar_t *_Str);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wcswcs wcsstr
  ਪੂਰਨ __cdecl wcsicmp(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2);
  ਪੂਰਨ __cdecl wcsnicmp(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2,ਮਾਪ_t Max_ਗਿਣਤੀ);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,ਮਾਪ_t Max_ਗਿਣਤੀ);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  ਪੂਰਨ __cdecl wcsicoll(ਅਚਲ wchar_t *_Str1,ਅਚਲ wchar_t *_Str2);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TM_DEFINED
  ਬਣਤਰ tm {
    ਪੂਰਨ tm_sec;
    ਪੂਰਨ tm_min;
    ਪੂਰਨ tm_hour;
    ਪੂਰਨ tm_mday;
    ਪੂਰਨ tm_mon;
    ਪੂਰਨ tm_year;
    ਪੂਰਨ tm_wday;
    ਪੂਰਨ tm_yday;
    ਪੂਰਨ tm_isdst;
  };
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WTIME_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ਅਚਲ __time32_t *ਸਮਾਂ_2);
  ਮਾਪ_t __cdecl wcsftime(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,ਅਚਲ ਬਣਤਰ tm *_Tm);
  _CRTIMP ਮਾਪ_t __cdecl _wcsftime_l(wchar_t *_Buf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,ਅਚਲ ਬਣਤਰ tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *ਬਫਰ_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *ਬਫਰ_2);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ਅਚਲ __time64_t *ਸਮਾਂ_2);
#ਜੇ_ਅੰਤ

#ਜੇ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WTIME_INL
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE wchar_t *__cdecl _wctime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime32(ਸਮਾਂ_2); }
#ਨਹੀਂਤਾਂ
__CRT_INLINE wchar_t *__cdecl _wctime(ਅਚਲ time_t *ਸਮਾਂ_2) { ਵਾਪਸ _wctime64(ਸਮਾਂ_2); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ mbstate_t;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ wchar_t _Wint_t;

  wint_t __cdecl btowc(ਪੂਰਨ);
  ਮਾਪ_t __cdecl mbrlen(ਅਚਲ ਅੱਖਰ *_Ch,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,mbstate_t *_State);
  ਮਾਪ_t __cdecl mbrtowc(wchar_t *_DstCh,ਅਚਲ ਅੱਖਰ *_SrcCh,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,mbstate_t *_State);
  ਮਾਪ_t __cdecl mbsrtowcs(wchar_t *_Dest,ਅਚਲ ਅੱਖਰ **_PSrc,ਮਾਪ_t ਗਿਣਤੀ_6,mbstate_t *_State);
  ਮਾਪ_t __cdecl wcrtomb(ਅੱਖਰ *_Dest,wchar_t ਸਰੋਤ_3,mbstate_t *_State);
  ਮਾਪ_t __cdecl wcsrtombs(ਅੱਖਰ *_Dest,ਅਚਲ wchar_t **_PSource,ਮਾਪ_t ਗਿਣਤੀ_6,mbstate_t *_State);
  ਪੂਰਨ __cdecl wctob(wint_t _WCh);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, ਮਾਪ_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ਅਚਲ wchar_t *s, wchar_t c, ਮਾਪ_t n);
  ਪੂਰਨ wmemcmp(ਅਚਲ wchar_t *s1, ਅਚਲ wchar_t *s2,ਮਾਪ_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ਅਚਲ wchar_t *s2,ਮਾਪ_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ਅਚਲ wchar_t *s2, ਮਾਪ_t n);
  ਲੰਮਾ ਲੰਮਾ __cdecl wcstoll(ਅਚਲ wchar_t *nptr,wchar_t **endptr, ਪੂਰਨ ਅਧਾਰ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __cdecl wcstoull(ਅਚਲ wchar_t *nptr,wchar_t **endptr, ਪੂਰਨ ਅਧਾਰ);
#ਜੇ_ਅੰਤ /* __NO_ISOCEXT */

  ਖਾਲੀ *__cdecl memmove(ਖਾਲੀ *_Dst,ਅਚਲ ਖਾਲੀ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  ਖਾਲੀ *__cdecl ਸਮ੍ਰਿਤੀ_ਨਕਲ(ਖਾਲੀ *_Dst,ਅਚਲ ਖਾਲੀ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ);
  __CRT_INLINE ਪੂਰਨ __cdecl fwide(FILE *_F,ਪੂਰਨ _M) { (ਖਾਲੀ)_F; ਵਾਪਸ (_M); }
  __CRT_INLINE ਪੂਰਨ __cdecl mbsinit(ਅਚਲ mbstate_t *_P) { ਵਾਪਸ (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ਅਚਲ wchar_t *_S,wchar_t _C,ਮਾਪ_t _N) { ਲਈ (;0<_N;++_S,--_N) ਜੇ (*_S==_C) ਵਾਪਸ (_CONST_RETURN wchar_t *)(_S); ਵਾਪਸ (0); }
  __CRT_INLINE ਪੂਰਨ __cdecl wmemcmp(ਅਚਲ wchar_t *_S1,ਅਚਲ wchar_t *_S2,ਮਾਪ_t _N) { ਲਈ (; 0 < _N; ++_S1,++_S2,--_N) ਜੇ (*_S1!=*_S2) ਵਾਪਸ (*_S1 < *_S2 ? -1 : +1); ਵਾਪਸ (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ਅਚਲ wchar_t *_S2,ਮਾਪ_t _N) { ਵਾਪਸ (wchar_t *)ਸਮ੍ਰਿਤੀ_ਨਕਲ(_S1,_S2,_N*ਆਕਾਰ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ਅਚਲ wchar_t *_S2,ਮਾਪ_t _N) { ਵਾਪਸ (wchar_t *)memmove(_S1,_S2,_N*ਆਕਾਰ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,ਮਾਪ_t _N) {
    wchar_t *_Su = _S;
    ਲਈ (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    ਵਾਪਸ (_S);
  }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਅਨ੍ਤਰ੍ਭਾਵ <sec_api/wchar_s.h>
#ਜੇ_ਅੰਤ
