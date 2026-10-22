#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح ارزښت_calls;
ساكن صحيح ترتیب_calls;

ساكن صحيح بل_ارزښت(فراغ)
{
    ++ارزښت_calls;
    أرجع 42;
}

ساكن صحيح بل_ترتیب(فراغ)
{
    ++ترتیب_calls;
    أرجع __ATOMIC_SEQ_CST;
}

صحيح اصلي(فراغ)
{
    صحيح ارزښتونه[2] = {7, 8};
    صحيح شاخص = 0;
    صحيح ارزښت = 1;
    متطاير صحيح vol = 0;
    صحيح *اشاره_ګر = &ارزښت;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&ارزښتونه[شاخص++], بل_ارزښت(), بل_ترتیب());
    چاپ_کړه("%d %d %d %d %d\n", شاخص, ارزښت_calls, ترتیب_calls,
           ارزښتونه[0], ارزښتونه[1]);
    __atomic_store_n(&ارزښت, ارزښت + 1, __ATOMIC_RELAXED);
    چاپ_کړه("%d\n", ارزښت);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    چاپ_کړه("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&اشاره_ګر, &ارزښتونه[0], __ATOMIC_RELEASE);
    چاپ_کړه("%d\n", *__atomic_load_n(&اشاره_ګر, __ATOMIC_ACQUIRE));

    atomic_signal_fence(حافظه_ترتیب_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(حافظه_ترتیب_seq_cst);
    atomic_thread_fence(حافظه_ترتیب_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    أرجع 0;
}
