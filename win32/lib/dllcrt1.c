//+---------------------------------------------------------------------------

#अन्तर्भाव <tchar.h>
#अन्तर्भाव <windows.h>
#अन्तर्भाव "crtinit.c"

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI _dllstart(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    BOOL bRet;
    यदि (dwReason == DLL_PROCESS_ATTACH) /* ignore DLL_THREAD_ATTACH */
        सततम्_ctors(0, 0, 0);
    bRet = DllMain (hDll, dwReason, lpReserved);
    यदि (dwReason == DLL_PROCESS_DETACH) /* ignore  DLL_THREAD_DETACH */
        सततम्_dtors();
    प्रत्यागम bRet;
}
