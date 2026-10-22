#include <stdatomic.h>
#include <stdio.h>

static ចំនួនគត់ value_calls;
static ចំនួនគត់ order_calls;

static ចំនួនគត់ next_value(void)
{
    ++value_calls;
    ត្រឡប់ 42;
}

static ចំនួនគត់ next_order(void)
{
    ++order_calls;
    ត្រឡប់ __ATOMIC_SEQ_CST;
}

ចំនួនគត់ main(void)
{
    ចំនួនគត់ values[2] = {7, 8};
    ចំនួនគត់ index = 0;
    ចំនួនគត់ value = 1;
    ca_ncala ចំនួនគត់ vol = 0;
    ចំនួនគត់ *pointer = &value;
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
    ត្រឡប់ 0;
}
