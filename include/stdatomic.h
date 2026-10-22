/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#جيڪڏهن_وصف_نه_ٿيل _STDATOMIC_H
#وصف_ڪريو _STDATOMIC_H

#ضمن <stddef.h>
#ضمن <stdint.h>
#ضمن <stdbool.h>

#وصف_ڪريو __ATOMIC_RELAXED 0
#وصف_ڪريو __ATOMIC_CONSUME 1
#وصف_ڪريو __ATOMIC_ACQUIRE 2
#وصف_ڪريو __ATOMIC_RELEASE 3
#وصف_ڪريو __ATOMIC_ACQ_REL 4
#وصف_ڪريو __ATOMIC_SEQ_CST 5

/* Memory ordering */
تعريفنوع تعداد {
    memory_order_relaxed = __ATOMIC_RELAXED,
    يادگيري_ترتيب_consume = __ATOMIC_CONSUME,
    يادگيري_ترتيب_acquire = __ATOMIC_ACQUIRE,
    يادگيري_ترتيب_release = __ATOMIC_RELEASE,
    يادگيري_ترتيب_acq_rel = __ATOMIC_ACQ_REL,
    يادگيري_ترتيب_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
تعريفنوع _Atomic(_Bool) atomic_bool;
تعريفنوع _Atomic(حرف) atomic_char;
تعريفنوع _Atomic(نشانوارو حرف) atomic_schar;
تعريفنوع _Atomic(بنانشان حرف) atomic_uchar;
تعريفنوع _Atomic(ننڍو) atomic_short;
تعريفنوع _Atomic(بنانشان ننڍو) atomic_ushort;
تعريفنوع _Atomic(صحيح) atomic_int;
تعريفنوع _Atomic(بنانشان صحيح) atomic_uint;
تعريفنوع _Atomic(ڊگهو) atomic_long;
تعريفنوع _Atomic(بنانشان ڊگهو) atomic_ulong;
تعريفنوع _Atomic(ڊگهو ڊگهو) atomic_llong;
تعريفنوع _Atomic(بنانشان ڊگهو ڊگهو) atomic_ullong;
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
تعريفنوع _Atomic(سائيز_t) atomic_size_t;
تعريفنوع _Atomic(ptrdiff_t) atomic_ptrdiff_t;
تعريفنوع _Atomic(intmax_t) atomic_intmax_t;
تعريفنوع _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
تعريفنوع بنية {
    atomic_bool قدر;
} atomic_flag;

#وصف_ڪريو ATOMIC_FLAG_INIT {0}
#وصف_ڪريو ATOMIC_VAR_INIT(قدر) (قدر)

/* Generic routines */
#وصف_ڪريو atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#وصف_ڪريو __atomic_store_n(ptr, val, ترتيب)                                 \
    ({ __typeof__ ((فراغ)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (ترتيب)); })
#وصف_ڪريو atomic_store_explicit(object, desired, ترتيب)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (ترتيب));                               \
    })
#وصف_ڪريو atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#وصف_ڪريو __atomic_load_n(ptr, ترتيب)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (ترتيب));                             \
       __val; })
#وصف_ڪريو atomic_load_explicit(object, ترتيب)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((فراغ)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (ترتيب));                                \
       tmp;                                                               \
    })
#وصف_ڪريو atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#وصف_ڪريو atomic_exchange_explicit(object, desired, ترتيب)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (ترتيب));                      \
       tmp;                                                               \
    })
#وصف_ڪريو atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#وصف_ڪريو __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#وصف_ڪريو atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#وصف_ڪريو atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#وصف_ڪريو atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#وصف_ڪريو atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#وصف_ڪريو atomic_fetch_add(object, عمليو_2) \
    __atomic_fetch_add(object, عمليو_2, __ATOMIC_SEQ_CST)
#وصف_ڪريو atomic_fetch_add_explicit __atomic_fetch_add

#وصف_ڪريو atomic_fetch_sub(object, عمليو_2) \
    __atomic_fetch_sub(object, عمليو_2, __ATOMIC_SEQ_CST)
#وصف_ڪريو atomic_fetch_sub_explicit __atomic_fetch_sub

#وصف_ڪريو atomic_fetch_or(object, عمليو_2) \
    __atomic_fetch_or(object, عمليو_2, __ATOMIC_SEQ_CST)
#وصف_ڪريو atomic_fetch_or_explicit __atomic_fetch_or

#وصف_ڪريو atomic_fetch_xor(object, عمليو_2) \
    __atomic_fetch_xor(object, عمليو_2, __ATOMIC_SEQ_CST)
#وصف_ڪريو atomic_fetch_xor_explicit __atomic_fetch_xor

#وصف_ڪريو atomic_fetch_and(object, عمليو_2) \
    __atomic_fetch_and(object, عمليو_2, __ATOMIC_SEQ_CST)
#وصف_ڪريو atomic_fetch_and_explicit __atomic_fetch_and

خارجي فراغ atomic_thread_fence (memory_order);
#وصف_ڪريو __atomic_thread_fence(ترتيب) atomic_thread_fence (ترتيب)
خارجي فراغ atomic_signal_fence (memory_order);
#وصف_ڪريو __atomic_signal_fence(ترتيب) atomic_signal_fence(ترتيب)
خارجي bool __atomic_is_lock_free(سائيز_t سائيز, فراغ *ptr);
#وصف_ڪريو atomic_is_lock_free(OBJ) __atomic_is_lock_free (حجم (*(OBJ)), (OBJ))

خارجي bool atomic_flag_test_and_set(فراغ *object);
خارجي bool atomic_flag_test_and_set_explicit(فراغ *object, memory_order ترتيب);
خارجي فراغ atomic_flag_clear(فراغ *object);
خارجي فراغ atomic_flag_clear_explicit(فراغ *object, memory_order ترتيب);
#جيڪڏهن_پورو /* _STDATOMIC_H */
