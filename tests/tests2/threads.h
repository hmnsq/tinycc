#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
цео pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    врати *p ? 0 : -1;
}
цео pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    ако (ret)
        *ret = (void*)(size_t)r;
    врати 0;
}
#инако
#include <pthread.h>
#endif
