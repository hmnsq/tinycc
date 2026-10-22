/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_WCHAR
#परिभाषय _INC_WCHAR

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् WCHAR_MIN  /* also at stdint.h */
#परिभाषय WCHAR_MIN 0
#परिभाषय WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#यदि_अन्तः

#यदि_अपरिभाषितम् __GNUC_VA_LIST
#परिभाषय __GNUC_VA_LIST
  प्रकारनिर्देश __builtin_va_list __gnuc_va_list;
#यदि_अन्तः

#यदि_अपरिभाषितम् _VA_LIST_DEFINED
#परिभाषय _VA_LIST_DEFINED
  प्रकारनिर्देश __gnuc_va_list va_list;
#यदि_अन्तः

#यदि_अपरिभाषितम् WEOF
#परिभाषय WEOF (wint_t)(0xFFFF)
#यदि_अन्तः

#यदि_अपरिभाषितम् _FILE_DEFINED
  संरचना _iobuf {
    वर्ण *_ptr;
    पूर्णाङ्क _cnt;
    वर्ण *आधारः_4;
    पूर्णाङ्क _flag;
    पूर्णाङ्क _file;
    पूर्णाङ्क _charbuf;
    पूर्णाङ्क _bufsiz;
    वर्ण *_tmpfname;
  };
  प्रकारनिर्देश संरचना _iobuf FILE;
#परिभाषय _FILE_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _STDIO_DEFINED
#यदि_परिभाषितम् _WIN64
  _CRTIMP FILE *__cdecl __iob_func(शून्य);
#अन्यथा
#यदि_परिभाषितम् _MSVCRT_
बाह्य FILE _iob[];	/* A pointer to an array of FILE */
#परिभाषय __iob_func()	(_iob)
#अन्यथा
बाह्य FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#परिभाषय __iob_func()	(*_imp___iob)
#परिभाषय _iob __iob_func()
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _iob __iob_func()
#यदि_अन्तः

#यदि_अपरिभाषितम् _STDSTREAM_DEFINED
#परिभाषय stdin (&__iob_func()[0])
#परिभाषय stdout (&__iob_func()[1])
#परिभाषय stderr (&__iob_func()[2])
#परिभाषय _STDSTREAM_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _FSIZE_T_DEFINED
  प्रकारनिर्देश अचिह्नित दीर्घ _fsize_t;
