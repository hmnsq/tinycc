#ifdef _WIN32
#ضمن <windows.h>
تعريفنوع HANDLE pthread_t;
صحيح pthread_create(pthread_t *p, فراغ *x, فراغ *fn, فراغ *args)
{
    DWORD tid;
    *p = CreateThread(عدم, 0, fn, args, 0, &tid);
    أرجع *p ? 0 : -1;
}
صحيح pthread_join(pthread_t h, فراغ **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    𐡄𐡍 (ret)
        *ret = (فراغ*)(size_t)r;
    أرجع 0;
}
#وإلا
#ضمن <pthread.h>
#endif
