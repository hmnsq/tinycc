/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_STDLIB
#నిర్వచించు _INC_STDLIB

#అన్తర్భావ <_mingw.h>
#అన్తర్భావ <limits.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు EXIT_SUCCESS 0
#నిర్వచించు EXIT_FAILURE 1

#నిర్వచితం_కాకపోతే _ONEXIT_T_DEFINED
#నిర్వచించు _ONEXIT_T_DEFINED

  రకనిర్వచనం పూర్ణాంకం (__cdecl *_onexit_t)(శూన్య);

#నిర్వచితం_కాకపోతే NO_OLDNAMES
#నిర్వచించు onexit_t _onexit_t
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _DIV_T_DEFINED
#నిర్వచించు _DIV_T_DEFINED

  రకనిర్వచనం నిర్మాణం _div_t {
    పూర్ణాంకం quot;
    పూర్ణాంకం rem;
  } div_t;

  రకనిర్వచనం నిర్మాణం _ldiv_t {
    దీర్ఘ quot;
    దీర్ఘ rem;
  } ldiv_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_DOUBLE_DEC
#నిర్వచించు _CRT_DOUBLE_DEC

#సూచన pack(4)
  రకనిర్వచనం నిర్మాణం {
    గుర్తులేని అక్షరం ld[10];
  } _LDOUBLE;
#సూచన pack()

#నిర్వచించు _PTR_LD(x) ((గుర్తులేని అక్షరం *)(&(x)->ld))

  రకనిర్వచనం నిర్మాణం {
    ద్విగుణ x;
  } _CRT_DOUBLE;

  రకనిర్వచనం నిర్మాణం {
    దశాంశం f;
  } _CRT_FLOAT;

#సూచన నెట్టు_macro("long")
#నిర్వచనం_రద్దు దీర్ఘ

  రకనిర్వచనం నిర్మాణం {
    దీర్ఘ ద్విగుణ x;
  } _LONGDOUBLE;

#సూచన తీయి_macro("long")

#సూచన pack(4)
  రకనిర్వచనం నిర్మాణం {
    గుర్తులేని అక్షరం ld12[12];
  } _LDBL12;
#సూచన pack()
#అయితే_ముగింపు

#నిర్వచించు RAND_MAX 0x7fff

#నిర్వచితం_కాకపోతే MB_CUR_MAX
#నిర్వచించు MB_CUR_MAX ___mb_cur_max_func()
#నిర్వచితం_కాకపోతే __mb_cur_max
#నిర్వచితమైతే _MSVCRT_
  బాహ్య పూర్ణాంకం __mb_cur_max;
#లేకపోతే
#నిర్వచించు __mb_cur_max    (*_imp____mb_cur_max)
  బాహ్య పూర్ణాంకం *_imp____mb_cur_max;
#అయితే_ముగింపు
#అయితే_ముగింపు
#నిర్వచితమైతే _MSVCRT_
  బాహ్య పూర్ణాంకం __mbcur_max;
#నిర్వచించు ___mb_cur_max_func() (__mb_cur_max)
#లేకపోతే
  బాహ్య పూర్ణాంకం* _imp____mbcur_max;
#నిర్వచించు ___mb_cur_max_func() (*_imp____mb_cur_max)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు __max(a,b) (((a) > (b)) ? (a) : (b))
#నిర్వచించు __min(a,b) (((a) < (b)) ? (a) : (b))

#నిర్వచించు MAX_మార్గం_2 260
#నిర్వచించు _MAX_DRIVE 3
#నిర్వచించు _MAX_DIR 256
#నిర్వచించు _MAX_FNAME 256
#నిర్వచించు _MAX_EXT 256

#నిర్వచించు బహిర్గతం_గమ్యం_DEFAULT 0
#నిర్వచించు బహిర్గతం_గమ్యం_STDERR 1
#నిర్వచించు బహిర్గతం_గమ్యం_MSGBOX 2
#నిర్వచించు _REPORT_ERRMODE 3

#నిర్వచించు WRITE_ABORT_సందేశం 0x1
#నిర్వచించు _CALL_REPORTFAULT 0x2

#నిర్వచించు _MAX_ENV 32767

  రకనిర్వచనం శూన్య (__cdecl *_purecall_handler)(శూన్య);

  _CRTIMP _purecall_handler __cdecl సమితి_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(శూన్య);

  రకనిర్వచనం శూన్య (__cdecl *_invalid_parameter_handler)(స్థిరరాశి wchar_t *,స్థిరరాశి wchar_t *,స్థిరరాశి wchar_t *,గుర్తులేని పూర్ణాంకం,uintptr_t);
  _invalid_parameter_handler __cdecl సమితి_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(శూన్య);

