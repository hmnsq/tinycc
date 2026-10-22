/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_WCHAR
#تعریف_کرو _INC_WCHAR

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ WCHAR_MIN  /* also at stdint.h */
#تعریف_کرو WCHAR_MIN 0
#تعریف_کرو WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#اگر_ختم

#اگر_غیر_تعریف_شدہ __GNUC_VA_LIST
#تعریف_کرو __GNUC_VA_LIST
  قسمتعریف __builtin_va_list __gnuc_va_list;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _VA_LIST_DEFINED
#تعریف_کرو _VA_LIST_DEFINED
  قسمتعریف __gnuc_va_list va_list;
#اگر_ختم

#اگر_غیر_تعریف_شدہ WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _FILE_DEFINED
  ساخت _iobuf {
    حرف *_ptr;
    صحیح _cnt;
    حرف *بنیاد_4;
    صحیح _flag;
    صحیح _file;
    صحیح _charbuf;
    صحیح _bufsiz;
    حرف *_tmpfname;
  };
  قسمتعریف ساخت _iobuf FILE;
#تعریف_کرو _FILE_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _STDIO_DEFINED
#اگر_تعریف_شدہ _WIN64
  _CRTIMP FILE *__cdecl __iob_func(خالی);
#ورنہ
#اگر_تعریف_شدہ _MSVCRT_
خارجی FILE _iob[];	/* A pointer to an array of FILE */
#تعریف_کرو __iob_func()	(_iob)
#ورنہ
خارجی FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#تعریف_کرو __iob_func()	(*_imp___iob)
#تعریف_کرو _iob __iob_func()
#اگر_ختم
#اگر_ختم

#تعریف_کرو _iob __iob_func()
#اگر_ختم

#اگر_غیر_تعریف_شدہ _STDSTREAM_DEFINED
#تعریف_کرو stdin (&__iob_func()[0])
#تعریف_کرو stdout (&__iob_func()[1])
#تعریف_کرو stderr (&__iob_func()[2])
#تعریف_کرو _STDSTREAM_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _FSIZE_T_DEFINED
  قسمتعریف غیرعلامتی طویل _fsize_t;
