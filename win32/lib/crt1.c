// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#समावेश <tchar.h>

#समावेश <windows.h>
#समावेश <stdio.h>
#समावेश <stdlib.h>

#घोषणा _UNKNOWN_APP    0
#घोषणा _CONSOLE_APP    1
#घोषणा _GUI_APP        2

#घोषणा _MCW_PC         0x00030000 // Precision Control
#घोषणा _PC_24          0x00020000 // 24 bits
#घोषणा _PC_53          0x00010000 // 53 bits
#घोषणा _PC_64          0x00000000 // 64 bits

#अगर_घोषित _UNICODE
#घोषणा __tgetmainargs __wgetmainargs
#घोषणा _tstart _wstart
#घोषणा _tmain wmain
#घोषणा _runtmain _runwmain
#अन्यथा
#घोषणा __tgetmainargs __getmainargs
#घोषणा _tstart _start
#घोषणा _tmain मुख्य
#घोषणा _runtmain _runmain
#पूर्ण_अगर

प्रकार काष्ठा { पूर्णांक newmode; } _startupinfo;
पूर्णांक __cdecl __tgetmainargs(पूर्णांक *pargc, _TCHAR ***pargv, _TCHAR ***penv, पूर्णांक globb, _startupinfo*);
व्योम __cdecl __set_app_type(पूर्णांक apptype);
अचिन्हित पूर्णांक __cdecl _controlfp(अचिन्हित पूर्णांक new_मूल्य, अचिन्हित पूर्णांक mask);
बाह्य पूर्णांक _tmain(पूर्णांक argc, _TCHAR * argv[], _TCHAR * env[]);

#समावेश "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
पूर्णांक _dowildcard;

अटल LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  वापस _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

व्योम _tstart(व्योम)
{
    पूर्णांक ret;

    _startupinfo start_info = {0};
    SetUnhandledExceptionFilter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#अगर defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#पूर्ण_अगर

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
#अगर defined UNICODE || defined __aarch64__
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
#पूर्ण_अगर
#अगर_घोषित UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    अगर (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#अन्यथा
    __argc = argc;
    __targv = argv;
#पूर्ण_अगर
#अगर defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#पूर्ण_अगर
    run_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    ख_साफ(मानक_निकास);
    ख_साफ(मानक_त्रुटि);
    run_dtors();
    __run_on_exit(ret);
    वापस ret;
}

// =============================================
