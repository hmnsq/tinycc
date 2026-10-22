//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const char *hello_data;

정수 WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    정수       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    반환 0;
}