#परिभाषय _FSIZE_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _WFINDDATA_T_DEFINED
  संरचना _wfinddata32_t {
    अचिह्नित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t आकार;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  संरचना _wfinddata32i64_t {
    अचिह्नित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 आकार;
    wchar_t name[260];
  };

  संरचना _wfinddata64i32_t {
    अचिह्नित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t आकार;
    wchar_t name[260];
  };

  संरचना _wfinddata64_t {
    अचिह्नित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 आकार;
    wchar_t name[260];
  };
/* #endif */

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#परिभाषय _wfinddata_t _wfinddata32_t
#परिभाषय _wfinddatai64_t _wfinddata32i64_t

#परिभाषय _wfindfirst _wfindfirst32
#परिभाषय _wfindnext _wfindnext32
#परिभाषय _wfindfirsti64 _wfindfirst32i64
#परिभाषय _wfindnexti64 _wfindnext32i64
#अन्यथा
#परिभाषय _wfinddata_t _wfinddata64i32_t
#परिभाषय _wfinddatai64_t _wfinddata64_t

#परिभाषय _wfindfirst _wfindfirst64i32
#परिभाषय _wfindnext _wfindnext64i32
#परिभाषय _wfindfirsti64 _wfindfirst64
#परिभाषय _wfindnexti64 _wfindnext64
#यदि_अन्तः

#परिभाषय _WFINDDATA_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _CONST_RETURN
#परिभाषय _CONST_RETURN
#यदि_अन्तः

#परिभाषय _WConst_return _CONST_RETURN

#यदि_अपरिभाषितम् _CRT_CTYPEDATA_DEFINED
#परिभाषय _CRT_CTYPEDATA_DEFINED
#यदि_अपरिभाषितम् _CTYPE_DISABLE_MACROS

#यदि_अपरिभाषितम् __PCTYPE_FUNC
#परिभाषय __PCTYPE_FUNC __pctype_func()
#यदि_परिभाषितम् _MSVCRT_
#परिभाषय __pctype_func() (_pctype)
#अन्यथा
#परिभाषय __pctype_func() (*_imp___pctype)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _pctype
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित ह्रस्व *_pctype;
#अन्यथा
  बाह्य अचिह्नित ह्रस्व **_imp___pctype;
#परिभाषय _pctype (*_imp___pctype)
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRT_WCTYPEDATA_DEFINED
#परिभाषय _CRT_WCTYPEDATA_DEFINED
#यदि_अपरिभाषितम् _CTYPE_DISABLE_MACROS
#यदि_अपरिभाषितम् _wctype
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित ह्रस्व *_wctype;
#अन्यथा
  बाह्य अचिह्नित ह्रस्व **_imp___wctype;
#परिभाषय _wctype (*_imp___wctype)
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् _MSVCRT_
#परिभाषय __pwctype_func() (_pwctype)
#अन्यथा
#परिभाषय __pwctype_func() (*_imp___pwctype)
#यदि_अन्तः

#यदि_अपरिभाषितम् _pwctype
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित ह्रस्व *_pwctype;
#अन्यथा
  बाह्य अचिह्नित ह्रस्व **_imp___pwctype;
#परिभाषय _pwctype (*_imp___pwctype)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः

#परिभाषय ऊर्ध्वस्थम्_3 0x1
#परिभाषय अधस्तनम्_2 0x2
#परिभाषय _DIGIT 0x4
#परिभाषय _SPACE 0x8

#परिभाषय _PUNCT 0x10
#परिभाषय _CONTROL 0x20
#परिभाषय _BLANK 0x40
#परिभाषय _HEX 0x80

#परिभाषय _LEADBYTE 0x8000
#परिभाषय _ALPHA (0x0100|ऊर्ध्वस्थम्_3|अधस्तनम्_2)

#यदि_अपरिभाषितम् _WCTYPE_DEFINED
#परिभाषय _WCTYPE_DEFINED

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
#यदि_अन्तः

#यदि_अपरिभाषितम् _WDIRECT_DEFINED
#परिभाषय _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,पूर्णाङ्क आकार_अन्तर्_शब्दाः);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क आकार_अन्तर्_शब्दाः);
  wchar_t *__cdecl _wgetdcwd_nolock(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क आकार_अन्तर्_शब्दाः);
  _CRTIMP पूर्णाङ्क __cdecl _wchdir(ध्रुव wchar_t *मार्गः_2);
  _CRTIMP पूर्णाङ्क __cdecl _wmkdir(ध्रुव wchar_t *मार्गः_2);
  _CRTIMP पूर्णाङ्क __cdecl _wrmdir(ध्रुव wchar_t *मार्गः_2);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WIO_DEFINED
#परिभाषय _WIO_DEFINED

  _CRTIMP पूर्णाङ्क __cdecl _waccess(ध्रुव wchar_t *_Filename,पूर्णाङ्क Access_बहुलकम्);
  _CRTIMP पूर्णाङ्क __cdecl _wchmod(ध्रुव wchar_t *_Filename,पूर्णाङ्क बहुलकम्_3);
  _CRTIMP पूर्णाङ्क __cdecl _wcreat(ध्रुव wchar_t *_Filename,पूर्णाङ्क Permission_बहुलकम्);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ध्रुव wchar_t *_Filename,संरचना _wfinddata32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32(intptr_t _FindHandle,संरचना _wfinddata32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wunlink(ध्रुव wchar_t *_Filename);
  _CRTIMP पूर्णाङ्क __cdecl _wrename(ध्रुव wchar_t *_NewFilename,ध्रुव wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ध्रुव wchar_t *_Filename,संरचना _wfinddata32i64_t *Find_दत्त);
  intptr_t __cdecl _wfindfirst64i32(ध्रुव wchar_t *_Filename,संरचना _wfinddata64i32_t *Find_दत्त);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ध्रुव wchar_t *_Filename,संरचना _wfinddata64_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32i64(intptr_t _FindHandle,संरचना _wfinddata32i64_t *Find_दत्त);
  पूर्णाङ्क __cdecl _wfindnext64i32(intptr_t _FindHandle,संरचना _wfinddata64i32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext64(intptr_t _FindHandle,संरचना _wfinddata64_t *Find_दत्त);
#यदि_अन्तः
  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णाङ्क *_FileHandle,ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionFlag);
#यदि !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,...);
  _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क Permission_बहुलकम् = 0);
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क Permission_बहुलकम् = 0);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WLOCALE_DEFINED
#परिभाषय _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(पूर्णाङ्क _Category,ध्रुव wchar_t *_Locale);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WPROCESS_DEFINED
#परिभाषय _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
#यदि_अपरिभाषितम् _CRT_WSYSTEM_DEFINED
#परिभाषय _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(ध्रुव wchar_t *_Command);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCTYPE_INLINE_DEFINED
#अपरिभाषय _CRT_WCTYPE_NOINLINE
#यदि !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#परिभाषय iswalpha(_c) (iswctype(_c,_ALPHA))
#परिभाषय iswupper(_c) (iswctype(_c,ऊर्ध्वस्थम्_3))
#परिभाषय iswlower(_c) (iswctype(_c,अधस्तनम्_2))
#परिभाषय iswdigit(_c) (iswctype(_c,_DIGIT))
#परिभाषय iswxdigit(_c) (iswctype(_c,_HEX))
#परिभाषय iswspace(_c) (iswctype(_c,_SPACE))
#परिभाषय iswpunct(_c) (iswctype(_c,_PUNCT))
#परिभाषय iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#परिभाषय iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#परिभाषय iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#परिभाषय iswcntrl(_c) (iswctype(_c,_CONTROL))
#परिभाषय iswascii(_c) ((अचिह्नित)(_c) < 0x80)

