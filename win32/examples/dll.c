//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ضمن <windows.h>

__declspec(dllexport) ثابت حرف *hello_انکڑے = "(not set)";

__declspec(dllexport) فراغ hello_func (فراغ)
{
    سنیہا_Box (0, hello_انکڑے, "From DLL", MB_ICONINFORMATION);
}
