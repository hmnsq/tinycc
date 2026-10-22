//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#অন্তর্ভাব <windows.h>

শূন্য hello_func (শূন্য);
__declspec(dllimport) বাহ্য ধ্রুব বর্ণ *hello_data;

পূর্ণাঙ্ক WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_সারি,
    পূর্ণাঙ্ক       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    প্রত্যাগম 0;
}
