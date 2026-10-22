/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_WCHAR
#घोषणा _INC_WCHAR

#समावेश <_mingw.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित WCHAR_MIN  /* also at stdint.h */
#घोषणा WCHAR_MIN 0
#घोषणा WCHAR_MAX ((ब_अक्षर_प्रकार) -1) /* UINT16_MAX */
#पूर्ण_अगर

#अगर_अघोषित __GNUC_VA_LIST
#घोषणा __GNUC_VA_LIST
  प्रकार __builtin_va_list __gnuc_va_list;
#पूर्ण_अगर

#अगर_अघोषित _VA_LIST_DEFINED
#घोषणा _VA_LIST_DEFINED
  प्रकार __gnuc_va_list बहु_सूची;
#पूर्ण_अगर

#अगर_अघोषित WEOF
#घोषणा WEOF (wint_t)(0xFFFF)
#पूर्ण_अगर

#अगर_अघोषित _FILE_DEFINED
  काष्ठा _iobuf {
    अक्षर *_ptr;
    पूर्णांक _cnt;
    अक्षर *_base;
    पूर्णांक _flag;
    पूर्णांक _file;
    पूर्णांक _charbuf;
    पूर्णांक _bufsiz;
    अक्षर *_tmpfname;
  };
  प्रकार काष्ठा _iobuf खाता;
#घोषणा _FILE_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _STDIO_DEFINED
#अगर_घोषित _WIN64
  _CRTIMP खाता *__cdecl __iob_func(व्योम);
#अन्यथा
#अगर_घोषित _MSVCRT_
बाह्य खाता _iob[];	/* A pointer to an array of FILE */
#घोषणा __iob_func()	(_iob)
#अन्यथा
बाह्य खाता (*_imp___iob)[];	/* A pointer to an array of FILE */
#घोषणा __iob_func()	(*_imp___iob)
#घोषणा _iob __iob_func()
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _iob __iob_func()
#पूर्ण_अगर

#अगर_अघोषित _STDSTREAM_DEFINED
#घोषणा मानक_निवेश (&__iob_func()[0])
#घोषणा मानक_निकास (&__iob_func()[1])
#घोषणा मानक_त्रुटि (&__iob_func()[2])
#घोषणा _STDSTREAM_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _FSIZE_T_DEFINED
  प्रकार अचिन्हित दीर्घ _fsize_t;
#घोषणा _FSIZE_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _WFINDDATA_T_DEFINED
  काष्ठा _wfinddata32_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t आकार;
    ब_अक्षर_प्रकार name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  काष्ठा _wfinddata32i64_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 आकार;
    ब_अक्षर_प्रकार name[260];
  };

  काष्ठा _wfinddata64i32_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t आकार;
    ब_अक्षर_प्रकार name[260];
  };

  काष्ठा _wfinddata64_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 आकार;
    ब_अक्षर_प्रकार name[260];
  };
/* #endif */

#अगर_घोषित _USE_32BIT_TIME_T
#घोषणा _wfinddata_t _wfinddata32_t
#घोषणा _wfinddatai64_t _wfinddata32i64_t

#घोषणा _wfindfirst _wfindfirst32
#घोषणा _wfindnext _wfindnext32
#घोषणा _wfindfirsti64 _wfindfirst32i64
#घोषणा _wfindnexti64 _wfindnext32i64
#अन्यथा
#घोषणा _wfinddata_t _wfinddata64i32_t
#घोषणा _wfinddatai64_t _wfinddata64_t

#घोषणा _wfindfirst _wfindfirst64i32
#घोषणा _wfindnext _wfindnext64i32
#घोषणा _wfindfirsti64 _wfindfirst64
#घोषणा _wfindnexti64 _wfindnext64
#पूर्ण_अगर

#घोषणा _WFINDDATA_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _CONST_RETURN
#घोषणा _CONST_RETURN
#पूर्ण_अगर

#घोषणा _WConst_return _CONST_RETURN

