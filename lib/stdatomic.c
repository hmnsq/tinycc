// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#وصف_ڪريو uint8_t بنانشان حرف
#وصف_ڪريو uint16_t بنانشان ننڍو
#وصف_ڪريو uint32_t بنانشان صحيح
#وصف_ڪريو uint64_t بنانشان ڊگهو ڊگهو
#وصف_ڪريو bool _Bool
#وصف_ڪريو false 0
#وصف_ڪريو true 1
#وصف_ڪريو __ATOMIC_RELAXED 0
#وصف_ڪريو __ATOMIC_CONSUME 1
#وصف_ڪريو __ATOMIC_ACQUIRE 2
#وصف_ڪريو __ATOMIC_RELEASE 3
#وصف_ڪريو __ATOMIC_ACQ_REL 4
#وصف_ڪريو __ATOMIC_SEQ_CST 5
تعريفنوع __SIZE_TYPE__ سائيز_t;

#وصف_ڪريو ATOMIC_GEN_OP(TYPE, گهڻائي_2, NAME, OP, RET) \
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

#وصف_ڪريو ATOMIC_EXCHANGE(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, exchange, قدر, cmp)
#وصف_ڪريو ATOMIC_جوڙيو_FETCH(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, جوڙيو_fetch, (cmp + قدر), xchg)
#وصف_ڪريو ATOMIC_SUB_FETCH(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, sub_fetch, (cmp - قدر), xchg)
#وصف_ڪريو ATOMIC_AND_FETCH(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, and_fetch, (cmp & قدر), xchg)
#وصف_ڪريو ATOMIC_OR_FETCH(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, or_fetch, (cmp | قدر), xchg)
#وصف_ڪريو ATOMIC_XOR_FETCH(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, xor_fetch, (cmp ^ قدر), xchg)
#وصف_ڪريو ATOMIC_NAND_FETCH(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, nand_fetch, ~(cmp & قدر), xchg)
#وصف_ڪريو ATOMIC_FETCH_جوڙيو(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, fetch_جوڙيو, (cmp + قدر), cmp)
#وصف_ڪريو ATOMIC_FETCH_SUB(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, fetch_sub, (cmp - قدر), cmp)
#وصف_ڪريو ATOMIC_FETCH_AND(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, fetch_and, (cmp & قدر), cmp)
#وصف_ڪريو ATOMIC_FETCH_OR(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, fetch_or, (cmp | قدر), cmp)
#وصف_ڪريو ATOMIC_FETCH_XOR(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, fetch_xor, (cmp ^ قدر), cmp)
#وصف_ڪريو ATOMIC_FETCH_NAND(TYPE, گهڻائي_2) \
    ATOMIC_GEN_OP(TYPE, گهڻائي_2, fetch_nand, ~(cmp & قدر), cmp)

#وصف_ڪريو ATOMIC_GEN(TYPE, سائيز_2) \
    ATOMIC_EXCHANGE(TYPE, سائيز_2) \
    ATOMIC_جوڙيو_FETCH(TYPE, سائيز_2) \
    ATOMIC_SUB_FETCH(TYPE, سائيز_2) \
    ATOMIC_AND_FETCH(TYPE, سائيز_2) \
    ATOMIC_OR_FETCH(TYPE, سائيز_2) \
    ATOMIC_XOR_FETCH(TYPE, سائيز_2) \
    ATOMIC_NAND_FETCH(TYPE, سائيز_2) \
    ATOMIC_FETCH_جوڙيو(TYPE, سائيز_2) \
    ATOMIC_FETCH_SUB(TYPE, سائيز_2) \
    ATOMIC_FETCH_AND(TYPE, سائيز_2) \
    ATOMIC_FETCH_OR(TYPE, سائيز_2) \
    ATOMIC_FETCH_XOR(TYPE, سائيز_2) \
    ATOMIC_FETCH_NAND(TYPE, سائيز_2)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#جيڪڏهن_وصف_ٿيل __TINYC__
#وصف_ڪريو ATOMIC(x)      __atomic_##x
#وإلا
#وصف_ڪريو ATOMIC(x)      __tcc_atomic_##x
#جيڪڏهن_پورو

bool ATOMIC(is_تالو_free) (بنانشان ڊگهو سائيز, ثابت متطاير فراغ *ptr)
{
    bool ret;

    بدل (سائيز) {
    حالة 1: ret = true; اكسر;
    حالة 2: ret = true; اكسر;
    حالة 4: ret = true; اكسر;
#إذا defined __x86_64__ || defined __aarch64__ || defined __riscv
    حالة 8: ret = true; اكسر;
#وإلا
    حالة 8: ret = false; اكسر;
#جيڪڏهن_پورو
    افتراضي: ret = false; اكسر;
    }
    أرجع ret;
}

#جيڪڏهن_وصف_نه_ٿيل __TINYC__
bool __atomic_is_lock_free(بنانشان ڊگهو سائيز, ثابت متطاير فراغ *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#جيڪڏهن_پورو
