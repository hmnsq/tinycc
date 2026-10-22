//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const var_na *hello_data;

ຈຳນວນເຕັມ WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    ຈຳນວນເຕັມ       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ສົ່ງຄືນ 0;
}
