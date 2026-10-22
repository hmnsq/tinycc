/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#অন্তর্ভাব <_mingw.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  প্রকারলেখ __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  প্রকারলেখ __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  কাঠামো _iobuf {
    অক্ষর *_ptr;
    পূর্ণসংখ্যা _cnt;
    অক্ষর *_base;
    পূর্ণসংখ্যা _flag;
    পূর্ণসংখ্যা _file;
    পূর্ণসংখ্যা _charbuf;
    পূর্ণসংখ্যা _bufsiz;
    অক্ষর *_tmpfname;
  };
  প্রকারলেখ কাঠামো _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(শূন্য);
#অন্যথা
#ifdef _MSVCRT_
বাহ্যিক FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#অন্যথা
বাহ্যিক FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  প্রকারলেখ unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  কাঠামো _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t আকার_2;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  কাঠামো _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 আকার_2;
    wchar_t name[260];
  };

  কাঠামো _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t আকার_2;
    wchar_t name[260];
  };

  কাঠামো _wfinddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 আকার_2;
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
#অন্যথা
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef ফাঁকা
#ifdef __cplusplus
#define ফাঁকা 0
#অন্যথা
#define ফাঁকা ((শূন্য *)0)
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
#অন্যথা
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  বাহ্যিক unsigned short *_pctype;
#অন্যথা
  বাহ্যিক unsigned short **_imp___pctype;
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
  বাহ্যিক unsigned short *_wctype;
