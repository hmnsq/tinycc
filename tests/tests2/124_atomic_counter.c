#ಅನ್ತರ್ಭಾವ <stddef.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ "threads.h"
#ಅನ್ತರ್ಭಾವ <stdatomic.h>

#ವ್ಯಾಖ್ಯಾನಿಸು NR_ಎಳೆಗಳು 16
#ವ್ಯಾಖ್ಯಾನಿಸು NR_ಹೆಜ್ಜೆಗಳು 10000

#ವ್ಯಾಖ್ಯಾನಿಸು BUG_ON(COND) \
    ಮಾಡು { \
        ಆದರೆ (!!(COND)) \
            abort(); \
    } ಆಗ (0)

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

ಸ್ಥಿರ
ಶೂನ್ಯ *adder_simple(ಶೂನ್ಯ *arg)
{
    ಗಾತ್ರ_t ಹೆಜ್ಜೆ;
    counter_type *counter = arg;

    ಗಾಗಿ (ಹೆಜ್ಜೆ = 0; ಹೆಜ್ಜೆ < NR_ಹೆಜ್ಜೆಗಳು; ++ಹೆಜ್ಜೆ) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಸ್ಥಿರ
ಶೂನ್ಯ *adder_cmpxchg(ಶೂನ್ಯ *arg)
{
    ಗಾತ್ರ_t ಹೆಜ್ಜೆ;
    counter_type *counter = arg;

    ಗಾಗಿ (ಹೆಜ್ಜೆ = 0; ಹೆಜ್ಜೆ < NR_ಹೆಜ್ಜೆಗಳು; ++ಹೆಜ್ಜೆ) {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ xchgc;
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ xchgs;
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ xchgi;
        ಗಾತ್ರ_t xchgl;
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        ಗಾತ್ರ_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        ಮಾಡು {
            xchgc = (cmpc + 1);
        } ಆಗ (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        ಮಾಡು {
            xchgs = (cmps + 1);
        } ಆಗ (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        ಮಾಡು {
            xchgi = (cmpi + 1);
        } ಆಗ (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        ಮಾಡು {
            xchgl = (cmpl + 1);
        } ಆಗ (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಸ್ಥಿರ
ಶೂನ್ಯ *adder_test_and_ಗಣ(ಶೂನ್ಯ *arg)
{
    ಗಾತ್ರ_t ಹೆಜ್ಜೆ;
    counter_type *counter = arg;

    ಗಾಗಿ (ಹೆಜ್ಜೆ = 0; ಹೆಜ್ಜೆ < NR_ಹೆಜ್ಜೆಗಳು; ++ಹೆಜ್ಜೆ) {
        ಆಗ (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಸ್ಥಿರ
ಶೂನ್ಯ atomic_counter_test(ಶೂನ್ಯ *(*adder)(ಶೂನ್ಯ *arg))
{
    ಗಾತ್ರ_t ಸೂಚ್ಯಂಕ;
    counter_type counter;
    pthread_t thread[NR_ಎಳೆಗಳು];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    ಗಾಗಿ (ಸೂಚ್ಯಂಕ = 0; ಸೂಚ್ಯಂಕ < NR_ಎಳೆಗಳು; ++ಸೂಚ್ಯಂಕ)
        BUG_ON(pthread_create(&thread[ಸೂಚ್ಯಂಕ], ಖಾಲಿ, adder, (ಶೂನ್ಯ *)&counter));

    ಗಾಗಿ (ಸೂಚ್ಯಂಕ = 0; ಸೂಚ್ಯಂಕ < NR_ಎಳೆಗಳು; ++ಸೂಚ್ಯಂಕ)
        BUG_ON(pthread_join(thread[ಸೂಚ್ಯಂಕ], ಖಾಲಿ));

    ಆದರೆ (atomic_load(&counter.uc) == ((NR_ಎಳೆಗಳು * NR_ಹೆಜ್ಜೆಗಳು) & 0xffu)
        && atomic_load(&counter.us) == ((NR_ಎಳೆಗಳು * NR_ಹೆಜ್ಜೆಗಳು) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_ಎಳೆಗಳು * NR_ಹೆಜ್ಜೆಗಳು)
        && atomic_load(&counter.ul) == (NR_ಎಳೆಗಳು * NR_ಹೆಜ್ಜೆಗಳು)
        )
        ಬರೆ("SUCCESS\n");
    ಇಲ್ಲದಿದ್ದರೆ
        ಬರೆ("FAILURE\n");
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_ಗಣ);

    ಹಿಂತಿರುಗಿ 0;
}
