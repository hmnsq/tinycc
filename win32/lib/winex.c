/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#अगर __aarch64__
#समावेश <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
अक्षर **_environ;
ब_अक्षर_प्रकार **_wenviron;
/* those do exist but have problems */
पूर्णांक __argc;
अक्षर **__argv;
ब_अक्षर_प्रकार **__wargv;
#पूर्ण_अगर

#अगर __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
व्योम __faststorefence(व्योम)
{
#अगर __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#या_अगर __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#पूर्ण_अगर
}
#पूर्ण_अगर
