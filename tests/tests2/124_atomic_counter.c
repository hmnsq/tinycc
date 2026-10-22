#অন্তর্ভাব <stddef.h>
#অন্তর্ভাব <stdint.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব "threads.h"
#অন্তর্ভাব <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    কুরু { \
        যদি (!!(COND)) \
            abort(); \
    } যাবত্ (0)

প্রকারনির্দেশ সংরচনা {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

স্থির
শূন্য *adder_simple(শূন্য *arg)
{
    size_t step;
    counter_type *counter = arg;

    প্রতি (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    প্রত্যাগম রিক্ত;
}

স্থির
শূন্য *adder_cmpxchg(শূন্য *arg)
{
    size_t step;
    counter_type *counter = arg;

    প্রতি (step = 0; step < NR_STEPS; ++step) {
        unsigned বর্ণ xchgc;
        unsigned short xchgs;
        unsigned পূর্ণাঙ্ক xchgi;
        size_t xchgl;
        unsigned বর্ণ cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        unsigned পূর্ণাঙ্ক cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        size_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        কুরু {
            xchgc = (cmpc + 1);
        } যাবত্ (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        কুরু {
            xchgs = (cmps + 1);
        } যাবত্ (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        কুরু {
            xchgi = (cmpi + 1);
        } যাবত্ (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        কুরু {
            xchgl = (cmpl + 1);
        } যাবত্ (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    প্রত্যাগম রিক্ত;
}

স্থির
শূন্য *adder_test_and_set(শূন্য *arg)
{
    size_t step;
    counter_type *counter = arg;

    প্রতি (step = 0; step < NR_STEPS; ++step) {
        যাবত্ (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    প্রত্যাগম রিক্ত;
}

স্থির
শূন্য atomic_counter_test(শূন্য *(*adder)(শূন্য *arg))
{
    size_t index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    প্রতি (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], রিক্ত, adder, (শূন্য *)&counter));

    প্রতি (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], রিক্ত));

    যদি (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    অন্যথা
        printf("FAILURE\n");
}

পূর্ণাঙ্ক main(শূন্য)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    প্রত্যাগম 0;
}
