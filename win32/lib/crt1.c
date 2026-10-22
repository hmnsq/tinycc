// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#അന്തര്ഭാവ <tchar.h>

#അന്തര്ഭാവ <windows.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <stdlib.h>

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
#അല്ലെങ്കിൽ
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain പ്രധാന
#define _runtmain _runmain
#endif

തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ newmode; } _startupinfo;
പൂർണ്ണസംഖ്യ __cdecl __tgetmainargs(പൂർണ്ണസംഖ്യ *pargc, _TCHAR ***pargv, _TCHAR ***penv, പൂർണ്ണസംഖ്യ globb, _startupinfo*);
ശൂന്യം __cdecl __set_app_type(പൂർണ്ണസംഖ്യ apptype);
unsigned പൂർണ്ണസംഖ്യ __cdecl _controlfp(unsigned പൂർണ്ണസംഖ്യ new_മൂല്യം, unsigned പൂർണ്ണസംഖ്യ mask);
ബാഹ്യ പൂർണ്ണസംഖ്യ _tmain(പൂർണ്ണസംഖ്യ argc, _TCHAR * argv[], _TCHAR * env[]);

#അന്തര്ഭാവ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
പൂർണ്ണസംഖ്യ _dowildcard;

സ്ഥിതം LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  തിരികെ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ശൂന്യം _tstart(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#എങ്കിൽ defined __i386__ || defined __x86_64__
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

__attribute__((weak)) ബാഹ്യ പൂർണ്ണസംഖ്യ __run_on_exit();

പൂർണ്ണസംഖ്യ _runtmain(പൂർണ്ണസംഖ്യ argc, /* as tcc passed in */ അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ ret;
#എങ്കിൽ defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    എങ്കിൽ (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#അല്ലെങ്കിൽ
    __argc = argc;
    __targv = argv;
#endif
#എങ്കിൽ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    run_dtors();
    __run_on_exit(ret);
    തിരികെ ret;
}

// =============================================
