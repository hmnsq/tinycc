// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdio.h>
#ضمن <stdlib.h>

#define _UNKNOWN_APP    0
#define _CONSOLE_APP    1
#define _GUI_APP        2

#define _MCW_PC         0x00030000 // Precision Control
#define _PC_24          0x00020000 // 24 bits
#define _PC_53          0x00010000 // 53 bits
#define _PC_64          0x00000000 // 64 bits

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _tstart _wstart
#define _tmain wmain
#define _runtmain _runwmain
#אחרת
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain main
#define _runtmain _runmain
#endif

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __cdecl __tgetmainargs(صحيح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحيح globb, _startupinfo*);
فراغ __cdecl __set_app_type(صحيح apptype);
unsigned صحيح __cdecl _controlfp(unsigned صحيح new_value, unsigned صحيح mask);
خارجي صحيح _tmain(صحيح argc, _TCHAR * argv[], _TCHAR * env[]);

#ضمن "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
صحيح _dowildcard;

ساكن LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  החזר _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

فراغ _tstart(فراغ)
{
    صحيح ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#אם defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    run_dtors();
    exit(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) خارجي صحيح __run_on_exit();

صحيح _runtmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
    صحيح ret;
#אם defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    אם (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#אחרת
    __argc = argc;
    __targv = argv;
#endif
#אם defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    החזר ret;
}

// =============================================
