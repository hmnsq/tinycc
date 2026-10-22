/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#ضمن <stdio.h>

#إذا defined test_unknown_instruction
صحيح اصلی(فراغ)
{
    __asm__("fubar x0, x1, x2");
    أرجع 0;
}

#وإلاإذا defined test_لغزش_imm_range_32
صحيح اصلی(فراغ)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    أرجع 0;
}

#وإلاإذا defined test_لغزش_imm_range_64
صحيح اصلی(فراغ)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    أرجع 0;
}

#وإلاإذا defined test_invalid_sysreg
صحيح اصلی(فراغ)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    أرجع 0;
}

#وإلاإذا defined test_invalid_barrier_option
صحيح اصلی(فراغ)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    أرجع 0;
}

#وإلاإذا defined test_missing_سوم_عملوند
صحيح اصلی(فراغ)
{
    __asm__("add x0, x1");
    أرجع 0;
}

#وإلاإذا defined test_movz_imm_range
صحيح اصلی(فراغ)
{
    __asm__("movz x0, #0x10000");
    أرجع 0;
}

#وإلاإذا defined test_movz_لغزش_range
صحيح اصلی(فراغ)
{
    __asm__("movz x0, #1, lsl #8");
    أرجع 0;
}

#وإلاإذا defined test_invalid_muls
صحيح اصلی(فراغ)
{
    __asm__("muls x0, x1, x2");
    أرجع 0;
}

#وإلاإذا defined test_extended_inline_asm
صحيح اصلی(فراغ)
{
    صحيح x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    أرجع 0;
}

#وإلاإذا defined test_extended_inline_clobber
صحيح اصلی(فراغ)
{
    /* Invalid clobber register name */
    __asm__ متطاير ("nop" : : : "bogus");
    أرجع 0;
}

#پایان_اگر
