//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdlib.h>

#وصف_ڪريو __UNKNOWN_APP    0
#وصف_ڪريو __CONSOLE_APP    1
#وصف_ڪريو __GUI_APP        2
فراغ __set_app_type(صحيح);
فراغ _controlfp(بنانشان a, بنانشان b);

#جيڪڏهن_وصف_ٿيل _UNICODE
#وصف_ڪريو __tgetmainargs __wgetmainargs
#وصف_ڪريو _twinstart _wwinstart
#وصف_ڪريو _runtwinmain _runwwinmain
صحيح APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, صحيح);
#وإلا
#وصف_ڪريو __tgetmainargs __getmainargs
#وصف_ڪريو _twinstart _winstart
#وصف_ڪريو _runtwinmain _runwinmain
#جيڪڏهن_پورو

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
        fShow = si.w_Show_دري;
    وإلا
        fShow = SW_SHOWDEFAULT;

    szCmd = عدم, p = Get_Command_سٽ();
    إذا (arg1)
        szCmd = _tcsstr(p, arg1);
    إذا (عدم == szCmd)
        szCmd = _tcsdup(__T(""));
    وإلا إذا (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#إذا defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#جيڪڏهن_پورو
    لاڳيتو_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(عدم), عدم, szCmd, fShow);
    لاڳيتو_dtors();
    أرجع retval;
}

ساكن LONG WINAPI catch_sig(EXCEPTION_اشارا *ex)
{
  أرجع _XcptFilter(ex->Exception_رڪارڊ->Exception_ڪوڊ, ex);
}

صحيح _twinstart(فراغ)
{
    _startupinfo شروعات_info_con = {0};
    سيٽ_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &شروعات_info_con);
    ٻاهر_نڪرو(go_winmain(__argc > 1 ? __targv[1] : عدم));
}

صحيح _runtwinmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
#جيڪڏهن_وصف_ٿيل UNICODE
    _startupinfo شروعات_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &شروعات_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#وإلا
    __argc = argc, __targv = argv;
#جيڪڏهن_پورو
    أرجع go_winmain(__argc > 1 ? __targv[1] : عدم);
}
