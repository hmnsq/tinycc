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

#অন্তর্ভাব <stddef.h>
#অন্তর্ভাব <stdint.h>
#অন্তর্ভাব <stdbool.h>

#define __ATOMIC_RELAXED 0
#define __ATOMIC_CONSUME 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_SEQ_CST 5

/* Memory ordering */
প্রকারলেখ গণনা {
    memory_order_relaxed = __ATOMIC_RELAXED,
    memory_order_consume = __ATOMIC_CONSUME,
    memory_order_acquire = __ATOMIC_ACQUIRE,
    memory_order_release = __ATOMIC_RELEASE,
    memory_order_acq_rel = __ATOMIC_ACQ_REL,
    memory_order_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
প্রকারলেখ _Atomic(_Bool) atomic_bool;
প্রকারলেখ _Atomic(অক্ষর) atomic_char;
প্রকারলেখ _Atomic(signed অক্ষর) atomic_schar;
প্রকারলেখ _Atomic(unsigned অক্ষর) atomic_uchar;
প্রকারলেখ _Atomic(short) atomic_short;
প্রকারলেখ _Atomic(unsigned short) atomic_ushort;
প্রকারলেখ _Atomic(পূর্ণসংখ্যা) atomic_int;
প্রকারলেখ _Atomic(unsigned পূর্ণসংখ্যা) atomic_uint;
প্রকারলেখ _Atomic(long) atomic_long;
প্রকারলেখ _Atomic(unsigned long) atomic_ulong;
প্রকারলেখ _Atomic(long long) atomic_llong;
প্রকারলেখ _Atomic(unsigned long long) atomic_ullong;
প্রকারলেখ _Atomic(uint_least16_t) atomic_char16_t;
প্রকারলেখ _Atomic(uint_least32_t) atomic_char32_t;
প্রকারলেখ _Atomic(wchar_t) atomic_wchar_t;
প্রকারলেখ _Atomic(int_least8_t) atomic_int_least8_t;
প্রকারলেখ _Atomic(uint_least8_t) atomic_uint_least8_t;
প্রকারলেখ _Atomic(int_least16_t) atomic_int_least16_t;
প্রকারলেখ _Atomic(uint_least16_t) atomic_uint_least16_t;
প্রকারলেখ _Atomic(int_least32_t) atomic_int_least32_t;
প্রকারলেখ _Atomic(uint_least32_t) atomic_uint_least32_t;
প্রকারলেখ _Atomic(int_least64_t) atomic_int_least64_t;
প্রকারলেখ _Atomic(uint_least64_t) atomic_uint_least64_t;
প্রকারলেখ _Atomic(int_fast8_t) atomic_int_fast8_t;
প্রকারলেখ _Atomic(uint_fast8_t) atomic_uint_fast8_t;
প্রকারলেখ _Atomic(int_fast16_t) atomic_int_fast16_t;
প্রকারলেখ _Atomic(uint_fast16_t) atomic_uint_fast16_t;
প্রকারলেখ _Atomic(int_fast32_t) atomic_int_fast32_t;
প্রকারলেখ _Atomic(uint_fast32_t) atomic_uint_fast32_t;
প্রকারলেখ _Atomic(int_fast64_t) atomic_int_fast64_t;
প্রকারলেখ _Atomic(uint_fast64_t) atomic_uint_fast64_t;
প্রকারলেখ _Atomic(intptr_t) atomic_intptr_t;
প্রকারলেখ _Atomic(uintptr_t) atomic_uintptr_t;
প্রকারলেখ _Atomic(আকার_t) atomic_size_t;
প্রকারলেখ _Atomic(ptrdiff_t) atomic_ptrdiff_t;
প্রকারলেখ _Atomic(intmax_t) atomic_intmax_t;
প্রকারলেখ _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
প্রকারলেখ কাঠামো {
    atomic_bool মান;
} atomic_flag;

#define ATOMIC_FLAG_INIT {0}
#define ATOMIC_VAR_INIT(মান) (মান)

/* Generic routines */
#define atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#define __atomic_store_n(ptr, val, order)                                 \
    ({ __typeof__ ((শূন্য)0, *(ptr)) __val = (val);                      \
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
       __typeof__ ((শূন্য)0,*ptr) tmp;                                             \
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

বাহ্যিক শূন্য atomic_thread_fence (memory_order);
#define __atomic_thread_fence(order) atomic_thread_fence (order)
বাহ্যিক শূন্য atomic_signal_fence (memory_order);
#define __atomic_signal_fence(order) atomic_signal_fence(order)
বাহ্যিক bool __atomic_is_lock_free(আকার_t আকার_2, শূন্য *ptr);
#define atomic_is_lock_free(OBJ) __atomic_is_lock_free (আকার (*(OBJ)), (OBJ))

বাহ্যিক bool atomic_flag_test_and_set(শূন্য *object);
বাহ্যিক bool atomic_flag_test_and_set_explicit(শূন্য *object, memory_order order);
বাহ্যিক শূন্য atomic_flag_clear(শূন্য *object);
বাহ্যিক শূন্য atomic_flag_clear_explicit(শূন্য *object, memory_order order);
#endif /* _STDATOMIC_H */
