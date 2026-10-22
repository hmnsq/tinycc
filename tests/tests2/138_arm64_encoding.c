/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#समावेश <stdio.h>
#समावेश <stdint.h>

/* ---- shift-by-immediate helpers ---- */

अटल uint32_t lsl32(uint32_t x, पूर्णांक n) { वापस x << n; }
अटल uint32_t lsr32(uint32_t x, पूर्णांक n) { वापस x >> n; }
अटल int32_t  asr32(int32_t  x, पूर्णांक n) { वापस x >> n; }
अटल uint64_t lsl64(uint64_t x, पूर्णांक n) { वापस x << n; }
अटल uint64_t lsr64(uint64_t x, पूर्णांक n) { वापस x >> n; }
अटल int64_t  asr64(int64_t  x, पूर्णांक n) { वापस x >> n; }

अटल व्योम test_shifts(व्योम)
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

अटल व्योम test_ldr_str(व्योम)
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

अटल व्योम test_ldp_stp(व्योम)
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

अटल स्थिर अक्षर *cbz_test(पूर्णांक x)
{
    अगर (x == 0)
        वापस "zero";
    वापस "nonzero";
}

अटल स्थिर अक्षर *cbnz_test(पूर्णांक x)
{
    अगर (x != 0)
        वापस "nonzero";
    वापस "zero";
}

अटल व्योम test_cond_branches(व्योम)
{
    म_लिखो("cbz-cbnz:\n");
    म_लिखो("%s\n", cbz_test(0));
    म_लिखो("%s\n", cbz_test(42));
    म_लिखो("%s\n", cbnz_test(0));
    म_लिखो("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

अटल पूर्णांक cond_select(पूर्णांक a, पूर्णांक b)
{
    /* TCC should generate csel or equivalent */
    वापस a > b ? a : b;
}

अटल व्योम test_cond_select(व्योम)
{
    म_लिखो("csel:\n");
    म_लिखो("%d\n", cond_select(5, 10));
    म_लिखो("%d\n", cond_select(10, 5));
    म_लिखो("%d\n", cond_select(0, 0));
    म_लिखो("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

अटल व्योम test_sysregs(व्योम)
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

अटल व्योम test_nop(व्योम)
{
    म_लिखो("nop:\n");
    __asm__ अस्थिर ("nop");
    __asm__ अस्थिर ("nop");
    __asm__ अस्थिर ("nop");
    म_लिखो("ok\n");
}

/* ---- barrier instructions ---- */

अटल व्योम test_barriers(व्योम)
{
    म_लिखो("barriers:\n");
    __asm__ अस्थिर ("dmb sy");
    __asm__ अस्थिर ("dsb sy");
    __asm__ अस्थिर ("isb");
    म_लिखो("ok\n");
}

/* ---- MOV (register) patterns ---- */

अटल int64_t mov_x0_x1(int64_t x)
{
    रेजिस्टर int64_t r __asm__("x0") = x;
    __asm__ अस्थिर ("" : "=r"(r) : "0"(r));
    वापस r;
}

अटल व्योम test_mov_reg(व्योम)
{
    म_लिखो("mov-reg:\n");
    म_लिखो("%lld\n", (दीर्घ दीर्घ)mov_x0_x1(42));
    म_लिखो("%lld\n", (दीर्घ दीर्घ)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

काष्ठा large { int64_t a, b, c, d; };

अटल int64_t योग_large(काष्ठा large s)
{
    वापस s.a + s.b + s.c + s.d;
}

अटल काष्ठा large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    काष्ठा large s = { a, b, c, d };
    वापस s;
}

अटल व्योम test_large_structs(व्योम)
{
    काष्ठा large s = { 1, 2, 3, 4 };
    काष्ठा large t;

    म_लिखो("large-struct:\n");
    म_लिखो("%lld\n", (दीर्घ दीर्घ)योग_large(s));

    t = make_large(10, 20, 30, 40);
    म_लिखो("%lld %lld %lld %lld\n",
           (दीर्घ दीर्घ)t.a, (दीर्घ दीर्घ)t.b,
           (दीर्घ दीर्घ)t.c, (दीर्घ दीर्घ)t.d);
}

/* ---- boundary-sized structs ---- */

काष्ठा s18 { अक्षर x[18]; };
काष्ठा s24 { अक्षर x[24]; };
काष्ठा s32 { अक्षर x[32]; };

अटल व्योम print_s18(काष्ठा s18 s) { म_लिखो("%.18s\n", s.x); }
अटल व्योम print_s24(काष्ठा s24 s) { म_लिखो("%.24s\n", s.x); }
अटल व्योम print_s32(काष्ठा s32 s) { म_लिखो("%.32s\n", s.x); }

अटल काष्ठा s18 ret_s18(व्योम)
{
    काष्ठा s18 s = { "123456789012345678" };
    वापस s;
}

अटल काष्ठा s24 ret_s24(व्योम)
{
    काष्ठा s24 s = { "123456789012345678901234" };
    वापस s;
}

अटल काष्ठा s32 ret_s32(व्योम)
{
    काष्ठा s32 s = { "12345678901234567890123456789012" };
    वापस s;
}

अटल व्योम test_boundary_structs(व्योम)
{
    काष्ठा s18 a;
    काष्ठा s24 b;
    काष्ठा s32 c;

    म_लिखो("boundary-structs:\n");
    a = ret_s18();
    म_लिखो("%.18s\n", a.x);
    b = ret_s24();
    म_लिखो("%.24s\n", b.x);
    c = ret_s32();
    म_लिखो("%.32s\n", c.x);
}

पूर्णांक मुख्य(व्योम)
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
    वापस 0;
}
