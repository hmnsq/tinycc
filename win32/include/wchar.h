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
বাহ্য "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  প্রকারনির্দেশ __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  প্রকারনির্দেশ __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  সংরচনা _iobuf {
    বর্ণ *_ptr;
    পূর্ণাঙ্ক _cnt;
    বর্ণ *_base;
    পূর্ণাঙ্ক _flag;
    পূর্ণাঙ্ক _file;
    পূর্ণাঙ্ক _charbuf;
    পূর্ণাঙ্ক _bufsiz;
    বর্ণ *_tmpfname;
  };
  প্রকারনির্দেশ সংরচনা _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(শূন্য);
#অন্যথা
#ifdef _MSVCRT_
বাহ্য FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#অন্যথা
বাহ্য FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  প্রকারনির্দেশ unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  সংরচনা _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  সংরচনা _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  সংরচনা _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  সংরচনা _wfinddata64_t {
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

#ifndef রিক্ত
#ifdef __cplusplus
#define রিক্ত 0
#অন্যথা
#define রিক্ত ((শূন্য *)0)
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
  বাহ্য unsigned short *_pctype;
#অন্যথা
  বাহ্য unsigned short **_imp___pctype;
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
  বাহ্য unsigned short *_wctype;
#অন্যথা
  বাহ্য unsigned short **_imp___wctype;
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
  বাহ্য unsigned short *_pwctype;
#অন্যথা
  বাহ্য unsigned short **_imp___pwctype;
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

  পূর্ণাঙ্ক __cdecl iswalpha(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswupper(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswlower(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswdigit(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswxdigit(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswspace(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswpunct(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswalnum(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswprint(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswgraph(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswcntrl(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswascii(wint_t _C);
  পূর্ণাঙ্ক __cdecl isleadbyte(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isleadbyte_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl __iswcsymf(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl __iswcsym(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,পূর্ণাঙ্ক Size_In_শব্দগুলি);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(পূর্ণাঙ্ক _Drive,wchar_t *_DstBuf,পূর্ণাঙ্ক Size_In_শব্দগুলি);
  wchar_t *__cdecl _wgetdcwd_nolock(পূর্ণাঙ্ক _Drive,wchar_t *_DstBuf,পূর্ণাঙ্ক Size_In_শব্দগুলি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wchdir(ধ্রুব wchar_t *_Path);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wmkdir(ধ্রুব wchar_t *_Path);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wrmdir(ধ্রুব wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP পূর্ণাঙ্ক __cdecl _waccess(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _AccessMode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wchmod(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _Mode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcreat(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wfindnext32(intptr_t _FindHandle,সংরচনা _wfinddata32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wunlink(ধ্রুব wchar_t *_Filename);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wrename(ধ্রুব wchar_t *_NewFilename,ধ্রুব wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata64_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wfindnext32i64(intptr_t _FindHandle,সংরচনা _wfinddata32i64_t *_FindData);
  পূর্ণাঙ্ক __cdecl _wfindnext64i32(intptr_t _FindHandle,সংরচনা _wfinddata64i32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wfindnext64(intptr_t _FindHandle,সংরচনা _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(পূর্ণাঙ্ক *_FileHandle,ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,পূর্ণাঙ্ক _PermissionFlag);
#যদি !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP পূর্ণাঙ্ক __cdecl _wopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wsopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,...);
#অন্যথা
  বাহ্য "C++" _CRTIMP পূর্ণাঙ্ক __cdecl _wopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _PermissionMode = 0);
  বাহ্য "C++" _CRTIMP পূর্ণাঙ্ক __cdecl _wsopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,পূর্ণাঙ্ক _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(পূর্ণাঙ্ক _Category,ধ্রুব wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP পূর্ণাঙ্ক __cdecl _wsystem(ধ্রুব wchar_t *_Command);
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned বর্ণ)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#যদি !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  প্রকারনির্দেশ unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  প্রকারনির্দেশ unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক _dev_t;
#ifndef	NO_OLDNAMES
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  প্রকারনির্দেশ long _off_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারনির্দেশ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  প্রকারনির্দেশ long long _off64_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারনির্দেশ long long off64_t;
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

  সংরচনা _stat32 {
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
  সংরচনা stat {
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

#যদি _INTEGRAL_MAX_BITS >= 64

  সংরচনা _stat32i64 {
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

  সংরচনা _stat64i32 {
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

  সংরচনা _stat64 {
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

  _CRTIMP পূর্ণাঙ্ক __cdecl _wstat32(ধ্রুব wchar_t *_Name,সংরচনা _stat32 *_Stat);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP পূর্ণাঙ্ক __cdecl _wstat32i64(ধ্রুব wchar_t *_Name,সংরচনা _stat32i64 *_Stat);
  পূর্ণাঙ্ক __cdecl _wstat64i32(ধ্রুব wchar_t *_Name,সংরচনা _stat64i32 *_Stat);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wstat64(ধ্রুব wchar_t *_Name,সংরচনা _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(শূন্য);
  _CRTIMP wint_t __cdecl _getwche(শূন্য);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cputws(ধ্রুব wchar_t *_String);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_p(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_p(ধ্রুব wchar_t *_Format,va_list _ArgList);

  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
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
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode,পূর্ণাঙ্ক _ShFlag);
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
  wchar_t *__cdecl fgetws(wchar_t *_Dst,পূর্ণাঙ্ক Size_In_শব্দগুলি,FILE *_File);
  পূর্ণাঙ্ক __cdecl fputws(ধ্রুব wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP পূর্ণাঙ্ক __cdecl _putws(ধ্রুব wchar_t *_Str);
  পূর্ণাঙ্ক __cdecl fwprintf(FILE *_File,ধ্রুব wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl wprintf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf(ধ্রুব wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl vfwprintf(FILE *_File,ধ্রুব wchar_t *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl vwprintf(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl swprintf(wchar_t*, ধ্রুব wchar_t*, ...);
  _CRTIMP পূর্ণাঙ্ক __cdecl vswprintf(wchar_t*, ধ্রুব wchar_t*,va_list);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwprintf(wchar_t *_Dest,size_t গুনতি_5,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnwprintf(wchar_t *_Dest,size_t গুনতি_5,ধ্রুব wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  পূর্ণাঙ্ক __cdecl snwprintf (wchar_t *s, size_t n, ধ্রুব wchar_t * format, ...);
  __CRT_INLINE পূর্ণাঙ্ক __cdecl vsnwprintf (wchar_t *s, size_t n, ধ্রুব wchar_t *format, va_list arg) { প্রত্যাগম _vsnwprintf(s,n,format,arg); }
  পূর্ণাঙ্ক __cdecl vwscanf (ধ্রুব wchar_t *, va_list);
  পূর্ণাঙ্ক __cdecl vfwscanf (FILE *,ধ্রুব wchar_t *,va_list);
  পূর্ণাঙ্ক __cdecl vswscanf (ধ্রুব wchar_t *,ধ্রুব wchar_t *,va_list);
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwprintf_p(FILE *_File,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wprintf_p(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfwprintf_p(FILE *_File,ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vwprintf_p(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf_p(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf_p(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vwprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vwprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwprintf_l(FILE *_File,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwprintf_p_l(FILE *_File,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfwprintf_l(FILE *_File,ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vfwprintf_p_l(FILE *_File,ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf(wchar_t *_Dest,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf(wchar_t *_Dest,ধ্রুব wchar_t *_Format,va_list _Args);
  _CRTIMP পূর্ণাঙ্ক __cdecl __swprintf_l(wchar_t *_Dest,ধ্রুব wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl __vswprintf_l(wchar_t *_Dest,ধ্রুব wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
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

  _CRTIMP wchar_t *__cdecl _wtempnam(ধ্রুব wchar_t *_Directory,ধ্রুব wchar_t *_FilePrefix);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl fwscanf(FILE *_File,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fwscanf_l(FILE *_File,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  পূর্ণাঙ্ক __cdecl swscanf(ধ্রুব wchar_t *_Src,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swscanf_l(ধ্রুব wchar_t *_Src,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwscanf(ধ্রুব wchar_t *_Src,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwscanf_l(ধ্রুব wchar_t *_Src,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  পূর্ণাঙ্ক __cdecl wscanf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wscanf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(পূর্ণাঙ্ক _FileHandle ,ধ্রুব wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুব wchar_t *Err_বার্তা);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ধ্রুব wchar_t *_Command,ধ্রুব wchar_t *_Mode);
#যদি !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _wremove(ধ্রুব wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#যদি !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#অন্যথা
  __CRT_INLINE wint_t __cdecl getwchar() {প্রত্যাগম (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {প্রত্যাগম (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(পূর্ণাঙ্ক মান_2,wchar_t *_Dest,পূর্ণাঙ্ক _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long মান_2,wchar_t *_Dest,পূর্ণাঙ্ক _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long মান_2,wchar_t *_Dest,পূর্ণাঙ্ক _Radix);
  দ্বিগুণ __cdecl wcstod(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP দ্বিগুণ __cdecl _wcstod_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  ভিন্ন __cdecl wcstof( ধ্রুব wchar_t *nptr, wchar_t **endptr);
#যদি !defined __NO_ISOCEXT /* in libmingwex.a */
  ভিন্ন __cdecl wcstof (ধ্রুব wchar_t * __restrict__, wchar_t ** __restrict__);
  long দ্বিগুণ __cdecl wcstold (ধ্রুব wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP long __cdecl _wcstol_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ধ্রুব wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP পূর্ণাঙ্ক __cdecl _wsystem(ধ্রুব wchar_t *_Command);
#endif
  _CRTIMP দ্বিগুণ __cdecl _wtof(ধ্রুব wchar_t *_Str);
  _CRTIMP দ্বিগুণ __cdecl _wtof_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wtoi(ধ্রুব wchar_t *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wtoi_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ধ্রুব wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);

#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,পূর্ণাঙ্ক _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,পূর্ণাঙ্ক _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ধ্রুব wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ধ্রুব wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ধ্রুব wchar_t *_Str,wchar_t **_EndPtr,পূর্ণাঙ্ক _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ধ্রুব wchar_t *_Path,size_t Size_In_শব্দগুলি);
  _CRTIMP শূন্য __cdecl _wmakepath(wchar_t *_ResultPath,ধ্রুব wchar_t *_Drive,ধ্রুব wchar_t *_Dir,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুব wchar_t *Err_বার্তা);
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _wputenv(ধ্রুব wchar_t *_EnvString);
  _CRTIMP শূন্য __cdecl _wsearchenv(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP শূন্য __cdecl _wsplitpath(ধ্রুব wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ধ্রুব wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ধ্রুব wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ধ্রুব wchar_t *_Str,wchar_t _Ch);
  পূর্ণাঙ্ক __cdecl wcscmp(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ধ্রুব wchar_t *_Source);
  size_t __cdecl wcscspn(ধ্রুব wchar_t *_Str,ধ্রুব wchar_t *_Control);
  size_t __cdecl wcslen(ধ্রুব wchar_t *_Str);
  size_t __cdecl wcsnlen(ধ্রুব wchar_t *_Src,size_t Max_গুনতি);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ধ্রুব wchar_t *_Source,size_t গুনতি_5);
  পূর্ণাঙ্ক __cdecl wcsncmp(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ধ্রুব wchar_t *_Source,size_t গুনতি_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ধ্রুব wchar_t *_Str,ধ্রুব wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ধ্রুব wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ধ্রুব wchar_t *_Str,ধ্রুব wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ধ্রুব wchar_t *_Str,ধ্রুব wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ধ্রুব wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(পূর্ণাঙ্ক Err_অঙ্ক);
  _CRTIMP wchar_t *__cdecl __wcserror(ধ্রুব wchar_t *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicmp(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicmp_l(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicmp(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicmp_l(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_গুনতি);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ধ্রুব wchar_t *_Src,size_t Max_গুনতি);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ধ্রুব wchar_t *_Src,size_t Max_গুনতি,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl wcscoll(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcscoll_l(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicoll(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicoll_l(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsncoll(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsncoll_l(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicoll(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicoll_l(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ধ্রুব wchar_t *_Str);
#define wcswcs wcsstr
  পূর্ণাঙ্ক __cdecl wcsicmp(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2);
  পূর্ণাঙ্ক __cdecl wcsnicmp(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2,size_t Max_গুনতি);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_গুনতি);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  পূর্ণাঙ্ক __cdecl wcsicoll(ধ্রুব wchar_t *_Str1,ধ্রুব wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  সংরচনা tm {
    পূর্ণাঙ্ক tm_sec;
    পূর্ণাঙ্ক tm_min;
    পূর্ণাঙ্ক tm_hour;
    পূর্ণাঙ্ক tm_mday;
    পূর্ণাঙ্ক tm_mon;
    পূর্ণাঙ্ক tm_year;
    পূর্ণাঙ্ক tm_wday;
    পূর্ণাঙ্ক tm_yday;
    পূর্ণাঙ্ক tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ধ্রুব সংরচনা tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ধ্রুব __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,ধ্রুব সংরচনা tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,ধ্রুব সংরচনা tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ধ্রুব __time64_t *_Time);
#endif

#যদি !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুব time_t *_Time) { প্রত্যাগম _wctime32(_Time); }
#অন্যথা
__CRT_INLINE wchar_t *__cdecl _wctime(ধ্রুব time_t *_Time) { প্রত্যাগম _wctime64(_Time); }
#endif
#endif
#endif

  প্রকারনির্দেশ পূর্ণাঙ্ক mbstate_t;
  প্রকারনির্দেশ wchar_t _Wint_t;

  wint_t __cdecl btowc(পূর্ণাঙ্ক);
  size_t __cdecl mbrlen(ধ্রুব বর্ণ *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,ধ্রুব বর্ণ *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,ধ্রুব বর্ণ **_PSrc,size_t গুনতি_5,mbstate_t *_State);
  size_t __cdecl wcrtomb(বর্ণ *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(বর্ণ *_Dest,ধ্রুব wchar_t **_PSource,size_t গুনতি_5,mbstate_t *_State);
  পূর্ণাঙ্ক __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ধ্রুব wchar_t *s, wchar_t c, size_t n);
  পূর্ণাঙ্ক wmemcmp(ধ্রুব wchar_t *s1, ধ্রুব wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ধ্রুব wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ধ্রুব wchar_t *s2, size_t n);
  long long __cdecl wcstoll(ধ্রুব wchar_t *nptr,wchar_t **endptr, পূর্ণাঙ্ক base);
  unsigned long long __cdecl wcstoull(ধ্রুব wchar_t *nptr,wchar_t **endptr, পূর্ণাঙ্ক base);
#endif /* __NO_ISOCEXT */

  শূন্য *__cdecl memmove(শূন্য *_Dst,ধ্রুব শূন্য *_Src,size_t Max_গুনতি);
  শূন্য *__cdecl memcpy(শূন্য *_Dst,ধ্রুব শূন্য *_Src,size_t Max_গুনতি);
  __CRT_INLINE পূর্ণাঙ্ক __cdecl fwide(FILE *_F,পূর্ণাঙ্ক _M) { (শূন্য)_F; প্রত্যাগম (_M); }
  __CRT_INLINE পূর্ণাঙ্ক __cdecl mbsinit(ধ্রুব mbstate_t *_P) { প্রত্যাগম (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ধ্রুব wchar_t *_S,wchar_t _C,size_t _N) { প্রতি (;0<_N;++_S,--_N) যদি (*_S==_C) প্রত্যাগম (_CONST_RETURN wchar_t *)(_S); প্রত্যাগম (0); }
  __CRT_INLINE পূর্ণাঙ্ক __cdecl wmemcmp(ধ্রুব wchar_t *_S1,ধ্রুব wchar_t *_S2,size_t _N) { প্রতি (; 0 < _N; ++_S1,++_S2,--_N) যদি (*_S1!=*_S2) প্রত্যাগম (*_S1 < *_S2 ? -1 : +1); প্রত্যাগম (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ধ্রুব wchar_t *_S2,size_t _N) { প্রত্যাগম (wchar_t *)memcpy(_S1,_S2,_N*পরিমাণ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ধ্রুব wchar_t *_S2,size_t _N) { প্রত্যাগম (wchar_t *)memmove(_S1,_S2,_N*পরিমাণ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    প্রতি (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    প্রত্যাগম (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/wchar_s.h>
#endif
