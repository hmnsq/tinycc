// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#تعریف_کرو uint8_t بنانشانی حرف
#تعریف_کرو uint16_t بنانشانی چھوٹا
#تعریف_کرو uint32_t بنانشانی صحيح
#تعریف_کرو uint64_t بنانشانی لما لما
#تعریف_کرو bool _Bool
#تعریف_کرو false 0
#تعریف_کرو true 1
#تعریف_کرو __ATOMIC_RELAXED 0
#تعریف_کرو __ATOMIC_CONSUME 1
#تعریف_کرو __ATOMIC_ACQUIRE 2
#تعریف_کرو __ATOMIC_RELEASE 3
#تعریف_کرو __ATOMIC_ACQ_REL 4
#تعریف_کرو __ATOMIC_SEQ_CST 5
تعريفنوع __SIZE_TYPE__ ناپ_t;

#تعریف_کرو ATOMIC_GEN_OP(TYPE, منوال_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(متطاير فراغ *atom, TYPE قدر, صحيح memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        افعل { \
            xchg = (OP); \
        } طالما (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        أرجع RET; \
    }

#تعریف_کرو ATOMIC_EXCHANGE(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, exchange, قدر, cmp)
#تعریف_کرو ATOMIC_جوڑو_FETCH(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, جوڑو_fetch, (cmp + قدر), xchg)
#تعریف_کرو ATOMIC_SUB_FETCH(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, sub_fetch, (cmp - قدر), xchg)
#تعریف_کرو ATOMIC_AND_FETCH(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, and_fetch, (cmp & قدر), xchg)
#تعریف_کرو ATOMIC_OR_FETCH(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, or_fetch, (cmp | قدر), xchg)
#تعریف_کرو ATOMIC_XOR_FETCH(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, xor_fetch, (cmp ^ قدر), xchg)
#تعریف_کرو ATOMIC_NAND_FETCH(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, nand_fetch, ~(cmp & قدر), xchg)
#تعریف_کرو ATOMIC_FETCH_جوڑو(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, fetch_جوڑو, (cmp + قدر), cmp)
#تعریف_کرو ATOMIC_FETCH_SUB(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, fetch_sub, (cmp - قدر), cmp)
#تعریف_کرو ATOMIC_FETCH_AND(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, fetch_and, (cmp & قدر), cmp)
#تعریف_کرو ATOMIC_FETCH_OR(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, fetch_or, (cmp | قدر), cmp)
#تعریف_کرو ATOMIC_FETCH_XOR(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, fetch_xor, (cmp ^ قدر), cmp)
#تعریف_کرو ATOMIC_FETCH_NAND(TYPE, منوال_2) \
    ATOMIC_GEN_OP(TYPE, منوال_2, fetch_nand, ~(cmp & قدر), cmp)

#تعریف_کرو ATOMIC_GEN(TYPE, ناپ_2) \
    ATOMIC_EXCHANGE(TYPE, ناپ_2) \
    ATOMIC_جوڑو_FETCH(TYPE, ناپ_2) \
    ATOMIC_SUB_FETCH(TYPE, ناپ_2) \
    ATOMIC_AND_FETCH(TYPE, ناپ_2) \
    ATOMIC_OR_FETCH(TYPE, ناپ_2) \
    ATOMIC_XOR_FETCH(TYPE, ناپ_2) \
    ATOMIC_NAND_FETCH(TYPE, ناپ_2) \
    ATOMIC_FETCH_جوڑو(TYPE, ناپ_2) \
    ATOMIC_FETCH_SUB(TYPE, ناپ_2) \
    ATOMIC_FETCH_AND(TYPE, ناپ_2) \
    ATOMIC_FETCH_OR(TYPE, ناپ_2) \
    ATOMIC_FETCH_XOR(TYPE, ناپ_2) \
    ATOMIC_FETCH_NAND(TYPE, ناپ_2)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#جے_تعریف_شدہ __TINYC__
#تعریف_کرو ATOMIC(x)      __atomic_##x
#وإلا
#تعریف_کرو ATOMIC(x)      __tcc_atomic_##x
#جے_انت

bool ATOMIC(is_جندرا_free) (بنانشانی لما ناپ, ثابت متطاير فراغ *ptr)
{
    bool ret;

    بدل (ناپ) {
    حالة 1: ret = true; اكسر;
    حالة 2: ret = true; اكسر;
    حالة 4: ret = true; اكسر;
#إذا defined __x86_64__ || defined __aarch64__ || defined __riscv
    حالة 8: ret = true; اكسر;
#وإلا
    حالة 8: ret = false; اكسر;
#جے_انت
    افتراضي: ret = false; اكسر;
    }
    أرجع ret;
}

#جے_بنا_تعریف __TINYC__
bool __atomic_is_lock_free(بنانشانی لما ناپ, ثابت متطاير فراغ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#جے_انت
