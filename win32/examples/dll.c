//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#अन्तर्भाव <windows.h>

__declspec(dllexport) अचर वर्ण *hello_data = "(not set)";

__declspec(dllexport) शून्य hello_func (शून्य)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
