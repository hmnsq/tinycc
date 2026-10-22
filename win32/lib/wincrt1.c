//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#شامل <tchar.h>

#شامل <windows.h>
#شامل <stdlib.h>

#تعریف_کرو __UNKNOWN_APP    0
#تعریف_کرو __CONSOLE_APP    1
#تعریف_کرو __GUI_APP        2
خالی __set_app_type(صحیح);
خالی _controlfp(غیرعلامتی a, غیرعلامتی b);

#اگر_تعریف_شدہ _UNICODE
#تعریف_کرو __tgetmainargs __wgetmainargs
#تعریف_کرو _twinstart _wwinstart
#تعریف_کرو _runtwinmain _runwwinmain
صحیح APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, صحیح);
#ورنہ
#تعریف_کرو __tgetmainargs __getmainargs
#تعریف_کرو _twinstart _winstart
#تعریف_کرو _runtwinmain _runwinmain
#اگر_ختم

قسمتعریف ساخت { صحیح newmode; } _startupinfo;
صحیح __cdecl __tgetmainargs(صحیح *pargc, _TCHAR ***pargv, _TCHAR ***penv, صحیح globb, _startupinfo*);

#شامل "crtinit.c"

ساکن صحیح go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    صحیح fShow;
    صحیح retval;

    GetStartupInfo(&si);
    اگر (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.w_Show_کھڑکی;
    ورنہ
        fShow = SW_SHOWDEFAULT;

    szCmd = تہی, p = Get_Command_سطر();
    اگر (arg1)
        szCmd = _tcsstr(p, arg1);
    اگر (تہی == szCmd)
        szCmd = _tcsdup(__T(""));
    ورنہ اگر (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#اگر defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#اگر_ختم
    تسلسل_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(تہی), تہی, szCmd, fShow);
    تسلسل_dtors();
    واپس retval;
}

ساکن LONG WINAPI catch_sig(EXCEPTION_اشارے *ex)
{
  واپس _XcptFilter(ex->Exception_ریکارڈ->Exception_رمز, ex);
}

صحیح _twinstart(خالی)
{
    _startupinfo آغاز_info_con = {0};
    سیٹ_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &آغاز_info_con);
    باہر_نکلو(go_winmain(__argc > 1 ? __targv[1] : تہی));
}

صحیح _runtwinmain(صحیح argc, /* as tcc passed in */ حرف **argv)
{
#اگر_تعریف_شدہ UNICODE
    _startupinfo آغاز_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &آغاز_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    اگر (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#ورنہ
    __argc = argc, __targv = argv;
#اگر_ختم
    واپس go_winmain(__argc > 1 ? __targv[1] : تہی);
}
