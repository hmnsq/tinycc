//+---------------------------------------------------------------------------

#ಅನ್ತರ್ಭಾವ <tchar.h>
#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    ಆದರೆ (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        ಸತತ_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    ಆದರೆ (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        ಸತತ_dtors();
    ಹಿಂತಿರುಗಿ bRet;
}
