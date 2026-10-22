//+---------------------------------------------------------------------------

// _UNICODE for tchar.h, UNICODE for API
#अन्तर्भाव <tchar.h>

#अन्तर्भाव <windows.h>
#अन्तर्भाव <stdlib.h>

#परिभाषय __UNKNOWN_APP    0
#परिभाषय __CONSOLE_APP    1
#परिभाषय __GUI_APP        2
शून्य __set_app_type(पूर्णाङ्क);
शून्य _controlfp(अचिह्नित a, अचिह्नित b);

#यदि_परिभाषितम् _UNICODE
#परिभाषय __tgetmainargs __wgetmainargs
#परिभाषय _twinstart _wwinstart
#परिभाषय _runtwinmain _runwwinmain
पूर्णाङ्क APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, पूर्णाङ्क);
#अन्यथा
#परिभाषय __tgetmainargs __getmainargs
#परिभाषय _twinstart _winstart
#परिभाषय _runtwinmain _runwinmain
#यदि_अन्तः

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
    यदि (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.w_Show_गवाक्षः;
    अन्यथा
        fShow = SW_SHOWDEFAULT;

    szCmd = रिक्त, p = Get_Command_पङ्क्तिः();
    यदि (arg1)
        szCmd = _tcsstr(p, arg1);
    यदि (रिक्त == szCmd)
        szCmd = _tcsdup(__T(""));
    अन्यथा यदि (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#यदि defined __i386__ || defined __x86_64__
    _controlfp(0x10000, 0x30000);
#यदि_अन्तः
    सततम्_ctors(__argc, __targv, _tenviron);
    retval = _tWinMain(GetModuleHandle(रिक्त), रिक्त, szCmd, fShow);
    सततम्_dtors();
    प्रत्यागम retval;
}

स्थिर LONG WINAPI catch_sig(EXCEPTION_सूचकाः *ex)
{
  प्रत्यागम _XcptFilter(ex->Exception_लेखः->Exception_संहिता, ex);
}

पूर्णाङ्क _twinstart(शून्य)
{
    _startupinfo start_info_con = {0};
    समुच्चयः_Unhandled_Exception_Filter(catch_sig);
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    निर्गच्छ(go_winmain(__argc > 1 ? __targv[1] : रिक्त));
}

पूर्णाङ्क _runtwinmain(पूर्णाङ्क argc, /* as tcc passed in */ वर्ण **argv)
{
#यदि_परिभाषितम् UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    यदि (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#अन्यथा
    __argc = argc, __targv = argv;
#यदि_अन्तः
    प्रत्यागम go_winmain(__argc > 1 ? __targv[1] : रिक्त);
}
