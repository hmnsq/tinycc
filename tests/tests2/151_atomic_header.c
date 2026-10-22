#অন্তর্ভাব <stdatomic.h>
#অন্তর্ভাব <stdio.h>

স্থির পূর্ণসংখ্যা মান_calls;
স্থির পূর্ণসংখ্যা order_calls;

স্থির পূর্ণসংখ্যা পরবর্তী_মান(শূন্য)
{
    ++মান_calls;
    ফেরত 42;
}

স্থির পূর্ণসংখ্যা পরবর্তী_order(শূন্য)
{
    ++order_calls;
    ফেরত __ATOMIC_SEQ_CST;
}

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    পূর্ণসংখ্যা মানসমূহ[2] = {7, 8};
    পূর্ণসংখ্যা সূচক = 0;
    পূর্ণসংখ্যা মান = 1;
    অস্থির পূর্ণসংখ্যা vol = 0;
    পূর্ণসংখ্যা *pointer = &মান;
    শূন্য (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&মানসমূহ[সূচক++], পরবর্তী_মান(), পরবর্তী_order());
    printf("%d %d %d %d %d\n", সূচক, মান_calls, order_calls,
           মানসমূহ[0], মানসমূহ[1]);
    __atomic_store_n(&মান, মান + 1, __ATOMIC_RELAXED);
    printf("%d\n", মান);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &মানসমূহ[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    ফেরত 0;
}
