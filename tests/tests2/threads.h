#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
целое pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    вернуть *p ? 0 : -1;
}
целое pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    если (ret)
        *ret = (void*)(size_t)r;
    вернуть 0;
}
#иначе
#include <pthread.h>
#endif
