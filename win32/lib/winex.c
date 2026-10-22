/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#якщо __aarch64__
#include <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
char **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
ціле __argc;
char **__argv;
wchar_t **__wargv;
#endif

#якщо __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
void __faststorefence(void)
{
#якщо __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#elif __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
