#अन्तर्भाव <stdatomic.h>
#अन्तर्भाव <stdio.h>

स्थिर पूर्णाङ्क मान_calls;
स्थिर पूर्णाङ्क order_calls;

स्थिर पूर्णाङ्क next_मान(शून्य)
{
    ++मान_calls;
    फर्काऊ 42;
}

स्थिर पूर्णाङ्क next_order(शून्य)
{
    ++order_calls;
    फर्काऊ __ATOMIC_SEQ_CST;
}

पूर्णाङ्क main(शून्य)
{
    पूर्णाङ्क मानहरू[2] = {7, 8};
    पूर्णाङ्क index = 0;
    पूर्णाङ्क मान = 1;
    चञ्चल पूर्णाङ्क vol = 0;
    पूर्णाङ्क *pointer = &मान;
    शून्य (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&मानहरू[index++], next_मान(), next_order());
    म_लिखो("%d %d %d %d %d\n", index, मान_calls, order_calls,
           मानहरू[0], मानहरू[1]);
    __atomic_store_n(&मान, मान + 1, __ATOMIC_RELAXED);
    म_लिखो("%d\n", मान);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    म_लिखो("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &मानहरू[0], __ATOMIC_RELEASE);
    म_लिखो("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    माला_दो("ok");
    फर्काऊ 0;
}
