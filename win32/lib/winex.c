/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#যদি __aarch64__
#অন্তর্ভাৱ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
ৱর্ণ **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
পূর্ণাঙ্ক __argc;
ৱর্ণ **__argv;
wchar_t **__wargv;
#endif

#যদি __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
শূন্য __faststorefence(শূন্য)
{
#যদি __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#নোচেদ্যদি __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
