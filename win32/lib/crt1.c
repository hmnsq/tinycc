// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#अन्तर्भाव <tchar.h>

#अन्तर्भाव <windows.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>

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
#अन्यथा
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain main
#define _runtmain _runmain
#endif

प्रकारव्याख्या संरचना { पूर्णांक newmode; } _startupinfo;
पूर्णांक __cdecl __tgetmainargs(पूर्णांक *pargc, _TCHAR ***pargv, _TCHAR ***penv, पूर्णांक globb, _startupinfo*);
शून्य __cdecl __set_app_type(पूर्णांक apptype);
अचिन्हित पूर्णांक __cdecl _controlfp(अचिन्हित पूर्णांक new_मूल्य, अचिन्हित पूर्णांक mask);
बाह्य पूर्णांक _tmain(पूर्णांक argc, _TCHAR * argv[], _TCHAR * env[]);

#अन्तर्भाव "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
पूर्णांक _dowildcard;

स्थिर LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  परत _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

शून्य _tstart(शून्य)
{
    पूर्णांक ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#जर defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    run_dtors();
    निकास(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) बाह्य पूर्णांक __run_on_exit();

पूर्णांक _runtmain(पूर्णांक argc, /* as tcc passed in */ अक्षर **argv)
{
    पूर्णांक ret;
#जर defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#endif
#ifdef UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    जर (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#अन्यथा
    __argc = argc;
    __targv = argv;
#endif
#जर defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#endif
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    ख_साफ(मानक_निकास);
    ख_साफ(मानक_त्रुटि);
    run_dtors();
    __run_on_exit(ret);
    परत ret;
}

// =============================================
