//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#شامل <windows.h>

__declspec(dllexport) ثابت نویسه *hello_data = "(not set)";

__declspec(dllexport) تهی hello_func (تهی)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
