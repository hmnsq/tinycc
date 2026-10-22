/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_STDLIB
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_STDLIB

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <limits.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಖಾಲಿ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ 0
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ ((ಶೂನ್ಯ *)0)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_SUCCESS 0
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_FAILURE 1

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _ONEXIT_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _ONEXIT_T_DEFINED

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (__cdecl *_onexit_t)(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿಸು onexit_t _onexit_t
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _DIV_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _DIV_T_DEFINED

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _div_t {
    ಪೂರ್ಣಾಂಕ quot;
    ಪೂರ್ಣಾಂಕ rem;
  } div_t;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ldiv_t {
    ದೀರ್ಘ quot;
    ದೀರ್ಘ rem;
  } ldiv_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_DOUBLE_DEC
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_DOUBLE_DEC

#ಸೂಚನೆ pack(4)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ld[10];
  } _LDOUBLE;
#ಸೂಚನೆ pack()

#ವ್ಯಾಖ್ಯಾನಿಸು _PTR_LD(x) ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)(&(x)->ld))

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ದ್ವಿಗುಣ x;
  } _CRT_DOUBLE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ದಶಮಾಂಶ f;
  } _CRT_FLOAT;

#ಸೂಚನೆ ತಳ್ಳು_macro("long")
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ದೀರ್ಘ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ದೀರ್ಘ ದ್ವಿಗುಣ x;
  } _LONGDOUBLE;

#ಸೂಚನೆ ತೆಗೆ_macro("long")

#ಸೂಚನೆ pack(4)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ld12[12];
  } _LDBL12;
#ಸೂಚನೆ pack()
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು RAND_MAX 0x7fff

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ MB_CUR_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು MB_CUR_MAX ___mb_cur_max_func()
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __mb_cur_max
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __mb_cur_max;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __mb_cur_max    (*_imp____mb_cur_max)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ *_imp____mb_cur_max;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __mbcur_max;
#ವ್ಯಾಖ್ಯಾನಿಸು ___mb_cur_max_func() (__mb_cur_max)
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ* _imp____mbcur_max;
#ವ್ಯಾಖ್ಯಾನಿಸು ___mb_cur_max_func() (*_imp____mb_cur_max)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು __max(a,b) (((a) > (b)) ? (a) : (b))
#ವ್ಯಾಖ್ಯಾನಿಸು __min(a,b) (((a) < (b)) ? (a) : (b))

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ಮಾರ್ಗ_2 260
#ವ್ಯಾಖ್ಯಾನಿಸು _MAX_DRIVE 3
#ವ್ಯಾಖ್ಯಾನಿಸು _MAX_DIR 256
#ವ್ಯಾಖ್ಯಾನಿಸು _MAX_FNAME 256
#ವ್ಯಾಖ್ಯಾನಿಸು _MAX_EXT 256

#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_ಗಮ್ಯ_DEFAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_ಗಮ್ಯ_STDERR 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_ಗಮ್ಯ_MSGBOX 2
#ವ್ಯಾಖ್ಯಾನಿಸು _REPORT_ERRMODE 3

#ವ್ಯಾಖ್ಯಾನಿಸು WRITE_ABORT_ಸಂದೇಶ 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು _CALL_REPORTFAULT 0x2

