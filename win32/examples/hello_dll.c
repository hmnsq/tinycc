//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>

ਖਾਲੀ hello_func (ਖਾਲੀ);
__declspec(dllimport) ਬਾਹਰੀ ਅਚਲ ਅੱਖਰ *hello_ਅੰਕੜੇ;

ਪੂਰਨ WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_ਸਤਰ,
    ਪੂਰਨ       nCmdShow)
{
    hello_ਅੰਕੜੇ = "Hello World!";
    hello_func();
    ਵਾਪਸ 0;
}
