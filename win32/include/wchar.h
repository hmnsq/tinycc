/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#અન્તર્ભાવ <_mingw.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  પ્રકારવ્યાખ્યા __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  પ્રકારવ્યાખ્યા __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  સંરચના _iobuf {
    અક્ષર *_ptr;
    પૂર્ણાંક _cnt;
    અક્ષર *_base;
    પૂર્ણાંક _flag;
    પૂર્ણાંક _file;
    પૂર્ણાંક _charbuf;
    પૂર્ણાંક _bufsiz;
    અક્ષર *_tmpfname;
  };
  પ્રકારવ્યાખ્યા સંરચના _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(શૂન્ય);
#નહીંતર
#ifdef _MSVCRT_
બાહ્ય FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#નહીંતર
બાહ્ય FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  પ્રકારવ્યાખ્યા unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  સંરચના _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  સંરચના _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  સંરચના _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  સંરચના _wfinddata64_t {
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
#નહીંતર
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef ખાલી
#ifdef __cplusplus
#define ખાલી 0
#નહીંતર
#define ખાલી ((શૂન્ય *)0)
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
#નહીંતર
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  બાહ્ય unsigned short *_pctype;
#નહીંતર
  બાહ્ય unsigned short **_imp___pctype;
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
  બાહ્ય unsigned short *_wctype;
#નહીંતર
  બાહ્ય unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#નહીંતર
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  બાહ્ય unsigned short *_pwctype;
#નહીંતર
  બાહ્ય unsigned short **_imp___pwctype;
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

  પૂર્ણાંક __cdecl iswalpha(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswupper(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswlower(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswdigit(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswxdigit(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswspace(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswpunct(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswalnum(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswprint(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswgraph(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswcntrl(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswascii(wint_t _C);
  પૂર્ણાંક __cdecl isleadbyte(પૂર્ણાંક _C);
  _CRTIMP પૂર્ણાંક __cdecl _isleadbyte_l(પૂર્ણાંક _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP પૂર્ણાંક __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl __iswcsymf(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl __iswcsym(wint_t _C);
  _CRTIMP પૂર્ણાંક __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  પૂર્ણાંક __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,પૂર્ણાંક Size_In_શબ્દો);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(પૂર્ણાંક _Drive,wchar_t *_DstBuf,પૂર્ણાંક Size_In_શબ્દો);
  wchar_t *__cdecl _wgetdcwd_nolock(પૂર્ણાંક _Drive,wchar_t *_DstBuf,પૂર્ણાંક Size_In_શબ્દો);
  _CRTIMP પૂર્ણાંક __cdecl _wchdir(અચલ wchar_t *_Path);
  _CRTIMP પૂર્ણાંક __cdecl _wmkdir(અચલ wchar_t *_Path);
  _CRTIMP પૂર્ણાંક __cdecl _wrmdir(અચલ wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP પૂર્ણાંક __cdecl _waccess(અચલ wchar_t *_Filename,પૂર્ણાંક _AccessMode);
  _CRTIMP પૂર્ણાંક __cdecl _wchmod(અચલ wchar_t *_Filename,પૂર્ણાંક _Mode);
  _CRTIMP પૂર્ણાંક __cdecl _wcreat(અચલ wchar_t *_Filename,પૂર્ણાંક _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(અચલ wchar_t *_Filename,સંરચના _wfinddata32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wfindnext32(intptr_t _FindHandle,સંરચના _wfinddata32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wunlink(અચલ wchar_t *_Filename);
  _CRTIMP પૂર્ણાંક __cdecl _wrename(અચલ wchar_t *_NewFilename,અચલ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(અચલ wchar_t *_Filename,સંરચના _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(અચલ wchar_t *_Filename,સંરચના _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(અચલ wchar_t *_Filename,સંરચના _wfinddata64_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wfindnext32i64(intptr_t _FindHandle,સંરચના _wfinddata32i64_t *_FindData);
  પૂર્ણાંક __cdecl _wfindnext64i32(intptr_t _FindHandle,સંરચના _wfinddata64i32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wfindnext64(intptr_t _FindHandle,સંરચના _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(પૂર્ણાંક *_FileHandle,અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,પૂર્ણાંક _PermissionFlag);
#જો !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP પૂર્ણાંક __cdecl _wopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,...);
  _CRTIMP પૂર્ણાંક __cdecl _wsopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,...);
#નહીંતર
  બાહ્ય "C++" _CRTIMP પૂર્ણાંક __cdecl _wopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _PermissionMode = 0);
  બાહ્ય "C++" _CRTIMP પૂર્ણાંક __cdecl _wsopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,પૂર્ણાંક _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(પૂર્ણાંક _Category,અચલ wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP પૂર્ણાંક __cdecl _wsystem(અચલ wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#જો !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned અક્ષર)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#જો !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  પ્રકારવ્યાખ્યા unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  પ્રકારવ્યાખ્યા unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક _dev_t;
#ifndef	NO_OLDNAMES
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  પ્રકારવ્યાખ્યા long _off_t;
#જો !defined(NO_OLDNAMES) || defined(_POSIX)
  પ્રકારવ્યાખ્યા long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  પ્રકારવ્યાખ્યા long long _off64_t;
#જો !defined(NO_OLDNAMES) || defined(_POSIX)
  પ્રકારવ્યાખ્યા long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#નહીંતર
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#નહીંતર
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  સંરચના _stat32 {
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
  સંરચના stat {
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

#જો _INTEGRAL_MAX_BITS >= 64

  સંરચના _stat32i64 {
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

  સંરચના _stat64i32 {
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

  સંરચના _stat64 {
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

  _CRTIMP પૂર્ણાંક __cdecl _wstat32(અચલ wchar_t *_Name,સંરચના _stat32 *_Stat);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP પૂર્ણાંક __cdecl _wstat32i64(અચલ wchar_t *_Name,સંરચના _stat32i64 *_Stat);
  પૂર્ણાંક __cdecl _wstat64i32(અચલ wchar_t *_Name,સંરચના _stat64i32 *_Stat);
  _CRTIMP પૂર્ણાંક __cdecl _wstat64(અચલ wchar_t *_Name,સંરચના _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(શૂન્ય);
  _CRTIMP wint_t __cdecl _getwche(શૂન્ય);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP પૂર્ણાંક __cdecl _cputws(અચલ wchar_t *_String);
  _CRTIMP પૂર્ણાંક __cdecl _cwprintf(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _cwscanf(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _cwscanf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cwprintf_p(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf_p(અચલ wchar_t *_Format,va_list _ArgList);

  _CRTIMP પૂર્ણાંક __cdecl _cwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(શૂન્ય);
  wint_t __cdecl _getwche_nolock(શૂન્ય);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode);
#નહીંતર
  _CRTIMP FILE *__cdecl _wfsopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode,પૂર્ણાંક _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(શૂન્ય);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(શૂન્ય);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,પૂર્ણાંક Size_In_શબ્દો,FILE *_File);
  પૂર્ણાંક __cdecl fputws(અચલ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP પૂર્ણાંક __cdecl _putws(અચલ wchar_t *_Str);
  પૂર્ણાંક __cdecl fwprintf(FILE *_File,અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl wprintf(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf(અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl vfwprintf(FILE *_File,અચલ wchar_t *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl vwprintf(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl swprintf(wchar_t*, અચલ wchar_t*, ...);
  _CRTIMP પૂર્ણાંક __cdecl vswprintf(wchar_t*, અચલ wchar_t*,va_list);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snwprintf(wchar_t *_Dest,size_t ગણતરી_5,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnwprintf(wchar_t *_Dest,size_t ગણતરી_5,અચલ wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  પૂર્ણાંક __cdecl snwprintf (wchar_t *s, size_t n, અચલ wchar_t * format, ...);
  __CRT_INLINE પૂર્ણાંક __cdecl vsnwprintf (wchar_t *s, size_t n, અચલ wchar_t *format, va_list arg) { પાછા _vsnwprintf(s,n,format,arg); }
  પૂર્ણાંક __cdecl vwscanf (અચલ wchar_t *, va_list);
  પૂર્ણાંક __cdecl vfwscanf (FILE *,અચલ wchar_t *,va_list);
  પૂર્ણાંક __cdecl vswscanf (અચલ wchar_t *,અચલ wchar_t *,va_list);
#endif
  _CRTIMP પૂર્ણાંક __cdecl _fwprintf_p(FILE *_File,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _wprintf_p(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfwprintf_p(FILE *_File,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vwprintf_p(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf_p(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf_p(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _wprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _wprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _fwprintf_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _fwprintf_p_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vfwprintf_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vfwprintf_p_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf(wchar_t *_Dest,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf(wchar_t *_Dest,અચલ wchar_t *_Format,va_list _Args);
  _CRTIMP પૂર્ણાંક __cdecl __swprintf_l(wchar_t *_Dest,અચલ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP પૂર્ણાંક __cdecl __vswprintf_l(wchar_t *_Dest,અચલ wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#અન્તર્ભાવ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(અચલ wchar_t *_Directory,અચલ wchar_t *_FilePrefix);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  પૂર્ણાંક __cdecl fwscanf(FILE *_File,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _fwscanf_l(FILE *_File,અચલ wchar_t *_Format,_locale_t _Locale,...);
  પૂર્ણાંક __cdecl swscanf(અચલ wchar_t *_Src,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _swscanf_l(અચલ wchar_t *_Src,અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _snwscanf(અચલ wchar_t *_Src,size_t Max_ગણતરી,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _snwscanf_l(અચલ wchar_t *_Src,size_t Max_ગણતરી,અચલ wchar_t *_Format,_locale_t _Locale,...);
  પૂર્ણાંક __cdecl wscanf(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _wscanf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(પૂર્ણાંક _FileHandle ,અચલ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP શૂન્ય __cdecl _wperror(અચલ wchar_t *Err_સંદેશ);
#endif
  _CRTIMP FILE *__cdecl _wpopen(અચલ wchar_t *_Command,અચલ wchar_t *_Mode);
#જો !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP પૂર્ણાંક __cdecl _wremove(અચલ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#જો !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#નહીંતર
  __CRT_INLINE wint_t __cdecl getwchar() {પાછા (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {પાછા (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(પૂર્ણાંક કિંમત_2,wchar_t *_Dest,પૂર્ણાંક _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long કિંમત_2,wchar_t *_Dest,પૂર્ણાંક _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long કિંમત_2,wchar_t *_Dest,પૂર્ણાંક _Radix);
  દ્વિગુણ __cdecl wcstod(અચલ wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP દ્વિગુણ __cdecl _wcstod_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  દશાંશ __cdecl wcstof( અચલ wchar_t *nptr, wchar_t **endptr);
#જો !defined __NO_ISOCEXT /* in libmingwex.a */
  દશાંશ __cdecl wcstof (અચલ wchar_t * __restrict__, wchar_t ** __restrict__);
  long દ્વિગુણ __cdecl wcstold (અચલ wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP long __cdecl _wcstol_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(અચલ wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP પૂર્ણાંક __cdecl _wsystem(અચલ wchar_t *_Command);
#endif
  _CRTIMP દ્વિગુણ __cdecl _wtof(અચલ wchar_t *_Str);
  _CRTIMP દ્વિગુણ __cdecl _wtof_l(અચલ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wtoi(અચલ wchar_t *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _wtoi_l(અચલ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(અચલ wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(અચલ wchar_t *_Str,_locale_t _Locale);

#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,પૂર્ણાંક _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,પૂર્ણાંક _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(અચલ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(અચલ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,અચલ wchar_t *_Path,size_t Size_In_શબ્દો);
  _CRTIMP શૂન્ય __cdecl _wmakepath(wchar_t *_ResultPath,અચલ wchar_t *_Drive,અચલ wchar_t *_Dir,અચલ wchar_t *_Filename,અચલ wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP શૂન્ય __cdecl _wperror(અચલ wchar_t *Err_સંદેશ);
#endif
  _CRTIMP પૂર્ણાંક __cdecl _wputenv(અચલ wchar_t *_EnvString);
  _CRTIMP શૂન્ય __cdecl _wsearchenv(અચલ wchar_t *_Filename,અચલ wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP શૂન્ય __cdecl _wsplitpath(અચલ wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(અચલ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,અચલ wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(અચલ wchar_t *_Str,wchar_t _Ch);
  પૂર્ણાંક __cdecl wcscmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,અચલ wchar_t *_Source);
  size_t __cdecl wcscspn(અચલ wchar_t *_Str,અચલ wchar_t *_Control);
  size_t __cdecl wcslen(અચલ wchar_t *_Str);
  size_t __cdecl wcsnlen(અચલ wchar_t *_Src,size_t Max_ગણતરી);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,અચલ wchar_t *_Source,size_t ગણતરી_5);
  પૂર્ણાંક __cdecl wcsncmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,અચલ wchar_t *_Source,size_t ગણતરી_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(અચલ wchar_t *_Str,અચલ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(અચલ wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(અચલ wchar_t *_Str,અચલ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(અચલ wchar_t *_Str,અચલ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,અચલ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(પૂર્ણાંક Err_અંક);
  _CRTIMP wchar_t *__cdecl __wcserror(અચલ wchar_t *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicmp_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicmp_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ગણતરી);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,અચલ wchar_t *_Src,size_t Max_ગણતરી);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,અચલ wchar_t *_Src,size_t Max_ગણતરી,_locale_t _Locale);
  પૂર્ણાંક __cdecl wcscoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _wcscoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsncoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _wcsncoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(અચલ wchar_t *_Str);
#define wcswcs wcsstr
  પૂર્ણાંક __cdecl wcsicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  પૂર્ણાંક __cdecl wcsnicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ગણતરી);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  પૂર્ણાંક __cdecl wcsicoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  સંરચના tm {
    પૂર્ણાંક tm_sec;
    પૂર્ણાંક tm_min;
    પૂર્ણાંક tm_hour;
    પૂર્ણાંક tm_mday;
    પૂર્ણાંક tm_mon;
    પૂર્ણાંક tm_year;
    પૂર્ણાંક tm_wday;
    પૂર્ણાંક tm_yday;
    પૂર્ણાંક tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(અચલ સંરચના tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(અચલ __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,અચલ સંરચના tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,અચલ સંરચના tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(અચલ __time64_t *_Time);
#endif

#જો !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(અચલ time_t *_Time) { પાછા _wctime32(_Time); }
#નહીંતર
__CRT_INLINE wchar_t *__cdecl _wctime(અચલ time_t *_Time) { પાછા _wctime64(_Time); }
#endif
#endif
#endif

  પ્રકારવ્યાખ્યા પૂર્ણાંક mbstate_t;
  પ્રકારવ્યાખ્યા wchar_t _Wint_t;

  wint_t __cdecl btowc(પૂર્ણાંક);
  size_t __cdecl mbrlen(અચલ અક્ષર *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,અચલ અક્ષર *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,અચલ અક્ષર **_PSrc,size_t ગણતરી_5,mbstate_t *_State);
  size_t __cdecl wcrtomb(અક્ષર *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(અક્ષર *_Dest,અચલ wchar_t **_PSource,size_t ગણતરી_5,mbstate_t *_State);
  પૂર્ણાંક __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(અચલ wchar_t *s, wchar_t c, size_t n);
  પૂર્ણાંક wmemcmp(અચલ wchar_t *s1, અચલ wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,અચલ wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, અચલ wchar_t *s2, size_t n);
  long long __cdecl wcstoll(અચલ wchar_t *nptr,wchar_t **endptr, પૂર્ણાંક base);
  unsigned long long __cdecl wcstoull(અચલ wchar_t *nptr,wchar_t **endptr, પૂર્ણાંક base);
#endif /* __NO_ISOCEXT */

  શૂન્ય *__cdecl memmove(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,size_t Max_ગણતરી);
  શૂન્ય *__cdecl memcpy(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,size_t Max_ગણતરી);
  __CRT_INLINE પૂર્ણાંક __cdecl fwide(FILE *_F,પૂર્ણાંક _M) { (શૂન્ય)_F; પાછા (_M); }
  __CRT_INLINE પૂર્ણાંક __cdecl mbsinit(અચલ mbstate_t *_P) { પાછા (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(અચલ wchar_t *_S,wchar_t _C,size_t _N) { માટે (;0<_N;++_S,--_N) જો (*_S==_C) પાછા (_CONST_RETURN wchar_t *)(_S); પાછા (0); }
  __CRT_INLINE પૂર્ણાંક __cdecl wmemcmp(અચલ wchar_t *_S1,અચલ wchar_t *_S2,size_t _N) { માટે (; 0 < _N; ++_S1,++_S2,--_N) જો (*_S1!=*_S2) પાછા (*_S1 < *_S2 ? -1 : +1); પાછા (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,અચલ wchar_t *_S2,size_t _N) { પાછા (wchar_t *)memcpy(_S1,_S2,_N*કદ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,અચલ wchar_t *_S2,size_t _N) { પાછા (wchar_t *)memmove(_S1,_S2,_N*કદ(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    માટે (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    પાછા (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)

#અન્તર્ભાવ <sec_api/wchar_s.h>
#endif
