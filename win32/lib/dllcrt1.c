//+---------------------------------------------------------------------------

#ਅਨ੍ਤਰ੍ਭਾਵ <tchar.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਅਨ੍ਤਰ੍ਭਾਵ "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    ਜੇ (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        ਲੜੀਵਾਰ_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    ਜੇ (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        ਲੜੀਵਾਰ_dtors();
    ਵਾਪਸ bRet;
}
