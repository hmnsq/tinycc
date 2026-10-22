/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_STDLIB
#تعریف_کرو _INC_STDLIB

#شامل <_mingw.h>
#شامل <limits.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#تعریف_کرو EXIT_SUCCESS 0
#تعریف_کرو EXIT_FAILURE 1

#اگر_غیر_تعریف_شدہ _ONEXIT_T_DEFINED
#تعریف_کرو _ONEXIT_T_DEFINED

  قسمتعریف صحیح (__cdecl *_onexit_t)(خالی);

#اگر_غیر_تعریف_شدہ NO_OLDNAMES
#تعریف_کرو onexit_t _onexit_t
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _DIV_T_DEFINED
#تعریف_کرو _DIV_T_DEFINED

  قسمتعریف ساخت _div_t {
    صحیح quot;
    صحیح rem;
  } div_t;

  قسمتعریف ساخت _ldiv_t {
    طویل quot;
    طویل rem;
  } ldiv_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_DOUBLE_DEC
#تعریف_کرو _CRT_DOUBLE_DEC

#ہدایت pack(4)
  قسمتعریف ساخت {
    غیرعلامتی حرف ld[10];
  } _LDOUBLE;
#ہدایت pack()

#تعریف_کرو _PTR_LD(x) ((غیرعلامتی حرف *)(&(x)->ld))

  قسمتعریف ساخت {
    دوہرا x;
  } _CRT_DOUBLE;

  قسمتعریف ساخت {
    اعشاری f;
  } _CRT_FLOAT;

#ہدایت ڈالو_macro("long")
#تعریف_منسوخ طویل

  قسمتعریف ساخت {
    طویل دوہرا x;
  } _LONGDOUBLE;

#ہدایت نکالو_macro("long")

#ہدایت pack(4)
  قسمتعریف ساخت {
    غیرعلامتی حرف ld12[12];
  } _LDBL12;
#ہدایت pack()
#اگر_ختم

#تعریف_کرو RAND_MAX 0x7fff

#اگر_غیر_تعریف_شدہ MB_CUR_MAX
#تعریف_کرو MB_CUR_MAX ___mb_cur_max_func()
#اگر_غیر_تعریف_شدہ __mb_cur_max
#اگر_تعریف_شدہ _MSVCRT_
  خارجی صحیح __mb_cur_max;
#ورنہ
#تعریف_کرو __mb_cur_max    (*_imp____mb_cur_max)
  خارجی صحیح *_imp____mb_cur_max;
#اگر_ختم
#اگر_ختم
#اگر_تعریف_شدہ _MSVCRT_
  خارجی صحیح __mbcur_max;
#تعریف_کرو ___mb_cur_max_func() (__mb_cur_max)
#ورنہ
  خارجی صحیح* _imp____mbcur_max;
#تعریف_کرو ___mb_cur_max_func() (*_imp____mb_cur_max)
#اگر_ختم
#اگر_ختم

#تعریف_کرو __max(a,b) (((a) > (b)) ? (a) : (b))
#تعریف_کرو __min(a,b) (((a) < (b)) ? (a) : (b))

#تعریف_کرو MAX_راستہ_2 260
#تعریف_کرو _MAX_DRIVE 3
#تعریف_کرو _MAX_DIR 256
#تعریف_کرو _MAX_FNAME 256
#تعریف_کرو _MAX_EXT 256

#تعریف_کرو برآمد_مقصد_DEFAULT 0
#تعریف_کرو برآمد_مقصد_STDERR 1
#تعریف_کرو برآمد_مقصد_MSGBOX 2
#تعریف_کرو _REPORT_ERRMODE 3

#تعریف_کرو WRITE_ABORT_پیغام 0x1
#تعریف_کرو _CALL_REPORTFAULT 0x2

