/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_STDLIB
#تعریف_کن _INC_STDLIB

#ضمن <_mingw.h>
#ضمن <limits.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#تعریف_کن EXIT_SUCCESS 0
#تعریف_کن EXIT_FAILURE 1

#اگر_تعریف_نشده _ONEXIT_T_DEFINED
#تعریف_کن _ONEXIT_T_DEFINED

  تعريفنوع صحيح (__cdecl *_onexit_t)(فراغ);

#اگر_تعریف_نشده NO_OLDNAMES
#تعریف_کن onexit_t _onexit_t
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _DIV_T_DEFINED
#تعریف_کن _DIV_T_DEFINED

  تعريفنوع بنية _div_t {
    صحيح quot;
    صحيح rem;
  } div_t;

  تعريفنوع بنية _ldiv_t {
    دراز quot;
    دراز rem;
  } ldiv_t;
#پایان_اگر

#اگر_تعریف_نشده _CRT_DOUBLE_DEC
#تعریف_کن _CRT_DOUBLE_DEC

#رهنمود pack(4)
  تعريفنوع بنية {
    بیعلامت حرف ld[10];
  } _LDOUBLE;
#رهنمود pack()

#تعریف_کن _PTR_LD(x) ((بیعلامت حرف *)(&(x)->ld))

  تعريفنوع بنية {
    مزدوج x;
  } _CRT_DOUBLE;

  تعريفنوع بنية {
    عائم f;
  } _CRT_FLOAT;

#رهنمود افزودن_macro("long")
#لغو_تعریف دراز

  تعريفنوع بنية {
    دراز مزدوج x;
  } _LONGDOUBLE;

#رهنمود برداشت_macro("long")

#رهنمود pack(4)
  تعريفنوع بنية {
    بیعلامت حرف ld12[12];
  } _LDBL12;
#رهنمود pack()
#پایان_اگر

#تعریف_کن RAND_MAX 0x7fff

#اگر_تعریف_نشده MB_CUR_MAX
#تعریف_کن MB_CUR_MAX ___mb_cur_max_func()
#اگر_تعریف_نشده __mb_cur_max
#اگر_تعریف_شده _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#تعریف_کن __mb_cur_max    (*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#پایان_اگر
#پایان_اگر
#اگر_تعریف_شده _MSVCRT_
  خارجي صحيح __mbcur_max;
#تعریف_کن ___mb_cur_max_func() (__mb_cur_max)
#وإلا
  خارجي صحيح* _imp____mbcur_max;
#تعریف_کن ___mb_cur_max_func() (*_imp____mb_cur_max)
#پایان_اگر
#پایان_اگر

#تعریف_کن __max(a,b) (((a) > (b)) ? (a) : (b))
#تعریف_کن __min(a,b) (((a) < (b)) ? (a) : (b))

#تعریف_کن MAX_مسیر_2 260
#تعریف_کن _MAX_DRIVE 3
#تعریف_کن _MAX_DIR 256
#تعریف_کن _MAX_FNAME 256
#تعریف_کن _MAX_EXT 256

#تعریف_کن بیرون_مقصد_DEFAULT 0
#تعریف_کن بیرون_مقصد_STDERR 1
#تعریف_کن بیرون_مقصد_MSGBOX 2
#تعریف_کن _REPORT_ERRMODE 3

#تعریف_کن WRITE_ABORT_پیام 0x1
#تعریف_کن _CALL_REPORTFAULT 0x2

#تعریف_کن _MAX_ENV 32767

  تعريفنوع فراغ (__cdecl *_purecall_handler)(فراغ);

  _CRTIMP _purecall_handler __cdecl مجموعه_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(فراغ);

  تعريفنوع فراغ (__cdecl *_invalid_parameter_handler)(ثابت wchar_t *,ثابت wchar_t *,ثابت wchar_t *,بیعلامت صحيح,uintptr_t);
  _invalid_parameter_handler __cdecl مجموعه_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(فراغ);

#اگر_تعریف_نشده _CRT_ERRNO_DEFINED
#تعریف_کن _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#تعریف_کن errno (*_errno())
  errno_t __cdecl مجموعه_errno(صحيح مقدار_2);
  errno_t __cdecl _get_errno(صحيح *مقدار_2);
