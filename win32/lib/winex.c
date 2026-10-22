/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#എങ്കിൽ __aarch64__
#അന്തര്ഭാവ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
അക്ഷരം **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
പൂർണ്ണസംഖ്യ __argc;
അക്ഷരം **__argv;
wchar_t **__wargv;
#endif

#എങ്കിൽ __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
ശൂന്യം __faststorefence(ശൂന്യം)
{
#എങ്കിൽ __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#അല്ലെങ്കിലെങ്കിൽ __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
