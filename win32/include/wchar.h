/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#अन्तर्भाव <_mingw.h>

#pragma pack(थप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((ब_अक्षर_प्रकार) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  प्रकारनिर्देश __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  प्रकारनिर्देश __gnuc_va_list बहु_सूची;
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
  प्रकारनिर्देश संरचना _iobuf खाता;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP खाता *__cdecl __iob_func(शून्य);
#अन्यथा
#ifdef _MSVCRT_
बाह्य खाता _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#अन्यथा
बाह्य खाता (*_imp___iob)[];	/* A pointer to an array of FILE */
#define __iob_func()	(*_imp___iob)
#define _iob __iob_func()
#endif
#endif

#define _iob __iob_func()
#endif

#ifndef _STDSTREAM_DEFINED
#define मानक_निवेश (&__iob_func()[0])
#define मानक_निकास (&__iob_func()[1])
#define मानक_त्रुटि (&__iob_func()[2])
#define _STDSTREAM_DEFINED
#endif

#ifndef _FSIZE_T_DEFINED
  प्रकारनिर्देश अचिन्हित दीर्घ _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  संरचना _wfinddata32_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    ब_अक्षर_प्रकार name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  संरचना _wfinddata32i64_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    ब_अक्षर_प्रकार name[260];
  };

  संरचना _wfinddata64i32_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    ब_अक्षर_प्रकार name[260];
  };

  संरचना _wfinddata64_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    ब_अक्षर_प्रकार name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _wfinddata_t _wfinddata32_t
#define _wfinddatai64_t _wfinddata32i64_t

