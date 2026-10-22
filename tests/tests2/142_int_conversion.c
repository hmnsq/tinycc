#అన్తర్భావ <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

గుర్తులేని అక్షరం get_uc(శూన్య) { తిరిగి 0x80; }
గుర్తుగల అక్షరం get_sc(శూన్య) { తిరిగి 0x80; }
గుర్తులేని పొట్టి get_us(శూన్య) { తిరిగి 0x8000; }
గుర్తుగల పొట్టి get_ss(శూన్య) { తిరిగి 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
గుర్తులేని అక్షరం (* అస్థిర fp_uc)(శూన్య) = get_uc;
గుర్తుగల అక్షరం (* అస్థిర fp_sc)(శూన్య) = get_sc;
గుర్తులేని పొట్టి (* అస్థిర fp_us)(శూన్య) = get_us;
గుర్తుగల పొట్టి (* అస్థిర fp_ss)(శూన్య) = get_ss;

పూర్ణాంకం promote_main(శూన్య)
{
    పూర్ణాంకం ok = 1;
    గుర్తులేని దీర్ఘ దీర్ఘ uc = fp_uc();
    గుర్తుగల దీర్ఘ దీర్ఘ sc = fp_sc();
    గుర్తులేని దీర్ఘ దీర్ఘ us = fp_us();
    గుర్తుగల దీర్ఘ దీర్ఘ ss = fp_ss();

    రాయి("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (గుర్తులేని దీర్ఘ దీర్ఘ)uc,
           (గుర్తులేని దీర్ఘ దీర్ఘ)sc,
           (గుర్తులేని దీర్ఘ దీర్ఘ)us,
           (గుర్తులేని దీర్ఘ దీర్ఘ)ss);

    ఒకవేళ (uc != 0x80) {
        రాయి("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    ఒకవేళ (sc != 0xffffffffffffff80LL) {
        రాయి("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    ఒకవేళ (us != 0x8000) {
        రాయి("FAIL: us not zero-extended\n");
        ok = 0;
    }
    ఒకవేళ (ss != 0xffffffffffff8000LL) {
        రాయి("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    రాయి("%s\n", ok ? "PASS" : "FAIL");
    తిరిగి ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

పూర్ణాంకం cast_main(శూన్య)
{
    పూర్ణాంకం ok = 1;
    పూర్ణాంకం x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    అక్షరం c = (అక్షరం)x + 1;
    గుర్తులేని అక్షరం uc = (గుర్తులేని అక్షరం)x + 1;
    పొట్టి s = (పొట్టి)x + 1;
    గుర్తులేని పొట్టి us = (గుర్తులేని పొట్టి)x + 1;

    రాయి("c=%x uc=%x s=%x us=%x\n",
           (గుర్తులేని అక్షరం)c, (గుర్తులేని)uc,
           (గుర్తులేని పొట్టి)s, (గుర్తులేని)us);

    ఒకవేళ (c != (అక్షరం)0x78 + 1) {
        రాయి("FAIL: char conversion\n");
        ok = 0;
    }
    ఒకవేళ (uc != (గుర్తులేని అక్షరం)0x78 + 1) {
        రాయి("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    ఒకవేళ (s != (పొట్టి)0x5678 + 1) {
        రాయి("FAIL: short conversion\n");
        ok = 0;
    }
    ఒకవేళ (us != (గుర్తులేని పొట్టి)0x5678 + 1) {
        రాయి("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    రాయి("%s\n", ok ? "PASS" : "FAIL");
    తిరిగి ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

పూర్ణాంకం sign_main(శూన్య)
{
    పూర్ణాంకం ok = 1;
    పూర్ణాంకం x = 0x80000000;
    దీర్ఘ దీర్ఘ y = (దీర్ఘ దీర్ఘ)x;

    రాయి("y=%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)y);

    ఒకవేళ (y != 0xffffffff80000000LL) {
        రాయి("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (దీర్ఘ దీర్ఘ)x;
    రాయి("y=%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)y);

    ఒకవేళ (y != 0x40000000LL) {
        రాయి("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    గుర్తులేని పూర్ణాంకం ux = 0x80000000;
    దీర్ఘ దీర్ఘ uy = (దీర్ఘ దీర్ఘ)(పూర్ణాంకం)ux;
    రాయి("uy=%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)uy);

    ఒకవేళ (uy != 0xffffffff80000000LL) {
        రాయి("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    రాయి("%s\n", ok ? "PASS" : "FAIL");
    తిరిగి ok ? 0 : 1;
}

పూర్ణాంకం ప్రధాన()
{
    తిరిగి
        promote_main()
        | cast_main()
        | sign_main();
}
