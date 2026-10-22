#ಅನ್ತರ್ಭಾವ <stddef.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ "threads.h"
#ಅನ್ತರ್ಭಾವ <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    ಕುರು { \
        ಯದಿ (!!(COND)) \
            abort(); \
    } ಯಾವತ್ (0)

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

ಸ್ಥಿರ
ಶೂನ್ಯ *adder_simple(ಶೂನ್ಯ *arg)
{
    size_t step;
    counter_type *counter = arg;

    ಪ್ರತಿ (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಸ್ಥಿರ
ಶೂನ್ಯ *adder_cmpxchg(ಶೂನ್ಯ *arg)
{
    size_t step;
    counter_type *counter = arg;

    ಪ್ರತಿ (step = 0; step < NR_STEPS; ++step) {
        unsigned ವರ್ಣ xchgc;
        unsigned short xchgs;
        unsigned ಪೂರ್ಣಾಙ್ಕ xchgi;
        size_t xchgl;
        unsigned ವರ್ಣ cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        unsigned ಪೂರ್ಣಾಙ್ಕ cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        size_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        ಕುರು {
            xchgc = (cmpc + 1);
        } ಯಾವತ್ (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        ಕುರು {
            xchgs = (cmps + 1);
        } ಯಾವತ್ (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        ಕುರು {
            xchgi = (cmpi + 1);
        } ಯಾವತ್ (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        ಕುರು {
            xchgl = (cmpl + 1);
        } ಯಾವತ್ (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಸ್ಥಿರ
ಶೂನ್ಯ *adder_test_and_set(ಶೂನ್ಯ *arg)
{
    size_t step;
    counter_type *counter = arg;

    ಪ್ರತಿ (step = 0; step < NR_STEPS; ++step) {
        ಯಾವತ್ (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಸ್ಥಿರ
ಶೂನ್ಯ atomic_counter_test(ಶೂನ್ಯ *(*adder)(ಶೂನ್ಯ *arg))
{
    size_t index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    ಪ್ರತಿ (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], ರಿಕ್ತ, adder, (ಶೂನ್ಯ *)&counter));

    ಪ್ರತಿ (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], ರಿಕ್ತ));

    ಯದಿ (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    ಅನ್ಯಥಾ
        printf("FAILURE\n");
}

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    ಪ್ರತ್ಯಾಗಮ 0;
}
