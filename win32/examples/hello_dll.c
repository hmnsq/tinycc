//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const var_na *hello_data;

ចំនួនគត់ WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    ចំនួនគត់       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ត្រឡប់ 0;
}
