// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#అన్తర్భావ <tchar.h>

#అన్తర్భావ <windows.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdlib.h>

#నిర్వచించు _UNKNOWN_APP    0
#నిర్వచించు _CONSOLE_APP    1
#నిర్వచించు _GUI_APP        2

#నిర్వచించు _MCW_PC         0x00030000 // Precision Control
#నిర్వచించు _PC_24          0x00020000 // 24 bits
#నిర్వచించు _PC_53          0x00010000 // 53 bits
#నిర్వచించు _PC_64          0x00000000 // 64 bits

#నిర్వచితమైతే _UNICODE
#నిర్వచించు __tgetmainargs __wgetmainargs
#నిర్వచించు _tstart _wstart
#నిర్వచించు _tmain wmain
#నిర్వచించు _runtmain _runwmain
#లేకపోతే
#నిర్వచించు __tgetmainargs __getmainargs
#నిర్వచించు _tstart ప్రారంభం_5
#నిర్వచించు _tmain ప్రధాన
#నిర్వచించు _runtmain _runmain
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం { పూర్ణాంకం newmode; } _startupinfo;
పూర్ణాంకం __cdecl __tgetmainargs(పూర్ణాంకం *pargc, _TCHAR ***pargv, _TCHAR ***penv, పూర్ణాంకం globb, _startupinfo*);
శూన్య __cdecl __set_app_type(పూర్ణాంకం apptype);
గుర్తులేని పూర్ణాంకం __cdecl _controlfp(గుర్తులేని పూర్ణాంకం new_విలువ, గుర్తులేని పూర్ణాంకం ముసుగు);
బాహ్య పూర్ణాంకం _tmain(పూర్ణాంకం argc, _TCHAR * argv[], _TCHAR * env[]);

#అన్తర్భావ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
పూర్ణాంకం _dowildcard;

స్థిర LONG WINAPI catch_sig(EXCEPTION_సూచికలు *ex)
{
  తిరిగి _XcptFilter(ex->Exception_రికార్డు->Exception_సంకేతం, ex);
}

శూన్య _tstart(శూన్య)
{
    పూర్ణాంకం ret;

    _startupinfo ప్రారంభం_info = {0};
    సమితి_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#ఒకవేళ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#అయితే_ముగింపు

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &ప్రారంభం_info);
    నిరంతరం_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    నిరంతరం_dtors();
    నిష్క్రమించు(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) బాహ్య పూర్ణాంకం __run_on_exit();

పూర్ణాంకం _runtmain(పూర్ణాంకం argc, /* as tcc passed in */ అక్షరం **argv)
{
    పూర్ణాంకం ret;
#ఒకవేళ defined UNICODE || defined __aarch64__
    _startupinfo ప్రారంభం_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ప్రారంభం_info);
#అయితే_ముగింపు
#నిర్వచితమైతే UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    ఒకవేళ (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#లేకపోతే
    __argc = argc;
    __targv = argv;
#అయితే_ముగింపు
#ఒకవేళ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#అయితే_ముగింపు
    నిరంతరం_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    నిరంతరం_dtors();
    __run_on_exit(ret);
    తిరిగి ret;
}

// =============================================
