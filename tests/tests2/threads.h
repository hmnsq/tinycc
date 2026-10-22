#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
puur_naa_nka pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    ᯀᯮᯞ *p ? 0 : -1;
}
puur_naa_nka pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    ᯀᯮᯝ (ret)
        *ret = (void*)(size_t)r;
    ᯀᯮᯞ 0;
}
#ᯀᯮᯝᯂᯪ
#include <pthread.h>
#endif