#تعریف_کرو _MAX_ENV 32767

  قسمتعریف خالی (__cdecl *_purecall_handler)(خالی);

  _CRTIMP _purecall_handler __cdecl سیٹ_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(خالی);

  قسمتعریف خالی (__cdecl *_invalid_parameter_handler)(ثابت wchar_t *,ثابت wchar_t *,ثابت wchar_t *,غیرعلامتی صحیح,uintptr_t);
  _invalid_parameter_handler __cdecl سیٹ_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(خالی);

#اگر_غیر_تعریف_شدہ _CRT_ERRNO_DEFINED
#تعریف_کرو _CRT_ERRNO_DEFINED
  _CRTIMP صحیح *__cdecl _errno(خالی);
#تعریف_کرو errno (*_errno())
  errno_t __cdecl سیٹ_errno(صحیح قدر_2);
  errno_t __cdecl _get_errno(صحیح *قدر_2);
#اگر_ختم
  _CRTIMP غیرعلامتی طویل *__cdecl __doserrno(خالی);
#تعریف_کرو _doserrno (*__doserrno())
  errno_t __cdecl سیٹ_doserrno(غیرعلامتی طویل قدر_2);
  errno_t __cdecl _get_doserrno(غیرعلامتی طویل *قدر_2);
#اگر_تعریف_شدہ _MSVCRT_
  خارجی حرف *_sys_errlist[];
  خارجی صحیح _sys_nerr;
#ورنہ
  _CRTIMP حرف *_sys_errlist[1];
  _CRTIMP صحیح _sys_nerr;
#اگر_ختم
#اگر (defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح *__cdecl __p___argc(خالی);
  _CRTIMP حرف ***__cdecl __p___argv(خالی);
  _CRTIMP wchar_t ***__cdecl __p___wargv(خالی);
  _CRTIMP حرف ***__cdecl __p__environ(خالی);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(خالی);
  _CRTIMP حرف **__cdecl __p__pgmptr(خالی);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(خالی);
#اگر_ختم
#اگر_غیر_تعریف_شدہ __argc
#اگر_تعریف_شدہ _MSVCRT_
  خارجی صحیح __argc;
#ورنہ
#تعریف_کرو __argc (*_imp____argc)
  خارجی صحیح *_imp____argc;
#اگر_ختم
#اگر_ختم
#اگر_غیر_تعریف_شدہ __argv
#اگر_تعریف_شدہ _MSVCRT_
  خارجی حرف **__argv;
#ورنہ
#تعریف_کرو __argv  (*_imp____argv)
  خارجی حرف ***_imp____argv;
#اگر_ختم
#اگر_ختم
#اگر_غیر_تعریف_شدہ __wargv
#اگر_تعریف_شدہ _MSVCRT_
  خارجی wchar_t **__wargv;
#ورنہ
#تعریف_کرو __wargv (*_imp____wargv)
  خارجی wchar_t ***_imp____wargv;
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ _POSIX_
  خارجی حرف **environ;
#ورنہ
#اگر_غیر_تعریف_شدہ _environ
#اگر_تعریف_شدہ _MSVCRT_
  خارجی حرف **_environ;
#ورنہ
#تعریف_کرو _environ (*_imp___environ)
  خارجی حرف ***_imp___environ;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _wenviron
#اگر_تعریف_شدہ _MSVCRT_
  خارجی wchar_t **_wenviron;
#ورنہ
#تعریف_کرو _wenviron       (*_imp___wenviron)
  خارجی wchar_t ***_imp___wenviron;
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
خارجی صحیح __argc;
خارجی حرف **__argv;
خارجی wchar_t **__wargv;
خارجی حرف **_environ;
خارجی wchar_t **_wenviron;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _pgmptr
#اگر_تعریف_شدہ _MSVCRT_
  خارجی حرف *_pgmptr;
#ورنہ
#تعریف_کرو _pgmptr (*_imp___pgmptr)
  خارجی حرف **_imp___pgmptr;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _wpgmptr
#اگر_تعریف_شدہ _MSVCRT_
  خارجی wchar_t *_wpgmptr;
#ورنہ
#تعریف_کرو _wpgmptr        (*_imp___wpgmptr)
  خارجی wchar_t **_imp___wpgmptr;
