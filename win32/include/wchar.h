/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#include <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  typedef __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  typedef __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  struct _iobuf {
    char *_ptr;
    số_nguyên _cnt;
    char *_base;
    số_nguyên _flag;
    số_nguyên _file;
    số_nguyên _charbuf;
    số_nguyên _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(void);
#không_thì
#ifdef _MSVCRT_
extern FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#không_thì
extern FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  typedef unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  struct _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  struct _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  struct _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  struct _wfinddata64_t {
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
#không_thì
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#không_thì
#define NULL ((void *)0)
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
#không_thì
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  extern unsigned short *_pctype;
#không_thì
  extern unsigned short **_imp___pctype;
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
  extern unsigned short *_wctype;
#không_thì
  extern unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#không_thì
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  extern unsigned short *_pwctype;
#không_thì
  extern unsigned short **_imp___pwctype;
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

  số_nguyên __cdecl iswalpha(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswupper(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswlower(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswdigit(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswxdigit(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswspace(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswpunct(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswalnum(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswprint(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswgraph(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswcntrl(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswascii(wint_t _C);
  số_nguyên __cdecl isleadbyte(số_nguyên _C);
  _CRTIMP số_nguyên __cdecl _isleadbyte_l(số_nguyên _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP số_nguyên __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl __iswcsymf(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl __iswcsym(wint_t _C);
  _CRTIMP số_nguyên __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  số_nguyên __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,số_nguyên _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(số_nguyên _Drive,wchar_t *_DstBuf,số_nguyên _SizeInWords);
  wchar_t *__cdecl _wgetdcwd_nolock(số_nguyên _Drive,wchar_t *_DstBuf,số_nguyên _SizeInWords);
  _CRTIMP số_nguyên __cdecl _wchdir(const wchar_t *_Path);
  _CRTIMP số_nguyên __cdecl _wmkdir(const wchar_t *_Path);
  _CRTIMP số_nguyên __cdecl _wrmdir(const wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP số_nguyên __cdecl _waccess(const wchar_t *_Filename,số_nguyên _AccessMode);
  _CRTIMP số_nguyên __cdecl _wchmod(const wchar_t *_Filename,số_nguyên _Mode);
  _CRTIMP số_nguyên __cdecl _wcreat(const wchar_t *_Filename,số_nguyên _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,struct _wfinddata32_t *_FindData);
  _CRTIMP số_nguyên __cdecl _wfindnext32(intptr_t _FindHandle,struct _wfinddata32_t *_FindData);
  _CRTIMP số_nguyên __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP số_nguyên __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#nếu _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,struct _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,struct _wfinddata64_t *_FindData);
  _CRTIMP số_nguyên __cdecl _wfindnext32i64(intptr_t _FindHandle,struct _wfinddata32i64_t *_FindData);
  số_nguyên __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData);
  _CRTIMP số_nguyên __cdecl _wfindnext64(intptr_t _FindHandle,struct _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(số_nguyên *_FileHandle,const wchar_t *_Filename,số_nguyên _OpenFlag,số_nguyên _ShareFlag,số_nguyên _PermissionFlag);
#nếu !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP số_nguyên __cdecl _wopen(const wchar_t *_Filename,số_nguyên _OpenFlag,...);
  _CRTIMP số_nguyên __cdecl _wsopen(const wchar_t *_Filename,số_nguyên _OpenFlag,số_nguyên _ShareFlag,...);
#không_thì
  extern "C++" _CRTIMP số_nguyên __cdecl _wopen(const wchar_t *_Filename,số_nguyên _OpenFlag,số_nguyên _PermissionMode = 0);
  extern "C++" _CRTIMP số_nguyên __cdecl _wsopen(const wchar_t *_Filename,số_nguyên _OpenFlag,số_nguyên _ShareFlag,số_nguyên _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(số_nguyên _Category,const wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(số_nguyên _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP số_nguyên __cdecl _wsystem(const wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#nếu !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned char)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#nếu !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  typedef unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  typedef unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  typedef unsigned số_nguyên _dev_t;
#ifndef	NO_OLDNAMES
  typedef unsigned số_nguyên dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#nếu !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  typedef long long _off64_t;
#nếu !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#không_thì
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#không_thì
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  struct _stat32 {
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
  struct stat {
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

#nếu _INTEGRAL_MAX_BITS >= 64

  struct _stat32i64 {
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

  struct _stat64i32 {
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

  struct _stat64 {
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

  _CRTIMP số_nguyên __cdecl _wstat32(const wchar_t *_Name,struct _stat32 *_Stat);
#nếu _INTEGRAL_MAX_BITS >= 64
  _CRTIMP số_nguyên __cdecl _wstat32i64(const wchar_t *_Name,struct _stat32i64 *_Stat);
  số_nguyên __cdecl _wstat64i32(const wchar_t *_Name,struct _stat64i32 *_Stat);
  _CRTIMP số_nguyên __cdecl _wstat64(const wchar_t *_Name,struct _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(void);
  _CRTIMP wint_t __cdecl _getwche(void);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP số_nguyên __cdecl _cputws(const wchar_t *_String);
  _CRTIMP số_nguyên __cdecl _cwprintf(const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _cwscanf(const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _cwscanf_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vcwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _cwprintf_p(const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _vcwprintf_p(const wchar_t *_Format,va_list _ArgList);

  _CRTIMP số_nguyên __cdecl _cwprintf_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vcwprintf_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _cwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vcwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(void);
  wint_t __cdecl _getwche_nolock(void);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode);
#không_thì
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,số_nguyên _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(void);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(void);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,số_nguyên _SizeInWords,FILE *_File);
  số_nguyên __cdecl fputws(const wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP số_nguyên __cdecl _putws(const wchar_t *_Str);
  số_nguyên __cdecl fwprintf(FILE *_File,const wchar_t *_Format,...);
  số_nguyên __cdecl wprintf(const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _scwprintf(const wchar_t *_Format,...);
  số_nguyên __cdecl vfwprintf(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  số_nguyên __cdecl vwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl swprintf(wchar_t*, const wchar_t*, ...);
  _CRTIMP số_nguyên __cdecl vswprintf(wchar_t*, const wchar_t*,va_list);
  _CRTIMP số_nguyên __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  số_nguyên __cdecl snwprintf (wchar_t *s, size_t n, const wchar_t * format, ...);
  __CRT_INLINE số_nguyên __cdecl vsnwprintf (wchar_t *s, size_t n, const wchar_t *format, va_list arg) { trả_về _vsnwprintf(s,n,format,arg); }
  số_nguyên __cdecl vwscanf (const wchar_t *, va_list);
  số_nguyên __cdecl vfwscanf (FILE *,const wchar_t *,va_list);
  số_nguyên __cdecl vswscanf (const wchar_t *,const wchar_t *,va_list);
#endif
  _CRTIMP số_nguyên __cdecl _fwprintf_p(FILE *_File,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _wprintf_p(const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _vfwprintf_p(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _vwprintf_p(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _scwprintf_p(const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _vscwprintf_p(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _wprintf_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _wprintf_p_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vwprintf_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _vwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _fwprintf_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _fwprintf_p_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vfwprintf_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _vfwprintf_p_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _scwprintf_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _scwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vscwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _swprintf(wchar_t *_Dest,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _vswprintf(wchar_t *_Dest,const wchar_t *_Format,va_list _Args);
  _CRTIMP số_nguyên __cdecl __swprintf_l(wchar_t *_Dest,const wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP số_nguyên __cdecl __vswprintf_l(wchar_t *_Dest,const wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#include <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(const wchar_t *_Directory,const wchar_t *_FilePrefix);
  _CRTIMP số_nguyên __cdecl _vscwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP số_nguyên __cdecl _vscwprintf_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  số_nguyên __cdecl fwscanf(FILE *_File,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _fwscanf_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  số_nguyên __cdecl swscanf(const wchar_t *_Src,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _swscanf_l(const wchar_t *_Src,const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP số_nguyên __cdecl _snwscanf(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _snwscanf_l(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  số_nguyên __cdecl wscanf(const wchar_t *_Format,...);
  _CRTIMP số_nguyên __cdecl _wscanf_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(số_nguyên _FileHandle ,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(const wchar_t *_Filename,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(const wchar_t *_Filename,const wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP FILE *__cdecl _wpopen(const wchar_t *_Command,const wchar_t *_Mode);
#nếu !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP số_nguyên __cdecl _wremove(const wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#nếu !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#không_thì
  __CRT_INLINE wint_t __cdecl getwchar() {trả_về (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {trả_về (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(số_nguyên _Value,wchar_t *_Dest,số_nguyên _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long _Value,wchar_t *_Dest,số_nguyên _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long _Value,wchar_t *_Dest,số_nguyên _Radix);
  double __cdecl wcstod(const wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP double __cdecl _wcstod_l(const wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  float __cdecl wcstof( const wchar_t *nptr, wchar_t **endptr);
#nếu !defined __NO_ISOCEXT /* in libmingwex.a */
  float __cdecl wcstof (const wchar_t * __restrict__, wchar_t ** __restrict__);
  long double __cdecl wcstold (const wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix);
  _CRTIMP long __cdecl _wcstol_l(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(const wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP số_nguyên __cdecl _wsystem(const wchar_t *_Command);
#endif
  _CRTIMP double __cdecl _wtof(const wchar_t *_Str);
  _CRTIMP double __cdecl _wtof_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wtoi(const wchar_t *_Str);
  _CRTIMP số_nguyên __cdecl _wtoi_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(const wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(const wchar_t *_Str,_locale_t _Locale);

#nếu _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,số_nguyên _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,số_nguyên _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(const wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str,wchar_t **_EndPtr,số_nguyên _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,const wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP void __cdecl _wmakepath(wchar_t *_ResultPath,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP số_nguyên __cdecl _wputenv(const wchar_t *_EnvString);
  _CRTIMP void __cdecl _wsearchenv(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP void __cdecl _wsplitpath(const wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,const wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  số_nguyên __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,const wchar_t *_Source);
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,const wchar_t *_Source,size_t _Count);
  số_nguyên __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,const wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,const wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(số_nguyên _ErrNum);
  _CRTIMP wchar_t *__cdecl __wcserror(const wchar_t *_Str);
  _CRTIMP số_nguyên __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP số_nguyên __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,const wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,const wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  số_nguyên __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP số_nguyên __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP số_nguyên __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(const wchar_t *_Str);
#define wcswcs wcsstr
  số_nguyên __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  số_nguyên __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  số_nguyên __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  struct tm {
    số_nguyên tm_sec;
    số_nguyên tm_min;
    số_nguyên tm_hour;
    số_nguyên tm_mday;
    số_nguyên tm_mon;
    số_nguyên tm_year;
    số_nguyên tm_wday;
    số_nguyên tm_yday;
    số_nguyên tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(const struct tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(const __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t _SizeInWords,const wchar_t *_Format,const struct tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t _SizeInWords,const wchar_t *_Format,const struct tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#nếu _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(const __time64_t *_Time);
#endif

#nếu !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { trả_về _wctime32(_Time); }
#không_thì
__CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { trả_về _wctime64(_Time); }
#endif
#endif
#endif

  typedef số_nguyên mbstate_t;
  typedef wchar_t _Wint_t;

  wint_t __cdecl btowc(số_nguyên);
  size_t __cdecl mbrlen(const char *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,const char *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,const char **_PSrc,size_t _Count,mbstate_t *_State);
  size_t __cdecl wcrtomb(char *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(char *_Dest,const wchar_t **_PSource,size_t _Count,mbstate_t *_State);
  số_nguyên __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *s, wchar_t c, size_t n);
  số_nguyên wmemcmp(const wchar_t *s1, const wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,const wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, const wchar_t *s2, size_t n);
  long long __cdecl wcstoll(const wchar_t *nptr,wchar_t **endptr, số_nguyên base);
  unsigned long long __cdecl wcstoull(const wchar_t *nptr,wchar_t **endptr, số_nguyên base);
#endif /* __NO_ISOCEXT */

  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _MaxCount);
  void *__cdecl memcpy(void *_Dst,const void *_Src,size_t _MaxCount);
  __CRT_INLINE số_nguyên __cdecl fwide(FILE *_F,số_nguyên _M) { (void)_F; trả_về (_M); }
  __CRT_INLINE số_nguyên __cdecl mbsinit(const mbstate_t *_P) { trả_về (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *_S,wchar_t _C,size_t _N) { cho (;0<_N;++_S,--_N) nếu (*_S==_C) trả_về (_CONST_RETURN wchar_t *)(_S); trả_về (0); }
  __CRT_INLINE số_nguyên __cdecl wmemcmp(const wchar_t *_S1,const wchar_t *_S2,size_t _N) { cho (; 0 < _N; ++_S1,++_S2,--_N) nếu (*_S1!=*_S2) trả_về (*_S1 < *_S2 ? -1 : +1); trả_về (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,const wchar_t *_S2,size_t _N) { trả_về (wchar_t *)memcpy(_S1,_S2,_N*sizeof(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,const wchar_t *_S2,size_t _N) { trả_về (wchar_t *)memmove(_S1,_S2,_N*sizeof(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    cho (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    trả_về (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/wchar_s.h>
#endif
