/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_STDLIB
#परिभाषय _INC_STDLIB

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <limits.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय EXIT_SUCCESS 0
#परिभाषय EXIT_FAILURE 1

#यदि_अपरिभाषितम् _ONEXIT_T_DEFINED
#परिभाषय _ONEXIT_T_DEFINED

  प्रकारनिर्देश पूर्णाङ्क (__cdecl *_onexit_t)(शून्य);

#यदि_अपरिभाषितम् NO_OLDNAMES
#परिभाषय onexit_t _onexit_t
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _DIV_T_DEFINED
#परिभाषय _DIV_T_DEFINED

  प्रकारनिर्देश संरचना _div_t {
    पूर्णाङ्क quot;
    पूर्णाङ्क rem;
  } div_t;

  प्रकारनिर्देश संरचना _ldiv_t {
    दीर्घ quot;
    दीर्घ rem;
  } ldiv_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRT_DOUBLE_DEC
#परिभाषय _CRT_DOUBLE_DEC

#निर्देशः pack(4)
  प्रकारनिर्देश संरचना {
    अचिह्नित वर्ण ld[10];
  } _LDOUBLE;
#निर्देशः pack()

#परिभाषय _PTR_LD(x) ((अचिह्नित वर्ण *)(&(x)->ld))

  प्रकारनिर्देश संरचना {
    द्विगुण x;
  } _CRT_DOUBLE;

  प्रकारनिर्देश संरचना {
    भिन्न f;
  } _CRT_FLOAT;

#निर्देशः प्रक्षिप_macro("long")
#अपरिभाषय दीर्घ

  प्रकारनिर्देश संरचना {
    दीर्घ द्विगुण x;
  } _LONGDOUBLE;

#निर्देशः निष्कासय_macro("long")

#निर्देशः pack(4)
  प्रकारनिर्देश संरचना {
    अचिह्नित वर्ण ld12[12];
  } _LDBL12;
#निर्देशः pack()
#यदि_अन्तः

#परिभाषय RAND_MAX 0x7fff

#यदि_अपरिभाषितम् MB_CUR_MAX
#परिभाषय MB_CUR_MAX ___mb_cur_max_func()
#यदि_अपरिभाषितम् __mb_cur_max
#यदि_परिभाषितम् _MSVCRT_
  बाह्य पूर्णाङ्क __mb_cur_max;
#अन्यथा
#परिभाषय __mb_cur_max    (*_imp____mb_cur_max)
  बाह्य पूर्णाङ्क *_imp____mb_cur_max;
#यदि_अन्तः
#यदि_अन्तः
#यदि_परिभाषितम् _MSVCRT_
  बाह्य पूर्णाङ्क __mbcur_max;
#परिभाषय ___mb_cur_max_func() (__mb_cur_max)
#अन्यथा
  बाह्य पूर्णाङ्क* _imp____mbcur_max;
#परिभाषय ___mb_cur_max_func() (*_imp____mb_cur_max)
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय __max(a,b) (((a) > (b)) ? (a) : (b))
#परिभाषय __min(a,b) (((a) < (b)) ? (a) : (b))

#परिभाषय MAX_मार्गः_2 260
#परिभाषय _MAX_DRIVE 3
#परिभाषय _MAX_DIR 256
#परिभाषय _MAX_FNAME 256
#परिभाषय _MAX_EXT 256

#परिभाषय बहिर्गमनम्_गन्तव्यम्_DEFAULT 0
#परिभाषय बहिर्गमनम्_गन्तव्यम्_STDERR 1
#परिभाषय बहिर्गमनम्_गन्तव्यम्_MSGBOX 2
#परिभाषय _REPORT_ERRMODE 3

#परिभाषय WRITE_ABORT_सन्देशः 0x1
#परिभाषय _CALL_REPORTFAULT 0x2

#परिभाषय _MAX_ENV 32767

  प्रकारनिर्देश शून्य (__cdecl *_purecall_handler)(शून्य);

  _CRTIMP _purecall_handler __cdecl समुच्चयः_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(शून्य);

  प्रकारनिर्देश शून्य (__cdecl *_invalid_parameter_handler)(ध्रुव wchar_t *,ध्रुव wchar_t *,ध्रुव wchar_t *,अचिह्नित पूर्णाङ्क,uintptr_t);
  _invalid_parameter_handler __cdecl समुच्चयः_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(शून्य);

