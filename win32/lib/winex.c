/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#ಆದರೆ __aarch64__
#ಅನ್ತರ್ಭಾವ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
ಅಕ್ಷರ **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
ಪೂರ್ಣಾಂಕ __argc;
ಅಕ್ಷರ **__argv;
wchar_t **__wargv;
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
ಶೂನ್ಯ __faststorefence(ಶೂನ್ಯ)
{
#ಆದರೆ __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#ಅಥವಾಆದರೆ __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#ಆದರೆ_ಅಂತ್ಯ
}
#ಆದರೆ_ಅಂತ್ಯ
