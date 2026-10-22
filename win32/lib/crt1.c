// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdio.h>
#ضمن <stdlib.h>

#تعریف_کړه _UNKNOWN_APP    0
#تعریف_کړه _CONSOLE_APP    1
#تعریف_کړه _GUI_APP        2

#تعریف_کړه _MCW_PC         0x00030000 // Precision Control
#تعریف_کړه _PC_24          0x00020000 // 24 bits
#تعریف_کړه _PC_53          0x00010000 // 53 bits
#تعریف_کړه _PC_64          0x00000000 // 64 bits

#که_تعریف_شوی _UNICODE
#تعریف_کړه __tgetmainargs __wgetmainargs
#تعریف_کړه _tstart _wstart
#تعریف_کړه _tmain wmain
#تعریف_کړه _runtmain _runwmain
#وإلا
#تعریف_کړه __tgetmainargs __getmainargs
#تعریف_کړه _tstart پیل_5
#تعریف_کړه _tmain اصلي
#تعریف_کړه _runtmain _runmain
#د_که_پای

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __cdecl __tgetmainargs(صحيح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحيح globb, _startupinfo*);
فراغ __cdecl __set_app_type(صحيح apptype);
بینښه صحيح __cdecl _controlfp(بینښه صحيح new_ارزښت, بینښه صحيح ماسک);
خارجي صحيح _tmain(صحيح argc, _TCHAR * argv[], _TCHAR * env[]);

#ضمن "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
صحيح _dowildcard;

ساكن LONG WINAPI catch_sig(EXCEPTION_اشارې *ex)
{
  أرجع _XcptFilter(ex->Exception_ریکارډ->Exception_کوډ, ex);
}

فراغ _tstart(فراغ)
{
    صحيح ret;

    _startupinfo پیل_info = {0};
    سېټ_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#د_که_پای

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &پیل_info);
    پرلپسې_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    پرلپسې_dtors();
    وتل(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) خارجي صحيح __run_on_exit();

صحيح _runtmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
    صحيح ret;
#إذا defined UNICODE || defined __aarch64__
    _startupinfo پیل_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &پیل_info);
#د_که_پای
#که_تعریف_شوی UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#وإلا
    __argc = argc;
    __targv = argv;
#د_که_پای
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#د_که_پای
    پرلپسې_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    پرلپسې_dtors();
    __run_on_exit(ret);
    أرجع ret;
}

// =============================================
