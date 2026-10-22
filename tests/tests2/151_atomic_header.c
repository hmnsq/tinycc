#include <stdatomic.h>
#include <stdio.h>

static 整数 value_calls;
static 整数 order_calls;

static 整数 next_value(void)
{
    ++value_calls;
    返回 42;
}

static 整数 next_order(void)
{
    ++order_calls;
    返回 __ATOMIC_SEQ_CST;
}

整数 主要(void)
{
    整数 values[2] = {7, 8};
    整数 index = 0;
    整数 value = 1;
    volatile 整数 vol = 0;
    整数 *pointer = &value;
    void (*signal_fence)(memory_order) = &atomic_signal_fence;

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
    返回 0;
}
