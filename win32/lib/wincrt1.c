//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ಅನ್ತರ್ಭಾವ <tchar.h>

#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>

#ವ್ಯಾಖ್ಯಾನಿಸು __UNKNOWN_APP    0
#ವ್ಯಾಖ್ಯಾನಿಸು __CONSOLE_APP    1
#ವ್ಯಾಖ್ಯಾನಿಸು __GUI_APP        2
ಶೂನ್ಯ __set_app_type(ಪೂರ್ಣಾಂಕ);
ಶೂನ್ಯ _controlfp(ಚಿಹ್ನೆರಹಿತ a, ಚಿಹ್ನೆರಹಿತ b);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು __tgetmainargs __wgetmainargs
#ವ್ಯಾಖ್ಯಾನಿಸು _twinstart _wwinstart
#ವ್ಯಾಖ್ಯಾನಿಸು _runtwinmain _runwwinmain
ಪೂರ್ಣಾಂಕ APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ಪೂರ್ಣಾಂಕ);
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __tgetmainargs __getmainargs
#ವ್ಯಾಖ್ಯಾನಿಸು _twinstart _winstart
#ವ್ಯಾಖ್ಯಾನಿಸು _runtwinmain _runwinmain
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ newmode; } _startupinfo;
ಪೂರ್ಣಾಂಕ __cdecl __tgetmainargs(ಪೂರ್ಣಾಂಕ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ಪೂರ್ಣಾಂಕ globb, _startupinfo*);

#ಅನ್ತರ್ಭಾವ "crtinit.c"

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ಪೂರ್ಣಾಂಕ fShow;
    ಪೂರ್ಣಾಂಕ retval;

    GetStartupInfo(&si);
    ಆದರೆ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.w_Show_ಕಿಟಕಿ;
    ಇಲ್ಲದಿದ್ದರೆ
        fShow = SW_SHOWDEFAULT;

    szCmd = ಖಾಲಿ, p = Get_Command_ಸಾಲು();
    ಆದರೆ (arg1)
        szCmd = _tcsstr(p, arg1);
    ಆದರೆ (ಖಾಲಿ == szCmd)
        szCmd = _tcsdup(__T(""));
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ಆದರೆ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#ಆದರೆ_ಅಂತ್ಯ
    ಸತತ_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ಖಾಲಿ), ಖಾಲಿ, szCmd, fShow);
    ಸತತ_dtors();
    ಹಿಂತಿರುಗಿ retval;
}

ಸ್ಥಿರ LONG WINAPI catch_sig(EXCEPTION_ಸೂಚಕಗಳು *ex)
{
  ಹಿಂತಿರುಗಿ _XcptFilter(ex->Exception_ದಾಖಲೆ->Exception_ಸಂಕೇತ, ex);
}

ಪೂರ್ಣಾಂಕ _twinstart(ಶೂನ್ಯ)
{
    _startupinfo ಆರಂಭ_info_con = {0};
    ಗಣ_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ಆರಂಭ_info_con);
    ನಿರ್ಗಮಿಸು(go_winmain(__argc > 1 ? __targv[1] : ಖಾಲಿ));
}

ಪೂರ್ಣಾಂಕ _runtwinmain(ಪೂರ್ಣಾಂಕ argc, /* as tcc passed in */ ಅಕ್ಷರ **argv)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
    _startupinfo ಆರಂಭ_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ಆರಂಭ_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ಆದರೆ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#ಇಲ್ಲದಿದ್ದರೆ
    __argc = argc, __targv = argv;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ go_winmain(__argc > 1 ? __targv[1] : ಖಾಲಿ);
}
