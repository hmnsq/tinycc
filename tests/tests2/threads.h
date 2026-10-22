#ifdef _WIN32
#ଅନ୍ତର୍ଭାଵ <windows.h>
ପ୍ରକାରବ୍ୟାଖ୍ୟା HANDLE pthread_t;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା pthread_create(pthread_t *p, ଶୂନ୍ୟ *x, ଶୂନ୍ୟ *fn, ଶୂନ୍ୟ *args)
{
    DWORD tid;
    *p = CreateThread(ଖାଲି, 0, fn, args, 0, &tid);
    ଫେରନ୍ତୁ *p ? 0 : -1;
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା pthread_join(pthread_t h, ଶୂନ୍ୟ **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    ଯଦି (ret)
        *ret = (ଶୂନ୍ୟ*)(size_t)r;
    ଫେରନ୍ତୁ 0;
}
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <pthread.h>
#endif
