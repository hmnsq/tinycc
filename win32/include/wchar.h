/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#അന്തര്ഭാവ <_mingw.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  തരനിർവചനം __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  തരനിർവചനം __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  ഘടന _iobuf {
    അക്ഷരം *_ptr;
    പൂർണ്ണസംഖ്യ _cnt;
    അക്ഷരം *_base;
    പൂർണ്ണസംഖ്യ _flag;
    പൂർണ്ണസംഖ്യ _file;
    പൂർണ്ണസംഖ്യ _charbuf;
    പൂർണ്ണസംഖ്യ _bufsiz;
    അക്ഷരം *_tmpfname;
  };
  തരനിർവചനം ഘടന _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ശൂന്യം);
#അല്ലെങ്കിൽ
#ifdef _MSVCRT_
ബാഹ്യ FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#അല്ലെങ്കിൽ
ബാഹ്യ FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#define __iob_func()	(*_imp___iob)
#define _iob __iob_func()
#endif
#endif

#define _iob __iob_func()
#endif

#ifndef _STDSTREAM_DEFINED
#define stdin (&__iob_func()[0])
#define stdout (&__iob_func()[1])
#define stderr (&__iob_func()[2])
#define _STDSTREAM_DEFINED
#endif

#ifndef _FSIZE_T_DEFINED
  തരനിർവചനം unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  ഘടന _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ഘടന _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ഘടന _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ഘടന _wfinddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    wchar_t name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _wfinddata_t _wfinddata32_t
#define _wfinddatai64_t _wfinddata32i64_t

#define _wfindfirst _wfindfirst32
#define _wfindnext _wfindnext32
#define _wfindfirsti64 _wfindfirst32i64
#define _wfindnexti64 _wfindnext32i64
#അല്ലെങ്കിൽ
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef ശൂന്യ
#ifdef __cplusplus
#define ശൂന്യ 0
#അല്ലെങ്കിൽ
#define ശൂന്യ ((ശൂന്യം *)0)
#endif
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_CTYPEDATA_DEFINED
#define _CRT_CTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS

#ifndef __PCTYPE_FUNC
#define __PCTYPE_FUNC __pctype_func()
#ifdef _MSVCRT_
#define __pctype_func() (_pctype)
#അല്ലെങ്കിൽ
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  ബാഹ്യ unsigned short *_pctype;
#അല്ലെങ്കിൽ
  ബാഹ്യ unsigned short **_imp___pctype;
#define _pctype (*_imp___pctype)
#endif
#endif
#endif
#endif

#ifndef _CRT_WCTYPEDATA_DEFINED
#define _CRT_WCTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS
#ifndef _wctype
#ifdef _MSVCRT_
  ബാഹ്യ unsigned short *_wctype;
#അല്ലെങ്കിൽ
  ബാഹ്യ unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#അല്ലെങ്കിൽ
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  ബാഹ്യ unsigned short *_pwctype;
#അല്ലെങ്കിൽ
  ബാഹ്യ unsigned short **_imp___pwctype;
#define _pwctype (*_imp___pwctype)
#endif
#endif

#endif
#endif

#define _UPPER 0x1
#define _LOWER 0x2
#define _DIGIT 0x4
#define _SPACE 0x8

#define _PUNCT 0x10
#define _CONTROL 0x20
#define _BLANK 0x40
#define _HEX 0x80

#define _LEADBYTE 0x8000
#define _ALPHA (0x0100|_UPPER|_LOWER)

