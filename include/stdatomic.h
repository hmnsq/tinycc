/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#నిర్వచితం_కాకపోతే _STDATOMIC_H
#నిర్వచించు _STDATOMIC_H

#అన్తర్భావ <stddef.h>
#అన్తర్భావ <stdint.h>
#అన్తర్భావ <stdbool.h>

#నిర్వచించు __ATOMIC_RELAXED 0
#నిర్వచించు __ATOMIC_CONSUME 1
#నిర్వచించు __ATOMIC_ACQUIRE 2
#నిర్వచించు __ATOMIC_RELEASE 3
#నిర్వచించు __ATOMIC_ACQ_REL 4
#నిర్వచించు __ATOMIC_SEQ_CST 5

/* Memory ordering */
రకనిర్వచనం గణన {
    memory_order_relaxed = __ATOMIC_RELAXED,
    జ్ఞాపకం_క్రమం_consume = __ATOMIC_CONSUME,
    జ్ఞాపకం_క్రమం_acquire = __ATOMIC_ACQUIRE,
    జ్ఞాపకం_క్రమం_release = __ATOMIC_RELEASE,
    జ్ఞాపకం_క్రమం_acq_rel = __ATOMIC_ACQ_REL,
    జ్ఞాపకం_క్రమం_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
రకనిర్వచనం _Atomic(_Bool) atomic_bool;
రకనిర్వచనం _Atomic(అక్షరం) atomic_char;
రకనిర్వచనం _Atomic(గుర్తుగల అక్షరం) atomic_schar;
రకనిర్వచనం _Atomic(గుర్తులేని అక్షరం) atomic_uchar;
రకనిర్వచనం _Atomic(పొట్టి) atomic_short;
రకనిర్వచనం _Atomic(గుర్తులేని పొట్టి) atomic_ushort;
రకనిర్వచనం _Atomic(పూర్ణాంకం) atomic_int;
రకనిర్వచనం _Atomic(గుర్తులేని పూర్ణాంకం) atomic_uint;
రకనిర్వచనం _Atomic(దీర్ఘ) atomic_long;
రకనిర్వచనం _Atomic(గుర్తులేని దీర్ఘ) atomic_ulong;
రకనిర్వచనం _Atomic(దీర్ఘ దీర్ఘ) atomic_llong;
రకనిర్వచనం _Atomic(గుర్తులేని దీర్ఘ దీర్ఘ) atomic_ullong;
రకనిర్వచనం _Atomic(uint_least16_t) atomic_char16_t;
రకనిర్వచనం _Atomic(uint_least32_t) atomic_char32_t;
రకనిర్వచనం _Atomic(wchar_t) atomic_wchar_t;
రకనిర్వచనం _Atomic(int_least8_t) atomic_int_least8_t;
రకనిర్వచనం _Atomic(uint_least8_t) atomic_uint_least8_t;
రకనిర్వచనం _Atomic(int_least16_t) atomic_int_least16_t;
రకనిర్వచనం _Atomic(uint_least16_t) atomic_uint_least16_t;
రకనిర్వచనం _Atomic(int_least32_t) atomic_int_least32_t;
రకనిర్వచనం _Atomic(uint_least32_t) atomic_uint_least32_t;
రకనిర్వచనం _Atomic(int_least64_t) atomic_int_least64_t;
రకనిర్వచనం _Atomic(uint_least64_t) atomic_uint_least64_t;
రకనిర్వచనం _Atomic(int_fast8_t) atomic_int_fast8_t;
రకనిర్వచనం _Atomic(uint_fast8_t) atomic_uint_fast8_t;
రకనిర్వచనం _Atomic(int_fast16_t) atomic_int_fast16_t;
రకనిర్వచనం _Atomic(uint_fast16_t) atomic_uint_fast16_t;
రకనిర్వచనం _Atomic(int_fast32_t) atomic_int_fast32_t;
రకనిర్వచనం _Atomic(uint_fast32_t) atomic_uint_fast32_t;
రకనిర్వచనం _Atomic(int_fast64_t) atomic_int_fast64_t;
రకనిర్వచనం _Atomic(uint_fast64_t) atomic_uint_fast64_t;
రకనిర్వచనం _Atomic(intptr_t) atomic_intptr_t;
రకనిర్వచనం _Atomic(uintptr_t) atomic_uintptr_t;
రకనిర్వచనం _Atomic(కొలత_t) atomic_size_t;
రకనిర్వచనం _Atomic(ptrdiff_t) atomic_ptrdiff_t;
రకనిర్వచనం _Atomic(intmax_t) atomic_intmax_t;
రకనిర్వచనం _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
రకనిర్వచనం నిర్మాణం {
    atomic_bool విలువ;
} atomic_flag;

#నిర్వచించు ATOMIC_FLAG_INIT {0}
#నిర్వచించు ATOMIC_VAR_INIT(విలువ) (విలువ)

/* Generic routines */
#నిర్వచించు atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#నిర్వచించు __atomic_store_n(ptr, val, క్రమం)                                 \
    ({ __typeof__ ((శూన్య)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (క్రమం)); })
#నిర్వచించు atomic_store_explicit(object, desired, క్రమం)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (క్రమం));                               \
    })
