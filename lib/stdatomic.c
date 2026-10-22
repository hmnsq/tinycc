// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#define uint8_t unsigned எழுத்து
#define uint16_t unsigned short
#define uint32_t unsigned முழு
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
வகைவரை __SIZE_TYPE__ size_t;

#define ATOMIC_GEN_OP(TYPE, MODE, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(நிலையற்ற வெறுமை *atom, TYPE மதிப்பு, முழு memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        செய் { \
            xchg = (OP); \
        } போது (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        திரும்பு RET; \
    }

#define ATOMIC_EXCHANGE(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, exchange, மதிப்பு, cmp)
#define ATOMIC_ADD_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, add_fetch, (cmp + மதிப்பு), xchg)
#define ATOMIC_SUB_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, sub_fetch, (cmp - மதிப்பு), xchg)
#define ATOMIC_AND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, and_fetch, (cmp & மதிப்பு), xchg)
#define ATOMIC_OR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, or_fetch, (cmp | மதிப்பு), xchg)
#define ATOMIC_XOR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, xor_fetch, (cmp ^ மதிப்பு), xchg)
#define ATOMIC_NAND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, nand_fetch, ~(cmp & மதிப்பு), xchg)
#define ATOMIC_FETCH_ADD(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_add, (cmp + மதிப்பு), cmp)
#define ATOMIC_FETCH_SUB(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_sub, (cmp - மதிப்பு), cmp)
#define ATOMIC_FETCH_AND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_and, (cmp & மதிப்பு), cmp)
#define ATOMIC_FETCH_OR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_or, (cmp | மதிப்பு), cmp)
#define ATOMIC_FETCH_XOR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_xor, (cmp ^ மதிப்பு), cmp)
#define ATOMIC_FETCH_NAND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_nand, ~(cmp & மதிப்பு), cmp)

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
#இல்லையெனில்
#define ATOMIC(x)      __tcc_atomic_##x
#endif

bool ATOMIC(is_lock_free) (unsigned long size, மாறிலி நிலையற்ற வெறுமை *ptr)
{
    bool ret;

    தேர்வு (size) {
    நிலை 1: ret = true; நிறுத்து;
    நிலை 2: ret = true; நிறுத்து;
    நிலை 4: ret = true; நிறுத்து;
#எனில் defined __x86_64__ || defined __aarch64__ || defined __riscv
    நிலை 8: ret = true; நிறுத்து;
#இல்லையெனில்
    நிலை 8: ret = false; நிறுத்து;
#endif
    இயல்பு: ret = false; நிறுத்து;
    }
    திரும்பு ret;
}

#ifndef __TINYC__
bool __atomic_is_lock_free(unsigned long size, மாறிலி நிலையற்ற வெறுமை *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#endif
