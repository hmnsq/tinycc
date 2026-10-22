#شامل <stddef.h>
#شامل <stdint.h>
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل "threads.h"
#شامل <stdatomic.h>

#تعریف_کرو NR_دھاگے 16
#تعریف_کرو NR_اقدام 10000

#تعریف_کرو BUG_ON(COND) \
    کرو { \
        اگر (!!(COND)) \
            abort(); \
    } جب (0)

قسمتعریف ساخت {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} شمار_type;

ساکن
خالی *adder_simple(خالی *arg)
{
    سائز_t قدم;
    شمار_type *شمار_2 = arg;

    برائے (قدم = 0; قدم < NR_اقدام; ++قدم) {
        atomic_fetch_add_explicit(&شمار_2->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&شمار_2->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&شمار_2->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&شمار_2->ul, 1, memory_order_relaxed);
    }

    واپس تہی;
}

ساکن
خالی *adder_cmpxchg(خالی *arg)
{
    سائز_t قدم;
    شمار_type *شمار_2 = arg;

    برائے (قدم = 0; قدم < NR_اقدام; ++قدم) {
        غیرعلامتی حرف xchgc;
        غیرعلامتی مختصر xchgs;
        غیرعلامتی صحیح xchgi;
        سائز_t xchgl;
        غیرعلامتی حرف cmpc = atomic_load_explicit(&شمار_2->uc, memory_order_relaxed);
        غیرعلامتی مختصر cmps = atomic_load_explicit(&شمار_2->us, memory_order_relaxed);
        غیرعلامتی صحیح cmpi = atomic_load_explicit(&شمار_2->ui, memory_order_relaxed);
        سائز_t cmpl = atomic_load_explicit(&شمار_2->ul, memory_order_relaxed);

        کرو {
            xchgc = (cmpc + 1);
        } جب (!atomic_compare_exchange_strong_explicit(&شمار_2->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        کرو {
            xchgs = (cmps + 1);
        } جب (!atomic_compare_exchange_strong_explicit(&شمار_2->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        کرو {
            xchgi = (cmpi + 1);
        } جب (!atomic_compare_exchange_strong_explicit(&شمار_2->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        کرو {
            xchgl = (cmpl + 1);
        } جب (!atomic_compare_exchange_strong_explicit(&شمار_2->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    واپس تہی;
}

ساکن
خالی *adder_test_and_سیٹ(خالی *arg)
{
    سائز_t قدم;
    شمار_type *شمار_2 = arg;

    برائے (قدم = 0; قدم < NR_اقدام; ++قدم) {
        جب (atomic_flag_test_and_set(&شمار_2->flag));
        ++شمار_2->uc;
        ++شمار_2->us;
        ++شمار_2->ui;
        ++شمار_2->ul;
        atomic_flag_clear(&شمار_2->flag);
    }

    واپس تہی;
}

ساکن
خالی atomic_شمار_test(خالی *(*adder)(خالی *arg))
{
    سائز_t اشاریہ;
    شمار_type شمار_2;
    pthread_t thread[NR_دھاگے];

    atomic_flag_clear(&شمار_2.flag);
    atomic_init(&شمار_2.uc, 0);
    atomic_init(&شمار_2.us, 0);
    atomic_init(&شمار_2.ui, 0);
    atomic_init(&شمار_2.ul, 0);

    برائے (اشاریہ = 0; اشاریہ < NR_دھاگے; ++اشاریہ)
        BUG_ON(pthread_create(&thread[اشاریہ], تہی, adder, (خالی *)&شمار_2));

    برائے (اشاریہ = 0; اشاریہ < NR_دھاگے; ++اشاریہ)
        BUG_ON(pthread_join(thread[اشاریہ], تہی));

    اگر (atomic_load(&شمار_2.uc) == ((NR_دھاگے * NR_اقدام) & 0xffu)
        && atomic_load(&شمار_2.us) == ((NR_دھاگے * NR_اقدام) & 0xffffu)
        && atomic_load(&شمار_2.ui) == (NR_دھاگے * NR_اقدام)
        && atomic_load(&شمار_2.ul) == (NR_دھاگے * NR_اقدام)
        )
        لکھو("SUCCESS\n");
    ورنہ
        لکھو("FAILURE\n");
}

صحیح مین(خالی)
{
    atomic_شمار_test(adder_simple);
    atomic_شمار_test(adder_cmpxchg);
    atomic_شمار_test(adder_test_and_سیٹ);

    واپس 0;
}
