/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

ಸ್ಥಿರ uint32_t lsl32(uint32_t x, ಪೂರ್ಣಾಂಕ n) { ಹಿಂತಿರುಗಿ x << n; }
ಸ್ಥಿರ uint32_t lsr32(uint32_t x, ಪೂರ್ಣಾಂಕ n) { ಹಿಂತಿರುಗಿ x >> n; }
ಸ್ಥಿರ int32_t  asr32(int32_t  x, ಪೂರ್ಣಾಂಕ n) { ಹಿಂತಿರುಗಿ x >> n; }
ಸ್ಥಿರ uint64_t lsl64(uint64_t x, ಪೂರ್ಣಾಂಕ n) { ಹಿಂತಿರುಗಿ x << n; }
ಸ್ಥಿರ uint64_t lsr64(uint64_t x, ಪೂರ್ಣಾಂಕ n) { ಹಿಂತಿರುಗಿ x >> n; }
ಸ್ಥಿರ int64_t  asr64(int64_t  x, ಪೂರ್ಣಾಂಕ n) { ಹಿಂತಿರುಗಿ x >> n; }

ಸ್ಥಿರ ಶೂನ್ಯ test_shifts(ಶೂನ್ಯ)
{
    ಬರೆ("shift-imm:\n");
    ಬರೆ("%x\n", lsl32(1, 0));
    ಬರೆ("%x\n", lsl32(1, 15));
    ಬರೆ("%x\n", lsl32(1, 31));
    ಬರೆ("%x\n", lsr32(0x80000000U, 31));
    ಬರೆ("%x\n", lsr32(0x80000000U, 16));
    ಬರೆ("%x\n", asr32(-1, 1));
    ಬರೆ("%x\n", asr32(-256, 4));
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)lsl64(1ULL, 0));
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)lsl64(1ULL, 32));
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)lsl64(1ULL, 63));
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)lsr64(0x8000000000000000ULL, 63));
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)asr64(-1LL, 1));
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_ldr_str(ಶೂನ್ಯ)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    ಬರೆ("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)val);
    val = buf[1];
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    ಬರೆ("%x\n", (ಚಿಹ್ನೆರಹಿತ)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    ಬರೆ("%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    ಬರೆ("%llx %llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)val,
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_ldp_stp(ಶೂನ್ಯ)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    ಬರೆ("ldp-stp:\n");
    ಬರೆ("%llx %llx\n",
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)dst[0],
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *cbz_test(ಪೂರ್ಣಾಂಕ x)
{
    ಆದರೆ (x == 0)
        ಹಿಂತಿರುಗಿ "zero";
    ಹಿಂತಿರುಗಿ "nonzero";
}

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *cbnz_test(ಪೂರ್ಣಾಂಕ x)
{
    ಆದರೆ (x != 0)
        ಹಿಂತಿರುಗಿ "nonzero";
    ಹಿಂತಿರುಗಿ "zero";
}

ಸ್ಥಿರ ಶೂನ್ಯ test_cond_branches(ಶೂನ್ಯ)
{
    ಬರೆ("cbz-cbnz:\n");
    ಬರೆ("%s\n", cbz_test(0));
    ಬರೆ("%s\n", cbz_test(42));
    ಬರೆ("%s\n", cbnz_test(0));
    ಬರೆ("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ cond_select(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
{
    /* TCC should generate csel or equivalent */
    ಹಿಂತಿರುಗಿ a > b ? a : b;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_cond_select(ಶೂನ್ಯ)
{
    ಬರೆ("csel:\n");
    ಬರೆ("%d\n", cond_select(5, 10));
    ಬರೆ("%d\n", cond_select(10, 5));
    ಬರೆ("%d\n", cond_select(0, 0));
    ಬರೆ("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_sysregs(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ fpcr, fpsr;

    ಬರೆ("sysregs:\n");

    /* Read FPCR */
    __asm__ ಅಸ್ಥಿರ ("mrs %0, fpcr" : "=r"(fpcr));
    ಬರೆ("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ ಅಸ್ಥಿರ ("mrs %0, fpsr" : "=r"(fpsr));
    ಬರೆ("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ ಅಸ್ಥಿರ ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ check;
        __asm__ ಅಸ್ಥಿರ ("mrs %0, fpcr" : "=r"(check));
        ಬರೆ("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_nop(ಶೂನ್ಯ)
{
    ಬರೆ("nop:\n");
    __asm__ ಅಸ್ಥಿರ ("nop");
    __asm__ ಅಸ್ಥಿರ ("nop");
    __asm__ ಅಸ್ಥಿರ ("nop");
    ಬರೆ("ok\n");
}

/* ---- barrier instructions ---- */

ಸ್ಥಿರ ಶೂನ್ಯ test_barriers(ಶೂನ್ಯ)
{
    ಬರೆ("barriers:\n");
    __asm__ ಅಸ್ಥಿರ ("dmb sy");
    __asm__ ಅಸ್ಥಿರ ("dsb sy");
    __asm__ ಅಸ್ಥಿರ ("isb");
    ಬರೆ("ok\n");
}

/* ---- MOV (register) patterns ---- */

ಸ್ಥಿರ int64_t mov_x0_x1(int64_t x)
{
    ನೋಂದಣಿ int64_t r __asm__("x0") = x;
    __asm__ ಅಸ್ಥಿರ ("" : "=r"(r) : "0"(r));
    ಹಿಂತಿರುಗಿ r;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_mov_reg(ಶೂನ್ಯ)
{
    ಬರೆ("mov-reg:\n");
    ಬರೆ("%lld\n", (ದೀರ್ಘ ದೀರ್ಘ)mov_x0_x1(42));
    ಬರೆ("%lld\n", (ದೀರ್ಘ ದೀರ್ಘ)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

ರಚನೆ large { int64_t a, b, c, d; };

ಸ್ಥಿರ int64_t ಮೊತ್ತ_large(ರಚನೆ large s)
{
    ಹಿಂತಿರುಗಿ s.a + s.b + s.c + s.d;
}

ಸ್ಥಿರ ರಚನೆ large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    ರಚನೆ large s = { a, b, c, d };
    ಹಿಂತಿರುಗಿ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_large_structs(ಶೂನ್ಯ)
{
    ರಚನೆ large s = { 1, 2, 3, 4 };
    ರಚನೆ large t;

    ಬರೆ("large-struct:\n");
    ಬರೆ("%lld\n", (ದೀರ್ಘ ದೀರ್ಘ)ಮೊತ್ತ_large(s));

    t = make_large(10, 20, 30, 40);
    ಬರೆ("%lld %lld %lld %lld\n",
           (ದೀರ್ಘ ದೀರ್ಘ)t.a, (ದೀರ್ಘ ದೀರ್ಘ)t.b,
           (ದೀರ್ಘ ದೀರ್ಘ)t.c, (ದೀರ್ಘ ದೀರ್ಘ)t.d);
}

/* ---- boundary-sized structs ---- */

ರಚನೆ s18 { ಅಕ್ಷರ x[18]; };
ರಚನೆ s24 { ಅಕ್ಷರ x[24]; };
ರಚನೆ s32 { ಅಕ್ಷರ x[32]; };

ಸ್ಥಿರ ಶೂನ್ಯ print_s18(ರಚನೆ s18 s) { ಬರೆ("%.18s\n", s.x); }
ಸ್ಥಿರ ಶೂನ್ಯ print_s24(ರಚನೆ s24 s) { ಬರೆ("%.24s\n", s.x); }
ಸ್ಥಿರ ಶೂನ್ಯ print_s32(ರಚನೆ s32 s) { ಬರೆ("%.32s\n", s.x); }

ಸ್ಥಿರ ರಚನೆ s18 ret_s18(ಶೂನ್ಯ)
{
    ರಚನೆ s18 s = { "123456789012345678" };
    ಹಿಂತಿರುಗಿ s;
}

ಸ್ಥಿರ ರಚನೆ s24 ret_s24(ಶೂನ್ಯ)
{
    ರಚನೆ s24 s = { "123456789012345678901234" };
    ಹಿಂತಿರುಗಿ s;
}

ಸ್ಥಿರ ರಚನೆ s32 ret_s32(ಶೂನ್ಯ)
{
    ರಚನೆ s32 s = { "12345678901234567890123456789012" };
    ಹಿಂತಿರುಗಿ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_boundary_structs(ಶೂನ್ಯ)
{
    ರಚನೆ s18 a;
    ರಚನೆ s24 b;
    ರಚನೆ s32 c;

    ಬರೆ("boundary-structs:\n");
    a = ret_s18();
    ಬರೆ("%.18s\n", a.x);
    b = ret_s24();
    ಬರೆ("%.24s\n", b.x);
    c = ret_s32();
    ಬರೆ("%.32s\n", c.x);
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
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
    ಹಿಂತಿರುಗಿ 0;
}