#నిర్వచించు atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#నిర్వచించు __atomic_load_n(ptr, క్రమం)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (క్రమం));                             \
       __val; })
#నిర్వచించు atomic_load_explicit(object, క్రమం)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((శూన్య)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (క్రమం));                                \
       tmp;                                                               \
    })
#నిర్వచించు atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#నిర్వచించు atomic_exchange_explicit(object, desired, క్రమం)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (క్రమం));                      \
       tmp;                                                               \
    })
#నిర్వచించు atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#నిర్వచించు __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#నిర్వచించు atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#నిర్వచించు atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#నిర్వచించు atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#నిర్వచించు atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#నిర్వచించు atomic_fetch_add(object, నిర్వాహ్యం_2) \
    __atomic_fetch_add(object, నిర్వాహ్యం_2, __ATOMIC_SEQ_CST)
#నిర్వచించు atomic_fetch_add_explicit __atomic_fetch_add

#నిర్వచించు atomic_fetch_sub(object, నిర్వాహ్యం_2) \
    __atomic_fetch_sub(object, నిర్వాహ్యం_2, __ATOMIC_SEQ_CST)
#నిర్వచించు atomic_fetch_sub_explicit __atomic_fetch_sub

#నిర్వచించు atomic_fetch_or(object, నిర్వాహ్యం_2) \
    __atomic_fetch_or(object, నిర్వాహ్యం_2, __ATOMIC_SEQ_CST)
#నిర్వచించు atomic_fetch_or_explicit __atomic_fetch_or

#నిర్వచించు atomic_fetch_xor(object, నిర్వాహ్యం_2) \
    __atomic_fetch_xor(object, నిర్వాహ్యం_2, __ATOMIC_SEQ_CST)
#నిర్వచించు atomic_fetch_xor_explicit __atomic_fetch_xor

#నిర్వచించు atomic_fetch_and(object, నిర్వాహ్యం_2) \
    __atomic_fetch_and(object, నిర్వాహ్యం_2, __ATOMIC_SEQ_CST)
#నిర్వచించు atomic_fetch_and_explicit __atomic_fetch_and

బాహ్య శూన్య atomic_thread_fence (memory_order);
#నిర్వచించు __atomic_thread_fence(క్రమం) atomic_thread_fence (క్రమం)
బాహ్య శూన్య atomic_signal_fence (memory_order);
#నిర్వచించు __atomic_signal_fence(క్రమం) atomic_signal_fence(క్రమం)
బాహ్య bool __atomic_is_lock_free(కొలత_t కొలత, శూన్య *ptr);
#నిర్వచించు atomic_is_lock_free(OBJ) __atomic_is_lock_free (పరిమాణం (*(OBJ)), (OBJ))

బాహ్య bool atomic_flag_test_and_set(శూన్య *object);
బాహ్య bool atomic_flag_test_and_set_explicit(శూన్య *object, memory_order క్రమం);
బాహ్య శూన్య atomic_flag_clear(శూన్య *object);
బాహ్య శూన్య atomic_flag_clear_explicit(శూన్య *object, memory_order క్రమం);
#అయితే_ముగింపు /* _STDATOMIC_H */
