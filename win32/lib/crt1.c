// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ଅନ୍ତର୍ଭାଵ <tchar.h>

#ଅନ୍ତର୍ଭାଵ <windows.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>

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
#ଅନ୍ୟଥା
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain ମୁଖ୍ୟ
#define _runtmain _runmain
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା newmode; } _startupinfo;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __tgetmainargs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pargc, _TCHAR ***pargv, _TCHAR ***penv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା globb, _startupinfo*);
ଶୂନ୍ୟ __cdecl __set_app_type(ପୂର୍ଣ୍ଣସଂଖ୍ୟା apptype);
unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _controlfp(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା new_ମୂଲ୍ୟ, unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା mask);
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା _tmain(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, _TCHAR * argv[], _TCHAR * env[]);

#ଅନ୍ତର୍ଭାଵ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _dowildcard;

ସ୍ଥିର LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ଫେରନ୍ତୁ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ଶୂନ୍ୟ _tstart(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#ଯଦି defined __i386__ || defined __x86_64__
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

__attribute__((weak)) ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __run_on_exit();

ପୂର୍ଣ୍ଣସଂଖ୍ୟା _runtmain(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, /* as tcc passed in */ ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;
#ଯଦି defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    ଯଦି (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#ଅନ୍ୟଥା
    __argc = argc;
    __targv = argv;
#endif
#ଯଦି defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    ଫେରନ୍ତୁ ret;
}

// =============================================
