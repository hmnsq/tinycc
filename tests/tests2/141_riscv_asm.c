#ಅನ್ತರ್ಭಾವ <stdio.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

ಪೂರ್ಣಾಂಕ test_neg(ಪೂರ್ಣಾಂಕ x)
{
    ಪೂರ್ಣಾಂಕ r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    ಹಿಂತಿರುಗಿ r;
}

ದೀರ್ಘ ದೀರ್ಘ test_negw(ದೀರ್ಘ ದೀರ್ಘ x)
{
    ಪೂರ್ಣಾಂಕ r;
    asm("negw %0, %1" : "=r"(r) : "r"((ಪೂರ್ಣಾಂಕ)x));
    ಹಿಂತಿರುಗಿ (ದೀರ್ಘ ದೀರ್ಘ)r;
}

ದೀರ್ಘ ದೀರ್ಘ test_sextw(ಪೂರ್ಣಾಂಕ x)
{
    ದೀರ್ಘ ದೀರ್ಘ r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    ಹಿಂತಿರುಗಿ r;
}

ದಶಮಾಂಶ test_fmv_s(ದಶಮಾಂಶ a)
{
    ದಶಮಾಂಶ r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    ಹಿಂತಿರುಗಿ r;
}

ದಶಮಾಂಶ test_fneg_s(ದಶಮಾಂಶ a)
{
    ದಶಮಾಂಶ r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    ಹಿಂತಿರುಗಿ r;
}

ದ್ವಿಗುಣ test_fmv_d(ದ್ವಿಗುಣ a)
{
    ದ್ವಿಗುಣ r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    ಹಿಂತಿರುಗಿ r;
}

ದ್ವಿಗುಣ test_fneg_d(ದ್ವಿಗುಣ a)
{
    ದ್ವಿಗುಣ r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    ಹಿಂತಿರುಗಿ r;
}

