// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#அந்தர்பாவ <tchar.h>

#அந்தர்பாவ <windows.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <stdlib.h>

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
#இல்லையெனில்
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain முதன்மை
#define _runtmain _runmain
#endif

வகைவரை கட்டமைப்பு { முழு newmode; } _startupinfo;
முழு __cdecl __tgetmainargs(முழு *pargc, _TCHAR ***pargv, _TCHAR ***penv, முழு globb, _startupinfo*);
வெறுமை __cdecl __set_app_type(முழு apptype);
unsigned முழு __cdecl _controlfp(unsigned முழு new_மதிப்பு, unsigned முழு mask);
வெளி முழு _tmain(முழு argc, _TCHAR * argv[], _TCHAR * env[]);

#அந்தர்பாவ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
முழு _dowildcard;

நிலையான LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  திரும்பு _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

வெறுமை _tstart(வெறுமை)
{
    முழு ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#எனில் defined __i386__ || defined __x86_64__
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

__attribute__((weak)) வெளி முழு __run_on_exit();

முழு _runtmain(முழு argc, /* as tcc passed in */ எழுத்து **argv)
{
    முழு ret;
#எனில் defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    எனில் (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#இல்லையெனில்
    __argc = argc;
    __targv = argv;
#endif
#எனில் defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    திரும்பு ret;
}

// =============================================
