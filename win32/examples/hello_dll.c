//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#অন্তর্ভাৱ <windows.h>

শূন্য hello_func (শূন্য);
__declspec(dllimport) বাহ্য ধ্রুৱ ৱর্ণ *hello_data;

পূর্ণাঙ্ক WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_সাৰি,
    পূর্ণাঙ্ক       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ঘূৰাই 0;
}
