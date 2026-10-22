//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#অন্তর্ভাব <tchar.h>

#অন্তর্ভাব <windows.h>
#অন্তর্ভাব <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
শূন্য __set_app_type(পূর্ণসংখ্যা);
শূন্য _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
পূর্ণসংখ্যা APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, পূর্ণসংখ্যা);
#অন্যথা
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

প্রকারলেখ কাঠামো { পূর্ণসংখ্যা newmode; } _startupinfo;
পূর্ণসংখ্যা __cdecl __tgetmainargs(পূর্ণসংখ্যা *pargc, _TCHAR ***pargv, _TCHAR ***penv, পূর্ণসংখ্যা globb, _startupinfo*);

#অন্তর্ভাব "crtinit.c"

স্থির পূর্ণসংখ্যা go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    পূর্ণসংখ্যা fShow;
    পূর্ণসংখ্যা retval;

    GetStartupInfo(&si);
    যদি (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    অন্যথা
        fShow = SW_SHOWDEFAULT;

    szCmd = ফাঁকা, p = Get_Command_সারি();
    যদি (arg1)
        szCmd = _tcsstr(p, arg1);
    যদি (ফাঁকা == szCmd)
        szCmd = _tcsdup(__T(""));
    অন্যথা যদি (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#যদি defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ফাঁকা), ফাঁকা, szCmd, fShow);
    run_dtors();
    ফেরত retval;
}

স্থির LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ফেরত _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

পূর্ণসংখ্যা _twinstart(শূন্য)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : ফাঁকা));
}

পূর্ণসংখ্যা _runtwinmain(পূর্ণসংখ্যা argc, /* as tcc passed in */ অক্ষর **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    যদি (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#অন্যথা
    __argc = argc, __targv = argv;
#endif
    ফেরত go_winmain(__argc > 1 ? __targv[1] : ফাঁকা);
}
