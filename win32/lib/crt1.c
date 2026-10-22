// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ਅਨ੍ਤਰ੍ਭਾਵ <tchar.h>

#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UNKNOWN_APP    0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CONSOLE_APP    1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _GUI_APP        2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MCW_PC         0x00030000 // Precision Control
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PC_24          0x00020000 // 24 bits
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PC_53          0x00010000 // 53 bits
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PC_64          0x00000000 // 64 bits

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgetmainargs __wgetmainargs
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tstart _wstart
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tmain wmain
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _runtmain _runwmain
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __tgetmainargs __getmainargs
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tstart ਸ਼ੁਰੂ_5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tmain ਮੁੱਖ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _runtmain _runmain
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ newmode; } _startupinfo;
ਪੂਰਨ __cdecl __tgetmainargs(ਪੂਰਨ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ਪੂਰਨ globb, _startupinfo*);
ਖਾਲੀ __cdecl __set_app_type(ਪੂਰਨ apptype);
ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl _controlfp(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ new_ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਨਕਾਬ);
ਬਾਹਰੀ ਪੂਰਨ _tmain(ਪੂਰਨ argc, _TCHAR * argv[], _TCHAR * env[]);

#ਅਨ੍ਤਰ੍ਭਾਵ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
ਪੂਰਨ _dowildcard;

ਸਥਿਰ LONG WINAPI catch_sig(EXCEPTION_ਸੂਚਕ_ਸਾਰੇ *ex)
{
  ਵਾਪਸ _XcptFilter(ex->Exception_ਰਿਕਾਰਡ->Exception_ਕੋਡ, ex);
}

ਖਾਲੀ _tstart(ਖਾਲੀ)
{
    ਪੂਰਨ ret;

    _startupinfo ਸ਼ੁਰੂ_info = {0};
    ਸੈੱਟ_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#ਜੇ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#ਜੇ_ਅੰਤ

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &ਸ਼ੁਰੂ_info);
    ਲੜੀਵਾਰ_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    ਲੜੀਵਾਰ_dtors();
    ਬਾਹਰ_ਨਿਕਲੋ(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) ਬਾਹਰੀ ਪੂਰਨ __run_on_exit();

ਪੂਰਨ _runtmain(ਪੂਰਨ argc, /* as tcc passed in */ ਅੱਖਰ **argv)
{
    ਪੂਰਨ ret;
#ਜੇ defined UNICODE || defined __aarch64__
    _startupinfo ਸ਼ੁਰੂ_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ਸ਼ੁਰੂ_info);
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    ਜੇ (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#ਨਹੀਂਤਾਂ
    __argc = argc;
    __targv = argv;
#ਜੇ_ਅੰਤ
#ਜੇ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#ਜੇ_ਅੰਤ
    ਲੜੀਵਾਰ_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    ਲੜੀਵਾਰ_dtors();
    __run_on_exit(ret);
    ਵਾਪਸ ret;
}

// =============================================
