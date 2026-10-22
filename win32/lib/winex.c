/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#જો __aarch64__
#અન્તર્ભાવ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
અક્ષર **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
પૂર્ણાંક __argc;
અક્ષર **__argv;
wchar_t **__wargv;
#endif

#જો __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
શૂન્ય __faststorefence(શૂન્ય)
{
#જો __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#અથવાજો __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
