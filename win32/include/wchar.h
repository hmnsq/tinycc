/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_WCHAR
#నిర్వచించు _INC_WCHAR

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WCHAR_MIN  /* also at stdint.h */
#నిర్వచించు WCHAR_MIN 0
#నిర్వచించు WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __GNUC_VA_LIST
#నిర్వచించు __GNUC_VA_LIST
  రకనిర్వచనం __builtin_va_list __gnuc_va_list;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _VA_LIST_DEFINED
#నిర్వచించు _VA_LIST_DEFINED
  రకనిర్వచనం __gnuc_va_list va_list;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WEOF
#నిర్వచించు WEOF (wint_t)(0xFFFF)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _FILE_DEFINED
  నిర్మాణం _iobuf {
    అక్షరం *_ptr;
    పూర్ణాంకం _cnt;
    అక్షరం *పునాది_4;
    పూర్ణాంకం _flag;
    పూర్ణాంకం _file;
    పూర్ణాంకం _charbuf;
    పూర్ణాంకం _bufsiz;
    అక్షరం *_tmpfname;
  };
  రకనిర్వచనం నిర్మాణం _iobuf FILE;
#నిర్వచించు _FILE_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STDIO_DEFINED
#నిర్వచితమైతే _WIN64
  _CRTIMP FILE *__cdecl __iob_func(శూన్య);
#లేకపోతే
#నిర్వచితమైతే _MSVCRT_
బాహ్య FILE _iob[];	/* A pointer to an array of FILE */
#నిర్వచించు __iob_func()	(_iob)
#లేకపోతే
బాహ్య FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#నిర్వచించు __iob_func()	(*_imp___iob)
#నిర్వచించు _iob __iob_func()
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _iob __iob_func()
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STDSTREAM_DEFINED
#నిర్వచించు stdin (&__iob_func()[0])
#నిర్వచించు stdout (&__iob_func()[1])
#నిర్వచించు stderr (&__iob_func()[2])
#నిర్వచించు _STDSTREAM_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _FSIZE_T_DEFINED
  రకనిర్వచనం గుర్తులేని దీర్ఘ _fsize_t;
