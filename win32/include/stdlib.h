/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#அந்தர்பாவ <_mingw.h>
#அந்தர்பாவ <limits.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef வெற்று
#ifdef __cplusplus
#define வெற்று 0
#இல்லையெனில்
#define வெற்று ((வெறுமை *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  வகைவரை முழு (__cdecl *_onexit_t)(வெறுமை);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  வகைவரை கட்டமைப்பு _div_t {
    முழு quot;
    முழு rem;
  } div_t;

  வகைவரை கட்டமைப்பு _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  வகைவரை கட்டமைப்பு {
    unsigned எழுத்து ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned எழுத்து *)(&(x)->ld))

  வகைவரை கட்டமைப்பு {
    இரட்டை x;
  } _CRT_DOUBLE;

  வகைவரை கட்டமைப்பு {
    தசம f;
  } _CRT_FLOAT;

#pragma தள்ளு_macro("long")
#undef long

  வகைவரை கட்டமைப்பு {
    long இரட்டை x;
  } _LONGDOUBLE;

#pragma எடு_macro("long")

#pragma pack(4)
  வகைவரை கட்டமைப்பு {
    unsigned எழுத்து ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  வெளி முழு __mb_cur_max;
#இல்லையெனில்
#define __mb_cur_max    (*_imp____mb_cur_max)
  வெளி முழு *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  வெளி முழு __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#இல்லையெனில்
  வெளி முழு* _imp____mbcur_max;
#define ___mb_cur_max_func() (*_imp____mb_cur_max)
#endif
#endif

#define __max(a,b) (((a) > (b)) ? (a) : (b))
#define __min(a,b) (((a) < (b)) ? (a) : (b))

#define _MAX_PATH 260
#define _MAX_DRIVE 3
#define _MAX_DIR 256
#define _MAX_FNAME 256
#define _MAX_EXT 256

#define _OUT_TO_DEFAULT 0
#define _OUT_TO_STDERR 1
#define _OUT_TO_MSGBOX 2
#define _REPORT_ERRMODE 3

#define WRITE_ABORT_செய்தி 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  வகைவரை வெறுமை (__cdecl *_purecall_handler)(வெறுமை);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(வெறுமை);

  வகைவரை வெறுமை (__cdecl *_invalid_parameter_handler)(மாறிலி wchar_t *,மாறிலி wchar_t *,மாறிலி wchar_t *,unsigned முழு,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(வெறுமை);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP முழு *__cdecl _errno(வெறுமை);
#define errno (*_errno())
  errno_t __cdecl _set_errno(முழு மதிப்பு_2);
  errno_t __cdecl _get_errno(முழு *மதிப்பு_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(வெறுமை);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long மதிப்பு_2);
  errno_t __cdecl _get_doserrno(unsigned long *மதிப்பு_2);
#ifdef _MSVCRT_
  வெளி எழுத்து *_sys_errlist[];
  வெளி முழு _sys_nerr;
#இல்லையெனில்
  _CRTIMP எழுத்து *_sys_errlist[1];
  _CRTIMP முழு _sys_nerr;
#endif
#எனில் (defined(_X86_) && !defined(__x86_64))
  _CRTIMP முழு *__cdecl __p___argc(வெறுமை);
  _CRTIMP எழுத்து ***__cdecl __p___argv(வெறுமை);
  _CRTIMP wchar_t ***__cdecl __p___wargv(வெறுமை);
  _CRTIMP எழுத்து ***__cdecl __p__environ(வெறுமை);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(வெறுமை);
  _CRTIMP எழுத்து **__cdecl __p__pgmptr(வெறுமை);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(வெறுமை);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  வெளி முழு __argc;
#இல்லையெனில்
#define __argc (*_imp____argc)
  வெளி முழு *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  வெளி எழுத்து **__argv;
#இல்லையெனில்
#define __argv  (*_imp____argv)
  வெளி எழுத்து ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  வெளி wchar_t **__wargv;
#இல்லையெனில்
#define __wargv (*_imp____wargv)
  வெளி wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  வெளி எழுத்து **environ;
#இல்லையெனில்
#ifndef _environ
#ifdef _MSVCRT_
  வெளி எழுத்து **_environ;
#இல்லையெனில்
#define _environ (*_imp___environ)
  வெளி எழுத்து ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  வெளி wchar_t **_wenviron;
#இல்லையெனில்
#define _wenviron       (*_imp___wenviron)
  வெளி wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#எனில் defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
வெளி முழு __argc;
வெளி எழுத்து **__argv;
வெளி wchar_t **__wargv;
வெளி எழுத்து **_environ;
வெளி wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  வெளி எழுத்து *_pgmptr;
#இல்லையெனில்
#define _pgmptr (*_imp___pgmptr)
  வெளி எழுத்து **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  வெளி wchar_t *_wpgmptr;
#இல்லையெனில்
#define _wpgmptr        (*_imp___wpgmptr)
  வெளி wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(எழுத்து **மதிப்பு_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **மதிப்பு_2);
#ifndef _fmode
#ifdef _MSVCRT_
  வெளி முழு _fmode;
#இல்லையெனில்
#define _fmode  (*_imp___fmode)
  வெளி முழு *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(முழு _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(முழு *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  வெளி unsigned முழு _osplatform;
#இல்லையெனில்
#define _osplatform (*_imp___osplatform)
  வெளி unsigned முழு *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  வெளி unsigned முழு _osver;
#இல்லையெனில்
#define _osver  (*_imp___osver)
  வெளி unsigned முழு *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  வெளி unsigned முழு _winver;
#இல்லையெனில்
#define _winver (*_imp___winver)
  வெளி unsigned முழு *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  வெளி unsigned முழு _winmajor;
#இல்லையெனில்
#define _winmajor       (*_imp___winmajor)
  வெளி unsigned முழு *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  வெளி unsigned முழு _winminor;
#இல்லையெனில்
#define _winminor       (*_imp___winminor)
  வெளி unsigned முழு *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned முழு *மதிப்பு_2);
  errno_t __cdecl _get_osver(unsigned முழு *மதிப்பு_2);
  errno_t __cdecl _get_winver(unsigned முழு *மதிப்பு_2);
  errno_t __cdecl _get_winmajor(unsigned முழு *மதிப்பு_2);
  errno_t __cdecl _get_winminor(unsigned முழு *மதிப்பு_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (அளவு(_Array) / அளவு(_Array[0]))
#இல்லையெனில்
  வெளி "C++" {
    template <typename _CountofType,size_t _SizeOfArray> எழுத்து (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) அளவு(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  வெறுமை __cdecl __MINGW_NOTHROW exit(முழு _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP வெறுமை __cdecl __MINGW_NOTHROW _exit(முழு _Code) __MINGW_ATTRIB_NORETURN;
#எனில் !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  வெறுமை __cdecl _Exit(முழு) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN வெறுமை  __cdecl _Exit(முழு status)
  {  _exit(status); }
#endif

#pragma தள்ளு_macro("abort")
#undef abort
  வெறுமை __cdecl __declspec(noreturn) abort(வெறுமை);
#pragma எடு_macro("abort")

#endif

  _CRTIMP unsigned முழு __cdecl _set_abort_behavior(unsigned முழு _Flags,unsigned முழு _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  முழு __cdecl abs(முழு _X);
  long __cdecl labs(long _X);
#endif

#எனில் _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  முழு __cdecl atexit(வெறுமை (__cdecl *)(வெறுமை));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  இரட்டை __cdecl atof(மாறிலி எழுத்து *_String);
  இரட்டை __cdecl _atof_l(மாறிலி எழுத்து *_String,_locale_t _Locale);
#endif
  முழு __cdecl atoi(மாறிலி எழுத்து *_Str);
  _CRTIMP முழு __cdecl _atoi_l(மாறிலி எழுத்து *_Str,_locale_t _Locale);
  long __cdecl atol(மாறிலி எழுத்து *_Str);
  _CRTIMP long __cdecl _atol_l(மாறிலி எழுத்து *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  வெறுமை *__cdecl bsearch(மாறிலி வெறுமை *சாவி_2,மாறிலி வெறுமை *_Base,size_t இலக்கம்_Of_Elements,size_t _SizeOfElements,முழு (__cdecl *_PtFuncCompare)(மாறிலி வெறுமை *,மாறிலி வெறுமை *));
  வெறுமை __cdecl qsort(வெறுமை *_Base,size_t இலக்கம்_Of_Elements,size_t _SizeOfElements,முழு (__cdecl *_PtFuncCompare)(மாறிலி வெறுமை *,மாறிலி வெறுமை *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#எனில் _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(முழு _Numerator,முழு _Denominator);
  எழுத்து *__cdecl getenv(மாறிலி எழுத்து *_VarName);
  _CRTIMP எழுத்து *__cdecl _itoa(முழு மதிப்பு_2,எழுத்து *_Dest,முழு _Radix);
#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP எழுத்து *__cdecl _i64toa(__int64 _Val,எழுத்து *_DstBuf,முழு _Radix);
  _CRTIMP எழுத்து *__cdecl _ui64toa(unsigned __int64 _Val,எழுத்து *_DstBuf,முழு _Radix);
  _CRTIMP __int64 __cdecl _atoi64(மாறிலி எழுத்து *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(மாறிலி எழுத்து *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(மாறிலி எழுத்து *_String,எழுத்து **_EndPtr,முழு _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(மாறிலி எழுத்து *_String,எழுத்து **_EndPtr,முழு _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(மாறிலி எழுத்து *_String,எழுத்து **_EndPtr,முழு _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(மாறிலி எழுத்து *_String,எழுத்து **_EndPtr,முழு _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP எழுத்து *__cdecl _ltoa(long மதிப்பு_2,எழுத்து *_Dest,முழு _Radix);
  முழு __cdecl mblen(மாறிலி எழுத்து *_Ch,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _mblen_l(மாறிலி எழுத்து *_Ch,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(மாறிலி எழுத்து *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(மாறிலி எழுத்து *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(மாறிலி எழுத்து *_Str,size_t Max_மொத்தம்);
  _CRTIMP size_t __cdecl _mbstrnlen_l(மாறிலி எழுத்து *_Str,size_t Max_மொத்தம்,_locale_t _Locale);
  முழு __cdecl mbtowc(wchar_t *_DstCh,மாறிலி எழுத்து *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP முழு __cdecl _mbtowc_l(wchar_t *_DstCh,மாறிலி எழுத்து *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,மாறிலி எழுத்து *_Source,size_t Max_மொத்தம்);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,மாறிலி எழுத்து *_Source,size_t Max_மொத்தம்,_locale_t _Locale);
  முழு __cdecl rand(வெறுமை);
  _CRTIMP முழு __cdecl _set_error_mode(முழு _Mode);
  வெறுமை __cdecl srand(unsigned முழு _Seed);
  இரட்டை __cdecl strtod(மாறிலி எழுத்து *_Str,எழுத்து **_EndPtr);
#எனில் !defined __NO_ISOCEXT  /* in libmingwex.a */
#எனில் __TINYC__
  __CRT_INLINE தசம __cdecl strtof (மாறிலி எழுத்து *p, எழுத்து ** e) { திரும்பு strtod(p, e); }
  __CRT_INLINE long இரட்டை __cdecl strtold(மாறிலி எழுத்து *p, எழுத்து ** e) { திரும்பு strtod(p, e); }
#இல்லையெனில்
  தசம __cdecl strtof (மாறிலி எழுத்து * __restrict__, எழுத்து ** __restrict__);
  long இரட்டை __cdecl strtold(மாறிலி எழுத்து * __restrict__, எழுத்து ** __restrict__);
#endif
#இல்லையெனில்
  தசம __cdecl strtof(மாறிலி எழுத்து *nptr, எழுத்து **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP இரட்டை __cdecl _strtod_l(மாறிலி எழுத்து *_Str,எழுத்து **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(மாறிலி எழுத்து *_Str,எழுத்து **_EndPtr,முழு _Radix);
  _CRTIMP long __cdecl _strtol_l(மாறிலி எழுத்து *_Str,எழுத்து **_EndPtr,முழு _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(மாறிலி எழுத்து *_Str,எழுத்து **_EndPtr,முழு _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(மாறிலி எழுத்து *_Str,எழுத்து **_EndPtr,முழு _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  முழு __cdecl system(மாறிலி எழுத்து *_Command);
#endif
  _CRTIMP எழுத்து *__cdecl _ultoa(unsigned long மதிப்பு_2,எழுத்து *_Dest,முழு _Radix);
  முழு __cdecl wctomb(எழுத்து *_MbCh,wchar_t _WCh);
  _CRTIMP முழு __cdecl _wctomb_l(எழுத்து *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(எழுத்து *_Dest,மாறிலி wchar_t *_Source,size_t Max_மொத்தம்);
  _CRTIMP size_t __cdecl _wcstombs_l(எழுத்து *_Dest,மாறிலி wchar_t *_Source,size_t Max_மொத்தம்,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  வெறுமை *__cdecl calloc(size_t இலக்கம்_Of_Elements,size_t _SizeOfElements);
  வெறுமை __cdecl விடுவி(வெறுமை *_Memory);
  வெறுமை *__cdecl malloc(size_t _Size);
  வெறுமை *__cdecl realloc(வெறுமை *_Memory,size_t _NewSize);
  _CRTIMP வெறுமை *__cdecl _recalloc(வெறுமை *_Memory,size_t மொத்தம்_5,size_t _Size);
  _CRTIMP வெறுமை __cdecl _aligned_free(வெறுமை *_Memory);
  _CRTIMP வெறுமை *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP வெறுமை *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP வெறுமை *__cdecl _aligned_realloc(வெறுமை *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP வெறுமை *__cdecl _aligned_recalloc(வெறுமை *_Memory,size_t மொத்தம்_5,size_t _Size,size_t _Alignment);
  _CRTIMP வெறுமை *__cdecl _aligned_offset_realloc(வெறுமை *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP வெறுமை *__cdecl _aligned_offset_recalloc(வெறுமை *_Memory,size_t மொத்தம்_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(முழு மதிப்பு_2,wchar_t *_Dest,முழு _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long மதிப்பு_2,wchar_t *_Dest,முழு _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long மதிப்பு_2,wchar_t *_Dest,முழு _Radix);
  இரட்டை __cdecl wcstod(மாறிலி wchar_t *_Str,wchar_t **_EndPtr);
  தசம __cdecl wcstof(மாறிலி wchar_t *nptr, wchar_t **endptr);
#எனில் !defined __NO_ISOCEXT /* in libmingwex.a */
  தசம __cdecl wcstof( மாறிலி wchar_t * __restrict__, wchar_t ** __restrict__);
  long இரட்டை __cdecl wcstold(மாறிலி wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP இரட்டை __cdecl _wcstod_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP long __cdecl _wcstol_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(மாறிலி wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP முழு __cdecl _wsystem(மாறிலி wchar_t *_Command);
#endif
  _CRTIMP இரட்டை __cdecl _wtof(மாறிலி wchar_t *_Str);
  _CRTIMP இரட்டை __cdecl _wtof_l(மாறிலி wchar_t *_Str,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wtoi(மாறிலி wchar_t *_Str);
  _CRTIMP முழு __cdecl _wtoi_l(மாறிலி wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(மாறிலி wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(மாறிலி wchar_t *_Str,_locale_t _Locale);

#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,முழு _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,முழு _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(மாறிலி wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(மாறிலி wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(மாறிலி wchar_t *_Str,wchar_t **_EndPtr,முழு _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(மாறிலி wchar_t *_Str ,wchar_t **_EndPtr,முழு _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP எழுத்து *__cdecl _fullpath(எழுத்து *_FullPath,மாறிலி எழுத்து *_Path,size_t _SizeInBytes);
  _CRTIMP எழுத்து *__cdecl _ecvt(இரட்டை _Val,முழு இலக்கம்_Of_Digits,முழு *_PtDec,முழு *_PtSign);
  _CRTIMP எழுத்து *__cdecl _fcvt(இரட்டை _Val,முழு இலக்கம்_Of_Dec,முழு *_PtDec,முழு *_PtSign);
  _CRTIMP எழுத்து *__cdecl _gcvt(இரட்டை _Val,முழு இலக்கம்_Of_Digits,எழுத்து *_DstBuf);
  _CRTIMP முழு __cdecl _atodbl(_CRT_DOUBLE *_Result,எழுத்து *_Str);
  _CRTIMP முழு __cdecl _atoldbl(_LDOUBLE *_Result,எழுத்து *_Str);
  _CRTIMP முழு __cdecl _atoflt(_CRT_FLOAT *_Result,எழுத்து *_Str);
  _CRTIMP முழு __cdecl _atodbl_l(_CRT_DOUBLE *_Result,எழுத்து *_Str,_locale_t _Locale);
  _CRTIMP முழு __cdecl _atoldbl_l(_LDOUBLE *_Result,எழுத்து *_Str,_locale_t _Locale);
  _CRTIMP முழு __cdecl _atoflt_l(_CRT_FLOAT *_Result,எழுத்து *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,முழு _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,முழு _Shift);
  _CRTIMP வெறுமை __cdecl _makepath(எழுத்து *_Path,மாறிலி எழுத்து *_Drive,மாறிலி எழுத்து *_Dir,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  வெறுமை __cdecl perror(மாறிலி எழுத்து *Err_செய்தி);
#endif
  _CRTIMP முழு __cdecl _putenv(மாறிலி எழுத்து *_EnvString);
  unsigned முழு __cdecl _rotl(unsigned முழு _Val,முழு _Shift);
#எனில் _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,முழு _Shift);
#endif
  unsigned முழு __cdecl _rotr(unsigned முழு _Val,முழு _Shift);
#எனில் _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,முழு _Shift);
#endif
  _CRTIMP வெறுமை __cdecl _searchenv(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_EnvVar,எழுத்து *_ResultPath);
  _CRTIMP வெறுமை __cdecl _splitpath(மாறிலி எழுத்து *_FullPath,எழுத்து *_Drive,எழுத்து *_Dir,எழுத்து *_Filename,எழுத்து *_Ext);
  _CRTIMP வெறுமை __cdecl _swab(எழுத்து *_Buf1,எழுத்து *_Buf2,முழு _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,மாறிலி wchar_t *_Path,size_t Size_In_சொற்கள்);
  _CRTIMP வெறுமை __cdecl _wmakepath(wchar_t *_ResultPath,மாறிலி wchar_t *_Drive,மாறிலி wchar_t *_Dir,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP வெறுமை __cdecl _wperror(மாறிலி wchar_t *Err_செய்தி);
#endif
  _CRTIMP முழு __cdecl _wputenv(மாறிலி wchar_t *_EnvString);
  _CRTIMP வெறுமை __cdecl _wsearchenv(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP வெறுமை __cdecl _wsplitpath(மாறிலி wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP வெறுமை __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP வெறுமை __cdecl _seterrormode(முழு _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP வெறுமை __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#எனில் 0
#ifndef __cplusplus
#ifndef NOMINMAX
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
#endif
#endif
#endif

#define sys_errlist _sys_errlist
#define sys_nerr _sys_nerr
#define environ _environ
  எழுத்து *__cdecl ecvt(இரட்டை _Val,முழு இலக்கம்_Of_Digits,முழு *_PtDec,முழு *_PtSign);
  எழுத்து *__cdecl fcvt(இரட்டை _Val,முழு இலக்கம்_Of_Dec,முழு *_PtDec,முழு *_PtSign);
  எழுத்து *__cdecl gcvt(இரட்டை _Val,முழு இலக்கம்_Of_Digits,எழுத்து *_DstBuf);
  எழுத்து *__cdecl itoa(முழு _Val,எழுத்து *_DstBuf,முழு _Radix);
  எழுத்து *__cdecl ltoa(long _Val,எழுத்து *_DstBuf,முழு _Radix);
  முழு __cdecl putenv(மாறிலி எழுத்து *_EnvString);
  வெறுமை __cdecl swab(எழுத்து *_Buf1,எழுத்து *_Buf2,முழு _SizeInBytes);
  எழுத்து *__cdecl ultoa(unsigned long _Val,எழுத்து *_Dstbuf,முழு _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#எனில் !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  வகைவரை கட்டமைப்பு { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { திரும்பு (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #இல்லையெனில்
  long long  __cdecl strtoll(மாறிலி எழுத்து* __restrict__, எழுத்து** __restrict, முழு);
  unsigned long long  __cdecl strtoull(மாறிலி எழுத்து* __restrict__, எழுத்து** __restrict__, முழு);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (மாறிலி எழுத்து *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (மாறிலி wchar_t *);
  எழுத்து *__cdecl lltoa (long long, எழுத்து *, முழு);
  எழுத்து *__cdecl ulltoa (unsigned long long , எழுத்து *, முழு);
  wchar_t *__cdecl lltow (long long, wchar_t *, முழு);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, முழு);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (மாறிலி எழுத்து * _c) { திரும்பு _atoi64 (_c); }
  __CRT_INLINE எழுத்து *__cdecl lltoa (long long _n, எழுத்து * _c, முழு _i) { திரும்பு _i64toa (_n, _c, _i); }
  __CRT_INLINE எழுத்து *__cdecl ulltoa (unsigned long long _n, எழுத்து * _c, முழு _i) { திரும்பு _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (மாறிலி wchar_t * _w) { திரும்பு _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, முழு _i) { திரும்பு _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, முழு _i) { திரும்பு _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)

#அந்தர்பாவ <sec_api/stdlib_s.h>
#அந்தர்பாவ <malloc.h>

#endif
