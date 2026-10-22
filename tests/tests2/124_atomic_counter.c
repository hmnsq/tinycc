#ضمن <stddef.h>
#ضمن <stdint.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن "threads.h"
#ضمن <stdatomic.h>

#تعریف_کړه NR_تارونه 16
#تعریف_کړه NR_ګامونه 10000

#تعریف_کړه BUG_ON(COND) \
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
    اندازه_t ګام;
    counter_type *counter = arg;

    لكل (ګام = 0; ګام < NR_ګامونه; ++ګام) {
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
    اندازه_t ګام;
    counter_type *counter = arg;

    لكل (ګام = 0; ګام < NR_ګامونه; ++ګام) {
        بینښه حرف xchgc;
        بینښه لنډ xchgs;
        بینښه صحيح xchgi;
        اندازه_t xchgl;
        بینښه حرف cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        بینښه لنډ cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        بینښه صحيح cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        اندازه_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

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
فراغ *adder_test_and_سېټ(فراغ *arg)
{
    اندازه_t ګام;
    counter_type *counter = arg;

    لكل (ګام = 0; ګام < NR_ګامونه; ++ګام) {
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
    اندازه_t شاخص;
    counter_type counter;
    pthread_t thread[NR_تارونه];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    لكل (شاخص = 0; شاخص < NR_تارونه; ++شاخص)
        BUG_ON(pthread_create(&thread[شاخص], عدم, adder, (فراغ *)&counter));

    لكل (شاخص = 0; شاخص < NR_تارونه; ++شاخص)
        BUG_ON(pthread_join(thread[شاخص], عدم));

    إذا (atomic_load(&counter.uc) == ((NR_تارونه * NR_ګامونه) & 0xffu)
        && atomic_load(&counter.us) == ((NR_تارونه * NR_ګامونه) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_تارونه * NR_ګامونه)
        && atomic_load(&counter.ul) == (NR_تارونه * NR_ګامونه)
        )
        چاپ_کړه("SUCCESS\n");
    وإلا
        چاپ_کړه("FAILURE\n");
}

صحيح اصلي(فراغ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_سېټ);

    أرجع 0;
}
