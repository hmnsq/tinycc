//+---------------------------------------------------------------------------

#include <tchar.h>
#include <windows.h>
#include "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    ᯀᯮᯝ (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        run_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    ᯀᯮᯝ (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        run_dtors();
    ᯀᯮᯞ bRet;
}
