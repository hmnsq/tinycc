#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح قدر_calls;
ساكن صحيح ترتيب_calls;

ساكن صحيح ايندڙ_قدر(فراغ)
{
    ++قدر_calls;
    أرجع 42;
}

ساكن صحيح ايندڙ_ترتيب(فراغ)
{
    ++ترتيب_calls;
    أرجع __ATOMIC_SEQ_CST;
}

صحيح مکيه(فراغ)
{
    صحيح قدرون[2] = {7, 8};
    صحيح اشاريو = 0;
    صحيح قدر = 1;
    متطاير صحيح vol = 0;
    صحيح *اشارو = &قدر;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&قدرون[اشاريو++], ايندڙ_قدر(), ايندڙ_ترتيب());
    لکو("%d %d %d %d %d\n", اشاريو, قدر_calls, ترتيب_calls,
           قدرون[0], قدرون[1]);
    __atomic_store_n(&قدر, قدر + 1, __ATOMIC_RELAXED);
    لکو("%d\n", قدر);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    لکو("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&اشارو, &قدرون[0], __ATOMIC_RELEASE);
    لکو("%d\n", *__atomic_load_n(&اشارو, __ATOMIC_ACQUIRE));

    atomic_signal_fence(يادگيري_ترتيب_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(يادگيري_ترتيب_seq_cst);
    atomic_thread_fence(يادگيري_ترتيب_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    أرجع 0;
}
