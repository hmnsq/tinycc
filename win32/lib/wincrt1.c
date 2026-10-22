//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(số_nguyên);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
số_nguyên APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, số_nguyên);
#không_thì
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef struct { số_nguyên newmode; } _startupinfo;
số_nguyên __cdecl __tgetmainargs(số_nguyên *pargc, _TCHAR ***pargv, _TCHAR ***penv, số_nguyên globb, _startupinfo*);

#include "crtinit.c"

static số_nguyên go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    số_nguyên fShow;
    số_nguyên retval;

    GetStartupInfo(&si);
    nếu (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    không_thì
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    nếu (arg1)
        szCmd = _tcsstr(p, arg1);
    nếu (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    không_thì nếu (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#nếu defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    trả_về retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  trả_về _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

số_nguyên _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

số_nguyên _runtwinmain(số_nguyên argc, /* as tcc passed in */ char **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    nếu (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#không_thì
    __argc = argc, __targv = argv;
#endif
    trả_về go_winmain(__argc > 1 ? __targv[1] : NULL);
}
