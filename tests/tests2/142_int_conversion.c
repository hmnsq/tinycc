#অন্তর্ভাব <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned বর্ণ get_uc(শূন্য) { প্রত্যাগম 0x80; }
signed বর্ণ get_sc(শূন্য) { প্রত্যাগম 0x80; }
unsigned short get_us(শূন্য) { প্রত্যাগম 0x8000; }
signed short get_ss(শূন্য) { প্রত্যাগম 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned বর্ণ (* চঞ্চল fp_uc)(শূন্য) = get_uc;
signed বর্ণ (* চঞ্চল fp_sc)(শূন্য) = get_sc;
unsigned short (* চঞ্চল fp_us)(শূন্য) = get_us;
signed short (* চঞ্চল fp_ss)(শূন্য) = get_ss;

পূর্ণাঙ্ক promote_main(শূন্য)
{
    পূর্ণাঙ্ক ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    যদি (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    যদি (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    যদি (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    যদি (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    প্রত্যাগম ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

পূর্ণাঙ্ক cast_main(শূন্য)
{
    পূর্ণাঙ্ক ok = 1;
    পূর্ণাঙ্ক x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    বর্ণ c = (বর্ণ)x + 1;
    unsigned বর্ণ uc = (unsigned বর্ণ)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned বর্ণ)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    যদি (c != (বর্ণ)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    যদি (uc != (unsigned বর্ণ)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    যদি (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    যদি (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    প্রত্যাগম ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

পূর্ণাঙ্ক sign_main(শূন্য)
{
    পূর্ণাঙ্ক ok = 1;
    পূর্ণাঙ্ক x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    যদি (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    যদি (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned পূর্ণাঙ্ক ux = 0x80000000;
    long long uy = (long long)(পূর্ণাঙ্ক)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    যদি (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    প্রত্যাগম ok ? 0 : 1;
}

পূর্ণাঙ্ক main()
{
    প্রত্যাগম
        promote_main()
        | cast_main()
        | sign_main();
}
