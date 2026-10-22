#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
จำนวนเต็ม pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    คืน *p ? 0 : -1;
}
จำนวนเต็ม pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    ถ้า (ret)
        *ret = (void*)(size_t)r;
    คืน 0;
}
#มิฉะนั้น
#include <pthread.h>
#endif