#ifndef _WCTYPE_DEFINED
#define _WCTYPE_DEFINED

  പൂർണ്ണസംഖ്യ __cdecl iswalpha(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswupper(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswlower(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswdigit(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswxdigit(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswspace(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswpunct(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswalnum(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswprint(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswgraph(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswcntrl(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswascii(wint_t _C);
  പൂർണ്ണസംഖ്യ __cdecl isleadbyte(പൂർണ്ണസംഖ്യ _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _isleadbyte_l(പൂർണ്ണസംഖ്യ _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl __iswcsymf(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl __iswcsym(wint_t _C);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(പൂർണ്ണസംഖ്യ _Drive,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ);
  wchar_t *__cdecl _wgetdcwd_nolock(പൂർണ്ണസംഖ്യ _Drive,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wchdir(സ്ഥിരം wchar_t *_Path);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wmkdir(സ്ഥിരം wchar_t *_Path);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wrmdir(സ്ഥിരം wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _waccess(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wchmod(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _Mode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcreat(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wfindnext32(intptr_t _FindHandle,ഘടന _wfinddata32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wunlink(സ്ഥിരം wchar_t *_Filename);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wrename(സ്ഥിരം wchar_t *_NewFilename,സ്ഥിരം wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata64_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wfindnext32i64(intptr_t _FindHandle,ഘടന _wfinddata32i64_t *_FindData);
  പൂർണ്ണസംഖ്യ __cdecl _wfindnext64i32(intptr_t _FindHandle,ഘടന _wfinddata64i32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wfindnext64(intptr_t _FindHandle,ഘടന _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(പൂർണ്ണസംഖ്യ *_FileHandle,സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,പൂർണ്ണസംഖ്യ _PermissionFlag);
#എങ്കിൽ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,...);
#അല്ലെങ്കിൽ
  ബാഹ്യ "C++" _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _PermissionMode = 0);
  ബാഹ്യ "C++" _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,പൂർണ്ണസംഖ്യ _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(പൂർണ്ണസംഖ്യ _Category,സ്ഥിരം wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsystem(സ്ഥിരം wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#എങ്കിൽ !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#define iswalpha(_c) (iswctype(_c,_ALPHA))
#define iswupper(_c) (iswctype(_c,_UPPER))
#define iswlower(_c) (iswctype(_c,_LOWER))
#define iswdigit(_c) (iswctype(_c,_DIGIT))
#define iswxdigit(_c) (iswctype(_c,_HEX))
#define iswspace(_c) (iswctype(_c,_SPACE))
#define iswpunct(_c) (iswctype(_c,_PUNCT))
#define iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#define iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#define iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#define iswcntrl(_c) (iswctype(_c,_CONTROL))
#define iswascii(_c) ((unsigned)(_c) < 0x80)

#define _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#define _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#define _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#define _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#define _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#define _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#define _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#define _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#define _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#define _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#define _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#ifndef _CTYPE_DISABLE_MACROS
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned അക്ഷരം)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#എങ്കിൽ !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  തരനിർവചനം unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  തരനിർവചനം unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ _dev_t;
#ifndef	NO_OLDNAMES
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  തരനിർവചനം long _off_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  തരനിർവചനം long long _off64_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#അല്ലെങ്കിൽ
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#അല്ലെങ്കിൽ
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  ഘടന _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#ifndef	NO_OLDNAMES
  ഘടന stat {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#endif

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64

  ഘടന _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  ഘടന _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  ഘടന _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#endif

#define __stat64 _stat64

#endif

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wstat32(സ്ഥിരം wchar_t *_Name,ഘടന _stat32 *_Stat);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wstat32i64(സ്ഥിരം wchar_t *_Name,ഘടന _stat32i64 *_Stat);
  പൂർണ്ണസംഖ്യ __cdecl _wstat64i32(സ്ഥിരം wchar_t *_Name,ഘടന _stat64i32 *_Stat);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wstat64(സ്ഥിരം wchar_t *_Name,ഘടന _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(ശൂന്യം);
  _CRTIMP wint_t __cdecl _getwche(ശൂന്യം);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cputws(സ്ഥിരം wchar_t *_String);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_p(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_p(സ്ഥിരം wchar_t *_Format,va_list _ArgList);

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(ശൂന്യം);
  wint_t __cdecl _getwche_nolock(ശൂന്യം);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode);
#അല്ലെങ്കിൽ
  _CRTIMP FILE *__cdecl _wfsopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode,പൂർണ്ണസംഖ്യ _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ശൂന്യം);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ശൂന്യം);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ,FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl fputws(സ്ഥിരം wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _putws(സ്ഥിരം wchar_t *_Str);
  പൂർണ്ണസംഖ്യ __cdecl fwprintf(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl wprintf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf(സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl vfwprintf(FILE *_File,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl vwprintf(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl swprintf(wchar_t*, സ്ഥിരം wchar_t*, ...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl vswprintf(wchar_t*, സ്ഥിരം wchar_t*,va_list);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwprintf(wchar_t *_Dest,size_t എണ്ണം_5,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnwprintf(wchar_t *_Dest,size_t എണ്ണം_5,സ്ഥിരം wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  പൂർണ്ണസംഖ്യ __cdecl snwprintf (wchar_t *s, size_t n, സ്ഥിരം wchar_t * format, ...);
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl vsnwprintf (wchar_t *s, size_t n, സ്ഥിരം wchar_t *format, va_list arg) { തിരികെ _vsnwprintf(s,n,format,arg); }
  പൂർണ്ണസംഖ്യ __cdecl vwscanf (സ്ഥിരം wchar_t *, va_list);
  പൂർണ്ണസംഖ്യ __cdecl vfwscanf (FILE *,സ്ഥിരം wchar_t *,va_list);
  പൂർണ്ണസംഖ്യ __cdecl vswscanf (സ്ഥിരം wchar_t *,സ്ഥിരം wchar_t *,va_list);
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwprintf_p(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wprintf_p(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfwprintf_p(FILE *_File,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vwprintf_p(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf_p(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf_p(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwprintf_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwprintf_p_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfwprintf_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vfwprintf_p_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,va_list _Args);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl __swprintf_l(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl __vswprintf_l(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#അന്തര്ഭാവ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(സ്ഥിരം wchar_t *_Directory,സ്ഥിരം wchar_t *_FilePrefix);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl fwscanf(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fwscanf_l(FILE *_File,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  പൂർണ്ണസംഖ്യ __cdecl swscanf(സ്ഥിരം wchar_t *_Src,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swscanf_l(സ്ഥിരം wchar_t *_Src,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwscanf(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwscanf_l(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  പൂർണ്ണസംഖ്യ __cdecl wscanf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wscanf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(പൂർണ്ണസംഖ്യ _FileHandle ,സ്ഥിരം wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ശൂന്യം __cdecl _wperror(സ്ഥിരം wchar_t *Err_സന്ദേശം);
#endif
  _CRTIMP FILE *__cdecl _wpopen(സ്ഥിരം wchar_t *_Command,സ്ഥിരം wchar_t *_Mode);
#എങ്കിൽ !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wremove(സ്ഥിരം wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#എങ്കിൽ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#അല്ലെങ്കിൽ
  __CRT_INLINE wint_t __cdecl getwchar() {തിരികെ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {തിരികെ (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(പൂർണ്ണസംഖ്യ മൂല്യം_2,wchar_t *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long മൂല്യം_2,wchar_t *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long മൂല്യം_2,wchar_t *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  ഇരട്ട __cdecl wcstod(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP ഇരട്ട __cdecl _wcstod_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  ദശാംശം __cdecl wcstof( സ്ഥിരം wchar_t *nptr, wchar_t **endptr);
#എങ്കിൽ !defined __NO_ISOCEXT /* in libmingwex.a */
  ദശാംശം __cdecl wcstof (സ്ഥിരം wchar_t * __restrict__, wchar_t ** __restrict__);
  long ഇരട്ട __cdecl wcstold (സ്ഥിരം wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP long __cdecl _wcstol_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(സ്ഥിരം wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsystem(സ്ഥിരം wchar_t *_Command);
#endif
  _CRTIMP ഇരട്ട __cdecl _wtof(സ്ഥിരം wchar_t *_Str);
  _CRTIMP ഇരട്ട __cdecl _wtof_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wtoi(സ്ഥിരം wchar_t *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wtoi_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(സ്ഥിരം wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(സ്ഥിരം wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,സ്ഥിരം wchar_t *_Path,size_t Size_In_വാക്കുകൾ);
  _CRTIMP ശൂന്യം __cdecl _wmakepath(wchar_t *_ResultPath,സ്ഥിരം wchar_t *_Drive,സ്ഥിരം wchar_t *_Dir,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ശൂന്യം __cdecl _wperror(സ്ഥിരം wchar_t *Err_സന്ദേശം);
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wputenv(സ്ഥിരം wchar_t *_EnvString);
  _CRTIMP ശൂന്യം __cdecl _wsearchenv(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP ശൂന്യം __cdecl _wsplitpath(സ്ഥിരം wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(സ്ഥിരം wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(സ്ഥിരം wchar_t *_Str,wchar_t _Ch);
  പൂർണ്ണസംഖ്യ __cdecl wcscmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source);
  size_t __cdecl wcscspn(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_Control);
  size_t __cdecl wcslen(സ്ഥിരം wchar_t *_Str);
  size_t __cdecl wcsnlen(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source,size_t എണ്ണം_5);
  പൂർണ്ണസംഖ്യ __cdecl wcsncmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source,size_t എണ്ണം_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(സ്ഥിരം wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,സ്ഥിരം wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(പൂർണ്ണസംഖ്യ Err_അക്കം);
  _CRTIMP wchar_t *__cdecl __wcserror(സ്ഥിരം wchar_t *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicmp_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicmp_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_എണ്ണം);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl wcscoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcscoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsncoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsncoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(സ്ഥിരം wchar_t *_Str);
#define wcswcs wcsstr
  പൂർണ്ണസംഖ്യ __cdecl wcsicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  പൂർണ്ണസംഖ്യ __cdecl wcsnicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_എണ്ണം);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  പൂർണ്ണസംഖ്യ __cdecl wcsicoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  ഘടന tm {
    പൂർണ്ണസംഖ്യ tm_sec;
    പൂർണ്ണസംഖ്യ tm_min;
    പൂർണ്ണസംഖ്യ tm_hour;
    പൂർണ്ണസംഖ്യ tm_mday;
    പൂർണ്ണസംഖ്യ tm_mon;
    പൂർണ്ണസംഖ്യ tm_year;
    പൂർണ്ണസംഖ്യ tm_wday;
    പൂർണ്ണസംഖ്യ tm_yday;
    പൂർണ്ണസംഖ്യ tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(സ്ഥിരം __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,സ്ഥിരം ഘടന tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,സ്ഥിരം ഘടന tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(സ്ഥിരം __time64_t *_Time);
#endif

#എങ്കിൽ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(സ്ഥിരം time_t *_Time) { തിരികെ _wctime32(_Time); }
#അല്ലെങ്കിൽ
__CRT_INLINE wchar_t *__cdecl _wctime(സ്ഥിരം time_t *_Time) { തിരികെ _wctime64(_Time); }
#endif
#endif
#endif

  തരനിർവചനം പൂർണ്ണസംഖ്യ mbstate_t;
  തരനിർവചനം wchar_t _Wint_t;

  wint_t __cdecl btowc(പൂർണ്ണസംഖ്യ);
  size_t __cdecl mbrlen(സ്ഥിരം അക്ഷരം *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,സ്ഥിരം അക്ഷരം *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,സ്ഥിരം അക്ഷരം **_PSrc,size_t എണ്ണം_5,mbstate_t *_State);
  size_t __cdecl wcrtomb(അക്ഷരം *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(അക്ഷരം *_Dest,സ്ഥിരം wchar_t **_PSource,size_t എണ്ണം_5,mbstate_t *_State);
  പൂർണ്ണസംഖ്യ __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(സ്ഥിരം wchar_t *s, wchar_t c, size_t n);
  പൂർണ്ണസംഖ്യ wmemcmp(സ്ഥിരം wchar_t *s1, സ്ഥിരം wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,സ്ഥിരം wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, സ്ഥിരം wchar_t *s2, size_t n);
  long long __cdecl wcstoll(സ്ഥിരം wchar_t *nptr,wchar_t **endptr, പൂർണ്ണസംഖ്യ base);
  unsigned long long __cdecl wcstoull(സ്ഥിരം wchar_t *nptr,wchar_t **endptr, പൂർണ്ണസംഖ്യ base);
#endif /* __NO_ISOCEXT */

  ശൂന്യം *__cdecl memmove(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,size_t Max_എണ്ണം);
  ശൂന്യം *__cdecl memcpy(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,size_t Max_എണ്ണം);
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl fwide(FILE *_F,പൂർണ്ണസംഖ്യ _M) { (ശൂന്യം)_F; തിരികെ (_M); }
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl mbsinit(സ്ഥിരം mbstate_t *_P) { തിരികെ (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(സ്ഥിരം wchar_t *_S,wchar_t _C,size_t _N) { വേണ്ടി (;0<_N;++_S,--_N) എങ്കിൽ (*_S==_C) തിരികെ (_CONST_RETURN wchar_t *)(_S); തിരികെ (0); }
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl wmemcmp(സ്ഥിരം wchar_t *_S1,സ്ഥിരം wchar_t *_S2,size_t _N) { വേണ്ടി (; 0 < _N; ++_S1,++_S2,--_N) എങ്കിൽ (*_S1!=*_S2) തിരികെ (*_S1 < *_S2 ? -1 : +1); തിരികെ (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,സ്ഥിരം wchar_t *_S2,size_t _N) { തിരികെ (wchar_t *)memcpy(_S1,_S2,_N*വലുപ്പം(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,സ്ഥിരം wchar_t *_S2,size_t _N) { തിരികെ (wchar_t *)memmove(_S1,_S2,_N*വലുപ്പം(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    വേണ്ടി (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    തിരികെ (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)

#അന്തര്ഭാവ <sec_api/wchar_s.h>
#endif
