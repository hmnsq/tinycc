//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ضمن <windows.h>

__declspec(dllexport) ثابت حرف *hello_معلومات = "(not set)";

__declspec(dllexport) فراغ hello_func (فراغ)
{
    پيغام_Box (0, hello_معلومات, "From DLL", MB_ICONINFORMATION);
}
