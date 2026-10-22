/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_STDLIB
#وصف_ڪريو _INC_STDLIB

#ضمن <_mingw.h>
#ضمن <limits.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل عدم
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو عدم 0
#وإلا
#وصف_ڪريو عدم ((فراغ *)0)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو EXIT_SUCCESS 0
#وصف_ڪريو EXIT_FAILURE 1

#جيڪڏهن_وصف_نه_ٿيل _ONEXIT_T_DEFINED
#وصف_ڪريو _ONEXIT_T_DEFINED

  تعريفنوع صحيح (__cdecl *_onexit_t)(فراغ);

#جيڪڏهن_وصف_نه_ٿيل NO_OLDNAMES
#وصف_ڪريو onexit_t _onexit_t
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _DIV_T_DEFINED
#وصف_ڪريو _DIV_T_DEFINED

  تعريفنوع بنية _div_t {
    صحيح quot;
    صحيح rem;
  } div_t;

  تعريفنوع بنية _ldiv_t {
    ڊگهو quot;
    ڊگهو rem;
  } ldiv_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_DOUBLE_DEC
#وصف_ڪريو _CRT_DOUBLE_DEC

#هدايت pack(4)
  تعريفنوع بنية {
    بنانشان حرف ld[10];
  } _LDOUBLE;
#هدايت pack()

#وصف_ڪريو _PTR_LD(x) ((بنانشان حرف *)(&(x)->ld))

  تعريفنوع بنية {
    مزدوج x;
  } _CRT_DOUBLE;

  تعريفنوع بنية {
    عائم f;
  } _CRT_FLOAT;

#هدايت ڌڪو_macro("long")
#وصف_رد ڊگهو

  تعريفنوع بنية {
    ڊگهو مزدوج x;
  } _LONGDOUBLE;

#هدايت ڪڍو_macro("long")

#هدايت pack(4)
  تعريفنوع بنية {
    بنانشان حرف ld12[12];
  } _LDBL12;
#هدايت pack()
#جيڪڏهن_پورو

#وصف_ڪريو RAND_MAX 0x7fff

#جيڪڏهن_وصف_نه_ٿيل MB_CUR_MAX
#وصف_ڪريو MB_CUR_MAX ___mb_cur_max_func()
#جيڪڏهن_وصف_نه_ٿيل __mb_cur_max
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#وصف_ڪريو __mb_cur_max    (*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي صحيح __mbcur_max;
#وصف_ڪريو ___mb_cur_max_func() (__mb_cur_max)
#وإلا
  خارجي صحيح* _imp____mbcur_max;
#وصف_ڪريو ___mb_cur_max_func() (*_imp____mb_cur_max)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو __max(a,b) (((a) > (b)) ? (a) : (b))
#وصف_ڪريو __min(a,b) (((a) < (b)) ? (a) : (b))

#وصف_ڪريو MAX_رستو_2 260
#وصف_ڪريو _MAX_DRIVE 3
#وصف_ڪريو _MAX_DIR 256
#وصف_ڪريو _MAX_FNAME 256
#وصف_ڪريو _MAX_EXT 256

#وصف_ڪريو ٻاهريون_منزل_DEFAULT 0
#وصف_ڪريو ٻاهريون_منزل_STDERR 1
#وصف_ڪريو ٻاهريون_منزل_MSGBOX 2
#وصف_ڪريو _REPORT_ERRMODE 3

#وصف_ڪريو WRITE_ABORT_نياپو 0x1
#وصف_ڪريو _CALL_REPORTFAULT 0x2

#وصف_ڪريو _MAX_ENV 32767

  تعريفنوع فراغ (__cdecl *_purecall_handler)(فراغ);

  _CRTIMP _purecall_handler __cdecl سيٽ_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(فراغ);

  تعريفنوع فراغ (__cdecl *_invalid_parameter_handler)(ثابت wchar_t *,ثابت wchar_t *,ثابت wchar_t *,بنانشان صحيح,uintptr_t);
  _invalid_parameter_handler __cdecl سيٽ_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(فراغ);

#جيڪڏهن_وصف_نه_ٿيل _CRT_ERRNO_DEFINED
#وصف_ڪريو _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#وصف_ڪريو errno (*_errno())
  errno_t __cdecl سيٽ_errno(صحيح قدر_2);
  errno_t __cdecl _get_errno(صحيح *قدر_2);
