/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

நிலையான uint32_t lsl32(uint32_t x, முழு n) { திரும்பு x << n; }
நிலையான uint32_t lsr32(uint32_t x, முழு n) { திரும்பு x >> n; }
நிலையான int32_t  asr32(int32_t  x, முழு n) { திரும்பு x >> n; }
நிலையான uint64_t lsl64(uint64_t x, முழு n) { திரும்பு x << n; }
நிலையான uint64_t lsr64(uint64_t x, முழு n) { திரும்பு x >> n; }
நிலையான int64_t  asr64(int64_t  x, முழு n) { திரும்பு x >> n; }

நிலையான வெறுமை test_shifts(வெறுமை)
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

நிலையான வெறுமை test_ldr_str(வெறுமை)
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

நிலையான வெறுமை test_ldp_stp(வெறுமை)
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

நிலையான மாறிலி எழுத்து *cbz_test(முழு x)
{
    எனில் (x == 0)
        திரும்பு "zero";
    திரும்பு "nonzero";
}

நிலையான மாறிலி எழுத்து *cbnz_test(முழு x)
{
    எனில் (x != 0)
        திரும்பு "nonzero";
    திரும்பு "zero";
}

நிலையான வெறுமை test_cond_branches(வெறுமை)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

நிலையான முழு cond_select(முழு a, முழு b)
{
    /* TCC should generate csel or equivalent */
    திரும்பு a > b ? a : b;
}

நிலையான வெறுமை test_cond_select(வெறுமை)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

நிலையான வெறுமை test_sysregs(வெறுமை)
{
    unsigned முழு fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ நிலையற்ற ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ நிலையற்ற ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ நிலையற்ற ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned முழு check;
        __asm__ நிலையற்ற ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

நிலையான வெறுமை test_nop(வெறுமை)
{
    printf("nop:\n");
    __asm__ நிலையற்ற ("nop");
    __asm__ நிலையற்ற ("nop");
    __asm__ நிலையற்ற ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

நிலையான வெறுமை test_barriers(வெறுமை)
{
    printf("barriers:\n");
    __asm__ நிலையற்ற ("dmb sy");
    __asm__ நிலையற்ற ("dsb sy");
    __asm__ நிலையற்ற ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

நிலையான int64_t mov_x0_x1(int64_t x)
{
    பதிவு int64_t r __asm__("x0") = x;
    __asm__ நிலையற்ற ("" : "=r"(r) : "0"(r));
    திரும்பு r;
}

நிலையான வெறுமை test_mov_reg(வெறுமை)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

கட்டமைப்பு large { int64_t a, b, c, d; };

நிலையான int64_t sum_large(கட்டமைப்பு large s)
{
    திரும்பு s.a + s.b + s.c + s.d;
}

நிலையான கட்டமைப்பு large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    கட்டமைப்பு large s = { a, b, c, d };
    திரும்பு s;
}

நிலையான வெறுமை test_large_structs(வெறுமை)
{
    கட்டமைப்பு large s = { 1, 2, 3, 4 };
    கட்டமைப்பு large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

கட்டமைப்பு s18 { எழுத்து x[18]; };
கட்டமைப்பு s24 { எழுத்து x[24]; };
கட்டமைப்பு s32 { எழுத்து x[32]; };

நிலையான வெறுமை print_s18(கட்டமைப்பு s18 s) { printf("%.18s\n", s.x); }
நிலையான வெறுமை print_s24(கட்டமைப்பு s24 s) { printf("%.24s\n", s.x); }
நிலையான வெறுமை print_s32(கட்டமைப்பு s32 s) { printf("%.32s\n", s.x); }

நிலையான கட்டமைப்பு s18 ret_s18(வெறுமை)
{
    கட்டமைப்பு s18 s = { "123456789012345678" };
    திரும்பு s;
}

நிலையான கட்டமைப்பு s24 ret_s24(வெறுமை)
{
    கட்டமைப்பு s24 s = { "123456789012345678901234" };
    திரும்பு s;
}

நிலையான கட்டமைப்பு s32 ret_s32(வெறுமை)
{
    கட்டமைப்பு s32 s = { "12345678901234567890123456789012" };
    திரும்பு s;
}

நிலையான வெறுமை test_boundary_structs(வெறுமை)
{
    கட்டமைப்பு s18 a;
    கட்டமைப்பு s24 b;
    கட்டமைப்பு s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

முழு முதன்மை(வெறுமை)
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
    திரும்பு 0;
}
