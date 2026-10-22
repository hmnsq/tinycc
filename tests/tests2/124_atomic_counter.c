#अन्तर्भाव <stddef.h>
#अन्तर्भाव <stdint.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव "threads.h"
#अन्तर्भाव <stdatomic.h>

#define NR_THREADS 16
#define NR_STEPS 10000

#define BUG_ON(COND) \
    गर { \
        यदि (!!(COND)) \
            पात(); \
    } जबसम्म (0)

प्रकारनिर्देश संरचना {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} counter_type;

स्थिर
शून्य *adder_simple(शून्य *arg)
{
    माप_प्रकार step;
    counter_type *counter = arg;

    लागि (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&counter->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&counter->ul, 1, memory_order_relaxed);
    }

    फर्काऊ रिक्त;
}

स्थिर
शून्य *adder_cmpxchg(शून्य *arg)
{
    माप_प्रकार step;
    counter_type *counter = arg;

    लागि (step = 0; step < NR_STEPS; ++step) {
        अचिन्हित वर्ण xchgc;
        अचिन्हित लघु xchgs;
        अचिन्हित पूर्णाङ्क xchgi;
        माप_प्रकार xchgl;
        अचिन्हित वर्ण cmpc = atomic_load_explicit(&counter->uc, memory_order_relaxed);
        अचिन्हित लघु cmps = atomic_load_explicit(&counter->us, memory_order_relaxed);
        अचिन्हित पूर्णाङ्क cmpi = atomic_load_explicit(&counter->ui, memory_order_relaxed);
        माप_प्रकार cmpl = atomic_load_explicit(&counter->ul, memory_order_relaxed);

        गर {
            xchgc = (cmpc + 1);
        } जबसम्म (!atomic_compare_exchange_strong_explicit(&counter->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        गर {
            xchgs = (cmps + 1);
        } जबसम्म (!atomic_compare_exchange_strong_explicit(&counter->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        गर {
            xchgi = (cmpi + 1);
        } जबसम्म (!atomic_compare_exchange_strong_explicit(&counter->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        गर {
            xchgl = (cmpl + 1);
        } जबसम्म (!atomic_compare_exchange_strong_explicit(&counter->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    फर्काऊ रिक्त;
}

स्थिर
शून्य *adder_test_and_set(शून्य *arg)
{
    माप_प्रकार step;
    counter_type *counter = arg;

    लागि (step = 0; step < NR_STEPS; ++step) {
        जबसम्म (atomic_flag_test_and_set(&counter->flag));
        ++counter->uc;
        ++counter->us;
        ++counter->ui;
        ++counter->ul;
        atomic_flag_clear(&counter->flag);
    }

    फर्काऊ रिक्त;
}

स्थिर
शून्य atomic_counter_test(शून्य *(*adder)(शून्य *arg))
{
    माप_प्रकार index;
    counter_type counter;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&counter.flag);
    atomic_init(&counter.uc, 0);
    atomic_init(&counter.us, 0);
    atomic_init(&counter.ui, 0);
    atomic_init(&counter.ul, 0);

    लागि (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_create(&thread[index], रिक्त, adder, (शून्य *)&counter));

    लागि (index = 0; index < NR_THREADS; ++index)
        BUG_ON(pthread_join(thread[index], रिक्त));

    यदि (atomic_load(&counter.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&counter.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&counter.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&counter.ul) == (NR_THREADS * NR_STEPS)
        )
        म_लिखो("SUCCESS\n");
    अन्यथा
        म_लिखो("FAILURE\n");
}

पूर्णाङ्क main(शून्य)
{
    atomic_counter_test(adder_simple);
    atomic_counter_test(adder_cmpxchg);
    atomic_counter_test(adder_test_and_set);

    फर्काऊ 0;
}
