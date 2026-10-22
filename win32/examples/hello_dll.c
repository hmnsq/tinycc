//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const var_na *hello_data;

จำนวนเต็ม WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    จำนวนเต็ม       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    คืน 0;
}
