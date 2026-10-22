#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
#ಅನ್ತರ್ಭಾವ <windows.h>
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE pthread_t;
ಪೂರ್ಣಾಂಕ pthread_create(pthread_t *p, ಶೂನ್ಯ *x, ಶೂನ್ಯ *fn, ಶೂನ್ಯ *ವಾದಗಳು)
{
    DWORD tid;
    *p = CreateThread(ಖಾಲಿ, 0, fn, ವಾದಗಳು, 0, &tid);
    ಹಿಂತಿರುಗಿ *p ? 0 : -1;
}
ಪೂರ್ಣಾಂಕ pthread_join(pthread_t h, ಶೂನ್ಯ **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    Get_Exit_ಸಂಕೇತ_Thread(h, &r);
    CloseHandle(h);
    ಆದರೆ (ret)
        *ret = (ಶೂನ್ಯ*)(ಗಾತ್ರ_t)r;
    ಹಿಂತಿರುಗಿ 0;
}
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಆದರೆ_ಅಂತ್ಯ
