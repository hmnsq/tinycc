/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#ಯದಿ __aarch64__
#ಅನ್ತರ್ಭಾವ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
ವರ್ಣ **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
ಪೂರ್ಣಾಙ್ಕ __argc;
ವರ್ಣ **__argv;
wchar_t **__wargv;
#endif

#ಯದಿ __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
ಶೂನ್ಯ __faststorefence(ಶೂನ್ಯ)
{
#ಯದಿ __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#ನೋಚೇದ್ಯದಿ __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
