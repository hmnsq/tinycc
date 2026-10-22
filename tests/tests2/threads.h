#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
ចំនួនគត់ pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    ត្រឡប់ *p ? 0 : -1;
}
ចំនួនគត់ pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    ប្រសិនបើ (ret)
        *ret = (void*)(size_t)r;
    ត្រឡប់ 0;
}
#បើមិនដូច្នេះ
#include <pthread.h>
#endif
