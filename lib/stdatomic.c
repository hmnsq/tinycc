// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#تعریف_کرو uint8_t غیرعلامتی حرف
#تعریف_کرو uint16_t غیرعلامتی مختصر
#تعریف_کرو uint32_t غیرعلامتی صحیح
#تعریف_کرو uint64_t غیرعلامتی طویل طویل
#تعریف_کرو bool _Bool
#تعریف_کرو false 0
#تعریف_کرو true 1
#تعریف_کرو __ATOMIC_RELAXED 0
#تعریف_کرو __ATOMIC_CONSUME 1
#تعریف_کرو __ATOMIC_ACQUIRE 2
#تعریف_کرو __ATOMIC_RELEASE 3
#تعریف_کرو __ATOMIC_ACQ_REL 4
#تعریف_کرو __ATOMIC_SEQ_CST 5
قسمتعریف __SIZE_TYPE__ سائز_t;

#تعریف_کرو ATOMIC_GEN_OP(TYPE, منوال_2, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(متلون خالی *atom, TYPE قدر, صحیح memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        کرو { \
            xchg = (OP); \
        } جب (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        واپس RET; \
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

#تعریف_کرو ATOMIC_GEN(TYPE, سائز_2) \
    ATOMIC_EXCHANGE(TYPE, سائز_2) \
    ATOMIC_جوڑو_FETCH(TYPE, سائز_2) \
    ATOMIC_SUB_FETCH(TYPE, سائز_2) \
    ATOMIC_AND_FETCH(TYPE, سائز_2) \
    ATOMIC_OR_FETCH(TYPE, سائز_2) \
    ATOMIC_XOR_FETCH(TYPE, سائز_2) \
    ATOMIC_NAND_FETCH(TYPE, سائز_2) \
    ATOMIC_FETCH_جوڑو(TYPE, سائز_2) \
    ATOMIC_FETCH_SUB(TYPE, سائز_2) \
    ATOMIC_FETCH_AND(TYPE, سائز_2) \
    ATOMIC_FETCH_OR(TYPE, سائز_2) \
    ATOMIC_FETCH_XOR(TYPE, سائز_2) \
    ATOMIC_FETCH_NAND(TYPE, سائز_2)

ATOMIC_GEN(uint8_t, 1)
ATOMIC_GEN(uint16_t, 2)
ATOMIC_GEN(uint32_t, 4)
ATOMIC_GEN(uint64_t, 8)

/* uses alias to allow building with gcc/clang */
#اگر_تعریف_شدہ __TINYC__
#تعریف_کرو ATOMIC(x)      __atomic_##x
#ورنہ
#تعریف_کرو ATOMIC(x)      __tcc_atomic_##x
#اگر_ختم

bool ATOMIC(is_تالا_free) (غیرعلامتی طویل سائز, ثابت متلون خالی *ptr)
{
    bool ret;

    انتخاب (سائز) {
    حالت 1: ret = true; توڑو;
    حالت 2: ret = true; توڑو;
    حالت 4: ret = true; توڑو;
#اگر defined __x86_64__ || defined __aarch64__ || defined __riscv
    حالت 8: ret = true; توڑو;
#ورنہ
    حالت 8: ret = false; توڑو;
#اگر_ختم
    طےشدہ: ret = false; توڑو;
    }
    واپس ret;
}

#اگر_غیر_تعریف_شدہ __TINYC__
bool __atomic_is_lock_free(غیرعلامتی طویل سائز, ثابت متلون خالی *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#اگر_ختم
