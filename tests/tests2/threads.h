#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
정수 pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    반환 *p ? 0 : -1;
}
정수 pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    만약 (ret)
        *ret = (void*)(size_t)r;
    반환 0;
}
#아니면
#include <pthread.h>
#endif
