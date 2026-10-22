#ଅନ୍ତର୍ଭାଵ <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test_neg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    ଫେରନ୍ତୁ r;
}

long long test_negw(long long x)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    asm("negw %0, %1" : "=r"(r) : "r"((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)x));
    ଫେରନ୍ତୁ (long long)r;
}

long long test_sextw(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    ଫେରନ୍ତୁ r;
}

ଦଶମିକ test_fmv_s(ଦଶମିକ a)
{
    ଦଶମିକ r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    ଫେରନ୍ତୁ r;
}

ଦଶମିକ test_fneg_s(ଦଶମିକ a)
{
    ଦଶମିକ r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    ଫେରନ୍ତୁ r;
}

ଦ୍ୱିଗୁଣ test_fmv_d(ଦ୍ୱିଗୁଣ a)
{
    ଦ୍ୱିଗୁଣ r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    ଫେରନ୍ତୁ r;
}

ଦ୍ୱିଗୁଣ test_fneg_d(ଦ୍ୱିଗୁଣ a)
{
    ଦ୍ୱିଗୁଣ r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    ଫେରନ୍ତୁ r;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test_pseudo(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;

    ଯଦି (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    ଯଦି (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    ଯଦି (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    ଯଦି (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    ଯଦି (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    ଯଦି (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    ଯଦି (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    ଫେରନ୍ତୁ ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(ଶୂନ୍ୟ)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    ଫେରନ୍ତୁ r;
}

long long test_li_large(ଶୂନ୍ୟ)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    ଫେରନ୍ତୁ r;
}

long long test_li_negative(ଶୂନ୍ୟ)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    ଫେରନ୍ତୁ r;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test_ll(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;

    ଯଦି (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    ଯଦି (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    ଯଦି (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    ଫେରନ୍ତୁ ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

ଦଶମିକ test_fadd_s(ଦଶମିକ a, ଦଶମିକ b)
{
    ଦଶମିକ r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ଦଶମିକ test_fsub_s(ଦଶମିକ a, ଦଶମିକ b)
{
    ଦଶମିକ r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ଦଶମିକ test_fmul_s(ଦଶମିକ a, ଦଶମିକ b)
{
    ଦଶମିକ r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ଦଶମିକ test_fdiv_s(ଦଶମିକ a, ଦଶମିକ b)
{
    ଦଶମିକ r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ଦ୍ୱିଗୁଣ test_fadd_d(ଦ୍ୱିଗୁଣ a, ଦ୍ୱିଗୁଣ b)
{
    ଦ୍ୱିଗୁଣ r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ଦ୍ୱିଗୁଣ test_fsub_d(ଦ୍ୱିଗୁଣ a, ଦ୍ୱିଗୁଣ b)
{
    ଦ୍ୱିଗୁଣ r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ଦ୍ୱିଗୁଣ test_fmul_d(ଦ୍ୱିଗୁଣ a, ଦ୍ୱିଗୁଣ b)
{
    ଦ୍ୱିଗୁଣ r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ଦ୍ୱିଗୁଣ test_fdiv_d(ଦ୍ୱିଗୁଣ a, ଦ୍ୱିଗୁଣ b)
{
    ଦ୍ୱିଗୁଣ r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ଫେରନ୍ତୁ r;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test_farith(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;

    ଯଦି (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    ଯଦି (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    ଯଦି (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    ଯଦି (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    ଯଦି (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    ଯଦି (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    ଯଦି (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    ଯଦି (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    ଫେରନ୍ତୁ ok;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା csr_pseudo_main(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା old, tmp;

    asm ଅସ୍ଥିର("csrr %0, 0x003" : "=r"(old));

    asm ଅସ୍ଥିର("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm ଅସ୍ଥିର("csrw 0x003, %0" : : "r"(0xE0));
    asm ଅସ୍ଥିର("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    ଯଦି (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm ଅସ୍ଥିର("csrw 0x003, %0" : : "r"(old));

    asm ଅସ୍ଥିର("csrwi 0x003, 0x10");
    asm ଅସ୍ଥିର("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    ଯଦି (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm ଅସ୍ଥିର("csrw 0x003, %0" : : "r"(old));

    asm ଅସ୍ଥିର("csrsi 0x003, 0x03");
    asm ଅସ୍ଥିର("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    ଯଦି ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm ଅସ୍ଥିର("csrw 0x003, %0" : : "r"(old));

    asm ଅସ୍ଥିର("csrci 0x003, 0x03");
    asm ଅସ୍ଥିର("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    ଯଦି ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm ଅସ୍ଥିର("csrw 0x003, %0" : : "r"(old));

    ଫେରନ୍ତୁ ok;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fp_cmp_cvt_main(ଶୂନ୍ୟ)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm ଅସ୍ଥିର("feq.s a0, fa0, fa1");
    asm ଅସ୍ଥିର("feq.d a0, fa0, fa1");
    asm ଅସ୍ଥିର("flt.s a0, fa0, fa1");
    asm ଅସ୍ଥିର("flt.d a0, fa0, fa1");
    asm ଅସ୍ଥିର("fle.s a0, fa0, fa1");
    asm ଅସ୍ଥିର("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm ଅସ୍ଥିର("fcvt.w.s a0, fa0");
    asm ଅସ୍ଥିର("fcvt.wu.s a0, fa0");
    asm ଅସ୍ଥିର("fcvt.s.w fa0, a0");
    asm ଅସ୍ଥିର("fcvt.w.d a0, fa0");
    asm ଅସ୍ଥିର("fcvt.d.w fa0, a0");
    asm ଅସ୍ଥିର("fcvt.d.s fa0, fa0");
    asm ଅସ୍ଥିର("fcvt.s.d fa0, fa0");

    /* fclass */
    asm ଅସ୍ଥିର("fclass.s a0, fa0");
    asm ଅସ୍ଥିର("fclass.d a0, fa0");

    ଫେରନ୍ତୁ 1;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା amo_main(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 0, r;
    long long xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
    asm("amoadd.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoswap.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoand.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoor.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoxor.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomax.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomaxu.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amomin.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amominu.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoadd.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoadd.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoadd.d.aqrl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoswap.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoswap.d.rl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoand.w.aqrl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoor.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoor.d.aq %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoxor.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomax.d.rl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amomaxu.w.aqrl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomin.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amominu.d.aq %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    ଫେରନ୍ତୁ 1;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fcvt_round_main(ଶୂନ୍ୟ)
{
    asm ଅସ୍ଥିର("fcvt.w.s a0, fa0, rne");
    asm ଅସ୍ଥିର("fcvt.w.s a0, fa0, rtz");
    asm ଅସ୍ଥିର("fcvt.w.s a0, fa0, rup");
    asm ଅସ୍ଥିର("fcvt.w.d a0, fa0, rne");
    asm ଅସ୍ଥିର("fcvt.w.d a0, fa0, rtz");
    ଫେରନ୍ତୁ 1;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    ଫେରନ୍ତୁ !ok;
}

#ଅନ୍ୟଥା
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    printf("SKIP\n");
}
#endif
