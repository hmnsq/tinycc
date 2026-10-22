#அந்தர்பாவ <stddef.h>
#அந்தர்பாவ <stdint.h>
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ "threads.h"
#அந்தர்பாவ <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    செய் { \
        எனில் (!!(COND)) \
            abort(); \
    } போது (0)

வகைவரை கட்டமைப்பு {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

நிலையான
வெறுமை *adder_simple(வெறுமை *arg)
{
    size_t step;
    counter_type *counter = arg;

    க்கு (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    திரும்பு வெற்று;
}

நிலையான
வெறுமை *adder_cmpxchg(வெறுமை *arg)
{
    size_t step;
    counter_type *counter = arg;

    க்கு (step = 0; step < NR_STEPS; ++step) {
        unsigned எழுத்து xchgc;
        unsigned short xchgs;
        unsigned முழு xchgi;
        size_t xchgl;
        unsigned எழுத்து cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        unsigned முழு cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        size_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        செய் {
            xchgc = (cmpc + 1);
        } போது (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        செய் {
            xchgs = (cmps + 1);
        } போது (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        செய் {
            xchgi = (cmpi + 1);
        } போது (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        செய் {
            xchgl = (cmpl + 1);
        } போது (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    திரும்பு வெற்று;
}

நிலையான
வெறுமை *adder_test_and_set(வெறுமை *arg)
{
    size_t step;
    counter_type *counter = arg;

    க்கு (step = 0; step < NR_STEPS; ++step) {
        போது (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    திரும்பு வெற்று;
}

நிலையான
வெறுமை atomic_counter_test(வெறுமை *(*adder)(வெறுமை *arg))
{
    size_t index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    க்கு (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], வெற்று, adder, (வெறுமை *)&counter));

    க்கு (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], வெற்று));

    எனில் (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    இல்லையெனில்
        printf("FAILURE\n");
}

முழு முதன்மை(வெறுமை)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    திரும்பு 0;
}
