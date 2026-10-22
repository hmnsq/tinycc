/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_WCHAR
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_WCHAR

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WCHAR_MIN  /* also at stdint.h */
#ವ್ಯಾಖ್ಯಾನಿಸು WCHAR_MIN 0
#ವ್ಯಾಖ್ಯಾನಿಸು WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __GNUC_VA_LIST
#ವ್ಯಾಖ್ಯಾನಿಸು __GNUC_VA_LIST
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __builtin_va_list __gnuc_va_list;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _VA_LIST_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _VA_LIST_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __gnuc_va_list va_list;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WEOF
#ವ್ಯಾಖ್ಯಾನಿಸು WEOF (wint_t)(0xFFFF)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FILE_DEFINED
  ರಚನೆ _iobuf {
    ಅಕ್ಷರ *_ptr;
    ಪೂರ್ಣಾಂಕ _cnt;
    ಅಕ್ಷರ *ತಳ_4;
    ಪೂರ್ಣಾಂಕ _flag;
    ಪೂರ್ಣಾಂಕ _file;
    ಪೂರ್ಣಾಂಕ _charbuf;
    ಪೂರ್ಣಾಂಕ _bufsiz;
    ಅಕ್ಷರ *_tmpfname;
  };
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _iobuf FILE;
#ವ್ಯಾಖ್ಯಾನಿಸು _FILE_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDIO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ಶೂನ್ಯ);
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
ಬಾಹ್ಯ FILE _iob[];	/* A pointer to an array of FILE */
#ವ್ಯಾಖ್ಯಾನಿಸು __iob_func()	(_iob)
#ಇಲ್ಲದಿದ್ದರೆ
ಬಾಹ್ಯ FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#ವ್ಯಾಖ್ಯಾನಿಸು __iob_func()	(*_imp___iob)
#ವ್ಯಾಖ್ಯಾನಿಸು _iob __iob_func()
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _iob __iob_func()
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDSTREAM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು stdin (&__iob_func()[0])
#ವ್ಯಾಖ್ಯಾನಿಸು stdout (&__iob_func()[1])
#ವ್ಯಾಖ್ಯಾನಿಸು stderr (&__iob_func()[2])
#ವ್ಯಾಖ್ಯಾನಿಸು _STDSTREAM_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FSIZE_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _fsize_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _FSIZE_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WFINDDATA_T_DEFINED
  ರಚನೆ _wfinddata32_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time32_t ಸಮಯ_create;
    __time32_t ಸಮಯ_access;
    __time32_t ಸಮಯ_write;
    _fsize_t ಗಾತ್ರ_2;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ರಚನೆ _wfinddata32i64_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time32_t ಸಮಯ_create;
    __time32_t ಸಮಯ_access;
    __time32_t ಸಮಯ_write;
    __int64 ಗಾತ್ರ_2;
    wchar_t name[260];
  };

  ರಚನೆ _wfinddata64i32_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time64_t ಸಮಯ_create;
    __time64_t ಸಮಯ_access;
    __time64_t ಸಮಯ_write;
    _fsize_t ಗಾತ್ರ_2;
    wchar_t name[260];
  };

  ರಚನೆ _wfinddata64_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time64_t ಸಮಯ_create;
    __time64_t ಸಮಯ_access;
    __time64_t ಸಮಯ_write;
    __int64 ಗಾತ್ರ_2;
    wchar_t name[260];
  };
/* #endif */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddata_t _wfinddata32_t
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddatai64_t _wfinddata32i64_t

#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirst _wfindfirst32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnext _wfindnext32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirsti64 _wfindfirst32i64
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnexti64 _wfindnext32i64
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddata_t _wfinddata64i32_t
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddatai64_t _wfinddata64_t

