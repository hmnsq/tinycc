#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
පූර්ණ_සංඛ්‍යා pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    ආපසු *p ? 0 : -1;
}
පූර්ණ_සංඛ්‍යා pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    නම් (ret)
        *ret = (void*)(size_t)r;
    ආපසු 0;
}
#නැතහොත්
#include <pthread.h>
#endif
