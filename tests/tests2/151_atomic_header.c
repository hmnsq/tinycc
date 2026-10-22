#شامل <stdatomic.h>
#شامل <stdio.h>

ساکن صحیح قدر_calls;
ساکن صحیح ترتیب_calls;

ساکن صحیح اگلا_قدر(خالی)
{
    ++قدر_calls;
    واپس 42;
}

ساکن صحیح اگلا_ترتیب(خالی)
{
    ++ترتیب_calls;
    واپس __ATOMIC_SEQ_CST;
}

صحیح مین(خالی)
{
    صحیح اقدار[2] = {7, 8};
    صحیح اشاریہ = 0;
    صحیح قدر = 1;
    متلون صحیح vol = 0;
    صحیح *اشارہ_گر = &قدر;
    خالی (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&اقدار[اشاریہ++], اگلا_قدر(), اگلا_ترتیب());
    لکھو("%d %d %d %d %d\n", اشاریہ, قدر_calls, ترتیب_calls,
           اقدار[0], اقدار[1]);
    __atomic_store_n(&قدر, قدر + 1, __ATOMIC_RELAXED);
    لکھو("%d\n", قدر);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    لکھو("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&اشارہ_گر, &اقدار[0], __ATOMIC_RELEASE);
    لکھو("%d\n", *__atomic_load_n(&اشارہ_گر, __ATOMIC_ACQUIRE));

    atomic_signal_fence(حافظہ_ترتیب_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(حافظہ_ترتیب_seq_cst);
    atomic_thread_fence(حافظہ_ترتیب_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    واپس 0;
}
