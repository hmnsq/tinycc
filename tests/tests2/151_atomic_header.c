#অন্তর্ভাৱ <stdatomic.h>
#অন্তর্ভাৱ <stdio.h>

স্থির পূর্ণাঙ্ক মান_calls;
স্থির পূর্ণাঙ্ক order_calls;

স্থির পূর্ণাঙ্ক next_মান(শূন্য)
{
    ++মান_calls;
    ঘূৰাই 42;
}

স্থির পূর্ণাঙ্ক next_order(শূন্য)
{
    ++order_calls;
    ঘূৰাই __ATOMIC_SEQ_CST;
}

পূর্ণাঙ্ক main(শূন্য)
{
    পূর্ণাঙ্ক মানসমূহ[2] = {7, 8};
    পূর্ণাঙ্ক index = 0;
    পূর্ণাঙ্ক মান = 1;
    চঞ্চল পূর্ণাঙ্ক vol = 0;
    পূর্ণাঙ্ক *pointer = &মান;
    শূন্য (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&মানসমূহ[index++], next_মান(), next_order());
    printf("%d %d %d %d %d\n", index, মান_calls, order_calls,
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
    ঘূৰাই 0;
}
