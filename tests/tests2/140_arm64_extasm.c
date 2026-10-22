/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#ضمن <stdio.h>
#ضمن <stdint.h>
#ضمن <assert.h>

بنية pair64 {
    uint64_t a;
    uint64_t b;
};

ساكن صحيح arm64_symbol_target(فراغ)
{
    החזר 7;
}

ساكن فراغ test_symbolic_address_constraint_compile_only(فراغ)
{
    asm متطاير("" : : "S"(arm64_symbol_target));
}

/* Test 1: Basic output operand */
فراغ test_basic_output(فراغ)
{
    صحيح x;
    asm("mov %0, #42" : "=r"(x));
    أكد(x == 42);
    printf("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
فراغ test_input_operand(فراغ)
{
    صحيح x = 10;
    صحيح y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    أكد(y == 15);
    printf("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
فراغ test_read_write_operand(فراغ)
{
    صحيح x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    أكد(x == 11);
    printf("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
فراغ test_memory_load(فراغ)
{
    صحيح x = 42;
    صحيح y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    أكد(y == 42);
    printf("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
فراغ test_memory_store(فراغ)
{
    صحيح x;
    صحيح val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    أكد(x == 123);
    printf("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
فراغ test_stack_memory_operand(فراغ)
{
    long x = 0;
    long val = 321;

    asm متطاير("str %0, %1" : : "r"(val), "m"(x));
    أكد(x == 321);
    printf("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
ساكن long arm64_symbol_mem;

فراغ test_symbol_memory_operand(فراغ)
{
    long val = 654;

    arm64_symbol_mem = 0;
    asm متطاير("str %0, %1" : : "r"(val), "m"(arm64_symbol_mem));
    أكد(arm64_symbol_mem == 654);
    printf("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
فراغ test_clobber_list(فراغ)
{
    صحيح x = 10;
    صحيح y = 20;
    صحيح result;
    asm("add %0, %1, %2" 
        : "=r"(result)
        : "r"(x), "r"(y)
        : "cc");
    أكد(result == 30);
    printf("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
فراغ test_multiple_outputs(فراغ)
{
    صحيح a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    أكد(a == 1 && b == 2);
    printf("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
فراغ test_constraint_reference(فراغ)
{
    صحيح x = 10;
    صحيح y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    أكد(y == 15);
    printf("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
فراغ test_early_clobber(فراغ)
{
    صحيح x = 10;
    صحيح y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    أكد(y == 42);
    printf("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
فراغ test_w_register(فراغ)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    أكد(y == 150);
    printf("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
فراغ test_immediate_i_constraint(فراغ)
{
    صحيح x = 100;
    صحيح y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    أكد(y == 300);
    printf("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
فراغ test_general_operand_constraint(فراغ)
{
    صحيح x = 50;
    صحيح y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    أكد(y == 60);
    printf("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
فراغ test_multiple_io(فراغ)
{
    صحيح a = 10, b = 20;
    صحيح sum, diff;
    asm("add %0, %1, %2" : "=r"(sum) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    أكد(sum == 30 && diff == -10);
    printf("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
فراغ test_regvar_preservation(فراغ)
{
    سجل uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t out;

    asm متطاير("mov x19, #7; add %0, x19, #1"
        : "=r"(out)
        :
        : "x19");
    أكد(keep == 0x123456789abcdef0ULL);
    أكد(out == 8);
    printf("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
فراغ test_complex_arithmetic(فراغ)
{
    صحيح a = 100, b = 50, c = 25;
    صحيح result;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(result)
        : "r"(a), "r"(b), "r"(c));
    أكد(result == 125);
    printf("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
فراغ test_named_operand(فراغ)
{
    صحيح input = 10;
    صحيح output;
    asm("add %[out], %[in], #5"
        : [out] "=r"(output)
        : [in] "r"(input));
    أكد(output == 15);
    printf("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
فراغ test_memory_clobber(فراغ)
{
    صحيح x = 10;
    asm متطاير("" : : : "memory");
    أكد(x == 10);
    printf("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
فراغ test_cc_clobber(فراغ)
{
    صحيح x = 100;
    صحيح y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    أكد(y == 100);
    printf("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
فراغ test_large_immediate(فراغ)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    أكد(val == 0x12345678ULL);
    printf("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
فراغ test_bitwise_ops(فراغ)
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

    أكد(andv == (a & b));
    أكد(orv == (a | b));
    أكد(xorv == (a ^ b));
    أكد(imm_and == 0xff00ff00ff00ff00ULL);
    printf("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
فراغ test_register_shift_operands(فراغ)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    أكد(shifted == 48);
    أكد(rotated == 0xef0123456789abcdULL);
    printf("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
فراغ test_ror_immediate(فراغ)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    أكد(rotated == 0xef0123456789abcdULL);
    printf("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
فراغ test_fp_register_operand(فراغ)
{
    مزدوج x = 3.5;
    مزدوج y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    أكد(y == x);
    printf("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
فراغ test_zero_constraint(فراغ)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    أكد(y == x);
    printf("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
فراغ test_logical_imm32_constraint(فراغ)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    أكد(y == 0xff);
    printf("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
فراغ test_logical_imm64_constraint(فراغ)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    أكد(y == 0xff00ff00ff00ff00ULL);
    printf("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
فراغ test_mov_imm32_constraint(فراغ)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    أكد(y == 0x1234);
    printf("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
فراغ test_mov_imm64_constraint(فراغ)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    أكد(y == 0x12340000ULL);
    printf("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
فراغ test_x_constraint_fp(فراغ)
{
    مزدوج x = 6.25;
    مزدوج y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    أكد(y == x);
    printf("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
فراغ test_y_constraint_fp(فراغ)
{
    مزدوج x = 7.25;
    مزدوج y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    أكد(y == x);
    printf("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
ساكن صحيح arm64_q_load(صحيح *ptr)
{
    صحيح y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    החזר y;
}

فراغ test_q_memory_constraint(فراغ)
{
    صحيح x = 91;
    أكد(arm64_q_load(&x) == 91);
    printf("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
فراغ test_ump_memory_constraint(فراغ)
{
    بنية pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    أكد(a == pair.a);
    أكد(b == pair.b);
    printf("Test 32 (Ump constraint): PASSED\n");
}

صحيح main(فراغ)
{
    printf("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_input_operand();
    test_read_write_operand();
    test_memory_load();
    test_memory_store();
    test_stack_memory_operand();
    test_symbol_memory_operand();
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
    החזר 0;
}
