#ifdef _WIN32
#ಅನ್ತರ್ಭಾವ <windows.h>
ಪ್ರಕಾರನಿರ್ದೇಶ HANDLE pthread_t;
ಪೂರ್ಣಾಙ್ಕ pthread_create(pthread_t *p, ಶೂನ್ಯ *x, ಶೂನ್ಯ *fn, ಶೂನ್ಯ *args)
{
    DWORD tid;
    *p = CreateThread(ರಿಕ್ತ, 0, fn, args, 0, &tid);
    ಪ್ರತ್ಯಾಗಮ *p ? 0 : -1;
}
ಪೂರ್ಣಾಙ್ಕ pthread_join(pthread_t h, ಶೂನ್ಯ **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    ಯದಿ (ret)
        *ret = (ಶೂನ್ಯ*)(size_t)r;
    ಪ್ರತ್ಯಾಗಮ 0;
}
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <pthread.h>
#endif
