#ଅନ୍ତର୍ଭାଵ <stdatomic.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_calls;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା order_calls;

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା next_ମୂଲ୍ୟ(ଶୂନ୍ୟ)
{
    ++ମୂଲ୍ୟ_calls;
    ଫେରନ୍ତୁ 42;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା next_order(ଶୂନ୍ୟ)
{
    ++order_calls;
    ଫେରନ୍ତୁ __ATOMIC_SEQ_CST;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟଗୁଡ଼ିକ[2] = {7, 8};
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ = 1;
    ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା vol = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer = &ମୂଲ୍ୟ;
    ଶୂନ୍ୟ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&ମୂଲ୍ୟଗୁଡ଼ିକ[index++], next_ମୂଲ୍ୟ(), next_order());
    printf("%d %d %d %d %d\n", index, ମୂଲ୍ୟ_calls, order_calls,
           ମୂଲ୍ୟଗୁଡ଼ିକ[0], ମୂଲ୍ୟଗୁଡ଼ିକ[1]);
    __atomic_store_n(&ମୂଲ୍ୟ, ମୂଲ୍ୟ + 1, __ATOMIC_RELAXED);
    printf("%d\n", ମୂଲ୍ୟ);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &ମୂଲ୍ୟଗୁଡ଼ିକ[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    ଫେରନ୍ତୁ 0;
}