#నిర్వచితం_కాకపోతే _CRT_ERRNO_DEFINED
#నిర్వచించు _CRT_ERRNO_DEFINED
  _CRTIMP పూర్ణాంకం *__cdecl _errno(శూన్య);
#నిర్వచించు errno (*_errno())
  errno_t __cdecl సమితి_errno(పూర్ణాంకం విలువ_2);
  errno_t __cdecl _get_errno(పూర్ణాంకం *విలువ_2);
#అయితే_ముగింపు
  _CRTIMP గుర్తులేని దీర్ఘ *__cdecl __doserrno(శూన్య);
#నిర్వచించు _doserrno (*__doserrno())
  errno_t __cdecl సమితి_doserrno(గుర్తులేని దీర్ఘ విలువ_2);
  errno_t __cdecl _get_doserrno(గుర్తులేని దీర్ఘ *విలువ_2);
#నిర్వచితమైతే _MSVCRT_
  బాహ్య అక్షరం *_sys_errlist[];
  బాహ్య పూర్ణాంకం _sys_nerr;
#లేకపోతే
  _CRTIMP అక్షరం *_sys_errlist[1];
  _CRTIMP పూర్ణాంకం _sys_nerr;
#అయితే_ముగింపు
#ఒకవేళ (defined(_X86_) && !defined(__x86_64))
  _CRTIMP పూర్ణాంకం *__cdecl __p___argc(శూన్య);
  _CRTIMP అక్షరం ***__cdecl __p___argv(శూన్య);
  _CRTIMP wchar_t ***__cdecl __p___wargv(శూన్య);
  _CRTIMP అక్షరం ***__cdecl __p__environ(శూన్య);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(శూన్య);
  _CRTIMP అక్షరం **__cdecl __p__pgmptr(శూన్య);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(శూన్య);
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే __argc
#నిర్వచితమైతే _MSVCRT_
  బాహ్య పూర్ణాంకం __argc;
#లేకపోతే
#నిర్వచించు __argc (*_imp____argc)
  బాహ్య పూర్ణాంకం *_imp____argc;
#అయితే_ముగింపు
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే __argv
#నిర్వచితమైతే _MSVCRT_
  బాహ్య అక్షరం **__argv;
#లేకపోతే
#నిర్వచించు __argv  (*_imp____argv)
  బాహ్య అక్షరం ***_imp____argv;
#అయితే_ముగింపు
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే __wargv
#నిర్వచితమైతే _MSVCRT_
  బాహ్య wchar_t **__wargv;
#లేకపోతే
#నిర్వచించు __wargv (*_imp____wargv)
  బాహ్య wchar_t ***_imp____wargv;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే _POSIX_
  బాహ్య అక్షరం **environ;
#లేకపోతే
#నిర్వచితం_కాకపోతే _environ
#నిర్వచితమైతే _MSVCRT_
  బాహ్య అక్షరం **_environ;
#లేకపోతే
#నిర్వచించు _environ (*_imp___environ)
  బాహ్య అక్షరం ***_imp___environ;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _wenviron
#నిర్వచితమైతే _MSVCRT_
  బాహ్య wchar_t **_wenviron;
#లేకపోతే
#నిర్వచించు _wenviron       (*_imp___wenviron)
  బాహ్య wchar_t ***_imp___wenviron;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
బాహ్య పూర్ణాంకం __argc;
బాహ్య అక్షరం **__argv;
బాహ్య wchar_t **__wargv;
బాహ్య అక్షరం **_environ;
బాహ్య wchar_t **_wenviron;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _pgmptr
#నిర్వచితమైతే _MSVCRT_
  బాహ్య అక్షరం *_pgmptr;
#లేకపోతే
#నిర్వచించు _pgmptr (*_imp___pgmptr)
  బాహ్య అక్షరం **_imp___pgmptr;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _wpgmptr
#నిర్వచితమైతే _MSVCRT_
  బాహ్య wchar_t *_wpgmptr;
#లేకపోతే
#నిర్వచించు _wpgmptr        (*_imp___wpgmptr)
  బాహ్య wchar_t **_imp___wpgmptr;
#అయితే_ముగింపు
#అయితే_ముగింపు
  errno_t __cdecl _get_pgmptr(అక్షరం **విలువ_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **విలువ_2);
#నిర్వచితం_కాకపోతే _fmode
#నిర్వచితమైతే _MSVCRT_
  బాహ్య పూర్ణాంకం _fmode;
