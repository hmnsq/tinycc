#അന്തര്ഭാവ <stdatomic.h>
#അന്തര്ഭാവ <stdio.h>

സ്ഥിതം പൂർണ്ണസംഖ്യ മൂല്യം_calls;
സ്ഥിതം പൂർണ്ണസംഖ്യ order_calls;

സ്ഥിതം പൂർണ്ണസംഖ്യ next_മൂല്യം(ശൂന്യം)
{
    ++മൂല്യം_calls;
    തിരികെ 42;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ next_order(ശൂന്യം)
{
    ++order_calls;
    തിരികെ __ATOMIC_SEQ_CST;
}

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ മൂല്യങ്ങൾ[2] = {7, 8};
    പൂർണ്ണസംഖ്യ index = 0;
    പൂർണ്ണസംഖ്യ മൂല്യം = 1;
    അസ്ഥിര പൂർണ്ണസംഖ്യ vol = 0;
    പൂർണ്ണസംഖ്യ *pointer = &മൂല്യം;
    ശൂന്യം (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&മൂല്യങ്ങൾ[index++], next_മൂല്യം(), next_order());
    printf("%d %d %d %d %d\n", index, മൂല്യം_calls, order_calls,
           മൂല്യങ്ങൾ[0], മൂല്യങ്ങൾ[1]);
    __atomic_store_n(&മൂല്യം, മൂല്യം + 1, __ATOMIC_RELAXED);
    printf("%d\n", മൂല്യം);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &മൂല്യങ്ങൾ[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    തിരികെ 0;
}
