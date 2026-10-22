// for libtcc1, avoid including files that are not part of tcc
// #include <stdint.h>
#घोषणा uint8_t अचिन्हित अक्षर
#घोषणा uint16_t अचिन्हित लघु
#घोषणा uint32_t अचिन्हित पूर्णांक
#घोषणा uint64_t अचिन्हित दीर्घ दीर्घ
#घोषणा bool _Bool
#घोषणा false 0
#घोषणा true 1
#घोषणा __ATOMIC_RELAXED 0
#घोषणा __ATOMIC_CONSUME 1
#घोषणा __ATOMIC_ACQUIRE 2
#घोषणा __ATOMIC_RELEASE 3
#घोषणा __ATOMIC_ACQ_REL 4
#घोषणा __ATOMIC_SEQ_CST 5
प्रकार __SIZE_TYPE__ माप_प्रकार;

#घोषणा ATOMIC_GEN_OP(TYPE, MODE, NAME, OP, RET) \
    TYPE __atomic_##NAME##_##MODE(अस्थिर व्योम *atom, TYPE मूल्य, पूर्णांक memorder) \
    { \
        TYPE xchg, cmp; \
        __atomic_load((TYPE *)atom, (TYPE *)&cmp, __ATOMIC_RELAXED); \
        करो { \
            xchg = (OP); \
        } जबतक (!__atomic_compare_exchange((TYPE *)atom, &cmp, &xchg, true, \
                                            __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)); \
        वापस RET; \
    }

#घोषणा ATOMIC_EXCHANGE(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, exchange, मूल्य, cmp)
#घोषणा ATOMIC_ADD_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, add_fetch, (cmp + मूल्य), xchg)
#घोषणा ATOMIC_SUB_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, sub_fetch, (cmp - मूल्य), xchg)
#घोषणा ATOMIC_AND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, and_fetch, (cmp & मूल्य), xchg)
#घोषणा ATOMIC_OR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, or_fetch, (cmp | मूल्य), xchg)
#घोषणा ATOMIC_XOR_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, xor_fetch, (cmp ^ मूल्य), xchg)
#घोषणा ATOMIC_NAND_FETCH(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, nand_fetch, ~(cmp & मूल्य), xchg)
#घोषणा ATOMIC_FETCH_ADD(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_add, (cmp + मूल्य), cmp)
#घोषणा ATOMIC_FETCH_SUB(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_sub, (cmp - मूल्य), cmp)
#घोषणा ATOMIC_FETCH_AND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_and, (cmp & मूल्य), cmp)
#घोषणा ATOMIC_FETCH_OR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_or, (cmp | मूल्य), cmp)
#घोषणा ATOMIC_FETCH_XOR(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_xor, (cmp ^ मूल्य), cmp)
#घोषणा ATOMIC_FETCH_NAND(TYPE, MODE) \
    ATOMIC_GEN_OP(TYPE, MODE, fetch_nand, ~(cmp & मूल्य), cmp)

#घोषणा ATOMIC_GEN(TYPE, आकार_2) \
    ATOMIC_EXCHANGE(TYPE, आकार_2) \
    ATOMIC_ADD_FETCH(TYPE, आकार_2) \
    ATOMIC_SUB_FETCH(TYPE, आकार_2) \
    ATOMIC_AND_FETCH(TYPE, आकार_2) \
    ATOMIC_OR_FETCH(TYPE, आकार_2) \
    ATOMIC_XOR_FETCH(TYPE, आकार_2) \
    ATOMIC_NAND_FETCH(TYPE, आकार_2) \
    ATOMIC_FETCH_ADD(TYPE, आकार_2) \
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
#अगर_घोषित __TINYC__
#घोषणा ATOMIC(x)      __atomic_##x
#अन्यथा
#घोषणा ATOMIC(x)      __tcc_atomic_##x
#पूर्ण_अगर

bool ATOMIC(is_lock_free) (अचिन्हित दीर्घ आकार, स्थिर अस्थिर व्योम *ptr)
{
    bool ret;

    चयन (आकार) {
    हाल 1: ret = true; अवरोध;
    हाल 2: ret = true; अवरोध;
    हाल 4: ret = true; अवरोध;
#अगर defined __x86_64__ || defined __aarch64__ || defined __riscv
    हाल 8: ret = true; अवरोध;
#अन्यथा
    हाल 8: ret = false; अवरोध;
#पूर्ण_अगर
    शेष: ret = false; अवरोध;
    }
    वापस ret;
}

#अगर_अघोषित __TINYC__
bool __atomic_is_lock_free(अचिन्हित दीर्घ आकार, स्थिर अस्थिर व्योम *ptr) __attribute__((alias("__tcc_atomic_is_lock_free")));
#पूर्ण_अगर