#تعریف_کرو _FSIZE_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WFINDDATA_T_DEFINED
  ساخت _wfinddata32_t {
    غیرعلامتی attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    _fsize_t سائز;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ساخت _wfinddata32i64_t {
    غیرعلامتی attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    __int64 سائز;
    wchar_t name[260];
  };

  ساخت _wfinddata64i32_t {
    غیرعلامتی attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    _fsize_t سائز;
    wchar_t name[260];
  };

  ساخت _wfinddata64_t {
    غیرعلامتی attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    __int64 سائز;
    wchar_t name[260];
  };
/* #endif */

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#تعریف_کرو _wfinddata_t _wfinddata32_t
#تعریف_کرو _wfinddatai64_t _wfinddata32i64_t

#تعریف_کرو _wfindfirst _wfindfirst32
#تعریف_کرو _wfindnext _wfindnext32
#تعریف_کرو _wfindfirsti64 _wfindfirst32i64
#تعریف_کرو _wfindnexti64 _wfindnext32i64
#ورنہ
#تعریف_کرو _wfinddata_t _wfinddata64i32_t
#تعریف_کرو _wfinddatai64_t _wfinddata64_t

#تعریف_کرو _wfindfirst _wfindfirst64i32
#تعریف_کرو _wfindnext _wfindnext64i32
#تعریف_کرو _wfindfirsti64 _wfindfirst64
#تعریف_کرو _wfindnexti64 _wfindnext64
#اگر_ختم

#تعریف_کرو _WFINDDATA_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CONST_RETURN
#تعریف_کرو _CONST_RETURN
#اگر_ختم

#تعریف_کرو _WConst_return _CONST_RETURN

#اگر_غیر_تعریف_شدہ _CRT_CTYPEDATA_DEFINED
#تعریف_کرو _CRT_CTYPEDATA_DEFINED
#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS

#اگر_غیر_تعریف_شدہ __PCTYPE_FUNC
#تعریف_کرو __PCTYPE_FUNC __pctype_func()
#اگر_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pctype_func() (_pctype)
#ورنہ
#تعریف_کرو __pctype_func() (*_imp___pctype)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _pctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_pctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___pctype;
#تعریف_کرو _pctype (*_imp___pctype)
#اگر_ختم
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_WCTYPEDATA_DEFINED
#تعریف_کرو _CRT_WCTYPEDATA_DEFINED
#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS
#اگر_غیر_تعریف_شدہ _wctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_wctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___wctype;
#تعریف_کرو _wctype (*_imp___wctype)
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pwctype_func() (_pwctype)
#ورنہ
#تعریف_کرو __pwctype_func() (*_imp___pwctype)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _pwctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_pwctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___pwctype;
#تعریف_کرو _pwctype (*_imp___pwctype)
#اگر_ختم
#اگر_ختم

#اگر_ختم
#اگر_ختم

#تعریف_کرو بالائی_3 0x1
#تعریف_کرو زیریں_2 0x2
#تعریف_کرو _DIGIT 0x4
#تعریف_کرو _SPACE 0x8

#تعریف_کرو _PUNCT 0x10
#تعریف_کرو _CONTROL 0x20
#تعریف_کرو _BLANK 0x40
#تعریف_کرو _HEX 0x80

#تعریف_کرو _LEADBYTE 0x8000
#تعریف_کرو _ALPHA (0x0100|بالائی_3|زیریں_2)

#اگر_غیر_تعریف_شدہ _WCTYPE_DEFINED
#تعریف_کرو _WCTYPE_DEFINED

  صحیح __cdecl iswalpha(wint_t _C);
  _CRTIMP صحیح __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswupper(wint_t _C);
  _CRTIMP صحیح __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswlower(wint_t _C);
  _CRTIMP صحیح __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswdigit(wint_t _C);
  _CRTIMP صحیح __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswxdigit(wint_t _C);
  _CRTIMP صحیح __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswspace(wint_t _C);
  _CRTIMP صحیح __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswpunct(wint_t _C);
  _CRTIMP صحیح __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswalnum(wint_t _C);
  _CRTIMP صحیح __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswprint(wint_t _C);
  _CRTIMP صحیح __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswgraph(wint_t _C);
  _CRTIMP صحیح __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswcntrl(wint_t _C);
  _CRTIMP صحیح __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswascii(wint_t _C);
  صحیح __cdecl isleadbyte(صحیح _C);
  _CRTIMP صحیح __cdecl _isleadbyte_l(صحیح _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP صحیح __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP صحیح __cdecl __iswcsymf(wint_t _C);
  _CRTIMP صحیح __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl __iswcsym(wint_t _C);
  _CRTIMP صحیح __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl is_wctype(wint_t _C,wctype_t _Type);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WDIRECT_DEFINED
#تعریف_کرو _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحیح سائز_اندر_الفاظ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحیح _Drive,wchar_t *_DstBuf,صحیح سائز_اندر_الفاظ);
  wchar_t *__cdecl _wgetdcwd_nolock(صحیح _Drive,wchar_t *_DstBuf,صحیح سائز_اندر_الفاظ);
  _CRTIMP صحیح __cdecl _wchdir(ثابت wchar_t *راستہ_2);
  _CRTIMP صحیح __cdecl _wmkdir(ثابت wchar_t *راستہ_2);
  _CRTIMP صحیح __cdecl _wrmdir(ثابت wchar_t *راستہ_2);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WIO_DEFINED
#تعریف_کرو _WIO_DEFINED

  _CRTIMP صحیح __cdecl _waccess(ثابت wchar_t *_Filename,صحیح Access_منوال);
  _CRTIMP صحیح __cdecl _wchmod(ثابت wchar_t *_Filename,صحیح منوال_3);
  _CRTIMP صحیح __cdecl _wcreat(ثابت wchar_t *_Filename,صحیح Permission_منوال);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,ساخت _wfinddata32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wfindnext32(intptr_t ڈھونڈو_Handle,ساخت _wfinddata32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحیح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,ساخت _wfinddata32i64_t *ڈھونڈو_ڈیٹا);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,ساخت _wfinddata64i32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,ساخت _wfinddata64_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wfindnext32i64(intptr_t ڈھونڈو_Handle,ساخت _wfinddata32i64_t *ڈھونڈو_ڈیٹا);
  صحیح __cdecl _wfindnext64i32(intptr_t ڈھونڈو_Handle,ساخت _wfinddata64i32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wfindnext64(intptr_t ڈھونڈو_Handle,ساخت _wfinddata64_t *ڈھونڈو_ڈیٹا);
#اگر_ختم
  _CRTIMP errno_t __cdecl _wsopen_s(صحیح *_FileHandle,ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح _PermissionFlag);
#اگر !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,...);
  _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
#ورنہ
  خارجی "C++" _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح Permission_منوال = 0);
  خارجی "C++" _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح Permission_منوال = 0);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WLOCALE_DEFINED
#تعریف_کرو _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحیح _Category,ثابت wchar_t *_Locale);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WPROCESS_DEFINED
#تعریف_کرو _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#اگر_غیر_تعریف_شدہ _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCTYPE_INLINE_DEFINED
#تعریف_منسوخ _CRT_WCTYPE_NOINLINE
#اگر !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#تعریف_کرو iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کرو iswupper(_c) (iswctype(_c,بالائی_3))
#تعریف_کرو iswlower(_c) (iswctype(_c,زیریں_2))
#تعریف_کرو iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کرو iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کرو iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کرو iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کرو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کرو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کرو iswascii(_c) ((غیرعلامتی)(_c) < 0x80)

#تعریف_کرو _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#تعریف_کرو _iswupper_l(_c,_p) (_iswctype_l(_c,بالائی_3,_p))
#تعریف_کرو _iswlower_l(_c,_p) (_iswctype_l(_c,زیریں_2,_p))
#تعریف_کرو _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#تعریف_کرو _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#تعریف_کرو _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#تعریف_کرو _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#تعریف_کرو _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS
#تعریف_کرو isleadbyte(_c) (__PCTYPE_FUNC[(غیرعلامتی حرف)(_c)] & _LEADBYTE)
#اگر_ختم
#اگر_ختم
#تعریف_کرو _WCTYPE_INLINE_DEFINED
#اگر_ختم

#اگر !defined(_POSIX_) || defined(__GNUC__)
#اگر_غیر_تعریف_شدہ _INO_T_DEFINED
#تعریف_کرو _INO_T_DEFINED
  قسمتعریف غیرعلامتی مختصر _ino_t;
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  قسمتعریف غیرعلامتی مختصر ino_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _DEV_T_DEFINED
#تعریف_کرو _DEV_T_DEFINED
  قسمتعریف غیرعلامتی صحیح _dev_t;
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  قسمتعریف غیرعلامتی صحیح dev_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _OFF_T_DEFINED
#تعریف_کرو _OFF_T_DEFINED
#اگر_غیر_تعریف_شدہ _OFF_T_
#تعریف_کرو _OFF_T_
  قسمتعریف طویل _off_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل off_t;
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _OFF64_T_DEFINED
#تعریف_کرو _OFF64_T_DEFINED
  قسمتعریف طویل طویل _off64_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل طویل off64_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _STAT_DEFINED
#تعریف_کرو _STAT_DEFINED

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_تعریف_شدہ WIN64
#تعریف_کرو _fstat _fstat32
#تعریف_کرو _stat _stat32
#تعریف_کرو _wstat _wstat32
#ورنہ
#تعریف_کرو _fstat32 _fstat
#تعریف_کرو _stat32 _stat
#تعریف_کرو _wstat32 _wstat
#اگر_ختم
#تعریف_کرو _fstati64 _fstat32i64
#تعریف_کرو _stati64 _stat32i64
#تعریف_کرو _wstati64 _wstat32i64
#ورنہ
#تعریف_کرو _fstat _fstat64i32
#تعریف_کرو _fstati64 _fstat64
#تعریف_کرو _stat _stat64i32
#تعریف_کرو _stati64 _stat64
#تعریف_کرو _wstat _wstat64i32
#تعریف_کرو _wstati64 _wstat64
#اگر_ختم

  ساخت _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    _off_t st_سائز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  ساخت stat {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    _off_t st_سائز;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#اگر_ختم

#اگر INTEGRAL_MAX_بٹ >= 64

  ساخت _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    __int64 st_سائز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  ساخت _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    _off_t st_سائز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  ساخت _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    __int64 st_سائز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#اگر_ختم

#تعریف_کرو __stat64 _stat64

#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTAT_DEFINED
#تعریف_کرو _WSTAT_DEFINED

  _CRTIMP صحیح __cdecl _wstat32(ثابت wchar_t *_Name,ساخت _stat32 *_Stat);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحیح __cdecl _wstat32i64(ثابت wchar_t *_Name,ساخت _stat32i64 *_Stat);
  صحیح __cdecl _wstat64i32(ثابت wchar_t *_Name,ساخت _stat64i32 *_Stat);
  _CRTIMP صحیح __cdecl _wstat64(ثابت wchar_t *_Name,ساخت _stat64 *_Stat);
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCONIO_DEFINED
#تعریف_کرو _WCONIO_DEFINED

#اگر_غیر_تعریف_شدہ WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#اگر_ختم

  _CRTIMP wchar_t *_cgetws(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _getwch(خالی);
  _CRTIMP wint_t __cdecl _getwche(خالی);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP صحیح __cdecl _cputws(ثابت wchar_t *_String);
  _CRTIMP صحیح __cdecl _cwprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vcwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);

  _CRTIMP صحیح __cdecl _cwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(خالی);
  wint_t __cdecl _getwche_nolock(خالی);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTDIO_DEFINED
#تعریف_کرو _WSTDIO_DEFINED

#اگر_غیر_تعریف_شدہ WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#اگر_ختم

#اگر_تعریف_شدہ _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
#ورنہ
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,صحیح _ShFlag);
#اگر_ختم

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(خالی);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(خالی);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحیح سائز_اندر_الفاظ,FILE *_File);
  صحیح __cdecl fputws(ثابت wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP صحیح __cdecl _putws(ثابت wchar_t *_Str);
  صحیح __cdecl fwprintf(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl wprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _scwprintf(ثابت wchar_t *_Format,...);
  صحیح __cdecl vfwprintf(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl vwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl swprintf(wchar_t*, ثابت wchar_t*, ...);
  _CRTIMP صحیح __cdecl vswprintf(wchar_t*, ثابت wchar_t*,va_list);
  _CRTIMP صحیح __cdecl _swprintf_c(wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_c(wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf(wchar_t *_Dest,سائز_t گنتی_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vsnwprintf(wchar_t *_Dest,سائز_t گنتی_5,ثابت wchar_t *_Format,va_list دلائل_2);
#اگر_غیر_تعریف_شدہ __NO_ISOCEXT  /* externs in libmingwex.a */
  صحیح __cdecl snwprintf (wchar_t *s, سائز_t n, ثابت wchar_t * format, ...);
  __CRT_INLINE صحیح __cdecl vsnwprintf (wchar_t *s, سائز_t n, ثابت wchar_t *format, va_list arg) { واپس _vsnwprintf(s,n,format,arg); }
  صحیح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحیح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحیح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#اگر_ختم
  _CRTIMP صحیح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_p(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_p(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vscwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _wprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _wprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _fwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _fwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vfwprintf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vfwprintf_p_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_c_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swprintf_p_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list دلائل_2);
  _CRTIMP صحیح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحیح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list دلائل_2);
#اگر_غیر_تعریف_شدہ RC_INVOKED
#شامل <vadefs.h>
#اگر_ختم

#اگر_تعریف_شدہ _CRT_NON_CONFORMING_SWPRINTFS
#اگر_غیر_تعریف_شدہ __cplusplus
#تعریف_کرو swprintf _swprintf
#تعریف_کرو vswprintf _vswprintf
#تعریف_کرو _swprintf_l __swprintf_l
#تعریف_کرو _vswprintf_l __vswprintf_l
#اگر_ختم
#اگر_ختم

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_سابقہ);
  _CRTIMP صحیح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  صحیح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحیح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snwscanf(ثابت wchar_t *_Src,سائز_t Max_گنتی,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _snwscanf_l(ثابت wchar_t *_Src,سائز_t Max_گنتی,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحیح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحیح _FileHandle ,ثابت wchar_t *منوال_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,FILE *_OldFile);

#اگر_غیر_تعریف_شدہ _CRT_WPERROR_DEFINED
#تعریف_کرو _CRT_WPERROR_DEFINED
  _CRTIMP خالی __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#اگر_ختم
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *منوال_3);
#اگر !defined(NO_OLDNAMES) && !defined(wpopen)
#تعریف_کرو wpopen	_wpopen
#اگر_ختم
  _CRTIMP صحیح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#تعریف_منسوخ _CRT_GETPUTWCHAR_NOINLINE

#اگر !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#تعریف_کرو getwchar() fgetwc(stdin)
#تعریف_کرو putwchar(_c) fputwc((_c),stdout)
#ورنہ
  __CRT_INLINE wint_t __cdecl getwchar() {واپس (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {واپس (fputwc(_C,stdout)); }
#اگر_ختم

#تعریف_کرو getwc(_stm) fgetwc(_stm)
#تعریف_کرو putwc(_c,_stm) fputwc(_c,_stm)
#تعریف_کرو _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#تعریف_کرو _getwc_nolock(_c) _fgetwc_nolock(_c)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTDLIB_DEFINED
#تعریف_کرو _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحیح قدر_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(طویل قدر_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(غیرعلامتی طویل قدر_2,wchar_t *_Dest,صحیح _Radix);
  دوہرا __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr);
  _CRTIMP دوہرا __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,_locale_t _Locale);
  اعشاری __cdecl wcstof( ثابت wchar_t *nptr, wchar_t **endptr);
#اگر !defined __NO_ISOCEXT /* in libmingwex.a */
  اعشاری __cdecl wcstof (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  طویل دوہرا __cdecl wcstold (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#اگر_ختم /* __NO_ISOCEXT */
  طویل __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP طویل __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  غیرعلامتی طویل __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP غیرعلامتی طویل __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#اگر_غیر_تعریف_شدہ _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#اگر_ختم
  _CRTIMP دوہرا __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP دوہرا __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP طویل __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP طویل __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(غیرعلامتی __int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP غیرعلامتی __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP غیرعلامتی __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _POSIX_
#اگر_غیر_تعریف_شدہ _WSTDLIBP_DEFINED
#تعریف_کرو _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *بھرا_راستہ,ثابت wchar_t *راستہ_2,سائز_t سائز_اندر_الفاظ);
  _CRTIMP خالی __cdecl _wmakepath(wchar_t *نتیجہ_راستہ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#اگر_غیر_تعریف_شدہ _CRT_WPERROR_DEFINED
#تعریف_کرو _CRT_WPERROR_DEFINED
  _CRTIMP خالی __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#اگر_ختم
  _CRTIMP صحیح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP خالی __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_راستہ);
  _CRTIMP خالی __cdecl _wsplitpath(ثابت wchar_t *بھرا_راستہ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTRING_DEFINED
#تعریف_کرو _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *ماخذ_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحیح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *ماخذ_3);
  سائز_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  سائز_t __cdecl wcslen(ثابت wchar_t *_Str);
  سائز_t __cdecl wcsnlen(ثابت wchar_t *_Src,سائز_t Max_گنتی);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ثابت wchar_t *ماخذ_3,سائز_t گنتی_5);
  صحیح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ثابت wchar_t *ماخذ_3,سائز_t گنتی_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  سائز_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحیح Err_عدد);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,سائز_t Max_گنتی);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  سائز_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  صحیح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی,_locale_t _Locale);

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#تعریف_کرو wcswcs wcsstr
  صحیح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحیح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,سائز_t Max_گنتی);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحیح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TM_DEFINED
#تعریف_کرو _TM_DEFINED
  ساخت tm {
    صحیح tm_sec;
    صحیح tm_min;
    صحیح tm_hour;
    صحیح tm_mday;
    صحیح tm_mon;
    صحیح tm_year;
    صحیح tm_wday;
    صحیح tm_yday;
    صحیح tm_isdst;
  };
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WTIME_DEFINED
#تعریف_کرو _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ثابت ساخت tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *وقت_2);
  سائز_t __cdecl wcsftime(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,ثابت ساخت tm *_Tm);
  _CRTIMP سائز_t __cdecl _wcsftime_l(wchar_t *_Buf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,ثابت ساخت tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *بفر_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *بفر_2);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *وقت_2);
#اگر_ختم

#اگر !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#تعریف_کرو _INC_WTIME_INL
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { واپس _wctime32(وقت_2); }
#ورنہ
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *وقت_2) { واپس _wctime64(وقت_2); }
#اگر_ختم
#اگر_ختم
#اگر_ختم

  قسمتعریف صحیح mbstate_t;
  قسمتعریف wchar_t _Wint_t;

  wint_t __cdecl btowc(صحیح);
  سائز_t __cdecl mbrlen(ثابت حرف *_Ch,سائز_t سائز_اندر_بائٹیں,mbstate_t *_State);
  سائز_t __cdecl mbrtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,سائز_t سائز_اندر_بائٹیں,mbstate_t *_State);
  سائز_t __cdecl mbsrtowcs(wchar_t *_Dest,ثابت حرف **_PSrc,سائز_t گنتی_5,mbstate_t *_State);
  سائز_t __cdecl wcrtomb(حرف *_Dest,wchar_t ماخذ_3,mbstate_t *_State);
  سائز_t __cdecl wcsrtombs(حرف *_Dest,ثابت wchar_t **_PSource,سائز_t گنتی_5,mbstate_t *_State);
  صحیح __cdecl wctob(wint_t _WCh);

#اگر_غیر_تعریف_شدہ __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, سائز_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *s, wchar_t c, سائز_t n);
  صحیح wmemcmp(ثابت wchar_t *s1, ثابت wchar_t *s2,سائز_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ثابت wchar_t *s2,سائز_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ثابت wchar_t *s2, سائز_t n);
  طویل طویل __cdecl wcstoll(ثابت wchar_t *nptr,wchar_t **endptr, صحیح بنیاد);
  غیرعلامتی طویل طویل __cdecl wcstoull(ثابت wchar_t *nptr,wchar_t **endptr, صحیح بنیاد);
#اگر_ختم /* __NO_ISOCEXT */

  خالی *__cdecl memmove(خالی *_Dst,ثابت خالی *_Src,سائز_t Max_گنتی);
  خالی *__cdecl حافظہ_نقل(خالی *_Dst,ثابت خالی *_Src,سائز_t Max_گنتی);
  __CRT_INLINE صحیح __cdecl fwide(FILE *_F,صحیح _M) { (خالی)_F; واپس (_M); }
  __CRT_INLINE صحیح __cdecl mbsinit(ثابت mbstate_t *_P) { واپس (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *_S,wchar_t _C,سائز_t _N) { برائے (;0<_N;++_S,--_N) اگر (*_S==_C) واپس (_CONST_RETURN wchar_t *)(_S); واپس (0); }
  __CRT_INLINE صحیح __cdecl wmemcmp(ثابت wchar_t *_S1,ثابت wchar_t *_S2,سائز_t _N) { برائے (; 0 < _N; ++_S1,++_S2,--_N) اگر (*_S1!=*_S2) واپس (*_S1 < *_S2 ? -1 : +1); واپس (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ثابت wchar_t *_S2,سائز_t _N) { واپس (wchar_t *)حافظہ_نقل(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ثابت wchar_t *_S2,سائز_t _N) { واپس (wchar_t *)memmove(_S1,_S2,_N*حجم(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,سائز_t _N) {
    wchar_t *_Su = _S;
    برائے (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    واپس (_S);
  }
#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)

#شامل <sec_api/wchar_s.h>
#اگر_ختم
