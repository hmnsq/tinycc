#ಅನ್ತರ್ಭಾವ <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

ಪೂರ್ಣಾಙ್ಕ test_neg(ಪೂರ್ಣಾಙ್ಕ x)
{
    ಪೂರ್ಣಾಙ್ಕ r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    ಪ್ರತ್ಯಾಗಮ r;
}

long long test_negw(long long x)
{
    ಪೂರ್ಣಾಙ್ಕ r;
    asm("negw %0, %1" : "=r"(r) : "r"((ಪೂರ್ಣಾಙ್ಕ)x));
    ಪ್ರತ್ಯಾಗಮ (long long)r;
}

long long test_sextw(ಪೂರ್ಣಾಙ್ಕ x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಭಿನ್ನ test_fmv_s(ಭಿನ್ನ a)
{
    ಭಿನ್ನ r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಭಿನ್ನ test_fneg_s(ಭಿನ್ನ a)
{
    ಭಿನ್ನ r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    ಪ್ರತ್ಯಾಗಮ r;
}

ದ್ವಿಗುಣ test_fmv_d(ದ್ವಿಗುಣ a)
{
    ದ್ವಿಗುಣ r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    ಪ್ರತ್ಯಾಗಮ r;
}

ದ್ವಿಗುಣ test_fneg_d(ದ್ವಿಗುಣ a)
{
    ದ್ವಿಗುಣ r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಪೂರ್ಣಾಙ್ಕ test_pseudo(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;

    ಯದಿ (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    ಯದಿ (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    ಯದಿ (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    ಯದಿ (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    ಯದಿ (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    ಯದಿ (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    ಯದಿ (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    ಪ್ರತ್ಯಾಗಮ ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(ಶೂನ್ಯ)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    ಪ್ರತ್ಯಾಗಮ r;
}

long long test_li_large(ಶೂನ್ಯ)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    ಪ್ರತ್ಯಾಗಮ r;
}

long long test_li_negative(ಶೂನ್ಯ)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಪೂರ್ಣಾಙ್ಕ test_ll(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;

    ಯದಿ (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    ಯದಿ (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    ಯದಿ (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    ಪ್ರತ್ಯಾಗಮ ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

ಭಿನ್ನ test_fadd_s(ಭಿನ್ನ a, ಭಿನ್ನ b)
{
    ಭಿನ್ನ r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಭಿನ್ನ test_fsub_s(ಭಿನ್ನ a, ಭಿನ್ನ b)
{
    ಭಿನ್ನ r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಭಿನ್ನ test_fmul_s(ಭಿನ್ನ a, ಭಿನ್ನ b)
{
    ಭಿನ್ನ r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಭಿನ್ನ test_fdiv_s(ಭಿನ್ನ a, ಭಿನ್ನ b)
{
    ಭಿನ್ನ r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ದ್ವಿಗುಣ test_fadd_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ದ್ವಿಗುಣ test_fsub_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ದ್ವಿಗುಣ test_fmul_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ದ್ವಿಗುಣ test_fdiv_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಪ್ರತ್ಯಾಗಮ r;
}

ಪೂರ್ಣಾಙ್ಕ test_farith(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;

    ಯದಿ (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    ಯದಿ (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    ಯದಿ (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    ಯದಿ (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    ಯದಿ (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    ಯದಿ (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    ಯದಿ (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    ಯದಿ (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    ಪ್ರತ್ಯಾಗಮ ok;
}

ಪೂರ್ಣಾಙ್ಕ csr_pseudo_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;
    ಪೂರ್ಣಾಙ್ಕ old, tmp;

    asm ಚಞ್ಚಲ("csrr %0, 0x003" : "=r"(old));

    asm ಚಞ್ಚಲ("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm ಚಞ್ಚಲ("csrw 0x003, %0" : : "r"(0xE0));
    asm ಚಞ್ಚಲ("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    ಯದಿ (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm ಚಞ್ಚಲ("csrw 0x003, %0" : : "r"(old));

    asm ಚಞ್ಚಲ("csrwi 0x003, 0x10");
    asm ಚಞ್ಚಲ("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    ಯದಿ (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm ಚಞ್ಚಲ("csrw 0x003, %0" : : "r"(old));

    asm ಚಞ್ಚಲ("csrsi 0x003, 0x03");
    asm ಚಞ್ಚಲ("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    ಯದಿ ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm ಚಞ್ಚಲ("csrw 0x003, %0" : : "r"(old));

    asm ಚಞ್ಚಲ("csrci 0x003, 0x03");
    asm ಚಞ್ಚಲ("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    ಯದಿ ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm ಚಞ್ಚಲ("csrw 0x003, %0" : : "r"(old));

    ಪ್ರತ್ಯಾಗಮ ok;
}

ಪೂರ್ಣಾಙ್ಕ fp_cmp_cvt_main(ಶೂನ್ಯ)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm ಚಞ್ಚಲ("feq.s a0, fa0, fa1");
    asm ಚಞ್ಚಲ("feq.d a0, fa0, fa1");
    asm ಚಞ್ಚಲ("flt.s a0, fa0, fa1");
    asm ಚಞ್ಚಲ("flt.d a0, fa0, fa1");
    asm ಚಞ್ಚಲ("fle.s a0, fa0, fa1");
    asm ಚಞ್ಚಲ("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm ಚಞ್ಚಲ("fcvt.w.s a0, fa0");
    asm ಚಞ್ಚಲ("fcvt.wu.s a0, fa0");
    asm ಚಞ್ಚಲ("fcvt.s.w fa0, a0");
    asm ಚಞ್ಚಲ("fcvt.w.d a0, fa0");
    asm ಚಞ್ಚಲ("fcvt.d.w fa0, a0");
    asm ಚಞ್ಚಲ("fcvt.d.s fa0, fa0");
    asm ಚಞ್ಚಲ("fcvt.s.d fa0, fa0");

    /* fclass */
    asm ಚಞ್ಚಲ("fclass.s a0, fa0");
    asm ಚಞ್ಚಲ("fclass.d a0, fa0");

    ಪ್ರತ್ಯಾಗಮ 1;
}

ಪೂರ್ಣಾಙ್ಕ amo_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ x = 0, r;
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
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಪೂರ್ಣಾಙ್ಕ fcvt_round_main(ಶೂನ್ಯ)
{
    asm ಚಞ್ಚಲ("fcvt.w.s a0, fa0, rne");
    asm ಚಞ್ಚಲ("fcvt.w.s a0, fa0, rtz");
    asm ಚಞ್ಚಲ("fcvt.w.s a0, fa0, rup");
    asm ಚಞ್ಚಲ("fcvt.w.d a0, fa0, rne");
    asm ಚಞ್ಚಲ("fcvt.w.d a0, fa0, rtz");
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಪೂರ್ಣಾಙ್ಕ main()
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    ಪ್ರತ್ಯಾಗಮ !ok;
}

#ಅನ್ಯಥಾ
ಪೂರ್ಣಾಙ್ಕ main()
{
    printf("SKIP\n");
}
#endif
