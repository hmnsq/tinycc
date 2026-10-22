/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_STDLIB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_STDLIB

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <limits.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਨਿਰਾ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ 0
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ ((ਖਾਲੀ *)0)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_SUCCESS 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_FAILURE 1

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _ONEXIT_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ONEXIT_T_DEFINED

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (__cdecl *_onexit_t)(ਖਾਲੀ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NO_OLDNAMES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ onexit_t _onexit_t
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _DIV_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DIV_T_DEFINED

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _div_t {
    ਪੂਰਨ quot;
    ਪੂਰਨ rem;
  } div_t;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ldiv_t {
    ਲੰਮਾ quot;
    ਲੰਮਾ rem;
  } ldiv_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_DOUBLE_DEC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_DOUBLE_DEC

#ਹਦਾਇਤ pack(4)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ld[10];
  } _LDOUBLE;
#ਹਦਾਇਤ pack()

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PTR_LD(x) ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)(&(x)->ld))

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਦੁੱਗਣਾ x;
  } _CRT_DOUBLE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਦਸ਼ਮਲਵ f;
  } _CRT_FLOAT;

#ਹਦਾਇਤ ਧੱਕੋ_macro("long")
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ਲੰਮਾ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਲੰਮਾ ਦੁੱਗਣਾ x;
  } _LONGDOUBLE;

#ਹਦਾਇਤ ਕੱਢੋ_macro("long")

#ਹਦਾਇਤ pack(4)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ld12[12];
  } _LDBL12;
