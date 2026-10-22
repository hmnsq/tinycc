#اگر_تعریف_شدہ _WIN32
#شامل <windows.h>
قسمتعریف HANDLE pthread_t;
صحیح pthread_create(pthread_t *p, خالی *x, خالی *fn, خالی *دلائل)
{
    DWORD tid;
    *p = CreateThread(تہی, 0, fn, دلائل, 0, &tid);
    واپس *p ? 0 : -1;
}
صحیح pthread_join(pthread_t h, خالی **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    Get_Exit_رمز_Thread(h, &r);
    CloseHandle(h);
    اگر (ret)
        *ret = (خالی*)(سائز_t)r;
    واپس 0;
}
#ورنہ
#شامل <pthread.h>
#اگر_ختم
