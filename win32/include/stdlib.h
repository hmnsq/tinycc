/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#અન્તર્ભાવ <_mingw.h>
#અન્તર્ભાવ <limits.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef ખાલી
#ifdef __cplusplus
#define ખાલી 0
#નહીંતર
#define ખાલી ((શૂન્ય *)0)
#endif
#endif

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED
#define _ONEXIT_T_DEFINED

  પ્રકારવ્યાખ્યા પૂર્ણાંક (__cdecl *_onexit_t)(શૂન્ય);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif
#endif

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED

  પ્રકારવ્યાખ્યા સંરચના _div_t {
    પૂર્ણાંક quot;
    પૂર્ણાંક rem;
  } div_t;

  પ્રકારવ્યાખ્યા સંરચના _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;
#endif

#ifndef _CRT_DOUBLE_DEC
#define _CRT_DOUBLE_DEC

#pragma pack(4)
  પ્રકારવ્યાખ્યા સંરચના {
    unsigned અક્ષર ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned અક્ષર *)(&(x)->ld))

  પ્રકારવ્યાખ્યા સંરચના {
    દ્વિગુણ x;
  } _CRT_DOUBLE;

  પ્રકારવ્યાખ્યા સંરચના {
    દશાંશ f;
  } _CRT_FLOAT;

#pragma ધકેલો_macro("long")
#undef long

  પ્રકારવ્યાખ્યા સંરચના {
    long દ્વિગુણ x;
  } _LONGDOUBLE;

#pragma કાઢો_macro("long")

#pragma pack(4)
  પ્રકારવ્યાખ્યા સંરચના {
    unsigned અક્ષર ld12[12];
  } _LDBL12;
#pragma pack()
#endif

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  બાહ્ય પૂર્ણાંક __mb_cur_max;
#નહીંતર
#define __mb_cur_max    (*_imp____mb_cur_max)
  બાહ્ય પૂર્ણાંક *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
  બાહ્ય પૂર્ણાંક __mbcur_max;
#define ___mb_cur_max_func() (__mb_cur_max)
#નહીંતર
  બાહ્ય પૂર્ણાંક* _imp____mbcur_max;
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

