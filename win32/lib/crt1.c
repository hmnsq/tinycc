// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#অন্তর্ভাব <tchar.h>

#অন্তর্ভাব <windows.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdlib.h>

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
#অন্যথা
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain main
#define _runtmain _runmain
#endif

প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক newmode; } _startupinfo;
পূর্ণাঙ্ক __cdecl __tgetmainargs(পূর্ণাঙ্ক *pargc, _TCHAR ***pargv, _TCHAR ***penv, পূর্ণাঙ্ক globb, _startupinfo*);
শূন্য __cdecl __set_app_type(পূর্ণাঙ্ক apptype);
unsigned পূর্ণাঙ্ক __cdecl _controlfp(unsigned পূর্ণাঙ্ক new_মান, unsigned পূর্ণাঙ্ক mask);
বাহ্য পূর্ণাঙ্ক _tmain(পূর্ণাঙ্ক argc, _TCHAR * argv[], _TCHAR * env[]);

#অন্তর্ভাব "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
পূর্ণাঙ্ক _dowildcard;

স্থির LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  প্রত্যাগম _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

শূন্য _tstart(শূন্য)
{
    পূর্ণাঙ্ক ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#যদি defined __i386__ || defined __x86_64__
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

__attribute__((weak)) বাহ্য পূর্ণাঙ্ক __run_on_exit();

পূর্ণাঙ্ক _runtmain(পূর্ণাঙ্ক argc, /* as tcc passed in */ বর্ণ **argv)
{
    পূর্ণাঙ্ক ret;
#যদি defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    যদি (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#অন্যথা
    __argc = argc;
    __targv = argv;
#endif
#যদি defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    প্রত্যাগম ret;
}

// =============================================
