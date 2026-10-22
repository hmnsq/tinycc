// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#define uint8_t unsigned ವರ್ಣ
#define uint16_t unsigned short
#define uint32_t unsigned ಪೂರ್ಣಾಙ್ಕ
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
ಪ್ರಕಾರನಿರ್ದೇಶ __SIZE_TYPE__ size_t;

#define ATOMIC_GEN_OP(TYPE, MODE, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(ಚಞ್ಚಲ ಶೂನ್ಯ *atom, TYPE ಮೌಲ್ಯ, ಪೂರ್ಣಾಙ್ಕ memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        ಕುರು { \
            xchg = (OP); \
        } ಯಾವತ್ (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        ಪ್ರತ್ಯಾಗಮ RET; \
    }

#define ATOMIC_EXCHANGE(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, exchange, ಮೌಲ್ಯ, cmp)
#define ATOMIC_ADD_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, add_fetch, (cmp + ಮೌಲ್ಯ), xchg)
#define ATOMIC_SUB_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, sub_fetch, (cmp - ಮೌಲ್ಯ), xchg)
#define ATOMIC_AND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, and_fetch, (cmp & ಮೌಲ್ಯ), xchg)
#define ATOMIC_OR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, or_fetch, (cmp | ಮೌಲ್ಯ), xchg)
#define ATOMIC_XOR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, xor_fetch, (cmp ^ ಮೌಲ್ಯ), xchg)
#define ATOMIC_NAND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, nand_fetch, ~(cmp & ಮೌಲ್ಯ), xchg)
#define ATOMIC_FETCH_ADD(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_add, (cmp + ಮೌಲ್ಯ), cmp)
#define ATOMIC_FETCH_SUB(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_sub, (cmp - ಮೌಲ್ಯ), cmp)
#define ATOMIC_FETCH_AND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_and, (cmp & ಮೌಲ್ಯ), cmp)
#define ATOMIC_FETCH_OR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_or, (cmp | ಮೌಲ್ಯ), cmp)
#define ATOMIC_FETCH_XOR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_xor, (cmp ^ ಮೌಲ್ಯ), cmp)
#define ATOMIC_FETCH_NAND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_nand, ~(cmp & ಮೌಲ್ಯ), cmp)

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
#ಅನ್ಯಥಾ
#define ATOMIC(x)      __tcc_atomic_##x
#endif

bool ATOMIC(is_lock_free) (unsigned long size, ಧ್ರುವ ಚಞ್ಚಲ ಶೂನ್ಯ *ptr)
{
    bool ret;

    ವಿಕಲ್ಪ (size) {
    ಪಕ್ಷ 1: ret = true; ಭಙ್ಗ;
    ಪಕ್ಷ 2: ret = true; ಭಙ್ಗ;
    ಪಕ್ಷ 4: ret = true; ಭಙ್ಗ;
#ಯದಿ defined __x86_64__ || defined __aarch64__ || defined __riscv
    ಪಕ್ಷ 8: ret = true; ಭಙ್ಗ;
#ಅನ್ಯಥಾ
    ಪಕ್ಷ 8: ret = false; ಭಙ್ಗ;
#endif
    ಸ್ವಭಾವ: ret = false; ಭಙ್ಗ;
    }
    ಪ್ರತ್ಯಾಗಮ ret;
}

#ifndef __TINYC__
bool __atomic_is_lock_free(unsigned long size, ಧ್ರುವ ಚಞ್ಚಲ ಶೂನ್ಯ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#endif
