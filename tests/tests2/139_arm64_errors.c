/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#නම් defined test_unknown_instruction
පූර්ණ_සංඛ්‍යා main(void)
{
    __asm__("fubar x0, x1, x2");
    ආපසු 0;
}

#elif defined test_shift_imm_range_32
පූර්ණ_සංඛ්‍යා main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ආපසු 0;
}

#elif defined test_shift_imm_range_64
පූර්ණ_සංඛ්‍යා main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ආපසු 0;
}

#elif defined test_invalid_sysreg
පූර්ණ_සංඛ්‍යා main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ආපසු 0;
}

#elif defined test_invalid_barrier_option
පූර්ණ_සංඛ්‍යා main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ආපසු 0;
}

#elif defined test_missing_third_operand
පූර්ණ_සංඛ්‍යා main(void)
{
    __asm__("add x0, x1");
    ආපසු 0;
}

#elif defined test_movz_imm_range
පූර්ණ_සංඛ්‍යා main(void)
{
    __asm__("movz x0, #0x10000");
    ආපසු 0;
}

#elif defined test_movz_shift_range
පූර්ණ_සංඛ්‍යා main(void)
{
    __asm__("movz x0, #1, lsl #8");
    ආපසු 0;
}

#elif defined test_invalid_muls
පූර්ණ_සංඛ්‍යා main(void)
{
    __asm__("muls x0, x1, x2");
    ආපසු 0;
}

#elif defined test_extended_inline_asm
පූර්ණ_සංඛ්‍යා main(void)
{
    පූර්ණ_සංඛ්‍යා x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ආපසු 0;
}

#elif defined test_extended_inline_clobber
පූර්ණ_සංඛ්‍යා main(void)
{
    /* Invalid clobber register name */
    __asm__ ca_ncala ("nop" : : : "bogus");
    ආපසු 0;
}

#endif
