//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#அந்தர்பாவ <windows.h>

__declspec(dllexport) மாறிலி எழுத்து *hello_data = "(not set)";

__declspec(dllexport) வெறுமை hello_func (வெறுமை)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
