// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdio.h>
#ضمن <stdlib.h>

#تعریف_کرو _UNKNOWN_APP    0
#تعریف_کرو _CONSOLE_APP    1
#تعریف_کرو _GUI_APP        2

#تعریف_کرو _MCW_PC         0x00030000 // Precision Control
#تعریف_کرو _PC_24          0x00020000 // 24 bits
#تعریف_کرو _PC_53          0x00010000 // 53 bits
#تعریف_کرو _PC_64          0x00000000 // 64 bits

#جے_تعریف_شدہ _UNICODE
#تعریف_کرو __tgetmainargs __wgetmainargs
#تعریف_کرو _tstart _wstart
#تعریف_کرو _tmain wmain
#تعریف_کرو _runtmain _runwmain
#وإلا
#تعریف_کرو __tgetmainargs __getmainargs
#تعریف_کرو _tstart شروع_5
#تعریف_کرو _tmain مکھ
#تعریف_کرو _runtmain _runmain
#جے_انت

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __cdecl __tgetmainargs(صحيح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحيح globb, _startupinfo*);
فراغ __cdecl __set_app_type(صحيح apptype);
بنانشانی صحيح __cdecl _controlfp(بنانشانی صحيح new_قدر, بنانشانی صحيح نقاب);
خارجي صحيح _tmain(صحيح argc, _TCHAR * argv[], _TCHAR * env[]);

#ضمن "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
صحيح _dowildcard;

ساكن LONG WINAPI catch_sig(EXCEPTION_سوچکاں *ex)
{
  أرجع _XcptFilter(ex->Exception_ریکارڈ->Exception_کوڈ, ex);
}

فراغ _tstart(فراغ)
{
    صحيح ret;

    _startupinfo شروع_info = {0};
    سیٹ_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#جے_انت

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &شروع_info);
    لگاتار_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    لگاتار_dtors();
    باہر_نکلو(ret);
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
#جے_انت
#جے_تعریف_شدہ UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#وإلا
    __argc = argc;
    __targv = argv;
#جے_انت
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#جے_انت
    لگاتار_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    لگاتار_dtors();
    __run_on_exit(ret);
    أرجع ret;
}

// =============================================
