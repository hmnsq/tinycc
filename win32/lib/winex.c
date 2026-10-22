/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#ਜੇ __aarch64__
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
ਅੱਖਰ **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
ਪੂਰਨ __argc;
ਅੱਖਰ **__argv;
wchar_t **__wargv;
#ਜੇ_ਅੰਤ

#ਜੇ __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
ਖਾਲੀ __faststorefence(ਖਾਲੀ)
{
#ਜੇ __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#ਜਾਂਜੇ __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#ਜੇ_ਅੰਤ
}
#ਜੇ_ਅੰਤ
