#ಅನ್ತರ್ಭಾವ <stdatomic.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_calls;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಕ್ರಮ_calls;

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಮುಂದಿನ_ಮೌಲ್ಯ(ಶೂನ್ಯ)
{
    ++ಮೌಲ್ಯ_calls;
    ಹಿಂತಿರುಗಿ 42;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಮುಂದಿನ_ಕ್ರಮ(ಶೂನ್ಯ)
{
    ++ಕ್ರಮ_calls;
    ಹಿಂತಿರುಗಿ __ATOMIC_SEQ_CST;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯಗಳು[2] = {7, 8};
    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ = 0;
    ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ = 1;
    ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ vol = 0;
    ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_2 = &ಮೌಲ್ಯ;
    ಶೂನ್ಯ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&ಮೌಲ್ಯಗಳು[ಸೂಚ್ಯಂಕ++], ಮುಂದಿನ_ಮೌಲ್ಯ(), ಮುಂದಿನ_ಕ್ರಮ());
    ಬರೆ("%d %d %d %d %d\n", ಸೂಚ್ಯಂಕ, ಮೌಲ್ಯ_calls, ಕ್ರಮ_calls,
           ಮೌಲ್ಯಗಳು[0], ಮೌಲ್ಯಗಳು[1]);
    __atomic_store_n(&ಮೌಲ್ಯ, ಮೌಲ್ಯ + 1, __ATOMIC_RELAXED);
    ಬರೆ("%d\n", ಮೌಲ್ಯ);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    ಬರೆ("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&ಸೂಚಕ_2, &ಮೌಲ್ಯಗಳು[0], __ATOMIC_RELEASE);
    ಬರೆ("%d\n", *__atomic_load_n(&ಸೂಚಕ_2, __ATOMIC_ACQUIRE));

    atomic_signal_fence(ಸ್ಮರಣೆ_ಕ್ರಮ_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(ಸ್ಮರಣೆ_ಕ್ರಮ_seq_cst);
    atomic_thread_fence(ಸ್ಮರಣೆ_ಕ್ರಮ_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    ಹಿಂತಿರುಗಿ 0;
}