#परिभाषय _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#परिभाषय _iswupper_l(_c,_p) (_iswctype_l(_c,ऊर्ध्वस्थम्_3,_p))
#परिभाषय _iswlower_l(_c,_p) (_iswctype_l(_c,अधस्तनम्_2,_p))
#परिभाषय _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#परिभाषय _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#परिभाषय _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#परिभाषय _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#परिभाषय _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#परिभाषय _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#परिभाषय _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#परिभाषय _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#यदि_अपरिभाषितम् _CTYPE_DISABLE_MACROS
#परिभाषय isleadbyte(_c) (__PCTYPE_FUNC[(अचिह्नित वर्ण)(_c)] & _LEADBYTE)
#यदि_अन्तः
#यदि_अन्तः
#परिभाषय _WCTYPE_INLINE_DEFINED
#यदि_अन्तः

#यदि !defined(_POSIX_) || defined(__GNUC__)
#यदि_अपरिभाषितम् _INO_T_DEFINED
#परिभाषय _INO_T_DEFINED
  प्रकारनिर्देश अचिह्नित ह्रस्व _ino_t;
#यदि_अपरिभाषितम्	NO_OLDNAMES
  प्रकारनिर्देश अचिह्नित ह्रस्व ino_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _DEV_T_DEFINED
#परिभाषय _DEV_T_DEFINED
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क _dev_t;
#यदि_अपरिभाषितम्	NO_OLDNAMES
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क dev_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _OFF_T_DEFINED
#परिभाषय _OFF_T_DEFINED
#यदि_अपरिभाषितम् _OFF_T_
#परिभाषय _OFF_T_
  प्रकारनिर्देश दीर्घ _off_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ off_t;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _OFF64_T_DEFINED
