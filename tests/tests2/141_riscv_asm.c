#अन्तर्भाव <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

पूर्णाङ्क test_neg(पूर्णाङ्क x)
{
    पूर्णाङ्क r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    प्रत्यागम r;
}

long long test_negw(long long x)
{
    पूर्णाङ्क r;
    asm("negw %0, %1" : "=r"(r) : "r"((पूर्णाङ्क)x));
    प्रत्यागम (long long)r;
}

long long test_sextw(पूर्णाङ्क x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    प्रत्यागम r;
}

भिन्न test_fmv_s(भिन्न a)
{
    भिन्न r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    प्रत्यागम r;
}

भिन्न test_fneg_s(भिन्न a)
{
    भिन्न r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    प्रत्यागम r;
}

द्विगुण test_fmv_d(द्विगुण a)
{
    द्विगुण r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    प्रत्यागम r;
}

द्विगुण test_fneg_d(द्विगुण a)
{
    द्विगुण r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    प्रत्यागम r;
}

पूर्णाङ्क test_pseudo(शून्य)
{
    पूर्णाङ्क ok = 1;

    यदि (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    यदि (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    यदि (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    यदि (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    यदि (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    यदि (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    यदि (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    प्रत्यागम ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(शून्य)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    प्रत्यागम r;
}

long long test_li_large(शून्य)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    प्रत्यागम r;
}

long long test_li_negative(शून्य)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    प्रत्यागम r;
}

पूर्णाङ्क test_ll(शून्य)
{
    पूर्णाङ्क ok = 1;

    यदि (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    यदि (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    यदि (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    प्रत्यागम ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

भिन्न test_fadd_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

भिन्न test_fsub_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

भिन्न test_fmul_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

भिन्न test_fdiv_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

द्विगुण test_fadd_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

द्विगुण test_fsub_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

द्विगुण test_fmul_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

द्विगुण test_fdiv_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    प्रत्यागम r;
}

पूर्णाङ्क test_farith(शून्य)
{
    पूर्णाङ्क ok = 1;

    यदि (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    यदि (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    यदि (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    यदि (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    यदि (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    यदि (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    यदि (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    यदि (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    प्रत्यागम ok;
}

पूर्णाङ्क csr_pseudo_main(शून्य)
{
    पूर्णाङ्क ok = 1;
    पूर्णाङ्क old, tmp;

    asm चञ्चल("csrr %0, 0x003" : "=r"(old));

    asm चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm चञ्चल("csrw 0x003, %0" : : "r"(0xE0));
    asm चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    यदि (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm चञ्चल("csrw 0x003, %0" : : "r"(old));

    asm चञ्चल("csrwi 0x003, 0x10");
    asm चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    यदि (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm चञ्चल("csrw 0x003, %0" : : "r"(old));

    asm चञ्चल("csrsi 0x003, 0x03");
    asm चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    यदि ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm चञ्चल("csrw 0x003, %0" : : "r"(old));

    asm चञ्चल("csrci 0x003, 0x03");
    asm चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    यदि ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm चञ्चल("csrw 0x003, %0" : : "r"(old));

    प्रत्यागम ok;
}

पूर्णाङ्क fp_cmp_cvt_main(शून्य)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm चञ्चल("feq.s a0, fa0, fa1");
    asm चञ्चल("feq.d a0, fa0, fa1");
    asm चञ्चल("flt.s a0, fa0, fa1");
    asm चञ्चल("flt.d a0, fa0, fa1");
    asm चञ्चल("fle.s a0, fa0, fa1");
    asm चञ्चल("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm चञ्चल("fcvt.w.s a0, fa0");
    asm चञ्चल("fcvt.wu.s a0, fa0");
    asm चञ्चल("fcvt.s.w fa0, a0");
    asm चञ्चल("fcvt.w.d a0, fa0");
    asm चञ्चल("fcvt.d.w fa0, a0");
    asm चञ्चल("fcvt.d.s fa0, fa0");
    asm चञ्चल("fcvt.s.d fa0, fa0");

    /* fclass */
    asm चञ्चल("fclass.s a0, fa0");
    asm चञ्चल("fclass.d a0, fa0");

    प्रत्यागम 1;
}

पूर्णाङ्क amo_main(शून्य)
{
    पूर्णाङ्क x = 0, r;
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
    प्रत्यागम 1;
}

पूर्णाङ्क fcvt_round_main(शून्य)
{
    asm चञ्चल("fcvt.w.s a0, fa0, rne");
    asm चञ्चल("fcvt.w.s a0, fa0, rtz");
    asm चञ्चल("fcvt.w.s a0, fa0, rup");
    asm चञ्चल("fcvt.w.d a0, fa0, rne");
    asm चञ्चल("fcvt.w.d a0, fa0, rtz");
    प्रत्यागम 1;
}

पूर्णाङ्क main()
{
    पूर्णाङ्क ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    प्रत्यागम !ok;
}

#अन्यथा
पूर्णाङ्क main()
{
    printf("SKIP\n");
}
#endif
