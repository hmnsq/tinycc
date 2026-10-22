#ضمن <stddef.h>
#ضمن <stdint.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن "threads.h"
#ضمن <stdatomic.h>

#تعریف_کرو NR_دھاگے 16
#تعریف_کرو NR_قدماں 10000

#تعریف_کرو BUG_ON(COND) \
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
    ناپ_t قدم;
    counter_type *counter = arg;

    لكل (قدم = 0; قدم < NR_قدماں; ++قدم) {
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
    ناپ_t قدم;
    counter_type *counter = arg;

    لكل (قدم = 0; قدم < NR_قدماں; ++قدم) {
        بنانشانی حرف xchgc;
        بنانشانی چھوٹا xchgs;
        بنانشانی صحيح xchgi;
        ناپ_t xchgl;
        بنانشانی حرف cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        بنانشانی چھوٹا cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        بنانشانی صحيح cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        ناپ_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

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
فراغ *adder_test_and_سیٹ(فراغ *arg)
{
    ناپ_t قدم;
    counter_type *counter = arg;

    لكل (قدم = 0; قدم < NR_قدماں; ++قدم) {
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
    ناپ_t اشاریہ;
    counter_type counter;
    pthread_t thread[NR_دھاگے];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    لكل (اشاریہ = 0; اشاریہ < NR_دھاگے; ++اشاریہ)
        BUG_ON(pthread_create(&thread[اشاریہ], عدم, adder, (فراغ *)&counter));

    لكل (اشاریہ = 0; اشاریہ < NR_دھاگے; ++اشاریہ)
        BUG_ON(pthread_join(thread[اشاریہ], عدم));

    إذا (atomic_load(&counter.uc) == ((NR_دھاگے * NR_قدماں) & 0xffu)
        && atomic_load(&counter.us) == ((NR_دھاگے * NR_قدماں) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_دھاگے * NR_قدماں)
        && atomic_load(&counter.ul) == (NR_دھاگے * NR_قدماں)
        )
        لکھو("SUCCESS\n");
    وإلا
        لکھو("FAILURE\n");
}

صحيح مکھ(فراغ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_سیٹ);

    أرجع 0;
}
