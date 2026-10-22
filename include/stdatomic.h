/* This file is derived from clang's stdatomic.h */

/*===---- stdatomic.h - Standard header for atomic types and operations -----===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */

#यदि_अपरिभाषितम् _STDATOMIC_H
#परिभाषय _STDATOMIC_H

#अन्तर्भाव <stddef.h>
#अन्तर्भाव <stdint.h>
#अन्तर्भाव <stdbool.h>

#परिभाषय __ATOMIC_RELAXED 0
#परिभाषय __ATOMIC_CONSUME 1
#परिभाषय __ATOMIC_ACQUIRE 2
#परिभाषय __ATOMIC_RELEASE 3
#परिभाषय __ATOMIC_ACQ_REL 4
#परिभाषय __ATOMIC_SEQ_CST 5

/* Memory ordering */
प्रकारनिर्देश गणना {
    memory_order_relaxed = __ATOMIC_RELAXED,
    स्मृतिः_क्रमः_consume = __ATOMIC_CONSUME,
    स्मृतिः_क्रमः_acquire = __ATOMIC_ACQUIRE,
    स्मृतिः_क्रमः_release = __ATOMIC_RELEASE,
    स्मृतिः_क्रमः_acq_rel = __ATOMIC_ACQ_REL,
    स्मृतिः_क्रमः_seq_cst = __ATOMIC_SEQ_CST,
} memory_order;

/* Atomic typedefs */
प्रकारनिर्देश _Atomic(_Bool) atomic_bool;
प्रकारनिर्देश _Atomic(वर्ण) atomic_char;
प्रकारनिर्देश _Atomic(चिह्नित वर्ण) atomic_schar;
प्रकारनिर्देश _Atomic(अचिह्नित वर्ण) atomic_uchar;
प्रकारनिर्देश _Atomic(ह्रस्व) atomic_short;
प्रकारनिर्देश _Atomic(अचिह्नित ह्रस्व) atomic_ushort;
प्रकारनिर्देश _Atomic(पूर्णाङ्क) atomic_int;
प्रकारनिर्देश _Atomic(अचिह्नित पूर्णाङ्क) atomic_uint;
प्रकारनिर्देश _Atomic(दीर्घ) atomic_long;
प्रकारनिर्देश _Atomic(अचिह्नित दीर्घ) atomic_ulong;
प्रकारनिर्देश _Atomic(दीर्घ दीर्घ) atomic_llong;
प्रकारनिर्देश _Atomic(अचिह्नित दीर्घ दीर्घ) atomic_ullong;
प्रकारनिर्देश _Atomic(uint_least16_t) atomic_char16_t;
प्रकारनिर्देश _Atomic(uint_least32_t) atomic_char32_t;
प्रकारनिर्देश _Atomic(wchar_t) atomic_wchar_t;
प्रकारनिर्देश _Atomic(int_least8_t) atomic_int_least8_t;
प्रकारनिर्देश _Atomic(uint_least8_t) atomic_uint_least8_t;
प्रकारनिर्देश _Atomic(int_least16_t) atomic_int_least16_t;
प्रकारनिर्देश _Atomic(uint_least16_t) atomic_uint_least16_t;
प्रकारनिर्देश _Atomic(int_least32_t) atomic_int_least32_t;
प्रकारनिर्देश _Atomic(uint_least32_t) atomic_uint_least32_t;
प्रकारनिर्देश _Atomic(int_least64_t) atomic_int_least64_t;
प्रकारनिर्देश _Atomic(uint_least64_t) atomic_uint_least64_t;
प्रकारनिर्देश _Atomic(int_fast8_t) atomic_int_fast8_t;
प्रकारनिर्देश _Atomic(uint_fast8_t) atomic_uint_fast8_t;
प्रकारनिर्देश _Atomic(int_fast16_t) atomic_int_fast16_t;
प्रकारनिर्देश _Atomic(uint_fast16_t) atomic_uint_fast16_t;
प्रकारनिर्देश _Atomic(int_fast32_t) atomic_int_fast32_t;
प्रकारनिर्देश _Atomic(uint_fast32_t) atomic_uint_fast32_t;
प्रकारनिर्देश _Atomic(int_fast64_t) atomic_int_fast64_t;
प्रकारनिर्देश _Atomic(uint_fast64_t) atomic_uint_fast64_t;
प्रकारनिर्देश _Atomic(intptr_t) atomic_intptr_t;
प्रकारनिर्देश _Atomic(uintptr_t) atomic_uintptr_t;
प्रकारनिर्देश _Atomic(आकार_t) atomic_size_t;
प्रकारनिर्देश _Atomic(ptrdiff_t) atomic_ptrdiff_t;
प्रकारनिर्देश _Atomic(intmax_t) atomic_intmax_t;
प्रकारनिर्देश _Atomic(uintmax_t) atomic_uintmax_t;

/* Atomic flag */
प्रकारनिर्देश संरचना {
    atomic_bool मानम्;
} atomic_flag;

#परिभाषय ATOMIC_FLAG_INIT {0}
#परिभाषय ATOMIC_VAR_INIT(मानम्) (मानम्)

