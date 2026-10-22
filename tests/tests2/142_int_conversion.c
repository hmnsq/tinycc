#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ get_uc(ਖਾਲੀ) { ਵਾਪਸ 0x80; }
ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ get_sc(ਖਾਲੀ) { ਵਾਪਸ 0x80; }
ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ get_us(ਖਾਲੀ) { ਵਾਪਸ 0x8000; }
ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ get_ss(ਖਾਲੀ) { ਵਾਪਸ 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ (* ਅਸਥਿਰ fp_uc)(ਖਾਲੀ) = get_uc;
ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ (* ਅਸਥਿਰ fp_sc)(ਖਾਲੀ) = get_sc;
ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ (* ਅਸਥਿਰ fp_us)(ਖਾਲੀ) = get_us;
ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ (* ਅਸਥਿਰ fp_ss)(ਖਾਲੀ) = get_ss;

ਪੂਰਨ promote_main(ਖਾਲੀ)
{
    ਪੂਰਨ ok = 1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ uc = fp_uc();
    ਨਿਸ਼ਾਨੀਵਾਲਾ ਲੰਮਾ ਲੰਮਾ sc = fp_sc();
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ us = fp_us();
    ਨਿਸ਼ਾਨੀਵਾਲਾ ਲੰਮਾ ਲੰਮਾ ss = fp_ss();

    ਲਿਖੋ("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)uc,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)sc,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)us,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)ss);

    ਜੇ (uc != 0x80) {
        ਲਿਖੋ("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    ਜੇ (sc != 0xffffffffffffff80LL) {
        ਲਿਖੋ("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    ਜੇ (us != 0x8000) {
        ਲਿਖੋ("FAIL: us not zero-extended\n");
        ok = 0;
    }
    ਜੇ (ss != 0xffffffffffff8000LL) {
        ਲਿਖੋ("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    ਲਿਖੋ("%s\n", ok ? "PASS" : "FAIL");
    ਵਾਪਸ ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

ਪੂਰਨ cast_main(ਖਾਲੀ)
{
    ਪੂਰਨ ok = 1;
    ਪੂਰਨ x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    ਅੱਖਰ c = (ਅੱਖਰ)x + 1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ uc = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)x + 1;
    ਛੋਟਾ s = (ਛੋਟਾ)x + 1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ us = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)x + 1;

    ਲਿਖੋ("c=%x uc=%x s=%x us=%x\n",
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)c, (ਬਿਨਾਨਿਸ਼ਾਨੀ)uc,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)s, (ਬਿਨਾਨਿਸ਼ਾਨੀ)us);

    ਜੇ (c != (ਅੱਖਰ)0x78 + 1) {
        ਲਿਖੋ("FAIL: char conversion\n");
        ok = 0;
    }
    ਜੇ (uc != (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)0x78 + 1) {
        ਲਿਖੋ("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    ਜੇ (s != (ਛੋਟਾ)0x5678 + 1) {
        ਲਿਖੋ("FAIL: short conversion\n");
        ok = 0;
    }
    ਜੇ (us != (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)0x5678 + 1) {
        ਲਿਖੋ("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    ਲਿਖੋ("%s\n", ok ? "PASS" : "FAIL");
    ਵਾਪਸ ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

ਪੂਰਨ sign_main(ਖਾਲੀ)
{
    ਪੂਰਨ ok = 1;
    ਪੂਰਨ x = 0x80000000;
    ਲੰਮਾ ਲੰਮਾ y = (ਲੰਮਾ ਲੰਮਾ)x;

    ਲਿਖੋ("y=%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)y);

    ਜੇ (y != 0xffffffff80000000LL) {
        ਲਿਖੋ("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (ਲੰਮਾ ਲੰਮਾ)x;
    ਲਿਖੋ("y=%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)y);

    ਜੇ (y != 0x40000000LL) {
        ਲਿਖੋ("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ux = 0x80000000;
    ਲੰਮਾ ਲੰਮਾ uy = (ਲੰਮਾ ਲੰਮਾ)(ਪੂਰਨ)ux;
    ਲਿਖੋ("uy=%llx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)uy);

    ਜੇ (uy != 0xffffffff80000000LL) {
        ਲਿਖੋ("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    ਲਿਖੋ("%s\n", ok ? "PASS" : "FAIL");
    ਵਾਪਸ ok ? 0 : 1;
}

ਪੂਰਨ ਮੁੱਖ()
{
    ਵਾਪਸ
        promote_main()
        | cast_main()
        | sign_main();
}
