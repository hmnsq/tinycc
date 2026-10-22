/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdint.h>

/* ---- shift-by-immediate helpers ---- */

स्थिर uint32_t lsl32(uint32_t x, पूर्णांक n) { परत x << n; }
स्थिर uint32_t lsr32(uint32_t x, पूर्णांक n) { परत x >> n; }
स्थिर int32_t  asr32(int32_t  x, पूर्णांक n) { परत x >> n; }
स्थिर uint64_t lsl64(uint64_t x, पूर्णांक n) { परत x << n; }
स्थिर uint64_t lsr64(uint64_t x, पूर्णांक n) { परत x >> n; }
स्थिर int64_t  asr64(int64_t  x, पूर्णांक n) { परत x >> n; }

स्थिर शून्य test_shifts(शून्य)
{
    म_लिखो("shift-imm:\n");
    म_लिखो("%x\n", lsl32(1, 0));
    म_लिखो("%x\n", lsl32(1, 15));
    म_लिखो("%x\n", lsl32(1, 31));
    म_लिखो("%x\n", lsr32(0x80000000U, 31));
    म_लिखो("%x\n", lsr32(0x80000000U, 16));
    म_लिखो("%x\n", asr32(-1, 1));
    म_लिखो("%x\n", asr32(-256, 4));
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)lsl64(1ULL, 0));
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)lsl64(1ULL, 32));
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)lsl64(1ULL, 63));
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)lsr64(0x8000000000000000ULL, 63));
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)asr64(-1LL, 1));
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

स्थिर शून्य test_ldr_str(शून्य)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    म_लिखो("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)val);
    val = buf[1];
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    म_लिखो("%x\n", (अचिन्हित)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    म_लिखो("%llx\n", (अचिन्हित दीर्घ दीर्घ)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    म_लिखो("%llx %llx\n", (अचिन्हित दीर्घ दीर्घ)val,
           (अचिन्हित दीर्घ दीर्घ)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

स्थिर शून्य test_ldp_stp(शून्य)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    म_लिखो("ldp-stp:\n");
    म_लिखो("%llx %llx\n",
           (अचिन्हित दीर्घ दीर्घ)dst[0],
           (अचिन्हित दीर्घ दीर्घ)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

स्थिर स्थिरांक अक्षर *cbz_test(पूर्णांक x)
{
    जर (x == 0)
        परत "zero";
    परत "nonzero";
}

स्थिर स्थिरांक अक्षर *cbnz_test(पूर्णांक x)
{
    जर (x != 0)
        परत "nonzero";
    परत "zero";
}

स्थिर शून्य test_cond_branches(शून्य)
{
    म_लिखो("cbz-cbnz:\n");
    म_लिखो("%s\n", cbz_test(0));
    म_लिखो("%s\n", cbz_test(42));
    म_लिखो("%s\n", cbnz_test(0));
    म_लिखो("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

स्थिर पूर्णांक cond_select(पूर्णांक a, पूर्णांक b)
{
    /* TCC should generate csel or equivalent */
    परत a > b ? a : b;
}

स्थिर शून्य test_cond_select(शून्य)
{
    म_लिखो("csel:\n");
    म_लिखो("%d\n", cond_select(5, 10));
    म_लिखो("%d\n", cond_select(10, 5));
    म_लिखो("%d\n", cond_select(0, 0));
    म_लिखो("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

स्थिर शून्य test_sysregs(शून्य)
{
    अचिन्हित पूर्णांक fpcr, fpsr;

    म_लिखो("sysregs:\n");

    /* Read FPCR */
    __asm__ अस्थिर ("mrs %0, fpcr" : "=r"(fpcr));
    म_लिखो("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ अस्थिर ("mrs %0, fpsr" : "=r"(fpsr));
    म_लिखो("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ अस्थिर ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        अचिन्हित पूर्णांक check;
        __asm__ अस्थिर ("mrs %0, fpcr" : "=r"(check));
        म_लिखो("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

स्थिर शून्य test_nop(शून्य)
{
    म_लिखो("nop:\n");
    __asm__ अस्थिर ("nop");
    __asm__ अस्थिर ("nop");
    __asm__ अस्थिर ("nop");
    म_लिखो("ok\n");
}

/* ---- barrier instructions ---- */

स्थिर शून्य test_barriers(शून्य)
{
    म_लिखो("barriers:\n");
    __asm__ अस्थिर ("dmb sy");
    __asm__ अस्थिर ("dsb sy");
    __asm__ अस्थिर ("isb");
    म_लिखो("ok\n");
}

/* ---- MOV (register) patterns ---- */

स्थिर int64_t mov_x0_x1(int64_t x)
{
    नोंदणी int64_t r __asm__("x0") = x;
    __asm__ अस्थिर ("" : "=r"(r) : "0"(r));
    परत r;
}

स्थिर शून्य test_mov_reg(शून्य)
{
    म_लिखो("mov-reg:\n");
    म_लिखो("%lld\n", (दीर्घ दीर्घ)mov_x0_x1(42));
    म_लिखो("%lld\n", (दीर्घ दीर्घ)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

संरचना large { int64_t a, b, c, d; };

स्थिर int64_t sum_large(संरचना large s)
{
    परत s.a + s.b + s.c + s.d;
}

स्थिर संरचना large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    संरचना large s = { a, b, c, d };
    परत s;
}

स्थिर शून्य test_large_structs(शून्य)
{
    संरचना large s = { 1, 2, 3, 4 };
    संरचना large t;

    म_लिखो("large-struct:\n");
    म_लिखो("%lld\n", (दीर्घ दीर्घ)sum_large(s));

    t = make_large(10, 20, 30, 40);
    म_लिखो("%lld %lld %lld %lld\n",
           (दीर्घ दीर्घ)t.a, (दीर्घ दीर्घ)t.b,
           (दीर्घ दीर्घ)t.c, (दीर्घ दीर्घ)t.d);
}

/* ---- boundary-sized structs ---- */

संरचना s18 { अक्षर x[18]; };
संरचना s24 { अक्षर x[24]; };
संरचना s32 { अक्षर x[32]; };

स्थिर शून्य print_s18(संरचना s18 s) { म_लिखो("%.18s\n", s.x); }
स्थिर शून्य print_s24(संरचना s24 s) { म_लिखो("%.24s\n", s.x); }
स्थिर शून्य print_s32(संरचना s32 s) { म_लिखो("%.32s\n", s.x); }

स्थिर संरचना s18 ret_s18(शून्य)
{
    संरचना s18 s = { "123456789012345678" };
    परत s;
}

स्थिर संरचना s24 ret_s24(शून्य)
{
    संरचना s24 s = { "123456789012345678901234" };
    परत s;
}

स्थिर संरचना s32 ret_s32(शून्य)
{
    संरचना s32 s = { "12345678901234567890123456789012" };
    परत s;
}

स्थिर शून्य test_boundary_structs(शून्य)
{
    संरचना s18 a;
    संरचना s24 b;
    संरचना s32 c;

    म_लिखो("boundary-structs:\n");
    a = ret_s18();
    म_लिखो("%.18s\n", a.x);
    b = ret_s24();
    म_लिखो("%.24s\n", b.x);
    c = ret_s32();
    म_लिखो("%.32s\n", c.x);
}

पूर्णांक main(शून्य)
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
    परत 0;
}
