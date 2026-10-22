//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#अन्तर्भाव <windows.h>

__declspec(dllexport) ध्रुव वर्ण *hello_दत्त = "(not set)";

__declspec(dllexport) शून्य hello_func (शून्य)
{
    सन्देशः_Box (0, hello_दत्त, "From DLL", MB_ICONINFORMATION);
}
