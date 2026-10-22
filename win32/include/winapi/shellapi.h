/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_SHELLAPI
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_SHELLAPI

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINSHELLAPI
#ಆದರೆ !defined(_SHELL32_)
#ವ್ಯಾಖ್ಯಾನಿಸು WINSHELLAPI DECLSPEC_IMPORT
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು WINSHELLAPI
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SHSTDAPI
#ಆದರೆ !defined(_SHELL32_)
#ವ್ಯಾಖ್ಯಾನಿಸು SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SHSTDAPI STDAPI
#ವ್ಯಾಖ್ಯಾನಿಸು SHSTDAPI_(type) STDAPI_(type)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#ಆದರೆ !defined(_WIN64)
#ಅನ್ತರ್ಭಾವ <pshpack1.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ShellExecute ShellExecuteW
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Executable ಕಂಡುಹಿಡಿ_Executable_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ShellExecute ShellExecuteA
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Executable ಕಂಡುಹಿಡಿ_Executable_A
#ಆದರೆ_ಅಂತ್ಯ

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ಕಂಡುಹಿಡಿ_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_ಫಲಿತಾಂಶ);
  SHSTDAPI_(HINSTANCE) ಕಂಡುಹಿಡಿ_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_ಫಲಿತಾಂಶ);
  SHSTDAPI_(LPWSTR *) Command_ಸಾಲು_ಗಮ್ಯ_Argv_W(LPCWSTR lp_Cmd_ಸಾಲು,ಪೂರ್ಣಾಂಕ*p_ಅಂಕೆ_ವಾದಗಳು);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(_WIN64)
#ಅನ್ತರ್ಭಾವ <poppack.h>
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
