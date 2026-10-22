/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  ಪ್ರಕಾರನಿರ್ದೇಶ __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  ಸಂರಚನಾ _iobuf {
    ವರ್ಣ *_ptr;
    ಪೂರ್ಣಾಙ್ಕ _cnt;
    ವರ್ಣ *_base;
    ಪೂರ್ಣಾಙ್ಕ _flag;
    ಪೂರ್ಣಾಙ್ಕ _file;
    ಪೂರ್ಣಾಙ್ಕ _charbuf;
    ಪೂರ್ಣಾಙ್ಕ _bufsiz;
    ವರ್ಣ *_tmpfname;
  };
  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ಶೂನ್ಯ);
#ಅನ್ಯಥಾ
#ifdef _MSVCRT_
ಬಾಹ್ಯ FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#ಅನ್ಯಥಾ
ಬಾಹ್ಯ FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  ಸಂರಚನಾ _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ಸಂರಚನಾ _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ಸಂರಚನಾ _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ಸಂರಚನಾ _wfinddata64_t {
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
#ಅನ್ಯಥಾ
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef ರಿಕ್ತ
#ifdef __cplusplus
#define ರಿಕ್ತ 0
#ಅನ್ಯಥಾ
#define ರಿಕ್ತ ((ಶೂನ್ಯ *)0)
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
#ಅನ್ಯಥಾ
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned short *_pctype;
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ unsigned short **_imp___pctype;
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
  ಬಾಹ್ಯ unsigned short *_wctype;
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#ಅನ್ಯಥಾ
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned short *_pwctype;
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ unsigned short **_imp___pwctype;
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

  ಪೂರ್ಣಾಙ್ಕ __cdecl iswalpha(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswupper(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswlower(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswdigit(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswxdigit(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswspace(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswpunct(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswalnum(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswprint(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswgraph(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswcntrl(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswascii(wint_t _C);
  ಪೂರ್ಣಾಙ್ಕ __cdecl isleadbyte(ಪೂರ್ಣಾಙ್ಕ _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _isleadbyte_l(ಪೂರ್ಣಾಙ್ಕ _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __iswcsymf(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __iswcsym(wint_t _C);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ಪೂರ್ಣಾಙ್ಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು);
  wchar_t *__cdecl _wgetdcwd_nolock(ಪೂರ್ಣಾಙ್ಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wchdir(ಧ್ರುವ wchar_t *_Path);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wmkdir(ಧ್ರುವ wchar_t *_Path);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wrmdir(ಧ್ರುವ wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _waccess(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _AccessMode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wchmod(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _Mode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcreat(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext32(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wunlink(ಧ್ರುವ wchar_t *_Filename);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wrename(ಧ್ರುವ wchar_t *_NewFilename,ಧ್ರುವ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata64_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext32i64(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata32i64_t *_FindData);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext64i32(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata64i32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext64(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(ಪೂರ್ಣಾಙ್ಕ *_FileHandle,ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionFlag);
#ಯದಿ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,...);
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionMode = 0);
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ಪೂರ್ಣಾಙ್ಕ _Category,ಧ್ರುವ wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsystem(ಧ್ರುವ wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#ಯದಿ !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned ವರ್ಣ)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#ಯದಿ !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ _dev_t;
#ifndef	NO_OLDNAMES
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ಪ್ರಕಾರನಿರ್ದೇಶ long _off_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ long long _off64_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#ಅನ್ಯಥಾ
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#ಅನ್ಯಥಾ
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  ಸಂರಚನಾ _stat32 {
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
  ಸಂರಚನಾ stat {
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

#ಯದಿ _INTEGRAL_MAX_BITS >= 64

  ಸಂರಚನಾ _stat32i64 {
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

  ಸಂರಚನಾ _stat64i32 {
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

  ಸಂರಚನಾ _stat64 {
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

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wstat32(ಧ್ರುವ wchar_t *_Name,ಸಂರಚನಾ _stat32 *_Stat);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wstat32i64(ಧ್ರುವ wchar_t *_Name,ಸಂರಚನಾ _stat32i64 *_Stat);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _wstat64i32(ಧ್ರುವ wchar_t *_Name,ಸಂರಚನಾ _stat64i32 *_Stat);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wstat64(ಧ್ರುವ wchar_t *_Name,ಸಂರಚನಾ _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _getwche(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cputws(ಧ್ರುವ wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwscanf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwscanf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_p(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_p(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(ಶೂನ್ಯ);
  wint_t __cdecl _getwche_nolock(ಶೂನ್ಯ);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode);
#ಅನ್ಯಥಾ
  _CRTIMP FILE *__cdecl _wfsopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode,ಪೂರ್ಣಾಙ್ಕ _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ಶೂನ್ಯ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ಶೂನ್ಯ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು,FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fputws(ಧ್ರುವ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _putws(ಧ್ರುವ wchar_t *_Str);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fwprintf(FILE *_File,ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wprintf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf(ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vfwprintf(FILE *_File,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vwprintf(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl swprintf(wchar_t*, ಧ್ರುವ wchar_t*, ...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl vswprintf(wchar_t*, ಧ್ರುವ wchar_t*,va_list);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwprintf(wchar_t *_Dest,size_t ಎಣಿಕೆ_5,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnwprintf(wchar_t *_Dest,size_t ಎಣಿಕೆ_5,ಧ್ರುವ wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ಪೂರ್ಣಾಙ್ಕ __cdecl snwprintf (wchar_t *s, size_t n, ಧ್ರುವ wchar_t * format, ...);
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl vsnwprintf (wchar_t *s, size_t n, ಧ್ರುವ wchar_t *format, va_list arg) { ಪ್ರತ್ಯಾಗಮ _vsnwprintf(s,n,format,arg); }
  ಪೂರ್ಣಾಙ್ಕ __cdecl vwscanf (ಧ್ರುವ wchar_t *, va_list);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vfwscanf (FILE *,ಧ್ರುವ wchar_t *,va_list);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vswscanf (ಧ್ರುವ wchar_t *,ಧ್ರುವ wchar_t *,va_list);
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwprintf_p(FILE *_File,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wprintf_p(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfwprintf_p(FILE *_File,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vwprintf_p(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf_p(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf_p(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwprintf_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwprintf_p_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfwprintf_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vfwprintf_p_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,va_list _Args);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __swprintf_l(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __vswprintf_l(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#ಅನ್ತರ್ಭಾವ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ಧ್ರುವ wchar_t *_Directory,ಧ್ರುವ wchar_t *_FilePrefix);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fwscanf(FILE *_File,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fwscanf_l(FILE *_File,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl swscanf(ಧ್ರುವ wchar_t *_Src,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swscanf_l(ಧ್ರುವ wchar_t *_Src,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwscanf(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwscanf_l(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wscanf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wscanf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(ಪೂರ್ಣಾಙ್ಕ _FileHandle ,ಧ್ರುವ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಧ್ರುವ wchar_t *Err_ಸಂದೇಶ);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ಧ್ರುವ wchar_t *_Command,ಧ್ರುವ wchar_t *_Mode);
#ಯದಿ !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wremove(ಧ್ರುವ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#ಯದಿ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#ಅನ್ಯಥಾ
  __CRT_INLINE wint_t __cdecl getwchar() {ಪ್ರತ್ಯಾಗಮ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {ಪ್ರತ್ಯಾಗಮ (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಙ್ಕ _Radix);
  ದ್ವಿಗುಣ __cdecl wcstod(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wcstod_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  ಭಿನ್ನ __cdecl wcstof( ಧ್ರುವ wchar_t *nptr, wchar_t **endptr);
#ಯದಿ !defined __NO_ISOCEXT /* in libmingwex.a */
  ಭಿನ್ನ __cdecl wcstof (ಧ್ರುವ wchar_t * __restrict__, wchar_t ** __restrict__);
  long ದ್ವಿಗುಣ __cdecl wcstold (ಧ್ರುವ wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP long __cdecl _wcstol_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ಧ್ರುವ wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsystem(ಧ್ರುವ wchar_t *_Command);
#endif
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wtoi(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wtoi_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);

#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ಧ್ರುವ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ಧ್ರುವ wchar_t *_Str,wchar_t **_EndPtr,ಪೂರ್ಣಾಙ್ಕ _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ಧ್ರುವ wchar_t *_Path,size_t Size_In_ಪದಗಳು);
  _CRTIMP ಶೂನ್ಯ __cdecl _wmakepath(wchar_t *_ResultPath,ಧ್ರುವ wchar_t *_Drive,ಧ್ರುವ wchar_t *_Dir,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಧ್ರುವ wchar_t *Err_ಸಂದೇಶ);
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wputenv(ಧ್ರುವ wchar_t *_EnvString);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsearchenv(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsplitpath(ಧ್ರುವ wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ಧ್ರುವ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ಧ್ರುವ wchar_t *_Str,wchar_t _Ch);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcscmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source);
  size_t __cdecl wcscspn(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_Control);
  size_t __cdecl wcslen(ಧ್ರುವ wchar_t *_Str);
  size_t __cdecl wcsnlen(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source,size_t ಎಣಿಕೆ_5);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsncmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source,size_t ಎಣಿಕೆ_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ಧ್ರುವ wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ಧ್ರುವ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(ಪೂರ್ಣಾಙ್ಕ Err_ಅಂಕೆ);
  _CRTIMP wchar_t *__cdecl __wcserror(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicmp_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicmp_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ಎಣಿಕೆ);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcscoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcscoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsncoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsncoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ಧ್ರುವ wchar_t *_Str);
#define wcswcs wcsstr
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsnicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsicoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  ಸಂರಚನಾ tm {
    ಪೂರ್ಣಾಙ್ಕ tm_sec;
    ಪೂರ್ಣಾಙ್ಕ tm_min;
    ಪೂರ್ಣಾಙ್ಕ tm_hour;
    ಪೂರ್ಣಾಙ್ಕ tm_mday;
    ಪೂರ್ಣಾಙ್ಕ tm_mon;
    ಪೂರ್ಣಾಙ್ಕ tm_year;
    ಪೂರ್ಣಾಙ್ಕ tm_wday;
    ಪೂರ್ಣಾಙ್ಕ tm_yday;
    ಪೂರ್ಣಾಙ್ಕ tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ಧ್ರುವ ಸಂರಚನಾ tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ಧ್ರುವ __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,ಧ್ರುವ ಸಂರಚನಾ tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,ಧ್ರುವ ಸಂರಚನಾ tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ಧ್ರುವ __time64_t *_Time);
#endif

#ಯದಿ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _wctime32(_Time); }
#ಅನ್ಯಥಾ
__CRT_INLINE wchar_t *__cdecl _wctime(ಧ್ರುವ time_t *_Time) { ಪ್ರತ್ಯಾಗಮ _wctime64(_Time); }
#endif
#endif
#endif

  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ mbstate_t;
  ಪ್ರಕಾರನಿರ್ದೇಶ wchar_t _Wint_t;

  wint_t __cdecl btowc(ಪೂರ್ಣಾಙ್ಕ);
  size_t __cdecl mbrlen(ಧ್ರುವ ವರ್ಣ *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,ಧ್ರುವ ವರ್ಣ *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,ಧ್ರುವ ವರ್ಣ **_PSrc,size_t ಎಣಿಕೆ_5,mbstate_t *_State);
  size_t __cdecl wcrtomb(ವರ್ಣ *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(ವರ್ಣ *_Dest,ಧ್ರುವ wchar_t **_PSource,size_t ಎಣಿಕೆ_5,mbstate_t *_State);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ಧ್ರುವ wchar_t *s, wchar_t c, size_t n);
  ಪೂರ್ಣಾಙ್ಕ wmemcmp(ಧ್ರುವ wchar_t *s1, ಧ್ರುವ wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ಧ್ರುವ wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ಧ್ರುವ wchar_t *s2, size_t n);
  long long __cdecl wcstoll(ಧ್ರುವ wchar_t *nptr,wchar_t **endptr, ಪೂರ್ಣಾಙ್ಕ base);
  unsigned long long __cdecl wcstoull(ಧ್ರುವ wchar_t *nptr,wchar_t **endptr, ಪೂರ್ಣಾಙ್ಕ base);
#endif /* __NO_ISOCEXT */

  ಶೂನ್ಯ *__cdecl memmove(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,size_t Max_ಎಣಿಕೆ);
  ಶೂನ್ಯ *__cdecl memcpy(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,size_t Max_ಎಣಿಕೆ);
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl fwide(FILE *_F,ಪೂರ್ಣಾಙ್ಕ _M) { (ಶೂನ್ಯ)_F; ಪ್ರತ್ಯಾಗಮ (_M); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl mbsinit(ಧ್ರುವ mbstate_t *_P) { ಪ್ರತ್ಯಾಗಮ (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ಧ್ರುವ wchar_t *_S,wchar_t _C,size_t _N) { ಪ್ರತಿ (;0<_N;++_S,--_N) ಯದಿ (*_S==_C) ಪ್ರತ್ಯಾಗಮ (_CONST_RETURN wchar_t *)(_S); ಪ್ರತ್ಯಾಗಮ (0); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl wmemcmp(ಧ್ರುವ wchar_t *_S1,ಧ್ರುವ wchar_t *_S2,size_t _N) { ಪ್ರತಿ (; 0 < _N; ++_S1,++_S2,--_N) ಯದಿ (*_S1!=*_S2) ಪ್ರತ್ಯಾಗಮ (*_S1 < *_S2 ? -1 : +1); ಪ್ರತ್ಯಾಗಮ (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ಧ್ರುವ wchar_t *_S2,size_t _N) { ಪ್ರತ್ಯಾಗಮ (wchar_t *)memcpy(_S1,_S2,_N*ಪರಿಮಾಣ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ಧ್ರುವ wchar_t *_S2,size_t _N) { ಪ್ರತ್ಯಾಗಮ (wchar_t *)memmove(_S1,_S2,_N*ಪರಿಮಾಣ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    ಪ್ರತಿ (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    ಪ್ರತ್ಯಾಗಮ (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/wchar_s.h>
#endif
