#ಅನ್ತರ್ಭಾವ <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ get_uc(ಶೂನ್ಯ) { ಹಿಂತಿರುಗಿ 0x80; }
ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ get_sc(ಶೂನ್ಯ) { ಹಿಂತಿರುಗಿ 0x80; }
ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ get_us(ಶೂನ್ಯ) { ಹಿಂತಿರುಗಿ 0x8000; }
ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ get_ss(ಶೂನ್ಯ) { ಹಿಂತಿರುಗಿ 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ (* ಅಸ್ಥಿರ fp_uc)(ಶೂನ್ಯ) = get_uc;
ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ (* ಅಸ್ಥಿರ fp_sc)(ಶೂನ್ಯ) = get_sc;
ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ (* ಅಸ್ಥಿರ fp_us)(ಶೂನ್ಯ) = get_us;
ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ (* ಅಸ್ಥಿರ fp_ss)(ಶೂನ್ಯ) = get_ss;

ಪೂರ್ಣಾಂಕ promote_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ok = 1;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ uc = fp_uc();
    ಚಿಹ್ನೆಯುಳ್ಳ ದೀರ್ಘ ದೀರ್ಘ sc = fp_sc();
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ us = fp_us();
    ಚಿಹ್ನೆಯುಳ್ಳ ದೀರ್ಘ ದೀರ್ಘ ss = fp_ss();

    ಬರೆ("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)uc,
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)sc,
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)us,
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)ss);

    ಆದರೆ (uc != 0x80) {
        ಬರೆ("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    ಆದರೆ (sc != 0xffffffffffffff80LL) {
        ಬರೆ("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    ಆದರೆ (us != 0x8000) {
        ಬರೆ("FAIL: us not zero-extended\n");
        ok = 0;
    }
    ಆದರೆ (ss != 0xffffffffffff8000LL) {
        ಬರೆ("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    ಬರೆ("%s\n", ok ? "PASS" : "FAIL");
    ಹಿಂತಿರುಗಿ ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

ಪೂರ್ಣಾಂಕ cast_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ok = 1;
    ಪೂರ್ಣಾಂಕ x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    ಅಕ್ಷರ c = (ಅಕ್ಷರ)x + 1;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ uc = (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)x + 1;
    ಗಿಡ್ಡ s = (ಗಿಡ್ಡ)x + 1;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ us = (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)x + 1;

    ಬರೆ("c=%x uc=%x s=%x us=%x\n",
           (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)c, (ಚಿಹ್ನೆರಹಿತ)uc,
           (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)s, (ಚಿಹ್ನೆರಹಿತ)us);

    ಆದರೆ (c != (ಅಕ್ಷರ)0x78 + 1) {
        ಬರೆ("FAIL: char conversion\n");
        ok = 0;
    }
    ಆದರೆ (uc != (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)0x78 + 1) {
        ಬರೆ("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    ಆದರೆ (s != (ಗಿಡ್ಡ)0x5678 + 1) {
        ಬರೆ("FAIL: short conversion\n");
        ok = 0;
    }
    ಆದರೆ (us != (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)0x5678 + 1) {
        ಬರೆ("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    ಬರೆ("%s\n", ok ? "PASS" : "FAIL");
    ಹಿಂತಿರುಗಿ ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

ಪೂರ್ಣಾಂಕ sign_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ok = 1;
    ಪೂರ್ಣಾಂಕ x = 0x80000000;
    ದೀರ್ಘ ದೀರ್ಘ y = (ದೀರ್ಘ ದೀರ್ಘ)x;

    ಬರೆ("y=%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)y);

    ಆದರೆ (y != 0xffffffff80000000LL) {
        ಬರೆ("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (ದೀರ್ಘ ದೀರ್ಘ)x;
    ಬರೆ("y=%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)y);

    ಆದರೆ (y != 0x40000000LL) {
        ಬರೆ("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ux = 0x80000000;
    ದೀರ್ಘ ದೀರ್ಘ uy = (ದೀರ್ಘ ದೀರ್ಘ)(ಪೂರ್ಣಾಂಕ)ux;
    ಬರೆ("uy=%llx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)uy);

    ಆದರೆ (uy != 0xffffffff80000000LL) {
        ಬರೆ("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    ಬರೆ("%s\n", ok ? "PASS" : "FAIL");
    ಹಿಂತಿರುಗಿ ok ? 0 : 1;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಹಿಂತಿರುಗಿ
        promote_main()
        | cast_main()
        | sign_main();
}
