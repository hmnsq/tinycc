// =============================================
// crt1.c

// _UNICODE for tchar.h, UNICODE for API
#ಅನ್ತರ್ಭಾವ <tchar.h>

#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>

#ವ್ಯಾಖ್ಯಾನಿಸು _UNKNOWN_APP    0
#ವ್ಯಾಖ್ಯಾನಿಸು _CONSOLE_APP    1
#ವ್ಯಾಖ್ಯಾನಿಸು _GUI_APP        2

#ವ್ಯಾಖ್ಯಾನಿಸು _MCW_PC         0x00030000 // Precision Control
#ವ್ಯಾಖ್ಯಾನಿಸು _PC_24          0x00020000 // 24 bits
#ವ್ಯಾಖ್ಯಾನಿಸು _PC_53          0x00010000 // 53 bits
#ವ್ಯಾಖ್ಯಾನಿಸು _PC_64          0x00000000 // 64 bits

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು __tgetmainargs __wgetmainargs
#ವ್ಯಾಖ್ಯಾನಿಸು _tstart _wstart
#ವ್ಯಾಖ್ಯಾನಿಸು _tmain wmain
#ವ್ಯಾಖ್ಯಾನಿಸು _runtmain _runwmain
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __tgetmainargs __getmainargs
#ವ್ಯಾಖ್ಯಾನಿಸು _tstart ಆರಂಭ_5
#ವ್ಯಾಖ್ಯಾನಿಸು _tmain ಮುಖ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _runtmain _runmain
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ newmode; } _startupinfo;
ಪೂರ್ಣಾಂಕ __cdecl __tgetmainargs(ಪೂರ್ಣಾಂಕ *pargc, _TCHAR ***pargv, _TCHAR ***penv, ಪೂರ್ಣಾಂಕ globb, _startupinfo*);
ಶೂನ್ಯ __cdecl __set_app_type(ಪೂರ್ಣಾಂಕ apptype);
ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl _controlfp(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ new_ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಮುಖವಾಡ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ _tmain(ಪೂರ್ಣಾಂಕ argc, _TCHAR * argv[], _TCHAR * env[]);

#ಅನ್ತರ್ಭಾವ "crtinit.c"

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
ಪೂರ್ಣಾಂಕ _dowildcard;

ಸ್ಥಿರ LONG WINAPI catch_sig(EXCEPTION_ಸೂಚಕಗಳು *ex)
{
  ಹಿಂತಿರುಗಿ _XcptFilter(ex->Exception_ದಾಖಲೆ->Exception_ಸಂಕೇತ, ex);
}

ಶೂನ್ಯ _tstart(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ret;

    _startupinfo ಆರಂಭ_info = {0};
    ಗಣ_Unhandled_Exception_Filter(catch_sig);
    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#ಆದರೆ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#ಆದರೆ_ಅಂತ್ಯ

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &ಆರಂಭ_info);
    ಸತತ_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    ಸತತ_dtors();
    ನಿರ್ಗಮಿಸು(ret);
}

// =============================================
// for 'tcc -run ,,,'

__attribute__((weak)) ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __run_on_exit();

ಪೂರ್ಣಾಂಕ _runtmain(ಪೂರ್ಣಾಂಕ argc, /* as tcc passed in */ ಅಕ್ಷರ **argv)
{
    ಪೂರ್ಣಾಂಕ ret;
#ಆದರೆ defined UNICODE || defined __aarch64__
    _startupinfo ಆರಂಭ_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &ಆರಂಭ_info);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
    /* may be wrong when tcc has received wildcards (*.c) */
    ಆದರೆ (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#ಇಲ್ಲದಿದ್ದರೆ
    __argc = argc;
    __targv = argv;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined __i386__ || defined __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#ಆದರೆ_ಅಂತ್ಯ
    ಸತತ_ctors(__argc, __targv, _tenviron);
    ret = _tmain(__argc, __targv, _tenviron);
    fflush(stdout);
    fflush(stderr);
    ಸತತ_dtors();
    __run_on_exit(ret);
    ಹಿಂತಿರುಗಿ ret;
}

// =============================================
