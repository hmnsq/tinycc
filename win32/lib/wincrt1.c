//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ضمن <tchar.h>

#ضمن <windows.h>
#ضمن <stdlib.h>

#تعریف_کرو __UNKNOWN_APP    0
#تعریف_کرو __CONSOLE_APP    1
#تعریف_کرو __GUI_APP        2
فراغ __set_app_type(صحيح);
فراغ _controlfp(بنانشانی a, بنانشانی b);

#جے_تعریف_شدہ _UNICODE
#تعریف_کرو __tgetmainargs __wgetmainargs
#تعریف_کرو _twinstart _wwinstart
#تعریف_کرو _runtwinmain _runwwinmain
صحيح APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, صحيح);
#وإلا
#تعریف_کرو __tgetmainargs __getmainargs
#تعریف_کرو _twinstart _winstart
#تعریف_کرو _runtwinmain _runwinmain
#جے_انت

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
        fShow = si.w_Show_کھڑکی;
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
#جے_انت
    لگاتار_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(عدم), عدم, szCmd, fShow);
    لگاتار_dtors();
    أرجع retval;
}

ساكن LONG WINAPI catch_sig(EXCEPTION_سوچکاں *ex)
{
  أرجع _XcptFilter(ex->Exception_ریکارڈ->Exception_کوڈ, ex);
}

صحيح _twinstart(فراغ)
{
    _startupinfo شروع_info_con = {0};
    سیٹ_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &شروع_info_con);
    باہر_نکلو(go_winmain(__argc > 1 ? __targv[1] : عدم));
}

صحيح _runtwinmain(صحيح argc, /* as tcc passed in */ حرف **argv)
{
#جے_تعریف_شدہ UNICODE
    _startupinfo شروع_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &شروع_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    إذا (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#وإلا
    __argc = argc, __targv = argv;
#جے_انت
    أرجع go_winmain(__argc > 1 ? __targv[1] : عدم);
}
