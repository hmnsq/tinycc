//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#समावेश <windows.h>

व्योम hello_func (व्योम);
__declspec(dllimport) बाह्य स्थिर अक्षर *hello_तथ्य;

पूर्णांक WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE h_पूर्व_Instance,
    LPSTR     lp_Cmd_पंक्ति,
    पूर्णांक       nCmdShow)
{
    hello_तथ्य = "Hello World!";
    hello_func();
    वापस 0;
}
