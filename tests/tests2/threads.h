#ifdef _WIN32
#अन्तर्भाव <windows.h>
प्रकारनिर्देश HANDLE pthread_t;
पूर्णाङ्क pthread_create(pthread_t *p, शून्य *x, शून्य *fn, शून्य *args)
{
    DWORD tid;
    *p = CreateThread(रिक्त, 0, fn, args, 0, &tid);
    फर्काऊ *p ? 0 : -1;
}
पूर्णाङ्क pthread_join(pthread_t h, शून्य **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    यदि (ret)
        *ret = (शून्य*)(माप_प्रकार)r;
    फर्काऊ 0;
}
#अन्यथा
#अन्तर्भाव <pthread.h>
#endif
