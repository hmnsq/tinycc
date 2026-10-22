// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#تعریف_کن uint8_t بیعلامت حرف
#تعریف_کن uint16_t بیعلامت کوتاه
#تعریف_کن uint32_t بیعلامت صحيح
#تعریف_کن uint64_t بیعلامت دراز دراز
#تعریف_کن bool _Bool
#تعریف_کن false 0
#تعریف_کن true 1
#تعریف_کن __ATOMIC_RELAXED 0
#تعریف_کن __ATOMIC_CONSUME 1
#تعریف_کن __ATOMIC_ACQUIRE 2
#تعریف_کن __ATOMIC_RELEASE 3
#تعریف_کن __ATOMIC_ACQ_REL 4
#تعریف_کن __ATOMIC_SEQ_CST 5
تعريفنوع __SIZE_TYPE__ اندازه_t;

#تعریف_کن ATOMIC_GEN_OP(TYPE, نما_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(متطاير فراغ *atom, TYPE مقدار, صحيح memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        افعل { \
            xchg = (OP); \
        } طالما (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        أرجع RET; \
    }

#تعریف_کن ATOMIC_EXCHANGE(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, exchange, مقدار, cmp)
#تعریف_کن ATOMIC_جمع_کن_FETCH(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, جمع_کن_fetch, (cmp + مقدار), xchg)
#تعریف_کن ATOMIC_SUB_FETCH(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, sub_fetch, (cmp - مقدار), xchg)
#تعریف_کن ATOMIC_AND_FETCH(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, and_fetch, (cmp & مقدار), xchg)
#تعریف_کن ATOMIC_OR_FETCH(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, or_fetch, (cmp | مقدار), xchg)
#تعریف_کن ATOMIC_XOR_FETCH(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, xor_fetch, (cmp ^ مقدار), xchg)
#تعریف_کن ATOMIC_NAND_FETCH(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, nand_fetch, ~(cmp & مقدار), xchg)
#تعریف_کن ATOMIC_FETCH_جمع_کن(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, fetch_جمع_کن, (cmp + مقدار), cmp)
#تعریف_کن ATOMIC_FETCH_SUB(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, fetch_sub, (cmp - مقدار), cmp)
#تعریف_کن ATOMIC_FETCH_AND(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, fetch_and, (cmp & مقدار), cmp)
#تعریف_کن ATOMIC_FETCH_OR(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, fetch_or, (cmp | مقدار), cmp)
#تعریف_کن ATOMIC_FETCH_XOR(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, fetch_xor, (cmp ^ مقدار), cmp)
#تعریف_کن ATOMIC_FETCH_NAND(TYPE, نما_2) \
    ATOMIC_GEN_OP(TYPE, نما_2, fetch_nand, ~(cmp & مقدار), cmp)

#تعریف_کن ATOMIC_GEN(TYPE, اندازه_2) \
    ATOMIC_EXCHANGE(TYPE, اندازه_2) \
    ATOMIC_جمع_کن_FETCH(TYPE, اندازه_2) \
    ATOMIC_SUB_FETCH(TYPE, اندازه_2) \
    ATOMIC_AND_FETCH(TYPE, اندازه_2) \
    ATOMIC_OR_FETCH(TYPE, اندازه_2) \
    ATOMIC_XOR_FETCH(TYPE, اندازه_2) \
    ATOMIC_NAND_FETCH(TYPE, اندازه_2) \
    ATOMIC_FETCH_جمع_کن(TYPE, اندازه_2) \
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
#اگر_تعریف_شده __TINYC__
#تعریف_کن ATOMIC(x)      __atomic_##x
#وإلا
#تعریف_کن ATOMIC(x)      __tcc_atomic_##x
#پایان_اگر

bool ATOMIC(is_قفل_free) (بیعلامت دراز اندازه, ثابت متطاير فراغ *ptr)
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
#پایان_اگر
    افتراضي: ret = false; اكسر;
    }
    أرجع ret;
}

#اگر_تعریف_نشده __TINYC__
bool __atomic_is_lock_free(بیعلامت دراز اندازه, ثابت متطاير فراغ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#پایان_اگر
