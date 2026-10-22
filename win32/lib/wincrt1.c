//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

#include <windows.h>
#include <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
void __set_app_type(ကိန်းပြည့်);
void _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
ကိန်းပြည့် APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ကိန်းပြည့်);
#မဟုတ်ပါက
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

typedef sa_nracanaa { ကိန်းပြည့် newmode; } _startupinfo;
ကိန်းပြည့် __cdecl __tgetmainargs(ကိန်းပြည့် *pargc, _TCHAR ***pargv, _TCHAR ***penv, ကိန်းပြည့် globb, _startupinfo*);

#include "crtinit.c"

static ကိန်းပြည့် go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ကိန်းပြည့် fShow;
    ကိန်းပြည့် retval;

    GetStartupInfo(&si);
    အကယ်၍ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    မဟုတ်ပါက
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    အကယ်၍ (arg1)
        szCmd = _tcsstr(p, arg1);
    အကယ်၍ (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    မဟုတ်ပါက အကယ်၍ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#အကယ်၍ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
    run_dtors();
    ပြန်ပေး retval;
}

static LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ပြန်ပေး _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ကိန်းပြည့် _twinstart(void)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

ကိန်းပြည့် _runtwinmain(ကိန်းပြည့် argc, /* as tcc passed in */ var_na **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    အကယ်၍ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#မဟုတ်ပါက
    __argc = argc, __targv = argv;
#endif
    ပြန်ပေး go_winmain(__argc > 1 ? __targv[1] : NULL);
}