#جيڪڏهن_پورو
  _CRTIMP بنانشان ڊگهو *__cdecl __doserrno(فراغ);
#وصف_ڪريو _doserrno (*__doserrno())
  errno_t __cdecl سيٽ_doserrno(بنانشان ڊگهو قدر_2);
  errno_t __cdecl _get_doserrno(بنانشان ڊگهو *قدر_2);
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي حرف *_sys_errlist[];
  خارجي صحيح _sys_nerr;
#وإلا
  _CRTIMP حرف *_sys_errlist[1];
  _CRTIMP صحيح _sys_nerr;
#جيڪڏهن_پورو
#إذا (defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح *__cdecl __p___argc(فراغ);
  _CRTIMP حرف ***__cdecl __p___argv(فراغ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(فراغ);
  _CRTIMP حرف ***__cdecl __p__environ(فراغ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(فراغ);
  _CRTIMP حرف **__cdecl __p__pgmptr(فراغ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(فراغ);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل __argc
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي صحيح __argc;
#وإلا
#وصف_ڪريو __argc (*_imp____argc)
  خارجي صحيح *_imp____argc;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل __argv
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي حرف **__argv;
#وإلا
#وصف_ڪريو __argv  (*_imp____argv)
  خارجي حرف ***_imp____argv;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل __wargv
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي wchar_t **__wargv;
#وإلا
#وصف_ڪريو __wargv (*_imp____wargv)
  خارجي wchar_t ***_imp____wargv;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _POSIX_
  خارجي حرف **environ;
#وإلا
#جيڪڏهن_وصف_نه_ٿيل _environ
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي حرف **_environ;
#وإلا
#وصف_ڪريو _environ (*_imp___environ)
  خارجي حرف ***_imp___environ;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _wenviron
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي wchar_t **_wenviron;
#وإلا
#وصف_ڪريو _wenviron       (*_imp___wenviron)
  خارجي wchar_t ***_imp___wenviron;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _pgmptr
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي حرف *_pgmptr;
#وإلا
#وصف_ڪريو _pgmptr (*_imp___pgmptr)
  خارجي حرف **_imp___pgmptr;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _wpgmptr
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي wchar_t *_wpgmptr;
#وإلا
#وصف_ڪريو _wpgmptr        (*_imp___wpgmptr)
  خارجي wchar_t **_imp___wpgmptr;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
  errno_t __cdecl _get_pgmptr(حرف **قدر_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **قدر_2);
#جيڪڏهن_وصف_نه_ٿيل _fmode
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي صحيح _fmode;
#وإلا
#وصف_ڪريو _fmode  (*_imp___fmode)
  خارجي صحيح *_imp___fmode;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
  _CRTIMP errno_t __cdecl سيٽ_fmode(صحيح گهڻائي_3);
  _CRTIMP errno_t __cdecl _get_fmode(صحيح *_PMode);

#جيڪڏهن_وصف_نه_ٿيل _osplatform
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان صحيح _osplatform;
#وإلا
#وصف_ڪريو _osplatform (*_imp___osplatform)
  خارجي بنانشان صحيح *_imp___osplatform;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _osver
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان صحيح _osver;
#وإلا
#وصف_ڪريو _osver  (*_imp___osver)
  خارجي بنانشان صحيح *_imp___osver;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _winver
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان صحيح _winver;
#وإلا
#وصف_ڪريو _winver (*_imp___winver)
  خارجي بنانشان صحيح *_imp___winver;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _winmajor
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان صحيح _winmajor;
#وإلا
#وصف_ڪريو _winmajor       (*_imp___winmajor)
  خارجي بنانشان صحيح *_imp___winmajor;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _winminor
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان صحيح _winminor;
#وإلا
#وصف_ڪريو _winminor       (*_imp___winminor)
  خارجي بنانشان صحيح *_imp___winminor;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  errno_t __cdecl _get_osplatform(بنانشان صحيح *قدر_2);
  errno_t __cdecl _get_osver(بنانشان صحيح *قدر_2);
  errno_t __cdecl _get_winver(بنانشان صحيح *قدر_2);
  errno_t __cdecl _get_winmajor(بنانشان صحيح *قدر_2);
  errno_t __cdecl _get_winminor(بنانشان صحيح *قدر_2);
#جيڪڏهن_وصف_نه_ٿيل _countof
#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#وصف_ڪريو _countof(_Array) (حجم(_Array) / حجم(_Array[0]))
#وإلا
  خارجي "C++" {
    سانچو <typename _CountofType,سائيز_t سائيز_جو_Array> حرف (*__countof_helper(UNALIGNED _CountofType (&_Array)[سائيز_جو_Array]))[سائيز_جو_Array];
#وصف_ڪريو _countof(_Array) حجم(*__countof_helper(_Array))
  }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_TERMINATE_DEFINED
#وصف_ڪريو _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW ٻاهر_نڪرو(صحيح ڪوڊ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح ڪوڊ_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ  __cdecl _Exit(صحيح حالت)
  {  _exit(حالت); }
#جيڪڏهن_پورو

#هدايت ڌڪو_macro("abort")
#وصف_رد abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#هدايت ڪڍو_macro("abort")

#جيڪڏهن_پورو

  _CRTIMP بنانشان صحيح __cdecl سيٽ_abort_behavior(بنانشان صحيح _Flags,بنانشان صحيح نقاب_2);

#جيڪڏهن_وصف_نه_ٿيل _CRT_ABS_DEFINED
#وصف_ڪريو _CRT_ABS_DEFINED
  صحيح __cdecl مطلق_قدر(صحيح _X);
  ڊگهو __cdecl labs(ڊگهو _X);
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 64
  __int64 __cdecl _abs64(__int64);
#جيڪڏهن_پورو
  صحيح __cdecl atexit(فراغ (__cdecl *)(فراغ));
#جيڪڏهن_وصف_نه_ٿيل _CRT_ATOF_DEFINED
#وصف_ڪريو _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#جيڪڏهن_پورو
  صحيح __cdecl atoi(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _atoi_l(ثابت حرف *_Str,_locale_t _Locale);
  ڊگهو __cdecl atol(ثابت حرف *_Str);
  _CRTIMP ڊگهو __cdecl _atol_l(ثابت حرف *_Str,_locale_t _Locale);
#جيڪڏهن_وصف_نه_ٿيل _CRT_ALGO_DEFINED
#وصف_ڪريو _CRT_ALGO_DEFINED
  فراغ *__cdecl bsearch(ثابت فراغ *ڪنجي_2,ثابت فراغ *بنياد_3,سائيز_t انگ_جو_Elements,سائيز_t سائيز_جو_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
  فراغ __cdecl qsort(فراغ *بنياد_3,سائيز_t انگ_جو_Elements,سائيز_t سائيز_جو_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
#جيڪڏهن_پورو
  بنانشان ننڍو __cdecl _byteswap_ushort(بنانشان ننڍو _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#إذا INTEGRAL_MAX_بٽ >= 64
  بنانشان __int64 __cdecl _byteswap_uint64(بنانشان __int64 _Int64);
#جيڪڏهن_پورو
  div_t __cdecl div(صحيح _Numerator,صحيح _Denominator);
  حرف *__cdecl getenv(ثابت حرف *_VarName);
  _CRTIMP حرف *__cdecl _itoa(صحيح قدر_2,حرف *_Dest,صحيح _Radix);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP حرف *__cdecl _i64toa(__int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP حرف *__cdecl _ui64toa(بنانشان __int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ثابت حرف *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ثابت حرف *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ثابت حرف *_String,حرف **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ثابت حرف *_String,حرف **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بنانشان __int64 __cdecl _strtoui64(ثابت حرف *_String,حرف **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP بنانشان __int64 __cdecl _strtoui64_l(ثابت حرف *_String,حرف **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
#جيڪڏهن_پورو
  ldiv_t __cdecl ldiv(ڊگهو _Numerator,ڊگهو _Denominator);
  _CRTIMP حرف *__cdecl _ltoa(ڊگهو قدر_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl mblen(ثابت حرف *_Ch,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _mblen_l(ثابت حرف *_Ch,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  _CRTIMP سائيز_t __cdecl _mbstrlen(ثابت حرف *_Str);
  _CRTIMP سائيز_t __cdecl _mbstrlen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP سائيز_t __cdecl _mbstrnlen(ثابت حرف *_Str,سائيز_t Max_ڳڻپ);
  _CRTIMP سائيز_t __cdecl _mbstrnlen_l(ثابت حرف *_Str,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  صحيح __cdecl mbtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,سائيز_t Src_سائيز_اندريون_بائيٽون);
  _CRTIMP صحيح __cdecl _mbtowc_l(wchar_t *_DstCh,ثابت حرف *_SrcCh,سائيز_t Src_سائيز_اندريون_بائيٽون,_locale_t _Locale);
  سائيز_t __cdecl mbstowcs(wchar_t *_Dest,ثابت حرف *ذريعو_3,سائيز_t Max_ڳڻپ);
  _CRTIMP سائيز_t __cdecl _mbstowcs_l(wchar_t *_Dest,ثابت حرف *ذريعو_3,سائيز_t Max_ڳڻپ,_locale_t _Locale);
  صحيح __cdecl rand(فراغ);
  _CRTIMP صحيح __cdecl سيٽ_error_گهڻائي(صحيح گهڻائي_3);
  فراغ __cdecl srand(بنانشان صحيح ٻج);
  مزدوج __cdecl strtod(ثابت حرف *_Str,حرف **پڇاڙي_Ptr);
#إذا !defined __NO_ISOCEXT  /* in libmingwex.a */
#إذا __TINYC__
  __CRT_INLINE عائم __cdecl strtof (ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
  __CRT_INLINE ڊگهو مزدوج __cdecl strtold(ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
#وإلا
  عائم __cdecl strtof (ثابت حرف * __restrict__, حرف ** __restrict__);
  ڊگهو مزدوج __cdecl strtold(ثابت حرف * __restrict__, حرف ** __restrict__);
#جيڪڏهن_پورو
#وإلا
  عائم __cdecl strtof(ثابت حرف *nptr, حرف **endptr);
#جيڪڏهن_پورو /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _strtod_l(ثابت حرف *_Str,حرف **پڇاڙي_Ptr,_locale_t _Locale);
  ڊگهو __cdecl strtol(ثابت حرف *_Str,حرف **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP ڊگهو __cdecl _strtol_l(ثابت حرف *_Str,حرف **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  بنانشان ڊگهو __cdecl strtoul(ثابت حرف *_Str,حرف **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP بنانشان ڊگهو __cdecl _strtoul_l(ثابت حرف *_Str,حرف **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
#جيڪڏهن_وصف_نه_ٿيل _CRT_SYSTEM_DEFINED
#وصف_ڪريو _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#جيڪڏهن_پورو
  _CRTIMP حرف *__cdecl _ultoa(بنانشان ڊگهو قدر_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl wctomb(حرف *_MbCh,wchar_t _WCh);
  _CRTIMP صحيح __cdecl _wctomb_l(حرف *_MbCh,wchar_t _WCh,_locale_t _Locale);
  سائيز_t __cdecl wcstombs(حرف *_Dest,ثابت wchar_t *ذريعو_3,سائيز_t Max_ڳڻپ);
  _CRTIMP سائيز_t __cdecl _wcstombs_l(حرف *_Dest,ثابت wchar_t *ذريعو_3,سائيز_t Max_ڳڻپ,_locale_t _Locale);

#جيڪڏهن_وصف_نه_ٿيل CRT_ورهاست_DEFINED
#وصف_ڪريو CRT_ورهاست_DEFINED
  فراغ *__cdecl صفر_يادگيري_ڏيو(سائيز_t انگ_جو_Elements,سائيز_t سائيز_جو_Elements);
  فراغ __cdecl حرر(فراغ *يادگيري);
  فراغ *__cdecl يادگيري_ڏيو(سائيز_t سائيز_4);
  فراغ *__cdecl realloc(فراغ *يادگيري,سائيز_t New_سائيز);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *يادگيري,سائيز_t ڳڻپ_5,سائيز_t سائيز_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *يادگيري);
  _CRTIMP فراغ *__cdecl _aligned_malloc(سائيز_t سائيز_4,سائيز_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وٿي_malloc(سائيز_t سائيز_4,سائيز_t _Alignment,سائيز_t وٿي_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *يادگيري,سائيز_t سائيز_4,سائيز_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *يادگيري,سائيز_t ڳڻپ_5,سائيز_t سائيز_4,سائيز_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وٿي_realloc(فراغ *يادگيري,سائيز_t سائيز_4,سائيز_t _Alignment,سائيز_t وٿي_2);
  _CRTIMP فراغ *__cdecl aligned_وٿي_recalloc(فراغ *يادگيري,سائيز_t ڳڻپ_5,سائيز_t سائيز_4,سائيز_t _Alignment,سائيز_t وٿي_2);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTDLIB_DEFINED
#وصف_ڪريو _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(ڊگهو قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(بنانشان ڊگهو قدر_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr);
  عائم __cdecl wcstof(ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof( ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  ڊگهو مزدوج __cdecl wcstold(ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#جيڪڏهن_پورو /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,_locale_t _Locale);
  ڊگهو __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP ڊگهو __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  بنانشان ڊگهو __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP بنانشان ڊگهو __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#جيڪڏهن_وصف_نه_ٿيل _CRT_WSYSTEM_DEFINED
#وصف_ڪريو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جيڪڏهن_پورو
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ڊگهو __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP ڊگهو __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(بنانشان __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بنانشان __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **پڇاڙي_Ptr,صحيح _Radix);
  _CRTIMP بنانشان __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str ,wchar_t **پڇاڙي_Ptr,صحيح _Radix,_locale_t _Locale);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _POSIX_
#وصف_ڪريو _CVTBUFSIZE (309+40)
  _CRTIMP حرف *__cdecl _fullpath(حرف *ڀريل_رستو,ثابت حرف *رستو_2,سائيز_t سائيز_اندريون_بائيٽون);
  _CRTIMP حرف *__cdecl _ecvt(مزدوج _Val,صحيح انگ_جو_Digits,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _fcvt(مزدوج _Val,صحيح انگ_جو_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _gcvt(مزدوج _Val,صحيح انگ_جو_Digits,حرف *_DstBuf);
  _CRTIMP صحيح __cdecl _atodbl(_CRT_DOUBLE *نتيجو_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoldbl(_LDOUBLE *نتيجو_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoflt(_CRT_FLOAT *نتيجو_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atodbl_l(_CRT_DOUBLE *نتيجو_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoldbl_l(_LDOUBLE *نتيجو_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoflt_l(_CRT_FLOAT *نتيجو_2,حرف *_Str,_locale_t _Locale);
  بنانشان ڊگهو __cdecl _lrotl(بنانشان ڊگهو _Val,صحيح سرڪايو_2);
  بنانشان ڊگهو __cdecl _lrotr(بنانشان ڊگهو _Val,صحيح سرڪايو_2);
  _CRTIMP فراغ __cdecl _makepath(حرف *رستو_2,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#جيڪڏهن_وصف_نه_ٿيل _CRT_PERROR_DEFINED
#وصف_ڪريو _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_نياپو);
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _putenv(ثابت حرف *_EnvString);
  بنانشان صحيح __cdecl _rotl(بنانشان صحيح _Val,صحيح سرڪايو_2);
#إذا INTEGRAL_MAX_بٽ >= 64
  بنانشان __int64 __cdecl _rotl64(بنانشان __int64 _Val,صحيح سرڪايو_2);
#جيڪڏهن_پورو
  بنانشان صحيح __cdecl _rotr(بنانشان صحيح _Val,صحيح سرڪايو_2);
#إذا INTEGRAL_MAX_بٽ >= 64
  بنانشان __int64 __cdecl _rotr64(بنانشان __int64 _Val,صحيح سرڪايو_2);
#جيڪڏهن_پورو
  _CRTIMP فراغ __cdecl _searchenv(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتيجو_رستو);
  _CRTIMP فراغ __cdecl _splitpath(ثابت حرف *ڀريل_رستو,حرف *_Drive,حرف *_Dir,حرف *_Filename,حرف *_Ext);
  _CRTIMP فراغ __cdecl _swab(حرف *_Buf1,حرف *_Buf2,صحيح سائيز_اندريون_بائيٽون);

#جيڪڏهن_وصف_نه_ٿيل _WSTDLIBP_DEFINED
#وصف_ڪريو _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *ڀريل_رستو,ثابت wchar_t *رستو_2,سائيز_t سائيز_اندريون_لفظ);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *نتيجو_رستو,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#جيڪڏهن_وصف_نه_ٿيل _CRT_WPERROR_DEFINED
#وصف_ڪريو _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_نياپو);
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتيجو_رستو);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *ڀريل_رستو,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#جيڪڏهن_پورو

  _CRTIMP فراغ __cdecl _beep(بنانشان _Frequency,بنانشان _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP فراغ __cdecl _seterrormode(صحيح گهڻائي_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP فراغ __cdecl _sleep(بنانشان ڊگهو _Duration) __MINGW_ATTRIB_DEPRECATED;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NO_OLDNAMES
#جيڪڏهن_وصف_نه_ٿيل _POSIX_
#إذا 0
#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#جيڪڏهن_وصف_نه_ٿيل NOMINMAX
#جيڪڏهن_وصف_نه_ٿيل max
#وصف_ڪريو max(a,b) (((a) > (b)) ? (a) : (b))
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل min
#وصف_ڪريو min(a,b) (((a) < (b)) ? (a) : (b))
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو sys_errlist _sys_errlist
#وصف_ڪريو sys_nerr _sys_nerr
#وصف_ڪريو environ _environ
  حرف *__cdecl ecvt(مزدوج _Val,صحيح انگ_جو_Digits,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl fcvt(مزدوج _Val,صحيح انگ_جو_Dec,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl gcvt(مزدوج _Val,صحيح انگ_جو_Digits,حرف *_DstBuf);
  حرف *__cdecl itoa(صحيح _Val,حرف *_DstBuf,صحيح _Radix);
  حرف *__cdecl ltoa(ڊگهو _Val,حرف *_DstBuf,صحيح _Radix);
  صحيح __cdecl putenv(ثابت حرف *_EnvString);
  فراغ __cdecl swab(حرف *_Buf1,حرف *_Buf2,صحيح سائيز_اندريون_بائيٽون);
  حرف *__cdecl ultoa(بنانشان ڊگهو _Val,حرف *_Dstbuf,صحيح _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#إذا !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  تعريفنوع بنية { ڊگهو ڊگهو quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(ڊگهو ڊگهو, ڊگهو ڊگهو);

  __CRT_INLINE ڊگهو ڊگهو __cdecl llabs(ڊگهو ڊگهو _j) { أرجع (_j >= 0 ? _j : -_j); }

 #جيڪڏهن_وصف_ٿيل __TINYC__ /* gr */
  #وصف_ڪريو strtoll _strtoi64
  #وصف_ڪريو strtoull _strtoui64
 #وإلا
  ڊگهو ڊگهو  __cdecl strtoll(ثابت حرف* __restrict__, حرف** __restrict, صحيح);
  بنانشان ڊگهو ڊگهو  __cdecl strtoull(ثابت حرف* __restrict__, حرف** __restrict__, صحيح);
 #جيڪڏهن_پورو

  /* these are stubs for MS _i64 versions */
  ڊگهو ڊگهو  __cdecl atoll (ثابت حرف *);

#جيڪڏهن_وصف_نه_ٿيل __STRICT_ANSI__
  ڊگهو ڊگهو  __cdecl wtoll (ثابت wchar_t *);
  حرف *__cdecl lltoa (ڊگهو ڊگهو, حرف *, صحيح);
  حرف *__cdecl ulltoa (بنانشان ڊگهو ڊگهو , حرف *, صحيح);
  wchar_t *__cdecl lltow (ڊگهو ڊگهو, wchar_t *, صحيح);
  wchar_t *__cdecl ulltow (بنانشان ڊگهو ڊگهو, wchar_t *, صحيح);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE ڊگهو ڊگهو  __cdecl atoll (ثابت حرف * _c) { أرجع _atoi64 (_c); }
  __CRT_INLINE حرف *__cdecl lltoa (ڊگهو ڊگهو _n, حرف * _c, صحيح _i) { أرجع _i64toa (_n, _c, _i); }
  __CRT_INLINE حرف *__cdecl ulltoa (بنانشان ڊگهو ڊگهو _n, حرف * _c, صحيح _i) { أرجع _ui64toa (_n, _c, _i); }
  __CRT_INLINE ڊگهو ڊگهو  __cdecl wtoll (ثابت wchar_t * _w) { أرجع _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (ڊگهو ڊگهو _n, wchar_t * _w, صحيح _i) { أرجع _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (بنانشان ڊگهو ڊگهو _n, wchar_t * _w, صحيح _i) { أرجع _ui64tow (_n, _w, _i); }
#جيڪڏهن_پورو /* (__STRICT_ANSI__)  */

#جيڪڏهن_پورو /* !__NO_ISOCEXT */

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)

#ضمن <sec_api/stdlib_s.h>
#ضمن <malloc.h>

#جيڪڏهن_پورو
