// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#define uint8_t unsigned অক্ষর
#define uint16_t unsigned short
#define uint32_t unsigned পূর্ণসংখ্যা
#define uint64_t unsigned long long
#define bool _Bool
#define false 0
#define true 1
#define __ATOMIC_RELAXED 0
#define __ATOMIC_CONSUME 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_SEQ_CST 5
প্রকারলেখ __SIZE_TYPE__ আকার_t;

#define ATOMIC_GEN_OP(TYPE, MODE, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(অস্থির শূন্য *atom, TYPE মান, পূর্ণসংখ্যা memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        করো { \
            xchg = (OP); \
        } যখন (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        ফেরত RET; \
    }

#define ATOMIC_EXCHANGE(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, exchange, মান, cmp)
#define ATOMIC_ADD_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, add_fetch, (cmp + মান), xchg)
#define ATOMIC_SUB_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, sub_fetch, (cmp - মান), xchg)
#define ATOMIC_AND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, and_fetch, (cmp & মান), xchg)
#define ATOMIC_OR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, or_fetch, (cmp | মান), xchg)
#define ATOMIC_XOR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, xor_fetch, (cmp ^ মান), xchg)
#define ATOMIC_NAND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, nand_fetch, ~(cmp & মান), xchg)
#define ATOMIC_FETCH_ADD(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_add, (cmp + মান), cmp)
#define ATOMIC_FETCH_SUB(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_sub, (cmp - মান), cmp)
#define ATOMIC_FETCH_AND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_and, (cmp & মান), cmp)
#define ATOMIC_FETCH_OR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_or, (cmp | মান), cmp)
#define ATOMIC_FETCH_XOR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_xor, (cmp ^ মান), cmp)
#define ATOMIC_FETCH_NAND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_nand, ~(cmp & মান), cmp)

#define ATOMIC_GEN(TYPE, আকার_3) \
    ATOMIC_EXCHANGE(TYPE, আকার_3) \
    ATOMIC_ADD_FETCH(TYPE, আকার_3) \
    ATOMIC_SUB_FETCH(TYPE, আকার_3) \
    ATOMIC_AND_FETCH(TYPE, আকার_3) \
    ATOMIC_OR_FETCH(TYPE, আকার_3) \
    ATOMIC_XOR_FETCH(TYPE, আকার_3) \
    ATOMIC_NAND_FETCH(TYPE, আকার_3) \
    ATOMIC_FETCH_ADD(TYPE, আকার_3) \
    ATOMIC_FETCH_SUB(TYPE, আকার_3) \
    ATOMIC_FETCH_AND(TYPE, আকার_3) \
    ATOMIC_FETCH_OR(TYPE, আকার_3) \
    ATOMIC_FETCH_XOR(TYPE, আকার_3) \
    ATOMIC_FETCH_NAND(TYPE, আকার_3)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#ifdef __TINYC__
#define ATOMIC(x)      __atomic_##x
#অন্যথা
#define ATOMIC(x)      __tcc_atomic_##x
#endif

bool ATOMIC(is_lock_free) (unsigned long আকার_2, ধ্রুবক অস্থির শূন্য *ptr)
{
    bool ret;

    নির্বাচন (আকার_2) {
    ক্ষেত্র 1: ret = true; বিরতি;
    ক্ষেত্র 2: ret = true; বিরতি;
    ক্ষেত্র 4: ret = true; বিরতি;
#যদি defined __x86_64__ || defined __aarch64__ || defined __riscv
    ক্ষেত্র 8: ret = true; বিরতি;
#অন্যথা
    ক্ষেত্র 8: ret = false; বিরতি;
#endif
    পূর্বনির্ধারিত: ret = false; বিরতি;
    }
    ফেরত ret;
}

#ifndef __TINYC__
bool __atomic_is_lock_free(unsigned long আকার_2, ধ্রুবক অস্থির শূন্য *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#endif
