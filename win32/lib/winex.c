/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#නම් __aarch64__
#include <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
var_na **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
පූර්ණ_සංඛ්‍යා __argc;
var_na **__argv;
wchar_t **__wargv;
#endif

#නම් __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
void __faststorefence(void)
{
#නම් __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#elif __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
