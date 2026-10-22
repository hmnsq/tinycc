/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdint.h>

/* ---- shift-by-immediate helpers ---- */

स्थिर uint32_t lsl32(uint32_t x, पूर्णाङ्क n) { प्रत्यागम x << n; }
स्थिर uint32_t lsr32(uint32_t x, पूर्णाङ्क n) { प्रत्यागम x >> n; }
स्थिर int32_t  asr32(int32_t  x, पूर्णाङ्क n) { प्रत्यागम x >> n; }
स्थिर uint64_t lsl64(uint64_t x, पूर्णाङ्क n) { प्रत्यागम x << n; }
स्थिर uint64_t lsr64(uint64_t x, पूर्णाङ्क n) { प्रत्यागम x >> n; }
स्थिर int64_t  asr64(int64_t  x, पूर्णाङ्क n) { प्रत्यागम x >> n; }

स्थिर शून्य test_shifts(शून्य)
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

स्थिर शून्य test_ldr_str(शून्य)
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

स्थिर शून्य test_ldp_stp(शून्य)
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

स्थिर ध्रुव वर्ण *cbz_test(पूर्णाङ्क x)
{
    जइ (x == 0)
        प्रत्यागम "zero";
    प्रत्यागम "nonzero";
}

स्थिर ध्रुव वर्ण *cbnz_test(पूर्णाङ्क x)
{
    जइ (x != 0)
        प्रत्यागम "nonzero";
    प्रत्यागम "zero";
}

स्थिर शून्य test_cond_branches(शून्य)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

स्थिर पूर्णाङ्क cond_select(पूर्णाङ्क a, पूर्णाङ्क b)
{
    /* TCC should generate csel or equivalent */
    प्रत्यागम a > b ? a : b;
}

स्थिर शून्य test_cond_select(शून्य)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

स्थिर शून्य test_sysregs(शून्य)
{
    unsigned पूर्णाङ्क fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ चञ्चल ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ चञ्चल ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ चञ्चल ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned पूर्णाङ्क check;
        __asm__ चञ्चल ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

स्थिर शून्य test_nop(शून्य)
{
    printf("nop:\n");
    __asm__ चञ्चल ("nop");
    __asm__ चञ्चल ("nop");
    __asm__ चञ्चल ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

स्थिर शून्य test_barriers(शून्य)
{
    printf("barriers:\n");
    __asm__ चञ्चल ("dmb sy");
    __asm__ चञ्चल ("dsb sy");
    __asm__ चञ्चल ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

स्थिर int64_t mov_x0_x1(int64_t x)
{
    पञ्जिका int64_t r __asm__("x0") = x;
    __asm__ चञ्चल ("" : "=r"(r) : "0"(r));
    प्रत्यागम r;
}

स्थिर शून्य test_mov_reg(शून्य)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

संरचना large { int64_t a, b, c, d; };

स्थिर int64_t sum_large(संरचना large s)
{
    प्रत्यागम s.a + s.b + s.c + s.d;
}

स्थिर संरचना large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    संरचना large s = { a, b, c, d };
    प्रत्यागम s;
}

स्थिर शून्य test_large_structs(शून्य)
{
    संरचना large s = { 1, 2, 3, 4 };
    संरचना large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

संरचना s18 { वर्ण x[18]; };
संरचना s24 { वर्ण x[24]; };
संरचना s32 { वर्ण x[32]; };

स्थिर शून्य print_s18(संरचना s18 s) { printf("%.18s\n", s.x); }
स्थिर शून्य print_s24(संरचना s24 s) { printf("%.24s\n", s.x); }
स्थिर शून्य print_s32(संरचना s32 s) { printf("%.32s\n", s.x); }

स्थिर संरचना s18 ret_s18(शून्य)
{
    संरचना s18 s = { "123456789012345678" };
    प्रत्यागम s;
}

स्थिर संरचना s24 ret_s24(शून्य)
{
    संरचना s24 s = { "123456789012345678901234" };
    प्रत्यागम s;
}

स्थिर संरचना s32 ret_s32(शून्य)
{
    संरचना s32 s = { "12345678901234567890123456789012" };
    प्रत्यागम s;
}

स्थिर शून्य test_boundary_structs(शून्य)
{
    संरचना s18 a;
    संरचना s24 b;
    संरचना s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

पूर्णाङ्क main(शून्य)
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
    प्रत्यागम 0;
}