#ವ್ಯಾಖ್ಯಾನಿಸು _MAX_ENV 32767

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (__cdecl *_purecall_handler)(ಶೂನ್ಯ);

  _CRTIMP _purecall_handler __cdecl ಗಣ_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(ಶೂನ್ಯ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (__cdecl *_invalid_parameter_handler)(ಸ್ಥಿರಾಂಕ wchar_t *,ಸ್ಥಿರಾಂಕ wchar_t *,ಸ್ಥಿರಾಂಕ wchar_t *,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ,uintptr_t);
  _invalid_parameter_handler __cdecl ಗಣ_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_ERRNO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ERRNO_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ *__cdecl _errno(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿಸು errno (*_errno())
  errno_t __cdecl ಗಣ_errno(ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_errno(ಪೂರ್ಣಾಂಕ *ಮೌಲ್ಯ_2);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *__cdecl __doserrno(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿಸು _doserrno (*__doserrno())
  errno_t __cdecl ಗಣ_doserrno(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_doserrno(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *ಮೌಲ್ಯ_2);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಅಕ್ಷರ *_sys_errlist[];
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ _sys_nerr;
#ಇಲ್ಲದಿದ್ದರೆ
  _CRTIMP ಅಕ್ಷರ *_sys_errlist[1];
  _CRTIMP ಪೂರ್ಣಾಂಕ _sys_nerr;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ (defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಂಕ *__cdecl __p___argc(ಶೂನ್ಯ);
  _CRTIMP ಅಕ್ಷರ ***__cdecl __p___argv(ಶೂನ್ಯ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(ಶೂನ್ಯ);
  _CRTIMP ಅಕ್ಷರ ***__cdecl __p__environ(ಶೂನ್ಯ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(ಶೂನ್ಯ);
  _CRTIMP ಅಕ್ಷರ **__cdecl __p__pgmptr(ಶೂನ್ಯ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __argc
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __argc;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __argc (*_imp____argc)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ *_imp____argc;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __argv
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಅಕ್ಷರ **__argv;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __argv  (*_imp____argv)
  ಬಾಹ್ಯ ಅಕ್ಷರ ***_imp____argv;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __wargv
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ wchar_t **__wargv;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __wargv (*_imp____wargv)
  ಬಾಹ್ಯ wchar_t ***_imp____wargv;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
  ಬಾಹ್ಯ ಅಕ್ಷರ **environ;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _environ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಅಕ್ಷರ **_environ;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _environ (*_imp___environ)
  ಬಾಹ್ಯ ಅಕ್ಷರ ***_imp___environ;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _wenviron
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ wchar_t **_wenviron;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _wenviron       (*_imp___wenviron)
  ಬಾಹ್ಯ wchar_t ***_imp___wenviron;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __argc;
ಬಾಹ್ಯ ಅಕ್ಷರ **__argv;
ಬಾಹ್ಯ wchar_t **__wargv;
ಬಾಹ್ಯ ಅಕ್ಷರ **_environ;
ಬಾಹ್ಯ wchar_t **_wenviron;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _pgmptr
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಅಕ್ಷರ *_pgmptr;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _pgmptr (*_imp___pgmptr)
  ಬಾಹ್ಯ ಅಕ್ಷರ **_imp___pgmptr;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _wpgmptr
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ wchar_t *_wpgmptr;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _wpgmptr        (*_imp___wpgmptr)
  ಬಾಹ್ಯ wchar_t **_imp___wpgmptr;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
  errno_t __cdecl _get_pgmptr(ಅಕ್ಷರ **ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **ಮೌಲ್ಯ_2);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _fmode
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ _fmode;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _fmode  (*_imp___fmode)
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ *_imp___fmode;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP errno_t __cdecl ಗಣ_fmode(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  _CRTIMP errno_t __cdecl _get_fmode(ಪೂರ್ಣಾಂಕ *_PMode);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _osplatform
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _osplatform;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _osplatform (*_imp___osplatform)
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *_imp___osplatform;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _osver
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _osver;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _osver  (*_imp___osver)
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *_imp___osver;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _winver
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _winver;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _winver (*_imp___winver)
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *_imp___winver;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _winmajor
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _winmajor;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _winmajor       (*_imp___winmajor)
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *_imp___winmajor;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _winminor
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _winminor;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _winminor       (*_imp___winminor)
  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *_imp___winminor;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  errno_t __cdecl _get_osplatform(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_osver(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_winver(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_winmajor(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_winminor(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಮೌಲ್ಯ_2);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _countof
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು _countof(_Array) (ಗಾತ್ರ(_Array) / ಗಾತ್ರ(_Array[0]))
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ "C++" {
    ಮಾದರಿ <typename _CountofType,ಗಾತ್ರ_t ಗಾತ್ರ_ದ_Array> ಅಕ್ಷರ (*__countof_helper(UNALIGNED _CountofType (&_Array)[ಗಾತ್ರ_ದ_Array]))[ಗಾತ್ರ_ದ_Array];
#ವ್ಯಾಖ್ಯಾನಿಸು _countof(_Array) ಗಾತ್ರ(*__countof_helper(_Array))
  }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_TERMINATE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_TERMINATE_DEFINED
  ಶೂನ್ಯ __cdecl __MINGW_NOTHROW ನಿರ್ಗಮಿಸು(ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_4) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _exit(ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_4) __MINGW_ATTRIB_NORETURN;
#ಆದರೆ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  ಶೂನ್ಯ __cdecl _Exit(ಪೂರ್ಣಾಂಕ) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN ಶೂನ್ಯ  __cdecl _Exit(ಪೂರ್ಣಾಂಕ ಸ್ಥಿತಿ_2)
  {  _exit(ಸ್ಥಿತಿ_2); }
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ ತಳ್ಳು_macro("abort")
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು abort
  ಶೂನ್ಯ __cdecl __declspec(noreturn) abort(ಶೂನ್ಯ);
#ಸೂಚನೆ ತೆಗೆ_macro("abort")

#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl ಗಣ_abort_behavior(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Flags,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಮುಖವಾಡ_2);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_ABS_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ABS_DEFINED
  ಪೂರ್ಣಾಂಕ __cdecl ನಿರಪೇಕ್ಷ(ಪೂರ್ಣಾಂಕ _X);
  ದೀರ್ಘ __cdecl labs(ದೀರ್ಘ _X);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  __int64 __cdecl _abs64(__int64);
#ಆದರೆ_ಅಂತ್ಯ
  ಪೂರ್ಣಾಂಕ __cdecl atexit(ಶೂನ್ಯ (__cdecl *)(ಶೂನ್ಯ));
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_ATOF_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ATOF_DEFINED
  ದ್ವಿಗುಣ __cdecl atof(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String);
  ದ್ವಿಗುಣ __cdecl _atof_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String,_locale_t _Locale);
#ಆದರೆ_ಅಂತ್ಯ
  ಪೂರ್ಣಾಂಕ __cdecl atoi(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _atoi_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,_locale_t _Locale);
  ದೀರ್ಘ __cdecl atol(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str);
  _CRTIMP ದೀರ್ಘ __cdecl _atol_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,_locale_t _Locale);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_ALGO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ALGO_DEFINED
  ಶೂನ್ಯ *__cdecl bsearch(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *ಕೀಲಿ_2,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *ತಳ_3,ಗಾತ್ರ_t ಅಂಕೆ_ದ_Elements,ಗಾತ್ರ_t ಗಾತ್ರ_ದ_Elements,ಪೂರ್ಣಾಂಕ (__cdecl *_PtFuncCompare)(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *));
  ಶೂನ್ಯ __cdecl qsort(ಶೂನ್ಯ *ತಳ_3,ಗಾತ್ರ_t ಅಂಕೆ_ದ_Elements,ಗಾತ್ರ_t ಗಾತ್ರ_ದ_Elements,ಪೂರ್ಣಾಂಕ (__cdecl *_PtFuncCompare)(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *));
#ಆದರೆ_ಅಂತ್ಯ
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __cdecl _byteswap_ushort(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _byteswap_uint64(ಚಿಹ್ನೆರಹಿತ __int64 _Int64);
#ಆದರೆ_ಅಂತ್ಯ
  div_t __cdecl div(ಪೂರ್ಣಾಂಕ _Numerator,ಪೂರ್ಣಾಂಕ _Denominator);
  ಅಕ್ಷರ *__cdecl getenv(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_VarName);
  _CRTIMP ಅಕ್ಷರ *__cdecl _itoa(ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2,ಅಕ್ಷರ *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP ಅಕ್ಷರ *__cdecl _i64toa(__int64 _Val,ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ಅಕ್ಷರ *__cdecl _ui64toa(ಚಿಹ್ನೆರಹಿತ __int64 _Val,ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _strtoui64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _strtoui64_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_String,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
#ಆದರೆ_ಅಂತ್ಯ
  ldiv_t __cdecl ldiv(ದೀರ್ಘ _Numerator,ದೀರ್ಘ _Denominator);
  _CRTIMP ಅಕ್ಷರ *__cdecl _ltoa(ದೀರ್ಘ ಮೌಲ್ಯ_2,ಅಕ್ಷರ *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  ಪೂರ್ಣಾಂಕ __cdecl mblen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Ch,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _mblen_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Ch,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP ಗಾತ್ರ_t __cdecl _mbstrlen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str);
  _CRTIMP ಗಾತ್ರ_t __cdecl _mbstrlen_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,_locale_t _Locale);
  _CRTIMP ಗಾತ್ರ_t __cdecl _mbstrnlen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಗಾತ್ರ_t __cdecl _mbstrnlen_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl mbtowc(wchar_t *_DstCh,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_SrcCh,ಗಾತ್ರ_t Src_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _mbtowc_l(wchar_t *_DstCh,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_SrcCh,ಗಾತ್ರ_t Src_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು,_locale_t _Locale);
  ಗಾತ್ರ_t __cdecl mbstowcs(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೂಲ_3,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಗಾತ್ರ_t __cdecl _mbstowcs_l(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೂಲ_3,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ಪೂರ್ಣಾಂಕ __cdecl rand(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl ಗಣ_error_ಬಹುಲಕ(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  ಶೂನ್ಯ __cdecl srand(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಬೀಜ);
  ದ್ವಿಗುಣ __cdecl strtod(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಅಕ್ಷರ **ಕೊನೆ_Ptr);
#ಆದರೆ !defined __NO_ISOCEXT  /* in libmingwex.a */
#ಆದರೆ __TINYC__
  __CRT_INLINE ದಶಮಾಂಶ __cdecl strtof (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, ಅಕ್ಷರ ** e) { ಹಿಂತಿರುಗಿ strtod(p, e); }
  __CRT_INLINE ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl strtold(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, ಅಕ್ಷರ ** e) { ಹಿಂತಿರುಗಿ strtod(p, e); }
#ಇಲ್ಲದಿದ್ದರೆ
  ದಶಮಾಂಶ __cdecl strtof (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * __restrict__, ಅಕ್ಷರ ** __restrict__);
  ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl strtold(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * __restrict__, ಅಕ್ಷರ ** __restrict__);
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ದಶಮಾಂಶ __cdecl strtof(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr);
#ಆದರೆ_ಅಂತ್ಯ /* __NO_ISOCEXT */
  _CRTIMP ದ್ವಿಗುಣ __cdecl _strtod_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಅಕ್ಷರ **ಕೊನೆ_Ptr,_locale_t _Locale);
  ದೀರ್ಘ __cdecl strtol(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ದೀರ್ಘ __cdecl _strtol_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl strtoul(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _strtoul_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,ಅಕ್ಷರ **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_SYSTEM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_SYSTEM_DEFINED
  ಪೂರ್ಣಾಂಕ __cdecl system(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Command);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಅಕ್ಷರ *__cdecl _ultoa(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ_2,ಅಕ್ಷರ *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  ಪೂರ್ಣಾಂಕ __cdecl wctomb(ಅಕ್ಷರ *_MbCh,wchar_t _WCh);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wctomb_l(ಅಕ್ಷರ *_MbCh,wchar_t _WCh,_locale_t _Locale);
  ಗಾತ್ರ_t __cdecl wcstombs(ಅಕ್ಷರ *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *ಮೂಲ_3,ಗಾತ್ರ_t Max_ಎಣಿಕೆ);
  _CRTIMP ಗಾತ್ರ_t __cdecl _wcstombs_l(ಅಕ್ಷರ *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *ಮೂಲ_3,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,_locale_t _Locale);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CRT_ಹಂಚಿಕೆ_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು CRT_ಹಂಚಿಕೆ_DEFINED
  ಶೂನ್ಯ *__cdecl ಸೊನ್ನೆ_ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t ಅಂಕೆ_ದ_Elements,ಗಾತ್ರ_t ಗಾತ್ರ_ದ_Elements);
  ಶೂನ್ಯ __cdecl ಬಿಡುಗಡೆ(ಶೂನ್ಯ *ಸ್ಮರಣೆ);
  ಶೂನ್ಯ *__cdecl ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t ಗಾತ್ರ_5);
  ಶೂನ್ಯ *__cdecl realloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t New_ಗಾತ್ರ);
  _CRTIMP ಶೂನ್ಯ *__cdecl _recalloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP ಶೂನ್ಯ __cdecl _aligned_free(ಶೂನ್ಯ *ಸ್ಮರಣೆ);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_malloc(ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl aligned_ಸ್ಥಾನಾಂತರ_malloc(ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment,ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ_2);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_realloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_recalloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl aligned_ಸ್ಥಾನಾಂತರ_realloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment,ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ_2);
  _CRTIMP ಶೂನ್ಯ *__cdecl aligned_ಸ್ಥಾನಾಂತರ_recalloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment,ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDLIB_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(ದೀರ್ಘ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ_2,wchar_t *_Dest,ಪೂರ್ಣಾಂಕ _Radix);
  ದ್ವಿಗುಣ __cdecl wcstod(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr);
  ದಶಮಾಂಶ __cdecl wcstof(ಸ್ಥಿರಾಂಕ wchar_t *nptr, wchar_t **endptr);
#ಆದರೆ !defined __NO_ISOCEXT /* in libmingwex.a */
  ದಶಮಾಂಶ __cdecl wcstof( ಸ್ಥಿರಾಂಕ wchar_t * __restrict__, wchar_t ** __restrict__);
  ದೀರ್ಘ ದ್ವಿಗುಣ __cdecl wcstold(ಸ್ಥಿರಾಂಕ wchar_t * __restrict__, wchar_t ** __restrict__);
#ಆದರೆ_ಅಂತ್ಯ /* __NO_ISOCEXT */
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wcstod_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,_locale_t _Locale);
  ದೀರ್ಘ __cdecl wcstol(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ದೀರ್ಘ __cdecl _wcstol_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl wcstoul(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _wcstoul_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ಸ್ಥಿರಾಂಕ wchar_t *_VarName);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WSYSTEM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsystem(ಸ್ಥಿರಾಂಕ wchar_t *_Command);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP ದ್ವಿಗುಣ __cdecl _wtof_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wtoi(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wtoi_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ದೀರ್ಘ __cdecl _wtol(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP ದೀರ್ಘ __cdecl _wtol_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(ಚಿಹ್ನೆರಹಿತ __int64 _Val,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _wcstoui64(ಸ್ಥಿರಾಂಕ wchar_t *_Str,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _wcstoui64_l(ಸ್ಥಿರಾಂಕ wchar_t *_Str ,wchar_t **ಕೊನೆ_Ptr,ಪೂರ್ಣಾಂಕ _Radix,_locale_t _Locale);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _POSIX_
#ವ್ಯಾಖ್ಯಾನಿಸು _CVTBUFSIZE (309+40)
  _CRTIMP ಅಕ್ಷರ *__cdecl _fullpath(ಅಕ್ಷರ *ತುಂಬಿದ_ಮಾರ್ಗ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP ಅಕ್ಷರ *__cdecl _ecvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Digits,ಪೂರ್ಣಾಂಕ *_PtDec,ಪೂರ್ಣಾಂಕ *_PtSign);
  _CRTIMP ಅಕ್ಷರ *__cdecl _fcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Dec,ಪೂರ್ಣಾಂಕ *_PtDec,ಪೂರ್ಣಾಂಕ *_PtSign);
  _CRTIMP ಅಕ್ಷರ *__cdecl _gcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Digits,ಅಕ್ಷರ *_DstBuf);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _atodbl(_CRT_DOUBLE *ಫಲಿತಾಂಶ_2,ಅಕ್ಷರ *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _atoldbl(_LDOUBLE *ಫಲಿತಾಂಶ_2,ಅಕ್ಷರ *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _atoflt(_CRT_FLOAT *ಫಲಿತಾಂಶ_2,ಅಕ್ಷರ *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _atodbl_l(_CRT_DOUBLE *ಫಲಿತಾಂಶ_2,ಅಕ್ಷರ *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _atoldbl_l(_LDOUBLE *ಫಲಿತಾಂಶ_2,ಅಕ್ಷರ *_Str,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _atoflt_l(_CRT_FLOAT *ಫಲಿತಾಂಶ_2,ಅಕ್ಷರ *_Str,_locale_t _Locale);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _lrotl(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _Val,ಪೂರ್ಣಾಂಕ ಸರಿಸು_2);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _lrotr(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _Val,ಪೂರ್ಣಾಂಕ ಸರಿಸು_2);
  _CRTIMP ಶೂನ್ಯ __cdecl _makepath(ಅಕ್ಷರ *ಮಾರ್ಗ_2,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Drive,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Dir,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_PERROR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_PERROR_DEFINED
  ಶೂನ್ಯ __cdecl perror(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *Err_ಸಂದೇಶ);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _putenv(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_EnvString);
  ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl _rotl(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Val,ಪೂರ್ಣಾಂಕ ಸರಿಸು_2);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _rotl64(ಚಿಹ್ನೆರಹಿತ __int64 _Val,ಪೂರ್ಣಾಂಕ ಸರಿಸು_2);
#ಆದರೆ_ಅಂತ್ಯ
  ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl _rotr(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Val,ಪೂರ್ಣಾಂಕ ಸರಿಸು_2);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _rotr64(ಚಿಹ್ನೆರಹಿತ __int64 _Val,ಪೂರ್ಣಾಂಕ ಸರಿಸು_2);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಶೂನ್ಯ __cdecl _searchenv(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_EnvVar,ಅಕ್ಷರ *ಫಲಿತಾಂಶ_ಮಾರ್ಗ);
  _CRTIMP ಶೂನ್ಯ __cdecl _splitpath(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ತುಂಬಿದ_ಮಾರ್ಗ,ಅಕ್ಷರ *_Drive,ಅಕ್ಷರ *_Dir,ಅಕ್ಷರ *_Filename,ಅಕ್ಷರ *_Ext);
  _CRTIMP ಶೂನ್ಯ __cdecl _swab(ಅಕ್ಷರ *_Buf1,ಅಕ್ಷರ *_Buf2,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDLIBP_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *ತುಂಬಿದ_ಮಾರ್ಗ,ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP ಶೂನ್ಯ __cdecl _wmakepath(wchar_t *ಫಲಿತಾಂಶ_ಮಾರ್ಗ,ಸ್ಥಿರಾಂಕ wchar_t *_Drive,ಸ್ಥಿರಾಂಕ wchar_t *_Dir,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_Ext);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WPERROR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಸ್ಥಿರಾಂಕ wchar_t *Err_ಸಂದೇಶ);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wputenv(ಸ್ಥಿರಾಂಕ wchar_t *_EnvString);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsearchenv(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_EnvVar,wchar_t *ಫಲಿತಾಂಶ_ಮಾರ್ಗ);
  _CRTIMP ಶೂನ್ಯ __cdecl _wsplitpath(ಸ್ಥಿರಾಂಕ wchar_t *ತುಂಬಿದ_ಮಾರ್ಗ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಶೂನ್ಯ __cdecl _beep(ಚಿಹ್ನೆರಹಿತ _Frequency,ಚಿಹ್ನೆರಹಿತ _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP ಶೂನ್ಯ __cdecl _seterrormode(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP ಶೂನ್ಯ __cdecl _sleep(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _Duration) __MINGW_ATTRIB_DEPRECATED;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _POSIX_
#ಆದರೆ 0
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMINMAX
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ max
#ವ್ಯಾಖ್ಯಾನಿಸು max(a,b) (((a) > (b)) ? (a) : (b))
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ min
#ವ್ಯಾಖ್ಯಾನಿಸು min(a,b) (((a) < (b)) ? (a) : (b))
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು sys_errlist _sys_errlist
#ವ್ಯಾಖ್ಯಾನಿಸು sys_nerr _sys_nerr
#ವ್ಯಾಖ್ಯಾನಿಸು environ _environ
  ಅಕ್ಷರ *__cdecl ecvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Digits,ಪೂರ್ಣಾಂಕ *_PtDec,ಪೂರ್ಣಾಂಕ *_PtSign);
  ಅಕ್ಷರ *__cdecl fcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Dec,ಪೂರ್ಣಾಂಕ *_PtDec,ಪೂರ್ಣಾಂಕ *_PtSign);
  ಅಕ್ಷರ *__cdecl gcvt(ದ್ವಿಗುಣ _Val,ಪೂರ್ಣಾಂಕ ಅಂಕೆ_ದ_Digits,ಅಕ್ಷರ *_DstBuf);
  ಅಕ್ಷರ *__cdecl itoa(ಪೂರ್ಣಾಂಕ _Val,ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  ಅಕ್ಷರ *__cdecl ltoa(ದೀರ್ಘ _Val,ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ _Radix);
  ಪೂರ್ಣಾಂಕ __cdecl putenv(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_EnvString);
  ಶೂನ್ಯ __cdecl swab(ಅಕ್ಷರ *_Buf1,ಅಕ್ಷರ *_Buf2,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  ಅಕ್ಷರ *__cdecl ultoa(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _Val,ಅಕ್ಷರ *_Dstbuf,ಪೂರ್ಣಾಂಕ _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ದೀರ್ಘ ದೀರ್ಘ quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(ದೀರ್ಘ ದೀರ್ಘ, ದೀರ್ಘ ದೀರ್ಘ);

  __CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ __cdecl llabs(ದೀರ್ಘ ದೀರ್ಘ _j) { ಹಿಂತಿರುಗಿ (_j >= 0 ? _j : -_j); }

 #ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__ /* gr */
  #ವ್ಯಾಖ್ಯಾನಿಸು strtoll _strtoi64
  #ವ್ಯಾಖ್ಯಾನಿಸು strtoull _strtoui64
 #ಇಲ್ಲದಿದ್ದರೆ
  ದೀರ್ಘ ದೀರ್ಘ  __cdecl strtoll(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* __restrict__, ಅಕ್ಷರ** __restrict, ಪೂರ್ಣಾಂಕ);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ  __cdecl strtoull(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* __restrict__, ಅಕ್ಷರ** __restrict__, ಪೂರ್ಣಾಂಕ);
 #ಆದರೆ_ಅಂತ್ಯ

  /* these are stubs for MS _i64 versions */
  ದೀರ್ಘ ದೀರ್ಘ  __cdecl atoll (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRICT_ANSI__
  ದೀರ್ಘ ದೀರ್ಘ  __cdecl wtoll (ಸ್ಥಿರಾಂಕ wchar_t *);
  ಅಕ್ಷರ *__cdecl lltoa (ದೀರ್ಘ ದೀರ್ಘ, ಅಕ್ಷರ *, ಪೂರ್ಣಾಂಕ);
  ಅಕ್ಷರ *__cdecl ulltoa (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ , ಅಕ್ಷರ *, ಪೂರ್ಣಾಂಕ);
  wchar_t *__cdecl lltow (ದೀರ್ಘ ದೀರ್ಘ, wchar_t *, ಪೂರ್ಣಾಂಕ);
  wchar_t *__cdecl ulltow (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ, wchar_t *, ಪೂರ್ಣಾಂಕ);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ  __cdecl atoll (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * _c) { ಹಿಂತಿರುಗಿ _atoi64 (_c); }
  __CRT_INLINE ಅಕ್ಷರ *__cdecl lltoa (ದೀರ್ಘ ದೀರ್ಘ _n, ಅಕ್ಷರ * _c, ಪೂರ್ಣಾಂಕ _i) { ಹಿಂತಿರುಗಿ _i64toa (_n, _c, _i); }
  __CRT_INLINE ಅಕ್ಷರ *__cdecl ulltoa (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ _n, ಅಕ್ಷರ * _c, ಪೂರ್ಣಾಂಕ _i) { ಹಿಂತಿರುಗಿ _ui64toa (_n, _c, _i); }
  __CRT_INLINE ದೀರ್ಘ ದೀರ್ಘ  __cdecl wtoll (ಸ್ಥಿರಾಂಕ wchar_t * _w) { ಹಿಂತಿರುಗಿ _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (ದೀರ್ಘ ದೀರ್ಘ _n, wchar_t * _w, ಪೂರ್ಣಾಂಕ _i) { ಹಿಂತಿರುಗಿ _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ _n, wchar_t * _w, ಪೂರ್ಣಾಂಕ _i) { ಹಿಂತಿರುಗಿ _ui64tow (_n, _w, _i); }
#ಆದರೆ_ಅಂತ್ಯ /* (__STRICT_ANSI__)  */

#ಆದರೆ_ಅಂತ್ಯ /* !__NO_ISOCEXT */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/stdlib_s.h>
#ಅನ್ತರ್ಭಾವ <malloc.h>

#ಆದರೆ_ಅಂತ್ಯ
