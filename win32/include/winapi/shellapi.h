/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_SHELLAPI
#تعریف_کرو _INC_SHELLAPI

#جے_بنا_تعریف WINSHELLAPI
#إذا !defined(_SHELL32_)
#تعریف_کرو WINSHELLAPI DECLSPEC_IMPORT
#وإلا
#تعریف_کرو WINSHELLAPI
#جے_انت
#جے_انت

#جے_بنا_تعریف SHSTDAPI
#إذا !defined(_SHELL32_)
#تعریف_کرو SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#تعریف_کرو SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#وإلا
#تعریف_کرو SHSTDAPI STDAPI
#تعریف_کرو SHSTDAPI_(type) STDAPI_(type)
#جے_انت
#جے_انت

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#إذا !defined(_WIN64)
#ضمن <pshpack1.h>
#جے_انت

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو ShellExecute ShellExecuteW
#تعریف_کرو لبھو_Executable لبھو_Executable_W
#وإلا
#تعریف_کرو ShellExecute ShellExecuteA
#تعریف_کرو لبھو_Executable لبھو_Executable_A
#جے_انت

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) لبھو_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_نتیجہ);
  SHSTDAPI_(HINSTANCE) لبھو_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_نتیجہ);
  SHSTDAPI_(LPWSTR *) Command_سطر_منزل_Argv_W(LPCWSTR lp_Cmd_سطر,صحيح*p_عدد_دلیلاں);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#إذا !defined(_WIN64)
#ضمن <poppack.h>
#جے_انت
#جے_انت
