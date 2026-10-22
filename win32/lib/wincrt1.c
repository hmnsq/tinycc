//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(puur_naa_nka);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
puur_naa_nka APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, puur_naa_nka);
#ᰀᰧᰀ
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef sa_nracanaa { puur_naa_nka newmode; } _startupinfo;
puur_naa_nka __cdecl __tgetmainargs(puur_naa_nka *pargc, _TCHAR ***pargv, _TCHAR ***penv, puur_naa_nka globb, _startupinfo*);

#include "crtinit.c"

static puur_naa_nka go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    puur_naa_nka fShow;
    puur_naa_nka retval;

    GetStartupInfo(&si);
    ᰀᰧ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    ᰀᰧᰀ
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    ᰀᰧ (arg1)
        szCmd = _tcsstr(p, arg1);
    ᰀᰧ (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    ᰀᰧᰀ ᰀᰧ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ᰀᰧ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    ᰀᰧᰌ retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ᰀᰧᰌ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

puur_naa_nka _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

puur_naa_nka _runtwinmain(puur_naa_nka argc, /* as tcc passed in */ var_na **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ᰀᰧ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#ᰀᰧᰀ
    __argc = argc, __targv = argv;
#endif
    ᰀᰧᰌ go_winmain(__argc > 1 ? __targv[1] : NULL);
}
