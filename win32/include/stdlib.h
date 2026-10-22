/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_STDLIB
#تعریف_کړه _INC_STDLIB

#ضمن <_mingw.h>
#ضمن <limits.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی عدم
#که_تعریف_شوی __cplusplus
#تعریف_کړه عدم 0
#وإلا
#تعریف_کړه عدم ((فراغ *)0)
#د_که_پای
#د_که_پای

#تعریف_کړه EXIT_SUCCESS 0
#تعریف_کړه EXIT_FAILURE 1

#که_نه_تعریف_شوی _ONEXIT_T_DEFINED
#تعریف_کړه _ONEXIT_T_DEFINED

  تعريفنوع صحيح (__cdecl *_onexit_t)(فراغ);

#که_نه_تعریف_شوی NO_OLDNAMES
#تعریف_کړه onexit_t _onexit_t
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _DIV_T_DEFINED
#تعریف_کړه _DIV_T_DEFINED

  تعريفنوع بنية _div_t {
    صحيح quot;
    صحيح rem;
  } div_t;

  تعريفنوع بنية _ldiv_t {
    اوږد quot;
    اوږد rem;
  } ldiv_t;
#د_که_پای

#که_نه_تعریف_شوی _CRT_DOUBLE_DEC
#تعریف_کړه _CRT_DOUBLE_DEC

#لارښوونه pack(4)
  تعريفنوع بنية {
    بینښه حرف ld[10];
  } _LDOUBLE;
#لارښوونه pack()

#تعریف_کړه _PTR_LD(x) ((بینښه حرف *)(&(x)->ld))

  تعريفنوع بنية {
    مزدوج x;
  } _CRT_DOUBLE;

  تعريفنوع بنية {
    عائم f;
  } _CRT_FLOAT;

#لارښوونه ټېل_macro("long")
#تعریف_لغوه اوږد

  تعريفنوع بنية {
    اوږد مزدوج x;
  } _LONGDOUBLE;

#لارښوونه راوباسه_macro("long")

#لارښوونه pack(4)
  تعريفنوع بنية {
    بینښه حرف ld12[12];
  } _LDBL12;
#لارښوونه pack()
#د_که_پای

#تعریف_کړه RAND_MAX 0x7fff

#که_نه_تعریف_شوی MB_CUR_MAX
#تعریف_کړه MB_CUR_MAX ___mb_cur_max_func()
#که_نه_تعریف_شوی __mb_cur_max
#که_تعریف_شوی _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#تعریف_کړه __mb_cur_max    (*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#د_که_پای
#د_که_پای
#که_تعریف_شوی _MSVCRT_
  خارجي صحيح __mbcur_max;
#تعریف_کړه ___mb_cur_max_func() (__mb_cur_max)
#وإلا
  خارجي صحيح* _imp____mbcur_max;
#تعریف_کړه ___mb_cur_max_func() (*_imp____mb_cur_max)
#د_که_پای
#د_که_پای

#تعریف_کړه __max(a,b) (((a) > (b)) ? (a) : (b))
#تعریف_کړه __min(a,b) (((a) < (b)) ? (a) : (b))

#تعریف_کړه MAX_لار_2 260
#تعریف_کړه _MAX_DRIVE 3
#تعریف_کړه _MAX_DIR 256
#تعریف_کړه _MAX_FNAME 256
#تعریف_کړه _MAX_EXT 256

#تعریف_کړه بهر_منزل_DEFAULT 0
#تعریف_کړه بهر_منزل_STDERR 1
#تعریف_کړه بهر_منزل_MSGBOX 2
#تعریف_کړه _REPORT_ERRMODE 3

#تعریف_کړه WRITE_ABORT_پیغام 0x1
#تعریف_کړه _CALL_REPORTFAULT 0x2

#تعریف_کړه _MAX_ENV 32767

  تعريفنوع فراغ (__cdecl *_purecall_handler)(فراغ);

  _CRTIMP _purecall_handler __cdecl سېټ_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(فراغ);

  تعريفنوع فراغ (__cdecl *_invalid_parameter_handler)(ثابت wchar_t *,ثابت wchar_t *,ثابت wchar_t *,بینښه صحيح,uintptr_t);
  _invalid_parameter_handler __cdecl سېټ_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(فراغ);