#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirst _wfindfirst64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnext _wfindnext64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirsti64 _wfindfirst64
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnexti64 _wfindnext64
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _WFINDDATA_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಖಾಲಿ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ 0
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ ((ಶೂನ್ಯ *)0)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CONST_RETURN
#ವ್ಯಾಖ್ಯಾನಿಸು _CONST_RETURN
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _WConst_return _CONST_RETURN

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_CTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_CTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CTYPE_DISABLE_MACROS

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __PCTYPE_FUNC
#ವ್ಯಾಖ್ಯಾನಿಸು __PCTYPE_FUNC __pctype_func()
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
#ವ್ಯಾಖ್ಯಾನಿಸು __pctype_func() (_pctype)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __pctype_func() (*_imp___pctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _pctype
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *_pctype;
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ **_imp___pctype;
#ವ್ಯಾಖ್ಯಾನಿಸು _pctype (*_imp___pctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WCTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WCTYPEDATA_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CTYPE_DISABLE_MACROS
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _wctype
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *_wctype;
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ **_imp___wctype;
#ವ್ಯಾಖ್ಯಾನಿಸು _wctype (*_imp___wctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
#ವ್ಯಾಖ್ಯಾನಿಸು __pwctype_func() (_pwctype)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __pwctype_func() (*_imp___pwctype)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _pwctype
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *_pwctype;
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ **_imp___pwctype;
#ವ್ಯಾಖ್ಯಾನಿಸು _pwctype (*_imp___pwctype)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಊರ್ಧ್ವ_3 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ಅಧೋ_2 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು _DIGIT 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು _SPACE 0x8

#ವ್ಯಾಖ್ಯಾನಿಸು _PUNCT 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು _CONTROL 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು _BLANK 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು _HEX 0x80

