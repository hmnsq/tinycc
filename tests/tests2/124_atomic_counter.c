#समावेश <stddef.h>
#समावेश <stdint.h>
#समावेश <stdlib.h>
#समावेश <stdio.h>
#समावेश "threads.h"
#समावेश <stdatomic.h>

#घोषणा NR_THREADS 16
#घोषणा NR_STEPS 10000

#घोषणा BUG_ON(COND) \
    करो { \
        अगर (!!(COND)) \
            पात(); \
    } जबतक (0)

प्रकार काष्ठा {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} गणक_type;

अटल
व्योम *adder_simple(व्योम *arg)
{
    माप_प्रकार step;
    गणक_type *गणक = arg;

    क्रम (step = 0; step < NR_STEPS; ++step) {
        atomic_fetch_add_explicit(&गणक->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&गणक->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&गणक->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&गणक->ul, 1, memory_order_relaxed);
    }

    वापस शून्य;
}

अटल
व्योम *adder_cmpxchg(व्योम *arg)
{
    माप_प्रकार step;
    गणक_type *गणक = arg;

    क्रम (step = 0; step < NR_STEPS; ++step) {
        अचिन्हित अक्षर xchgc;
        अचिन्हित लघु xchgs;
        अचिन्हित पूर्णांक xchgi;
        माप_प्रकार xchgl;
        अचिन्हित अक्षर cmpc = atomic_load_explicit(&गणक->uc, memory_order_relaxed);
        अचिन्हित लघु cmps = atomic_load_explicit(&गणक->us, memory_order_relaxed);
        अचिन्हित पूर्णांक cmpi = atomic_load_explicit(&गणक->ui, memory_order_relaxed);
        माप_प्रकार cmpl = atomic_load_explicit(&गणक->ul, memory_order_relaxed);

        करो {
            xchgc = (cmpc + 1);
        } जबतक (!atomic_compare_exchange_strong_explicit(&गणक->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        करो {
            xchgs = (cmps + 1);
        } जबतक (!atomic_compare_exchange_strong_explicit(&गणक->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        करो {
            xchgi = (cmpi + 1);
        } जबतक (!atomic_compare_exchange_strong_explicit(&गणक->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        करो {
            xchgl = (cmpl + 1);
        } जबतक (!atomic_compare_exchange_strong_explicit(&गणक->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    वापस शून्य;
}

अटल
व्योम *adder_test_and_set(व्योम *arg)
{
    माप_प्रकार step;
    गणक_type *गणक = arg;

    क्रम (step = 0; step < NR_STEPS; ++step) {
        जबतक (atomic_flag_test_and_set(&गणक->flag));
        ++गणक->uc;
        ++गणक->us;
        ++गणक->ui;
        ++गणक->ul;
        atomic_flag_clear(&गणक->flag);
    }

    वापस शून्य;
}

अटल
व्योम atomic_गणक_test(व्योम *(*adder)(व्योम *arg))
{
    माप_प्रकार सूचकांक;
    गणक_type गणक;
    pthread_t thread[NR_THREADS];

    atomic_flag_clear(&गणक.flag);
    atomic_init(&गणक.uc, 0);
    atomic_init(&गणक.us, 0);
    atomic_init(&गणक.ui, 0);
    atomic_init(&गणक.ul, 0);

    क्रम (सूचकांक = 0; सूचकांक < NR_THREADS; ++सूचकांक)
        BUG_ON(pthread_create(&thread[सूचकांक], शून्य, adder, (व्योम *)&गणक));

    क्रम (सूचकांक = 0; सूचकांक < NR_THREADS; ++सूचकांक)
        BUG_ON(pthread_join(thread[सूचकांक], शून्य));

    अगर (atomic_load(&गणक.uc) == ((NR_THREADS * NR_STEPS) & 0xffu)
        && atomic_load(&गणक.us) == ((NR_THREADS * NR_STEPS) & 0xffffu)
        && atomic_load(&गणक.ui) == (NR_THREADS * NR_STEPS)
        && atomic_load(&गणक.ul) == (NR_THREADS * NR_STEPS)
        )
        म_लिखो("SUCCESS\n");
    अन्यथा
        म_लिखो("FAILURE\n");
}

पूर्णांक मुख्य(व्योम)
{
    atomic_गणक_test(adder_simple);
    atomic_गणक_test(adder_cmpxchg);
    atomic_गणक_test(adder_test_and_set);

    वापस 0;
}
