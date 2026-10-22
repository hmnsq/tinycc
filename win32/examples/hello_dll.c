//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#شامل <windows.h>

تهی hello_func (تهی);
__declspec(dllimport) بیرونی ثابت نویسه *hello_data;

صحیح WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_سطر,
    صحیح       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    بازگشت 0;
}
