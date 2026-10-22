#यदि_परिभाषितम् _WIN32
#अन्तर्भाव <windows.h>
प्रकारनिर्देश HANDLE pthread_t;
पूर्णाङ्क pthread_create(pthread_t *p, शून्य *x, शून्य *fn, शून्य *तर्काः)
{
    DWORD tid;
    *p = CreateThread(रिक्त, 0, fn, तर्काः, 0, &tid);
    प्रत्यागम *p ? 0 : -1;
}
पूर्णाङ्क pthread_join(pthread_t h, शून्य **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    Get_Exit_संहिता_Thread(h, &r);
    CloseHandle(h);
    यदि (ret)
        *ret = (शून्य*)(आकार_t)r;
    प्रत्यागम 0;
}
#अन्यथा
#अन्तर्भाव <pthread.h>
#यदि_अन्तः
