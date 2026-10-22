#ifdef _WIN32
#شامل <windows.h>
تعریفنوع HANDLE pthread_t;
صحیح pthread_create(pthread_t *p, تهی *x, تهی *fn, تهی *args)
{
    DWORD tid;
    *p = CreateThread(پوچ, 0, fn, args, 0, &tid);
    بازگشت *p ? 0 : -1;
}
صحیح pthread_join(pthread_t h, تهی **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    اگر (ret)
        *ret = (تهی*)(size_t)r;
    بازگشت 0;
}
#وگرنه
#شامل <pthread.h>
#endif
