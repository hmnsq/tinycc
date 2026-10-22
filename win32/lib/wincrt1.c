//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(ཧྲིལ);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
ཧྲིལ APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ཧྲིལ);
#དེ་མིན
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef sa_nracanaa { ཧྲིལ newmode; } _startupinfo;
ཧྲིལ __cdecl __tgetmainargs(ཧྲིལ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ཧྲིལ globb, _startupinfo*);

#include "crtinit.c"

static ཧྲིལ go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ཧྲིལ fShow;
    ཧྲིལ retval;

    GetStartupInfo(&si);
    གལ་སྲིད (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    དེ་མིན
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    གལ་སྲིད (arg1)
        szCmd = _tcsstr(p, arg1);
    གལ་སྲིད (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    དེ་མིན གལ་སྲིད (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#གལ་སྲིད defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    ལོག retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ལོག _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ཧྲིལ _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

ཧྲིལ _runtwinmain(ཧྲིལ argc, /* as tcc passed in */ var_na **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    གལ་སྲིད (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#དེ་མིན
    __argc = argc, __targv = argv;
#endif
    ལོག go_winmain(__argc > 1 ? __targv[1] : NULL);
}