#define _wfindfirst _wfindfirst32
#define _wfindnext _wfindnext32
#define _wfindfirsti64 _wfindfirst32i64
#define _wfindnexti64 _wfindnext32i64
#अन्यथा
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
#अन्यथा
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
#अन्यथा
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  बाह्य अचिन्हित लघु *_pctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pctype;
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
  बाह्य अचिन्हित लघु *_wctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#अन्यथा
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  बाह्य अचिन्हित लघु *_pwctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pwctype;
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

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetcwd(ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क Size_In_शब्दहरू);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetdcwd(पूर्णाङ्क _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क Size_In_शब्दहरू);
  ब_अक्षर_प्रकार *__cdecl _wgetdcwd_nolock(पूर्णाङ्क _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क Size_In_शब्दहरू);
  _CRTIMP पूर्णाङ्क __cdecl _wchdir(अचर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wmkdir(अचर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wrmdir(अचर ब_अक्षर_प्रकार *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP पूर्णाङ्क __cdecl _waccess(अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _AccessMode);
  _CRTIMP पूर्णाङ्क __cdecl _wchmod(अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _Mode);
  _CRTIMP पूर्णाङ्क __cdecl _wcreat(अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(अचर ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32(intptr_t _FindHandle,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wunlink(अचर ब_अक्षर_प्रकार *_Filename);
  _CRTIMP पूर्णाङ्क __cdecl _wrename(अचर ब_अक्षर_प्रकार *_NewFilename,अचर ब_अक्षर_प्रकार *_OldFilename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wmktemp(ब_अक्षर_प्रकार *_TemplateName);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(अचर ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(अचर ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(अचर ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata64_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32i64(intptr_t _FindHandle,संरचना _wfinddata32i64_t *_FindData);
  पूर्णाङ्क __cdecl _wfindnext64i32(intptr_t _FindHandle,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext64(intptr_t _FindHandle,संरचना _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णाङ्क *_FileHandle,अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionFlag);
#यदि !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क __cdecl _wopen(अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _OpenFlag,...);
  _CRTIMP पूर्णाङ्क __cdecl _wsopen(अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wopen(अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wsopen(अचर ब_अक्षर_प्रकार *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wsetlocale(पूर्णाङ्क _Category,अचर ब_अक्षर_प्रकार *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList,अचर ब_अक्षर_प्रकार *अचर *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList,अचर ब_अक्षर_प्रकार *अचर *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList,अचर ब_अक्षर_प्रकार *अचर *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(पूर्णाङ्क _Mode,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *अचर *_ArgList,अचर ब_अक्षर_प्रकार *अचर *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(अचर ब_अक्षर_प्रकार *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#यदि !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define iswascii(_c) ((अचिन्हित)(_c) < 0x80)

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
#define isleadbyte(_c) (__PCTYPE_FUNC[(अचिन्हित वर्ण)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#यदि !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  प्रकारनिर्देश अचिन्हित लघु _ino_t;
#ifndef	NO_OLDNAMES
  प्रकारनिर्देश अचिन्हित लघु ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क _dev_t;
#ifndef	NO_OLDNAMES
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  प्रकारनिर्देश दीर्घ _off_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  प्रकारनिर्देश दीर्घ दीर्घ _off64_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ दीर्घ off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#अन्यथा
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#अन्यथा
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
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
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
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    समय_प्रकार st_atime;
    समय_प्रकार st_mtime;
    समय_प्रकार st_ctime;
  };
#endif

#यदि _INTEGRAL_MAX_BITS >= 64

  संरचना _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  संरचना _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  संरचना _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
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

  _CRTIMP पूर्णाङ्क __cdecl _wstat32(अचर ब_अक्षर_प्रकार *_Name,संरचना _stat32 *_Stat);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णाङ्क __cdecl _wstat32i64(अचर ब_अक्षर_प्रकार *_Name,संरचना _stat32i64 *_Stat);
  पूर्णाङ्क __cdecl _wstat64i32(अचर ब_अक्षर_प्रकार *_Name,संरचना _stat64i32 *_Stat);
  _CRTIMP पूर्णाङ्क __cdecl _wstat64(अचर ब_अक्षर_प्रकार *_Name,संरचना _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP ब_अक्षर_प्रकार *_cgetws(ब_अक्षर_प्रकार *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(शून्य);
  _CRTIMP wint_t __cdecl _getwche(शून्य);
  _CRTIMP wint_t __cdecl _putwch(ब_अक्षर_प्रकार _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP पूर्णाङ्क __cdecl _cputws(अचर ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);

  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  wint_t __cdecl _putwch_nolock(ब_अक्षर_प्रकार _WCh);
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
  _CRTIMP खाता *__cdecl _wfsopen(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _wfsopen(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Mode,पूर्णाङ्क _ShFlag);
#endif

  wint_t __cdecl fgetwc(खाता *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(शून्य);
  wint_t __cdecl fputwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _fputwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl getwc(खाता *_File);
  wint_t __cdecl getwchar(शून्य);
  wint_t __cdecl putwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  wint_t __cdecl putwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,खाता *_File);
  ब_अक्षर_प्रकार *__cdecl fgetws(ब_अक्षर_प्रकार *_Dst,पूर्णाङ्क Size_In_शब्दहरू,खाता *_File);
  पूर्णाङ्क __cdecl fputws(अचर ब_अक्षर_प्रकार *_Str,खाता *_File);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws(ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णाङ्क __cdecl _putws(अचर ब_अक्षर_प्रकार *_Str);
  पूर्णाङ्क __cdecl fwprintf(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl wprintf(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf(अचर ब_अक्षर_प्रकार *_Format,...);
  पूर्णाङ्क __cdecl vfwprintf(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl vwprintf(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl swprintf(ब_अक्षर_प्रकार*, अचर ब_अक्षर_प्रकार*, ...);
  _CRTIMP पूर्णाङ्क __cdecl vswprintf(ब_अक्षर_प्रकार*, अचर ब_अक्षर_प्रकार*,बहु_सूची);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार गन्ती_5,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार गन्ती_5,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णाङ्क __cdecl snwprintf (ब_अक्षर_प्रकार *s, माप_प्रकार n, अचर ब_अक्षर_प्रकार * format, ...);
  __CRT_INLINE पूर्णाङ्क __cdecl vsnwprintf (ब_अक्षर_प्रकार *s, माप_प्रकार n, अचर ब_अक्षर_प्रकार *format, बहु_सूची arg) { फर्काऊ _vsnwprintf(s,n,format,arg); }
  पूर्णाङ्क __cdecl vwscanf (अचर ब_अक्षर_प्रकार *, बहु_सूची);
  पूर्णाङ्क __cdecl vfwscanf (खाता *,अचर ब_अक्षर_प्रकार *,बहु_सूची);
  पूर्णाङ्क __cdecl vswscanf (अचर ब_अक्षर_प्रकार *,अचर ब_अक्षर_प्रकार *,बहु_सूची);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);
  _CRTIMP पूर्णाङ्क __cdecl __swprintf_l(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,...);
  _CRTIMP पूर्णाङ्क __cdecl __vswprintf_l(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,बहु_सूची _Args);
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

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtempnam(अचर ब_अक्षर_प्रकार *_Directory,अचर ब_अक्षर_प्रकार *_FilePrefix);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf(अचर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  पूर्णाङ्क __cdecl fwscanf(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_l(खाता *_File,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl swscanf(अचर ब_अक्षर_प्रकार *_Src,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_l(अचर ब_अक्षर_प्रकार *_Src,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf(अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_l(अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती,अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl wscanf(अचर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_l(अचर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP खाता *__cdecl _wfdopen(पूर्णाङ्क _FileHandle ,अचर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfopen(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfreopen(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(अचर ब_अक्षर_प्रकार *Err_सन्देश);
#endif
  _CRTIMP खाता *__cdecl _wpopen(अचर ब_अक्षर_प्रकार *_Command,अचर ब_अक्षर_प्रकार *_Mode);
#यदि !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP पूर्णाङ्क __cdecl _wremove(अचर ब_अक्षर_प्रकार *_Filename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtmpnam(ब_अक्षर_प्रकार *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(खाता *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,खाता *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#यदि !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(मानक_निवेश)
#define putwchar(_c) fputwc((_c),मानक_निकास)
#अन्यथा
  __CRT_INLINE wint_t __cdecl getwchar() {फर्काऊ (fgetwc(मानक_निवेश)); }
  __CRT_INLINE wint_t __cdecl putwchar(ब_अक्षर_प्रकार _C) {फर्काऊ (fputwc(_C,मानक_निकास)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _itow(पूर्णाङ्क मान_2,ब_अक्षर_प्रकार *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ltow(दीर्घ मान_2,ब_अक्षर_प्रकार *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ultow(अचिन्हित दीर्घ मान_2,ब_अक्षर_प्रकार *_Dest,पूर्णाङ्क _Radix);
  द्विगुण __cdecl wcstod(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr);
  _CRTIMP द्विगुण __cdecl _wcstod_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,_locale_t _Locale);
  भिन्न __cdecl wcstof( अचर ब_अक्षर_प्रकार *nptr, ब_अक्षर_प्रकार **endptr);
#यदि !defined __NO_ISOCEXT /* in libmingwex.a */
  भिन्न __cdecl wcstof (अचर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
  दीर्घ द्विगुण __cdecl wcstold (अचर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
#endif /* __NO_ISOCEXT */
  दीर्घ __cdecl wcstol(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP दीर्घ __cdecl _wcstol_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl wcstoul(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _wcstoul_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetenv(अचर ब_अक्षर_प्रकार *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(अचर ब_अक्षर_प्रकार *_Command);
#endif
  _CRTIMP द्विगुण __cdecl _wtof(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP द्विगुण __cdecl _wtof_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP दीर्घ __cdecl _wtol(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP दीर्घ __cdecl _wtol_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);

#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _i64tow(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ui64tow(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(अचर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64_l(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णाङ्क _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wfullpath(ब_अक्षर_प्रकार *_FullPath,अचर ब_अक्षर_प्रकार *_Path,माप_प्रकार Size_In_शब्दहरू);
  _CRTIMP शून्य __cdecl _wmakepath(ब_अक्षर_प्रकार *_ResultPath,अचर ब_अक्षर_प्रकार *_Drive,अचर ब_अक्षर_प्रकार *_Dir,अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(अचर ब_अक्षर_प्रकार *Err_सन्देश);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _wputenv(अचर ब_अक्षर_प्रकार *_EnvString);
  _CRTIMP शून्य __cdecl _wsearchenv(अचर ब_अक्षर_प्रकार *_Filename,अचर ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *_ResultPath);
  _CRTIMP शून्य __cdecl _wsplitpath(अचर ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,ब_अक्षर_प्रकार *_Dir,ब_अक्षर_प्रकार *_Filename,ब_अक्षर_प्रकार *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsdup(अचर ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcscat(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcschr(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  पूर्णाङ्क __cdecl wcscmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  ब_अक्षर_प्रकार *__cdecl wcscpy(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source);
  माप_प्रकार __cdecl wcscspn(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Control);
  माप_प्रकार __cdecl wcslen(अचर ब_अक्षर_प्रकार *_Str);
  माप_प्रकार __cdecl wcsnlen(अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *__cdecl wcsncat(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source,माप_प्रकार गन्ती_5);
  पूर्णाङ्क __cdecl wcsncmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *__cdecl wcsncpy(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source,माप_प्रकार गन्ती_5);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcspbrk(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsrchr(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  माप_प्रकार __cdecl wcsspn(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsstr(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_SubStr);
  ब_अक्षर_प्रकार *__cdecl wcstok(ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Delim);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcserror(पूर्णाङ्क Err_अङ्क);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl __wcserror(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गन्ती);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsrev(ब_अक्षर_प्रकार *_Str);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcslwr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcslwr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsupr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcsupr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  माप_प्रकार __cdecl wcsxfrm(ब_अक्षर_प्रकार *_Dst,अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती);
  _CRTIMP माप_प्रकार __cdecl _wcsxfrm_l(ब_अक्षर_प्रकार *_Dst,अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  पूर्णाङ्क __cdecl wcscoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcscoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  ब_अक्षर_प्रकार *__cdecl wcsdup(अचर ब_अक्षर_प्रकार *_Str);
#define wcswcs wcsstr
  पूर्णाङ्क __cdecl wcsicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  पूर्णाङ्क __cdecl wcsnicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *__cdecl wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *__cdecl wcsrev(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  ब_अक्षर_प्रकार *__cdecl wcslwr(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsupr(ब_अक्षर_प्रकार *_Str);
  पूर्णाङ्क __cdecl wcsicoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  संरचना पंचांग {
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

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wasctime(अचर संरचना पंचांग *_Tm);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime32(अचर __time32_t *_Time);
  माप_प्रकार __cdecl wcsftime(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,अचर संरचना पंचांग *_Tm);
  _CRTIMP माप_प्रकार __cdecl _wcsftime_l(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *_Format,अचर संरचना पंचांग *_Tm,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrdate(ब_अक्षर_प्रकार *_Buffer);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrtime(ब_अक्षर_प्रकार *_Buffer);
#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime64(अचर __time64_t *_Time);
#endif

#यदि !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(अचर समय_प्रकार *_Time) { फर्काऊ _wctime32(_Time); }
#अन्यथा
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(अचर समय_प्रकार *_Time) { फर्काऊ _wctime64(_Time); }
#endif
#endif
#endif

  प्रकारनिर्देश पूर्णाङ्क mbstate_t;
  प्रकारनिर्देश ब_अक्षर_प्रकार _Wint_t;

  wint_t __cdecl btowc(पूर्णाङ्क);
  माप_प्रकार __cdecl mbrlen(अचर वर्ण *_Ch,माप_प्रकार _SizeInBytes,mbstate_t *_State);
  माप_प्रकार __cdecl mbrtowc(ब_अक्षर_प्रकार *_DstCh,अचर वर्ण *_SrcCh,माप_प्रकार _SizeInBytes,mbstate_t *_State);
  माप_प्रकार __cdecl mbsrtowcs(ब_अक्षर_प्रकार *_Dest,अचर वर्ण **_PSrc,माप_प्रकार गन्ती_5,mbstate_t *_State);
  माप_प्रकार __cdecl wcrtomb(वर्ण *_Dest,ब_अक्षर_प्रकार _Source,mbstate_t *_State);
  माप_प्रकार __cdecl wcsrtombs(वर्ण *_Dest,अचर ब_अक्षर_प्रकार **_PSource,माप_प्रकार गन्ती_5,mbstate_t *_State);
  पूर्णाङ्क __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  ब_अक्षर_प्रकार *__cdecl wmemset(ब_अक्षर_प्रकार *s, ब_अक्षर_प्रकार c, माप_प्रकार n);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wmemchr(अचर ब_अक्षर_प्रकार *s, ब_अक्षर_प्रकार c, माप_प्रकार n);
  पूर्णाङ्क wmemcmp(अचर ब_अक्षर_प्रकार *s1, अचर ब_अक्षर_प्रकार *s2,माप_प्रकार n);
  ब_अक्षर_प्रकार *__cdecl wmemcpy(ब_अक्षर_प्रकार *s1,अचर ब_अक्षर_प्रकार *s2,माप_प्रकार n);
  ब_अक्षर_प्रकार *__cdecl wmemmove(ब_अक्षर_प्रकार *s1, अचर ब_अक्षर_प्रकार *s2, माप_प्रकार n);
  दीर्घ दीर्घ __cdecl wcstoll(अचर ब_अक्षर_प्रकार *nptr,ब_अक्षर_प्रकार **endptr, पूर्णाङ्क base);
  अचिन्हित दीर्घ दीर्घ __cdecl wcstoull(अचर ब_अक्षर_प्रकार *nptr,ब_अक्षर_प्रकार **endptr, पूर्णाङ्क base);
#endif /* __NO_ISOCEXT */

  शून्य *__cdecl स_हटाओ(शून्य *_Dst,अचर शून्य *_Src,माप_प्रकार Max_गन्ती);
  शून्य *__cdecl स_नकल(शून्य *_Dst,अचर शून्य *_Src,माप_प्रकार Max_गन्ती);
  __CRT_INLINE पूर्णाङ्क __cdecl fwide(खाता *_F,पूर्णाङ्क _M) { (शून्य)_F; फर्काऊ (_M); }
  __CRT_INLINE पूर्णाङ्क __cdecl mbsinit(अचर mbstate_t *_P) { फर्काऊ (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wmemchr(अचर ब_अक्षर_प्रकार *_S,ब_अक्षर_प्रकार _C,माप_प्रकार _N) { लागि (;0<_N;++_S,--_N) यदि (*_S==_C) फर्काऊ (_CONST_RETURN ब_अक्षर_प्रकार *)(_S); फर्काऊ (0); }
  __CRT_INLINE पूर्णाङ्क __cdecl wmemcmp(अचर ब_अक्षर_प्रकार *_S1,अचर ब_अक्षर_प्रकार *_S2,माप_प्रकार _N) { लागि (; 0 < _N; ++_S1,++_S2,--_N) यदि (*_S1!=*_S2) फर्काऊ (*_S1 < *_S2 ? -1 : +1); फर्काऊ (0); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl wmemcpy(ब_अक्षर_प्रकार *_S1,अचर ब_अक्षर_प्रकार *_S2,माप_प्रकार _N) { फर्काऊ (ब_अक्षर_प्रकार *)स_नकल(_S1,_S2,_N*परिमाण(ब_अक्षर_प्रकार)); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl wmemmove(ब_अक्षर_प्रकार *_S1,अचर ब_अक्षर_प्रकार *_S2,माप_प्रकार _N) { फर्काऊ (ब_अक्षर_प्रकार *)स_हटाओ(_S1,_S2,_N*परिमाण(ब_अक्षर_प्रकार)); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl wmemset(ब_अक्षर_प्रकार *_S,ब_अक्षर_प्रकार _C,माप_प्रकार _N) {
    ब_अक्षर_प्रकार *_Su = _S;
    लागि (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    फर्काऊ (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(झिक)

#अन्तर्भाव <sec_api/wchar_s.h>
#endif
