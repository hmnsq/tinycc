//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#અન્તર્ભાવ <windows.h>

શૂન્ય hello_func (શૂન્ય);
__declspec(dllimport) બાહ્ય અચલ અક્ષર *hello_data;

પૂર્ણાંક WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_લીટી,
    પૂર્ણાંક       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    પાછા 0;
}
