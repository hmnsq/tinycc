#अन्तर्भाव <stdatomic.h>
#अन्तर्भाव <stdio.h>

स्थिर पूर्णाङ्क मानम्_calls;
स्थिर पूर्णाङ्क order_calls;

स्थिर पूर्णाङ्क next_मानम्(शून्य)
{
    ++मानम्_calls;
    पटिनिवत्त 42;
}

स्थिर पूर्णाङ्क next_order(शून्य)
{
    ++order_calls;
    पटिनिवत्त __ATOMIC_SEQ_CST;
}

पूर्णाङ्क main(शून्य)
{
    पूर्णाङ्क मानानि[2] = {7, 8};
    पूर्णाङ्क index = 0;
    पूर्णाङ्क मानम् = 1;
    चञ्चल पूर्णाङ्क vol = 0;
    पूर्णाङ्क *pointer = &मानम्;
    शून्य (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&मानानि[index++], next_मानम्(), next_order());
    printf("%d %d %d %d %d\n", index, मानम्_calls, order_calls,
           मानानि[0], मानानि[1]);
    __atomic_store_n(&मानम्, मानम् + 1, __ATOMIC_RELAXED);
    printf("%d\n", मानम्);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &मानानि[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    पटिनिवत्त 0;
}
