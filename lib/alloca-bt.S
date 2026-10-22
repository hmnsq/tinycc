/* ---------------------------------------------- */
/* alloca-bt.S */

#ifdef __leading_underscore
# define _(s) _##s
#else
# define _(s) s
#endif

/* ---------------------------------------------- */
#if defined __i386__

.globl _(__bound_alloca)
_(__bound_alloca):
    उद्धर     %edx
    उद्धर     %eax
    चालय     %eax, %ecx
    test    %eax,%eax
    jz      p6
    योजय     $3 + 1,%eax
    and     $-4,%eax

#ifdef _WIN32
p4:
    तुलय     $4096,%eax
    jb      p5
    test    %eax,-4096(%esp)
    वियोजय     $4096,%esp
    वियोजय     $4096,%eax
    कूर्द p4

p5:
#endif

    वियोजय     %eax,%esp
    चालय     %esp,%eax

    निक्षिप    %edx
    निक्षिप    %eax
    निक्षिप    %ecx
    निक्षिप    %eax
    आह्वान    _(__bound_new_region)
    योजय     $8, %esp
    उद्धर     %eax
    उद्धर     %edx

p6:
    निक्षिप    %edx
    निक्षिप    %edx
    प्रत्यागच्छ

/* ---------------------------------------------- */
#elif defined __x86_64__

.globl _(__bound_alloca)
_(__bound_alloca):
#ifdef _WIN32
    inc %rcx            # योजय one extra to separate regions
    कूर्द _(alloca)
.globl _(__bound_alloca_nr)
_(__bound_alloca_nr):
    dec     %rcx
    निक्षिप    %rax
    चालय     %rcx,%rdx
    चालय     %rax,%rcx
    वियोजय     $32,%rsp
    आह्वान    _(__bound_new_region)
    योजय     $32,%rsp
    उद्धर     %rax
    प्रत्यागच्छ
#else
    उद्धर     %rdx
    चालय     %rdi,%rax
    and     %eax,%eax
    jz      p3
    चालय     %rax,%rsi	# size, a second parm to the __bound_new_region
    योजय     $15 + 1,%rax  # योजय one extra to separate regions
    and     $-16,%rax

    वियोजय     %rax,%rsp
    चालय     %rsp,%rdi	# pointer, a first parm to the __bound_new_region
    चालय     %rsp,%rax

    निक्षिप    %rdx
    निक्षिप    %rax
    आह्वान    _(__bound_new_region)
    उद्धर     %rax
    उद्धर     %rdx

p3:
    निक्षिप    %rdx
    प्रत्यागच्छ
#endif

/* ---------------------------------------------- */
#elif defined __arm__

.globl _(__bound_alloca)
_(__bound_alloca):
    चालय r1, r0
    योजय r0, r0, #1
    rsb sp, r0, sp
    bic sp, sp, #7
    चालय r0, sp
    निक्षिप { lr }
    bl _(__bound_new_region)
    उद्धर { lr }
    चालय r0, sp
    चालय pc, lr

/* ---------------------------------------------- */
#elif defined __aarch64__ || defined __arm64__

.globl _(__bound_alloca)
_(__bound_alloca):
#ifdef __TINYC__
    .int 0xaa0003e1
    .int 0x91004000
    .int 0x927cec00
#ifdef _WIN32
    .int 0xb4000160
    .int 0xd2820002
    .int 0xeb02001f
    .int 0x540000c3
    .int 0xcb2263e3
    .int 0xf940007f
    .int 0xcb2263ff
    .int 0xcb020000
    .int 0x17fffffa
    .int 0xb4000040
#endif
    .int 0xcb2063ff
    .int 0x910003e0
    .int 0xa9bf7bfd
    .reloc ., R_AARCH64_CALL26,  _(__bound_new_region)
    .int 0x94000000
    .int 0xa8c17bfd
    .int 0x910003e0
    .int 0xd65f03c0
#else
    चालय x1, x0
    योजय x0, x0, #16     // Round up to 16-byte boundary
    and x0, x0, #-16    // Ensure 16-byte alignment
#ifdef _WIN32
    cbz x0, p100        // If size is 0, skip to return
    // Windows requires page-wise allocation with stack probing
    चालय x2, #4096       // Page size = 4096 bytes

p101:
    तुलय x0, x2          // Compare remaining size with page size
    b.lo    p102        // If less than page, jump to remainder

    // Probe first, then allocate
    वियोजय x3, sp, x2      // Calculate guard page address (sp - 4096)
    ldr xzr, [x3]       // Touch guard page FIRST
    वियोजय sp, sp, x2      // THEN allocate the page

    वियोजय x0, x0, x2      // Decrement remaining size
    b   p101            // Continue loop

p102:
    // Allocate remaining bytes (less than one page)
    cbz x0, p100        // If no remaining bytes, skip
    वियोजय sp, sp, x0      // Allocate remaining space
#else
    // Non-Windows: simple one-time allocation
    वियोजय sp, sp, x0      // Allocate space on stack
#endif

p100:
    चालय x0, sp          // Return allocated address
    stp x29, x30, [sp, #-16]!
    bl _(__bound_new_region)
    ldp x29, x30, [sp], #16
    चालय x0, sp          // Return allocated address
    प्रत्यागच्छ                 // Return to caller
#endif

/* ---------------------------------------------- */
#elif defined __riscv

.globl _(__bound_alloca)
_(__bound_alloca):
    mv     a1, a0
    वियोजय    sp, sp, a0
    addi   sp, sp, -16
    andi   sp, sp, -16
    योजय    a0, sp, zero
    addi   sp,sp,-16
    sd     s0,0(sp)
    sd     ra,8(sp)
    jal    _(__bound_new_region)
    ld     s0,0(sp)
    ld     ra,8(sp)
    addi   sp,sp,16
    योजय    a0, sp, zero
    प्रत्यागच्छ

/* ---------------------------------------------- */
#endif
