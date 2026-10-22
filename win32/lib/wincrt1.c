//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#समावेश <tchar.h>

#समावेश <windows.h>
#समावेश <stdlib.h>

#घोषणा __UNKNOWN_APP    0
#घोषणा __CONSOLE_APP    1
#घोषणा __GUI_APP        2
व्योम __set_app_type(पूर्णांक);
व्योम _controlfp(अचिन्हित a, अचिन्हित b);

#अगर_घोषित _UNICODE
#घोषणा __tgetmainargs __wgetmainargs
#घोषणा _twinstart _wwinstart
#घोषणा _runtwinmain _runwwinmain
पूर्णांक APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, पूर्णांक);
#अन्यथा
#घोषणा __tgetmainargs __getmainargs
#घोषणा _twinstart _winstart
#घोषणा _runtwinmain _runwinmain
#पूर्ण_अगर

प्रकार काष्ठा { पूर्णांक newmode; } _startupinfo;
पूर्णांक __cdecl __tgetmainargs(पूर्णांक *pargc, _TCHAR ***pargv, _TCHAR ***penv, पूर्णांक globb, _startupinfo*);

#समावेश "crtinit.c"

अटल पूर्णांक go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    पूर्णांक fShow;
    पूर्णांक retval;

    GetStartupInfo(&si);
    अगर (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    अन्यथा
        fShow = SW_SHOWDEFAULT;

    szCmd = शून्य, p = Get_Command_पंक्ति();
    अगर (arg1)
        szCmd = _tcsstr(p, arg1);
    अगर (शून्य == szCmd)
        szCmd = _tcsdup(__T(""));
    अन्यथा अगर (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#अगर defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#पूर्ण_अगर
    run_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(शून्य), शून्य, szCmd, fShow);
    run_dtors();
    वापस retval;
}

अटल LONG WINAPI catch_sig(EXCEPTION_POINTERS *ex)
{
  वापस _XcptFilter(ex->ExceptionRecord->ExceptionCode, ex);
}

पूर्णांक _twinstart(व्योम)
{
    _startupinfo start_info_con = {0};
    SetUnhandledExceptionFilter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    निकास(go_winmain(__argc > 1 ? __targv[1] : शून्य));
}

पूर्णांक _runtwinmain(पूर्णांक argc, /* as tcc passed in */ अक्षर **argv)
{
#अगर_घोषित UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    अगर (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#अन्यथा
    __argc = argc, __targv = argv;
#पूर्ण_अगर
    वापस go_winmain(__argc > 1 ? __targv[1] : शून्य);
}
