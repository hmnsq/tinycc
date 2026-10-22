//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(ចំនួនគត់);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
ចំនួនគត់ APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ចំនួនគត់);
#បើមិនដូច្នេះ
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef sa_nracanaa { ចំនួនគត់ newmode; } _startupinfo;
ចំនួនគត់ __cdecl __tgetmainargs(ចំនួនគត់ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ចំនួនគត់ globb, _startupinfo*);

#include "crtinit.c"

static ចំនួនគត់ go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ចំនួនគត់ fShow;
    ចំនួនគត់ retval;

    GetStartupInfo(&si);
    ប្រសិនបើ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    បើមិនដូច្នេះ
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    ប្រសិនបើ (arg1)
        szCmd = _tcsstr(p, arg1);
    ប្រសិនបើ (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    បើមិនដូច្នេះ ប្រសិនបើ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ប្រសិនបើ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    ត្រឡប់ retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ត្រឡប់ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ចំនួនគត់ _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

ចំនួនគត់ _runtwinmain(ចំនួនគត់ argc, /* as tcc passed in */ var_na **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ប្រសិនបើ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#បើមិនដូច្នេះ
    __argc = argc, __targv = argv;
#endif
    ត្រឡប់ go_winmain(__argc > 1 ? __targv[1] : NULL);
}
