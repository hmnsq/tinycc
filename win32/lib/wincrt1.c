//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#અન્તર્ભાવ <tchar.h>

#અન્તર્ભાવ <windows.h>
#અન્તર્ભાવ <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
શૂન્ય __set_app_type(પૂર્ણાંક);
શૂન્ય _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
પૂર્ણાંક APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, પૂર્ણાંક);
#નહીંતર
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક newmode; } _startupinfo;
પૂર્ણાંક __cdecl __tgetmainargs(પૂર્ણાંક *pargc, _TCHAR ***pargv, _TCHAR ***penv, પૂર્ણાંક globb, _startupinfo*);

#અન્તર્ભાવ "crtinit.c"

સ્થિર પૂર્ણાંક go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    પૂર્ણાંક fShow;
    પૂર્ણાંક retval;

    GetStartupInfo(&si);
    જો (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    નહીંતર
        fShow = SW_SHOWDEFAULT;

    szCmd = ખાલી, p = Get_Command_લીટી();
    જો (arg1)
        szCmd = _tcsstr(p, arg1);
    જો (ખાલી == szCmd)
        szCmd = _tcsdup(__T(""));
    નહીંતર જો (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#જો defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ખાલી), ખાલી, szCmd, fShow);
    run_dtors();
    પાછા retval;
}

સ્થિર LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  પાછા _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

પૂર્ણાંક _twinstart(શૂન્ય)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : ખાલી));
}

પૂર્ણાંક _runtwinmain(પૂર્ણાંક argc, /* as tcc passed in */ અક્ષર **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    જો (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#નહીંતર
    __argc = argc, __targv = argv;
#endif
    પાછા go_winmain(__argc > 1 ? __targv[1] : ખાલી);
}
