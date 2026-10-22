//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#अन्तर्भाव <tchar.h>

#अन्तर्भाव <windows.h>
#अन्तर्भाव <stdlib.h>

#define __UNKNOWN_APP    0
#define __CONSOLE_APP    1
#define __GUI_APP        2
शून्य __set_app_type(पूर्णांक);
शून्य _controlfp(अचिन्हित a, अचिन्हित b);

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _twinstart _wwinstart
#define _runtwinmain _runwwinmain
पूर्णांक APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, पूर्णांक);
#अन्यथा
#define __tgetmainargs __getmainargs
#define _twinstart _winstart
#define _runtwinmain _runwinmain
#endif

प्रकारव्याख्या संरचना { पूर्णांक newmode; } _startupinfo;
पूर्णांक __cdecl __tgetmainargs(पूर्णांक *pargc, _TCHAR ***pargv, _TCHAR ***penv, पूर्णांक globb, _startupinfo*);

#अन्तर्भाव "crtinit.c"

स्थिर पूर्णांक go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    पूर्णांक fShow;
    पूर्णांक retval;

    GetStartupInfo(&si);
    जर (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    अन्यथा
        fShow = SW_SHOWDEFAULT;

    szCmd = रिक्त, p = Get_Command_ओळ();
    जर (arg1)
        szCmd = _tcsstr(p, arg1);
    जर (रिक्त == szCmd)
        szCmd = _tcsdup(__T(""));
    अन्यथा जर (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#जर defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#endif
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(रिक्त), रिक्त, szCmd, fShow);
    run_dtors();
    परत retval;
}

स्थिर LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  परत _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

पूर्णांक _twinstart(शून्य)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    निकास(go_winmain(__argc > 1 ? __targv[1] : रिक्त));
}

पूर्णांक _runtwinmain(पूर्णांक argc, /* as tcc passed in */ अक्षर **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    जर (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#अन्यथा
    __argc = argc, __targv = argv;
#endif
    परत go_winmain(__argc > 1 ? __targv[1] : रिक्त);
}
