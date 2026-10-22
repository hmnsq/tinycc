//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#অন্তর্ভাব <windows.h>

শূন্য hello_func (শূন্য);
__declspec(dllimport) বাহ্যিক ধ্রুবক অক্ষর *hello_তথ্য;

পূর্ণসংখ্যা WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE h_পূর্ব_Instance,
    LPSTR     lp_Cmd_সারি,
    পূর্ণসংখ্যা       nCmdShow)
{
    hello_তথ্য = "Hello World!";
    hello_func();
    ফেরত 0;
}
