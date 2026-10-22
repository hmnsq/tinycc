//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#अन्तर्भाव <windows.h>

शून्य hello_func (शून्य);
__declspec(dllimport) बाह्य ध्रुव वर्ण *hello_data;

पूर्णाङ्क WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_ओळ,
    पूर्णाङ्क       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    प्रत्यागम 0;
}
