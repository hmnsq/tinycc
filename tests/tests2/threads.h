#جيڪڏهن_وصف_ٿيل _WIN32
#ضمن <windows.h>
تعريفنوع HANDLE pthread_t;
صحيح pthread_create(pthread_t *p, فراغ *x, فراغ *fn, فراغ *دليلون)
{
    DWORD tid;
    *p = CreateThread(عدم, 0, fn, دليلون, 0, &tid);
    أرجع *p ? 0 : -1;
}
صحيح pthread_join(pthread_t h, فراغ **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    Get_Exit_ڪوڊ_Thread(h, &r);
    CloseHandle(h);
    إذا (ret)
        *ret = (فراغ*)(سائيز_t)r;
    أرجع 0;
}
#وإلا
#ضمن <pthread.h>
#جيڪڏهن_پورو