#ವ್ಯಾಖ್ಯಾನಿಸು _LEADBYTE 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು _ALPHA (0x0100|ಊರ್ಧ್ವ_3|ಅಧೋ_2)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCTYPE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCTYPE_DEFINED

  ಪೂರ್ಣಾಂಕ __cdecl iswalpha(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswupper(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswlower(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswdigit(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswxdigit(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswspace(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswpunct(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswalnum(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswprint(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswgraph(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswcntrl(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswascii(wint_t _C);
  ಪೂರ್ಣಾಂಕ __cdecl isleadbyte(ಪೂರ್ಣಾಂಕ _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _isleadbyte_l(ಪೂರ್ಣಾಂಕ _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __iswcsymf(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __iswcsym(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl is_wctype(wint_t _C,wctype_t _Type);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WDIRECT_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ಪೂರ್ಣಾಂಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  wchar_t *__cdecl _wgetdcwd_nolock(ಪೂರ್ಣಾಂಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wchdir(ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wmkdir(ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wrmdir(ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WIO_DEFINED

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _waccess(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wchmod(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcreat(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wfindnext32(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wunlink(ಸ್ಥಿರಾಂಕ wchar_t *_Filename);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wrename(ಸ್ಥಿರಾಂಕ wchar_t *_NewFilename,ಸ್ಥಿರಾಂಕ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata32i64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  intptr_t __cdecl _wfindfirst64i32(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wfindnext32i64(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata32i64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  ಪೂರ್ಣಾಂಕ __cdecl _wfindnext64i32(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wfindnext64(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP errno_t __cdecl _wsopen_s(ಪೂರ್ಣಾಂಕ *_FileHandle,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,ಪೂರ್ಣಾಂಕ _PermissionFlag);
#ಆದರೆ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,...);
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ = 0);
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ = 0);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WLOCALE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ಪೂರ್ಣಾಂಕ _Category,ಸ್ಥಿರಾಂಕ wchar_t *_Locale);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WPROCESS_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WSYSTEM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsystem(ಸ್ಥಿರಾಂಕ wchar_t *_Command);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCTYPE_INLINE_DEFINED
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _CRT_WCTYPE_NOINLINE
#ಆದರೆ !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#ವ್ಯಾಖ್ಯಾನಿಸು iswalpha(_c) (iswctype(_c,_ALPHA))
#ವ್ಯಾಖ್ಯಾನಿಸು iswupper(_c) (iswctype(_c,ಊರ್ಧ್ವ_3))
#ವ್ಯಾಖ್ಯಾನಿಸು iswlower(_c) (iswctype(_c,ಅಧೋ_2))
#ವ್ಯಾಖ್ಯಾನಿಸು iswdigit(_c) (iswctype(_c,_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswxdigit(_c) (iswctype(_c,_HEX))
#ವ್ಯಾಖ್ಯಾನಿಸು iswspace(_c) (iswctype(_c,_SPACE))
#ವ್ಯಾಖ್ಯಾನಿಸು iswpunct(_c) (iswctype(_c,_PUNCT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#ವ್ಯಾಖ್ಯಾನಿಸು iswcntrl(_c) (iswctype(_c,_CONTROL))
#ವ್ಯಾಖ್ಯಾನಿಸು iswascii(_c) ((ಚಿಹ್ನೆರಹಿತ)(_c) < 0x80)

#ವ್ಯಾಖ್ಯಾನಿಸು _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswupper_l(_c,_p) (_iswctype_l(_c,ಊರ್ಧ್ವ_3,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswlower_l(_c,_p) (_iswctype_l(_c,ಅಧೋ_2,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#ವ್ಯಾಖ್ಯಾನಿಸು _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CTYPE_DISABLE_MACROS
#ವ್ಯಾಖ್ಯಾನಿಸು isleadbyte(_c) (__PCTYPE_FUNC[(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)(_c)] & _LEADBYTE)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _WCTYPE_INLINE_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(_POSIX_) || defined(__GNUC__)
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INO_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _INO_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ _ino_t;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ino_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _DEV_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _DEV_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _dev_t;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ dev_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF_T_
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF_T_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ _off_t;
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ off_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF64_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF64_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ _off64_t;
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ off64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STAT_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _STAT_DEFINED

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು _fstat _fstat32
#ವ್ಯಾಖ್ಯಾನಿಸು _stat _stat32
#ವ್ಯಾಖ್ಯಾನಿಸು _wstat _wstat32
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _fstat32 _fstat
#ವ್ಯಾಖ್ಯಾನಿಸು _stat32 _stat
#ವ್ಯಾಖ್ಯಾನಿಸು _wstat32 _wstat
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _fstati64 _fstat32i64
#ವ್ಯಾಖ್ಯಾನಿಸು _stati64 _stat32i64
#ವ್ಯಾಖ್ಯಾನಿಸು _wstati64 _wstat32i64
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _fstat _fstat64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _fstati64 _fstat64
#ವ್ಯಾಖ್ಯಾನಿಸು _stat _stat64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _stati64 _stat64
#ವ್ಯಾಖ್ಯಾನಿಸು _wstat _wstat64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _wstati64 _wstat64
#ಆದರೆ_ಅಂತ್ಯ

  ರಚನೆ _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    _off_t st_ಗಾತ್ರ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ರಚನೆ stat {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    _off_t st_ಗಾತ್ರ;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64

  ರಚನೆ _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    __int64 st_ಗಾತ್ರ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  ರಚನೆ _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    _off_t st_ಗಾತ್ರ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  ರಚನೆ _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    __int64 st_ಗಾತ್ರ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು __stat64 _stat64

#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTAT_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTAT_DEFINED

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wstat32(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat32 *_Stat);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wstat32i64(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat32i64 *_Stat);
  ಪೂರ್ಣಾಂಕ __cdecl _wstat64i32(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat64i32 *_Stat);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wstat64(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat64 *_Stat);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCONIO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCONIO_DEFINED

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WEOF
#ವ್ಯಾಖ್ಯಾನಿಸು WEOF (wint_t)(0xFFFF)
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP wchar_t *_cgetws(wchar_t *ಬಫರ್_2);
  _CRTIMP wint_t __cdecl _getwch(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _getwche(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cputws(ಸ್ಥಿರಾಂಕ wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(ಶೂನ್ಯ);
  wint_t __cdecl _getwche_nolock(ಶೂನ್ಯ);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDIO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDIO_DEFINED

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WEOF
#ವ್ಯಾಖ್ಯಾನಿಸು WEOF (wint_t)(0xFFFF)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
#ಇಲ್ಲದಿದ್ದರೆ
  _CRTIMP FILE *__cdecl _wfsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3,ಪೂರ್ಣಾಂಕ _ShFlag);
#ಆದರೆ_ಅಂತ್ಯ

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ಶೂನ್ಯ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ಶೂನ್ಯ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು,FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl fputws(ಸ್ಥಿರಾಂಕ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _putws(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  ಪೂರ್ಣಾಂಕ __cdecl fwprintf(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl wprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl vfwprintf(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl vwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl swprintf(wchar_t*, ಸ್ಥಿರಾಂಕ wchar_t*, ...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl vswprintf(wchar_t*, ಸ್ಥಿರಾಂಕ wchar_t*,va_list);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_c(wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_c(wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwprintf(wchar_t *_Dest,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnwprintf(wchar_t *_Dest,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list ವಾದಗಳು_2);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __NO_ISOCEXT  /* externs in libmingwex.a */
  ಪೂರ್ಣಾಂಕ __cdecl snwprintf (wchar_t *s, ಗಾತ್ರ_t n, ಸ್ಥಿರಾಂಕ wchar_t * format, ...);
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl vsnwprintf (wchar_t *s, ಗಾತ್ರ_t n, ಸ್ಥಿರಾಂಕ wchar_t *format, va_list arg) { ಹಿಂತಿರುಗಿ _vsnwprintf(s,n,format,arg); }
  ಪೂರ್ಣಾಂಕ __cdecl vwscanf (ಸ್ಥಿರಾಂಕ wchar_t *, va_list);
  ಪೂರ್ಣಾಂಕ __cdecl vfwscanf (FILE *,ಸ್ಥಿರಾಂಕ wchar_t *,va_list);
  ಪೂರ್ಣಾಂಕ __cdecl vswscanf (ಸ್ಥಿರಾಂಕ wchar_t *,ಸ್ಥಿರಾಂಕ wchar_t *,va_list);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwprintf_p(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfwprintf_p(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_p(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_p(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwprintf_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwprintf_p_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfwprintf_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vfwprintf_p_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_c_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_p_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwprintf_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list ವಾದಗಳು_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __swprintf_l(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl __vswprintf_l(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Plocinfo,va_list ವಾದಗಳು_2);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ಅನ್ತರ್ಭಾವ <vadefs.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _CRT_NON_CONFORMING_SWPRINTFS
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು swprintf _swprintf
#ವ್ಯಾಖ್ಯಾನಿಸು vswprintf _vswprintf
#ವ್ಯಾಖ್ಯಾನಿಸು _swprintf_l __swprintf_l
#ವ್ಯಾಖ್ಯಾನಿಸು _vswprintf_l __vswprintf_l
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP wchar_t *__cdecl _wtempnam(ಸ್ಥಿರಾಂಕ wchar_t *_Directory,ಸ್ಥಿರಾಂಕ wchar_t *File_ಪೂರ್ವಪ್ರತ್ಯಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl fwscanf(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fwscanf_l(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಂಕ __cdecl swscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಂಕ __cdecl wscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(ಪೂರ್ಣಾಂಕ _FileHandle ,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
  _CRTIMP FILE *__cdecl _wfopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
  _CRTIMP FILE *__cdecl _wfreopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3,FILE *_OldFile);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WPERROR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಸ್ಥಿರಾಂಕ wchar_t *Err_ಸಂದೇಶ);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP FILE *__cdecl _wpopen(ಸ್ಥಿರಾಂಕ wchar_t *_Command,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
#ಆದರೆ !defined(NO_OLDNAMES) && !defined(wpopen)
#ವ್ಯಾಖ್ಯಾನಿಸು wpopen	_wpopen
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wremove(ಸ್ಥಿರಾಂಕ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *ಬಫರ್_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _CRT_GETPUTWCHAR_NOINLINE

#ಆದರೆ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#ವ್ಯಾಖ್ಯಾನಿಸು getwchar() fgetwc(stdin)
#ವ್ಯಾಖ್ಯಾನಿಸು putwchar(_c) fputwc((_c),stdout)
#ಇಲ್ಲದಿದ್ದರೆ
  __CRT_INLINE wint_t __cdecl getwchar() {ಹಿಂತಿರುಗಿ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {ಹಿಂತಿರುಗಿ (fputwc(_C,stdout)); }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು getwc(_stm) fgetwc(_stm)
#ವ್ಯಾಖ್ಯಾನಿಸು putwc(_c,_stm) fputwc(_c,_stm)
#ವ್ಯಾಖ್ಯಾನಿಸು _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#ವ್ಯಾಖ್ಯಾನಿಸು _getwc_nolock(_c) _fgetwc_nolock(_c)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDLIB_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(ದೀರ್ಘ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  ದ್ವಿಗುಣ __cdecl wcstod(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wcstod_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,_locale_t _Locale);
  ದಶಮಾಂಶ __cdecl wcstof( ಸ್ಥಿರಾಂಕ wchar_t *nptr, wchar_t **endptr);
#ಆದರೆ !defined __NO_ISOCEXT /* in libmingwex.a */
  ದಶಮಾಂಶ __cdecl wcstof (ಸ್ಥಿರಾಂಕ wchar_t * __restrict__, wchar_t ** __restrict__);
  ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl wcstold (ಸ್ಥಿರಾಂಕ wchar_t * __restrict__, wchar_t ** __restrict__);
#ಆದರೆ_ಅಂತ್ಯ /* __NO_ISOCEXT */
  ದೀರ್ಘ __cdecl wcstol(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ದೀರ್ಘ __cdecl _wcstol_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl wcstoul(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _wcstoul_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ಸ್ಥಿರಾಂಕ wchar_t *_VarName);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WSYSTEM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsystem(ಸ್ಥಿರಾಂಕ wchar_t *_Command);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wtoi(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wtoi_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ದೀರ್ಘ __cdecl _wtol(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP ದೀರ್ಘ __cdecl _wtol_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(ಚಿಹ್ನೆರಹಿತ __int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _wcstoui64(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _wcstoui64_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _POSIX_
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDLIBP_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *ತುಂಬಿದ_ಮಾರ್ಗ,ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP ಶೂನ್ಯ __cdecl _wmakepath(wchar_t *ಫಲಿತಾಂಶ_ಮಾರ್ಗ,ಸ್ಥಿರಾಂಕ wchar_t *_Drive,ಸ್ಥಿರಾಂಕ wchar_t *_Dir,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_Ext);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WPERROR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಸ್ಥಿರಾಂಕ wchar_t *Err_ಸಂದೇಶ);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wputenv(ಸ್ಥಿರಾಂಕ wchar_t *_EnvString);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsearchenv(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_EnvVar,wchar_t *ಫಲಿತಾಂಶ_ಮಾರ್ಗ);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsplitpath(ಸ್ಥಿರಾಂಕ wchar_t *ತುಂಬಿದ_ಮಾರ್ಗ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTRING_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *ಮೂಲ_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t _Ch);
  ಪೂರ್ಣಾಂಕ __cdecl wcscmp(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *ಮೂಲ_3);
  ಗಾತ್ರ_t __cdecl wcscspn(ಸ್ಥಿರಾಂಕ wchar_t *_Str,ಸ್ಥಿರಾಂಕ wchar_t *_Control);
  ಗಾತ್ರ_t __cdecl wcslen(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  ಗಾತ್ರ_t __cdecl wcsnlen(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *ಮೂಲ_3,ಗಾತ್ರ_t ಎಣಿಕೆ_6);
  ಪೂರ್ಣಾಂಕ __cdecl wcsncmp(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *ಮೂಲ_3,ಗಾತ್ರ_t ಎಣಿಕೆ_6);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ಸ್ಥಿರಾಂಕ wchar_t *_Str,ಸ್ಥಿರಾಂಕ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t _Ch);
  ಗಾತ್ರ_t __cdecl wcsspn(ಸ್ಥಿರಾಂಕ wchar_t *_Str,ಸ್ಥಿರಾಂಕ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ಸ್ಥಿರಾಂಕ wchar_t *_Str,ಸ್ಥಿರಾಂಕ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ಸ್ಥಿರಾಂಕ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(ಪೂರ್ಣಾಂಕ Err_ಅಂಕೆ);
  _CRTIMP wchar_t *__cdecl __wcserror(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsicmp(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsicmp_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsnicmp(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsnicmp_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  ಗಾತ್ರ_t __cdecl wcsxfrm(wchar_t *_Dst,ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಗಾತ್ರ_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl wcscoll(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcscoll_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsicoll(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsicoll_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsncoll(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsncoll_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsnicoll(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcsnicoll_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
#ವ್ಯಾಖ್ಯಾನಿಸು wcswcs wcsstr
  ಪೂರ್ಣಾಂಕ __cdecl wcsicmp(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2);
  ಪೂರ್ಣಾಂಕ __cdecl wcsnicmp(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  ಪೂರ್ಣಾಂಕ __cdecl wcsicoll(ಸ್ಥಿರಾಂಕ wchar_t *_Str1,ಸ್ಥಿರಾಂಕ wchar_t *_Str2);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TM_DEFINED
  ರಚನೆ tm {
    ಪೂರ್ಣಾಂಕ tm_sec;
    ಪೂರ್ಣಾಂಕ tm_min;
    ಪೂರ್ಣಾಂಕ tm_hour;
    ಪೂರ್ಣಾಂಕ tm_mday;
    ಪೂರ್ಣಾಂಕ tm_mon;
    ಪೂರ್ಣಾಂಕ tm_year;
    ಪೂರ್ಣಾಂಕ tm_wday;
    ಪೂರ್ಣಾಂಕ tm_yday;
    ಪೂರ್ಣಾಂಕ tm_isdst;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WTIME_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ಸ್ಥಿರಾಂಕ __time32_t *ಸಮಯ_2);
  ಗಾತ್ರ_t __cdecl wcsftime(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm);
  _CRTIMP ಗಾತ್ರ_t __cdecl _wcsftime_l(wchar_t *_Buf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,ಸ್ಥಿರಾಂಕ ರಚನೆ tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *ಬಫರ್_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *ಬಫರ್_2);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ಸ್ಥಿರಾಂಕ __time64_t *ಸಮಯ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_WTIME_INL
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE wchar_t *__cdecl _wctime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _wctime32(ಸಮಯ_2); }
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE wchar_t *__cdecl _wctime(ಸ್ಥಿರಾಂಕ time_t *ಸಮಯ_2) { ಹಿಂತಿರುಗಿ _wctime64(ಸಮಯ_2); }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ mbstate_t;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ wchar_t _Wint_t;

  wint_t __cdecl btowc(ಪೂರ್ಣಾಂಕ);
  ಗಾತ್ರ_t __cdecl mbrlen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Ch,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,mbstate_t *_State);
  ಗಾತ್ರ_t __cdecl mbrtowc(wchar_t *_DstCh,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_SrcCh,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,mbstate_t *_State);
  ಗಾತ್ರ_t __cdecl mbsrtowcs(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ **_PSrc,ಗಾತ್ರ_t ಎಣಿಕೆ_6,mbstate_t *_State);
  ಗಾತ್ರ_t __cdecl wcrtomb(ಅಕ್ಷರ *_Dest,wchar_t ಮೂಲ_3,mbstate_t *_State);
  ಗಾತ್ರ_t __cdecl wcsrtombs(ಅಕ್ಷರ *_Dest,ಸ್ಥಿರಾಂಕ wchar_t **_PSource,ಗಾತ್ರ_t ಎಣಿಕೆ_6,mbstate_t *_State);
  ಪೂರ್ಣಾಂಕ __cdecl wctob(wint_t _WCh);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, ಗಾತ್ರ_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ಸ್ಥಿರಾಂಕ wchar_t *s, wchar_t c, ಗಾತ್ರ_t n);
  ಪೂರ್ಣಾಂಕ wmemcmp(ಸ್ಥಿರಾಂಕ wchar_t *s1, ಸ್ಥಿರಾಂಕ wchar_t *s2,ಗಾತ್ರ_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ಸ್ಥಿರಾಂಕ wchar_t *s2,ಗಾತ್ರ_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ಸ್ಥಿರಾಂಕ wchar_t *s2, ಗಾತ್ರ_t n);
  ದೀರ್ಘ ದೀರ್ಘ __cdecl wcstoll(ಸ್ಥಿರಾಂಕ wchar_t *nptr,wchar_t **endptr, ಪೂರ್ಣಾಂಕ ತಳ);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __cdecl wcstoull(ಸ್ಥಿರಾಂಕ wchar_t *nptr,wchar_t **endptr, ಪೂರ್ಣಾಂಕ ತಳ);
#ಆದರೆ_ಅಂತ್ಯ /* __NO_ISOCEXT */

  ಶೂನ್ಯ *__cdecl memmove(ಶೂನ್ಯ *_Dst,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  ಶೂನ್ಯ *__cdecl ಸ್ಮರಣೆ_ನಕಲು(ಶೂನ್ಯ *_Dst,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl fwide(FILE *_F,ಪೂರ್ಣಾಂಕ _M) { (ಶೂನ್ಯ)_F; ಹಿಂತಿರುಗಿ (_M); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl mbsinit(ಸ್ಥಿರಾಂಕ mbstate_t *_P) { ಹಿಂತಿರುಗಿ (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ಸ್ಥಿರಾಂಕ wchar_t *_S,wchar_t _C,ಗಾತ್ರ_t _N) { ಗಾಗಿ (;0<_N;++_S,--_N) ಆದರೆ (*_S==_C) ಹಿಂತಿರುಗಿ (_CONST_RETURN wchar_t *)(_S); ಹಿಂತಿರುಗಿ (0); }
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl wmemcmp(ಸ್ಥಿರಾಂಕ wchar_t *_S1,ಸ್ಥಿರಾಂಕ wchar_t *_S2,ಗಾತ್ರ_t _N) { ಗಾಗಿ (; 0 < _N; ++_S1,++_S2,--_N) ಆದರೆ (*_S1!=*_S2) ಹಿಂತಿರುಗಿ (*_S1 < *_S2 ? -1 : +1); ಹಿಂತಿರುಗಿ (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ಸ್ಥಿರಾಂಕ wchar_t *_S2,ಗಾತ್ರ_t _N) { ಹಿಂತಿರುಗಿ (wchar_t *)ಸ್ಮರಣೆ_ನಕಲು(_S1,_S2,_N*ಗಾತ್ರ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ಸ್ಥಿರಾಂಕ wchar_t *_S2,ಗಾತ್ರ_t _N) { ಹಿಂತಿರುಗಿ (wchar_t *)memmove(_S1,_S2,_N*ಗಾತ್ರ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,ಗಾತ್ರ_t _N) {
    wchar_t *_Su = _S;
    ಗಾಗಿ (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    ಹಿಂತಿರುಗಿ (_S);
  }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/wchar_s.h>
#ಆದರೆ_ಅಂತ್ಯ
