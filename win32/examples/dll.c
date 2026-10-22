//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#অন্তর্ভাব <windows.h>

__declspec(dllexport) ধ্রুবক অক্ষর *hello_তথ্য = "(not set)";

__declspec(dllexport) শূন্য hello_func (শূন্য)
{
    MessageBox (0, hello_তথ্য, "From DLL", MB_ICONINFORMATION);
}