#परिभाषय _OFF64_T_DEFINED
  प्रकारनिर्देश दीर्घ दीर्घ _off64_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ दीर्घ off64_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _STAT_DEFINED
#परिभाषय _STAT_DEFINED

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#यदि_परिभाषितम् WIN64
#परिभाषय _fstat _fstat32
#परिभाषय _stat _stat32
#परिभाषय _wstat _wstat32
#अन्यथा
#परिभाषय _fstat32 _fstat
#परिभाषय _stat32 _stat
#परिभाषय _wstat32 _wstat
#यदि_अन्तः
#परिभाषय _fstati64 _fstat32i64
#परिभाषय _stati64 _stat32i64
#परिभाषय _wstati64 _wstat32i64
#अन्यथा
#परिभाषय _fstat _fstat64i32
#परिभाषय _fstati64 _fstat64
#परिभाषय _stat _stat64i32
#परिभाषय _stati64 _stat64
#परिभाषय _wstat _wstat64i32
#परिभाषय _wstati64 _wstat64
#यदि_अन्तः

  संरचना _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#यदि_अपरिभाषितम्	NO_OLDNAMES
  संरचना stat {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64

  संरचना _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  संरचना _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  संरचना _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#यदि_अन्तः

#परिभाषय __stat64 _stat64

#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTAT_DEFINED
#परिभाषय _WSTAT_DEFINED

  _CRTIMP पूर्णाङ्क __cdecl _wstat32(ध्रुव wchar_t *_Name,संरचना _stat32 *_Stat);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP पूर्णाङ्क __cdecl _wstat32i64(ध्रुव wchar_t *_Name,संरचना _stat32i64 *_Stat);
  पूर्णाङ्क __cdecl _wstat64i32(ध्रुव wchar_t *_Name,संरचना _stat64i32 *_Stat);
  _CRTIMP पूर्णाङ्क __cdecl _wstat64(ध्रुव wchar_t *_Name,संरचना _stat64 *_Stat);
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCONIO_DEFINED
#परिभाषय _WCONIO_DEFINED

#यदि_अपरिभाषितम् WEOF
#परिभाषय WEOF (wint_t)(0xFFFF)
#यदि_अन्तः

  _CRTIMP wchar_t *_cgetws(wchar_t *बफर_2);
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
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTDIO_DEFINED
#परिभाषय _WSTDIO_DEFINED

#यदि_अपरिभाषितम् WEOF
#परिभाषय WEOF (wint_t)(0xFFFF)
#यदि_अन्तः

#यदि_परिभाषितम् _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3);
#अन्यथा
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3,पूर्णाङ्क _ShFlag);
#यदि_अन्तः

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(शून्य);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(शून्य);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,पूर्णाङ्क आकार_अन्तर्_शब्दाः,FILE *_File);
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
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c(wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c(wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf(wchar_t *_Dest,आकार_t गणनम्_5,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf(wchar_t *_Dest,आकार_t गणनम्_5,ध्रुव wchar_t *_Format,va_list तर्काः_2);
#यदि_अपरिभाषितम् __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णाङ्क __cdecl snwprintf (wchar_t *s, आकार_t n, ध्रुव wchar_t * format, ...);
  __CRT_INLINE पूर्णाङ्क __cdecl vsnwprintf (wchar_t *s, आकार_t n, ध्रुव wchar_t *format, va_list arg) { प्रत्यागम _vsnwprintf(s,n,format,arg); }
  पूर्णाङ्क __cdecl vwscanf (ध्रुव wchar_t *, va_list);
  पूर्णाङ्क __cdecl vfwscanf (FILE *,ध्रुव wchar_t *,va_list);
  पूर्णाङ्क __cdecl vswscanf (ध्रुव wchar_t *,ध्रुव wchar_t *,va_list);
#यदि_अन्तः
  _CRTIMP पूर्णाङ्क __cdecl _fwprintf_p(FILE *_File,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wprintf_p(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vfwprintf_p(FILE *_File,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vwprintf_p(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,va_list _ArgList);
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
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c_l(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_p_l(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c_l(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_p_l(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf_l(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf_l(wchar_t *_DstBuf,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,va_list तर्काः_2);
  _CRTIMP पूर्णाङ्क __cdecl __swprintf_l(wchar_t *_Dest,ध्रुव wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP पूर्णाङ्क __cdecl __vswprintf_l(wchar_t *_Dest,ध्रुव wchar_t *_Format,_locale_t _Plocinfo,va_list तर्काः_2);
#यदि_अपरिभाषितम् RC_INVOKED
#अन्तर्भाव <vadefs.h>
#यदि_अन्तः

#यदि_परिभाषितम् _CRT_NON_CONFORMING_SWPRINTFS
#यदि_अपरिभाषितम् __cplusplus
#परिभाषय swprintf _swprintf
#परिभाषय vswprintf _vswprintf
#परिभाषय _swprintf_l __swprintf_l
#परिभाषय _vswprintf_l __vswprintf_l
#यदि_अन्तः
#यदि_अन्तः

  _CRTIMP wchar_t *__cdecl _wtempnam(ध्रुव wchar_t *_Directory,ध्रुव wchar_t *File_उपसर्गः);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  पूर्णाङ्क __cdecl fwscanf(FILE *_File,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _fwscanf_l(FILE *_File,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl swscanf(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _swscanf_l(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf(ध्रुव wchar_t *_Src,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf_l(ध्रुव wchar_t *_Src,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  पूर्णाङ्क __cdecl wscanf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _wscanf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(पूर्णाङ्क _FileHandle ,ध्रुव wchar_t *बहुलकम्_3);
  _CRTIMP FILE *__cdecl _wfopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3);
  _CRTIMP FILE *__cdecl _wfreopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3,FILE *_OldFile);

#यदि_अपरिभाषितम् _CRT_WPERROR_DEFINED
#परिभाषय _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(ध्रुव wchar_t *Err_सन्देशः);
#यदि_अन्तः
  _CRTIMP FILE *__cdecl _wpopen(ध्रुव wchar_t *_Command,ध्रुव wchar_t *बहुलकम्_3);
#यदि !defined(NO_OLDNAMES) && !defined(wpopen)
#परिभाषय wpopen	_wpopen
#यदि_अन्तः
  _CRTIMP पूर्णाङ्क __cdecl _wremove(ध्रुव wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *बफर_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#अपरिभाषय _CRT_GETPUTWCHAR_NOINLINE

#यदि !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#परिभाषय getwchar() fgetwc(stdin)
#परिभाषय putwchar(_c) fputwc((_c),stdout)
#अन्यथा
  __CRT_INLINE wint_t __cdecl getwchar() {प्रत्यागम (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {प्रत्यागम (fputwc(_C,stdout)); }
#यदि_अन्तः

#परिभाषय getwc(_stm) fgetwc(_stm)
#परिभाषय putwc(_c,_stm) fputwc(_c,_stm)
#परिभाषय _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#परिभाषय _getwc_nolock(_c) _fgetwc_nolock(_c)
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTDLIB_DEFINED
#परिभाषय _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(पूर्णाङ्क मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(दीर्घ मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(अचिह्नित दीर्घ मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  द्विगुण __cdecl wcstod(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr);
  _CRTIMP द्विगुण __cdecl _wcstod_l(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,_locale_t _Locale);
  भिन्न __cdecl wcstof( ध्रुव wchar_t *nptr, wchar_t **endptr);
#यदि !defined __NO_ISOCEXT /* in libmingwex.a */
  भिन्न __cdecl wcstof (ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
  दीर्घ द्विगुण __cdecl wcstold (ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
#यदि_अन्तः /* __NO_ISOCEXT */
  दीर्घ __cdecl wcstol(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP दीर्घ __cdecl _wcstol_l(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
  अचिह्नित दीर्घ __cdecl wcstoul(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP अचिह्नित दीर्घ __cdecl _wcstoul_l(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ध्रुव wchar_t *_VarName);
#यदि_अपरिभाषितम् _CRT_WSYSTEM_DEFINED
#परिभाषय _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(ध्रुव wchar_t *_Command);
#यदि_अन्तः
  _CRTIMP द्विगुण __cdecl _wtof(ध्रुव wchar_t *_Str);
  _CRTIMP द्विगुण __cdecl _wtof_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi(ध्रुव wchar_t *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wtoi_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP दीर्घ __cdecl _wtol(ध्रुव wchar_t *_Str);
  _CRTIMP दीर्घ __cdecl _wtol_l(ध्रुव wchar_t *_Str,_locale_t _Locale);

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(अचिह्नित __int64 _Val,wchar_t *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ध्रुव wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ध्रुव wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP अचिह्नित __int64 __cdecl _wcstoui64(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP अचिह्नित __int64 __cdecl _wcstoui64_l(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _POSIX_
#यदि_अपरिभाषितम् _WSTDLIBP_DEFINED
#परिभाषय _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *पूर्णम्_मार्गः,ध्रुव wchar_t *मार्गः_2,आकार_t आकार_अन्तर्_शब्दाः);
  _CRTIMP शून्य __cdecl _wmakepath(wchar_t *परिणाम_मार्गः,ध्रुव wchar_t *_Drive,ध्रुव wchar_t *_Dir,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Ext);
#यदि_अपरिभाषितम् _CRT_WPERROR_DEFINED
#परिभाषय _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(ध्रुव wchar_t *Err_सन्देशः);
#यदि_अन्तः
  _CRTIMP पूर्णाङ्क __cdecl _wputenv(ध्रुव wchar_t *_EnvString);
  _CRTIMP शून्य __cdecl _wsearchenv(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_EnvVar,wchar_t *परिणाम_मार्गः);
  _CRTIMP शून्य __cdecl _wsplitpath(ध्रुव wchar_t *पूर्णम्_मार्गः,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTRING_DEFINED
#परिभाषय _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(ध्रुव wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  पूर्णाङ्क __cdecl wcscmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  आकार_t __cdecl wcscspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  आकार_t __cdecl wcslen(ध्रुव wchar_t *_Str);
  आकार_t __cdecl wcsnlen(ध्रुव wchar_t *_Src,आकार_t Max_गणनम्);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,ध्रुव wchar_t *_Source,आकार_t गणनम्_5);
  पूर्णाङ्क __cdecl wcsncmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,ध्रुव wchar_t *_Source,आकार_t गणनम्_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  आकार_t __cdecl wcsspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ध्रुव wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(पूर्णाङ्क Err_अङ्कः);
  _CRTIMP wchar_t *__cdecl __wcserror(ध्रुव wchar_t *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,आकार_t Max_गणनम्);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  आकार_t __cdecl wcsxfrm(wchar_t *_Dst,ध्रुव wchar_t *_Src,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ध्रुव wchar_t *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  पूर्णाङ्क __cdecl wcscoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcscoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);

#यदि_अपरिभाषितम्	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ध्रुव wchar_t *_Str);
#परिभाषय wcswcs wcsstr
  पूर्णाङ्क __cdecl wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  पूर्णाङ्क __cdecl wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,आकार_t Max_गणनम्);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  पूर्णाङ्क __cdecl wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _TM_DEFINED
#परिभाषय _TM_DEFINED
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
#यदि_अन्तः

#यदि_अपरिभाषितम् _WTIME_DEFINED
#परिभाषय _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(ध्रुव संरचना tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(ध्रुव __time32_t *_Time);
  आकार_t __cdecl wcsftime(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm);
  _CRTIMP आकार_t __cdecl _wcsftime_l(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,ध्रुव संरचना tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *बफर_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *बफर_2);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(ध्रुव __time64_t *_Time);
#यदि_अन्तः

#यदि !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#परिभाषय _INC_WTIME_INL
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { प्रत्यागम _wctime32(_Time); }
#अन्यथा
__CRT_INLINE wchar_t *__cdecl _wctime(ध्रुव time_t *_Time) { प्रत्यागम _wctime64(_Time); }
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

  प्रकारनिर्देश पूर्णाङ्क mbstate_t;
  प्रकारनिर्देश wchar_t _Wint_t;

  wint_t __cdecl btowc(पूर्णाङ्क);
  आकार_t __cdecl mbrlen(ध्रुव वर्ण *_Ch,आकार_t आकार_अन्तर्_अष्टकानि,mbstate_t *_State);
  आकार_t __cdecl mbrtowc(wchar_t *_DstCh,ध्रुव वर्ण *_SrcCh,आकार_t आकार_अन्तर्_अष्टकानि,mbstate_t *_State);
  आकार_t __cdecl mbsrtowcs(wchar_t *_Dest,ध्रुव वर्ण **_PSrc,आकार_t गणनम्_5,mbstate_t *_State);
  आकार_t __cdecl wcrtomb(वर्ण *_Dest,wchar_t _Source,mbstate_t *_State);
  आकार_t __cdecl wcsrtombs(वर्ण *_Dest,ध्रुव wchar_t **_PSource,आकार_t गणनम्_5,mbstate_t *_State);
  पूर्णाङ्क __cdecl wctob(wint_t _WCh);

#यदि_अपरिभाषितम् __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, आकार_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(ध्रुव wchar_t *s, wchar_t c, आकार_t n);
  पूर्णाङ्क wmemcmp(ध्रुव wchar_t *s1, ध्रुव wchar_t *s2,आकार_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,ध्रुव wchar_t *s2,आकार_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, ध्रुव wchar_t *s2, आकार_t n);
  दीर्घ दीर्घ __cdecl wcstoll(ध्रुव wchar_t *nptr,wchar_t **endptr, पूर्णाङ्क आधारः);
  अचिह्नित दीर्घ दीर्घ __cdecl wcstoull(ध्रुव wchar_t *nptr,wchar_t **endptr, पूर्णाङ्क आधारः);
#यदि_अन्तः /* __NO_ISOCEXT */

  शून्य *__cdecl memmove(शून्य *_Dst,ध्रुव शून्य *_Src,आकार_t Max_गणनम्);
  शून्य *__cdecl स्मृतिं_प्रतिलिख(शून्य *_Dst,ध्रुव शून्य *_Src,आकार_t Max_गणनम्);
  __CRT_INLINE पूर्णाङ्क __cdecl fwide(FILE *_F,पूर्णाङ्क _M) { (शून्य)_F; प्रत्यागम (_M); }
  __CRT_INLINE पूर्णाङ्क __cdecl mbsinit(ध्रुव mbstate_t *_P) { प्रत्यागम (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(ध्रुव wchar_t *_S,wchar_t _C,आकार_t _N) { प्रति (;0<_N;++_S,--_N) यदि (*_S==_C) प्रत्यागम (_CONST_RETURN wchar_t *)(_S); प्रत्यागम (0); }
  __CRT_INLINE पूर्णाङ्क __cdecl wmemcmp(ध्रुव wchar_t *_S1,ध्रुव wchar_t *_S2,आकार_t _N) { प्रति (; 0 < _N; ++_S1,++_S2,--_N) यदि (*_S1!=*_S2) प्रत्यागम (*_S1 < *_S2 ? -1 : +1); प्रत्यागम (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,ध्रुव wchar_t *_S2,आकार_t _N) { प्रत्यागम (wchar_t *)स्मृतिं_प्रतिलिख(_S1,_S2,_N*परिमाण(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,ध्रुव wchar_t *_S2,आकार_t _N) { प्रत्यागम (wchar_t *)memmove(_S1,_S2,_N*परिमाण(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,आकार_t _N) {
    wchar_t *_Su = _S;
    प्रति (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    प्रत्यागम (_S);
  }
#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)

#अन्तर्भाव <sec_api/wchar_s.h>
#यदि_अन्तः
