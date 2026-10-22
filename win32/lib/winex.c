/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#எனில் __aarch64__
#அந்தர்பாவ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
எழுத்து **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
முழு __argc;
எழுத்து **__argv;
wchar_t **__wargv;
#endif

#எனில் __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
வெறுமை __faststorefence(வெறுமை)
{
#எனில் __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#அல்லதெனில் __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
