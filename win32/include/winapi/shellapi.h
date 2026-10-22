/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_SHELLAPI
#تعریف_کن _INC_SHELLAPI

#اگر_تعریف_نشده WINSHELLAPI
#إذا !defined(_SHELL32_)
#تعریف_کن WINSHELLAPI DECLSPEC_IMPORT
#وإلا
#تعریف_کن WINSHELLAPI
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده SHSTDAPI
#إذا !defined(_SHELL32_)
#تعریف_کن SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#تعریف_کن SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#وإلا
#تعریف_کن SHSTDAPI STDAPI
#تعریف_کن SHSTDAPI_(type) STDAPI_(type)
#پایان_اگر
#پایان_اگر

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#إذا !defined(_WIN64)
#ضمن <pshpack1.h>
#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن ShellExecute ShellExecuteW
#تعریف_کن پیدا_کن_Executable پیدا_کن_Executable_W
#وإلا
#تعریف_کن ShellExecute ShellExecuteA
#تعریف_کن پیدا_کن_Executable پیدا_کن_Executable_A
#پایان_اگر

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) پیدا_کن_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_نتیجه);
  SHSTDAPI_(HINSTANCE) پیدا_کن_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_نتیجه);
  SHSTDAPI_(LPWSTR *) Command_سطر_مقصد_Argv_W(LPCWSTR lp_Cmd_سطر,صحيح*p_رقم_آرگومانها);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#إذا !defined(_WIN64)
#ضمن <poppack.h>
#پایان_اگر
#پایان_اگر