#اگر_ختم
#اگر_ختم
  errno_t __cdecl _get_pgmptr(حرف **قدر_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **قدر_2);
#اگر_غیر_تعریف_شدہ _fmode
#اگر_تعریف_شدہ _MSVCRT_
  خارجی صحیح _fmode;
#ورنہ
#تعریف_کرو _fmode  (*_imp___fmode)
  خارجی صحیح *_imp___fmode;
#اگر_ختم
#اگر_ختم
  _CRTIMP errno_t __cdecl سیٹ_fmode(صحیح منوال_3);
  _CRTIMP errno_t __cdecl _get_fmode(صحیح *_PMode);

#اگر_غیر_تعریف_شدہ _osplatform
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی صحیح _osplatform;
#ورنہ
#تعریف_کرو _osplatform (*_imp___osplatform)
  خارجی غیرعلامتی صحیح *_imp___osplatform;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _osver
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی صحیح _osver;
#ورنہ
#تعریف_کرو _osver  (*_imp___osver)
  خارجی غیرعلامتی صحیح *_imp___osver;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _winver
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی صحیح _winver;
#ورنہ
#تعریف_کرو _winver (*_imp___winver)
  خارجی غیرعلامتی صحیح *_imp___winver;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _winmajor
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی صحیح _winmajor;
#ورنہ
#تعریف_کرو _winmajor       (*_imp___winmajor)
  خارجی غیرعلامتی صحیح *_imp___winmajor;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _winminor
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی صحیح _winminor;
#ورنہ
#تعریف_کرو _winminor       (*_imp___winminor)
  خارجی غیرعلامتی صحیح *_imp___winminor;
#اگر_ختم
#اگر_ختم

  errno_t __cdecl _get_osplatform(غیرعلامتی صحیح *قدر_2);
  errno_t __cdecl _get_osver(غیرعلامتی صحیح *قدر_2);
  errno_t __cdecl _get_winver(غیرعلامتی صحیح *قدر_2);
  errno_t __cdecl _get_winmajor(غیرعلامتی صحیح *قدر_2);
  errno_t __cdecl _get_winminor(غیرعلامتی صحیح *قدر_2);
