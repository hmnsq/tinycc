//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#ضمن <windows.h>

فراغ hello_func (فراغ);
__declspec(dllimport) خارجي ثابت حرف *hello_معلومات;

صحيح WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_سٽ,
    صحيح       nCmdShow)
{
    hello_معلومات = "Hello World!";
    hello_func();
    أرجع 0;
}
