/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#समावेश <stdio.h>

#अगर defined test_unknown_instruction
पूर्णांक मुख्य(व्योम)
{
    __asm__("fubar x0, x1, x2");
    वापस 0;
}

#या_अगर defined test_shift_imm_range_32
पूर्णांक मुख्य(व्योम)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    वापस 0;
}

#या_अगर defined test_shift_imm_range_64
पूर्णांक मुख्य(व्योम)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    वापस 0;
}

#या_अगर defined test_invalid_sysreg
पूर्णांक मुख्य(व्योम)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    वापस 0;
}

#या_अगर defined test_invalid_barrier_option
पूर्णांक मुख्य(व्योम)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    वापस 0;
}

#या_अगर defined test_missing_third_operand
पूर्णांक मुख्य(व्योम)
{
    __asm__("add x0, x1");
    वापस 0;
}

#या_अगर defined test_movz_imm_range
पूर्णांक मुख्य(व्योम)
{
    __asm__("movz x0, #0x10000");
    वापस 0;
}

#या_अगर defined test_movz_shift_range
पूर्णांक मुख्य(व्योम)
{
    __asm__("movz x0, #1, lsl #8");
    वापस 0;
}

#या_अगर defined test_invalid_muls
पूर्णांक मुख्य(व्योम)
{
    __asm__("muls x0, x1, x2");
    वापस 0;
}

#या_अगर defined test_extended_inline_asm
पूर्णांक मुख्य(व्योम)
{
    पूर्णांक x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    वापस 0;
}

#या_अगर defined test_extended_inline_clobber
पूर्णांक मुख्य(व्योम)
{
    /* Invalid clobber register name */
    __asm__ अस्थिर ("nop" : : : "bogus");
    वापस 0;
}

#पूर्ण_अगर
