#include <stdatomic.h>
#include <stdio.h>

static จำนวนเต็ม value_calls;
static จำนวนเต็ม order_calls;

static จำนวนเต็ม next_value(void)
{
    ++value_calls;
    คืน 42;
}

static จำนวนเต็ม next_order(void)
{
    ++order_calls;
    คืน __ATOMIC_SEQ_CST;
}

จำนวนเต็ม หลัก(void)
{
    จำนวนเต็ม values[2] = {7, 8};
    จำนวนเต็ม index = 0;
    จำนวนเต็ม value = 1;
    ca_ncala จำนวนเต็ม vol = 0;
    จำนวนเต็ม *pointer = &value;
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
    คืน 0;
}
