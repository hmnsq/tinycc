//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#അന്തര്ഭാവ <tchar.h>

#അന്തര്ഭാവ <windows.h>
#അന്തര്ഭാവ <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
ശൂന്യം __set_app_type(പൂർണ്ണസംഖ്യ);
ശൂന്യം _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
പൂർണ്ണസംഖ്യ APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, പൂർണ്ണസംഖ്യ);
#അല്ലെങ്കിൽ
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ newmode; } _startupinfo;
പൂർണ്ണസംഖ്യ __cdecl __tgetmainargs(പൂർണ്ണസംഖ്യ *pargc, _TCHAR ***pargv, _TCHAR ***penv, പൂർണ്ണസംഖ്യ globb, _startupinfo*);

#അന്തര്ഭാവ "crtinit.c"

സ്ഥിതം പൂർണ്ണസംഖ്യ go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    പൂർണ്ണസംഖ്യ fShow;
    പൂർണ്ണസംഖ്യ retval;

    GetStartupInfo(&si);
    എങ്കിൽ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    അല്ലെങ്കിൽ
        fShow = SW_SHOWDEFAULT;

    szCmd = ശൂന്യ, p = Get_Command_വരി();
    എങ്കിൽ (arg1)
        szCmd = _tcsstr(p, arg1);
    എങ്കിൽ (ശൂന്യ == szCmd)
        szCmd = _tcsdup(__T(""));
    അല്ലെങ്കിൽ എങ്കിൽ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#എങ്കിൽ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ശൂന്യ), ശൂന്യ, szCmd, fShow);
    run_dtors();
    തിരികെ retval;
}

സ്ഥിതം LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  തിരികെ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

പൂർണ്ണസംഖ്യ _twinstart(ശൂന്യം)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : ശൂന്യ));
}

പൂർണ്ണസംഖ്യ _runtwinmain(പൂർണ്ണസംഖ്യ argc, /* as tcc passed in */ അക്ഷരം **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    എങ്കിൽ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#അല്ലെങ്കിൽ
    __argc = argc, __targv = argv;
#endif
    തിരികെ go_winmain(__argc > 1 ? __targv[1] : ശൂന്യ);
}
