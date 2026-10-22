/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#شامل <_mingw.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  تعریفنوع __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  تعریفنوع __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  ساختار _iobuf {
    نویسه *_ptr;
    صحیح _cnt;
    نویسه *_base;
    صحیح _flag;
    صحیح _file;
    صحیح _charbuf;
    صحیح _bufsiz;
    نویسه *_tmpfname;
  };
  تعریفنوع ساختار _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(تهی);
#وگرنه
#ifdef _MSVCRT_
بیرونی FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#وگرنه
بیرونی FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  تعریفنوع unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  ساختار _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ساختار _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ساختار _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ساختار _wfinddata64_t {
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
#وگرنه
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef پوچ
#ifdef __cplusplus
#define پوچ 0
#وگرنه
#define پوچ ((تهی *)0)
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
#وگرنه
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  بیرونی unsigned short *_pctype;
#وگرنه
  بیرونی unsigned short **_imp___pctype;
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
  بیرونی unsigned short *_wctype;
#وگرنه
  بیرونی unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#وگرنه
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  بیرونی unsigned short *_pwctype;
#وگرنه
  بیرونی unsigned short **_imp___pwctype;
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
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحیح Size_In_واژگان);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحیح _Drive,wchar_t *_DstBuf,صحیح Size_In_واژگان);
  wchar_t *__cdecl _wgetdcwd_nolock(صحیح _Drive,wchar_t *_DstBuf,صحیح Size_In_واژگان);
  _CRTIMP صحیح __cdecl _wchdir(ثابت wchar_t *_Path);
  _CRTIMP صحیح __cdecl _wmkdir(ثابت wchar_t *_Path);
  _CRTIMP صحیح __cdecl _wrmdir(ثابت wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP صحیح __cdecl _waccess(ثابت wchar_t *_Filename,صحیح _AccessMode);
  _CRTIMP صحیح __cdecl _wchmod(ثابت wchar_t *_Filename,صحیح _Mode);
  _CRTIMP صحیح __cdecl _wcreat(ثابت wchar_t *_Filename,صحیح _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,ساختار _wfinddata32_t *_FindData);
  _CRTIMP صحیح __cdecl _wfindnext32(intptr_t _FindHandle,ساختار _wfinddata32_t *_FindData);
  _CRTIMP صحیح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحیح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,ساختار _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,ساختار _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,ساختار _wfinddata64_t *_FindData);
  _CRTIMP صحیح __cdecl _wfindnext32i64(intptr_t _FindHandle,ساختار _wfinddata32i64_t *_FindData);
  صحیح __cdecl _wfindnext64i32(intptr_t _FindHandle,ساختار _wfinddata64i32_t *_FindData);
  _CRTIMP صحیح __cdecl _wfindnext64(intptr_t _FindHandle,ساختار _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(صحیح *_FileHandle,ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح _PermissionFlag);
#اگر !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,...);
  _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
#وگرنه
  بیرونی "C++" _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _PermissionMode = 0);
  بیرونی "C++" _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(صحیح _Category,ثابت wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#اگر !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned نویسه)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#اگر !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  تعریفنوع unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  تعریفنوع unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  تعریفنوع unsigned صحیح _dev_t;
#ifndef	NO_OLDNAMES
  تعریفنوع unsigned صحیح dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  تعریفنوع long _off_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  تعریفنوع long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  تعریفنوع long long _off64_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  تعریفنوع long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#وگرنه
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#وگرنه
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  ساختار _stat32 {
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
  ساختار stat {
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

#اگر _INTEGRAL_MAX_BITS >= 64

  ساختار _stat32i64 {
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

  ساختار _stat64i32 {
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

  ساختار _stat64 {
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

  _CRTIMP صحیح __cdecl _wstat32(ثابت wchar_t *_Name,ساختار _stat32 *_Stat);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP صحیح __cdecl _wstat32i64(ثابت wchar_t *_Name,ساختار _stat32i64 *_Stat);
  صحیح __cdecl _wstat64i32(ثابت wchar_t *_Name,ساختار _stat64i32 *_Stat);
  _CRTIMP صحیح __cdecl _wstat64(ثابت wchar_t *_Name,ساختار _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(تهی);
  _CRTIMP wint_t __cdecl _getwche(تهی);
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
  wint_t __cdecl _getwch_nolock(تهی);
  wint_t __cdecl _getwche_nolock(تهی);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
#وگرنه
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,صحیح _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(تهی);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(تهی);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحیح Size_In_واژگان,FILE *_File);
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
  _CRTIMP صحیح __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_واژگان,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_واژگان,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf(wchar_t *_Dest,size_t شمار_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vsnwprintf(wchar_t *_Dest,size_t شمار_5,ثابت wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  صحیح __cdecl snwprintf (wchar_t *s, size_t n, ثابت wchar_t * format, ...);
  __CRT_INLINE صحیح __cdecl vsnwprintf (wchar_t *s, size_t n, ثابت wchar_t *format, va_list arg) { بازگشت _vsnwprintf(s,n,format,arg); }
  صحیح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحیح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحیح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#endif
  _CRTIMP صحیح __cdecl _fwprintf_p(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _wprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vfwprintf_p(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,va_list _ArgList);
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
  _CRTIMP صحیح __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _scwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _scwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vscwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list _Args);
  _CRTIMP صحیح __cdecl __swprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP صحیح __cdecl __vswprintf_l(wchar_t *_Dest,ثابت wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#شامل <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *_FilePrefix);
  _CRTIMP صحیح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _vscwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  صحیح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _fwscanf_l(FILE *_File,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحیح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _swscanf_l(ثابت wchar_t *_Src,ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _snwscanf(ثابت wchar_t *_Src,size_t Max_شمار,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _snwscanf_l(ثابت wchar_t *_Src,size_t Max_شمار,ثابت wchar_t *_Format,_locale_t _Locale,...);
  صحیح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _wscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحیح _FileHandle ,ثابت wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP تهی __cdecl _wperror(ثابت wchar_t *Err_پیام);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *_Mode);
#اگر !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP صحیح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#اگر !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#وگرنه
  __CRT_INLINE wint_t __cdecl getwchar() {بازگشت (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {بازگشت (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحیح مقدار_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long مقدار_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long مقدار_2,wchar_t *_Dest,صحیح _Radix);
  دوگانه __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP دوگانه __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  اعشاری __cdecl wcstof( ثابت wchar_t *nptr, wchar_t **endptr);
#اگر !defined __NO_ISOCEXT /* in libmingwex.a */
  اعشاری __cdecl wcstof (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  long دوگانه __cdecl wcstold (ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP long __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#endif
  _CRTIMP دوگانه __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP دوگانه __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str,wchar_t **_EndPtr,صحیح _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ثابت wchar_t *_Path,size_t Size_In_واژگان);
  _CRTIMP تهی __cdecl _wmakepath(wchar_t *_ResultPath,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP تهی __cdecl _wperror(ثابت wchar_t *Err_پیام);
#endif
  _CRTIMP صحیح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP تهی __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP تهی __cdecl _wsplitpath(ثابت wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحیح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *_Source);
  size_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  size_t __cdecl wcslen(ثابت wchar_t *_Str);
  size_t __cdecl wcsnlen(ثابت wchar_t *_Src,size_t Max_شمار);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ثابت wchar_t *_Source,size_t شمار_5);
  صحیح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ثابت wchar_t *_Source,size_t شمار_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحیح Err_رقم);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_شمار);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,size_t Max_شمار);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,size_t Max_شمار,_locale_t _Locale);
  صحیح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#define wcswcs wcsstr
  صحیح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحیح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_شمار);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحیح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  ساختار tm {
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
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ثابت ساختار tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ثابت __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_واژگان,ثابت wchar_t *_Format,ثابت ساختار tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_واژگان,ثابت wchar_t *_Format,ثابت ساختار tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ثابت __time64_t *_Time);
#endif

#اگر !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *_Time) { بازگشت _wctime32(_Time); }
#وگرنه
__CRT_INLINE wchar_t *__cdecl _wctime(ثابت time_t *_Time) { بازگشت _wctime64(_Time); }
#endif
#endif
#endif

  تعریفنوع صحیح mbstate_t;
  تعریفنوع wchar_t _Wint_t;

  wint_t __cdecl btowc(صحیح);
  size_t __cdecl mbrlen(ثابت نویسه *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,ثابت نویسه *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,ثابت نویسه **_PSrc,size_t شمار_5,mbstate_t *_State);
  size_t __cdecl wcrtomb(نویسه *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(نویسه *_Dest,ثابت wchar_t **_PSource,size_t شمار_5,mbstate_t *_State);
  صحیح __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *s, wchar_t c, size_t n);
  صحیح wmemcmp(ثابت wchar_t *s1, ثابت wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ثابت wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ثابت wchar_t *s2, size_t n);
  long long __cdecl wcstoll(ثابت wchar_t *nptr,wchar_t **endptr, صحیح base);
  unsigned long long __cdecl wcstoull(ثابت wchar_t *nptr,wchar_t **endptr, صحیح base);
#endif /* __NO_ISOCEXT */

  تهی *__cdecl memmove(تهی *_Dst,ثابت تهی *_Src,size_t Max_شمار);
  تهی *__cdecl memcpy(تهی *_Dst,ثابت تهی *_Src,size_t Max_شمار);
  __CRT_INLINE صحیح __cdecl fwide(FILE *_F,صحیح _M) { (تهی)_F; بازگشت (_M); }
  __CRT_INLINE صحیح __cdecl mbsinit(ثابت mbstate_t *_P) { بازگشت (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ثابت wchar_t *_S,wchar_t _C,size_t _N) { برای (;0<_N;++_S,--_N) اگر (*_S==_C) بازگشت (_CONST_RETURN wchar_t *)(_S); بازگشت (0); }
  __CRT_INLINE صحیح __cdecl wmemcmp(ثابت wchar_t *_S1,ثابت wchar_t *_S2,size_t _N) { برای (; 0 < _N; ++_S1,++_S2,--_N) اگر (*_S1!=*_S2) بازگشت (*_S1 < *_S2 ? -1 : +1); بازگشت (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ثابت wchar_t *_S2,size_t _N) { بازگشت (wchar_t *)memcpy(_S1,_S2,_N*اندازه(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ثابت wchar_t *_S2,size_t _N) { بازگشت (wchar_t *)memmove(_S1,_S2,_N*اندازه(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    برای (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    بازگشت (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)

#شامل <sec_api/wchar_s.h>
#endif
