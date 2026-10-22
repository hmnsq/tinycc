#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
整数 pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    戻る *p ? 0 : -1;
}
整数 pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    もし (ret)
        *ret = (void*)(size_t)r;
    戻る 0;
}
#否则
#include <pthread.h>
#endif
