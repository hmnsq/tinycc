/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#ضمن <stdio.h>

#إذا defined test_unknown_instruction
صحيح الرئيسية(فراغ)
{
    __asm__("fubar x0, x1, x2");
    إرجاع 0;
}

#وإلاإذا defined test_shift_imm_range_32
صحيح الرئيسية(فراغ)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    إرجاع 0;
}

#وإلاإذا defined test_shift_imm_range_64
صحيح الرئيسية(فراغ)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    إرجاع 0;
}

#وإلاإذا defined test_invalid_sysreg
صحيح الرئيسية(فراغ)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    إرجاع 0;
}

#وإلاإذا defined test_invalid_barrier_option
صحيح الرئيسية(فراغ)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    إرجاع 0;
}

#وإلاإذا defined test_missing_third_operand
صحيح الرئيسية(فراغ)
{
    __asm__("add x0, x1");
    إرجاع 0;
}

#وإلاإذا defined test_movz_imm_range
صحيح الرئيسية(فراغ)
{
    __asm__("movz x0, #0x10000");
    إرجاع 0;
}

#وإلاإذا defined test_movz_shift_range
صحيح الرئيسية(فراغ)
{
    __asm__("movz x0, #1, lsl #8");
    إرجاع 0;
}

#وإلاإذا defined test_invalid_muls
صحيح الرئيسية(فراغ)
{
    __asm__("muls x0, x1, x2");
    إرجاع 0;
}

#وإلاإذا defined test_extended_inline_asm
صحيح الرئيسية(فراغ)
{
    صحيح x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    إرجاع 0;
}

#وإلاإذا defined test_extended_inline_clobber
صحيح الرئيسية(فراغ)
{
    /* Invalid clobber register name */
    __asm__ متطاير ("nop" : : : "bogus");
    إرجاع 0;
}

#endif
