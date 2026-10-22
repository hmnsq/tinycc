/* ---------------------------------------------- */
/* chkstk86.s */

#ifdef __leading_underscore
# define _(s) _##s
#else
# define _(s) s
#endif

/* ---------------------------------------------- */
#if defined(__aarch64__)

.globl __chkstk
__chkstk:
    /* Windows ARM64 stack probing helper.
       arm64-gen.c passes the requested frame size in x15, scaled in 16-byte
       units. Probe one 4 KiB page at a time and leave SP unchanged; the caller
       subtracts SP after the probe returns. */
    चालय     x16, sp
    lsl     x17, x15, 4
    cbz     x17, L_chkstk_done
L_chkstk_loop:
    subs    x0, x17, 4096
    bls     L_chkstk_tail
    वियोजय     x16, x16, 4096
    ldr     xzr, [x16]
    वियोजय     x17, x17, 4096
    b       L_chkstk_loop
L_chkstk_tail:
    वियोजय     x16, x16, x17
    ldr     xzr, [x16]
L_chkstk_done:
    प्रत्यागच्छ

/* ---------------------------------------------- */
#elif defined(__i386__)

.globl _(__chkstk)
_(__chkstk):
    xchg    (%esp),%ebp     /* store ebp, get प्रत्यागच्छ.addr */
    निक्षिप    %ebp            /* निक्षिप प्रत्यागच्छ.addr */
    lea     4(%esp),%ebp    /* setup frame ptr */
    निक्षिप    %ecx            /* save ecx */
    चालय     %ebp,%ecx
P0:
    वियोजय     $4096,%ecx
    test    %eax,(%ecx)
    वियोजय     $4096,%eax
    तुलय     $4096,%eax
    jge     P0
    वियोजय     %eax,%ecx
    test    %eax,(%ecx)

    चालय     %esp,%eax
    चालय     %ecx,%esp
    चालय     (%eax),%ecx     /* restore ecx */
    कूर्द     *4(%eax)

/* ---------------------------------------------- */
#else /* __x86_64__ */

.globl _(__chkstk)
_(__chkstk):
    xchg    (%rsp),%rbp     /* store ebp, get प्रत्यागच्छ.addr */
    निक्षिप    %rbp            /* निक्षिप प्रत्यागच्छ.addr */
    lea     8(%rsp),%rbp    /* setup frame ptr */
    निक्षिप    %rcx            /* save ecx */
    चालय     %rbp,%rcx
    movslq  %eax,%rax
P0:
    वियोजय     $4096,%rcx
    test    %rax,(%rcx)
    वियोजय     $4096,%rax
    तुलय     $4096,%rax
    jge     P0
    वियोजय     %rax,%rcx
    test    %rax,(%rcx)

    चालय     %rsp,%rax
    चालय     %rcx,%rsp
    चालय     (%rax),%rcx     /* restore ecx */
    कूर्द     *8(%rax)

/* ---------------------------------------------- */
#endif
/* ---------------------------------------------- */
