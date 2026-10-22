//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#ಅನ್ತರ್ಭಾವ <windows.h>

__declspec(dllexport) ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *hello_ದತ್ತಾಂಶ = "(not set)";

__declspec(dllexport) ಶೂನ್ಯ hello_func (ಶೂನ್ಯ)
{
    ಸಂದೇಶ_Box (0, hello_ದತ್ತಾಂಶ, "From DLL", MB_ICONINFORMATION);
}
