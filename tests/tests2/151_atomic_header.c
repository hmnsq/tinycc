#ضمن <stdatomic.h>
#ضمن <stdio.h>

ساكن صحيح مقدار_calls;
ساكن صحيح ترتیب_calls;

ساكن صحيح بعدی_مقدار(فراغ)
{
    ++مقدار_calls;
    أرجع 42;
}

ساكن صحيح بعدی_ترتیب(فراغ)
{
    ++ترتیب_calls;
    أرجع __ATOMIC_SEQ_CST;
}

صحيح اصلی(فراغ)
{
    صحيح مقادیر[2] = {7, 8};
    صحيح شاخص = 0;
    صحيح مقدار = 1;
    متطاير صحيح vol = 0;
    صحيح *اشاره_گر = &مقدار;
    فراغ (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&مقادیر[شاخص++], بعدی_مقدار(), بعدی_ترتیب());
    چاپ_کن("%d %d %d %d %d\n", شاخص, مقدار_calls, ترتیب_calls,
           مقادیر[0], مقادیر[1]);
    __atomic_store_n(&مقدار, مقدار + 1, __ATOMIC_RELAXED);
    چاپ_کن("%d\n", مقدار);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    چاپ_کن("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&اشاره_گر, &مقادیر[0], __ATOMIC_RELEASE);
    چاپ_کن("%d\n", *__atomic_load_n(&اشاره_گر, __ATOMIC_ACQUIRE));

    atomic_signal_fence(حافظه_ترتیب_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(حافظه_ترتیب_seq_cst);
    atomic_thread_fence(حافظه_ترتیب_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    أرجع 0;
}
