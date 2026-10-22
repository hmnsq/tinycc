//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#അന്തര്ഭാവ <windows.h>

ശൂന്യം hello_func (ശൂന്യം);
__declspec(dllimport) ബാഹ്യ സ്ഥിരം അക്ഷരം *hello_data;

പൂർണ്ണസംഖ്യ WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_വരി,
    പൂർണ്ണസംഖ്യ       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    തിരികെ 0;
}