#define WRITE_ABORT_સંદેશ 0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV 32767

  પ્રકારવ્યાખ્યા શૂન્ય (__cdecl *_purecall_handler)(શૂન્ય);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(શૂન્ય);

  પ્રકારવ્યાખ્યા શૂન્ય (__cdecl *_invalid_parameter_handler)(અચલ wchar_t *,અચલ wchar_t *,અચલ wchar_t *,unsigned પૂર્ણાંક,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(શૂન્ય);

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP પૂર્ણાંક *__cdecl _errno(શૂન્ય);
#define errno (*_errno())
  errno_t __cdecl _set_errno(પૂર્ણાંક કિંમત_2);
  errno_t __cdecl _get_errno(પૂર્ણાંક *કિંમત_2);
#endif
  _CRTIMP unsigned long *__cdecl __doserrno(શૂન્ય);
#define _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(unsigned long કિંમત_2);
  errno_t __cdecl _get_doserrno(unsigned long *કિંમત_2);
#ifdef _MSVCRT_
  બાહ્ય અક્ષર *_sys_errlist[];
  બાહ્ય પૂર્ણાંક _sys_nerr;
#નહીંતર
  _CRTIMP અક્ષર *_sys_errlist[1];
  _CRTIMP પૂર્ણાંક _sys_nerr;
#endif
#જો (defined(_X86_) && !defined(__x86_64))
  _CRTIMP પૂર્ણાંક *__cdecl __p___argc(શૂન્ય);
  _CRTIMP અક્ષર ***__cdecl __p___argv(શૂન્ય);
  _CRTIMP wchar_t ***__cdecl __p___wargv(શૂન્ય);
  _CRTIMP અક્ષર ***__cdecl __p__environ(શૂન્ય);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(શૂન્ય);
  _CRTIMP અક્ષર **__cdecl __p__pgmptr(શૂન્ય);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(શૂન્ય);
#endif
#ifndef __argc
#ifdef _MSVCRT_
  બાહ્ય પૂર્ણાંક __argc;
#નહીંતર
#define __argc (*_imp____argc)
  બાહ્ય પૂર્ણાંક *_imp____argc;
#endif
#endif
#ifndef __argv
#ifdef _MSVCRT_
  બાહ્ય અક્ષર **__argv;
#નહીંતર
#define __argv  (*_imp____argv)
  બાહ્ય અક્ષર ***_imp____argv;
#endif
#endif
#ifndef __wargv
#ifdef _MSVCRT_
  બાહ્ય wchar_t **__wargv;
#નહીંતર
#define __wargv (*_imp____wargv)
  બાહ્ય wchar_t ***_imp____wargv;
#endif
#endif

#ifdef _POSIX_
  બાહ્ય અક્ષર **environ;
#નહીંતર
#ifndef _environ
#ifdef _MSVCRT_
  બાહ્ય અક્ષર **_environ;
#નહીંતર
#define _environ (*_imp___environ)
  બાહ્ય અક્ષર ***_imp___environ;
#endif
#endif

#ifndef _wenviron
#ifdef _MSVCRT_
  બાહ્ય wchar_t **_wenviron;
#નહીંતર
#define _wenviron       (*_imp___wenviron)
  બાહ્ય wchar_t ***_imp___wenviron;
#endif
#endif
#endif

#જો defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
બાહ્ય પૂર્ણાંક __argc;
બાહ્ય અક્ષર **__argv;
બાહ્ય wchar_t **__wargv;
બાહ્ય અક્ષર **_environ;
બાહ્ય wchar_t **_wenviron;
#endif

#ifndef _pgmptr
#ifdef _MSVCRT_
  બાહ્ય અક્ષર *_pgmptr;
#નહીંતર
#define _pgmptr (*_imp___pgmptr)
  બાહ્ય અક્ષર **_imp___pgmptr;
#endif
#endif

#ifndef _wpgmptr
#ifdef _MSVCRT_
  બાહ્ય wchar_t *_wpgmptr;
#નહીંતર
#define _wpgmptr        (*_imp___wpgmptr)
  બાહ્ય wchar_t **_imp___wpgmptr;
#endif
#endif
  errno_t __cdecl _get_pgmptr(અક્ષર **કિંમત_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **કિંમત_2);
#ifndef _fmode
#ifdef _MSVCRT_
  બાહ્ય પૂર્ણાંક _fmode;
#નહીંતર
#define _fmode  (*_imp___fmode)
  બાહ્ય પૂર્ણાંક *_imp___fmode;
#endif
#endif
  _CRTIMP errno_t __cdecl _set_fmode(પૂર્ણાંક _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(પૂર્ણાંક *_PMode);

#ifndef _osplatform
#ifdef _MSVCRT_
  બાહ્ય unsigned પૂર્ણાંક _osplatform;
#નહીંતર
#define _osplatform (*_imp___osplatform)
  બાહ્ય unsigned પૂર્ણાંક *_imp___osplatform;
#endif
#endif

#ifndef _osver
#ifdef _MSVCRT_
  બાહ્ય unsigned પૂર્ણાંક _osver;
#નહીંતર
#define _osver  (*_imp___osver)
  બાહ્ય unsigned પૂર્ણાંક *_imp___osver;
#endif
#endif

#ifndef _winver
#ifdef _MSVCRT_
  બાહ્ય unsigned પૂર્ણાંક _winver;
#નહીંતર
#define _winver (*_imp___winver)
  બાહ્ય unsigned પૂર્ણાંક *_imp___winver;
#endif
#endif

#ifndef _winmajor
#ifdef _MSVCRT_
  બાહ્ય unsigned પૂર્ણાંક _winmajor;
#નહીંતર
#define _winmajor       (*_imp___winmajor)
  બાહ્ય unsigned પૂર્ણાંક *_imp___winmajor;
#endif
#endif

#ifndef _winminor
#ifdef _MSVCRT_
  બાહ્ય unsigned પૂર્ણાંક _winminor;
#નહીંતર
#define _winminor       (*_imp___winminor)
  બાહ્ય unsigned પૂર્ણાંક *_imp___winminor;
#endif
#endif

  errno_t __cdecl _get_osplatform(unsigned પૂર્ણાંક *કિંમત_2);
  errno_t __cdecl _get_osver(unsigned પૂર્ણાંક *કિંમત_2);
  errno_t __cdecl _get_winver(unsigned પૂર્ણાંક *કિંમત_2);
  errno_t __cdecl _get_winmajor(unsigned પૂર્ણાંક *કિંમત_2);
  errno_t __cdecl _get_winminor(unsigned પૂર્ણાંક *કિંમત_2);
#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (કદ(_Array) / કદ(_Array[0]))
#નહીંતર
  બાહ્ય "C++" {
    template <typename _CountofType,size_t _SizeOfArray> અક્ષર (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) કદ(*__countof_helper(_Array))
  }
#endif
#endif

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  શૂન્ય __cdecl __MINGW_NOTHROW exit(પૂર્ણાંક _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP શૂન્ય __cdecl __MINGW_NOTHROW _exit(પૂર્ણાંક _Code) __MINGW_ATTRIB_NORETURN;
#જો !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  શૂન્ય __cdecl _Exit(પૂર્ણાંક) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN શૂન્ય  __cdecl _Exit(પૂર્ણાંક status)
  {  _exit(status); }
#endif

#pragma ધકેલો_macro("abort")
#undef abort
  શૂન્ય __cdecl __declspec(noreturn) abort(શૂન્ય);
#pragma કાઢો_macro("abort")

#endif

  _CRTIMP unsigned પૂર્ણાંક __cdecl _set_abort_behavior(unsigned પૂર્ણાંક _Flags,unsigned પૂર્ણાંક _Mask);

#ifndef _CRT_ABS_DEFINED
#define _CRT_ABS_DEFINED
  પૂર્ણાંક __cdecl abs(પૂર્ણાંક _X);
  long __cdecl labs(long _X);
#endif

#જો _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#endif
  પૂર્ણાંક __cdecl atexit(શૂન્ય (__cdecl *)(શૂન્ય));
#ifndef _CRT_ATOF_DEFINED
#define _CRT_ATOF_DEFINED
  દ્વિગુણ __cdecl atof(અચલ અક્ષર *_String);
  દ્વિગુણ __cdecl _atof_l(અચલ અક્ષર *_String,_locale_t _Locale);
#endif
  પૂર્ણાંક __cdecl atoi(અચલ અક્ષર *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _atoi_l(અચલ અક્ષર *_Str,_locale_t _Locale);
  long __cdecl atol(અચલ અક્ષર *_Str);
  _CRTIMP long __cdecl _atol_l(અચલ અક્ષર *_Str,_locale_t _Locale);
#ifndef _CRT_ALGO_DEFINED
#define _CRT_ALGO_DEFINED
  શૂન્ય *__cdecl bsearch(અચલ શૂન્ય *ચાવી_2,અચલ શૂન્ય *_Base,size_t અંક_Of_Elements,size_t _SizeOfElements,પૂર્ણાંક (__cdecl *_PtFuncCompare)(અચલ શૂન્ય *,અચલ શૂન્ય *));
  શૂન્ય __cdecl qsort(શૂન્ય *_Base,size_t અંક_Of_Elements,size_t _SizeOfElements,પૂર્ણાંક (__cdecl *_PtFuncCompare)(અચલ શૂન્ય *,અચલ શૂન્ય *));
#endif
  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#જો _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif
  div_t __cdecl div(પૂર્ણાંક _Numerator,પૂર્ણાંક _Denominator);
  અક્ષર *__cdecl getenv(અચલ અક્ષર *_VarName);
  _CRTIMP અક્ષર *__cdecl _itoa(પૂર્ણાંક કિંમત_2,અક્ષર *_Dest,પૂર્ણાંક _Radix);
#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP અક્ષર *__cdecl _i64toa(__int64 _Val,અક્ષર *_DstBuf,પૂર્ણાંક _Radix);
  _CRTIMP અક્ષર *__cdecl _ui64toa(unsigned __int64 _Val,અક્ષર *_DstBuf,પૂર્ણાંક _Radix);
  _CRTIMP __int64 __cdecl _atoi64(અચલ અક્ષર *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(અચલ અક્ષર *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(અચલ અક્ષર *_String,અક્ષર **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(અચલ અક્ષર *_String,અક્ષર **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _strtoui64(અચલ અક્ષર *_String,અક્ષર **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP unsigned __int64 __cdecl _strtoui64_l(અચલ અક્ષર *_String,અક્ષર **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
#endif
  ldiv_t __cdecl ldiv(long _Numerator,long _Denominator);
  _CRTIMP અક્ષર *__cdecl _ltoa(long કિંમત_2,અક્ષર *_Dest,પૂર્ણાંક _Radix);
  પૂર્ણાંક __cdecl mblen(અચલ અક્ષર *_Ch,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _mblen_l(અચલ અક્ષર *_Ch,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(અચલ અક્ષર *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(અચલ અક્ષર *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(અચલ અક્ષર *_Str,size_t Max_ગણતરી);
  _CRTIMP size_t __cdecl _mbstrnlen_l(અચલ અક્ષર *_Str,size_t Max_ગણતરી,_locale_t _Locale);
  પૂર્ણાંક __cdecl mbtowc(wchar_t *_DstCh,અચલ અક્ષર *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP પૂર્ણાંક __cdecl _mbtowc_l(wchar_t *_DstCh,અચલ અક્ષર *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,અચલ અક્ષર *_Source,size_t Max_ગણતરી);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,અચલ અક્ષર *_Source,size_t Max_ગણતરી,_locale_t _Locale);
  પૂર્ણાંક __cdecl rand(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _set_error_mode(પૂર્ણાંક _Mode);
  શૂન્ય __cdecl srand(unsigned પૂર્ણાંક _Seed);
  દ્વિગુણ __cdecl strtod(અચલ અક્ષર *_Str,અક્ષર **_EndPtr);
#જો !defined __NO_ISOCEXT  /* in libmingwex.a */
#જો __TINYC__
  __CRT_INLINE દશાંશ __cdecl strtof (અચલ અક્ષર *p, અક્ષર ** e) { પાછા strtod(p, e); }
  __CRT_INLINE long દ્વિગુણ __cdecl strtold(અચલ અક્ષર *p, અક્ષર ** e) { પાછા strtod(p, e); }
#નહીંતર
  દશાંશ __cdecl strtof (અચલ અક્ષર * __restrict__, અક્ષર ** __restrict__);
  long દ્વિગુણ __cdecl strtold(અચલ અક્ષર * __restrict__, અક્ષર ** __restrict__);
#endif
#નહીંતર
  દશાંશ __cdecl strtof(અચલ અક્ષર *nptr, અક્ષર **endptr);
#endif /* __NO_ISOCEXT */
  _CRTIMP દ્વિગુણ __cdecl _strtod_l(અચલ અક્ષર *_Str,અક્ષર **_EndPtr,_locale_t _Locale);
  long __cdecl strtol(અચલ અક્ષર *_Str,અક્ષર **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP long __cdecl _strtol_l(અચલ અક્ષર *_Str,અક્ષર **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  unsigned long __cdecl strtoul(અચલ અક્ષર *_Str,અક્ષર **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(અચલ અક્ષર *_Str,અક્ષર **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  પૂર્ણાંક __cdecl system(અચલ અક્ષર *_Command);
#endif
  _CRTIMP અક્ષર *__cdecl _ultoa(unsigned long કિંમત_2,અક્ષર *_Dest,પૂર્ણાંક _Radix);
  પૂર્ણાંક __cdecl wctomb(અક્ષર *_MbCh,wchar_t _WCh);
  _CRTIMP પૂર્ણાંક __cdecl _wctomb_l(અક્ષર *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(અક્ષર *_Dest,અચલ wchar_t *_Source,size_t Max_ગણતરી);
  _CRTIMP size_t __cdecl _wcstombs_l(અક્ષર *_Dest,અચલ wchar_t *_Source,size_t Max_ગણતરી,_locale_t _Locale);

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  શૂન્ય *__cdecl calloc(size_t અંક_Of_Elements,size_t _SizeOfElements);
  શૂન્ય __cdecl મુક્ત(શૂન્ય *_Memory);
  શૂન્ય *__cdecl malloc(size_t _Size);
  શૂન્ય *__cdecl realloc(શૂન્ય *_Memory,size_t _NewSize);
  _CRTIMP શૂન્ય *__cdecl _recalloc(શૂન્ય *_Memory,size_t ગણતરી_5,size_t _Size);
  _CRTIMP શૂન્ય __cdecl _aligned_free(શૂન્ય *_Memory);
  _CRTIMP શૂન્ય *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP શૂન્ય *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP શૂન્ય *__cdecl _aligned_realloc(શૂન્ય *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP શૂન્ય *__cdecl _aligned_recalloc(શૂન્ય *_Memory,size_t ગણતરી_5,size_t _Size,size_t _Alignment);
  _CRTIMP શૂન્ય *__cdecl _aligned_offset_realloc(શૂન્ય *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP શૂન્ય *__cdecl _aligned_offset_recalloc(શૂન્ય *_Memory,size_t ગણતરી_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#ifndef _WSTDLIB_DEFINED
#define _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(પૂર્ણાંક કિંમત_2,wchar_t *_Dest,પૂર્ણાંક _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(long કિંમત_2,wchar_t *_Dest,પૂર્ણાંક _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long કિંમત_2,wchar_t *_Dest,પૂર્ણાંક _Radix);
  દ્વિગુણ __cdecl wcstod(અચલ wchar_t *_Str,wchar_t **_EndPtr);
  દશાંશ __cdecl wcstof(અચલ wchar_t *nptr, wchar_t **endptr);
#જો !defined __NO_ISOCEXT /* in libmingwex.a */
  દશાંશ __cdecl wcstof( અચલ wchar_t * __restrict__, wchar_t ** __restrict__);
  long દ્વિગુણ __cdecl wcstold(અચલ wchar_t * __restrict__, wchar_t ** __restrict__);
#endif /* __NO_ISOCEXT */
  _CRTIMP દ્વિગુણ __cdecl _wcstod_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  long __cdecl wcstol(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP long __cdecl _wcstol_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  unsigned long __cdecl wcstoul(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP unsigned long __cdecl _wcstoul_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(અચલ wchar_t *_VarName);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP પૂર્ણાંક __cdecl _wsystem(અચલ wchar_t *_Command);
#endif
  _CRTIMP દ્વિગુણ __cdecl _wtof(અચલ wchar_t *_Str);
  _CRTIMP દ્વિગુણ __cdecl _wtof_l(અચલ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wtoi(અચલ wchar_t *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _wtoi_l(અચલ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP long __cdecl _wtol(અચલ wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(અચલ wchar_t *_Str,_locale_t _Locale);

#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,પૂર્ણાંક _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val,wchar_t *_DstBuf,પૂર્ણાંક _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(અચલ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(અચલ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64(અચલ wchar_t *_Str,wchar_t **_EndPtr,પૂર્ણાંક _Radix);
  _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(અચલ wchar_t *_Str ,wchar_t **_EndPtr,પૂર્ણાંક _Radix,_locale_t _Locale);
#endif
#endif

#ifndef _POSIX_
#define _CVTBUFSIZE (309+40)
  _CRTIMP અક્ષર *__cdecl _fullpath(અક્ષર *_FullPath,અચલ અક્ષર *_Path,size_t _SizeInBytes);
  _CRTIMP અક્ષર *__cdecl _ecvt(દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Digits,પૂર્ણાંક *_PtDec,પૂર્ણાંક *_PtSign);
  _CRTIMP અક્ષર *__cdecl _fcvt(દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Dec,પૂર્ણાંક *_PtDec,પૂર્ણાંક *_PtSign);
  _CRTIMP અક્ષર *__cdecl _gcvt(દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Digits,અક્ષર *_DstBuf);
  _CRTIMP પૂર્ણાંક __cdecl _atodbl(_CRT_DOUBLE *_Result,અક્ષર *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _atoldbl(_LDOUBLE *_Result,અક્ષર *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _atoflt(_CRT_FLOAT *_Result,અક્ષર *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _atodbl_l(_CRT_DOUBLE *_Result,અક્ષર *_Str,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _atoldbl_l(_LDOUBLE *_Result,અક્ષર *_Str,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _atoflt_l(_CRT_FLOAT *_Result,અક્ષર *_Str,_locale_t _Locale);
  unsigned long __cdecl _lrotl(unsigned long _Val,પૂર્ણાંક _Shift);
  unsigned long __cdecl _lrotr(unsigned long _Val,પૂર્ણાંક _Shift);
  _CRTIMP શૂન્ય __cdecl _makepath(અક્ષર *_Path,અચલ અક્ષર *_Drive,અચલ અક્ષર *_Dir,અચલ અક્ષર *_Filename,અચલ અક્ષર *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  શૂન્ય __cdecl perror(અચલ અક્ષર *Err_સંદેશ);
#endif
  _CRTIMP પૂર્ણાંક __cdecl _putenv(અચલ અક્ષર *_EnvString);
  unsigned પૂર્ણાંક __cdecl _rotl(unsigned પૂર્ણાંક _Val,પૂર્ણાંક _Shift);
#જો _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val,પૂર્ણાંક _Shift);
#endif
  unsigned પૂર્ણાંક __cdecl _rotr(unsigned પૂર્ણાંક _Val,પૂર્ણાંક _Shift);
#જો _INTEGRAL_MAX_BITS >= 64
  unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val,પૂર્ણાંક _Shift);
#endif
  _CRTIMP શૂન્ય __cdecl _searchenv(અચલ અક્ષર *_Filename,અચલ અક્ષર *_EnvVar,અક્ષર *_ResultPath);
  _CRTIMP શૂન્ય __cdecl _splitpath(અચલ અક્ષર *_FullPath,અક્ષર *_Drive,અક્ષર *_Dir,અક્ષર *_Filename,અક્ષર *_Ext);
  _CRTIMP શૂન્ય __cdecl _swab(અક્ષર *_Buf1,અક્ષર *_Buf2,પૂર્ણાંક _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
#define _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,અચલ wchar_t *_Path,size_t Size_In_શબ્દો);
  _CRTIMP શૂન્ય __cdecl _wmakepath(wchar_t *_ResultPath,અચલ wchar_t *_Drive,અચલ wchar_t *_Dir,અચલ wchar_t *_Filename,અચલ wchar_t *_Ext);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP શૂન્ય __cdecl _wperror(અચલ wchar_t *Err_સંદેશ);
#endif
  _CRTIMP પૂર્ણાંક __cdecl _wputenv(અચલ wchar_t *_EnvString);
  _CRTIMP શૂન્ય __cdecl _wsearchenv(અચલ wchar_t *_Filename,અચલ wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP શૂન્ય __cdecl _wsplitpath(અચલ wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#endif

  _CRTIMP શૂન્ય __cdecl _beep(unsigned _Frequency,unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP શૂન્ય __cdecl _seterrormode(પૂર્ણાંક _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP શૂન્ય __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;
#endif

#ifndef NO_OLDNAMES
#ifndef _POSIX_
#જો 0
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
  અક્ષર *__cdecl ecvt(દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Digits,પૂર્ણાંક *_PtDec,પૂર્ણાંક *_PtSign);
  અક્ષર *__cdecl fcvt(દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Dec,પૂર્ણાંક *_PtDec,પૂર્ણાંક *_PtSign);
  અક્ષર *__cdecl gcvt(દ્વિગુણ _Val,પૂર્ણાંક અંક_Of_Digits,અક્ષર *_DstBuf);
  અક્ષર *__cdecl itoa(પૂર્ણાંક _Val,અક્ષર *_DstBuf,પૂર્ણાંક _Radix);
  અક્ષર *__cdecl ltoa(long _Val,અક્ષર *_DstBuf,પૂર્ણાંક _Radix);
  પૂર્ણાંક __cdecl putenv(અચલ અક્ષર *_EnvString);
  શૂન્ય __cdecl swab(અક્ષર *_Buf1,અક્ષર *_Buf2,પૂર્ણાંક _SizeInBytes);
  અક્ષર *__cdecl ultoa(unsigned long _Val,અક્ષર *_Dstbuf,પૂર્ણાંક _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#endif
#endif

#જો !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  પ્રકારવ્યાખ્યા સંરચના { long long quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(long long, long long);

  __CRT_INLINE long long __cdecl llabs(long long _j) { પાછા (_j >= 0 ? _j : -_j); }

 #ifdef __TINYC__ /* gr */
  #define strtoll _strtoi64
  #define strtoull _strtoui64
 #નહીંતર
  long long  __cdecl strtoll(અચલ અક્ષર* __restrict__, અક્ષર** __restrict, પૂર્ણાંક);
  unsigned long long  __cdecl strtoull(અચલ અક્ષર* __restrict__, અક્ષર** __restrict__, પૂર્ણાંક);
 #endif

  /* these are stubs for MS _i64 versions */
  long long  __cdecl atoll (અચલ અક્ષર *);

#ifndef __STRICT_ANSI__
  long long  __cdecl wtoll (અચલ wchar_t *);
  અક્ષર *__cdecl lltoa (long long, અક્ષર *, પૂર્ણાંક);
  અક્ષર *__cdecl ulltoa (unsigned long long , અક્ષર *, પૂર્ણાંક);
  wchar_t *__cdecl lltow (long long, wchar_t *, પૂર્ણાંક);
  wchar_t *__cdecl ulltow (unsigned long long, wchar_t *, પૂર્ણાંક);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE long long  __cdecl atoll (અચલ અક્ષર * _c) { પાછા _atoi64 (_c); }
  __CRT_INLINE અક્ષર *__cdecl lltoa (long long _n, અક્ષર * _c, પૂર્ણાંક _i) { પાછા _i64toa (_n, _c, _i); }
  __CRT_INLINE અક્ષર *__cdecl ulltoa (unsigned long long _n, અક્ષર * _c, પૂર્ણાંક _i) { પાછા _ui64toa (_n, _c, _i); }
  __CRT_INLINE long long  __cdecl wtoll (અચલ wchar_t * _w) { પાછા _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (long long _n, wchar_t * _w, પૂર્ણાંક _i) { પાછા _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (unsigned long long _n, wchar_t * _w, પૂર્ણાંક _i) { પાછા _ui64tow (_n, _w, _i); }
#endif /* (__STRICT_ANSI__)  */

#endif /* !__NO_ISOCEXT */

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)

#અન્તર્ભાવ <sec_api/stdlib_s.h>
#અન્તર્ભાવ <malloc.h>

#endif
