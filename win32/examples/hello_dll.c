//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#अन्तर्भाव <windows.h>

शून्य hello_func (शून्य);
__declspec(dllimport) बाह्य स्थिरांक अक्षर *hello_data;

पूर्णांक WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_ओळ,
    पूर्णांक       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    परत 0;
}
