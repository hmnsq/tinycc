//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const char *hello_data;

цяло WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    цяло       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    върни 0;
}
