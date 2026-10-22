#ifdef _WIN32
#অন্তর্ভাব <windows.h>
প্রকারনির্দেশ HANDLE pthread_t;
পূর্ণাঙ্ক pthread_create(pthread_t *p, শূন্য *x, শূন্য *fn, শূন্য *args)
{
    DWORD tid;
    *p = CreateThread(রিক্ত, 0, fn, args, 0, &tid);
    প্রত্যাগম *p ? 0 : -1;
}
পূর্ণাঙ্ক pthread_join(pthread_t h, শূন্য **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    যদি (ret)
        *ret = (শূন্য*)(size_t)r;
    প্রত্যাগম 0;
}
#অন্যথা
#অন্তর্ভাব <pthread.h>
#endif
