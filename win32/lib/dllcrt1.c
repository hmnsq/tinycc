//+---------------------------------------------------------------------------

#شامل <tchar.h>
#شامل <windows.h>
#شامل "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    اگر (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        تسلسل_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    اگر (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        تسلسل_dtors();
    واپس bRet;
}
