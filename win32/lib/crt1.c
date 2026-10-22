// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdio.h>
#ضمن <stdlib.h>

#وصف_ڪريو _UNKNOWN_APP    0
#وصف_ڪريو _CONSOLE_APP    1
#وصف_ڪريو _GUI_APP        2

#وصف_ڪريو _MCW_PC         0x00030000 // Precision Control
#وصف_ڪريو _PC_24          0x00020000 // 24 bits
#وصف_ڪريو _PC_53          0x00010000 // 53 bits
#وصف_ڪريو _PC_64          0x00000000 // 64 bits

#جيڪڏهن_وصف_ٿيل _UNICODE
#وصف_ڪريو __tgetmainargs __wgetmainargs
#وصف_ڪريو _tstart _wstart
#وصف_ڪريو _tmain wmain
#وصف_ڪريو _runtmain _runwmain
#وإلا
#وصف_ڪريو __tgetmainargs __getmainargs
#وصف_ڪريو _tstart شروعات_5
#وصف_ڪريو _tmain مکيه
#وصف_ڪريو _runtmain _runmain
#جيڪڏهن_پورو

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __cdecl __tgetmainargs(صحيح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحيح globb, _startupinfo*);
فراغ __cdecl __set_app_type(صحيح apptype);
بنانشان صحيح __cdecl _controlfp(بنانشان صحيح new_قدر, بنانشان صحيح نقاب);
خارجي صحيح _tmain(صحيح argc, _TCHAR * argv[], _TCHAR * env[]);

#ضمن "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
صحيح _dowildcard;

ساكن LONG WINAPI catch_sig(EXCEPTION_اشارا *ex)
{
  أرجع _XcptFilter(ex->Exception_رڪارڊ->Exception_ڪوڊ, ex);
}

فراغ _tstart(فراغ)
{
    صحيح ret;

    _startupinfo شروعات_info = {0};
    سيٽ_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#جيڪڏهن_پورو

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &شروعات_info);
    لاڳيتو_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    لاڳيتو_dtors();
    ٻاهر_نڪرو(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) خارجي صحيح __run_on_exit();

صحيح _runtmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
    صحيح ret;
#إذا defined UNICODE || defined __aarch64__
    _startupinfo شروعات_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &شروعات_info);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#وإلا
    __argc = argc;
    __targv = argv;
#جيڪڏهن_پورو
#إذا defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#جيڪڏهن_پورو
    لاڳيتو_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    لاڳيتو_dtors();
    __run_on_exit(ret);
    أرجع ret;
}

// =============================================
