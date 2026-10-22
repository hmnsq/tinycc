#समावेश <stdatomic.h>
#समावेश <stdio.h>

अटल पूर्णांक मूल्य_calls;
अटल पूर्णांक order_calls;

अटल पूर्णांक अग्र_मूल्य(व्योम)
{
    ++मूल्य_calls;
    वापस 42;
}

अटल पूर्णांक अग्र_order(व्योम)
{
    ++order_calls;
    वापस __ATOMIC_SEQ_CST;
}

पूर्णांक मुख्य(व्योम)
{
    पूर्णांक मूल्यावली[2] = {7, 8};
    पूर्णांक सूचकांक = 0;
    पूर्णांक मूल्य = 1;
    अस्थिर पूर्णांक vol = 0;
    पूर्णांक *pointer = &मूल्य;
    व्योम (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&मूल्यावली[सूचकांक++], अग्र_मूल्य(), अग्र_order());
    म_लिखो("%d %d %d %d %d\n", सूचकांक, मूल्य_calls, order_calls,
           मूल्यावली[0], मूल्यावली[1]);
    __atomic_store_n(&मूल्य, मूल्य + 1, __ATOMIC_RELAXED);
    म_लिखो("%d\n", मूल्य);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    म_लिखो("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &मूल्यावली[0], __ATOMIC_RELEASE);
    म_लिखो("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    माला_दो("ok");
    वापस 0;
}
