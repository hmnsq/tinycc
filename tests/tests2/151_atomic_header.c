#include <stdatomic.h>
#include <stdio.h>

static ціле value_calls;
static ціле order_calls;

static ціле next_value(void)
{
    ++value_calls;
    повернути 42;
}

static ціле next_order(void)
{
    ++order_calls;
    повернути __ATOMIC_SEQ_CST;
}

ціле main(void)
{
    ціле values[2] = {7, 8};
    ціле index = 0;
    ціле value = 1;
    volatile ціле vol = 0;
    ціле *pointer = &value;
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
    повернути 0;
}
