// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ಅನ್ತರ್ಭಾವ <tchar.h>

#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>

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
#ಅನ್ಯಥಾ
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain main
#define _runtmain _runmain
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ newmode; } _startupinfo;
ಪೂರ್ಣಾಙ್ಕ __cdecl __tgetmainargs(ಪೂರ್ಣಾಙ್ಕ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ಪೂರ್ಣಾಙ್ಕ globb, _startupinfo*);
ಶೂನ್ಯ __cdecl __set_app_type(ಪೂರ್ಣಾಙ್ಕ apptype);
unsigned ಪೂರ್ಣಾಙ್ಕ __cdecl _controlfp(unsigned ಪೂರ್ಣಾಙ್ಕ new_ಮೌಲ್ಯ, unsigned ಪೂರ್ಣಾಙ್ಕ mask);
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ _tmain(ಪೂರ್ಣಾಙ್ಕ argc, _TCHAR * argv[], _TCHAR * env[]);

#ಅನ್ತರ್ಭಾವ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
ಪೂರ್ಣಾಙ್ಕ _dowildcard;

ಸ್ಥಿರ LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ಪ್ರತ್ಯಾಗಮ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ಶೂನ್ಯ _tstart(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#ಯದಿ defined __i386__ || defined __x86_64__
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

__attribute__((weak)) ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __run_on_exit();

ಪೂರ್ಣಾಙ್ಕ _runtmain(ಪೂರ್ಣಾಙ್ಕ argc, /* as tcc passed in */ ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ ret;
#ಯದಿ defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    ಯದಿ (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#ಅನ್ಯಥಾ
    __argc = argc;
    __targv = argv;
#endif
#ಯದಿ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    ಪ್ರತ್ಯಾಗಮ ret;
}

// =============================================
