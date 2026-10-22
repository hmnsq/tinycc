//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#ಅನ್ತರ್ಭಾವ <windows.h>

ಶೂನ್ಯ hello_func (ಶೂನ್ಯ);
__declspec(dllimport) ಬಾಹ್ಯ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *hello_ದತ್ತಾಂಶ;

ಪೂರ್ಣಾಂಕ WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lp_Cmd_ಸಾಲು,
    ಪೂರ್ಣಾಂಕ       nCmdShow)
{
    hello_ದತ್ತಾಂಶ = "Hello World!";
    hello_func();
    ಹಿಂತಿರುಗಿ 0;
}
