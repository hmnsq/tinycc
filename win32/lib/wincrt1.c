//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#அந்தர்பாவ <tchar.h>

#அந்தர்பாவ <windows.h>
#அந்தர்பாவ <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
வெறுமை __set_app_type(முழு);
வெறுமை _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
முழு APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, முழு);
#இல்லையெனில்
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

வகைவரை கட்டமைப்பு { முழு newmode; } _startupinfo;
முழு __cdecl __tgetmainargs(முழு *pargc, _TCHAR ***pargv, _TCHAR ***penv, முழு globb, _startupinfo*);

#அந்தர்பாவ "crtinit.c"

நிலையான முழு go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    முழு fShow;
    முழு retval;

    GetStartupInfo(&si);
    எனில் (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    இல்லையெனில்
        fShow = SW_SHOWDEFAULT;

    szCmd = வெற்று, p = Get_Command_வரி();
    எனில் (arg1)
        szCmd = _tcsstr(p, arg1);
    எனில் (வெற்று == szCmd)
        szCmd = _tcsdup(__T(""));
    இல்லையெனில் எனில் (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#எனில் defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(வெற்று), வெற்று, szCmd, fShow);
    run_dtors();
    திரும்பு retval;
}

நிலையான LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  திரும்பு _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

முழு _twinstart(வெறுமை)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : வெற்று));
}

முழு _runtwinmain(முழு argc, /* as tcc passed in */ எழுத்து **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    எனில் (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#இல்லையெனில்
    __argc = argc, __targv = argv;
#endif
    திரும்பு go_winmain(__argc > 1 ? __targv[1] : வெற்று);
}
