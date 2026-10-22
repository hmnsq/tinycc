/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#که_نه_تعریف_شوی _STDATOMIC_H
#تعریف_کړه _STDATOMIC_H

#ضمن <stddef.h>
#ضمن <stdint.h>
#ضمن <stdbool.h>

#تعریف_کړه __ATOMIC_RELAXED 0
#تعریف_کړه __ATOMIC_CONSUME 1
#تعریف_کړه __ATOMIC_ACQUIRE 2
#تعریف_کړه __ATOMIC_RELEASE 3
#تعریف_کړه __ATOMIC_ACQ_REL 4
#تعریف_کړه __ATOMIC_SEQ_CST 5

/* Memory ordering */
تعريفنوع تعداد {
    memory_order_relaxed = __ATOMIC_RELAXED,
    حافظه_ترتیب_consume = __ATOMIC_CONSUME,
    حافظه_ترتیب_acquire = __ATOMIC_ACQUIRE,
    حافظه_ترتیب_release = __ATOMIC_RELEASE,
    حافظه_ترتیب_acq_rel = __ATOMIC_ACQ_REL,
    حافظه_ترتیب_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
تعريفنوع _Atomic(_Bool) atomic_bool;
تعريفنوع _Atomic(حرف) atomic_char;
تعريفنوع _Atomic(نښهدار حرف) atomic_schar;
تعريفنوع _Atomic(بینښه حرف) atomic_uchar;
تعريفنوع _Atomic(لنډ) atomic_short;
تعريفنوع _Atomic(بینښه لنډ) atomic_ushort;
تعريفنوع _Atomic(صحيح) atomic_int;
تعريفنوع _Atomic(بینښه صحيح) atomic_uint;
تعريفنوع _Atomic(اوږد) atomic_long;
تعريفنوع _Atomic(بینښه اوږد) atomic_ulong;
تعريفنوع _Atomic(اوږد اوږد) atomic_llong;
تعريفنوع _Atomic(بینښه اوږد اوږد) atomic_ullong;
تعريفنوع _Atomic(uint_least16_t) atomic_char16_t;
تعريفنوع _Atomic(uint_least32_t) atomic_char32_t;
تعريفنوع _Atomic(wchar_t) atomic_wchar_t;
تعريفنوع _Atomic(int_least8_t) atomic_int_least8_t;
تعريفنوع _Atomic(uint_least8_t) atomic_uint_least8_t;
تعريفنوع _Atomic(int_least16_t) atomic_int_least16_t;
تعريفنوع _Atomic(uint_least16_t) atomic_uint_least16_t;
تعريفنوع _Atomic(int_least32_t) atomic_int_least32_t;
تعريفنوع _Atomic(uint_least32_t) atomic_uint_least32_t;
تعريفنوع _Atomic(int_least64_t) atomic_int_least64_t;
تعريفنوع _Atomic(uint_least64_t) atomic_uint_least64_t;
تعريفنوع _Atomic(int_fast8_t) atomic_int_fast8_t;
تعريفنوع _Atomic(uint_fast8_t) atomic_uint_fast8_t;
تعريفنوع _Atomic(int_fast16_t) atomic_int_fast16_t;
تعريفنوع _Atomic(uint_fast16_t) atomic_uint_fast16_t;
تعريفنوع _Atomic(int_fast32_t) atomic_int_fast32_t;
تعريفنوع _Atomic(uint_fast32_t) atomic_uint_fast32_t;
تعريفنوع _Atomic(int_fast64_t) atomic_int_fast64_t;
تعريفنوع _Atomic(uint_fast64_t) atomic_uint_fast64_t;
تعريفنوع _Atomic(intptr_t) atomic_intptr_t;
تعريفنوع _Atomic(uintptr_t) atomic_uintptr_t;
تعريفنوع _Atomic(اندازه_t) atomic_size_t;
تعريفنوع _Atomic(ptrdiff_t) atomic_ptrdiff_t;
تعريفنوع _Atomic(intmax_t) atomic_intmax_t;
تعريفنوع _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
تعريفنوع بنية {
    atomic_bool ارزښت;
} atomic_flag;

#تعریف_کړه ATOMIC_FLAG_INIT {0}
#تعریف_کړه ATOMIC_VAR_INIT(ارزښت) (ارزښت)

/* Generic routines */
#تعریف_کړه atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#تعریف_کړه __atomic_store_n(ptr, val, ترتیب)                                 \
    ({ __typeof__ ((فراغ)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (ترتیب)); })
#تعریف_کړه atomic_store_explicit(object, desired, ترتیب)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (ترتیب));                               \
    })
#تعریف_کړه atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#تعریف_کړه __atomic_load_n(ptr, ترتیب)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (ترتیب));                             \
       __val; })
#تعریف_کړه atomic_load_explicit(object, ترتیب)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((فراغ)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (ترتیب));                                \
       tmp;                                                               \
    })
#تعریف_کړه atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#تعریف_کړه atomic_exchange_explicit(object, desired, ترتیب)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (ترتیب));                      \
       tmp;                                                               \
    })
#تعریف_کړه atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#تعریف_کړه __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#تعریف_کړه atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#تعریف_کړه atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#تعریف_کړه atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#تعریف_کړه atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#تعریف_کړه atomic_fetch_add(object, عملوند_2) \
    __atomic_fetch_add(object, عملوند_2, __ATOMIC_SEQ_CST)
#تعریف_کړه atomic_fetch_add_explicit __atomic_fetch_add

#تعریف_کړه atomic_fetch_sub(object, عملوند_2) \
    __atomic_fetch_sub(object, عملوند_2, __ATOMIC_SEQ_CST)
#تعریف_کړه atomic_fetch_sub_explicit __atomic_fetch_sub

#تعریف_کړه atomic_fetch_or(object, عملوند_2) \
    __atomic_fetch_or(object, عملوند_2, __ATOMIC_SEQ_CST)
#تعریف_کړه atomic_fetch_or_explicit __atomic_fetch_or

#تعریف_کړه atomic_fetch_xor(object, عملوند_2) \
    __atomic_fetch_xor(object, عملوند_2, __ATOMIC_SEQ_CST)
#تعریف_کړه atomic_fetch_xor_explicit __atomic_fetch_xor

#تعریف_کړه atomic_fetch_and(object, عملوند_2) \
    __atomic_fetch_and(object, عملوند_2, __ATOMIC_SEQ_CST)
#تعریف_کړه atomic_fetch_and_explicit __atomic_fetch_and

خارجي فراغ atomic_thread_fence (memory_order);
#تعریف_کړه __atomic_thread_fence(ترتیب) atomic_thread_fence (ترتیب)
خارجي فراغ atomic_signal_fence (memory_order);
#تعریف_کړه __atomic_signal_fence(ترتیب) atomic_signal_fence(ترتیب)
خارجي bool __atomic_is_lock_free(اندازه_t اندازه, فراغ *ptr);
#تعریف_کړه atomic_is_lock_free(OBJ) __atomic_is_lock_free (حجم (*(OBJ)), (OBJ))

خارجي bool atomic_flag_test_and_set(فراغ *object);
خارجي bool atomic_flag_test_and_set_explicit(فراغ *object, memory_order ترتیب);
خارجي فراغ atomic_flag_clear(فراغ *object);
خارجي فراغ atomic_flag_clear_explicit(فراغ *object, memory_order ترتیب);
#د_که_پای /* _STDATOMIC_H */
