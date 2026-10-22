/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDATOMIC_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDATOMIC_H

#ਅਨ੍ਤਰ੍ਭਾਵ <stddef.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdbool.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_RELAXED 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_CONSUME 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_ACQUIRE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_RELEASE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_ACQ_REL 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ATOMIC_SEQ_CST 5

/* Memory ordering */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ {
    memory_order_relaxed = __ATOMIC_RELAXED,
    ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_consume = __ATOMIC_CONSUME,
    ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_acquire = __ATOMIC_ACQUIRE,
    ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_release = __ATOMIC_RELEASE,
    ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_acq_rel = __ATOMIC_ACQ_REL,
    ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(_Bool) atomic_bool;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਅੱਖਰ) atomic_char;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ) atomic_schar;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ) atomic_uchar;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਛੋਟਾ) atomic_short;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ) atomic_ushort;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਪੂਰਨ) atomic_int;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ) atomic_uint;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਲੰਮਾ) atomic_long;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) atomic_ulong;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਲੰਮਾ ਲੰਮਾ) atomic_llong;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ) atomic_ullong;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_least16_t) atomic_char16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_least32_t) atomic_char32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(wchar_t) atomic_wchar_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_least8_t) atomic_int_least8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_least8_t) atomic_uint_least8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_least16_t) atomic_int_least16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_least16_t) atomic_uint_least16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_least32_t) atomic_int_least32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_least32_t) atomic_uint_least32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_least64_t) atomic_int_least64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_least64_t) atomic_uint_least64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_fast8_t) atomic_int_fast8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_fast8_t) atomic_uint_fast8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_fast16_t) atomic_int_fast16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_fast16_t) atomic_uint_fast16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_fast32_t) atomic_int_fast32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_fast32_t) atomic_uint_fast32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(int_fast64_t) atomic_int_fast64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uint_fast64_t) atomic_uint_fast64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(intptr_t) atomic_intptr_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uintptr_t) atomic_uintptr_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ਮਾਪ_t) atomic_size_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(ptrdiff_t) atomic_ptrdiff_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(intmax_t) atomic_intmax_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    atomic_bool ਮੁੱਲ;
} atomic_flag;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_FLAG_INIT {0}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATOMIC_VAR_INIT(ਮੁੱਲ) (ਮੁੱਲ)

/* Generic routines */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __atomic_store_n(ptr, val, ਕ੍ਰਮ)                                 \
    ({ __typeof__ ((ਖਾਲੀ)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (ਕ੍ਰਮ)); })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_store_explicit(object, desired, ਕ੍ਰਮ)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (ਕ੍ਰਮ));                               \
    })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __atomic_load_n(ptr, ਕ੍ਰਮ)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (ਕ੍ਰਮ));                             \
       __val; })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_load_explicit(object, ਕ੍ਰਮ)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((ਖਾਲੀ)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (ਕ੍ਰਮ));                                \
       tmp;                                                               \
    })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_exchange_explicit(object, desired, ਕ੍ਰਮ)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (ਕ੍ਰਮ));                      \
       tmp;                                                               \
    })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_add(object, ਸੰਕਾਰਜ_2) \
    __atomic_fetch_add(object, ਸੰਕਾਰਜ_2, __ATOMIC_SEQ_CST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_add_explicit __atomic_fetch_add

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_sub(object, ਸੰਕਾਰਜ_2) \
    __atomic_fetch_sub(object, ਸੰਕਾਰਜ_2, __ATOMIC_SEQ_CST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_sub_explicit __atomic_fetch_sub

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_or(object, ਸੰਕਾਰਜ_2) \
    __atomic_fetch_or(object, ਸੰਕਾਰਜ_2, __ATOMIC_SEQ_CST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_or_explicit __atomic_fetch_or

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_xor(object, ਸੰਕਾਰਜ_2) \
    __atomic_fetch_xor(object, ਸੰਕਾਰਜ_2, __ATOMIC_SEQ_CST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_xor_explicit __atomic_fetch_xor

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_and(object, ਸੰਕਾਰਜ_2) \
    __atomic_fetch_and(object, ਸੰਕਾਰਜ_2, __ATOMIC_SEQ_CST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_fetch_and_explicit __atomic_fetch_and

ਬਾਹਰੀ ਖਾਲੀ atomic_thread_fence (memory_order);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __atomic_thread_fence(ਕ੍ਰਮ) atomic_thread_fence (ਕ੍ਰਮ)
ਬਾਹਰੀ ਖਾਲੀ atomic_signal_fence (memory_order);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __atomic_signal_fence(ਕ੍ਰਮ) atomic_signal_fence(ਕ੍ਰਮ)
ਬਾਹਰੀ bool __atomic_is_lock_free(ਮਾਪ_t ਮਾਪ, ਖਾਲੀ *ptr);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ atomic_is_lock_free(OBJ) __atomic_is_lock_free (ਆਕਾਰ (*(OBJ)), (OBJ))

ਬਾਹਰੀ bool atomic_flag_test_and_set(ਖਾਲੀ *object);
ਬਾਹਰੀ bool atomic_flag_test_and_set_explicit(ਖਾਲੀ *object, memory_order ਕ੍ਰਮ);
ਬਾਹਰੀ ਖਾਲੀ atomic_flag_clear(ਖਾਲੀ *object);
ਬਾਹਰੀ ਖਾਲੀ atomic_flag_clear_explicit(ਖਾਲੀ *object, memory_order ਕ੍ਰਮ);
#ਜੇ_ਅੰਤ /* _STDATOMIC_H */
