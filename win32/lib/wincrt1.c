//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
فراغ __set_app_type(صحيح);
فراغ _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
صحيح APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, صحيح);
#وإلا
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

تعريفنوع بنية { صحيح newmode; } _startupinfo;
صحيح __cdecl __tgetmainargs(صحيح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحيح globb, _startupinfo*);

#ضمن "crtinit.c"

ساكن صحيح go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    صحيح fShow;
    صحيح retval;

    GetStartupInfo(&si);
    إذا (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    وإلا
        fShow = SW_SHOWDEFAULT;

    szCmd = عدم, p = Get_Command_سطر();
    إذا (arg1)
        szCmd = _tcsstr(p, arg1);
    إذا (عدم == szCmd)
        szCmd = _tcsdup(__T(""));
    وإلا إذا (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#إذا defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(عدم), عدم, szCmd, fShow);
    run_dtors();
    إرجاع retval;
}

ساكن LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  إرجاع _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

صحيح _twinstart(فراغ)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : عدم));
}

صحيح _runtwinmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#وإلا
    __argc = argc, __targv = argv;
#endif
    إرجاع go_winmain(__argc > 1 ? __targv[1] : عدم);
}
