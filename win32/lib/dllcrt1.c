//+---------------------------------------------------------------------------

#समावेश <tchar.h>
#समावेश <windows.h>
#समावेश "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    अगर (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        run_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    अगर (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        run_dtors();
    वापस bRet;
}