/* Generic routines */
#परिभाषय atomic_init(object, desired)                                      \
    atomic_store_explicit(object, desired, __ATOMIC_RELAXED)

#परिभाषय __atomic_store_n(ptr, val, क्रमः)                                 \
    ({ __typeof__ ((शून्य)0, *(ptr)) __val = (val);                      \
       __atomic_store((ptr), &__val, (क्रमः)); })
#परिभाषय atomic_store_explicit(object, desired, क्रमः)                     \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = (desired);                                 \
       __atomic_store (ptr, &tmp, (क्रमः));                               \
    })
#परिभाषय atomic_store(object, desired)                                     \
     atomic_store_explicit (object, desired, __ATOMIC_SEQ_CST)

#परिभाषय __atomic_load_n(ptr, क्रमः)                                       \
    ({ typeof(*(ptr)) __val;                                              \
       __atomic_load((ptr), &__val, (क्रमः));                             \
       __val; })
#परिभाषय atomic_load_explicit(object, क्रमः)                               \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ ((शून्य)0,*ptr) tmp;                                             \
       __atomic_load (ptr, &tmp, (क्रमः));                                \
       tmp;                                                               \
    })
#परिभाषय atomic_load(object) atomic_load_explicit (object, __ATOMIC_SEQ_CST)

#परिभाषय atomic_exchange_explicit(object, desired, क्रमः)                  \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) val = (desired);                                 \
       __typeof__ (*ptr) tmp;                                             \
       __atomic_exchange (ptr, &val, &tmp, (क्रमः));                      \
       tmp;                                                               \
    })
#परिभाषय atomic_exchange(object, desired)                                  \
  atomic_exchange_explicit (object, desired, __ATOMIC_SEQ_CST)
#परिभाषय __atomic_compare_exchange_n(ptr, expected, desired, weak, success, failure) \
    ({ typeof(*(ptr)) __desired = (desired);                              \
       __atomic_compare_exchange((ptr), (expected), &__desired,          \
         (weak), (success), (failure)); })
#परिभाषय atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 0, success, failure); \
    })
#परिभाषय atomic_compare_exchange_strong(object, expected, desired)         \
    atomic_compare_exchange_strong_explicit (object, expected, desired,   \
                                             __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)
#परिभाषय atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    ({ __typeof__ (object) ptr = (object);                                \
       __typeof__ (*ptr) tmp = desired;                                   \
       __atomic_compare_exchange(ptr, expected, &tmp, 1, success, failure); \
    })
#परिभाषय atomic_compare_exchange_weak(object, expected, desired)           \
    atomic_compare_exchange_weak_explicit (object, expected, desired,     \
                                           __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#परिभाषय atomic_fetch_add(object, सङ्कार्यम्_2) \
    __atomic_fetch_add(object, सङ्कार्यम्_2, __ATOMIC_SEQ_CST)
#परिभाषय atomic_fetch_add_explicit __atomic_fetch_add

#परिभाषय atomic_fetch_sub(object, सङ्कार्यम्_2) \
    __atomic_fetch_sub(object, सङ्कार्यम्_2, __ATOMIC_SEQ_CST)
#परिभाषय atomic_fetch_sub_explicit __atomic_fetch_sub

#परिभाषय atomic_fetch_or(object, सङ्कार्यम्_2) \
    __atomic_fetch_or(object, सङ्कार्यम्_2, __ATOMIC_SEQ_CST)
#परिभाषय atomic_fetch_or_explicit __atomic_fetch_or

#परिभाषय atomic_fetch_xor(object, सङ्कार्यम्_2) \
    __atomic_fetch_xor(object, सङ्कार्यम्_2, __ATOMIC_SEQ_CST)
#परिभाषय atomic_fetch_xor_explicit __atomic_fetch_xor

#परिभाषय atomic_fetch_and(object, सङ्कार्यम्_2) \
    __atomic_fetch_and(object, सङ्कार्यम्_2, __ATOMIC_SEQ_CST)
#परिभाषय atomic_fetch_and_explicit __atomic_fetch_and

बाह्य शून्य atomic_thread_fence (memory_order);
#परिभाषय __atomic_thread_fence(क्रमः) atomic_thread_fence (क्रमः)
बाह्य शून्य atomic_signal_fence (memory_order);
#परिभाषय __atomic_signal_fence(क्रमः) atomic_signal_fence(क्रमः)
बाह्य bool __atomic_is_lock_free(आकार_t आकार, शून्य *ptr);
#परिभाषय atomic_is_lock_free(OBJ) __atomic_is_lock_free (परिमाण (*(OBJ)), (OBJ))

बाह्य bool atomic_flag_test_and_set(शून्य *object);
बाह्य bool atomic_flag_test_and_set_explicit(शून्य *object, memory_order क्रमः);
बाह्य शून्य atomic_flag_clear(शून्य *object);
बाह्य शून्य atomic_flag_clear_explicit(शून्य *object, memory_order क्रमः);
#यदि_अन्तः /* _STDATOMIC_H */
