#include <stdatomic.h>
#include <stdio.h>

static int हालागा_calls;
static int order_calls;

static int next_हालागा(void)
{
    ++हालागा_calls;
    return 42;
}

static int next_order(void)
{
    ++order_calls;
    return __ATOMIC_SEQ_CST;
}

int main(void)
{
    int मगा_हालागा[2] = {7, 8};
    int index = 0;
    int हालागा = 1;
    volatile int vol = 0;
    int *pointer = &हालागा;
    void (*signal_fence)(memory_order) = &atomic_signal_fence;

    __atomic_store_n(&मगा_हालागा[index++], next_हालागा(), next_order());
    printf("%d %d %d %d %d\n", index, हालागा_calls, order_calls,
           मगा_हालागा[0], मगा_हालागा[1]);
    __atomic_store_n(&हालागा, हालागा + 1, __ATOMIC_RELAXED);
    printf("%d\n", हालागा);
    __atomic_store_n(&vol, 13, __ATOMIC_RELEASE);
    printf("%d\n", __atomic_load_n(&vol, __ATOMIC_ACQUIRE));
    __atomic_store_n(&pointer, &मगा_हालागा[0], __ATOMIC_RELEASE);
    printf("%d\n", *__atomic_load_n(&pointer, __ATOMIC_ACQUIRE));

    atomic_signal_fence(memory_order_acquire);
    __atomic_signal_fence(__ATOMIC_RELEASE);
    signal_fence(memory_order_seq_cst);
    atomic_thread_fence(memory_order_seq_cst);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    puts("ok");
    return 0;
}
