#include <stdatomic.h>
#include <stdio.h>

static පූර්ණ_සංඛ්‍යා value_calls;
static පූර්ණ_සංඛ්‍යා order_calls;

static පූර්ණ_සංඛ්‍යා next_value(void)
{
    ++value_calls;
    ආපසු 42;
}

static පූර්ණ_සංඛ්‍යා next_order(void)
{
    ++order_calls;
    ආපසු __ATOMIC_SEQ_CST;
}

පූර්ණ_සංඛ්‍යා main(void)
{
    පූර්ණ_සංඛ්‍යා values[2] = {7, 8};
    පූර්ණ_සංඛ්‍යා index = 0;
    පූර්ණ_සංඛ්‍යා value = 1;
    ca_ncala පූර්ණ_සංඛ්‍යා vol = 0;
    පූර්ණ_සංඛ්‍යා *pointer = &value;
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
    ආපසු 0;
}
