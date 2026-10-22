#ifdef _WIN32
#अन्तर्भाव <windows.h>
प्रकारनिर्देश HANDLE pthread_t;
पूर्णाङ्क pthread_create(pthread_t *p, शून्य *x, शून्य *fn, शून्य *args)
{
    DWORD tid;
    *p = CreateThread(रिक्त, 0, fn, args, 0, &tid);
    प्रत्यागम *p ? 0 : -1;
}
पूर्णाङ्क pthread_join(pthread_t h, शून्य **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    जइ (ret)
        *ret = (शून्य*)(size_t)r;
    प्रत्यागम 0;
}
#अण्णहा
#अन्तर्भाव <pthread.h>
#endif
