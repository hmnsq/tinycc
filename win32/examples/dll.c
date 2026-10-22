//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ଅନ୍ତର୍ଭାଵ <windows.h>

__declspec(dllexport) ଅଚଳ ଅକ୍ଷର *hello_data = "(not set)";

__declspec(dllexport) ଶୂନ୍ୟ hello_func (ଶୂନ୍ୟ)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
