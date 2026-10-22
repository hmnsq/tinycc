//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#شامل <tchar.h>

#شامل <windows.h>
#شامل <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
تهی __set_app_type(صحیح);
تهی _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
صحیح APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, صحیح);
#وگرنه
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

تعریفنوع ساختار { صحیح newmode; } _startupinfo;
صحیح __cdecl __tgetmainargs(صحیح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحیح globb, _startupinfo*);

#شامل "crtinit.c"

ایستا صحیح go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    صحیح fShow;
    صحیح retval;

    GetStartupInfo(&si);
    اگر (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    وگرنه
        fShow = SW_SHOWDEFAULT;

    szCmd = پوچ, p = Get_Command_سطر();
    اگر (arg1)
        szCmd = _tcsstr(p, arg1);
    اگر (پوچ == szCmd)
        szCmd = _tcsdup(__T(""));
    وگرنه اگر (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#اگر defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(پوچ), پوچ, szCmd, fShow);
    run_dtors();
    بازگشت retval;
}

ایستا LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  بازگشت _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

صحیح _twinstart(تهی)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : پوچ));
}

صحیح _runtwinmain(صحیح argc, /* as tcc passed in */ نویسه **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    اگر (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#وگرنه
    __argc = argc, __targv = argv;
#endif
    بازگشت go_winmain(__argc > 1 ? __targv[1] : پوچ);
}
