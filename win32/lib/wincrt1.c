//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(පූර්ණ_සංඛ්‍යා);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
පූර්ණ_සංඛ්‍යා APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, පූර්ණ_සංඛ්‍යා);
#නැතහොත්
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef sa_nracanaa { පූර්ණ_සංඛ්‍යා newmode; } _startupinfo;
පූර්ණ_සංඛ්‍යා __cdecl __tgetmainargs(පූර්ණ_සංඛ්‍යා *pargc, _TCHAR ***pargv, _TCHAR ***penv, පූර්ණ_සංඛ්‍යා globb, _startupinfo*);

#include "crtinit.c"

static පූර්ණ_සංඛ්‍යා go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    පූර්ණ_සංඛ්‍යා fShow;
    පූර්ණ_සංඛ්‍යා retval;

    GetStartupInfo(&si);
    නම් (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    නැතහොත්
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    නම් (arg1)
        szCmd = _tcsstr(p, arg1);
    නම් (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    නැතහොත් නම් (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#නම් defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    ආපසු retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ආපසු _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

පූර්ණ_සංඛ්‍යා _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

පූර්ණ_සංඛ්‍යා _runtwinmain(පූර්ණ_සංඛ්‍යා argc, /* as tcc passed in */ var_na **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    නම් (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#නැතහොත්
    __argc = argc, __targv = argv;
#endif
    ආපසු go_winmain(__argc > 1 ? __targv[1] : NULL);
}
