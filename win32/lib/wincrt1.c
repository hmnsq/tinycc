//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#अन्तर्भाव <tchar.h>

#अन्तर्भाव <windows.h>
#अन्तर्भाव <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
शून्य __set_app_type(पूर्णाङ्क);
शून्य _controlfp(unsigned a, unsigned b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
पूर्णाङ्क APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, पूर्णाङ्क);
#अञ्ञथा
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

प्रकारनिर्देश संरचना { पूर्णाङ्क newmode; } _startupinfo;
पूर्णाङ्क __cdecl __tgetmainargs(पूर्णाङ्क *pargc, _TCHAR ***pargv, _TCHAR ***penv, पूर्णाङ्क globb, _startupinfo*);

#अन्तर्भाव "crtinit.c"

स्थिर पूर्णाङ्क go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    पूर्णाङ्क fShow;
    पूर्णाङ्क retval;

    GetStartupInfo(&si);
    सचे (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    अञ्ञथा
        fShow = SW_SHOWDEFAULT;

    szCmd = रिक्त, p = Get_Command_पङ्क्तिः();
    सचे (arg1)
        szCmd = _tcsstr(p, arg1);
    सचे (रिक्त == szCmd)
        szCmd = _tcsdup(__T(""));
    अञ्ञथा सचे (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#सचे defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(रिक्त), रिक्त, szCmd, fShow);
    run_dtors();
    पटिनिवत्त retval;
}

स्थिर LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  पटिनिवत्त _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

पूर्णाङ्क _twinstart(शून्य)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : रिक्त));
}

पूर्णाङ्क _runtwinmain(पूर्णाङ्क argc, /* as tcc passed in */ वर्ण **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    सचे (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#अञ्ञथा
    __argc = argc, __targv = argv;
#endif
    पटिनिवत्त go_winmain(__argc > 1 ? __targv[1] : रिक्त);
}
