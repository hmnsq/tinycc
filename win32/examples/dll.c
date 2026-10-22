//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#অন্তর্ভাৱ <windows.h>

__declspec(dllexport) ধ্রুৱ ৱর্ণ *hello_data = "(not set)";

__declspec(dllexport) শূন্য hello_func (শূন্য)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
