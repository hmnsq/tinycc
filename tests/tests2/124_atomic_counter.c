#अन्तर्भाव <stddef.h>
#अन्तर्भाव <stdint.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव "threads.h"
#अन्तर्भाव <stdatomic.h>

#परिभाषय NR_तन्तवः 16
#परिभाषय NR_चरणाः 10000

#परिभाषय BUG_ON(COND) \
    कुरु { \
        यदि (!!(COND)) \
            abort(); \
    } यावत् (0)

प्रकारनिर्देश संरचना {
    atomic_flag flag;
    atomic_uchar uc;
    atomic_ushort us;
    atomic_uint ui;
    atomic_size_t ul;
} गणक_type;

स्थिर
शून्य *adder_simple(शून्य *arg)
{
    आकार_t चरणः;
    गणक_type *गणक = arg;

    प्रति (चरणः = 0; चरणः < NR_चरणाः; ++चरणः) {
        atomic_fetch_add_explicit(&गणक->uc, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&गणक->us, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&गणक->ui, 1, memory_order_relaxed);
        atomic_fetch_add_explicit(&गणक->ul, 1, memory_order_relaxed);
    }

    प्रत्यागम रिक्त;
}

स्थिर
शून्य *adder_cmpxchg(शून्य *arg)
{
    आकार_t चरणः;
    गणक_type *गणक = arg;

    प्रति (चरणः = 0; चरणः < NR_चरणाः; ++चरणः) {
        अचिह्नित वर्ण xchgc;
        अचिह्नित ह्रस्व xchgs;
        अचिह्नित पूर्णाङ्क xchgi;
        आकार_t xchgl;
        अचिह्नित वर्ण cmpc = atomic_load_explicit(&गणक->uc, memory_order_relaxed);
        अचिह्नित ह्रस्व cmps = atomic_load_explicit(&गणक->us, memory_order_relaxed);
        अचिह्नित पूर्णाङ्क cmpi = atomic_load_explicit(&गणक->ui, memory_order_relaxed);
        आकार_t cmpl = atomic_load_explicit(&गणक->ul, memory_order_relaxed);

        कुरु {
            xchgc = (cmpc + 1);
        } यावत् (!atomic_compare_exchange_strong_explicit(&गणक->uc,
            &cmpc, xchgc, memory_order_relaxed, memory_order_relaxed));
        कुरु {
            xchgs = (cmps + 1);
        } यावत् (!atomic_compare_exchange_strong_explicit(&गणक->us,
            &cmps, xchgs, memory_order_relaxed, memory_order_relaxed));
        कुरु {
            xchgi = (cmpi + 1);
        } यावत् (!atomic_compare_exchange_strong_explicit(&गणक->ui,
            &cmpi, xchgi, memory_order_relaxed, memory_order_relaxed));
        कुरु {
            xchgl = (cmpl + 1);
        } यावत् (!atomic_compare_exchange_strong_explicit(&गणक->ul,
            &cmpl, xchgl, memory_order_relaxed, memory_order_relaxed));
    }

    प्रत्यागम रिक्त;
}

स्थिर
शून्य *adder_test_and_समुच्चयः(शून्य *arg)
{
    आकार_t चरणः;
    गणक_type *गणक = arg;

    प्रति (चरणः = 0; चरणः < NR_चरणाः; ++चरणः) {
        यावत् (atomic_flag_test_and_set(&गणक->flag));
        ++गणक->uc;
        ++गणक->us;
        ++गणक->ui;
        ++गणक->ul;
        atomic_flag_clear(&गणक->flag);
    }

    प्रत्यागम रिक्त;
}

स्थिर
शून्य atomic_गणक_test(शून्य *(*adder)(शून्य *arg))
{
    आकार_t सूचकांक;
    गणक_type गणक;
    pthread_t thread[NR_तन्तवः];

    atomic_flag_clear(&गणक.flag);
    atomic_init(&गणक.uc, 0);
    atomic_init(&गणक.us, 0);
    atomic_init(&गणक.ui, 0);
    atomic_init(&गणक.ul, 0);

    प्रति (सूचकांक = 0; सूचकांक < NR_तन्तवः; ++सूचकांक)
        BUG_ON(pthread_create(&thread[सूचकांक], रिक्त, adder, (शून्य *)&गणक));

    प्रति (सूचकांक = 0; सूचकांक < NR_तन्तवः; ++सूचकांक)
        BUG_ON(pthread_join(thread[सूचकांक], रिक्त));

    यदि (atomic_load(&गणक.uc) == ((NR_तन्तवः * NR_चरणाः) & 0xffu)
        && atomic_load(&गणक.us) == ((NR_तन्तवः * NR_चरणाः) & 0xffffu)
        && atomic_load(&गणक.ui) == (NR_तन्तवः * NR_चरणाः)
        && atomic_load(&गणक.ul) == (NR_तन्तवः * NR_चरणाः)
        )
        प्रारूप_लिख("SUCCESS\n");
    अन्यथा
        प्रारूप_लिख("FAILURE\n");
}

पूर्णाङ्क मुख्यम्(शून्य)
{
    atomic_गणक_test(adder_simple);
    atomic_गणक_test(adder_cmpxchg);
    atomic_गणक_test(adder_test_and_समुच्चयः);

    प्रत्यागम 0;
}
