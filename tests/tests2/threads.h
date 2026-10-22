#ifdef _WIN32
#അന്തര്ഭാവ <windows.h>
തരനിർവചനം HANDLE pthread_t;
പൂർണ്ണസംഖ്യ pthread_create(pthread_t *p, ശൂന്യം *x, ശൂന്യം *fn, ശൂന്യം *args)
{
    DWORD tid;
    *p = CreateThread(ശൂന്യ, 0, fn, args, 0, &tid);
    തിരികെ *p ? 0 : -1;
}
പൂർണ്ണസംഖ്യ pthread_join(pthread_t h, ശൂന്യം **ret)
{
    DWORD r;
    WaitForSingleObject(h, INFINITE);
    GetExitCodeThread(h, &r);
    CloseHandle(h);
    എങ്കിൽ (ret)
        *ret = (ശൂന്യം*)(size_t)r;
    തിരികെ 0;
}
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <pthread.h>
#endif
