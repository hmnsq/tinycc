#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح قيمة_calls;
ساكن صحيح order_calls;

ساكن صحيح next_قيمة(فراغ)
{
    ++قيمة_calls;
    إرجاع 42;
}

ساكن صحيح next_order(فراغ)
{
    ++order_calls;
    إرجاع __ATOMIC_SEQ_CST;
}

صحيح الرئيسية(فراغ)
{
    صحيح قيم[2] = {7, 8};
    صحيح index = 0;
    صحيح قيمة = 1;
    متطاير صحيح vol = 0;
    صحيح *pointer = &قيمة;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&قيم[index++], next_قيمة(), next_order());
    printf("%d %d %d %d %d\n", index, قيمة_calls, order_calls,
           قيم[0], قيم[1]);
    __atomic_store_n(&قيمة, قيمة + 1, __ATOMIC_RELAXED);
    printf("%d\n", قيمة);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &قيم[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    إرجاع 0;
}