#پایان_اگر
  _CRTIMP بیعلامت دراز *__cdecl __doserrno(فراغ);
#تعریف_کن _doserrno (*__doserrno())
  errno_t __cdecl مجموعه_doserrno(بیعلامت دراز مقدار_2);
  errno_t __cdecl _get_doserrno(بیعلامت دراز *مقدار_2);
#اگر_تعریف_شده _MSVCRT_
  خارجي حرف *_sys_errlist[];
  خارجي صحيح _sys_nerr;
#وإلا
  _CRTIMP حرف *_sys_errlist[1];
  _CRTIMP صحيح _sys_nerr;
#پایان_اگر
#إذا (defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح *__cdecl __p___argc(فراغ);
  _CRTIMP حرف ***__cdecl __p___argv(فراغ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(فراغ);
  _CRTIMP حرف ***__cdecl __p__environ(فراغ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(فراغ);
  _CRTIMP حرف **__cdecl __p__pgmptr(فراغ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(فراغ);
#پایان_اگر
#اگر_تعریف_نشده __argc
#اگر_تعریف_شده _MSVCRT_
  خارجي صحيح __argc;
#وإلا
#تعریف_کن __argc (*_imp____argc)
  خارجي صحيح *_imp____argc;
#پایان_اگر
#پایان_اگر
#اگر_تعریف_نشده __argv
#اگر_تعریف_شده _MSVCRT_
  خارجي حرف **__argv;
#وإلا
#تعریف_کن __argv  (*_imp____argv)
  خارجي حرف ***_imp____argv;
#پایان_اگر
#پایان_اگر
#اگر_تعریف_نشده __wargv
#اگر_تعریف_شده _MSVCRT_
  خارجي wchar_t **__wargv;
#وإلا
#تعریف_کن __wargv (*_imp____wargv)
  خارجي wchar_t ***_imp____wargv;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده _POSIX_
  خارجي حرف **environ;
#وإلا
#اگر_تعریف_نشده _environ
#اگر_تعریف_شده _MSVCRT_
  خارجي حرف **_environ;
#وإلا
#تعریف_کن _environ (*_imp___environ)
  خارجي حرف ***_imp___environ;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _wenviron
#اگر_تعریف_شده _MSVCRT_
  خارجي wchar_t **_wenviron;
#وإلا
#تعریف_کن _wenviron       (*_imp___wenviron)
  خارجي wchar_t ***_imp___wenviron;
#پایان_اگر
#پایان_اگر
#پایان_اگر

#إذا defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
خارجي صحيح __argc;
خارجي حرف **__argv;
خارجي wchar_t **__wargv;
خارجي حرف **_environ;
خارجي wchar_t **_wenviron;
#پایان_اگر

#اگر_تعریف_نشده _pgmptr
#اگر_تعریف_شده _MSVCRT_
  خارجي حرف *_pgmptr;
#وإلا
#تعریف_کن _pgmptr (*_imp___pgmptr)
  خارجي حرف **_imp___pgmptr;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _wpgmptr
#اگر_تعریف_شده _MSVCRT_
  خارجي wchar_t *_wpgmptr;
#وإلا
#تعریف_کن _wpgmptr        (*_imp___wpgmptr)
  خارجي wchar_t **_imp___wpgmptr;
#پایان_اگر
#پایان_اگر
  errno_t __cdecl _get_pgmptr(حرف **مقدار_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **مقدار_2);
#اگر_تعریف_نشده _fmode
#اگر_تعریف_شده _MSVCRT_
  خارجي صحيح _fmode;
#وإلا
#تعریف_کن _fmode  (*_imp___fmode)
  خارجي صحيح *_imp___fmode;
#پایان_اگر
#پایان_اگر
  _CRTIMP errno_t __cdecl مجموعه_fmode(صحيح نما_3);
  _CRTIMP errno_t __cdecl _get_fmode(صحيح *_PMode);

#اگر_تعریف_نشده _osplatform
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت صحيح _osplatform;
#وإلا
#تعریف_کن _osplatform (*_imp___osplatform)
  خارجي بیعلامت صحيح *_imp___osplatform;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _osver
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت صحيح _osver;
#وإلا
#تعریف_کن _osver  (*_imp___osver)
  خارجي بیعلامت صحيح *_imp___osver;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _winver
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت صحيح _winver;
#وإلا
#تعریف_کن _winver (*_imp___winver)
  خارجي بیعلامت صحيح *_imp___winver;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _winmajor
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت صحيح _winmajor;
#وإلا
#تعریف_کن _winmajor       (*_imp___winmajor)
  خارجي بیعلامت صحيح *_imp___winmajor;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _winminor
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت صحيح _winminor;
#وإلا
#تعریف_کن _winminor       (*_imp___winminor)
  خارجي بیعلامت صحيح *_imp___winminor;
#پایان_اگر
#پایان_اگر

  errno_t __cdecl _get_osplatform(بیعلامت صحيح *مقدار_2);
  errno_t __cdecl _get_osver(بیعلامت صحيح *مقدار_2);
  errno_t __cdecl _get_winver(بیعلامت صحيح *مقدار_2);
  errno_t __cdecl _get_winmajor(بیعلامت صحيح *مقدار_2);
  errno_t __cdecl _get_winminor(بیعلامت صحيح *مقدار_2);
#اگر_تعریف_نشده _countof
#اگر_تعریف_نشده __cplusplus
#تعریف_کن _countof(_Array) (حجم(_Array) / حجم(_Array[0]))
#وإلا
  خارجي "C++" {
    قالب <typename _CountofType,اندازه_t اندازه_از_Array> حرف (*__countof_helper(UNALIGNED _CountofType (&_Array)[اندازه_از_Array]))[اندازه_از_Array];
#تعریف_کن _countof(_Array) حجم(*__countof_helper(_Array))
  }
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _CRT_TERMINATE_DEFINED
#تعریف_کن _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW خروج(صحيح کد_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کد_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ  __cdecl _Exit(صحيح وضعیت)
  {  _exit(وضعیت); }
#پایان_اگر

#رهنمود افزودن_macro("abort")
#لغو_تعریف abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#رهنمود برداشت_macro("abort")

#پایان_اگر

  _CRTIMP بیعلامت صحيح __cdecl مجموعه_abort_behavior(بیعلامت صحيح _Flags,بیعلامت صحيح ماسک_2);

#اگر_تعریف_نشده _CRT_ABS_DEFINED
#تعریف_کن _CRT_ABS_DEFINED
  صحيح __cdecl قدر_مطلق(صحيح _X);
  دراز __cdecl labs(دراز _X);
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 64
  __int64 __cdecl _abs64(__int64);
#پایان_اگر
  صحيح __cdecl atexit(فراغ (__cdecl *)(فراغ));
#اگر_تعریف_نشده _CRT_ATOF_DEFINED
#تعریف_کن _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#پایان_اگر
  صحيح __cdecl atoi(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _atoi_l(ثابت حرف *_Str,_locale_t _Locale);
  دراز __cdecl atol(ثابت حرف *_Str);
  _CRTIMP دراز __cdecl _atol_l(ثابت حرف *_Str,_locale_t _Locale);
#اگر_تعریف_نشده _CRT_ALGO_DEFINED
#تعریف_کن _CRT_ALGO_DEFINED
  فراغ *__cdecl bsearch(ثابت فراغ *کلید_2,ثابت فراغ *پایه_3,اندازه_t رقم_از_Elements,اندازه_t اندازه_از_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
  فراغ __cdecl qsort(فراغ *پایه_3,اندازه_t رقم_از_Elements,اندازه_t اندازه_از_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
#پایان_اگر
  بیعلامت کوتاه __cdecl _byteswap_ushort(بیعلامت کوتاه _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#إذا INTEGRAL_MAX_بیتها >= 64
  بیعلامت __int64 __cdecl _byteswap_uint64(بیعلامت __int64 _Int64);
#پایان_اگر
  div_t __cdecl div(صحيح _Numerator,صحيح _Denominator);
  حرف *__cdecl getenv(ثابت حرف *_VarName);
  _CRTIMP حرف *__cdecl _itoa(صحيح مقدار_2,حرف *_Dest,صحيح _Radix);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP حرف *__cdecl _i64toa(__int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP حرف *__cdecl _ui64toa(بیعلامت __int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ثابت حرف *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ثابت حرف *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ثابت حرف *_String,حرف **انتها_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ثابت حرف *_String,حرف **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بیعلامت __int64 __cdecl _strtoui64(ثابت حرف *_String,حرف **انتها_Ptr,صحيح _Radix);
  _CRTIMP بیعلامت __int64 __cdecl _strtoui64_l(ثابت حرف *_String,حرف **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
#پایان_اگر
  ldiv_t __cdecl ldiv(دراز _Numerator,دراز _Denominator);
  _CRTIMP حرف *__cdecl _ltoa(دراز مقدار_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl mblen(ثابت حرف *_Ch,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _mblen_l(ثابت حرف *_Ch,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _mbstrlen(ثابت حرف *_Str);
  _CRTIMP اندازه_t __cdecl _mbstrlen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _mbstrnlen(ثابت حرف *_Str,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _mbstrnlen_l(ثابت حرف *_Str,اندازه_t Max_شمار,_locale_t _Locale);
  صحيح __cdecl mbtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,اندازه_t Src_اندازه_درون_بایتها);
  _CRTIMP صحيح __cdecl _mbtowc_l(wchar_t *_DstCh,ثابت حرف *_SrcCh,اندازه_t Src_اندازه_درون_بایتها,_locale_t _Locale);
  اندازه_t __cdecl mbstowcs(wchar_t *_Dest,ثابت حرف *منبع_3,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _mbstowcs_l(wchar_t *_Dest,ثابت حرف *منبع_3,اندازه_t Max_شمار,_locale_t _Locale);
  صحيح __cdecl rand(فراغ);
  _CRTIMP صحيح __cdecl مجموعه_error_نما(صحيح نما_3);
  فراغ __cdecl srand(بیعلامت صحيح دانه);
  مزدوج __cdecl strtod(ثابت حرف *_Str,حرف **انتها_Ptr);
#إذا !defined __NO_ISOCEXT  /* in libmingwex.a */
#إذا __TINYC__
  __CRT_INLINE عائم __cdecl strtof (ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
  __CRT_INLINE دراز مزدوج __cdecl strtold(ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
#وإلا
  عائم __cdecl strtof (ثابت حرف * __restrict__, حرف ** __restrict__);
  دراز مزدوج __cdecl strtold(ثابت حرف * __restrict__, حرف ** __restrict__);
#پایان_اگر
#وإلا
  عائم __cdecl strtof(ثابت حرف *nptr, حرف **endptr);
#پایان_اگر /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _strtod_l(ثابت حرف *_Str,حرف **انتها_Ptr,_locale_t _Locale);
  دراز __cdecl strtol(ثابت حرف *_Str,حرف **انتها_Ptr,صحيح _Radix);
  _CRTIMP دراز __cdecl _strtol_l(ثابت حرف *_Str,حرف **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  بیعلامت دراز __cdecl strtoul(ثابت حرف *_Str,حرف **انتها_Ptr,صحيح _Radix);
  _CRTIMP بیعلامت دراز __cdecl _strtoul_l(ثابت حرف *_Str,حرف **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
#اگر_تعریف_نشده _CRT_SYSTEM_DEFINED
#تعریف_کن _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#پایان_اگر
  _CRTIMP حرف *__cdecl _ultoa(بیعلامت دراز مقدار_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl wctomb(حرف *_MbCh,wchar_t _WCh);
  _CRTIMP صحيح __cdecl _wctomb_l(حرف *_MbCh,wchar_t _WCh,_locale_t _Locale);
  اندازه_t __cdecl wcstombs(حرف *_Dest,ثابت wchar_t *منبع_3,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _wcstombs_l(حرف *_Dest,ثابت wchar_t *منبع_3,اندازه_t Max_شمار,_locale_t _Locale);

#اگر_تعریف_نشده CRT_تخصیص_DEFINED
#تعریف_کن CRT_تخصیص_DEFINED
  فراغ *__cdecl حافظه_صفر_بده(اندازه_t رقم_از_Elements,اندازه_t اندازه_از_Elements);
  فراغ __cdecl حرر(فراغ *حافظه);
  فراغ *__cdecl حافظه_بده(اندازه_t اندازه_4);
  فراغ *__cdecl realloc(فراغ *حافظه,اندازه_t New_اندازه);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *حافظه,اندازه_t شمار_5,اندازه_t اندازه_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *حافظه);
  _CRTIMP فراغ *__cdecl _aligned_malloc(اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_جابه_جایی_malloc(اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t جابه_جایی_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *حافظه,اندازه_t شمار_5,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_جابه_جایی_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t جابه_جایی_2);
  _CRTIMP فراغ *__cdecl aligned_جابه_جایی_recalloc(فراغ *حافظه,اندازه_t شمار_5,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t جابه_جایی_2);
#پایان_اگر

#اگر_تعریف_نشده _WSTDLIB_DEFINED
#تعریف_کن _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح مقدار_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(دراز مقدار_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(بیعلامت دراز مقدار_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **انتها_Ptr);
  عائم __cdecl wcstof(ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof( ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  دراز مزدوج __cdecl wcstold(ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#پایان_اگر /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,_locale_t _Locale);
  دراز __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP دراز __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  بیعلامت دراز __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP بیعلامت دراز __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#اگر_تعریف_نشده _CRT_WSYSTEM_DEFINED
#تعریف_کن _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#پایان_اگر
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP دراز __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP دراز __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(بیعلامت __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بیعلامت __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **انتها_Ptr,صحيح _Radix);
  _CRTIMP بیعلامت __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str ,wchar_t **انتها_Ptr,صحيح _Radix,_locale_t _Locale);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _POSIX_
#تعریف_کن _CVTBUFSIZE (309+40)
  _CRTIMP حرف *__cdecl _fullpath(حرف *پر_مسیر,ثابت حرف *مسیر_2,اندازه_t اندازه_درون_بایتها);
  _CRTIMP حرف *__cdecl _ecvt(مزدوج _Val,صحيح رقم_از_Digits,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _fcvt(مزدوج _Val,صحيح رقم_از_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _gcvt(مزدوج _Val,صحيح رقم_از_Digits,حرف *_DstBuf);
  _CRTIMP صحيح __cdecl _atodbl(_CRT_DOUBLE *نتیجه_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoldbl(_LDOUBLE *نتیجه_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoflt(_CRT_FLOAT *نتیجه_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atodbl_l(_CRT_DOUBLE *نتیجه_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoldbl_l(_LDOUBLE *نتیجه_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoflt_l(_CRT_FLOAT *نتیجه_2,حرف *_Str,_locale_t _Locale);
  بیعلامت دراز __cdecl _lrotl(بیعلامت دراز _Val,صحيح لغزش_2);
  بیعلامت دراز __cdecl _lrotr(بیعلامت دراز _Val,صحيح لغزش_2);
  _CRTIMP فراغ __cdecl _makepath(حرف *مسیر_2,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#اگر_تعریف_نشده _CRT_PERROR_DEFINED
#تعریف_کن _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_پیام);
#پایان_اگر
  _CRTIMP صحيح __cdecl _putenv(ثابت حرف *_EnvString);
  بیعلامت صحيح __cdecl _rotl(بیعلامت صحيح _Val,صحيح لغزش_2);
#إذا INTEGRAL_MAX_بیتها >= 64
  بیعلامت __int64 __cdecl _rotl64(بیعلامت __int64 _Val,صحيح لغزش_2);
#پایان_اگر
  بیعلامت صحيح __cdecl _rotr(بیعلامت صحيح _Val,صحيح لغزش_2);
#إذا INTEGRAL_MAX_بیتها >= 64
  بیعلامت __int64 __cdecl _rotr64(بیعلامت __int64 _Val,صحيح لغزش_2);
#پایان_اگر
  _CRTIMP فراغ __cdecl _searchenv(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتیجه_مسیر);
  _CRTIMP فراغ __cdecl _splitpath(ثابت حرف *پر_مسیر,حرف *_Drive,حرف *_Dir,حرف *_Filename,حرف *_Ext);
  _CRTIMP فراغ __cdecl _swab(حرف *_Buf1,حرف *_Buf2,صحيح اندازه_درون_بایتها);

#اگر_تعریف_نشده _WSTDLIBP_DEFINED
#تعریف_کن _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *پر_مسیر,ثابت wchar_t *مسیر_2,اندازه_t اندازه_درون_واژگان);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *نتیجه_مسیر,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#اگر_تعریف_نشده _CRT_WPERROR_DEFINED
#تعریف_کن _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیام);
#پایان_اگر
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجه_مسیر);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *پر_مسیر,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#پایان_اگر

  _CRTIMP فراغ __cdecl _beep(بیعلامت _Frequency,بیعلامت _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP فراغ __cdecl _seterrormode(صحيح نما_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP فراغ __cdecl _sleep(بیعلامت دراز _Duration) __MINGW_ATTRIB_DEPRECATED;
#پایان_اگر

#اگر_تعریف_نشده NO_OLDNAMES
#اگر_تعریف_نشده _POSIX_
#إذا 0
#اگر_تعریف_نشده __cplusplus
#اگر_تعریف_نشده NOMINMAX
#اگر_تعریف_نشده max
#تعریف_کن max(a,b) (((a) > (b)) ? (a) : (b))
#پایان_اگر
#اگر_تعریف_نشده min
#تعریف_کن min(a,b) (((a) < (b)) ? (a) : (b))
#پایان_اگر
#پایان_اگر
#پایان_اگر
#پایان_اگر

#تعریف_کن sys_errlist _sys_errlist
#تعریف_کن sys_nerr _sys_nerr
#تعریف_کن environ _environ
  حرف *__cdecl ecvt(مزدوج _Val,صحيح رقم_از_Digits,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl fcvt(مزدوج _Val,صحيح رقم_از_Dec,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl gcvt(مزدوج _Val,صحيح رقم_از_Digits,حرف *_DstBuf);
  حرف *__cdecl itoa(صحيح _Val,حرف *_DstBuf,صحيح _Radix);
  حرف *__cdecl ltoa(دراز _Val,حرف *_DstBuf,صحيح _Radix);
  صحيح __cdecl putenv(ثابت حرف *_EnvString);
  فراغ __cdecl swab(حرف *_Buf1,حرف *_Buf2,صحيح اندازه_درون_بایتها);
  حرف *__cdecl ultoa(بیعلامت دراز _Val,حرف *_Dstbuf,صحيح _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#پایان_اگر
#پایان_اگر

#إذا !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  تعريفنوع بنية { دراز دراز quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(دراز دراز, دراز دراز);

  __CRT_INLINE دراز دراز __cdecl llabs(دراز دراز _j) { أرجع (_j >= 0 ? _j : -_j); }

 #اگر_تعریف_شده __TINYC__ /* gr */
  #تعریف_کن strtoll _strtoi64
  #تعریف_کن strtoull _strtoui64
 #وإلا
  دراز دراز  __cdecl strtoll(ثابت حرف* __restrict__, حرف** __restrict, صحيح);
  بیعلامت دراز دراز  __cdecl strtoull(ثابت حرف* __restrict__, حرف** __restrict__, صحيح);
 #پایان_اگر

  /* these are stubs for MS _i64 versions */
  دراز دراز  __cdecl atoll (ثابت حرف *);

#اگر_تعریف_نشده __STRICT_ANSI__
  دراز دراز  __cdecl wtoll (ثابت wchar_t *);
  حرف *__cdecl lltoa (دراز دراز, حرف *, صحيح);
  حرف *__cdecl ulltoa (بیعلامت دراز دراز , حرف *, صحيح);
  wchar_t *__cdecl lltow (دراز دراز, wchar_t *, صحيح);
  wchar_t *__cdecl ulltow (بیعلامت دراز دراز, wchar_t *, صحيح);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE دراز دراز  __cdecl atoll (ثابت حرف * _c) { أرجع _atoi64 (_c); }
  __CRT_INLINE حرف *__cdecl lltoa (دراز دراز _n, حرف * _c, صحيح _i) { أرجع _i64toa (_n, _c, _i); }
  __CRT_INLINE حرف *__cdecl ulltoa (بیعلامت دراز دراز _n, حرف * _c, صحيح _i) { أرجع _ui64toa (_n, _c, _i); }
  __CRT_INLINE دراز دراز  __cdecl wtoll (ثابت wchar_t * _w) { أرجع _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (دراز دراز _n, wchar_t * _w, صحيح _i) { أرجع _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (بیعلامت دراز دراز _n, wchar_t * _w, صحيح _i) { أرجع _ui64tow (_n, _w, _i); }
#پایان_اگر /* (__STRICT_ANSI__)  */

#پایان_اگر /* !__NO_ISOCEXT */

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)

#ضمن <sec_api/stdlib_s.h>
#ضمن <malloc.h>

#پایان_اگر
