#include <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned char get_uc(void) { 返回 0x80; }
signed char get_sc(void) { 返回 0x80; }
unsigned short get_us(void) { 返回 0x8000; }
signed short get_ss(void) { 返回 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned char (* volatile fp_uc)(void) = get_uc;
signed char (* volatile fp_sc)(void) = get_sc;
unsigned short (* volatile fp_us)(void) = get_us;
signed short (* volatile fp_ss)(void) = get_ss;

整数 promote_main(void)
{
    整数 ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    如果 (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    如果 (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    如果 (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    如果 (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    返回 ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

整数 cast_main(void)
{
    整数 ok = 1;
    整数 x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    char c = (char)x + 1;
    unsigned char uc = (unsigned char)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned char)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    如果 (c != (char)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    如果 (uc != (unsigned char)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    如果 (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    如果 (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    返回 ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

整数 sign_main(void)
{
    整数 ok = 1;
    整数 x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    如果 (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    如果 (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned 整数 ux = 0x80000000;
    long long uy = (long long)(整数)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    如果 (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    返回 ok ? 0 : 1;
}

整数 主要()
{
    返回
        promote_main()
        | cast_main()
        | sign_main();
}