#లేకపోతే
#నిర్వచించు _fmode  (*_imp___fmode)
  బాహ్య పూర్ణాంకం *_imp___fmode;
#అయితే_ముగింపు
#అయితే_ముగింపు
  _CRTIMP errno_t __cdecl సమితి_fmode(పూర్ణాంకం బహుళకం_3);
  _CRTIMP errno_t __cdecl _get_fmode(పూర్ణాంకం *_PMode);

#నిర్వచితం_కాకపోతే _osplatform
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పూర్ణాంకం _osplatform;
#లేకపోతే
#నిర్వచించు _osplatform (*_imp___osplatform)
  బాహ్య గుర్తులేని పూర్ణాంకం *_imp___osplatform;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _osver
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పూర్ణాంకం _osver;
#లేకపోతే
#నిర్వచించు _osver  (*_imp___osver)
  బాహ్య గుర్తులేని పూర్ణాంకం *_imp___osver;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _winver
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పూర్ణాంకం _winver;
#లేకపోతే
#నిర్వచించు _winver (*_imp___winver)
  బాహ్య గుర్తులేని పూర్ణాంకం *_imp___winver;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _winmajor
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పూర్ణాంకం _winmajor;
#లేకపోతే
#నిర్వచించు _winmajor       (*_imp___winmajor)
  బాహ్య గుర్తులేని పూర్ణాంకం *_imp___winmajor;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _winminor
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పూర్ణాంకం _winminor;
#లేకపోతే
#నిర్వచించు _winminor       (*_imp___winminor)
  బాహ్య గుర్తులేని పూర్ణాంకం *_imp___winminor;
#అయితే_ముగింపు
#అయితే_ముగింపు

  errno_t __cdecl _get_osplatform(గుర్తులేని పూర్ణాంకం *విలువ_2);
  errno_t __cdecl _get_osver(గుర్తులేని పూర్ణాంకం *విలువ_2);
  errno_t __cdecl _get_winver(గుర్తులేని పూర్ణాంకం *విలువ_2);
  errno_t __cdecl _get_winmajor(గుర్తులేని పూర్ణాంకం *విలువ_2);
  errno_t __cdecl _get_winminor(గుర్తులేని పూర్ణాంకం *విలువ_2);
#నిర్వచితం_కాకపోతే _countof
#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచించు _countof(_Array) (పరిమాణం(_Array) / పరిమాణం(_Array[0]))
#లేకపోతే
  బాహ్య "C++" {
    మూస <typename _CountofType,కొలత_t కొలత_యొక్క_Array> అక్షరం (*__countof_helper(UNALIGNED _CountofType (&_Array)[కొలత_యొక్క_Array]))[కొలత_యొక్క_Array];
#నిర్వచించు _countof(_Array) పరిమాణం(*__countof_helper(_Array))
  }
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_TERMINATE_DEFINED
#నిర్వచించు _CRT_TERMINATE_DEFINED
  శూన్య __cdecl __MINGW_NOTHROW నిష్క్రమించు(పూర్ణాంకం సంకేతం_4) __MINGW_ATTRIB_NORETURN;
  _CRTIMP శూన్య __cdecl __MINGW_NOTHROW _exit(పూర్ణాంకం సంకేతం_4) __MINGW_ATTRIB_NORETURN;
#ఒకవేళ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  శూన్య __cdecl _Exit(పూర్ణాంకం) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN శూన్య  __cdecl _Exit(పూర్ణాంకం స్థితి_2)
  {  _exit(స్థితి_2); }
#అయితే_ముగింపు

#సూచన నెట్టు_macro("abort")
#నిర్వచనం_రద్దు abort
  శూన్య __cdecl __declspec(noreturn) abort(శూన్య);
#సూచన తీయి_macro("abort")

#అయితే_ముగింపు

  _CRTIMP గుర్తులేని పూర్ణాంకం __cdecl సమితి_abort_behavior(గుర్తులేని పూర్ణాంకం _Flags,గుర్తులేని పూర్ణాంకం ముసుగు_2);

#నిర్వచితం_కాకపోతే _CRT_ABS_DEFINED
#నిర్వచించు _CRT_ABS_DEFINED
  పూర్ణాంకం __cdecl నిరపేక్ష(పూర్ణాంకం _X);
  దీర్ఘ __cdecl labs(దీర్ఘ _X);
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  __int64 __cdecl _abs64(__int64);
#అయితే_ముగింపు
  పూర్ణాంకం __cdecl atexit(శూన్య (__cdecl *)(శూన్య));
