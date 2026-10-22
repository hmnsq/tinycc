#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح value_calls;
ساكن صحيح order_calls;

ساكن صحيح next_value(فراغ)
{
    ++value_calls;
    החזר 42;
}

ساكن صحيح next_order(فراغ)
{
    ++order_calls;
    החזר __ATOMIC_SEQ_CST;
}

صحيح main(فراغ)
{
    صحيح values[2] = {7, 8};
    صحيح index = 0;
    صحيح value = 1;
    متطاير صحيح vol = 0;
    صحيح *pointer = &value;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&values[index++], next_value(), next_order());
    printf("%d %d %d %d %d\n", index, value_calls, order_calls,
           values[0], values[1]);
    __atomic_store_n(&value, value + 1, __ATOMIC_RELAXED);
    printf("%d\n", value);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &values[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    החזר 0;
}
