#అన్తర్భావ <stddef.h>
#అన్తర్భావ <stdint.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ "threads.h"
#అన్తర్భావ <stdatomic.h>

#నిర్వచించు NR_దారాలు 16
#నిర్వచించు NR_అడుగులు 10000

#నిర్వచించు BUG_ON(COND) \
    చేయి { \
        ఒకవేళ (!!(COND)) \
            abort(); \
    } అయితే (0)

రకనిర్వచనం నిర్మాణం {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

స్థిర
శూన్య *adder_simple(శూన్య *arg)
{
    కొలత_t అడుగు;
    counter_type *counter = arg;

    కొరకు (అడుగు = 0; అడుగు < NR_అడుగులు; ++అడుగు) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    తిరిగి ఖాళీ;
}

స్థిర
శూన్య *adder_cmpxchg(శూన్య *arg)
{
    కొలత_t అడుగు;
    counter_type *counter = arg;

    కొరకు (అడుగు = 0; అడుగు < NR_అడుగులు; ++అడుగు) {
        గుర్తులేని అక్షరం xchgc;
        గుర్తులేని పొట్టి xchgs;
        గుర్తులేని పూర్ణాంకం xchgi;
        కొలత_t xchgl;
        గుర్తులేని అక్షరం cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        గుర్తులేని పొట్టి cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        గుర్తులేని పూర్ణాంకం cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        కొలత_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        చేయి {
            xchgc = (cmpc + 1);
        } అయితే (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        చేయి {
            xchgs = (cmps + 1);
        } అయితే (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        చేయి {
            xchgi = (cmpi + 1);
        } అయితే (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        చేయి {
            xchgl = (cmpl + 1);
        } అయితే (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    తిరిగి ఖాళీ;
}

స్థిర
శూన్య *adder_test_and_సమితి(శూన్య *arg)
{
    కొలత_t అడుగు;
    counter_type *counter = arg;

    కొరకు (అడుగు = 0; అడుగు < NR_అడుగులు; ++అడుగు) {
        అయితే (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    తిరిగి ఖాళీ;
}

స్థిర
శూన్య atomic_counter_test(శూన్య *(*adder)(శూన్య *arg))
{
    కొలత_t సూచీ;
    counter_type counter;
    pthread_t thread[NR_దారాలు];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    కొరకు (సూచీ = 0; సూచీ < NR_దారాలు; ++సూచీ)
        BUG_ON(pthread_create(&thread[సూచీ], ఖాళీ, adder, (శూన్య *)&counter));

    కొరకు (సూచీ = 0; సూచీ < NR_దారాలు; ++సూచీ)
        BUG_ON(pthread_join(thread[సూచీ], ఖాళీ));

    ఒకవేళ (atomic_load(&counter.uc) == ((NR_దారాలు * NR_అడుగులు) & 0xffu)
        && atomic_load(&counter.us) == ((NR_దారాలు * NR_అడుగులు) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_దారాలు * NR_అడుగులు)
        && atomic_load(&counter.ul) == (NR_దారాలు * NR_అడుగులు)
        )
        రాయి("SUCCESS\n");
    లేకపోతే
        రాయి("FAILURE\n");
}

పూర్ణాంకం ప్రధాన(శూన్య)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_సమితి);

    తిరిగి 0;
}
