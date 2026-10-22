//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(цяло);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
цяло APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, цяло);
#иначе
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef struct { цяло newmode; } _startupinfo;
цяло __cdecl __tgetmainargs(цяло *pargc, _TCHAR ***pargv, _TCHAR ***penv, цяло globb, _startupinfo*);

#include "crtinit.c"

static цяло go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    цяло fShow;
    цяло retval;

    GetStartupInfo(&si);
    ако (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    иначе
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    ако (arg1)
        szCmd = _tcsstr(p, arg1);
    ако (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    иначе ако (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ако defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    върни retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  върни _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

цяло _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

цяло _runtwinmain(цяло argc, /* as tcc passed in */ char **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ако (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#иначе
    __argc = argc, __targv = argv;
#endif
    върни go_winmain(__argc > 1 ? __targv[1] : NULL);
}
