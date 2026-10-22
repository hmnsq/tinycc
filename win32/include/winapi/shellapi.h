/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_SHELLAPI
#وصف_ڪريو _INC_SHELLAPI

#جيڪڏهن_وصف_نه_ٿيل WINSHELLAPI
#إذا !defined(_SHELL32_)
#وصف_ڪريو WINSHELLAPI DECLSPEC_IMPORT
#وإلا
#وصف_ڪريو WINSHELLAPI
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل SHSTDAPI
#إذا !defined(_SHELL32_)
#وصف_ڪريو SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#وصف_ڪريو SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#وإلا
#وصف_ڪريو SHSTDAPI STDAPI
#وصف_ڪريو SHSTDAPI_(type) STDAPI_(type)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#إذا !defined(_WIN64)
#ضمن <pshpack1.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ShellExecute ShellExecuteW
#وصف_ڪريو ڳوليو_Executable ڳوليو_Executable_W
#وإلا
#وصف_ڪريو ShellExecute ShellExecuteA
#وصف_ڪريو ڳوليو_Executable ڳوليو_Executable_A
#جيڪڏهن_پورو

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ڳوليو_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_نتيجو);
  SHSTDAPI_(HINSTANCE) ڳوليو_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_نتيجو);
  SHSTDAPI_(LPWSTR *) Command_سٽ_منزل_Argv_W(LPCWSTR lp_Cmd_سٽ,صحيح*p_انگ_دليلون);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#إذا !defined(_WIN64)
#ضمن <poppack.h>
#جيڪڏهن_پورو
#جيڪڏهن_پورو
