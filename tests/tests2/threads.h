#నిర్వచితమైతే _WIN32
#అన్తర్భావ <windows.h>
రకనిర్వచనం HANDLE pthread_t;
పూర్ణాంకం pthread_create(pthread_t *p, శూన్య *x, శూన్య *fn, శూన్య *వాదనలు)
{
    DWORD tid;
    *p = CreateThread(ఖాళీ, 0, fn, వాదనలు, 0, &tid);
    తిరిగి *p ? 0 : -1;
}
పూర్ణాంకం pthread_join(pthread_t h, శూన్య **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    Get_Exit_సంకేతం_Thread(h, &r);
    CloseHandle(h);
    ఒకవేళ (ret)
        *ret = (శూన్య*)(కొలత_t)r;
    తిరిగి 0;
}
#లేకపోతే
#అన్తర్భావ <pthread.h>
#అయితే_ముగింపు
