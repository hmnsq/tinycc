#ਅਨ੍ਤਰ੍ਭਾਵ <stddef.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ "threads.h"
#ਅਨ੍ਤਰ੍ਭਾਵ <stdatomic.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NR_ਧਾਗੇ 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NR_ਕਦਮਾਂ 10000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BUG_ON(COND) \
    ਕਰੋ { \
        ਜੇ (!!(COND)) \
            abort(); \
    } ਜਦੋਂ (0)

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

ਸਥਿਰ
ਖਾਲੀ *adder_simple(ਖਾਲੀ *arg)
{
    ਮਾਪ_t ਕਦਮ;
    counter_type *counter = arg;

    ਲਈ (ਕਦਮ = 0; ਕਦਮ < NR_ਕਦਮਾਂ; ++ਕਦਮ) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    ਵਾਪਸ ਨਿਰਾ;
}

ਸਥਿਰ
ਖਾਲੀ *adder_cmpxchg(ਖਾਲੀ *arg)
{
    ਮਾਪ_t ਕਦਮ;
    counter_type *counter = arg;

    ਲਈ (ਕਦਮ = 0; ਕਦਮ < NR_ਕਦਮਾਂ; ++ਕਦਮ) {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ xchgc;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ xchgs;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ xchgi;
        ਮਾਪ_t xchgl;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        ਮਾਪ_t cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        ਕਰੋ {
            xchgc = (cmpc + 1);
        } ਜਦੋਂ (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        ਕਰੋ {
            xchgs = (cmps + 1);
        } ਜਦੋਂ (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        ਕਰੋ {
            xchgi = (cmpi + 1);
        } ਜਦੋਂ (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        ਕਰੋ {
            xchgl = (cmpl + 1);
        } ਜਦੋਂ (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    ਵਾਪਸ ਨਿਰਾ;
}

ਸਥਿਰ
ਖਾਲੀ *adder_test_and_ਸੈੱਟ(ਖਾਲੀ *arg)
{
    ਮਾਪ_t ਕਦਮ;
    counter_type *counter = arg;

    ਲਈ (ਕਦਮ = 0; ਕਦਮ < NR_ਕਦਮਾਂ; ++ਕਦਮ) {
        ਜਦੋਂ (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    ਵਾਪਸ ਨਿਰਾ;
}

ਸਥਿਰ
ਖਾਲੀ atomic_counter_test(ਖਾਲੀ *(*adder)(ਖਾਲੀ *arg))
{
    ਮਾਪ_t ਸੂਚਕਾਂਕ;
    counter_type counter;
    pthread_t thread[NR_ਧਾਗੇ];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    ਲਈ (ਸੂਚਕਾਂਕ = 0; ਸੂਚਕਾਂਕ < NR_ਧਾਗੇ; ++ਸੂਚਕਾਂਕ)
        BUG_ON(pthread_create(&thread[ਸੂਚਕਾਂਕ], ਨਿਰਾ, adder, (ਖਾਲੀ *)&counter));

    ਲਈ (ਸੂਚਕਾਂਕ = 0; ਸੂਚਕਾਂਕ < NR_ਧਾਗੇ; ++ਸੂਚਕਾਂਕ)
        BUG_ON(pthread_join(thread[ਸੂਚਕਾਂਕ], ਨਿਰਾ));

    ਜੇ (atomic_load(&counter.uc) == ((NR_ਧਾਗੇ * NR_ਕਦਮਾਂ) & 0xffu)
        && atomic_load(&counter.us) == ((NR_ਧਾਗੇ * NR_ਕਦਮਾਂ) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_ਧਾਗੇ * NR_ਕਦਮਾਂ)
        && atomic_load(&counter.ul) == (NR_ਧਾਗੇ * NR_ਕਦਮਾਂ)
        )
        ਲਿਖੋ("SUCCESS\n");
    ਨਹੀਂਤਾਂ
        ਲਿਖੋ("FAILURE\n");
}

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_ਸੈੱਟ);

    ਵਾਪਸ 0;
}
