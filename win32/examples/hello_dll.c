//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#include <windows.h>

void hello_func (void);
__declspec(dllimport) extern const var_na *hello_data;

puur_naa_nka WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    puur_naa_nka       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ᨀᨘᨒ 0;
}
