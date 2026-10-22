// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#నిర్వచించు uint8_t గుర్తులేని అక్షరం
#నిర్వచించు uint16_t గుర్తులేని పొట్టి
#నిర్వచించు uint32_t గుర్తులేని పూర్ణాంకం
#నిర్వచించు uint64_t గుర్తులేని దీర్ఘ దీర్ఘ
#నిర్వచించు bool _Bool
#నిర్వచించు false 0
#నిర్వచించు true 1
#నిర్వచించు __ATOMIC_RELAXED 0
#నిర్వచించు __ATOMIC_CONSUME 1
#నిర్వచించు __ATOMIC_ACQUIRE 2
#నిర్వచించు __ATOMIC_RELEASE 3
#నిర్వచించు __ATOMIC_ACQ_REL 4
#నిర్వచించు __ATOMIC_SEQ_CST 5
రకనిర్వచనం __SIZE_TYPE__ కొలత_t;

#నిర్వచించు ATOMIC_GEN_OP(TYPE, బహుళకం_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(అస్థిర శూన్య *atom, TYPE విలువ, పూర్ణాంకం memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        చేయి { \
            xchg = (OP); \
        } అయితే (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        తిరిగి RET; \
    }

#నిర్వచించు ATOMIC_EXCHANGE(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, exchange, విలువ, cmp)
#నిర్వచించు ATOMIC_కూడు_FETCH(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, కూడు_fetch, (cmp + విలువ), xchg)
#నిర్వచించు ATOMIC_SUB_FETCH(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, sub_fetch, (cmp - విలువ), xchg)
#నిర్వచించు ATOMIC_AND_FETCH(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, and_fetch, (cmp & విలువ), xchg)
#నిర్వచించు ATOMIC_OR_FETCH(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, or_fetch, (cmp | విలువ), xchg)
#నిర్వచించు ATOMIC_XOR_FETCH(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, xor_fetch, (cmp ^ విలువ), xchg)
#నిర్వచించు ATOMIC_NAND_FETCH(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, nand_fetch, ~(cmp & విలువ), xchg)
#నిర్వచించు ATOMIC_FETCH_కూడు(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, fetch_కూడు, (cmp + విలువ), cmp)
#నిర్వచించు ATOMIC_FETCH_SUB(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, fetch_sub, (cmp - విలువ), cmp)
#నిర్వచించు ATOMIC_FETCH_AND(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, fetch_and, (cmp & విలువ), cmp)
#నిర్వచించు ATOMIC_FETCH_OR(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, fetch_or, (cmp | విలువ), cmp)
#నిర్వచించు ATOMIC_FETCH_XOR(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, fetch_xor, (cmp ^ విలువ), cmp)
#నిర్వచించు ATOMIC_FETCH_NAND(TYPE, బహుళకం_2) \
    ATOMIC_GEN_OP(TYPE, బహుళకం_2, fetch_nand, ~(cmp & విలువ), cmp)

#నిర్వచించు ATOMIC_GEN(TYPE, కొలత_2) \
    ATOMIC_EXCHANGE(TYPE, కొలత_2) \
    ATOMIC_కూడు_FETCH(TYPE, కొలత_2) \
    ATOMIC_SUB_FETCH(TYPE, కొలత_2) \
    ATOMIC_AND_FETCH(TYPE, కొలత_2) \
    ATOMIC_OR_FETCH(TYPE, కొలత_2) \
    ATOMIC_XOR_FETCH(TYPE, కొలత_2) \
    ATOMIC_NAND_FETCH(TYPE, కొలత_2) \
    ATOMIC_FETCH_కూడు(TYPE, కొలత_2) \
    ATOMIC_FETCH_SUB(TYPE, కొలత_2) \
    ATOMIC_FETCH_AND(TYPE, కొలత_2) \
    ATOMIC_FETCH_OR(TYPE, కొలత_2) \
    ATOMIC_FETCH_XOR(TYPE, కొలత_2) \
    ATOMIC_FETCH_NAND(TYPE, కొలత_2)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#నిర్వచితమైతే __TINYC__
#నిర్వచించు ATOMIC(x)      __atomic_##x
#లేకపోతే
#నిర్వచించు ATOMIC(x)      __tcc_atomic_##x
#అయితే_ముగింపు

bool ATOMIC(is_తాళం_free) (గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అస్థిర శూన్య *ptr)
{
    bool ret;

    ఎంపిక (కొలత) {
    స్థితి 1: ret = true; ఆపు;
    స్థితి 2: ret = true; ఆపు;
    స్థితి 4: ret = true; ఆపు;
#ఒకవేళ defined __x86_64__ || defined __aarch64__ || defined __riscv
    స్థితి 8: ret = true; ఆపు;
#లేకపోతే
    స్థితి 8: ret = false; ఆపు;
#అయితే_ముగింపు
    అప్రమేయ: ret = false; ఆపు;
    }
    తిరిగి ret;
}

#నిర్వచితం_కాకపోతే __TINYC__
bool __atomic_is_lock_free(గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అస్థిర శూన్య *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#అయితే_ముగింపు
