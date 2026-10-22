/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#அந்தர்பாவ <_mingw.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  வகைவரை __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  வகைவரை __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  கட்டமைப்பு _iobuf {
    எழுத்து *_ptr;
    முழு _cnt;
    எழுத்து *_base;
    முழு _flag;
    முழு _file;
    முழு _charbuf;
    முழு _bufsiz;
    எழுத்து *_tmpfname;
  };
  வகைவரை கட்டமைப்பு _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(வெறுமை);
#இல்லையெனில்
#ifdef _MSVCRT_
வெளி FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#இல்லையெனில்
வெளி FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  வகைவரை unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  கட்டமைப்பு _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  கட்டமைப்பு _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  கட்டமைப்பு _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  கட்டமைப்பு _wfinddata64_t {
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
#இல்லையெனில்
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef வெற்று
#ifdef __cplusplus
#define வெற்று 0
#இல்லையெனில்
#define வெற்று ((வெறுமை *)0)
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
#இல்லையெனில்
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  வெளி unsigned short *_pctype;
#இல்லையெனில்
  வெளி unsigned short **_imp___pctype;
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
  வெளி unsigned short *_wctype;
#இல்லையெனில்
  வெளி unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#இல்லையெனில்
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  வெளி unsigned short *_pwctype;
#இல்லையெனில்
  வெளி unsigned short **_imp___pwctype;
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

  முழு __cdecl iswalpha(wint_t _C);
  _CRTIMP முழு __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswupper(wint_t _C);
  _CRTIMP முழு __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswlower(wint_t _C);
  _CRTIMP முழு __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswdigit(wint_t _C);
  _CRTIMP முழு __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswxdigit(wint_t _C);
  _CRTIMP முழு __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswspace(wint_t _C);
  _CRTIMP முழு __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswpunct(wint_t _C);
  _CRTIMP முழு __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswalnum(wint_t _C);
  _CRTIMP முழு __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswprint(wint_t _C);
  _CRTIMP முழு __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswgraph(wint_t _C);
  _CRTIMP முழு __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswcntrl(wint_t _C);
  _CRTIMP முழு __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswascii(wint_t _C);
  முழு __cdecl isleadbyte(முழு _C);
  _CRTIMP முழு __cdecl _isleadbyte_l(முழு _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP முழு __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP முழு __cdecl __iswcsymf(wint_t _C);
  _CRTIMP முழு __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP முழு __cdecl __iswcsym(wint_t _C);
  _CRTIMP முழு __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  முழு __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,முழு Size_In_சொற்கள்);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(முழு _Drive,wchar_t *_DstBuf,முழு Size_In_சொற்கள்);
  wchar_t *__cdecl _wgetdcwd_nolock(முழு _Drive,wchar_t *_DstBuf,முழு Size_In_சொற்கள்);
  _CRTIMP முழு __cdecl _wchdir(மாறிலி wchar_t *_Path);
  _CRTIMP முழு __cdecl _wmkdir(மாறிலி wchar_t *_Path);
  _CRTIMP முழு __cdecl _wrmdir(மாறிலி wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP முழு __cdecl _waccess(மாறிலி wchar_t *_Filename,முழு _AccessMode);
  _CRTIMP முழு __cdecl _wchmod(மாறிலி wchar_t *_Filename,முழு _Mode);
  _CRTIMP முழு __cdecl _wcreat(மாறிலி wchar_t *_Filename,முழு _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata32_t *_FindData);
  _CRTIMP முழு __cdecl _wfindnext32(intptr_t _FindHandle,கட்டமைப்பு _wfinddata32_t *_FindData);
  _CRTIMP முழு __cdecl _wunlink(மாறிலி wchar_t *_Filename);
  _CRTIMP முழு __cdecl _wrename(மாறிலி wchar_t *_NewFilename,மாறிலி wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata64_t *_FindData);
  _CRTIMP முழு __cdecl _wfindnext32i64(intptr_t _FindHandle,கட்டமைப்பு _wfinddata32i64_t *_FindData);
  முழு __cdecl _wfindnext64i32(intptr_t _FindHandle,கட்டமைப்பு _wfinddata64i32_t *_FindData);
  _CRTIMP முழு __cdecl _wfindnext64(intptr_t _FindHandle,கட்டமைப்பு _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(முழு *_FileHandle,மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _ShareFlag,முழு _PermissionFlag);
#எனில் !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP முழு __cdecl _wopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,...);
  _CRTIMP முழு __cdecl _wsopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _ShareFlag,...);
#இல்லையெனில்
  வெளி "C++" _CRTIMP முழு __cdecl _wopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _PermissionMode = 0);
  வெளி "C++" _CRTIMP முழு __cdecl _wsopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _ShareFlag,முழு _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(முழு _Category,மாறிலி wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP முழு __cdecl _wsystem(மாறிலி wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#எனில் !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned எழுத்து)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#எனில் !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  வகைவரை unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  வகைவரை unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  வகைவரை unsigned முழு _dev_t;
#ifndef	NO_OLDNAMES
  வகைவரை unsigned முழு dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  வகைவரை long _off_t;
#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
  வகைவரை long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  வகைவரை long long _off64_t;
#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
  வகைவரை long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#இல்லையெனில்
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#இல்லையெனில்
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  கட்டமைப்பு _stat32 {
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
  கட்டமைப்பு stat {
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

#எனில் _INTEGRAL_MAX_BITS >= 64

  கட்டமைப்பு _stat32i64 {
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

  கட்டமைப்பு _stat64i32 {
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

  கட்டமைப்பு _stat64 {
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

  _CRTIMP முழு __cdecl _wstat32(மாறிலி wchar_t *_Name,கட்டமைப்பு _stat32 *_Stat);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP முழு __cdecl _wstat32i64(மாறிலி wchar_t *_Name,கட்டமைப்பு _stat32i64 *_Stat);
  முழு __cdecl _wstat64i32(மாறிலி wchar_t *_Name,கட்டமைப்பு _stat64i32 *_Stat);
  _CRTIMP முழு __cdecl _wstat64(மாறிலி wchar_t *_Name,கட்டமைப்பு _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(வெறுமை);
  _CRTIMP wint_t __cdecl _getwche(வெறுமை);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP முழு __cdecl _cputws(மாறிலி wchar_t *_String);
  _CRTIMP முழு __cdecl _cwprintf(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cwprintf_p(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vcwprintf_p(மாறிலி wchar_t *_Format,va_list _ArgList);

  _CRTIMP முழு __cdecl _cwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _cwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(வெறுமை);
  wint_t __cdecl _getwche_nolock(வெறுமை);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode);
#இல்லையெனில்
  _CRTIMP FILE *__cdecl _wfsopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode,முழு _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(வெறுமை);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(வெறுமை);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,முழு Size_In_சொற்கள்,FILE *_File);
  முழு __cdecl fputws(மாறிலி wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP முழு __cdecl _putws(மாறிலி wchar_t *_Str);
  முழு __cdecl fwprintf(FILE *_File,மாறிலி wchar_t *_Format,...);
  முழு __cdecl wprintf(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _scwprintf(மாறிலி wchar_t *_Format,...);
  முழு __cdecl vfwprintf(FILE *_File,மாறிலி wchar_t *_Format,va_list _ArgList);
  முழு __cdecl vwprintf(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl swprintf(wchar_t*, மாறிலி wchar_t*, ...);
  _CRTIMP முழு __cdecl vswprintf(wchar_t*, மாறிலி wchar_t*,va_list);
  _CRTIMP முழு __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _snwprintf(wchar_t *_Dest,size_t மொத்தம்_5,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vsnwprintf(wchar_t *_Dest,size_t மொத்தம்_5,மாறிலி wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  முழு __cdecl snwprintf (wchar_t *s, size_t n, மாறிலி wchar_t * format, ...);
  __CRT_INLINE முழு __cdecl vsnwprintf (wchar_t *s, size_t n, மாறிலி wchar_t *format, va_list arg) { திரும்பு _vsnwprintf(s,n,format,arg); }
  முழு __cdecl vwscanf (மாறிலி wchar_t *, va_list);
  முழு __cdecl vfwscanf (FILE *,மாறிலி wchar_t *,va_list);
  முழு __cdecl vswscanf (மாறிலி wchar_t *,மாறிலி wchar_t *,va_list);
#endif
  _CRTIMP முழு __cdecl _fwprintf_p(FILE *_File,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _wprintf_p(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vfwprintf_p(FILE *_File,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _vwprintf_p(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _scwprintf_p(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vscwprintf_p(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _wprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _wprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _fwprintf_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _fwprintf_p_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vfwprintf_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vfwprintf_p_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _scwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _scwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vscwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _swprintf(wchar_t *_Dest,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vswprintf(wchar_t *_Dest,மாறிலி wchar_t *_Format,va_list _Args);
  _CRTIMP முழு __cdecl __swprintf_l(wchar_t *_Dest,மாறிலி wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP முழு __cdecl __vswprintf_l(wchar_t *_Dest,மாறிலி wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#அந்தர்பாவ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(மாறிலி wchar_t *_Directory,மாறிலி wchar_t *_FilePrefix);
  _CRTIMP முழு __cdecl _vscwprintf(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _vscwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  முழு __cdecl fwscanf(FILE *_File,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _fwscanf_l(FILE *_File,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  முழு __cdecl swscanf(மாறிலி wchar_t *_Src,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _swscanf_l(மாறிலி wchar_t *_Src,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _snwscanf(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _snwscanf_l(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  முழு __cdecl wscanf(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _wscanf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(முழு _FileHandle ,மாறிலி wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP வெறுமை __cdecl _wperror(மாறிலி wchar_t *Err_செய்தி);
#endif
  _CRTIMP FILE *__cdecl _wpopen(மாறிலி wchar_t *_Command,மாறிலி wchar_t *_Mode);
#எனில் !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP முழு __cdecl _wremove(மாறிலி wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#எனில் !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#இல்லையெனில்
  __CRT_INLINE wint_t __cdecl getwchar() {திரும்பு (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {திரும்பு (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(முழு மதிப்பு_2,wchar_t *_Dest,முழு _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long மதிப்பு_2,wchar_t *_Dest,முழு _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long மதிப்பு_2,wchar_t *_Dest,முழு _Radix);
  இரட்டை __cdecl wcstod(மாறிலி wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP இரட்டை __cdecl _wcstod_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  தசம __cdecl wcstof( மாறிலி wchar_t *nptr, wchar_t **endptr);
#எனில் !defined __NO_ISOCEXT /* in libmingwex.a */
  தசம __cdecl wcstof (மாறிலி wchar_t * __restrict__, wchar_t ** __restrict__);
  long இரட்டை __cdecl wcstold (மாறிலி wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP long __cdecl _wcstol_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(மாறிலி wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP முழு __cdecl _wsystem(மாறிலி wchar_t *_Command);
#endif
  _CRTIMP இரட்டை __cdecl _wtof(மாறிலி wchar_t *_Str);
  _CRTIMP இரட்டை __cdecl _wtof_l(மாறிலி wchar_t *_Str,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wtoi(மாறிலி wchar_t *_Str);
  _CRTIMP முழு __cdecl _wtoi_l(மாறிலி wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(மாறிலி wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(மாறிலி wchar_t *_Str,_locale_t _Locale);

#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,முழு _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,முழு _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(மாறிலி wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(மாறிலி wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,மாறிலி wchar_t *_Path,size_t Size_In_சொற்கள்);
  _CRTIMP வெறுமை __cdecl _wmakepath(wchar_t *_ResultPath,மாறிலி wchar_t *_Drive,மாறிலி wchar_t *_Dir,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP வெறுமை __cdecl _wperror(மாறிலி wchar_t *Err_செய்தி);
#endif
  _CRTIMP முழு __cdecl _wputenv(மாறிலி wchar_t *_EnvString);
  _CRTIMP வெறுமை __cdecl _wsearchenv(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP வெறுமை __cdecl _wsplitpath(மாறிலி wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(மாறிலி wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,மாறிலி wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(மாறிலி wchar_t *_Str,wchar_t _Ch);
  முழு __cdecl wcscmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,மாறிலி wchar_t *_Source);
  size_t __cdecl wcscspn(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_Control);
  size_t __cdecl wcslen(மாறிலி wchar_t *_Str);
  size_t __cdecl wcsnlen(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,மாறிலி wchar_t *_Source,size_t மொத்தம்_5);
  முழு __cdecl wcsncmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,மாறிலி wchar_t *_Source,size_t மொத்தம்_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(மாறிலி wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,மாறிலி wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(முழு Err_இலக்கம்);
  _CRTIMP wchar_t *__cdecl __wcserror(மாறிலி wchar_t *_Str);
  _CRTIMP முழு __cdecl _wcsicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  _CRTIMP முழு __cdecl _wcsicmp_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsnicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _wcsnicmp_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_மொத்தம்);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,மாறிலி wchar_t *_Src,size_t Max_மொத்தம்);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,_locale_t _Locale);
  முழு __cdecl wcscoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  _CRTIMP முழு __cdecl _wcscoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsicoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  _CRTIMP முழு __cdecl _wcsicoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsncoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _wcsncoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsnicoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _wcsnicoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(மாறிலி wchar_t *_Str);
#define wcswcs wcsstr
  முழு __cdecl wcsicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  முழு __cdecl wcsnicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_மொத்தம்);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  முழு __cdecl wcsicoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  கட்டமைப்பு tm {
    முழு tm_sec;
    முழு tm_min;
    முழு tm_hour;
    முழு tm_mday;
    முழு tm_mon;
    முழு tm_year;
    முழு tm_wday;
    முழு tm_yday;
    முழு tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(மாறிலி கட்டமைப்பு tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(மாறிலி __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,மாறிலி கட்டமைப்பு tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,மாறிலி கட்டமைப்பு tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(மாறிலி __time64_t *_Time);
#endif

#எனில் !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(மாறிலி time_t *_Time) { திரும்பு _wctime32(_Time); }
#இல்லையெனில்
__CRT_INLINE wchar_t *__cdecl _wctime(மாறிலி time_t *_Time) { திரும்பு _wctime64(_Time); }
#endif
#endif
#endif

  வகைவரை முழு mbstate_t;
  வகைவரை wchar_t _Wint_t;

  wint_t __cdecl btowc(முழு);
  size_t __cdecl mbrlen(மாறிலி எழுத்து *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,மாறிலி எழுத்து *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,மாறிலி எழுத்து **_PSrc,size_t மொத்தம்_5,mbstate_t *_State);
  size_t __cdecl wcrtomb(எழுத்து *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(எழுத்து *_Dest,மாறிலி wchar_t **_PSource,size_t மொத்தம்_5,mbstate_t *_State);
  முழு __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(மாறிலி wchar_t *s, wchar_t c, size_t n);
  முழு wmemcmp(மாறிலி wchar_t *s1, மாறிலி wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,மாறிலி wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, மாறிலி wchar_t *s2, size_t n);
  long long __cdecl wcstoll(மாறிலி wchar_t *nptr,wchar_t **endptr, முழு base);
  unsigned long long __cdecl wcstoull(மாறிலி wchar_t *nptr,wchar_t **endptr, முழு base);
#endif /* __NO_ISOCEXT */

  வெறுமை *__cdecl memmove(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,size_t Max_மொத்தம்);
  வெறுமை *__cdecl memcpy(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,size_t Max_மொத்தம்);
  __CRT_INLINE முழு __cdecl fwide(FILE *_F,முழு _M) { (வெறுமை)_F; திரும்பு (_M); }
  __CRT_INLINE முழு __cdecl mbsinit(மாறிலி mbstate_t *_P) { திரும்பு (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(மாறிலி wchar_t *_S,wchar_t _C,size_t _N) { க்கு (;0<_N;++_S,--_N) எனில் (*_S==_C) திரும்பு (_CONST_RETURN wchar_t *)(_S); திரும்பு (0); }
  __CRT_INLINE முழு __cdecl wmemcmp(மாறிலி wchar_t *_S1,மாறிலி wchar_t *_S2,size_t _N) { க்கு (; 0 < _N; ++_S1,++_S2,--_N) எனில் (*_S1!=*_S2) திரும்பு (*_S1 < *_S2 ? -1 : +1); திரும்பு (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,மாறிலி wchar_t *_S2,size_t _N) { திரும்பு (wchar_t *)memcpy(_S1,_S2,_N*அளவு(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,மாறிலி wchar_t *_S2,size_t _N) { திரும்பு (wchar_t *)memmove(_S1,_S2,_N*அளவு(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    க்கு (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    திரும்பு (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(எடு)

#அந்தர்பாவ <sec_api/wchar_s.h>
#endif
