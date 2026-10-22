#अन्तर्भाव <stdatomic.h>
#अन्तर्भाव <stdio.h>

स्थिर पूर्णांक मूल्य_calls;
स्थिर पूर्णांक order_calls;

स्थिर पूर्णांक next_मूल्य(शून्य)
{
    ++मूल्य_calls;
    परत 42;
}

स्थिर पूर्णांक next_order(शून्य)
{
    ++order_calls;
    परत __ATOMIC_SEQ_CST;
}

पूर्णांक main(शून्य)
{
    पूर्णांक मूल्ये[2] = {7, 8};
    पूर्णांक index = 0;
    पूर्णांक मूल्य = 1;
    अस्थिर पूर्णांक vol = 0;
    पूर्णांक *pointer = &मूल्य;
    शून्य (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&मूल्ये[index++], next_मूल्य(), next_order());
    म_लिखो("%d %d %d %d %d\n", index, मूल्य_calls, order_calls,
           मूल्ये[0], मूल्ये[1]);
    __atomic_store_n(&मूल्य, मूल्य + 1, __ATOMIC_RELAXED);
    म_लिखो("%d\n", मूल्य);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    म_लिखो("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &मूल्ये[0], __ATOMIC_RELEASE);
    म_लिखो("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    माला_दो("ok");
    परत 0;
}