#ਹਦਾਇਤ pack()
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RAND_MAX 0x7fff

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ MB_CUR_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_CUR_MAX ___mb_cur_max_func()
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __mb_cur_max
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਪੂਰਨ __mb_cur_max;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __mb_cur_max    (*_imp____mb_cur_max)
  ਬਾਹਰੀ ਪੂਰਨ *_imp____mb_cur_max;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਪੂਰਨ __mbcur_max;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ___mb_cur_max_func() (__mb_cur_max)
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ ਪੂਰਨ* _imp____mbcur_max;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ___mb_cur_max_func() (*_imp____mb_cur_max)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __max(a,b) (((a) > (b)) ? (a) : (b))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __min(a,b) (((a) < (b)) ? (a) : (b))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ਰਸਤਾ_2 260
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MAX_DRIVE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MAX_DIR 256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MAX_FNAME 256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MAX_EXT 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_ਮੰਜ਼ਿਲ_DEFAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_ਮੰਜ਼ਿਲ_STDERR 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_ਮੰਜ਼ਿਲ_MSGBOX 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _REPORT_ERRMODE 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WRITE_ABORT_ਸੁਨੇਹਾ 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CALL_REPORTFAULT 0x2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MAX_ENV 32767

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (__cdecl *_purecall_handler)(ਖਾਲੀ);

  _CRTIMP _purecall_handler __cdecl ਸੈੱਟ_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(ਖਾਲੀ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (__cdecl *_invalid_parameter_handler)(ਅਚਲ wchar_t *,ਅਚਲ wchar_t *,ਅਚਲ wchar_t *,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ,uintptr_t);
  _invalid_parameter_handler __cdecl ਸੈੱਟ_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(ਖਾਲੀ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_ERRNO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ERRNO_DEFINED
  _CRTIMP ਪੂਰਨ *__cdecl _errno(ਖਾਲੀ);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ errno (*_errno())
  errno_t __cdecl ਸੈੱਟ_errno(ਪੂਰਨ ਮੁੱਲ_2);
  errno_t __cdecl _get_errno(ਪੂਰਨ *ਮੁੱਲ_2);
#ਜੇ_ਅੰਤ
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *__cdecl __doserrno(ਖਾਲੀ);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _doserrno (*__doserrno())
  errno_t __cdecl ਸੈੱਟ_doserrno(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ_2);
  errno_t __cdecl _get_doserrno(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *ਮੁੱਲ_2);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਅੱਖਰ *_sys_errlist[];
  ਬਾਹਰੀ ਪੂਰਨ _sys_nerr;
#ਨਹੀਂਤਾਂ
  _CRTIMP ਅੱਖਰ *_sys_errlist[1];
  _CRTIMP ਪੂਰਨ _sys_nerr;
#ਜੇ_ਅੰਤ
#ਜੇ (defined(_X86_) && !defined(__x86_64))
  _CRTIMP ਪੂਰਨ *__cdecl __p___argc(ਖਾਲੀ);
  _CRTIMP ਅੱਖਰ ***__cdecl __p___argv(ਖਾਲੀ);
  _CRTIMP wchar_t ***__cdecl __p___wargv(ਖਾਲੀ);
  _CRTIMP ਅੱਖਰ ***__cdecl __p__environ(ਖਾਲੀ);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(ਖਾਲੀ);
  _CRTIMP ਅੱਖਰ **__cdecl __p__pgmptr(ਖਾਲੀ);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(ਖਾਲੀ);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __argc
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਪੂਰਨ __argc;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __argc (*_imp____argc)
  ਬਾਹਰੀ ਪੂਰਨ *_imp____argc;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __argv
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਅੱਖਰ **__argv;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __argv  (*_imp____argv)
  ਬਾਹਰੀ ਅੱਖਰ ***_imp____argv;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __wargv
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ wchar_t **__wargv;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __wargv (*_imp____wargv)
  ਬਾਹਰੀ wchar_t ***_imp____wargv;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
  ਬਾਹਰੀ ਅੱਖਰ **environ;
#ਨਹੀਂਤਾਂ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _environ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਅੱਖਰ **_environ;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _environ (*_imp___environ)
  ਬਾਹਰੀ ਅੱਖਰ ***_imp___environ;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _wenviron
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ wchar_t **_wenviron;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wenviron       (*_imp___wenviron)
  ਬਾਹਰੀ wchar_t ***_imp___wenviron;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ defined __aarch64__
/* something does not work using those from msvcrt.dll */
# undef __argc
# undef __argv
# undef __wargv
# undef _wenviron
# undef _environ
ਬਾਹਰੀ ਪੂਰਨ __argc;
ਬਾਹਰੀ ਅੱਖਰ **__argv;
ਬਾਹਰੀ wchar_t **__wargv;
ਬਾਹਰੀ ਅੱਖਰ **_environ;
ਬਾਹਰੀ wchar_t **_wenviron;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _pgmptr
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਅੱਖਰ *_pgmptr;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _pgmptr (*_imp___pgmptr)
  ਬਾਹਰੀ ਅੱਖਰ **_imp___pgmptr;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _wpgmptr
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ wchar_t *_wpgmptr;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wpgmptr        (*_imp___wpgmptr)
  ਬਾਹਰੀ wchar_t **_imp___wpgmptr;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
  errno_t __cdecl _get_pgmptr(ਅੱਖਰ **ਮੁੱਲ_2);
  errno_t __cdecl _get_wpgmptr(wchar_t **ਮੁੱਲ_2);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _fmode
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਪੂਰਨ _fmode;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fmode  (*_imp___fmode)
  ਬਾਹਰੀ ਪੂਰਨ *_imp___fmode;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
  _CRTIMP errno_t __cdecl ਸੈੱਟ_fmode(ਪੂਰਨ ਬਹੁਲਕ_3);
  _CRTIMP errno_t __cdecl _get_fmode(ਪੂਰਨ *_PMode);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _osplatform
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _osplatform;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _osplatform (*_imp___osplatform)
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *_imp___osplatform;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _osver
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _osver;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _osver  (*_imp___osver)
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *_imp___osver;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _winver
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _winver;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _winver (*_imp___winver)
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *_imp___winver;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _winmajor
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _winmajor;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _winmajor       (*_imp___winmajor)
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *_imp___winmajor;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _winminor
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _winminor;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _winminor       (*_imp___winminor)
  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *_imp___winminor;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  errno_t __cdecl _get_osplatform(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਮੁੱਲ_2);
  errno_t __cdecl _get_osver(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਮੁੱਲ_2);
  errno_t __cdecl _get_winver(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਮੁੱਲ_2);
  errno_t __cdecl _get_winmajor(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਮੁੱਲ_2);
  errno_t __cdecl _get_winminor(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਮੁੱਲ_2);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _countof
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _countof(_Array) (ਆਕਾਰ(_Array) / ਆਕਾਰ(_Array[0]))
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ "C++" {
    ਸਾਂਚਾ <typename _CountofType,ਮਾਪ_t ਮਾਪ_ਦਾ_Array> ਅੱਖਰ (*__countof_helper(UNALIGNED _CountofType (&_Array)[ਮਾਪ_ਦਾ_Array]))[ਮਾਪ_ਦਾ_Array];
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _countof(_Array) ਆਕਾਰ(*__countof_helper(_Array))
  }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_TERMINATE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_TERMINATE_DEFINED
  ਖਾਲੀ __cdecl __MINGW_NOTHROW ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ ਕੋਡ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ਖਾਲੀ __cdecl __MINGW_NOTHROW _exit(ਪੂਰਨ ਕੋਡ_3) __MINGW_ATTRIB_NORETURN;
#ਜੇ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
  /* C99 function name */
  ਖਾਲੀ __cdecl _Exit(ਪੂਰਨ) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN ਖਾਲੀ  __cdecl _Exit(ਪੂਰਨ ਸਥਿਤੀ)
  {  _exit(ਸਥਿਤੀ); }
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ ਧੱਕੋ_macro("abort")
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ abort
  ਖਾਲੀ __cdecl __declspec(noreturn) abort(ਖਾਲੀ);
#ਹਦਾਇਤ ਕੱਢੋ_macro("abort")

#ਜੇ_ਅੰਤ

  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl ਸੈੱਟ_abort_behavior(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Flags,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਨਕਾਬ_2);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_ABS_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ABS_DEFINED
  ਪੂਰਨ __cdecl ਨਿਰਪੇਖ(ਪੂਰਨ _X);
  ਲੰਮਾ __cdecl labs(ਲੰਮਾ _X);
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  __int64 __cdecl _abs64(__int64);
#ਜੇ_ਅੰਤ
  ਪੂਰਨ __cdecl atexit(ਖਾਲੀ (__cdecl *)(ਖਾਲੀ));
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_ATOF_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ATOF_DEFINED
  ਦੁੱਗਣਾ __cdecl atof(ਅਚਲ ਅੱਖਰ *_String);
  ਦੁੱਗਣਾ __cdecl _atof_l(ਅਚਲ ਅੱਖਰ *_String,_locale_t _Locale);
#ਜੇ_ਅੰਤ
  ਪੂਰਨ __cdecl atoi(ਅਚਲ ਅੱਖਰ *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _atoi_l(ਅਚਲ ਅੱਖਰ *_Str,_locale_t _Locale);
  ਲੰਮਾ __cdecl atol(ਅਚਲ ਅੱਖਰ *_Str);
  _CRTIMP ਲੰਮਾ __cdecl _atol_l(ਅਚਲ ਅੱਖਰ *_Str,_locale_t _Locale);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_ALGO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ALGO_DEFINED
  ਖਾਲੀ *__cdecl bsearch(ਅਚਲ ਖਾਲੀ *ਕੁੰਜੀ_2,ਅਚਲ ਖਾਲੀ *ਅਧਾਰ_3,ਮਾਪ_t ਅੰਕ_ਦਾ_Elements,ਮਾਪ_t ਮਾਪ_ਦਾ_Elements,ਪੂਰਨ (__cdecl *_PtFuncCompare)(ਅਚਲ ਖਾਲੀ *,ਅਚਲ ਖਾਲੀ *));
  ਖਾਲੀ __cdecl qsort(ਖਾਲੀ *ਅਧਾਰ_3,ਮਾਪ_t ਅੰਕ_ਦਾ_Elements,ਮਾਪ_t ਮਾਪ_ਦਾ_Elements,ਪੂਰਨ (__cdecl *_PtFuncCompare)(ਅਚਲ ਖਾਲੀ *,ਅਚਲ ਖਾਲੀ *));
#ਜੇ_ਅੰਤ
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __cdecl _byteswap_ushort(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ _Short);
  /*unsigned long __cdecl _byteswap_ulong (unsigned long _Long); */
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _byteswap_uint64(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Int64);
#ਜੇ_ਅੰਤ
  div_t __cdecl div(ਪੂਰਨ _Numerator,ਪੂਰਨ _Denominator);
  ਅੱਖਰ *__cdecl getenv(ਅਚਲ ਅੱਖਰ *_VarName);
  _CRTIMP ਅੱਖਰ *__cdecl _itoa(ਪੂਰਨ ਮੁੱਲ_2,ਅੱਖਰ *_Dest,ਪੂਰਨ _Radix);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP ਅੱਖਰ *__cdecl _i64toa(__int64 _Val,ਅੱਖਰ *_DstBuf,ਪੂਰਨ _Radix);
  _CRTIMP ਅੱਖਰ *__cdecl _ui64toa(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Val,ਅੱਖਰ *_DstBuf,ਪੂਰਨ _Radix);
  _CRTIMP __int64 __cdecl _atoi64(ਅਚਲ ਅੱਖਰ *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(ਅਚਲ ਅੱਖਰ *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(ਅਚਲ ਅੱਖਰ *_String,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(ਅਚਲ ਅੱਖਰ *_String,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _strtoui64(ਅਚਲ ਅੱਖਰ *_String,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _strtoui64_l(ਅਚਲ ਅੱਖਰ *_String,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
#ਜੇ_ਅੰਤ
  ldiv_t __cdecl ldiv(ਲੰਮਾ _Numerator,ਲੰਮਾ _Denominator);
  _CRTIMP ਅੱਖਰ *__cdecl _ltoa(ਲੰਮਾ ਮੁੱਲ_2,ਅੱਖਰ *_Dest,ਪੂਰਨ _Radix);
  ਪੂਰਨ __cdecl mblen(ਅਚਲ ਅੱਖਰ *_Ch,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਪੂਰਨ __cdecl _mblen_l(ਅਚਲ ਅੱਖਰ *_Ch,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  _CRTIMP ਮਾਪ_t __cdecl _mbstrlen(ਅਚਲ ਅੱਖਰ *_Str);
  _CRTIMP ਮਾਪ_t __cdecl _mbstrlen_l(ਅਚਲ ਅੱਖਰ *_Str,_locale_t _Locale);
  _CRTIMP ਮਾਪ_t __cdecl _mbstrnlen(ਅਚਲ ਅੱਖਰ *_Str,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਮਾਪ_t __cdecl _mbstrnlen_l(ਅਚਲ ਅੱਖਰ *_Str,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  ਪੂਰਨ __cdecl mbtowc(wchar_t *_DstCh,ਅਚਲ ਅੱਖਰ *_SrcCh,ਮਾਪ_t Src_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP ਪੂਰਨ __cdecl _mbtowc_l(wchar_t *_DstCh,ਅਚਲ ਅੱਖਰ *_SrcCh,ਮਾਪ_t Src_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ,_locale_t _Locale);
  ਮਾਪ_t __cdecl mbstowcs(wchar_t *_Dest,ਅਚਲ ਅੱਖਰ *ਸਰੋਤ_3,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਮਾਪ_t __cdecl _mbstowcs_l(wchar_t *_Dest,ਅਚਲ ਅੱਖਰ *ਸਰੋਤ_3,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);
  ਪੂਰਨ __cdecl rand(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl ਸੈੱਟ_error_ਬਹੁਲਕ(ਪੂਰਨ ਬਹੁਲਕ_3);
  ਖਾਲੀ __cdecl srand(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਬੀਜ);
  ਦੁੱਗਣਾ __cdecl strtod(ਅਚਲ ਅੱਖਰ *_Str,ਅੱਖਰ **ਸਿਰਾ_Ptr);
#ਜੇ !defined __NO_ISOCEXT  /* in libmingwex.a */
#ਜੇ __TINYC__
  __CRT_INLINE ਦਸ਼ਮਲਵ __cdecl strtof (ਅਚਲ ਅੱਖਰ *p, ਅੱਖਰ ** e) { ਵਾਪਸ strtod(p, e); }
  __CRT_INLINE ਲੰਮਾ ਦੁੱਗਣਾ __cdecl strtold(ਅਚਲ ਅੱਖਰ *p, ਅੱਖਰ ** e) { ਵਾਪਸ strtod(p, e); }
#ਨਹੀਂਤਾਂ
  ਦਸ਼ਮਲਵ __cdecl strtof (ਅਚਲ ਅੱਖਰ * __restrict__, ਅੱਖਰ ** __restrict__);
  ਲੰਮਾ ਦੁੱਗਣਾ __cdecl strtold(ਅਚਲ ਅੱਖਰ * __restrict__, ਅੱਖਰ ** __restrict__);
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਦਸ਼ਮਲਵ __cdecl strtof(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr);
#ਜੇ_ਅੰਤ /* __NO_ISOCEXT */
  _CRTIMP ਦੁੱਗਣਾ __cdecl _strtod_l(ਅਚਲ ਅੱਖਰ *_Str,ਅੱਖਰ **ਸਿਰਾ_Ptr,_locale_t _Locale);
  ਲੰਮਾ __cdecl strtol(ਅਚਲ ਅੱਖਰ *_Str,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਲੰਮਾ __cdecl _strtol_l(ਅਚਲ ਅੱਖਰ *_Str,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl strtoul(ਅਚਲ ਅੱਖਰ *_Str,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _strtoul_l(ਅਚਲ ਅੱਖਰ *_Str,ਅੱਖਰ **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_SYSTEM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_SYSTEM_DEFINED
  ਪੂਰਨ __cdecl system(ਅਚਲ ਅੱਖਰ *_Command);
#ਜੇ_ਅੰਤ
  _CRTIMP ਅੱਖਰ *__cdecl _ultoa(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ_2,ਅੱਖਰ *_Dest,ਪੂਰਨ _Radix);
  ਪੂਰਨ __cdecl wctomb(ਅੱਖਰ *_MbCh,wchar_t _WCh);
  _CRTIMP ਪੂਰਨ __cdecl _wctomb_l(ਅੱਖਰ *_MbCh,wchar_t _WCh,_locale_t _Locale);
  ਮਾਪ_t __cdecl wcstombs(ਅੱਖਰ *_Dest,ਅਚਲ wchar_t *ਸਰੋਤ_3,ਮਾਪ_t Max_ਗਿਣਤੀ);
  _CRTIMP ਮਾਪ_t __cdecl _wcstombs_l(ਅੱਖਰ *_Dest,ਅਚਲ wchar_t *ਸਰੋਤ_3,ਮਾਪ_t Max_ਗਿਣਤੀ,_locale_t _Locale);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CRT_ਵੰਡ_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CRT_ਵੰਡ_DEFINED
  ਖਾਲੀ *__cdecl ਸਿਫਰ_ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t ਅੰਕ_ਦਾ_Elements,ਮਾਪ_t ਮਾਪ_ਦਾ_Elements);
  ਖਾਲੀ __cdecl ਮੁਕਤ(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ);
  ਖਾਲੀ *__cdecl ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t ਮਾਪ_4);
  ਖਾਲੀ *__cdecl realloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t New_ਮਾਪ);
  _CRTIMP ਖਾਲੀ *__cdecl _recalloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਗਿਣਤੀ_6,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP ਖਾਲੀ __cdecl _aligned_free(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ);
  _CRTIMP ਖਾਲੀ *__cdecl _aligned_malloc(ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment);
  _CRTIMP ਖਾਲੀ *__cdecl aligned_ਵਿੱਥ_malloc(ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment,ਮਾਪ_t ਵਿੱਥ_2);
  _CRTIMP ਖਾਲੀ *__cdecl _aligned_realloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment);
  _CRTIMP ਖਾਲੀ *__cdecl _aligned_recalloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਗਿਣਤੀ_6,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment);
  _CRTIMP ਖਾਲੀ *__cdecl aligned_ਵਿੱਥ_realloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment,ਮਾਪ_t ਵਿੱਥ_2);
  _CRTIMP ਖਾਲੀ *__cdecl aligned_ਵਿੱਥ_recalloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਗਿਣਤੀ_6,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment,ਮਾਪ_t ਵਿੱਥ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDLIB_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(ਪੂਰਨ ਮੁੱਲ_2,wchar_t *_Dest,ਪੂਰਨ _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(ਲੰਮਾ ਮੁੱਲ_2,wchar_t *_Dest,ਪੂਰਨ _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ_2,wchar_t *_Dest,ਪੂਰਨ _Radix);
  ਦੁੱਗਣਾ __cdecl wcstod(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr);
  ਦਸ਼ਮਲਵ __cdecl wcstof(ਅਚਲ wchar_t *nptr, wchar_t **endptr);
#ਜੇ !defined __NO_ISOCEXT /* in libmingwex.a */
  ਦਸ਼ਮਲਵ __cdecl wcstof( ਅਚਲ wchar_t * __restrict__, wchar_t ** __restrict__);
  ਲੰਮਾ ਦੁੱਗਣਾ __cdecl wcstold(ਅਚਲ wchar_t * __restrict__, wchar_t ** __restrict__);
#ਜੇ_ਅੰਤ /* __NO_ISOCEXT */
  _CRTIMP ਦੁੱਗਣਾ __cdecl _wcstod_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,_locale_t _Locale);
  ਲੰਮਾ __cdecl wcstol(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਲੰਮਾ __cdecl _wcstol_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl wcstoul(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _wcstoul_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(ਅਚਲ wchar_t *_VarName);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WSYSTEM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WSYSTEM_DEFINED
  _CRTIMP ਪੂਰਨ __cdecl _wsystem(ਅਚਲ wchar_t *_Command);
#ਜੇ_ਅੰਤ
  _CRTIMP ਦੁੱਗਣਾ __cdecl _wtof(ਅਚਲ wchar_t *_Str);
  _CRTIMP ਦੁੱਗਣਾ __cdecl _wtof_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _wtoi(ਅਚਲ wchar_t *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _wtoi_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP ਲੰਮਾ __cdecl _wtol(ਅਚਲ wchar_t *_Str);
  _CRTIMP ਲੰਮਾ __cdecl _wtol_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,ਪੂਰਨ _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Val,wchar_t *_DstBuf,ਪੂਰਨ _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(ਅਚਲ wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(ਅਚਲ wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _wcstoui64(ਅਚਲ wchar_t *_Str,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _wcstoui64_l(ਅਚਲ wchar_t *_Str ,wchar_t **ਸਿਰਾ_Ptr,ਪੂਰਨ _Radix,_locale_t _Locale);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CVTBUFSIZE (309+40)
  _CRTIMP ਅੱਖਰ *__cdecl _fullpath(ਅੱਖਰ *ਭਰਿਆ_ਰਸਤਾ,ਅਚਲ ਅੱਖਰ *ਰਸਤਾ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP ਅੱਖਰ *__cdecl _ecvt(ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Digits,ਪੂਰਨ *_PtDec,ਪੂਰਨ *_PtSign);
  _CRTIMP ਅੱਖਰ *__cdecl _fcvt(ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Dec,ਪੂਰਨ *_PtDec,ਪੂਰਨ *_PtSign);
  _CRTIMP ਅੱਖਰ *__cdecl _gcvt(ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Digits,ਅੱਖਰ *_DstBuf);
  _CRTIMP ਪੂਰਨ __cdecl _atodbl(_CRT_DOUBLE *ਨਤੀਜਾ_2,ਅੱਖਰ *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _atoldbl(_LDOUBLE *ਨਤੀਜਾ_2,ਅੱਖਰ *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _atoflt(_CRT_FLOAT *ਨਤੀਜਾ_2,ਅੱਖਰ *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _atodbl_l(_CRT_DOUBLE *ਨਤੀਜਾ_2,ਅੱਖਰ *_Str,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _atoldbl_l(_LDOUBLE *ਨਤੀਜਾ_2,ਅੱਖਰ *_Str,_locale_t _Locale);
  _CRTIMP ਪੂਰਨ __cdecl _atoflt_l(_CRT_FLOAT *ਨਤੀਜਾ_2,ਅੱਖਰ *_Str,_locale_t _Locale);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _lrotl(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _Val,ਪੂਰਨ ਖਿਸਕਾਓ_2);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _lrotr(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _Val,ਪੂਰਨ ਖਿਸਕਾਓ_2);
  _CRTIMP ਖਾਲੀ __cdecl _makepath(ਅੱਖਰ *ਰਸਤਾ_2,ਅਚਲ ਅੱਖਰ *_Drive,ਅਚਲ ਅੱਖਰ *_Dir,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_PERROR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_PERROR_DEFINED
  ਖਾਲੀ __cdecl perror(ਅਚਲ ਅੱਖਰ *Err_ਸੁਨੇਹਾ);
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _putenv(ਅਚਲ ਅੱਖਰ *_EnvString);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl _rotl(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Val,ਪੂਰਨ ਖਿਸਕਾਓ_2);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _rotl64(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Val,ਪੂਰਨ ਖਿਸਕਾਓ_2);
#ਜੇ_ਅੰਤ
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl _rotr(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Val,ਪੂਰਨ ਖਿਸਕਾਓ_2);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _rotr64(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _Val,ਪੂਰਨ ਖਿਸਕਾਓ_2);
#ਜੇ_ਅੰਤ
  _CRTIMP ਖਾਲੀ __cdecl _searchenv(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_EnvVar,ਅੱਖਰ *ਨਤੀਜਾ_ਰਸਤਾ);
  _CRTIMP ਖਾਲੀ __cdecl _splitpath(ਅਚਲ ਅੱਖਰ *ਭਰਿਆ_ਰਸਤਾ,ਅੱਖਰ *_Drive,ਅੱਖਰ *_Dir,ਅੱਖਰ *_Filename,ਅੱਖਰ *_Ext);
  _CRTIMP ਖਾਲੀ __cdecl _swab(ਅੱਖਰ *_Buf1,ਅੱਖਰ *_Buf2,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDLIBP_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *ਭਰਿਆ_ਰਸਤਾ,ਅਚਲ wchar_t *ਰਸਤਾ_2,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP ਖਾਲੀ __cdecl _wmakepath(wchar_t *ਨਤੀਜਾ_ਰਸਤਾ,ਅਚਲ wchar_t *_Drive,ਅਚਲ wchar_t *_Dir,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_Ext);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WPERROR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WPERROR_DEFINED
  _CRTIMP ਖਾਲੀ __cdecl _wperror(ਅਚਲ wchar_t *Err_ਸੁਨੇਹਾ);
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _wputenv(ਅਚਲ wchar_t *_EnvString);
  _CRTIMP ਖਾਲੀ __cdecl _wsearchenv(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_EnvVar,wchar_t *ਨਤੀਜਾ_ਰਸਤਾ);
  _CRTIMP ਖਾਲੀ __cdecl _wsplitpath(ਅਚਲ wchar_t *ਭਰਿਆ_ਰਸਤਾ,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#ਜੇ_ਅੰਤ

  _CRTIMP ਖਾਲੀ __cdecl _beep(ਬਿਨਾਨਿਸ਼ਾਨੀ _Frequency,ਬਿਨਾਨਿਸ਼ਾਨੀ _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (int).  */
  _CRTIMP ਖਾਲੀ __cdecl _seterrormode(ਪੂਰਨ ਬਹੁਲਕ_3) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP ਖਾਲੀ __cdecl _sleep(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _Duration) __MINGW_ATTRIB_DEPRECATED;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NO_OLDNAMES
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਜੇ 0
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMINMAX
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ max
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ max(a,b) (((a) > (b)) ? (a) : (b))
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ min
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ min(a,b) (((a) < (b)) ? (a) : (b))
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ sys_errlist _sys_errlist
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ sys_nerr _sys_nerr
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ environ _environ
  ਅੱਖਰ *__cdecl ecvt(ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Digits,ਪੂਰਨ *_PtDec,ਪੂਰਨ *_PtSign);
  ਅੱਖਰ *__cdecl fcvt(ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Dec,ਪੂਰਨ *_PtDec,ਪੂਰਨ *_PtSign);
  ਅੱਖਰ *__cdecl gcvt(ਦੁੱਗਣਾ _Val,ਪੂਰਨ ਅੰਕ_ਦਾ_Digits,ਅੱਖਰ *_DstBuf);
  ਅੱਖਰ *__cdecl itoa(ਪੂਰਨ _Val,ਅੱਖਰ *_DstBuf,ਪੂਰਨ _Radix);
  ਅੱਖਰ *__cdecl ltoa(ਲੰਮਾ _Val,ਅੱਖਰ *_DstBuf,ਪੂਰਨ _Radix);
  ਪੂਰਨ __cdecl putenv(ਅਚਲ ਅੱਖਰ *_EnvString);
  ਖਾਲੀ __cdecl swab(ਅੱਖਰ *_Buf1,ਅੱਖਰ *_Buf2,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  ਅੱਖਰ *__cdecl ultoa(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _Val,ਅੱਖਰ *_Dstbuf,ਪੂਰਨ _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ !defined __NO_ISOCEXT /* externs in static libmingwex.a */

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਲੰਮਾ ਲੰਮਾ quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(ਲੰਮਾ ਲੰਮਾ, ਲੰਮਾ ਲੰਮਾ);

  __CRT_INLINE ਲੰਮਾ ਲੰਮਾ __cdecl llabs(ਲੰਮਾ ਲੰਮਾ _j) { ਵਾਪਸ (_j >= 0 ? _j : -_j); }

 #ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__ /* gr */
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ strtoll _strtoi64
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ strtoull _strtoui64
 #ਨਹੀਂਤਾਂ
  ਲੰਮਾ ਲੰਮਾ  __cdecl strtoll(ਅਚਲ ਅੱਖਰ* __restrict__, ਅੱਖਰ** __restrict, ਪੂਰਨ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ  __cdecl strtoull(ਅਚਲ ਅੱਖਰ* __restrict__, ਅੱਖਰ** __restrict__, ਪੂਰਨ);
 #ਜੇ_ਅੰਤ

  /* these are stubs for MS _i64 versions */
  ਲੰਮਾ ਲੰਮਾ  __cdecl atoll (ਅਚਲ ਅੱਖਰ *);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRICT_ANSI__
  ਲੰਮਾ ਲੰਮਾ  __cdecl wtoll (ਅਚਲ wchar_t *);
  ਅੱਖਰ *__cdecl lltoa (ਲੰਮਾ ਲੰਮਾ, ਅੱਖਰ *, ਪੂਰਨ);
  ਅੱਖਰ *__cdecl ulltoa (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ , ਅੱਖਰ *, ਪੂਰਨ);
  wchar_t *__cdecl lltow (ਲੰਮਾ ਲੰਮਾ, wchar_t *, ਪੂਰਨ);
  wchar_t *__cdecl ulltow (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ, wchar_t *, ਪੂਰਨ);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE ਲੰਮਾ ਲੰਮਾ  __cdecl atoll (ਅਚਲ ਅੱਖਰ * _c) { ਵਾਪਸ _atoi64 (_c); }
  __CRT_INLINE ਅੱਖਰ *__cdecl lltoa (ਲੰਮਾ ਲੰਮਾ _n, ਅੱਖਰ * _c, ਪੂਰਨ _i) { ਵਾਪਸ _i64toa (_n, _c, _i); }
  __CRT_INLINE ਅੱਖਰ *__cdecl ulltoa (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ _n, ਅੱਖਰ * _c, ਪੂਰਨ _i) { ਵਾਪਸ _ui64toa (_n, _c, _i); }
  __CRT_INLINE ਲੰਮਾ ਲੰਮਾ  __cdecl wtoll (ਅਚਲ wchar_t * _w) { ਵਾਪਸ _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (ਲੰਮਾ ਲੰਮਾ _n, wchar_t * _w, ਪੂਰਨ _i) { ਵਾਪਸ _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ _n, wchar_t * _w, ਪੂਰਨ _i) { ਵਾਪਸ _ui64tow (_n, _w, _i); }
#ਜੇ_ਅੰਤ /* (__STRICT_ANSI__)  */

#ਜੇ_ਅੰਤ /* !__NO_ISOCEXT */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਅਨ੍ਤਰ੍ਭਾਵ <sec_api/stdlib_s.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <malloc.h>

#ਜੇ_ਅੰਤ
