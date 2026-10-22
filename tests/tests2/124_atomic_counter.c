#അന്തര്ഭാവ <stddef.h>
#അന്തര്ഭാവ <stdint.h>
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ "threads.h"
#അന്തര്ഭാവ <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    ചെയ്യുക { \
        എങ്കിൽ (!!(COND)) \
            abort(); \
    } ആകുമ്പോൾ (0)

തരനിർവചനം ഘടന {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

സ്ഥിതം
ശൂന്യം *adder_simple(ശൂന്യം *arg)
{
    size_t step;
    counter_type *counter = arg;

    വേണ്ടി (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    തിരികെ ശൂന്യ;
}

സ്ഥിതം
ശൂന്യം *adder_cmpxchg(ശൂന്യം *arg)
{
    size_t step;
    counter_type *counter = arg;

    വേണ്ടി (step = 0; step < NR_STEPS; ++step) {
        unsigned അക്ഷരം xchgc;
        unsigned short xchgs;
        unsigned പൂർണ്ണസംഖ്യ xchgi;
        size_t xchgl;
        unsigned അക്ഷരം cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        unsigned പൂർണ്ണസംഖ്യ cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        size_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        ചെയ്യുക {
            xchgc = (cmpc + 1);
        } ആകുമ്പോൾ (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        ചെയ്യുക {
            xchgs = (cmps + 1);
        } ആകുമ്പോൾ (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        ചെയ്യുക {
            xchgi = (cmpi + 1);
        } ആകുമ്പോൾ (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        ചെയ്യുക {
            xchgl = (cmpl + 1);
        } ആകുമ്പോൾ (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    തിരികെ ശൂന്യ;
}

സ്ഥിതം
ശൂന്യം *adder_test_and_set(ശൂന്യം *arg)
{
    size_t step;
    counter_type *counter = arg;

    വേണ്ടി (step = 0; step < NR_STEPS; ++step) {
        ആകുമ്പോൾ (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    തിരികെ ശൂന്യ;
}

സ്ഥിതം
ശൂന്യം atomic_counter_test(ശൂന്യം *(*adder)(ശൂന്യം *arg))
{
    size_t index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    വേണ്ടി (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], ശൂന്യ, adder, (ശൂന്യം *)&counter));

    വേണ്ടി (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], ശൂന്യ));

    എങ്കിൽ (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    അല്ലെങ്കിൽ
        printf("FAILURE\n");
}

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    തിരികെ 0;
}
