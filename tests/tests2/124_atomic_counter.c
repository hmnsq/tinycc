#ضمن <stddef.h>
#ضمن <stdint.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن "threads.h"
#ضمن <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    افعل { \
        إذا (!!(COND)) \
            abort(); \
    } طالما (0)

تعريفنوع بنية {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

ساكن
فراغ *adder_simple(فراغ *arg)
{
    size_t step;
    counter_type *counter = arg;

    لكل (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    أرجع عدم;
}

ساكن
فراغ *adder_cmpxchg(فراغ *arg)
{
    size_t step;
    counter_type *counter = arg;

    لكل (step = 0; step < NR_STEPS; ++step) {
        unsigned حرف xchgc;
        unsigned short xchgs;
        unsigned صحيح xchgi;
        size_t xchgl;
        unsigned حرف cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        unsigned صحيح cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        size_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        افعل {
            xchgc = (cmpc + 1);
        } طالما (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        افعل {
            xchgs = (cmps + 1);
        } طالما (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        افعل {
            xchgi = (cmpi + 1);
        } طالما (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        افعل {
            xchgl = (cmpl + 1);
        } طالما (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    أرجع عدم;
}

ساكن
فراغ *adder_test_and_set(فراغ *arg)
{
    size_t step;
    counter_type *counter = arg;

    لكل (step = 0; step < NR_STEPS; ++step) {
        طالما (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    أرجع عدم;
}

ساكن
فراغ atomic_counter_test(فراغ *(*adder)(فراغ *arg))
{
    size_t index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    لكل (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], عدم, adder, (فراغ *)&counter));

    لكل (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], عدم));

    إذا (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    وإلا
        printf("FAILURE\n");
}

صحيح main(فراغ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    أرجع 0;
}
