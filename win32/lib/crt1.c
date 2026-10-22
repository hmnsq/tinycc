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
#ບໍ່ດັ່ງນັ້ນ
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain main
#define _runtmain _runmain
#endif

typedef sa_nracanaa { ຈຳນວນເຕັມ newmode; } _startupinfo;
ຈຳນວນເຕັມ __cdecl __tgetmainargs(ຈຳນວນເຕັມ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ຈຳນວນເຕັມ globb, _startupinfo*);
void __cdecl __set_app_type(ຈຳນວນເຕັມ apptype);
unsigned ຈຳນວນເຕັມ __cdecl _controlfp(unsigned ຈຳນວນເຕັມ new_value, unsigned ຈຳນວນເຕັມ mask);
extern ຈຳນວນເຕັມ _tmain(ຈຳນວນເຕັມ argc, _TCHAR * argv[], _TCHAR * env[]);

#include "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
ຈຳນວນເຕັມ _dowildcard;

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ສົ່ງຄືນ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

void _tstart(void)
{
    ຈຳນວນເຕັມ ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#ຖ້າ defined __i386__ || defined __x86_64__
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

__attribute__((weak)) extern ຈຳນວນເຕັມ __run_on_exit();

ຈຳນວນເຕັມ _runtmain(ຈຳນວນເຕັມ argc, /* as tcc passed in */ var_na **argv)
{
    ຈຳນວນເຕັມ ret;
#ຖ້າ defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    ຖ້າ (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#ບໍ່ດັ່ງນັ້ນ
    __argc = argc;
    __targv = argv;
#endif
#ຖ້າ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    ສົ່ງຄືນ ret;
}

// =============================================
