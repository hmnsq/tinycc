//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const var_na *hello_data;

පූර්ණ_සංඛ්‍යා WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    පූර්ණ_සංඛ්‍යා       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ආපසු 0;
}