#اگر_غیر_تعریف_شدہ _countof
#اگر_غیر_تعریف_شدہ __cplusplus
#تعریف_کرو _countof(_Array) (حجم(_Array) / حجم(_Array[0]))
#ورنہ
  خارجی "C++" {
    سانچہ <typename _CountofType,سائز_t سائز_کا_Array> حرف (*__countof_helper(UNALIGNED _CountofType (&_Array)[سائز_کا_Array]))[سائز_کا_Array];
#تعریف_کرو _countof(_Array) حجم(*__countof_helper(_Array))
  }
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_TERMINATE_DEFINED
#تعریف_کرو _CRT_TERMINATE_DEFINED
  خالی __cdecl __MINGW_NOTHROW باہر_نکلو(صحیح رمز_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP خالی __cdecl __MINGW_NOTHROW _exit(صحیح رمز_3) __MINGW_ATTRIB_NORETURN;
#اگر !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  خالی __cdecl _Exit(صحیح) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN خالی  __cdecl _Exit(صحیح حالت_2)
  {  _exit(حالت_2); }
#اگر_ختم

#ہدایت ڈالو_macro("abort")
#تعریف_منسوخ abort
  خالی __cdecl __declspec(noreturn) abort(خالی);
#ہدایت نکالو_macro("abort")

#اگر_ختم

  _CRTIMP غیرعلامتی صحیح __cdecl سیٹ_abort_behavior(غیرعلامتی صحیح _Flags,غیرعلامتی صحیح نقاب_2);

#اگر_غیر_تعریف_شدہ _CRT_ABS_DEFINED
#تعریف_کرو _CRT_ABS_DEFINED
  صحیح __cdecl مطلق_قدر(صحیح _X);
  طویل __cdecl labs(طویل _X);
#اگر_ختم

#اگر INTEGRAL_MAX_بٹ >= 64
  __int64 __cdecl _abs64(__int64);
#اگر_ختم
  صحیح __cdecl atexit(خالی (__cdecl *)(خالی));
#اگر_غیر_تعریف_شدہ _CRT_ATOF_DEFINED
#تعریف_کرو _CRT_ATOF_DEFINED
  دوہرا __cdecl atof(ثابت حرف *_String);
  دوہرا __cdecl _atof_l(ثابت حرف *_String,_locale_t _Locale);
#اگر_ختم
  صحیح __cdecl atoi(ثابت حرف *_Str);
  _CRTIMP صحیح __cdecl _atoi_l(ثابت حرف *_Str,_locale_t _Locale);
  طویل __cdecl atol(ثابت حرف *_Str);
  _CRTIMP طویل __cdecl _atol_l(ثابت حرف *_Str,_locale_t _Locale);
#اگر_غیر_تعریف_شدہ _CRT_ALGO_DEFINED
#تعریف_کرو _CRT_ALGO_DEFINED
  خالی *__cdecl bsearch(ثابت خالی *کلید_2,ثابت خالی *بنیاد_3,سائز_t عدد_کا_Elements,سائز_t سائز_کا_Elements,صحیح (__cdecl *_PtFuncCompare)(ثابت خالی *,ثابت خالی *));
  خالی __cdecl qsort(خالی *بنیاد_3,سائز_t عدد_کا_Elements,سائز_t سائز_کا_Elements,صحیح (__cdecl *_PtFuncCompare)(ثابت خالی *,ثابت خالی *));
#اگر_ختم
  غیرعلامتی مختصر __cdecl _byteswap_ushort(غیرعلامتی مختصر _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#اگر INTEGRAL_MAX_بٹ >= 64
  غیرعلامتی __int64 __cdecl _byteswap_uint64(غیرعلامتی __int64 _Int64);
#اگر_ختم
  div_t __cdecl div(صحیح _Numerator,صحیح _Denominator);
  حرف *__cdecl getenv(ثابت حرف *_VarName);
  _CRTIMP حرف *__cdecl _itoa(صحیح قدر_2,حرف *_Dest,صحیح _Radix);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP حرف *__cdecl _i64toa(__int64 _Val,حرف *_DstBuf,صحیح _Radix);
  _CRTIMP حرف *__cdecl _ui64toa(غیرعلامتی __int64 _Val,حرف *_DstBuf,صحیح _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ثابت حرف *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ثابت حرف *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ثابت حرف *_String,حرف **انتہا_Ptr,صحیح _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ثابت حرف *_String,حرف **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP غیرعلامتی __int64 __cdecl _strtoui64(ثابت حرف *_String,حرف **انتہا_Ptr,صحیح _Radix);
  _CRTIMP غیرعلامتی __int64 __cdecl _strtoui64_l(ثابت حرف *_String,حرف **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
#اگر_ختم
  ldiv_t __cdecl ldiv(طویل _Numerator,طویل _Denominator);
  _CRTIMP حرف *__cdecl _ltoa(طویل قدر_2,حرف *_Dest,صحیح _Radix);
  صحیح __cdecl mblen(ثابت حرف *_Ch,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _mblen_l(ثابت حرف *_Ch,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP سائز_t __cdecl _mbstrlen(ثابت حرف *_Str);
  _CRTIMP سائز_t __cdecl _mbstrlen_l(ثابت حرف *_Str,_locale_t _Locale);
  _CRTIMP سائز_t __cdecl _mbstrnlen(ثابت حرف *_Str,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _mbstrnlen_l(ثابت حرف *_Str,سائز_t Max_گنتی,_locale_t _Locale);
  صحیح __cdecl mbtowc(wchar_t *_DstCh,ثابت حرف *_SrcCh,سائز_t Src_سائز_اندر_بائٹیں);
  _CRTIMP صحیح __cdecl _mbtowc_l(wchar_t *_DstCh,ثابت حرف *_SrcCh,سائز_t Src_سائز_اندر_بائٹیں,_locale_t _Locale);
  سائز_t __cdecl mbstowcs(wchar_t *_Dest,ثابت حرف *ماخذ_3,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _mbstowcs_l(wchar_t *_Dest,ثابت حرف *ماخذ_3,سائز_t Max_گنتی,_locale_t _Locale);
  صحیح __cdecl rand(خالی);
  _CRTIMP صحیح __cdecl سیٹ_error_منوال(صحیح منوال_3);
  خالی __cdecl srand(غیرعلامتی صحیح بیج);
  دوہرا __cdecl strtod(ثابت حرف *_Str,حرف **انتہا_Ptr);
#اگر !defined __NO_ISOCEXT  /* in libmingwex.a */
#اگر __TINYC__
  __CRT_INLINE اعشاری __cdecl strtof (ثابت حرف *p, حرف ** e) { واپس strtod(p, e); }
  __CRT_INLINE طویل دوہرا __cdecl strtold(ثابت حرف *p, حرف ** e) { واپس strtod(p, e); }
#ورنہ
  اعشاری __cdecl strtof (ثابت حرف * __restrict__, حرف ** __restrict__);
  طویل دوہرا __cdecl strtold(ثابت حرف * __restrict__, حرف ** __restrict__);
#اگر_ختم
#ورنہ
  اعشاری __cdecl strtof(ثابت حرف *nptr, حرف **endptr);
#اگر_ختم /* __NO_ISOCEXT */
  _CRTIMP دوہرا __cdecl _strtod_l(ثابت حرف *_Str,حرف **انتہا_Ptr,_locale_t _Locale);
  طویل __cdecl strtol(ثابت حرف *_Str,حرف **انتہا_Ptr,صحیح _Radix);
  _CRTIMP طویل __cdecl _strtol_l(ثابت حرف *_Str,حرف **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  غیرعلامتی طویل __cdecl strtoul(ثابت حرف *_Str,حرف **انتہا_Ptr,صحیح _Radix);
  _CRTIMP غیرعلامتی طویل __cdecl _strtoul_l(ثابت حرف *_Str,حرف **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
#اگر_غیر_تعریف_شدہ _CRT_SYSTEM_DEFINED
#تعریف_کرو _CRT_SYSTEM_DEFINED
  صحیح __cdecl system(ثابت حرف *_Command);
#اگر_ختم
  _CRTIMP حرف *__cdecl _ultoa(غیرعلامتی طویل قدر_2,حرف *_Dest,صحیح _Radix);
  صحیح __cdecl wctomb(حرف *_MbCh,wchar_t _WCh);
  _CRTIMP صحیح __cdecl _wctomb_l(حرف *_MbCh,wchar_t _WCh,_locale_t _Locale);
  سائز_t __cdecl wcstombs(حرف *_Dest,ثابت wchar_t *ماخذ_3,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _wcstombs_l(حرف *_Dest,ثابت wchar_t *ماخذ_3,سائز_t Max_گنتی,_locale_t _Locale);

#اگر_غیر_تعریف_شدہ CRT_تخصیص_DEFINED
#تعریف_کرو CRT_تخصیص_DEFINED
  خالی *__cdecl صفر_حافظہ_دو(سائز_t عدد_کا_Elements,سائز_t سائز_کا_Elements);
  خالی __cdecl آزاد(خالی *حافظہ);
  خالی *__cdecl حافظہ_دو(سائز_t سائز_4);
  خالی *__cdecl realloc(خالی *حافظہ,سائز_t New_سائز);
  _CRTIMP خالی *__cdecl _recalloc(خالی *حافظہ,سائز_t گنتی_5,سائز_t سائز_4);
  _CRTIMP خالی __cdecl _aligned_free(خالی *حافظہ);
  _CRTIMP خالی *__cdecl _aligned_malloc(سائز_t سائز_4,سائز_t _Alignment);
  _CRTIMP خالی *__cdecl aligned_انحراف_malloc(سائز_t سائز_4,سائز_t _Alignment,سائز_t انحراف_2);
  _CRTIMP خالی *__cdecl _aligned_realloc(خالی *حافظہ,سائز_t سائز_4,سائز_t _Alignment);
  _CRTIMP خالی *__cdecl _aligned_recalloc(خالی *حافظہ,سائز_t گنتی_5,سائز_t سائز_4,سائز_t _Alignment);
  _CRTIMP خالی *__cdecl aligned_انحراف_realloc(خالی *حافظہ,سائز_t سائز_4,سائز_t _Alignment,سائز_t انحراف_2);
  _CRTIMP خالی *__cdecl aligned_انحراف_recalloc(خالی *حافظہ,سائز_t گنتی_5,سائز_t سائز_4,سائز_t _Alignment,سائز_t انحراف_2);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTDLIB_DEFINED
#تعریف_کرو _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(صحیح قدر_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(طویل قدر_2,wchar_t *_Dest,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(غیرعلامتی طویل قدر_2,wchar_t *_Dest,صحیح _Radix);
  دوہرا __cdecl wcstod(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr);
  اعشاری __cdecl wcstof(ثابت wchar_t *nptr, wchar_t **endptr);
#اگر !defined __NO_ISOCEXT /* in libmingwex.a */
  اعشاری __cdecl wcstof( ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
  طویل دوہرا __cdecl wcstold(ثابت wchar_t * __restrict__, wchar_t ** __restrict__);
#اگر_ختم /* __NO_ISOCEXT */
  _CRTIMP دوہرا __cdecl _wcstod_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,_locale_t _Locale);
  طویل __cdecl wcstol(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP طویل __cdecl _wcstol_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  غیرعلامتی طویل __cdecl wcstoul(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP غیرعلامتی طویل __cdecl _wcstoul_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ثابت wchar_t *_VarName);
#اگر_غیر_تعریف_شدہ _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#اگر_ختم
  _CRTIMP دوہرا __cdecl _wtof(ثابت wchar_t *_Str);
  _CRTIMP دوہرا __cdecl _wtof_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wtoi(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wtoi_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP طویل __cdecl _wtol(ثابت wchar_t *_Str);
  _CRTIMP طویل __cdecl _wtol_l(ثابت wchar_t *_Str,_locale_t _Locale);

#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(غیرعلامتی __int64 _Val,wchar_t *_DstBuf,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ثابت wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ثابت wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
  _CRTIMP غیرعلامتی __int64 __cdecl _wcstoui64(ثابت wchar_t *_Str,wchar_t **انتہا_Ptr,صحیح _Radix);
  _CRTIMP غیرعلامتی __int64 __cdecl _wcstoui64_l(ثابت wchar_t *_Str ,wchar_t **انتہا_Ptr,صحیح _Radix,_locale_t _Locale);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _POSIX_
#تعریف_کرو _CVTBUFSIZE (309+40)
  _CRTIMP حرف *__cdecl _fullpath(حرف *بھرا_راستہ,ثابت حرف *راستہ_2,سائز_t سائز_اندر_بائٹیں);
  _CRTIMP حرف *__cdecl _ecvt(دوہرا _Val,صحیح عدد_کا_Digits,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP حرف *__cdecl _fcvt(دوہرا _Val,صحیح عدد_کا_Dec,صحیح *_PtDec,صحیح *_PtSign);
  _CRTIMP حرف *__cdecl _gcvt(دوہرا _Val,صحیح عدد_کا_Digits,حرف *_DstBuf);
  _CRTIMP صحیح __cdecl _atodbl(_CRT_DOUBLE *نتیجہ_2,حرف *_Str);
  _CRTIMP صحیح __cdecl _atoldbl(_LDOUBLE *نتیجہ_2,حرف *_Str);
  _CRTIMP صحیح __cdecl _atoflt(_CRT_FLOAT *نتیجہ_2,حرف *_Str);
  _CRTIMP صحیح __cdecl _atodbl_l(_CRT_DOUBLE *نتیجہ_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _atoldbl_l(_LDOUBLE *نتیجہ_2,حرف *_Str,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _atoflt_l(_CRT_FLOAT *نتیجہ_2,حرف *_Str,_locale_t _Locale);
  غیرعلامتی طویل __cdecl _lrotl(غیرعلامتی طویل _Val,صحیح سرکاؤ_2);
  غیرعلامتی طویل __cdecl _lrotr(غیرعلامتی طویل _Val,صحیح سرکاؤ_2);
  _CRTIMP خالی __cdecl _makepath(حرف *راستہ_2,ثابت حرف *_Drive,ثابت حرف *_Dir,ثابت حرف *_Filename,ثابت حرف *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#اگر_غیر_تعریف_شدہ _CRT_PERROR_DEFINED
#تعریف_کرو _CRT_PERROR_DEFINED
  خالی __cdecl perror(ثابت حرف *Err_پیغام);
#اگر_ختم
  _CRTIMP صحیح __cdecl _putenv(ثابت حرف *_EnvString);
  غیرعلامتی صحیح __cdecl _rotl(غیرعلامتی صحیح _Val,صحیح سرکاؤ_2);
#اگر INTEGRAL_MAX_بٹ >= 64
  غیرعلامتی __int64 __cdecl _rotl64(غیرعلامتی __int64 _Val,صحیح سرکاؤ_2);
#اگر_ختم
  غیرعلامتی صحیح __cdecl _rotr(غیرعلامتی صحیح _Val,صحیح سرکاؤ_2);
#اگر INTEGRAL_MAX_بٹ >= 64
  غیرعلامتی __int64 __cdecl _rotr64(غیرعلامتی __int64 _Val,صحیح سرکاؤ_2);
#اگر_ختم
  _CRTIMP خالی __cdecl _searchenv(ثابت حرف *_Filename,ثابت حرف *_EnvVar,حرف *نتیجہ_راستہ);
  _CRTIMP خالی __cdecl _splitpath(ثابت حرف *بھرا_راستہ,حرف *_Drive,حرف *_Dir,حرف *_Filename,حرف *_Ext);
  _CRTIMP خالی __cdecl _swab(حرف *_Buf1,حرف *_Buf2,صحیح سائز_اندر_بائٹیں);

#اگر_غیر_تعریف_شدہ _WSTDLIBP_DEFINED
#تعریف_کرو _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *بھرا_راستہ,ثابت wchar_t *راستہ_2,سائز_t سائز_اندر_الفاظ);
  _CRTIMP خالی __cdecl _wmakepath(wchar_t *نتیجہ_راستہ,ثابت wchar_t *_Drive,ثابت wchar_t *_Dir,ثابت wchar_t *_Filename,ثابت wchar_t *_Ext);
#اگر_غیر_تعریف_شدہ _CRT_WPERROR_DEFINED
#تعریف_کرو _CRT_WPERROR_DEFINED
  _CRTIMP خالی __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#اگر_ختم
  _CRTIMP صحیح __cdecl _wputenv(ثابت wchar_t *_EnvString);
  _CRTIMP خالی __cdecl _wsearchenv(ثابت wchar_t *_Filename,ثابت wchar_t *_EnvVar,wchar_t *نتیجہ_راستہ);
  _CRTIMP خالی __cdecl _wsplitpath(ثابت wchar_t *بھرا_راستہ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#اگر_ختم

  _CRTIMP خالی __cdecl _beep(غیرعلامتی _Frequency,غیرعلامتی _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP خالی __cdecl _seterrormode(صحیح منوال_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP خالی __cdecl _sleep(غیرعلامتی طویل _Duration) __MINGW_ATTRIB_DEPRECATED;
#اگر_ختم

#اگر_غیر_تعریف_شدہ NO_OLDNAMES
#اگر_غیر_تعریف_شدہ _POSIX_
#اگر 0
#اگر_غیر_تعریف_شدہ __cplusplus
#اگر_غیر_تعریف_شدہ NOMINMAX
#اگر_غیر_تعریف_شدہ max
#تعریف_کرو max(a,b) (((a) > (b)) ? (a) : (b))
#اگر_ختم
#اگر_غیر_تعریف_شدہ min
#تعریف_کرو min(a,b) (((a) < (b)) ? (a) : (b))
#اگر_ختم
#اگر_ختم
#اگر_ختم
#اگر_ختم

#تعریف_کرو sys_errlist _sys_errlist
#تعریف_کرو sys_nerr _sys_nerr
#تعریف_کرو environ _environ
  حرف *__cdecl ecvt(دوہرا _Val,صحیح عدد_کا_Digits,صحیح *_PtDec,صحیح *_PtSign);
  حرف *__cdecl fcvt(دوہرا _Val,صحیح عدد_کا_Dec,صحیح *_PtDec,صحیح *_PtSign);
  حرف *__cdecl gcvt(دوہرا _Val,صحیح عدد_کا_Digits,حرف *_DstBuf);
  حرف *__cdecl itoa(صحیح _Val,حرف *_DstBuf,صحیح _Radix);
  حرف *__cdecl ltoa(طویل _Val,حرف *_DstBuf,صحیح _Radix);
  صحیح __cdecl putenv(ثابت حرف *_EnvString);
  خالی __cdecl swab(حرف *_Buf1,حرف *_Buf2,صحیح سائز_اندر_بائٹیں);
  حرف *__cdecl ultoa(غیرعلامتی طویل _Val,حرف *_Dstbuf,صحیح _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#اگر_ختم
#اگر_ختم

#اگر !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  قسمتعریف ساخت { طویل طویل quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(طویل طویل, طویل طویل);

  __CRT_INLINE طویل طویل __cdecl llabs(طویل طویل _j) { واپس (_j >= 0 ? _j : -_j); }

 #اگر_تعریف_شدہ __TINYC__ /* gr */
  #تعریف_کرو strtoll _strtoi64
  #تعریف_کرو strtoull _strtoui64
 #ورنہ
  طویل طویل  __cdecl strtoll(ثابت حرف* __restrict__, حرف** __restrict, صحیح);
  غیرعلامتی طویل طویل  __cdecl strtoull(ثابت حرف* __restrict__, حرف** __restrict__, صحیح);
 #اگر_ختم

  /* these are stubs for MS _i64 versions */
  طویل طویل  __cdecl atoll (ثابت حرف *);

#اگر_غیر_تعریف_شدہ __STRICT_ANSI__
  طویل طویل  __cdecl wtoll (ثابت wchar_t *);
  حرف *__cdecl lltoa (طویل طویل, حرف *, صحیح);
  حرف *__cdecl ulltoa (غیرعلامتی طویل طویل , حرف *, صحیح);
  wchar_t *__cdecl lltow (طویل طویل, wchar_t *, صحیح);
  wchar_t *__cdecl ulltow (غیرعلامتی طویل طویل, wchar_t *, صحیح);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE طویل طویل  __cdecl atoll (ثابت حرف * _c) { واپس _atoi64 (_c); }
  __CRT_INLINE حرف *__cdecl lltoa (طویل طویل _n, حرف * _c, صحیح _i) { واپس _i64toa (_n, _c, _i); }
  __CRT_INLINE حرف *__cdecl ulltoa (غیرعلامتی طویل طویل _n, حرف * _c, صحیح _i) { واپس _ui64toa (_n, _c, _i); }
  __CRT_INLINE طویل طویل  __cdecl wtoll (ثابت wchar_t * _w) { واپس _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (طویل طویل _n, wchar_t * _w, صحیح _i) { واپس _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (غیرعلامتی طویل طویل _n, wchar_t * _w, صحیح _i) { واپس _ui64tow (_n, _w, _i); }
#اگر_ختم /* (__STRICT_ANSI__)  */

#اگر_ختم /* !__NO_ISOCEXT */

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)

#شامل <sec_api/stdlib_s.h>
#شامل <malloc.h>

#اگر_ختم
