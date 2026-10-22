//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const var_na *hello_data;

ကိန်းပြည့် WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    ကိန်းပြည့်       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ပြန်ပေး 0;
}
