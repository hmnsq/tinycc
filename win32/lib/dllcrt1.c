//+---------------------------------------------------------------------------

#అన్తర్భావ <tchar.h>
#అన్తర్భావ <windows.h>
#అన్తర్భావ "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    ఒకవేళ (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        నిరంతరం_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    ఒకవేళ (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        నిరంతరం_dtors();
    తిరిగి bRet;
}
