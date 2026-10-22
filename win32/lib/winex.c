/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#यदि __aarch64__
#अन्तर्भाव <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
वर्ण **_environ;
ब_अक्षर_प्रकार **_wenviron;
/* those do exist but have problems */
पूर्णाङ्क __argc;
वर्ण **__argv;
ब_अक्षर_प्रकार **__wargv;
#endif

#यदि __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
शून्य __faststorefence(शून्य)
{
#यदि __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#नोचेद्यदि __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#endif
}
#endif
