//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>

__declspec(dllexport) ਅਚਲ ਅੱਖਰ *hello_ਅੰਕੜੇ = "(not set)";

__declspec(dllexport) ਖਾਲੀ hello_func (ਖਾਲੀ)
{
    ਸੁਨੇਹਾ_Box (0, hello_ਅੰਕੜੇ, "From DLL", MB_ICONINFORMATION);
}
