/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಆದರೆ defined test_unknown_instruction
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    __asm__("fubar x0, x1, x2");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_ಸರಿಸು_imm_range_32
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_ಸರಿಸು_imm_range_64
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_invalid_sysreg
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_invalid_barrier_option
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_missing_ಮೂರನೇ_ಕಾರ್ಯಾಂಶ
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    __asm__("add x0, x1");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_movz_imm_range
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    __asm__("movz x0, #0x10000");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_movz_ಸರಿಸು_range
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    __asm__("movz x0, #1, lsl #8");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_invalid_muls
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    __asm__("muls x0, x1, x2");
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_extended_inline_asm
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_extended_inline_clobber
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    /* Invalid clobber register name */
    __asm__ ಅಸ್ಥಿರ ("nop" : : : "bogus");
    ಹಿಂತಿರುಗಿ 0;
}

#ಆದರೆ_ಅಂತ್ಯ
