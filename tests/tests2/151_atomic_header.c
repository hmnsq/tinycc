#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح قدر_calls;
ساكن صحيح order_calls;

ساكن صحيح next_قدر(فراغ)
{
    ++قدر_calls;
    أرجع 42;
}

ساكن صحيح next_order(فراغ)
{
    ++order_calls;
    أرجع __ATOMIC_SEQ_CST;
}

صحيح main(فراغ)
{
    صحيح اقدار[2] = {7, 8};
    صحيح index = 0;
    صحيح قدر = 1;
    متطاير صحيح vol = 0;
    صحيح *pointer = &قدر;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&اقدار[index++], next_قدر(), next_order());
    printf("%d %d %d %d %d\n", index, قدر_calls, order_calls,
           اقدار[0], اقدار[1]);
    __atomic_store_n(&قدر, قدر + 1, __ATOMIC_RELAXED);
    printf("%d\n", قدر);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &اقدار[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    أرجع 0;
}
