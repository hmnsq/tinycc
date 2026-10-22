//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#અન્તર્ભાવ <windows.h>

__declspec(dllexport) અચલ અક્ષર *hello_data = "(not set)";

__declspec(dllexport) શૂન્ય hello_func (શૂન્ય)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
