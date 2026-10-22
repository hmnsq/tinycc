#ifdef _WIN32
#include <windows.h>
typedef HANDLE pthread_t;
ຈຳນວນເຕັມ pthread_create(pthread_t *p, void *x, void *fn, void *args)
{
    DWORD tid;
    *p = CreateThread(NULL, 0, fn, args, 0, &tid);
    ສົ່ງຄືນ *p ? 0 : -1;
}
ຈຳນວນເຕັມ pthread_join(pthread_t h, void **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    ຖ້າ (ret)
        *ret = (void*)(size_t)r;
    ສົ່ງຄືນ 0;
}
#ບໍ່ດັ່ງນັ້ນ
#include <pthread.h>
#endif
