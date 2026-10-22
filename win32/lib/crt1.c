// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

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
#아니면
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain main
#define _runtmain _runmain
#endif

typedef struct { 정수 newmode; } _startupinfo;
정수 __cdecl __tgetmainargs(정수 *pargc, _TCHAR ***pargv, _TCHAR ***penv, 정수 globb, _startupinfo*);
void __cdecl __set_app_type(정수 apptype);
unsigned 정수 __cdecl _controlfp(unsigned 정수 new_value, unsigned 정수 mask);
extern 정수 _tmain(정수 argc, _TCHAR * argv[], _TCHAR * env[]);

#include "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
정수 _dowildcard;

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  반환 _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

void _tstart(void)
{
    정수 ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#만약 defined __i386__ || defined __x86_64__
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

__attribute__((weak)) extern 정수 __run_on_exit();

정수 _runtmain(정수 argc, /* as tcc passed in */ char **argv)
{
    정수 ret;
#만약 defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    만약 (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#아니면
    __argc = argc;
    __targv = argv;
#endif
#만약 defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    반환 ret;
}

// =============================================
