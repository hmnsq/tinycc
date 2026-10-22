//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#ଅନ୍ତର୍ଭାଵ <tchar.h>

#ଅନ୍ତର୍ଭାଵ <windows.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
ଶୂନ୍ୟ __set_app_type(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ଶୂନ୍ୟ _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
ପୂର୍ଣ୍ଣସଂଖ୍ୟା APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
#ଅନ୍ୟଥା
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା newmode; } _startupinfo;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __tgetmainargs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pargc, _TCHAR ***pargv, _TCHAR ***penv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା globb, _startupinfo*);

#ଅନ୍ତର୍ଭାଵ "crtinit.c"

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fShow;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା retval;

    GetStartupInfo(&si);
    ଯଦି (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    ଅନ୍ୟଥା
        fShow = SW_SHOWDEFAULT;

    szCmd = ଖାଲି, p = Get_Command_ଧାଡ଼ି();
    ଯଦି (arg1)
        szCmd = _tcsstr(p, arg1);
    ଯଦି (ଖାଲି == szCmd)
        szCmd = _tcsdup(__T(""));
    ଅନ୍ୟଥା ଯଦି (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ଯଦି defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ଖାଲି), ଖାଲି, szCmd, fShow);
    run_dtors();
    ଫେରନ୍ତୁ retval;
}

ସ୍ଥିର LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  ଫେରନ୍ତୁ _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା _twinstart(ଶୂନ୍ୟ)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : ଖାଲି));
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା _runtwinmain(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, /* as tcc passed in */ ଅକ୍ଷର **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ଯଦି (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#ଅନ୍ୟଥା
    __argc = argc, __targv = argv;
#endif
    ଫେରନ୍ତୁ go_winmain(__argc > 1 ? __targv[1] : ଖାଲି);
}
