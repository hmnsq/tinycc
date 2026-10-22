#અન્તર્ભાવ <stdatomic.h>
#અન્તર્ભાવ <stdio.h>

સ્થિર પૂર્ણાંક કિંમત_calls;
સ્થિર પૂર્ણાંક order_calls;

સ્થિર પૂર્ણાંક next_કિંમત(શૂન્ય)
{
    ++કિંમત_calls;
    પાછા 42;
}

સ્થિર પૂર્ણાંક next_order(શૂન્ય)
{
    ++order_calls;
    પાછા __ATOMIC_SEQ_CST;
}

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    પૂર્ણાંક કિંમતો[2] = {7, 8};
    પૂર્ણાંક index = 0;
    પૂર્ણાંક કિંમત = 1;
    અસ્થિર પૂર્ણાંક vol = 0;
    પૂર્ણાંક *pointer = &કિંમત;
    શૂન્ય (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&કિંમતો[index++], next_કિંમત(), next_order());
    printf("%d %d %d %d %d\n", index, કિંમત_calls, order_calls,
           કિંમતો[0], કિંમતો[1]);
    __atomic_store_n(&કિંમત, કિંમત + 1, __ATOMIC_RELAXED);
    printf("%d\n", કિંમત);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &કિંમતો[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    પાછા 0;
}
