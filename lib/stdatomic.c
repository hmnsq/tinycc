// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#define uint8_t unsigned ଅକ୍ଷର
#define uint16_t unsigned short
#define uint32_t unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା
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
ପ୍ରକାରବ୍ୟାଖ୍ୟା __SIZE_TYPE__ size_t;

#define ATOMIC_GEN_OP(TYPE, MODE, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(ଅସ୍ଥିର ଶୂନ୍ୟ *atom, TYPE ମୂଲ୍ୟ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        କର { \
            xchg = (OP); \
        } ଯେତେବେଳେ (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        ଫେରନ୍ତୁ RET; \
    }

#define ATOMIC_EXCHANGE(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, exchange, ମୂଲ୍ୟ, cmp)
#define ATOMIC_ADD_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, add_fetch, (cmp + ମୂଲ୍ୟ), xchg)
#define ATOMIC_SUB_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, sub_fetch, (cmp - ମୂଲ୍ୟ), xchg)
#define ATOMIC_AND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, and_fetch, (cmp & ମୂଲ୍ୟ), xchg)
#define ATOMIC_OR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, or_fetch, (cmp | ମୂଲ୍ୟ), xchg)
#define ATOMIC_XOR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, xor_fetch, (cmp ^ ମୂଲ୍ୟ), xchg)
#define ATOMIC_NAND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, nand_fetch, ~(cmp & ମୂଲ୍ୟ), xchg)
#define ATOMIC_FETCH_ADD(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_add, (cmp + ମୂଲ୍ୟ), cmp)
#define ATOMIC_FETCH_SUB(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_sub, (cmp - ମୂଲ୍ୟ), cmp)
#define ATOMIC_FETCH_AND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_and, (cmp & ମୂଲ୍ୟ), cmp)
#define ATOMIC_FETCH_OR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_or, (cmp | ମୂଲ୍ୟ), cmp)
#define ATOMIC_FETCH_XOR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_xor, (cmp ^ ମୂଲ୍ୟ), cmp)
#define ATOMIC_FETCH_NAND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_nand, ~(cmp & ମୂଲ୍ୟ), cmp)

#define ATOMIC_GEN(TYPE, SIZE) \
    ATOMIC_EXCHANGE(TYPE, SIZE) \
    ATOMIC_ADD_FETCH(TYPE, SIZE) \
    ATOMIC_SUB_FETCH(TYPE, SIZE) \
    ATOMIC_AND_FETCH(TYPE, SIZE) \
    ATOMIC_OR_FETCH(TYPE, SIZE) \
    ATOMIC_XOR_FETCH(TYPE, SIZE) \
    ATOMIC_NAND_FETCH(TYPE, SIZE) \
    ATOMIC_FETCH_ADD(TYPE, SIZE) \
    ATOMIC_FETCH_SUB(TYPE, SIZE) \
    ATOMIC_FETCH_AND(TYPE, SIZE) \
    ATOMIC_FETCH_OR(TYPE, SIZE) \
    ATOMIC_FETCH_XOR(TYPE, SIZE) \
    ATOMIC_FETCH_NAND(TYPE, SIZE)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#ifdef __TINYC__
#define ATOMIC(x)      __atomic_##x
#ଅନ୍ୟଥା
#define ATOMIC(x)      __tcc_atomic_##x
#endif

bool ATOMIC(is_lock_free) (unsigned long size, ଅଚଳ ଅସ୍ଥିର ଶୂନ୍ୟ *ptr)
{
    bool ret;

    ବାଛ (size) {
    ସ୍ଥିତି 1: ret = true; ଭାଙ୍ଗ;
    ସ୍ଥିତି 2: ret = true; ଭାଙ୍ଗ;
    ସ୍ଥିତି 4: ret = true; ଭାଙ୍ଗ;
#ଯଦି defined __x86_64__ || defined __aarch64__ || defined __riscv
    ସ୍ଥିତି 8: ret = true; ଭାଙ୍ଗ;
#ଅନ୍ୟଥା
    ସ୍ଥିତି 8: ret = false; ଭାଙ୍ଗ;
#endif
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ret = false; ଭାଙ୍ଗ;
    }
    ଫେରନ୍ତୁ ret;
}

#ifndef __TINYC__
bool __atomic_is_lock_free(unsigned long size, ଅଚଳ ଅସ୍ଥିର ଶୂନ୍ୟ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#endif
