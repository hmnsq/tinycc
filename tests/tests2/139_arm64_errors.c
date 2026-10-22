/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಯದಿ defined test_unknown_instruction
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    __asm__("fubar x0, x1, x2");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_shift_imm_range_32
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_shift_imm_range_64
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_invalid_sysreg
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_invalid_barrier_option
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_missing_third_operand
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    __asm__("add x0, x1");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_movz_imm_range
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    __asm__("movz x0, #0x10000");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_movz_shift_range
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    __asm__("movz x0, #1, lsl #8");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_invalid_muls
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    __asm__("muls x0, x1, x2");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_extended_inline_asm
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined test_extended_inline_clobber
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    /* Invalid clobber register name */
    __asm__ ಚಞ್ಚಲ ("nop" : : : "bogus");
    ಪ್ರತ್ಯಾಗಮ 0;
}

#endif
