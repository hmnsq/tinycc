#ଅନ୍ତର୍ଭାଵ <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned ଅକ୍ଷର get_uc(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 0x80; }
signed ଅକ୍ଷର get_sc(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 0x80; }
unsigned short get_us(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 0x8000; }
signed short get_ss(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned ଅକ୍ଷର (* ଅସ୍ଥିର fp_uc)(ଶୂନ୍ୟ) = get_uc;
signed ଅକ୍ଷର (* ଅସ୍ଥିର fp_sc)(ଶୂନ୍ୟ) = get_sc;
unsigned short (* ଅସ୍ଥିର fp_us)(ଶୂନ୍ୟ) = get_us;
signed short (* ଅସ୍ଥିର fp_ss)(ଶୂନ୍ୟ) = get_ss;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା promote_main(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    ଯଦି (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    ଯଦି (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    ଯଦି (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    ଯଦି (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ଫେରନ୍ତୁ ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

ପୂର୍ଣ୍ଣସଂଖ୍ୟା cast_main(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    ଅକ୍ଷର c = (ଅକ୍ଷର)x + 1;
    unsigned ଅକ୍ଷର uc = (unsigned ଅକ୍ଷର)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned ଅକ୍ଷର)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    ଯଦି (c != (ଅକ୍ଷର)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    ଯଦି (uc != (unsigned ଅକ୍ଷର)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    ଯଦି (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    ଯଦି (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ଫେରନ୍ତୁ ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

ପୂର୍ଣ୍ଣସଂଖ୍ୟା sign_main(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ok = 1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    ଯଦି (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    ଯଦି (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା ux = 0x80000000;
    long long uy = (long long)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    ଯଦି (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ଫେରନ୍ତୁ ok ? 0 : 1;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ଫେରନ୍ତୁ
        promote_main()
        | cast_main()
        | sign_main();
}
