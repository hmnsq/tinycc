#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح قىممەت_calls;
ساكن صحيح order_calls;

ساكن صحيح next_قىممەت(فراغ)
{
    ++قىممەت_calls;
    أرجع 42;
}

ساكن صحيح next_order(فراغ)
{
    ++order_calls;
    أرجع __ATOMIC_SEQ_CST;
}

صحيح main(فراغ)
{
    صحيح قىممەتلەر[2] = {7, 8};
    صحيح index = 0;
    صحيح قىممەت = 1;
    متطاير صحيح vol = 0;
    صحيح *pointer = &قىممەت;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&قىممەتلەر[index++], next_قىممەت(), next_order());
    printf("%d %d %d %d %d\n", index, قىممەت_calls, order_calls,
           قىممەتلەر[0], قىممەتلەر[1]);
    __atomic_store_n(&قىممەت, قىممەت + 1, __ATOMIC_RELAXED);
    printf("%d\n", قىممەت);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &قىممەتلەر[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    أرجع 0;
}
