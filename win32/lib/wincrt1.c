//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(целое);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
целое APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, целое);
#иначе
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef struct { целое newmode; } _startupinfo;
целое __cdecl __tgetmainargs(целое *pargc, _TCHAR ***pargv, _TCHAR ***penv, целое globb, _startupinfo*);

#include "crtinit.c"

static целое go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    целое fShow;
    целое retval;

    GetStartupInfo(&si);
    если (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    иначе
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    если (arg1)
        szCmd = _tcsstr(p, arg1);
    если (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    иначе если (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#если defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    вернуть retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  вернуть _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

целое _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

целое _runtwinmain(целое argc, /* as tcc passed in */ char **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    если (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#иначе
    __argc = argc, __targv = argv;
#endif
    вернуть go_winmain(__argc > 1 ? __targv[1] : NULL);
}
