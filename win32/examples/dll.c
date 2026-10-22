//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#അന്തര്ഭാവ <windows.h>

__declspec(dllexport) സ്ഥിരം അക്ഷരം *hello_data = "(not set)";

__declspec(dllexport) ശൂന്യം hello_func (ശൂന്യം)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
