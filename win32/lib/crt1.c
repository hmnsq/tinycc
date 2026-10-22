// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#شامل <tchar.h>

#شامل <windows.h>
#شامل <stdio.h>
#شامل <stdlib.h>

#تعریف_کرو _UNKNOWN_APP    0
#تعریف_کرو _CONSOLE_APP    1
#تعریف_کرو _GUI_APP        2

#تعریف_کرو _MCW_PC         0x00030000 // Precision Control
#تعریف_کرو _PC_24          0x00020000 // 24 bits
#تعریف_کرو _PC_53          0x00010000 // 53 bits
#تعریف_کرو _PC_64          0x00000000 // 64 bits

#اگر_تعریف_شدہ _UNICODE
#تعریف_کرو __tgetmainargs __wgetmainargs
#تعریف_کرو _tstart _wstart
#تعریف_کرو _tmain wmain
#تعریف_کرو _runtmain _runwmain
#ورنہ
#تعریف_کرو __tgetmainargs __getmainargs
#تعریف_کرو _tstart آغاز_5
#تعریف_کرو _tmain مین
#تعریف_کرو _runtmain _runmain
#اگر_ختم

قسمتعریف ساخت { صحیح newmode; } _startupinfo;
صحیح __cdecl __tgetmainargs(صحیح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحیح globb, _startupinfo*);
خالی __cdecl __set_app_type(صحیح apptype);
غیرعلامتی صحیح __cdecl _controlfp(غیرعلامتی صحیح new_قدر, غیرعلامتی صحیح نقاب);
خارجی صحیح _tmain(صحیح argc, _TCHAR * argv[], _TCHAR * env[]);

#شامل "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
صحیح _dowildcard;

ساکن LONG WINAPI catch_sig(EXCEPTION_اشارے *ex)
{
  واپس _XcptFilter(ex->Exception_ریکارڈ->Exception_رمز, ex);
}

خالی _tstart(خالی)
{
    صحیح ret;

    _startupinfo آغاز_info = {0};
    سیٹ_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#اگر defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#اگر_ختم

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &آغاز_info);
    تسلسل_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    تسلسل_dtors();
    باہر_نکلو(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) خارجی صحیح __run_on_exit();

صحیح _runtmain(صحیح argc, /* as tcc passed in */ حرف **argv)
{
    صحیح ret;
#اگر defined UNICODE || defined __aarch64__
    _startupinfo آغاز_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &آغاز_info);
#اگر_ختم
#اگر_تعریف_شدہ UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    اگر (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#ورنہ
    __argc = argc;
    __targv = argv;
#اگر_ختم
#اگر defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#اگر_ختم
    تسلسل_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    تسلسل_dtors();
    __run_on_exit(ret);
    واپس ret;
}

// =============================================