#که_نه_تعریف_شوی _CRT_ERRNO_DEFINED
#تعریف_کړه _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#تعریف_کړه errno (*_errno())
  errno_t __cdecl سېټ_errno(صحيح ارزښت_2);
  errno_t __cdecl _get_errno(صحيح *ارزښت_2);
#د_که_پای
  _CRTIMP بینښه اوږد *__cdecl __doserrno(فراغ);
#تعریف_کړه _doserrno (*__doserrno())
  errno_t __cdecl سېټ_doserrno(بینښه اوږد ارزښت_2);
  errno_t __cdecl _get_doserrno(بینښه اوږد *ارزښت_2);
#که_تعریف_شوی _MSVCRT_
  خارجي حرف *_sys_errlist[];
  خارجي صحيح _sys_nerr;
#وإلا
  _CRTIMP حرف *_sys_errlist[1];
  _CRTIMP صحيح _sys_nerr;
#د_که_پای
#إذا (defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح *__cdecl __p___argc(فراغ);
  _CRTIMP حرف ***__cdecl __p___argv(فراغ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(فراغ);
  _CRTIMP حرف ***__cdecl __p__environ(فراغ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(فراغ);
  _CRTIMP حرف **__cdecl __p__pgmptr(فراغ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(فراغ);
#د_که_پای
#که_نه_تعریف_شوی __argc
#که_تعریف_شوی _MSVCRT_
  خارجي صحيح __argc;
#وإلا
#تعریف_کړه __argc (*_imp____argc)
  خارجي صحيح *_imp____argc;
#د_که_پای
#د_که_پای
#که_نه_تعریف_شوی __argv
#که_تعریف_شوی _MSVCRT_
  خارجي حرف **__argv;
#وإلا
#تعریف_کړه __argv  (*_imp____argv)
  خارجي حرف ***_imp____argv;
#د_که_پای
#د_که_پای
#که_نه_تعریف_شوی __wargv
#که_تعریف_شوی _MSVCRT_
  خارجي wchar_t **__wargv;
#وإلا
#تعریف_کړه __wargv (*_imp____wargv)
  خارجي wchar_t ***_imp____wargv;
#د_که_پای
#د_که_پای

#که_تعریف_شوی _POSIX_
  خارجي حرف **environ;
#وإلا
#که_نه_تعریف_شوی _environ
#که_تعریف_شوی _MSVCRT_
  خارجي حرف **_environ;
#وإلا
#تعریف_کړه _environ (*_imp___environ)
  خارجي حرف ***_imp___environ;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _wenviron
#که_تعریف_شوی _MSVCRT_
  خارجي wchar_t **_wenviron;
#وإلا
#تعریف_کړه _wenviron       (*_imp___wenviron)
  خارجي wchar_t ***_imp___wenviron;
#د_که_پای
#د_که_پای
#د_که_پای

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
#د_که_پای

#که_نه_تعریف_شوی _pgmptr
#که_تعریف_شوی _MSVCRT_
  خارجي حرف *_pgmptr;
#وإلا
#تعریف_کړه _pgmptr (*_imp___pgmptr)
  خارجي حرف **_imp___pgmptr;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _wpgmptr
#که_تعریف_شوی _MSVCRT_
  خارجي wchar_t *_wpgmptr;
#وإلا
#تعریف_کړه _wpgmptr        (*_imp___wpgmptr)
  خارجي wchar_t **_imp___wpgmptr;
#د_که_پای
#د_که_پای
  errno_t __cdecl _get_pgmptr(حرف **ارزښت_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **ارزښت_2);
#که_نه_تعریف_شوی _fmode
#که_تعریف_شوی _MSVCRT_
  خارجي صحيح _fmode;
#وإلا
#تعریف_کړه _fmode  (*_imp___fmode)
  خارجي صحيح *_imp___fmode;
#د_که_پای
#د_که_پای
  _CRTIMP errno_t __cdecl سېټ_fmode(صحيح ډېرپېښ_3);
  _CRTIMP errno_t __cdecl _get_fmode(صحيح *_PMode);

#که_نه_تعریف_شوی _osplatform
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه صحيح _osplatform;
#وإلا
#تعریف_کړه _osplatform (*_imp___osplatform)
  خارجي بینښه صحيح *_imp___osplatform;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _osver
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه صحيح _osver;
#وإلا
#تعریف_کړه _osver  (*_imp___osver)
  خارجي بینښه صحيح *_imp___osver;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _winver
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه صحيح _winver;
#وإلا
#تعریف_کړه _winver (*_imp___winver)
  خارجي بینښه صحيح *_imp___winver;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _winmajor
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه صحيح _winmajor;
#وإلا
#تعریف_کړه _winmajor       (*_imp___winmajor)
  خارجي بینښه صحيح *_imp___winmajor;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _winminor
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه صحيح _winminor;
#وإلا
#تعریف_کړه _winminor       (*_imp___winminor)
  خارجي بینښه صحيح *_imp___winminor;
#د_که_پای
#د_که_پای

  errno_t __cdecl _get_osplatform(بینښه صحيح *ارزښت_2);
  errno_t __cdecl _get_osver(بینښه صحيح *ارزښت_2);
  errno_t __cdecl _get_winver(بینښه صحيح *ارزښت_2);
  errno_t __cdecl _get_winmajor(بینښه صحيح *ارزښت_2);
  errno_t __cdecl _get_winminor(بینښه صحيح *ارزښت_2);
#که_نه_تعریف_شوی _countof
#که_نه_تعریف_شوی __cplusplus
#تعریف_کړه _countof(_Array) (حجم(_Array) / حجم(_Array[0]))
#وإلا
  خارجي "C++" {
    کينډۍ <typename _CountofType,اندازه_t اندازه_د_Array> حرف (*__countof_helper(UNALIGNED _CountofType (&_Array)[اندازه_د_Array]))[اندازه_د_Array];
#تعریف_کړه _countof(_Array) حجم(*__countof_helper(_Array))
  }
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _CRT_TERMINATE_DEFINED
#تعریف_کړه _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW وتل(صحيح کوډ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کوډ_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ  __cdecl _Exit(صحيح حالت)
  {  _exit(حالت); }
#د_که_پای

#لارښوونه ټېل_macro("abort")
#تعریف_لغوه abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#لارښوونه راوباسه_macro("abort")

#د_که_پای

  _CRTIMP بینښه صحيح __cdecl سېټ_abort_behavior(بینښه صحيح _Flags,بینښه صحيح ماسک_2);

#که_نه_تعریف_شوی _CRT_ABS_DEFINED
#تعریف_کړه _CRT_ABS_DEFINED
  صحيح __cdecl مطلق_قیمت(صحيح _X);
  اوږد __cdecl labs(اوږد _X);
#د_که_پای

#إذا INTEGRAL_MAX_بټونه >= 64
  __int64 __cdecl _abs64(__int64);
#د_که_پای
  صحيح __cdecl atexit(فراغ (__cdecl *)(فراغ));
#که_نه_تعریف_شوی _CRT_ATOF_DEFINED
#تعریف_کړه _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#د_که_پای
  صحيح __cdecl atoi(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _atoi_l(ثابت حرف *_Str,_locale_t _Locale);
  اوږد __cdecl atol(ثابت حرف *_Str);
  _CRTIMP اوږد __cdecl _atol_l(ثابت حرف *_Str,_locale_t _Locale);
#که_نه_تعریف_شوی _CRT_ALGO_DEFINED
#تعریف_کړه _CRT_ALGO_DEFINED
  فراغ *__cdecl bsearch(ثابت فراغ *کلی_2,ثابت فراغ *بنسټ_3,اندازه_t عدد_د_Elements,اندازه_t اندازه_د_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
  فراغ __cdecl qsort(فراغ *بنسټ_3,اندازه_t عدد_د_Elements,اندازه_t اندازه_د_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
#د_که_پای
  بینښه لنډ __cdecl _byteswap_ushort(بینښه لنډ _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#إذا INTEGRAL_MAX_بټونه >= 64
  بینښه __int64 __cdecl _byteswap_uint64(بینښه __int64 _Int64);
#د_که_پای
  div_t __cdecl div(صحيح _Numerator,صحيح _Denominator);
  حرف *__cdecl getenv(ثابت حرف *_VarName);
  _CRTIMP حرف *__cdecl _itoa(صحيح ارزښت_2,حرف *_Dest,صحيح _Radix);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP حرف *__cdecl _i64toa(__int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP حرف *__cdecl _ui64toa(بینښه __int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ثابت حرف *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ثابت حرف *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ثابت حرف *_String,حرف **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ثابت حرف *_String,حرف **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بینښه __int64 __cdecl _strtoui64(ثابت حرف *_String,حرف **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP بینښه __int64 __cdecl _strtoui64_l(ثابت حرف *_String,حرف **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
#د_که_پای
  ldiv_t __cdecl ldiv(اوږد _Numerator,اوږد _Denominator);
  _CRTIMP حرف *__cdecl _ltoa(اوږد ارزښت_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl mblen(ثابت حرف *_Ch,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _mblen_l(ثابت حرف *_Ch,اندازه_t Max_شمېر,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _mbstrlen(ثابت حرف *_Str);
  _CRTIMP اندازه_t __cdecl _mbstrlen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP اندازه_t __cdecl _mbstrnlen(ثابت حرف *_Str,اندازه_t Max_شمېر);
  _CRTIMP اندازه_t __cdecl _mbstrnlen_l(ثابت حرف *_Str,اندازه_t Max_شمېر,_locale_t _Locale);
  صحيح __cdecl mbtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,اندازه_t Src_اندازه_دننه_بایټونه);
  _CRTIMP صحيح __cdecl _mbtowc_l(wchar_t *_DstCh,ثابت حرف *_SrcCh,اندازه_t Src_اندازه_دننه_بایټونه,_locale_t _Locale);
  اندازه_t __cdecl mbstowcs(wchar_t *_Dest,ثابت حرف *سرچینه_3,اندازه_t Max_شمېر);
  _CRTIMP اندازه_t __cdecl _mbstowcs_l(wchar_t *_Dest,ثابت حرف *سرچینه_3,اندازه_t Max_شمېر,_locale_t _Locale);
  صحيح __cdecl rand(فراغ);
  _CRTIMP صحيح __cdecl سېټ_error_ډېرپېښ(صحيح ډېرپېښ_3);
  فراغ __cdecl srand(بینښه صحيح تخم);
  مزدوج __cdecl strtod(ثابت حرف *_Str,حرف **پای_ټکی_Ptr);
#إذا !defined __NO_ISOCEXT  /* in libmingwex.a */
#إذا __TINYC__
  __CRT_INLINE عائم __cdecl strtof (ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
  __CRT_INLINE اوږد مزدوج __cdecl strtold(ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
#وإلا
  عائم __cdecl strtof (ثابت حرف * __restrict__, حرف ** __restrict__);
  اوږد مزدوج __cdecl strtold(ثابت حرف * __restrict__, حرف ** __restrict__);
#د_که_پای
#وإلا
  عائم __cdecl strtof(ثابت حرف *nptr, حرف **endptr);
#د_که_پای /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _strtod_l(ثابت حرف *_Str,حرف **پای_ټکی_Ptr,_locale_t _Locale);
  اوږد __cdecl strtol(ثابت حرف *_Str,حرف **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP اوږد __cdecl _strtol_l(ثابت حرف *_Str,حرف **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
  بینښه اوږد __cdecl strtoul(ثابت حرف *_Str,حرف **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP بینښه اوږد __cdecl _strtoul_l(ثابت حرف *_Str,حرف **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
#که_نه_تعریف_شوی _CRT_SYSTEM_DEFINED
#تعریف_کړه _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#د_که_پای
  _CRTIMP حرف *__cdecl _ultoa(بینښه اوږد ارزښت_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl wctomb(حرف *_MbCh,wchar_t _WCh);
  _CRTIMP صحيح __cdecl _wctomb_l(حرف *_MbCh,wchar_t _WCh,_locale_t _Locale);
  اندازه_t __cdecl wcstombs(حرف *_Dest,ثابت wchar_t *سرچینه_3,اندازه_t Max_شمېر);
  _CRTIMP اندازه_t __cdecl _wcstombs_l(حرف *_Dest,ثابت wchar_t *سرچینه_3,اندازه_t Max_شمېر,_locale_t _Locale);

#که_نه_تعریف_شوی CRT_ویش_DEFINED
#تعریف_کړه CRT_ویش_DEFINED
  فراغ *__cdecl حافظه_صفر_ورکړه(اندازه_t عدد_د_Elements,اندازه_t اندازه_د_Elements);
  فراغ __cdecl حرر(فراغ *حافظه);
  فراغ *__cdecl حافظه_ورکړه(اندازه_t اندازه_4);
  فراغ *__cdecl realloc(فراغ *حافظه,اندازه_t New_اندازه);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *حافظه,اندازه_t شمېر_5,اندازه_t اندازه_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *حافظه);
  _CRTIMP فراغ *__cdecl _aligned_malloc(اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_دننه_واټن_malloc(اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t دننه_واټن_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *حافظه,اندازه_t شمېر_5,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_دننه_واټن_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t دننه_واټن_2);
  _CRTIMP فراغ *__cdecl aligned_دننه_واټن_recalloc(فراغ *حافظه,اندازه_t شمېر_5,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t دننه_واټن_2);
#د_که_پای

#که_نه_تعریف_شوی _WSTDLIB_DEFINED
#تعریف_کړه _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح ارزښت_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(اوږد ارزښت_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(بینښه اوږد ارزښت_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr);
  عائم __cdecl wcstof(ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof( ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  اوږد مزدوج __cdecl wcstold(ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#د_که_پای /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,_locale_t _Locale);
  اوږد __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP اوږد __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
  بینښه اوږد __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP بینښه اوږد __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#که_نه_تعریف_شوی _CRT_WSYSTEM_DEFINED
#تعریف_کړه _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#د_که_پای
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP اوږد __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP اوږد __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(بینښه __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بینښه __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **پای_ټکی_Ptr,صحيح _Radix);
  _CRTIMP بینښه __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str ,wchar_t **پای_ټکی_Ptr,صحيح _Radix,_locale_t _Locale);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _POSIX_
#تعریف_کړه _CVTBUFSIZE (309+40)
  _CRTIMP حرف *__cdecl _fullpath(حرف *ډک_لار,ثابت حرف *لار_2,اندازه_t اندازه_دننه_بایټونه);
  _CRTIMP حرف *__cdecl _ecvt(مزدوج _Val,صحيح عدد_د_Digits,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _fcvt(مزدوج _Val,صحيح عدد_د_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _gcvt(مزدوج _Val,صحيح عدد_د_Digits,حرف *_DstBuf);
  _CRTIMP صحيح __cdecl _atodbl(_CRT_DOUBLE *پایله_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoldbl(_LDOUBLE *پایله_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoflt(_CRT_FLOAT *پایله_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atodbl_l(_CRT_DOUBLE *پایله_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoldbl_l(_LDOUBLE *پایله_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoflt_l(_CRT_FLOAT *پایله_2,حرف *_Str,_locale_t _Locale);
  بینښه اوږد __cdecl _lrotl(بینښه اوږد _Val,صحيح ښويدنه_2);
  بینښه اوږد __cdecl _lrotr(بینښه اوږد _Val,صحيح ښويدنه_2);
  _CRTIMP فراغ __cdecl _makepath(حرف *لار_2,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#که_نه_تعریف_شوی _CRT_PERROR_DEFINED
#تعریف_کړه _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_پیغام);
#د_که_پای
  _CRTIMP صحيح __cdecl _putenv(ثابت حرف *_EnvString);
  بینښه صحيح __cdecl _rotl(بینښه صحيح _Val,صحيح ښويدنه_2);
#إذا INTEGRAL_MAX_بټونه >= 64
  بینښه __int64 __cdecl _rotl64(بینښه __int64 _Val,صحيح ښويدنه_2);
#د_که_پای
  بینښه صحيح __cdecl _rotr(بینښه صحيح _Val,صحيح ښويدنه_2);
#إذا INTEGRAL_MAX_بټونه >= 64
  بینښه __int64 __cdecl _rotr64(بینښه __int64 _Val,صحيح ښويدنه_2);
#د_که_پای
  _CRTIMP فراغ __cdecl _searchenv(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *پایله_لار);
  _CRTIMP فراغ __cdecl _splitpath(ثابت حرف *ډک_لار,حرف *_Drive,حرف *_Dir,حرف *_Filename,حرف *_Ext);
  _CRTIMP فراغ __cdecl _swab(حرف *_Buf1,حرف *_Buf2,صحيح اندازه_دننه_بایټونه);

#که_نه_تعریف_شوی _WSTDLIBP_DEFINED
#تعریف_کړه _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *ډک_لار,ثابت wchar_t *لار_2,اندازه_t اندازه_دننه_ټکي);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *پایله_لار,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#که_نه_تعریف_شوی _CRT_WPERROR_DEFINED
#تعریف_کړه _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#د_که_پای
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *پایله_لار);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *ډک_لار,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#د_که_پای

  _CRTIMP فراغ __cdecl _beep(بینښه _Frequency,بینښه _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP فراغ __cdecl _seterrormode(صحيح ډېرپېښ_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP فراغ __cdecl _sleep(بینښه اوږد _Duration) __MINGW_ATTRIB_DEPRECATED;
#د_که_پای

#که_نه_تعریف_شوی NO_OLDNAMES
#که_نه_تعریف_شوی _POSIX_
#إذا 0
#که_نه_تعریف_شوی __cplusplus
#که_نه_تعریف_شوی NOMINMAX
#که_نه_تعریف_شوی max
#تعریف_کړه max(a,b) (((a) > (b)) ? (a) : (b))
#د_که_پای
#که_نه_تعریف_شوی min
#تعریف_کړه min(a,b) (((a) < (b)) ? (a) : (b))
#د_که_پای
#د_که_پای
#د_که_پای
#د_که_پای

#تعریف_کړه sys_errlist _sys_errlist
#تعریف_کړه sys_nerr _sys_nerr
#تعریف_کړه environ _environ
  حرف *__cdecl ecvt(مزدوج _Val,صحيح عدد_د_Digits,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl fcvt(مزدوج _Val,صحيح عدد_د_Dec,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl gcvt(مزدوج _Val,صحيح عدد_د_Digits,حرف *_DstBuf);
  حرف *__cdecl itoa(صحيح _Val,حرف *_DstBuf,صحيح _Radix);
  حرف *__cdecl ltoa(اوږد _Val,حرف *_DstBuf,صحيح _Radix);
  صحيح __cdecl putenv(ثابت حرف *_EnvString);
  فراغ __cdecl swab(حرف *_Buf1,حرف *_Buf2,صحيح اندازه_دننه_بایټونه);
  حرف *__cdecl ultoa(بینښه اوږد _Val,حرف *_Dstbuf,صحيح _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#د_که_پای
#د_که_پای

#إذا !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  تعريفنوع بنية { اوږد اوږد quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(اوږد اوږد, اوږد اوږد);

  __CRT_INLINE اوږد اوږد __cdecl llabs(اوږد اوږد _j) { أرجع (_j >= 0 ? _j : -_j); }

 #که_تعریف_شوی __TINYC__ /* gr */
  #تعریف_کړه strtoll _strtoi64
  #تعریف_کړه strtoull _strtoui64
 #وإلا
  اوږد اوږد  __cdecl strtoll(ثابت حرف* __restrict__, حرف** __restrict, صحيح);
  بینښه اوږد اوږد  __cdecl strtoull(ثابت حرف* __restrict__, حرف** __restrict__, صحيح);
 #د_که_پای

  /* these are stubs for MS _i64 versions */
  اوږد اوږد  __cdecl atoll (ثابت حرف *);

#که_نه_تعریف_شوی __STRICT_ANSI__
  اوږد اوږد  __cdecl wtoll (ثابت wchar_t *);
  حرف *__cdecl lltoa (اوږد اوږد, حرف *, صحيح);
  حرف *__cdecl ulltoa (بینښه اوږد اوږد , حرف *, صحيح);
  wchar_t *__cdecl lltow (اوږد اوږد, wchar_t *, صحيح);
  wchar_t *__cdecl ulltow (بینښه اوږد اوږد, wchar_t *, صحيح);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE اوږد اوږد  __cdecl atoll (ثابت حرف * _c) { أرجع _atoi64 (_c); }
  __CRT_INLINE حرف *__cdecl lltoa (اوږد اوږد _n, حرف * _c, صحيح _i) { أرجع _i64toa (_n, _c, _i); }
  __CRT_INLINE حرف *__cdecl ulltoa (بینښه اوږد اوږد _n, حرف * _c, صحيح _i) { أرجع _ui64toa (_n, _c, _i); }
  __CRT_INLINE اوږد اوږد  __cdecl wtoll (ثابت wchar_t * _w) { أرجع _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (اوږد اوږد _n, wchar_t * _w, صحيح _i) { أرجع _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (بینښه اوږد اوږد _n, wchar_t * _w, صحيح _i) { أرجع _ui64tow (_n, _w, _i); }
#د_که_پای /* (__STRICT_ANSI__)  */

#د_که_پای /* !__NO_ISOCEXT */

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)

#ضمن <sec_api/stdlib_s.h>
#ضمن <malloc.h>

#د_که_پای
