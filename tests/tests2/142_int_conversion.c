#ಅನ್ತರ್ಭಾವ <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned ವರ್ಣ get_uc(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 0x80; }
signed ವರ್ಣ get_sc(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 0x80; }
unsigned short get_us(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 0x8000; }
signed short get_ss(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned ವರ್ಣ (* ಚಞ್ಚಲ fp_uc)(ಶೂನ್ಯ) = get_uc;
signed ವರ್ಣ (* ಚಞ್ಚಲ fp_sc)(ಶೂನ್ಯ) = get_sc;
unsigned short (* ಚಞ್ಚಲ fp_us)(ಶೂನ್ಯ) = get_us;
signed short (* ಚಞ್ಚಲ fp_ss)(ಶೂನ್ಯ) = get_ss;

ಪೂರ್ಣಾಙ್ಕ promote_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    ಯದಿ (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    ಯದಿ (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    ಯದಿ (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    ಯದಿ (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ಪ್ರತ್ಯಾಗಮ ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

ಪೂರ್ಣಾಙ್ಕ cast_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;
    ಪೂರ್ಣಾಙ್ಕ x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    ವರ್ಣ c = (ವರ್ಣ)x + 1;
    unsigned ವರ್ಣ uc = (unsigned ವರ್ಣ)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned ವರ್ಣ)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    ಯದಿ (c != (ವರ್ಣ)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    ಯದಿ (uc != (unsigned ವರ್ಣ)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    ಯದಿ (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    ಯದಿ (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ಪ್ರತ್ಯಾಗಮ ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

ಪೂರ್ಣಾಙ್ಕ sign_main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ok = 1;
    ಪೂರ್ಣಾಙ್ಕ x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    ಯದಿ (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    ಯದಿ (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned ಪೂರ್ಣಾಙ್ಕ ux = 0x80000000;
    long long uy = (long long)(ಪೂರ್ಣಾಙ್ಕ)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    ಯದಿ (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ಪ್ರತ್ಯಾಗಮ ok ? 0 : 1;
}

ಪೂರ್ಣಾಙ್ಕ main()
{
    ಪ್ರತ್ಯಾಗಮ
        promote_main()
        | cast_main()
        | sign_main();
}
