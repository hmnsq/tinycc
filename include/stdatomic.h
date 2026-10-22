/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#अगर_अघोषित _STDATOMIC_H
#घोषणा _STDATOMIC_H

#समावेश <stddef.h>
#समावेश <stdint.h>
#समावेश <stdbool.h>

#घोषणा __ATOMIC_RELAXED 0
#घोषणा __ATOMIC_CONSUME 1
#घोषणा __ATOMIC_ACQUIRE 2
#घोषणा __ATOMIC_RELEASE 3
#घोषणा __ATOMIC_ACQ_REL 4
#घोषणा __ATOMIC_SEQ_CST 5

/* Memory ordering */
प्रकार क्रमागत {
    memory_order_relaxed = __ATOMIC_RELAXED,
    memory_order_consume = __ATOMIC_CONSUME,
    memory_order_acquire = __ATOMIC_ACQUIRE,
    memory_order_release = __ATOMIC_RELEASE,
    memory_order_acq_rel = __ATOMIC_ACQ_REL,
    memory_order_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
प्रकार _Atomic(_Bool) atomic_bool;
प्रकार _Atomic(अक्षर) atomic_char;
प्रकार _Atomic(चिन्हित अक्षर) atomic_schar;
प्रकार _Atomic(अचिन्हित अक्षर) atomic_uchar;
प्रकार _Atomic(लघु) atomic_short;
प्रकार _Atomic(अचिन्हित लघु) atomic_ushort;
प्रकार _Atomic(पूर्णांक) atomic_int;
प्रकार _Atomic(अचिन्हित पूर्णांक) atomic_uint;
प्रकार _Atomic(दीर्घ) atomic_long;
प्रकार _Atomic(अचिन्हित दीर्घ) atomic_ulong;
प्रकार _Atomic(दीर्घ दीर्घ) atomic_llong;
प्रकार _Atomic(अचिन्हित दीर्घ दीर्घ) atomic_ullong;
प्रकार _Atomic(uint_least16_t) atomic_char16_t;
प्रकार _Atomic(uint_least32_t) atomic_char32_t;
प्रकार _Atomic(ब_अक्षर_प्रकार) atomic_wchar_t;
प्रकार _Atomic(int_least8_t) atomic_int_least8_t;
प्रकार _Atomic(uint_least8_t) atomic_uint_least8_t;
प्रकार _Atomic(int_least16_t) atomic_int_least16_t;
प्रकार _Atomic(uint_least16_t) atomic_uint_least16_t;
प्रकार _Atomic(int_least32_t) atomic_int_least32_t;
प्रकार _Atomic(uint_least32_t) atomic_uint_least32_t;
प्रकार _Atomic(int_least64_t) atomic_int_least64_t;
प्रकार _Atomic(uint_least64_t) atomic_uint_least64_t;
प्रकार _Atomic(int_fast8_t) atomic_int_fast8_t;
प्रकार _Atomic(uint_fast8_t) atomic_uint_fast8_t;
प्रकार _Atomic(int_fast16_t) atomic_int_fast16_t;
प्रकार _Atomic(uint_fast16_t) atomic_uint_fast16_t;
प्रकार _Atomic(int_fast32_t) atomic_int_fast32_t;
प्रकार _Atomic(uint_fast32_t) atomic_uint_fast32_t;
प्रकार _Atomic(int_fast64_t) atomic_int_fast64_t;
प्रकार _Atomic(uint_fast64_t) atomic_uint_fast64_t;
प्रकार _Atomic(intptr_t) atomic_intptr_t;
प्रकार _Atomic(uintptr_t) atomic_uintptr_t;
प्रकार _Atomic(माप_प्रकार) atomic_size_t;
प्रकार _Atomic(सूचक_भेद_प्रकार) atomic_ptrdiff_t;
प्रकार _Atomic(intmax_t) atomic_intmax_t;
प्रकार _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
प्रकार काष्ठा {
    atomic_bool मूल्य;
} atomic_flag;

#घोषणा ATOMIC_FLAG_INIT {0}
#घोषणा ATOMIC_VAR_INIT(मूल्य) (मूल्य)

/* Generic routines */
#घोषणा atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#घोषणा __atomic_store_n(ptr, val, order)                                 \
    ({ __typeof__ ((व्योम)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (order)); })
#घोषणा atomic_store_explicit(object, desired, order)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (order));                               \
    })
#घोषणा atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#घोषणा __atomic_load_n(ptr, order)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (order));                             \
       __val; })
#घोषणा atomic_load_explicit(object, order)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((व्योम)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (order));                                \
       tmp;                                                               \
    })
#घोषणा atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#घोषणा atomic_exchange_explicit(object, desired, order)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (order));                      \
       tmp;                                                               \
    })
#घोषणा atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#घोषणा __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#घोषणा atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#घोषणा atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#घोषणा atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#घोषणा atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#घोषणा atomic_fetch_add(object, operand) \
    __atomic_fetch_add(object, operand, __ATOMIC_SEQ_CST)
#घोषणा atomic_fetch_add_explicit __atomic_fetch_add

#घोषणा atomic_fetch_sub(object, operand) \
    __atomic_fetch_sub(object, operand, __ATOMIC_SEQ_CST)
#घोषणा atomic_fetch_sub_explicit __atomic_fetch_sub

#घोषणा atomic_fetch_or(object, operand) \
    __atomic_fetch_or(object, operand, __ATOMIC_SEQ_CST)
#घोषणा atomic_fetch_or_explicit __atomic_fetch_or

#घोषणा atomic_fetch_xor(object, operand) \
    __atomic_fetch_xor(object, operand, __ATOMIC_SEQ_CST)
#घोषणा atomic_fetch_xor_explicit __atomic_fetch_xor

#घोषणा atomic_fetch_and(object, operand) \
    __atomic_fetch_and(object, operand, __ATOMIC_SEQ_CST)
#घोषणा atomic_fetch_and_explicit __atomic_fetch_and

बाह्य व्योम atomic_thread_fence (memory_order);
#घोषणा __atomic_thread_fence(order) atomic_thread_fence (order)
बाह्य व्योम atomic_signal_fence (memory_order);
#घोषणा __atomic_signal_fence(order) atomic_signal_fence(order)
बाह्य bool __atomic_is_lock_free(माप_प्रकार आकार, व्योम *ptr);
#घोषणा atomic_is_lock_free(OBJ) __atomic_is_lock_free (माप (*(OBJ)), (OBJ))

बाह्य bool atomic_flag_test_and_set(व्योम *object);
बाह्य bool atomic_flag_test_and_set_explicit(व्योम *object, memory_order order);
बाह्य व्योम atomic_flag_clear(व्योम *object);
बाह्य व्योम atomic_flag_clear_explicit(व्योम *object, memory_order order);
#पूर्ण_अगर /* _STDATOMIC_H */