#अगर_अघोषित _CRT_CTYPEDATA_DEFINED
#घोषणा _CRT_CTYPEDATA_DEFINED
#अगर_अघोषित _CTYPE_DISABLE_MACROS

#अगर_अघोषित __PCTYPE_FUNC
#घोषणा __PCTYPE_FUNC __pctype_func()
#अगर_घोषित _MSVCRT_
#घोषणा __pctype_func() (_pctype)
#अन्यथा
#घोषणा __pctype_func() (*_imp___pctype)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _pctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_pctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pctype;
#घोषणा _pctype (*_imp___pctype)
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _CRT_WCTYPEDATA_DEFINED
#घोषणा _CRT_WCTYPEDATA_DEFINED
#अगर_अघोषित _CTYPE_DISABLE_MACROS
#अगर_अघोषित _wctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_wctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___wctype;
#घोषणा _wctype (*_imp___wctype)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित _MSVCRT_
#घोषणा __pwctype_func() (_pwctype)
#अन्यथा
#घोषणा __pwctype_func() (*_imp___pwctype)
#पूर्ण_अगर

#अगर_अघोषित _pwctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_pwctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pwctype;
#घोषणा _pwctype (*_imp___pwctype)
#पूर्ण_अगर
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा _UPPER 0x1
#घोषणा _LOWER 0x2
#घोषणा _DIGIT 0x4
#घोषणा _SPACE 0x8

#घोषणा _PUNCT 0x10
#घोषणा _CONTROL 0x20
#घोषणा _BLANK 0x40
#घोषणा _HEX 0x80

#घोषणा _LEADBYTE 0x8000
#घोषणा _ALPHA (0x0100|_UPPER|_LOWER)

