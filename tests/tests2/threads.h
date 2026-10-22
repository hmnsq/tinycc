#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
ཧྲིལ pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    ལོག *p ? 0 : -1;
}
ཧྲིལ pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    གལ་སྲིད (ret)
        *ret = (void*)(size_t)r;
    ལོག 0;
}
#དེ་མིན
#include <pthread.h>
#endif
