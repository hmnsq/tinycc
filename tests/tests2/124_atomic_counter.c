#ଅନ୍ତର୍ଭାଵ <stddef.h>
#ଅନ୍ତର୍ଭାଵ <stdint.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ "threads.h"
#ଅନ୍ତର୍ଭାଵ <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    କର { \
        ଯଦି (!!(COND)) \
            abort(); \
    } ଯେତେବେଳେ (0)

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

ସ୍ଥିର
ଶୂନ୍ୟ *adder_simple(ଶୂନ୍ୟ *arg)
{
    size_t step;
    counter_type *counter = arg;

    ପାଇଁ (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    ଫେରନ୍ତୁ ଖାଲି;
}

ସ୍ଥିର
ଶୂନ୍ୟ *adder_cmpxchg(ଶୂନ୍ୟ *arg)
{
    size_t step;
    counter_type *counter = arg;

    ପାଇଁ (step = 0; step < NR_STEPS; ++step) {
        unsigned ଅକ୍ଷର xchgc;
        unsigned short xchgs;
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା xchgi;
        size_t xchgl;
        unsigned ଅକ୍ଷର cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        size_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        କର {
            xchgc = (cmpc + 1);
        } ଯେତେବେଳେ (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        କର {
            xchgs = (cmps + 1);
        } ଯେତେବେଳେ (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        କର {
            xchgi = (cmpi + 1);
        } ଯେତେବେଳେ (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        କର {
            xchgl = (cmpl + 1);
        } ଯେତେବେଳେ (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    ଫେରନ୍ତୁ ଖାଲି;
}

ସ୍ଥିର
ଶୂନ୍ୟ *adder_test_and_set(ଶୂନ୍ୟ *arg)
{
    size_t step;
    counter_type *counter = arg;

    ପାଇଁ (step = 0; step < NR_STEPS; ++step) {
        ଯେତେବେଳେ (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    ଫେରନ୍ତୁ ଖାଲି;
}

ସ୍ଥିର
ଶୂନ୍ୟ atomic_counter_test(ଶୂନ୍ୟ *(*adder)(ଶୂନ୍ୟ *arg))
{
    size_t index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    ପାଇଁ (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], ଖାଲି, adder, (ଶୂନ୍ୟ *)&counter));

    ପାଇଁ (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], ଖାଲି));

    ଯଦି (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    ଅନ୍ୟଥା
        printf("FAILURE\n");
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    ଫେରନ୍ତୁ 0;
}
