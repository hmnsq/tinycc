//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#ಅನ್ತರ್ಭಾವ <windows.h>

ಶೂನ್ಯ hello_func (ಶೂನ್ಯ);
__declspec(dllimport) ಬಾಹ್ಯ ಧ್ರುವ ವರ್ಣ *hello_data;

ಪೂರ್ಣಾಙ್ಕ WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_ಸಾಲು,
    ಪೂರ್ಣಾಙ್ಕ       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    ಪ್ರತ್ಯಾಗಮ 0;
}
