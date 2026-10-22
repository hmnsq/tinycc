//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#ضمن <windows.h>

فراغ hello_func (فراغ);
__declspec(dllimport) خارجي ثابت حرف *hello_data;

صحيح WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    صحيح       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ܦܢܐ 0;
}
