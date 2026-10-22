/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#𐤀𐤌 __aarch64__
#ضمن <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
حرف **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
صحيح __argc;
حرف **__argv;
wchar_t **__wargv;
#endif

#𐤀𐤌 __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
فراغ __faststorefence(فراغ)
{
#𐤀𐤌 __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#وإلاإذا __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
