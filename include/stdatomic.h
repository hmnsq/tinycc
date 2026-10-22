/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDATOMIC_H
#ವ್ಯಾಖ್ಯಾನಿಸು _STDATOMIC_H

#ಅನ್ತರ್ಭಾವ <stddef.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <stdbool.h>

#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_RELAXED 0
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_CONSUME 1
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_ACQUIRE 2
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_RELEASE 3
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_ACQ_REL 4
#ವ್ಯಾಖ್ಯಾನಿಸು __ATOMIC_SEQ_CST 5

/* Memory ordering */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ {
    memory_order_relaxed = __ATOMIC_RELAXED,
    ಸ್ಮರಣೆ_ಕ್ರಮ_consume = __ATOMIC_CONSUME,
    ಸ್ಮರಣೆ_ಕ್ರಮ_acquire = __ATOMIC_ACQUIRE,
    ಸ್ಮರಣೆ_ಕ್ರಮ_release = __ATOMIC_RELEASE,
    ಸ್ಮರಣೆ_ಕ್ರಮ_acq_rel = __ATOMIC_ACQ_REL,
    ಸ್ಮರಣೆ_ಕ್ರಮ_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(_Bool) atomic_bool;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಅಕ್ಷರ) atomic_char;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ) atomic_schar;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ) atomic_uchar;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಗಿಡ್ಡ) atomic_short;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ) atomic_ushort;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಪೂರ್ಣಾಂಕ) atomic_int;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ) atomic_uint;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ದೀರ್ಘ) atomic_long;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) atomic_ulong;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ದೀರ್ಘ ದೀರ್ಘ) atomic_llong;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ) atomic_ullong;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_least16_t) atomic_char16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_least32_t) atomic_char32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(wchar_t) atomic_wchar_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_least8_t) atomic_int_least8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_least8_t) atomic_uint_least8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_least16_t) atomic_int_least16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_least16_t) atomic_uint_least16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_least32_t) atomic_int_least32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_least32_t) atomic_uint_least32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_least64_t) atomic_int_least64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_least64_t) atomic_uint_least64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_fast8_t) atomic_int_fast8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_fast8_t) atomic_uint_fast8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_fast16_t) atomic_int_fast16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_fast16_t) atomic_uint_fast16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_fast32_t) atomic_int_fast32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_fast32_t) atomic_uint_fast32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(int_fast64_t) atomic_int_fast64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uint_fast64_t) atomic_uint_fast64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(intptr_t) atomic_intptr_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uintptr_t) atomic_uintptr_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ಗಾತ್ರ_t) atomic_size_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(ptrdiff_t) atomic_ptrdiff_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(intmax_t) atomic_intmax_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    atomic_bool ಮೌಲ್ಯ;
} atomic_flag;

#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_FLAG_INIT {0}
#ವ್ಯಾಖ್ಯಾನಿಸು ATOMIC_VAR_INIT(ಮೌಲ್ಯ) (ಮೌಲ್ಯ)

/* Generic routines */
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#ವ್ಯಾಖ್ಯಾನಿಸು __atomic_store_n(ptr, val, ಕ್ರಮ)                                 \
    ({ __typeof__ ((ಶೂನ್ಯ)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (ಕ್ರಮ)); })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_store_explicit(object, desired, ಕ್ರಮ)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (ಕ್ರಮ));                               \
    })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#ವ್ಯಾಖ್ಯಾನಿಸು __atomic_load_n(ptr, ಕ್ರಮ)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (ಕ್ರಮ));                             \
       __val; })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_load_explicit(object, ಕ್ರಮ)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((ಶೂನ್ಯ)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (ಕ್ರಮ));                                \
       tmp;                                                               \
    })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#ವ್ಯಾಖ್ಯಾನಿಸು atomic_exchange_explicit(object, desired, ಕ್ರಮ)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (ಕ್ರಮ));                      \
       tmp;                                                               \
    })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#ವ್ಯಾಖ್ಯಾನಿಸು __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_add(object, ಕಾರ್ಯಾಂಶ_2) \
    __atomic_fetch_add(object, ಕಾರ್ಯಾಂಶ_2, __ATOMIC_SEQ_CST)
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_add_explicit __atomic_fetch_add

#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_sub(object, ಕಾರ್ಯಾಂಶ_2) \
    __atomic_fetch_sub(object, ಕಾರ್ಯಾಂಶ_2, __ATOMIC_SEQ_CST)
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_sub_explicit __atomic_fetch_sub

#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_or(object, ಕಾರ್ಯಾಂಶ_2) \
    __atomic_fetch_or(object, ಕಾರ್ಯಾಂಶ_2, __ATOMIC_SEQ_CST)
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_or_explicit __atomic_fetch_or

#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_xor(object, ಕಾರ್ಯಾಂಶ_2) \
    __atomic_fetch_xor(object, ಕಾರ್ಯಾಂಶ_2, __ATOMIC_SEQ_CST)
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_xor_explicit __atomic_fetch_xor

#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_and(object, ಕಾರ್ಯಾಂಶ_2) \
    __atomic_fetch_and(object, ಕಾರ್ಯಾಂಶ_2, __ATOMIC_SEQ_CST)
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_fetch_and_explicit __atomic_fetch_and

ಬಾಹ್ಯ ಶೂನ್ಯ atomic_thread_fence (memory_order);
#ವ್ಯಾಖ್ಯಾನಿಸು __atomic_thread_fence(ಕ್ರಮ) atomic_thread_fence (ಕ್ರಮ)
ಬಾಹ್ಯ ಶೂನ್ಯ atomic_signal_fence (memory_order);
#ವ್ಯಾಖ್ಯಾನಿಸು __atomic_signal_fence(ಕ್ರಮ) atomic_signal_fence(ಕ್ರಮ)
ಬಾಹ್ಯ bool __atomic_is_lock_free(ಗಾತ್ರ_t ಗಾತ್ರ_2, ಶೂನ್ಯ *ptr);
#ವ್ಯಾಖ್ಯಾನಿಸು atomic_is_lock_free(OBJ) __atomic_is_lock_free (ಗಾತ್ರ (*(OBJ)), (OBJ))

ಬಾಹ್ಯ bool atomic_flag_test_and_set(ಶೂನ್ಯ *object);
ಬಾಹ್ಯ bool atomic_flag_test_and_set_explicit(ಶೂನ್ಯ *object, memory_order ಕ್ರಮ);
ಬಾಹ್ಯ ಶೂನ್ಯ atomic_flag_clear(ಶೂನ್ಯ *object);
ಬಾಹ್ಯ ಶೂನ್ಯ atomic_flag_clear_explicit(ಶೂನ್ಯ *object, memory_order ಕ್ರಮ);
#ಆದರೆ_ಅಂತ್ಯ /* _STDATOMIC_H */
