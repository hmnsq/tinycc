#अगर_घोषित _WIN32
#समावेश <windows.h>
प्रकार HANDLE pthread_t;
पूर्णांक pthread_create(pthread_t *p, व्योम *x, व्योम *fn, व्योम *args)
{
    DWORD tid;
    *p = CreateThread(शून्य, 0, fn, args, 0, &tid);
    वापस *p ? 0 : -1;
}
पूर्णांक pthread_join(pthread_t h, व्योम **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    अगर (ret)
        *ret = (व्योम*)(माप_प्रकार)r;
    वापस 0;
}
#अन्यथा
#समावेश <pthread.h>
#पूर्ण_अगर
