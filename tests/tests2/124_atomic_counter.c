#ضمن <stddef.h>
#ضمن <stdint.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن "threads.h"
#ضمن <stdatomic.h>

#وصف_ڪريو NR_ڌاڳا 16
#وصف_ڪريو NR_قدمن 10000

#وصف_ڪريو BUG_ON(COND) \
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
    سائيز_t قدم;
    counter_type *counter = arg;

    لكل (قدم = 0; قدم < NR_قدمن; ++قدم) {
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
    سائيز_t قدم;
    counter_type *counter = arg;

    لكل (قدم = 0; قدم < NR_قدمن; ++قدم) {
        بنانشان حرف xchgc;
        بنانشان ننڍو xchgs;
        بنانشان صحيح xchgi;
        سائيز_t xchgl;
        بنانشان حرف cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        بنانشان ننڍو cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        بنانشان صحيح cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        سائيز_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

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
فراغ *adder_test_and_سيٽ(فراغ *arg)
{
    سائيز_t قدم;
    counter_type *counter = arg;

    لكل (قدم = 0; قدم < NR_قدمن; ++قدم) {
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
    سائيز_t اشاريو;
    counter_type counter;
    pthread_t thread[NR_ڌاڳا];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    لكل (اشاريو = 0; اشاريو < NR_ڌاڳا; ++اشاريو)
        BUG_ON(pthread_create(&thread[اشاريو], عدم, adder, (فراغ *)&counter));

    لكل (اشاريو = 0; اشاريو < NR_ڌاڳا; ++اشاريو)
        BUG_ON(pthread_join(thread[اشاريو], عدم));

    إذا (atomic_load(&counter.uc) == ((NR_ڌاڳا * NR_قدمن) & 0xffu)
        && atomic_load(&counter.us) == ((NR_ڌاڳا * NR_قدمن) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_ڌاڳا * NR_قدمن)
        && atomic_load(&counter.ul) == (NR_ڌاڳا * NR_قدمن)
        )
        لکو("SUCCESS\n");
    وإلا
        لکو("FAILURE\n");
}

صحيح مکيه(فراغ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_سيٽ);

    أرجع 0;
}
