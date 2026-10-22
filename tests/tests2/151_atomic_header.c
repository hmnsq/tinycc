#include <stdatomic.h>
#include <stdio.h>

static 정수 value_calls;
static 정수 order_calls;

static 정수 next_value(void)
{
    ++value_calls;
    반환 42;
}

static 정수 next_order(void)
{
    ++order_calls;
    반환 __ATOMIC_SEQ_CST;
}

정수 main(void)
{
    정수 values[2] = {7, 8};
    정수 index = 0;
    정수 value = 1;
    volatile 정수 vol = 0;
    정수 *pointer = &value;
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
    반환 0;
}
