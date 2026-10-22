/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

ਸਥਿਰ uint32_t lsl32(uint32_t x, ਪੂਰਨ n) { ਵਾਪਸ x << n; }
ਸਥਿਰ uint32_t lsr32(uint32_t x, ਪੂਰਨ n) { ਵਾਪਸ x >> n; }
ਸਥਿਰ int32_t  asr32(int32_t  x, ਪੂਰਨ n) { ਵਾਪਸ x >> n; }
ਸਥਿਰ uint64_t lsl64(uint64_t x, ਪੂਰਨ n) { ਵਾਪਸ x << n; }
ਸਥਿਰ uint64_t lsr64(uint64_t x, ਪੂਰਨ n) { ਵਾਪਸ x >> n; }
ਸਥਿਰ int64_t  asr64(int64_t  x, ਪੂਰਨ n) { ਵਾਪਸ x >> n; }

ਸਥਿਰ ਖਾਲੀ test_shifts(ਖਾਲੀ)
{
    ਲਿਖੋ("shift-imm:\n");
    ਲਿਖੋ("%x\n", lsl32(1, 0));
    ਲਿਖੋ("%x\n", lsl32(1, 15));
    ਲਿਖੋ("%x\n", lsl32(1, 31));
    ਲਿਖੋ("%x\n", lsr32(0x80000000U, 31));
    ਲਿਖੋ("%x\n", lsr32(0x80000000U, 16));
    ਲਿਖੋ("%x\n", asr32(-1, 1));
    ਲਿਖੋ("%x\n", asr32(-256, 4));
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)lsl64(1ULL, 0));
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)lsl64(1ULL, 32));
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)lsl64(1ULL, 63));
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)lsr64(0x8000000000000000ULL, 63));
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)asr64(-1LL, 1));
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

