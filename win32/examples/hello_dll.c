//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#अन्तर्भाव <windows.h>

शून्य hello_func (शून्य);
__declspec(dllimport) बाह्य अचर वर्ण *hello_data;

पूर्णाङ्क WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_पङ्क्ति,
    पूर्णाङ्क       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    फर्काऊ 0;
}
