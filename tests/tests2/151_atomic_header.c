#அந்தர்பாவ <stdatomic.h>
#அந்தர்பாவ <stdio.h>

நிலையான முழு மதிப்பு_calls;
நிலையான முழு order_calls;

நிலையான முழு next_மதிப்பு(வெறுமை)
{
    ++மதிப்பு_calls;
    திரும்பு 42;
}

நிலையான முழு next_order(வெறுமை)
{
    ++order_calls;
    திரும்பு __ATOMIC_SEQ_CST;
}

முழு முதன்மை(வெறுமை)
{
    முழு மதிப்புகள்[2] = {7, 8};
    முழு index = 0;
    முழு மதிப்பு = 1;
    நிலையற்ற முழு vol = 0;
    முழு *pointer = &மதிப்பு;
    வெறுமை (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&மதிப்புகள்[index++], next_மதிப்பு(), next_order());
    printf("%d %d %d %d %d\n", index, மதிப்பு_calls, order_calls,
           மதிப்புகள்[0], மதிப்புகள்[1]);
    __atomic_store_n(&மதிப்பு, மதிப்பு + 1, __ATOMIC_RELAXED);
    printf("%d\n", மதிப்பு);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &மதிப்புகள்[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    திரும்பு 0;
}
