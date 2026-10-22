#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
ကိန်းပြည့် pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    ပြန်ပေး *p ? 0 : -1;
}
ကိန်းပြည့် pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    အကယ်၍ (ret)
        *ret = (void*)(size_t)r;
    ပြန်ပေး 0;
}
#မဟုတ်ပါက
#include <pthread.h>
#endif
