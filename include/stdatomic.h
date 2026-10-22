/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef _STDATOMIC_H
#define _STDATOMIC_H

#ಅನ್ತರ್ಭಾವ <stddef.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <stdbool.h>

#define __ATOMIC_RELAXED 0
#define __ATOMIC_CONSUME 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_SEQ_CST 5

/* Memory ordering */
ಪ್ರಕಾರನಿರ್ದೇಶ ಗಣನಾ {
    memory_order_relaxed = __ATOMIC_RELAXED,
    memory_order_consume = __ATOMIC_CONSUME,
    memory_order_acquire = __ATOMIC_ACQUIRE,
    memory_order_release = __ATOMIC_RELEASE,
    memory_order_acq_rel = __ATOMIC_ACQ_REL,
    memory_order_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(_Bool) atomic_bool;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(ವರ್ಣ) atomic_char;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(signed ವರ್ಣ) atomic_schar;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(unsigned ವರ್ಣ) atomic_uchar;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(short) atomic_short;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(unsigned short) atomic_ushort;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(ಪೂರ್ಣಾಙ್ಕ) atomic_int;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(unsigned ಪೂರ್ಣಾಙ್ಕ) atomic_uint;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(long) atomic_long;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(unsigned long) atomic_ulong;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(long long) atomic_llong;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(unsigned long long) atomic_ullong;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_least16_t) atomic_char16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_least32_t) atomic_char32_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(wchar_t) atomic_wchar_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_least8_t) atomic_int_least8_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_least8_t) atomic_uint_least8_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_least16_t) atomic_int_least16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_least16_t) atomic_uint_least16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_least32_t) atomic_int_least32_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_least32_t) atomic_uint_least32_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_least64_t) atomic_int_least64_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_least64_t) atomic_uint_least64_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_fast8_t) atomic_int_fast8_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_fast8_t) atomic_uint_fast8_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_fast16_t) atomic_int_fast16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_fast16_t) atomic_uint_fast16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_fast32_t) atomic_int_fast32_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_fast32_t) atomic_uint_fast32_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(int_fast64_t) atomic_int_fast64_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uint_fast64_t) atomic_uint_fast64_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(intptr_t) atomic_intptr_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uintptr_t) atomic_uintptr_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(size_t) atomic_size_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(ptrdiff_t) atomic_ptrdiff_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(intmax_t) atomic_intmax_t;
ಪ್ರಕಾರನಿರ್ದೇಶ _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    atomic_bool ಮೌಲ್ಯ;
} atomic_flag;

#define ATOMIC_FLAG_INIT {0}
#define ATOMIC_VAR_INIT(ಮೌಲ್ಯ) (ಮೌಲ್ಯ)

/* Generic routines */
#define atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#define __atomic_store_n(ptr, val, order)                                 \
    ({ __typeof__ ((ಶೂನ್ಯ)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (order)); })
#define atomic_store_explicit(object, desired, order)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (order));                               \
    })
#define atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#define __atomic_load_n(ptr, order)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (order));                             \
       __val; })
#define atomic_load_explicit(object, order)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((ಶೂನ್ಯ)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (order));                                \
       tmp;                                                               \
    })
#define atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#define atomic_exchange_explicit(object, desired, order)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (order));                      \
       tmp;                                                               \
    })
#define atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#define __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#define atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#define atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#define atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#define atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#define atomic_fetch_add(object, operand) \
    __atomic_fetch_add(object, operand, __ATOMIC_SEQ_CST)
#define atomic_fetch_add_explicit __atomic_fetch_add

#define atomic_fetch_sub(object, operand) \
    __atomic_fetch_sub(object, operand, __ATOMIC_SEQ_CST)
#define atomic_fetch_sub_explicit __atomic_fetch_sub

#define atomic_fetch_or(object, operand) \
    __atomic_fetch_or(object, operand, __ATOMIC_SEQ_CST)
#define atomic_fetch_or_explicit __atomic_fetch_or

#define atomic_fetch_xor(object, operand) \
    __atomic_fetch_xor(object, operand, __ATOMIC_SEQ_CST)
#define atomic_fetch_xor_explicit __atomic_fetch_xor

#define atomic_fetch_and(object, operand) \
    __atomic_fetch_and(object, operand, __ATOMIC_SEQ_CST)
#define atomic_fetch_and_explicit __atomic_fetch_and

ಬಾಹ್ಯ ಶೂನ್ಯ atomic_thread_fence (memory_order);
#define __atomic_thread_fence(order) atomic_thread_fence (order)
ಬಾಹ್ಯ ಶೂನ್ಯ atomic_signal_fence (memory_order);
#define __atomic_signal_fence(order) atomic_signal_fence(order)
ಬಾಹ್ಯ bool __atomic_is_lock_free(size_t size, ಶೂನ್ಯ *ptr);
#define atomic_is_lock_free(OBJ) __atomic_is_lock_free (ಪರಿಮಾಣ (*(OBJ)), (OBJ))

ಬಾಹ್ಯ bool atomic_flag_test_and_set(ಶೂನ್ಯ *object);
ಬಾಹ್ಯ bool atomic_flag_test_and_set_explicit(ಶೂನ್ಯ *object, memory_order order);
ಬಾಹ್ಯ ಶೂನ್ಯ atomic_flag_clear(ಶೂನ್ಯ *object);
ಬಾಹ್ಯ ಶೂನ್ಯ atomic_flag_clear_explicit(ಶೂನ್ಯ *object, memory_order order);
#endif /* _STDATOMIC_H */
