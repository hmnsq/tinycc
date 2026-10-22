/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#include <_mingw.h>
#include <limits.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#නැතහොත්
#define NULL ((void *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  typedef පූර්ණ_සංඛ්‍යා (__cdecl *_onexit_t)(void);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  typedef sa_nracanaa _div_t {
    පූර්ණ_සංඛ්‍යා quot;
    පූර්ණ_සංඛ්‍යා rem;
  } div_t;

  typedef sa_nracanaa _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  typedef sa_nracanaa {
    unsigned var_na ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned var_na *)(&(x)->ld))

  typedef sa_nracanaa {
    dviguu_na x;
  } _CRT_DOUBLE;

  typedef sa_nracanaa {
    float f;
  } _CRT_FLOAT;

#pragma push_macro("long")
#undef long

  typedef sa_nracanaa {
    long dviguu_na x;
  } _LONGDOUBLE;

#pragma pop_macro("long")

#pragma pack(4)
  typedef sa_nracanaa {
    unsigned var_na ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  extern පූර්ණ_සංඛ්‍යා __mb_cur_max;
#නැතහොත්
#define __mb_cur_max    (*_imp____mb_cur_max)
  extern පූර්ණ_සංඛ්‍යා *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  extern පූර්ණ_සංඛ්‍යා __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#නැතහොත්
  extern පූර්ණ_සංඛ්‍යා* _imp____mbcur_max;
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

#define _WRITE_ABORT_MSG 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  typedef void (__cdecl *_purecall_handler)(void);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(void);

  typedef void (__cdecl *_invalid_parameter_handler)(const wchar_t *,const wchar_t *,const wchar_t *,unsigned පූර්ණ_සංඛ්‍යා,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP පූර්ණ_සංඛ්‍යා *__cdecl _errno(void);
#define errno (*_errno())
  errno_t __cdecl _set_errno(පූර්ණ_සංඛ්‍යා _Value);
  errno_t __cdecl _get_errno(පූර්ණ_සංඛ්‍යා *_Value);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(void);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long _Value);
  errno_t __cdecl _get_doserrno(unsigned long *_Value);
#ifdef _MSVCRT_
  extern var_na *_sys_errlist[];
  extern පූර්ණ_සංඛ්‍යා _sys_nerr;
#නැතහොත්
  _CRTIMP var_na *_sys_errlist[1];
  _CRTIMP පූර්ණ_සංඛ්‍යා _sys_nerr;
#endif
#නම් (defined(_X86_) && !defined(__x86_64))
  _CRTIMP පූර්ණ_සංඛ්‍යා *__cdecl __p___argc(void);
  _CRTIMP var_na ***__cdecl __p___argv(void);
  _CRTIMP wchar_t ***__cdecl __p___wargv(void);
  _CRTIMP var_na ***__cdecl __p__environ(void);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(void);
  _CRTIMP var_na **__cdecl __p__pgmptr(void);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(void);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  extern පූර්ණ_සංඛ්‍යා __argc;
#නැතහොත්
#define __argc (*_imp____argc)
  extern පූර්ණ_සංඛ්‍යා *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  extern var_na **__argv;
#නැතහොත්
#define __argv  (*_imp____argv)
  extern var_na ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  extern wchar_t **__wargv;
#නැතහොත්
#define __wargv (*_imp____wargv)
  extern wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  extern var_na **environ;
#නැතහොත්
#ifndef _environ
#ifdef _MSVCRT_
  extern var_na **_environ;
#නැතහොත්
#define _environ (*_imp___environ)
  extern var_na ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  extern wchar_t **_wenviron;
#නැතහොත්
#define _wenviron       (*_imp___wenviron)
  extern wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#නම් defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
extern පූර්ණ_සංඛ්‍යා __argc;
extern var_na **__argv;
extern wchar_t **__wargv;
extern var_na **_environ;
extern wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  extern var_na *_pgmptr;
#නැතහොත්
#define _pgmptr (*_imp___pgmptr)
  extern var_na **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  extern wchar_t *_wpgmptr;
#නැතහොත්
#define _wpgmptr        (*_imp___wpgmptr)
  extern wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(var_na **_Value);
  errno_t __cdecl _get_wpgmptr(wchar_t **_Value);
#ifndef _fmode
#ifdef _MSVCRT_
  extern පූර්ණ_සංඛ්‍යා _fmode;
#නැතහොත්
#define _fmode  (*_imp___fmode)
  extern පූර්ණ_සංඛ්‍යා *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(පූර්ණ_සංඛ්‍යා _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(පූර්ණ_සංඛ්‍යා *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  extern unsigned පූර්ණ_සංඛ්‍යා _osplatform;
#නැතහොත්
#define _osplatform (*_imp___osplatform)
  extern unsigned පූර්ණ_සංඛ්‍යා *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  extern unsigned පූර්ණ_සංඛ්‍යා _osver;
#නැතහොත්
#define _osver  (*_imp___osver)
  extern unsigned පූර්ණ_සංඛ්‍යා *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  extern unsigned පූර්ණ_සංඛ්‍යා _winver;
#නැතහොත්
#define _winver (*_imp___winver)
  extern unsigned පූර්ණ_සංඛ්‍යා *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  extern unsigned පූර්ණ_සංඛ්‍යා _winmajor;
#නැතහොත්
#define _winmajor       (*_imp___winmajor)
  extern unsigned පූර්ණ_සංඛ්‍යා *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  extern unsigned පූර්ණ_සංඛ්‍යා _winminor;
#නැතහොත්
#define _winminor       (*_imp___winminor)
  extern unsigned පූර්ණ_සංඛ්‍යා *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned පූර්ණ_සංඛ්‍යා *_Value);
  errno_t __cdecl _get_osver(unsigned පූර්ණ_සංඛ්‍යා *_Value);
  errno_t __cdecl _get_winver(unsigned පූර්ණ_සංඛ්‍යා *_Value);
  errno_t __cdecl _get_winmajor(unsigned පූර්ණ_සංඛ්‍යා *_Value);
  errno_t __cdecl _get_winminor(unsigned පූර්ණ_සංඛ්‍යා *_Value);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (parimaa_na(_Array) / parimaa_na(_Array[0]))
#නැතහොත්
  extern "C++" {
    template <typename _CountofType,size_t _SizeOfArray> var_na (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) parimaa_na(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  void __cdecl __MINGW_NOTHROW exit(පූර්ණ_සංඛ්‍යා _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP void __cdecl __MINGW_NOTHROW _exit(පූර්ණ_සංඛ්‍යා _Code) __MINGW_ATTRIB_NORETURN;
#නම් !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  void __cdecl _Exit(පූර්ණ_සංඛ්‍යා) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN void  __cdecl _Exit(පූර්ණ_සංඛ්‍යා status)
  {  _exit(status); }
#endif

#pragma push_macro("abort")
#undef abort
  void __cdecl __declspec(noreturn) abort(void);
#pragma pop_macro("abort")

#endif

  _CRTIMP unsigned පූර්ණ_සංඛ්‍යා __cdecl _set_abort_behavior(unsigned පූර්ණ_සංඛ්‍යා _Flags,unsigned පූර්ණ_සංඛ්‍යා _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  පූර්ණ_සංඛ්‍යා __cdecl abs(පූර්ණ_සංඛ්‍යා _X);
  long __cdecl labs(long _X);
#endif

#නම් _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  පූර්ණ_සංඛ්‍යා __cdecl atexit(void (__cdecl *)(void));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  dviguu_na __cdecl atof(const var_na *_String);
  dviguu_na __cdecl _atof_l(const var_na *_String,_locale_t _Locale);
#endif
  පූර්ණ_සංඛ්‍යා __cdecl atoi(const var_na *_Str);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _atoi_l(const var_na *_Str,_locale_t _Locale);
  long __cdecl atol(const var_na *_Str);
  _CRTIMP long __cdecl _atol_l(const var_na *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  void *__cdecl bsearch(const void *_Key,const void *_Base,size_t _NumOfElements,size_t _SizeOfElements,පූර්ණ_සංඛ්‍යා (__cdecl *_PtFuncCompare)(const void *,const void *));
  void __cdecl qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,පූර්ණ_සංඛ්‍යා (__cdecl *_PtFuncCompare)(const void *,const void *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#නම් _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(පූර්ණ_සංඛ්‍යා _Numerator,පූර්ණ_සංඛ්‍යා _Denominator);
  var_na *__cdecl getenv(const var_na *_VarName);
  _CRTIMP var_na *__cdecl _itoa(පූර්ණ_සංඛ්‍යා _Value,var_na *_Dest,පූර්ණ_සංඛ්‍යා _Radix);
#නම් _INTEGRAL_MAX_BITS >= 64
  _CRTIMP var_na *__cdecl _i64toa(__int64 _Val,var_na *_DstBuf,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP var_na *__cdecl _ui64toa(unsigned __int64 _Val,var_na *_DstBuf,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP __int64 __cdecl _atoi64(const var_na *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(const var_na *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(const var_na *_String,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(const var_na *_String,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(const var_na *_String,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(const var_na *_String,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP var_na *__cdecl _ltoa(long _Value,var_na *_Dest,පූර්ණ_සංඛ්‍යා _Radix);
  පූර්ණ_සංඛ්‍යා __cdecl mblen(const var_na *_Ch,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _mblen_l(const var_na *_Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(const var_na *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(const var_na *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(const var_na *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstrnlen_l(const var_na *_Str,size_t _MaxCount,_locale_t _Locale);
  පූර්ණ_සංඛ්‍යා __cdecl mbtowc(wchar_t *_DstCh,const var_na *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _mbtowc_l(wchar_t *_DstCh,const var_na *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,const var_na *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,const var_na *_Source,size_t _MaxCount,_locale_t _Locale);
  පූර්ණ_සංඛ්‍යා __cdecl rand(void);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _set_error_mode(පූර්ණ_සංඛ්‍යා _Mode);
  void __cdecl srand(unsigned පූර්ණ_සංඛ්‍යා _Seed);
  dviguu_na __cdecl strtod(const var_na *_Str,var_na **_EndPtr);
#නම් !defined __NO_ISOCEXT  /* in libmingwex.a */
#නම් __TINYC__
  __CRT_INLINE float __cdecl strtof (const var_na *p, var_na ** e) { ආපසු strtod(p, e); }
  __CRT_INLINE long dviguu_na __cdecl strtold(const var_na *p, var_na ** e) { ආපසු strtod(p, e); }
#නැතහොත්
  float __cdecl strtof (const var_na * __restrict__, var_na ** __restrict__);
  long dviguu_na __cdecl strtold(const var_na * __restrict__, var_na ** __restrict__);
#endif
#නැතහොත්
  float __cdecl strtof(const var_na *nptr, var_na **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP dviguu_na __cdecl _strtod_l(const var_na *_Str,var_na **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(const var_na *_Str,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP long __cdecl _strtol_l(const var_na *_Str,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(const var_na *_Str,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(const var_na *_Str,var_na **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  පූර්ණ_සංඛ්‍යා __cdecl system(const var_na *_Command);
#endif
  _CRTIMP var_na *__cdecl _ultoa(unsigned long _Value,var_na *_Dest,පූර්ණ_සංඛ්‍යා _Radix);
  පූර්ණ_සංඛ්‍යා __cdecl wctomb(var_na *_MbCh,wchar_t _WCh);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wctomb_l(var_na *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(var_na *_Dest,const wchar_t *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcstombs_l(var_na *_Dest,const wchar_t *_Source,size_t _MaxCount,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  void *__cdecl calloc(size_t _NumOfElements,size_t _SizeOfElements);
  void __cdecl free(void *_Memory);
  void *__cdecl malloc(size_t _Size);
  void *__cdecl realloc(void *_Memory,size_t _NewSize);
  _CRTIMP void *__cdecl _recalloc(void *_Memory,size_t _Count,size_t _Size);
  _CRTIMP void __cdecl _aligned_free(void *_Memory);
  _CRTIMP void *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP void *__cdecl _aligned_realloc(void *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_realloc(void *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP void *__cdecl _aligned_offset_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(පූර්ණ_සංඛ්‍යා _Value,wchar_t *_Dest,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long _Value,wchar_t *_Dest,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long _Value,wchar_t *_Dest,පූර්ණ_සංඛ්‍යා _Radix);
  dviguu_na __cdecl wcstod(const wchar_t *_Str,wchar_t **_EndPtr);
  float __cdecl wcstof(const wchar_t *nptr, wchar_t **endptr);
#නම් !defined __NO_ISOCEXT /* in libmingwex.a */
  float __cdecl wcstof( const wchar_t * __restrict__, wchar_t ** __restrict__);
  long dviguu_na __cdecl wcstold(const wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP dviguu_na __cdecl _wcstod_l(const wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(const wchar_t *_Str,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP long __cdecl _wcstol_l(const wchar_t *_Str,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(const wchar_t *_Str,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(const wchar_t *_Str,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(const wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wsystem(const wchar_t *_Command);
#endif
  _CRTIMP dviguu_na __cdecl _wtof(const wchar_t *_Str);
  _CRTIMP dviguu_na __cdecl _wtof_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wtoi(const wchar_t *_Str);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wtoi_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(const wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(const wchar_t *_Str,_locale_t _Locale);

#නම් _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(const wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(const wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(const wchar_t *_Str,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(const wchar_t *_Str,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str ,wchar_t **_EndPtr,පූර්ණ_සංඛ්‍යා _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP var_na *__cdecl _fullpath(var_na *_FullPath,const var_na *_Path,size_t _SizeInBytes);
  _CRTIMP var_na *__cdecl _ecvt(dviguu_na _Val,පූර්ණ_සංඛ්‍යා _NumOfDigits,පූර්ණ_සංඛ්‍යා *_PtDec,පූර්ණ_සංඛ්‍යා *_PtSign);
  _CRTIMP var_na *__cdecl _fcvt(dviguu_na _Val,පූර්ණ_සංඛ්‍යා _NumOfDec,පූර්ණ_සංඛ්‍යා *_PtDec,පූර්ණ_සංඛ්‍යා *_PtSign);
  _CRTIMP var_na *__cdecl _gcvt(dviguu_na _Val,පූර්ණ_සංඛ්‍යා _NumOfDigits,var_na *_DstBuf);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _atodbl(_CRT_DOUBLE *_Result,var_na *_Str);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _atoldbl(_LDOUBLE *_Result,var_na *_Str);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _atoflt(_CRT_FLOAT *_Result,var_na *_Str);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _atodbl_l(_CRT_DOUBLE *_Result,var_na *_Str,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _atoldbl_l(_LDOUBLE *_Result,var_na *_Str,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _atoflt_l(_CRT_FLOAT *_Result,var_na *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,පූර්ණ_සංඛ්‍යා _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,පූර්ණ_සංඛ්‍යා _Shift);
  _CRTIMP void __cdecl _makepath(var_na *_Path,const var_na *_Drive,const var_na *_Dir,const var_na *_Filename,const var_na *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  void __cdecl perror(const var_na *_ErrMsg);
#endif
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _putenv(const var_na *_EnvString);
  unsigned පූර්ණ_සංඛ්‍යා __cdecl _rotl(unsigned පූර්ණ_සංඛ්‍යා _Val,පූර්ණ_සංඛ්‍යා _Shift);
#නම් _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,පූර්ණ_සංඛ්‍යා _Shift);
#endif
  unsigned පූර්ණ_සංඛ්‍යා __cdecl _rotr(unsigned පූර්ණ_සංඛ්‍යා _Val,පූර්ණ_සංඛ්‍යා _Shift);
#නම් _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,පූර්ණ_සංඛ්‍යා _Shift);
#endif
  _CRTIMP void __cdecl _searchenv(const var_na *_Filename,const var_na *_EnvVar,var_na *_ResultPath);
  _CRTIMP void __cdecl _splitpath(const var_na *_FullPath,var_na *_Drive,var_na *_Dir,var_na *_Filename,var_na *_Ext);
  _CRTIMP void __cdecl _swab(var_na *_Buf1,var_na *_Buf2,පූර්ණ_සංඛ්‍යා _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,const wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP void __cdecl _wmakepath(wchar_t *_ResultPath,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wputenv(const wchar_t *_EnvString);
  _CRTIMP void __cdecl _wsearchenv(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP void __cdecl _wsplitpath(const wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP void __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP void __cdecl _seterrormode(පූර්ණ_සංඛ්‍යා _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP void __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#නම් 0
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
  var_na *__cdecl ecvt(dviguu_na _Val,පූර්ණ_සංඛ්‍යා _NumOfDigits,පූර්ණ_සංඛ්‍යා *_PtDec,පූර්ණ_සංඛ්‍යා *_PtSign);
  var_na *__cdecl fcvt(dviguu_na _Val,පූර්ණ_සංඛ්‍යා _NumOfDec,පූර්ණ_සංඛ්‍යා *_PtDec,පූර්ණ_සංඛ්‍යා *_PtSign);
  var_na *__cdecl gcvt(dviguu_na _Val,පූර්ණ_සංඛ්‍යා _NumOfDigits,var_na *_DstBuf);
  var_na *__cdecl itoa(පූර්ණ_සංඛ්‍යා _Val,var_na *_DstBuf,පූර්ණ_සංඛ්‍යා _Radix);
  var_na *__cdecl ltoa(long _Val,var_na *_DstBuf,පූර්ණ_සංඛ්‍යා _Radix);
  පූර්ණ_සංඛ්‍යා __cdecl putenv(const var_na *_EnvString);
  void __cdecl swab(var_na *_Buf1,var_na *_Buf2,පූර්ණ_සංඛ්‍යා _SizeInBytes);
  var_na *__cdecl ultoa(unsigned long _Val,var_na *_Dstbuf,පූර්ණ_සංඛ්‍යා _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#නම් !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  typedef sa_nracanaa { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { ආපසු (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #නැතහොත්
  long long  __cdecl strtoll(const var_na* __restrict__, var_na** __restrict, පූර්ණ_සංඛ්‍යා);
  unsigned long long  __cdecl strtoull(const var_na* __restrict__, var_na** __restrict__, පූර්ණ_සංඛ්‍යා);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (const var_na *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (const wchar_t *);
  var_na *__cdecl lltoa (long long, var_na *, පූර්ණ_සංඛ්‍යා);
  var_na *__cdecl ulltoa (unsigned long long , var_na *, පූර්ණ_සංඛ්‍යා);
  wchar_t *__cdecl lltow (long long, wchar_t *, පූර්ණ_සංඛ්‍යා);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, පූර්ණ_සංඛ්‍යා);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (const var_na * _c) { ආපසු _atoi64 (_c); }
  __CRT_INLINE var_na *__cdecl lltoa (long long _n, var_na * _c, පූර්ණ_සංඛ්‍යා _i) { ආපසු _i64toa (_n, _c, _i); }
  __CRT_INLINE var_na *__cdecl ulltoa (unsigned long long _n, var_na * _c, පූර්ණ_සංඛ්‍යා _i) { ආපසු _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (const wchar_t * _w) { ආපසු _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, පූර්ණ_සංඛ්‍යා _i) { ආපසු _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, පූර්ණ_සංඛ්‍යා _i) { ආපසු _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/stdlib_s.h>
#include <malloc.h>

#endif
