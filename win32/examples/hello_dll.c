//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#شامل <windows.h>

خالی hello_func (خالی);
__declspec(dllimport) خارجی ثابت حرف *hello_ڈیٹا;

صحیح WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE h_پچھلا_Instance,
    LPSTR     lp_Cmd_سطر,
    صحیح       nCmdShow)
{
    hello_ڈیٹا = "Hello World!";
    hello_func();
    واپس 0;
}
