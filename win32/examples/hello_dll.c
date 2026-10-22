//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#ଅନ୍ତର୍ଭାଵ <windows.h>

ଶୂନ୍ୟ hello_func (ଶୂନ୍ୟ);
__declspec(dllimport) ବାହ୍ୟ ଅଚଳ ଅକ୍ଷର *hello_data;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_ଧାଡ଼ି,
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ଫେରନ୍ତୁ 0;
}
