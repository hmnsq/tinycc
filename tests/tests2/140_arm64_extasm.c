/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <stdint.h>
#അന്തര്ഭാവ <assert.h>

ഘടന pair64 {
    uint64_t a;
    uint64_t b;
};

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_ചിഹ്നം_target(ശൂന്യം)
{
    തിരികെ 7;
}

സ്ഥിതം ശൂന്യം test_symbolic_address_constraint_compile_only(ശൂന്യം)
{
    asm അസ്ഥിര("" : : "S"(arm64_ചിഹ്നം_target));
}

/* Test 1: Basic output operand */
ശൂന്യം test_basic_output(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x;
    asm("mov %0, #42" : "=r"(x));
    പ്രതിജ്ഞാ(x == 42);
    printf("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
ശൂന്യം test_നിവേശം_operand(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 10;
    പൂർണ്ണസംഖ്യ y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    പ്രതിജ്ഞാ(y == 15);
    printf("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
ശൂന്യം test_read_write_operand(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    പ്രതിജ്ഞാ(x == 11);
    printf("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
ശൂന്യം test_memory_load(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 42;
    പൂർണ്ണസംഖ്യ y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    പ്രതിജ്ഞാ(y == 42);
    printf("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
ശൂന്യം test_memory_store(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x;
    പൂർണ്ണസംഖ്യ val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    പ്രതിജ്ഞാ(x == 123);
    printf("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
ശൂന്യം test_അട്ടി_memory_operand(ശൂന്യം)
{
    long x = 0;
    long val = 321;

    asm അസ്ഥിര("str %0, %1" : : "r"(val), "m"(x));
    പ്രതിജ്ഞാ(x == 321);
    printf("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
സ്ഥിതം long arm64_ചിഹ്നം_mem;

ശൂന്യം test_ചിഹ്നം_memory_operand(ശൂന്യം)
{
    long val = 654;

    arm64_ചിഹ്നം_mem = 0;
    asm അസ്ഥിര("str %0, %1" : : "r"(val), "m"(arm64_ചിഹ്നം_mem));
    പ്രതിജ്ഞാ(arm64_ചിഹ്നം_mem == 654);
    printf("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
ശൂന്യം test_clobber_list(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 10;
    പൂർണ്ണസംഖ്യ y = 20;
    പൂർണ്ണസംഖ്യ result;
    asm("add %0, %1, %2" 
        : "=r"(result)
        : "r"(x), "r"(y)
        : "cc");
    പ്രതിജ്ഞാ(result == 30);
    printf("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
ശൂന്യം test_multiple_outputs(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    പ്രതിജ്ഞാ(a == 1 && b == 2);
    printf("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
ശൂന്യം test_constraint_reference(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 10;
    പൂർണ്ണസംഖ്യ y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    പ്രതിജ്ഞാ(y == 15);
    printf("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
ശൂന്യം test_early_clobber(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 10;
    പൂർണ്ണസംഖ്യ y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    പ്രതിജ്ഞാ(y == 42);
    printf("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
ശൂന്യം test_w_register(ശൂന്യം)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    പ്രതിജ്ഞാ(y == 150);
    printf("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
ശൂന്യം test_immediate_i_constraint(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 100;
    പൂർണ്ണസംഖ്യ y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    പ്രതിജ്ഞാ(y == 300);
    printf("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
ശൂന്യം test_general_operand_constraint(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 50;
    പൂർണ്ണസംഖ്യ y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    പ്രതിജ്ഞാ(y == 60);
    printf("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
ശൂന്യം test_multiple_io(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a = 10, b = 20;
    പൂർണ്ണസംഖ്യ sum, diff;
    asm("add %0, %1, %2" : "=r"(sum) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    പ്രതിജ്ഞാ(sum == 30 && diff == -10);
    printf("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
ശൂന്യം test_regvar_preservation(ശൂന്യം)
{
    രജിസ്റ്റർ uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t out;

    asm അസ്ഥിര("mov x19, #7; add %0, x19, #1"
        : "=r"(out)
        :
        : "x19");
    പ്രതിജ്ഞാ(keep == 0x123456789abcdef0ULL);
    പ്രതിജ്ഞാ(out == 8);
    printf("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
ശൂന്യം test_complex_arithmetic(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a = 100, b = 50, c = 25;
    പൂർണ്ണസംഖ്യ result;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(result)
        : "r"(a), "r"(b), "r"(c));
    പ്രതിജ്ഞാ(result == 125);
    printf("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
ശൂന്യം test_named_operand(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ നിവേശം = 10;
    പൂർണ്ണസംഖ്യ output;
    asm("add %[out], %[in], #5"
        : [out] "=r"(output)
        : [in] "r"(നിവേശം));
    പ്രതിജ്ഞാ(output == 15);
    printf("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
ശൂന്യം test_memory_clobber(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 10;
    asm അസ്ഥിര("" : : : "memory");
    പ്രതിജ്ഞാ(x == 10);
    printf("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
ശൂന്യം test_cc_clobber(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 100;
    പൂർണ്ണസംഖ്യ y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    പ്രതിജ്ഞാ(y == 100);
    printf("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
ശൂന്യം test_large_immediate(ശൂന്യം)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    പ്രതിജ്ഞാ(val == 0x12345678ULL);
    printf("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
ശൂന്യം test_bitwise_ops(ശൂന്യം)
{
    uint64_t a = 0xf0f0f0f00f0f0f0fULL;
    uint64_t b = 0x3333ffff0000ccccULL;
    uint64_t andv;
    uint64_t orv;
    uint64_t xorv;
    uint64_t imm_and;

    asm("and %0, %1, %2" : "=r"(andv) : "r"(a), "r"(b));
    asm("orr %0, %1, %2" : "=r"(orv) : "r"(a), "r"(b));
    asm("eor %0, %1, %2" : "=r"(xorv) : "r"(a), "r"(b));
    asm("and %0, %1, %2" : "=r"(imm_and)
        : "r"(~0ULL), "L"(0xff00ff00ff00ff00ULL));

    പ്രതിജ്ഞാ(andv == (a & b));
    പ്രതിജ്ഞാ(orv == (a | b));
    പ്രതിജ്ഞാ(xorv == (a ^ b));
    പ്രതിജ്ഞാ(imm_and == 0xff00ff00ff00ff00ULL);
    printf("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
ശൂന്യം test_register_shift_operands(ശൂന്യം)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    പ്രതിജ്ഞാ(shifted == 48);
    പ്രതിജ്ഞാ(rotated == 0xef0123456789abcdULL);
    printf("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
ശൂന്യം test_ror_immediate(ശൂന്യം)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    പ്രതിജ്ഞാ(rotated == 0xef0123456789abcdULL);
    printf("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
ശൂന്യം test_fp_register_operand(ശൂന്യം)
{
    ഇരട്ട x = 3.5;
    ഇരട്ട y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    പ്രതിജ്ഞാ(y == x);
    printf("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
ശൂന്യം test_zero_constraint(ശൂന്യം)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    പ്രതിജ്ഞാ(y == x);
    printf("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
ശൂന്യം test_logical_imm32_constraint(ശൂന്യം)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    പ്രതിജ്ഞാ(y == 0xff);
    printf("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
ശൂന്യം test_logical_imm64_constraint(ശൂന്യം)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    പ്രതിജ്ഞാ(y == 0xff00ff00ff00ff00ULL);
    printf("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
ശൂന്യം test_mov_imm32_constraint(ശൂന്യം)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    പ്രതിജ്ഞാ(y == 0x1234);
    printf("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
ശൂന്യം test_mov_imm64_constraint(ശൂന്യം)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    പ്രതിജ്ഞാ(y == 0x12340000ULL);
    printf("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
ശൂന്യം test_x_constraint_fp(ശൂന്യം)
{
    ഇരട്ട x = 6.25;
    ഇരട്ട y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    പ്രതിജ്ഞാ(y == x);
    printf("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
ശൂന്യം test_y_constraint_fp(ശൂന്യം)
{
    ഇരട്ട x = 7.25;
    ഇരട്ട y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    പ്രതിജ്ഞാ(y == x);
    printf("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_q_load(പൂർണ്ണസംഖ്യ *ptr)
{
    പൂർണ്ണസംഖ്യ y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    തിരികെ y;
}

ശൂന്യം test_q_memory_constraint(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 91;
    പ്രതിജ്ഞാ(arm64_q_load(&x) == 91);
    printf("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
ശൂന്യം test_ump_memory_constraint(ശൂന്യം)
{
    ഘടന pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    പ്രതിജ്ഞാ(a == pair.a);
    പ്രതിജ്ഞാ(b == pair.b);
    printf("Test 32 (Ump constraint): PASSED\n");
}

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    printf("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_നിവേശം_operand();
    test_read_write_operand();
    test_memory_load();
    test_memory_store();
    test_അട്ടി_memory_operand();
    test_ചിഹ്നം_memory_operand();
    test_clobber_list();
    test_multiple_outputs();
    test_constraint_reference();
    test_early_clobber();
    test_w_register();
    test_immediate_i_constraint();
    test_general_operand_constraint();
    test_multiple_io();
    test_regvar_preservation();
    test_complex_arithmetic();
    test_named_operand();
    test_memory_clobber();
    test_cc_clobber();
    test_large_immediate();
    test_bitwise_ops();
    test_register_shift_operands();
    test_ror_immediate();
    test_fp_register_operand();
    test_zero_constraint();
    test_logical_imm32_constraint();
    test_logical_imm64_constraint();
    test_mov_imm32_constraint();
    test_mov_imm64_constraint();
    test_x_constraint_fp();
    test_y_constraint_fp();
    test_q_memory_constraint();
    test_ump_memory_constraint();
    test_symbolic_address_constraint_compile_only();
    printf("ARM64 Extended Inline Assembly Tests PASSED!\n");
    തിരികെ 0;
}
