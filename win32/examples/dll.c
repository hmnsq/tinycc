//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#شامل <windows.h>

__declspec(dllexport) ثابت حرف *hello_ڈیٹا = "(not set)";

__declspec(dllexport) خالی hello_func (خالی)
{
    پیغام_Box (0, hello_ڈیٹا, "From DLL", MB_ICONINFORMATION);
}
