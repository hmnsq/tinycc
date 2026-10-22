//+---------------------------------------------------------------------------

#ضمن <tchar.h>
#ضمن <windows.h>
#ضمن "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    إذا (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        لگاتار_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    إذا (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        لگاتار_dtors();
    أرجع bRet;
}