#अगर_अघोषित _WCTYPE_DEFINED
#घोषणा _WCTYPE_DEFINED

  पूर्णांक __cdecl iswalpha(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswupper(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswlower(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswdigit(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswxdigit(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswspace(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswpunct(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswalnum(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswprint(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswgraph(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswcntrl(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswascii(wint_t _C);
  पूर्णांक __cdecl isleadbyte(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isleadbyte_l(पूर्णांक _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP पूर्णांक __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl __iswcsymf(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl __iswcsym(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl is_wctype(wint_t _C,wctype_t _Type);
#पूर्ण_अगर

#अगर_अघोषित _WDIRECT_DEFINED
#घोषणा _WDIRECT_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetcwd(ब_अक्षर_प्रकार *_DstBuf,पूर्णांक आकार_In_शब्दगण);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetdcwd(पूर्णांक _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक आकार_In_शब्दगण);
  ब_अक्षर_प्रकार *__cdecl _wgetdcwd_nolock(पूर्णांक _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक आकार_In_शब्दगण);
  _CRTIMP पूर्णांक __cdecl _wchdir(स्थिर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णांक __cdecl _wmkdir(स्थिर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णांक __cdecl _wrmdir(स्थिर ब_अक्षर_प्रकार *_Path);
#पूर्ण_अगर

#अगर_अघोषित _WIO_DEFINED
#घोषणा _WIO_DEFINED

  _CRTIMP पूर्णांक __cdecl _waccess(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _AccessMode);
  _CRTIMP पूर्णांक __cdecl _wchmod(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _Mode);
  _CRTIMP पूर्णांक __cdecl _wcreat(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wfindnext32(intptr_t _FindHandle,काष्ठा _wfinddata32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wunlink(स्थिर ब_अक्षर_प्रकार *_Filename);
  _CRTIMP पूर्णांक __cdecl _wrename(स्थिर ब_अक्षर_प्रकार *_NewFilename,स्थिर ब_अक्षर_प्रकार *_OldFilename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wmktemp(ब_अक्षर_प्रकार *_TemplateName);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata32i64_t *Find_तथ्य);
  intptr_t __cdecl _wfindfirst64i32(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata64i32_t *Find_तथ्य);
  _CRTIMP intptr_t __cdecl _wfindfirst64(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata64_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wfindnext32i64(intptr_t _FindHandle,काष्ठा _wfinddata32i64_t *Find_तथ्य);
  पूर्णांक __cdecl _wfindnext64i32(intptr_t _FindHandle,काष्ठा _wfinddata64i32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wfindnext64(intptr_t _FindHandle,काष्ठा _wfinddata64_t *Find_तथ्य);
#पूर्ण_अगर
  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णांक *_FileHandle,स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionFlag);
#अगर !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णांक __cdecl _wopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,...);
  _CRTIMP पूर्णांक __cdecl _wsopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _wopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _wsopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionMode = 0);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WLOCALE_DEFINED
#घोषणा _WLOCALE_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wsetlocale(पूर्णांक _Category,स्थिर ब_अक्षर_प्रकार *_Locale);
#पूर्ण_अगर

#अगर_अघोषित _WPROCESS_DEFINED
#घोषणा _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
#अगर_अघोषित _CRT_WSYSTEM_DEFINED
#घोषणा _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णांक __cdecl _wsystem(स्थिर ब_अक्षर_प्रकार *_Command);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WCTYPE_INLINE_DEFINED
#अघोषित _CRT_WCTYPE_NOINLINE
#अगर !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#घोषणा iswalpha(_c) (iswctype(_c,_ALPHA))
#घोषणा iswupper(_c) (iswctype(_c,_UPPER))
#घोषणा iswlower(_c) (iswctype(_c,_LOWER))
#घोषणा iswdigit(_c) (iswctype(_c,_DIGIT))
#घोषणा iswxdigit(_c) (iswctype(_c,_HEX))
#घोषणा iswspace(_c) (iswctype(_c,_SPACE))
#घोषणा iswpunct(_c) (iswctype(_c,_PUNCT))
#घोषणा iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#घोषणा iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#घोषणा iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#घोषणा iswcntrl(_c) (iswctype(_c,_CONTROL))
#घोषणा iswascii(_c) ((अचिन्हित)(_c) < 0x80)

#घोषणा _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#घोषणा _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#घोषणा _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#घोषणा _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#घोषणा _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#घोषणा _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#घोषणा _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#घोषणा _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#घोषणा _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#घोषणा _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#घोषणा _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#अगर_अघोषित _CTYPE_DISABLE_MACROS
#घोषणा isleadbyte(_c) (__PCTYPE_FUNC[(अचिन्हित अक्षर)(_c)] & _LEADBYTE)
#पूर्ण_अगर
#पूर्ण_अगर
#घोषणा _WCTYPE_INLINE_DEFINED
#पूर्ण_अगर

#अगर !defined(_POSIX_) || defined(__GNUC__)
#अगर_अघोषित _INO_T_DEFINED
#घोषणा _INO_T_DEFINED
  प्रकार अचिन्हित लघु _ino_t;
#अगर_अघोषित	NO_OLDNAMES
  प्रकार अचिन्हित लघु ino_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _DEV_T_DEFINED
#घोषणा _DEV_T_DEFINED
  प्रकार अचिन्हित पूर्णांक _dev_t;
#अगर_अघोषित	NO_OLDNAMES
  प्रकार अचिन्हित पूर्णांक dev_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _OFF_T_DEFINED
#घोषणा _OFF_T_DEFINED
#अगर_अघोषित _OFF_T_
#घोषणा _OFF_T_
  प्रकार दीर्घ _off_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ off_t;
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _OFF64_T_DEFINED
#घोषणा _OFF64_T_DEFINED
  प्रकार दीर्घ दीर्घ _off64_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ दीर्घ off64_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _STAT_DEFINED
#घोषणा _STAT_DEFINED

#अगर_घोषित _USE_32BIT_TIME_T
#अगर_घोषित WIN64
#घोषणा _fstat _fstat32
#घोषणा _stat _stat32
#घोषणा _wstat _wstat32
#अन्यथा
#घोषणा _fstat32 _fstat
#घोषणा _stat32 _stat
#घोषणा _wstat32 _wstat
#पूर्ण_अगर
#घोषणा _fstati64 _fstat32i64
#घोषणा _stati64 _stat32i64
#घोषणा _wstati64 _wstat32i64
#अन्यथा
#घोषणा _fstat _fstat64i32
#घोषणा _fstati64 _fstat64
#घोषणा _stat _stat64i32
#घोषणा _stati64 _stat64
#घोषणा _wstat _wstat64i32
#घोषणा _wstati64 _wstat64
#पूर्ण_अगर

  काष्ठा _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#अगर_अघोषित	NO_OLDNAMES
  काष्ठा stat {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    समय_प्रकार st_atime;
    समय_प्रकार st_mtime;
    समय_प्रकार st_ctime;
  };
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 64

  काष्ठा _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  काष्ठा _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  काष्ठा _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#पूर्ण_अगर

#घोषणा __stat64 _stat64

#पूर्ण_अगर

#अगर_अघोषित _WSTAT_DEFINED
#घोषणा _WSTAT_DEFINED

  _CRTIMP पूर्णांक __cdecl _wstat32(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat32 *_Stat);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णांक __cdecl _wstat32i64(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat32i64 *_Stat);
  पूर्णांक __cdecl _wstat64i32(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat64i32 *_Stat);
  _CRTIMP पूर्णांक __cdecl _wstat64(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat64 *_Stat);
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WCONIO_DEFINED
#घोषणा _WCONIO_DEFINED

#अगर_अघोषित WEOF
#घोषणा WEOF (wint_t)(0xFFFF)
#पूर्ण_अगर

  _CRTIMP ब_अक्षर_प्रकार *_cgetws(ब_अक्षर_प्रकार *बफर_2);
  _CRTIMP wint_t __cdecl _getwch(व्योम);
  _CRTIMP wint_t __cdecl _getwche(व्योम);
  _CRTIMP wint_t __cdecl _putwch(ब_अक्षर_प्रकार _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP पूर्णांक __cdecl _cputws(स्थिर ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णांक __cdecl _cwprintf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);

  _CRTIMP पूर्णांक __cdecl _cwprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  wint_t __cdecl _putwch_nolock(ब_अक्षर_प्रकार _WCh);
  wint_t __cdecl _getwch_nolock(व्योम);
  wint_t __cdecl _getwche_nolock(व्योम);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#पूर्ण_अगर

#अगर_अघोषित _WSTDIO_DEFINED
#घोषणा _WSTDIO_DEFINED

#अगर_अघोषित WEOF
#घोषणा WEOF (wint_t)(0xFFFF)
#पूर्ण_अगर

#अगर_घोषित _POSIX_
  _CRTIMP खाता *__cdecl _wfsopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _wfsopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode,पूर्णांक _ShFlag);
#पूर्ण_अगर

  wint_t __cdecl fgetwc(खाता *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(व्योम);
  wint_t __cdecl fputwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _fputwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl getwc(खाता *_File);
  wint_t __cdecl getwchar(व्योम);
  wint_t __cdecl putwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  wint_t __cdecl putwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,खाता *_File);
  ब_अक्षर_प्रकार *__cdecl fgetws(ब_अक्षर_प्रकार *_Dst,पूर्णांक आकार_In_शब्दगण,खाता *_File);
  पूर्णांक __cdecl fputws(स्थिर ब_अक्षर_प्रकार *_Str,खाता *_File);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws(ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णांक __cdecl _putws(स्थिर ब_अक्षर_प्रकार *_Str);
  पूर्णांक __cdecl fwprintf(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl wprintf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _scwprintf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl vfwprintf(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl vwprintf(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl swprintf(ब_अक्षर_प्रकार*, स्थिर ब_अक्षर_प्रकार*, ...);
  _CRTIMP पूर्णांक __cdecl vswprintf(ब_अक्षर_प्रकार*, स्थिर ब_अक्षर_प्रकार*,बहु_सूची);
  _CRTIMP पूर्णांक __cdecl _swprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार गिनती_5,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार गिनती_5,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);
#अगर_अघोषित __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णांक __cdecl snwprintf (ब_अक्षर_प्रकार *s, माप_प्रकार n, स्थिर ब_अक्षर_प्रकार * format, ...);
  __CRT_INLINE पूर्णांक __cdecl vsnwprintf (ब_अक्षर_प्रकार *s, माप_प्रकार n, स्थिर ब_अक्षर_प्रकार *format, बहु_सूची arg) { वापस _vsnwprintf(s,n,format,arg); }
  पूर्णांक __cdecl vwscanf (स्थिर ब_अक्षर_प्रकार *, बहु_सूची);
  पूर्णांक __cdecl vfwscanf (खाता *,स्थिर ब_अक्षर_प्रकार *,बहु_सूची);
  पूर्णांक __cdecl vswscanf (स्थिर ब_अक्षर_प्रकार *,स्थिर ब_अक्षर_प्रकार *,बहु_सूची);
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _fwprintf_p(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _wprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_p(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vwprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _swprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_p(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _scwprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vscwprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _wprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _wprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vwprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vwprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _fwprintf_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _fwprintf_p_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vfwprintf_p_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _swprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _swprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_c_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vswprintf_p_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _scwprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _scwprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vscwprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf_l(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _swprintf(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);
  _CRTIMP पूर्णांक __cdecl __swprintf_l(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,...);
  _CRTIMP पूर्णांक __cdecl __vswprintf_l(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Plocinfo,बहु_सूची _Args);
#अगर_अघोषित RC_INVOKED
#समावेश <vadefs.h>
#पूर्ण_अगर

#अगर_घोषित _CRT_NON_CONFORMING_SWPRINTFS
#अगर_अघोषित __cplusplus
#घोषणा swprintf _swprintf
#घोषणा vswprintf _vswprintf
#घोषणा _swprintf_l __swprintf_l
#घोषणा _vswprintf_l __vswprintf_l
#पूर्ण_अगर
#पूर्ण_अगर

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtempnam(स्थिर ब_अक्षर_प्रकार *_Directory,स्थिर ब_अक्षर_प्रकार *_FilePrefix);
  _CRTIMP पूर्णांक __cdecl _vscwprintf(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _vscwprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  पूर्णांक __cdecl fwscanf(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _fwscanf_l(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  पूर्णांक __cdecl swscanf(स्थिर ब_अक्षर_प्रकार *_Src,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _swscanf_l(स्थिर ब_अक्षर_प्रकार *_Src,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf(स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf_l(स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  पूर्णांक __cdecl wscanf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _wscanf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP खाता *__cdecl _wfdopen(पूर्णांक _FileHandle ,स्थिर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfreopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);

#अगर_अघोषित _CRT_WPERROR_DEFINED
#घोषणा _CRT_WPERROR_DEFINED
  _CRTIMP व्योम __cdecl _wperror(स्थिर ब_अक्षर_प्रकार *Err_संदेश);
#पूर्ण_अगर
  _CRTIMP खाता *__cdecl _wpopen(स्थिर ब_अक्षर_प्रकार *_Command,स्थिर ब_अक्षर_प्रकार *_Mode);
#अगर !defined(NO_OLDNAMES) && !defined(wpopen)
#घोषणा wpopen	_wpopen
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _wremove(स्थिर ब_अक्षर_प्रकार *_Filename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtmpnam(ब_अक्षर_प्रकार *बफर_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(खाता *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,खाता *_File);

#अघोषित _CRT_GETPUTWCHAR_NOINLINE

#अगर !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#घोषणा getwchar() fgetwc(मानक_निवेश)
#घोषणा putwchar(_c) fputwc((_c),मानक_निकास)
#अन्यथा
  __CRT_INLINE wint_t __cdecl getwchar() {वापस (fgetwc(मानक_निवेश)); }
  __CRT_INLINE wint_t __cdecl putwchar(ब_अक्षर_प्रकार _C) {वापस (fputwc(_C,मानक_निकास)); }
#पूर्ण_अगर

#घोषणा getwc(_stm) fgetwc(_stm)
#घोषणा putwc(_c,_stm) fputwc(_c,_stm)
#घोषणा _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#घोषणा _getwc_nolock(_c) _fgetwc_nolock(_c)
#पूर्ण_अगर

#अगर_अघोषित _WSTDLIB_DEFINED
#घोषणा _WSTDLIB_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _itow(पूर्णांक मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ltow(दीर्घ मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ultow(अचिन्हित दीर्घ मूल्य_2,ब_अक्षर_प्रकार *_Dest,पूर्णांक _Radix);
  द्विगुन __cdecl wcstod(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr);
  _CRTIMP द्विगुन __cdecl _wcstod_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,_locale_t _Locale);
  भग्न __cdecl wcstof( स्थिर ब_अक्षर_प्रकार *nptr, ब_अक्षर_प्रकार **endptr);
#अगर !defined __NO_ISOCEXT /* in libmingwex.a */
  भग्न __cdecl wcstof (स्थिर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
  दीर्घ द्विगुन __cdecl wcstold (स्थिर ब_अक्षर_प्रकार * __restrict__, ब_अक्षर_प्रकार ** __restrict__);
#पूर्ण_अगर /* __NO_ISOCEXT */
  दीर्घ __cdecl wcstol(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP दीर्घ __cdecl _wcstol_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  अचिन्हित दीर्घ __cdecl wcstoul(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित दीर्घ __cdecl _wcstoul_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetenv(स्थिर ब_अक्षर_प्रकार *_VarName);
#अगर_अघोषित _CRT_WSYSTEM_DEFINED
#घोषणा _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णांक __cdecl _wsystem(स्थिर ब_अक्षर_प्रकार *_Command);
#पूर्ण_अगर
  _CRTIMP द्विगुन __cdecl _wtof(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP द्विगुन __cdecl _wtof_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wtoi(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णांक __cdecl _wtoi_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP दीर्घ __cdecl _wtol(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP दीर्घ __cdecl _wtol_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);

#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _i64tow(__int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक _Radix);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _ui64tow(अचिन्हित __int64 _Val,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(स्थिर ब_अक्षर_प्रकार *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix);
  _CRTIMP अचिन्हित __int64 __cdecl _wcstoui64_l(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार **_EndPtr,पूर्णांक _Radix,_locale_t _Locale);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _POSIX_
#अगर_अघोषित _WSTDLIBP_DEFINED
#घोषणा _WSTDLIBP_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wfullpath(ब_अक्षर_प्रकार *_FullPath,स्थिर ब_अक्षर_प्रकार *_Path,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP व्योम __cdecl _wmakepath(ब_अक्षर_प्रकार *परिणाम_Path,स्थिर ब_अक्षर_प्रकार *_Drive,स्थिर ब_अक्षर_प्रकार *_Dir,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Ext);
#अगर_अघोषित _CRT_WPERROR_DEFINED
#घोषणा _CRT_WPERROR_DEFINED
  _CRTIMP व्योम __cdecl _wperror(स्थिर ब_अक्षर_प्रकार *Err_संदेश);
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _wputenv(स्थिर ब_अक्षर_प्रकार *_EnvString);
  _CRTIMP व्योम __cdecl _wsearchenv(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_EnvVar,ब_अक्षर_प्रकार *परिणाम_Path);
  _CRTIMP व्योम __cdecl _wsplitpath(स्थिर ब_अक्षर_प्रकार *_FullPath,ब_अक्षर_प्रकार *_Drive,ब_अक्षर_प्रकार *_Dir,ब_अक्षर_प्रकार *_Filename,ब_अक्षर_प्रकार *_Ext);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WSTRING_DEFINED
#घोषणा _WSTRING_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsdup(स्थिर ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcscat(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcschr(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  पूर्णांक __cdecl wcscmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  ब_अक्षर_प्रकार *__cdecl wcscpy(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source);
  माप_प्रकार __cdecl wcscspn(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Control);
  माप_प्रकार __cdecl wcslen(स्थिर ब_अक्षर_प्रकार *_Str);
  माप_प्रकार __cdecl wcsnlen(स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsncat(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source,माप_प्रकार गिनती_5);
  पूर्णांक __cdecl wcsncmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsncpy(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source,माप_प्रकार गिनती_5);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcspbrk(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsrchr(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  माप_प्रकार __cdecl wcsspn(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsstr(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_SubStr);
  ब_अक्षर_प्रकार *__cdecl wcstok(ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Delim);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcserror(पूर्णांक Err_अंक);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl __wcserror(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णांक __cdecl _wcsicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णांक __cdecl _wcsicmp_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsnicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _wcsnicmp_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsrev(ब_अक्षर_प्रकार *_Str);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcslwr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcslwr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsupr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcsupr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  माप_प्रकार __cdecl wcsxfrm(ब_अक्षर_प्रकार *_Dst,स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _wcsxfrm_l(ब_अक्षर_प्रकार *_Dst,स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  पूर्णांक __cdecl wcscoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णांक __cdecl _wcscoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsicoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णांक __cdecl _wcsicoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsncoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _wcsncoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsnicoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _wcsnicoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);

#अगर_अघोषित	NO_OLDNAMES
  ब_अक्षर_प्रकार *__cdecl wcsdup(स्थिर ब_अक्षर_प्रकार *_Str);
#घोषणा wcswcs wcsstr
  पूर्णांक __cdecl wcsicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  पूर्णांक __cdecl wcsnicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsrev(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  ब_अक्षर_प्रकार *__cdecl wcslwr(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsupr(ब_अक्षर_प्रकार *_Str);
  पूर्णांक __cdecl wcsicoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TM_DEFINED
#घोषणा _TM_DEFINED
  काष्ठा पंचांग {
    पूर्णांक tm_sec;
    पूर्णांक tm_min;
    पूर्णांक tm_hour;
    पूर्णांक tm_mday;
    पूर्णांक tm_mon;
    पूर्णांक tm_year;
    पूर्णांक tm_wday;
    पूर्णांक tm_yday;
    पूर्णांक tm_isdst;
  };
#पूर्ण_अगर

#अगर_अघोषित _WTIME_DEFINED
#घोषणा _WTIME_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wasctime(स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime32(स्थिर __time32_t *_Time);
  माप_प्रकार __cdecl wcsftime(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP माप_प्रकार __cdecl _wcsftime_l(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,स्थिर काष्ठा पंचांग *_Tm,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrdate(ब_अक्षर_प्रकार *बफर_2);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wstrtime(ब_अक्षर_प्रकार *बफर_2);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wctime64(स्थिर __time64_t *_Time);
#पूर्ण_अगर

#अगर !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#घोषणा _INC_WTIME_INL
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(स्थिर समय_प्रकार *_Time) { वापस _wctime32(_Time); }
#अन्यथा
__CRT_INLINE ब_अक्षर_प्रकार *__cdecl _wctime(स्थिर समय_प्रकार *_Time) { वापस _wctime64(_Time); }
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

  प्रकार पूर्णांक mbstate_t;
  प्रकार ब_अक्षर_प्रकार _Wint_t;

  wint_t __cdecl btowc(पूर्णांक);
  माप_प्रकार __cdecl mbrlen(स्थिर अक्षर *_Ch,माप_प्रकार आकार_In_Bytes,mbstate_t *_State);
  माप_प्रकार __cdecl mbrtowc(ब_अक्षर_प्रकार *_DstCh,स्थिर अक्षर *_SrcCh,माप_प्रकार आकार_In_Bytes,mbstate_t *_State);
  माप_प्रकार __cdecl mbsrtowcs(ब_अक्षर_प्रकार *_Dest,स्थिर अक्षर **_PSrc,माप_प्रकार गिनती_5,mbstate_t *_State);
  माप_प्रकार __cdecl wcrtomb(अक्षर *_Dest,ब_अक्षर_प्रकार _Source,mbstate_t *_State);
  माप_प्रकार __cdecl wcsrtombs(अक्षर *_Dest,स्थिर ब_अक्षर_प्रकार **_PSource,माप_प्रकार गिनती_5,mbstate_t *_State);
  पूर्णांक __cdecl wctob(wint_t _WCh);

#अगर_अघोषित __NO_ISOCEXT /* these need static lib libmingwex.a */
  ब_अक्षर_प्रकार *__cdecl wmemset(ब_अक्षर_प्रकार *s, ब_अक्षर_प्रकार c, माप_प्रकार n);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wmemchr(स्थिर ब_अक्षर_प्रकार *s, ब_अक्षर_प्रकार c, माप_प्रकार n);
  पूर्णांक wmemcmp(स्थिर ब_अक्षर_प्रकार *s1, स्थिर ब_अक्षर_प्रकार *s2,माप_प्रकार n);
  ब_अक्षर_प्रकार *__cdecl wmemcpy(ब_अक्षर_प्रकार *s1,स्थिर ब_अक्षर_प्रकार *s2,माप_प्रकार n);
  ब_अक्षर_प्रकार *__cdecl wmemmove(ब_अक्षर_प्रकार *s1, स्थिर ब_अक्षर_प्रकार *s2, माप_प्रकार n);
  दीर्घ दीर्घ __cdecl wcstoll(स्थिर ब_अक्षर_प्रकार *nptr,ब_अक्षर_प्रकार **endptr, पूर्णांक base);
  अचिन्हित दीर्घ दीर्घ __cdecl wcstoull(स्थिर ब_अक्षर_प्रकार *nptr,ब_अक्षर_प्रकार **endptr, पूर्णांक base);
#पूर्ण_अगर /* __NO_ISOCEXT */

  व्योम *__cdecl स_हटाओ(व्योम *_Dst,स्थिर व्योम *_Src,माप_प्रकार Max_गिनती);
  व्योम *__cdecl स_नकल(व्योम *_Dst,स्थिर व्योम *_Src,माप_प्रकार Max_गिनती);
  __CRT_INLINE पूर्णांक __cdecl fwide(खाता *_F,पूर्णांक _M) { (व्योम)_F; वापस (_M); }
  __CRT_INLINE पूर्णांक __cdecl mbsinit(स्थिर mbstate_t *_P) { वापस (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wmemchr(स्थिर ब_अक्षर_प्रकार *_S,ब_अक्षर_प्रकार _C,माप_प्रकार _N) { क्रम (;0<_N;++_S,--_N) अगर (*_S==_C) वापस (_CONST_RETURN ब_अक्षर_प्रकार *)(_S); वापस (0); }
  __CRT_INLINE पूर्णांक __cdecl wmemcmp(स्थिर ब_अक्षर_प्रकार *_S1,स्थिर ब_अक्षर_प्रकार *_S2,माप_प्रकार _N) { क्रम (; 0 < _N; ++_S1,++_S2,--_N) अगर (*_S1!=*_S2) वापस (*_S1 < *_S2 ? -1 : +1); वापस (0); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl wmemcpy(ब_अक्षर_प्रकार *_S1,स्थिर ब_अक्षर_प्रकार *_S2,माप_प्रकार _N) { वापस (ब_अक्षर_प्रकार *)स_नकल(_S1,_S2,_N*माप(ब_अक्षर_प्रकार)); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl wmemmove(ब_अक्षर_प्रकार *_S1,स्थिर ब_अक्षर_प्रकार *_S2,माप_प्रकार _N) { वापस (ब_अक्षर_प्रकार *)स_हटाओ(_S1,_S2,_N*माप(ब_अक्षर_प्रकार)); }
  __CRT_INLINE ब_अक्षर_प्रकार *__cdecl wmemset(ब_अक्षर_प्रकार *_S,ब_अक्षर_प्रकार _C,माप_प्रकार _N) {
    ब_अक्षर_प्रकार *_Su = _S;
    क्रम (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    वापस (_S);
  }
#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)

#समावेश <sec_api/wchar_s.h>
#पूर्ण_अगर
