#ಅನ್ತರ್ಭಾವ <stdatomic.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_calls;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ order_calls;

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ next_ಮೌಲ್ಯ(ಶೂನ್ಯ)
{
    ++ಮೌಲ್ಯ_calls;
    ಪ್ರತ್ಯಾಗಮ 42;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ next_order(ಶೂನ್ಯ)
{
    ++order_calls;
    ಪ್ರತ್ಯಾಗಮ __ATOMIC_SEQ_CST;
}

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯಗಳು[2] = {7, 8};
    ಪೂರ್ಣಾಙ್ಕ index = 0;
    ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ = 1;
    ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ vol = 0;
    ಪೂರ್ಣಾಙ್ಕ *pointer = &ಮೌಲ್ಯ;
    ಶೂನ್ಯ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&ಮೌಲ್ಯಗಳು[index++], next_ಮೌಲ್ಯ(), next_order());
    printf("%d %d %d %d %d\n", index, ಮೌಲ್ಯ_calls, order_calls,
           ಮೌಲ್ಯಗಳು[0], ಮೌಲ್ಯಗಳು[1]);
    __atomic_store_n(&ಮೌಲ್ಯ, ಮೌಲ್ಯ + 1, __ATOMIC_RELAXED);
    printf("%d\n", ಮೌಲ್ಯ);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &ಮೌಲ್ಯಗಳು[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    ಪ್ರತ್ಯಾಗಮ 0;
}
