// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdio.h>
#ضمن <stdlib.h>

#تعریف_کن _UNKNOWN_APP    0
#تعریف_کن _CONSOLE_APP    1
#تعریف_کن _GUI_APP        2

#تعریف_کن _MCW_PC         0x00030000 // Precision Control
#تعریف_کن _PC_24          0x00020000 // 24 bits
#تعریف_کن _PC_53          0x00010000 // 53 bits
#تعریف_کن _PC_64          0x00000000 // 64 bits

#اگر_تعریف_شده _UNICODE
#تعریف_کن __tgetmainargs __wgetmainargs
#تعریف_کن _tstart _wstart
#تعریف_کن _tmain wmain
#تعریف_کن _runtmain _runwmain
#وإلا
#تعریف_کن __tgetmainargs __getmainargs
#تعریف_کن _tstart شروع_5
#تعریف_کن _tmain اصلی
#تعریف_کن _runtmain _runmain
#پایان_اگر

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __cdecl __tgetmainargs(صحيح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحيح globb, _startupinfo*);
فراغ __cdecl __set_app_type(صحيح apptype);
بیعلامت صحيح __cdecl _controlfp(بیعلامت صحيح new_مقدار, بیعلامت صحيح ماسک);
خارجي صحيح _tmain(صحيح argc, _TCHAR * argv[], _TCHAR * env[]);

#ضمن "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
صحيح _dowildcard;

ساكن LONG WINAPI catch_sig(EXCEPTION_اشارهگرها *ex)
{
  أرجع _XcptFilter(ex->Exception_رکورد->Exception_کد, ex);
}

فراغ _tstart(فراغ)
{
    صحيح ret;

    _startupinfo شروع_info = {0};
    مجموعه_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#پایان_اگر

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &شروع_info);
    پیاپی_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    پیاپی_dtors();
    خروج(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) خارجي صحيح __run_on_exit();

صحيح _runtmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
    صحيح ret;
#إذا defined UNICODE || defined __aarch64__
    _startupinfo شروع_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &شروع_info);
#پایان_اگر
#اگر_تعریف_شده UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#وإلا
    __argc = argc;
    __targv = argv;
#پایان_اگر
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#پایان_اگر
    پیاپی_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    پیاپی_dtors();
    __run_on_exit(ret);
    أرجع ret;
}

// =============================================
