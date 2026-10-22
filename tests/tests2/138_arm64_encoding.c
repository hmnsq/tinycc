/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

സ്ഥിതം uint32_t lsl32(uint32_t x, പൂർണ്ണസംഖ്യ n) { തിരികെ x << n; }
സ്ഥിതം uint32_t lsr32(uint32_t x, പൂർണ്ണസംഖ്യ n) { തിരികെ x >> n; }
സ്ഥിതം int32_t  asr32(int32_t  x, പൂർണ്ണസംഖ്യ n) { തിരികെ x >> n; }
സ്ഥിതം uint64_t lsl64(uint64_t x, പൂർണ്ണസംഖ്യ n) { തിരികെ x << n; }
സ്ഥിതം uint64_t lsr64(uint64_t x, പൂർണ്ണസംഖ്യ n) { തിരികെ x >> n; }
സ്ഥിതം int64_t  asr64(int64_t  x, പൂർണ്ണസംഖ്യ n) { തിരികെ x >> n; }

സ്ഥിതം ശൂന്യം test_shifts(ശൂന്യം)
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

സ്ഥിതം ശൂന്യം test_ldr_str(ശൂന്യം)
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

സ്ഥിതം ശൂന്യം test_ldp_stp(ശൂന്യം)
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

സ്ഥിതം സ്ഥിരം അക്ഷരം *cbz_test(പൂർണ്ണസംഖ്യ x)
{
    എങ്കിൽ (x == 0)
        തിരികെ "zero";
    തിരികെ "nonzero";
}

സ്ഥിതം സ്ഥിരം അക്ഷരം *cbnz_test(പൂർണ്ണസംഖ്യ x)
{
    എങ്കിൽ (x != 0)
        തിരികെ "nonzero";
    തിരികെ "zero";
}

സ്ഥിതം ശൂന്യം test_cond_branches(ശൂന്യം)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

സ്ഥിതം പൂർണ്ണസംഖ്യ cond_select(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
    /* TCC should generate csel or equivalent */
    തിരികെ a > b ? a : b;
}

സ്ഥിതം ശൂന്യം test_cond_select(ശൂന്യം)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

സ്ഥിതം ശൂന്യം test_sysregs(ശൂന്യം)
{
    unsigned പൂർണ്ണസംഖ്യ fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ അസ്ഥിര ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ അസ്ഥിര ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ അസ്ഥിര ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned പൂർണ്ണസംഖ്യ check;
        __asm__ അസ്ഥിര ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

സ്ഥിതം ശൂന്യം test_nop(ശൂന്യം)
{
    printf("nop:\n");
    __asm__ അസ്ഥിര ("nop");
    __asm__ അസ്ഥിര ("nop");
    __asm__ അസ്ഥിര ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

സ്ഥിതം ശൂന്യം test_barriers(ശൂന്യം)
{
    printf("barriers:\n");
    __asm__ അസ്ഥിര ("dmb sy");
    __asm__ അസ്ഥിര ("dsb sy");
    __asm__ അസ്ഥിര ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

സ്ഥിതം int64_t mov_x0_x1(int64_t x)
{
    രജിസ്റ്റർ int64_t r __asm__("x0") = x;
    __asm__ അസ്ഥിര ("" : "=r"(r) : "0"(r));
    തിരികെ r;
}

സ്ഥിതം ശൂന്യം test_mov_reg(ശൂന്യം)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

ഘടന large { int64_t a, b, c, d; };

സ്ഥിതം int64_t sum_large(ഘടന large s)
{
    തിരികെ s.a + s.b + s.c + s.d;
}

സ്ഥിതം ഘടന large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    ഘടന large s = { a, b, c, d };
    തിരികെ s;
}

സ്ഥിതം ശൂന്യം test_large_structs(ശൂന്യം)
{
    ഘടന large s = { 1, 2, 3, 4 };
    ഘടന large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

ഘടന s18 { അക്ഷരം x[18]; };
ഘടന s24 { അക്ഷരം x[24]; };
ഘടന s32 { അക്ഷരം x[32]; };

സ്ഥിതം ശൂന്യം print_s18(ഘടന s18 s) { printf("%.18s\n", s.x); }
സ്ഥിതം ശൂന്യം print_s24(ഘടന s24 s) { printf("%.24s\n", s.x); }
സ്ഥിതം ശൂന്യം print_s32(ഘടന s32 s) { printf("%.32s\n", s.x); }

സ്ഥിതം ഘടന s18 ret_s18(ശൂന്യം)
{
    ഘടന s18 s = { "123456789012345678" };
    തിരികെ s;
}

സ്ഥിതം ഘടന s24 ret_s24(ശൂന്യം)
{
    ഘടന s24 s = { "123456789012345678901234" };
    തിരികെ s;
}

സ്ഥിതം ഘടന s32 ret_s32(ശൂന്യം)
{
    ഘടന s32 s = { "12345678901234567890123456789012" };
    തിരികെ s;
}

സ്ഥിതം ശൂന്യം test_boundary_structs(ശൂന്യം)
{
    ഘടന s18 a;
    ഘടന s24 b;
    ഘടന s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
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
    തിരികെ 0;
}