ಪೂರ್ಣಾಂಕ test_pseudo(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ok = 1;

    ಆದರೆ (test_neg(42) != -42) {
        ಬರೆ("FAIL: neg\n");
        ok = 0;
    }
    ಆದರೆ (test_negw(100) != -100) {
        ಬರೆ("FAIL: negw\n");
        ok = 0;
    }
    ಆದರೆ (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        ಬರೆ("FAIL: sext.w\n");
        ok = 0;
    }
    ಆದರೆ (test_fmv_s(3.14f) != 3.14f) {
        ಬರೆ("FAIL: fmv.s\n");
        ok = 0;
    }
    ಆದರೆ (test_fneg_s(3.14f) != -3.14f) {
        ಬರೆ("FAIL: fneg.s\n");
        ok = 0;
    }
    ಆದರೆ (test_fmv_d(2.718281828) != 2.718281828) {
        ಬರೆ("FAIL: fmv.d\n");
        ok = 0;
    }
    ಆದರೆ (test_fneg_d(2.718281828) != -2.718281828) {
        ಬರೆ("FAIL: fneg.d\n");
        ok = 0;
    }
    ಹಿಂತಿರುಗಿ ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

ದೀರ್ಘ ದೀರ್ಘ test_li_small(ಶೂನ್ಯ)
{
    ದೀರ್ಘ ದೀರ್ಘ r;
    asm("li %0, 42" : "=r"(r));
    ಹಿಂತಿರುಗಿ r;
}

ದೀರ್ಘ ದೀರ್ಘ test_li_large(ಶೂನ್ಯ)
{
    ದೀರ್ಘ ದೀರ್ಘ r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    ಹಿಂತಿರುಗಿ r;
}

ದೀರ್ಘ ದೀರ್ಘ test_li_negative(ಶೂನ್ಯ)
{
    ದೀರ್ಘ ದೀರ್ಘ r;
    asm("li %0, -1" : "=r"(r));
    ಹಿಂತಿರುಗಿ r;
}

ಪೂರ್ಣಾಂಕ test_ll(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ok = 1;

    ಆದರೆ (test_li_small() != 42) {
        ಬರೆ("FAIL: li small\n");
        ok = 0;
    }
    ಆದರೆ (test_li_large() != 0x123456789ABCDEF0LL) {
        ಬರೆ("FAIL: li large\n");
        ok = 0;
    }
    ಆದರೆ (test_li_negative() != -1) {
        ಬರೆ("FAIL: li negative\n");
        ok = 0;
    }
    ಹಿಂತಿರುಗಿ ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

ದಶಮಾಂಶ test_fadd_s(ದಶಮಾಂಶ a, ದಶಮಾಂಶ b)
{
    ದಶಮಾಂಶ r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ದಶಮಾಂಶ test_fsub_s(ದಶಮಾಂಶ a, ದಶಮಾಂಶ b)
{
    ದಶಮಾಂಶ r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ದಶಮಾಂಶ test_fmul_s(ದಶಮಾಂಶ a, ದಶಮಾಂಶ b)
{
    ದಶಮಾಂಶ r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ದಶಮಾಂಶ test_fdiv_s(ದಶಮಾಂಶ a, ದಶಮಾಂಶ b)
{
    ದಶಮಾಂಶ r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ದ್ವಿಗುಣ test_fadd_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ದ್ವಿಗುಣ test_fsub_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ದ್ವಿಗುಣ test_fmul_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ದ್ವಿಗುಣ test_fdiv_d(ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b)
{
    ದ್ವಿಗುಣ r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ಹಿಂತಿರುಗಿ r;
}

ಪೂರ್ಣಾಂಕ test_farith(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ok = 1;

    ಆದರೆ (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        ಬರೆ("FAIL: fadd.s\n");
        ok = 0;
    }
    ಆದರೆ (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        ಬರೆ("FAIL: fsub.s\n");
        ok = 0;
    }
    ಆದರೆ (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        ಬರೆ("FAIL: fmul.s\n");
        ok = 0;
    }
    ಆದರೆ (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        ಬರೆ("FAIL: fdiv.s\n");
        ok = 0;
    }

    ಆದರೆ (test_fadd_d(1.5, 2.5) != 4.0) {
        ಬರೆ("FAIL: fadd.d\n");
        ok = 0;
    }
    ಆದರೆ (test_fsub_d(5.0, 2.0) != 3.0) {
        ಬರೆ("FAIL: fsub.d\n");
        ok = 0;
    }
    ಆದರೆ (test_fmul_d(3.0, 4.0) != 12.0) {
        ಬರೆ("FAIL: fmul.d\n");
        ok = 0;
    }
    ಆದರೆ (test_fdiv_d(12.0, 4.0) != 3.0) {
        ಬರೆ("FAIL: fdiv.d\n");
        ok = 0;
    }
    ಹಿಂತಿರುಗಿ ok;
}

ಪೂರ್ಣಾಂಕ csr_pseudo_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ok = 1;
    ಪೂರ್ಣಾಂಕ old, tmp;

    asm ಅಸ್ಥಿರ("csrr %0, 0x003" : "=r"(old));

    asm ಅಸ್ಥಿರ("csrr %0, 0x003" : "=r"(tmp));
    ಬರೆ("csrr fcsr=%x\n", (ಚಿಹ್ನೆರಹಿತ)tmp);

    asm ಅಸ್ಥಿರ("csrw 0x003, %0" : : "r"(0xE0));
    asm ಅಸ್ಥಿರ("csrr %0, 0x003" : "=r"(tmp));
    ಬರೆ("csrw: wrote e0 got %x\n", (ಚಿಹ್ನೆರಹಿತ)tmp);
    ಆದರೆ (tmp != 0xE0) { ಬರೆ("FAIL: csrw\n"); ok = 0; }
    asm ಅಸ್ಥಿರ("csrw 0x003, %0" : : "r"(old));

    asm ಅಸ್ಥಿರ("csrwi 0x003, 0x10");
    asm ಅಸ್ಥಿರ("csrr %0, 0x003" : "=r"(tmp));
    ಬರೆ("csrwi: wrote 0x10 got %x\n", (ಚಿಹ್ನೆರಹಿತ)tmp);
    ಆದರೆ (tmp != 0x10) { ಬರೆ("FAIL: csrwi\n"); ok = 0; }
    asm ಅಸ್ಥಿರ("csrw 0x003, %0" : : "r"(old));

    asm ಅಸ್ಥಿರ("csrsi 0x003, 0x03");
    asm ಅಸ್ಥಿರ("csrr %0, 0x003" : "=r"(tmp));
    ಬರೆ("csrsi: old|3=%x\n", (ಚಿಹ್ನೆರಹಿತ)tmp);
    ಆದರೆ ((old | 0x03) != tmp) { ಬರೆ("FAIL: csrsi\n"); ok = 0; }
    asm ಅಸ್ಥಿರ("csrw 0x003, %0" : : "r"(old));

    asm ಅಸ್ಥಿರ("csrci 0x003, 0x03");
    asm ಅಸ್ಥಿರ("csrr %0, 0x003" : "=r"(tmp));
    ಬರೆ("csrci: old&~3=%x\n", (ಚಿಹ್ನೆರಹಿತ)tmp);
    ಆದರೆ ((old & ~0x03) != tmp) { ಬರೆ("FAIL: csrci\n"); ok = 0; }
    asm ಅಸ್ಥಿರ("csrw 0x003, %0" : : "r"(old));

    ಹಿಂತಿರುಗಿ ok;
}

ಪೂರ್ಣಾಂಕ fp_cmp_cvt_main(ಶೂನ್ಯ)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm ಅಸ್ಥಿರ("feq.s a0, fa0, fa1");
    asm ಅಸ್ಥಿರ("feq.d a0, fa0, fa1");
    asm ಅಸ್ಥಿರ("flt.s a0, fa0, fa1");
    asm ಅಸ್ಥಿರ("flt.d a0, fa0, fa1");
    asm ಅಸ್ಥಿರ("fle.s a0, fa0, fa1");
    asm ಅಸ್ಥಿರ("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm ಅಸ್ಥಿರ("fcvt.w.s a0, fa0");
    asm ಅಸ್ಥಿರ("fcvt.wu.s a0, fa0");
    asm ಅಸ್ಥಿರ("fcvt.s.w fa0, a0");
    asm ಅಸ್ಥಿರ("fcvt.w.d a0, fa0");
    asm ಅಸ್ಥಿರ("fcvt.d.w fa0, a0");
    asm ಅಸ್ಥಿರ("fcvt.d.s fa0, fa0");
    asm ಅಸ್ಥಿರ("fcvt.s.d fa0, fa0");

    /* fclass */
    asm ಅಸ್ಥಿರ("fclass.s a0, fa0");
    asm ಅಸ್ಥಿರ("fclass.d a0, fa0");

    ಹಿಂತಿರುಗಿ 1;
}

ಪೂರ್ಣಾಂಕ amo_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 0, r;
    ದೀರ್ಘ ದೀರ್ಘ xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
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
    ಹಿಂತಿರುಗಿ 1;
}

ಪೂರ್ಣಾಂಕ fcvt_ಸುತ್ತು_main(ಶೂನ್ಯ)
{
    asm ಅಸ್ಥಿರ("fcvt.w.s a0, fa0, rne");
    asm ಅಸ್ಥಿರ("fcvt.w.s a0, fa0, rtz");
    asm ಅಸ್ಥಿರ("fcvt.w.s a0, fa0, rup");
    asm ಅಸ್ಥಿರ("fcvt.w.d a0, fa0, rne");
    asm ಅಸ್ಥಿರ("fcvt.w.d a0, fa0, rtz");
    ಹಿಂತಿರುಗಿ 1;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_ಸುತ್ತು_main();
    ಬರೆ("%s\n", ok ? "PASS" : "FAIL");
    ಹಿಂತಿರುಗಿ !ok;
}

#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಬರೆ("SKIP\n");
}
#ಆದರೆ_ಅಂತ್ಯ
