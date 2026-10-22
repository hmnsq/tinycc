// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#تعریف_کړه uint8_t بینښه حرف
#تعریف_کړه uint16_t بینښه لنډ
#تعریف_کړه uint32_t بینښه صحيح
#تعریف_کړه uint64_t بینښه اوږد اوږد
#تعریف_کړه bool _Bool
#تعریف_کړه false 0
#تعریف_کړه true 1
#تعریف_کړه __ATOMIC_RELAXED 0
#تعریف_کړه __ATOMIC_CONSUME 1
#تعریف_کړه __ATOMIC_ACQUIRE 2
#تعریف_کړه __ATOMIC_RELEASE 3
#تعریف_کړه __ATOMIC_ACQ_REL 4
#تعریف_کړه __ATOMIC_SEQ_CST 5
تعريفنوع __SIZE_TYPE__ اندازه_t;

#تعریف_کړه ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(متطاير فراغ *atom, TYPE ارزښت, صحيح memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        افعل { \
            xchg = (OP); \
        } طالما (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        أرجع RET; \
    }

#تعریف_کړه ATOMIC_EXCHANGE(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, exchange, ارزښت, cmp)
#تعریف_کړه ATOMIC_جمع_کړه_FETCH(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, جمع_کړه_fetch, (cmp + ارزښت), xchg)
#تعریف_کړه ATOMIC_SUB_FETCH(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, sub_fetch, (cmp - ارزښت), xchg)
#تعریف_کړه ATOMIC_AND_FETCH(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, and_fetch, (cmp & ارزښت), xchg)
#تعریف_کړه ATOMIC_OR_FETCH(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, or_fetch, (cmp | ارزښت), xchg)
#تعریف_کړه ATOMIC_XOR_FETCH(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, xor_fetch, (cmp ^ ارزښت), xchg)
#تعریف_کړه ATOMIC_NAND_FETCH(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, nand_fetch, ~(cmp & ارزښت), xchg)
#تعریف_کړه ATOMIC_FETCH_جمع_کړه(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, fetch_جمع_کړه, (cmp + ارزښت), cmp)
#تعریف_کړه ATOMIC_FETCH_SUB(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, fetch_sub, (cmp - ارزښت), cmp)
#تعریف_کړه ATOMIC_FETCH_AND(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, fetch_and, (cmp & ارزښت), cmp)
#تعریف_کړه ATOMIC_FETCH_OR(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, fetch_or, (cmp | ارزښت), cmp)
#تعریف_کړه ATOMIC_FETCH_XOR(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, fetch_xor, (cmp ^ ارزښت), cmp)
#تعریف_کړه ATOMIC_FETCH_NAND(TYPE, ډېرپېښ_2) \
    ATOMIC_GEN_OP(TYPE, ډېرپېښ_2, fetch_nand, ~(cmp & ارزښت), cmp)

#تعریف_کړه ATOMIC_GEN(TYPE, اندازه_2) \
    ATOMIC_EXCHANGE(TYPE, اندازه_2) \
    ATOMIC_جمع_کړه_FETCH(TYPE, اندازه_2) \
    ATOMIC_SUB_FETCH(TYPE, اندازه_2) \
    ATOMIC_AND_FETCH(TYPE, اندازه_2) \
    ATOMIC_OR_FETCH(TYPE, اندازه_2) \
    ATOMIC_XOR_FETCH(TYPE, اندازه_2) \
    ATOMIC_NAND_FETCH(TYPE, اندازه_2) \
    ATOMIC_FETCH_جمع_کړه(TYPE, اندازه_2) \
    ATOMIC_FETCH_SUB(TYPE, اندازه_2) \
    ATOMIC_FETCH_AND(TYPE, اندازه_2) \
    ATOMIC_FETCH_OR(TYPE, اندازه_2) \
    ATOMIC_FETCH_XOR(TYPE, اندازه_2) \
    ATOMIC_FETCH_NAND(TYPE, اندازه_2)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#که_تعریف_شوی __TINYC__
#تعریف_کړه ATOMIC(x)      __atomic_##x
#وإلا
#تعریف_کړه ATOMIC(x)      __tcc_atomic_##x
#د_که_پای

bool ATOMIC(is_قلف_free) (بینښه اوږد اندازه, ثابت متطاير فراغ *ptr)
{
    bool ret;

    بدل (اندازه) {
    حالة 1: ret = true; اكسر;
    حالة 2: ret = true; اكسر;
    حالة 4: ret = true; اكسر;
#إذا defined __x86_64__ || defined __aarch64__ || defined __riscv
    حالة 8: ret = true; اكسر;
#وإلا
    حالة 8: ret = false; اكسر;
#د_که_پای
    افتراضي: ret = false; اكسر;
    }
    أرجع ret;
}

#که_نه_تعریف_شوی __TINYC__
bool __atomic_is_lock_free(بینښه اوږد اندازه, ثابت متطاير فراغ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#د_که_پای
