#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح نيلاي_calls;
ساكن صحيح order_calls;

ساكن صحيح next_نيلاي(فراغ)
{
    ++نيلاي_calls;
    أرجع 42;
}

ساكن صحيح next_order(فراغ)
{
    ++order_calls;
    أرجع __ATOMIC_SEQ_CST;
}

صحيح main(فراغ)
{
    صحيح نيلاي_سموا[2] = {7, 8};
    صحيح index = 0;
    صحيح نيلاي = 1;
    متطاير صحيح vol = 0;
    صحيح *pointer = &نيلاي;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&نيلاي_سموا[index++], next_نيلاي(), next_order());
    printf("%d %d %d %d %d\n", index, نيلاي_calls, order_calls,
           نيلاي_سموا[0], نيلاي_سموا[1]);
    __atomic_store_n(&نيلاي, نيلاي + 1, __ATOMIC_RELAXED);
    printf("%d\n", نيلاي);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &نيلاي_سموا[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    أرجع 0;
}
