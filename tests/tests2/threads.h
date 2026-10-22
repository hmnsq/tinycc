#اگر_تعریف_شده _WIN32
#ضمن <windows.h>
تعريفنوع HANDLE pthread_t;
صحيح pthread_create(pthread_t *p, فراغ *x, فراغ *fn, فراغ *آرگومانها)
{
    DWORD tid;
    *p = CreateThread(عدم, 0, fn, آرگومانها, 0, &tid);
    أرجع *p ? 0 : -1;
}
صحيح pthread_join(pthread_t h, فراغ **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    Get_Exit_کد_Thread(h, &r);
    CloseHandle(h);
    إذا (ret)
        *ret = (فراغ*)(اندازه_t)r;
    أرجع 0;
}
#وإلا
#ضمن <pthread.h>
#پایان_اگر
