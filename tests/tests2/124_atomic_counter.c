#অন্তর্ভাব <stddef.h>
#অন্তর্ভাব <stdint.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব "threads.h"
#অন্তর্ভাব <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    করো { \
        যদি (!!(COND)) \
            abort(); \
    } যখন (0)

প্রকারলেখ কাঠামো {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} গণক_type;

স্থির
শূন্য *adder_simple(শূন্য *arg)
{
    আকার_t step;
    গণক_type *গণক = arg;

    জন্য (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&গণক->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&গণক->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&গণক->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&গণক->ul, 1, memory_order_relaxed);
    }

    ফেরত ফাঁকা;
}

স্থির
শূন্য *adder_cmpxchg(শূন্য *arg)
{
    আকার_t step;
    গণক_type *গণক = arg;

    জন্য (step = 0; step < NR_STEPS; ++step) {
        unsigned অক্ষর xchgc;
        unsigned short xchgs;
        unsigned পূর্ণসংখ্যা xchgi;
        আকার_t xchgl;
        unsigned অক্ষর cmpc = atomic_load_explicit(&গণক->uc, memory_order_relaxed);
        unsigned short cmps = atomic_load_explicit(&গণক->us, memory_order_relaxed);
        unsigned পূর্ণসংখ্যা cmpi = atomic_load_explicit(&গণক->ui, memory_order_relaxed);
        আকার_t cmpl = atomic_load_explicit(&গণক->ul, memory_order_relaxed);

        করো {
            xchgc = (cmpc + 1);
        } যখন (!atomic_compare_exchange_strong_explicit(&গণক->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        করো {
            xchgs = (cmps + 1);
        } যখন (!atomic_compare_exchange_strong_explicit(&গণক->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        করো {
            xchgi = (cmpi + 1);
        } যখন (!atomic_compare_exchange_strong_explicit(&গণক->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        করো {
            xchgl = (cmpl + 1);
        } যখন (!atomic_compare_exchange_strong_explicit(&গণক->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    ফেরত ফাঁকা;
}

স্থির
শূন্য *adder_test_and_set(শূন্য *arg)
{
    আকার_t step;
    গণক_type *গণক = arg;

    জন্য (step = 0; step < NR_STEPS; ++step) {
        যখন (atomic_flag_test_and_set(&গণক->flag));
        ++গণক->uc;
        ++গণক->us;
        ++গণক->ui;
        ++গণক->ul;
        atomic_flag_clear(&গণক->flag);
    }

    ফেরত ফাঁকা;
}

স্থির
শূন্য atomic_গণক_test(শূন্য *(*adder)(শূন্য *arg))
{
    আকার_t সূচক;
    গণক_type গণক;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&গণক.flag);
    atomic_init(&গণক.uc, 0);
    atomic_init(&গণক.us, 0);
    atomic_init(&গণক.ui, 0);
    atomic_init(&গণক.ul, 0);

    জন্য (সূচক = 0; সূচক < NR_THREADS; ++সূচক)
        BUG_ON(pthread_create(&thread[সূচক], ফাঁকা, adder, (শূন্য *)&গণক));

    জন্য (সূচক = 0; সূচক < NR_THREADS; ++সূচক)
        BUG_ON(pthread_join(thread[সূচক], ফাঁকা));

    যদি (atomic_load(&গণক.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&গণক.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&গণক.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&গণক.ul) == (NR_THREADS * NR_STEPS)
        )
        printf("SUCCESS\n");
    অন্যথা
        printf("FAILURE\n");
}

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    atomic_গণক_test(adder_simple);
    atomic_গণক_test(adder_cmpxchg);
    atomic_গণক_test(adder_test_and_set);

    ফেরত 0;
}