#నిర్వచించు _FSIZE_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WFINDDATA_T_DEFINED
  నిర్మాణం _wfinddata32_t {
    గుర్తులేని attrib;
    __time32_t సమయం_create;
    __time32_t సమయం_access;
    __time32_t సమయం_write;
    _fsize_t కొలత;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  నిర్మాణం _wfinddata32i64_t {
    గుర్తులేని attrib;
    __time32_t సమయం_create;
    __time32_t సమయం_access;
    __time32_t సమయం_write;
    __int64 కొలత;
    wchar_t name[260];
  };

  నిర్మాణం _wfinddata64i32_t {
    గుర్తులేని attrib;
    __time64_t సమయం_create;
    __time64_t సమయం_access;
    __time64_t సమయం_write;
    _fsize_t కొలత;
    wchar_t name[260];
  };

  నిర్మాణం _wfinddata64_t {
    గుర్తులేని attrib;
    __time64_t సమయం_create;
    __time64_t సమయం_access;
    __time64_t సమయం_write;
    __int64 కొలత;
    wchar_t name[260];
  };
/* #endif */

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచించు _wfinddata_t _wfinddata32_t
#నిర్వచించు _wfinddatai64_t _wfinddata32i64_t

#నిర్వచించు _wfindfirst _wfindfirst32
#నిర్వచించు _wfindnext _wfindnext32
#నిర్వచించు _wfindfirsti64 _wfindfirst32i64
#నిర్వచించు _wfindnexti64 _wfindnext32i64
#లేకపోతే
#నిర్వచించు _wfinddata_t _wfinddata64i32_t
#నిర్వచించు _wfinddatai64_t _wfinddata64_t

#నిర్వచించు _wfindfirst _wfindfirst64i32
#నిర్వచించు _wfindnext _wfindnext64i32
#నిర్వచించు _wfindfirsti64 _wfindfirst64
#నిర్వచించు _wfindnexti64 _wfindnext64
#అయితే_ముగింపు

#నిర్వచించు _WFINDDATA_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CONST_RETURN
#నిర్వచించు _CONST_RETURN
#అయితే_ముగింపు

#నిర్వచించు _WConst_return _CONST_RETURN

#నిర్వచితం_కాకపోతే _CRT_CTYPEDATA_DEFINED
#నిర్వచించు _CRT_CTYPEDATA_DEFINED
#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS

#నిర్వచితం_కాకపోతే __PCTYPE_FUNC
#నిర్వచించు __PCTYPE_FUNC __pctype_func()
#నిర్వచితమైతే _MSVCRT_
#నిర్వచించు __pctype_func() (_pctype)
#లేకపోతే
#నిర్వచించు __pctype_func() (*_imp___pctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _pctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_pctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___pctype;
#నిర్వచించు _pctype (*_imp___pctype)
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_WCTYPEDATA_DEFINED
#నిర్వచించు _CRT_WCTYPEDATA_DEFINED
#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS
#నిర్వచితం_కాకపోతే _wctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_wctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___wctype;
#నిర్వచించు _wctype (*_imp___wctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే _MSVCRT_
#నిర్వచించు __pwctype_func() (_pwctype)
#లేకపోతే
#నిర్వచించు __pwctype_func() (*_imp___pwctype)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _pwctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_pwctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___pwctype;
#నిర్వచించు _pwctype (*_imp___pwctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు పై_3 0x1
#నిర్వచించు క్రింది_2 0x2
#నిర్వచించు _DIGIT 0x4
#నిర్వచించు _SPACE 0x8

#నిర్వచించు _PUNCT 0x10
#నిర్వచించు _CONTROL 0x20
#నిర్వచించు _BLANK 0x40
#నిర్వచించు _HEX 0x80

#నిర్వచించు _LEADBYTE 0x8000
#నిర్వచించు _ALPHA (0x0100|పై_3|క్రింది_2)

#నిర్వచితం_కాకపోతే _WCTYPE_DEFINED
#నిర్వచించు _WCTYPE_DEFINED

  పూర్ణాంకం __cdecl iswalpha(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswupper(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswlower(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswdigit(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswxdigit(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswspace(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswpunct(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswalnum(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswprint(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswgraph(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswcntrl(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswascii(wint_t _C);
  పూర్ణాంకం __cdecl isleadbyte(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isleadbyte_l(పూర్ణాంకం _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP పూర్ణాంకం __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl __iswcsymf(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl __iswcsym(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl is_wctype(wint_t _C,wctype_t _Type);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WDIRECT_DEFINED
#నిర్వచించు _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,పూర్ణాంకం కొలత_లోపల_పదాలు);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(పూర్ణాంకం _Drive,wchar_t *_DstBuf,పూర్ణాంకం కొలత_లోపల_పదాలు);
  wchar_t *__cdecl _wgetdcwd_nolock(పూర్ణాంకం _Drive,wchar_t *_DstBuf,పూర్ణాంకం కొలత_లోపల_పదాలు);
  _CRTIMP పూర్ణాంకం __cdecl _wchdir(స్థిరరాశి wchar_t *మార్గం_2);
  _CRTIMP పూర్ణాంకం __cdecl _wmkdir(స్థిరరాశి wchar_t *మార్గం_2);
  _CRTIMP పూర్ణాంకం __cdecl _wrmdir(స్థిరరాశి wchar_t *మార్గం_2);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WIO_DEFINED
#నిర్వచించు _WIO_DEFINED

  _CRTIMP పూర్ణాంకం __cdecl _waccess(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం Access_బహుళకం);
  _CRTIMP పూర్ణాంకం __cdecl _wchmod(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం బహుళకం_3);
  _CRTIMP పూర్ణాంకం __cdecl _wcreat(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం Permission_బహుళకం);
  _CRTIMP intptr_t __cdecl _wfindfirst32(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wfindnext32(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wunlink(స్థిరరాశి wchar_t *_Filename);
  _CRTIMP పూర్ణాంకం __cdecl _wrename(స్థిరరాశి wchar_t *_NewFilename,స్థిరరాశి wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata32i64_t *కనుగొను_దత్తాంశం);
  intptr_t __cdecl _wfindfirst64i32(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata64i32_t *కనుగొను_దత్తాంశం);
  _CRTIMP intptr_t __cdecl _wfindfirst64(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata64_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wfindnext32i64(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata32i64_t *కనుగొను_దత్తాంశం);
  పూర్ణాంకం __cdecl _wfindnext64i32(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata64i32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wfindnext64(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata64_t *కనుగొను_దత్తాంశం);
#అయితే_ముగింపు
  _CRTIMP errno_t __cdecl _wsopen_s(పూర్ణాంకం *_FileHandle,స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,పూర్ణాంకం _PermissionFlag);
#ఒకవేళ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP పూర్ణాంకం __cdecl _wopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,...);
  _CRTIMP పూర్ణాంకం __cdecl _wsopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,...);
#లేకపోతే
  బాహ్య "C++" _CRTIMP పూర్ణాంకం __cdecl _wopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం Permission_బహుళకం = 0);
  బాహ్య "C++" _CRTIMP పూర్ణాంకం __cdecl _wsopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,పూర్ణాంకం Permission_బహుళకం = 0);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WLOCALE_DEFINED
#నిర్వచించు _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(పూర్ణాంకం _Category,స్థిరరాశి wchar_t *_Locale);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WPROCESS_DEFINED
#నిర్వచించు _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
#నిర్వచితం_కాకపోతే _CRT_WSYSTEM_DEFINED
#నిర్వచించు _CRT_WSYSTEM_DEFINED
  _CRTIMP పూర్ణాంకం __cdecl _wsystem(స్థిరరాశి wchar_t *_Command);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCTYPE_INLINE_DEFINED
#నిర్వచనం_రద్దు _CRT_WCTYPE_NOINLINE
#ఒకవేళ !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#నిర్వచించు iswalpha(_c) (iswctype(_c,_ALPHA))
#నిర్వచించు iswupper(_c) (iswctype(_c,పై_3))
#నిర్వచించు iswlower(_c) (iswctype(_c,క్రింది_2))
#నిర్వచించు iswdigit(_c) (iswctype(_c,_DIGIT))
#నిర్వచించు iswxdigit(_c) (iswctype(_c,_HEX))
#నిర్వచించు iswspace(_c) (iswctype(_c,_SPACE))
#నిర్వచించు iswpunct(_c) (iswctype(_c,_PUNCT))
#నిర్వచించు iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#నిర్వచించు iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#నిర్వచించు iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#నిర్వచించు iswcntrl(_c) (iswctype(_c,_CONTROL))
#నిర్వచించు iswascii(_c) ((గుర్తులేని)(_c) < 0x80)

#నిర్వచించు _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#నిర్వచించు _iswupper_l(_c,_p) (_iswctype_l(_c,పై_3,_p))
#నిర్వచించు _iswlower_l(_c,_p) (_iswctype_l(_c,క్రింది_2,_p))
#నిర్వచించు _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#నిర్వచించు _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#నిర్వచించు _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#నిర్వచించు _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#నిర్వచించు _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#నిర్వచించు _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#నిర్వచించు _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#నిర్వచించు _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS
#నిర్వచించు isleadbyte(_c) (__PCTYPE_FUNC[(గుర్తులేని అక్షరం)(_c)] & _LEADBYTE)
#అయితే_ముగింపు
#అయితే_ముగింపు
#నిర్వచించు _WCTYPE_INLINE_DEFINED
#అయితే_ముగింపు

#ఒకవేళ !defined(_POSIX_) || defined(__GNUC__)
#నిర్వచితం_కాకపోతే _INO_T_DEFINED
#నిర్వచించు _INO_T_DEFINED
  రకనిర్వచనం గుర్తులేని పొట్టి _ino_t;
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  రకనిర్వచనం గుర్తులేని పొట్టి ino_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _DEV_T_DEFINED
#నిర్వచించు _DEV_T_DEFINED
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం _dev_t;
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం dev_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _OFF_T_DEFINED
#నిర్వచించు _OFF_T_DEFINED
#నిర్వచితం_కాకపోతే _OFF_T_
#నిర్వచించు _OFF_T_
  రకనిర్వచనం దీర్ఘ _off_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ off_t;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _OFF64_T_DEFINED
#నిర్వచించు _OFF64_T_DEFINED
  రకనిర్వచనం దీర్ఘ దీర్ఘ _off64_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ దీర్ఘ off64_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STAT_DEFINED
#నిర్వచించు _STAT_DEFINED

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచితమైతే WIN64
#నిర్వచించు _fstat _fstat32
#నిర్వచించు _stat _stat32
#నిర్వచించు _wstat _wstat32
#లేకపోతే
#నిర్వచించు _fstat32 _fstat
#నిర్వచించు _stat32 _stat
#నిర్వచించు _wstat32 _wstat
#అయితే_ముగింపు
#నిర్వచించు _fstati64 _fstat32i64
#నిర్వచించు _stati64 _stat32i64
#నిర్వచించు _wstati64 _wstat32i64
#లేకపోతే
#నిర్వచించు _fstat _fstat64i32
#నిర్వచించు _fstati64 _fstat64
#నిర్వచించు _stat _stat64i32
#నిర్వచించు _stati64 _stat64
#నిర్వచించు _wstat _wstat64i32
#నిర్వచించు _wstati64 _wstat64
#అయితే_ముగింపు

  నిర్మాణం _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    _off_t st_కొలత;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  నిర్మాణం stat {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    _off_t st_కొలత;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64

  నిర్మాణం _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    __int64 st_కొలత;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  నిర్మాణం _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    _off_t st_కొలత;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  నిర్మాణం _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    __int64 st_కొలత;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#అయితే_ముగింపు

#నిర్వచించు __stat64 _stat64

#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTAT_DEFINED
#నిర్వచించు _WSTAT_DEFINED

  _CRTIMP పూర్ణాంకం __cdecl _wstat32(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat32 *_Stat);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP పూర్ణాంకం __cdecl _wstat32i64(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat32i64 *_Stat);
  పూర్ణాంకం __cdecl _wstat64i32(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat64i32 *_Stat);
  _CRTIMP పూర్ణాంకం __cdecl _wstat64(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat64 *_Stat);
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCONIO_DEFINED
#నిర్వచించు _WCONIO_DEFINED

#నిర్వచితం_కాకపోతే WEOF
#నిర్వచించు WEOF (wint_t)(0xFFFF)
#అయితే_ముగింపు

  _CRTIMP wchar_t *_cgetws(wchar_t *బఫరు_2);
  _CRTIMP wint_t __cdecl _getwch(శూన్య);
  _CRTIMP wint_t __cdecl _getwche(శూన్య);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP పూర్ణాంకం __cdecl _cputws(స్థిరరాశి wchar_t *_String);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_p(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_p(స్థిరరాశి wchar_t *_Format,va_list _ArgList);

  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(శూన్య);
  wint_t __cdecl _getwche_nolock(శూన్య);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTDIO_DEFINED
#నిర్వచించు _WSTDIO_DEFINED

#నిర్వచితం_కాకపోతే WEOF
#నిర్వచించు WEOF (wint_t)(0xFFFF)
#అయితే_ముగింపు

#నిర్వచితమైతే _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3);
#లేకపోతే
  _CRTIMP FILE *__cdecl _wfsopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3,పూర్ణాంకం _ShFlag);
#అయితే_ముగింపు

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(శూన్య);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(శూన్య);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,పూర్ణాంకం కొలత_లోపల_పదాలు,FILE *_File);
  పూర్ణాంకం __cdecl fputws(స్థిరరాశి wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP పూర్ణాంకం __cdecl _putws(స్థిరరాశి wchar_t *_Str);
  పూర్ణాంకం __cdecl fwprintf(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl wprintf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf(స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl vfwprintf(FILE *_File,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl vwprintf(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl swprintf(wchar_t*, స్థిరరాశి wchar_t*, ...);
  _CRTIMP పూర్ణాంకం __cdecl vswprintf(wchar_t*, స్థిరరాశి wchar_t*,va_list);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_c(wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_c(wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snwprintf(wchar_t *_Dest,కొలత_t లెక్క_5,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnwprintf(wchar_t *_Dest,కొలత_t లెక్క_5,స్థిరరాశి wchar_t *_Format,va_list వాదనలు_2);
#నిర్వచితం_కాకపోతే __NO_ISOCEXT  /* externs in libmingwex.a */
  పూర్ణాంకం __cdecl snwprintf (wchar_t *s, కొలత_t n, స్థిరరాశి wchar_t * format, ...);
  __CRT_INLINE పూర్ణాంకం __cdecl vsnwprintf (wchar_t *s, కొలత_t n, స్థిరరాశి wchar_t *format, va_list arg) { తిరిగి _vsnwprintf(s,n,format,arg); }
  పూర్ణాంకం __cdecl vwscanf (స్థిరరాశి wchar_t *, va_list);
  పూర్ణాంకం __cdecl vfwscanf (FILE *,స్థిరరాశి wchar_t *,va_list);
  పూర్ణాంకం __cdecl vswscanf (స్థిరరాశి wchar_t *,స్థిరరాశి wchar_t *,va_list);
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _fwprintf_p(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _wprintf_p(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfwprintf_p(FILE *_File,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vwprintf_p(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_p(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_p(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf_p(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf_p(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _wprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _wprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _fwprintf_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _fwprintf_p_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vfwprintf_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vfwprintf_p_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_c_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_p_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_c_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_p_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snwprintf_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnwprintf_l(wchar_t *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,va_list వాదనలు_2);
  _CRTIMP పూర్ణాంకం __cdecl __swprintf_l(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP పూర్ణాంకం __cdecl __vswprintf_l(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,_locale_t _Plocinfo,va_list వాదనలు_2);
#నిర్వచితం_కాకపోతే RC_INVOKED
#అన్తర్భావ <vadefs.h>
#అయితే_ముగింపు

#నిర్వచితమైతే _CRT_NON_CONFORMING_SWPRINTFS
#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచించు swprintf _swprintf
#నిర్వచించు vswprintf _vswprintf
#నిర్వచించు _swprintf_l __swprintf_l
#నిర్వచించు _vswprintf_l __vswprintf_l
#అయితే_ముగింపు
#అయితే_ముగింపు

  _CRTIMP wchar_t *__cdecl _wtempnam(స్థిరరాశి wchar_t *_Directory,స్థిరరాశి wchar_t *File_ఉపసర్గ);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  పూర్ణాంకం __cdecl fwscanf(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _fwscanf_l(FILE *_File,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  పూర్ణాంకం __cdecl swscanf(స్థిరరాశి wchar_t *_Src,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _swscanf_l(స్థిరరాశి wchar_t *_Src,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _snwscanf(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _snwscanf_l(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  పూర్ణాంకం __cdecl wscanf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _wscanf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(పూర్ణాంకం _FileHandle ,స్థిరరాశి wchar_t *బహుళకం_3);
  _CRTIMP FILE *__cdecl _wfopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3);
  _CRTIMP FILE *__cdecl _wfreopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3,FILE *_OldFile);

#నిర్వచితం_కాకపోతే _CRT_WPERROR_DEFINED
#నిర్వచించు _CRT_WPERROR_DEFINED
  _CRTIMP శూన్య __cdecl _wperror(స్థిరరాశి wchar_t *Err_సందేశం);
#అయితే_ముగింపు
  _CRTIMP FILE *__cdecl _wpopen(స్థిరరాశి wchar_t *_Command,స్థిరరాశి wchar_t *బహుళకం_3);
#ఒకవేళ !defined(NO_OLDNAMES) && !defined(wpopen)
#నిర్వచించు wpopen	_wpopen
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _wremove(స్థిరరాశి wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *బఫరు_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#నిర్వచనం_రద్దు _CRT_GETPUTWCHAR_NOINLINE

#ఒకవేళ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#నిర్వచించు getwchar() fgetwc(stdin)
#నిర్వచించు putwchar(_c) fputwc((_c),stdout)
#లేకపోతే
  __CRT_INLINE wint_t __cdecl getwchar() {తిరిగి (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {తిరిగి (fputwc(_C,stdout)); }
#అయితే_ముగింపు

#నిర్వచించు getwc(_stm) fgetwc(_stm)
#నిర్వచించు putwc(_c,_stm) fputwc(_c,_stm)
#నిర్వచించు _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#నిర్వచించు _getwc_nolock(_c) _fgetwc_nolock(_c)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTDLIB_DEFINED
#నిర్వచించు _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(పూర్ణాంకం విలువ_2,wchar_t *_Dest,పూర్ణాంకం _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(దీర్ఘ విలువ_2,wchar_t *_Dest,పూర్ణాంకం _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(గుర్తులేని దీర్ఘ విలువ_2,wchar_t *_Dest,పూర్ణాంకం _Radix);
  ద్విగుణ __cdecl wcstod(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr);
  _CRTIMP ద్విగుణ __cdecl _wcstod_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,_locale_t _Locale);
  దశాంశం __cdecl wcstof( స్థిరరాశి wchar_t *nptr, wchar_t **endptr);
#ఒకవేళ !defined __NO_ISOCEXT /* in libmingwex.a */
  దశాంశం __cdecl wcstof (స్థిరరాశి wchar_t * __restrict__, wchar_t ** __restrict__);
  దీర్ఘ ద్విగుణ __cdecl wcstold (స్థిరరాశి wchar_t * __restrict__, wchar_t ** __restrict__);
#అయితే_ముగింపు /* __NO_ISOCEXT */
  దీర్ఘ __cdecl wcstol(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP దీర్ఘ __cdecl _wcstol_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  గుర్తులేని దీర్ఘ __cdecl wcstoul(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP గుర్తులేని దీర్ఘ __cdecl _wcstoul_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(స్థిరరాశి wchar_t *_VarName);
#నిర్వచితం_కాకపోతే _CRT_WSYSTEM_DEFINED
#నిర్వచించు _CRT_WSYSTEM_DEFINED
  _CRTIMP పూర్ణాంకం __cdecl _wsystem(స్థిరరాశి wchar_t *_Command);
#అయితే_ముగింపు
  _CRTIMP ద్విగుణ __cdecl _wtof(స్థిరరాశి wchar_t *_Str);
  _CRTIMP ద్విగుణ __cdecl _wtof_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wtoi(స్థిరరాశి wchar_t *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _wtoi_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);
  _CRTIMP దీర్ఘ __cdecl _wtol(స్థిరరాశి wchar_t *_Str);
  _CRTIMP దీర్ఘ __cdecl _wtol_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,పూర్ణాంకం _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(గుర్తులేని __int64 _Val,wchar_t *_DstBuf,పూర్ణాంకం _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(స్థిరరాశి wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  _CRTIMP గుర్తులేని __int64 __cdecl _wcstoui64(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP గుర్తులేని __int64 __cdecl _wcstoui64_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _POSIX_
#నిర్వచితం_కాకపోతే _WSTDLIBP_DEFINED
#నిర్వచించు _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *నిండిన_మార్గం,స్థిరరాశి wchar_t *మార్గం_2,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP శూన్య __cdecl _wmakepath(wchar_t *ఫలితం_మార్గం,స్థిరరాశి wchar_t *_Drive,స్థిరరాశి wchar_t *_Dir,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_Ext);
#నిర్వచితం_కాకపోతే _CRT_WPERROR_DEFINED
#నిర్వచించు _CRT_WPERROR_DEFINED
  _CRTIMP శూన్య __cdecl _wperror(స్థిరరాశి wchar_t *Err_సందేశం);
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _wputenv(స్థిరరాశి wchar_t *_EnvString);
  _CRTIMP శూన్య __cdecl _wsearchenv(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_EnvVar,wchar_t *ఫలితం_మార్గం);
  _CRTIMP శూన్య __cdecl _wsplitpath(స్థిరరాశి wchar_t *నిండిన_మార్గం,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTRING_DEFINED
#నిర్వచించు _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(స్థిరరాశి wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(స్థిరరాశి wchar_t *_Str,wchar_t _Ch);
  పూర్ణాంకం __cdecl wcscmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3);
  కొలత_t __cdecl wcscspn(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_Control);
  కొలత_t __cdecl wcslen(స్థిరరాశి wchar_t *_Str);
  కొలత_t __cdecl wcsnlen(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3,కొలత_t లెక్క_5);
  పూర్ణాంకం __cdecl wcsncmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3,కొలత_t లెక్క_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(స్థిరరాశి wchar_t *_Str,wchar_t _Ch);
  కొలత_t __cdecl wcsspn(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,స్థిరరాశి wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(పూర్ణాంకం Err_అంకె);
  _CRTIMP wchar_t *__cdecl __wcserror(స్థిరరాశి wchar_t *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicmp_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicmp_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,కొలత_t Max_లెక్క);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  కొలత_t __cdecl wcsxfrm(wchar_t *_Dst,స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _wcsxfrm_l(wchar_t *_Dst,స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  పూర్ణాంకం __cdecl wcscoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _wcscoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsncoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _wcsncoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(స్థిరరాశి wchar_t *_Str);
#నిర్వచించు wcswcs wcsstr
  పూర్ణాంకం __cdecl wcsicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  పూర్ణాంకం __cdecl wcsnicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,కొలత_t Max_లెక్క);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  పూర్ణాంకం __cdecl wcsicoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TM_DEFINED
#నిర్వచించు _TM_DEFINED
  నిర్మాణం tm {
    పూర్ణాంకం tm_sec;
    పూర్ణాంకం tm_min;
    పూర్ణాంకం tm_hour;
    పూర్ణాంకం tm_mday;
    పూర్ణాంకం tm_mon;
    పూర్ణాంకం tm_year;
    పూర్ణాంకం tm_wday;
    పూర్ణాంకం tm_yday;
    పూర్ణాంకం tm_isdst;
  };
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WTIME_DEFINED
#నిర్వచించు _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(స్థిరరాశి __time32_t *సమయం_2);
  కొలత_t __cdecl wcsftime(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,స్థిరరాశి నిర్మాణం tm *_Tm);
  _CRTIMP కొలత_t __cdecl _wcsftime_l(wchar_t *_Buf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,స్థిరరాశి నిర్మాణం tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *బఫరు_2);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *బఫరు_2);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(స్థిరరాశి __time64_t *సమయం_2);
#అయితే_ముగింపు

#ఒకవేళ !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#నిర్వచించు _INC_WTIME_INL
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE wchar_t *__cdecl _wctime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime32(సమయం_2); }
#లేకపోతే
__CRT_INLINE wchar_t *__cdecl _wctime(స్థిరరాశి time_t *సమయం_2) { తిరిగి _wctime64(సమయం_2); }
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

  రకనిర్వచనం పూర్ణాంకం mbstate_t;
  రకనిర్వచనం wchar_t _Wint_t;

  wint_t __cdecl btowc(పూర్ణాంకం);
  కొలత_t __cdecl mbrlen(స్థిరరాశి అక్షరం *_Ch,కొలత_t కొలత_లోపల_బైట్లు,mbstate_t *_State);
  కొలత_t __cdecl mbrtowc(wchar_t *_DstCh,స్థిరరాశి అక్షరం *_SrcCh,కొలత_t కొలత_లోపల_బైట్లు,mbstate_t *_State);
  కొలత_t __cdecl mbsrtowcs(wchar_t *_Dest,స్థిరరాశి అక్షరం **_PSrc,కొలత_t లెక్క_5,mbstate_t *_State);
  కొలత_t __cdecl wcrtomb(అక్షరం *_Dest,wchar_t ఆధారం_3,mbstate_t *_State);
  కొలత_t __cdecl wcsrtombs(అక్షరం *_Dest,స్థిరరాశి wchar_t **_PSource,కొలత_t లెక్క_5,mbstate_t *_State);
  పూర్ణాంకం __cdecl wctob(wint_t _WCh);

#నిర్వచితం_కాకపోతే __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, కొలత_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(స్థిరరాశి wchar_t *s, wchar_t c, కొలత_t n);
  పూర్ణాంకం wmemcmp(స్థిరరాశి wchar_t *s1, స్థిరరాశి wchar_t *s2,కొలత_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,స్థిరరాశి wchar_t *s2,కొలత_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, స్థిరరాశి wchar_t *s2, కొలత_t n);
  దీర్ఘ దీర్ఘ __cdecl wcstoll(స్థిరరాశి wchar_t *nptr,wchar_t **endptr, పూర్ణాంకం పునాది);
  గుర్తులేని దీర్ఘ దీర్ఘ __cdecl wcstoull(స్థిరరాశి wchar_t *nptr,wchar_t **endptr, పూర్ణాంకం పునాది);
#అయితే_ముగింపు /* __NO_ISOCEXT */

  శూన్య *__cdecl memmove(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,కొలత_t Max_లెక్క);
  శూన్య *__cdecl జ్ఞాపకం_నకలు(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,కొలత_t Max_లెక్క);
  __CRT_INLINE పూర్ణాంకం __cdecl fwide(FILE *_F,పూర్ణాంకం _M) { (శూన్య)_F; తిరిగి (_M); }
  __CRT_INLINE పూర్ణాంకం __cdecl mbsinit(స్థిరరాశి mbstate_t *_P) { తిరిగి (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(స్థిరరాశి wchar_t *_S,wchar_t _C,కొలత_t _N) { కొరకు (;0<_N;++_S,--_N) ఒకవేళ (*_S==_C) తిరిగి (_CONST_RETURN wchar_t *)(_S); తిరిగి (0); }
  __CRT_INLINE పూర్ణాంకం __cdecl wmemcmp(స్థిరరాశి wchar_t *_S1,స్థిరరాశి wchar_t *_S2,కొలత_t _N) { కొరకు (; 0 < _N; ++_S1,++_S2,--_N) ఒకవేళ (*_S1!=*_S2) తిరిగి (*_S1 < *_S2 ? -1 : +1); తిరిగి (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,స్థిరరాశి wchar_t *_S2,కొలత_t _N) { తిరిగి (wchar_t *)జ్ఞాపకం_నకలు(_S1,_S2,_N*పరిమాణం(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,స్థిరరాశి wchar_t *_S2,కొలత_t _N) { తిరిగి (wchar_t *)memmove(_S1,_S2,_N*పరిమాణం(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,కొలత_t _N) {
    wchar_t *_Su = _S;
    కొరకు (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    తిరిగి (_S);
  }
#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)

#అన్తర్భావ <sec_api/wchar_s.h>
#అయితే_ముగింపు
