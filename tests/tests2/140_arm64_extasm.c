/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <stdint.h>
#அந்தர்பாவ <assert.h>

கட்டமைப்பு pair64 {
    uint64_t a;
    uint64_t b;
};

நிலையான முழு arm64_குறியீடு_target(வெறுமை)
{
    திரும்பு 7;
}

நிலையான வெறுமை test_symbolic_address_constraint_compile_only(வெறுமை)
{
    asm நிலையற்ற("" : : "S"(arm64_குறியீடு_target));
}

/* Test 1: Basic output operand */
வெறுமை test_basic_output(வெறுமை)
{
    முழு x;
    asm("mov %0, #42" : "=r"(x));
    ப்ரதிஜ்ஞா(x == 42);
    printf("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
வெறுமை test_உள்ளீடு_operand(வெறுமை)
{
    முழு x = 10;
    முழு y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    ப்ரதிஜ்ஞா(y == 15);
    printf("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
வெறுமை test_read_write_operand(வெறுமை)
{
    முழு x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    ப்ரதிஜ்ஞா(x == 11);
    printf("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
வெறுமை test_memory_load(வெறுமை)
{
    முழு x = 42;
    முழு y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    ப்ரதிஜ்ஞா(y == 42);
    printf("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
வெறுமை test_memory_store(வெறுமை)
{
    முழு x;
    முழு val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    ப்ரதிஜ்ஞா(x == 123);
    printf("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
வெறுமை test_அடுக்கு_memory_operand(வெறுமை)
{
    long x = 0;
    long val = 321;

    asm நிலையற்ற("str %0, %1" : : "r"(val), "m"(x));
    ப்ரதிஜ்ஞா(x == 321);
    printf("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
நிலையான long arm64_குறியீடு_mem;

வெறுமை test_குறியீடு_memory_operand(வெறுமை)
{
    long val = 654;

    arm64_குறியீடு_mem = 0;
    asm நிலையற்ற("str %0, %1" : : "r"(val), "m"(arm64_குறியீடு_mem));
    ப்ரதிஜ்ஞா(arm64_குறியீடு_mem == 654);
    printf("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
வெறுமை test_clobber_list(வெறுமை)
{
    முழு x = 10;
    முழு y = 20;
    முழு result;
    asm("add %0, %1, %2" 
        : "=r"(result)
        : "r"(x), "r"(y)
        : "cc");
    ப்ரதிஜ்ஞா(result == 30);
    printf("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
வெறுமை test_multiple_outputs(வெறுமை)
{
    முழு a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    ப்ரதிஜ்ஞா(a == 1 && b == 2);
    printf("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
வெறுமை test_constraint_reference(வெறுமை)
{
    முழு x = 10;
    முழு y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    ப்ரதிஜ்ஞா(y == 15);
    printf("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
வெறுமை test_early_clobber(வெறுமை)
{
    முழு x = 10;
    முழு y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    ப்ரதிஜ்ஞா(y == 42);
    printf("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
வெறுமை test_w_register(வெறுமை)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    ப்ரதிஜ்ஞா(y == 150);
    printf("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
வெறுமை test_immediate_i_constraint(வெறுமை)
{
    முழு x = 100;
    முழு y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    ப்ரதிஜ்ஞா(y == 300);
    printf("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
வெறுமை test_general_operand_constraint(வெறுமை)
{
    முழு x = 50;
    முழு y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    ப்ரதிஜ்ஞா(y == 60);
    printf("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
வெறுமை test_multiple_io(வெறுமை)
{
    முழு a = 10, b = 20;
    முழு sum, diff;
    asm("add %0, %1, %2" : "=r"(sum) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    ப்ரதிஜ்ஞா(sum == 30 && diff == -10);
    printf("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
வெறுமை test_regvar_preservation(வெறுமை)
{
    பதிவு uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t out;

    asm நிலையற்ற("mov x19, #7; add %0, x19, #1"
        : "=r"(out)
        :
        : "x19");
    ப்ரதிஜ்ஞா(keep == 0x123456789abcdef0ULL);
    ப்ரதிஜ்ஞா(out == 8);
    printf("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
வெறுமை test_complex_arithmetic(வெறுமை)
{
    முழு a = 100, b = 50, c = 25;
    முழு result;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(result)
        : "r"(a), "r"(b), "r"(c));
    ப்ரதிஜ்ஞா(result == 125);
    printf("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
வெறுமை test_named_operand(வெறுமை)
{
    முழு உள்ளீடு = 10;
    முழு output;
    asm("add %[out], %[in], #5"
        : [out] "=r"(output)
        : [in] "r"(உள்ளீடு));
    ப்ரதிஜ்ஞா(output == 15);
    printf("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
வெறுமை test_memory_clobber(வெறுமை)
{
    முழு x = 10;
    asm நிலையற்ற("" : : : "memory");
    ப்ரதிஜ்ஞா(x == 10);
    printf("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
வெறுமை test_cc_clobber(வெறுமை)
{
    முழு x = 100;
    முழு y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    ப்ரதிஜ்ஞா(y == 100);
    printf("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
வெறுமை test_large_immediate(வெறுமை)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    ப்ரதிஜ்ஞா(val == 0x12345678ULL);
    printf("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
வெறுமை test_bitwise_ops(வெறுமை)
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

    ப்ரதிஜ்ஞா(andv == (a & b));
    ப்ரதிஜ்ஞா(orv == (a | b));
    ப்ரதிஜ்ஞா(xorv == (a ^ b));
    ப்ரதிஜ்ஞா(imm_and == 0xff00ff00ff00ff00ULL);
    printf("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
வெறுமை test_register_shift_operands(வெறுமை)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    ப்ரதிஜ்ஞா(shifted == 48);
    ப்ரதிஜ்ஞா(rotated == 0xef0123456789abcdULL);
    printf("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
வெறுமை test_ror_immediate(வெறுமை)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    ப்ரதிஜ்ஞா(rotated == 0xef0123456789abcdULL);
    printf("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
வெறுமை test_fp_register_operand(வெறுமை)
{
    இரட்டை x = 3.5;
    இரட்டை y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    ப்ரதிஜ்ஞா(y == x);
    printf("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
வெறுமை test_zero_constraint(வெறுமை)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    ப்ரதிஜ்ஞா(y == x);
    printf("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
வெறுமை test_logical_imm32_constraint(வெறுமை)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    ப்ரதிஜ்ஞா(y == 0xff);
    printf("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
வெறுமை test_logical_imm64_constraint(வெறுமை)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    ப்ரதிஜ்ஞா(y == 0xff00ff00ff00ff00ULL);
    printf("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
வெறுமை test_mov_imm32_constraint(வெறுமை)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    ப்ரதிஜ்ஞா(y == 0x1234);
    printf("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
வெறுமை test_mov_imm64_constraint(வெறுமை)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    ப்ரதிஜ்ஞா(y == 0x12340000ULL);
    printf("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
வெறுமை test_x_constraint_fp(வெறுமை)
{
    இரட்டை x = 6.25;
    இரட்டை y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    ப்ரதிஜ்ஞா(y == x);
    printf("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
வெறுமை test_y_constraint_fp(வெறுமை)
{
    இரட்டை x = 7.25;
    இரட்டை y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    ப்ரதிஜ்ஞா(y == x);
    printf("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
நிலையான முழு arm64_q_load(முழு *ptr)
{
    முழு y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    திரும்பு y;
}

வெறுமை test_q_memory_constraint(வெறுமை)
{
    முழு x = 91;
    ப்ரதிஜ்ஞா(arm64_q_load(&x) == 91);
    printf("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
வெறுமை test_ump_memory_constraint(வெறுமை)
{
    கட்டமைப்பு pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    ப்ரதிஜ்ஞா(a == pair.a);
    ப்ரதிஜ்ஞா(b == pair.b);
    printf("Test 32 (Ump constraint): PASSED\n");
}

முழு முதன்மை(வெறுமை)
{
    printf("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_உள்ளீடு_operand();
    test_read_write_operand();
    test_memory_load();
    test_memory_store();
    test_அடுக்கு_memory_operand();
    test_குறியீடு_memory_operand();
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
    திரும்பு 0;
}
