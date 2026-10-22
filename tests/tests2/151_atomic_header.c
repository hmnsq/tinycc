#شامل <stdatomic.h>
#شامل <stdio.h>

ایستا صحیح مقدار_calls;
ایستا صحیح order_calls;

ایستا صحیح next_مقدار(تهی)
{
    ++مقدار_calls;
    بازگشت 42;
}

ایستا صحیح next_order(تهی)
{
    ++order_calls;
    بازگشت __ATOMIC_SEQ_CST;
}

صحیح اصلی(تهی)
{
    صحیح مقادیر[2] = {7, 8};
    صحیح index = 0;
    صحیح مقدار = 1;
    فرار صحیح vol = 0;
    صحیح *pointer = &مقدار;
    تهی (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&مقادیر[index++], next_مقدار(), next_order());
    printf("%d %d %d %d %d\n", index, مقدار_calls, order_calls,
           مقادیر[0], مقادیر[1]);
    __atomic_store_n(&مقدار, مقدار + 1, __ATOMIC_RELAXED);
    printf("%d\n", مقدار);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &مقادیر[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    بازگشت 0;
}
