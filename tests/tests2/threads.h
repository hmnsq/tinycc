#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
số_nguyên pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    trả_về *p ? 0 : -1;
}
số_nguyên pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    nếu (ret)
        *ret = (void*)(size_t)r;
    trả_về 0;
}
#không_thì
#include <pthread.h>
#endif