#অন্যথা
  বাহ্যিক unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#অন্যথা
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  বাহ্যিক unsigned short *_pwctype;
#অন্যথা
  বাহ্যিক unsigned short **_imp___pwctype;
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

  পূর্ণসংখ্যা __cdecl iswalpha(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswupper(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswlower(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswdigit(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswxdigit(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswspace(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswpunct(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswalnum(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswprint(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswgraph(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswcntrl(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswascii(wint_t _C);
  পূর্ণসংখ্যা __cdecl isleadbyte(পূর্ণসংখ্যা _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _isleadbyte_l(পূর্ণসংখ্যা _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl __iswcsymf(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl __iswcsym(wint_t _C);
  _CRTIMP পূর্ণসংখ্যা __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,পূর্ণসংখ্যা আকার_In_শব্দগুলি);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(পূর্ণসংখ্যা _Drive,wchar_t *_DstBuf,পূর্ণসংখ্যা আকার_In_শব্দগুলি);
  wchar_t *__cdecl _wgetdcwd_nolock(পূর্ণসংখ্যা _Drive,wchar_t *_DstBuf,পূর্ণসংখ্যা আকার_In_শব্দগুলি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wchdir(ধ্রুবক wchar_t *_Path);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wmkdir(ধ্রুবক wchar_t *_Path);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wrmdir(ধ্রুবক wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP পূর্ণসংখ্যা __cdecl _waccess(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _AccessMode);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wchmod(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _Mode);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcreat(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ধ্রুবক wchar_t *_Filename,কাঠামো _wfinddata32_t *Find_তথ্য);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wfindnext32(intptr_t _FindHandle,কাঠামো _wfinddata32_t *Find_তথ্য);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wunlink(ধ্রুবক wchar_t *_Filename);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wrename(ধ্রুবক wchar_t *_NewFilename,ধ্রুবক wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ধ্রুবক wchar_t *_Filename,কাঠামো _wfinddata32i64_t *Find_তথ্য);
  intptr_t __cdecl _wfindfirst64i32(ধ্রুবক wchar_t *_Filename,কাঠামো _wfinddata64i32_t *Find_তথ্য);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ধ্রুবক wchar_t *_Filename,কাঠামো _wfinddata64_t *Find_তথ্য);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wfindnext32i64(intptr_t _FindHandle,কাঠামো _wfinddata32i64_t *Find_তথ্য);
  পূর্ণসংখ্যা __cdecl _wfindnext64i32(intptr_t _FindHandle,কাঠামো _wfinddata64i32_t *Find_তথ্য);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wfindnext64(intptr_t _FindHandle,কাঠামো _wfinddata64_t *Find_তথ্য);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(পূর্ণসংখ্যা *_FileHandle,ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _OpenFlag,পূর্ণসংখ্যা _ShareFlag,পূর্ণসংখ্যা _PermissionFlag);
#যদি !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP পূর্ণসংখ্যা __cdecl _wopen(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _OpenFlag,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wsopen(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _OpenFlag,পূর্ণসংখ্যা _ShareFlag,...);
#অন্যথা
  বাহ্যিক "C++" _CRTIMP পূর্ণসংখ্যা __cdecl _wopen(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _OpenFlag,পূর্ণসংখ্যা _PermissionMode = 0);
  বাহ্যিক "C++" _CRTIMP পূর্ণসংখ্যা __cdecl _wsopen(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _OpenFlag,পূর্ণসংখ্যা _ShareFlag,পূর্ণসংখ্যা _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(পূর্ণসংখ্যা _Category,ধ্রুবক wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList,ধ্রুবক wchar_t *ধ্রুবক *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList,ধ্রুবক wchar_t *ধ্রুবক *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList,ধ্রুবক wchar_t *ধ্রুবক *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(পূর্ণসংখ্যা _Mode,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *ধ্রুবক *_ArgList,ধ্রুবক wchar_t *ধ্রুবক *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP পূর্ণসংখ্যা __cdecl _wsystem(ধ্রুবক wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#যদি !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned অক্ষর)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#যদি !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  প্রকারলেখ unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  প্রকারলেখ unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  প্রকারলেখ unsigned পূর্ণসংখ্যা _dev_t;
#ifndef	NO_OLDNAMES
  প্রকারলেখ unsigned পূর্ণসংখ্যা dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  প্রকারলেখ long _off_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারলেখ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  প্রকারলেখ long long _off64_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারলেখ long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#অন্যথা
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#অন্যথা
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  কাঠামো _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_আকার;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#ifndef	NO_OLDNAMES
  কাঠামো stat {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_আকার;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#endif

#যদি _INTEGRAL_MAX_BITS >= 64

  কাঠামো _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    __int64 st_আকার;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  কাঠামো _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_আকার;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  কাঠামো _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    __int64 st_আকার;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#endif

#define __stat64 _stat64

#endif

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED

  _CRTIMP পূর্ণসংখ্যা __cdecl _wstat32(ধ্রুবক wchar_t *_Name,কাঠামো _stat32 *_Stat);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP পূর্ণসংখ্যা __cdecl _wstat32i64(ধ্রুবক wchar_t *_Name,কাঠামো _stat32i64 *_Stat);
  পূর্ণসংখ্যা __cdecl _wstat64i32(ধ্রুবক wchar_t *_Name,কাঠামো _stat64i32 *_Stat);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wstat64(ধ্রুবক wchar_t *_Name,কাঠামো _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *বাফার_2);
  _CRTIMP wint_t __cdecl _getwch(শূন্য);
  _CRTIMP wint_t __cdecl _getwche(শূন্য);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP পূর্ণসংখ্যা __cdecl _cputws(ধ্রুবক wchar_t *_String);
  _CRTIMP পূর্ণসংখ্যা __cdecl _cwprintf(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _cwscanf(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _cwscanf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vcwprintf(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _cwprintf_p(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vcwprintf_p(ধ্রুবক wchar_t *_Format,va_list _ArgList);

  _CRTIMP পূর্ণসংখ্যা __cdecl _cwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vcwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _cwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vcwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(শূন্য);
  wint_t __cdecl _getwche_nolock(শূন্য);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode,পূর্ণসংখ্যা _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(শূন্য);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(শূন্য);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,পূর্ণসংখ্যা আকার_In_শব্দগুলি,FILE *_File);
  পূর্ণসংখ্যা __cdecl fputws(ধ্রুবক wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP পূর্ণসংখ্যা __cdecl _putws(ধ্রুবক wchar_t *_Str);
  পূর্ণসংখ্যা __cdecl fwprintf(FILE *_File,ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl wprintf(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf(ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl vfwprintf(FILE *_File,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl vwprintf(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl swprintf(wchar_t*, ধ্রুবক wchar_t*, ...);
  _CRTIMP পূর্ণসংখ্যা __cdecl vswprintf(wchar_t*, ধ্রুবক wchar_t*,va_list);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_c(wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_c(wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwprintf(wchar_t *_Dest,আকার_t গুনতি_5,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnwprintf(wchar_t *_Dest,আকার_t গুনতি_5,ধ্রুবক wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  পূর্ণসংখ্যা __cdecl snwprintf (wchar_t *s, আকার_t n, ধ্রুবক wchar_t * format, ...);
  __CRT_INLINE পূর্ণসংখ্যা __cdecl vsnwprintf (wchar_t *s, আকার_t n, ধ্রুবক wchar_t *format, va_list arg) { ফেরত _vsnwprintf(s,n,format,arg); }
  পূর্ণসংখ্যা __cdecl vwscanf (ধ্রুবক wchar_t *, va_list);
  পূর্ণসংখ্যা __cdecl vfwscanf (FILE *,ধ্রুবক wchar_t *,va_list);
  পূর্ণসংখ্যা __cdecl vswscanf (ধ্রুবক wchar_t *,ধ্রুবক wchar_t *,va_list);
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwprintf_p(FILE *_File,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wprintf_p(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfwprintf_p(FILE *_File,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vwprintf_p(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_p(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_p(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf_p(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf_p(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwprintf_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwprintf_p_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfwprintf_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vfwprintf_p_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_c_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_p_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_c_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_p_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf_p_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwprintf_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnwprintf_l(wchar_t *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,va_list _Args);
  _CRTIMP পূর্ণসংখ্যা __cdecl __swprintf_l(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl __vswprintf_l(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#অন্তর্ভাব <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ধ্রুবক wchar_t *_Directory,ধ্রুবক wchar_t *_FilePrefix);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl fwscanf(FILE *_File,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fwscanf_l(FILE *_File,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  পূর্ণসংখ্যা __cdecl swscanf(ধ্রুবক wchar_t *_Src,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swscanf_l(ধ্রুবক wchar_t *_Src,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwscanf(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwscanf_l(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  পূর্ণসংখ্যা __cdecl wscanf(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wscanf_l(ধ্রুবক wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(পূর্ণসংখ্যা _FileHandle ,ধ্রুবক wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুবক wchar_t *Err_বার্তা);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ধ্রুবক wchar_t *_Command,ধ্রুবক wchar_t *_Mode);
#যদি !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _wremove(ধ্রুবক wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *বাফার_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#যদি !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#অন্যথা
  __CRT_INLINE wint_t __cdecl getwchar() {ফেরত (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {ফেরত (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(পূর্ণসংখ্যা মান_2,wchar_t *_Dest,পূর্ণসংখ্যা _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long মান_2,wchar_t *_Dest,পূর্ণসংখ্যা _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long মান_2,wchar_t *_Dest,পূর্ণসংখ্যা _Radix);
  দ্বিগুণ __cdecl wcstod(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP দ্বিগুণ __cdecl _wcstod_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  দশমিক __cdecl wcstof( ধ্রুবক wchar_t *nptr, wchar_t **endptr);
#যদি !defined __NO_ISOCEXT /* in libmingwex.a */
  দশমিক __cdecl wcstof (ধ্রুবক wchar_t * __restrict__, wchar_t ** __restrict__);
  long দ্বিগুণ __cdecl wcstold (ধ্রুবক wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP long __cdecl _wcstol_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ধ্রুবক wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP পূর্ণসংখ্যা __cdecl _wsystem(ধ্রুবক wchar_t *_Command);
#endif
  _CRTIMP দ্বিগুণ __cdecl _wtof(ধ্রুবক wchar_t *_Str);
  _CRTIMP দ্বিগুণ __cdecl _wtof_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wtoi(ধ্রুবক wchar_t *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wtoi_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ধ্রুবক wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);

#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,পূর্ণসংখ্যা _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,পূর্ণসংখ্যা _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ধ্রুবক wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ধ্রুবক wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ধ্রুবক wchar_t *_Str,wchar_t **_EndPtr,পূর্ণসংখ্যা _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ধ্রুবক wchar_t *_Path,আকার_t আকার_In_শব্দগুলি);
  _CRTIMP শূন্য __cdecl _wmakepath(wchar_t *ফলাফল_Path,ধ্রুবক wchar_t *_Drive,ধ্রুবক wchar_t *_Dir,ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুবক wchar_t *Err_বার্তা);
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _wputenv(ধ্রুবক wchar_t *_EnvString);
  _CRTIMP শূন্য __cdecl _wsearchenv(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_EnvVar,wchar_t *ফলাফল_Path);
  _CRTIMP শূন্য __cdecl _wsplitpath(ধ্রুবক wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ধ্রুবক wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ধ্রুবক wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ধ্রুবক wchar_t *_Str,wchar_t _Ch);
  পূর্ণসংখ্যা __cdecl wcscmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ধ্রুবক wchar_t *_Source);
  আকার_t __cdecl wcscspn(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_Control);
  আকার_t __cdecl wcslen(ধ্রুবক wchar_t *_Str);
  আকার_t __cdecl wcsnlen(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ধ্রুবক wchar_t *_Source,আকার_t গুনতি_5);
  পূর্ণসংখ্যা __cdecl wcsncmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ধ্রুবক wchar_t *_Source,আকার_t গুনতি_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ধ্রুবক wchar_t *_Str,wchar_t _Ch);
  আকার_t __cdecl wcsspn(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ধ্রুবক wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(পূর্ণসংখ্যা Err_অঙ্ক);
  _CRTIMP wchar_t *__cdecl __wcserror(ধ্রুবক wchar_t *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicmp_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicmp_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,আকার_t Max_গুনতি);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  আকার_t __cdecl wcsxfrm(wchar_t *_Dst,ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি);
  _CRTIMP আকার_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl wcscoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcscoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsncoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsncoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ধ্রুবক wchar_t *_Str);
#define wcswcs wcsstr
  পূর্ণসংখ্যা __cdecl wcsicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  পূর্ণসংখ্যা __cdecl wcsnicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,আকার_t Max_গুনতি);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  পূর্ণসংখ্যা __cdecl wcsicoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  কাঠামো tm {
    পূর্ণসংখ্যা tm_sec;
    পূর্ণসংখ্যা tm_min;
    পূর্ণসংখ্যা tm_hour;
    পূর্ণসংখ্যা tm_mday;
    পূর্ণসংখ্যা tm_mon;
    পূর্ণসংখ্যা tm_year;
    পূর্ণসংখ্যা tm_wday;
    পূর্ণসংখ্যা tm_yday;
    পূর্ণসংখ্যা tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ধ্রুবক কাঠামো tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ধ্রুবক __time32_t *_Time);
  আকার_t __cdecl wcsftime(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,ধ্রুবক কাঠামো tm *_Tm);
  _CRTIMP আকার_t __cdecl _wcsftime_l(wchar_t *_Buf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,ধ্রুবক কাঠামো tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *বাফার_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *বাফার_2);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ধ্রুবক __time64_t *_Time);
#endif

#যদি !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুবক time_t *_Time) { ফেরত _wctime32(_Time); }
#অন্যথা
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুবক time_t *_Time) { ফেরত _wctime64(_Time); }
#endif
#endif
#endif

  প্রকারলেখ পূর্ণসংখ্যা mbstate_t;
  প্রকারলেখ wchar_t _Wint_t;

  wint_t __cdecl btowc(পূর্ণসংখ্যা);
  আকার_t __cdecl mbrlen(ধ্রুবক অক্ষর *_Ch,আকার_t আকার_In_Bytes,mbstate_t *_State);
  আকার_t __cdecl mbrtowc(wchar_t *_DstCh,ধ্রুবক অক্ষর *_SrcCh,আকার_t আকার_In_Bytes,mbstate_t *_State);
  আকার_t __cdecl mbsrtowcs(wchar_t *_Dest,ধ্রুবক অক্ষর **_PSrc,আকার_t গুনতি_5,mbstate_t *_State);
  আকার_t __cdecl wcrtomb(অক্ষর *_Dest,wchar_t _Source,mbstate_t *_State);
  আকার_t __cdecl wcsrtombs(অক্ষর *_Dest,ধ্রুবক wchar_t **_PSource,আকার_t গুনতি_5,mbstate_t *_State);
  পূর্ণসংখ্যা __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, আকার_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ধ্রুবক wchar_t *s, wchar_t c, আকার_t n);
  পূর্ণসংখ্যা wmemcmp(ধ্রুবক wchar_t *s1, ধ্রুবক wchar_t *s2,আকার_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ধ্রুবক wchar_t *s2,আকার_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ধ্রুবক wchar_t *s2, আকার_t n);
  long long __cdecl wcstoll(ধ্রুবক wchar_t *nptr,wchar_t **endptr, পূর্ণসংখ্যা base);
  unsigned long long __cdecl wcstoull(ধ্রুবক wchar_t *nptr,wchar_t **endptr, পূর্ণসংখ্যা base);
#endif /* __NO_ISOCEXT */

  শূন্য *__cdecl memmove(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,আকার_t Max_গুনতি);
  শূন্য *__cdecl memcpy(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,আকার_t Max_গুনতি);
  __CRT_INLINE পূর্ণসংখ্যা __cdecl fwide(FILE *_F,পূর্ণসংখ্যা _M) { (শূন্য)_F; ফেরত (_M); }
  __CRT_INLINE পূর্ণসংখ্যা __cdecl mbsinit(ধ্রুবক mbstate_t *_P) { ফেরত (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ধ্রুবক wchar_t *_S,wchar_t _C,আকার_t _N) { জন্য (;0<_N;++_S,--_N) যদি (*_S==_C) ফেরত (_CONST_RETURN wchar_t *)(_S); ফেরত (0); }
  __CRT_INLINE পূর্ণসংখ্যা __cdecl wmemcmp(ধ্রুবক wchar_t *_S1,ধ্রুবক wchar_t *_S2,আকার_t _N) { জন্য (; 0 < _N; ++_S1,++_S2,--_N) যদি (*_S1!=*_S2) ফেরত (*_S1 < *_S2 ? -1 : +1); ফেরত (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ধ্রুবক wchar_t *_S2,আকার_t _N) { ফেরত (wchar_t *)memcpy(_S1,_S2,_N*আকার(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ধ্রুবক wchar_t *_S2,আকার_t _N) { ফেরত (wchar_t *)memmove(_S1,_S2,_N*আকার(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,আকার_t _N) {
    wchar_t *_Su = _S;
    জন্য (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    ফেরত (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/wchar_s.h>
#endif
