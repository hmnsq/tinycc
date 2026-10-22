// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ uint8_t ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ uint16_t ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ uint32_t ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ uint64_t ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ bool _Bool
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ false 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ true 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_RELAXED 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_CONSUME 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_ACQUIRE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_RELEASE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_ACQ_REL 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_SEQ_CST 5
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ ਮਾਪ_t;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(ਅਸਥਿਰ ਖਾਲੀ *atom, TYPE ਮੁੱਲ, ਪੂਰਨ memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        ਕਰੋ { \
            xchg = (OP); \
        } ਜਦੋਂ (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        ਵਾਪਸ RET; \
    }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_EXCHANGE(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, exchange, ਮੁੱਲ, cmp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_ਜੋੜੋ_FETCH(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, ਜੋੜੋ_fetch, (cmp + ਮੁੱਲ), xchg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_SUB_FETCH(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, sub_fetch, (cmp - ਮੁੱਲ), xchg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_AND_FETCH(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, and_fetch, (cmp & ਮੁੱਲ), xchg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_OR_FETCH(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, or_fetch, (cmp | ਮੁੱਲ), xchg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_XOR_FETCH(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, xor_fetch, (cmp ^ ਮੁੱਲ), xchg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_NAND_FETCH(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, nand_fetch, ~(cmp & ਮੁੱਲ), xchg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_FETCH_ਜੋੜੋ(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, fetch_ਜੋੜੋ, (cmp + ਮੁੱਲ), cmp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_FETCH_SUB(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, fetch_sub, (cmp - ਮੁੱਲ), cmp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_FETCH_AND(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, fetch_and, (cmp & ਮੁੱਲ), cmp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_FETCH_OR(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, fetch_or, (cmp | ਮੁੱਲ), cmp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_FETCH_XOR(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, fetch_xor, (cmp ^ ਮੁੱਲ), cmp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_FETCH_NAND(TYPE, ਬਹੁਲਕ_2) \
    ATOMIC_GEN_OP(TYPE, ਬਹੁਲਕ_2, fetch_nand, ~(cmp & ਮੁੱਲ), cmp)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_GEN(TYPE, ਮਾਪ_2) \
    ATOMIC_EXCHANGE(TYPE, ਮਾਪ_2) \
    ATOMIC_ਜੋੜੋ_FETCH(TYPE, ਮਾਪ_2) \
    ATOMIC_SUB_FETCH(TYPE, ਮਾਪ_2) \
    ATOMIC_AND_FETCH(TYPE, ਮਾਪ_2) \
    ATOMIC_OR_FETCH(TYPE, ਮਾਪ_2) \
    ATOMIC_XOR_FETCH(TYPE, ਮਾਪ_2) \
    ATOMIC_NAND_FETCH(TYPE, ਮਾਪ_2) \
    ATOMIC_FETCH_ਜੋੜੋ(TYPE, ਮਾਪ_2) \
    ATOMIC_FETCH_SUB(TYPE, ਮਾਪ_2) \
    ATOMIC_FETCH_AND(TYPE, ਮਾਪ_2) \
    ATOMIC_FETCH_OR(TYPE, ਮਾਪ_2) \
    ATOMIC_FETCH_XOR(TYPE, ਮਾਪ_2) \
    ATOMIC_FETCH_NAND(TYPE, ਮਾਪ_2)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC(x)      __atomic_##x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC(x)      __tcc_atomic_##x
#ਜੇ_ਅੰਤ

bool ATOMIC(is_ਤਾਲਾ_free) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅਸਥਿਰ ਖਾਲੀ *ptr)
{
    bool ret;

    ਚੋਣ (ਮਾਪ) {
    ਹਾਲਤ 1: ret = true; ਰੋਕੋ;
    ਹਾਲਤ 2: ret = true; ਰੋਕੋ;
    ਹਾਲਤ 4: ret = true; ਰੋਕੋ;
#ਜੇ defined __x86_64__ || defined __aarch64__ || defined __riscv
    ਹਾਲਤ 8: ret = true; ਰੋਕੋ;
#ਨਹੀਂਤਾਂ
    ਹਾਲਤ 8: ret = false; ਰੋਕੋ;
#ਜੇ_ਅੰਤ
    ਮੂਲ: ret = false; ਰੋਕੋ;
    }
    ਵਾਪਸ ret;
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TINYC__
bool __atomic_is_lock_free(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅਸਥਿਰ ਖਾਲੀ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#ਜੇ_ਅੰਤ
