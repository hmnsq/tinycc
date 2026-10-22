//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(ціле);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
ціле APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ціле);
#інакше
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef struct { ціле newmode; } _startupinfo;
ціле __cdecl __tgetmainargs(ціле *pargc, _TCHAR ***pargv, _TCHAR ***penv, ціле globb, _startupinfo*);

#include "crtinit.c"

static ціле go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ціле fShow;
    ціле retval;

    GetStartupInfo(&si);
    якщо (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    інакше
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    якщо (arg1)
        szCmd = _tcsstr(p, arg1);
    якщо (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    інакше якщо (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#якщо defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    повернути retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  повернути _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ціле _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

ціле _runtwinmain(ціле argc, /* as tcc passed in */ char **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    якщо (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#інакше
    __argc = argc, __targv = argv;
#endif
    повернути go_winmain(__argc > 1 ? __targv[1] : NULL);
}
