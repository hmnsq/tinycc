//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#समावेश <windows.h>

__declspec(dllexport) स्थिर अक्षर *hello_तथ्य = "(not set)";

__declspec(dllexport) व्योम hello_func (व्योम)
{
    MessageBox (0, hello_तथ्य, "From DLL", MB_ICONINFORMATION);
}
