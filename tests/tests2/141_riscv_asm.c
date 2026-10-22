#அந்தர்பாவ <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

முழு test_neg(முழு x)
{
    முழு r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    திரும்பு r;
}

long long test_negw(long long x)
{
    முழு r;
    asm("negw %0, %1" : "=r"(r) : "r"((முழு)x));
    திரும்பு (long long)r;
}

long long test_sextw(முழு x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    திரும்பு r;
}

தசம test_fmv_s(தசம a)
{
    தசம r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    திரும்பு r;
}

தசம test_fneg_s(தசம a)
{
    தசம r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    திரும்பு r;
}

இரட்டை test_fmv_d(இரட்டை a)
{
    இரட்டை r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    திரும்பு r;
}

இரட்டை test_fneg_d(இரட்டை a)
{
    இரட்டை r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    திரும்பு r;
}

முழு test_pseudo(வெறுமை)
{
    முழு ok = 1;

    எனில் (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    எனில் (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    எனில் (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    எனில் (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    எனில் (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    எனில் (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    எனில் (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    திரும்பு ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(வெறுமை)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    திரும்பு r;
}

long long test_li_large(வெறுமை)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    திரும்பு r;
}

long long test_li_negative(வெறுமை)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    திரும்பு r;
}

முழு test_ll(வெறுமை)
{
    முழு ok = 1;

    எனில் (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    எனில் (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    எனில் (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    திரும்பு ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

தசம test_fadd_s(தசம a, தசம b)
{
    தசம r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

தசம test_fsub_s(தசம a, தசம b)
{
    தசம r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

தசம test_fmul_s(தசம a, தசம b)
{
    தசம r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

தசம test_fdiv_s(தசம a, தசம b)
{
    தசம r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

இரட்டை test_fadd_d(இரட்டை a, இரட்டை b)
{
    இரட்டை r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

இரட்டை test_fsub_d(இரட்டை a, இரட்டை b)
{
    இரட்டை r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

இரட்டை test_fmul_d(இரட்டை a, இரட்டை b)
{
    இரட்டை r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

இரட்டை test_fdiv_d(இரட்டை a, இரட்டை b)
{
    இரட்டை r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    திரும்பு r;
}

முழு test_farith(வெறுமை)
{
    முழு ok = 1;

    எனில் (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    எனில் (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    எனில் (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    எனில் (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    எனில் (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    எனில் (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    எனில் (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    எனில் (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    திரும்பு ok;
}

முழு csr_pseudo_main(வெறுமை)
{
    முழு ok = 1;
    முழு old, tmp;

    asm நிலையற்ற("csrr %0, 0x003" : "=r"(old));

    asm நிலையற்ற("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm நிலையற்ற("csrw 0x003, %0" : : "r"(0xE0));
    asm நிலையற்ற("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    எனில் (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm நிலையற்ற("csrw 0x003, %0" : : "r"(old));

    asm நிலையற்ற("csrwi 0x003, 0x10");
    asm நிலையற்ற("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    எனில் (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm நிலையற்ற("csrw 0x003, %0" : : "r"(old));

    asm நிலையற்ற("csrsi 0x003, 0x03");
    asm நிலையற்ற("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    எனில் ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm நிலையற்ற("csrw 0x003, %0" : : "r"(old));

    asm நிலையற்ற("csrci 0x003, 0x03");
    asm நிலையற்ற("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    எனில் ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm நிலையற்ற("csrw 0x003, %0" : : "r"(old));

    திரும்பு ok;
}

முழு fp_cmp_cvt_main(வெறுமை)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm நிலையற்ற("feq.s a0, fa0, fa1");
    asm நிலையற்ற("feq.d a0, fa0, fa1");
    asm நிலையற்ற("flt.s a0, fa0, fa1");
    asm நிலையற்ற("flt.d a0, fa0, fa1");
    asm நிலையற்ற("fle.s a0, fa0, fa1");
    asm நிலையற்ற("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm நிலையற்ற("fcvt.w.s a0, fa0");
    asm நிலையற்ற("fcvt.wu.s a0, fa0");
    asm நிலையற்ற("fcvt.s.w fa0, a0");
    asm நிலையற்ற("fcvt.w.d a0, fa0");
    asm நிலையற்ற("fcvt.d.w fa0, a0");
    asm நிலையற்ற("fcvt.d.s fa0, fa0");
    asm நிலையற்ற("fcvt.s.d fa0, fa0");

    /* fclass */
    asm நிலையற்ற("fclass.s a0, fa0");
    asm நிலையற்ற("fclass.d a0, fa0");

    திரும்பு 1;
}

முழு amo_main(வெறுமை)
{
    முழு x = 0, r;
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
    திரும்பு 1;
}

முழு fcvt_round_main(வெறுமை)
{
    asm நிலையற்ற("fcvt.w.s a0, fa0, rne");
    asm நிலையற்ற("fcvt.w.s a0, fa0, rtz");
    asm நிலையற்ற("fcvt.w.s a0, fa0, rup");
    asm நிலையற்ற("fcvt.w.d a0, fa0, rne");
    asm நிலையற்ற("fcvt.w.d a0, fa0, rtz");
    திரும்பு 1;
}

முழு முதன்மை()
{
    முழு ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    திரும்பு !ok;
}

#இல்லையெனில்
முழு முதன்மை()
{
    printf("SKIP\n");
}
#endif
