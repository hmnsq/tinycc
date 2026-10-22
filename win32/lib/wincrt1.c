//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(整数);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
整数 APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, 整数);
#否则
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef struct { 整数 newmode; } _startupinfo;
整数 __cdecl __tgetmainargs(整数 *pargc, _TCHAR ***pargv, _TCHAR ***penv, 整数 globb, _startupinfo*);

#include "crtinit.c"

static 整数 go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    整数 fShow;
    整数 retval;

    GetStartupInfo(&si);
    もし (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    否则
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    もし (arg1)
        szCmd = _tcsstr(p, arg1);
    もし (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    否则 もし (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#もし defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    戻る retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  戻る _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

整数 _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

整数 _runtwinmain(整数 argc, /* as tcc passed in */ char **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    もし (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#否则
    __argc = argc, __targv = argv;
#endif
    戻る go_winmain(__argc > 1 ? __targv[1] : NULL);
}
