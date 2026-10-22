/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

ಸ್ಥಿರ uint32_t lsl32(uint32_t x, ಪೂರ್ಣಾಙ್ಕ n) { ಪ್ರತ್ಯಾಗಮ x << n; }
ಸ್ಥಿರ uint32_t lsr32(uint32_t x, ಪೂರ್ಣಾಙ್ಕ n) { ಪ್ರತ್ಯಾಗಮ x >> n; }
ಸ್ಥಿರ int32_t  asr32(int32_t  x, ಪೂರ್ಣಾಙ್ಕ n) { ಪ್ರತ್ಯಾಗಮ x >> n; }
ಸ್ಥಿರ uint64_t lsl64(uint64_t x, ಪೂರ್ಣಾಙ್ಕ n) { ಪ್ರತ್ಯಾಗಮ x << n; }
ಸ್ಥಿರ uint64_t lsr64(uint64_t x, ಪೂರ್ಣಾಙ್ಕ n) { ಪ್ರತ್ಯಾಗಮ x >> n; }
ಸ್ಥಿರ int64_t  asr64(int64_t  x, ಪೂರ್ಣಾಙ್ಕ n) { ಪ್ರತ್ಯಾಗಮ x >> n; }

ಸ್ಥಿರ ಶೂನ್ಯ test_shifts(ಶೂನ್ಯ)
{
    printf("shift-imm:\n");
    printf("%x\n", lsl32(1, 0));
    printf("%x\n", lsl32(1, 15));
    printf("%x\n", lsl32(1, 31));
    printf("%x\n", lsr32(0x80000000U, 31));
    printf("%x\n", lsr32(0x80000000U, 16));
    printf("%x\n", asr32(-1, 1));
    printf("%x\n", asr32(-256, 4));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 0));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 32));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 63));
    printf("%llx\n", (unsigned long long)lsr64(0x8000000000000000ULL, 63));
    printf("%llx\n", (unsigned long long)asr64(-1LL, 1));
    printf("%llx\n", (unsigned long long)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_ldr_str(ಶೂನ್ಯ)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    printf("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    printf("%llx\n", (unsigned long long)val);
    val = buf[1];
    printf("%llx\n", (unsigned long long)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    printf("%x\n", (unsigned)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    printf("%llx\n", (unsigned long long)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    printf("%llx %llx\n", (unsigned long long)val,
           (unsigned long long)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_ldp_stp(ಶೂನ್ಯ)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    printf("ldp-stp:\n");
    printf("%llx %llx\n",
           (unsigned long long)dst[0],
           (unsigned long long)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *cbz_test(ಪೂರ್ಣಾಙ್ಕ x)
{
    ಯದಿ (x == 0)
        ಪ್ರತ್ಯಾಗಮ "zero";
    ಪ್ರತ್ಯಾಗಮ "nonzero";
}

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *cbnz_test(ಪೂರ್ಣಾಙ್ಕ x)
{
    ಯದಿ (x != 0)
        ಪ್ರತ್ಯಾಗಮ "nonzero";
    ಪ್ರತ್ಯಾಗಮ "zero";
}

ಸ್ಥಿರ ಶೂನ್ಯ test_cond_branches(ಶೂನ್ಯ)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ cond_select(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
    /* TCC should generate csel or equivalent */
    ಪ್ರತ್ಯಾಗಮ a > b ? a : b;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_cond_select(ಶೂನ್ಯ)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_sysregs(ಶೂನ್ಯ)
{
    unsigned ಪೂರ್ಣಾಙ್ಕ fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ ಚಞ್ಚಲ ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ ಚಞ್ಚಲ ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ ಚಞ್ಚಲ ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned ಪೂರ್ಣಾಙ್ಕ check;
        __asm__ ಚಞ್ಚಲ ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_nop(ಶೂನ್ಯ)
{
    printf("nop:\n");
    __asm__ ಚಞ್ಚಲ ("nop");
    __asm__ ಚಞ್ಚಲ ("nop");
    __asm__ ಚಞ್ಚಲ ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_barriers(ಶೂನ್ಯ)
{
    printf("barriers:\n");
    __asm__ ಚಞ್ಚಲ ("dmb sy");
    __asm__ ಚಞ್ಚಲ ("dsb sy");
    __asm__ ಚಞ್ಚಲ ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

ಸ್ಥಿರ int64_t mov_x0_x1(int64_t x)
{
    ಪಞ್ಜಿಕಾ int64_t r __asm__("x0") = x;
    __asm__ ಚಞ್ಚಲ ("" : "=r"(r) : "0"(r));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_mov_reg(ಶೂನ್ಯ)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

ಸಂರಚನಾ large { int64_t a, b, c, d; };

ಸ್ಥಿರ int64_t sum_large(ಸಂರಚನಾ large s)
{
    ಪ್ರತ್ಯಾಗಮ s.a + s.b + s.c + s.d;
}

ಸ್ಥಿರ ಸಂರಚನಾ large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    ಸಂರಚನಾ large s = { a, b, c, d };
    ಪ್ರತ್ಯಾಗಮ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_large_structs(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ large s = { 1, 2, 3, 4 };
    ಸಂರಚನಾ large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

ಸಂರಚನಾ s18 { ವರ್ಣ x[18]; };
ಸಂರಚನಾ s24 { ವರ್ಣ x[24]; };
ಸಂರಚನಾ s32 { ವರ್ಣ x[32]; };

ಸ್ಥಿರ ಶೂನ್ಯ print_s18(ಸಂರಚನಾ s18 s) { printf("%.18s\n", s.x); }
ಸ್ಥಿರ ಶೂನ್ಯ print_s24(ಸಂರಚನಾ s24 s) { printf("%.24s\n", s.x); }
ಸ್ಥಿರ ಶೂನ್ಯ print_s32(ಸಂರಚನಾ s32 s) { printf("%.32s\n", s.x); }

ಸ್ಥಿರ ಸಂರಚನಾ s18 ret_s18(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ s18 s = { "123456789012345678" };
    ಪ್ರತ್ಯಾಗಮ s;
}

ಸ್ಥಿರ ಸಂರಚನಾ s24 ret_s24(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ s24 s = { "123456789012345678901234" };
    ಪ್ರತ್ಯಾಗಮ s;
}

ಸ್ಥಿರ ಸಂರಚನಾ s32 ret_s32(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ s32 s = { "12345678901234567890123456789012" };
    ಪ್ರತ್ಯಾಗಮ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_boundary_structs(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ s18 a;
    ಸಂರಚನಾ s24 b;
    ಸಂರಚನಾ s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    test_shifts();
    test_ldr_str();
    test_ldp_stp();
    test_cond_branches();
    test_cond_select();
    test_sysregs();
    test_nop();
    test_barriers();
    test_mov_reg();
    test_large_structs();
    test_boundary_structs();
    ಪ್ರತ್ಯಾಗಮ 0;
}
