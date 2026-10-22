//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ضمن <windows.h>

__declspec(dllexport) ثابت حرف *hello_data = "(not set)";

__declspec(dllexport) فراغ hello_func (فراغ)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
