/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#include <stdio.h>
#include <stdint.h>

/* ---- shift-by-immediate helpers ---- */

static uint32_t lsl32(uint32_t x, ကိန်းပြည့် n) { ပြန်ပေး x << n; }
static uint32_t lsr32(uint32_t x, ကိန်းပြည့် n) { ပြန်ပေး x >> n; }
static int32_t  asr32(int32_t  x, ကိန်းပြည့် n) { ပြန်ပေး x >> n; }
static uint64_t lsl64(uint64_t x, ကိန်းပြည့် n) { ပြန်ပေး x << n; }
static uint64_t lsr64(uint64_t x, ကိန်းပြည့် n) { ပြန်ပေး x >> n; }
static int64_t  asr64(int64_t  x, ကိန်းပြည့် n) { ပြန်ပေး x >> n; }

static void test_shifts(void)
{
    printf("shift-imm:\n");
    printf("%x\n", lsl32(1, 0));
    printf("%x\n", lsl32(1, 15));
    printf("%x\n", lsl32(1, 31));
    printf("%x\n", lsr32(0x80000000U, 31));
    printf("%x\n", lsr32(0x80000000U, 16));
    printf("%x\n", asr32(-1, 1));
    printf("%x\n", asr32(-256, 4));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 0));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 32));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 63));
    printf("%llx\n", (unsigned long long)lsr64(0x8000000000000000ULL, 63));
    printf("%llx\n", (unsigned long long)asr64(-1LL, 1));
    printf("%llx\n", (unsigned long long)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

static void test_ldr_str(void)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    printf("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    printf("%llx\n", (unsigned long long)val);
    val = buf[1];
    printf("%llx\n", (unsigned long long)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    printf("%x\n", (unsigned)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    printf("%llx\n", (unsigned long long)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    printf("%llx %llx\n", (unsigned long long)val,
           (unsigned long long)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

static void test_ldp_stp(void)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    printf("ldp-stp:\n");
    printf("%llx %llx\n",
           (unsigned long long)dst[0],
           (unsigned long long)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

static const var_na *cbz_test(ကိန်းပြည့် x)
{
    အကယ်၍ (x == 0)
        ပြန်ပေး "zero";
    ပြန်ပေး "nonzero";
}

static const var_na *cbnz_test(ကိန်းပြည့် x)
{
    အကယ်၍ (x != 0)
        ပြန်ပေး "nonzero";
    ပြန်ပေး "zero";
}

static void test_cond_branches(void)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

static ကိန်းပြည့် cond_select(ကိန်းပြည့် a, ကိန်းပြည့် b)
{
    /* TCC should generate csel or equivalent */
    ပြန်ပေး a > b ? a : b;
}

static void test_cond_select(void)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

static void test_sysregs(void)
{
    unsigned ကိန်းပြည့် fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ ca_ncala ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ ca_ncala ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ ca_ncala ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned ကိန်းပြည့် check;
        __asm__ ca_ncala ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

static void test_nop(void)
{
    printf("nop:\n");
    __asm__ ca_ncala ("nop");
    __asm__ ca_ncala ("nop");
    __asm__ ca_ncala ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

static void test_barriers(void)
{
    printf("barriers:\n");
    __asm__ ca_ncala ("dmb sy");
    __asm__ ca_ncala ("dsb sy");
    __asm__ ca_ncala ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

static int64_t mov_x0_x1(int64_t x)
{
    pa_njikaa int64_t r __asm__("x0") = x;
    __asm__ ca_ncala ("" : "=r"(r) : "0"(r));
    ပြန်ပေး r;
}

static void test_mov_reg(void)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

sa_nracanaa large { int64_t a, b, c, d; };

static int64_t sum_large(sa_nracanaa large s)
{
    ပြန်ပေး s.a + s.b + s.c + s.d;
}

static sa_nracanaa large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    sa_nracanaa large s = { a, b, c, d };
    ပြန်ပေး s;
}

static void test_large_structs(void)
{
    sa_nracanaa large s = { 1, 2, 3, 4 };
    sa_nracanaa large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

sa_nracanaa s18 { var_na x[18]; };
sa_nracanaa s24 { var_na x[24]; };
sa_nracanaa s32 { var_na x[32]; };

static void print_s18(sa_nracanaa s18 s) { printf("%.18s\n", s.x); }
static void print_s24(sa_nracanaa s24 s) { printf("%.24s\n", s.x); }
static void print_s32(sa_nracanaa s32 s) { printf("%.32s\n", s.x); }

static sa_nracanaa s18 ret_s18(void)
{
    sa_nracanaa s18 s = { "123456789012345678" };
    ပြန်ပေး s;
}

static sa_nracanaa s24 ret_s24(void)
{
    sa_nracanaa s24 s = { "123456789012345678901234" };
    ပြန်ပေး s;
}

static sa_nracanaa s32 ret_s32(void)
{
    sa_nracanaa s32 s = { "12345678901234567890123456789012" };
    ပြန်ပေး s;
}

static void test_boundary_structs(void)
{
    sa_nracanaa s18 a;
    sa_nracanaa s24 b;
    sa_nracanaa s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

ကိန်းပြည့် main(void)
{
    test_shifts();
    test_ldr_str();
    test_ldp_stp();
    test_cond_branches();
    test_cond_select();
    test_sysregs();
    test_nop();
    test_barriers();
    test_mov_reg();
    test_large_structs();
    test_boundary_structs();
    ပြန်ပေး 0;
}
