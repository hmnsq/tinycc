/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <stdint.h>
#અન્તર્ભાવ <assert.h>

સંરચના pair64 {
    uint64_t a;
    uint64_t b;
};

સ્થિર પૂર્ણાંક arm64_પ્રતીક_target(શૂન્ય)
{
    પાછા 7;
}

સ્થિર શૂન્ય test_symbolic_address_constraint_compile_only(શૂન્ય)
{
    asm અસ્થિર("" : : "S"(arm64_પ્રતીક_target));
}

/* Test 1: Basic output operand */
શૂન્ય test_basic_output(શૂન્ય)
{
    પૂર્ણાંક x;
    asm("mov %0, #42" : "=r"(x));
    પ્રતિજ્ઞા(x == 42);
    printf("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
શૂન્ય test_આગત_operand(શૂન્ય)
{
    પૂર્ણાંક x = 10;
    પૂર્ણાંક y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    પ્રતિજ્ઞા(y == 15);
    printf("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
શૂન્ય test_read_write_operand(શૂન્ય)
{
    પૂર્ણાંક x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    પ્રતિજ્ઞા(x == 11);
    printf("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
શૂન્ય test_memory_load(શૂન્ય)
{
    પૂર્ણાંક x = 42;
    પૂર્ણાંક y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    પ્રતિજ્ઞા(y == 42);
    printf("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
શૂન્ય test_memory_store(શૂન્ય)
{
    પૂર્ણાંક x;
    પૂર્ણાંક val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    પ્રતિજ્ઞા(x == 123);
    printf("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
શૂન્ય test_ઢગલો_memory_operand(શૂન્ય)
{
    long x = 0;
    long val = 321;

    asm અસ્થિર("str %0, %1" : : "r"(val), "m"(x));
    પ્રતિજ્ઞા(x == 321);
    printf("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
સ્થિર long arm64_પ્રતીક_mem;

શૂન્ય test_પ્રતીક_memory_operand(શૂન્ય)
{
    long val = 654;

    arm64_પ્રતીક_mem = 0;
    asm અસ્થિર("str %0, %1" : : "r"(val), "m"(arm64_પ્રતીક_mem));
    પ્રતિજ્ઞા(arm64_પ્રતીક_mem == 654);
    printf("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
શૂન્ય test_clobber_list(શૂન્ય)
{
    પૂર્ણાંક x = 10;
    પૂર્ણાંક y = 20;
    પૂર્ણાંક result;
    asm("add %0, %1, %2" 
        : "=r"(result)
        : "r"(x), "r"(y)
        : "cc");
    પ્રતિજ્ઞા(result == 30);
    printf("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
શૂન્ય test_multiple_outputs(શૂન્ય)
{
    પૂર્ણાંક a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    પ્રતિજ્ઞા(a == 1 && b == 2);
    printf("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
શૂન્ય test_constraint_reference(શૂન્ય)
{
    પૂર્ણાંક x = 10;
    પૂર્ણાંક y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    પ્રતિજ્ઞા(y == 15);
    printf("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
શૂન્ય test_early_clobber(શૂન્ય)
{
    પૂર્ણાંક x = 10;
    પૂર્ણાંક y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    પ્રતિજ્ઞા(y == 42);
    printf("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
શૂન્ય test_w_register(શૂન્ય)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    પ્રતિજ્ઞા(y == 150);
    printf("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
શૂન્ય test_immediate_i_constraint(શૂન્ય)
{
    પૂર્ણાંક x = 100;
    પૂર્ણાંક y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    પ્રતિજ્ઞા(y == 300);
    printf("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
શૂન્ય test_general_operand_constraint(શૂન્ય)
{
    પૂર્ણાંક x = 50;
    પૂર્ણાંક y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    પ્રતિજ્ઞા(y == 60);
    printf("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
શૂન્ય test_multiple_io(શૂન્ય)
{
    પૂર્ણાંક a = 10, b = 20;
    પૂર્ણાંક sum, diff;
    asm("add %0, %1, %2" : "=r"(sum) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    પ્રતિજ્ઞા(sum == 30 && diff == -10);
    printf("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
શૂન્ય test_regvar_preservation(શૂન્ય)
{
    નોંધણી uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t out;

    asm અસ્થિર("mov x19, #7; add %0, x19, #1"
        : "=r"(out)
        :
        : "x19");
    પ્રતિજ્ઞા(keep == 0x123456789abcdef0ULL);
    પ્રતિજ્ઞા(out == 8);
    printf("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
શૂન્ય test_complex_arithmetic(શૂન્ય)
{
    પૂર્ણાંક a = 100, b = 50, c = 25;
    પૂર્ણાંક result;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(result)
        : "r"(a), "r"(b), "r"(c));
    પ્રતિજ્ઞા(result == 125);
    printf("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
શૂન્ય test_named_operand(શૂન્ય)
{
    પૂર્ણાંક આગત = 10;
    પૂર્ણાંક output;
    asm("add %[out], %[in], #5"
        : [out] "=r"(output)
        : [in] "r"(આગત));
    પ્રતિજ્ઞા(output == 15);
    printf("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
શૂન્ય test_memory_clobber(શૂન્ય)
{
    પૂર્ણાંક x = 10;
    asm અસ્થિર("" : : : "memory");
    પ્રતિજ્ઞા(x == 10);
    printf("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
શૂન્ય test_cc_clobber(શૂન્ય)
{
    પૂર્ણાંક x = 100;
    પૂર્ણાંક y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    પ્રતિજ્ઞા(y == 100);
    printf("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
શૂન્ય test_large_immediate(શૂન્ય)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    પ્રતિજ્ઞા(val == 0x12345678ULL);
    printf("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
શૂન્ય test_bitwise_ops(શૂન્ય)
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

    પ્રતિજ્ઞા(andv == (a & b));
    પ્રતિજ્ઞા(orv == (a | b));
    પ્રતિજ્ઞા(xorv == (a ^ b));
    પ્રતિજ્ઞા(imm_and == 0xff00ff00ff00ff00ULL);
    printf("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
શૂન્ય test_register_shift_operands(શૂન્ય)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    પ્રતિજ્ઞા(shifted == 48);
    પ્રતિજ્ઞા(rotated == 0xef0123456789abcdULL);
    printf("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
શૂન્ય test_ror_immediate(શૂન્ય)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    પ્રતિજ્ઞા(rotated == 0xef0123456789abcdULL);
    printf("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
શૂન્ય test_fp_register_operand(શૂન્ય)
{
    દ્વિગુણ x = 3.5;
    દ્વિગુણ y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    પ્રતિજ્ઞા(y == x);
    printf("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
શૂન્ય test_zero_constraint(શૂન્ય)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    પ્રતિજ્ઞા(y == x);
    printf("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
શૂન્ય test_logical_imm32_constraint(શૂન્ય)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    પ્રતિજ્ઞા(y == 0xff);
    printf("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
શૂન્ય test_logical_imm64_constraint(શૂન્ય)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    પ્રતિજ્ઞા(y == 0xff00ff00ff00ff00ULL);
    printf("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
શૂન્ય test_mov_imm32_constraint(શૂન્ય)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    પ્રતિજ્ઞા(y == 0x1234);
    printf("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
શૂન્ય test_mov_imm64_constraint(શૂન્ય)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    પ્રતિજ્ઞા(y == 0x12340000ULL);
    printf("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
શૂન્ય test_x_constraint_fp(શૂન્ય)
{
    દ્વિગુણ x = 6.25;
    દ્વિગુણ y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    પ્રતિજ્ઞા(y == x);
    printf("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
શૂન્ય test_y_constraint_fp(શૂન્ય)
{
    દ્વિગુણ x = 7.25;
    દ્વિગુણ y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    પ્રતિજ્ઞા(y == x);
    printf("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
સ્થિર પૂર્ણાંક arm64_q_load(પૂર્ણાંક *ptr)
{
    પૂર્ણાંક y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    પાછા y;
}

શૂન્ય test_q_memory_constraint(શૂન્ય)
{
    પૂર્ણાંક x = 91;
    પ્રતિજ્ઞા(arm64_q_load(&x) == 91);
    printf("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
શૂન્ય test_ump_memory_constraint(શૂન્ય)
{
    સંરચના pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    પ્રતિજ્ઞા(a == pair.a);
    પ્રતિજ્ઞા(b == pair.b);
    printf("Test 32 (Ump constraint): PASSED\n");
}

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    printf("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_આગત_operand();
    test_read_write_operand();
    test_memory_load();
    test_memory_store();
    test_ઢગલો_memory_operand();
    test_પ્રતીક_memory_operand();
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
    પાછા 0;
}
