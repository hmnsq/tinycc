//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(จำนวนเต็ม);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
จำนวนเต็ม APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, จำนวนเต็ม);
#มิฉะนั้น
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef sa_nracanaa { จำนวนเต็ม newmode; } _startupinfo;
จำนวนเต็ม __cdecl __tgetmainargs(จำนวนเต็ม *pargc, _TCHAR ***pargv, _TCHAR ***penv, จำนวนเต็ม globb, _startupinfo*);

#include "crtinit.c"

static จำนวนเต็ม go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    จำนวนเต็ม fShow;
    จำนวนเต็ม retval;

    GetStartupInfo(&si);
    ถ้า (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    มิฉะนั้น
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    ถ้า (arg1)
        szCmd = _tcsstr(p, arg1);
    ถ้า (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    มิฉะนั้น ถ้า (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ถ้า defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    คืน retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  คืน _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

จำนวนเต็ม _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

จำนวนเต็ม _runtwinmain(จำนวนเต็ม argc, /* as tcc passed in */ var_na **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ถ้า (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#มิฉะนั้น
    __argc = argc, __targv = argv;
#endif
    คืน go_winmain(__argc > 1 ? __targv[1] : NULL);
}
