/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_STDLIB
#تعریف_کرو _INC_STDLIB

#ضمن <_mingw.h>
#ضمن <limits.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف عدم
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو عدم 0
#وإلا
#تعریف_کرو عدم ((فراغ *)0)
#جے_انت
#جے_انت

#تعریف_کرو EXIT_SUCCESS 0
#تعریف_کرو EXIT_FAILURE 1

#جے_بنا_تعریف _ONEXIT_T_DEFINED
#تعریف_کرو _ONEXIT_T_DEFINED

  تعريفنوع صحيح (__cdecl *_onexit_t)(فراغ);

#جے_بنا_تعریف NO_OLDNAMES
#تعریف_کرو onexit_t _onexit_t
#جے_انت
#جے_انت

#جے_بنا_تعریف _DIV_T_DEFINED
#تعریف_کرو _DIV_T_DEFINED

  تعريفنوع بنية _div_t {
    صحيح quot;
    صحيح rem;
  } div_t;

  تعريفنوع بنية _ldiv_t {
    لما quot;
    لما rem;
  } ldiv_t;
#جے_انت

#جے_بنا_تعریف _CRT_DOUBLE_DEC
#تعریف_کرو _CRT_DOUBLE_DEC

#ہدایت pack(4)
  تعريفنوع بنية {
    بنانشانی حرف ld[10];
  } _LDOUBLE;
#ہدایت pack()

#تعریف_کرو _PTR_LD(x) ((بنانشانی حرف *)(&(x)->ld))

  تعريفنوع بنية {
    مزدوج x;
  } _CRT_DOUBLE;

  تعريفنوع بنية {
    عائم f;
  } _CRT_FLOAT;

#ہدایت ڈالو_macro("long")
#تعریف_رد لما

  تعريفنوع بنية {
    لما مزدوج x;
  } _LONGDOUBLE;

#ہدایت نکالو_macro("long")

#ہدایت pack(4)
  تعريفنوع بنية {
    بنانشانی حرف ld12[12];
  } _LDBL12;
#ہدایت pack()
#جے_انت

#تعریف_کرو RAND_MAX 0x7fff

#جے_بنا_تعریف MB_CUR_MAX
#تعریف_کرو MB_CUR_MAX ___mb_cur_max_func()
#جے_بنا_تعریف __mb_cur_max
#جے_تعریف_شدہ _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#تعریف_کرو __mb_cur_max    (*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#جے_انت
#جے_انت
#جے_تعریف_شدہ _MSVCRT_
  خارجي صحيح __mbcur_max;
#تعریف_کرو ___mb_cur_max_func() (__mb_cur_max)
#وإلا
  خارجي صحيح* _imp____mbcur_max;
#تعریف_کرو ___mb_cur_max_func() (*_imp____mb_cur_max)
#جے_انت
#جے_انت

#تعریف_کرو __max(a,b) (((a) > (b)) ? (a) : (b))
#تعریف_کرو __min(a,b) (((a) < (b)) ? (a) : (b))

#تعریف_کرو MAX_رستہ_2 260
#تعریف_کرو _MAX_DRIVE 3
#تعریف_کرو _MAX_DIR 256
#تعریف_کرو _MAX_FNAME 256
#تعریف_کرو _MAX_EXT 256

#تعریف_کرو باہرلا_منزل_DEFAULT 0
#تعریف_کرو باہرلا_منزل_STDERR 1
#تعریف_کرو باہرلا_منزل_MSGBOX 2
#تعریف_کرو _REPORT_ERRMODE 3

#تعریف_کرو WRITE_ABORT_پیغام 0x1
#تعریف_کرو _CALL_REPORTFAULT 0x2

#تعریف_کرو _MAX_ENV 32767

  تعريفنوع فراغ (__cdecl *_purecall_handler)(فراغ);

  _CRTIMP _purecall_handler __cdecl سیٹ_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(فراغ);

  تعريفنوع فراغ (__cdecl *_invalid_parameter_handler)(ثابت wchar_t *,ثابت wchar_t *,ثابت wchar_t *,بنانشانی صحيح,uintptr_t);
  _invalid_parameter_handler __cdecl سیٹ_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(فراغ);