ਸਥਿਰ ਖਾਲੀ test_ldr_str(ਖਾਲੀ)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    ਲਿਖੋ("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)val);
    val = buf[1];
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    ਲਿਖੋ("%x\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    ਲਿਖੋ("%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    ਲਿਖੋ("%llx %llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)val,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

ਸਥਿਰ ਖਾਲੀ test_ldp_stp(ਖਾਲੀ)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    ਲਿਖੋ("ldp-stp:\n");
    ਲਿਖੋ("%llx %llx\n",
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)dst[0],
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

ਸਥਿਰ ਅਚਲ ਅੱਖਰ *cbz_test(ਪੂਰਨ x)
{
    ਜੇ (x == 0)
        ਵਾਪਸ "zero";
    ਵਾਪਸ "nonzero";
}

ਸਥਿਰ ਅਚਲ ਅੱਖਰ *cbnz_test(ਪੂਰਨ x)
{
    ਜੇ (x != 0)
        ਵਾਪਸ "nonzero";
    ਵਾਪਸ "zero";
}

ਸਥਿਰ ਖਾਲੀ test_cond_branches(ਖਾਲੀ)
{
    ਲਿਖੋ("cbz-cbnz:\n");
    ਲਿਖੋ("%s\n", cbz_test(0));
    ਲਿਖੋ("%s\n", cbz_test(42));
    ਲਿਖੋ("%s\n", cbnz_test(0));
    ਲਿਖੋ("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

ਸਥਿਰ ਪੂਰਨ cond_select(ਪੂਰਨ a, ਪੂਰਨ b)
{
    /* TCC should generate csel or equivalent */
    ਵਾਪਸ a > b ? a : b;
}

ਸਥਿਰ ਖਾਲੀ test_cond_select(ਖਾਲੀ)
{
    ਲਿਖੋ("csel:\n");
    ਲਿਖੋ("%d\n", cond_select(5, 10));
    ਲਿਖੋ("%d\n", cond_select(10, 5));
    ਲਿਖੋ("%d\n", cond_select(0, 0));
    ਲਿਖੋ("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

ਸਥਿਰ ਖਾਲੀ test_sysregs(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ fpcr, fpsr;

    ਲਿਖੋ("sysregs:\n");

    /* Read FPCR */
    __asm__ ਅਸਥਿਰ ("mrs %0, fpcr" : "=r"(fpcr));
    ਲਿਖੋ("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ ਅਸਥਿਰ ("mrs %0, fpsr" : "=r"(fpsr));
    ਲਿਖੋ("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ ਅਸਥਿਰ ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ check;
        __asm__ ਅਸਥਿਰ ("mrs %0, fpcr" : "=r"(check));
        ਲਿਖੋ("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

ਸਥਿਰ ਖਾਲੀ test_nop(ਖਾਲੀ)
{
    ਲਿਖੋ("nop:\n");
    __asm__ ਅਸਥਿਰ ("nop");
    __asm__ ਅਸਥਿਰ ("nop");
    __asm__ ਅਸਥਿਰ ("nop");
    ਲਿਖੋ("ok\n");
}

/* ---- barrier instructions ---- */

ਸਥਿਰ ਖਾਲੀ test_barriers(ਖਾਲੀ)
{
    ਲਿਖੋ("barriers:\n");
    __asm__ ਅਸਥਿਰ ("dmb sy");
    __asm__ ਅਸਥਿਰ ("dsb sy");
    __asm__ ਅਸਥਿਰ ("isb");
    ਲਿਖੋ("ok\n");
}

/* ---- MOV (register) patterns ---- */

ਸਥਿਰ int64_t mov_x0_x1(int64_t x)
{
    ਰਜਿਸਟਰ int64_t r __asm__("x0") = x;
    __asm__ ਅਸਥਿਰ ("" : "=r"(r) : "0"(r));
    ਵਾਪਸ r;
}

ਸਥਿਰ ਖਾਲੀ test_mov_reg(ਖਾਲੀ)
{
    ਲਿਖੋ("mov-reg:\n");
    ਲਿਖੋ("%lld\n", (ਲੰਮਾ ਲੰਮਾ)mov_x0_x1(42));
    ਲਿਖੋ("%lld\n", (ਲੰਮਾ ਲੰਮਾ)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

ਬਣਤਰ large { int64_t a, b, c, d; };

ਸਥਿਰ int64_t ਜੋੜ_large(ਬਣਤਰ large s)
{
    ਵਾਪਸ s.a + s.b + s.c + s.d;
}

ਸਥਿਰ ਬਣਤਰ large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    ਬਣਤਰ large s = { a, b, c, d };
    ਵਾਪਸ s;
}

ਸਥਿਰ ਖਾਲੀ test_large_structs(ਖਾਲੀ)
{
    ਬਣਤਰ large s = { 1, 2, 3, 4 };
    ਬਣਤਰ large t;

    ਲਿਖੋ("large-struct:\n");
    ਲਿਖੋ("%lld\n", (ਲੰਮਾ ਲੰਮਾ)ਜੋੜ_large(s));

    t = make_large(10, 20, 30, 40);
    ਲਿਖੋ("%lld %lld %lld %lld\n",
           (ਲੰਮਾ ਲੰਮਾ)t.a, (ਲੰਮਾ ਲੰਮਾ)t.b,
           (ਲੰਮਾ ਲੰਮਾ)t.c, (ਲੰਮਾ ਲੰਮਾ)t.d);
}

/* ---- boundary-sized structs ---- */

ਬਣਤਰ s18 { ਅੱਖਰ x[18]; };
ਬਣਤਰ s24 { ਅੱਖਰ x[24]; };
ਬਣਤਰ s32 { ਅੱਖਰ x[32]; };

ਸਥਿਰ ਖਾਲੀ print_s18(ਬਣਤਰ s18 s) { ਲਿਖੋ("%.18s\n", s.x); }
ਸਥਿਰ ਖਾਲੀ print_s24(ਬਣਤਰ s24 s) { ਲਿਖੋ("%.24s\n", s.x); }
ਸਥਿਰ ਖਾਲੀ print_s32(ਬਣਤਰ s32 s) { ਲਿਖੋ("%.32s\n", s.x); }

ਸਥਿਰ ਬਣਤਰ s18 ret_s18(ਖਾਲੀ)
{
    ਬਣਤਰ s18 s = { "123456789012345678" };
    ਵਾਪਸ s;
}

ਸਥਿਰ ਬਣਤਰ s24 ret_s24(ਖਾਲੀ)
{
    ਬਣਤਰ s24 s = { "123456789012345678901234" };
    ਵਾਪਸ s;
}

ਸਥਿਰ ਬਣਤਰ s32 ret_s32(ਖਾਲੀ)
{
    ਬਣਤਰ s32 s = { "12345678901234567890123456789012" };
    ਵਾਪਸ s;
}

ਸਥਿਰ ਖਾਲੀ test_boundary_structs(ਖਾਲੀ)
{
    ਬਣਤਰ s18 a;
    ਬਣਤਰ s24 b;
    ਬਣਤਰ s32 c;

    ਲਿਖੋ("boundary-structs:\n");
    a = ret_s18();
    ਲਿਖੋ("%.18s\n", a.x);
    b = ret_s24();
    ਲਿਖੋ("%.24s\n", b.x);
    c = ret_s32();
    ਲਿਖੋ("%.32s\n", c.x);
}

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
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
    ਵਾਪਸ 0;
}
