/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#اگر __aarch64__
#شامل <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
نویسه **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
صحیح __argc;
نویسه **__argv;
wchar_t **__wargv;
#endif

#اگر __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
تهی __faststorefence(تهی)
{
#اگر __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#وگرنهاگر __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
