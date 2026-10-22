/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#ضمن <stdio.h>
#ضمن <stdint.h>

/* ---- shift-by-immediate helpers ---- */

ساكن uint32_t lsl32(uint32_t x, صحيح n) { أرجع x << n; }
ساكن uint32_t lsr32(uint32_t x, صحيح n) { أرجع x >> n; }
ساكن int32_t  asr32(int32_t  x, صحيح n) { أرجع x >> n; }
ساكن uint64_t lsl64(uint64_t x, صحيح n) { أرجع x << n; }
ساكن uint64_t lsr64(uint64_t x, صحيح n) { أرجع x >> n; }
ساكن int64_t  asr64(int64_t  x, صحيح n) { أرجع x >> n; }

ساكن فراغ test_shifts(فراغ)
{
    لکو("shift-imm:\n");
    لکو("%x\n", lsl32(1, 0));
    لکو("%x\n", lsl32(1, 15));
    لکو("%x\n", lsl32(1, 31));
    لکو("%x\n", lsr32(0x80000000U, 31));
    لکو("%x\n", lsr32(0x80000000U, 16));
    لکو("%x\n", asr32(-1, 1));
    لکو("%x\n", asr32(-256, 4));
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)lsl64(1ULL, 0));
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)lsl64(1ULL, 32));
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)lsl64(1ULL, 63));
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)lsr64(0x8000000000000000ULL, 63));
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)asr64(-1LL, 1));
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

ساكن فراغ test_ldr_str(فراغ)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    لکو("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)val);
    val = buf[1];
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    لکو("%x\n", (بنانشان)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    لکو("%llx\n", (بنانشان ڊگهو ڊگهو)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    لکو("%llx %llx\n", (بنانشان ڊگهو ڊگهو)val,
           (بنانشان ڊگهو ڊگهو)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

ساكن فراغ test_ldp_stp(فراغ)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    لکو("ldp-stp:\n");
    لکو("%llx %llx\n",
           (بنانشان ڊگهو ڊگهو)dst[0],
           (بنانشان ڊگهو ڊگهو)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

ساكن ثابت حرف *cbz_test(صحيح x)
{
    إذا (x == 0)
        أرجع "zero";
    أرجع "nonzero";
}

ساكن ثابت حرف *cbnz_test(صحيح x)
{
    إذا (x != 0)
        أرجع "nonzero";
    أرجع "zero";
}

ساكن فراغ test_cond_branches(فراغ)
{
    لکو("cbz-cbnz:\n");
    لکو("%s\n", cbz_test(0));
    لکو("%s\n", cbz_test(42));
    لکو("%s\n", cbnz_test(0));
    لکو("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

ساكن صحيح cond_select(صحيح a, صحيح b)
{
    /* TCC should generate csel or equivalent */
    أرجع a > b ? a : b;
}

ساكن فراغ test_cond_select(فراغ)
{
    لکو("csel:\n");
    لکو("%d\n", cond_select(5, 10));
    لکو("%d\n", cond_select(10, 5));
    لکو("%d\n", cond_select(0, 0));
    لکو("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

ساكن فراغ test_sysregs(فراغ)
{
    بنانشان صحيح fpcr, fpsr;

    لکو("sysregs:\n");

    /* Read FPCR */
    __asm__ متطاير ("mrs %0, fpcr" : "=r"(fpcr));
    لکو("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ متطاير ("mrs %0, fpsr" : "=r"(fpsr));
    لکو("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ متطاير ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        بنانشان صحيح check;
        __asm__ متطاير ("mrs %0, fpcr" : "=r"(check));
        لکو("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

ساكن فراغ test_nop(فراغ)
{
    لکو("nop:\n");
    __asm__ متطاير ("nop");
    __asm__ متطاير ("nop");
    __asm__ متطاير ("nop");
    لکو("ok\n");
}

/* ---- barrier instructions ---- */

ساكن فراغ test_barriers(فراغ)
{
    لکو("barriers:\n");
    __asm__ متطاير ("dmb sy");
    __asm__ متطاير ("dsb sy");
    __asm__ متطاير ("isb");
    لکو("ok\n");
}

/* ---- MOV (register) patterns ---- */

ساكن int64_t mov_x0_x1(int64_t x)
{
    سجل int64_t r __asm__("x0") = x;
    __asm__ متطاير ("" : "=r"(r) : "0"(r));
    أرجع r;
}

ساكن فراغ test_mov_reg(فراغ)
{
    لکو("mov-reg:\n");
    لکو("%lld\n", (ڊگهو ڊگهو)mov_x0_x1(42));
    لکو("%lld\n", (ڊگهو ڊگهو)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

بنية large { int64_t a, b, c, d; };

ساكن int64_t جوڙ_large(بنية large s)
{
    أرجع s.a + s.b + s.c + s.d;
}

ساكن بنية large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    بنية large s = { a, b, c, d };
    أرجع s;
}

ساكن فراغ test_large_structs(فراغ)
{
    بنية large s = { 1, 2, 3, 4 };
    بنية large t;

    لکو("large-struct:\n");
    لکو("%lld\n", (ڊگهو ڊگهو)جوڙ_large(s));

    t = make_large(10, 20, 30, 40);
    لکو("%lld %lld %lld %lld\n",
           (ڊگهو ڊگهو)t.a, (ڊگهو ڊگهو)t.b,
           (ڊگهو ڊگهو)t.c, (ڊگهو ڊگهو)t.d);
}

/* ---- boundary-sized structs ---- */

بنية s18 { حرف x[18]; };
بنية s24 { حرف x[24]; };
بنية s32 { حرف x[32]; };

ساكن فراغ print_s18(بنية s18 s) { لکو("%.18s\n", s.x); }
ساكن فراغ print_s24(بنية s24 s) { لکو("%.24s\n", s.x); }
ساكن فراغ print_s32(بنية s32 s) { لکو("%.32s\n", s.x); }

ساكن بنية s18 ret_s18(فراغ)
{
    بنية s18 s = { "123456789012345678" };
    أرجع s;
}

ساكن بنية s24 ret_s24(فراغ)
{
    بنية s24 s = { "123456789012345678901234" };
    أرجع s;
}

ساكن بنية s32 ret_s32(فراغ)
{
    بنية s32 s = { "12345678901234567890123456789012" };
    أرجع s;
}

ساكن فراغ test_boundary_structs(فراغ)
{
    بنية s18 a;
    بنية s24 b;
    بنية s32 c;

    لکو("boundary-structs:\n");
    a = ret_s18();
    لکو("%.18s\n", a.x);
    b = ret_s24();
    لکو("%.24s\n", b.x);
    c = ret_s32();
    لکو("%.32s\n", c.x);
}

صحيح مکيه(فراغ)
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
    أرجع 0;
}