#నిర్వచితం_కాకపోతే _CRT_ATOF_DEFINED
#నిర్వచించు _CRT_ATOF_DEFINED
  ద్విగుణ __cdecl atof(స్థిరరాశి అక్షరం *_String);
  ద్విగుణ __cdecl _atof_l(స్థిరరాశి అక్షరం *_String,_locale_t _Locale);
#అయితే_ముగింపు
  పూర్ణాంకం __cdecl atoi(స్థిరరాశి అక్షరం *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _atoi_l(స్థిరరాశి అక్షరం *_Str,_locale_t _Locale);
  దీర్ఘ __cdecl atol(స్థిరరాశి అక్షరం *_Str);
  _CRTIMP దీర్ఘ __cdecl _atol_l(స్థిరరాశి అక్షరం *_Str,_locale_t _Locale);
#నిర్వచితం_కాకపోతే _CRT_ALGO_DEFINED
#నిర్వచించు _CRT_ALGO_DEFINED
  శూన్య *__cdecl bsearch(స్థిరరాశి శూన్య *కీలకం_2,స్థిరరాశి శూన్య *పునాది_3,కొలత_t అంకె_యొక్క_Elements,కొలత_t కొలత_యొక్క_Elements,పూర్ణాంకం (__cdecl *_PtFuncCompare)(స్థిరరాశి శూన్య *,స్థిరరాశి శూన్య *));
  శూన్య __cdecl qsort(శూన్య *పునాది_3,కొలత_t అంకె_యొక్క_Elements,కొలత_t కొలత_యొక్క_Elements,పూర్ణాంకం (__cdecl *_PtFuncCompare)(స్థిరరాశి శూన్య *,స్థిరరాశి శూన్య *));
#అయితే_ముగింపు
  గుర్తులేని పొట్టి __cdecl _byteswap_ushort(గుర్తులేని పొట్టి _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  గుర్తులేని __int64 __cdecl _byteswap_uint64(గుర్తులేని __int64 _Int64);
#అయితే_ముగింపు
  div_t __cdecl div(పూర్ణాంకం _Numerator,పూర్ణాంకం _Denominator);
  అక్షరం *__cdecl getenv(స్థిరరాశి అక్షరం *_VarName);
  _CRTIMP అక్షరం *__cdecl _itoa(పూర్ణాంకం విలువ_2,అక్షరం *_Dest,పూర్ణాంకం _Radix);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP అక్షరం *__cdecl _i64toa(__int64 _Val,అక్షరం *_DstBuf,పూర్ణాంకం _Radix);
  _CRTIMP అక్షరం *__cdecl _ui64toa(గుర్తులేని __int64 _Val,అక్షరం *_DstBuf,పూర్ణాంకం _Radix);
  _CRTIMP __int64 __cdecl _atoi64(స్థిరరాశి అక్షరం *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(స్థిరరాశి అక్షరం *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(స్థిరరాశి అక్షరం *_String,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(స్థిరరాశి అక్షరం *_String,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  _CRTIMP గుర్తులేని __int64 __cdecl _strtoui64(స్థిరరాశి అక్షరం *_String,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP గుర్తులేని __int64 __cdecl _strtoui64_l(స్థిరరాశి అక్షరం *_String,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
#అయితే_ముగింపు
  ldiv_t __cdecl ldiv(దీర్ఘ _Numerator,దీర్ఘ _Denominator);
  _CRTIMP అక్షరం *__cdecl _ltoa(దీర్ఘ విలువ_2,అక్షరం *_Dest,పూర్ణాంకం _Radix);
  పూర్ణాంకం __cdecl mblen(స్థిరరాశి అక్షరం *_Ch,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _mblen_l(స్థిరరాశి అక్షరం *_Ch,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP కొలత_t __cdecl _mbstrlen(స్థిరరాశి అక్షరం *_Str);
  _CRTIMP కొలత_t __cdecl _mbstrlen_l(స్థిరరాశి అక్షరం *_Str,_locale_t _Locale);
  _CRTIMP కొలత_t __cdecl _mbstrnlen(స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _mbstrnlen_l(స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క,_locale_t _Locale);
  పూర్ణాంకం __cdecl mbtowc(wchar_t *_DstCh,స్థిరరాశి అక్షరం *_SrcCh,కొలత_t Src_కొలత_లోపల_బైట్లు);
  _CRTIMP పూర్ణాంకం __cdecl _mbtowc_l(wchar_t *_DstCh,స్థిరరాశి అక్షరం *_SrcCh,కొలత_t Src_కొలత_లోపల_బైట్లు,_locale_t _Locale);
  కొలత_t __cdecl mbstowcs(wchar_t *_Dest,స్థిరరాశి అక్షరం *ఆధారం_3,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _mbstowcs_l(wchar_t *_Dest,స్థిరరాశి అక్షరం *ఆధారం_3,కొలత_t Max_లెక్క,_locale_t _Locale);
  పూర్ణాంకం __cdecl rand(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl సమితి_error_బహుళకం(పూర్ణాంకం బహుళకం_3);
  శూన్య __cdecl srand(గుర్తులేని పూర్ణాంకం విత్తనం);
  ద్విగుణ __cdecl strtod(స్థిరరాశి అక్షరం *_Str,అక్షరం **చివర_Ptr);
#ఒకవేళ !defined __NO_ISOCEXT  /* in libmingwex.a */
#ఒకవేళ __TINYC__
  __CRT_INLINE దశాంశం __cdecl strtof (స్థిరరాశి అక్షరం *p, అక్షరం ** e) { తిరిగి strtod(p, e); }
  __CRT_INLINE దీర్ఘ ద్విగుణ __cdecl strtold(స్థిరరాశి అక్షరం *p, అక్షరం ** e) { తిరిగి strtod(p, e); }
#లేకపోతే
  దశాంశం __cdecl strtof (స్థిరరాశి అక్షరం * __restrict__, అక్షరం ** __restrict__);
  దీర్ఘ ద్విగుణ __cdecl strtold(స్థిరరాశి అక్షరం * __restrict__, అక్షరం ** __restrict__);
#అయితే_ముగింపు
#లేకపోతే
  దశాంశం __cdecl strtof(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr);
#అయితే_ముగింపు /* __NO_ISOCEXT */
  _CRTIMP ద్విగుణ __cdecl _strtod_l(స్థిరరాశి అక్షరం *_Str,అక్షరం **చివర_Ptr,_locale_t _Locale);
  దీర్ఘ __cdecl strtol(స్థిరరాశి అక్షరం *_Str,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP దీర్ఘ __cdecl _strtol_l(స్థిరరాశి అక్షరం *_Str,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  గుర్తులేని దీర్ఘ __cdecl strtoul(స్థిరరాశి అక్షరం *_Str,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP గుర్తులేని దీర్ఘ __cdecl _strtoul_l(స్థిరరాశి అక్షరం *_Str,అక్షరం **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
#నిర్వచితం_కాకపోతే _CRT_SYSTEM_DEFINED
#నిర్వచించు _CRT_SYSTEM_DEFINED
  పూర్ణాంకం __cdecl system(స్థిరరాశి అక్షరం *_Command);
#అయితే_ముగింపు
  _CRTIMP అక్షరం *__cdecl _ultoa(గుర్తులేని దీర్ఘ విలువ_2,అక్షరం *_Dest,పూర్ణాంకం _Radix);
  పూర్ణాంకం __cdecl wctomb(అక్షరం *_MbCh,wchar_t _WCh);
  _CRTIMP పూర్ణాంకం __cdecl _wctomb_l(అక్షరం *_MbCh,wchar_t _WCh,_locale_t _Locale);
  కొలత_t __cdecl wcstombs(అక్షరం *_Dest,స్థిరరాశి wchar_t *ఆధారం_3,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _wcstombs_l(అక్షరం *_Dest,స్థిరరాశి wchar_t *ఆధారం_3,కొలత_t Max_లెక్క,_locale_t _Locale);

#నిర్వచితం_కాకపోతే CRT_కేటాయింపు_DEFINED
#నిర్వచించు CRT_కేటాయింపు_DEFINED
  శూన్య *__cdecl సున్నా_జ్ఞాపకం_ఇవ్వు(కొలత_t అంకె_యొక్క_Elements,కొలత_t కొలత_యొక్క_Elements);
  శూన్య __cdecl విడుదల(శూన్య *జ్ఞాపకం);
  శూన్య *__cdecl జ్ఞాపకం_ఇవ్వు(కొలత_t కొలత_4);
  శూన్య *__cdecl realloc(శూన్య *జ్ఞాపకం,కొలత_t New_కొలత);
  _CRTIMP శూన్య *__cdecl _recalloc(శూన్య *జ్ఞాపకం,కొలత_t లెక్క_5,కొలత_t కొలత_4);
  _CRTIMP శూన్య __cdecl _aligned_free(శూన్య *జ్ఞాపకం);
  _CRTIMP శూన్య *__cdecl _aligned_malloc(కొలత_t కొలత_4,కొలత_t _Alignment);
  _CRTIMP శూన్య *__cdecl aligned_స్థానభ్రంశం_malloc(కొలత_t కొలత_4,కొలత_t _Alignment,కొలత_t స్థానభ్రంశం_2);
  _CRTIMP శూన్య *__cdecl _aligned_realloc(శూన్య *జ్ఞాపకం,కొలత_t కొలత_4,కొలత_t _Alignment);
  _CRTIMP శూన్య *__cdecl _aligned_recalloc(శూన్య *జ్ఞాపకం,కొలత_t లెక్క_5,కొలత_t కొలత_4,కొలత_t _Alignment);
  _CRTIMP శూన్య *__cdecl aligned_స్థానభ్రంశం_realloc(శూన్య *జ్ఞాపకం,కొలత_t కొలత_4,కొలత_t _Alignment,కొలత_t స్థానభ్రంశం_2);
  _CRTIMP శూన్య *__cdecl aligned_స్థానభ్రంశం_recalloc(శూన్య *జ్ఞాపకం,కొలత_t లెక్క_5,కొలత_t కొలత_4,కొలత_t _Alignment,కొలత_t స్థానభ్రంశం_2);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTDLIB_DEFINED
#నిర్వచించు _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(పూర్ణాంకం విలువ_2,wchar_t *_Dest,పూర్ణాంకం _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(దీర్ఘ విలువ_2,wchar_t *_Dest,పూర్ణాంకం _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(గుర్తులేని దీర్ఘ విలువ_2,wchar_t *_Dest,పూర్ణాంకం _Radix);
  ద్విగుణ __cdecl wcstod(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr);
  దశాంశం __cdecl wcstof(స్థిరరాశి wchar_t *nptr, wchar_t **endptr);
#ఒకవేళ !defined __NO_ISOCEXT /* in libmingwex.a */
  దశాంశం __cdecl wcstof( స్థిరరాశి wchar_t * __restrict__, wchar_t ** __restrict__);
  దీర్ఘ ద్విగుణ __cdecl wcstold(స్థిరరాశి wchar_t * __restrict__, wchar_t ** __restrict__);
#అయితే_ముగింపు /* __NO_ISOCEXT */
  _CRTIMP ద్విగుణ __cdecl _wcstod_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,_locale_t _Locale);
  దీర్ఘ __cdecl wcstol(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP దీర్ఘ __cdecl _wcstol_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  గుర్తులేని దీర్ఘ __cdecl wcstoul(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP గుర్తులేని దీర్ఘ __cdecl _wcstoul_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(స్థిరరాశి wchar_t *_VarName);
#నిర్వచితం_కాకపోతే _CRT_WSYSTEM_DEFINED
#నిర్వచించు _CRT_WSYSTEM_DEFINED
  _CRTIMP పూర్ణాంకం __cdecl _wsystem(స్థిరరాశి wchar_t *_Command);
#అయితే_ముగింపు
  _CRTIMP ద్విగుణ __cdecl _wtof(స్థిరరాశి wchar_t *_Str);
  _CRTIMP ద్విగుణ __cdecl _wtof_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wtoi(స్థిరరాశి wchar_t *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _wtoi_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);
  _CRTIMP దీర్ఘ __cdecl _wtol(స్థిరరాశి wchar_t *_Str);
  _CRTIMP దీర్ఘ __cdecl _wtol_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,పూర్ణాంకం _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(గుర్తులేని __int64 _Val,wchar_t *_DstBuf,పూర్ణాంకం _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(స్థిరరాశి wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(స్థిరరాశి wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
  _CRTIMP గుర్తులేని __int64 __cdecl _wcstoui64(స్థిరరాశి wchar_t *_Str,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix);
  _CRTIMP గుర్తులేని __int64 __cdecl _wcstoui64_l(స్థిరరాశి wchar_t *_Str ,wchar_t **చివర_Ptr,పూర్ణాంకం _Radix,_locale_t _Locale);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _POSIX_
#నిర్వచించు _CVTBUFSIZE (309+40)
  _CRTIMP అక్షరం *__cdecl _fullpath(అక్షరం *నిండిన_మార్గం,స్థిరరాశి అక్షరం *మార్గం_2,కొలత_t కొలత_లోపల_బైట్లు);
  _CRTIMP అక్షరం *__cdecl _ecvt(ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Digits,పూర్ణాంకం *_PtDec,పూర్ణాంకం *_PtSign);
  _CRTIMP అక్షరం *__cdecl _fcvt(ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Dec,పూర్ణాంకం *_PtDec,పూర్ణాంకం *_PtSign);
  _CRTIMP అక్షరం *__cdecl _gcvt(ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Digits,అక్షరం *_DstBuf);
  _CRTIMP పూర్ణాంకం __cdecl _atodbl(_CRT_DOUBLE *ఫలితం_2,అక్షరం *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _atoldbl(_LDOUBLE *ఫలితం_2,అక్షరం *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _atoflt(_CRT_FLOAT *ఫలితం_2,అక్షరం *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _atodbl_l(_CRT_DOUBLE *ఫలితం_2,అక్షరం *_Str,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _atoldbl_l(_LDOUBLE *ఫలితం_2,అక్షరం *_Str,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _atoflt_l(_CRT_FLOAT *ఫలితం_2,అక్షరం *_Str,_locale_t _Locale);
  గుర్తులేని దీర్ఘ __cdecl _lrotl(గుర్తులేని దీర్ఘ _Val,పూర్ణాంకం జరుపు_2);
  గుర్తులేని దీర్ఘ __cdecl _lrotr(గుర్తులేని దీర్ఘ _Val,పూర్ణాంకం జరుపు_2);
  _CRTIMP శూన్య __cdecl _makepath(అక్షరం *మార్గం_2,స్థిరరాశి అక్షరం *_Drive,స్థిరరాశి అక్షరం *_Dir,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#నిర్వచితం_కాకపోతే _CRT_PERROR_DEFINED
#నిర్వచించు _CRT_PERROR_DEFINED
  శూన్య __cdecl perror(స్థిరరాశి అక్షరం *Err_సందేశం);
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _putenv(స్థిరరాశి అక్షరం *_EnvString);
  గుర్తులేని పూర్ణాంకం __cdecl _rotl(గుర్తులేని పూర్ణాంకం _Val,పూర్ణాంకం జరుపు_2);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  గుర్తులేని __int64 __cdecl _rotl64(గుర్తులేని __int64 _Val,పూర్ణాంకం జరుపు_2);
#అయితే_ముగింపు
  గుర్తులేని పూర్ణాంకం __cdecl _rotr(గుర్తులేని పూర్ణాంకం _Val,పూర్ణాంకం జరుపు_2);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  గుర్తులేని __int64 __cdecl _rotr64(గుర్తులేని __int64 _Val,పూర్ణాంకం జరుపు_2);
#అయితే_ముగింపు
  _CRTIMP శూన్య __cdecl _searchenv(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_EnvVar,అక్షరం *ఫలితం_మార్గం);
  _CRTIMP శూన్య __cdecl _splitpath(స్థిరరాశి అక్షరం *నిండిన_మార్గం,అక్షరం *_Drive,అక్షరం *_Dir,అక్షరం *_Filename,అక్షరం *_Ext);
  _CRTIMP శూన్య __cdecl _swab(అక్షరం *_Buf1,అక్షరం *_Buf2,పూర్ణాంకం కొలత_లోపల_బైట్లు);

#నిర్వచితం_కాకపోతే _WSTDLIBP_DEFINED
#నిర్వచించు _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *నిండిన_మార్గం,స్థిరరాశి wchar_t *మార్గం_2,కొలత_t కొలత_లోపల_పదాలు);
  _CRTIMP శూన్య __cdecl _wmakepath(wchar_t *ఫలితం_మార్గం,స్థిరరాశి wchar_t *_Drive,స్థిరరాశి wchar_t *_Dir,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_Ext);
#నిర్వచితం_కాకపోతే _CRT_WPERROR_DEFINED
#నిర్వచించు _CRT_WPERROR_DEFINED
  _CRTIMP శూన్య __cdecl _wperror(స్థిరరాశి wchar_t *Err_సందేశం);
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _wputenv(స్థిరరాశి wchar_t *_EnvString);
  _CRTIMP శూన్య __cdecl _wsearchenv(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_EnvVar,wchar_t *ఫలితం_మార్గం);
  _CRTIMP శూన్య __cdecl _wsplitpath(స్థిరరాశి wchar_t *నిండిన_మార్గం,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#అయితే_ముగింపు

  _CRTIMP శూన్య __cdecl _beep(గుర్తులేని _Frequency,గుర్తులేని _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP శూన్య __cdecl _seterrormode(పూర్ణాంకం బహుళకం_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP శూన్య __cdecl _sleep(గుర్తులేని దీర్ఘ _Duration) __MINGW_ATTRIB_DEPRECATED;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NO_OLDNAMES
#నిర్వచితం_కాకపోతే _POSIX_
#ఒకవేళ 0
#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచితం_కాకపోతే NOMINMAX
#నిర్వచితం_కాకపోతే max
#నిర్వచించు max(a,b) (((a) > (b)) ? (a) : (b))
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే min
#నిర్వచించు min(a,b) (((a) < (b)) ? (a) : (b))
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు sys_errlist _sys_errlist
#నిర్వచించు sys_nerr _sys_nerr
#నిర్వచించు environ _environ
  అక్షరం *__cdecl ecvt(ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Digits,పూర్ణాంకం *_PtDec,పూర్ణాంకం *_PtSign);
  అక్షరం *__cdecl fcvt(ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Dec,పూర్ణాంకం *_PtDec,పూర్ణాంకం *_PtSign);
  అక్షరం *__cdecl gcvt(ద్విగుణ _Val,పూర్ణాంకం అంకె_యొక్క_Digits,అక్షరం *_DstBuf);
  అక్షరం *__cdecl itoa(పూర్ణాంకం _Val,అక్షరం *_DstBuf,పూర్ణాంకం _Radix);
  అక్షరం *__cdecl ltoa(దీర్ఘ _Val,అక్షరం *_DstBuf,పూర్ణాంకం _Radix);
  పూర్ణాంకం __cdecl putenv(స్థిరరాశి అక్షరం *_EnvString);
  శూన్య __cdecl swab(అక్షరం *_Buf1,అక్షరం *_Buf2,పూర్ణాంకం కొలత_లోపల_బైట్లు);
  అక్షరం *__cdecl ultoa(గుర్తులేని దీర్ఘ _Val,అక్షరం *_Dstbuf,పూర్ణాంకం _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  రకనిర్వచనం నిర్మాణం { దీర్ఘ దీర్ఘ quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(దీర్ఘ దీర్ఘ, దీర్ఘ దీర్ఘ);

  __CRT_INLINE దీర్ఘ దీర్ఘ __cdecl llabs(దీర్ఘ దీర్ఘ _j) { తిరిగి (_j >= 0 ? _j : -_j); }

 #నిర్వచితమైతే __TINYC__ /* gr */
  #నిర్వచించు strtoll _strtoi64
  #నిర్వచించు strtoull _strtoui64
 #లేకపోతే
  దీర్ఘ దీర్ఘ  __cdecl strtoll(స్థిరరాశి అక్షరం* __restrict__, అక్షరం** __restrict, పూర్ణాంకం);
  గుర్తులేని దీర్ఘ దీర్ఘ  __cdecl strtoull(స్థిరరాశి అక్షరం* __restrict__, అక్షరం** __restrict__, పూర్ణాంకం);
 #అయితే_ముగింపు

  /* these are stubs for MS _i64 versions */
  దీర్ఘ దీర్ఘ  __cdecl atoll (స్థిరరాశి అక్షరం *);

#నిర్వచితం_కాకపోతే __STRICT_ANSI__
  దీర్ఘ దీర్ఘ  __cdecl wtoll (స్థిరరాశి wchar_t *);
  అక్షరం *__cdecl lltoa (దీర్ఘ దీర్ఘ, అక్షరం *, పూర్ణాంకం);
  అక్షరం *__cdecl ulltoa (గుర్తులేని దీర్ఘ దీర్ఘ , అక్షరం *, పూర్ణాంకం);
  wchar_t *__cdecl lltow (దీర్ఘ దీర్ఘ, wchar_t *, పూర్ణాంకం);
  wchar_t *__cdecl ulltow (గుర్తులేని దీర్ఘ దీర్ఘ, wchar_t *, పూర్ణాంకం);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE దీర్ఘ దీర్ఘ  __cdecl atoll (స్థిరరాశి అక్షరం * _c) { తిరిగి _atoi64 (_c); }
  __CRT_INLINE అక్షరం *__cdecl lltoa (దీర్ఘ దీర్ఘ _n, అక్షరం * _c, పూర్ణాంకం _i) { తిరిగి _i64toa (_n, _c, _i); }
  __CRT_INLINE అక్షరం *__cdecl ulltoa (గుర్తులేని దీర్ఘ దీర్ఘ _n, అక్షరం * _c, పూర్ణాంకం _i) { తిరిగి _ui64toa (_n, _c, _i); }
  __CRT_INLINE దీర్ఘ దీర్ఘ  __cdecl wtoll (స్థిరరాశి wchar_t * _w) { తిరిగి _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (దీర్ఘ దీర్ఘ _n, wchar_t * _w, పూర్ణాంకం _i) { తిరిగి _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (గుర్తులేని దీర్ఘ దీర్ఘ _n, wchar_t * _w, పూర్ణాంకం _i) { తిరిగి _ui64tow (_n, _w, _i); }
#అయితే_ముగింపు /* (__STRICT_ANSI__)  */

#అయితే_ముగింపు /* !__NO_ISOCEXT */

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)

#అన్తర్భావ <sec_api/stdlib_s.h>
#అన్తర్భావ <malloc.h>

#అయితే_ముగింపు