#यदि_अपरिभाषितम् _CRT_ERRNO_DEFINED
#परिभाषय _CRT_ERRNO_DEFINED
  _CRTIMP पूर्णाङ्क *__cdecl _errno(शून्य);
#परिभाषय errno (*_errno())
  errno_t __cdecl समुच्चयः_errno(पूर्णाङ्क मानम्_2);
  errno_t __cdecl _get_errno(पूर्णाङ्क *मानम्_2);
#यदि_अन्तः
  _CRTIMP अचिह्नित दीर्घ *__cdecl __doserrno(शून्य);
#परिभाषय _doserrno (*__doserrno())
  errno_t __cdecl समुच्चयः_doserrno(अचिह्नित दीर्घ मानम्_2);
  errno_t __cdecl _get_doserrno(अचिह्नित दीर्घ *मानम्_2);
#यदि_परिभाषितम् _MSVCRT_
  बाह्य वर्ण *_sys_errlist[];
  बाह्य पूर्णाङ्क _sys_nerr;
#अन्यथा
  _CRTIMP वर्ण *_sys_errlist[1];
  _CRTIMP पूर्णाङ्क _sys_nerr;
#यदि_अन्तः
#यदि (defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क *__cdecl __p___argc(शून्य);
  _CRTIMP वर्ण ***__cdecl __p___argv(शून्य);
  _CRTIMP wchar_t ***__cdecl __p___wargv(शून्य);
  _CRTIMP वर्ण ***__cdecl __p__environ(शून्य);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(शून्य);
  _CRTIMP वर्ण **__cdecl __p__pgmptr(शून्य);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(शून्य);
#यदि_अन्तः
#यदि_अपरिभाषितम् __argc
#यदि_परिभाषितम् _MSVCRT_
  बाह्य पूर्णाङ्क __argc;
#अन्यथा
#परिभाषय __argc (*_imp____argc)
  बाह्य पूर्णाङ्क *_imp____argc;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अपरिभाषितम् __argv
#यदि_परिभाषितम् _MSVCRT_
  बाह्य वर्ण **__argv;
#अन्यथा
#परिभाषय __argv  (*_imp____argv)
  बाह्य वर्ण ***_imp____argv;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अपरिभाषितम् __wargv
#यदि_परिभाषितम् _MSVCRT_
  बाह्य wchar_t **__wargv;
#अन्यथा
#परिभाषय __wargv (*_imp____wargv)
  बाह्य wchar_t ***_imp____wargv;
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् _POSIX_
  बाह्य वर्ण **environ;
#अन्यथा
#यदि_अपरिभाषितम् _environ
#यदि_परिभाषितम् _MSVCRT_
  बाह्य वर्ण **_environ;
#अन्यथा
#परिभाषय _environ (*_imp___environ)
  बाह्य वर्ण ***_imp___environ;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _wenviron
#यदि_परिभाषितम् _MSVCRT_
  बाह्य wchar_t **_wenviron;
#अन्यथा
#परिभाषय _wenviron       (*_imp___wenviron)
  बाह्य wchar_t ***_imp___wenviron;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
बाह्य पूर्णाङ्क __argc;
बाह्य वर्ण **__argv;
बाह्य wchar_t **__wargv;
बाह्य वर्ण **_environ;
बाह्य wchar_t **_wenviron;
#यदि_अन्तः

#यदि_अपरिभाषितम् _pgmptr
#यदि_परिभाषितम् _MSVCRT_
  बाह्य वर्ण *_pgmptr;
#अन्यथा
#परिभाषय _pgmptr (*_imp___pgmptr)
  बाह्य वर्ण **_imp___pgmptr;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _wpgmptr
#यदि_परिभाषितम् _MSVCRT_
  बाह्य wchar_t *_wpgmptr;
#अन्यथा
#परिभाषय _wpgmptr        (*_imp___wpgmptr)
  बाह्य wchar_t **_imp___wpgmptr;
#यदि_अन्तः
#यदि_अन्तः
  errno_t __cdecl _get_pgmptr(वर्ण **मानम्_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **मानम्_2);
#यदि_अपरिभाषितम् _fmode
#यदि_परिभाषितम् _MSVCRT_
  बाह्य पूर्णाङ्क _fmode;
#अन्यथा
#परिभाषय _fmode  (*_imp___fmode)
  बाह्य पूर्णाङ्क *_imp___fmode;
