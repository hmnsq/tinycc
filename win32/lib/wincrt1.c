//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdlib.h>

#تعریف_کړه __UNKNOWN_APP    0
#تعریف_کړه __CONSOLE_APP    1
#تعریف_کړه __GUI_APP        2
فراغ __set_app_type(صحيح);
فراغ _controlfp(بینښه a, بینښه b);

#که_تعریف_شوی _UNICODE
#تعریف_کړه __tgetmainargs __wgetmainargs
#تعریف_کړه _twinstart _wwinstart
#تعریف_کړه _runtwinmain _runwwinmain
صحيح APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, صحيح);
#وإلا
#تعریف_کړه __tgetmainargs __getmainargs
#تعریف_کړه _twinstart _winstart
#تعریف_کړه _runtwinmain _runwinmain
#د_که_پای

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
        fShow = si.w_Show_کړکۍ;
    وإلا
        fShow = SW_SHOWDEFAULT;

    szCmd = عدم, p = Get_Command_کرښه();
    إذا (arg1)
        szCmd = _tcsstr(p, arg1);
    إذا (عدم == szCmd)
        szCmd = _tcsdup(__T(""));
    وإلا إذا (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#إذا defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#د_که_پای
    پرلپسې_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(عدم), عدم, szCmd, fShow);
    پرلپسې_dtors();
    أرجع retval;
}

ساكن LONG WINAPI catch_sig(EXCEPTION_اشارې *ex)
{
  أرجع _XcptFilter(ex->Exception_ریکارډ->Exception_کوډ, ex);
}

صحيح _twinstart(فراغ)
{
    _startupinfo پیل_info_con = {0};
    سېټ_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &پیل_info_con);
    وتل(go_winmain(__argc > 1 ? __targv[1] : عدم));
}

صحيح _runtwinmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
#که_تعریف_شوی UNICODE
    _startupinfo پیل_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &پیل_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#وإلا
    __argc = argc, __targv = argv;
#د_که_پای
    أرجع go_winmain(__argc > 1 ? __targv[1] : عدم);
}
