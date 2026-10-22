//+---------------------------------------------------------------------------

#ضمن <tchar.h>
#ضمن <windows.h>
#ضمن "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    𐤀𐤌 (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        run_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    𐤀𐤌 (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        run_dtors();
    أرجع bRet;
}
