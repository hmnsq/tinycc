#અન્તર્ભાવ <stddef.h>
#અન્તર્ભાવ <stdint.h>
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ "threads.h"
#અન્તર્ભાવ <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    કરો { \
        જો (!!(COND)) \
            abort(); \
    } જ્યારે (0)

પ્રકારવ્યાખ્યા સંરચના {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

સ્થિર
શૂન્ય *adder_simple(શૂન્ય *arg)
{
    size_t step;
    counter_type *counter = arg;

    માટે (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    પાછા ખાલી;
}

સ્થિર
શૂન્ય *adder_cmpxchg(શૂન્ય *arg)
{
    size_t step;
    counter_type *counter = arg;

    માટે (step = 0; step < NR_STEPS; ++step) {
        unsigned અક્ષર xchgc;
        unsigned short xchgs;
        unsigned પૂર્ણાંક xchgi;
        size_t xchgl;
        unsigned અક્ષર cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        unsigned પૂર્ણાંક cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        size_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        કરો {
            xchgc = (cmpc + 1);
        } જ્યારે (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        કરો {
            xchgs = (cmps + 1);
        } જ્યારે (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        કરો {
            xchgi = (cmpi + 1);
        } જ્યારે (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        કરો {
            xchgl = (cmpl + 1);
        } જ્યારે (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    પાછા ખાલી;
}

સ્થિર
શૂન્ય *adder_test_and_set(શૂન્ય *arg)
{
    size_t step;
    counter_type *counter = arg;

    માટે (step = 0; step < NR_STEPS; ++step) {
        જ્યારે (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    પાછા ખાલી;
}

સ્થિર
શૂન્ય atomic_counter_test(શૂન્ય *(*adder)(શૂન્ય *arg))
{
    size_t index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    માટે (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], ખાલી, adder, (શૂન્ય *)&counter));

    માટે (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], ખાલી));

    જો (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    નહીંતર
        printf("FAILURE\n");
}

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    પાછા 0;
}
