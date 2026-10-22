// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#ವ್ಯಾಖ್ಯಾನಿಸು uint8_t ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ
#ವ್ಯಾಖ್ಯಾನಿಸು uint16_t ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ
#ವ್ಯಾಖ್ಯಾನಿಸು uint32_t ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ
#ವ್ಯಾಖ್ಯಾನಿಸು uint64_t ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ
#ವ್ಯಾಖ್ಯಾನಿಸು bool _Bool
#ವ್ಯಾಖ್ಯಾನಿಸು false 0
#ವ್ಯಾಖ್ಯಾನಿಸು true 1
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_RELAXED 0
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_CONSUME 1
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_ACQUIRE 2
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_RELEASE 3
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_ACQ_REL 4
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_SEQ_CST 5
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __SIZE_TYPE__ ಗಾತ್ರ_t;

#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(ಅಸ್ಥಿರ ಶೂನ್ಯ *atom, TYPE ಮೌಲ್ಯ, ಪೂರ್ಣಾಂಕ memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        ಮಾಡು { \
            xchg = (OP); \
        } ಆಗ (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        ಹಿಂತಿರುಗಿ RET; \
    }

#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_EXCHANGE(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, exchange, ಮೌಲ್ಯ, cmp)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_ಕೂಡಿಸು_FETCH(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, ಕೂಡಿಸು_fetch, (cmp + ಮೌಲ್ಯ), xchg)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_SUB_FETCH(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, sub_fetch, (cmp - ಮೌಲ್ಯ), xchg)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_AND_FETCH(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, and_fetch, (cmp & ಮೌಲ್ಯ), xchg)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_OR_FETCH(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, or_fetch, (cmp | ಮೌಲ್ಯ), xchg)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_XOR_FETCH(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, xor_fetch, (cmp ^ ಮೌಲ್ಯ), xchg)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_NAND_FETCH(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, nand_fetch, ~(cmp & ಮೌಲ್ಯ), xchg)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_FETCH_ಕೂಡಿಸು(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, fetch_ಕೂಡಿಸು, (cmp + ಮೌಲ್ಯ), cmp)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_FETCH_SUB(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, fetch_sub, (cmp - ಮೌಲ್ಯ), cmp)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_FETCH_AND(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, fetch_and, (cmp & ಮೌಲ್ಯ), cmp)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_FETCH_OR(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, fetch_or, (cmp | ಮೌಲ್ಯ), cmp)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_FETCH_XOR(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, fetch_xor, (cmp ^ ಮೌಲ್ಯ), cmp)
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_FETCH_NAND(TYPE, ಬಹುಲಕ_2) \
    ATOMIC_GEN_OP(TYPE, ಬಹುಲಕ_2, fetch_nand, ~(cmp & ಮೌಲ್ಯ), cmp)

#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_GEN(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_EXCHANGE(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_ಕೂಡಿಸು_FETCH(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_SUB_FETCH(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_AND_FETCH(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_OR_FETCH(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_XOR_FETCH(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_NAND_FETCH(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_FETCH_ಕೂಡಿಸು(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_FETCH_SUB(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_FETCH_AND(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_FETCH_OR(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_FETCH_XOR(TYPE, ಗಾತ್ರ_3) \
    ATOMIC_FETCH_NAND(TYPE, ಗಾತ್ರ_3)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC(x)      __atomic_##x
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC(x)      __tcc_atomic_##x
#ಆದರೆ_ಅಂತ್ಯ

bool ATOMIC(is_ಬೀಗ_free) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಸ್ಥಿರ ಶೂನ್ಯ *ptr)
{
    bool ret;

    ಆಯ್ಕೆ (ಗಾತ್ರ_2) {
    ಸ್ಥಿತಿ 1: ret = true; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 2: ret = true; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 4: ret = true; ನಿಲ್ಲಿಸು;
#ಆದರೆ defined __x86_64__ || defined __aarch64__ || defined __riscv
    ಸ್ಥಿತಿ 8: ret = true; ನಿಲ್ಲಿಸು;
#ಇಲ್ಲದಿದ್ದರೆ
    ಸ್ಥಿತಿ 8: ret = false; ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
    ಪೂರ್ವನಿಯೋಜಿತ: ret = false; ನಿಲ್ಲಿಸು;
    }
    ಹಿಂತಿರುಗಿ ret;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TINYC__
bool __atomic_is_lock_free(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಸ್ಥಿರ ಶೂನ್ಯ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#ಆದರೆ_ಅಂತ್ಯ
