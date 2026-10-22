#ifdef _WIN32
#அந்தர்பாவ <windows.h>
வகைவரை HANDLE pthread_t;
முழு pthread_create(pthread_t *p, வெறுமை *x, வெறுமை *fn, வெறுமை *args)
{
    DWORD tid;
    *p = CreateThread(வெற்று, 0, fn, args, 0, &tid);
    திரும்பு *p ? 0 : -1;
}
முழு pthread_join(pthread_t h, வெறுமை **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    எனில் (ret)
        *ret = (வெறுமை*)(size_t)r;
    திரும்பு 0;
}
#இல்லையெனில்
#அந்தர்பாவ <pthread.h>
#endif