#جے_بنا_تعریف _CRT_ERRNO_DEFINED
#تعریف_کرو _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#تعریف_کرو errno (*_errno())
  errno_t __cdecl سیٹ_errno(صحيح قدر_2);
  errno_t __cdecl _get_errno(صحيح *قدر_2);
#جے_انت
  _CRTIMP بنانشانی لما *__cdecl __doserrno(فراغ);
#تعریف_کرو _doserrno (*__doserrno())
  errno_t __cdecl سیٹ_doserrno(بنانشانی لما قدر_2);
  errno_t __cdecl _get_doserrno(بنانشانی لما *قدر_2);
#جے_تعریف_شدہ _MSVCRT_
  خارجي حرف *_sys_errlist[];
  خارجي صحيح _sys_nerr;
#وإلا
  _CRTIMP حرف *_sys_errlist[1];
  _CRTIMP صحيح _sys_nerr;
#جے_انت
#إذا (defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح *__cdecl __p___argc(فراغ);
  _CRTIMP حرف ***__cdecl __p___argv(فراغ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(فراغ);
  _CRTIMP حرف ***__cdecl __p__environ(فراغ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(فراغ);
  _CRTIMP حرف **__cdecl __p__pgmptr(فراغ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(فراغ);
#جے_انت
#جے_بنا_تعریف __argc
#جے_تعریف_شدہ _MSVCRT_
  خارجي صحيح __argc;
#وإلا
#تعریف_کرو __argc (*_imp____argc)
  خارجي صحيح *_imp____argc;
#جے_انت
#جے_انت
#جے_بنا_تعریف __argv
#جے_تعریف_شدہ _MSVCRT_
  خارجي حرف **__argv;
#وإلا
#تعریف_کرو __argv  (*_imp____argv)
  خارجي حرف ***_imp____argv;
#جے_انت
#جے_انت
#جے_بنا_تعریف __wargv
#جے_تعریف_شدہ _MSVCRT_
  خارجي wchar_t **__wargv;
#وإلا
#تعریف_کرو __wargv (*_imp____wargv)
  خارجي wchar_t ***_imp____wargv;
#جے_انت
#جے_انت

#جے_تعریف_شدہ _POSIX_
  خارجي حرف **environ;
#وإلا
#جے_بنا_تعریف _environ
#جے_تعریف_شدہ _MSVCRT_
  خارجي حرف **_environ;
#وإلا
#تعریف_کرو _environ (*_imp___environ)
  خارجي حرف ***_imp___environ;
#جے_انت
#جے_انت

#جے_بنا_تعریف _wenviron
#جے_تعریف_شدہ _MSVCRT_
  خارجي wchar_t **_wenviron;
#وإلا
#تعریف_کرو _wenviron       (*_imp___wenviron)
  خارجي wchar_t ***_imp___wenviron;
#جے_انت
#جے_انت
#جے_انت

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
#جے_انت

#جے_بنا_تعریف _pgmptr
#جے_تعریف_شدہ _MSVCRT_
  خارجي حرف *_pgmptr;
#وإلا
#تعریف_کرو _pgmptr (*_imp___pgmptr)
  خارجي حرف **_imp___pgmptr;
#جے_انت
#جے_انت

#جے_بنا_تعریف _wpgmptr
#جے_تعریف_شدہ _MSVCRT_
  خارجي wchar_t *_wpgmptr;
#وإلا
#تعریف_کرو _wpgmptr        (*_imp___wpgmptr)
  خارجي wchar_t **_imp___wpgmptr;
#جے_انت
#جے_انت
  errno_t __cdecl _get_pgmptr(حرف **قدر_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **قدر_2);
#جے_بنا_تعریف _fmode
#جے_تعریف_شدہ _MSVCRT_
  خارجي صحيح _fmode;
#وإلا
#تعریف_کرو _fmode  (*_imp___fmode)
  خارجي صحيح *_imp___fmode;
#جے_انت
#جے_انت
  _CRTIMP errno_t __cdecl سیٹ_fmode(صحيح منوال_3);
  _CRTIMP errno_t __cdecl _get_fmode(صحيح *_PMode);

#جے_بنا_تعریف _osplatform
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی صحيح _osplatform;
#وإلا
#تعریف_کرو _osplatform (*_imp___osplatform)
  خارجي بنانشانی صحيح *_imp___osplatform;
#جے_انت
#جے_انت

#جے_بنا_تعریف _osver
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی صحيح _osver;
#وإلا
#تعریف_کرو _osver  (*_imp___osver)
  خارجي بنانشانی صحيح *_imp___osver;
#جے_انت
#جے_انت

#جے_بنا_تعریف _winver
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی صحيح _winver;
#وإلا
#تعریف_کرو _winver (*_imp___winver)
  خارجي بنانشانی صحيح *_imp___winver;
#جے_انت
#جے_انت

#جے_بنا_تعریف _winmajor
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی صحيح _winmajor;
#وإلا
#تعریف_کرو _winmajor       (*_imp___winmajor)
  خارجي بنانشانی صحيح *_imp___winmajor;
#جے_انت
#جے_انت

#جے_بنا_تعریف _winminor
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی صحيح _winminor;
#وإلا
#تعریف_کرو _winminor       (*_imp___winminor)
  خارجي بنانشانی صحيح *_imp___winminor;
#جے_انت
#جے_انت

  errno_t __cdecl _get_osplatform(بنانشانی صحيح *قدر_2);
  errno_t __cdecl _get_osver(بنانشانی صحيح *قدر_2);
  errno_t __cdecl _get_winver(بنانشانی صحيح *قدر_2);
  errno_t __cdecl _get_winmajor(بنانشانی صحيح *قدر_2);
  errno_t __cdecl _get_winminor(بنانشانی صحيح *قدر_2);
#جے_بنا_تعریف _countof
#جے_بنا_تعریف __cplusplus
#تعریف_کرو _countof(_Array) (حجم(_Array) / حجم(_Array[0]))
#وإلا
  خارجي "C++" {
    سانچا <typename _CountofType,ناپ_t ناپ_دا_Array> حرف (*__countof_helper(UNALIGNED _CountofType (&_Array)[ناپ_دا_Array]))[ناپ_دا_Array];
#تعریف_کرو _countof(_Array) حجم(*__countof_helper(_Array))
  }
#جے_انت
#جے_انت

#جے_بنا_تعریف _CRT_TERMINATE_DEFINED
#تعریف_کرو _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW باہر_نکلو(صحيح کوڈ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کوڈ_3) __MINGW_ATTRIB_NORETURN;
#إذا !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  فراغ __cdecl _Exit(صحيح) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN فراغ  __cdecl _Exit(صحيح حالت)
  {  _exit(حالت); }
#جے_انت

#ہدایت ڈالو_macro("abort")
#تعریف_رد abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#ہدایت نکالو_macro("abort")

#جے_انت

  _CRTIMP بنانشانی صحيح __cdecl سیٹ_abort_behavior(بنانشانی صحيح _Flags,بنانشانی صحيح نقاب_2);

#جے_بنا_تعریف _CRT_ABS_DEFINED
#تعریف_کرو _CRT_ABS_DEFINED
  صحيح __cdecl مطلق_قدر(صحيح _X);
  لما __cdecl labs(لما _X);
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 64
  __int64 __cdecl _abs64(__int64);
#جے_انت
  صحيح __cdecl atexit(فراغ (__cdecl *)(فراغ));
#جے_بنا_تعریف _CRT_ATOF_DEFINED
#تعریف_کرو _CRT_ATOF_DEFINED
  مزدوج __cdecl atof(ثابت حرف *_String);
  مزدوج __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#جے_انت
  صحيح __cdecl atoi(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _atoi_l(ثابت حرف *_Str,_locale_t _Locale);
  لما __cdecl atol(ثابت حرف *_Str);
  _CRTIMP لما __cdecl _atol_l(ثابت حرف *_Str,_locale_t _Locale);
#جے_بنا_تعریف _CRT_ALGO_DEFINED
#تعریف_کرو _CRT_ALGO_DEFINED
  فراغ *__cdecl bsearch(ثابت فراغ *کلید_2,ثابت فراغ *ادھار_3,ناپ_t عدد_دا_Elements,ناپ_t ناپ_دا_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
  فراغ __cdecl qsort(فراغ *ادھار_3,ناپ_t عدد_دا_Elements,ناپ_t ناپ_دا_Elements,صحيح (__cdecl *_PtFuncCompare)(ثابت فراغ *,ثابت فراغ *));
#جے_انت
  بنانشانی چھوٹا __cdecl _byteswap_ushort(بنانشانی چھوٹا _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#إذا INTEGRAL_MAX_بٹ >= 64
  بنانشانی __int64 __cdecl _byteswap_uint64(بنانشانی __int64 _Int64);
#جے_انت
  div_t __cdecl div(صحيح _Numerator,صحيح _Denominator);
  حرف *__cdecl getenv(ثابت حرف *_VarName);
  _CRTIMP حرف *__cdecl _itoa(صحيح قدر_2,حرف *_Dest,صحيح _Radix);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP حرف *__cdecl _i64toa(__int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP حرف *__cdecl _ui64toa(بنانشانی __int64 _Val,حرف *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ثابت حرف *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ثابت حرف *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ثابت حرف *_String,حرف **سرا_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ثابت حرف *_String,حرف **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بنانشانی __int64 __cdecl _strtoui64(ثابت حرف *_String,حرف **سرا_Ptr,صحيح _Radix);
  _CRTIMP بنانشانی __int64 __cdecl _strtoui64_l(ثابت حرف *_String,حرف **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
#جے_انت
  ldiv_t __cdecl ldiv(لما _Numerator,لما _Denominator);
  _CRTIMP حرف *__cdecl _ltoa(لما قدر_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl mblen(ثابت حرف *_Ch,ناپ_t Max_گنتی);
  _CRTIMP صحيح __cdecl _mblen_l(ثابت حرف *_Ch,ناپ_t Max_گنتی,_locale_t _Locale);
  _CRTIMP ناپ_t __cdecl _mbstrlen(ثابت حرف *_Str);
  _CRTIMP ناپ_t __cdecl _mbstrlen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP ناپ_t __cdecl _mbstrnlen(ثابت حرف *_Str,ناپ_t Max_گنتی);
  _CRTIMP ناپ_t __cdecl _mbstrnlen_l(ثابت حرف *_Str,ناپ_t Max_گنتی,_locale_t _Locale);
  صحيح __cdecl mbtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,ناپ_t Src_ناپ_وچ_بائٹاں);
  _CRTIMP صحيح __cdecl _mbtowc_l(wchar_t *_DstCh,ثابت حرف *_SrcCh,ناپ_t Src_ناپ_وچ_بائٹاں,_locale_t _Locale);
  ناپ_t __cdecl mbstowcs(wchar_t *_Dest,ثابت حرف *سروت_3,ناپ_t Max_گنتی);
  _CRTIMP ناپ_t __cdecl _mbstowcs_l(wchar_t *_Dest,ثابت حرف *سروت_3,ناپ_t Max_گنتی,_locale_t _Locale);
  صحيح __cdecl rand(فراغ);
  _CRTIMP صحيح __cdecl سیٹ_error_منوال(صحيح منوال_3);
  فراغ __cdecl srand(بنانشانی صحيح بیج);
  مزدوج __cdecl strtod(ثابت حرف *_Str,حرف **سرا_Ptr);
#إذا !defined __NO_ISOCEXT  /* in libmingwex.a */
#إذا __TINYC__
  __CRT_INLINE عائم __cdecl strtof (ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
  __CRT_INLINE لما مزدوج __cdecl strtold(ثابت حرف *p, حرف ** e) { أرجع strtod(p, e); }
#وإلا
  عائم __cdecl strtof (ثابت حرف * __restrict__, حرف ** __restrict__);
  لما مزدوج __cdecl strtold(ثابت حرف * __restrict__, حرف ** __restrict__);
#جے_انت
#وإلا
  عائم __cdecl strtof(ثابت حرف *nptr, حرف **endptr);
#جے_انت /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _strtod_l(ثابت حرف *_Str,حرف **سرا_Ptr,_locale_t _Locale);
  لما __cdecl strtol(ثابت حرف *_Str,حرف **سرا_Ptr,صحيح _Radix);
  _CRTIMP لما __cdecl _strtol_l(ثابت حرف *_Str,حرف **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  بنانشانی لما __cdecl strtoul(ثابت حرف *_Str,حرف **سرا_Ptr,صحيح _Radix);
  _CRTIMP بنانشانی لما __cdecl _strtoul_l(ثابت حرف *_Str,حرف **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
#جے_بنا_تعریف _CRT_SYSTEM_DEFINED
#تعریف_کرو _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#جے_انت
  _CRTIMP حرف *__cdecl _ultoa(بنانشانی لما قدر_2,حرف *_Dest,صحيح _Radix);
  صحيح __cdecl wctomb(حرف *_MbCh,wchar_t _WCh);
  _CRTIMP صحيح __cdecl _wctomb_l(حرف *_MbCh,wchar_t _WCh,_locale_t _Locale);
  ناپ_t __cdecl wcstombs(حرف *_Dest,ثابت wchar_t *سروت_3,ناپ_t Max_گنتی);
  _CRTIMP ناپ_t __cdecl _wcstombs_l(حرف *_Dest,ثابت wchar_t *سروت_3,ناپ_t Max_گنتی,_locale_t _Locale);

#جے_بنا_تعریف CRT_ونڈ_DEFINED
#تعریف_کرو CRT_ونڈ_DEFINED
  فراغ *__cdecl صفر_حافظہ_دیو(ناپ_t عدد_دا_Elements,ناپ_t ناپ_دا_Elements);
  فراغ __cdecl حرر(فراغ *حافظہ);
  فراغ *__cdecl حافظہ_دیو(ناپ_t ناپ_4);
  فراغ *__cdecl realloc(فراغ *حافظہ,ناپ_t New_ناپ);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *حافظہ,ناپ_t گنتی_5,ناپ_t ناپ_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *حافظہ);
  _CRTIMP فراغ *__cdecl _aligned_malloc(ناپ_t ناپ_4,ناپ_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وتھ_malloc(ناپ_t ناپ_4,ناپ_t _Alignment,ناپ_t وتھ_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *حافظہ,ناپ_t ناپ_4,ناپ_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *حافظہ,ناپ_t گنتی_5,ناپ_t ناپ_4,ناپ_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وتھ_realloc(فراغ *حافظہ,ناپ_t ناپ_4,ناپ_t _Alignment,ناپ_t وتھ_2);
  _CRTIMP فراغ *__cdecl aligned_وتھ_recalloc(فراغ *حافظہ,ناپ_t گنتی_5,ناپ_t ناپ_4,ناپ_t _Alignment,ناپ_t وتھ_2);
#جے_انت

#جے_بنا_تعریف _WSTDLIB_DEFINED
#تعریف_کرو _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحيح قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(لما قدر_2,wchar_t *_Dest,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(بنانشانی لما قدر_2,wchar_t *_Dest,صحيح _Radix);
  مزدوج __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **سرا_Ptr);
  عائم __cdecl wcstof(ثابت wchar_t *nptr, wchar_t **endptr);
#إذا !defined __NO_ISOCEXT /* in libmingwex.a */
  عائم __cdecl wcstof( ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  لما مزدوج __cdecl wcstold(ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#جے_انت /* __NO_ISOCEXT */
  _CRTIMP مزدوج __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,_locale_t _Locale);
  لما __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP لما __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  بنانشانی لما __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP بنانشانی لما __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#جے_بنا_تعریف _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جے_انت
  _CRTIMP مزدوج __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP مزدوج __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP لما __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP لما __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(بنانشانی __int64 _Val,wchar_t *_DstBuf,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
  _CRTIMP بنانشانی __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **سرا_Ptr,صحيح _Radix);
  _CRTIMP بنانشانی __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str ,wchar_t **سرا_Ptr,صحيح _Radix,_locale_t _Locale);
#جے_انت
#جے_انت

#جے_بنا_تعریف _POSIX_
#تعریف_کرو _CVTBUFSIZE (309+40)
  _CRTIMP حرف *__cdecl _fullpath(حرف *بھریا_رستہ,ثابت حرف *رستہ_2,ناپ_t ناپ_وچ_بائٹاں);
  _CRTIMP حرف *__cdecl _ecvt(مزدوج _Val,صحيح عدد_دا_Digits,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _fcvt(مزدوج _Val,صحيح عدد_دا_Dec,صحيح *_PtDec,صحيح *_PtSign);
  _CRTIMP حرف *__cdecl _gcvt(مزدوج _Val,صحيح عدد_دا_Digits,حرف *_DstBuf);
  _CRTIMP صحيح __cdecl _atodbl(_CRT_DOUBLE *نتیجہ_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoldbl(_LDOUBLE *نتیجہ_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atoflt(_CRT_FLOAT *نتیجہ_2,حرف *_Str);
  _CRTIMP صحيح __cdecl _atodbl_l(_CRT_DOUBLE *نتیجہ_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoldbl_l(_LDOUBLE *نتیجہ_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _atoflt_l(_CRT_FLOAT *نتیجہ_2,حرف *_Str,_locale_t _Locale);
  بنانشانی لما __cdecl _lrotl(بنانشانی لما _Val,صحيح کھسکاؤ_2);
  بنانشانی لما __cdecl _lrotr(بنانشانی لما _Val,صحيح کھسکاؤ_2);
  _CRTIMP فراغ __cdecl _makepath(حرف *رستہ_2,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#جے_بنا_تعریف _CRT_PERROR_DEFINED
#تعریف_کرو _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_پیغام);
#جے_انت
  _CRTIMP صحيح __cdecl _putenv(ثابت حرف *_EnvString);
  بنانشانی صحيح __cdecl _rotl(بنانشانی صحيح _Val,صحيح کھسکاؤ_2);
#إذا INTEGRAL_MAX_بٹ >= 64
  بنانشانی __int64 __cdecl _rotl64(بنانشانی __int64 _Val,صحيح کھسکاؤ_2);
#جے_انت
  بنانشانی صحيح __cdecl _rotr(بنانشانی صحيح _Val,صحيح کھسکاؤ_2);
#إذا INTEGRAL_MAX_بٹ >= 64
  بنانشانی __int64 __cdecl _rotr64(بنانشانی __int64 _Val,صحيح کھسکاؤ_2);
#جے_انت
  _CRTIMP فراغ __cdecl _searchenv(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتیجہ_رستہ);
  _CRTIMP فراغ __cdecl _splitpath(ثابت حرف *بھریا_رستہ,حرف *_Drive,حرف *_Dir,حرف *_Filename,حرف *_Ext);
  _CRTIMP فراغ __cdecl _swab(حرف *_Buf1,حرف *_Buf2,صحيح ناپ_وچ_بائٹاں);

#جے_بنا_تعریف _WSTDLIBP_DEFINED
#تعریف_کرو _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *بھریا_رستہ,ثابت wchar_t *رستہ_2,ناپ_t ناپ_وچ_الفاظ);
  _CRTIMP فراغ __cdecl _wmakepath(wchar_t *نتیجہ_رستہ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#جے_بنا_تعریف _CRT_WPERROR_DEFINED
#تعریف_کرو _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#جے_انت
  _CRTIMP صحيح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP فراغ __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_رستہ);
  _CRTIMP فراغ __cdecl _wsplitpath(ثابت wchar_t *بھریا_رستہ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#جے_انت

  _CRTIMP فراغ __cdecl _beep(بنانشانی _Frequency,بنانشانی _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP فراغ __cdecl _seterrormode(صحيح منوال_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP فراغ __cdecl _sleep(بنانشانی لما _Duration) __MINGW_ATTRIB_DEPRECATED;
#جے_انت

#جے_بنا_تعریف NO_OLDNAMES
#جے_بنا_تعریف _POSIX_
#إذا 0
#جے_بنا_تعریف __cplusplus
#جے_بنا_تعریف NOMINMAX
#جے_بنا_تعریف max
#تعریف_کرو max(a,b) (((a) > (b)) ? (a) : (b))
#جے_انت
#جے_بنا_تعریف min
#تعریف_کرو min(a,b) (((a) < (b)) ? (a) : (b))
#جے_انت
#جے_انت
#جے_انت
#جے_انت

#تعریف_کرو sys_errlist _sys_errlist
#تعریف_کرو sys_nerr _sys_nerr
#تعریف_کرو environ _environ
  حرف *__cdecl ecvt(مزدوج _Val,صحيح عدد_دا_Digits,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl fcvt(مزدوج _Val,صحيح عدد_دا_Dec,صحيح *_PtDec,صحيح *_PtSign);
  حرف *__cdecl gcvt(مزدوج _Val,صحيح عدد_دا_Digits,حرف *_DstBuf);
  حرف *__cdecl itoa(صحيح _Val,حرف *_DstBuf,صحيح _Radix);
  حرف *__cdecl ltoa(لما _Val,حرف *_DstBuf,صحيح _Radix);
  صحيح __cdecl putenv(ثابت حرف *_EnvString);
  فراغ __cdecl swab(حرف *_Buf1,حرف *_Buf2,صحيح ناپ_وچ_بائٹاں);
  حرف *__cdecl ultoa(بنانشانی لما _Val,حرف *_Dstbuf,صحيح _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#جے_انت
#جے_انت

#إذا !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  تعريفنوع بنية { لما لما quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(لما لما, لما لما);

  __CRT_INLINE لما لما __cdecl llabs(لما لما _j) { أرجع (_j >= 0 ? _j : -_j); }

 #جے_تعریف_شدہ __TINYC__ /* gr */
  #تعریف_کرو strtoll _strtoi64
  #تعریف_کرو strtoull _strtoui64
 #وإلا
  لما لما  __cdecl strtoll(ثابت حرف* __restrict__, حرف** __restrict, صحيح);
  بنانشانی لما لما  __cdecl strtoull(ثابت حرف* __restrict__, حرف** __restrict__, صحيح);
 #جے_انت

  /* these are stubs for MS _i64 versions */
  لما لما  __cdecl atoll (ثابت حرف *);

#جے_بنا_تعریف __STRICT_ANSI__
  لما لما  __cdecl wtoll (ثابت wchar_t *);
  حرف *__cdecl lltoa (لما لما, حرف *, صحيح);
  حرف *__cdecl ulltoa (بنانشانی لما لما , حرف *, صحيح);
  wchar_t *__cdecl lltow (لما لما, wchar_t *, صحيح);
  wchar_t *__cdecl ulltow (بنانشانی لما لما, wchar_t *, صحيح);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE لما لما  __cdecl atoll (ثابت حرف * _c) { أرجع _atoi64 (_c); }
  __CRT_INLINE حرف *__cdecl lltoa (لما لما _n, حرف * _c, صحيح _i) { أرجع _i64toa (_n, _c, _i); }
  __CRT_INLINE حرف *__cdecl ulltoa (بنانشانی لما لما _n, حرف * _c, صحيح _i) { أرجع _ui64toa (_n, _c, _i); }
  __CRT_INLINE لما لما  __cdecl wtoll (ثابت wchar_t * _w) { أرجع _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (لما لما _n, wchar_t * _w, صحيح _i) { أرجع _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (بنانشانی لما لما _n, wchar_t * _w, صحيح _i) { أرجع _ui64tow (_n, _w, _i); }
#جے_انت /* (__STRICT_ANSI__)  */

#جے_انت /* !__NO_ISOCEXT */

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)

#ضمن <sec_api/stdlib_s.h>
#ضمن <malloc.h>

#جے_انت
