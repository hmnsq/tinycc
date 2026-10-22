#شامل <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned نویسه get_uc(تهی) { بازگشت 0x80; }
signed نویسه get_sc(تهی) { بازگشت 0x80; }
unsigned short get_us(تهی) { بازگشت 0x8000; }
signed short get_ss(تهی) { بازگشت 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned نویسه (* فرار fp_uc)(تهی) = get_uc;
signed نویسه (* فرار fp_sc)(تهی) = get_sc;
unsigned short (* فرار fp_us)(تهی) = get_us;
signed short (* فرار fp_ss)(تهی) = get_ss;

صحیح promote_main(تهی)
{
    صحیح ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    اگر (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    اگر (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    اگر (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    اگر (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    بازگشت ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

صحیح cast_main(تهی)
{
    صحیح ok = 1;
    صحیح x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    نویسه c = (نویسه)x + 1;
    unsigned نویسه uc = (unsigned نویسه)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned نویسه)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    اگر (c != (نویسه)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    اگر (uc != (unsigned نویسه)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    اگر (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    اگر (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    بازگشت ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

صحیح sign_main(تهی)
{
    صحیح ok = 1;
    صحیح x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    اگر (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    اگر (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned صحیح ux = 0x80000000;
    long long uy = (long long)(صحیح)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    اگر (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    بازگشت ok ? 0 : 1;
}

صحیح اصلی()
{
    بازگشت
        promote_main()
        | cast_main()
        | sign_main();
}
