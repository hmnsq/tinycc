//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#অন্তর্ভাব <windows.h>

__declspec(dllexport) ধ্রুব বর্ণ *hello_data = "(not set)";

__declspec(dllexport) শূন্য hello_func (শূন্য)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
