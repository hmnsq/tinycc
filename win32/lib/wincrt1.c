//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ಅನ್ತರ್ಭಾವ <tchar.h>

#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
ಶೂನ್ಯ __set_app_type(ಪೂರ್ಣಾಙ್ಕ);
ಶೂನ್ಯ _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
ಪೂರ್ಣಾಙ್ಕ APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ಪೂರ್ಣಾಙ್ಕ);
#ಅನ್ಯಥಾ
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ newmode; } _startupinfo;
ಪೂರ್ಣಾಙ್ಕ __cdecl __tgetmainargs(ಪೂರ್ಣಾಙ್ಕ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ಪೂರ್ಣಾಙ್ಕ globb, _startupinfo*);

#ಅನ್ತರ್ಭಾವ "crtinit.c"

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ಪೂರ್ಣಾಙ್ಕ fShow;
    ಪೂರ್ಣಾಙ್ಕ retval;

    GetStartupInfo(&si);
    ಯದಿ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    ಅನ್ಯಥಾ
        fShow = SW_SHOWDEFAULT;

    szCmd = ರಿಕ್ತ, p = Get_Command_ಸಾಲು();
    ಯದಿ (arg1)
        szCmd = _tcsstr(p, arg1);
    ಯದಿ (ರಿಕ್ತ == szCmd)
        szCmd = _tcsdup(__T(""));
    ಅನ್ಯಥಾ ಯದಿ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ಯದಿ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ರಿಕ್ತ), ರಿಕ್ತ, szCmd, fShow);
    run_dtors();
    ಪ್ರತ್ಯಾಗಮ retval;
}

ಸ್ಥಿರ LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ಪ್ರತ್ಯಾಗಮ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ಪೂರ್ಣಾಙ್ಕ _twinstart(ಶೂನ್ಯ)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : ರಿಕ್ತ));
}

ಪೂರ್ಣಾಙ್ಕ _runtwinmain(ಪೂರ್ಣಾಙ್ಕ argc, /* as tcc passed in */ ವರ್ಣ **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ಯದಿ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#ಅನ್ಯಥಾ
    __argc = argc, __targv = argv;
#endif
    ಪ್ರತ್ಯಾಗಮ go_winmain(__argc > 1 ? __targv[1] : ರಿಕ್ತ);
}
