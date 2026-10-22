#ifdef _WIN32
#અન્તર્ભાવ <windows.h>
પ્રકારવ્યાખ્યા HANDLE pthread_t;
પૂર્ણાંક pthread_create(pthread_t *p, શૂન્ય *x, શૂન્ય *fn, શૂન્ય *args)
{
    DWORD tid;
    *p = CreateThread(ખાલી, 0, fn, args, 0, &tid);
    પાછા *p ? 0 : -1;
}
પૂર્ણાંક pthread_join(pthread_t h, શૂન્ય **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    જો (ret)
        *ret = (શૂન્ય*)(size_t)r;
    પાછા 0;
}
#નહીંતર
#અન્તર્ભાવ <pthread.h>
#endif
