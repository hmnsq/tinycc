#ਅਨ੍ਤਰ੍ਭਾਵ <stdatomic.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਸਥਿਰ ਪੂਰਨ ਮੁੱਲ_calls;
ਸਥਿਰ ਪੂਰਨ ਕ੍ਰਮ_calls;

ਸਥਿਰ ਪੂਰਨ ਅਗਲਾ_ਮੁੱਲ(ਖਾਲੀ)
{
    ++ਮੁੱਲ_calls;
    ਵਾਪਸ 42;
}

ਸਥਿਰ ਪੂਰਨ ਅਗਲਾ_ਕ੍ਰਮ(ਖਾਲੀ)
{
    ++ਕ੍ਰਮ_calls;
    ਵਾਪਸ __ATOMIC_SEQ_CST;
}

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    ਪੂਰਨ ਮੁੱਲਾਂ[2] = {7, 8};
    ਪੂਰਨ ਸੂਚਕਾਂਕ = 0;
    ਪੂਰਨ ਮੁੱਲ = 1;
    ਅਸਥਿਰ ਪੂਰਨ vol = 0;
    ਪੂਰਨ *ਸੂਚਕ = &ਮੁੱਲ;
    ਖਾਲੀ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&ਮੁੱਲਾਂ[ਸੂਚਕਾਂਕ++], ਅਗਲਾ_ਮੁੱਲ(), ਅਗਲਾ_ਕ੍ਰਮ());
    ਲਿਖੋ("%d %d %d %d %d\n", ਸੂਚਕਾਂਕ, ਮੁੱਲ_calls, ਕ੍ਰਮ_calls,
           ਮੁੱਲਾਂ[0], ਮੁੱਲਾਂ[1]);
    __atomic_store_n(&ਮੁੱਲ, ਮੁੱਲ + 1, __ATOMIC_RELAXED);
    ਲਿਖੋ("%d\n", ਮੁੱਲ);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    ਲਿਖੋ("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&ਸੂਚਕ, &ਮੁੱਲਾਂ[0], __ATOMIC_RELEASE);
    ਲਿਖੋ("%d\n", *__atomic_load_n(&ਸੂਚਕ, __ATOMIC_ACQUIRE));

    atomic_signal_fence(ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_seq_cst);
    atomic_thread_fence(ਸਮ੍ਰਿਤੀ_ਕ੍ਰਮ_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    ਵਾਪਸ 0;
}
