#ifdef _WIN32
#অন্তর্ভাব <windows.h>
প্রকারলেখ HANDLE pthread_t;
পূর্ণসংখ্যা pthread_create(pthread_t *p, শূন্য *x, শূন্য *fn, শূন্য *args)
{
    DWORD tid;
    *p = CreateThread(ফাঁকা, 0, fn, args, 0, &tid);
    ফেরত *p ? 0 : -1;
}
পূর্ণসংখ্যা pthread_join(pthread_t h, শূন্য **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    যদি (ret)
        *ret = (শূন্য*)(আকার_t)r;
    ফেরত 0;
}
#অন্যথা
#অন্তর্ভাব <pthread.h>
#endif
