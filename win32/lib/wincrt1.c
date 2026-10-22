//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(ຈຳນວນເຕັມ);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
ຈຳນວນເຕັມ APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ຈຳນວນເຕັມ);
#ບໍ່ດັ່ງນັ້ນ
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef sa_nracanaa { ຈຳນວນເຕັມ newmode; } _startupinfo;
ຈຳນວນເຕັມ __cdecl __tgetmainargs(ຈຳນວນເຕັມ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ຈຳນວນເຕັມ globb, _startupinfo*);

#include "crtinit.c"

static ຈຳນວນເຕັມ go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ຈຳນວນເຕັມ fShow;
    ຈຳນວນເຕັມ retval;

    GetStartupInfo(&si);
    ຖ້າ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    ບໍ່ດັ່ງນັ້ນ
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    ຖ້າ (arg1)
        szCmd = _tcsstr(p, arg1);
    ຖ້າ (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    ບໍ່ດັ່ງນັ້ນ ຖ້າ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ຖ້າ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    ສົ່ງຄືນ retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ສົ່ງຄືນ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ຈຳນວນເຕັມ _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

ຈຳນວນເຕັມ _runtwinmain(ຈຳນວນເຕັມ argc, /* as tcc passed in */ var_na **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ຖ້າ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#ບໍ່ດັ່ງນັ້ນ
    __argc = argc, __targv = argv;
#endif
    ສົ່ງຄືນ go_winmain(__argc > 1 ? __targv[1] : NULL);
}
