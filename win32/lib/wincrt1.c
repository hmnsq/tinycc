//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(정수);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
정수 APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, 정수);
#아니면
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef struct { 정수 newmode; } _startupinfo;
정수 __cdecl __tgetmainargs(정수 *pargc, _TCHAR ***pargv, _TCHAR ***penv, 정수 globb, _startupinfo*);

#include "crtinit.c"

static 정수 go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    정수 fShow;
    정수 retval;

    GetStartupInfo(&si);
    만약 (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    아니면
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    만약 (arg1)
        szCmd = _tcsstr(p, arg1);
    만약 (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    아니면 만약 (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#만약 defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    반환 retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  반환 _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

정수 _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

정수 _runtwinmain(정수 argc, /* as tcc passed in */ char **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    만약 (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#아니면
    __argc = argc, __targv = argv;
#endif
    반환 go_winmain(__argc > 1 ? __targv[1] : NULL);
}
