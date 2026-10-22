// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#અન્તર્ભાવ <tchar.h>

#અન્તર્ભાવ <windows.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <stdlib.h>

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
#નહીંતર
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain મુખ્ય
#define _runtmain _runmain
#endif

પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક newmode; } _startupinfo;
પૂર્ણાંક __cdecl __tgetmainargs(પૂર્ણાંક *pargc, _TCHAR ***pargv, _TCHAR ***penv, પૂર્ણાંક globb, _startupinfo*);
શૂન્ય __cdecl __set_app_type(પૂર્ણાંક apptype);
unsigned પૂર્ણાંક __cdecl _controlfp(unsigned પૂર્ણાંક new_કિંમત, unsigned પૂર્ણાંક mask);
બાહ્ય પૂર્ણાંક _tmain(પૂર્ણાંક argc, _TCHAR * argv[], _TCHAR * env[]);

#અન્તર્ભાવ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
પૂર્ણાંક _dowildcard;

સ્થિર LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  પાછા _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

શૂન્ય _tstart(શૂન્ય)
{
    પૂર્ણાંક ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#જો defined __i386__ || defined __x86_64__
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

__attribute__((weak)) બાહ્ય પૂર્ણાંક __run_on_exit();

પૂર્ણાંક _runtmain(પૂર્ણાંક argc, /* as tcc passed in */ અક્ષર **argv)
{
    પૂર્ણાંક ret;
#જો defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    જો (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#નહીંતર
    __argc = argc;
    __targv = argv;
#endif
#જો defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    પાછા ret;
}

// =============================================
