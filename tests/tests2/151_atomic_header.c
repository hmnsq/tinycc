#अन्तर्भाव <stdatomic.h>
#अन्तर्भाव <stdio.h>

स्थिर पूर्णाङ्क मूल्य_calls;
स्थिर पूर्णाङ्क order_calls;

स्थिर पूर्णाङ्क next_मूल्य(शून्य)
{
    ++मूल्य_calls;
    प्रत्यागम 42;
}

स्थिर पूर्णाङ्क next_order(शून्य)
{
    ++order_calls;
    प्रत्यागम __ATOMIC_SEQ_CST;
}

पूर्णाङ्क main(शून्य)
{
    पूर्णाङ्क मूल्यावली[2] = {7, 8};
    पूर्णाङ्क index = 0;
    पूर्णाङ्क मूल्य = 1;
    चञ्चल पूर्णाङ्क vol = 0;
    पूर्णाङ्क *pointer = &मूल्य;
    शून्य (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&मूल्यावली[index++], next_मूल्य(), next_order());
    printf("%d %d %d %d %d\n", index, मूल्य_calls, order_calls,
           मूल्यावली[0], मूल्यावली[1]);
    __atomic_store_n(&मूल्य, मूल्य + 1, __ATOMIC_RELAXED);
    printf("%d\n", मूल्य);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &मूल्यावली[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    प्रत्यागम 0;
}
