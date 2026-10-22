//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#அந்தர்பாவ <windows.h>

வெறுமை hello_func (வெறுமை);
__declspec(dllimport) வெளி மாறிலி எழுத்து *hello_data;

முழு WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_வரி,
    முழு       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    திரும்பு 0;
}
