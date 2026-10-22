/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#ଯଦି __aarch64__
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
ଅକ୍ଷର **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __argc;
ଅକ୍ଷର **__argv;
wchar_t **__wargv;
#endif

#ଯଦି __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
ଶୂନ୍ୟ __faststorefence(ଶୂନ୍ୟ)
{
#ଯଦି __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#ନଚେତଯଦି __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
