//+---------------------------------------------------------------------------

#include <tchar.h>
#include <windows.h>
#include "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    ຖ້າ (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        run_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    ຖ້າ (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        run_dtors();
    ສົ່ງຄືນ bRet;
}