#यदि_अन्तः
#यदि_अन्तः
  _CRTIMP errno_t __cdecl समुच्चयः_fmode(पूर्णाङ्क बहुलकम्_3);
  _CRTIMP errno_t __cdecl _get_fmode(पूर्णाङ्क *_PMode);

#यदि_अपरिभाषितम् _osplatform
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित पूर्णाङ्क _osplatform;
#अन्यथा
#परिभाषय _osplatform (*_imp___osplatform)
  बाह्य अचिह्नित पूर्णाङ्क *_imp___osplatform;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _osver
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित पूर्णाङ्क _osver;
#अन्यथा
#परिभाषय _osver  (*_imp___osver)
  बाह्य अचिह्नित पूर्णाङ्क *_imp___osver;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _winver
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित पूर्णाङ्क _winver;
#अन्यथा
#परिभाषय _winver (*_imp___winver)
  बाह्य अचिह्नित पूर्णाङ्क *_imp___winver;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _winmajor
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित पूर्णाङ्क _winmajor;
#अन्यथा
#परिभाषय _winmajor       (*_imp___winmajor)
  बाह्य अचिह्नित पूर्णाङ्क *_imp___winmajor;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _winminor
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित पूर्णाङ्क _winminor;
#अन्यथा
#परिभाषय _winminor       (*_imp___winminor)
  बाह्य अचिह्नित पूर्णाङ्क *_imp___winminor;
