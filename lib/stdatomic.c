// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#परिभाषय uint8_t अचिह्नित वर्ण
#परिभाषय uint16_t अचिह्नित ह्रस्व
#परिभाषय uint32_t अचिह्नित पूर्णाङ्क
#परिभाषय uint64_t अचिह्नित दीर्घ दीर्घ
#परिभाषय bool _Bool
#परिभाषय false 0
#परिभाषय true 1
#परिभाषय __ATOMIC_RELAXED 0
#परिभाषय __ATOMIC_CONSUME 1
#परिभाषय __ATOMIC_ACQUIRE 2
#परिभाषय __ATOMIC_RELEASE 3
#परिभाषय __ATOMIC_ACQ_REL 4
#परिभाषय __ATOMIC_SEQ_CST 5
प्रकारनिर्देश __SIZE_TYPE__ आकार_t;

#परिभाषय ATOMIC_GEN_OP(TYPE, बहुलकम्_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(चञ्चल शून्य *atom, TYPE मानम्, पूर्णाङ्क memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        कुरु { \
            xchg = (OP); \
        } यावत् (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        प्रत्यागम RET; \
    }

#परिभाषय ATOMIC_EXCHANGE(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, exchange, मानम्, cmp)
#परिभाषय ATOMIC_सङ्कलय_FETCH(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, सङ्कलय_fetch, (cmp + मानम्), xchg)
#परिभाषय ATOMIC_SUB_FETCH(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, sub_fetch, (cmp - मानम्), xchg)
#परिभाषय ATOMIC_AND_FETCH(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, and_fetch, (cmp & मानम्), xchg)
#परिभाषय ATOMIC_OR_FETCH(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, or_fetch, (cmp | मानम्), xchg)
#परिभाषय ATOMIC_XOR_FETCH(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, xor_fetch, (cmp ^ मानम्), xchg)
#परिभाषय ATOMIC_NAND_FETCH(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, nand_fetch, ~(cmp & मानम्), xchg)
#परिभाषय ATOMIC_FETCH_सङ्कलय(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, fetch_सङ्कलय, (cmp + मानम्), cmp)
#परिभाषय ATOMIC_FETCH_SUB(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, fetch_sub, (cmp - मानम्), cmp)
#परिभाषय ATOMIC_FETCH_AND(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, fetch_and, (cmp & मानम्), cmp)
#परिभाषय ATOMIC_FETCH_OR(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, fetch_or, (cmp | मानम्), cmp)
#परिभाषय ATOMIC_FETCH_XOR(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, fetch_xor, (cmp ^ मानम्), cmp)
#परिभाषय ATOMIC_FETCH_NAND(TYPE, बहुलकम्_2) \
    ATOMIC_GEN_OP(TYPE, बहुलकम्_2, fetch_nand, ~(cmp & मानम्), cmp)

#परिभाषय ATOMIC_GEN(TYPE, आकार_2) \
    ATOMIC_EXCHANGE(TYPE, आकार_2) \
    ATOMIC_सङ्कलय_FETCH(TYPE, आकार_2) \
    ATOMIC_SUB_FETCH(TYPE, आकार_2) \
    ATOMIC_AND_FETCH(TYPE, आकार_2) \
    ATOMIC_OR_FETCH(TYPE, आकार_2) \
    ATOMIC_XOR_FETCH(TYPE, आकार_2) \
    ATOMIC_NAND_FETCH(TYPE, आकार_2) \
    ATOMIC_FETCH_सङ्कलय(TYPE, आकार_2) \
    ATOMIC_FETCH_SUB(TYPE, आकार_2) \
    ATOMIC_FETCH_AND(TYPE, आकार_2) \
    ATOMIC_FETCH_OR(TYPE, आकार_2) \
    ATOMIC_FETCH_XOR(TYPE, आकार_2) \
    ATOMIC_FETCH_NAND(TYPE, आकार_2)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#यदि_परिभाषितम् __TINYC__
#परिभाषय ATOMIC(x)      __atomic_##x
#अन्यथा
#परिभाषय ATOMIC(x)      __tcc_atomic_##x
#यदि_अन्तः

bool ATOMIC(is_तालकम्_free) (अचिह्नित दीर्घ आकार, ध्रुव चञ्चल शून्य *ptr)
{
    bool ret;

    विकल्प (आकार) {
    पक्ष 1: ret = true; भङ्ग;
    पक्ष 2: ret = true; भङ्ग;
    पक्ष 4: ret = true; भङ्ग;
#यदि defined __x86_64__ || defined __aarch64__ || defined __riscv
    पक्ष 8: ret = true; भङ्ग;
#अन्यथा
    पक्ष 8: ret = false; भङ्ग;
#यदि_अन्तः
    स्वभाव: ret = false; भङ्ग;
    }
    प्रत्यागम ret;
}

#यदि_अपरिभाषितम् __TINYC__
bool __atomic_is_lock_free(अचिह्नित दीर्घ आकार, ध्रुव चञ्चल शून्य *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#यदि_अन्तः
