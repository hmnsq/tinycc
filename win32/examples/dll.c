//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ضمن <windows.h>

__declspec(dllexport) ثابت حرف *hello_داده = "(not set)";

__declspec(dllexport) فراغ hello_func (فراغ)
{
    پیام_Box (0, hello_داده, "From DLL", MB_ICONINFORMATION);
}
