//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ਅਨ੍ਤਰ੍ਭਾਵ <tchar.h>

#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __UNKNOWN_APP    0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CONSOLE_APP    1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __GUI_APP        2
ਖਾਲੀ __set_app_type(ਪੂਰਨ);
ਖਾਲੀ _controlfp(ਬਿਨਾਨਿਸ਼ਾਨੀ a, ਬਿਨਾਨਿਸ਼ਾਨੀ b);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgetmainargs __wgetmainargs
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _twinstart _wwinstart
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _runtwinmain _runwwinmain
ਪੂਰਨ APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ਪੂਰਨ);
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgetmainargs __getmainargs
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _twinstart _winstart
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _runtwinmain _runwinmain
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ newmode; } _startupinfo;
ਪੂਰਨ __cdecl __tgetmainargs(ਪੂਰਨ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ਪੂਰਨ globb, _startupinfo*);

#ਅਨ੍ਤਰ੍ਭਾਵ "crtinit.c"

ਸਥਿਰ ਪੂਰਨ go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ਪੂਰਨ fShow;
    ਪੂਰਨ retval;

    GetStartupInfo(&si);
    ਜੇ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.w_Show_ਖਿੜਕੀ;
    ਨਹੀਂਤਾਂ
        fShow = SW_SHOWDEFAULT;

    szCmd = ਨਿਰਾ, p = Get_Command_ਸਤਰ();
    ਜੇ (arg1)
        szCmd = _tcsstr(p, arg1);
    ਜੇ (ਨਿਰਾ == szCmd)
        szCmd = _tcsdup(__T(""));
    ਨਹੀਂਤਾਂ ਜੇ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ਜੇ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#ਜੇ_ਅੰਤ
    ਲੜੀਵਾਰ_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ਨਿਰਾ), ਨਿਰਾ, szCmd, fShow);
    ਲੜੀਵਾਰ_dtors();
    ਵਾਪਸ retval;
}

ਸਥਿਰ LONG WINAPI catch_sig(EXCEPTION_ਸੂਚਕ_ਸਾਰੇ *ex)
{
  ਵਾਪਸ _XcptFilter(ex->Exception_ਰਿਕਾਰਡ->Exception_ਕੋਡ, ex);
}

ਪੂਰਨ _twinstart(ਖਾਲੀ)
{
    _startupinfo ਸ਼ੁਰੂ_info_con = {0};
    ਸੈੱਟ_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ਸ਼ੁਰੂ_info_con);
    ਬਾਹਰ_ਨਿਕਲੋ(go_winmain(__argc > 1 ? __targv[1] : ਨਿਰਾ));
}

ਪੂਰਨ _runtwinmain(ਪੂਰਨ argc, /* as tcc passed in */ ਅੱਖਰ **argv)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
    _startupinfo ਸ਼ੁਰੂ_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ਸ਼ੁਰੂ_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ਜੇ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#ਨਹੀਂਤਾਂ
    __argc = argc, __targv = argv;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ go_winmain(__argc > 1 ? __targv[1] : ਨਿਰਾ);
}
