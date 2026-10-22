/* ------------------------------------------------------------------------- */
/* winex.c : extra stuff */

#ఒకవేళ __aarch64__
#అన్తర్భావ <stdlib.h>
/* replaces environ from arm64-msvcrt.dll which does not exist */
అక్షరం **_environ;
wchar_t **_wenviron;
/* those do exist but have problems */
పూర్ణాంకం __argc;
అక్షరం **__argv;
wchar_t **__wargv;
#అయితే_ముగింపు

#ఒకవేళ __aarch64__ || __x86_64__
/* MSVC x64 intrinsic */
శూన్య __faststorefence(శూన్య)
{
#ఒకవేళ __aarch64__
    /* ARM64: Data Memory Barrier (Inner Shareable) */
    __asm__("dmb ish");
#లేదావేళ __x86_64__
    /* x86-64: lock prefix to flush store buffer */
    __asm__("lock; orl $0,(%%rsp)" ::: "memory");
#అయితే_ముగింపు
}
#అయితే_ముగింపు
