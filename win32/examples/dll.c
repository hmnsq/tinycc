//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ಅನ್ತರ್ಭಾವ <windows.h>

__declspec(dllexport) ಧ್ರುವ ವರ್ಣ *hello_data = "(not set)";

__declspec(dllexport) ಶೂನ್ಯ hello_func (ಶೂನ್ಯ)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
