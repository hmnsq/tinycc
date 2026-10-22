/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#अन्तर्भाव <_mingw.h>

#pragma pack(प्रक्षिप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  प्रकारनिर्देश __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  प्रकारनिर्देश __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  संरचना _iobuf {
    वर्ण *_ptr;
    पूर्णाङ्क _cnt;
    वर्ण *_base;
    पूर्णाङ्क _flag;
    पूर्णाङ्क _file;
    पूर्णाङ्क _charbuf;
    पूर्णाङ्क _bufsiz;
    वर्ण *_tmpfname;
  };
  प्रकारनिर्देश संरचना _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(शून्य);
#अञ्ञथा
#ifdef _MSVCRT_
बाह्य FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#अञ्ञथा
बाह्य FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  प्रकारनिर्देश unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  संरचना _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  संरचना _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  संरचना _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  संरचना _wfinddata64_t {
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
#अञ्ञथा
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अञ्ञथा
#define रिक्त ((शून्य *)0)
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
#अञ्ञथा
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  बाह्य unsigned short *_pctype;
#अञ्ञथा
  बाह्य unsigned short **_imp___pctype;
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
  बाह्य unsigned short *_wctype;
#अञ्ञथा
  बाह्य unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#अञ्ञथा
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  बाह्य unsigned short *_pwctype;
#अञ्ञथा
  बाह्य unsigned short **_imp___pwctype;
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

  पूर्णाङ्क __cdecl iswalpha(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswupper(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswlower(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswdigit(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswxdigit(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswspace(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswpunct(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswalnum(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswprint(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswgraph(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswcntrl(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswascii(wint_t _C);
  पूर्णाङ्क __cdecl isleadbyte(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isleadbyte_l(पूर्णाङ्क _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP पूर्णाङ्क __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl __iswcsymf(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl __iswcsym(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,पूर्णाङ्क Size_In_शब्दाः);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क Size_In_शब्दाः);
  wchar_t *__cdecl _wgetdcwd_nolock(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क Size_In_शब्दाः);
  _CRTIMP पूर्णाङ्क __cdecl _wchdir(ध्रुव wchar_t *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wmkdir(ध्रुव wchar_t *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wrmdir(ध्रुव wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP पूर्णाङ्क __cdecl _waccess(ध्रुव wchar_t *_Filename,पूर्णाङ्क _AccessMode);
  _CRTIMP पूर्णाङ्क __cdecl _wchmod(ध्रुव wchar_t *_Filename,पूर्णाङ्क _Mode);
  _CRTIMP पूर्णाङ्क __cdecl _wcreat(ध्रुव wchar_t *_Filename,पूर्णाङ्क _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ध्रुव wchar_t *_Filename,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32(intptr_t _FindHandle,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wunlink(ध्रुव wchar_t *_Filename);
  _CRTIMP पूर्णाङ्क __cdecl _wrename(ध्रुव wchar_t *_NewFilename,ध्रुव wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#सचे _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ध्रुव wchar_t *_Filename,संरचना _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ध्रुव wchar_t *_Filename,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ध्रुव wchar_t *_Filename,संरचना _wfinddata64_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32i64(intptr_t _FindHandle,संरचना _wfinddata32i64_t *_FindData);
  पूर्णाङ्क __cdecl _wfindnext64i32(intptr_t _FindHandle,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext64(intptr_t _FindHandle,संरचना _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णाङ्क *_FileHandle,ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionFlag);
#सचे !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,...);
  _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
#अञ्ञथा
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(पूर्णाङ्क _Category,ध्रुव wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(पूर्णाङ्क _Mode,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(ध्रुव wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#सचे !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned वर्ण)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#सचे !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  प्रकारनिर्देश unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  प्रकारनिर्देश unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  प्रकारनिर्देश unsigned पूर्णाङ्क _dev_t;
#ifndef	NO_OLDNAMES
  प्रकारनिर्देश unsigned पूर्णाङ्क dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  प्रकारनिर्देश long _off_t;
#सचे !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  प्रकारनिर्देश long long _off64_t;
#सचे !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#अञ्ञथा
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#अञ्ञथा
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  संरचना _stat32 {
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
  संरचना stat {
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

#सचे _INTEGRAL_MAX_BITS >= 64

  संरचना _stat32i64 {
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

  संरचना _stat64i32 {
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

  संरचना _stat64 {
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

  _CRTIMP पूर्णाङ्क __cdecl _wstat32(ध्रुव wchar_t *_Name,संरचना _stat32 *_Stat);
#सचे _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णाङ्क __cdecl _wstat32i64(ध्रुव wchar_t *_Name,संरचना _stat32i64 *_Stat);
  पूर्णाङ्क __cdecl _wstat64i32(ध्रुव wchar_t *_Name,संरचना _stat64i32 *_Stat);
  _CRTIMP पूर्णाङ्क __cdecl _wstat64(ध्रुव wchar_t *_Name,संरचना _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(शून्य);
  _CRTIMP wint_t __cdecl _getwche(शून्य);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP पूर्णाङ्क __cdecl _cputws(ध्रुव wchar_t *_String);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p(ध्रुव wchar_t *_Format,va_list _ArgList);

  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(शून्य);
  wint_t __cdecl _getwche_nolock(शून्य);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode);
#अञ्ञथा
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode,पूर्णाङ्क _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(शून्य);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(शून्य);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,पूर्णाङ्क Size_In_शब्दाः,FILE *_File);
  पूर्णाङ्क __cdecl fputws(ध्रुव wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP पूर्णाङ्क __cdecl _putws(ध्रुव wchar_t *_Str);
  पूर्णाङ्क __cdecl fwprintf(FILE *_File,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl wprintf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf(ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl vfwprintf(FILE *_File,ध्रुव wchar_t *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl swprintf(wchar_t*, ध्रुव wchar_t*, ...);
  _CRTIMP पूर्णाङ्क __cdecl vswprintf(wchar_t*, ध्रुव wchar_t*,va_list);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf(wchar_t *_Dest,size_t गणनम्_5,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf(wchar_t *_Dest,size_t गणनम्_5,ध्रुव wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णाङ्क __cdecl snwprintf (wchar_t *s, size_t n, ध्रुव wchar_t * format, ...);
  __CRT_INLINE पूर्णाङ्क __cdecl vsnwprintf (wchar_t *s, size_t n, ध्रुव wchar_t *format, va_list arg) { पटिनिवत्त _vsnwprintf(s,n,format,arg); }
  पूर्णाङ्क __cdecl vwscanf (ध्रुव wchar_t *, va_list);
  पूर्णाङ्क __cdecl vfwscanf (FILE *,ध्रुव wchar_t *,va_list);
  पूर्णाङ्क __cdecl vswscanf (ध्रुव wchar_t *,ध्रुव wchar_t *,va_list);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p(FILE *_File,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p(FILE *_File,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,va_list _Args);
  _CRTIMP पूर्णाङ्क __cdecl __swprintf_l(wchar_t *_Dest,ध्रुव wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP पूर्णाङ्क __cdecl __vswprintf_l(wchar_t *_Dest,ध्रुव wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#अन्तर्भाव <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ध्रुव wchar_t *_Directory,ध्रुव wchar_t *_FilePrefix);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  पूर्णाङ्क __cdecl fwscanf(FILE *_File,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl swscanf(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_l(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf(ध्रुव wchar_t *_Src,size_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_l(ध्रुव wchar_t *_Src,size_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl wscanf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(पूर्णाङ्क _FileHandle ,ध्रुव wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(ध्रुव wchar_t *Err_सन्देशः);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ध्रुव wchar_t *_Command,ध्रुव wchar_t *_Mode);
#सचे !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP पूर्णाङ्क __cdecl _wremove(ध्रुव wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#सचे !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#अञ्ञथा
  __CRT_INLINE wint_t __cdecl getwchar() {पटिनिवत्त (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {पटिनिवत्त (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(पूर्णाङ्क मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  द्विगुण __cdecl wcstod(ध्रुव wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP द्विगुण __cdecl _wcstod_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  भिन्न __cdecl wcstof( ध्रुव wchar_t *nptr, wchar_t **endptr);
#सचे !defined __NO_ISOCEXT /* in libmingwex.a */
  भिन्न __cdecl wcstof (ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
  long द्विगुण __cdecl wcstold (ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP long __cdecl _wcstol_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ध्रुव wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(ध्रुव wchar_t *_Command);
#endif
  _CRTIMP द्विगुण __cdecl _wtof(ध्रुव wchar_t *_Str);
  _CRTIMP द्विगुण __cdecl _wtof_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi(ध्रुव wchar_t *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ध्रुव wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ध्रुव wchar_t *_Str,_locale_t _Locale);

#सचे _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ध्रुव wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ध्रुव wchar_t *_Str,wchar_t **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ध्रुव wchar_t *_Path,size_t Size_In_शब्दाः);
  _CRTIMP शून्य __cdecl _wmakepath(wchar_t *_ResultPath,ध्रुव wchar_t *_Drive,ध्रुव wchar_t *_Dir,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(ध्रुव wchar_t *Err_सन्देशः);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _wputenv(ध्रुव wchar_t *_EnvString);
  _CRTIMP शून्य __cdecl _wsearchenv(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP शून्य __cdecl _wsplitpath(ध्रुव wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ध्रुव wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  पूर्णाङ्क __cdecl wcscmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  size_t __cdecl wcscspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  size_t __cdecl wcslen(ध्रुव wchar_t *_Str);
  size_t __cdecl wcsnlen(ध्रुव wchar_t *_Src,size_t Max_गणनम्);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ध्रुव wchar_t *_Source,size_t गणनम्_5);
  पूर्णाङ्क __cdecl wcsncmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ध्रुव wchar_t *_Source,size_t गणनम्_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ध्रुव wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(पूर्णाङ्क Err_अङ्कः);
  _CRTIMP wchar_t *__cdecl __wcserror(ध्रुव wchar_t *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_गणनम्);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ध्रुव wchar_t *_Src,size_t Max_गणनम्);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ध्रुव wchar_t *_Src,size_t Max_गणनम्,_locale_t _Locale);
  पूर्णाङ्क __cdecl wcscoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcscoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ध्रुव wchar_t *_Str);
#define wcswcs wcsstr
  पूर्णाङ्क __cdecl wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  पूर्णाङ्क __cdecl wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_गणनम्);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_गणनम्);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  पूर्णाङ्क __cdecl wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  संरचना tm {
    पूर्णाङ्क tm_sec;
    पूर्णाङ्क tm_min;
    पूर्णाङ्क tm_hour;
    पूर्णाङ्क tm_mday;
    पूर्णाङ्क tm_mon;
    पूर्णाङ्क tm_year;
    पूर्णाङ्क tm_wday;
    पूर्णाङ्क tm_yday;
    पूर्णाङ्क tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ध्रुव संरचना tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ध्रुव __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#सचे _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ध्रुव __time64_t *_Time);
#endif

#सचे !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { पटिनिवत्त _wctime32(_Time); }
#अञ्ञथा
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { पटिनिवत्त _wctime64(_Time); }
#endif
#endif
#endif

  प्रकारनिर्देश पूर्णाङ्क mbstate_t;
  प्रकारनिर्देश wchar_t _Wint_t;

  wint_t __cdecl btowc(पूर्णाङ्क);
  size_t __cdecl mbrlen(ध्रुव वर्ण *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,ध्रुव वर्ण *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,ध्रुव वर्ण **_PSrc,size_t गणनम्_5,mbstate_t *_State);
  size_t __cdecl wcrtomb(वर्ण *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(वर्ण *_Dest,ध्रुव wchar_t **_PSource,size_t गणनम्_5,mbstate_t *_State);
  पूर्णाङ्क __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ध्रुव wchar_t *s, wchar_t c, size_t n);
  पूर्णाङ्क wmemcmp(ध्रुव wchar_t *s1, ध्रुव wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ध्रुव wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ध्रुव wchar_t *s2, size_t n);
  long long __cdecl wcstoll(ध्रुव wchar_t *nptr,wchar_t **endptr, पूर्णाङ्क base);
  unsigned long long __cdecl wcstoull(ध्रुव wchar_t *nptr,wchar_t **endptr, पूर्णाङ्क base);
#endif /* __NO_ISOCEXT */

  शून्य *__cdecl memmove(शून्य *_Dst,ध्रुव शून्य *_Src,size_t Max_गणनम्);
  शून्य *__cdecl memcpy(शून्य *_Dst,ध्रुव शून्य *_Src,size_t Max_गणनम्);
  __CRT_INLINE पूर्णाङ्क __cdecl fwide(FILE *_F,पूर्णाङ्क _M) { (शून्य)_F; पटिनिवत्त (_M); }
  __CRT_INLINE पूर्णाङ्क __cdecl mbsinit(ध्रुव mbstate_t *_P) { पटिनिवत्त (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ध्रुव wchar_t *_S,wchar_t _C,size_t _N) { अत्थाय (;0<_N;++_S,--_N) सचे (*_S==_C) पटिनिवत्त (_CONST_RETURN wchar_t *)(_S); पटिनिवत्त (0); }
  __CRT_INLINE पूर्णाङ्क __cdecl wmemcmp(ध्रुव wchar_t *_S1,ध्रुव wchar_t *_S2,size_t _N) { अत्थाय (; 0 < _N; ++_S1,++_S2,--_N) सचे (*_S1!=*_S2) पटिनिवत्त (*_S1 < *_S2 ? -1 : +1); पटिनिवत्त (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ध्रुव wchar_t *_S2,size_t _N) { पटिनिवत्त (wchar_t *)memcpy(_S1,_S2,_N*परिमाण(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ध्रुव wchar_t *_S2,size_t _N) { पटिनिवत्त (wchar_t *)memmove(_S1,_S2,_N*परिमाण(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    अत्थाय (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    पटिनिवत्त (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(निष्कासय)

#अन्तर्भाव <sec_api/wchar_s.h>
#endif