#यदि_अन्तः
#यदि_अन्तः

  errno_t __cdecl _get_osplatform(अचिह्नित पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_osver(अचिह्नित पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_winver(अचिह्नित पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_winmajor(अचिह्नित पूर्णाङ्क *मानम्_2);
  errno_t __cdecl _get_winminor(अचिह्नित पूर्णाङ्क *मानम्_2);
#यदि_अपरिभाषितम् _countof
#यदि_अपरिभाषितम् __cplusplus
#परिभाषय _countof(_Array) (परिमाण(_Array) / परिमाण(_Array[0]))
#अन्यथा
  बाह्य "C++" {
    प्रतिरूपम् <typename _CountofType,आकार_t आकार_सम्बन्धि_Array> वर्ण (*__countof_helper(UNALIGNED _CountofType (&_Array)[आकार_सम्बन्धि_Array]))[आकार_सम्बन्धि_Array];
#परिभाषय _countof(_Array) परिमाण(*__countof_helper(_Array))
  }
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRT_TERMINATE_DEFINED
#परिभाषय _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW निर्गच्छ(पूर्णाङ्क संहिता_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णाङ्क संहिता_3) __MINGW_ATTRIB_NORETURN;
#यदि !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  शून्य __cdecl _Exit(पूर्णाङ्क) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN शून्य  __cdecl _Exit(पूर्णाङ्क स्थितिः)
  {  _exit(स्थितिः); }
#यदि_अन्तः

#निर्देशः प्रक्षिप_macro("abort")
#अपरिभाषय abort
  शून्य __cdecl __declspec(noreturn) abort(शून्य);
#निर्देशः निष्कासय_macro("abort")

#यदि_अन्तः

  _CRTIMP अचिह्नित पूर्णाङ्क __cdecl समुच्चयः_abort_behavior(अचिह्नित पूर्णाङ्क _Flags,अचिह्नित पूर्णाङ्क आवरणम्_2);

#यदि_अपरिभाषितम् _CRT_ABS_DEFINED
#परिभाषय _CRT_ABS_DEFINED
  पूर्णाङ्क __cdecl निरपेक्षम्(पूर्णाङ्क _X);
  दीर्घ __cdecl labs(दीर्घ _X);
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  __int64 __cdecl _abs64(__int64);
#यदि_अन्तः
  पूर्णाङ्क __cdecl atexit(शून्य (__cdecl *)(शून्य));
#यदि_अपरिभाषितम् _CRT_ATOF_DEFINED
#परिभाषय _CRT_ATOF_DEFINED
  द्विगुण __cdecl atof(ध्रुव वर्ण *_String);
  द्विगुण __cdecl _atof_l(ध्रुव वर्ण *_String,_locale_t _Locale);
#यदि_अन्तः
  पूर्णाङ्क __cdecl atoi(ध्रुव वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoi_l(ध्रुव वर्ण *_Str,_locale_t _Locale);
  दीर्घ __cdecl atol(ध्रुव वर्ण *_Str);
  _CRTIMP दीर्घ __cdecl _atol_l(ध्रुव वर्ण *_Str,_locale_t _Locale);
#यदि_अपरिभाषितम् _CRT_ALGO_DEFINED
#परिभाषय _CRT_ALGO_DEFINED
  शून्य *__cdecl bsearch(ध्रुव शून्य *कुञ्चिका_2,ध्रुव शून्य *आधारः_3,आकार_t अङ्कः_सम्बन्धि_Elements,आकार_t आकार_सम्बन्धि_Elements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(ध्रुव शून्य *,ध्रुव शून्य *));
  शून्य __cdecl शीघ्रं_क्रमय(शून्य *आधारः_3,आकार_t अङ्कः_सम्बन्धि_Elements,आकार_t आकार_सम्बन्धि_Elements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(ध्रुव शून्य *,ध्रुव शून्य *));
#यदि_अन्तः
  अचिह्नित ह्रस्व __cdecl _byteswap_ushort(अचिह्नित ह्रस्व _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  अचिह्नित __int64 __cdecl _byteswap_uint64(अचिह्नित __int64 _Int64);
#यदि_अन्तः
  div_t __cdecl भाजय(पूर्णाङ्क _Numerator,पूर्णाङ्क _Denominator);
  वर्ण *__cdecl getenv(ध्रुव वर्ण *_VarName);
  _CRTIMP वर्ण *__cdecl _itoa(पूर्णाङ्क मानम्_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP वर्ण *__cdecl _i64toa(__int64 _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP वर्ण *__cdecl _ui64toa(अचिह्नित __int64 _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ध्रुव वर्ण *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ध्रुव वर्ण *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ध्रुव वर्ण *_String,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ध्रुव वर्ण *_String,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
  _CRTIMP अचिह्नित __int64 __cdecl _strtoui64(ध्रुव वर्ण *_String,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP अचिह्नित __int64 __cdecl _strtoui64_l(ध्रुव वर्ण *_String,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
#यदि_अन्तः
  ldiv_t __cdecl ldiv(दीर्घ _Numerator,दीर्घ _Denominator);
  _CRTIMP वर्ण *__cdecl _ltoa(दीर्घ मानम्_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl mblen(ध्रुव वर्ण *_Ch,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _mblen_l(ध्रुव वर्ण *_Ch,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP आकार_t __cdecl _mbstrlen(ध्रुव वर्ण *_Str);
  _CRTIMP आकार_t __cdecl _mbstrlen_l(ध्रुव वर्ण *_Str,_locale_t _Locale);
  _CRTIMP आकार_t __cdecl _mbstrnlen(ध्रुव वर्ण *_Str,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _mbstrnlen_l(ध्रुव वर्ण *_Str,आकार_t Max_गणनम्,_locale_t _Locale);
  पूर्णाङ्क __cdecl mbtowc(wchar_t *_DstCh,ध्रुव वर्ण *_SrcCh,आकार_t Src_आकार_अन्तर्_अष्टकानि);
  _CRTIMP पूर्णाङ्क __cdecl _mbtowc_l(wchar_t *_DstCh,ध्रुव वर्ण *_SrcCh,आकार_t Src_आकार_अन्तर्_अष्टकानि,_locale_t _Locale);
  आकार_t __cdecl mbstowcs(wchar_t *_Dest,ध्रुव वर्ण *_Source,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _mbstowcs_l(wchar_t *_Dest,ध्रुव वर्ण *_Source,आकार_t Max_गणनम्,_locale_t _Locale);
  पूर्णाङ्क __cdecl यादृच्छिकम्(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl समुच्चयः_error_बहुलकम्(पूर्णाङ्क बहुलकम्_3);
  शून्य __cdecl बीजं_रोपय(अचिह्नित पूर्णाङ्क बीजम्);
  द्विगुण __cdecl strtod(ध्रुव वर्ण *_Str,वर्ण **अन्तः_Ptr);
#यदि !defined __NO_ISOCEXT  /* in libmingwex.a */
#यदि __TINYC__
  __CRT_INLINE भिन्न __cdecl strtof (ध्रुव वर्ण *p, वर्ण ** e) { प्रत्यागम strtod(p, e); }
  __CRT_INLINE दीर्घ द्विगुण __cdecl strtold(ध्रुव वर्ण *p, वर्ण ** e) { प्रत्यागम strtod(p, e); }
#अन्यथा
  भिन्न __cdecl strtof (ध्रुव वर्ण * __restrict__, वर्ण ** __restrict__);
  दीर्घ द्विगुण __cdecl strtold(ध्रुव वर्ण * __restrict__, वर्ण ** __restrict__);
#यदि_अन्तः
#अन्यथा
  भिन्न __cdecl strtof(ध्रुव वर्ण *nptr, वर्ण **endptr);
#यदि_अन्तः /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _strtod_l(ध्रुव वर्ण *_Str,वर्ण **अन्तः_Ptr,_locale_t _Locale);
  दीर्घ __cdecl strtol(ध्रुव वर्ण *_Str,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP दीर्घ __cdecl _strtol_l(ध्रुव वर्ण *_Str,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
  अचिह्नित दीर्घ __cdecl strtoul(ध्रुव वर्ण *_Str,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix);
  _CRTIMP अचिह्नित दीर्घ __cdecl _strtoul_l(ध्रुव वर्ण *_Str,वर्ण **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
#यदि_अपरिभाषितम् _CRT_SYSTEM_DEFINED
#परिभाषय _CRT_SYSTEM_DEFINED
  पूर्णाङ्क __cdecl system(ध्रुव वर्ण *_Command);
#यदि_अन्तः
  _CRTIMP वर्ण *__cdecl _ultoa(अचिह्नित दीर्घ मानम्_2,वर्ण *_Dest,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl wctomb(वर्ण *_MbCh,wchar_t _WCh);
  _CRTIMP पूर्णाङ्क __cdecl _wctomb_l(वर्ण *_MbCh,wchar_t _WCh,_locale_t _Locale);
  आकार_t __cdecl wcstombs(वर्ण *_Dest,ध्रुव wchar_t *_Source,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _wcstombs_l(वर्ण *_Dest,ध्रुव wchar_t *_Source,आकार_t Max_गणनम्,_locale_t _Locale);

#यदि_अपरिभाषितम् CRT_आवण्टनम्_DEFINED
#परिभाषय CRT_आवण्टनम्_DEFINED
  शून्य *__cdecl शून्यस्मृतिं_देहि(आकार_t अङ्कः_सम्बन्धि_Elements,आकार_t आकार_सम्बन्धि_Elements);
  शून्य __cdecl मुक्त(शून्य *स्मृतिः);
  शून्य *__cdecl स्मृतिं_देहि(आकार_t आकार_4);
  शून्य *__cdecl realloc(शून्य *स्मृतिः,आकार_t New_आकार);
  _CRTIMP शून्य *__cdecl _recalloc(शून्य *स्मृतिः,आकार_t गणनम्_5,आकार_t आकार_4);
  _CRTIMP शून्य __cdecl _aligned_free(शून्य *स्मृतिः);
  _CRTIMP शून्य *__cdecl _aligned_malloc(आकार_t आकार_4,आकार_t _Alignment);
  _CRTIMP शून्य *__cdecl aligned_विस्थापनम्_malloc(आकार_t आकार_4,आकार_t _Alignment,आकार_t विस्थापनम्_2);
  _CRTIMP शून्य *__cdecl _aligned_realloc(शून्य *स्मृतिः,आकार_t आकार_4,आकार_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_recalloc(शून्य *स्मृतिः,आकार_t गणनम्_5,आकार_t आकार_4,आकार_t _Alignment);
  _CRTIMP शून्य *__cdecl aligned_विस्थापनम्_realloc(शून्य *स्मृतिः,आकार_t आकार_4,आकार_t _Alignment,आकार_t विस्थापनम्_2);
  _CRTIMP शून्य *__cdecl aligned_विस्थापनम्_recalloc(शून्य *स्मृतिः,आकार_t गणनम्_5,आकार_t आकार_4,आकार_t _Alignment,आकार_t विस्थापनम्_2);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTDLIB_DEFINED
#परिभाषय _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(पूर्णाङ्क मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(दीर्घ मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(अचिह्नित दीर्घ मानम्_2,wchar_t *_Dest,पूर्णाङ्क _Radix);
  द्विगुण __cdecl wcstod(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr);
  भिन्न __cdecl wcstof(ध्रुव wchar_t *nptr, wchar_t **endptr);
#यदि !defined __NO_ISOCEXT /* in libmingwex.a */
  भिन्न __cdecl wcstof( ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
  दीर्घ द्विगुण __cdecl wcstold(ध्रुव wchar_t * __restrict__, wchar_t ** __restrict__);
#यदि_अन्तः /* __NO_ISOCEXT */
  _CRTIMP द्विगुण __cdecl _wcstod_l(ध्रुव wchar_t *_Str,wchar_t **अन्तः_Ptr,_locale_t _Locale);
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
  _CRTIMP अचिह्नित __int64 __cdecl _wcstoui64_l(ध्रुव wchar_t *_Str ,wchar_t **अन्तः_Ptr,पूर्णाङ्क _Radix,_locale_t _Locale);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _POSIX_
#परिभाषय _CVTBUFSIZE (309+40)
  _CRTIMP वर्ण *__cdecl _fullpath(वर्ण *पूर्णम्_मार्गः,ध्रुव वर्ण *मार्गः_2,आकार_t आकार_अन्तर्_अष्टकानि);
  _CRTIMP वर्ण *__cdecl _ecvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Digits,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP वर्ण *__cdecl _fcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  _CRTIMP वर्ण *__cdecl _gcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Digits,वर्ण *_DstBuf);
  _CRTIMP पूर्णाङ्क __cdecl _atodbl(_CRT_DOUBLE *परिणाम_2,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoldbl(_LDOUBLE *परिणाम_2,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atoflt(_CRT_FLOAT *परिणाम_2,वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _atodbl_l(_CRT_DOUBLE *परिणाम_2,वर्ण *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _atoldbl_l(_LDOUBLE *परिणाम_2,वर्ण *_Str,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _atoflt_l(_CRT_FLOAT *परिणाम_2,वर्ण *_Str,_locale_t _Locale);
  अचिह्नित दीर्घ __cdecl _lrotl(अचिह्नित दीर्घ _Val,पूर्णाङ्क सरणम्_2);
  अचिह्नित दीर्घ __cdecl _lrotr(अचिह्नित दीर्घ _Val,पूर्णाङ्क सरणम्_2);
  _CRTIMP शून्य __cdecl _makepath(वर्ण *मार्गः_2,ध्रुव वर्ण *_Drive,ध्रुव वर्ण *_Dir,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#यदि_अपरिभाषितम् _CRT_PERROR_DEFINED
#परिभाषय _CRT_PERROR_DEFINED
  शून्य __cdecl perror(ध्रुव वर्ण *Err_सन्देशः);
#यदि_अन्तः
  _CRTIMP पूर्णाङ्क __cdecl _putenv(ध्रुव वर्ण *_EnvString);
  अचिह्नित पूर्णाङ्क __cdecl _rotl(अचिह्नित पूर्णाङ्क _Val,पूर्णाङ्क सरणम्_2);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  अचिह्नित __int64 __cdecl _rotl64(अचिह्नित __int64 _Val,पूर्णाङ्क सरणम्_2);
#यदि_अन्तः
  अचिह्नित पूर्णाङ्क __cdecl _rotr(अचिह्नित पूर्णाङ्क _Val,पूर्णाङ्क सरणम्_2);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  अचिह्नित __int64 __cdecl _rotr64(अचिह्नित __int64 _Val,पूर्णाङ्क सरणम्_2);
#यदि_अन्तः
  _CRTIMP शून्य __cdecl _searchenv(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_EnvVar,वर्ण *परिणाम_मार्गः);
  _CRTIMP शून्य __cdecl _splitpath(ध्रुव वर्ण *पूर्णम्_मार्गः,वर्ण *_Drive,वर्ण *_Dir,वर्ण *_Filename,वर्ण *_Ext);
  _CRTIMP शून्य __cdecl _swab(वर्ण *_Buf1,वर्ण *_Buf2,पूर्णाङ्क आकार_अन्तर्_अष्टकानि);

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

  _CRTIMP शून्य __cdecl _beep(अचिह्नित _Frequency,अचिह्नित _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP शून्य __cdecl _seterrormode(पूर्णाङ्क बहुलकम्_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP शून्य __cdecl _sleep(अचिह्नित दीर्घ _Duration) __MINGW_ATTRIB_DEPRECATED;
#यदि_अन्तः

#यदि_अपरिभाषितम् NO_OLDNAMES
#यदि_अपरिभाषितम् _POSIX_
#यदि 0
#यदि_अपरिभाषितम् __cplusplus
#यदि_अपरिभाषितम् NOMINMAX
#यदि_अपरिभाषितम् max
#परिभाषय max(a,b) (((a) > (b)) ? (a) : (b))
#यदि_अन्तः
#यदि_अपरिभाषितम् min
#परिभाषय min(a,b) (((a) < (b)) ? (a) : (b))
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय sys_errlist _sys_errlist
#परिभाषय sys_nerr _sys_nerr
#परिभाषय environ _environ
  वर्ण *__cdecl ecvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Digits,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  वर्ण *__cdecl fcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Dec,पूर्णाङ्क *_PtDec,पूर्णाङ्क *_PtSign);
  वर्ण *__cdecl gcvt(द्विगुण _Val,पूर्णाङ्क अङ्कः_सम्बन्धि_Digits,वर्ण *_DstBuf);
  वर्ण *__cdecl itoa(पूर्णाङ्क _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  वर्ण *__cdecl ltoa(दीर्घ _Val,वर्ण *_DstBuf,पूर्णाङ्क _Radix);
  पूर्णाङ्क __cdecl putenv(ध्रुव वर्ण *_EnvString);
  शून्य __cdecl swab(वर्ण *_Buf1,वर्ण *_Buf2,पूर्णाङ्क आकार_अन्तर्_अष्टकानि);
  वर्ण *__cdecl ultoa(अचिह्नित दीर्घ _Val,वर्ण *_Dstbuf,पूर्णाङ्क _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#यदि_अन्तः
#यदि_अन्तः

#यदि !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  प्रकारनिर्देश संरचना { दीर्घ दीर्घ quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(दीर्घ दीर्घ, दीर्घ दीर्घ);

  __CRT_INLINE दीर्घ दीर्घ __cdecl llabs(दीर्घ दीर्घ _j) { प्रत्यागम (_j >= 0 ? _j : -_j); }

 #यदि_परिभाषितम् __TINYC__ /* gr */
  #परिभाषय strtoll _strtoi64
  #परिभाषय strtoull _strtoui64
 #अन्यथा
  दीर्घ दीर्घ  __cdecl strtoll(ध्रुव वर्ण* __restrict__, वर्ण** __restrict, पूर्णाङ्क);
  अचिह्नित दीर्घ दीर्घ  __cdecl strtoull(ध्रुव वर्ण* __restrict__, वर्ण** __restrict__, पूर्णाङ्क);
 #यदि_अन्तः

  /* these are stubs for MS _i64 versions */
  दीर्घ दीर्घ  __cdecl atoll (ध्रुव वर्ण *);

#यदि_अपरिभाषितम् __STRICT_ANSI__
  दीर्घ दीर्घ  __cdecl wtoll (ध्रुव wchar_t *);
  वर्ण *__cdecl lltoa (दीर्घ दीर्घ, वर्ण *, पूर्णाङ्क);
  वर्ण *__cdecl ulltoa (अचिह्नित दीर्घ दीर्घ , वर्ण *, पूर्णाङ्क);
  wchar_t *__cdecl lltow (दीर्घ दीर्घ, wchar_t *, पूर्णाङ्क);
  wchar_t *__cdecl ulltow (अचिह्नित दीर्घ दीर्घ, wchar_t *, पूर्णाङ्क);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE दीर्घ दीर्घ  __cdecl atoll (ध्रुव वर्ण * _c) { प्रत्यागम _atoi64 (_c); }
  __CRT_INLINE वर्ण *__cdecl lltoa (दीर्घ दीर्घ _n, वर्ण * _c, पूर्णाङ्क _i) { प्रत्यागम _i64toa (_n, _c, _i); }
  __CRT_INLINE वर्ण *__cdecl ulltoa (अचिह्नित दीर्घ दीर्घ _n, वर्ण * _c, पूर्णाङ्क _i) { प्रत्यागम _ui64toa (_n, _c, _i); }
  __CRT_INLINE दीर्घ दीर्घ  __cdecl wtoll (ध्रुव wchar_t * _w) { प्रत्यागम _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (दीर्घ दीर्घ _n, wchar_t * _w, पूर्णाङ्क _i) { प्रत्यागम _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (अचिह्नित दीर्घ दीर्घ _n, wchar_t * _w, पूर्णाङ्क _i) { प्रत्यागम _ui64tow (_n, _w, _i); }
#यदि_अन्तः /* (__STRICT_ANSI__)  */

#यदि_अन्तः /* !__NO_ISOCEXT */

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)

#अन्तर्भाव <sec_api/stdlib_s.h>
#अन्तर्भाव <malloc.h>

#यदि_अन्तः
