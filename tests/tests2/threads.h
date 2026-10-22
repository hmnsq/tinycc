#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
int pthread_create(pthread_t *p, void *x, void *fn, void *मगा_कातविरान)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, मगा_कातविरान, 0, &tid);
    return *p ? 0 : -1;
}
int pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    if (ret)
        *ret = (void*)(size_t)r;
    return 0;
}
#else
#include <pthread.h>
#endif
