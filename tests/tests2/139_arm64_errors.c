/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#अन्तर्भाव <stdio.h>

#जर defined test_unknown_instruction
पूर्णांक main(शून्य)
{
    __asm__("fubar x0, x1, x2");
    परत 0;
}

#किंवाजर defined test_shift_imm_range_32
पूर्णांक main(शून्य)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    परत 0;
}

#किंवाजर defined test_shift_imm_range_64
पूर्णांक main(शून्य)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    परत 0;
}

#किंवाजर defined test_invalid_sysreg
पूर्णांक main(शून्य)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    परत 0;
}

#किंवाजर defined test_invalid_barrier_option
पूर्णांक main(शून्य)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    परत 0;
}

#किंवाजर defined test_missing_third_operand
पूर्णांक main(शून्य)
{
    __asm__("add x0, x1");
    परत 0;
}

#किंवाजर defined test_movz_imm_range
पूर्णांक main(शून्य)
{
    __asm__("movz x0, #0x10000");
    परत 0;
}

#किंवाजर defined test_movz_shift_range
पूर्णांक main(शून्य)
{
    __asm__("movz x0, #1, lsl #8");
    परत 0;
}

#किंवाजर defined test_invalid_muls
पूर्णांक main(शून्य)
{
    __asm__("muls x0, x1, x2");
    परत 0;
}

#किंवाजर defined test_extended_inline_asm
पूर्णांक main(शून्य)
{
    पूर्णांक x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    परत 0;
}

#किंवाजर defined test_extended_inline_clobber
पूर्णांक main(शून्य)
{
    /* Invalid clobber register name */
    __asm__ अस्थिर ("nop" : : : "bogus");
    परत 0;
}

#endif
