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
    لکھو("shift-imm:\n");
    لکھو("%x\n", lsl32(1, 0));
    لکھو("%x\n", lsl32(1, 15));
    لکھو("%x\n", lsl32(1, 31));
    لکھو("%x\n", lsr32(0x80000000U, 31));
    لکھو("%x\n", lsr32(0x80000000U, 16));
    لکھو("%x\n", asr32(-1, 1));
    لکھو("%x\n", asr32(-256, 4));
    لکھو("%llx\n", (بنانشانی لما لما)lsl64(1ULL, 0));
    لکھو("%llx\n", (بنانشانی لما لما)lsl64(1ULL, 32));
    لکھو("%llx\n", (بنانشانی لما لما)lsl64(1ULL, 63));
    لکھو("%llx\n", (بنانشانی لما لما)lsr64(0x8000000000000000ULL, 63));
    لکھو("%llx\n", (بنانشانی لما لما)asr64(-1LL, 1));
    لکھو("%llx\n", (بنانشانی لما لما)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

ساكن فراغ test_ldr_str(فراغ)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    لکھو("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    لکھو("%llx\n", (بنانشانی لما لما)val);
    val = buf[1];
    لکھو("%llx\n", (بنانشانی لما لما)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    لکھو("%x\n", (بنانشانی)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    لکھو("%llx\n", (بنانشانی لما لما)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    لکھو("%llx %llx\n", (بنانشانی لما لما)val,
           (بنانشانی لما لما)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

ساكن فراغ test_ldp_stp(فراغ)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    لکھو("ldp-stp:\n");
    لکھو("%llx %llx\n",
           (بنانشانی لما لما)dst[0],
           (بنانشانی لما لما)dst[1]);
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
    لکھو("cbz-cbnz:\n");
    لکھو("%s\n", cbz_test(0));
    لکھو("%s\n", cbz_test(42));
    لکھو("%s\n", cbnz_test(0));
    لکھو("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

ساكن صحيح cond_select(صحيح a, صحيح b)
{
    /* TCC should generate csel or equivalent */
    أرجع a > b ? a : b;
}

ساكن فراغ test_cond_select(فراغ)
{
    لکھو("csel:\n");
    لکھو("%d\n", cond_select(5, 10));
    لکھو("%d\n", cond_select(10, 5));
    لکھو("%d\n", cond_select(0, 0));
    لکھو("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

ساكن فراغ test_sysregs(فراغ)
{
    بنانشانی صحيح fpcr, fpsr;

    لکھو("sysregs:\n");

    /* Read FPCR */
    __asm__ متطاير ("mrs %0, fpcr" : "=r"(fpcr));
    لکھو("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ متطاير ("mrs %0, fpsr" : "=r"(fpsr));
    لکھو("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ متطاير ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        بنانشانی صحيح check;
        __asm__ متطاير ("mrs %0, fpcr" : "=r"(check));
        لکھو("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

ساكن فراغ test_nop(فراغ)
{
    لکھو("nop:\n");
    __asm__ متطاير ("nop");
    __asm__ متطاير ("nop");
    __asm__ متطاير ("nop");
    لکھو("ok\n");
}

/* ---- barrier instructions ---- */

ساكن فراغ test_barriers(فراغ)
{
    لکھو("barriers:\n");
    __asm__ متطاير ("dmb sy");
    __asm__ متطاير ("dsb sy");
    __asm__ متطاير ("isb");
    لکھو("ok\n");
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
    لکھو("mov-reg:\n");
    لکھو("%lld\n", (لما لما)mov_x0_x1(42));
    لکھو("%lld\n", (لما لما)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

بنية large { int64_t a, b, c, d; };

ساكن int64_t جوڑ_large(بنية large s)
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

    لکھو("large-struct:\n");
    لکھو("%lld\n", (لما لما)جوڑ_large(s));

    t = make_large(10, 20, 30, 40);
    لکھو("%lld %lld %lld %lld\n",
           (لما لما)t.a, (لما لما)t.b,
           (لما لما)t.c, (لما لما)t.d);
}

/* ---- boundary-sized structs ---- */

بنية s18 { حرف x[18]; };
بنية s24 { حرف x[24]; };
بنية s32 { حرف x[32]; };

ساكن فراغ print_s18(بنية s18 s) { لکھو("%.18s\n", s.x); }
ساكن فراغ print_s24(بنية s24 s) { لکھو("%.24s\n", s.x); }
ساكن فراغ print_s32(بنية s32 s) { لکھو("%.32s\n", s.x); }

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

    لکھو("boundary-structs:\n");
    a = ret_s18();
    لکھو("%.18s\n", a.x);
    b = ret_s24();
    لکھو("%.24s\n", b.x);
    c = ret_s32();
    لکھو("%.32s\n", c.x);
}

صحيح مکھ(فراغ)
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
