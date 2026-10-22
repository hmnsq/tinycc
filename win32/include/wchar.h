/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef WCHAR_MIN  /* also at stdint.h */
#define WCHAR_MIN 0
#define WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __gnuc_va_list va_list;
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _FILE_DEFINED
  ସଂରଚନା _iobuf {
    ଅକ୍ଷର *_ptr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _cnt;
    ଅକ୍ଷର *_base;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _flag;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _file;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _charbuf;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _bufsiz;
    ଅକ୍ଷର *_tmpfname;
  };
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ଶୂନ୍ୟ);
#ଅନ୍ୟଥା
#ifdef _MSVCRT_
ବାହ୍ୟ FILE _iob[];	/* A pointer to an array of FILE */
#define __iob_func()	(_iob)
#ଅନ୍ୟଥା
ବାହ୍ୟ FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
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
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  ସଂରଚନା _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ସଂରଚନା _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ସଂରଚନା _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ସଂରଚନା _wfinddata64_t {
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
#ଅନ୍ୟଥା
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef ଖାଲି
#ifdef __cplusplus
#define ଖାଲି 0
#ଅନ୍ୟଥା
#define ଖାଲି ((ଶୂନ୍ୟ *)0)
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
#ଅନ୍ୟଥା
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned short *_pctype;
#ଅନ୍ୟଥା
  ବାହ୍ୟ unsigned short **_imp___pctype;
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
  ବାହ୍ୟ unsigned short *_wctype;
#ଅନ୍ୟଥା
  ବାହ୍ୟ unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#ଅନ୍ୟଥା
#define __pwctype_func() (*_imp___pwctype)
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned short *_pwctype;
#ଅନ୍ୟଥା
  ବାହ୍ୟ unsigned short **_imp___pwctype;
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

  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswalpha(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswupper(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswlower(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswdigit(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswxdigit(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswspace(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswpunct(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswalnum(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswprint(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswgraph(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswcntrl(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswascii(wint_t _C);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isleadbyte(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isleadbyte_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __iswcsymf(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __iswcsym(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Drive,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  wchar_t *__cdecl _wgetdcwd_nolock(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Drive,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wchdir(ଅଚଳ wchar_t *_Path);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wmkdir(ଅଚଳ wchar_t *_Path);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wrmdir(ଅଚଳ wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _waccess(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _AccessMode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wchmod(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcreat(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext32(intptr_t _FindHandle,ସଂରଚନା _wfinddata32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wunlink(ଅଚଳ wchar_t *_Filename);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wrename(ଅଚଳ wchar_t *_NewFilename,ଅଚଳ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata64_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext32i64(intptr_t _FindHandle,ସଂରଚନା _wfinddata32i64_t *_FindData);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext64i32(intptr_t _FindHandle,ସଂରଚନା _wfinddata64i32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext64(intptr_t _FindHandle,ସଂରଚନା _wfinddata64_t *_FindData);
#endif
  _CRTIMP errno_t __cdecl _wsopen_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_FileHandle,ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionFlag);
#ଯଦି !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,...);
#ଅନ୍ୟଥା
  ବାହ୍ୟ "C++" _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode = 0);
  ବାହ୍ୟ "C++" _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode = 0);
#endif
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Category,ଅଚଳ wchar_t *_Locale);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsystem(ଅଚଳ wchar_t *_Command);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#ଯଦି !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
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
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned ଅକ୍ଷର)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#ଯଦି !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _dev_t;
#ifndef	NO_OLDNAMES
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା dev_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long _off_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long _off64_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long off64_t;
#endif
#endif

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifdef WIN64
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#ଅନ୍ୟଥା
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#ଅନ୍ୟଥା
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64i32
#define _stati64 _stat64
#define _wstat _wstat64i32
#define _wstati64 _wstat64
#endif

  ସଂରଚନା _stat32 {
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
  ସଂରଚନା stat {
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

#ଯଦି _INTEGRAL_MAX_BITS >= 64

  ସଂରଚନା _stat32i64 {
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

  ସଂରଚନା _stat64i32 {
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

  ସଂରଚନା _stat64 {
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

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wstat32(ଅଚଳ wchar_t *_Name,ସଂରଚନା _stat32 *_Stat);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wstat32i64(ଅଚଳ wchar_t *_Name,ସଂରଚନା _stat32i64 *_Stat);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wstat64i32(ଅଚଳ wchar_t *_Name,ସଂରଚନା _stat64i32 *_Stat);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wstat64(ଅଚଳ wchar_t *_Name,ସଂରଚନା _stat64 *_Stat);
#endif
#endif
#endif

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(ଶୂନ୍ୟ);
  _CRTIMP wint_t __cdecl _getwche(ଶୂନ୍ୟ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cputws(ଅଚଳ wchar_t *_String);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwscanf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwscanf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_p(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_p(ଅଚଳ wchar_t *_Format,va_list _ArgList);

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(ଶୂନ୍ୟ);
  wint_t __cdecl _getwche_nolock(ଶୂନ୍ୟ);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef _WSTDIO_DEFINED
#define _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode);
#ଅନ୍ୟଥା
  _CRTIMP FILE *__cdecl _wfsopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShFlag);
#endif

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ଶୂନ୍ୟ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ଶୂନ୍ୟ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ,FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fputws(ଅଚଳ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _putws(ଅଚଳ wchar_t *_Str);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fwprintf(FILE *_File,ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wprintf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf(ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vfwprintf(FILE *_File,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vwprintf(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl swprintf(wchar_t*, ଅଚଳ wchar_t*, ...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vswprintf(wchar_t*, ଅଚଳ wchar_t*,va_list);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwprintf(wchar_t *_Dest,size_t ଗଣନା_6,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnwprintf(wchar_t *_Dest,size_t ଗଣନା_6,ଅଚଳ wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl snwprintf (wchar_t *s, size_t n, ଅଚଳ wchar_t * format, ...);
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsnwprintf (wchar_t *s, size_t n, ଅଚଳ wchar_t *format, va_list arg) { ଫେରନ୍ତୁ _vsnwprintf(s,n,format,arg); }
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vwscanf (ଅଚଳ wchar_t *, va_list);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vfwscanf (FILE *,ଅଚଳ wchar_t *,va_list);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vswscanf (ଅଚଳ wchar_t *,ଅଚଳ wchar_t *,va_list);
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwprintf_p(FILE *_File,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wprintf_p(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfwprintf_p(FILE *_File,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vwprintf_p(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_p(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf_p(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf_p(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwprintf_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwprintf_p_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfwprintf_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vfwprintf_p_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,va_list _Args);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __swprintf_l(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __vswprintf_l(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#ifndef RC_INVOKED
#ଅନ୍ତର୍ଭାଵ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ଅଚଳ wchar_t *_Directory,ଅଚଳ wchar_t *_FilePrefix);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fwscanf(FILE *_File,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fwscanf_l(FILE *_File,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl swscanf(ଅଚଳ wchar_t *_Src,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swscanf_l(ଅଚଳ wchar_t *_Src,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwscanf(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwscanf_l(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wscanf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wscanf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle ,ଅଚଳ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode,FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ଶୂନ୍ୟ __cdecl _wperror(ଅଚଳ wchar_t *Err_ସନ୍ଦେଶ);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ଅଚଳ wchar_t *_Command,ଅଚଳ wchar_t *_Mode);
#ଯଦି !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen	_wpopen
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wremove(ଅଚଳ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#ଯଦି !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#ଅନ୍ୟଥା
  __CRT_INLINE wint_t __cdecl getwchar() {ଫେରନ୍ତୁ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {ଫେରନ୍ତୁ (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_c) _fgetwc_nolock(_c)
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2,wchar_t *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long ମୂଲ୍ୟ_2,wchar_t *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long ମୂଲ୍ୟ_2,wchar_t *_Dest,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  ଦ୍ୱିଗୁଣ __cdecl wcstod(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _wcstod_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  ଦଶମିକ __cdecl wcstof( ଅଚଳ wchar_t *nptr, wchar_t **endptr);
#ଯଦି !defined __NO_ISOCEXT /* in libmingwex.a */
  ଦଶମିକ __cdecl wcstof (ଅଚଳ wchar_t * __restrict__, wchar_t ** __restrict__);
  long ଦ୍ୱିଗୁଣ __cdecl wcstold (ଅଚଳ wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  long __cdecl wcstol(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP long __cdecl _wcstol_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ଅଚଳ wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsystem(ଅଚଳ wchar_t *_Command);
#endif
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _wtof(ଅଚଳ wchar_t *_Str);
  _CRTIMP ଦ୍ୱିଗୁଣ __cdecl _wtof_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wtoi(ଅଚଳ wchar_t *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wtoi_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(ଅଚଳ wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ଅଚଳ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ଅଚଳ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(ଅଚଳ wchar_t *_Str,wchar_t **_EndPtr,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,ଅଚଳ wchar_t *_Path,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP ଶୂନ୍ୟ __cdecl _wmakepath(wchar_t *_ResultPath,ଅଚଳ wchar_t *_Drive,ଅଚଳ wchar_t *_Dir,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ଶୂନ୍ୟ __cdecl _wperror(ଅଚଳ wchar_t *Err_ସନ୍ଦେଶ);
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wputenv(ଅଚଳ wchar_t *_EnvString);
  _CRTIMP ଶୂନ୍ୟ __cdecl _wsearchenv(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP ଶୂନ୍ୟ __cdecl _wsplitpath(ଅଚଳ wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ଅଚଳ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ଅଚଳ wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ଅଚଳ wchar_t *_Str,wchar_t _Ch);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcscmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ଅଚଳ wchar_t *_Source);
  size_t __cdecl wcscspn(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_Control);
  size_t __cdecl wcslen(ଅଚଳ wchar_t *_Str);
  size_t __cdecl wcsnlen(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ଅଚଳ wchar_t *_Source,size_t ଗଣନା_6);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsncmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ଅଚଳ wchar_t *_Source,size_t ଗଣନା_6);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ଅଚଳ wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ଅଚଳ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(ପୂର୍ଣ୍ଣସଂଖ୍ୟା Err_ଅଙ୍କ);
  _CRTIMP wchar_t *__cdecl __wcserror(ଅଚଳ wchar_t *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicmp_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicmp_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ଗଣନା);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcscoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcscoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsncoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsncoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ଅଚଳ wchar_t *_Str);
#define wcswcs wcsstr
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsnicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ଗଣନା);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsicoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  ସଂରଚନା tm {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_sec;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_min;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_hour;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_mday;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_mon;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_year;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_wday;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_yday;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ଅଚଳ ସଂରଚନା tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ଅଚଳ __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,ଅଚଳ ସଂରଚନା tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,ଅଚଳ ସଂରଚନା tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ଅଚଳ __time64_t *_Time);
#endif

#ଯଦି !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _wctime32(_Time); }
#ଅନ୍ୟଥା
__CRT_INLINE wchar_t *__cdecl _wctime(ଅଚଳ time_t *_Time) { ଫେରନ୍ତୁ _wctime64(_Time); }
#endif
#endif
#endif

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା mbstate_t;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା wchar_t _Wint_t;

  wint_t __cdecl btowc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  size_t __cdecl mbrlen(ଅଚଳ ଅକ୍ଷର *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,ଅଚଳ ଅକ୍ଷର *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,ଅଚଳ ଅକ୍ଷର **_PSrc,size_t ଗଣନା_6,mbstate_t *_State);
  size_t __cdecl wcrtomb(ଅକ୍ଷର *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(ଅକ୍ଷର *_Dest,ଅଚଳ wchar_t **_PSource,size_t ଗଣନା_6,mbstate_t *_State);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ଅଚଳ wchar_t *s, wchar_t c, size_t n);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା wmemcmp(ଅଚଳ wchar_t *s1, ଅଚଳ wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ଅଚଳ wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ଅଚଳ wchar_t *s2, size_t n);
  long long __cdecl wcstoll(ଅଚଳ wchar_t *nptr,wchar_t **endptr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା base);
  unsigned long long __cdecl wcstoull(ଅଚଳ wchar_t *nptr,wchar_t **endptr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା base);
#endif /* __NO_ISOCEXT */

  ଶୂନ୍ୟ *__cdecl memmove(ଶୂନ୍ୟ *_Dst,ଅଚଳ ଶୂନ୍ୟ *_Src,size_t Max_ଗଣନା);
  ଶୂନ୍ୟ *__cdecl memcpy(ଶୂନ୍ୟ *_Dst,ଅଚଳ ଶୂନ୍ୟ *_Src,size_t Max_ଗଣନା);
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fwide(FILE *_F,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _M) { (ଶୂନ୍ୟ)_F; ଫେରନ୍ତୁ (_M); }
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl mbsinit(ଅଚଳ mbstate_t *_P) { ଫେରନ୍ତୁ (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ଅଚଳ wchar_t *_S,wchar_t _C,size_t _N) { ପାଇଁ (;0<_N;++_S,--_N) ଯଦି (*_S==_C) ଫେରନ୍ତୁ (_CONST_RETURN wchar_t *)(_S); ଫେରନ୍ତୁ (0); }
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wmemcmp(ଅଚଳ wchar_t *_S1,ଅଚଳ wchar_t *_S2,size_t _N) { ପାଇଁ (; 0 < _N; ++_S1,++_S2,--_N) ଯଦି (*_S1!=*_S2) ଫେରନ୍ତୁ (*_S1 < *_S2 ? -1 : +1); ଫେରନ୍ତୁ (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ଅଚଳ wchar_t *_S2,size_t _N) { ଫେରନ୍ତୁ (wchar_t *)memcpy(_S1,_S2,_N*ଆକାର(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ଅଚଳ wchar_t *_S2,size_t _N) { ଫେରନ୍ତୁ (wchar_t *)memmove(_S1,_S2,_N*ଆକାର(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    ପାଇଁ (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    ଫେରନ୍ତୁ (_S);
  }
#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)

#ଅନ୍ତର୍ଭାଵ <sec_api/wchar_s.h>
#endif
