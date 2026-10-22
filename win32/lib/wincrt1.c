//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#అన్తర్భావ <tchar.h>

#అన్తర్భావ <windows.h>
#అన్తర్భావ <stdlib.h>

#నిర్వచించు __UNKNOWN_APP    0
#నిర్వచించు __CONSOLE_APP    1
#నిర్వచించు __GUI_APP        2
శూన్య __set_app_type(పూర్ణాంకం);
శూన్య _controlfp(గుర్తులేని a, గుర్తులేని b);

#నిర్వచితమైతే _UNICODE
#నిర్వచించు __tgetmainargs __wgetmainargs
#నిర్వచించు _twinstart _wwinstart
#నిర్వచించు _runtwinmain _runwwinmain
పూర్ణాంకం APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, పూర్ణాంకం);
#లేకపోతే
#నిర్వచించు __tgetmainargs __getmainargs
#నిర్వచించు _twinstart _winstart
#నిర్వచించు _runtwinmain _runwinmain
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం { పూర్ణాంకం newmode; } _startupinfo;
పూర్ణాంకం __cdecl __tgetmainargs(పూర్ణాంకం *pargc, _TCHAR ***pargv, _TCHAR ***penv, పూర్ణాంకం globb, _startupinfo*);

#అన్తర్భావ "crtinit.c"

స్థిర పూర్ణాంకం go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    పూర్ణాంకం fShow;
    పూర్ణాంకం retval;

    GetStartupInfo(&si);
    ఒకవేళ (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.w_Show_కిటికీ;
    లేకపోతే
        fShow = SW_SHOWDEFAULT;

    szCmd = ఖాళీ, p = Get_Command_పంక్తి();
    ఒకవేళ (arg1)
        szCmd = _tcsstr(p, arg1);
    ఒకవేళ (ఖాళీ == szCmd)
        szCmd = _tcsdup(__T(""));
    లేకపోతే ఒకవేళ (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#ఒకవేళ defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#అయితే_ముగింపు
    నిరంతరం_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(ఖాళీ), ఖాళీ, szCmd, fShow);
    నిరంతరం_dtors();
    తిరిగి retval;
}

స్థిర LONG WINAPI catch_sig(EXCEPTION_సూచికలు *ex)
{
  తిరిగి _XcptFilter(ex->Exception_రికార్డు->Exception_సంకేతం, ex);
}

పూర్ణాంకం _twinstart(శూన్య)
{
    _startupinfo ప్రారంభం_info_con = {0};
    సమితి_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ప్రారంభం_info_con);
    నిష్క్రమించు(go_winmain(__argc > 1 ? __targv[1] : ఖాళీ));
}

పూర్ణాంకం _runtwinmain(పూర్ణాంకం argc, /* as tcc passed in */ అక్షరం **argv)
{
#నిర్వచితమైతే UNICODE
    _startupinfo ప్రారంభం_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ప్రారంభం_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    ఒకవేళ (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#లేకపోతే
    __argc = argc, __targv = argv;
#అయితే_ముగింపు
    తిరిగి go_winmain(__argc > 1 ? __targv[1] : ఖాళీ);
}
