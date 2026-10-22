#ضمن <stddef.h>
#ضمن <stdint.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن "threads.h"
#ضمن <stdatomic.h>

#تعریف_کن NR_نخها 16
#تعریف_کن NR_گامها 10000

#تعریف_کن BUG_ON(COND) \
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
    اندازه_t گام;
    counter_type *counter = arg;

    لكل (گام = 0; گام < NR_گامها; ++گام) {
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
    اندازه_t گام;
    counter_type *counter = arg;

    لكل (گام = 0; گام < NR_گامها; ++گام) {
        بیعلامت حرف xchgc;
        بیعلامت کوتاه xchgs;
        بیعلامت صحيح xchgi;
        اندازه_t xchgl;
        بیعلامت حرف cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        بیعلامت کوتاه cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        بیعلامت صحيح cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
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
فراغ *adder_test_and_مجموعه(فراغ *arg)
{
    اندازه_t گام;
    counter_type *counter = arg;

    لكل (گام = 0; گام < NR_گامها; ++گام) {
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
    pthread_t thread[NR_نخها];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    لكل (شاخص = 0; شاخص < NR_نخها; ++شاخص)
        BUG_ON(pthread_create(&thread[شاخص], عدم, adder, (فراغ *)&counter));

    لكل (شاخص = 0; شاخص < NR_نخها; ++شاخص)
        BUG_ON(pthread_join(thread[شاخص], عدم));

    إذا (atomic_load(&counter.uc) == ((NR_نخها * NR_گامها) & 0xffu)
        && atomic_load(&counter.us) == ((NR_نخها * NR_گامها) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_نخها * NR_گامها)
        && atomic_load(&counter.ul) == (NR_نخها * NR_گامها)
        )
        چاپ_کن("SUCCESS\n");
    وإلا
        چاپ_کن("FAILURE\n");
}

صحيح اصلی(فراغ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_مجموعه);

    أرجع 0;
}
