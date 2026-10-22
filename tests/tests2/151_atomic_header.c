#అన్తర్భావ <stdatomic.h>
#అన్తర్భావ <stdio.h>

స్థిర పూర్ణాంకం విలువ_calls;
స్థిర పూర్ణాంకం క్రమం_calls;

స్థిర పూర్ణాంకం తదుపరి_విలువ(శూన్య)
{
    ++విలువ_calls;
    తిరిగి 42;
}

స్థిర పూర్ణాంకం తదుపరి_క్రమం(శూన్య)
{
    ++క్రమం_calls;
    తిరిగి __ATOMIC_SEQ_CST;
}

పూర్ణాంకం ప్రధాన(శూన్య)
{
    పూర్ణాంకం విలువలు[2] = {7, 8};
    పూర్ణాంకం సూచీ = 0;
    పూర్ణాంకం విలువ = 1;
    అస్థిర పూర్ణాంకం vol = 0;
    పూర్ణాంకం *సూచిక_2 = &విలువ;
    శూన్య (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&విలువలు[సూచీ++], తదుపరి_విలువ(), తదుపరి_క్రమం());
    రాయి("%d %d %d %d %d\n", సూచీ, విలువ_calls, క్రమం_calls,
           విలువలు[0], విలువలు[1]);
    __atomic_store_n(&విలువ, విలువ + 1, __ATOMIC_RELAXED);
    రాయి("%d\n", విలువ);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    రాయి("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&సూచిక_2, &విలువలు[0], __ATOMIC_RELEASE);
    రాయి("%d\n", *__atomic_load_n(&సూచిక_2, __ATOMIC_ACQUIRE));

    atomic_signal_fence(జ్ఞాపకం_క్రమం_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(జ్ఞాపకం_క్రమం_seq_cst);
    atomic_thread_fence(జ్ఞాపకం_క్రమం_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    తిరిగి 0;
}
