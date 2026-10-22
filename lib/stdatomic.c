// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#define uint8_t अचिन्हित वर्ण
#define uint16_t अचिन्हित लघु
#define uint32_t अचिन्हित पूर्णाङ्क
#define uint64_t अचिन्हित दीर्घ दीर्घ
#define bool _Bool
#define false 0
#define true 1
#define __ATOMIC_RELAXED 0
#define __ATOMIC_CONSUME 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_SEQ_CST 5
प्रकारनिर्देश __SIZE_TYPE__ माप_प्रकार;

#define ATOMIC_GEN_OP(TYPE, MODE, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(चञ्चल शून्य *atom, TYPE मान, पूर्णाङ्क memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        गर { \
            xchg = (OP); \
        } जबसम्म (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        फर्काऊ RET; \
    }

#define ATOMIC_EXCHANGE(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, exchange, मान, cmp)
#define ATOMIC_ADD_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, add_fetch, (cmp + मान), xchg)
#define ATOMIC_SUB_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, sub_fetch, (cmp - मान), xchg)
#define ATOMIC_AND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, and_fetch, (cmp & मान), xchg)
#define ATOMIC_OR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, or_fetch, (cmp | मान), xchg)
#define ATOMIC_XOR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, xor_fetch, (cmp ^ मान), xchg)
#define ATOMIC_NAND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, nand_fetch, ~(cmp & मान), xchg)
#define ATOMIC_FETCH_ADD(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_add, (cmp + मान), cmp)
#define ATOMIC_FETCH_SUB(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_sub, (cmp - मान), cmp)
#define ATOMIC_FETCH_AND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_and, (cmp & मान), cmp)
#define ATOMIC_FETCH_OR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_or, (cmp | मान), cmp)
#define ATOMIC_FETCH_XOR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_xor, (cmp ^ मान), cmp)
#define ATOMIC_FETCH_NAND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_nand, ~(cmp & मान), cmp)

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
#अन्यथा
#define ATOMIC(x)      __tcc_atomic_##x
#endif

bool ATOMIC(is_lock_free) (अचिन्हित दीर्घ size, अचर चञ्चल शून्य *ptr)
{
    bool ret;

    विकल्प (size) {
    पक्ष 1: ret = true; रोक;
    पक्ष 2: ret = true; रोक;
    पक्ष 4: ret = true; रोक;
#यदि defined __x86_64__ || defined __aarch64__ || defined __riscv
    पक्ष 8: ret = true; रोक;
#अन्यथा
    पक्ष 8: ret = false; रोक;
#endif
    स्वभाव: ret = false; रोक;
    }
    फर्काऊ ret;
}

#ifndef __TINYC__
bool __atomic_is_lock_free(अचिन्हित दीर्घ size, अचर चञ्चल शून्य *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#endif
