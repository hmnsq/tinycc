#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE pthread_t;
ਪੂਰਨ pthread_create(pthread_t *p, ਖਾਲੀ *x, ਖਾਲੀ *fn, ਖਾਲੀ *ਦਲੀਲਾਂ)
{
    DWORD tid;
    *p = CreateThread(ਨਿਰਾ, 0, fn, ਦਲੀਲਾਂ, 0, &tid);
    ਵਾਪਸ *p ? 0 : -1;
}
ਪੂਰਨ pthread_join(pthread_t h, ਖਾਲੀ **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    Get_Exit_ਕੋਡ_Thread(h, &r);
    CloseHandle(h);
    ਜੇ (ret)
        *ret = (ਖਾਲੀ*)(ਮਾਪ_t)r;
    ਵਾਪਸ 0;
}
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
#ਜੇ_ਅੰਤ
