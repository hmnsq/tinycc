/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <stdint.h>
#ଅନ୍ତର୍ଭାଵ <assert.h>

ସଂରଚନା pair64 {
    uint64_t a;
    uint64_t b;
};

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_ପ୍ରତୀକ_target(ଶୂନ୍ୟ)
{
    ଫେରନ୍ତୁ 7;
}

ସ୍ଥିର ଶୂନ୍ୟ test_symbolic_address_constraint_compile_only(ଶୂନ୍ୟ)
{
    asm ଅସ୍ଥିର("" : : "S"(arm64_ପ୍ରତୀକ_target));
}

/* Test 1: Basic output operand */
ଶୂନ୍ୟ test_basic_output(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
    asm("mov %0, #42" : "=r"(x));
    ପ୍ରତିଜ୍ଞା(x == 42);
    printf("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
ଶୂନ୍ୟ test_ନିବେଶ_operand(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 10;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    ପ୍ରତିଜ୍ଞା(y == 15);
    printf("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
ଶୂନ୍ୟ test_read_write_operand(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    ପ୍ରତିଜ୍ଞା(x == 11);
    printf("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
ଶୂନ୍ୟ test_memory_load(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 42;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    ପ୍ରତିଜ୍ଞା(y == 42);
    printf("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
ଶୂନ୍ୟ test_memory_store(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    ପ୍ରତିଜ୍ଞା(x == 123);
    printf("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
ଶୂନ୍ୟ test_ଗଦା_memory_operand(ଶୂନ୍ୟ)
{
    long x = 0;
    long val = 321;

    asm ଅସ୍ଥିର("str %0, %1" : : "r"(val), "m"(x));
    ପ୍ରତିଜ୍ଞା(x == 321);
    printf("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
ସ୍ଥିର long arm64_ପ୍ରତୀକ_mem;

ଶୂନ୍ୟ test_ପ୍ରତୀକ_memory_operand(ଶୂନ୍ୟ)
{
    long val = 654;

    arm64_ପ୍ରତୀକ_mem = 0;
    asm ଅସ୍ଥିର("str %0, %1" : : "r"(val), "m"(arm64_ପ୍ରତୀକ_mem));
    ପ୍ରତିଜ୍ଞା(arm64_ପ୍ରତୀକ_mem == 654);
    printf("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
ଶୂନ୍ୟ test_clobber_list(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 10;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y = 20;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା result;
    asm("add %0, %1, %2" 
        : "=r"(result)
        : "r"(x), "r"(y)
        : "cc");
    ପ୍ରତିଜ୍ଞା(result == 30);
    printf("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
ଶୂନ୍ୟ test_multiple_outputs(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    ପ୍ରତିଜ୍ଞା(a == 1 && b == 2);
    printf("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
ଶୂନ୍ୟ test_constraint_reference(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 10;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    ପ୍ରତିଜ୍ଞା(y == 15);
    printf("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
ଶୂନ୍ୟ test_early_clobber(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 10;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    ପ୍ରତିଜ୍ଞା(y == 42);
    printf("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
ଶୂନ୍ୟ test_w_register(ଶୂନ୍ୟ)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    ପ୍ରତିଜ୍ଞା(y == 150);
    printf("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
ଶୂନ୍ୟ test_immediate_i_constraint(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 100;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    ପ୍ରତିଜ୍ଞା(y == 300);
    printf("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
ଶୂନ୍ୟ test_general_operand_constraint(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 50;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    ପ୍ରତିଜ୍ଞା(y == 60);
    printf("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
ଶୂନ୍ୟ test_multiple_io(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a = 10, b = 20;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sum, diff;
    asm("add %0, %1, %2" : "=r"(sum) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    ପ୍ରତିଜ୍ଞା(sum == 30 && diff == -10);
    printf("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
ଶୂନ୍ୟ test_regvar_preservation(ଶୂନ୍ୟ)
{
    ପଞ୍ଜିକରଣ uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t out;

    asm ଅସ୍ଥିର("mov x19, #7; add %0, x19, #1"
        : "=r"(out)
        :
        : "x19");
    ପ୍ରତିଜ୍ଞା(keep == 0x123456789abcdef0ULL);
    ପ୍ରତିଜ୍ଞା(out == 8);
    printf("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
ଶୂନ୍ୟ test_complex_arithmetic(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a = 100, b = 50, c = 25;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା result;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(result)
        : "r"(a), "r"(b), "r"(c));
    ପ୍ରତିଜ୍ଞା(result == 125);
    printf("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
ଶୂନ୍ୟ test_named_operand(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ନିବେଶ = 10;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା output;
    asm("add %[out], %[in], #5"
        : [out] "=r"(output)
        : [in] "r"(ନିବେଶ));
    ପ୍ରତିଜ୍ଞା(output == 15);
    printf("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
ଶୂନ୍ୟ test_memory_clobber(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 10;
    asm ଅସ୍ଥିର("" : : : "memory");
    ପ୍ରତିଜ୍ଞା(x == 10);
    printf("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
ଶୂନ୍ୟ test_cc_clobber(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 100;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    ପ୍ରତିଜ୍ଞା(y == 100);
    printf("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
ଶୂନ୍ୟ test_large_immediate(ଶୂନ୍ୟ)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    ପ୍ରତିଜ୍ଞା(val == 0x12345678ULL);
    printf("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
ଶୂନ୍ୟ test_bitwise_ops(ଶୂନ୍ୟ)
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

    ପ୍ରତିଜ୍ଞା(andv == (a & b));
    ପ୍ରତିଜ୍ଞା(orv == (a | b));
    ପ୍ରତିଜ୍ଞା(xorv == (a ^ b));
    ପ୍ରତିଜ୍ଞା(imm_and == 0xff00ff00ff00ff00ULL);
    printf("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
ଶୂନ୍ୟ test_register_shift_operands(ଶୂନ୍ୟ)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    ପ୍ରତିଜ୍ଞା(shifted == 48);
    ପ୍ରତିଜ୍ଞା(rotated == 0xef0123456789abcdULL);
    printf("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
ଶୂନ୍ୟ test_ror_immediate(ଶୂନ୍ୟ)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    ପ୍ରତିଜ୍ଞା(rotated == 0xef0123456789abcdULL);
    printf("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
ଶୂନ୍ୟ test_fp_register_operand(ଶୂନ୍ୟ)
{
    ଦ୍ୱିଗୁଣ x = 3.5;
    ଦ୍ୱିଗୁଣ y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    ପ୍ରତିଜ୍ଞା(y == x);
    printf("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
ଶୂନ୍ୟ test_zero_constraint(ଶୂନ୍ୟ)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    ପ୍ରତିଜ୍ଞା(y == x);
    printf("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
ଶୂନ୍ୟ test_logical_imm32_constraint(ଶୂନ୍ୟ)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    ପ୍ରତିଜ୍ଞା(y == 0xff);
    printf("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
ଶୂନ୍ୟ test_logical_imm64_constraint(ଶୂନ୍ୟ)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    ପ୍ରତିଜ୍ଞା(y == 0xff00ff00ff00ff00ULL);
    printf("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
ଶୂନ୍ୟ test_mov_imm32_constraint(ଶୂନ୍ୟ)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    ପ୍ରତିଜ୍ଞା(y == 0x1234);
    printf("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
ଶୂନ୍ୟ test_mov_imm64_constraint(ଶୂନ୍ୟ)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    ପ୍ରତିଜ୍ଞା(y == 0x12340000ULL);
    printf("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
ଶୂନ୍ୟ test_x_constraint_fp(ଶୂନ୍ୟ)
{
    ଦ୍ୱିଗୁଣ x = 6.25;
    ଦ୍ୱିଗୁଣ y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    ପ୍ରତିଜ୍ଞା(y == x);
    printf("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
ଶୂନ୍ୟ test_y_constraint_fp(ଶୂନ୍ୟ)
{
    ଦ୍ୱିଗୁଣ x = 7.25;
    ଦ୍ୱିଗୁଣ y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    ପ୍ରତିଜ୍ଞା(y == x);
    printf("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_q_load(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ptr)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    ଫେରନ୍ତୁ y;
}

ଶୂନ୍ୟ test_q_memory_constraint(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 91;
    ପ୍ରତିଜ୍ଞା(arm64_q_load(&x) == 91);
    printf("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
ଶୂନ୍ୟ test_ump_memory_constraint(ଶୂନ୍ୟ)
{
    ସଂରଚନା pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    ପ୍ରତିଜ୍ଞା(a == pair.a);
    ପ୍ରତିଜ୍ଞା(b == pair.b);
    printf("Test 32 (Ump constraint): PASSED\n");
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    printf("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_ନିବେଶ_operand();
    test_read_write_operand();
    test_memory_load();
    test_memory_store();
    test_ଗଦା_memory_operand();
    test_ପ୍ରତୀକ_memory_operand();
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
    ଫେରନ୍ତୁ 0;
}
