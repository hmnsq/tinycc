/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#اگر_غیر_تعریف_شدہ _STDATOMIC_H
#تعریف_کرو _STDATOMIC_H

#شامل <stddef.h>
#شامل <stdint.h>
#شامل <stdbool.h>

#تعریف_کرو __ATOMIC_RELAXED 0
#تعریف_کرو __ATOMIC_CONSUME 1
#تعریف_کرو __ATOMIC_ACQUIRE 2
#تعریف_کرو __ATOMIC_RELEASE 3
#تعریف_کرو __ATOMIC_ACQ_REL 4
#تعریف_کرو __ATOMIC_SEQ_CST 5

/* Memory ordering */
قسمتعریف شمار {
    memory_order_relaxed = __ATOMIC_RELAXED,
    حافظہ_ترتیب_consume = __ATOMIC_CONSUME,
    حافظہ_ترتیب_acquire = __ATOMIC_ACQUIRE,
    حافظہ_ترتیب_release = __ATOMIC_RELEASE,
    حافظہ_ترتیب_acq_rel = __ATOMIC_ACQ_REL,
    حافظہ_ترتیب_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
قسمتعریف _Atomic(_Bool) atomic_bool;
قسمتعریف _Atomic(حرف) atomic_char;
قسمتعریف _Atomic(علامتی حرف) atomic_schar;
قسمتعریف _Atomic(غیرعلامتی حرف) atomic_uchar;
قسمتعریف _Atomic(مختصر) atomic_short;
قسمتعریف _Atomic(غیرعلامتی مختصر) atomic_ushort;
قسمتعریف _Atomic(صحیح) atomic_int;
قسمتعریف _Atomic(غیرعلامتی صحیح) atomic_uint;
قسمتعریف _Atomic(طویل) atomic_long;
قسمتعریف _Atomic(غیرعلامتی طویل) atomic_ulong;
قسمتعریف _Atomic(طویل طویل) atomic_llong;
قسمتعریف _Atomic(غیرعلامتی طویل طویل) atomic_ullong;
قسمتعریف _Atomic(uint_least16_t) atomic_char16_t;
قسمتعریف _Atomic(uint_least32_t) atomic_char32_t;
قسمتعریف _Atomic(wchar_t) atomic_wchar_t;
قسمتعریف _Atomic(int_least8_t) atomic_int_least8_t;
قسمتعریف _Atomic(uint_least8_t) atomic_uint_least8_t;
قسمتعریف _Atomic(int_least16_t) atomic_int_least16_t;
قسمتعریف _Atomic(uint_least16_t) atomic_uint_least16_t;
قسمتعریف _Atomic(int_least32_t) atomic_int_least32_t;
قسمتعریف _Atomic(uint_least32_t) atomic_uint_least32_t;
قسمتعریف _Atomic(int_least64_t) atomic_int_least64_t;
قسمتعریف _Atomic(uint_least64_t) atomic_uint_least64_t;
قسمتعریف _Atomic(int_fast8_t) atomic_int_fast8_t;
قسمتعریف _Atomic(uint_fast8_t) atomic_uint_fast8_t;
قسمتعریف _Atomic(int_fast16_t) atomic_int_fast16_t;
قسمتعریف _Atomic(uint_fast16_t) atomic_uint_fast16_t;
قسمتعریف _Atomic(int_fast32_t) atomic_int_fast32_t;
قسمتعریف _Atomic(uint_fast32_t) atomic_uint_fast32_t;
قسمتعریف _Atomic(int_fast64_t) atomic_int_fast64_t;
قسمتعریف _Atomic(uint_fast64_t) atomic_uint_fast64_t;
قسمتعریف _Atomic(intptr_t) atomic_intptr_t;
قسمتعریف _Atomic(uintptr_t) atomic_uintptr_t;
قسمتعریف _Atomic(سائز_t) atomic_size_t;
قسمتعریف _Atomic(ptrdiff_t) atomic_ptrdiff_t;
قسمتعریف _Atomic(intmax_t) atomic_intmax_t;
قسمتعریف _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
قسمتعریف ساخت {
    atomic_bool قدر;
} atomic_flag;

#تعریف_کرو ATOMIC_FLAG_INIT {0}
#تعریف_کرو ATOMIC_VAR_INIT(قدر) (قدر)

/* Generic routines */
#تعریف_کرو atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#تعریف_کرو __atomic_store_n(ptr, val, ترتیب)                                 \
    ({ __typeof__ ((خالی)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (ترتیب)); })
#تعریف_کرو atomic_store_explicit(object, desired, ترتیب)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (ترتیب));                               \
    })
#تعریف_کرو atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#تعریف_کرو __atomic_load_n(ptr, ترتیب)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (ترتیب));                             \
       __val; })
#تعریف_کرو atomic_load_explicit(object, ترتیب)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((خالی)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (ترتیب));                                \
       tmp;                                                               \
    })
#تعریف_کرو atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#تعریف_کرو atomic_exchange_explicit(object, desired, ترتیب)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (ترتیب));                      \
       tmp;                                                               \
    })
#تعریف_کرو atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#تعریف_کرو __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#تعریف_کرو atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#تعریف_کرو atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#تعریف_کرو atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#تعریف_کرو atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#تعریف_کرو atomic_fetch_add(object, عملیہ_2) \
    __atomic_fetch_add(object, عملیہ_2, __ATOMIC_SEQ_CST)
#تعریف_کرو atomic_fetch_add_explicit __atomic_fetch_add

#تعریف_کرو atomic_fetch_sub(object, عملیہ_2) \
    __atomic_fetch_sub(object, عملیہ_2, __ATOMIC_SEQ_CST)
#تعریف_کرو atomic_fetch_sub_explicit __atomic_fetch_sub

#تعریف_کرو atomic_fetch_or(object, عملیہ_2) \
    __atomic_fetch_or(object, عملیہ_2, __ATOMIC_SEQ_CST)
#تعریف_کرو atomic_fetch_or_explicit __atomic_fetch_or

#تعریف_کرو atomic_fetch_xor(object, عملیہ_2) \
    __atomic_fetch_xor(object, عملیہ_2, __ATOMIC_SEQ_CST)
#تعریف_کرو atomic_fetch_xor_explicit __atomic_fetch_xor

#تعریف_کرو atomic_fetch_and(object, عملیہ_2) \
    __atomic_fetch_and(object, عملیہ_2, __ATOMIC_SEQ_CST)
#تعریف_کرو atomic_fetch_and_explicit __atomic_fetch_and

خارجی خالی atomic_thread_fence (memory_order);
#تعریف_کرو __atomic_thread_fence(ترتیب) atomic_thread_fence (ترتیب)
خارجی خالی atomic_signal_fence (memory_order);
#تعریف_کرو __atomic_signal_fence(ترتیب) atomic_signal_fence(ترتیب)
خارجی bool __atomic_is_lock_free(سائز_t سائز, خالی *ptr);
#تعریف_کرو atomic_is_lock_free(OBJ) __atomic_is_lock_free (حجم (*(OBJ)), (OBJ))

خارجی bool atomic_flag_test_and_set(خالی *object);
خارجی bool atomic_flag_test_and_set_explicit(خالی *object, memory_order ترتیب);
خارجی خالی atomic_flag_clear(خالی *object);
خارجی خالی atomic_flag_clear_explicit(خالی *object, memory_order ترتیب);
#اگر_ختم /* _STDATOMIC_H */
