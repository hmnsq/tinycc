/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#അന്തര്ഭാവ <_mingw.h>
#അന്തര്ഭാവ <limits.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef ശൂന്യ
#ifdef __cplusplus
#define ശൂന്യ 0
#അല്ലെങ്കിൽ
#define ശൂന്യ ((ശൂന്യം *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  തരനിർവചനം പൂർണ്ണസംഖ്യ (__cdecl *_onexit_t)(ശൂന്യം);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  തരനിർവചനം ഘടന _div_t {
    പൂർണ്ണസംഖ്യ quot;
    പൂർണ്ണസംഖ്യ rem;
  } div_t;

  തരനിർവചനം ഘടന _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  തരനിർവചനം ഘടന {
    unsigned അക്ഷരം ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned അക്ഷരം *)(&(x)->ld))

  തരനിർവചനം ഘടന {
    ഇരട്ട x;
  } _CRT_DOUBLE;

  തരനിർവചനം ഘടന {
    ദശാംശം f;
  } _CRT_FLOAT;

#pragma തള്ളുക_macro("long")
#undef long

  തരനിർവചനം ഘടന {
    long ഇരട്ട x;
  } _LONGDOUBLE;

#pragma എടുക്കുക_macro("long")

#pragma pack(4)
  തരനിർവചനം ഘടന {
    unsigned അക്ഷരം ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  ബാഹ്യ പൂർണ്ണസംഖ്യ __mb_cur_max;
#അല്ലെങ്കിൽ
#define __mb_cur_max    (*_imp____mb_cur_max)
  ബാഹ്യ പൂർണ്ണസംഖ്യ *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  ബാഹ്യ പൂർണ്ണസംഖ്യ __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#അല്ലെങ്കിൽ
  ബാഹ്യ പൂർണ്ണസംഖ്യ* _imp____mbcur_max;
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

#define WRITE_ABORT_സന്ദേശം 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  തരനിർവചനം ശൂന്യം (__cdecl *_purecall_handler)(ശൂന്യം);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(ശൂന്യം);

  തരനിർവചനം ശൂന്യം (__cdecl *_invalid_parameter_handler)(സ്ഥിരം wchar_t *,സ്ഥിരം wchar_t *,സ്ഥിരം wchar_t *,unsigned പൂർണ്ണസംഖ്യ,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(ശൂന്യം);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP പൂർണ്ണസംഖ്യ *__cdecl _errno(ശൂന്യം);
#define errno (*_errno())
  errno_t __cdecl _set_errno(പൂർണ്ണസംഖ്യ മൂല്യം_2);
  errno_t __cdecl _get_errno(പൂർണ്ണസംഖ്യ *മൂല്യം_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(ശൂന്യം);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long മൂല്യം_2);
  errno_t __cdecl _get_doserrno(unsigned long *മൂല്യം_2);
#ifdef _MSVCRT_
  ബാഹ്യ അക്ഷരം *_sys_errlist[];
  ബാഹ്യ പൂർണ്ണസംഖ്യ _sys_nerr;
#അല്ലെങ്കിൽ
  _CRTIMP അക്ഷരം *_sys_errlist[1];
  _CRTIMP പൂർണ്ണസംഖ്യ _sys_nerr;
#endif
#എങ്കിൽ (defined(_X86_) && !defined(__x86_64))
  _CRTIMP പൂർണ്ണസംഖ്യ *__cdecl __p___argc(ശൂന്യം);
  _CRTIMP അക്ഷരം ***__cdecl __p___argv(ശൂന്യം);
  _CRTIMP wchar_t ***__cdecl __p___wargv(ശൂന്യം);
  _CRTIMP അക്ഷരം ***__cdecl __p__environ(ശൂന്യം);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(ശൂന്യം);
  _CRTIMP അക്ഷരം **__cdecl __p__pgmptr(ശൂന്യം);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(ശൂന്യം);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  ബാഹ്യ പൂർണ്ണസംഖ്യ __argc;
#അല്ലെങ്കിൽ
#define __argc (*_imp____argc)
  ബാഹ്യ പൂർണ്ണസംഖ്യ *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  ബാഹ്യ അക്ഷരം **__argv;
#അല്ലെങ്കിൽ
#define __argv  (*_imp____argv)
  ബാഹ്യ അക്ഷരം ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  ബാഹ്യ wchar_t **__wargv;
#അല്ലെങ്കിൽ
#define __wargv (*_imp____wargv)
  ബാഹ്യ wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  ബാഹ്യ അക്ഷരം **environ;
#അല്ലെങ്കിൽ
#ifndef _environ
#ifdef _MSVCRT_
  ബാഹ്യ അക്ഷരം **_environ;
#അല്ലെങ്കിൽ
#define _environ (*_imp___environ)
  ബാഹ്യ അക്ഷരം ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  ബാഹ്യ wchar_t **_wenviron;
#അല്ലെങ്കിൽ
#define _wenviron       (*_imp___wenviron)
  ബാഹ്യ wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#എങ്കിൽ defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
ബാഹ്യ പൂർണ്ണസംഖ്യ __argc;
ബാഹ്യ അക്ഷരം **__argv;
ബാഹ്യ wchar_t **__wargv;
ബാഹ്യ അക്ഷരം **_environ;
ബാഹ്യ wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  ബാഹ്യ അക്ഷരം *_pgmptr;
#അല്ലെങ്കിൽ
#define _pgmptr (*_imp___pgmptr)
  ബാഹ്യ അക്ഷരം **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  ബാഹ്യ wchar_t *_wpgmptr;
#അല്ലെങ്കിൽ
#define _wpgmptr        (*_imp___wpgmptr)
  ബാഹ്യ wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(അക്ഷരം **മൂല്യം_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **മൂല്യം_2);
#ifndef _fmode
#ifdef _MSVCRT_
  ബാഹ്യ പൂർണ്ണസംഖ്യ _fmode;
#അല്ലെങ്കിൽ
#define _fmode  (*_imp___fmode)
  ബാഹ്യ പൂർണ്ണസംഖ്യ *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(പൂർണ്ണസംഖ്യ _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(പൂർണ്ണസംഖ്യ *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ _osplatform;
#അല്ലെങ്കിൽ
#define _osplatform (*_imp___osplatform)
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ _osver;
#അല്ലെങ്കിൽ
#define _osver  (*_imp___osver)
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ _winver;
#അല്ലെങ്കിൽ
#define _winver (*_imp___winver)
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ _winmajor;
#അല്ലെങ്കിൽ
#define _winmajor       (*_imp___winmajor)
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ _winminor;
#അല്ലെങ്കിൽ
#define _winminor       (*_imp___winminor)
  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned പൂർണ്ണസംഖ്യ *മൂല്യം_2);
  errno_t __cdecl _get_osver(unsigned പൂർണ്ണസംഖ്യ *മൂല്യം_2);
  errno_t __cdecl _get_winver(unsigned പൂർണ്ണസംഖ്യ *മൂല്യം_2);
  errno_t __cdecl _get_winmajor(unsigned പൂർണ്ണസംഖ്യ *മൂല്യം_2);
  errno_t __cdecl _get_winminor(unsigned പൂർണ്ണസംഖ്യ *മൂല്യം_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (വലുപ്പം(_Array) / വലുപ്പം(_Array[0]))
#അല്ലെങ്കിൽ
  ബാഹ്യ "C++" {
    template <typename _CountofType,size_t _SizeOfArray> അക്ഷരം (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) വലുപ്പം(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ശൂന്യം __cdecl __MINGW_NOTHROW exit(പൂർണ്ണസംഖ്യ _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ശൂന്യം __cdecl __MINGW_NOTHROW _exit(പൂർണ്ണസംഖ്യ _Code) __MINGW_ATTRIB_NORETURN;
#എങ്കിൽ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  ശൂന്യം __cdecl _Exit(പൂർണ്ണസംഖ്യ) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN ശൂന്യം  __cdecl _Exit(പൂർണ്ണസംഖ്യ status)
  {  _exit(status); }
#endif

#pragma തള്ളുക_macro("abort")
#undef abort
  ശൂന്യം __cdecl __declspec(noreturn) abort(ശൂന്യം);
#pragma എടുക്കുക_macro("abort")

#endif

  _CRTIMP unsigned പൂർണ്ണസംഖ്യ __cdecl _set_abort_behavior(unsigned പൂർണ്ണസംഖ്യ _Flags,unsigned പൂർണ്ണസംഖ്യ _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  പൂർണ്ണസംഖ്യ __cdecl abs(പൂർണ്ണസംഖ്യ _X);
  long __cdecl labs(long _X);
#endif

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  പൂർണ്ണസംഖ്യ __cdecl atexit(ശൂന്യം (__cdecl *)(ശൂന്യം));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  ഇരട്ട __cdecl atof(സ്ഥിരം അക്ഷരം *_String);
  ഇരട്ട __cdecl _atof_l(സ്ഥിരം അക്ഷരം *_String,_locale_t _Locale);
#endif
  പൂർണ്ണസംഖ്യ __cdecl atoi(സ്ഥിരം അക്ഷരം *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _atoi_l(സ്ഥിരം അക്ഷരം *_Str,_locale_t _Locale);
  long __cdecl atol(സ്ഥിരം അക്ഷരം *_Str);
  _CRTIMP long __cdecl _atol_l(സ്ഥിരം അക്ഷരം *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  ശൂന്യം *__cdecl bsearch(സ്ഥിരം ശൂന്യം *താക്കോൽ_2,സ്ഥിരം ശൂന്യം *_Base,size_t അക്കം_Of_Elements,size_t _SizeOfElements,പൂർണ്ണസംഖ്യ (__cdecl *_PtFuncCompare)(സ്ഥിരം ശൂന്യം *,സ്ഥിരം ശൂന്യം *));
  ശൂന്യം __cdecl qsort(ശൂന്യം *_Base,size_t അക്കം_Of_Elements,size_t _SizeOfElements,പൂർണ്ണസംഖ്യ (__cdecl *_PtFuncCompare)(സ്ഥിരം ശൂന്യം *,സ്ഥിരം ശൂന്യം *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(പൂർണ്ണസംഖ്യ _Numerator,പൂർണ്ണസംഖ്യ _Denominator);
  അക്ഷരം *__cdecl getenv(സ്ഥിരം അക്ഷരം *_VarName);
  _CRTIMP അക്ഷരം *__cdecl _itoa(പൂർണ്ണസംഖ്യ മൂല്യം_2,അക്ഷരം *_Dest,പൂർണ്ണസംഖ്യ _Radix);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP അക്ഷരം *__cdecl _i64toa(__int64 _Val,അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP അക്ഷരം *__cdecl _ui64toa(unsigned __int64 _Val,അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP __int64 __cdecl _atoi64(സ്ഥിരം അക്ഷരം *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(സ്ഥിരം അക്ഷരം *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(സ്ഥിരം അക്ഷരം *_String,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(സ്ഥിരം അക്ഷരം *_String,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(സ്ഥിരം അക്ഷരം *_String,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(സ്ഥിരം അക്ഷരം *_String,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP അക്ഷരം *__cdecl _ltoa(long മൂല്യം_2,അക്ഷരം *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  പൂർണ്ണസംഖ്യ __cdecl mblen(സ്ഥിരം അക്ഷരം *_Ch,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _mblen_l(സ്ഥിരം അക്ഷരം *_Ch,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(സ്ഥിരം അക്ഷരം *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(സ്ഥിരം അക്ഷരം *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(സ്ഥിരം അക്ഷരം *_Str,size_t Max_എണ്ണം);
  _CRTIMP size_t __cdecl _mbstrnlen_l(സ്ഥിരം അക്ഷരം *_Str,size_t Max_എണ്ണം,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl mbtowc(wchar_t *_DstCh,സ്ഥിരം അക്ഷരം *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _mbtowc_l(wchar_t *_DstCh,സ്ഥിരം അക്ഷരം *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,സ്ഥിരം അക്ഷരം *_Source,size_t Max_എണ്ണം);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,സ്ഥിരം അക്ഷരം *_Source,size_t Max_എണ്ണം,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl rand(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _set_error_mode(പൂർണ്ണസംഖ്യ _Mode);
  ശൂന്യം __cdecl srand(unsigned പൂർണ്ണസംഖ്യ _Seed);
  ഇരട്ട __cdecl strtod(സ്ഥിരം അക്ഷരം *_Str,അക്ഷരം **_EndPtr);
#എങ്കിൽ !defined __NO_ISOCEXT  /* in libmingwex.a */
#എങ്കിൽ __TINYC__
  __CRT_INLINE ദശാംശം __cdecl strtof (സ്ഥിരം അക്ഷരം *p, അക്ഷരം ** e) { തിരികെ strtod(p, e); }
  __CRT_INLINE long ഇരട്ട __cdecl strtold(സ്ഥിരം അക്ഷരം *p, അക്ഷരം ** e) { തിരികെ strtod(p, e); }
#അല്ലെങ്കിൽ
  ദശാംശം __cdecl strtof (സ്ഥിരം അക്ഷരം * __restrict__, അക്ഷരം ** __restrict__);
  long ഇരട്ട __cdecl strtold(സ്ഥിരം അക്ഷരം * __restrict__, അക്ഷരം ** __restrict__);
#endif
#അല്ലെങ്കിൽ
  ദശാംശം __cdecl strtof(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP ഇരട്ട __cdecl _strtod_l(സ്ഥിരം അക്ഷരം *_Str,അക്ഷരം **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(സ്ഥിരം അക്ഷരം *_Str,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP long __cdecl _strtol_l(സ്ഥിരം അക്ഷരം *_Str,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(സ്ഥിരം അക്ഷരം *_Str,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(സ്ഥിരം അക്ഷരം *_Str,അക്ഷരം **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  പൂർണ്ണസംഖ്യ __cdecl system(സ്ഥിരം അക്ഷരം *_Command);
#endif
  _CRTIMP അക്ഷരം *__cdecl _ultoa(unsigned long മൂല്യം_2,അക്ഷരം *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  പൂർണ്ണസംഖ്യ __cdecl wctomb(അക്ഷരം *_MbCh,wchar_t _WCh);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wctomb_l(അക്ഷരം *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(അക്ഷരം *_Dest,സ്ഥിരം wchar_t *_Source,size_t Max_എണ്ണം);
  _CRTIMP size_t __cdecl _wcstombs_l(അക്ഷരം *_Dest,സ്ഥിരം wchar_t *_Source,size_t Max_എണ്ണം,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  ശൂന്യം *__cdecl calloc(size_t അക്കം_Of_Elements,size_t _SizeOfElements);
  ശൂന്യം __cdecl സ്വതന്ത്രം(ശൂന്യം *_Memory);
  ശൂന്യം *__cdecl malloc(size_t _Size);
  ശൂന്യം *__cdecl realloc(ശൂന്യം *_Memory,size_t _NewSize);
  _CRTIMP ശൂന്യം *__cdecl _recalloc(ശൂന്യം *_Memory,size_t എണ്ണം_5,size_t _Size);
  _CRTIMP ശൂന്യം __cdecl _aligned_free(ശൂന്യം *_Memory);
  _CRTIMP ശൂന്യം *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP ശൂന്യം *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ശൂന്യം *__cdecl _aligned_realloc(ശൂന്യം *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP ശൂന്യം *__cdecl _aligned_recalloc(ശൂന്യം *_Memory,size_t എണ്ണം_5,size_t _Size,size_t _Alignment);
  _CRTIMP ശൂന്യം *__cdecl _aligned_offset_realloc(ശൂന്യം *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ശൂന്യം *__cdecl _aligned_offset_recalloc(ശൂന്യം *_Memory,size_t എണ്ണം_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(പൂർണ്ണസംഖ്യ മൂല്യം_2,wchar_t *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long മൂല്യം_2,wchar_t *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long മൂല്യം_2,wchar_t *_Dest,പൂർണ്ണസംഖ്യ _Radix);
  ഇരട്ട __cdecl wcstod(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr);
  ദശാംശം __cdecl wcstof(സ്ഥിരം wchar_t *nptr, wchar_t **endptr);
#എങ്കിൽ !defined __NO_ISOCEXT /* in libmingwex.a */
  ദശാംശം __cdecl wcstof( സ്ഥിരം wchar_t * __restrict__, wchar_t ** __restrict__);
  long ഇരട്ട __cdecl wcstold(സ്ഥിരം wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP ഇരട്ട __cdecl _wcstod_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP long __cdecl _wcstol_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(സ്ഥിരം wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsystem(സ്ഥിരം wchar_t *_Command);
#endif
  _CRTIMP ഇരട്ട __cdecl _wtof(സ്ഥിരം wchar_t *_Str);
  _CRTIMP ഇരട്ട __cdecl _wtof_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wtoi(സ്ഥിരം wchar_t *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wtoi_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(സ്ഥിരം wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(സ്ഥിരം wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(സ്ഥിരം wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(സ്ഥിരം wchar_t *_Str,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(സ്ഥിരം wchar_t *_Str ,wchar_t **_EndPtr,പൂർണ്ണസംഖ്യ _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP അക്ഷരം *__cdecl _fullpath(അക്ഷരം *_FullPath,സ്ഥിരം അക്ഷരം *_Path,size_t _SizeInBytes);
  _CRTIMP അക്ഷരം *__cdecl _ecvt(ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Digits,പൂർണ്ണസംഖ്യ *_PtDec,പൂർണ്ണസംഖ്യ *_PtSign);
  _CRTIMP അക്ഷരം *__cdecl _fcvt(ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Dec,പൂർണ്ണസംഖ്യ *_PtDec,പൂർണ്ണസംഖ്യ *_PtSign);
  _CRTIMP അക്ഷരം *__cdecl _gcvt(ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Digits,അക്ഷരം *_DstBuf);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _atodbl(_CRT_DOUBLE *_Result,അക്ഷരം *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _atoldbl(_LDOUBLE *_Result,അക്ഷരം *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _atoflt(_CRT_FLOAT *_Result,അക്ഷരം *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _atodbl_l(_CRT_DOUBLE *_Result,അക്ഷരം *_Str,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _atoldbl_l(_LDOUBLE *_Result,അക്ഷരം *_Str,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _atoflt_l(_CRT_FLOAT *_Result,അക്ഷരം *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,പൂർണ്ണസംഖ്യ _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,പൂർണ്ണസംഖ്യ _Shift);
  _CRTIMP ശൂന്യം __cdecl _makepath(അക്ഷരം *_Path,സ്ഥിരം അക്ഷരം *_Drive,സ്ഥിരം അക്ഷരം *_Dir,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  ശൂന്യം __cdecl perror(സ്ഥിരം അക്ഷരം *Err_സന്ദേശം);
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _putenv(സ്ഥിരം അക്ഷരം *_EnvString);
  unsigned പൂർണ്ണസംഖ്യ __cdecl _rotl(unsigned പൂർണ്ണസംഖ്യ _Val,പൂർണ്ണസംഖ്യ _Shift);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,പൂർണ്ണസംഖ്യ _Shift);
#endif
  unsigned പൂർണ്ണസംഖ്യ __cdecl _rotr(unsigned പൂർണ്ണസംഖ്യ _Val,പൂർണ്ണസംഖ്യ _Shift);
#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,പൂർണ്ണസംഖ്യ _Shift);
#endif
  _CRTIMP ശൂന്യം __cdecl _searchenv(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_EnvVar,അക്ഷരം *_ResultPath);
  _CRTIMP ശൂന്യം __cdecl _splitpath(സ്ഥിരം അക്ഷരം *_FullPath,അക്ഷരം *_Drive,അക്ഷരം *_Dir,അക്ഷരം *_Filename,അക്ഷരം *_Ext);
  _CRTIMP ശൂന്യം __cdecl _swab(അക്ഷരം *_Buf1,അക്ഷരം *_Buf2,പൂർണ്ണസംഖ്യ _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,സ്ഥിരം wchar_t *_Path,size_t Size_In_വാക്കുകൾ);
  _CRTIMP ശൂന്യം __cdecl _wmakepath(wchar_t *_ResultPath,സ്ഥിരം wchar_t *_Drive,സ്ഥിരം wchar_t *_Dir,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ശൂന്യം __cdecl _wperror(സ്ഥിരം wchar_t *Err_സന്ദേശം);
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wputenv(സ്ഥിരം wchar_t *_EnvString);
  _CRTIMP ശൂന്യം __cdecl _wsearchenv(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP ശൂന്യം __cdecl _wsplitpath(സ്ഥിരം wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP ശൂന്യം __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP ശൂന്യം __cdecl _seterrormode(പൂർണ്ണസംഖ്യ _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP ശൂന്യം __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#എങ്കിൽ 0
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
  അക്ഷരം *__cdecl ecvt(ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Digits,പൂർണ്ണസംഖ്യ *_PtDec,പൂർണ്ണസംഖ്യ *_PtSign);
  അക്ഷരം *__cdecl fcvt(ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Dec,പൂർണ്ണസംഖ്യ *_PtDec,പൂർണ്ണസംഖ്യ *_PtSign);
  അക്ഷരം *__cdecl gcvt(ഇരട്ട _Val,പൂർണ്ണസംഖ്യ അക്കം_Of_Digits,അക്ഷരം *_DstBuf);
  അക്ഷരം *__cdecl itoa(പൂർണ്ണസംഖ്യ _Val,അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  അക്ഷരം *__cdecl ltoa(long _Val,അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _Radix);
  പൂർണ്ണസംഖ്യ __cdecl putenv(സ്ഥിരം അക്ഷരം *_EnvString);
  ശൂന്യം __cdecl swab(അക്ഷരം *_Buf1,അക്ഷരം *_Buf2,പൂർണ്ണസംഖ്യ _SizeInBytes);
  അക്ഷരം *__cdecl ultoa(unsigned long _Val,അക്ഷരം *_Dstbuf,പൂർണ്ണസംഖ്യ _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#എങ്കിൽ !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  തരനിർവചനം ഘടന { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { തിരികെ (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #അല്ലെങ്കിൽ
  long long  __cdecl strtoll(സ്ഥിരം അക്ഷരം* __restrict__, അക്ഷരം** __restrict, പൂർണ്ണസംഖ്യ);
  unsigned long long  __cdecl strtoull(സ്ഥിരം അക്ഷരം* __restrict__, അക്ഷരം** __restrict__, പൂർണ്ണസംഖ്യ);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (സ്ഥിരം അക്ഷരം *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (സ്ഥിരം wchar_t *);
  അക്ഷരം *__cdecl lltoa (long long, അക്ഷരം *, പൂർണ്ണസംഖ്യ);
  അക്ഷരം *__cdecl ulltoa (unsigned long long , അക്ഷരം *, പൂർണ്ണസംഖ്യ);
  wchar_t *__cdecl lltow (long long, wchar_t *, പൂർണ്ണസംഖ്യ);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, പൂർണ്ണസംഖ്യ);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (സ്ഥിരം അക്ഷരം * _c) { തിരികെ _atoi64 (_c); }
  __CRT_INLINE അക്ഷരം *__cdecl lltoa (long long _n, അക്ഷരം * _c, പൂർണ്ണസംഖ്യ _i) { തിരികെ _i64toa (_n, _c, _i); }
  __CRT_INLINE അക്ഷരം *__cdecl ulltoa (unsigned long long _n, അക്ഷരം * _c, പൂർണ്ണസംഖ്യ _i) { തിരികെ _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (സ്ഥിരം wchar_t * _w) { തിരികെ _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, പൂർണ്ണസംഖ്യ _i) { തിരികെ _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, പൂർണ്ണസംഖ്യ _i) { തിരികെ _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)

#അന്തര്ഭാവ <sec_api/stdlib_s.h>
#അന്തര്ഭാവ <malloc.h>

#endif
